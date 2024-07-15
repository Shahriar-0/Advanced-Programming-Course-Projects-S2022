#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

const std::string NO_TRANSLATOR_FOUND = "Not Found";
const std::string OUTPUT_DELIMETER = ": ";
const std::string ERROR_1 = "haven't pass the argument";

const char* SPLIT_CHAR = " ";
const int LANGUAGE_NOT_FOUND = -1;

namespace Data {

struct Time {
    int hour;
    int minute;
};

struct TimePeriod {
    Time start;
    Time end;
};

struct Translator {
    std::string name;
    TimePeriod availableTimePeriod;
    std::vector<TimePeriod> occupiedTimes;
    std::vector<std::string> languages;
    int numOfLanguages;
};

struct EventsLanguage {
    std::string languageName;
    std::string translatorName;
    int numOfTranslators;
    int priority;
};

struct Event {
    std::string name;
    TimePeriod timePeriod;
    std::vector<EventsLanguage> eventLanguages;
    std::vector<std::string> languages;
};

struct Language {
    Language(std::string name, int numOfTranslators,
             std::vector<std::shared_ptr<Translator>> translators)
        : name(name), numOfTranslators(numOfTranslators), translators(std::move(translators)) {}
    std::string name;
    int numOfTranslators;
    std::vector<std::shared_ptr<Translator>> translators;
};

using Languages = std::vector<Language>;
using Translators = std::vector<std::shared_ptr<Translator>>;
using Events = std::vector<Event>;

struct EventScheduler {
    Languages languages;
    Translators translators;
    Events events;
};

}  // namespace Data

namespace Input {

void readInput(Data::EventScheduler& scheduler, const std::string fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) throw std::runtime_error(ERROR_1);

    readTranslators(scheduler, file);
    readEvents(scheduler, file);
}

void readTranslators(Data::EventScheduler& scheduler, std::ifstream& file) {
    int numOfTranslators;
    file >> numOfTranslators;
    scheduler.translators.reserve(numOfTranslators);
    for (int i = 0; i < numOfTranslators; ++i) {
        auto translator = std::make_shared<Data::Translator>();
        file >> *translator;
        scheduler.translators.push_back(translator);
        for (auto language : translator->languages) {
            int index = Scheduling::search(scheduler.languages, language);

            if (index == LANGUAGE_NOT_FOUND)
                Input::addNew(scheduler, language, i);
            else
                Input::addExisting(scheduler, index, i);
        }
    }
}

void readEvents(Data::EventScheduler& scheduler, std::ifstream& file) {
    int numOfEvents;
    file >> numOfEvents;
    scheduler.events.reserve(numOfEvents);
    for (int i = 0; i < numOfEvents; ++i) {
        Data::Event event;
        file >> event;
        Data::EventsLanguage eventLanguage = {""};
        int priority = 0;
        for (auto language : event.languages) {
            eventLanguage.languageName = language;
            int index = Scheduling::search(scheduler.languages, language);
            eventLanguage.numOfTranslators =
                (index != LANGUAGE_NOT_FOUND) ? scheduler.languages[index].numOfTranslators : 0;
            eventLanguage.priority = priority++;  // this is for knowing the order of input
            sort(event.eventLanguages.begin(), event.eventLanguages.end(),
                 Scheduling::language_of_event_compare);
            event.eventLanguages.push_back(eventLanguage);
        }
    }
}

void addNew(Data::EventScheduler& scheduler, std::string name, int translatorIndex) {
    scheduler.languages.push_back(
        Data::Language(name, 1, {scheduler.translators[translatorIndex]}));
}

void addExisting(Data::EventScheduler& scheduler, int index, int translatorIndex) {
    scheduler.languages[index].numOfTranslators++;
    scheduler.languages[index].translators.push_back(scheduler.translators[translatorIndex]);
}

std::ifstream& operator>>(std::ifstream& file, Data::Time& time) {
    file >> time.hour;
    file >> time.minute;
    return file;
}

std::ifstream& operator>>(std::ifstream& file, Data::Translator& translator) {
    file >> translator.name;
    file >> translator.availableTimePeriod.start >> translator.availableTimePeriod.end;
    std::string languagesNames;
    std::getline(file, languagesNames);
    translator.languages =
        split(languagesNames.substr(1));  // cause we have an extra space in the beginning
    translator.numOfLanguages = translator.languages.size();
    return file;
}

std::ifstream& operator>>(std::ifstream& file, Data::Event& event) {
    file >> event.name;
    file >> event.timePeriod.start >> event.timePeriod.end;
    std::string languagesNames;
    std::getline(file, languagesNames);
    event.languages =
        split(languagesNames.substr(1));  // cause we have an extra space in the beginning
    return file;
}

std::vector<std::string> split(const std::string s, std::string reg = "\\s+") {
    std::regex ws_re(reg);
    std::vector<std::string> tokens;
    std::copy(std::sregex_token_iterator(s.begin(), s.end(), ws_re, -1),
              std::sregex_token_iterator(), std::back_inserter(tokens));
    return tokens;
}
}  // namespace Input

namespace Scheduling {

int search(const Data::Languages& languages, const std::string& name) {
    auto it = std::find_if(languages.begin(), languages.end(),
                           [&name](const Data::Language& lang) { return lang.name == name; });

    if (it != languages.end()) 
        return std::distance(languages.begin(), it);
    else 
        return LANGUAGE_NOT_FOUND;
}

bool language_of_event_compare(const Data::EventsLanguage& first,
                               const Data::EventsLanguage& second) {
    return first.numOfTranslators < second.numOfTranslators;
}

bool language_of_event_compare_for_priority(const Data::EventsLanguage& first,
                                            const Data::EventsLanguage& second) {
    return first.priority < second.priority;
}

bool is_before(Data::Time first, Data::Time second) {
    return (first.hour < second.hour) ||
           ((first.hour == second.hour) && (first.minute < second.minute));
}

bool is_overlapping(Data::TimePeriod first, Data::TimePeriod second) {
    return (is_before(second.start, first.start) || is_before(second.start, first.end)) &&
           (is_before(first.start, second.start) || is_before(first.start, second.end));
}

bool is_available(std::shared_ptr<Data::Translator> translatorPtr,
                  Data::TimePeriod goalTimePeriod) {
    if (is_before(goalTimePeriod.start, translatorPtr->availableTimePeriod.start) ||
        is_before(translatorPtr->availableTimePeriod.end, goalTimePeriod.end))
        return false;
    for (auto element : translatorPtr->occupiedTimes)
        if (is_overlapping(element, goalTimePeriod)) return false;
    return true;
}

std::shared_ptr<Data::Translator> find_first_available_translator(
    int languageIndex, const Data::EventScheduler& scheduler, Data::TimePeriod goalPeriod) {
    for (int i = 0; i < scheduler.languages[languageIndex].translators.size(); i++) {
        auto translatorPtr = scheduler.languages[languageIndex].translators[i];
        if (is_available(translatorPtr, goalPeriod)) return translatorPtr;
    }
    return nullptr;
}

void schedule(Data::EventScheduler& scheduler) {
    for (int i = 0; i < scheduler.events.size(); i++) {
        for (int j = 0; j < scheduler.events[i].eventLanguages.size(); j++) {
            int languageIndex =
                search(scheduler.languages, scheduler.events[i].eventLanguages[j].languageName);
            std::shared_ptr<Data::Translator> translatorPtr = nullptr;
            if (languageIndex != LANGUAGE_NOT_FOUND)
                translatorPtr = find_first_available_translator(languageIndex, scheduler,
                                                                scheduler.events[i].timePeriod);
            if (translatorPtr == nullptr)
                scheduler.events[i].eventLanguages[j].translatorName = NO_TRANSLATOR_FOUND;
            else {
                scheduler.events[i].eventLanguages[j].translatorName = translatorPtr->name;
                translatorPtr->occupiedTimes.push_back(scheduler.events[i].timePeriod);
            }
        }
        sort(scheduler.events[i].eventLanguages.begin(), scheduler.events[i].eventLanguages.end(),
             language_of_event_compare_for_priority);
    }
}

}  // namespace Scheduling

namespace Output {

void display(const Data::EventScheduler& scheduler) {
    for (auto element : scheduler.events) {
        std::cout << element.name << std::endl;
        for (auto language : element.eventLanguages)
            std::cout << language.languageName << OUTPUT_DELIMETER << language.translatorName
                      << std::endl;
    }
}

}  // namespace Output

int main(int argc, const char* argv[]) {

    Data::EventScheduler scheduler;

    try {
        Input::readInput(scheduler, argv[argc - 1]);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    Scheduling::schedule(scheduler);

    Output::display(scheduler);

    return 0;
}

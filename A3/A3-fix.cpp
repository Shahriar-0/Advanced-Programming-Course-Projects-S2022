#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

// clang format off
const std::string NO_TRANSLATOR_FOUND = "Not Found";
const std::string OUTPUT_DELIMETER = ": ";
const std::string ERROR_1 = "haven't pass the argument";

const char* SPLIT_CHAR = " ";
const int LANGUAGE_NOT_FOUND = -1;
// clang format on

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
};

struct Language {
    Language(std::string name, int numOfTranslators, std::vector<std::unique_ptr<Translator>> translators)
        : name(name), numOfTranslators(numOfTranslators), translators(std::move(translators)) {}
    std::string name;
    int numOfTranslators;
    std::vector<std::unique_ptr<Translator>> translators;
};

using Languages = std::vector<Language>;
using Translators = std::vector<Translator>;
using Events = std::vector<Event>;
using TranslatorPointer = std::unique_ptr<Translator>;

struct EventScheduler {
    Languages languages;
    Translators translators;
    Events events;
};

}  // namespace Data

namespace Input {

void readInput(Data::EventScheduler& scheduler, const std::string fileName) {
    std::ifstream file(fileName);
    if (!file.is_open())
        throw std::runtime_error(ERROR_1);

    readTranslators(scheduler, file);
}

void readTranslators(Data::EventScheduler& scheduler, std::ifstream& file) {
    int numOfTranslators;
    file >> numOfTranslators;
    scheduler.translators.reserve(numOfTranslators);
    for (int i = 0; i < numOfTranslators; ++i) {
        Data::Translator translator;
        file >> translator;
        scheduler.translators.push_back(translator);
        for (auto language : translator.languages) {
            int index = Scheduling::search(scheduler.languages, language);
            if (index == LANGUAGE_NOT_FOUND) {
            }
        }
    }
}

void addNew(Data::EventScheduler& scheduler, std::string name, int translatorIndex) {
    scheduler.languages.push_back(Data::Language(name, 1, {std::make_unique<Data::Translator>(scheduler.translators[translatorIndex])}));
}

void addExisting(Data::EventScheduler& scheduler, int index, int translatorIndex) {
    scheduler.languages[index].numOfTranslators++;
    scheduler.languages[index].translators.push_back(std::make_unique<Data::Translator>(scheduler.translators[translatorIndex]));
}

std::ifstream& operator>>(std::ifstream& file, Data::Translator& translator) {
    file >> translator.name;
    file >> translator.availableTimePeriod.start.hour;
    file >> translator.availableTimePeriod.start.minute;
    file >> translator.availableTimePeriod.end.hour;
    file >> translator.availableTimePeriod.end.minute;
    std::string languagesNames;
    std::getline(file, languagesNames);
    translator.languages = split(languagesNames.substr(1));  // cause we have an extra space in thr beginning
    translator.numOfLanguages = translator.languages.size();
    return file;
}

std::vector<std::string> split(const std::string s, std::string reg = "\\s+") {
    std::regex ws_re(reg);
    std::vector<std::string> tokens;
    std::copy(std::sregex_token_iterator(s.begin(), s.end(), ws_re, -1),
              std::sregex_token_iterator(),
              std::back_inserter(tokens));
    return tokens;
}
}  // namespace Input

namespace Scheduling {

int search(const Data::Languages& languages, const std::string& name) {
    auto it = std::find_if(languages.begin(), languages.end(),
                           [&name](const Data::Language& lang) {
                               return lang.name == name;
                           });

    if (it != languages.end()) {
        return std::distance(languages.begin(), it);
    } else {
        return LANGUAGE_NOT_FOUND;
    }
}

void schedule(Data::EventScheduler& scheduler) {
    //...
    // schedule events
}

}  // namespace Scheduling

namespace Output {

void display(const Data::EventScheduler& scheduler) {
    //...
    // display scheduled events
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
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define NO_TRANSLATOR_FOUND "Not Found"
#define LANGUAGE_NOT_FOUND -1
#define SPLIT_CHAR " "
#define OUTPUT_DELIMETER ": "
#define ERROR_1 "haven't pass the argument"

using namespace std;

struct Time {
    int hour;
    int minute;
};

struct TimePeriod {
    Time start;
    Time end;
};

struct Translator {
    string name;
    TimePeriod availableTimePeriod;
    vector<TimePeriod> occupiedTimes;
    int numOfLanguages;
};

struct EventsLanguage {
    string languageName;
    string translatorName;
    int numOfTranslators;
    int priority;
};

struct Event {
    string name;
    TimePeriod timePeriod;
    vector<EventsLanguage> eventLanguages;
};

struct Language {
    string name;
    int numOfTranslators;
    vector<Translator*> translators;
};

typedef vector<Language> Languages;
typedef vector<Translator> Translators;
typedef vector<Event> Events;
typedef Translator* TranslatorPointer;

void get_input(string, Languages&, Translators&, Events&);
void initialising_data(string, Languages&, Translators&, Events&);
void check_for_file_validation(ifstream&);
void read_languages(ifstream&, Languages&, Translators&);
Time read_time_format(ifstream&);
Translator read_translator_info(ifstream&);
int search(const Languages&, string);
void add_new(Languages&, string, Translators&, int);
void add_existing(Languages&, string, Translators&, int, int);
void read_events(ifstream&, Events&, const Languages&);
vector<string> read_list_of_languages(ifstream&);
vector<string> string_tokenizer(char*);
void sorting_languages(Languages&);
bool name_compare(string, string);
bool translator_compare(const TranslatorPointer&, const TranslatorPointer&);
bool language_of_event_compare(const EventsLanguage&, const EventsLanguage&);
bool language_of_event_compare_for_priority(const EventsLanguage&, const EventsLanguage&);
void dedicate_time(Events&, const Languages&);
bool is_before(Time, Time);
bool is_available(TranslatorPointer, TimePeriod);
bool is_overlapping(TimePeriod, TimePeriod);
TranslatorPointer find_first_available_translator(int, const Languages&, TimePeriod);
void show_result(const Events&);

int main(int argc, const char* argv[]) {
    Languages languagesList;
    Translators translatorsList;
    Events eventsList;
    initialising_data(argv[argc - 1], languagesList, translatorsList, eventsList);
    dedicate_time(eventsList, languagesList);
    show_result(eventsList);
    return EXIT_SUCCESS;
}

void initialising_data(string inputFile, Languages& languagesList, Translators& translatorsList, Events& eventsList) {
    get_input(inputFile, languagesList, translatorsList, eventsList);
    sorting_languages(languagesList);
}

void sorting_languages(Languages& languagesList) {
    for (int i = 0; i < languagesList.size(); i++)
        sort(languagesList[i].translators.begin(), languagesList[i].translators.end(), translator_compare);
}

bool translator_compare(const TranslatorPointer& first, const TranslatorPointer& second) {
    return first->numOfLanguages < second->numOfLanguages ||
           ((second->numOfLanguages == first->numOfLanguages) && name_compare(first->name, second->name));
}

bool name_compare(string first, string second) {
    int i = 0;
    for (; i < max(first.size(), second.size()); i++) {
        if (first[i] != second[i])
            return first[i] < second[i];
    }
    return true;  // when both are equal
}

void get_input(string inputFile, Languages& languagesList, Translators& translatorsList, Events& eventsList) {
    ifstream fileStream(inputFile);
    check_for_file_validation(fileStream);
    read_languages(fileStream, languagesList, translatorsList);
    read_events(fileStream, eventsList, languagesList);
    fileStream.close();
}

void check_for_file_validation(ifstream& inputFile) {
    if (!inputFile.is_open()) {
        cerr << ERROR_1 << endl;
        exit(EXIT_FAILURE);
    }
}

void read_languages(ifstream& fileStream, Languages& languagesList, Translators& translatorsList) {
    int lineCount;
    fileStream >> lineCount;
    translatorsList.resize(lineCount);
    for (int i = 0; i < lineCount; i++) {
        Translator translator = read_translator_info(fileStream);
        translatorsList[i] = translator;
        vector<string> splittedLanguages = read_list_of_languages(fileStream);
        translatorsList[i].numOfLanguages = splittedLanguages.size();
        for (auto singleLanguageName : splittedLanguages) {
            int languageIndex = search(languagesList, singleLanguageName);

            if (languageIndex == LANGUAGE_NOT_FOUND)
                add_new(languagesList, singleLanguageName, translatorsList, i);
            else
                add_existing(languagesList, singleLanguageName, translatorsList, i, languageIndex);
        }
    }
}

void add_new(Languages& languagesList, string name, Translators& translatorsList, int translatorIndex) {
    languagesList.resize(languagesList.size() + 1);
    languagesList[languagesList.size() - 1].name = name;
    languagesList[languagesList.size() - 1].numOfTranslators = 1;  // it's the first translator
    languagesList[languagesList.size() - 1].translators.push_back(&translatorsList[translatorIndex]);
}

void add_existing(Languages& languagesList, string name, Translators& translatorsList, int translatorIndex, int index) {
    languagesList[index].numOfTranslators++;
    languagesList[index].translators.push_back(&translatorsList[translatorIndex]);
}

int search(const Languages& languages, string name) {
    for (int i = 0; i < languages.size(); i++) {
        if (languages[i].name == name)
            return i;
    }
    return LANGUAGE_NOT_FOUND;
}

Translator read_translator_info(ifstream& fileStream) {
    Translator translator;
    fileStream >> translator.name;
    translator.availableTimePeriod.start = read_time_format(fileStream);
    translator.availableTimePeriod.end = read_time_format(fileStream);
    return translator;
}

Time read_time_format(ifstream& fileStream) {
    Time time;
    fileStream >> time.hour;
    char letter;
    fileStream >> letter;
    fileStream >> time.minute;
    return time;
}

vector<string> read_list_of_languages(ifstream& fileStream) {
    string languagesName;
    getline(fileStream, languagesName);
    languagesName = languagesName.substr(1);  // cause we have an extra space in thr beginning
    return string_tokenizer(&languagesName[0]);
}

vector<string> string_tokenizer(char* str) {
    vector<string> result;
    str = strtok(str, SPLIT_CHAR);
    while (str != NULL) {
        string singleLanguageName(str);
        result.push_back(singleLanguageName);
        str = strtok(NULL, SPLIT_CHAR);
    }
    return result;
}

void read_events(ifstream& fileStream, Events& eventsList, const Languages& languagesList) {
    int lineCount;
    fileStream >> lineCount;
    while (lineCount--) {
        Event event;
        fileStream >> event.name;
        event.timePeriod.start = read_time_format(fileStream);
        event.timePeriod.end = read_time_format(fileStream);
        vector<string> splittedLanguages = read_list_of_languages(fileStream);
        EventsLanguage eventLanguage = {""};
        int priority = 0;
        for (auto singleLanguageName : splittedLanguages) {
            eventLanguage.languageName = singleLanguageName;
            int index = search(languagesList, singleLanguageName);
            if (index == LANGUAGE_NOT_FOUND)
                eventLanguage.numOfTranslators = 0;
            else
                eventLanguage.numOfTranslators = languagesList[index].numOfTranslators;
            eventLanguage.priority = priority;  // this is for knowing the order of input
            priority++;
            event.eventLanguages.push_back(eventLanguage);
        }
        sort(event.eventLanguages.begin(), event.eventLanguages.end(), language_of_event_compare);
        eventsList.push_back(event);
    }
}

bool language_of_event_compare(const EventsLanguage& first, const EventsLanguage& second) {
    return first.numOfTranslators < second.numOfTranslators;
}

bool language_of_event_compare_for_priority(const EventsLanguage& first, const EventsLanguage& second) {
    return first.priority < second.priority;
}

void dedicate_time(Events& eventsList, const Languages& languageList) {
    for (int i = 0; i < eventsList.size(); i++) {
        for (int j = 0; j < eventsList[i].eventLanguages.size(); j++) {
            int languageIndex = search(languageList, eventsList[i].eventLanguages[j].languageName);
            TranslatorPointer translatorPtr = nullptr;
            if (languageIndex != LANGUAGE_NOT_FOUND)
                translatorPtr = find_first_available_translator(languageIndex, languageList, eventsList[i].timePeriod);
            if (translatorPtr == nullptr)
                eventsList[i].eventLanguages[j].translatorName = NO_TRANSLATOR_FOUND;
            else {
                eventsList[i].eventLanguages[j].translatorName = translatorPtr->name;
                translatorPtr->occupiedTimes.push_back(eventsList[i].timePeriod);
            }
        }
        sort(eventsList[i].eventLanguages.begin(), eventsList[i].eventLanguages.end(),
             language_of_event_compare_for_priority);
    }
}

bool is_before(Time first, Time second) {
    return (first.hour < second.hour) || ((first.hour == second.hour) && (first.minute < second.minute));
}

bool is_overlapping(TimePeriod first, TimePeriod second) {
    return (is_before(second.start, first.start) || is_before(second.start, first.end)) &&
           (is_before(first.start, second.start) || is_before(first.start, second.end));
}

bool is_available(TranslatorPointer translatorPtr, TimePeriod goalTimePeriod) {
    if (is_before(goalTimePeriod.start, translatorPtr->availableTimePeriod.start) ||
        is_before(translatorPtr->availableTimePeriod.end, goalTimePeriod.end))
        return false;
    for (auto element : translatorPtr->occupiedTimes)
        if (is_overlapping(element, goalTimePeriod))
            return false;
    return true;
}

TranslatorPointer find_first_available_translator(int languageIndex, const Languages& languagesList, TimePeriod goalPeriod) {
    for (int i = 0; i < languagesList[languageIndex].translators.size(); i++)
        if (is_available(languagesList[languageIndex].translators[i], goalPeriod))
            return languagesList[languageIndex].translators[i];
    return nullptr;
}

void show_result(const Events& eventsList) {
    for (auto element : eventsList) {
        cout << element.name << endl;
        for (auto language : element.eventLanguages)
            cout << language.languageName << OUTPUT_DELIMETER << language.translatorName << endl;
    }
}

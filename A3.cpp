#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define NO_TRANSLATOR_FOUND "Not Found"
#define LANGUAGE_NOT_FOUND -1

using namespace std;

struct Time {
    int hour;
    int minute;
};

struct Translator {
    string name;
    Time startTime;
    Time endTime;
    vector<Time> occupiedTimes; 
    int numOfLanguages;
};

struct EventsLanguage {
    string languageName;
    string translatorName;
};

struct Event {
    string name;
    Time startTime;
    Time endTime;
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


void get_input(string, Languages&, Translators&, Events&);
void get_input_and_convert_to_suitable_format(string, Languages&, Translators&, Events&);
void check_for_file_validation(ifstream&);
void read_languages(ifstream&, Languages&, Translators&);
Time convert_ints_to_Time_format(int, int);
Translator read_translator_info(ifstream&);
int search(const Languages&, string);
void add_new(Languages&, string, Translator, Translators&);
void add_existing(Languages&, string, Translator, Translators&, int);
void read_events(ifstream&, Events&);


int main(int argc, const char* argv[]) {
    Languages languagesList;
    Translators translatorsList;
    Events eventsList;
}


void get_input_and_convert_to_suitable_format(string inputFile, Languages& languagesList,
    Translators& translatorsList, Events& eventsList) {
    get_input(inputFile, languagesList, translatorsList, eventsList);

}

void check_for_file_validation(ifstream& inputFile) {
    if (!inputFile.is_open()) {
        cerr << "haven't pass the argument" << endl;
        exit(EXIT_FAILURE);
    }
}

Time convert_ints_to_Time_format(int hour, int minute) {
    Time time;
    time.hour = hour;
    time.minute = minute;
    return time;
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
    int startHour, endHour, startMinute, endMinute;
    fileStream >> startHour>> startMinute >> endHour  >> endMinute;
    translator.startTime = convert_ints_to_Time_format(startHour, startMinute);
    translator.endTime = convert_ints_to_Time_format(endHour, endMinute);
    translator.numOfLanguages = 1; //at least one language is known by that translator
    return translator;
}

void add_new(Languages& languagesList, string name, Translator translator, Translators& translatorsList) {
    if (translator.name != translatorsList[translatorsList.size() - 1].name)    
        translatorsList.push_back(translator);
    else
        translatorsList[translatorsList.size() - 1].numOfLanguages++; //in case someone knows more than one language
    
    languagesList.resize(languagesList.size() + 1);
    languagesList[languagesList.size() - 1].name = name;
    languagesList[languagesList.size() - 1].numOfTranslators = 1;   //it's the first translator
    languagesList[languagesList.size() - 1].translators.push_back(&translatorsList[translatorsList.size() - 1]);
}

void add_existing(Languages& languagesList, string name, Translator translator, Translators& translatorsList, int index) {
    if (translator.name != translatorsList[translatorsList.size() - 1].name)    
        translatorsList.push_back(translator);
    else
        translatorsList[translatorsList.size() - 1].numOfLanguages++; //in case someone knows more than one language

    languagesList[index].numOfTranslators++;
    languagesList[index].translators.push_back(&translatorsList[translatorsList.size() - 1]);
}

void read_languages(ifstream& fileStream, Languages& languagesList, Translators& translatorsList) {
    
    int lineCount; 
    fileStream >> lineCount;
    while (lineCount--) {
        Translator translator = read_translator_info(fileStream);
        string languageName;
        while (fileStream >> languageName) {
            int index = search(languagesList, languageName);

            if (index == LANGUAGE_NOT_FOUND) 
                add_new(languagesList, languageName, translator, translatorsList);
            else
                add_existing(languagesList, languageName, translator, translatorsList, index);
        }
    }
}


void read_events(ifstream& fileStream, Events& eventsList) {
    int lineCount; 
    fileStream >> lineCount;
    while (lineCount--) {
        Event event;
        fileStream >> event.name;
        int startHour, endHour, startMinute, endMinute;
        fileStream >> startHour>> startMinute >> endHour  >> endMinute;
        event.startTime = convert_ints_to_Time_format(startHour, startMinute);
        event.endTime = convert_ints_to_Time_format(endHour, endMinute);
        EventsLanguage eventLanguage = {""};
        while (fileStream >> eventLanguage.languageName)
            event.eventLanguages.push_back(eventLanguage);
        eventsList.push_back(event);
    }
}

void get_input(string inputFile, Languages& languagesList, Translators& translatorsList, Events& eventsList) {
    ifstream fileStream (inputFile);
    check_for_file_validation(fileStream);
    read_languages(fileStream, languagesList, translatorsList);
    read_events(fileStream, eventsList);
}

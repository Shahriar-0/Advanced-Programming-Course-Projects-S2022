#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

#define NO_TRANSLATOR_FOUND "Not Found"
#define LANGUAGE_NOT_FOUND -1
#define SPLIT_CHAR " "

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
void initialising_data(string, Languages&, Translators&, Events&);
void check_for_file_validation(ifstream&);
void read_languages(ifstream&, Languages&, Translators&);
Time read_time_format(ifstream&);
Translator read_translator_info(ifstream&);
int search(const Languages&, string);
void add_new(Languages&, string, Translator, Translators&);
void add_existing(Languages&, string, Translator, Translators&, int);
void read_events(ifstream&, Events&);
vector<string> read_list_of_languages(ifstream&);
vector<string> string_tokenizer(char*);

void print_everything(Languages languageslist, Translators translatorsList, Events eventsList) {
    cout << "languages " << endl;
    for (auto x : languageslist) {
        cout << x.name << " with " << x.numOfTranslators << " translators " << endl;
        cout << "list of translators " << endl;
        for (auto y : x.translators) {
            cout << y->name << " from " << setw(2) << setfill('0') << y->startTime.hour << ":";
            cout << setw(2) << setfill('0') << y->startTime.minute << " to ";
            cout << setw(2) << setfill('0') << y->endTime.hour << ":";
            cout << setw(2) << setfill('0') << y->endTime.minute << " to ";
            cout << "knowing " << y->numOfLanguages << " languages" << endl;
        }
    }
    cout << endl <<"************now events****************" << endl;
    for (auto x : eventsList) {
        cout << x.name << " which starts at " << setw(2) << setfill('0') << x.startTime.hour << ":";
        cout << setw(2) << setfill('0') << x.startTime.minute << " to ";
        cout << setw(2) << setfill('0') << x.endTime.hour << ":";
        cout << setw(2) << setfill('0') << x.endTime.minute << "  ";
        cout << "with this required languages ";
        for (auto y : x.eventLanguages) {
            cout << y.languageName << " ";
        }
        cout << endl;
    }
}


int main(int argc, const char* argv[]) {
    Languages languagesList;
    Translators translatorsList;
    Events eventsList;
    initialising_data(argv[argc - 1], languagesList, translatorsList, eventsList);
    print_everything(languagesList, translatorsList, eventsList);
}


void initialising_data(string inputFile, Languages& languagesList,
    Translators& translatorsList, Events& eventsList) {
    get_input(inputFile, languagesList, translatorsList, eventsList);

}

void check_for_file_validation(ifstream& inputFile) {
    if (!inputFile.is_open()) {
        cerr << "haven't pass the argument" << endl;
        exit(EXIT_FAILURE);
    }
}

Time read_time_format(ifstream& fileStream) {
    Time time;
    fileStream >> time.hour;
    char letter;
    fileStream >> letter;
    fileStream >> time.minute;
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
    translator.startTime = read_time_format(fileStream);
    translator.endTime = read_time_format(fileStream);
    translator.numOfLanguages = 1; //at least one language is known by that translator
    return translator;
}

void add_new(Languages& languagesList, string name, Translator translator, Translators& translatorsList) {
    if (translatorsList.empty() || translator.name != translatorsList[translatorsList.size() - 1].name)    
        translatorsList.push_back(translator);
    else
        translatorsList[translatorsList.size() - 1].numOfLanguages++; //in case someone knows more than one language
    
    languagesList.resize(languagesList.size() + 1);
    languagesList[languagesList.size() - 1].name = name;
    languagesList[languagesList.size() - 1].numOfTranslators = 1;   //it's the first translator
    languagesList[languagesList.size() - 1].translators.push_back(&translatorsList[translatorsList.size() - 1]);
}

void add_existing(Languages& languagesList, string name, Translator translator, Translators& translatorsList, int index) {
    if (translatorsList.empty() || translator.name != translatorsList[translatorsList.size() - 1].name)    
        translatorsList.push_back(translator);
    else
        translatorsList[translatorsList.size() - 1].numOfLanguages++; //in case someone knows more than one language

    languagesList[index].numOfTranslators++;
    languagesList[index].translators.push_back(&translatorsList[translatorsList.size() - 1]);
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

vector<string> read_list_of_languages(ifstream& fileStream) {
    string languagesName;
    getline(fileStream, languagesName);
    languagesName = languagesName.substr(1); //cause we have an extra space
    return string_tokenizer(&languagesName[0]);
}

void read_languages(ifstream& fileStream, Languages& languagesList, Translators& translatorsList) {
    
    int lineCount; 
    fileStream >> lineCount;
    translatorsList.resize(lineCount);
    while (lineCount--) {
        Translator translator = read_translator_info(fileStream);
        vector<string> splittedLanguages = read_list_of_languages(fileStream);
        for (auto singleLanguageName : splittedLanguages) {
            int index = search(languagesList, singleLanguageName);

            if (index == LANGUAGE_NOT_FOUND) 
                add_new(languagesList, singleLanguageName, translator, translatorsList);
            else
                add_existing(languagesList, singleLanguageName, translator, translatorsList, index);
        }
    }
}


void read_events(ifstream& fileStream, Events& eventsList) {
    int lineCount; 
    fileStream >> lineCount;
    while (lineCount--) {
        Event event;
        fileStream >> event.name;
        event.startTime = read_time_format(fileStream);
        event.endTime = read_time_format(fileStream);
        vector<string> splittedLanguages = read_list_of_languages(fileStream);
        EventsLanguage eventLanguage = {""};
        for (auto singleLanguageName : splittedLanguages) { 
            eventLanguage.languageName = singleLanguageName;
            event.eventLanguages.push_back(eventLanguage);
        }
        
        eventsList.push_back(event);
    }
}

void get_input(string inputFile, Languages& languagesList, Translators& translatorsList, Events& eventsList) {
    ifstream fileStream (inputFile);
    check_for_file_validation(fileStream);
    read_languages(fileStream, languagesList, translatorsList);
    read_events(fileStream, eventsList);
}

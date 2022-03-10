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
void read_events(ifstream&, Events&);
vector<string> read_list_of_languages(ifstream&);
vector<string> string_tokenizer(char*);
void sorting_languages(Languages&);
bool name_compare(string, string);
bool translator_compare(const TranslatorPointer&, const TranslatorPointer&);
bool language_compare(const Language&, const Language&);


void print_everything(Languages languageslist, Translators translatorsList, Events eventsList) {
    for (auto x : languageslist) {
        cout << x.name << " with " << x.numOfTranslators << " translators " << endl;
        cout << "************list of translators************" << endl;
        for (auto y : x.translators) {
            cout << y->name << " from " << setw(2) << setfill('0') << y->startTime.hour << ":";
            cout << setw(2) << setfill('0') << y->startTime.minute << " to ";
            cout << setw(2) << setfill('0') << y->endTime.hour << ":";
            cout << setw(2) << setfill('0') << y->endTime.minute << " ";
            cout << "knowing " << y->numOfLanguages << " languages" << endl;
        }
        cout << "--------------------------------" << endl;
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
    //print_everything(languagesList, translatorsList, eventsList);
}


void initialising_data(string inputFile, Languages& languagesList,
    Translators& translatorsList, Events& eventsList) {
    get_input(inputFile, languagesList, translatorsList, eventsList);
    sorting_languages(languagesList);
    //TODO: sorting languages and translators inside them
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

void add_new(Languages& languagesList, string name, Translators& translatorsList, int translatorIndex) {
    languagesList.resize(languagesList.size() + 1);
    languagesList[languagesList.size() - 1].name = name;
    languagesList[languagesList.size() - 1].numOfTranslators = 1;   //it's the first translator
    languagesList[languagesList.size() - 1].translators.push_back(&translatorsList[translatorIndex]);
}

void add_existing(Languages& languagesList, string name, Translators& translatorsList, int translatorIndex, int index) {
    languagesList[index].numOfTranslators++;
    languagesList[index].translators.push_back(&translatorsList[translatorIndex]);
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
                add_existing(languagesList, singleLanguageName, translatorsList, i,languageIndex);
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

bool language_compare(const Language& first, const Language& second) {
    return first.numOfTranslators < second.numOfTranslators;
}

bool name_compare(string first, string second) {
	int i = 0;
	for (; i < max(first.size(), second.size()); i++) {
		if (first[i] != second[i])
			return first[i] < second[i];
	}
	return true;    //when both are equal
}

bool translator_compare(const TranslatorPointer& first, const TranslatorPointer& second) {
    if (first->numOfLanguages < second->numOfLanguages) 
        return true;
    else if (second->numOfLanguages == first->numOfLanguages) 
        return name_compare(first->name, second->name);
    return false;
}

void sorting_languages(Languages& languagesList) {
    sort(languagesList.begin(), languagesList.end(), language_compare);
    for (auto element : languagesList) 
        sort(element.translators.begin(), element.translators.end(), translator_compare);
}

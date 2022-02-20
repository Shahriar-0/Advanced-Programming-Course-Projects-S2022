#include <unordered_map>
#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>

#define MINUTES_PER_HOUR 60
#define START_HOUR 12
#define START_MINUTE 0
#define END_HOUR 20
#define END_MINUTE 0

using namespace std;

typedef struct Time_format {
    int hour;
    int minute;
} Time_format;

typedef struct Time_period {
    Time_format begin;
    Time_format end;
    Time_format currentTime;
    int duration;
    int range_id;
} Time_period;


void strind_to_time_format(char*, Time_period*);
void getting_input(vector<Time_period>*, vector<Time_period>*);
int time_diffence(Time_period, Time_period);
void find_free_times(vector<Time_period>, vector<Time_period>*);
void showing_results(vector<Time_period>, vector<Time_period>);
void add_and_wrap_time(Time_format*, int);


int main(void) {    
    //initializing
    vector<Time_period> occupiedTimes, freeTimes, activites;
    getting_input(&occupiedTimes, &activites);
    find_free_times(occupiedTimes, &freeTimes);
    showing_results(freeTimes, activites);
    return 0;
}

int time_diffence(Time_format first, Time_format second) {
    //to simply calculate the difference between two time
    return second.hour * MINUTES_PER_HOUR + second.minute - 
        (first.hour * MINUTES_PER_HOUR + first.minute);
}

void strind_to_time_format(char* timeInString, Time_period* pointerToTime) {
    //just to convert string in valid format to store
    pointerToTime->begin.hour = atoi(strtok(timeInString, " :"));
    pointerToTime->begin.minute = atoi(strtok(NULL, " -"));
    pointerToTime->end.hour = atoi(strtok(NULL, " :"));
    pointerToTime->end.minute = atoi(strtok(NULL, " -"));
    pointerToTime->duration = time_diffence(pointerToTime->begin, pointerToTime->end);
    pointerToTime->currentTime = pointerToTime->begin;
    pointerToTime->range_id = 0;
}

void getting_input(vector<Time_period>* occupiedTimes, vector<Time_period>* activites) {
    //a function to get initial values for us
    string line;
    Time_period time;

    //recieving occupied times
    while (cin >> line && line != "#") {
        strind_to_time_format(&line[0], &time);
        (*occupiedTimes).push_back(time);
    }
    //just to be easier when calculating free times
    time.begin.hour = END_HOUR;
    time.begin.minute = END_MINUTE;
    time.end.hour = END_HOUR;
    time.end.minute = END_MINUTE;
    time.duration = time.range_id = 0;
    (*occupiedTimes).push_back(time);

    time = {0};
    //recieving activities
    while (cin >> time.duration && cin >> time.range_id) 
        (*activites).push_back(time);
}

void find_free_times(vector<Time_period> occupiedTimes, vector<Time_period>* freeTimes) {
    //now we move and find free times

    Time_format currentTime;
    currentTime.hour = START_HOUR;
    currentTime.minute = START_MINUTE;
    for (int i = 0; i < occupiedTimes.size(); i++) {
        if (time_diffence(currentTime, occupiedTimes[i].begin) > 0) {
            //put it in a value
            Time_period period;
            period.currentTime = period.begin = currentTime;
            period.end = occupiedTimes[i].begin;
            period.duration = time_diffence(currentTime, occupiedTimes[i].begin);
            period.range_id = 0;

            //add it to the list
            (*freeTimes).push_back(period);
        }
        currentTime = occupiedTimes[i].end;
    }
}

void showing_results(vector<Time_period> freeTimes, vector<Time_period> activites) {
    //showing times by going through each activity and give it a time
    
    for (int i = 0; i < activites.size(); i++) {
        int index = activites[i].range_id - 1;
        cout << i + 1 << " ";
        cout << setw(2) << setfill('0') << freeTimes[index].currentTime.hour << ":" <<
                setw(2) << setfill('0') << freeTimes[index].currentTime.minute << "-";
        add_and_wrap_time(&(freeTimes[index].currentTime), activites[i].duration);
        cout << setw(2) << setfill('0') << freeTimes[index].currentTime.hour << ":" <<
                setw(2) << setfill('0') << freeTimes[index].currentTime.minute << endl;
    }
}

void add_and_wrap_time(Time_format* time, int duration) {
    //for adding times and making some adjustments

    time->minute += duration;
    while (time->minute >= MINUTES_PER_HOUR) {
        time->hour++;
        time->minute -= MINUTES_PER_HOUR;
    }
}

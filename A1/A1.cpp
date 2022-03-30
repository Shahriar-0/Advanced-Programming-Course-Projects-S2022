//an app to schedule your activities for you 
//based on time required and free times that you got
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>

#define MINUTES_PER_HOUR 60
#define START_HOUR 12
#define START_MINUTE 00
#define END_HOUR 20
#define END_MINUTE 00

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

Time_period string_to_time_format(char*);
void getting_input(vector<Time_period>&, vector<Time_period>&);
int time_diffence(Time_period, Time_period);
void find_free_times(vector<Time_period>, vector<Time_period>&);
void showing_results(vector<Time_period>, vector<Time_period>);
void add_and_wrap_time(Time_format*, int);

int main(void) {    
    vector<Time_period> occupiedTimes, freeTimes, activites;
    getting_input(occupiedTimes, activites);
    find_free_times(occupiedTimes, freeTimes);
    showing_results(freeTimes, activites);
    return 0;
}

int time_diffence(Time_format first, Time_format second) {
    return second.hour * MINUTES_PER_HOUR + second.minute - 
        (first.hour * MINUTES_PER_HOUR + first.minute);
}

Time_period string_to_time_format(char* timeInString) {
    //just to convert string into a valid format to store
    //the parses are based on the given input format
    Time_period time;
    time.begin.hour = atoi(strtok(timeInString, " :"));
    time.begin.minute = atoi(strtok(NULL, " -"));
    time.end.hour = atoi(strtok(NULL, " :"));
    time.end.minute = atoi(strtok(NULL, " -"));
    time.duration = time_diffence(time.begin, time.end);
    time.currentTime = time.begin;
    time.range_id = 0;

    return time;
}

void getting_input(vector<Time_period>& occupiedTimes, vector<Time_period>& activites) {
    //a function to get initial values for us
    string line;
    Time_period time;

    //recieving occupied times
    while (cin >> line && line != "#") {
        time = string_to_time_format(&line[0]);
        occupiedTimes.push_back(time);
    }
    //just to be easier when calculating free times
    time.end.hour = time.begin.hour = END_HOUR;
    time.end.minute = time.begin.minute = END_MINUTE;
    time.duration = time.range_id = 0;
    occupiedTimes.push_back(time);

    time = {0};
    //recieving activities
    while (cin >> time.duration && cin >> time.range_id) 
        activites.push_back(time);
}

void find_free_times(vector<Time_period> occupiedTimes, vector<Time_period>& freeTimes) {
    //now we move through day with currentTime and find free times

    Time_format currentTime;
    currentTime.hour = START_HOUR;
    currentTime.minute = START_MINUTE;
    for (auto element : occupiedTimes) {
        if (time_diffence(currentTime, element.begin) > 0) {
            //there's a free time
            Time_period period;
            period.currentTime = period.begin = currentTime;
            period.end = element.begin;
            period.duration = time_diffence(currentTime, element.begin);
            period.range_id = 0;

            //add it to the list
            freeTimes.push_back(period);
        }
        //we are currently at the end of the last one
        currentTime = element.end;
    }
}

void showing_results(vector<Time_period> freeTimes, vector<Time_period> activites) {
    //showing times by going through each activity and give it a time
    
    for (int i = 0; i < activites.size(); i++) {
        int index = activites[i].range_id - 1;
        //the id of the activity
        cout << i + 1 << " ";

        cout << setw(2) << setfill('0') << freeTimes[index].currentTime.hour << ":" <<
                setw(2) << setfill('0') << freeTimes[index].currentTime.minute << "-";

        //to subtract the time spent on the activity from free times
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
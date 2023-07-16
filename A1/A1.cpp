#include <string.h>

#include <iomanip>
#include <iostream>
#include <vector>

namespace IO {
// clang-format off
const std::string TIMES_DELIMETER       = "-";
const std::string HOUR_MINUTE_DELIMETER = ":";
const std::string END_OF_INPUT          = "#";
const std::string ID_TIME_DELIMETER     = " ";
// clang-format on
const char FILLER = '0';
} // namespace IO

namespace Time {
typedef struct TimeFormat {
    int hour;
    int minute;
} TimeFormat;

typedef struct TimePeriod {
    TimeFormat begin;
    TimeFormat end;
    TimeFormat currentTime;
    int duration;
    int range_id;
    
} TimePeriod;
// clang-format off
constexpr int MINUTES_PER_HOUR = 60;
constexpr Time::TimeFormat START_TIME = Time::TimeFormat{12, 00};
constexpr Time::TimeFormat END_TIME   = Time::TimeFormat{20, 00};
// clang-format on
} // namespace Time


namespace Time {
int time_difference(Time::TimeFormat first, Time::TimeFormat second) {
        return (second.hour * Time::MINUTES_PER_HOUR + second.minute) -
               (first.hour * Time::MINUTES_PER_HOUR + first.minute);
}

void find_free_times(std::vector<Time::TimePeriod> occupiedTimes, std::vector<Time::TimePeriod>& freeTimes) {
    Time::TimeFormat currentTime;
    currentTime.hour = Time::START_TIME.hour;
    currentTime.minute = Time::START_TIME.minute;
    for (auto occupiedTime : occupiedTimes) {
        if (time_difference(currentTime, occupiedTime.begin) > 0) {
            Time::TimePeriod period;

            period.currentTime = period.begin = currentTime;
            period.end = occupiedTime.begin;
            period.duration = time_difference(currentTime, occupiedTime.begin);
            period.range_id = 0; // it won't be used so it's not important

            freeTimes.push_back(period);
        }
        currentTime = occupiedTime.end;
    }
}

void time_pass(Time::TimeFormat* time, int duration) {
    time->minute += duration;
    while (time->minute >= Time::MINUTES_PER_HOUR) {
        time->hour++;
        time->minute -= Time::MINUTES_PER_HOUR;
    }
}

TimePeriod string_to_time(char* str) {
    TimePeriod time;
    // clang-format off
    time.begin.hour   = atoi(strtok(str,  IO::HOUR_MINUTE_DELIMETER.c_str()));
    time.begin.minute = atoi(strtok(NULL, IO::TIMES_DELIMETER.c_str()));

    time.end.hour     = atoi(strtok(NULL, IO::HOUR_MINUTE_DELIMETER.c_str()));
    time.end.minute   = atoi(strtok(NULL, IO::TIMES_DELIMETER.c_str()));

    time.duration     = time_difference(time.begin, time.end);
    time.currentTime  = time.begin;
    time.range_id     = 0;
    // clang-format on
    return time;
}
}  // namespace Time

namespace IO {
void getting_input(std::vector<Time::TimePeriod>& occupiedTimes, std::vector<Time::TimePeriod>& activities) {
    std::string line;
    Time::TimePeriod time;

    while (std::cin >> line && line != IO::END_OF_INPUT) {
        time = Time::string_to_time(&line[0]);
        occupiedTimes.push_back(time);
    }
    // clang-format off
    time.end.hour   = time.begin.hour   = Time::END_TIME.hour;
    time.end.minute = time.begin.minute = Time::END_TIME.minute;
    time.duration   = time.range_id = 0; // these two are not used when time is occupied so it doesn't matter
    // clang-format on
    occupiedTimes.push_back(time);

    time = {0};
    while (std::cin >> time.duration && std::cin >> time.range_id)
        activities.push_back(time);
}

void showing_results(std::vector<Time::TimePeriod> freeTimes, std::vector<Time::TimePeriod> activities) {
    for (int i = 0; i < activities.size(); i++) {
        int index = activities[i].range_id - 1;
        std::cout << i + 1 << IO::ID_TIME_DELIMETER;

        std::cout << std::setw(2) << std::setfill(IO::FILLER) << freeTimes[index].currentTime.hour
                  << IO::HOUR_MINUTE_DELIMETER
                  << std::setw(2) << std::setfill(IO::FILLER) << freeTimes[index].currentTime.minute
                  << IO::TIMES_DELIMETER;

        Time::time_pass(&(freeTimes[index].currentTime), activities[i].duration);

        std::cout << std::setw(2) << std::setfill(IO::FILLER) << freeTimes[index].currentTime.hour
                  << IO::HOUR_MINUTE_DELIMETER
                  << std::setw(2) << std::setfill(IO::FILLER) << freeTimes[index].currentTime.minute
                  << std::endl;
    }
}
}  // namespace IO

int main(void) {
    std::vector<Time::TimePeriod> occupiedTimes, freeTimes, activities;
    IO::getting_input(occupiedTimes, activities);
    Time::find_free_times(occupiedTimes, freeTimes);
    IO::showing_results(freeTimes, activities);
    return 0;
}
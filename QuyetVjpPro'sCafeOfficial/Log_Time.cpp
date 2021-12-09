#include "Log_Time.h"

string Log_Time::Time()
{
    time_t current_time;
    time(&current_time);
    char buffer[30];
    ctime_s(buffer, sizeof(buffer), &current_time);
    string tmp(buffer);
    return tmp;
}

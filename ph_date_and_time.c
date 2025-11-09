#include "ph_date_and_time.h"

#include <time.h>

i32_t ph_local_timezone_hour() {
    time_t now = time(nullptr);

    struct tm local_tm = *localtime(&now);
    struct tm utc_tm = *gmtime(&now);

    time_t local_time = mktime(&local_tm);
    time_t utc_as_local = mktime(&utc_tm);

    return difftime(local_time, utc_as_local) / 3'600;
}

i32_t ph_local_timezone_second() {
    time_t now = time(nullptr);

    struct tm local_tm = *localtime(&now);
    struct tm utc_tm = *gmtime(&now);

    time_t local_time = mktime(&local_tm);
    time_t utc_as_local = mktime(&utc_tm);

    return difftime(local_time, utc_as_local);
}

str_t* ph_local_timezone_string() {
    char tz[32];
    time_t now = time(nullptr);
    struct tm* local = localtime(&now);

    strftime(tz, sizeof(tz), "%Z", local);

    char* res = tz;

    return res;
}


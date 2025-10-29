#ifndef PH_DATE_AND_TIME_H
#define PH_DATE_AND_TIME_H
#include "ph_numeric.h"

/// @brief get local timezone by hour
///
/// @return int32_t
int32_t ph_local_timezone_hour();

/// @brief get local timezone by second
///
/// @return int32_t
int32_t ph_local_timezone_second();

/// @brief get local timezone string
///
/// @return char* 
char* ph_local_timezone_string();

#endif // PH_DATE_AND_TIME_H


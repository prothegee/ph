/// ### file: date_and_time.h
/// 
/// ### author: Prana Ron
/// 
/// ---------------------------------------------------------
/// 
/// ### brief:
/// ph date and time header
/// 
/// ### note:
/// n/a
/// 
/// ---------------------------------------------------------
/// 
/// ### copyright:
/// 
/// - (c) Prana Ron // @prothegee // prothegee@proton.me
/// 
/// ### contributors:
/// 
/// - Prana Ron // @prothegee // prothegee@proton.me
/// 
#ifndef PH_DATE_AND_TIME_H
#define PH_DATE_AND_TIME_H
#include "numeric.h"
#include "string.h"

/// @brief get local timezone by hour
///
/// @return i32_t
i32_t ph_local_timezone_hour();

/// @brief get local timezone by second
///
/// @return i32_t
i32_t ph_local_timezone_second();

/// @brief get local timezone string
///
/// @note required free after used
///
/// @return str_t* 
str_t* ph_local_timezone_string();

/// @brief get timestamp with nanosecond precise
///
/// @note default UTC 0
/// @note required free after used
///
/// @return str_t*
str_t* ph_timestamp_ns();

#endif // PH_DATE_AND_TIME_H


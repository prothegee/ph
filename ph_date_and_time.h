/// ### file: ph_date_and_time.h
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
/// - (c) 2025 Prana Ron // @prothegee // prothegee@proton.me
/// 
/// ### contributors:
/// 
/// - Prana Ron // @prothegee // prothegee@proton.me
/// 
#ifndef PH_DATE_AND_TIME_H
#define PH_DATE_AND_TIME_H
#include <ph_numeric.h>
#include <ph_string.h>

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
/// @return str_t* 
str_t* ph_local_timezone_string();

#endif // PH_DATE_AND_TIME_H


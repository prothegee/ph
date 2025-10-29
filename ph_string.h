/// ### file: ph_string.h
/// 
/// ### author: Prana Ron
/// 
/// ---------------------------------------------------------
/// 
/// ### brief:
/// ph string header
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
#ifndef PH_STRING_H
#define PH_STRING_H
#include "ph_size.h"

// --------------------------------------------------------- //

/// fixed 8 size char string
typedef char str8_t[PH_SIZE_8];

/// fixed 16 size char string
typedef char str16_t[PH_SIZE_16];

/// fixed 32 size char string
typedef char str32_t[PH_SIZE_32];

/// fixed 36 size char string
typedef char str36_t[PH_SIZE_36];

/// fixed 64 size char string
typedef char str64_t[PH_SIZE_64];

/// fixed 128 size char string
typedef char str128_t[PH_SIZE_128_WIDTH];

// --------------------------------------------------------- //

#endif // PH_STRING_H


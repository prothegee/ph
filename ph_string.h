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

typedef char char_t;

/// fixed 8 size char string
typedef char_t str8_t[PH_SIZE_8_WIDTH];

/// fixed 16 size char string
typedef char_t str16_t[PH_SIZE_16_WIDTH];

/// fixed 32 size char string
typedef char_t str32_t[PH_SIZE_32_WIDTH];

/// fixed 36 size char string
typedef char_t str36_t[PH_SIZE_36_WIDTH];

/// fixed 64 size char string
typedef char_t str64_t[PH_SIZE_64_WIDTH];

/// fixed 128 size char string
typedef char_t str128_t[PH_SIZE_128_WIDTH];

// --------------------------------------------------------- //

typedef unsigned char uchar_t;

/// fixed 8 size unsigned char string
typedef uchar_t ustr8_t[PH_SIZE_8_WIDTH];

/// fixed 16 size unsigned char string
typedef uchar_t ustr16_t[PH_SIZE_16_WIDTH];

/// fixed 32 size unsigned char string
typedef uchar_t ustr32_t[PH_SIZE_32_WIDTH];

/// fixed 36 size unsigned char string
typedef uchar_t ustr36_t[PH_SIZE_36_WIDTH];

/// fixed 64 size unsigned char string
typedef uchar_t ustr64_t[PH_SIZE_64_WIDTH];

/// fixed 128 size unsigned char string
typedef uchar_t ustr128_t[PH_SIZE_128_WIDTH];

// --------------------------------------------------------- //

#endif // PH_STRING_H


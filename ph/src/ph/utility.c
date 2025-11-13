/// ### file: utility.c
/// 
/// ### author: Prana Ron
/// 
/// ---------------------------------------------------------
/// 
/// ### brief:
/// ph utility source
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
/// - (c) Prana Ron // @prothegee // prothegee@proton.me
///
#include <ph/utility.h>

bool_t ph_input_is_numeric(const str_t* input) {
    if (strlen(input) <= 0) { return false; }

    return true;
}


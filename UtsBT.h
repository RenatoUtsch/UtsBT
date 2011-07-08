#ifndef UTSCHBASICTYPES_HPP
#define UTSCHBASICTYPES_HPP
/***************************************************************************************************************
 *
 *    Project         <<<<<<<<>>>>>>>>-<<<<<<<<>>>>>>>>
 *                    <<< Utsch Basic Types - UtsBT >>>
 *                    <<<<<<<>>><>>>>>-<<<<<<<<>>>>>>>>
 *
 * Copyright (C) 2011, Renato Utsch, <renatoutsch@gmail.com>
 *
 * This software is licensed under GNU GPL license, as described
 * in the file COPYING, which you should have receibed as part of
 * this distribution. The terms are also available at:
 * http://www.gnu.org/licenses/gpl.html
 *
 * This software doesn't have ANY WARRANTY OF ANY KIND, either
 * express or implied.
 *
 **************************************************************************************************************
 *
 * >>> Utsch Basic Types File <<<
 * 
 *************************************************************************************************************/

/* =================
 * Utsch Basic Types
 * =================
 * This file defines confiable standard types to be used in any kind of application. The types are defined with
 * an u_type kind. The complete reference is:
 *
 * u_char refers to a char type / wchar_t type (defined on the options below)
 * u_uchar refers to a unsigned char type / unsigned wchar_t type (defined on the options below)
 * 
 * u_sint8 refers to a 8 bit signed intenger - Range: at least [ -128 ~ 127 ]
 * u_uint8 refers to a 8 bit unsigned intenger - Range: at least [ 0 ~ 255 ]
 *
 * u_sint16 refers to a 16 bit signed intenger - Range: at least [ -32768 ~ 38767 ]
 * u_uint16 refers to a 16 bit unsigned intenger - Range: at least [ 0 ~ 65535 ]
 *
 * u_sint32 refers to a 32 bit signed intenger - Range: at least [ -2147483648 ~ 2147483647 ]
 * u_uint32 refers to a 32 bit unsigned intenger - Range: at least [ 0 ~ 4294967295 ]
 *
 * u_sint64 refers to a 64 bit signed intenger - Range: implementation defined - at least an u_sint32
 * u_uint64 refers to a 64 bit unsigned intenger - Range: implementation defined - at least an u_uint32
 *
 * Please read the following configuration to change any aspect of the types you want to have.
 */

/* ======================================================================================================== *\
 *                                                                                                          *
 *                                                                                                          *
 *                                         <<< CONFIGURATION >>>                                            *
 *                                                                                                          *
 *                                                                                                          *
\* ======================================================================================================== */

/* Configurations for the user to change. */



/* MAXIMUM INTENGER SIZE
 *
 * Set here the maximum size in bits of the intengers that you want to use. Like, if you want to have, at
 * maximum a 32 bit intenger, put 32 in the variable.
 *
 * Configurations:
 *
 * 8 -> 8 bits intengers, the size of a 32s bit char.
 * 16 -> (8 and) 16 bits intengers, the size of a 32 bits short int.
 * 32 -> (8 and 16 and) 32 bits intengers, the size of a 32 bits int.
 * 64 -> (8 and 16 and 32 and) 64 bits intengers, the size of a 64 bits int.
 *
 * The default is 64.
 *
 * Please note that if your Operational System and your Compiler supports a bigger long int type, it
 * will be added conforming to the USE_SAFE_LONG_INT macro of this file, if you set to 64 bits the size.
 * The 64 bits size here doesn't need a 64 bits machine. It will only apply if your compiler, Operational
 * System AND computer supports it. So, its better to set as 64.
 *
 * Observation: the char type is always defined.
 */
#define BIT_MAX_SIZE 64



/* DEFAULT INTENGER SIGN
 *
 * Set here if you want to have a signed or unsigned intenger as default.
 *
 * If you want to use signed intengers on the base type (like, a 16 bit signed intenger on a u_int16),
 * set as 0. If you want to use unsigned intengers on the base type (like, a 16 bit unsigned intenger on
 * a u_int16), set as 1.
 *
 * Please remember that the u_sintX and u_uintX, where X is the number of bits, will always be defined.
 * The only thing that changes is the base one.
 *
 * The default is 0 (signed).
 */
#define DEFAULT_INTENGER_SIGN 0



/* CHAR OR WCHAR
 *
 * Set here if you want to use a wchar type. If you want to use a char type, put 0. If you want to use a
 * wchar_t type, put 1.
 *
 * If you put 1, use the variable u_char normally. It will be the wchar_t type. This makes veeery easy to
 * change between a char and wchar_t type on a program. You only have to change this definition.
 *
 * The default is 0 (char).
 */
#define USE_WCHAR 0



/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> DO NOT MODIFY FROM HERE! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */



/* ======================================================================================================== *\
 *                                                                                                          *
 *                                                                                                          *
 *                                         <<< CONF CHECKING >>>                                            *
 *                                                                                                          *
 *                                                                                                          *
\* ======================================================================================================== */

/* Checks the configuration set by the users. */



/* Checks if BIT_MAX_SIZE was set correctly. */
#if BIT_MAX_SIZE != 8 && BIT_MAX_SIZE != 16 && BIT_MAX_SIZE != 32 && BIT_MAX_SIZE != 64
#    error error@UtsBT: The BIT_MAX_SIZE macro was set incorrectly.
#endif

/* Checks if USE_SAFE_LONG_INT was set correctly. */
#if USE_SAFE_LONG_INT != 0 && USE_SAFE_LONG_INT != 1
#    error error@UtsBT: The USE_SAFE_LONG_INT macro was set incorrectly.
#endif

/* Checks if DEFAULT_INTENGER_SIGN was set correctly. */
#if DEFAULT_INTENGER_SIGN != 0 && DEFAULT_INTENGER_SIGN != 1
#    error error@UtsBT: The DEFAULT_INTENGER_SIGN macro was set incorrectly.
#endif

/* Checks if USE_WCHAR was set correctly. */
#if USE_WCHAR != 0 && USE_WCHAR != 1
#    error error@utsBT: The USE_WCHAR macro was set incorrectly.
#endif



/* ======================================================================================================== *\
 *                                                                                                          *
 *                                                                                                          *
 *                                            <<< INTERNAL >>>                                              *
 *                                                                                                          *
 *                                                                                                          *
\* ======================================================================================================== */

/* Here, includes the needed headers and declares the internal macros. */



/* First, declares the internal macros. */



/* The copyright is declared. */
#define UTSBT_COPYRIGHT "Copyright (C) 2011, Renato Utsch, <renatoutsch@gmail.com>"

/* The version in a string. */
#define UTSBT_VERSION "1.0"

/* The version is available in two parts: */
#define UTSBT_VERSION_MAJOR 1
#define UTSBT_VERSION_MINOR 0

/* It is also available in a hexadecimal to compare against versions. */
#define UTSBT_VERSION_HEX 0x0100;



/* Then, the inclusions. */



/* Here, the #include directives, separed for C and C++. */
#ifdef __cplusplus
#    include <climits> /* Used to calculate the limits with the intenger types. */
#
#    if USE_WCHAR == 1
#        include <cwchar> /* To use the wchar_t type. */
#    endif
#
#else
#    include <limits.h> /* Used to calculate the limits with the intenger types. */
#
#    if USE_WCHAR == 1
#        include <wchar.h> /* To use the wchar_t type. */
#    endif
#
#endif


/* Now, for a bit extra security, tests if the compiler has supplied a conformant <limits.h> file... */
#if !defined(CHAR_BIT) || !defined(SCHAR_MIN) || !defined(SCHAR_MAX) || !defined(UCHAR_MAX) || \
  !defined(CHAR_MIN) || !defined(CHAR_MAX) || !defined(SHRT_MIN) || !defined(SHRT_MAX) || \
  !defined(USHRT_MAX) || !defined(INT_MIN) || !defined(INT_MAX) || !defined(UINT_MAX) || \
  !defined(LONG_MIN) || !defined(LONG_MAX) || !defined(ULONG_MAX)
#    error error@UtsBT: <limits.h> / <climits> is not conformant with ISO C.
#endif



/* ======================================================================================================== *\
 *                                                                                                          *
 *                                                                                                          *
 *                                             <<< TYPES >>>                                                *
 *                                                                                                          *
 *                                                                                                          *
\* ======================================================================================================== */

/* Defines the proper types. */



/*************************************************************************************************************
 *
 * Intengers with guaranteed MINIMUM and MAXIMUM sizes.
 *
 ************************************************************************************************************/

/* Defines the char type. Guarantees at least the (-128) ~ 127 size. */
#if USE_WCHAR == 0 /* If is a normal char... */
#    if CHAR_MIN == (-128) /* Checks if starts as a 'signed' char. */
#        if CHAR_MAX == 0x7F /* And checks if ends as a 'signed' char. */
             typedef char u_char;
#            define U_CHAR_DEFINED 0
#        else /* If the size is wrong. */
#            error error@UtsBT: The char type does not have the correct size.
#        endif
#
#    else /* Checks if starts as an 'unsigned' char. */
#        if CHAR_MAX == 0xFF /* And checks if ends as an 'unsigned' char. */
             typedef char u_char
#            define U_CHAR_DEFINED 0
#        else /* If the size is wrong. */
#            error error@UtsBT: The char type does not have the correct size.
#        endif
#    endif
#
#elif USE_WCHAR == 1 /* If is a wchar_t char... */
# /* Needs to implement... */
#endif



/* Defines the u_sint8 and u_uint8 types.
 * Guarantees at least the [(-128) ~ 127] / [0 ~ 255] size
 */
#if BIT_MAX_SIZE >= 8 /* Checks if is to support the 8 bits int. */
#    if SCHAR_MIN <= (-128) /* Checks if starts as a signed int8. */
#        if SCHAR_MAX >= 0x7F /* And checks if ends as a signed int8. */
             typedef signed char u_sint8;
#            define U_SINT8_DEFINED 0
#        else /* If the size is wrong. */
#            error error@UtsBT: The 8 bits signed int type does not have the correct size.
#        endif
#    else /* If the size is wrong. */
#        error error@UtsBT: The 8 bits signed int type does not have the correct size.
#    endif
#
#    if UCHAR_MAX >= 0xFF /* Checks if ends as an unsigned int8. */
         typedef unsigned char u_uint8;
#        define U_UINT8_DEFINED 0
#    else /* If the size is wrong. */
#        error error@UtsBT: The 8 bits unsigned int type does not have the correct size.
#    endif
#

/* Now, sets the base int8 type. */
#    if DEFAULT_INTENGER_SIGN == 0
         typedef u_sint8 u_int8;
#        define U_INT8_DEFINED 0
#        define U_INT8_IS_SIGNED 0 /* To be used as additional error checking... */
#    else /* DEFAULT_INTENGER_SIGN == 1 */
         typedef u_uint8 u_int8;
#        define U_INT8_DEFINED 0
#        define U_INT8_IS_UNSIGNED 0 /* To be used as additional error checking... */
#    endif /* DEFAULT_INTENGER_SIGN == 0 */

/* End of int8 types. */
#endif /* BIT_MAX_SIZE >= 8 */



/* Now defines the u_sint16 and u_uint16 types. Guarantees at least the
 * [(-32768) ~ 32767] / [0 ~ 65535] size.
 */
#if BIT_MAX_SIZE >= 16 /* Checks if is to support the 16 bits sign. */
#    if SHRT_MIN <= (-32768) /* Checks if starts as a signed int16. */
#        if SHRT_MAX >= 0x7FFF /* Checks if ends as a signed int16. */
             typedef signed short int u_sint16;
#            define U_SINT16_DEFINED 0
#        else /* If the size is wrong. */
#            error error@UtsBT: The 16 bits signed int type does not have the correct size.
#        endif
#    else /* If the size is wrong. */
#        error error@UtsBT: The 16 bits signed int type does not have the correct size.
#    endif
#
#    if USHRT_MAX >= 0xFFFF /* Checks if ends as an unsigned int16. */
         typedef unsigned short int u_uint16;
#        define U_UINT16_DEFINED 0
#    else /* If the size is wrong. */
#        error error@UtsBT: The 16 bits unsigned int type does not have the correct size.
#    endif
#

/* Now, sets the base int16 type. */
#    if DEFAULT_INTENGER_SIGN == 0
         typedef u_sint16 u_int16;
#        define U_INT16_DEFINED 0
#        define U_INT16_IS_SIGNED 0 /* To be used as additional error checking... */
#    else /* DEFAULT_INTENGER_SIGN == 1 */
         typedef u_uint16 u_int16;
#        define U_INT16_DEFINED 0
#        define U_INT16_IS_UNSIGNED 0 /* To be used as additional error checking... */
#    endif /* DEFAULT_INTENGER_SIGN == 0 */

/* End of int16 types. */
#endif /* BIT_MAX_SIZE >= 16 */



/* Now defines the u_sint32 and u_uint32 types. Guarantees at least the
 * [(-2147483648) ~ 2147483647] / [0 ~ 4294967295] size.
 */
#if BIT_MAX_SIZE >= 32 /* Checks if is to support the 32 bits sign. */
#    if INT_MIN <= (-2147483648) /* Checks if starts as a signed int32. */
#        if INT_MAX >= 0x7FFFFFFF /* Checks if ends as a signed int32. */
             typedef signed int u_sint32;
#            define U_SINT32_DEFINED 0
#        else /* If the size is wrong. */
#            error error@UtsBT: The 32 bits signed int type does not have the correct size.
#        endif
#    else /* If the size is wrong. */
#        error error@UtsBT: The 32 bits signed int type does not have the correct size.
#    endif
#
#    if UINT_MAX >= 0xFFFFFFFFU /* Checks if ends as an unsigned int32. */
         typedef unsigned int u_uint32;
#        define U_UINT32_DEFINED 0
#    else /* If the size is wrong. */
#        error error@UtsBT: The 16 bits unsigned int type does not have the correct size.
#    endif
#

/* Now, sets the base int32 type. */
#    if DEFAULT_INTENGER_SIGN == 0
         typedef u_sint32 u_int32;
#        define U_INT32_DEFINED 0
#        define U_INT32_IS_SIGNED 0 /* To be used as additional error checking... */
#    else /* DEFAULT_INTENGER_SIGN == 1 */
         typedef u_uint32 u_int32;
#        define U_INT32_DEFINED 0
#        define U_INT32_IS_UNSIGNED 0 /* To be used as additional error checking... */
#    endif /* DEFAULT_INTENGER_SIGN == 0 */

/* End of int32 types. */
#endif /* BIT_MAX_SIZE >= 32 */



/*************************************************************************************************************
 *
 * Intengers with guaranteed MINIMUM, but not maximum size.
 *
 ************************************************************************************************************/

/* The u_sint64 and u_uint64 have variable maximum size.
 * If USE_SAFE_LONG_INT was set to 1, only sets the u_sint64 and u_uint64 if it is bigger than the u_sint32
 * and u_uint32, respectively.
 */
#if BIT_MAX_SIZE >= 64 /* Checks if is to support the 64 bits sign. */
/* As we have no proper ways to check if is really a int64, we'll believe on the compiler and add it. */
     typedef signed long int u_sint64;
#    define U_SINT64_DEFINED 0
#
     typedef unsigned long int u_uint64;
#    define U_UINT64_DEFINED 0
#

/* Now, sets the base int64 type. */
#    if DEFAULT_INTENGER_SIGN == 0
         typedef u_sint64 u_int64;
#        define U_INT64_DEFINED 0
#        define U_INT64_IS_SIGNED 0 /* To be used as additional error checking... */
#    else /* DEFAULT_INTENGER_SIGN == 1 */
         typedef u_uint64 u_int64;
#        define U_INT64_DEFINED 0
#        define U_INT64_IS_UNSIGNED 0 /* To be used as additional error checking... */
#    endif /* DEFAULT_INTENGER_SIGN == 0 */
#

/* End of int64 types. */
#endif /* BIT_MAX_SIZE >= 64 */

#endif /* !UTSCHBASICTYPES_HPP */



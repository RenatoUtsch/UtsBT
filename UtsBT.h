#ifndef UTSBT_H_INCLUDED
#define UTSBT_H_INCLUDED
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
 * u_sint64 refers to a 64 bit signed intenger - Range: configuration. At least a u_sint32 type, but
 *                                                   can be [ -9223372036854775808 ~ 9223372036854775807 ] if
 *                                                   configured on USE_SAFE_LONG_TYPES.
 * u_uint64 refers to a 64 bit unsigned intenger - Range: configuration. At least a u_uint32 type, but
 *                                                     can be [ 0 ~ 18446744073709551615 ] if
 *                                                     configured on USE_SAFE_LONG_TYPES.
 *
 * u_int8 refers to a 8bit signed/unsigned intenger, as defined in DEFAULT_INTENGER_SIGN configuration.
 * u_int16 refers to a 16bit signed/unsigned intenger, as defined in DEFAULT_INTENGER_SIGN configuration.
 * u_int32 refers to a 32bit signed/unsigned intenger, as defined in DEFAULT_INTENGER_SIGN configuration.
 * u_int64 refers to a 64bit signed/unsigned intenger, as defined in DEFAULT_INTENGER_SIGN configuration.
 *
 *
 *
 * OBSERVATION: when compiling, if having many errors, check if any 'error@UtsBT' message was shown. If yes,
 * the cause of the problem is explained in the message and it may be causing all these errors.
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



/* USE SAFE LONG TYPES
 *
 * Set here if you want to be sure that any long type (64 bits type) is bigger than its 'predecessor'.
 *
 * Like, if you want the u_int64 only to be defined when it is a real 64 bit type (not a 32 bit, like
 * in some compilers), set here. If it is a int32 type, a macro U_INT64_IS_U_INT32 will be defined.
 *
 * If you want to it always be defined, if the 64bit type is a 32bit type, the macro U_INT64_IS_U_INT32
 * will still be defined, but the types will be too.
 *
 * If you want to define the 64bit types safely (only if they are bigger), set this to 1. If you want to
 * define it all times, set to 0.
 *
 * The default is 1 (only define 64 bits types when they are bigger than 32 bits types).
 */
#define USE_SAFE_LONG_TYPES 1



/* FALL THROUGH TYPES
 *
 * Set here if you want to fall through bigger types to ensure that almost all times the types will be defined.
 *
 * For example, if the small int size is not sufficient to cover a 16 bit intenger size (which isn't normal), before
 * launching an error UtsBT checks if the int size can cover the 16 bit intenger size, or the long int. Then defines
 * it as the intenger size. This is specially useful if you compile on a architecture different of the one you originally
 * designed the software to work.
 *
 * The default is 1 (this mode is activated).
 */
#define FALL_THROUGH_TYPES 1



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

/* Checks if USE_SAFE_LONG_TYPES was set correctly. */
#if USE_SAFE_LONG_TYPES != 0 && USE_SAFE_LONG_TYPES != 1
#    error error@UtsBT: The USE_SAFE_LONG_INT macro was set incorrectly.
#endif

/* Checks if DEFAULT_INTENGER_SIGN was set correctly. */
#if DEFAULT_INTENGER_SIGN != 0 && DEFAULT_INTENGER_SIGN != 1
#    error error@UtsBT: The DEFAULT_INTENGER_SIGN macro was set incorrectly.
#endif

/* Checks if FALL_THROUGH_TYPES was set correctly. */
#if FALL_THROUGH_TYPES != 0 && FALL_THROUGH_TYPES != 1
#    error error@UtsBT: The FALL_THROUGH_TYPES macro was set incorrectly.
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
#define UTSBT_VERSION "1.2"

/* The version is available in two parts: */
#define UTSBT_VERSION_MAJOR 1
#define UTSBT_VERSION_MINOR 2

/* It is also available in a hexadecimal to compare against versions. */
#define UTSBT_VERSION_HEX 0x0102;



/* Then, the inclusions. */



/* Here, the #include directives, separed for C and C++. */
#ifdef __cplusplus
#    include <climits> /* Used to calculate the limits with the intenger types. */
#
#    if USE_WCHAR == 1
#        include <cwchar> /* To use the wchar_t type. */
#    endif
#
#else /* __cplusplus is not defined. */
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
  !defined(LONG_MIN) || !defined(LONG_MAX) || !defined(ULONG_MAX) || \
  SCHAR_MIN < SHRT_MIN || SHRT_MIN < INT_MIN || INT_MIN < LONG_MIN || \
  SCHAR_MAX > SHRT_MAX || SHRT_MAX > INT_MAX || INT_MAX > LONG_MAX || \
  UCHAR_MAX > USHRT_MAX || USHRT_MAX > UINT_MAX || UINT_MAX > ULONG_MAX
#    ifndef __cplusplus /* Using C. */
#        error error@UtsBT: <limits.h> is not conformant with ISO C+.
#    else /* Using C++. */
#        error error@UtsBT: <climits> is not conformant with ISO C++.
#    endif
#endif



/* ======================================================================================================== *\
 *                                                                                                          *
 *                                                                                                          *
 *                                             <<< TYPES >>>                                                *
 *                                                                                                          *
 *                                                                                                          *
\* ======================================================================================================== */

/* Defines the proper types. */



/* Defines the char type. Guarantees at least the (-128) ~ 127 size. */
#if USE_WCHAR == 0 /* If is a normal char... */
#    if CHAR_MIN == -0x80 /* Checks if starts as a 'signed' char. */
#        if CHAR_MAX == 0x7F /* And checks if ends as a 'signed' char. */
             typedef char u_char;
#            define U_CHAR_DEFINED 1
#        else /* If the size is wrong. */
#            error error@UtsBT: The char type does not have the correct size.
#        endif
#
#    else /* If is a 'unsigned' char. */
#        if CHAR_MAX == 0xFF /* And checks if ends as an 'unsigned' char. */
             typedef char u_char;
#            define U_CHAR_DEFINED 1
#        else /* If the size is wrong. */
#            error error@UtsBT: The char type does not have the correct size.
#        endif
#    endif
#
#elif USE_WCHAR == 1 /* If is a wchar_t char... */
#    define WCHAR_NOT_IMPLEMENTED 1 /* Needs to implement... */
#endif



/* Defines the u_sint8 and u_uint8 types.
 * Guarantees at least the [(-128) ~ 127] / [0 ~ 255] size
 */
#if BIT_MAX_SIZE >= 8 /* Checks if is to support the 8 bits int. */
#    if SCHAR_MIN <= -0x80 /* Checks if starts as a signed int8. */
#        if SCHAR_MAX >= 0x7F /* And checks if ends as a signed int8. */
             typedef signed char u_sint8;
#            define U_SINT8_DEFINED 1
#        else /* If the size is wrong. */
#            if FALL_THROUGH_TYPES == 1 /* If is to fall through the bigger types to define others. */
#                if SHRT_MIN <= SCHAR_MIN && SHRT_MAX >= 0x7F /* Checks if the size is sufficiently big to define the type.
                                                               * SCHAR_MIN is guaranteed to have a minimum size ok, so only check by that. */
				     typedef signed short int u_sint8;
#                    define U_SINT8_DEFINED 1
#                elif INT_MIN <= SCHAR_MIN && INT_MAX >= 0x7F /* Checks if the size is sufficiently big to define the type.
                                                               * SCHAR_MIN is guaranteed to have a minimum size ok, so only check by that. */
				     typedef signed int u_sint8;
#                    define U_SINT8_DEFINED 1
#                elif LONG_MIN <= SCHAR_MIN && LONG_MAX >= 0x7F /* Checks if the size is sufficiently big to define the type.
                                                                 * SCHAR_MIN is guaranteed to have a minimum size ok, so only check by that. */
				     typedef signed long int u_sint8;
#                    define U_SINT8_DEFINED 1
#                else
#                    error error@UtsBT: The 8 bits signed int type does not have the correct size.
#                endif
#            else /* FALL_THROUGH_TYPES == 0 */
#                error error@UtsBT: The 8 bits signed int type does not have the correct size.
#            endif
#        endif
#    else /* If the size is wrong. */
#        if FALL_THROUGH_TYPES == 1 /* If is to fall through the bigger types to define others. */
#            if SHRT_MIN <= -0x80 /* Checks if the size is sufficiently small to define the type. */
#                if SHRT_MAX >= 0x7F /* Checks if the size is sufficiently big to define the type. */
                     typedef signed short int u_sint8;
#					 define U_SINT8_DEFINED 1
#                elif INT_MIN <= SHRT_MIN && INT_MAX >= 0x7F /* Checks if the size is sufficiently big to define the type.
                                                              * SHRT_MIN is guaranteed to have a minimum size ok, so only check by that. */
	                 typedef signed int u_sint8;
#                    define U_SINT8_DEFINED 1
#                elif LONG_MIN <= SHRT_MIN && LONG_MAX >= 0x7F /* Checks if the size is sufficiently big to define the type.
                                                                * SHRT_MIN is guaranteed to have a minimum size ok, so only check by that. */
                     typedef signed long int u_sint8;
#				     define U_SINT8_DEFINED 1
#                else /* If no size is compatible. */
#                    error@UtsBT: The 8 bits signed int type does not have the correct size.
#                endif
#            elif INT_MIN <= -0x80 /* Checks if the size is sufficiently small to define the type. */
#                if INT_MAX >= 0x7F /* Checks if the size is sufficiently big to define the type. */
                     typedef signed int u_sint8;
#                    define U_SINT8_DEFINED 1
#                elif LONG_MIN <= INT_MIN && LONG_MAX >= 0x7F /* Checks if the size is sufficiently big to define the type.
                                                               * INT_MIN is guaranteed to have a minimum size ok, so only check by that. */
			         typedef signed long int u_sint8;
#                    define U_SINT8_DEFINED 1
#                else /* If no size is compatible. */
#                    error error@UtsBT: The 8 bits signed int type does not have the correct size.
#                endif
#            elif LONG_MIN <= -0x80 /* Checks if the size is sufficiently small to define the type. */
#                if LONG_MAX >= 0x7F /* Checks if the size is sufficiently big to define the type. */
                     typedef signed long int u_sint8;
#                    define U_SINT8_DEFINED 1
#                else
#                    error error@UtsBT: The 8 bits signed int type does not have the correct size.
#                endif
#            else /* If no size is compatible. */
#                error error@UtsBT: The 8 bits signed int type does not have the correct size.
#            endif
#        else /* FALL_THROUGH_TYPES == 0 */
#            error error@UtsBT: The 8 bits signed int type does not have the correct size.
#        endif
#    endif
#
#    if UCHAR_MAX >= 0xFF /* Checks if ends as an unsigned int8. */
         typedef unsigned char u_uint8;
#        define U_UINT8_DEFINED 1
#    else /* If the size is wrong. */
#        if FALL_THROUGH_TYPES == 1 /* If is to fall through the bigger types to define others. */
#            if USHRT_MAX >= 0xFF /* Checks if the size is sufficiently big to define the type. */
                 typedef unsigned short int u_uint8;
#                define U_UINT8_DEFINED 1
#            elif UINT_MAX >= 0xFF /* Checks if the size is sufficiently big to define the type. */
                 typedef unsigned int u_uint8;
#                define U_UINT8_DEFINED 1
#            elif ULONG_MAX >= 0xFF /* Checks if the size is sufficiently big to define the type. */
                 typedef unsigned long int u_uint8;
#                define U_UINT8_DEFINED 1
#            else /* If no size is compatible. */
#                error error@UtsBT: The 8 bits unsigned int type does not have the correct size.
#            endif
#        else /* FALL_THROUGH_TYPES == 0 */
#            error error@UtsBT: The 8 bits unsigned int type does not have the correct size.
#        endif
#    endif
#

/* Now, sets the base int8 type. */
#    if DEFAULT_INTENGER_SIGN == 0
         typedef u_sint8 u_int8;
#        define U_INT8_DEFINED 1
#        define U_INT8_IS_SIGNED 1 /* To be used as additional error checking... */
#    else /* DEFAULT_INTENGER_SIGN == 1 */
         typedef u_uint8 u_int8;
#        define U_INT8_DEFINED 1
#        define U_INT8_IS_UNSIGNED 1 /* To be used as additional error checking... */
#    endif /* DEFAULT_INTENGER_SIGN == 0 */

/* End of int8 types. */
#endif /* BIT_MAX_SIZE >= 8 */



/* Now defines the u_sint16 and u_uint16 types. Guarantees at least the
 * [(-32768) ~ 32767] / [0 ~ 65535] size.
 */
#if BIT_MAX_SIZE >= 16 /* Checks if is to support the 16 bits sign. */
#    if SHRT_MIN <= -0x8000 /* Checks if starts as a signed int16. */
#        if SHRT_MAX >= 0x7FFF /* Checks if ends as a signed int16. */
             typedef signed short int u_sint16;
#            define U_SINT16_DEFINED 1
#        else /* If the size is wrong. */
#            error error@UtsBT: The 16 bits signed int type does not have the correct size.
#        endif
#    else /* If the size is wrong. */
#        error error@UtsBT: The 16 bits signed int type does not have the correct size.
#    endif
#
#    if USHRT_MAX >= 0xFFFF /* Checks if ends as an unsigned int16. */
         typedef unsigned short int u_uint16;
#        define U_UINT16_DEFINED 1
#    else /* If the size is wrong. */
#        error error@UtsBT: The 16 bits unsigned int type does not have the correct size.
#    endif
#

/* Now, sets the base int16 type. */
#    if DEFAULT_INTENGER_SIGN == 0
         typedef u_sint16 u_int16;
#        define U_INT16_DEFINED 1
#        define U_INT16_IS_SIGNED 1 /* To be used as additional error checking... */
#    else /* DEFAULT_INTENGER_SIGN == 1 */
         typedef u_uint16 u_int16;
#        define U_INT16_DEFINED 1
#        define U_INT16_IS_UNSIGNED 1 /* To be used as additional error checking... */
#    endif /* DEFAULT_INTENGER_SIGN == 0 */

/* End of int16 types. */
#endif /* BIT_MAX_SIZE >= 16 */



/* Now defines the u_sint32 and u_uint32 types. Guarantees at least the
 * [(-2147483648) ~ 2147483647] / [0 ~ 4294967295] size.
 */
#if BIT_MAX_SIZE >= 32 /* Checks if is to support the 32 bits sign. */
#    if INT_MIN <= -0x80000000 /* Checks if starts as a signed int32. */
#        if INT_MAX >= 0x7FFFFFFF /* Checks if ends as a signed int32. */
             typedef signed int u_sint32;
#            define U_SINT32_DEFINED 1
#        else /* If the size is wrong. */
#            error error@UtsBT: The 32 bits signed int type does not have the correct size.
#        endif
#    else /* If the size is wrong. */
#        error error@UtsBT: The 32 bits signed int type does not have the correct size.
#    endif
#
#    if UINT_MAX >= 0xFFFFFFFFU /* Checks if ends as an unsigned int32. */
         typedef unsigned int u_uint32;
#        define U_UINT32_DEFINED 1
#    else /* If the size is wrong. */
#        error error@UtsBT: The 32 bits unsigned int type does not have the correct size.
#    endif
#

/* Now, sets the base int32 type. */
#    if DEFAULT_INTENGER_SIGN == 0
         typedef u_sint32 u_int32;
#        define U_INT32_DEFINED 1
#        define U_INT32_IS_SIGNED 1 /* To be used as additional error checking... */
#    else /* DEFAULT_INTENGER_SIGN == 1 */
         typedef u_uint32 u_int32;
#        define U_INT32_DEFINED 1
#        define U_INT32_IS_UNSIGNED 1 /* To be used as additional error checking... */
#    endif /* DEFAULT_INTENGER_SIGN == 0 */

/* End of int32 types. */
#endif /* BIT_MAX_SIZE >= 32 */



/* The u_sint64 and u_uint64 have variable maximum size.
 * If USE_SAFE_LONG_INT was set to 1, only sets the u_sint64 and u_uint64 if it is bigger than the u_sint32
 * and u_uint32, respectively.
 */
#if BIT_MAX_SIZE >= 64 /* Checks if is to support the 64 bits sign. */
#    if LONG_MIN < INT_MIN && INT_MAX < LONG_MAX && UINT_MAX < ULONG_MAX
#        if LONG_MIN <= -0x8000000000000000L /* Checks if starts as a signed int64. */
#            if LONG_MAX >= 0x7FFFFFFFFFFFFFFFL /* Checks if ends as a signed int64. */
                 typedef signed long int u_sint64;
#                define U_SINT64_DEFINED 1
#            else /* If the size is wrong. */
#                error error@UtsBT: The 64 bits signed int type does not have the correct size.
#            endif
#        else /* If the size is wrong. */
#            error error@UtsBT: The 64 bits signed int type does not have the correct size.
#        endif
#
#        if ULONG_MAX >= 0xFFFFFFFFFFFFFFFFUL /* Checks if ends as an unsigned int64. */
             typedef unsigned long int u_uint64;
#            define U_UINT64_DEFINED 1
#        else /* If the size is wrong. */
#            error error@UtsBT: The 64 bits unsigned int type does not have the correct size.
#        endif
#    elif LONG_MIN <= INT_MIN && LONG_MAX >= INT_MAX && ULONG_MAX >= UINT_MAX
         /* The int64 is at least an int32, but not an int64. So, say that's an int32. */
#        define U_INT64_IS_U_INT32 1
#        if USE_SAFE_LONG_TYPES == 0
             /* The int64 is surely the int32 type. No need for additional checking. */
             typedef signed long int u_sint64;
#            define U_SINT64_IS_DEFINED 1
             typedef unsigned long int u_uint64;
#            define U_UINT64_IS_DEFINED 1
#        else /* USE_SAFE_LONG_TYPES == 1 */
#            error error@UtsBT: The int64 type is the int32 type.
#        endif
#    else
#        error error@UtsBT: The 64 bits type is not conformant with ISO C89/C99/C++98.
#    endif
#

/* Now, sets the base int64 type. */
#    if U_SINT64_IS_DEFINED == 1 && U_UINT64_IS_DEFINED == 1 /* To prevent strange error messsages
                                                              * on the compiling time. */
#        if DEFAULT_INTENGER_SIGN == 0
             typedef u_sint64 u_int64;
#            define U_INT64_DEFINED 1
#            define U_INT64_IS_SIGNED 1 /* To be used as additional error checking... */
#        else /* DEFAULT_INTENGER_SIGN == 1 */
             typedef u_uint64 u_int64;
#            define U_INT64_DEFINED 1
#            define U_INT64_IS_UNSIGNED 1 /* To be used as additional error checking... */
#        endif /* DEFAULT_INTENGER_SIGN == 0 */
#    endif
#

/* End of int64 types. */
#endif /* BIT_MAX_SIZE >= 64 */

#endif /* !UTSBT_H_INCLUDED */
#ifndef UTSBT_H_INCLUDED
#define UTSBT_H_INCLUDED
/***************************************************************************************************************
 *
 *    Project         <<<<<<<<>>>>>>>>-<<<<<<<<>>>>>>>>
 *                    <<< Utsch Basic Types - UtsBT >>>
 *                    <<<<<<<<>>>>>>>>-<<<<<<<<>>>>>>>>
 *
 * Copyright (C) 2011, Renato Utsch, <renatoutsch@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
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
 *                                                   configured on UTSBT_USE_SAFE_LONG_TYPES.
 * u_uint64 refers to a 64 bit unsigned intenger - Range: configuration. At least a u_uint32 type, but
 *                                                     can be [ 0 ~ 18446744073709551615 ] if
 *                                                     configured on UTSBT_USE_SAFE_LONG_TYPES.
 *
 * u_int8 refers to a 8bit signed/unsigned intenger, as defined in UTSBT_DEFAULT_INTENGER_SIGN configuration.
 * u_int16 refers to a 16bit signed/unsigned intenger, as defined in UTSBT_DEFAULT_INTENGER_SIGN configuration.
 * u_int32 refers to a 32bit signed/unsigned intenger, as defined in UTSBT_DEFAULT_INTENGER_SIGN configuration.
 * u_int64 refers to a 64bit signed/unsigned intenger, as defined in UTSBT_DEFAULT_INTENGER_SIGN configuration.
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



#ifndef UTSBT_BIT_MAX_SIZE
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
#define UTSBT_BIT_MAX_SIZE 32
#endif



#ifndef UTSBT_DEFAULT_INTENGER_SIGN
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
#define UTSBT_DEFAULT_INTENGER_SIGN 0
#endif



#ifndef UTSBT_USE_SAFE_LONG_TYPES
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
 * The default is 0 (define it all times). It's highly recommended to enable this option (put it to 1) if
 * you're compiling a 64bits native program.
 */
#define UTSBT_USE_SAFE_LONG_TYPES 0
#endif



#ifndef UTSBT_FALL_THROUGH_TYPES
/* FALL THROUGH TYPES
 *
 * Set here if you want to fall through bigger types to ensure that almost all times the types will be defined.
 *
 * For example, if the small int size is not sufficient to cover a 16 bit intenger size (which isn't normal),
 * before launching an error UtsBT checks if the int size can cover the 16 bit intenger size, or the long int.
 * Then defines it as the intenger size. This is specially useful if you compile on a architecture different
 * of the one you originally designed the software to work.
 *
 * The default is 1 (this mode is activated).
 */
#define UTSBT_FALL_THROUGH_TYPES 1
#endif



#ifndef UTSBT_USE_WCHAR_TYPE
/* USE WCHAR TYPE
 *
 * Set here if you want to use a wchar type. If you want to use a char type, put 0. If you want to use a
 * wchar_t type, put 1.
 *
 * If you put 1, use the variable u_char normally. It will be the wchar_t type. This makes veeery easy to
 * change between a char and wchar_t type on a program. You only have to change this definition.
 *
 * Remember that the wchar type will only work with compilers that support it (C++ compilers and the ones
 * that support the first ammendment to the C89).
 *
 * The default is 0 (char).
 */
#define UTSBT_USE_WCHAR_TYPE 0
#endif



#ifndef UTSBT_DEFINE_BOOL_TYPE
/* DEFINE BOOL TYPE
 *
 * Set here if you want to allow UtsBT to define a bool type. The bool type uses the following names:
 *
 * bool -> bool type
 * u_bool -> secure and fast bool type defined by UtsBT.
 * true -> macro representing 1
 * false -> macro representing 0
 *
 * If you set to 1 (to define the bool type), the bool type and the true and false macros only wil be
 * defined if they wasn't before. The u_bool macro will always be defined. This will resolve conflicts
 * with C++ and with the C99's <stdbool.h>.
 *
 * Set as 0 if you want to disable the definition of the bool type.
 *
 * The default is 1 (define the bool type).
 */
#define UTSBT_DEFINE_BOOL_TYPE 1
#endif



#ifndef UTSBT_BOOL_IMPLEMENTATION
/* BOOL IMPLEMENTATION
 *
 * Set here what kind of implementation that you want for the bool type.
 *
 * If you set 0, the bool and u_bool type will be defined as macros to the u_sint8 type and the true
 * and false will be defined as macros (NOT RECOMMENDED).
 *
 * If you set to 1, the bool and u_bool type will be defined as typedefs to the u_sint8 (the smallest
 * type avaible) and the true and false will be defined as macros.
 *
 * If you set to 2, the bool and u_bool type will be defined as enumerations, with false and true as it's
 * only possibilities.
 *
 * The advantage of the implementation set to 1 is that the bool type will ocupy the smallest part possible
 * in the memory and the advantage of the implementation set to 2 is that the bool type will have only two
 * possible values, true and false. Other values will be considered as an error (such as 34).
 *
 * Please note that if you're on C++ or included the <stdbool.h> header of C99, the option selected here
 * doesn't mind: only the u_bool type will be defined, and it will be a typedef of the standard bool type.
 *
 * The default is 1.
 */
#define UTSBT_BOOL_IMPLEMENTATION 1
#endif



/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> DO NOT MODIFY FROM HERE! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */



/* ======================================================================================================== *\
 *                                                                                                          *
 *                                                                                                          *
 *                                            <<< INTERNAL >>>                                              *
 *                                                                                                          *
 *                                                                                                          *
\* ======================================================================================================== */

/* Here, defines the internal macros. */



/* The copyright is declared. */
#define UTSBT_COPYRIGHT "Copyright (C) 2011, Renato Utsch, <renatoutsch@gmail.com>"

/* The version in a string. */
#define UTSBT_VERSION "2.1"

/* The version is available in two parts: */
#define UTSBT_VERSION_MAJOR 2
#define UTSBT_VERSION_MINOR 1

/* It is also available in a hexadecimal to compare against versions. */
#define UTSBT_VERSION_HEX 0x0201;



/* ======================================================================================================== *\
 *                                                                                                          *
 *                                                                                                          *
 *                                           <<< INCLUSIONS >>>                                             *
 *                                                                                                          *
 *                                                                                                          *
\* ======================================================================================================== */

/* Here, include the needed headers. */



/* Here, the #include directives, separed for C and C++. */
#ifdef __cplusplus
#    include <climits> /* Used to calculate the limits with the intenger types. */
#
#    if UTSBT_USE_WCHAR_TYPE == 1
#        include <cwchar> /* To use the wchar_t type. */
#    endif
#
#else /* __cplusplus is not defined. */
#    include <limits.h> /* Used to calculate the limits with the intenger types. */
#
#    if UTSBT_USE_WCHAR_TYPE == 1
#        include <wchar.h> /* To use the wchar_t type. */
#    endif
#
#endif



/* ======================================================================================================== *\
 *                                                                                                          *
 *                                                                                                          *
 *                                         <<< CONF CHECKING >>>                                            *
 *                                                                                                          *
 *                                                                                                          *
\* ======================================================================================================== */

/* Checks the configuration. */



/* Checks if UTSBT_BIT_MAX_SIZE was set correctly. */
#if UTSBT_BIT_MAX_SIZE != 8 && UTSBT_BIT_MAX_SIZE != 16 && UTSBT_BIT_MAX_SIZE != 32 && UTSBT_BIT_MAX_SIZE != 64
#    error error@UtsBT: the UTSBT_BIT_MAX_SIZE macro was set incorrectly.
#endif

/* Checks if UTSBT_USE_SAFE_LONG_TYPES was set correctly. */
#if UTSBT_USE_SAFE_LONG_TYPES != 0 && UTSBT_USE_SAFE_LONG_TYPES != 1
#    error error@UtsBT: the USE_SAFE_LONG_INT macro was set incorrectly.
#endif

/* Checks if UTSBT_DEFAULT_INTENGER_SIGN was set correctly. */
#if UTSBT_DEFAULT_INTENGER_SIGN != 0 && UTSBT_DEFAULT_INTENGER_SIGN != 1
#    error error@UtsBT: the UTSBT_DEFAULT_INTENGER_SIGN macro was set incorrectly.
#endif

/* Checks if UTSBT_FALL_THROUGH_TYPES was set correctly. */
#if UTSBT_FALL_THROUGH_TYPES != 0 && UTSBT_FALL_THROUGH_TYPES != 1
#    error error@UtsBT: the UTSBT_FALL_THROUGH_TYPES macro was set incorrectly.
#endif

/* Checks if USE_WCHAR was set correctly. */
#if USE_WCHAR != 0 && USE_WCHAR != 1
#    error error@UtsBT: the USE_WCHAR macro was set incorrectly.
#endif

/* Checks if UTSBT_DEFINE_BOOL_TYPE was set correctly. */
#if UTSBT_DEFINE_BOOL_TYPE != 0 && UTSBT_DEFINE_BOOL_TYPE != 1
#    error error@UtsBT: the UTSBT_DEFINE_BOOL_TYPE macro was set incorrectly.
#endif

/* Checks if UTSBT_BOOL_IMPLEMENTATION was set correctly. */
#if UTSBT_BOOL_IMPLEMENTATION != 0 && UTSBT_BOOL_IMPLEMENTATION != 1 && UTSBT_BOOL_IMPLEMENTATION != 2
#    error error@UtsBT: the UTSBT_BOOL_IMPLEMENTATION macro was set incorrectly.
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
#if UTSBT_USE_WCHAR_TYPE == 0 /* If is a normal char... */
#    if CHAR_MIN <= -0x80 /* Checks if starts as a 'signed' char. */
#        if CHAR_MAX >= 0x7F /* And checks if ends as a 'signed' char. */
             typedef char u_char;
#            define U_CHAR_DEFINED 1
#        else /* If the size is wrong. */
#            error error@UtsBT: the char type does not have a compatible size.
#        endif
#
#    else /* If is a 'unsigned' char. */
#        if CHAR_MAX >= 0xFF /* And checks if ends as an 'unsigned' char. */
             typedef char u_char;
#            define U_CHAR_DEFINED 1
#        else /* If the size is wrong. */
#            error error@UtsBT: the char type does not have a compatible size.
#        endif
#    endif
#
#else /* UTSBT_USE_WCHAR_TYPE == 1 */
#    define WCHAR_NOT_IMPLEMENTED 1 /* Needs to implement... */
#endif



/* Defines the u_sint8 and u_uint8 types.
 * Guarantees at least the [(-128) ~ 127] / [0 ~ 255] size
 */
#if UTSBT_BIT_MAX_SIZE >= 8 /* Checks if is to support the 8 bits int. */
#    if SCHAR_MIN <= -0x80L /* Checks if starts as a signed int8. */
#        if SCHAR_MAX >= 0x7FL /* And checks if ends as a signed int8. */
             typedef signed char u_sint8;
#            define U_SINT8_DEFINED 1
#        else /* If the size is wrong. */
#            if UTSBT_FALL_THROUGH_TYPES == 1 /* If is to fall through the bigger types to define others. */
#                define U_SINT8_FALLED_THROUGH 1 /* To define a falled through macro to this. */
#                if SHRT_MIN <= SCHAR_MIN && SHRT_MAX >= 0x7FL /* Checks if the size is sufficiently big to define the type.
                                                                * SCHAR_MIN is guaranteed to have a minimum size ok, so only check by that. */
				     typedef signed short int u_sint8;
#                    define U_SINT8_DEFINED 1
#                elif INT_MIN <= SCHAR_MIN && INT_MAX >= 0x7FL /* Checks if the size is sufficiently big to define the type.
                                                                * SCHAR_MIN is guaranteed to have a minimum size ok, so only check by that. */
				     typedef signed int u_sint8;
#                    define U_SINT8_DEFINED 1
#                elif LONG_MIN <= SCHAR_MIN && LONG_MAX >= 0x7FL /* Checks if the size is sufficiently big to define the type.
                                                                  * SCHAR_MIN is guaranteed to have a minimum size ok, so only check by that. */
				     typedef signed long int u_sint8;
#                    define U_SINT8_DEFINED 1
#                else
#                    error error@UtsBT: the 8 bits signed int type does not have a compatible size.
#                endif
#            else /* UTSBT_FALL_THROUGH_TYPES == 0 */
#                error error@UtsBT: the 8 bits signed int needed to fall through, but it was set to not fall through.
#            endif
#        endif
#    else /* If the size is wrong. */
#        if UTSBT_FALL_THROUGH_TYPES == 1 /* If is to fall through the bigger types to define others. */
#            define U_SINT8_FALLED_THROUGH 1 /* To define a falled through macro to this. */
#            if SHRT_MIN <= -0x80L /* Checks if the size is sufficiently small to define the type. */
#                if SHRT_MAX >= 0x7FL /* Checks if the size is sufficiently big to define the type. */
                     typedef signed short int u_sint8;
#					 define U_SINT8_DEFINED 1
#                elif INT_MIN <= SHRT_MIN && INT_MAX >= 0x7FL /* Checks if the size is sufficiently big to define the type.
                                                              * SHRT_MIN is guaranteed to have a minimum size ok, so only check by that. */
	                 typedef signed int u_sint8;
#                    define U_SINT8_DEFINED 1
#                elif LONG_MIN <= SHRT_MIN && LONG_MAX >= 0x7FL /* Checks if the size is sufficiently big to define the type.
                                                                 * SHRT_MIN is guaranteed to have a minimum size ok, so only check by that. */
                     typedef signed long int u_sint8;
#				     define U_SINT8_DEFINED 1
#                else /* If no size is compatible. */
#                    error@UtsBT: the 8 bits signed int type does not have a compatible size.
#                endif
#            elif INT_MIN <= -0x80L /* Checks if the size is sufficiently small to define the type. */
#                if INT_MAX >= 0x7FL /* Checks if the size is sufficiently big to define the type. */
                     typedef signed int u_sint8;
#                    define U_SINT8_DEFINED 1
#                elif LONG_MIN <= INT_MIN && LONG_MAX >= 0x7FL /* Checks if the size is sufficiently big to define the type.
                                                                * INT_MIN is guaranteed to have a minimum size ok, so only check by that. */
			         typedef signed long int u_sint8;
#                    define U_SINT8_DEFINED 1
#                else /* If no size is compatible. */
#                    error error@UtsBT: the 8 bits signed int type does not have a compatible size.
#                endif
#            elif LONG_MIN <= -0x80L /* Checks if the size is sufficiently small to define the type. */
#                if LONG_MAX >= 0x7FL /* Checks if the size is sufficiently big to define the type. */
                     typedef signed long int u_sint8;
#                    define U_SINT8_DEFINED 1
#                else
#                    error error@UtsBT: the 8 bits signed int type does not have a compatible size.
#                endif
#            else /* If no size is compatible. */
#                error error@UtsBT: the 8 bits signed int type does not have a compatible size.
#            endif
#        else /* UTSBT_FALL_THROUGH_TYPES == 0 */
#            error error@UtsBT: the 8 bits signed int type needed to fall through, but it was set to not fall through.
#        endif
#    endif
#
#    if UCHAR_MAX >= 0xFF /* Checks if ends as an unsigned int8. */
         typedef unsigned char u_uint8;
#        define U_UINT8_DEFINED 1
#    else /* If the size is wrong. */
#        if UTSBT_FALL_THROUGH_TYPES == 1 /* If is to fall through the bigger types to define others. */
#            define U_UINT8_FALLED_THROUGH 1 /* To define a falled through macro to this. */
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
#                error error@UtsBT: the 8 bits unsigned int type does not have a compatible size.
#            endif
#        else /* UTSBT_FALL_THROUGH_TYPES == 0 */
#            error error@UtsBT: the 8 bits unsigned int type does not have a compatible size.
#        endif
#    endif
#

/* Now, sets the base int8 type. */
#    if UTSBT_DEFAULT_INTENGER_SIGN == 0
         typedef u_sint8 u_int8;
#        define U_INT8_DEFINED 1
#        define U_INT8_IS_SIGNED 1 /* To be used as additional error checking... */
#    else /* UTSBT_DEFAULT_INTENGER_SIGN == 1 */
         typedef u_uint8 u_int8;
#        define U_INT8_DEFINED 1
#        define U_INT8_IS_UNSIGNED 1 /* To be used as additional error checking... */
#    endif /* UTSBT_DEFAULT_INTENGER_SIGN == 0 */

/* End of int8 types. */
#endif /* UTSBT_BIT_MAX_SIZE >= 8 */



/* Now defines the u_sint16 and u_uint16 types. Guarantees at least the
 * [(-32768) ~ 32767] / [0 ~ 65535] size.
 */
#if UTSBT_BIT_MAX_SIZE >= 16 /* Checks if is to support the 16 bits sign. */
#    if SHRT_MIN <= -0x8000L /* Checks if starts as a signed int16. */
#        if SHRT_MAX >= 0x7FFFL /* Checks if ends as a signed int16. */
             typedef signed short int u_sint16;
#            define U_SINT16_DEFINED 1
#        else /* If the size is wrong. */
#            if UTSBT_FALL_THROUGH_TYPES == 1 /* If is to fall through the bigger types to define others. */
#                define U_SINT16_FALLED_THROUGH 1 /* To define a falled through macro to this. */
#                if INT_MIN <= SHRT_MIN && INT_MAX >= 0x7FFFL /* Checks if the size is sufficiently big to define the type.
                                                               * SHRT_MIN is guaranteed to have a minimum size ok, so only check by that. */
				     typedef signed int u_sint16;
#                    define U_SINT16_DEFINED 1
#                elif LONG_MIN <= SHRT_MIN && LONG_MAX >= 0x7FFFL /* Checks if the size is sufficiently big to define the type.
                                                                   * SHRT_MIN is guaranteed to have a minimum size ok, so only check by that. */
			         typedef signed long int u_sint16;
#                    define U_SINT16_DEFINED 1
#                else /* If no size is compatible. */
#                    error error@UtsBT: the 16 bits signed int type does not have a compatible size.
#                endif
#            else /* UTSBT_FALL_THROUGH_TYPES == 0 */
#                error error@UtsBT: the 16 bits signed int type needed to fall through, but it was set to not fall through.
#            endif
#        endif
#    else /* If the size is wrong. */
#        if UTSBT_FALL_THROUGH_TYPES == 1 /* If is to fall through the bigger types to define others. */
#            define U_SINT16_FALLED_THROUGH 1 /* To define a falled through macro to this. */
#            if INT_MIN <= -0x8000L /* Checks if the size is sufficiently small to define the type. */
#                if INT_MAX >= 0x7FFFL /* Checks if the size is sufficiently big to define the type. */
                     typedef signed int u_sint16;
#                    define U_SINT16_DEFINED 1
#                elif LONG_MIN <= INT_MIN && LONG_MAX >= 0x7FFFL /* Checks if the size is sufficiently big to define the type.
                                                                  * INT_MIN is guaranteed to have a minimum size ok, so only check by that. */
				     typedef signed long int u_sint16;
#                    define U_SINT16_DEFINED 1
#                else /* If no size is compatible. */
#                    error error@UtsBT: the 16 bits signed int type does not have a compatible size.
#                endif
#            elif LONG_MIN <= -0x8000L /* Checks if the size is sufficiently small to define the type. */
#                if LONG_MAX >= 0x7FFFL /* Checks if the size is sufficiently big to define the type. */
                     typedef signed long int u_sint16;
#                    define U_SINT16_DEFINED 1
#                else /* If no type is compatible. */
#                    error error@UtsBT: the 16 bits signed int type does not have a compatible size.
#                endif
#            else /* If no type is compatible. */
#                error error@UtsBT: the 16 bits signed int type does not have a compatible size.
#            endif
#
#        else /* UTSBT_FALL_THROUGH_TYPES == 0 */
#            error error@UtsBT: the 16 bits signed int type needed to fall through, but it was set to not to fall through.
#        endif
#    endif
#
#    if USHRT_MAX >= 0xFFFFUL /* Checks if ends as an unsigned int16. */
         typedef unsigned short int u_uint16;
#        define U_UINT16_DEFINED 1
#    else /* If the size is wrong. */
#        if UTSBT_FALL_THROUGH_TYPES == 1 /* If is to fall through the bigger types to define others. */
#            define U_UINT16_FALLED_THROUGH 1 /* To define a falled through macro to this. */
#            if INT_MAX >= 0xFFFFUL /* Checks if the size is sufficiently big to define the type. */
                 typedef unsigned int u_uint16;
#                define U_UINT16_DEFINED 1
#            elif LONG_MAX >= 0xFFFFUL /* Checks if the size is sufficiently big to define the type. */
                 typedef unsigned long int u_uint16;
#                define U_UINT16_DEFINED 1
#            else /* If no size is compatible. */
#                error error@UtsBT: the 16 bits unsigned int type does not have a compatible size.
#            endif
#        else /* UTSBT_FALL_THROUGH_TYPES == 0 */
#            error error@UtsBT: the 16 bits unsigned int type needed to fall through, but it was set to not to fall through.
#        endif
#    endif
#

/* Now, sets the base int16 type. */
#    if UTSBT_DEFAULT_INTENGER_SIGN == 0
         typedef u_sint16 u_int16;
#        define U_INT16_DEFINED 1
#        define U_INT16_IS_SIGNED 1 /* To be used as additional error checking... */
#    else /* UTSBT_DEFAULT_INTENGER_SIGN == 1 */
         typedef u_uint16 u_int16;
#        define U_INT16_DEFINED 1
#        define U_INT16_IS_UNSIGNED 1 /* To be used as additional error checking... */
#    endif /* UTSBT_DEFAULT_INTENGER_SIGN == 0 */

/* End of int16 types. */
#endif /* UTSBT_BIT_MAX_SIZE >= 16 */



/* Now defines the u_sint32 and u_uint32 types. Guarantees at least the
 * [(-2147483648) ~ 2147483647] / [0 ~ 4294967295] size.
 */
#if UTSBT_BIT_MAX_SIZE >= 32 /* Checks if is to support the 32 bits sign. */
#    if INT_MIN <= -0x80000000L /* Checks if starts as a signed int32. */
#        if INT_MAX >= 0x7FFFFFFFL /* Checks if ends as a signed int32. */
             typedef signed int u_sint32;
#            define U_SINT32_DEFINED 1
#        else /* If the size is wrong. */
#            if UTSBT_FALL_THROUGH_TYPES == 1 /* If is to fall through the bigger types to define others. */
#                if LONG_MIN <= INT_MIN && LONG_MAX >= 0x7FFFFFFFL /* Checks if the size is sufficiently big to define the type.
                                                                    * INT_MIN is guaranteed to have a minimum size ok, so only check by that. */
				     typedef signed long int u_sint32;
#                    define U_SINT32_DEFINED 1
#                else /* If no size is compatible. */
#                    error error@UtsBT: the 32 bits signed int type does not have a compatible size.
#                endif
#            else /* UTSBT_FALL_THROUGH_TYPES == 0 */
#                error error@UtsBT: the 32 bits signed int type needed to fall through, but it was set to not fall through..
#            endif
#        endif
#    else /* If the size is wrong. */
#        if UTSBT_FALL_THROUGH_TYPES == 1 /* If is to fall through the bigger types to define others. */
#            if LONG_MIN <= 0x80000000L /* Checks if the size is sufficiently small to define the type. */
#                if LONG_MAX >= 0x7FFFFFFFL /* Checks if the size is sufficiently big to define the type. */
                     typedef signed long int u_sint32;
#                    define U_SINT32_DEFINED 1;
#                else /* If no size is compatible. */
#                    error error@UtsBT: the 32 bits signed int type does not have a compatible size.
#                endif
#            else /* If no size is compatible. */
#                error error@UtsBT: the 32 bits signed int type does not have a compatible size.
#            endif
#        else /* UTSBT_FALL_THROUGH_TYPES == 0 */
#            error error@UtsBT: the 32 bits signed int type needed to fall through, but it was set to not fall through.
#        endif
#    endif
#
#    if UINT_MAX >= 0xFFFFFFFFUL /* Checks if ends as an unsigned int32. */
         typedef unsigned int u_uint32;
#        define U_UINT32_DEFINED 1
#    else /* If the size is wrong. */
#        error error@UtsBT: the 32 bits unsigned int type does not have a compatible size.
#    endif
#

/* Now, sets the base int32 type. */
#    if UTSBT_DEFAULT_INTENGER_SIGN == 0
         typedef u_sint32 u_int32;
#        define U_INT32_DEFINED 1
#        define U_INT32_IS_SIGNED 1 /* To be used as additional error checking... */
#    else /* UTSBT_DEFAULT_INTENGER_SIGN == 1 */
         typedef u_uint32 u_int32;
#        define U_INT32_DEFINED 1
#        define U_INT32_IS_UNSIGNED 1 /* To be used as additional error checking... */
#    endif /* UTSBT_DEFAULT_INTENGER_SIGN == 0 */

/* End of int32 types. */
#endif /* UTSBT_BIT_MAX_SIZE >= 32 */



/* Now defines the u_sint64 and u_uint64 types. Guarantees at least the
 * [(-9223372036854775808) ~ 9223372036854775807] / [0 ~  18446744073709551615] size.
 */
#if UTSBT_BIT_MAX_SIZE >= 64 /* Checks if is to support the 64 bits sign. */
#    if LONG_MIN < INT_MIN && INT_MAX < LONG_MAX && UINT_MAX < ULONG_MAX
#        if LONG_MIN <= -0x8000000000000000L /* Checks if starts as a signed int64. */
#            if LONG_MAX >= 0x7FFFFFFFFFFFFFFFL /* Checks if ends as a signed int64. */
                 typedef signed long int u_sint64;
#                define U_SINT64_DEFINED 1
#            else /* If the size is wrong. */
#                error error@UtsBT: the 64 bits signed int type does not have a compatible size.
#            endif
#        else /* If the size is wrong. */
#            error error@UtsBT: the 64 bits signed int type does not have a compatible size.
#        endif
#
#        if ULONG_MAX >= 0xFFFFFFFFFFFFFFFFUL /* Checks if ends as an unsigned int64. */
             typedef unsigned long int u_uint64;
#            define U_UINT64_DEFINED 1
#        else /* If the size is wrong. */
#            error error@UtsBT: the 64 bits unsigned int type does not have a compatible size.
#        endif
#    elif LONG_MIN <= INT_MIN && LONG_MAX >= INT_MAX && ULONG_MAX >= UINT_MAX
         /* The int64 is at least an int32, but not an int64. So, say that's an int32. */
#        define U_INT64_IS_U_INT32 1
#        if UTSBT_USE_SAFE_LONG_TYPES == 0
             /* The int64 is surely the int32 type. No need for additional checking. */
             typedef signed long int u_sint64;
#            define U_SINT64_IS_DEFINED 1
             typedef unsigned long int u_uint64;
#            define U_UINT64_IS_DEFINED 1
#        else /* UTSBT_USE_SAFE_LONG_TYPES == 1 */
#            error error@UtsBT: the int64 type is the int32 type.
#        endif
#    else
#        error error@UtsBT: the 64 bits type is not conformant with ISO C89/C99/C++98.
#    endif
#

/* Now, sets the base int64 type. */
#    if U_SINT64_IS_DEFINED == 1 && U_UINT64_IS_DEFINED == 1 /* To prevent strange error messsages
                                                              * on the compiling time. */
#        if UTSBT_DEFAULT_INTENGER_SIGN == 0
             typedef u_sint64 u_int64;
#            define U_INT64_DEFINED 1
#            define U_INT64_IS_SIGNED 1 /* To be used as additional error checking... */
#        else /* UTSBT_DEFAULT_INTENGER_SIGN == 1 */
             typedef u_uint64 u_int64;
#            define U_INT64_DEFINED 1
#            define U_INT64_IS_UNSIGNED 1 /* To be used as additional error checking... */
#        endif /* UTSBT_DEFAULT_INTENGER_SIGN == 0 */
#    endif
#

/* End of int64 types. */
#endif /* UTSBT_BIT_MAX_SIZE >= 64 */



/* Definition of the bool type. */
#if UTSBT_DEFINE_BOOL_TYPE == 1
#    if UTSBT_BOOL_IMPLEMENTATION == 0
#        if defined __cplusplus || defined __bool_true_false_are_defined
             typedef bool u_bool;
#        else /* not defined __cplusplus || not defined __bool_true_false_are_defined */
#            define bool u_sint8
#            define u_bool u_sint8
#            define false 0
#            define true 1
#        endif
#    elif UTSBT_BOOL_IMPLEMENTATION == 1
#        if defined __cplusplus || defined __bool_true_false_are_defined
             typedef bool u_bool;
#        else /* not defined __cplusplus || not defined __bool_true_false_are_defined */
             typedef u_sint8 bool;
             typedef u_sint8 u_bool;
#            define false 0
#            define true 1
#        endif
#    else /* UTSBT_BOOL_IMPLEMENTATION == 2 */
#        if defined __cplusplus || defined __bool_true_false_are_defined
             typedef bool u_bool;
#        else /* not defined __cplusplus || not defined __bool_true_false_are_defined */
             typedef enum {
			     false, true
		     } bool, u_bool;
#        endif
#    endif
#endif


#endif /* !UTSBT_H_INCLUDED */

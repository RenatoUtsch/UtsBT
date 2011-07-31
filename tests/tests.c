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
 * >>> Tests File <<<
 * 
 *************************************************************************************************************/

/* Only a small file by now... later I'll make it better... */

#include "../UtsBT.h"
#include <stdio.h>

int main(void) {
    u_char testchar = 'd';
    u_int8 testint8 = 84;
    u_int16 testint16 = 28429;
    u_int32 testint32 = 248975239;
#   if U_INT64_DEFINED
    u_int64 testint64 = 59043875498237L;
#   endif

    printf("%c\n", testchar);
    printf("%hd\n", testint8);
    printf("%d\n", testint16);
    printf("%d\n", testint32);
#   if U_INT64_DEFINED
    printf("%ld\n", testint64);
#   endif

    printf("End Tests!");

    return 0;
}

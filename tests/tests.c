/* Only a small tests program by now... later I'll make it better... */

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

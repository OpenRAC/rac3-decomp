#include "common.h"

/* declared by functions of L39_004BCDE0.c, which this file was cut from */
typedef struct S_004BCDE0 {
    u8 _00[0x88];
    long f88;
    long f90;
    u8 _98[8];
    s32 fA0;
} S_004BCDE0;
extern s32 **func_L39_004BD178(S_004BCDE0 *, s32, s32 *);

/* localdecomp:start func_L39_004BEC38 */
typedef struct {
    s32 num;
    char **data;
} STK_004BEC38;

extern char D_L39_00475580[];
extern char *D_L39_00464828[];
extern STK_004BEC38 *D_L39_00464894 __attribute__((section(".data")));

char *func_L39_004BEC38(s32 n) {
    char *r;

    if (n < 0)
        r = D_L39_00475580;
    else if (n < 27)
        r = D_L39_00464828[n];
    else if (D_L39_00464894 == 0)
        r = D_L39_00475580;
    else if (n - 27 >= D_L39_00464894->num)
        r = D_L39_00475580;
    else
        r = D_L39_00464894->data[n - 27];
    return r;
}
/* localdecomp:end func_L39_004BEC38 */

LINKER_REMNANT("asm/levels", func_L39_004BECA0);

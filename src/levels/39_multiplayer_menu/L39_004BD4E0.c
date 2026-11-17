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

/* localdecomp:start func_L39_004BD4E0 */
extern s32 func_L39_004E23D8(s32);
extern s32 (*D_L39_004647D8[])(s32, s32, s32, s32, s32);

s32 func_L39_004BD4E0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    s32 v;
    s32 n;
    s32 i;

    v = func_L39_004E23D8(a3);
    n = (u32)v >> 28;
    for (i = 0; i < n; i++) {
        D_L39_004647D8[(v >> (i * 4)) & 0xF](a0, a1, a2, a4, a5);
    }
    return 0;
}
/* localdecomp:end func_L39_004BD4E0 */

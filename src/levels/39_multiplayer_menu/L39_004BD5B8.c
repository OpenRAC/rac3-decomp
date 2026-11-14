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

/* localdecomp:start func_L39_004BD5B8 */
/* log: 1) loop over words, xor where the callee says so */
extern s32 func_L39_004E2398(s32, s32, s32);

s32 func_L39_004BD5B8(s32 p, s32 end, s32 base, s32 a3, s32 a4)
{
    while (p < end) {
        if (func_L39_004E2398(p - base, a3, a4) > 0) {
            *(s32 *)p ^= 0x9F8ED17;
        }
        p += 4;
    }
    return 0;
}
/* localdecomp:end func_L39_004BD5B8 */

INCLUDE_ASM("asm/levels", func_L39_004BD658);

INCLUDE_ASM("asm/levels", func_L39_004BD6F8);

INCLUDE_ASM("asm/levels", func_L39_004BD7A8);

INCLUDE_ASM("asm/levels", func_L39_004BD858);

INCLUDE_ASM("asm/levels", func_L39_004BD930);

INCLUDE_ASM("asm/levels", func_L39_004BD9F0);

INCLUDE_ASM("asm/levels", func_L39_004BDAF0);

INCLUDE_ASM("asm/levels", func_L39_004BDC08);

INCLUDE_ASM("asm/levels", func_L39_004BDCE0);

INCLUDE_ASM("asm/levels", func_L39_004BDD80);

INCLUDE_ASM("asm/levels", func_L39_004BDE20);

INCLUDE_ASM("asm/levels", func_L39_004BDEE0);

INCLUDE_ASM("asm/levels", func_L39_004BDFA0);

/* localdecomp:start func_L39_004BE078 */
extern s32 func_L39_004E2398(s32, s32, s32);

s32 func_L39_004BE078(s32 p, s32 end, s32 base, s32 a3, s32 a4) {
    s32 v;

    for (; p < end; p += 4) {
        if (func_L39_004E2398(p - base, a3, a4) > 0) {
            v = *(s32 *)p ^ 0x9F8ED17;
            *(s32 *)p = ((v >> 13) & 0x7FFFF) | ((v << 19) & 0xFFF80000);
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004BE078 */

INCLUDE_ASM("asm/levels", func_L39_004BE150);

INCLUDE_ASM("asm/levels", func_L39_004BE260);

INCLUDE_ASM("asm/levels", func_L39_004BE388);

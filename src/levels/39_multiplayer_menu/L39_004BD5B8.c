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

/* localdecomp:start func_L39_004BD858 */
extern s32 func_L39_004E2398(s32, s32, s32);

s32 func_L39_004BD858(s32 p, s32 end, s32 base, s32 a3, s32 a4) {
    s32 v;

    for (; p < end; p += 4) {
        if (func_L39_004E2398(p - base, a3, a4) > 0) {
            v = *(s32 *)p;
            *(s32 *)p = ((v << 16) & 0xFF0000) | ((v >> 8) & 0xFF) | ((v << 8) & 0xFF000000) | ((v >> 16) & 0xFF00);
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004BD858 */

/* localdecomp:start func_L39_004BD930 */
extern s32 func_L39_004E2398(s32, s32, s32);

s32 func_L39_004BD930(s32 p, s32 end, s32 base, s32 a, s32 b)
{
    for (; p < end; p += 4) {
        if (func_L39_004E2398(p - base, a, b) > 0) {
            *(u32 *)p = (((*(u32 *)p << 13) & 0xFFFFE000) | (*(u32 *)p >> 19)) ^ 0x9F8ED17;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004BD930 */

/* localdecomp:start func_L39_004BD9F0 */
extern s32 func_L39_004E2398(s32, s32, s32);

s32 func_L39_004BD9F0(s32 p, s32 end, s32 base, s32 a3, s32 a4)
{
    u32 x;
    s32 y;

    for (; p < end; p += 4) {
        if (func_L39_004E2398(p - base, a3, a4) > 0) {
            x = *(u32 *)p;
            y = ((x << 8) & 0xFFFFFF00) | (x >> 24);
            y ^= 0xA95128C3;
            *(s32 *)p = ((y << 16) & 0xFF0000) | ((y >> 8) & 0xFF) | ((y << 8) & 0xFF000000) | ((y >> 16) & 0xFF00);
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004BD9F0 */

INCLUDE_ASM("asm/levels", func_L39_004BDAF0);

INCLUDE_ASM("asm/levels", func_L39_004BDC08);

INCLUDE_ASM("asm/levels", func_L39_004BDCE0);

INCLUDE_ASM("asm/levels", func_L39_004BDD80);

/* localdecomp:start func_L39_004BDE20 */
extern s32 func_L39_004E2398(s32, s32, s32);

s32 func_L39_004BDE20(s32 p, s32 end, s32 base, s32 a, s32 b)
{
    for (; p < end; p += 4) {
        if (func_L39_004E2398(p - base, a, b) > 0) {
            *(s32 *)p = ((*(s32 *)p >> 13) & 0x7FFFF) | ((*(s32 *)p << 19) & 0xFFF80000);
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004BDE20 */

/* localdecomp:start func_L39_004BDEE0 */
extern s32 func_L39_004E2398(s32, s32, s32);

s32 func_L39_004BDEE0(s32 p, s32 end, s32 base, s32 a, s32 b)
{
    for (; p < end; p += 4) {
        if (func_L39_004E2398(p - base, a, b) > 0) {
            *(s32 *)p = ((*(s32 *)p >> 8) & 0xFFFFFF) | ((*(s32 *)p << 24) & 0xFF000000);
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004BDEE0 */

/* localdecomp:start func_L39_004BDFA0 */
extern s32 func_L39_004E2398(s32, s32, s32);

s32 func_L39_004BDFA0(s32 p, s32 end, s32 base, s32 a3, s32 a4) {
    s32 v;

    for (; p < end; p += 4) {
        if (func_L39_004E2398(p - base, a3, a4) > 0) {
            v = *(s32 *)p;
            *(s32 *)p = (((v << 8) & 0xFF00) | ((v >> 8) & 0xFF0000)) | (((v >> 16) & 0xFF) | ((v << 16) & 0xFF000000));
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004BDFA0 */

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

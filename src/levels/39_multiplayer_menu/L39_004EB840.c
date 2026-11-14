#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");

/* localdecomp:start func_L39_004EB840 */
s32 func_L39_004EB840(long index)
{
    switch (index) {
    case 2: case 3: case 18: case 19: case 20: case 21: case 22:
        return 0x30;
    case 4: case 5: case 6: case 9: case 11: case 13: case 14: case 15: case 16:
        return 0x2A;
    case 7: case 8:
        return 0x33;
    case 10: case 12:
        return 0x2D;
    case 23:
        return 0x2C;
    case 17:
        return 0x50;
    case 50:
        return 0x28;
    }
    return 0x2E;
}
/* localdecomp:end func_L39_004EB840 */

INCLUDE_ASM("asm/levels", func_L39_004EB8B0);

INCLUDE_ASM("asm/levels", func_L39_004EBB10);

INCLUDE_ASM("asm/levels", func_L39_004EBE78);

INCLUDE_ASM("asm/levels", func_L39_004EBF88);

INCLUDE_ASM("asm/levels", func_L39_004EBFE0);

/* localdecomp:start func_L39_004EC190 */
extern s32 func_L39_004EC250(s32, s32, s32, s32, s32);

s32 func_L39_004EC190(s32 a0, s32 a1, s32 a2) {
    return func_L39_004EC250(a0, a1, 0, 0, a2);
}
/* localdecomp:end func_L39_004EC190 */

INCLUDE_ASM("asm/levels", func_L39_004EC1B8);

INCLUDE_ASM("asm/levels", func_L39_004EC250);

INCLUDE_ASM("asm/levels", func_L39_004EC378);

INCLUDE_ASM("asm/levels", func_L39_004EC548);

INCLUDE_ASM("asm/levels", func_L39_004EC6A8);

/* localdecomp:start func_L39_004EC740 */
s32 func_L39_004EC740(s32 *a0, s32 a1) {
    a0[6] = 3;
    if (a1 >= 0) {
        a0[16] += a1;
        return 0;
    }
    return a1;
}
/* localdecomp:end func_L39_004EC740 */

INCLUDE_ASM("asm/levels", func_L39_004EC768);

/* localdecomp:start func_L39_004EC7B8 */
s32 func_L39_004EC7B8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0xC));
}
/* localdecomp:end func_L39_004EC7B8 */

/* localdecomp:start func_L39_004EC7C0 */
s32 func_L39_004EC7C0(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x10));
}
/* localdecomp:end func_L39_004EC7C0 */

/* localdecomp:start func_L39_004EC7C8 */
s32 func_L39_004EC7C8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0xB8));
}
/* localdecomp:end func_L39_004EC7C8 */

LINKER_REMNANT("asm/levels", func_L39_004EC7D0);

INCLUDE_ASM("asm/levels", func_L39_004EC7D8);

INCLUDE_ASM("asm/levels", func_L39_004EC800);

/* localdecomp:start func_L39_004EC830 */
extern s32 func_11D2EC(void *, void *, s32);

s32 func_L39_004EC830(u8 *a, u8 *b) {
    if (*(s32 *)a != *(s32 *)b || *(s32 *)(a + 0x44) != *(s32 *)(b + 0x44)) {
        return 1;
    }
    return func_11D2EC(a + 0x48, b + 0x48, *(s32 *)(a + 0x44));
}
/* localdecomp:end func_L39_004EC830 */

INCLUDE_ASM("asm/levels", func_L39_004EC870);

/* localdecomp:start func_L39_004ECA10 */
extern s32 func_139328(u8 *);
extern s32 func_L39_004ECAB8(u8 *);
extern s32 func_L39_004ECAD8(s32, s32, s32);
extern s32 func_L39_004ECB48(s32 *);

s32 func_L39_004ECA10(void) {
    u8 buf[8];
    s32 v[7];

    if (func_139328(buf) == 0 || buf[0] != 0) {
        return -1;
    }
    do {
        v[5] = func_L39_004ECAB8(buf + 7) + 100;
        v[4] = func_L39_004ECAB8(buf + 6) - 1;
        v[3] = func_L39_004ECAB8(buf + 5);
    } while (0);
    do { v[2] = func_L39_004ECAB8(buf + 3); } while (0);
    do { v[1] = func_L39_004ECAB8(buf + 2); } while (0);
    v[0] = func_L39_004ECAB8(buf + 1);
    v[6] = func_L39_004ECAD8(v[5] + 0x76C, v[4], v[3]);
    return func_L39_004ECB48(v);
}
/* localdecomp:end func_L39_004ECA10 */

/* localdecomp:start func_L39_004ECAB8 */
s32 func_L39_004ECAB8(u8 *arg0) {
    u8 temp_v1;

    temp_v1 = *arg0;
    return ((temp_v1 >> 4) * 0xA) + (temp_v1 & 0xF);
}
/* localdecomp:end func_L39_004ECAB8 */

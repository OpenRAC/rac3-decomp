#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004E5210);

/* localdecomp:start func_L39_004E5250 */
extern s32 D_L39_0046D350[];

void func_L39_004E5250(s32 arg0) {
    D_L39_0046D350[0] = arg0;
}
/* localdecomp:end func_L39_004E5250 */

INCLUDE_ASM("asm/levels", func_L39_004E5260);

INCLUDE_ASM("asm/levels", func_L39_004E52A0);

INCLUDE_ASM("asm/levels", func_L39_004E58C4);

INCLUDE_ASM("asm/levels", func_L39_004E593C);

INCLUDE_ASM("asm/levels", func_L39_004E59B4);

INCLUDE_ASM("asm/levels", func_L39_004E6030);

INCLUDE_ASM("asm/levels", func_L39_004E6570);

INCLUDE_ASM("asm/levels", func_L39_004E6798);

INCLUDE_ASM("asm/levels", func_L39_004E78D4);

INCLUDE_ASM("asm/levels", func_L39_004E78FC);

INCLUDE_ASM("asm/levels", func_L39_004E7E58);

INCLUDE_ASM("asm/levels", func_L39_004E9D70);

INCLUDE_ASM("asm/levels", func_L39_004EA080);

INCLUDE_ASM("asm/levels", func_L39_004EA230);

/* localdecomp:start func_L39_004EA3C8 */
void func_L39_004EACC8(void *);
void func_L39_004EACD8(void *);
void func_L39_004EACE8(void *);
void func_L39_004EACF8(void *);
extern u8 D_L39_004ED578[];
extern u8 D_L39_004ED6A8[];
extern u8 D_L39_004EEBC0[];
extern u8 D_L39_004EED58[];

s32 func_L39_004EA3C8(void) {
    func_L39_004EACC8(D_L39_004EEBC0);
    func_L39_004EACE8(D_L39_004EED58);
    func_L39_004EACD8(D_L39_004ED578);
    func_L39_004EACF8(D_L39_004ED6A8);
    return 1;
}
/* localdecomp:end func_L39_004EA3C8 */

INCLUDE_ASM("asm/levels", func_L39_004EA410);

INCLUDE_ASM("asm/levels", func_L39_004EA4A8);

INCLUDE_ASM("asm/levels", func_L39_004EA4E0);

/* localdecomp:start func_L39_004EA570 */
/* m2c3 */
s32 func_L39_004E48A8(s32, s32, s32, s32, s32, s32, s32); /* extern */

s32 func_L39_004EA570(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_L39_004E48A8((*(s32 *)((u8 *)(arg0) + 4)), 0x10, arg1, 0, arg2, arg3, 0x12) == 0;
}
/* localdecomp:end func_L39_004EA570 */

INCLUDE_ASM("asm/levels", func_L39_004EA5A8);

INCLUDE_ASM("asm/levels", func_L39_004EA8A0);

INCLUDE_ASM("asm/levels", func_L39_004EA938);

INCLUDE_ASM("asm/levels", func_L39_004EA968);

INCLUDE_ASM("asm/levels", func_L39_004EA9D0);

INCLUDE_ASM("asm/levels", func_L39_004EAA68);

INCLUDE_ASM("asm/levels", func_L39_004EAB38);

INCLUDE_ASM("asm/levels", func_L39_004EABF0);

INCLUDE_ASM("asm/levels", func_L39_004EAC08);

/* localdecomp:start func_L39_004EACC8 */
extern s32 D_L39_0046D3B0[];
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACC8_004EACC8(s32 a0) {
    D_L39_0046D3B0[0] = a0;
}
/* localdecomp:end func_L39_004EACC8 */

/* localdecomp:start func_L39_004EACD8 */
extern s32 D_L39_0046D3B4[];
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACD8_004EACD8(s32 a0) {
    D_L39_0046D3B4[0] = a0;
}
/* localdecomp:end func_L39_004EACD8 */

/* localdecomp:start func_L39_004EACE8 */
extern s32 D_L39_0046D3B8[];
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");
void func_L39_004EACE8_004EACE8(s32 a0) {
    D_L39_0046D3B8[0] = a0;
}
/* localdecomp:end func_L39_004EACE8 */

INCLUDE_ASM("asm/levels", func_L39_004EACF8);

INCLUDE_ASM("asm/levels", func_L39_004EAD18);

INCLUDE_ASM("asm/levels", func_L39_004EADC0);

INCLUDE_ASM("asm/levels", func_L39_004EAED8);

INCLUDE_ASM("asm/levels", func_L39_004EAFA8);

/* localdecomp:start func_L39_004EB0B0 */
typedef struct {
    s32 pad0;
    u8 *f4;
} S1_004EB0B0;

typedef struct {
    u8 pad0[0x30];
    s32 f30;
    u8 pad34[8];
    S1_004EB0B0 *f3C;
    s32 f40;
    s32 f44;
} S_004EB0B0;

extern void func_L39_004CA180(void *, s32);

void func_L39_004EB0B0(S_004EB0B0 *a0, s32 a1, s32 a2) {
    if (a0->f30 == a1) {
        *a0->f3C->f4 = 1;
        a0->f40 = 1;
        a0->f30 = a2;
        a0->f44 = 0;
    }
    func_L39_004CA180(a0, 0x14);
}
/* localdecomp:end func_L39_004EB0B0 */

INCLUDE_ASM("asm/levels", func_L39_004EB100);

INCLUDE_ASM("asm/levels", func_L39_004EB540);

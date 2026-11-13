#include "common.h"

typedef struct E_003354A0 {
    u8 pad0[0x9E];
    u8 f9E;
    u8 f9F;
    u8 pad1[4];
    s16 fA4;
} E_003354A0;
typedef struct O_003354A0 {
    u8 pad0[0x68];
    E_003354A0 *f68;
} O_003354A0;

/* localdecomp:start func_L07_00334B68 */
s32 func_00382498(s32, s32);
void func_L07_003A2380(s32, s32, s32, s32);

void func_L07_00334B68(s32 arg0) {
    func_L07_003A2380(func_00382498(0x43, 0x46) & 0xFF, arg0, 0, 0x64);
}
/* localdecomp:end func_L07_00334B68 */

/* localdecomp:start func_L07_00334BA8 */
s32 func_00382498(s32, s32);
void func_L07_003A2380(s32, s32, s32, s32);

void func_L07_00334BA8(s32 arg0) {
    func_L07_003A2380(func_00382498(0x47, 0x49) & 0xFF, arg0, 0, 0x64);
}
/* localdecomp:end func_L07_00334BA8 */

/* localdecomp:start func_L07_00334BE8 */
s32 func_00382498(s32, s32);
void func_L07_003A2380(s32, s32, s32, s32);

void func_L07_00334BE8(s32 arg0) {
    func_L07_003A2380(func_00382498(0x4A, 0x4E) & 0xFF, arg0, 0, 0x64);
}
/* localdecomp:end func_L07_00334BE8 */

INCLUDE_ASM("asm/levels", func_L07_00334C28);

INCLUDE_ASM("asm/levels", func_L07_00334EC0);

INCLUDE_ASM("asm/levels", func_L07_00334FB0);

INCLUDE_ASM("asm/levels", func_L07_003350F0);

/* localdecomp:start func_L07_00335230 */
s32 func_00382468(s32);
s32 func_00382498(s32, s32);
void func_L07_003A2380(s32, s32, s32, s32);

void func_L07_00335230(s32 arg0) {
    s32 r = func_00382468(4);

    switch (r) {
    case 0:
        func_L07_003A2380(0x4F, arg0, 0, 0x64);
        break;
    case 1:
        func_L07_003A2380(0x50, arg0, 0, 0x64);
        break;
    default:
        func_L07_003A2380(func_00382498(0x67, 0x69) & 0xFF, arg0, 0, 0x64);
        break;
    }
}
/* localdecomp:end func_L07_00335230 */

INCLUDE_ASM("asm/levels", func_L07_003352B8);

/* localdecomp:start func_L07_00335448 */
extern void func_L03_003AECB0(void *);
extern void func_L01_00516FD8(s32, void *);
extern u8 D_L07_001E0D10_00335448 __asm__("D_L07_001E0D10");
__asm__(".extern D_L07_001E0D10, 16");
extern u8 D_L07_001E0D20_00335448 __asm__("D_L07_001E0D20");
__asm__(".extern D_L07_001E0D20, 16");
extern void func_L07_003354A0(O_003354A0 *);

void func_L07_00335448(O_003354A0 *arg0) {
    func_L03_003AECB0(arg0);
    func_L01_00516FD8(0x150006, &D_L07_001E0D10_00335448);
    func_L01_00516FD8(0x150007, &D_L07_001E0D20_00335448);
    func_L07_003354A0(arg0);
}
/* localdecomp:end func_L07_00335448 */

/* localdecomp:start func_L07_003354A0 */
extern u8 D_L07_002B0D40[];
extern u8 D_L07_001DD128[];
extern u8 D_L07_001E0D10[];
extern u8 D_L07_001DD130[];
extern u8 D_L07_001E0D20[];
extern void func_11B2E8(long, ...);
extern s32 func_00381FF0(s32);
extern void func_L03_0032FAB8(s32, s32 *, s32 *);
s32 func_L07_00333460(s32, s32);

void func_L07_003354A0(O_003354A0 *arg0) {
    E_003354A0 *s0;
    s32 buf[2];
    s32 *r;
    s32 id, b0, b1;

    s0 = arg0->f68;
    func_11B2E8((long)D_L07_001E0D10, D_L07_001DD128, s0->f9F + 1, *(s16 *)(D_L07_002B0D40 + s0->f9E * 16));
    r = (s32 *)func_L07_00333460(s0->f9E, s0->f9F);
    if (r[1] != -1) {
        func_L03_0032FAB8(s0->fA4, &buf[0], &buf[1]);
        b1 = buf[1];
        b0 = buf[0];
        func_11B2E8((long)D_L07_001E0D20, D_L07_001DD130, b0, b1);
    } else {
        id = func_00381FF0(0x1921);
        func_11B2E8((long)D_L07_001E0D20, id);
    }
}
/* localdecomp:end func_L07_003354A0 */

INCLUDE_ASM("asm/levels", func_L07_00335558);

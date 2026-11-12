#include "common.h"

/* localdecomp:start func_L34_003515A0 */
s32 func_003C24B0(s32, s32);
void func_L01_00456160(s32, s32);
void func_003C7C38(s32);
void func_L01_004450F0(s32, s32, s32);

s32 func_L34_003515A0(s32 arg0, s32 arg1) {
    u8 *p = (u8 *)func_003C24B0(0x16F4, 0x80);
    u8 *st;

    if (p != 0) {
        func_L01_00456160((s32)p, arg0);
        *(s32 *)(p + 0xF4) = 0;
        func_003C7C38((s32)p);
        st = *(u8 **)(p + 0x68);
        *(s32 *)(st + 0x0) = 0x14D;
        *(s32 *)(st + 0x10) = -1;
        *(s32 *)(st + 0x14) = 0;
        if (arg1 != 0) {
            *(f32 *)(p + 0x2C) = *(f32 *)(p + 0x2C) * 0.4f;
            func_L01_004450F0((s32)p, 2, -1);
        }
    }
    return (s32)p;
}
/* localdecomp:end func_L34_003515A0 */

INCLUDE_ASM("asm/levels", func_L34_00351648);

/* localdecomp:start func_L34_00351B58 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A4F28(s32);
extern void func_L34_00351EB0(void *);
extern void func_003C2880(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern u8 D_001A30B0[];

void func_L34_00351B58(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x68);
    s32 idx;

    if (func_L01_00447490(a0, 0x10000, 0) != 0) {
        idx = *(s32 *)(s1 + 0x18C);
        if (idx != -1) {
            u8 *e = D_001A30B0 + (idx << 7);
            if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        *(s32 *)(s1 + 0x18C) = -1;
        func_L34_00351EB0(a0);
        func_003C2880(a0);
    } else {
        func_L01_0044E850(a0, s1, 3, 0.028800001f, 0.43200004f);
    }
}
/* localdecomp:end func_L34_00351B58 */

/* localdecomp:start func_L34_00351C18 */
s32 func_003C24B0(s32, s32);
void func_L01_00456160(s32, s32);

s32 func_L34_00351C18(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_003C24B0(0x16F5, 0x1C0);
    if (temp_v0 != 0) {
        func_L01_00456160(temp_v0, arg0);
    }
    return temp_v0;
}
/* localdecomp:end func_L34_00351C18 */

INCLUDE_ASM("asm/levels", func_L34_00351C68);

INCLUDE_ASM("asm/levels", func_L34_00351D48);

INCLUDE_ASM("asm/levels", func_L34_00351EB0);

/* localdecomp:start func_L34_00352018 */
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);

void func_L34_00352018(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 r;

    *(s32 *)(p + 0x144) = 1;
    r = func_003824E0(0.8f, 1.2f) * 0.10000001f;
    *(f32 *)(p + 0x178) = r;
    *(f32 *)(p + 0x14C) = func_00382538();
    *(f32 *)(p + 0x154) = *(f32 *)(a0 + 0x18);
}
/* localdecomp:end func_L34_00352018 */

INCLUDE_ASM("asm/levels", func_L34_00352090);

INCLUDE_ASM("asm/levels", func_L34_00352430);

INCLUDE_ASM("asm/levels", func_L34_00352718);

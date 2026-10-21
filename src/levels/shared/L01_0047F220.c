#include "common.h"

/* localdecomp:start func_L01_0047F220 */
extern u8 D_L01_001D82C0;
extern s32 func_00381FF0(s32);
extern s32 func_003B9700(s32, s32, s32, s32, s32);
extern s32 func_003B97B0(void);
extern s32 func_L01_00498110_0047F220(void);
extern void *func_L01_0043B548(s32, s32);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_0047FE28(void);
extern void func_L01_00516090_0047F220(s32);
extern s32 func_L01_00516D60(s32, s32);

s32 func_L01_0047F220(void) {
    s32 a;
    s32 b;
    s32 c;
    s32 r;
    void **p;

    switch (D_L01_001D82C0) {
    case 0:
        return 0;
    case 1:
        a = func_00381FF0(2274);
        b = func_00381FF0(2271);
        c = func_00381FF0(4145);
        func_003B9700(0, a, b, c, 0);
        D_L01_001D82C0 = 2;
        return 1;
    case 2:
        if (func_003B97B0() != 0) {
            return 1;
        }
        r = func_L01_00498110_0047F220();
        if (r == 1) {
            p = func_L01_0043B548(6747, 4);
            if (p != 0) {
                ((void (*)(void))*p)();
            }
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090_0047F220(func_L01_0047FE28());
            D_L01_001D82C0 = 0;
            func_L01_00516D60(0xD000B, 1);
            func_L01_00516D60(0xD0025, 1);
            return 1;
        }
        if (r == 2) {
            D_L01_001D82C0 = 0;
            func_L01_00516D60(0xD000B, 1);
            func_L01_00516D60(0xD0025, 1);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0047F220 */

INCLUDE_ASM("asm/levels", func_L01_0047F370);

INCLUDE_ASM("asm/levels", func_L01_0047F3B0);

INCLUDE_ASM("asm/levels", func_L01_0047F3D8);

INCLUDE_ASM("asm/levels", func_L01_0047F400);

INCLUDE_ASM("asm/levels", func_L01_0047F428);

INCLUDE_ASM("asm/levels", func_L01_0047F450);

/* localdecomp:start func_L01_0047F478 */
extern void func_L01_00516090_0047F478(s32);
extern s32 func_L01_0047FE28(void);
extern void func_L01_00517748(s32);

extern s32 func_L01_00492870(void);
/* no prototype: func_0047C878 passes an arg */
 
void func_L01_0047F478(void) {
    ((s32 (*)())func_L01_00517748)(func_L01_00492870());
    ((void (*)(void *p))func_L01_00516090_0047F478)(((void * (*)())func_L01_0047FE28)());
}
/* localdecomp:end func_L01_0047F478 */

/* localdecomp:start func_L01_0047F4B0 */
extern void func_L01_00516090_0047F4B0(s32);
extern s32 func_L01_0047FE28(void);
extern void func_L01_00517748(s32);

extern s32 func_L01_004A1128(void);
/* no prototype: func_0047C878 passes an arg */
 
void func_L01_0047F4B0(void) {
    ((s32 (*)())func_L01_00517748)(func_L01_004A1128());
    ((void (*)(void *p))func_L01_00516090_0047F4B0)(((void * (*)())func_L01_0047FE28)());
}
/* localdecomp:end func_L01_0047F4B0 */

/* localdecomp:start func_L01_0047F4E8 */
extern s32 func_L01_004914D0(s32);
extern void func_L01_00517748(s32);
extern s32 func_L01_0047FE28(void);
extern void func_L01_00516090_0047F4E8(s32);
void func_L01_0047F4E8(void) {
    func_L01_00517748(func_L01_004914D0(0));
    func_L01_00516090_0047F4E8(func_L01_0047FE28());
}
/* localdecomp:end func_L01_0047F4E8 */

INCLUDE_ASM("asm/levels", func_L01_0047F520);

INCLUDE_ASM("asm/levels", func_L01_0047FAC8);

/* localdecomp:start func_L01_0047FDC0 */
extern s32 func_L01_00517918_0047FDC0();
 
void func_L01_0047FDC0(void) {
    func_L01_00517918_0047FDC0(0x10);
    func_L01_00517918_0047FDC0(0x11);
}
/* localdecomp:end func_L01_0047FDC0 */

/* localdecomp:start func_L01_0047FDE8 */
extern void func_L01_0047E4B8_0047FDE8();
 
void func_L01_0047FDE8(void) {
    func_L01_0047E4B8_0047FDE8();
}
/* localdecomp:end func_L01_0047FDE8 */

/* localdecomp:start func_L01_0047FE08 */
extern void func_L01_0047E520_0047FE08();
 
void func_L01_0047FE08(void) {
    func_L01_0047E520_0047FE08();
}
/* localdecomp:end func_L01_0047FE08 */

/* localdecomp:start func_L01_0047FE28 */
extern s32 func_L01_0047FE28(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0680;
extern s32 D_L01_001E0668[2];
extern void func_L01_0047F520();
extern void func_L01_0047FDC0();
extern void func_L01_0047FAC8();
extern void func_L01_0047FDE8_0047FE28(void);
extern void func_L01_0047FE08_0047FE28();
s32 func_L01_0047FE28(void) {
    if (D_L01_001E0680 == 0) {
        func_003E6FA0(D_L01_001E0668, (s32)func_L01_0047F520, (s32)func_L01_0047FDC0, (s32)func_L01_0047FAC8, (s32)func_L01_0047FDE8_0047FE28, (s32)func_L01_0047FE08_0047FE28);
        D_L01_001E0680 = 1;
    }
    return (s32)D_L01_001E0668;
}
/* localdecomp:end func_L01_0047FE28 */

/* localdecomp:start func_L01_0047FE80 */
extern s32 func_L01_0047FE28_0047FE80(void);
 
void func_L01_0047FE80(void) {
    ((void (*)())func_L01_0047FE28_0047FE80)();
}
/* localdecomp:end func_L01_0047FE80 */

/* localdecomp:start func_L01_0047FEA0 */
s32 func_L01_0047FEA0(void) {
    return 0;
}
/* localdecomp:end func_L01_0047FEA0 */

/* localdecomp:start func_L01_0047FEA8 */
extern s32 func_00392DF0();
void func_L01_0047FEA8(void) {
    func_00392DF0(22, 1);
}
/* localdecomp:end func_L01_0047FEA8 */

/* localdecomp:start func_L01_0047FEC8 */
extern s32 func_L01_004800D8(void);
extern void func_L01_00516090_0047FEC8(s32);
extern void func_L01_00517748(s32);
extern void func_L01_00480B10(s32);
extern s32 func_L01_00482588(void);
void func_L01_0047FEC8(void) {
    func_L01_00480B10(3);
    ((s32 (*)())func_L01_00517748)(func_L01_00482588());
    ((void (*)(void *p))func_L01_00516090_0047FEC8)(((void * (*)())func_L01_004800D8)());
}
/* localdecomp:end func_L01_0047FEC8 */

INCLUDE_ASM("asm/levels", func_L01_0047FF08);

INCLUDE_ASM("asm/levels", func_L01_00480060);

/* localdecomp:start func_L01_00480070 */
extern void func_L01_0047FF08_00480070();
 
void func_L01_00480070(void) {
    func_L01_0047FF08_00480070();
}
/* localdecomp:end func_L01_00480070 */

INCLUDE_ASM("asm/levels", func_L01_00480090);

/* localdecomp:start func_L01_00480098 */
extern void func_L01_0047E4B8_00480098();
 
void func_L01_00480098(void) {
    func_L01_0047E4B8_00480098();
}
/* localdecomp:end func_L01_00480098 */

/* localdecomp:start func_L01_004800B8 */
extern void func_L01_0047E520_004800B8();
 
void func_L01_004800B8(void) {
    func_L01_0047E520_004800B8();
}
/* localdecomp:end func_L01_004800B8 */

/* localdecomp:start func_L01_004800D8 */
extern s32 func_L01_004800D8(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E06A0;
extern s32 D_L01_001E0688[2];
extern void func_L01_00480060_004800D8();
extern void func_L01_00480090();
extern void func_L01_00480070_004800D8();
extern void func_L01_00480098_004800D8(void);
extern void func_L01_004800B8_004800D8();
s32 func_L01_004800D8(void) {
    if (D_L01_001E06A0 == 0) {
        func_003E6FA0(D_L01_001E0688, (s32)func_L01_00480060_004800D8, (s32)func_L01_00480090, (s32)func_L01_00480070_004800D8, (s32)func_L01_00480098_004800D8, (s32)func_L01_004800B8_004800D8);
        D_L01_001E06A0 = 1;
    }
    return (s32)D_L01_001E0688;
}
/* localdecomp:end func_L01_004800D8 */

/* localdecomp:start func_L01_00480130 */
extern s32 func_L01_00452818(s32);

s32 func_L01_00480130(s32 a0) {
    return func_L01_00452818(a0) >= a0;
}
/* localdecomp:end func_L01_00480130 */

/* localdecomp:start func_L01_00480160 */
extern u8 D_001427A1[];

s32 func_L01_00480160(void) {
    return D_001427A1[0] != 0;
}
/* localdecomp:end func_L01_00480160 */

INCLUDE_ASM("asm/levels", func_L01_00480170);

INCLUDE_ASM("asm/levels", func_L01_00480800);

INCLUDE_ASM("asm/levels", func_L01_004809E8);

/* localdecomp:start func_L01_00480A78 */
extern void func_L01_0047E4B8_00480A78();
 
void func_L01_00480A78(void) {
    func_L01_0047E4B8_00480A78();
}
/* localdecomp:end func_L01_00480A78 */

/* localdecomp:start func_L01_00480A98 */
extern void func_L01_0047E520_00480A98();
 
void func_L01_00480A98(void) {
    func_L01_0047E520_00480A98();
}
/* localdecomp:end func_L01_00480A98 */

/* localdecomp:start func_L01_00480AB8 */
extern s32 func_L01_00480AB8(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E06C8;
extern s32 D_L01_001E06B0[2];
extern void func_L01_00480170();
extern void func_L01_004809E8();
extern void func_L01_00480800();
extern void func_L01_00480A78_00480AB8(void);
extern void func_L01_00480A98_00480AB8();
s32 func_L01_00480AB8(void) {
    if (D_L01_001E06C8 == 0) {
        func_003E6FA0(D_L01_001E06B0, (s32)func_L01_00480170, (s32)func_L01_004809E8, (s32)func_L01_00480800, (s32)func_L01_00480A78_00480AB8, (s32)func_L01_00480A98_00480AB8);
        D_L01_001E06C8 = 1;
    }
    return (s32)D_L01_001E06B0;
}
/* localdecomp:end func_L01_00480AB8 */

/* localdecomp:start func_L01_00480B10 */
extern s32 D_L01_001D8368;

void func_L01_00480B10(s32 a) {
    D_L01_001D8368 = a;
}
/* localdecomp:end func_L01_00480B10 */

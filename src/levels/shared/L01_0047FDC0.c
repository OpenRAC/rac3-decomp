#include "common.h"

/* declared by functions of L01_0047F220.c, which this file was cut from */
extern s32 func_00381FF0(s32);
extern s32 func_003B9700(s32, s32, s32, s32, s32);
extern s32 func_003B97B0(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_0047FE28(void);

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

/* localdecomp:start func_L01_0047FF08 */
extern u32 D_L01_001D4CEC_0047FF08;
__asm__(".extern D_L01_001D4CEC_0047FF08, 16");
extern u8 D_L01_001D8310_0047FF08;
extern s32 func_00381FF0(s32);
extern s32 func_003B9700(s32, s32, s32, s32, s32);
extern void func_003B96D8();
extern s32 func_003B97B0(void);
extern s32 func_L01_00498110_0047FF08(void);
extern void func_L01_004981E0_0047FF08(s32, s32);
extern void func_L01_0047DAF8_0047FF08(void);
extern s32 func_L01_004800D8_0047FF08(void);
extern s32 func_L01_0047EBE0_0047FF08(void);
extern void func_L01_00516090_0047FF08(s32);
extern void func_L01_00517748_0047FF08(s32);
extern void func_L01_0047FEC8_0047FF08(void);
extern void func_L01_0047FEA8_0047FF08(void);

s32 func_L01_0047FF08(void) {
    s32 a;
    s32 b;
    s32 c;
    s32 r;

    if (D_L01_001D4CEC_0047FF08 & 1) {
        func_L01_0047DAF8_0047FF08();
        func_L01_00516090_0047FF08(func_L01_004800D8_0047FF08());
        func_L01_00517748_0047FF08(func_L01_0047EBE0_0047FF08());
        return 1;
    }
    switch (D_L01_001D8310_0047FF08) {
    case 0:
        D_L01_001D8310_0047FF08 = 1;
        return 0;
    case 1:
        a = func_00381FF0(1410);
        b = func_00381FF0(2863);
        c = func_00381FF0(3848);
        func_003B9700(0, a, b, c, 1);
        func_L01_004981E0_0047FF08(0x40, 0x1C0);
        func_003B96D8(0x20, 0x80);
        D_L01_001D8310_0047FF08 = D_L01_001D8310_0047FF08 + 1;
        return 1;
    case 2:
        if (func_003B97B0() != 0) {
            return 1;
        }
        r = func_L01_00498110_0047FF08();
        if (r == 1) {
            D_L01_001D8310_0047FF08 = 0;
            func_L01_0047FEC8_0047FF08();
            return 1;
        }
        if (r == 2) {
            D_L01_001D8310_0047FF08 = 0;
            func_L01_0047FEA8_0047FF08();
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0047FF08 */

/* localdecomp:start func_L01_00480060 */
extern s8 D_L01_001D672D_00480060;
void func_L01_00480060(void) {
    D_L01_001D672D_00480060 = 1;
}
/* localdecomp:end func_L01_00480060 */

/* localdecomp:start func_L01_00480070 */
extern void func_L01_0047FF08_00480070();

void func_L01_00480070(void) {
    func_L01_0047FF08_00480070();
}
/* localdecomp:end func_L01_00480070 */

/* localdecomp:start func_L01_00480090 */
extern s8 D_L01_001D8310;

void func_L01_00480090(void) {
    D_L01_001D8310 = 0;
}
/* localdecomp:end func_L01_00480090 */

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

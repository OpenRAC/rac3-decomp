#include "common.h"

INCLUDE_ASM("asm/levels", func_L33_0034D190);

INCLUDE_ASM("asm/levels", func_L33_0034D838);

/* localdecomp:start func_L33_0034E8C0 */
extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern void *func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_L31_003473F0(void *, f32, f32);
void func_L33_0034EC28(u8 *, s32);
extern s32 D_L33_001DD774;
extern f32 D_L33_001DD5BC;
extern f32 D_L33_001DD584;
extern f32 D_L33_001DD580;
extern f32 D_L33_001DD5C0;
extern f32 D_L33_001DD604;
extern f32 D_L33_001DD608;
extern f32 D_L33_001DD628;
extern f32 D_001A4C64[];

typedef struct {
    u8 pad0[0x60];
    f32 f60;
    f32 f64;
    f32 f68;
} S_0034E8C0;

typedef struct {
    u8 pad0[0xF8];
    f32 fF8;
} P_0034E8C0;

void func_L33_0034E8C0(u8 *p) {
    u8 *s = *(u8 **)(p + 0x68);
    u8 *r;
    f32 dmg;

    if (p[0x20] == 10 && *(s32 *)(s + 0x9C) != 0) {
        return;
    }
    func_0038CAD0(s + 0x74);
    func_L01_0044ABD0(p, s);
    r = func_L01_00447490(p, 0x10000, 0);
    if (r != 0) {
        p[0xA8] = 0xFF;
        dmg = *(f32 *)(r + 0x2C);
        if (0.0f < dmg) {
            if (p[0x20] != 1 && *(s32 *)(s + 0x74) <= 0) {
                *(f32 *)(s + 0x10) -= dmg;
                if (*(u8 **)(r + 0x20) != 0 && *(s16 *)(*(u8 **)(r + 0x20) + 0xAA) == 0x173F) {
                    *(s32 *)(s + 0x74) = D_L33_001DD774;
                } else {
                    *(s32 *)(s + 0x74) = 0xC;
                }
                s[9] = 0;
                s[8] = 0;
                s[7] = 0xFF;
                func_003C4A40(p, s);
                if (*(f32 *)(s + 0x10) <= 0.0f) {
                    if (*(f32 *)(r + 0x10) < 0.0f) {
                        ((S_0034E8C0 *)s)->f60 = -D_L33_001DD5BC;
                        *(f32 *)(p + 0xF8) = D_L33_001DD584;
                    } else {
                        ((S_0034E8C0 *)s)->f60 = D_L33_001DD5BC;
                        *(f32 *)(p + 0xF8) = D_L33_001DD580;
                    }
                    ((S_0034E8C0 *)s)->f68 = D_L33_001DD5C0;
                    func_L33_0034EC28(p, 1);
                } else {
                    if (*(f32 *)(r + 0x10) < 0.0f) {
                        ((S_0034E8C0 *)s)->f60 = -D_L33_001DD604;
                        *(f32 *)(p + 0xF8) = D_L33_001DD584;
                    } else {
                        ((S_0034E8C0 *)s)->f60 = D_L33_001DD604;
                        *(f32 *)(p + 0xF8) = D_L33_001DD580;
                    }
                    ((S_0034E8C0 *)s)->f68 = D_L33_001DD608;
                    func_L33_0034EC28(p, 6);
                }
            }
        }
    }
    if (p[0x20] != 1) {
        func_L31_003473F0(p + 0x10, D_L33_001DD628, D_L33_001DD628);
    }
    *(f32 *)(p + 0x14) = D_001A4C64[0];
}
/* localdecomp:end func_L33_0034E8C0 */

/* localdecomp:start func_L33_0034EA80 */
#include "vu0.h"

extern void func_L31_00346998(void *, void *);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
void func_L33_0034F250(u8 *, u8 *);
void func_L33_0034EE00(u8 *, u8 *);
void func_L33_0034F530(u8 *, u8 *);
extern f32 D_L33_001DD638;
extern f32 D_L33_001DD59C;
extern f32 D_L33_001DD5A0;
extern s32 D_L33_001DD610;
extern s32 D_L33_001DD6DC;
extern s32 D_L33_001DD6E0;
extern f32 D_L33_001DD6F4;
extern s32 D_L33_001DD6FC;
extern s32 D_L33_001DD6D8;
extern s32 D_L33_001DD680;
extern s32 D_L33_001DD684;
extern f32 D_L33_001DD6A0;
extern s32 D_L33_001DD6A8;
extern s32 D_L33_001DD67C;
extern s32 D_L33_001DD738;
extern s32 D_L33_001DD73C;
extern f32 D_L33_001DD740;
extern s32 D_L33_001DD74C;
extern s32 D_L33_001DD72C;
extern f32 D_L33_001DD5D8;

typedef struct {
    u8 pad0[0xC0];
    s32 fC0;
    s32 fC4;
} S_0034EA80;

typedef struct {
    u8 obj[0x10];
    s32 val;
} E_0034EA80;

typedef struct {
    u8 pad0[8];
    f32 f8;
    u8 padC[4];
} H_0034EA80;

extern H_0034EA80 D_L33_001E17A0 __attribute__((section(".sdata")));
extern E_0034EA80 D_L33_001E17B0 __attribute__((section(".sdata")));
extern E_0034EA80 D_L33_001E17D0 __attribute__((section(".sdata")));
extern E_0034EA80 D_L33_001E17F0 __attribute__((section(".sdata")));

void func_L33_0034EA80(u8 *p) {
    u8 *s = *(u8 **)(p + 0x68);
    f32 lim;

    if (*(s16 *)(s + 0x14) == 0) {
        *(s16 *)(s + 0x14) = 3;
        *(f32 *)(s + 0x10) = 3.0f;
    }
    if (s[0x24] == 0) {
        s[0x24] = 0x14;
    }
    *(f32 *)(s + 0x20) = 1.5f;
    func_L31_00346998(p, s + 0x50);
    *(s32 *)(s + 0xA0) = 0;
    qzero(s + 0x80);
    *(s32 *)(s + 0xA4) = 0;
    *(s32 *)(s + 0xA8) = 0;
    *(s32 *)(s + 0xAC) = 0;
    *(s32 *)(s + 0xB0) = (*(s32 *)(s + 0xB0) * 5 + 2) / 6;
    lim = *(f32 *)(s + 0xA0);
    if (*(f32 *)(s + 0xB4) < lim) {
        *(f32 *)(s + 0xB4) = D_L33_001DD638;
    }
    if (*(f32 *)(s + 0xB8) < lim) {
        *(f32 *)(s + 0xB8) = D_L33_001DD59C;
    }
    if (*(f32 *)(s + 0xBC) < lim) {
        *(f32 *)(s + 0xBC) = D_L33_001DD5A0;
    }
    ((S_0034EA80 *)s)->fC4 = -1;
    ((S_0034EA80 *)s)->fC0 = 0;
    if (D_L33_001DD610 == 0) {
        D_L33_001DD610 = 1;
        func_L03_0034B218(D_L33_001E17D0.obj, D_L33_001DD6DC, D_L33_001DD6E0, D_L33_001DD6F4, D_L33_001DD6FC, (void *)func_L33_0034F250);
        D_L33_001E17D0.val = D_L33_001DD6D8;
        func_L03_0034B218(D_L33_001E17B0.obj, D_L33_001DD680, D_L33_001DD684, D_L33_001DD6A0, D_L33_001DD6A8, (void *)func_L33_0034EE00);
        D_L33_001E17B0.val = D_L33_001DD67C;
        func_L03_0034B218(D_L33_001E17F0.obj, D_L33_001DD738, D_L33_001DD73C, D_L33_001DD740, D_L33_001DD74C, (void *)func_L33_0034F530);
        qzero(&D_L33_001E17A0);
        D_L33_001E17F0.val = D_L33_001DD72C;
        D_L33_001E17A0.f8 = D_L33_001DD5D8;
    }
}
/* localdecomp:end func_L33_0034EA80 */

/* localdecomp:start func_L33_0034EC28 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_00382498(s32, s32);
extern s32 D_L33_001DD588;
extern s32 D_L33_001DD58C;
extern f32 D_L33_001DD5AC;
extern f32 D_L33_001DD5F4;

void func_L33_0034EC28(u8 *p, s32 state) {
    func_L01_004450F0(p, state, -1);
    switch (p[0x20]) {
    case 1:
        if (p[0x43] != 8) {
            func_003C3A10(p, 8, (s32)D_L33_001DD5AC, D_L33_001DD588);
        }
        *(f32 *)(p + 0x48) = 1.0f;
        *(f32 *)(p + 0x44) += *(f32 *)(p + 0x4C);
        break;
    case 2:
        break;
    case 3:
        if (p[0x43] != 1) {
            func_003C3A10(p, 1, 0, D_L33_001DD588);
        }
        *(f32 *)(p + 0x48) = 1.0f;
        break;
    case 4:
        if (p[0x43] != 5) {
            func_003C3A10(p, 5, 0, D_L33_001DD588);
        }
        *(f32 *)(p + 0x48) = 1.0f;
        break;
    case 5:
        if (p[0x43] != 4) {
            func_003C3A10(p, 4, 0, D_L33_001DD588);
        }
        *(f32 *)(p + 0x48) = 1.0f;
        break;
    case 6:
        func_003C3A10(p, 6, (s32)D_L33_001DD5F4, D_L33_001DD58C);
        *(f32 *)(p + 0x48) = 1.0f;
        *(f32 *)(p + 0x44) += *(f32 *)(p + 0x4C);
        break;
    case 7:
        if (func_00382498(0, 1) == 0) {
            if (p[0x43] != 2) {
                func_003C3A10(p, 2, 0, D_L33_001DD588);
            }
        } else {
            if (p[0x43] != 3) {
                func_003C3A10(p, 3, 0, D_L33_001DD588);
            }
        }
        *(f32 *)(p + 0x48) = 1.0f;
        break;
    case 8:
        if (p[0x43] != 0) {
            func_003C3A10(p, 0, 0, D_L33_001DD588);
        }
    case 9:
        if (p[0x43] != 0) {
            func_003C3A10(p, 0, 0, D_L33_001DD588);
        }
        break;
    case 10:
        if (func_00382498(0, 1) == 0) {
            if (p[0x43] != 2) {
                func_003C3A10(p, 2, 0, D_L33_001DD588);
            }
        } else {
            if (p[0x43] != 3) {
                func_003C3A10(p, 3, 0, D_L33_001DD588);
            }
        }
        *(f32 *)(p + 0x48) = 1.0f;
        break;
    }
}
/* localdecomp:end func_L33_0034EC28 */

INCLUDE_ASM("asm/levels", func_L33_0034EE00);

INCLUDE_ASM("asm/levels", func_L33_0034F250);

INCLUDE_ASM("asm/levels", func_L33_0034F530);

/* localdecomp:start func_L33_0034F910 */
void func_L33_0034F998(void *);
void func_L33_00350378(void *);
void func_L33_00350470(void *);
void func_L33_003505D8(void *);

void func_L33_0034F910(void *arg0) {
    u8 temp_v1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    switch (temp_v1) {                              /* irregular */
    case 0:
        func_L33_00350378(arg0);
        break;
    case 1:
        func_L33_00350470(arg0);
        break;
    case 2:
        func_L33_003505D8(arg0);
        break;
    }
    func_L33_0034F998(arg0);
}
/* localdecomp:end func_L33_0034F910 */

/* localdecomp:start func_L33_0034F998 */
extern float D_001DD7D8;
extern int func_L30_0034D8D8(void *, float);
extern void func_003C2880(void *);

void func_L33_0034F998(void *p)
{
    if (func_L30_0034D8D8((char *)p + 0x10, D_001DD7D8) == 0) {
        func_003C2880(p);
    }
}
/* localdecomp:end func_L33_0034F998 */

/* localdecomp:start func_L33_0034F9D8 */
void func_L33_0034F9D8(u8 *a0, f32 f12, f32 f13, s32 a1, s32 a2, s32 a3, f32 f14, f32 f15, f32 f16) {
    u8 *p = *(u8 **)(a0 + 0x68);

    *(f32 *)(p + 0x2C) = f12;
    *(f32 *)(p + 0x30) = f13;
    *(s32 *)(p + 0x34) = a2;
    *(s32 *)(p + 0x38) = a1;
    *(s32 *)(p + 0x3C) = a3;
    *(f32 *)(p + 0x40) = f14;
    *(f32 *)(p + 0x44) = f15;
    *(f32 *)(p + 0x48) = f16;
}
/* localdecomp:end func_L33_0034F9D8 */

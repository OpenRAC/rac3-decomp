#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L28_0039B910 */
extern u8 D_001426E0[];
extern s16 D_001A4DC0[];
extern s32 D_L28_001DE840;
extern s32 D_001A82AC[];
extern s32 D_001D545C_0039B910;
__asm__(".extern D_001D545C_0039B910, 16");
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0041A5B0(s32, s32);
void func_L28_0039B910(u8 *a0) {
    u8 *q = D_001426E0;
    f32 v[4];
    f32 w[4];
    s32 m, t;
    if (q[0x73] == 0) {
        if (a0[0x20] == 0) {
            a0[0x30] = 0xFF;
            v[0] = 474.54998779f;
            v[1] = 445.32998657f;
            v[2] = 972.21997070f;
            w[2] = -3.11999988f;
            func_L01_004F50C8(v, w, 0, 1);
            q[0x73] = 1;
            D_001A4DC0[0] = 200;
            func_L01_004450F0(a0, 1, -1);
        }
    }
    if (a0[0x20] == 1) {
        if (D_L28_001DE840 > 0x3A98) {
            t = D_001A82AC[0];
            m = 1 << D_001D545C_0039B910;
            if ((t & m) == 0) {
                func_L01_0041A5B0(0xC9E, 0x61);
            }
        }
    }
}
/* localdecomp:end func_L28_0039B910 */

INCLUDE_ASM("asm/levels", func_L28_0039BA28);

/* localdecomp:start func_L28_0039CCD8 */
typedef int q_0039CCD8 __attribute__((mode(TI)));
extern s32 func_L28_0039D038(void *);
extern void func_003C2880(void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 func_L01_0044CE88(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_L02_00351780(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L08_003A0D40(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
s32 func_L28_0039CCD8(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *p;
    s32 t;
    vu0_v4 v;
    if (a0[0x20] == 0) {
        if (func_L28_0039D038(a0) != 0) return 1;
    }
    if (*(f32 *)(a0 + 0x18) < *(f32 *)(st + 0x198) - 200.0f) {
        func_003C2880(a0);
        return 1;
    }
    p = func_L01_00447490(a0, 0x10000, 0);
    if (func_0038CB00(st + 0x36) == 0) p = 0;
    if (p != 0 || *(f32 *)(st + 0x30) <= 0.0f) {
        if (*(u8 **)(p + 0x20) == a0) {
            func_L01_004450F0(a0, 9, -1);
        } else {
            st[0x47] = func_L01_0044CE88(*(u8 **)(p + 0x20));
            func_0038CF68(&v, p + 0x10, -1.0f);
            if (abs_asm(func_0038CE68(&v, a0 + 0xE0) < 0.9f)) *(q_0039CCD8 *)(a0 + 0xC0) = *(q_0039CCD8 *)&v;
            func_0038CE90(a0 + 0xD0, a0 + 0xE0, a0 + 0xC0);
            func_0038CF68(a0 + 0xD0, a0 + 0xD0, 1.0f);
            func_0038CE90(a0 + 0xC0, a0 + 0xD0, a0 + 0xE0);
            func_0038CF68(a0 + 0xC0, a0 + 0xC0, 1.0f);
            *(s16 *)(st + 0x36) = 0x21;
            func_L01_004450F0(a0, 8, -1);
        }
        func_L02_00351780(a0);
    }
    a0[0xA8] = 0xFF;
    func_L01_00452860(a0, st + 0x30, 0);
    if (st[0x5E] != 0) {
        func_L08_003A0D40(a0);
        return 1;
    }
    if (st[0x3E] == 2) return 1;
    if (st[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x180), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x184), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x188), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x18C), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x180), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x184), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x188), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x18C), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L28_0039CCD8 */

/* localdecomp:start func_L28_0039D038 */
/* stores to 0x34 and 0xB8 go through a struct so sched1 sees them as not aliasing the $gp scalars */

typedef int u128_0039D038 __attribute__((mode(TI)));
extern f32 D_L28_001DDDC0;
extern f32 D_L28_001DDDC4;
extern u8 D_L28_001DDDF0;
__asm__(".extern D_L28_001DDDC0, 4");
__asm__(".extern D_L28_001DDDC4, 4");
__asm__(".extern D_L28_001DDDF0, 1");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C7DD8(void *);
typedef struct { u8 pad[0x23]; u8 f23; u8 pad2[0x10]; u16 f34; u8 pad3[0x82]; s32 fB8; } S_0039D038;
s32 func_L28_0039D038(void *self) {
    u8 *a0 = self;
    f32 fa, fb;
    u8 *st = *(u8 **)(a0 + 0x68);
    *(u128_0039D038 *)(st + 0x190) = *(u128_0039D038 *)(a0 + 0x10);
    if (*(s16 *)(a0 + 0xB2) == 0) {
        *(s32 *)(st + 0x1B0) = -1;
        *(s32 *)(st + 0x1B8) = -1;
    }
    a0[0x23] = 0x70;
    ((S_0039D038 *)a0)->f34 |= 0x2100;
    ((S_0039D038 *)a0)->fB8 = 0;
    fa = D_L28_001DDDC4 * 0.00040000002f;
    fb = D_L28_001DDDC0 * 0.020000001f;
    *(s32 *)(st + 0xA8) |= 5;
    *(f32 *)(st + 0x78) = 0.7f;
    *(f32 *)(st + 0x70) = 0.4f;
    *(f32 *)(st + 0x74) = 0.15000001f;
    *(f32 *)(st + 0x7C) = 0.7f;
    *(f32 *)(st + 0x80) = 12.566371f;
    *(f32 *)(st + 0xA0) = 0.34906584f;
    *(f32 *)(st + 0x9C) = 0.00392f;
    func_L01_0045BD78(a0, fa, fb, 0.010053097f, 0.25132743f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(s16 *)(st + 0x34) = 1;
        *(f32 *)(st + 0x30) = 1.0f;
    }
    *(f32 *)(st + 0x40) = 0.25f;
    st[0x39] = D_L28_001DDDF0;
    st[0x3F] = 1;
    st[0x64] = 1;
    st[0x3E] = 1;
    func_L01_004450F0(a0, 3, -1);
    if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 0);
    if (*(s32 *)(st + 0x1B0) != -1 || *(unsigned long *)(st + 0x1B8) != 0xFFFFFFFFUL) {
        func_L01_004450F0(a0, 1, -1);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
    }
    func_003C7DD8(a0);
    return 0;
}
/* localdecomp:end func_L28_0039D038 */

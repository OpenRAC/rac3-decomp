#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_00421730);

/* localdecomp:start func_L01_00421738 */
extern long *D_L01_001E1068;
__asm__(".extern D_L01_001E1068, 16");
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
__asm__(".extern D_001D4BD0, 16");
__asm__(".extern D_001D4BD4, 16");

void func_L01_00421738(s32 a0, s32 a1, s32 a2, s32 a3, long p4, s32 p5) {
    long *q;
    *(s32 *)((u8 *)D_L01_001E1068 + 0) = 0x10000003;
    *(s32 *)((u8 *)D_L01_001E1068 + 4) = 0;
    *(s32 *)((u8 *)D_L01_001E1068 + 8) = 0;
    *(s32 *)((u8 *)D_L01_001E1068 + 12) = 0x50000003;
    q = D_L01_001E1068;
    D_L01_001E1068 = q + 2;
    q[2] = 0x4400000000008001L;
    q[3] = 0x4410;
    q[4] = 70;
    q[5] = p4;
    if (p5 != 0) {
        q[6] = (a0 + D_001D4BD0 - 8) | ((long)(a1 + D_001D4BD4 - 8) << 16) | 0xFFFFF000000000L;
        q[7] = (a2 + D_001D4BD0 - 8) | ((long)(a3 + D_001D4BD4 - 8) << 16) | 0xFFFFF000000000L;
    } else {
        q[6] = ((a0 << 4) + D_001D4BD0 - 16) | ((long)((a1 << 4) + D_001D4BD4 - 16) << 16) | 0xFFFFF000000000L;
        q[7] = ((a2 << 4) + D_001D4BD0 - 16) | ((long)((a3 << 4) + D_001D4BD4 - 16) << 16) | 0xFFFFF000000000L;
    }
    D_L01_001E1068 = D_L01_001E1068 + 6;
}
/* localdecomp:end func_L01_00421738 */

LINKER_REMNANT("asm/levels", func_L01_004218C8);

/* localdecomp:start func_L01_00421988 */
__asm__(".extern D_L01_001D6A08, 4");
__asm__(".extern D_L01_001D6A0C, 4");
__asm__(".extern D_L01_001D6A10, 4");
__asm__(".extern D_L01_001D6A14, 4");
__asm__(".extern D_L01_001D6A18, 4");
extern s32 D_L01_001D6A08;
extern s32 D_L01_001D6A0C;
extern f32 D_L01_001D6A10;
extern s32 D_L01_001D6A14;
extern s32 D_L01_001D6A18;
extern u8 func_L01_00422338(void);
extern u8 func_L01_00421A30(void);
extern void func_L01_00436070(void *, void *, s32);
extern void func_L01_00448248(s32 *, s32, s32);

void func_L01_00421988(s32 mode, s32 a1, s32 a2, f32 f) {
    if (D_L01_001D6A08 == 0 || (D_L01_001D6A0C != 2 && mode == 2)) {
        D_L01_001D6A0C = mode;
        func_L01_00436070(func_L01_00422338, func_L01_00421A30, 1);
    }
    if (mode == D_L01_001D6A0C) {
        D_L01_001D6A14 = a1;
        D_L01_001D6A18 = a2;
        D_L01_001D6A10 = f;
        func_L01_00448248(&D_L01_001D6A08, 10, 2);
    }
}
/* localdecomp:end func_L01_00421988 */

/* localdecomp:start func_L01_00421A30 */
extern u8 D_L01_001D6808;
__asm__(".extern D_L01_001D6808, 1");
extern u8 *D_L01_001D67C8;
extern s32 D_L01_002E5F30[];
typedef struct { u8 pad[0xB0]; f32 fB0; } G_00421A30;
extern G_00421A30 D_L01_001E7580;
extern f32 D_L01_001E11A4;
__asm__(".extern D_L01_001E11A4, 16");
extern s32 D_L01_001E11A0_00421A30;
__asm__(".extern D_L01_001E11A0_00421A30, 16");
extern void func_003873C0(void);
extern s32 func_0038DBD8(s32, s32, f32);
extern void *func_003ABDD8(void *, s32);
extern void func_003AA320(void *, s32, f32, f32, f32, f32, f32);
extern void func_0038AF30(s32, s32, s32, s32, s32);

static __inline__ s32 scale_00421A30(f32 v) {
    f32 z0 = 0.0f, z1 = 0.0f;
    return (s32)(v * D_L01_001E11A4 + 0.5f + (D_L01_001E11A0_00421A30 == 1 ? z0 : z1));
}

u8 func_L01_00421A30(void) {
    f32 sv, f;
    s32 i, c0, c1, c2, c3, t;
    s32 *st;

    if (D_L01_001D67C8 != 0) {
        st = D_L01_002E5F30;
        if (st[0] == 0 && st[9] == -1) {
            sv = D_L01_001E7580.fB0;
            D_L01_001E7580.fB0 = 0.62f;
            func_003873C0();
            f = (f32)D_L01_001D6A08 * 0.1f;
            c0 = func_0038DBD8(0x1465B7, 0x331465B7, f);
            c1 = func_0038DBD8(0x2299DE, 0x332299DE, f);
            if (D_L01_001D6A0C == 3) {
                func_003AA320(func_003ABDD8(D_L01_001D67C8 + 0x7090, 0x10), c0, 484.0f, (f32)scale_00421A30(174.0f), 1.0f, 1.0f, 0.0f);
                func_003AA320(func_003ABDD8(D_L01_001D67C8 + 0x7090, 0x11), c1, 484.0f, (f32)scale_00421A30(174.0f), 1.0f, 1.0f, 0.0f);
            } else {
                func_003AA320(func_003ABDD8(D_L01_001D67C8 + 0x7090, 0x10), c0, 484.0f, (f32)scale_00421A30(206.0f), 1.0f, 1.0f, 0.0f);
                func_003AA320(func_003ABDD8(D_L01_001D67C8 + 0x7090, 0x11), c1, 484.0f, (f32)scale_00421A30(206.0f), 1.0f, 1.0f, 0.0f);
            }
            switch (D_L01_001D6A0C) {
            case 3: {
                f32 a, b, c, k;
                c1 = func_0038DBD8(D_L01_001D6A14 & 0xFFFFFF, D_L01_001D6A14, f);
                a = (f32)scale_00421A30(253.0f);
                b = (f32)scale_00421A30(253.0f - (1.0f - D_L01_001D6A10) * 157.0f);
                k = (f32)scale_00421A30(96.0f) * 0.2f;
                c = a - k + 1.0f;
                for (i = 0; i < 10; i++) {
                    if (c <= b) {
                        c = b;
                    }
                    func_0038AF30((s32)c, (s32)a, 0x1DD, 0x1E9, c1);
                    a -= k;
                    c -= k;
                    if (a <= b) {
                        break;
                    }
                }
                break;
            }
            case 0: {
                f32 a, b, c, k, k2;
                if (D_L01_001D6A10 >= 0.0f && D_L01_001D6A10 <= 1.0f) {
                    c2 = func_0038DBD8(D_L01_001D6A14 & 0xFFFFFF, D_L01_001D6A14, f);
                    c3 = func_0038DBD8(D_L01_001D6A18 & 0xFFFFFF, D_L01_001D6A18, f);
                    t = scale_00421A30((f32)(0x11D - (s32)((1.0f - D_L01_001D6A10) * 157.0f)));
                    b = (f32)scale_00421A30(128.0f) * 0.25f;
                    a = (f32)scale_00421A30(285.0f);
                    c = a - b + 1.0f;
                    for (i = 0; i < 5; i++) {
                        k = (f32)t;
                        if (c <= k) {
                            c = k;
                        }
                        func_0038AF30((s32)c, (s32)a, 0x1DD, 0x1E9, c2);
                        a -= b;
                        c -= b;
                        if (a <= k) {
                            break;
                        }
                    }
                    c = (f32)scale_00421A30(128.0f);
                    a = c + b - 1.0f;
                    for (i = 0; i < 5; i++) {
                        k2 = (f32)t;
                        if (k2 <= a) {
                            a = k2;
                        }
                        func_0038AF30((s32)c, (s32)a, 0x1DC, 0x1E8, c3);
                        c += b;
                        a += b;
                        if (k2 <= c) {
                            break;
                        }
                    }
                }
                break;
            }
            case 1:
            case 2: {
                f32 a, b, c, k;
                c2 = func_0038DBD8(D_L01_001D6A14 & 0xFFFFFF, D_L01_001D6A14, f);
                t = scale_00421A30((f32)(0x11D - (s32)((1.0f - D_L01_001D6A10) * 157.0f)));
                b = (f32)scale_00421A30(128.0f) * 0.25f;
                a = (f32)scale_00421A30(285.0f);
                c = a - b + 1.0f;
                for (i = 0; i < 5; i++) {
                    k = (f32)t;
                    if (c <= k) {
                        c = k;
                    }
                    func_0038AF30((s32)c, (s32)a, 0x1DC, 0x1E8, c2);
                    a -= b;
                    c -= b;
                    if (a <= k) {
                        break;
                    }
                }
                break;
            }
            }
            D_L01_001E7580.fB0 = sv;
            func_003873C0();
        }
    }
    return D_L01_001D6808;
}
/* localdecomp:end func_L01_00421A30 */

/* localdecomp:start func_L01_00422338 */
__asm__(".extern D_L01_001D6A08, 4");
__asm__(".extern D_L01_001D6808, 1");
extern u8 D_L01_001D6808;
extern s32 D_L01_001D6694[] __attribute__((section(".sdata")));
extern s32 func_0038CAD0(void *);
extern void func_L01_004360B8(s32);

u8 func_L01_00422338(void) {
    s32 v = D_L01_001D6694[0];
    if (v == 0 || v == 7) {
        if (func_0038CAD0(&D_L01_001D6A08)) {
            func_L01_004360B8(1);
        }
    }
    return D_L01_001D6808;
}
/* localdecomp:end func_L01_00422338 */

/* localdecomp:start func_L01_00422388 */
extern void func_L01_00422388(void);

extern s32 D_L01_001D6A3C;
void func_L01_00422388(void) {
    *(u8 *)&D_L01_001D6A3C = 1;
}
/* localdecomp:end func_L01_00422388 */

#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003E51D0 */
typedef struct { u8 pad_0[0xB0]; u8 flag; } MobyA_003E51D0;
typedef struct { u8 pad_0[0x70]; s32 index; } MobyB_003E51D0;

extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern u8 D_001BBC40[];
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 func_L01_00456250(u8 *);

s32 func_L04_003E51D0(MobyA_003E51D0 *a0, MobyB_003E51D0 *a1) {
    s32 v;

    v = a1->index;
    if (v >= 0) {
        if (func_L01_00456250(D_L04_001DFD9C + (v << 8)) != 0) {
            return 1;
        }
    }
    if (a0->flag != 0xFF) {
        if ((D_001BBC40[a0->flag + (D_001D545C_sda << 4)] & 0x80) != 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L04_003E51D0 */

/* localdecomp:start func_L04_003E5250 */
typedef struct R_3E5250 { u8 pad_0[0x10]; u8 f10; } R_3E5250;
typedef struct Q_3E5250 { u8 pad_0[0x10]; s32 f10; u8 pad_14[0x34]; R_3E5250 *f48; } Q_3E5250;
typedef struct V4_3E5250 { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3E5250;
typedef struct B_3E5250 {
    u8 pad_0[0x30];
    u8 f30[0x40];
    s32 f70;
    s32 f74;
    f32 f78;
    f32 f7C;
    s32 f80;
    s32 f84;
    s32 f88;
    f32 f8C;
} B_3E5250;
typedef struct A_3E5250 {
    u8 pad_0[0x20];
    u8 f20;
    u8 pad_21[0x3];
    Q_3E5250 *f24;
    u8 pad_28[0x1A];
    u8 f42;
    u8 f43;
    u8 pad_44[0x4];
    f32 f48;
    u8 pad_4c[0x14];
    u8 f60;
    u8 pad_61[0x7];
    B_3E5250 *f68;
    u8 pad_6c[0x2A];
    u16 f96;
    s32 f98;
    u8 pad_9c[0x54];
    V4_3E5250 vec;
} A_3E5250;
typedef struct G_3E5250 { u8 pad_0[0x35C]; void *f35C; s32 f360; } G_3E5250;

extern G_3E5250 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern u8 D_L04_001D66B0[8];
extern f32 D_001DF1BC_sda;
__asm__(".extern D_001DF1BC_sda, 4");
extern f32 D_001DF1B8_sda;
__asm__(".extern D_001DF1B8_sda, 4");
extern f32 D_001DF1C0_sda;
__asm__(".extern D_001DF1C0_sda, 4");
extern s32 D_001DF1C4_sda;
__asm__(".extern D_001DF1C4_sda, 4");
extern s32 D_001DF1C8_sda;
__asm__(".extern D_001DF1C8_sda, 4");
extern f32 D_001DF1CC_sda;
__asm__(".extern D_001DF1CC_sda, 4");
extern f32 D_001DF1D0_sda;
__asm__(".extern D_001DF1D0_sda, 4");
extern f32 D_001DF1D4_sda;
__asm__(".extern D_001DF1D4_sda, 4");
extern u8 *D_001DFD9C_sda;
__asm__(".extern D_001DFD9C_sda, 4");

extern s32 func_L04_003E5788(void *);
extern s32 func_L04_003E5898(u8 *, s32);
extern void func_L04_003E5D88(void *);
extern void func_L04_003E5FB8(u8 *, f32);
extern f32 func_L04_003E5E78(void *);
extern void func_L04_003E5940();
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_L01_004395E0(void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C4138(f32, f32, void *);
extern void func_003C4DA8(void *, void *, void *, void *);
extern void func_L01_00448690(void *, s32, f32, f32);
extern void func_L01_00404808(void *, void *);

void func_L04_003E5250(A_3E5250 *a0) {
    B_3E5250 *s0;
    V4_3E5250 loc;
    s32 r;
    f32 f0;
    V4_3E5250 *vp;

    s0 = a0->f68;
    switch (a0->f20) {
    case 0:
        a0->f98 = 0;
        s0->f74 = func_L04_003E5788(a0);
        r = func_00382468(a0->f24->f48->f10);
        func_003C3A10(a0, 0, r, 1);
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L04_003E51D0((MobyA_003E51D0 *)a0, (MobyB_003E51D0 *)s0) == 0) break;
        if (func_L04_003E5898((u8 *)a0, 0) == 0) break;
        func_L01_004450F0(a0, 2, -1);
        break;
    case 2:
        if (a0->f43 == 0) {
            s32 old = a0->f96;
            a0->f96 = old + 1;
            if ((s0->f74 + 1) * 12 < old) {
                if (s0->f74 == 0) func_003A52A0(1, 4, a0);
                if (a0->f43 == 1) break;
                func_003C3A10(a0, 1, 0, 4);
                break;
            }
        }
        if (a0->f42 != 1) break;
        if ((a0->f60 & 2) == 0) break;
        func_L01_004450F0(a0, 3, -1);
        if (a0->f43 == 2) break;
        func_003C3A10(a0, 2, 0, 4);
        break;
    case 3:
        a0->f48 = 0.0f;
        if (func_L04_003E5898((u8 *)a0, 2) == 0) break;
        func_L01_004450F0(a0, 4, -1);
        if (s0->f74 == 0) {
            a0->f48 = D_001DF1BC_sda + 0.01f;
        } else {
            a0->f48 = func_003824E0(D_001DF1B8_sda, D_001DF1BC_sda);
        }
        break;
    case 4:
        if (a0->f42 != a0->f43) break;
        if (54.0f < func_L01_004395E0(a0)) {
            f0 = func_L01_00443A18(0.0f, D_001DF1C0_sda) * 0.0174532924f;
            s0->f7C = 1.0f;
            s0->f78 = f0 * 0.0200000014f;
            if (s0->f70 != -1 && func_L01_00456250(D_L04_001DFD9C + (s0->f70 << 8)) != 0) {
                s0->f8C = 0.0f;
            } else {
                s0->f8C = 1.0f;
            }
            if (a0->f43 != 3) func_003C3A10(a0, 3, 0, 1);
            a0->f98 = a0->f24->f10;
            func_L01_004450F0(a0, 5, -1);
            func_L04_003E5D88(a0);
        }
        break;
    case 5:
        if (s0->f74 == 0) func_L01_00404808((void *)func_L04_003E5940, a0);
        if (D_001A4BE0.f35C == a0 && D_001A4BE0.f360 != 0) {
            if (s0->f84 == 0) {
                func_L04_003E5D88(a0);
                s0->f84 = 1;
            }
        } else {
            s0->f84 = 0;
        }
        if (func_0038CAD0(&s0->f80) != 0 && D_001A4BE0.f35C == a0 && D_001A4BE0.f360 != 0) {
            s0->f7C = 1.0f;
            r = func_00382498(D_001DF1C4_sda, D_001DF1C8_sda);
            s0->f80 = (r * 5 + 2) / 6;
        } else {
            func_003C4138(0.0f, D_001DF1CC_sda * 0.0200000014f, &s0->f7C);
        }
        vp = &a0->vec;
        loc = *vp;
        f0 = func_L04_003E5E78(a0);
        func_L04_003E5FB8((u8 *)a0, f0);
        func_003C4DA8(s0->f30, D_L04_001D66B0, &loc, vp);
        if (s0->f70 != -1 && func_L01_00456250(D_001DFD9C_sda + (s0->f70 << 8)) == 0) {
            func_003C4138(1.0f, D_001DF1D4_sda * 0.0200000014f, &s0->f8C);
            if (s0->f88 != 0 && func_L04_003E5898((u8 *)a0, 3) != 0) {
                func_L01_004450F0(a0, 6, -1);
                a0->f98 = 0;
            }
        } else {
            func_003C4138(0.0f, D_001DF1D0_sda * 0.0200000014f, &s0->f8C);
        }
        break;
    case 6:
        func_L01_00448690(&a0->vec, 0, 0.0f, 0.0209439527f);
        if (a0->f43 == 3) {
            s32 old = a0->f96++;
            if (s0->f74 * 12 < old) func_003C3A10(a0, 4, 0, 4);
        } else if (a0->f42 == 4 && (a0->f60 & 2) != 0) {
            func_L01_004450F0(a0, 1, -1);
            if (a0->f43 != 0) func_003C3A10(a0, 0, 0, 4);
        }
        break;
    }
}
/* localdecomp:end func_L04_003E5250 */

/* localdecomp:start func_L04_003E5788 */
extern u16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern s32 D_L04_001DFDD8;
extern void func_003C5060(u8 *, void *, void *, void *);

s32 func_L04_003E5788(void *a0) {
    u8 *self = a0;
    u16 *p;
    u8 *e;
    s32 n = 0;
    vu0_v4 v;
    for (p = D_L04_0021C9A0[self[0x21]];
         self[0x21] != 0xFF && self[0x21] <= D_L04_001DFDD8 && p != 0 &&
         ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[self[0x21]]);
         p++) {
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return n;
        if (e != self) {
            vec_sub_ab(&v, e + 0x10, self + 0x10);
            func_003C5060(self, &v, &v, 0);
            if (v.x < 0.0f)
                n++;
        }
    }
    return n;
}
/* localdecomp:end func_L04_003E5788 */

/* localdecomp:start func_L04_003E5898 */
extern u16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern s32 D_L04_001DFDD8;

s32 func_L04_003E5898(u8 *a0, s32 a1) {
    u16 *p;
    u8 *e;
    p = D_L04_0021C9A0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L04_001DFDD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[a0[0x21]])) {
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        if (e[0x43] != a1) return 0;
    }
    return 1;
}
/* localdecomp:end func_L04_003E5898 */

INCLUDE_ASM("asm/levels", func_L04_003E5940);

/* localdecomp:start func_L04_003E5D88 */
typedef struct { f32 f[6]; } V_003E5D88;

extern u8 D_L04_001DF278[];
extern s32 D_001DF270_sda;
__asm__(".extern D_001DF270_sda, 4");
extern s32 func_00382468(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_004AB048(s32, s32);

void func_L04_003E5D88(void *a0) {
    u8 *s0;
    V_003E5D88 v;
    s32 idx;
    s32 r;
    f32 f20;
    f32 val;

    s0 = *(u8 **)((u8 *)a0 + 0x68);
    v = *(V_003E5D88 *)D_L04_001DF278;
    idx = func_00382468(5);
    f20 = 1024.0f;
    val = *(f32 *)(s0 + 0x8C);
    if (idx == D_001DF270_sda) {
        idx++;
    }
    D_001DF270_sda = idx;
    if (val != 0.0f) {
        f20 = 512.0f;
    }

    r = func_003A52A0(0, 0, a0);
    if (r != -1) {
        func_L01_004AB048(r, (s32)(f20 * v.f[idx]));
    }
}
/* localdecomp:end func_L04_003E5D88 */

/* localdecomp:start func_L04_003E5E78 */
extern u16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern s32 D_L04_001DFDD8;
extern G_3E5250 D_001A4BE0;
__asm__(".extern D_L04_001DF290, 4");
extern f32 D_L04_001DF290;
extern void func_003C5060(u8 *, void *, void *, void *);

f32 func_L04_003E5E78(void *a0) {
    u8 *self = a0;
    u8 *q = *(u8 **)(self + 0x68);
    u16 *p;
    u8 *e;
    f32 hi = 0.0f;
    f32 lo = hi;
    f32 r;
    vu0_v4 v;

    for (p = D_L04_0021C9A0[self[0x21]];
         self[0x21] != 0xFF && self[0x21] <= D_L04_001DFDD8 && p != 0 &&
         ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[self[0x21]]);
         p++) {
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s32 *)(*(u8 **)(e + 0x68) + 0x74) == *(s32 *)(q + 0x74) - 1) {
            lo = *(f32 *)(e + 0xF0);
        } else if (*(s32 *)(*(u8 **)(e + 0x68) + 0x74) == *(s32 *)(q + 0x74) + 1) {
            hi = *(f32 *)(e + 0xF0);
        }
    }
    r = (lo + hi) * 0.5f;
    if (D_001A4BE0.f360 != 0) {
        if (D_001A4BE0.f35C != self)
            return r;
        vec_sub_ba(&v, (u8 *)&D_001A4BE0 + 0x80, self + 0x10);
        func_003C5060(self, &v, &v, 0);
        r += v.y * D_L04_001DF290;
    }
    return r;
}
/* localdecomp:end func_L04_003E5E78 */

/* localdecomp:start func_L04_003E5FB8 */
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 D_001DF294_sda;
__asm__(".extern D_001DF294_sda, 4");
extern f32 D_001DF298_sda;
__asm__(".extern D_001DF298_sda, 4");

void func_L04_003E5FB8(u8 *arg0, f32 fparg0) {
    u8 *s0;
    f32 t;
    f32 x;

    s0 = *(u8 **)(arg0 + 0x68);
    t = func_0038DB00(fparg0, *(f32 *)(arg0 + 0xF0));
    x = *(f32 *)(s0 + 0x78);
    *(f32 *)(s0 + 0x78) = x + (t * D_001DF294_sda + x * D_001DF298_sda);
    *(f32 *)(arg0 + 0xF0) = func_0038DAB8(*(f32 *)(arg0 + 0xF0), *(f32 *)(s0 + 0x78));
}
/* localdecomp:end func_L04_003E5FB8 */

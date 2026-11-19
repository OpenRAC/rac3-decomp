/* functional: medium. Hand-written from PAL assembly (no draft existed). Light-beam/spark effect object update (types 1, 2, 3 = fade in/steady/out stages with particle sparks); the tail registers the draw callback func_L03_003A5388. All delay-slot stores read against the asm (e.g. v->0x8 = 0 before the +0xC test). Needs the unit's func_L03_003A51E0 signature (void*, s32). */
#include "common.h"

/* localdecomp:start func_L11_003B4870 */
typedef int Quad_003B4870 __attribute__((mode(TI)));
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_003B4870;

extern V_003B4870 D_L11_001E1700;
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern u8 *D_L11_001DEF00;
__asm__(".extern D_L11_001E1700, 16");
__asm__(".extern D_L11_001DEF00, 16");
extern void func_L11_003B4FB0(void *);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_00456500(void *, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L03_003A51E0(void *, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0046B458(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);
extern void func_L01_004048D0(void *, u8 *);
extern void func_L03_003A5388(void);

void func_L11_003B4870(u8 *self) {
    u8 *v;
    s32 c20;
    s32 c21;
    s32 type;
    s32 h;
    s32 n;
    s32 rr;
    f32 f20;
    f32 f0;
    f32 dist;
    f32 dot;
    f32 f21;
    f32 f22;
    f32 ang;
    V_003B4870 a;
    V_003B4870 b;
    V_003B4870 c;
    V_003B4870 zero;

    v = *(u8 **)(self + 0x68);
    c21 = ((v[0x1E] + 0x20) << 16) | (((v[0x1D] + 0x20) << 8) | 0x60000000) | (v[0x1C] + 0x20);
    c20 = (v[0x1E] << 16) | ((v[0x1D] << 8) | 0x80000000) | v[0x1C];
    if (self[0x20] == 0) {
        func_L11_003B4FB0(self);
    }
    if (self[0x95] == 0) {
        return;
    }
    f20 = 0.0f;
    if (self[0x20] != 1) {
        a.v[0] = *(f32 *)(self + 0x10) - D_L11_001E1700.v[0];
        a.v[1] = *(f32 *)(self + 0x14) - D_L11_001E1700.v[1];
        a.v[2] = *(f32 *)(self + 0x18) - D_L11_001E1700.v[2];
        a.v[3] = *(f32 *)(self + 0x1C);
        dist = func_L01_0040E548(self + 0x10, D_001A4C60);
        if (dist < 2304.0f) {
            dot = ((f32 *)&D_L11_001E1700)[8] * a.v[0] + ((f32 *)&D_L11_001E1700)[9] * a.v[1];
            if (0.0f < dot) {
                f20 = 1.0f - (dist - 576.0f) / 1728.0f;
                if (f20 < 0.0f) {
                    f0 = 0.0f;
                } else if (f20 > 1.0f) {
                    f0 = 1.0f;
                } else {
                    f0 = f20;
                }
                f20 = f0;
            }
        }
    }
    type = self[0x20];
    if (type == 1) {
        if (func_L01_004561B8(self) != 0) {
            h = *(s32 *)(v + 0x14);
            if (h >= 0 && *(u8 **)(D_001A30B0 + h * 128 + 0xDC) == self) {
                func_003A4F28(h);
            }
            *(s32 *)(v + 0x14) = -1;
        }
        if (*(s32 *)(v + 0x18) == -1) {
            return;
        }
        f0 = *(f32 *)(v + 4) - 0.1f;
        if (f0 < 0.0f) {
            f0 = 0.0f;
        }
        *(f32 *)(v + 4) = f0;
        *(s32 *)(v + 8) = 0;
        if (*(s32 *)(v + 0xC) == 0 || func_L01_00456250(self) == 0) {
            func_L01_004450F0(self, 3, -1);
        }
        if (*(s32 *)(v + 0x24) != -1 && func_L01_00456500(D_001A4C60, *(s32 *)(v + 0x24)) != 0) {
            *(s32 *)(v + 0xC) = 0;
            func_L01_004450F0(self, 3, -1);
        }
    } else if (type == 2) {
        func_L01_004561B8(self);
        h = *(s32 *)(v + 0x14);
        if (h == -1 || *(u8 **)(D_001A30B0 + h * 128 + 0xDC) != self) {
            *(s32 *)(v + 0x14) = func_003A52A0(1, 4, self);
        }
        f0 = *(f32 *)(v + 4) + 0.05f;
        if (1.0f < f0) {
            f0 = 1.0f;
        }
        *(f32 *)(v + 4) = f0;
        *(s32 *)(v + 8) = *(s32 *)(v + 0x18);
        if (*(s32 *)(v + 0xC) > 0 || func_L01_00456250(self) > 0) {
            func_L01_004450F0(self, 1, -1);
        }
        if (*(s32 *)(v + 0x28) != -1 && func_L01_00456500(D_001A4C60, *(s32 *)(v + 0x28)) != 0) {
            *(s32 *)(v + 0xC) = 1;
            func_L01_004450F0(self, 1, -1);
        }
        n = (s32)(f20 * 10.0f);
        if (n > 0) {
            f21 = 0.0f;
            f22 = 0.1f;
            do {
                func_L03_003A51E0(&a, *(s32 *)v);
                n--;
                c = *(V_003B4870 *)(D_L11_001DEF00 + *(s32 *)v * 128 + 0x30);
                b.v[0] = c.v[0] - a.v[0];
                b.v[1] = c.v[1] - a.v[1];
                b.v[2] = c.v[2] - a.v[2];
                b.v[3] = c.v[3];
                f20 = func_003824E0(f21, 0.2f);
                func_0038CE20(&b, &b, f20 * func_003824E0(f21, f22));
                f20 = func_003824E0(0.5f, 1.0f);
                func_L01_0046B458((f32 *)&a, 0x28, c20, 0, func_00382498(-10, 10), (f32 *)&b, f22, f20, f21, 0);
            } while (n != 0);
        }
    } else if (type == 3) {
        if (func_L01_004561B8(self) != 0) {
            h = *(s32 *)(v + 0x14);
            if (h >= 0) {
                if (*(u8 **)(D_001A30B0 + h * 128 + 0xDC) == self && D_001A30B0[h * 128 + 0xD0] != 0) {
                    func_003A4F28(h);
                }
                *(s32 *)(v + 0x14) = -1;
            }
            *(s32 *)(v + 0x14) = func_003A52A0(0, 0, self);
        }
        *(s32 *)(v + 8) = *(s32 *)(v + 8) + 1;
        *(f32 *)(v + 4) = 0.0f;
        if (*(s32 *)(v + 8) >= *(s32 *)(v + 0x18)) {
            *(s32 *)(v + 0x14) = -1;
            func_L01_004450F0(self, 2, -1);
        }
        if (*(s32 *)(v + 0xC) > 0 || func_L01_00456250(self) > 0) {
            h = *(s32 *)(v + 0x14);
            if (h >= 0) {
                if (*(u8 **)(D_001A30B0 + h * 128 + 0xDC) == self && D_001A30B0[h * 128 + 0xD0] != 0) {
                    func_003A4F28(h);
                }
                *(s32 *)(v + 0x14) = -1;
            }
            func_L01_004450F0(self, 1, -1);
        }
        f0 = (f32)(*(s32 *)(v + 8) * 10) * 0.5f;
        dot = 3.0f;
        if (*(s32 *)(v + 0x18) != 0) {
            dot = (f32)*(s32 *)(v + 0x18);
        }
        n = (s32)(f20 * (f0 / dot));
        if (n > 0) {
            do {
                func_L03_003A51E0(&a, *(s32 *)v);
                n--;
                *(Quad_003B4870 *)&zero = 0;
                rr = func_00382498(20, 30);
                f20 = func_003824E0(0.3f, 0.8f);
                func_L01_0046B458((f32 *)&a, rr, c21, 0, func_00382498(-6, 6), (f32 *)&zero, 0.08f, f20, 0.0f, 0);
            } while (n != 0);
        }
    }
    ang = *(f32 *)(v + 0x10) + 0.05235988f;
    *(f32 *)(v + 0x10) = ang;
    if (3.1415927f <= ang) {
        *(f32 *)(v + 0x10) = ang - 6.2831855f;
    }
    if (0.0f < *(f32 *)(v + 4)) {
        func_L01_004048D0(func_L03_003A5388, self);
        *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
    } else {
        *(s32 *)(self + 0x98) = 0;
    }
}
/* localdecomp:end func_L11_003B4870 */

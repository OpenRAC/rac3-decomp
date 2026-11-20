#include "common.h"

/* localdecomp:start func_L40_00431948 */
typedef struct O_00431948 O_00431948;
typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(O_00431948 *, s32);
} VT_00431948;
struct O_00431948 {
    u8 pad0[0x14];
    VT_00431948 *vt;
};

extern u8 *D_001D5F30_sda;
__asm__(".extern D_001D5F30_sda, 4");
extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 4");
extern f32 D_L40_00247A04;
__asm__(".extern D_L40_00247A04, 4");
extern f32 D_L40_00247A08;
__asm__(".extern D_L40_00247A08, 4");
extern s32 D_L40_00247A10;
__asm__(".extern D_L40_00247A10, 4");
extern f32 D_L40_00247A14;
__asm__(".extern D_L40_00247A14, 4");
extern s32 D_L40_00247A18;
__asm__(".extern D_L40_00247A18, 4");
extern s32 D_L40_00247A1C;
__asm__(".extern D_L40_00247A1C, 4");
extern u8 D_001FE020[];
extern void func_L01_0044ABD0(u8 *m, u8 *a1);
extern void func_003C2880(u8 *m);
extern s32 func_L40_003F6078(u8 *m);
extern u8 *func_L39_0066C828(u8 *m, s32 a1, s32 a2);
extern void func_L39_0061C1E0(u8 *m, s32 a1);
extern O_00431948 *func_L39_0061D7B0(u8 *m);
extern void func_L01_004450F0(u8 *m, s32 a1, s32 a2);
extern s32 func_L39_005F33E0(s32 a0, s32 a1, u8 *m);
extern void func_L40_00431EA0(u8 *m);
extern s32 func_L01_004561B8(u8 *m);
extern void func_L40_00431C00(u8 *m);
extern void func_L39_005F2FF8(u8 *m, s32 a1);
extern s32 func_L39_005B4398(s32 n);
extern void func_L40_004311A8(u8 *m, f32 f12, f32 f13, f32 f14, f32 f15, s32 a1, s32 a2, s32 a3);

void func_L40_00431948(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 t;
    s32 idx;
    O_00431948 *o;
    f32 s;
    u8 *e;

    if (*(u16 *)(m + 0x96) < 0xFFFF) {
        *(u16 *)(m + 0x96) += 1;
    }
    if (m[0x20] != 2) {
        func_L01_0044ABD0(m, v + 0x70);
    }
    switch (m[0x20]) {
    case 0:
        t = -1;
        if (*(s8 *)(D_001D5F30_sda + 0x190) == 0) {
            func_003C2880(m);
            break;
        }
        idx = *(s32 *)(v + 0x8C);
        if (idx >= 0) {
            t = func_L40_003F6078(D_L40_0024845C + idx * 0x100);
        }
        *(s32 *)(func_L39_0066C828(m, -1, 1) + 0x28) = t;
        *(s32 *)(v + 0x88) = t;
        func_L39_0061C1E0(m, -1);
        o = func_L39_0061D7B0(m);
        if (o->vt->f1C(o, 0) != 0) {
            m[0xBE] = (m[0xBE] | 0x10) & ~8;
        } else if (o->vt->f1C(o, 1) != 0) {
            m[0xBE] = (m[0xBE] | 8) & ~0x10;
        } else {
            m[0xBE] &= ~0x18;
        }
        *(s32 *)(v + 0x90) = 0;
        *(u16 *)(m + 0x34) |= 0x4000;
        *(s32 *)(v + 0x94) = -1;
        *(f32 *)(v + 0x30) = *(s16 *)(v + 0x34);
        v[0x3E] = 3;
        v[0x38] = v[0x88];
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        idx = *(s32 *)(v + 0x94);
        if (idx == -1 || *(u8 **)((e = D_001FE020 + (idx << 7)) + 0xDC) != m || e[0xD0] == 0) {
            *(s32 *)(v + 0x94) = func_L39_005F33E0(1, 4, m);
        }
        func_L40_00431EA0(m);
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            func_L40_00431C00(m);
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
            func_L39_005F2FF8(m, 1);
            *(s32 *)(v + 0x84) = D_L40_00247A1C;
        }
        if (func_L39_005B4398(4) != 0) {
            break;
        }
        if (*(s32 *)(v + 0x84) > 0) {
            s = *(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
            func_L40_004311A8(m, D_L40_00247A14 * s, D_L40_00247A04 * s, D_L40_00247A08 * s, s, D_L40_00247A10, 0x32, D_L40_00247A18);
            *(s32 *)(v + 0x84) -= 1;
        }
        break;
    }
}
/* localdecomp:end func_L40_00431948 */

/* localdecomp:start func_L40_00431C00 */
extern f32 D_L40_00247A14;
extern u8 D_001FE020[];
extern s32 func_L39_005F33E0(s32 a0, s32 a1, u8 *m);
extern void func_L40_004311A8(u8 *m, f32 f12, f32 f13, f32 f14, f32 f15, s32 a1, s32 a2, s32 a3);
#include "vu0.h"

extern vu0_v4 D_L40_00249F40;
extern u8 D_L40_00242930[] __attribute__((section(".sdata")));
extern s32 D_L40_00247A20;
__asm__(".extern D_L40_00247A20, 4");
__asm__(".extern D_L40_00247A14, 4");
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L39_005F3088(s32);

void func_L40_00431C00(u8 *m) {
    vu0_v4 dir;
    vu0_v4 pos;
    u8 *v = *(u8 **)(m + 0x68);
    f32 s;
    s32 i;
    s32 idx;
    u8 *e;

    vec_sub_ab(&dir, &D_L40_00249F40, m + 0x10);
    func_0038CF68(&dir, &dir, 1.0f);
    func_L01_00451FE0(m, 0xFF, D_L40_00242930, 3.0f, 6.0f, 5.0f, 8.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    s = *(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
    for (i = 0; i < D_L40_00247A20; i++) {
        func_L40_004311A8(m, D_L40_00247A14 + s * 1.5f, s * 1.5f, s, s, 5, 0x32, 2);
    }
    pos.x = *(f32 *)(m + 0x0) * 0.0009765625f;
    pos.y = *(f32 *)(m + 0x4) * 0.0009765625f;
    pos.z = *(f32 *)(m + 0x8) * 0.0009765625f;
    pos.w = 0.0f;
    func_L01_003303B8(&pos, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 2.5f, 0.0f, 0.0f, 2.0f,
                      1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    idx = *(s32 *)(v + 0x94);
    if (idx != -1 && *(u8 **)((e = D_001FE020 + (idx << 7)) + 0xDC) == m && e[0xD0] != 0) {
        func_L39_005F3088(idx);
    }
    *(s32 *)(v + 0x94) = -1;
    func_L39_005F33E0(0, 0, m);
}
/* localdecomp:end func_L40_00431C00 */

/* localdecomp:start func_L40_00431EA0 */
typedef struct {
    u8 pad[0x1C];
    u8 (*f1C)(void *, s32);
} VT_00431EA0;
typedef struct {
    u8 pad[0x14];
    VT_00431EA0 *vt;
} O_00431EA0;
extern u8 *func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, s32);
extern O_00431EA0 *func_L39_0061CEA0(s32);
extern void func_003C4A40(void *, void *);
extern s32 D_L40_002499F4;
__asm__(".extern D_L40_002499F4, 16");

void func_L40_00431EA0(u8 *m) {
    u8 *pv;
    u8 *r;
    u8 *t;
    O_00431EA0 *o;
    u8 doit;

    r = (u8 *)func_L39_0061D7B0(m);
    pv = *(u8 **)(m + 0x68);
    if (r == 0) {
        return;
    }
    if (*(s32 *)(r + 4) == D_L40_002499F4) {
        return;
    }
    t = func_L01_00447490(m, 0x10000, 0);
    func_L01_004474E8(m, (s32)t);
    if (t != 0 && *(s32 *)(t + 0x20) != 0) {
        o = func_L39_0061CEA0(*(s32 *)(t + 0x20));
        doit = 1;
        if (o != 0) {
            doit = o->vt->f1C(o, *(s32 *)(pv + 0x88)) ^ 1;
        }
        if (doit) {
            func_L39_005F33E0(2, 0, m);
            func_003C4A40(m, pv + 0x70);
        }
    }
    m[0xA8] = 0xFF;
}
/* localdecomp:end func_L40_00431EA0 */

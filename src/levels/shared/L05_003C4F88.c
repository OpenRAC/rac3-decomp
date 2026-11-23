#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L05_003C4F88);

/* localdecomp:start func_L05_003C6080 */
extern u8 D_001A30B0[];
extern s32 D_001D545C;
extern s32 func_L05_003C63A8_003C6080(void);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L05_003C66F0_003C6080(u8 *a0);
extern s32 func_L01_00452FB0_003C6080(void *, void *, s32, s32, s32);
extern void func_L05_003C6920_003C6080(void *);
extern void func_L01_00455E18_003C6080(void *, void *, void *);
extern s32 func_L01_00452860_003C6080(void *, void *, s32);
extern void func_L01_00456BD0_003C6080(void *, s32);
extern void func_L01_00456C98_003C6080(void *, s32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, f32);

s32 func_L05_003C6080(u8 *o) {
    u8 *t;
    u8 *e;
    s32 id;

    t = *(u8 **)(o + 0x68);
    if (o[0x20] == 0) {
        if (func_L05_003C63A8_003C6080() != 0) {
            return 1;
        }
    }
    id = *(s32 *)(t + 0x420);
    if (id == -1 || (e = D_001A30B0 + id * 0x80, *(u8 **)(e + 0xDC) != o) || e[0xD0] == 0) {
        *(s32 *)(t + 0x420) = func_003A52A0(3, 4, o);
    }
    if (t[0x3E] == 2) {
        func_L05_003C66F0_003C6080(o);
        return 1;
    }
    if (o[0xBC] != 0) {
        o[0xBC] = o[0xBC] - 1;
    }
    if (o[0x20] == 4 && D_001D545C == 0xB) {
        if (func_L01_00452FB0_003C6080(o, t + 0x160, 0, 0, 1) != 0) {
            if (o[0xBC] == 0) {
                func_003A52A0(4, 0, o);
                o[0xBC] = 0x19;
            }
            *(s16 *)(t + 0x42A) = 1;
            func_L05_003C6920_003C6080(o);
        }
    } else {
        if (func_L01_00452FB0_003C6080(o, t + 0x160, 0, 0, 0) != 0) {
            if (o[0xBC] == 0) {
                func_003A52A0(4, 0, o);
                o[0xBC] = 0x19;
            }
            *(s16 *)(t + 0x42A) = 1;
            func_L05_003C6920_003C6080(o);
        }
    }
    func_L01_00455E18_003C6080(o, t + 0x240, t + 0x30);
    func_L01_00452860_003C6080(o, t + 0x30, 0);
    if (t[0x5E] != 0) {
        func_L05_003C66F0_003C6080(o);
        return 1;
    }
    if (t[0x5F] != 0) {
        func_L01_00456BD0_003C6080(o, 5);
        if (o[0x95] == 0) {
            func_L01_00456C98_003C6080(o, *(s32 *)(t + 0x2E0), *(f32 *)(t + 0x2E4), 10.0f, 0, 0, 0, 0, 3, 0, 0, 0, 1.0f);
        } else {
            func_L01_00456C98_003C6080(o, *(s32 *)(t + 0x2E8), *(f32 *)(t + 0x2EC), 10.0f, 0, 0, 0, 0, 3, 0, 0, 0, 1.0f);
        }
    } else {
        func_L01_00456BD0_003C6080(o, 3);
        if (*(s16 *)(t + 0x42A) != 0) {
            func_L01_00456C98_003C6080(o, -1, 256.0f, 256.0f, 0, 0, 0, 0, 1, 0, 0, 0, 1.0f);
        } else if (o[0x95] == 0) {
            func_L01_00456C98_003C6080(o, *(s32 *)(t + 0x2E0), *(f32 *)(t + 0x2E4), 10.0f, 0, 0, 0, 0, 1, 0, 0, 0, 1.0f);
        } else {
            func_L01_00456C98_003C6080(o, *(s32 *)(t + 0x2E8), *(f32 *)(t + 0x2EC), 10.0f, 0, 0, 0, 0, 1, 0, 0, 0, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L05_003C6080 */

/* localdecomp:start func_L05_003C63A8 */
struct V_3C42B0;
typedef struct {
    u8 pad0[0x68];
    struct V_3C42B0 *v68;
    u8 pad6C[0x10];
    s16 h7C;
} O_3C42B0;
typedef struct V_3C42B0 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x3];
    u8 b39;
    u8 pad3A[0x4];
    u8 b3E;
    u8 b3F;
    f32 f40;
    u8 pad44[0x14];
    u8 b58;
    u8 pad59[0x1];
    u8 b5A;
    u8 pad5B[0x9];
    u8 b64;
    u8 pad65[0xB];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0x18];
    union { f32 f; s32 i; } u9C;
    f32 fA0;
    u8 padA4[0x4];
    s32 wA8;
    u8 padAC[0xC4];
    u8 b170;
    u8 pad171[0x1F];
    f32 f190;
    f32 f194;
    u8 pad198[0x4];
    f32 f19C;
    u8 pad1A0[0x8];
    u8 b1A8;
    u8 pad1A9[0x2E];
    u8 b1D7;
    u8 b1D8;
    u8 b1D9;
    u8 b1DA;
    u8 b1DB;
    u8 pad1DC[0x244];
    s32 w420;
    s32 w424;
    s16 h428;
} V_3C42B0;
extern s32 D_L05_001D673C;
extern s32 D_L05_001DF6C0;
extern s32 D_L05_001D67BC;
extern vu0_v4 D_L05_001EA6E0;
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

s32 func_L05_003C63A8(u8 *o) {
    V_3C42B0 *v = ((O_3C42B0 *)o)->v68;
    vu0_v4 m[4];
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 m2[4];

    ((O_3C42B0 *)o)->h7C = 0x7F;
    if (D_L05_001D673C != 0) {
        *(s16 *)(o + 0x32) = 0xFF;
        *(u16 *)(o + 0x34) |= 0x100;
        func_003C5180(o + 0x10, m, 0);
        func_L01_004515D8(o + 0xC0, &m[0], &m[1]);
        func_0038CF68(&a, o + 0xE0, 0.5f);
        func_0038CF68(&b, o + 0xE0, -4.0f);
        vec_add_ba(&a, &a, o + 0x10);
        vec_add_ba(&b, &b, o + 0x10);
        if (func_003D3CB0(&a, &b, 2, o, 0) != 0) {
            *(vu0_v4 *)(o + 0x10) = D_L05_001EA6E0;
            func_003C5180(o + 0x10, m2, 0);
            func_L01_004515D8(o + 0xC0, &m2[0], &m2[1]);
        }
        v->h428 = 0;
    }
    v->b170 = 0xA;
    v->b1A8 = 3;
    v->b1D7 = 1;
    v->b1DB = 0xFF;
    v->b1D8 = 0;
    v->b1D9 = 0;
    v->b1DA = 0;
    v->f19C = 0.15f;
    v->f70 = 0.7f;
    v->f78 = v->f74 = v->f194 = v->f190 = 0.5f;
    v->f7C = 1.0f;
    v->f80 = 0.7853982f;
    v->fA0 = 0.34906584f;
    v->u9C.f = 0.00392f;
    if (D_L05_001D673C != 0) {
        v->u9C.i = 0;
    }
    v->wA8 |= 4;
    if (D_L05_001D673C == 0) {
        v->wA8 |= 0x14;
    }
    func_L01_0045BD78(o, 0.012f, 0.20000002f, 0.010053097f, 0.25132743f);
    v->b58 = 0x14;
    v->b5A = 0xE;
    if (v->h34 == 0) {
        v->h34 = 0x64;
        v->f30 = 100.0f;
    }
    v->b39 = 1;
    v->b3E = 1;
    v->b3F = 0;
    v->b64 = 0;
    v->w420 = -1;
    v->f40 = 2.0f;
    func_L01_004450F0(o, 1, 0);
    if (o[0x43] != 0) {
        func_003C3A10(o, 0, 0, 0);
    }
    if (v->w424 != 0) {
        *(s32 *)(o + 0x98) = 0;
        *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(o, 1);
    }
    if (v->h428 != 0) {
        v->wA8 |= 4;
        *(u16 *)(o + 0x34) |= 0x100;
        v->f80 = 12.566371f;
        v->wA8 |= 1;
    }
    if (D_L05_001DF6C0 == 0) {
        D_L05_001D67BC = 0;
    }
    return 0;
}
/* localdecomp:end func_L05_003C63A8 */

/* localdecomp:start func_L05_003C66F0 */
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                              f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_00459C50(s32);
extern s32 D_001D545C;
extern s32 D_L05_001D67BC;
extern u8 D_L05_001D66B0[8];

void func_L05_003C66F0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    if (D_001D545C == 0x11 && (pv[0x60] != 0 || pv[0x47] == 0x87)) {
        D_L05_001D67BC = D_L05_001D67BC + 1;
        if (D_L05_001D67BC >= 0x28) {
            func_L01_00459C50(0x13);
        }
    }
    func_L01_004443E8(a0, 0, 3);
    func_L01_00452310(a0, 0x3FFF, D_L05_001D66B0, 1, 0x28, -1.0f, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0);
}
/* localdecomp:end func_L05_003C66F0 */

/* localdecomp:start func_L05_003C67C0 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern u8 D_L05_001E2700[];

void func_L05_003C67C0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    f32 a;
    f32 b;
    func_0038CAD0(v + 0x2F0);
    func_0038CB00(v + 0x2F4);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        (*(u16 *)(a0 + 0x96))++;
    }
    func_L01_00451DF8(a0, v + 0x260, 4, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L05_001E2700, a0 + 0x10) < 1024.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x1E;
        }
    }
    a = 0.0432000011f;
    *(f32 *)(v + 0x42C) = func_0038DAB8(*(f32 *)(v + 0x42C), 0.069813177f);
    b = 0.432000041f;
    *(s32 *)(a0 + 0x78) = func_0038DBD8(0x80A0A0A0, 0x60101010, (func_0038D0B0(*(f32 *)(v + 0x42C)) + 1.0f) * 0.5f);
    func_L01_0044E850(a0, v + 0x300, 0, a, b);
    func_L01_0044E850(a0, v + 0x380, 1, a, b);
}
/* localdecomp:end func_L05_003C67C0 */

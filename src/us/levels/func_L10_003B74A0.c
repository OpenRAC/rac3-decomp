#include "common.h"

/* NTSC-U counterpart of func_L10_003B9570 (src/levels/10_zeldrin_starport/L10_003B9570.c) */
#include "vu0.h"

/* localdecomp:start func_L10_003B74A0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9570;

typedef struct {
    s32 id;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 e;
    f32 f;
    f32 g;
} Out_3B9570;

extern s32 D_L10_001D673C_003B74A0;
__asm__(".extern D_L10_001D673C_003B74A0, 4");

extern s32 func_003C0B10(void *, s32, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void func_L10_003B6FC0(void *, s32, s32, s32);
extern void func_003BF4F8(void *, void *);
extern f32 func_003BFB80(void *, void *, s32);
extern void func_003BFC18(void *, void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_00388880(void *, void *, f32);
extern void func_003BF910(void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern f32 func_003887A0(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003C0E10(void *, void *, void *, f32, f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);

s32 func_L10_003B74A0(u8 *m, u8 *hit, u8 *vec, s32 type) {
    V4_3B9570 buf[4];
    Out_3B9570 o;
    s32 ok;
    f32 f20;
    f32 f21;

    o.c = *(f32 *)(hit + 0x24);
    o.d = *(f32 *)(hit + 0x28);
    o.a = *(f32 *)(hit + 0x1C);
    o.b = *(f32 *)(hit + 0x20);
    ok = 1;
    o.g = *(f32 *)(hit + 0x2C);
    switch (type) {
    default:
    case 1:
        hit[7] = 0xFF;
        break;
    case 2:
        hit[7] = 0xFF;
        if (m[0x95] != 5) {
            if (func_003C0B10(m, 0, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
                func_L10_003B6FC0(m, o.id, 3, 3);
            } else if (func_003C0B10(m, 1, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
            } else if (hit[0x11] != 0xFF) {
                o.a = o.a * 0.5f;
                o.b = o.b * 0.5f;
                o.e = (f32) * (s8 *)(hit + 0x6C);
                o.f = (f32) * (s8 *)(hit + 0x6D);
                func_L10_003B6FC0(m, hit[0x11], 3, 3);
            } else {
                ok = 0;
            }
        } else {
            ok = 0;
        }
        break;
    case 3:
        hit[7] = 0xFF;
        if (m[0x95] != 5) {
            if (func_003C0B10(m, 1, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
                func_L10_003B6FC0(m, o.id, 0, 3);
            } else if (func_003C0B10(m, 0, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
                func_L10_003B6FC0(m, o.id, 3, 3);
            } else if (hit[0x12] != 0xFF) {
                o.a = o.a * 0.75f;
                o.b = o.b * 0.75f;
                o.e = (f32) * (s8 *)(hit + 0x6E);
                o.f = (f32) * (s8 *)(hit + 0x6F);
                func_L10_003B6FC0(m, hit[0x12], 3, 3);
            } else {
                ok = 0;
            }
        } else {
            ok = 0;
        }
        break;
    case 6:
        hit[7] = 0xFF;
        if (m[0x95] != 5 && func_003C0B10(m, 5, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
            func_L10_003B6FC0(m, o.id, 0, 3);
        } else {
            ok = 0;
        }
        break;
    case 4:
        *(u16 *)(hit + 0x38) |= 1;
        hit[7] = 0xFF;
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) &= 0xEFFF;
        if (m[0x95] != 5) {
            if (func_003C0B10(m, 3, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
                func_L10_003B6FC0(m, o.id, 3, 3);
            } else if (hit[0x16] != 0xFF) {
                o.e = (f32) * (s8 *)(hit + 0x72);
                o.f = (f32) * (s8 *)(hit + 0x73);
                func_L10_003B6FC0(m, hit[0x16], 3, 3);
            } else {
                ok = 0;
            }
        } else {
            ok = 0;
        }
        break;
    case 5:
        *(u16 *)(hit + 0x38) |= 2;
        hit[7] = 0xFF;
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) &= 0xEFFF;
        if (m[0x95] != 5) {
            if (func_003C0B10(m, 4, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
                func_L10_003B6FC0(m, o.id, 0, 3);
            } else if (hit[0x17] != 0xFF) {
                o.a = o.a * 1.5f;
                o.b = o.b * 1.5f;
                o.e = (f32) * (s8 *)(hit + 0x72);
                o.f = (f32) * (s8 *)(hit + 0x73);
                func_L10_003B6FC0(m, hit[0x17], 0, 3);
            } else {
                ok = 0;
            }
        } else {
            ok = 0;
        }
        *(f32 *)(hit + 0x90) = 0.104719765f;
        *(f32 *)(hit + 0x94) = 0.41887906f;
        break;
    }
    func_003BF4F8(m, hit);
    if (type != 1 && ok != 0) {
    if (D_L10_001D673C_003B74A0 != 0) {
        f21 = 1.0f;
        f20 = func_003BFB80(m, vec, 0);
        if (f20 < f21) {
            f20 = f21;
        }
        func_003BFC18(m + 0x10, &buf[1], 0);
        func_00388830(&buf[3], vec, -1.0f);
        func_003BF910(&buf[3], hit + 0x64);
        {
            f32 d = func_00388730(&buf[1], vec);
            func_00388830(&buf[2], &buf[1], d);
        }
        vec_sub_ab(vec, vec, &buf[2]);
        if (func_00388770(vec) < f21) {
            func_00388830(vec, vec, f21);
        }
        func_003886E8(hit + 0x80, vec, o.a);
        func_00388830(&buf[2], &buf[1], -o.b * f20);
        vec_add_ab(hit + 0x80, hit + 0x80, &buf[2]);
    } else {
        func_003C0E10(m, vec, vec, 5.0f, 0.7853982f, 4.0f);
        f20 = 1.0f;
        if (func_003887A0(vec) < f20) {
            func_00388880(vec, vec, f20);
        }
        if (*(f32 *)(vec + 8) < f20) {
            *(f32 *)(vec + 8) = f20;
        }
        *(f32 *)(hit + 0x80) = *(f32 *)vec * o.a;
        *(f32 *)(hit + 0x84) = *(f32 *)(vec + 4) * o.a;
        *(f32 *)(hit + 0x88) = *(f32 *)(vec + 8) * o.b;
        *(f32 *)(hit + 0x64) = func_00389380(func_00388A28(*(f32 *)vec, *(f32 *)(vec + 4)), 3.14159f);
    }
    if (hit[0x76] != 0 && type < 4) {
        *(f32 *)(hit + 0x4C) = 0.0f;
        *(f32 *)(hit + 0x50) = 0.0f;
        *(f32 *)(hit + 0x54) = -1.0f;
        *(f32 *)(hit + 0x60) = -1.0f;
    } else {
        *(f32 *)(hit + 0x54) = o.e;
        *(f32 *)(hit + 0x60) = o.f;
        *(f32 *)(hit + 0x4C) = o.c;
        *(f32 *)(hit + 0x50) = o.d;
        *(f32 *)(hit + 0x2C) = o.g;
    }
    return 1;
    }
    return 0;
}

/* localdecomp:end func_L10_003B74A0 */

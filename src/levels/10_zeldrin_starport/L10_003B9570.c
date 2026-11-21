#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L10_003B9570 */
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

extern s32 D_001D673C;
__asm__(".extern D_001D673C, 4");

extern s32 func_003C6068(void *, s32, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void func_L10_003B9078(void *, s32, s32, s32);
extern void func_003C4A40(void *, void *);
extern f32 func_003C50E8(void *, void *, s32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CFB8(void *, void *, f32);
extern void func_003C4E80(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CED8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C6368(void *, void *, void *, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);

s32 func_L10_003B9570(u8 *m, u8 *hit, u8 *vec, s32 type) {
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
            if (func_003C6068(m, 0, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
                func_L10_003B9078(m, o.id, 3, 2);
            } else if (func_003C6068(m, 1, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
            } else if (hit[0x11] != 0xFF) {
                o.a = o.a * 0.5f;
                o.b = o.b * 0.5f;
                o.e = (f32) * (s8 *)(hit + 0x6C);
                o.f = (f32) * (s8 *)(hit + 0x6D);
                func_L10_003B9078(m, hit[0x11], 3, 2);
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
            if (func_003C6068(m, 1, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
                func_L10_003B9078(m, o.id, 0, 2);
            } else if (func_003C6068(m, 0, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
                func_L10_003B9078(m, o.id, 3, 2);
            } else if (hit[0x12] != 0xFF) {
                o.a = o.a * 0.75f;
                o.b = o.b * 0.75f;
                o.e = (f32) * (s8 *)(hit + 0x6E);
                o.f = (f32) * (s8 *)(hit + 0x6F);
                func_L10_003B9078(m, hit[0x12], 3, 2);
            } else {
                ok = 0;
            }
        } else {
            ok = 0;
        }
        break;
    case 6:
        hit[7] = 0xFF;
        if (m[0x95] != 5 && func_003C6068(m, 5, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
            func_L10_003B9078(m, o.id, 0, 2);
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
            if (func_003C6068(m, 3, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
                func_L10_003B9078(m, o.id, 3, 2);
            } else if (hit[0x16] != 0xFF) {
                o.e = (f32) * (s8 *)(hit + 0x72);
                o.f = (f32) * (s8 *)(hit + 0x73);
                func_L10_003B9078(m, hit[0x16], 3, 2);
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
            if (func_003C6068(m, 4, &o.id, &o.a, &o.b, &o.c, &o.d, &o.e, &o.f, &o.g, &buf[0]) != 0) {
                func_L10_003B9078(m, o.id, 0, 2);
            } else if (hit[0x17] != 0xFF) {
                o.a = o.a * 1.5f;
                o.b = o.b * 1.5f;
                o.e = (f32) * (s8 *)(hit + 0x72);
                o.f = (f32) * (s8 *)(hit + 0x73);
                func_L10_003B9078(m, hit[0x17], 0, 2);
            } else {
                ok = 0;
            }
        } else {
            ok = 0;
        }
        *(f32 *)(hit + 0x90) = 0.12566371f;
        *(f32 *)(hit + 0x94) = 0.50265485f;
        break;
    }
    func_003C4A40(m, hit);
    if (type != 1 && ok != 0) {
    if (D_001D673C != 0) {
        f21 = 1.0f;
        f20 = func_003C50E8(m, vec, 0);
        if (f20 < f21) {
            f20 = f21;
        }
        func_003C5180(m + 0x10, &buf[1], 0);
        func_0038CF68(&buf[3], vec, -1.0f);
        func_003C4E80(&buf[3], hit + 0x64);
        {
            f32 d = func_0038CE68(&buf[1], vec);
            func_0038CF68(&buf[2], &buf[1], d);
        }
        vec_sub_ab(vec, vec, &buf[2]);
        if (func_0038CEA8(vec) < f21) {
            func_0038CF68(vec, vec, f21);
        }
        func_0038CE20(hit + 0x80, vec, o.a);
        func_0038CF68(&buf[2], &buf[1], -o.b * f20);
        vec_add_ab(hit + 0x80, hit + 0x80, &buf[2]);
    } else {
        func_003C6368(m, vec, vec, 5.0f, 0.7853982f, 4.0f);
        f20 = 1.0f;
        if (func_0038CED8(vec) < f20) {
            func_0038CFB8(vec, vec, f20);
        }
        if (*(f32 *)(vec + 8) < f20) {
            *(f32 *)(vec + 8) = f20;
        }
        *(f32 *)(hit + 0x80) = *(f32 *)vec * o.a;
        *(f32 *)(hit + 0x84) = *(f32 *)(vec + 4) * o.a;
        *(f32 *)(hit + 0x88) = *(f32 *)(vec + 8) * o.b;
        *(f32 *)(hit + 0x64) = func_0038DAB8(func_0038D160(*(f32 *)vec, *(f32 *)(vec + 4)), 3.14159f);
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

/* localdecomp:end func_L10_003B9570 */

/* localdecomp:start func_L10_003B9D28 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9D28;
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 D_L10_001E8918[];

s32 func_L10_003B9D28(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x68);
    V4_3B9D28 a;
    V4_3B9D28 b;
    s32 t;
    s32 r;

    func_003C2F58(*(void **)(s1 + 0x2DC), 0, &a);
    b = *(V4_3B9D28 *)(s1 + 0x220);
    if (func_003D3CB0(&a, &b, 0x10, a0, 0) == 0) {
        return 1;
    }
    t = D_L10_001E8918[0];
    if (t != 0 && t == *(s32 *)(s1 + 0x230)) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L10_003B9D28 */

/* localdecomp:start func_L10_003B9DB0 */
typedef int u128_t_3B9DB0 __attribute__((mode(TI)));
typedef struct P_3B9DB0 {
    u8 pad0[0x10];
    f32 f10;
    s16 f14;
} P_3B9DB0;
typedef struct S_3B9DB0 {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x3];
    u8 *f24;
    u8 pad2[0x4];
    f32 f2C;
    u8 pad3[0x1];
    u8 f31;
    u8 pad4[0x2];
    u16 f34;
    u8 pad5[0xC];
    u8 f42;
    u8 f43;
    u8 pad6[0x1C];
    u8 f60;
    u8 pad7[0x7];
    P_3B9DB0 *f68;
    u8 pad8[0x8C];
    f32 fF8;
} S_3B9DB0;
typedef struct T_3B9DB0 { s16 f0; s16 f2; s32 f4; } T_3B9DB0;
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001CCFD0[];
extern u8 D_00142CBA[];
extern T_3B9DB0 D_L10_001DF034;
extern f32 D_L10_001DE780;
extern s32 D_L10_001DEC5C;
__asm__(".extern D_L10_001DE780, 4");
__asm__(".extern D_L10_001DF034, 16");

void func_L04_003E3618(void *);
void func_L05_003DD790(void *);
void func_L04_003E3978(void *);
s32 func_003A1798(void);
void func_L01_00419188(s32);
void func_L01_004F50C8(void *, void *, s32, s32);
void func_L01_003EB5E0(s32, s32);
s32 func_0039EC28(s32, s32);
void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
void func_L01_00451F60(s32, s32, s32);
void func_003C2880(void *);
void func_L01_0050FB40(s32, s32, f32);
s32 func_L01_004561B8(void *);
s32 func_0038CB00(void *);
s32 func_L01_0041A5B0(s32, s32);
f32 func_0038DAB8(f32, f32);
f32 func_L01_0040E570(void *, void *);

void func_L10_003B9DB0(void *m) {
    S_3B9DB0 *s = m;
    P_3B9DB0 *p;
    u8 *c;
    u8 *g;

    p = s->f68;
    if (s->f20 == 0) {
        if (D_00142CBA[0] != 0) {
            func_003C2880(s);
            return;
        }
        s->f2C = *(f32 *)(s->f24 + 0x24) * D_L10_001DE780;
        *(u128_t_3B9DB0 *)p = *(u128_t_3B9DB0 *)((u8 *)s + 0x10);
        p->f10 = s->fF8;
        func_L01_004450F0(s, 1, -1);
    }

    switch (s->f20) {
    case 1:
        s->fF8 = func_0038DAB8(s->fF8, 0.090757132f);
        func_L04_003E3618(s);
        if (func_L01_0040E570(D_001A4C60, (u8 *)s + 0x10) < 25.0f) {
            func_L05_003DD790(s);
        }
        break;
    case 2:
        c = D_001CCFD0;
        if (*(s16 *)(c + 0x76) == 0) {
            if (*(s16 *)(c + 0x9E) == 3 && *(s16 *)(c + 0x98) < 0x1B58) {
                if (func_L01_004561B8(s)) {
                    func_003A1798();
                }
            }
        }
        g = D_001A4BE0;
        *(s16 *)(g + 0x1DC) = 3;
        D_L10_001DF034.f4 = 1;
        func_L04_003E3978(s);
        *(u128_t_3B9DB0 *)((u8 *)s + 0x10) = *(u128_t_3B9DB0 *)(g + 0x80);
        *(u128_t_3B9DB0 *)((u8 *)s + 0xF0) = *(u128_t_3B9DB0 *)(g + 0x90);
        if (*(u32 *)(g + 0xC08) & 2) {
            func_L01_0050FB40(0, 0, 25.0f);
        }
        if (s->f42 == 1 && (s->f60 & 2)) {
            if (s->f43 != 0) {
                func_003C3A10((u8 *)s, 0, 0, 0);
            }
            s->f31 = 0;
            s->f34 = s->f34 | 1;
            func_L01_004450F0(s, 5, -1);
        }
        break;
    case 5:
        if (func_0038CB00((u8 *)p + 0x14) != 0) {
            func_L01_00419188(0x1A);
            func_L01_00419188(7);
            D_L10_001DEC5C = 0;
            func_L01_004F50C8(D_001A4C60, D_001A4C60 + 0x10, 0, 0);
            func_L01_003EB5E0(0, 0);
            func_0039EC28(0, -1);
            p->f14 = 0x32;
            func_L01_004450F0(s, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(s)) {
            func_L01_00451F60(0x1B82, 0x64, 0);
        }
        if (func_0038CB00((u8 *)p + 0x14) != 0 && func_L01_0041A5B0(0x1426, 0x114) != 0) {
            func_003C2880(s);
        }
        break;
    }
}
/* localdecomp:end func_L10_003B9DB0 */

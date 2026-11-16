#include "common.h"

/* NTSC-U counterpart of func_L24_0034DAB8 (src/levels/24_insomniac_museum/L24_0034DAB8.c) */
/* localdecomp:start func_L24_0034CC68 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0034DAB8;
typedef struct {
    V4_0034DAB8 v;
    u8 pad[0x18 - 0x10];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad2[0x30 - 0x1C];
} Hit_0034DAB8;
typedef struct {
    V4_0034DAB8 off;
    s32 i10;
    f32 f14;
    u8 pad18[0x24 - 0x18];
    s32 timer;
    u8 pad28[4];
    s32 i2C;
} Vars_0034DAB8;
typedef struct { u8 pad[0x18]; s32 f18; s32 f1C; u8 f20[1]; } Flags_0034DAB8;

extern Flags_0034DAB8 D_L24_001E8F40_0034CC68;
extern void func_L01_00443648(void *, f32, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00454348(void *, void *, f32, f32, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003CF790(void *, s32, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern s32 func_L01_00440E98(void *, s32 *);
extern void func_L01_0030EF98(void *, s32, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_00447D00(void *, void *, s32, f32, f32, f32, s32, s32, s32, f32, s32, s32, f32, f32, f32, s32, s32, s32, s32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern s32 func_003894A0(s32, s32, f32);

void func_L24_0034CC68(u8 *a0) {
    Vars_0034DAB8 *v = *(Vars_0034DAB8 **)(a0 + 0x68);
    V4_0034DAB8 p;
    union {
        Hit_0034DAB8 h;
        struct { V4_0034DAB8 d, b; } s;
    } u;
    V4_0034DAB8 d;
    Hit_0034DAB8 h2;
    s32 n;
    s32 i;
    s32 j;
    s16 type;
    f32 fa, fb, fc, fd;
    s32 cnt;
    s32 hits;

    v->timer++;
    if (v->timer > 0xF0) {
        func_L01_00443648(a0, 0.6f, a0 + 0x10, v->i2C, v->f14, 0.0f, 0, 1, 0);
        func_L01_00441FB8(a0, 1, -1);
    }

    switch (a0[0x20]) {
    case 0:
        p.x = 0.0f;
        p.y = 0.0f;
        p.z = 0.5f;
        func_L01_00454348(a0, &p, 0.1454441100358963f, 0.1745329350233078f, 0.20943953096866608f);
        vec_add_ba(&p, a0 + 0x10, &v->off);
        v->off.z -= v->off.w;
        func_L01_00443628(&u.h, a0, v->i2C, v, v->f14);
        u.h.h1A = *(u16 *)(a0 + 0xAA);
        if (func_003CE740(a0 + 0x10, &p, 0, a0, &u.h) != 0 ||
            func_L01_003F9498(a0 + 0x10, 0, a0, 0.4f) != 0) {
            if (D_L24_001E8F40_0034CC68.f18 != 0) {
                if (D_L24_001E8F40_0034CC68.f18 == v->i10) {
                    goto fail;
                }
                *(vu0_q *)&d = *(vu0_q *)&v->off;
                func_003886E8(&d, &d, 2.0f);
                d.w = 5627.9248f;
                func_L01_00443628(&h2, a0, v->i2C, &d, v->f14);
                h2.b18 = 0;
                h2.b19 = 1;
                h2.h1A = *(u16 *)(a0 + 0xAA);
                func_003CF790(D_L24_001E8F40_0034CC68.f20, 0, a0, &h2, 0.4f);
                func_L01_00441FB8(a0, 1, -1);
                return;
            } else {
                *(vu0_q *)&d = *(vu0_q *)&v->off;
                func_003886E8(&d, &d, 3.0f);
                d.w = 5627.9248f;
                func_L01_00443628(&h2, a0, v->i2C, &d, v->f14);
                h2.b18 = 0;
                h2.b19 = 1;
                h2.h1A = *(u16 *)(a0 + 0xAA);
                func_003CF790(D_L24_001E8F40_0034CC68.f20, 0, a0, &h2, 0.6f);
                func_L01_00441FB8(a0, 1, -1);
                return;
            }
        }
fail:
        *(vu0_q *)(a0 + 0x10) = *(vu0_q *)&p;
        break;
    case 1:
        type = *(s16 *)(a0 + 0xAA);
        if (type == 0x1F4 || type == 0x15AF) {
            func_00388830(&p, v, -0.1666666716337204f);
            fa = 3.0f;
            fb = 6.0f;
            fc = -1.0f;
            fd = 1.0f;
            func_L01_0044EBF8(a0, func_0037E1D8(3), 0.0f);
            cnt = 3;
            func_L01_0044ED60(a0, 0x25, &p, fa, fb, fa, fb, 0xFF, fc, fc, 0xB4, 0, 0, 0x23, fd, fd, 0, cnt);
            func_00388830(&p, v, 0.1666666716337204f);
            func_L01_0044ED60(a0, 0x25, &p, fa, fb, fa, fb, 0xFF, fc, fc, 0xB4, 0, 0, 0x23, fd, fd, 0, cnt);
            func_0039FE80(0, 0, a0);
        } else if (type == 0x1FF) {
            func_00388830(&p, v, -0.1666666716337204f);
            func_L01_00440E98(a0, &n);
            hits = func_L01_00440E98(a0, &n);
            for (i = 0; i < hits; i++) {
                func_L01_0030EF98(a0 + 0x10, n, -1, 0);
            }
            fa = 3.0f;
            fb = 6.0f;
            fc = -1.0f;
            fd = 1.0f;
            cnt = 3;
            func_L01_0044ED60(a0, 0x25, &p, fa, fb, fa, fb, 0xFF, fc, fc, 0xB4, 0, 0, 0x23, fd, fd, 0, cnt);
            func_00388830(&p, v, 0.1666666716337204f);
            func_L01_0044ED60(a0, 0x25, &p, fa, fb, fa, fb, 0xFF, fc, fc, 0xB4, 0, 0, 0x23, fd, fd, 0, cnt);
            func_0039FE80(0, 0, a0);
        } else {
            func_L01_00447D00(a0, v, 0, 0.0f, 0.0f, 2.0f, 4, 0, 0, 1.0f, -1, 0, 9.0f, 1.0f, 0.0f, 0, -1, 1, 0x1010001);
            for (i = 0; i < 20; i++) {
                f32 ang, r, z;
                V4_0034DAB8 *pp = &p;
                *(vu0_q *)pp = *(vu0_q *)(a0 + 0x10);
                func_003BF6A8(pp, 0.25f);
                p.z += 0.25f;
                ang = func_0037E2A8();
                r = func_0037E250(1.0f, 8.0f);
                z = func_0037E250(2.0f, 6.0f);
                r *= 0.01666666753590107f;
                func_003886E8(&u.s.d, v, func_0037E250(0.0f, 0.0f) * 0.01666666753590107f);
                u.s.d.x += func_00388960(ang) * r;
                u.s.d.y += func_00388978(ang) * r;
                u.s.d.z += z * 0.01666666753590107f;
                u.s.b = u.s.d;
                u.s.b.z -= 0.1666666716337204f;
                for (j = 0; j < 10; j++) {
                    f32 s;
                    s32 c1, c2;
                    s = func_0037E250(0.5f, 1.5f);
                    u.s.d.w = s * 0.125f;
                    u.s.b.w = s * 0.0649999976f;
                    func_003BF6A8(&p, 0.125f);
                    func_003BF6A8(&u.s.b, 0.008333333767950535f);
                    c1 = func_003894A0(0x8000EEEE, 0x8000FF90, func_0037E250(0.0f, 1.0f));
                    c2 = func_003894A0(0xFFEE, 0xFFEE, func_0037E250(0.0f, 1.0f));
                    func_L01_0045FEC8(&p, &u.s.d, &u.s.b, c1, c2, 10, 30,
                                      (s32)func_0037E250(5.0f, 25.0f), -1);
                }
            }
        }
        func_003BD360(a0);
        break;
    }
}
/* localdecomp:end func_L24_0034CC68 */

#include "common.h"

/* localdecomp:start func_L24_0034DAB8 */
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

extern Flags_0034DAB8 D_L24_001E8F40;
extern void func_L01_00446780(void *, f32, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00457638(void *, void *, f32, f32, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern void func_L01_00451E78(void *, s32, f32);
extern s32 func_L01_00443FB0(void *, s32 *);
extern void func_L01_0030F288(void *, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, f32, s32, s32, s32, f32, s32, s32, f32, f32, f32, s32, s32, s32, s32);
extern void func_003C4C18(void *, f32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L24_0034DAB8(u8 *a0) {
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
        func_L01_00446780(a0, 0.6f, a0 + 0x10, v->i2C, v->f14, 0.0f, 0, 1, 0);
        func_L01_004450F0(a0, 1, -1);
    }

    switch (a0[0x20]) {
    case 0:
        p.x = 0.0f;
        p.y = 0.0f;
        p.z = 0.5f;
        func_L01_00457638(a0, &p, 0.174532935f, 0.209439516f, 0.251327425f);
        vec_add_ba(&p, a0 + 0x10, &v->off);
        v->off.z -= v->off.w;
        func_L01_00446760(&u.h, a0, v->i2C, v, v->f14);
        u.h.h1A = *(u16 *)(a0 + 0xAA);
        if (func_003D3CB0(a0 + 0x10, &p, 0, a0, &u.h) != 0 ||
            func_L01_003FB640(a0 + 0x10, 0, a0, 0.4f) != 0) {
            if (D_L24_001E8F40.f18 != 0) {
                if (D_L24_001E8F40.f18 == v->i10) {
                    goto fail;
                }
                *(vu0_q *)&d = *(vu0_q *)&v->off;
                func_0038CE20(&d, &d, 2.0f);
                d.w = 5627.9248f;
                func_L01_00446760(&h2, a0, v->i2C, &d, v->f14);
                h2.b18 = 0;
                h2.b19 = 1;
                h2.h1A = *(u16 *)(a0 + 0xAA);
                func_003D4D00(D_L24_001E8F40.f20, 0, a0, &h2, 0.4f);
                func_L01_004450F0(a0, 1, -1);
                return;
            } else {
                *(vu0_q *)&d = *(vu0_q *)&v->off;
                func_0038CE20(&d, &d, 3.0f);
                d.w = 5627.9248f;
                func_L01_00446760(&h2, a0, v->i2C, &d, v->f14);
                h2.b18 = 0;
                h2.b19 = 1;
                h2.h1A = *(u16 *)(a0 + 0xAA);
                func_003D4D00(D_L24_001E8F40.f20, 0, a0, &h2, 0.6f);
                func_L01_004450F0(a0, 1, -1);
                return;
            }
        }
fail:
        *(vu0_q *)(a0 + 0x10) = *(vu0_q *)&p;
        break;
    case 1:
        type = *(s16 *)(a0 + 0xAA);
        if (type == 0x1F4 || type == 0x15AF) {
            func_0038CF68(&p, v, -0.200000018f);
            fa = 3.0f;
            fb = 6.0f;
            fc = -1.0f;
            fd = 1.0f;
            func_L01_00451E78(a0, func_00382468(3), 0.0f);
            cnt = 3;
            func_L01_00451FE0(a0, 0x25, &p, fa, fb, fa, fb, 0xFF, fc, fc, 0xB4, 0, 0, 0x23, fd, fd, 0, cnt);
            func_0038CF68(&p, v, 0.200000018f);
            func_L01_00451FE0(a0, 0x25, &p, fa, fb, fa, fb, 0xFF, fc, fc, 0xB4, 0, 0, 0x23, fd, fd, 0, cnt);
            func_003A52A0(0, 0, a0);
        } else if (type == 0x1FF) {
            func_0038CF68(&p, v, -0.200000018f);
            func_L01_00443FB0(a0, &n);
            hits = func_L01_00443FB0(a0, &n);
            for (i = 0; i < hits; i++) {
                func_L01_0030F288(a0 + 0x10, n, -1, 0);
            }
            fa = 3.0f;
            fb = 6.0f;
            fc = -1.0f;
            fd = 1.0f;
            cnt = 3;
            func_L01_00451FE0(a0, 0x25, &p, fa, fb, fa, fb, 0xFF, fc, fc, 0xB4, 0, 0, 0x23, fd, fd, 0, cnt);
            func_0038CF68(&p, v, 0.200000018f);
            func_L01_00451FE0(a0, 0x25, &p, fa, fb, fa, fb, 0xFF, fc, fc, 0xB4, 0, 0, 0x23, fd, fd, 0, cnt);
            func_003A52A0(0, 0, a0);
        } else {
            func_L01_0044AF78(a0, v, 0, 0.0f, 0.0f, 2.0f, 4, 0, 0, 1.0f, -1, 0, 9.0f, 1.0f, 0.0f, 0, -1, 1, 0x1010001);
            for (i = 0; i < 20; i++) {
                f32 ang, r, z;
                V4_0034DAB8 *pp = &p;
                *(vu0_q *)pp = *(vu0_q *)(a0 + 0x10);
                func_003C4C18(pp, 0.25f);
                p.z += 0.25f;
                ang = func_00382538();
                r = func_003824E0(1.0f, 8.0f);
                z = func_003824E0(2.0f, 6.0f);
                r *= 0.0200000014f;
                func_0038CE20(&u.s.d, v, func_003824E0(0.0f, 0.0f) * 0.0200000014f);
                u.s.d.x += func_0038D098(ang) * r;
                u.s.d.y += func_0038D0B0(ang) * r;
                u.s.d.z += z * 0.0200000014f;
                u.s.b = u.s.d;
                u.s.b.z -= 0.2f;
                for (j = 0; j < 10; j++) {
                    f32 s;
                    s32 c1, c2;
                    s = func_003824E0(0.5f, 1.5f);
                    u.s.d.w = s * 0.125f;
                    u.s.b.w = s * 0.0649999976f;
                    func_003C4C18(&p, 0.125f);
                    func_003C4C18(&u.s.b, 0.0100000007f);
                    c1 = func_0038DBD8(0x8000EEEE, 0x8000FF90, func_003824E0(0.0f, 1.0f));
                    c2 = func_0038DBD8(0xFFEE, 0xFFEE, func_003824E0(0.0f, 1.0f));
                    func_L01_00463378(&p, &u.s.d, &u.s.b, c1, c2, 8, 0x19,
                                      (s32)((func_003824E0(5.0f, 25.0f) * 5.0f + 2.0f) / 6.0f), -1);
                }
            }
        }
        func_003C2880(a0);
        break;
    }
}
/* localdecomp:end func_L24_0034DAB8 */

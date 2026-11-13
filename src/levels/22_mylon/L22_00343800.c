#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L22_00343800 */
extern vu0_v4 D_L22_001E2A80;
extern u8 D_L22_001D66B0[8];
extern u8 *D_L22_0021FFAC[];
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_00382468(s32);

void func_L22_00343800(vu0_v4 *pos, s32 a1, s32 big) {
    vu0_v4 d;
    vu0_v4 vel;
    vu0_v4 at;
    vu0_v4 pt;
    f32 heading;
    f32 speed;
    f32 size;
    f32 tilt;
    f32 yaw;
    s32 n;
    s32 i;
    u8 *q;
    u8 *data;

    vec_sub_ab(&d, &D_L22_001E2A80, pos);
    heading = func_0038D160(d.x, d.y);
    for (i = 0; i < 20; i++) {
        speed = func_003824E0(0.2f, 3.0f);
        func_003C5180(pos, &at, 1);
        func_0038CE20(&vel, &at, -(speed * 0.020000001f));
        n = func_L01_00443A18(1.0f, 2.0f);
        size = func_003824E0(0.3f, 0.75f) * 210000.0f;
        pt.x = pos->x + func_L01_00443A18(0.0f, 0.2f);
        pt.y = pos->y + func_L01_00443A18(0.0f, 0.2f);
        pt.z = pos->z + func_L01_00443A18(0.0f, 0.2f);
        q = func_L01_004669B0(&pt, 0.0f, 1.0f, 1.01f, size, n, &vel, 0x7F202020, 1);
        if (q != 0) {
            q[3] = 0x44;
            *(s16 *)(q + 0xA) = 0x4B;
            q[9] = 0x44;
            data = q + 0x20;
            *(f32 *)(data + 0x1C) = 4.0f;
            *(s32 *)(data + 4) = 3;
            data[0xA] = 0x30;
            data[0xB] = q[0xA];
        }
        speed = func_003824E0(1.0f, 2.0f);
        tilt = func_003824E0(0.0f, 1.3962634f);
        yaw = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962634f));
        func_00382760(&vel, speed * 0.020000001f, yaw, tilt);
        pt.x = pos->x + func_L01_00443A18(0.0f, 0.1f);
        pt.y = pos->y + func_L01_00443A18(0.0f, 0.1f);
        pt.z = pos->z + func_L01_00443A18(0.0f, 0.1f);
        func_L01_0046A610(&pt, &vel, 0x19, 0x7F, 0x7F7F7F, n, func_003824E0(0.1f, 0.5f) * 210000.0f, 500.0f, 1.0f, 0.0f, 1.0f);
    }
    if (big == 1) {
        n = func_00382468(0xFF);
        q = func_L01_0046A610(pos, D_L22_001D66B0, 4, 0x7F, 0x207080, n, 525000.0f, 0.0f, 1.0f, 0.0f, 1.0f);
        if (q != 0) {
            q[2] = *D_L22_0021FFAC[0];
        }
        q = func_L01_0046A610(pos, D_L22_001D66B0, 4, 0x7F, 0x207080, (n + 0x80) & 0xFF, 525000.0f, 0.0f, 1.0f, 0.0f, 1.0f);
        if (q != 0) {
            q[2] = *D_L22_0021FFAC[0];
        }
    }
}
/* localdecomp:end func_L22_00343800 */

/* localdecomp:start func_L22_00343C18 */
typedef struct {
    vu0_v4 vel;
    u16 x10;
    s16 x12;
    void *x14;
    s32 x18;
    s32 x1C;
    f32 x20;
    u8 *x24;
    f32 x28;
} S_343C18v;

extern u8 D_L22_001D66B0[8];
extern u8 *D_L22_001E9858[];
extern vu0_v4 D_L22_001E9860[];
extern void func_L22_00343800(vu0_v4 *, s32, s32);
extern u8 *func_00382348(s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern f32 func_0038DB48(f32);
extern void func_003C4098(void *, void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_00443B88(void *, f32, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_003C2880(void *);

void func_L22_00343C18(u8 *p) {
    vu0_v4 np;
    vu0_v4 v10;
    vu0_v4 dir;
    u8 info[0x30];
    vu0_v4 v60;
    S_343C18v *st;
    u8 *t;
    u8 *h;
    void *o;
    u8 *r;
    f32 a;
    f32 k;
    f32 sz;
    s32 hit;
    s32 n;
    s32 i;

    st = *(S_343C18v **)(p + 0x68);
    switch (p[0x20]) {
    case 0:
        *(u16 *)(p + 0x96) += 1;
        t = st->x24;
        if (t != 0) {
            r = func_00382348((s32)t);
            if (t[0x20] == 0xFE) {
                st->x24 = 0;
            } else if (t[0x20] == 0xFD) {
                st->x24 = 0;
            } else if (r != 0 && *(f32 *)r <= 0.0f) {
                st->x24 = 0;
            } else if (*(u16 *)(p + 0x96) >= 5) {
                dir = *(vu0_v4 *)(t + 0x10);
                dir.z += *(f32 *)(t + 0xC) * 0.0009765625f;
                vec_sub_ba(&dir, &dir, p + 0x10);
                func_0038CF68(&dir, &dir, 1.0f);
                func_0038CF68(&v10, st, 1.0f);
                a = func_0038DB48(func_0038D0C8(func_0038CE68(&dir, &v10)) + 1.5707964f);
                k = 1.0f;
                if (st->x28 < a) {
                    k = st->x28 / a;
                }
                func_003C4098(&dir, &v10, &dir, k);
                func_0038CF68(st, &dir, func_0038CEA8(st));
            }
        }
        vec_add_ba(&np, p + 0x10, st);
        if (st->x12 < 12) {
            st->x12++;
        }
        func_L01_00446760(info, p, 0x10001, D_L22_001D66B0, st->x18);
        o = st->x14;
        func_L01_004CB320();
        hit = func_003D3CB0(p + 0x10, &np, 0, o, info);
        if (hit != 0) {
            h = D_L22_001E9858[0];
            if (h != 0 && *(s16 *)(h + 0xAA) == 0x186D && h[0x20] != 2 && h[0x20] != 5) {
                h[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit != 0) {
            *(s32 *)(p + 0x98) = 0;
            *(u16 *)(p + 0x34) = (*(u16 *)(p + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(p, 1);
            func_L01_004450F0(p, 1, -1);
            func_L22_00343800(D_L22_001E9860, 0xA, 1);
        } else if (func_0038CB00(&st->x10) != 0) {
            *(s32 *)(p + 0x98) = 0;
            *(u16 *)(p + 0x34) = (*(u16 *)(p + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(p, 1);
            func_L01_004450F0(p, 1, -1);
        } else {
            v10 = *(vu0_v4 *)(p + 0x10);
            func_0038CE20(&dir, st, 0.2f);
            for (i = 0; i < 5; i++) {
                sz = func_003824E0(0.1f, 0.3f) * st->x20;
                n = func_00382468(0xFF);
                func_L01_00443B88(&v60, 0.0f, 0.1f);
                vec_add_ba(&v60, &v60, &v10);
                func_L01_0046FB40(&v60, D_L22_001D66B0, 0xC, st->x1C, n, 0x20, 0, sz * 210000.0f, sz * 0.2f * 210000.0f, 0.0f, 0);
                vec_add_ab(&v10, &v10, &dir);
            }
        }
        *(vu0_v4 *)(p + 0x10) = np;
        break;
    case 1:
        if (--st->x12 == -1) {
            func_003C2880(p);
        }
        break;
    }
}
/* localdecomp:end func_L22_00343C18 */

/* localdecomp:start func_L22_00344050 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern u8 *func_00382348(s32);
extern f32 D_L22_001DD0BC;
__asm__(".extern D_L22_001DD0BC, 4");
u8 *func_L22_00344050(s32 a0, u128_t *a1, f32 *a2, s32 a3, s32 a4, s32 a5, f32 fa, f32 fb) {
    u8 *o = func_003C24B0(0xA72, 0x80);
    u8 *st;
    u8 *q;
    if (o != 0) {
        st = *(u8 **)(o + 0x68);
        func_L01_00456160(o, a0);
        *(u128_t *)(o + 0x10) = *a1;
        *(f32 *)(o + 0xF8) = func_0038D160(a2[0], a2[1]);
        *(f32 *)(o + 0xF4) = -func_0038D160(func_0038CED8(a2), a2[2]);
        *(u128_t *)st = *(u128_t *)a2;
        *(u16 *)(st + 0x10) = 0x4B;
        *(s32 *)(st + 0x14) = a0;
        *(s32 *)(st + 0x18) = a3;
        *(s32 *)(st + 0x1C) = a4;
        *(f32 *)(st + 0x28) = fb;
        *(u16 *)(st + 0x12) = 0;
        *(f32 *)(st + 0x20) = fa;
        if (a5 != 0) {
            q = func_00382348(a5);
            if (q != 0) {
                *(u16 *)(q + 0x1E) = *(u16 *)(q + 0x1E) | 0x80;
                if (q[0xB] != 0) {
                    *(s32 *)(st + 0x24) = 0;
                } else {
                    *(s32 *)(st + 0x24) = a5;
                }
            } else {
                *(s32 *)(st + 0x24) = a5;
            }
        }
        if (fa == 1.0f) {
            *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * D_L22_001DD0BC;
        } else {
            *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * fa;
        }
    }
    return o;
}
/* localdecomp:end func_L22_00344050 */

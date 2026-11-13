#include "common.h"

/* localdecomp:start func_L24_00356100 */
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
void func_L24_00356100(u8 *a0, u8 *a1) {
    if (*(s32 *)(a1 + 0x8E0) > 0) {
        *(f32 *)(a1 + 0x8EC) = 3.1415927f;
    } else {
        *(f32 *)(a1 + 0x8EC) = 0.0f;
    }
    func_L01_00448890(a0 + 0xF8, a1 + 0x8E8, 0, *(f32 *)(a1 + 0x8EC), 0.31415927f, 0.31415927f, 0.34906587f);
}
/* localdecomp:end func_L24_00356100 */

INCLUDE_ASM("asm/levels", func_L24_00356168);

/* localdecomp:start func_L24_003572D8 */
#include "vu0.h"
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
__asm__(".extern D_L24_001DD594, 4");
extern s32 D_L24_001DD594;

void func_L24_003572D8(u8 *obj, u8 *s) {
    f32 a[4];
    f32 b[4];
    f32 d[4];
    u8 c[0x30];
    f32 f[4];
    f32 out[4];
    f32 e[4];
    s32 i;
    s32 n;
    s32 t;

    func_003C2F58(obj, 0, a);
    func_003C2F58(obj, 1, b);
    n = D_L24_001DD594;
    t = n - 2;
    i = (*(s32 *)(s + 0x8B0) + t) % n;
    vec_sub_ab(d, s + 0x2A0 + *(s32 *)(s + 0x8B0) * 16, s + 0x2A0 + i * 16);
    func_0038CF68(d, d, 2.5f);
    d[2] = 1.0f;
    d[3] = 5627.9248f;
    func_L01_00446760(c, obj, 0x10000, d, 10.0f);
    c[0x18] = 0;
    c[0x19] = 1;
    *(u16 *)(c + 0x1A) = *(u16 *)(obj + 0xAA);
    func_003D3CB0(a, b, 9, obj, c);
    vec_sub_ab(e, s + 0x2A0 + i * 16, obj + 0x10);
    vec_sub_ab(f, b, obj + 0x10);
    func_L01_0044C280(out, e, f, 0, 0.2f);
    vec_add_ab(out, out, obj + 0x10);
    func_003D3CB0(a, out, 9, obj, c);
    func_L01_0044C280(out, e, f, 0, 0.4f);
    vec_add_ab(out, out, obj + 0x10);
    func_003D3CB0(a, out, 9, obj, c);
    func_L01_0044C280(out, e, f, 0, 0.6f);
    vec_add_ab(out, out, obj + 0x10);
    func_003D3CB0(a, out, 9, obj, c);
    func_L01_0044C280(out, e, f, 0, 0.8f);
    vec_add_ba(out, out, obj + 0x10);
    func_003D3CB0(a, out, 9, obj, c);
    func_003D3CB0(a, s + 0x2A0 + i * 16, 9, obj, c);
}
/* localdecomp:end func_L24_003572D8 */

/* localdecomp:start func_L24_00357588 */
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);

void func_L24_00357588(u8 *obj, s32 a1, s32 a2, s32 a3, f32 scale) {
    u8 buf[16];

    func_003C2F58(obj, a2, buf);
    func_L01_00446780(obj, buf, 0x10000, 0, 1, 0, scale, (f32)a3, 1.0f);
}
/* localdecomp:end func_L24_00357588 */

/* localdecomp:start func_L24_00357600 */
void func_L24_00357600(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    *(s32 *)(s + 0x8C0) = 0x7F96006B;
    *(s32 *)(s + 0x8C4) = 0x6FFFFFFF;
    *(s32 *)(s + 0x8C8) = 0x2096006B;
    *(s32 *)(s + 0x8CC) = 0x450030;
}
/* localdecomp:end func_L24_00357600 */

/* localdecomp:start func_L24_00357638 */
#include "vu0.h"
extern s32 D_L24_001E0FF0;
extern s32 D_L24_001E0FF4;
extern s32 D_L24_001E0FF8;
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L24_00357600(u8 *);

s32 func_L24_00357638(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);

    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.9f;
    D_L24_001E0FF0 = 0;
    D_L24_001E0FF4 = 0;
    D_L24_001E0FF8 = 0;
    *(vu0_q *)(s + 0x8A0) = *(vu0_q *)(obj + 0x10);
    *(u8 *)(s + 0x170) = 9;
    *(u8 *)(s + 0x1A8) = 3;
    *(f32 *)(s + 0x1BC) = 0.5f;
    *(f32 *)(s + 0x74) = 0.5f;
    *(f32 *)(s + 0x1B8) = 0.01f;
    *(u8 *)(s + 0x171) = 8;
    *(u8 *)(s + 0x176) = 9;
    *(s32 *)(s + 0x20C) = 0;
    *(f32 *)(s + 0x70) = 0.7f;
    *(f32 *)(s + 0x78) = 0.5f;
    *(f32 *)(s + 0x7C) = 1.0f;
    *(f32 *)(s + 0x80) = 0.7853982f;
    *(f32 *)(s + 0xA0) = 0.34906584f;
    *(f32 *)(s + 0x9C) = 0.0039200001f;
    func_L01_0045BD78(obj, 0.004f, 0.16000001f, 0.010053097f, 0.25132742f);
    if (*(s16 *)(s + 0x34) == 0) {
        *(s16 *)(s + 0x34) = 100;
        *(f32 *)(s + 0x30) = 100.0f;
    }
    *(u8 *)(s + 0x39) = 0;
    *(f32 *)(s + 0x40) = 2.0f;
    func_L24_00357600(obj);
    *(s32 *)(s + 0x8E4) = -1;
    func_L01_004450F0(obj, 1, 0);
    if (*(u8 *)(obj + 0x43) != 0) {
        func_003C3A10(obj, 0, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L24_00357638 */

/* localdecomp:start func_L24_003577D0 */
#include "vu0.h"
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
__asm__(".extern D_L24_001DD598, 4");
__asm__(".extern D_L24_001DD59C, 4");
__asm__(".extern D_L24_001DD5A0, 4");
__asm__(".extern D_L24_001DD5A4, 4");
__asm__(".extern D_L24_001DD5A8, 4");
__asm__(".extern D_L24_001DD5AC, 4");
__asm__(".extern D_L24_001DD5B0, 4");
__asm__(".extern D_L24_001DD5B4, 4");
extern u32 D_L24_001DD598;
extern f32 D_L24_001DD59C;
extern f32 D_L24_001DD5A0;
extern u32 D_L24_001DD5A4;
extern f32 D_L24_001DD5A8;
extern f32 D_L24_001DD5AC;
extern u32 D_L24_001DD5B0;
extern f32 D_L24_001DD5B4;

void func_L24_003577D0(u8 *obj) {
    f32 a[4];
    f32 b[4];
    f32 c[4];
    f32 m1[16];
    f32 m2[16];
    f32 s;

    func_003C2F58(obj, 5, a);
    func_003C2EC0(obj, 6, m1);
    func_003C2EC0(obj, 7, m2);
    func_0038CF68(b, m1, D_L24_001DD5A0);
    vec_add_ab(b, b, &m1[12]);
    func_0038CF68(c, m2, D_L24_001DD5AC);
    vec_add_ab(c, c, &m2[12]);
    s = *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
    func_003D9508(a, 0xB, D_L24_001DD5B0, 1, s * D_L24_001DD5B4, 0.08f, 0.0f);
    func_003D9508(b, 0xB, D_L24_001DD598, 1, s * D_L24_001DD59C, 0.08f, 0.0f);
    func_003D9508(c, 0xB, D_L24_001DD5A4, 1, s * D_L24_001DD5A8, 0.08f, 0.0f);
}
/* localdecomp:end func_L24_003577D0 */

/* localdecomp:start func_L24_00357930 */
#include "vu0.h"
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, u32, s32, u32, u32, u32, u32, f32, f32, f32);
extern void func_L01_00408C98(void *, s32, void *, void *, s32, s32, f32, s32, s32, s32);
__asm__(".extern D_L24_001DD590, 4");
__asm__(".extern D_L24_001DD594, 4");
extern u32 D_L24_001DD590;
extern s32 D_L24_001DD594;

void func_L24_00357930(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 a[4];
    f32 b[4];
    f32 c[4];
    f32 d[4];
    f32 m[16];
    f32 w[4];
    f32 t;
    u8 *q;

    t = *(f32 *)(s + 0x8B8) - 0.1f;
    *(f32 *)(s + 0x8B8) = t;
    if (t <= -8.0f) {
        *(f32 *)(s + 0x8B8) = t + 8.0f;
    }
    func_003C2F58(obj, 0, a);
    func_003C2F58(obj, 2, b);
    func_003C2F58(obj, 1, c);
    func_003C2F58(obj, 3, d);
    q = s + 0x6A0;
    func_003C2EC0(obj, 1, m);
    *(vu0_q *)w = *(vu0_q *)m;
    func_0038CF68(w, w, -2.25f);
    *(vu0_q *)(s + 0x6B0) = *(vu0_q *)w;
    *(f32 *)(s + 0x6BC) = 1.0f;
    *(vu0_q *)w = *(vu0_q *)m;
    func_0038CF68(w, w, 0.45f);
    *(vu0_q *)(s + 0x6A0) = *(vu0_q *)w;
    *(f32 *)(s + 0x6AC) = 1.0f;
    func_L01_0040A8C0(a, c, D_L24_001DD590, 1, *(u32 *)(s + 0x8C0), *(u32 *)(s + 0x8C0), *(u32 *)(s + 0x8C0), *(u32 *)(s + 0x8C0), 0.08f, 0.75f, *(f32 *)(s + 0x8B8));
    func_L01_0040A8C0(b, d, D_L24_001DD590, 1, *(u32 *)(s + 0x8C0), *(u32 *)(s + 0x8C0), *(u32 *)(s + 0x8C0), *(u32 *)(s + 0x8C0), 0.08f, 0.75f, *(f32 *)(s + 0x8B8));
    func_L01_0040A8C0(a, c, D_L24_001DD590, 1, *(u32 *)(s + 0x8C4), *(u32 *)(s + 0x8C4), *(u32 *)(s + 0x8C4), *(u32 *)(s + 0x8C4), 0.035f, 0.75f, *(f32 *)(s + 0x8B8));
    func_L01_0040A8C0(b, d, D_L24_001DD590, 1, *(u32 *)(s + 0x8C4), *(u32 *)(s + 0x8C4), *(u32 *)(s + 0x8C4), *(u32 *)(s + 0x8C4), 0.035f, 0.75f, *(f32 *)(s + 0x8B8));
    func_L01_00408C98(q, D_L24_001DD594, s + 0x2A0, s + 0x4A0, *(s32 *)(s + 0x8B0), *(s32 *)(s + 0x8D8), *(f32 *)(s + 0x8D0), *(s32 *)(s + 0x8C8), *(s32 *)(s + 0x8CC), 5);
}
/* localdecomp:end func_L24_00357930 */

/* localdecomp:start func_L24_00357BB0 */
typedef int u128_t __attribute__((mode(TI)));
void func_L24_00357BB0(u8 *obj) {
    *(u128_t *)(obj + 0x10) = *(u128_t *)(*(u8 **)(obj + 0x68) + 0x8A0);
}
/* localdecomp:end func_L24_00357BB0 */

/* localdecomp:start func_L24_00357BC0 */
#include "vu0.h"
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern void func_003C3FC0(void *, void *);
__asm__(".extern D_L24_001DD594, 4");
extern s32 D_L24_001DD594;

void func_L24_00357BC0(void *arg) {
    u8 *obj = arg;
    u8 *s = *(u8 **)(obj + 0x68);
    f32 a[4];
    f32 m[16];
    s32 z[4];
    f32 d1[4];
    f32 d2[4];
    f32 out[4];
    s32 i;
    s32 n;
    s32 t;

    *(f32 *)(s + 0x8D0) = 0.0f;
    func_003C2F58(obj, 1, a);
    func_003C2EC0(obj, 1, m);
    if (*(f32 *)(s + 0x8D0) == 0.0f) {
        s32 n = D_L24_001DD594;
        *(s32 *)(s + 0x8B0) = (*(s32 *)(s + 0x8B0) + 1) % n;
        if (*(s32 *)(s + 0x8D8) < n) {
            *(s32 *)(s + 0x8D8) = *(s32 *)(s + 0x8D8) + 1;
        }
    }
    z[0] = 0;
    z[1] = 0;
    z[2] = 0;
    z[3] = 0;
    if (*(s32 *)(s + 0x8BC) >= 2) {
        n = D_L24_001DD594;
        t = n - 1;
        i = (*(s32 *)(s + 0x8B0) + t) % n;
        vec_sub_ab(d1, a, obj + 0x10);
        vec_sub_ba(d2, s + 0x2A0 + i * 16, obj + 0x10);
        func_L01_0044C280(out, d2, d1, 0, 0.5f);
        func_003C3FC0(s + 0x4A0 + *(s32 *)(s + 0x8B0) * 16, z);
        vec_add_ba(s + 0x2A0 + *(s32 *)(s + 0x8B0) * 16, out, obj + 0x10);
        *(s32 *)(s + 0x8B0) = (*(s32 *)(s + 0x8B0) + 1) % D_L24_001DD594;
    }
    func_003C3FC0(s + 0x4A0 + *(s32 *)(s + 0x8B0) * 16, z);
    *(vu0_q *)(s + 0x2A0 + *(s32 *)(s + 0x8B0) * 16) = *(vu0_q *)a;
}
/* localdecomp:end func_L24_00357BC0 */

/* localdecomp:start func_L24_00357D50 */
#include "vu0.h"
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern void func_L01_0046B458(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);

void func_L24_00357D50(u8 *obj) {
    f32 d[4];
    f32 a[4];
    f32 c[4];
    f32 f;
    s32 n;
    s32 r;

    n = 3;
    do {
        func_003C2F58(obj, 7, a);
        n--;
        a[0] += func_003824E0(-0.15f, 0.15f);
        a[1] += func_003824E0(-0.15f, 0.15f);
        a[2] += func_003824E0(-0.15f, 0.15f);
        *(vu0_q *)c = *(vu0_q *)(obj + 0xC0);
        func_0038CF68(c, c, 0.5f);
        vec_add_ab(a, a, c);
        *(vu0_q *)d = *(vu0_q *)(obj + 0xC0);
        d[0] += func_003824E0(-0.07f, 0.07f);
        d[1] += func_003824E0(-0.07f, 0.07f);
        d[2] += func_003824E0(0.0f, 0.3f);
        func_0038CF68(d, d, func_003824E0(0.05f, 0.2f));
        f = func_003824E0(0.15f, 0.3f);
        r = func_00382468(2);
        if (r == 0)
            r = r - 1;
        func_L01_0046B458(a, 0x96, 0x7F007FFF, 0, r, d, f * 0.1f, f, 0.0028800003f, 0);
    } while (n >= 0);
}
/* localdecomp:end func_L24_00357D50 */

INCLUDE_ASM("asm/levels", func_L24_00357F70);

/* localdecomp:start func_L24_00358860 */
#include "vu0.h"
typedef struct { u8 pad[0x50]; f32 f50; u8 pad2[0x9C]; } T_358860;
__asm__(".extern D_L24_001DF51C, 4");
extern u8 *D_L24_001DF51C;
extern s32 D_L24_001DF0C0;
extern u8 D_001425C0[];
extern T_358860 D_L24_002C35C0[];
extern u8 D_001A4C60[];
extern void func_L01_0044ABD0(void *, void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_L01_004474E8(void *, void *);
extern void func_L01_00455E18(void *, void *, void *);
extern f32 func_L01_004510F8(void *, void *, s32);
extern void func_L01_00451048(void *, void *, void *, s32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_L24_00357F70(void *, void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

s32 func_L24_00358860(u8 *obj, u8 *r, s32 flag) {
    s32 lvl = 0;
    u8 *s;
    u8 *h;
    u8 *t21;
    u8 *hit;
    f32 dmg;
    f32 base;
    f32 hp;
    s32 thr;
    f32 dir[4];

    if (!(*(u16 *)(obj + 0x34) & 0x20)) {
        return 0;
    }
    s = *(u8 **)(obj + 0x68);
    h = *(u8 **)s;
    t21 = *(u8 **)(s + 0x20);
    if (r == 0) {
        return 0;
    }
    if (h == 0) {
        return 0;
    }
    func_L01_0044ABD0(obj, r);
    base = 0.0f;
    hit = func_L01_00447490(obj, 0x10000, 0);
    if (func_0038CB00(h + 6) == 0) {
        hit = 0;
    }
    if (hit != 0) {
        base = *(f32 *)(hit + 0x2C);
        if (*(f32 *)(r + 0xA8) != 0.0f && *(u8 **)(hit + 0x20) != 0
            && *(s16 *)(obj + 0xAA) == *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA)) {
            *(f32 *)(hit + 0x2C) = base * *(f32 *)(r + 0xA8);
        }
        if (flag != 0) {
            *(f32 *)(hit + 0x2C) = *(f32 *)(hit + 0x2C) * *(f32 *)(r + 0xAC);
        }
    }
    dmg = func_L01_004474E8(obj, hit);
    obj[0xA8] = 0xFF;
    *(f32 *)h = *(f32 *)h - dmg;
    if (t21 != 0) {
        func_L01_00455E18(obj, t21, h);
    }
    if ((flag == 0 || hit == 0) && dmg == 0.0f) {
        return 0;
    }
    *(s16 *)(r + 0x70) = -1;
    if (hit != 0 && *(u8 **)(hit + 0x20) != 0) {
        *(s16 *)(r + 0x70) = (*(u8 **)(hit + 0x20) - D_L24_001DF51C) >> 8;
    }
    {
        s32 ix = h[0x17];
        f32 k = ((T_358860 *)(D_001425C0[ix] * 0xF0 + (u8 *)D_L24_002C35C0))->f50;
        thr = 300;
        hp = (f32)*(s16 *)(h + 4) * *(f32 *)(r + 0x58);
        if (hp <= dmg * k) {
            thr = 90;
        }
    }
    if (r[0x77] == 0 && (thr * 5 + 2) / 6 < abs_asm(D_L24_001DF0C0 - *(s32 *)(r + 0x44)) && dmg < hp) {
        dmg = hp;
    }
    if (*(f32 *)h <= 0.0f) {
        lvl = 4;
    } else if ((f32)(s16)*(u16 *)(h + 4) * *(f32 *)(r + 0x5C) <= dmg) {
        lvl = 3;
    } else if ((f32)(s16)*(u16 *)(h + 4) * *(f32 *)(r + 0x58) <= dmg) {
        lvl = 2;
    } else if (dmg != 0.0f && r[0x77] == 0 && hit != 0 && *(u8 **)(hit + 0x20) != 0
               && *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x47) {
        lvl = 2;
    } else if (base != 0.0f) {
        lvl = 1;
    }
    if (flag != 0 && (u32)(lvl - 1) <= 2) {
        lvl = 6;
    }
    if (lvl >= 2 && hit != 0 && h[0x17] == 9) {
        f32 f = func_L01_004510F8(obj, hit + 0x10, 0);
        vec_sub_ab(hit + 0x10, obj + 0x10, D_001A4C60);
        func_L01_00451048(obj, hit + 0x10, hit + 0x10, 0, f);
    }
    if (lvl == 0) {
        return 0;
    }
    if (*(u16 *)(r + 0x38) & 3) {
        return 0;
    }
    if (obj[0x95] == r[0x48] && lvl < 4) {
        if (r[0x75] != 0) {
            return 0;
        }
        if (r[0x1A] < 2) {
            return 0;
        }
    }
    if (hit != 0 && (*(s32 *)(hit + 0x30) & 1)) {
        *(vu0_q *)dir = *(vu0_q *)(hit + 0x10);
    } else {
        func_0038CE20(dir, obj + 0xC0, -1.0f);
        dir[2] = 1.0f;
        dir[3] = 5627.925f;
    }
    if (func_L24_00357F70(obj, r, dir, lvl, -1) != 0) {
        *(s32 *)(r + 0x44) = D_L24_001DF0C0;
        if (flag == 0) {
            if (r[0x48] != 0xFF && r[0x48] != 0) {
                func_L01_004450F0(obj, r[0x10], r[0x48]);
            } else if (r[0x10] != 0xFF && r[0x10] != 0) {
                func_L01_004450F0(obj, r[0x10], -1);
            }
        }
        r[0x1A] = 0;
    }
    return lvl;
}
/* localdecomp:end func_L24_00358860 */

/* localdecomp:start func_L24_00358D10 */
/* from rac2-decomp's func_00312B58, renamed (constants adapted) */
s32 func_L24_00358D10(void *p)
{
    return *((u8 *)p + 0x20) == 8;
}
/* localdecomp:end func_L24_00358D10 */

/* localdecomp:start func_L24_00358D20 */
extern s32 func_L24_00358D10(void *);
extern s32 func_L24_00358860(u8 *, u8 *, s32);

s32 func_L24_00358D20(void *arg0) {
    if (func_L24_00358D10(arg0) != 0) {
        func_L24_00358860(arg0, (u8 *)(*(s32 *)((u8 *)arg0 + 0x68) + 0x160), 1);
    } else {
        func_L24_00358860(arg0, (u8 *)(*(s32 *)((u8 *)arg0 + 0x68) + 0x160), 0);
    }
    return 0;
}
/* localdecomp:end func_L24_00358D20 */

/* localdecomp:start func_L24_00358D78 */
extern s32 func_0038CAD0(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L24_00357930(u8 *);
extern void func_L24_00357BC0(void *);
extern void func_L24_003577D0(u8 *);
extern s32 D_L24_001E0FF0;
extern s32 D_L24_001E0FF4;
extern s32 D_L24_001E0FF8;
extern s32 D_L24_001E1000;
extern s32 D_L24_001E1004;
extern s32 D_L24_001E1008;
extern s32 D_L24_001E1010;
extern s32 D_L24_001E1014;
extern s32 D_L24_001E1018;

void func_L24_00358D78(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    if (*(u16 *)(obj + 0x96) <= 0xFFFE) {
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    }
    if (*(s32 *)(s + 0x8BC) < 10) {
        *(s32 *)(s + 0x8BC) = *(s32 *)(s + 0x8BC) + 1;
    }
    if (func_0038CAD0(&D_L24_001E0FF4) != 0) {
        D_L24_001E0FF0 = 0;
        D_L24_001E0FF4 = 0;
        D_L24_001E0FF8 = 0;
    }
    if (func_0038CAD0(&D_L24_001E1004) != 0) {
        D_L24_001E1000 = 0;
        D_L24_001E1004 = 0;
        D_L24_001E1008 = 0;
    }
    if (func_0038CAD0(&D_L24_001E1014) != 0) {
        D_L24_001E1010 = 0;
        D_L24_001E1014 = 0;
        D_L24_001E1018 = 0;
    }
    if (*(s32 *)(s + 0x8BC) != 0) {
        func_L01_00404808(func_L24_00357930, obj);
        func_L24_00357BC0(obj);
    }
    func_L01_00404808(func_L24_003577D0, obj);
}
/* localdecomp:end func_L24_00358D78 */

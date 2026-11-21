#include "common.h"

/* localdecomp:start func_L11_0033CFB0 */
#include "vu0.h"
typedef struct {
    f32 f00;
    f32 f04;
    u8 pad08[8];
    f32 f10[4];
    f32 f20[4];
    f32 f30[4];
} P_0033CFB0;

extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L11_0033D310(void *);
extern void func_L11_0033D510_0033CFB0(void *);
extern void func_L01_00404808(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern u8 D_L11_001E84E0[];
extern f32 D_L11_001DBBA8;
extern s32 D_001D545C;
extern u8 D_001A4C60[];
extern u8 D_001A4EC0[];
extern f32 D_L11_001DCFA8[2], D_L11_001DCFB0[2];
extern f32 D_L11_001DCFC0;
extern s32 D_L11_001DCFB8[2];
__asm__(".extern D_L11_001DCFB8, 8");

void func_L11_0033CFB0(u8 *obj) {
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 u20;
    vu0_v4 u30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 u80;
    vu0_v4 u90;
    P_0033CFB0 *p;
    s32 i;
    f32 c;
    u8 *hero;
    u8 state;

    state = obj[0x20];
    p = *(P_0033CFB0 **)(obj + 0x68);
    switch (state) {
    case 0:
        *(u16 *)(obj + 0x34) |= 0x100;
        func_003C5180(obj + 0x10, &v0, 0);
        func_L01_004515D8(obj + 0xC0, &v0, &v1);
        func_0038CF68(&v40, obj + 0xE0, 0.5f);
        func_0038CF68(&v50, obj + 0xE0, -4.0f);
        vec_add_ba(&v40, &v40, obj + 0x10);
        vec_add_ba(&v50, &v50, obj + 0x10);
        if (func_003D3CB0(&v40, &v50, 2, obj, 0) != 0) {
            *(vu0_q *)(obj + 0x10) = *(vu0_q *)D_L11_001E84E0;
            func_0038CF68(&v50, obj + 0xE0, -0.1f);
            vec_add_ba(obj + 0x10, &v50, obj + 0x10);
            func_003C5180(obj + 0x10, &v60, 0);
            func_L01_004515D8(obj + 0xC0, &v60, &v70);
        }
        func_L01_004450F0(obj, 1, -1);
        *(s16 *)(obj + 0x32) = 0xFF;
        for (i = 0; i < 4; i++) {
            p->f20[i] = (f32)i * 0.25f;
            p->f30[i] = func_003824E0(D_L11_001DCFA8[0], D_L11_001DCFA8[1]) * 0.020000001f;
            p->f10[i] = func_003824E0(D_L11_001DCFB0[0], D_L11_001DCFB0[1]);
        }
        break;
    case 1:
        if (D_001D545C == 0xB) {
            func_003C5180(obj + 0x10, &v0, 0);
            func_L01_004515D8(obj + 0xC0, &v0, &v1);
        }
        if (func_0038CF00(D_001A4C60, obj + 0x10) < 3.0f) {
            D_L11_001DBBA8 = p->f00;
        }
        hero = D_001A4C60 - 0x80;
        if (*(s32 *)(hero + 0x25C4) == 0x86) {
            if (*(s32 *)(hero + 0x1B8) == state) {
                func_003A52A0(0, 0, obj);
            }
        }
        if (func_0038CE68(obj + 0xE0, D_001A4EC0) < -0.6f) {
            func_L11_0033D310(obj);
            func_L01_00404808(func_L11_0033D510_0033CFB0, obj);
        }
        break;
    }
    if (obj[0x31] != 0) {
        c = func_0038DAB8(p->f04, D_L11_001DCFC0 * 0.017453292f * 0.020000001f);
        p->f04 = c;
        c = func_0038D0B0(c);
        c = c * c;
        c = c * c;
        *(s32 *)(obj + 0x78) = func_0038DBD8(D_L11_001DCFB8[0], D_L11_001DCFB8[1], c * c);
    }
}
/* localdecomp:end func_L11_0033CFB0 */

/* localdecomp:start func_L11_0033D310 */
#include "vu0.h"
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; u8 *f68; } S_0033D310;
extern s32 func_00382468(s32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern f32 D_L11_001DCFA8[2], D_L11_001DCFB0[2], D_L11_001DCFC8[2], D_L11_001DCFD0[2], D_L11_001DCFE8[2];
extern s32 D_L11_001DCFE0[2];
__asm__(".extern D_L11_001DCFE0, 8");
extern s32 D_L11_001DCFD8, D_L11_001DCFDC, D_L11_001DCFF0;

void func_L11_0033D310(void *arg) {
    S_0033D310 *a0 = arg;
    vu0_v4 w;
    vu0_v4 v;
    f32 *p;
    s32 i;
    s32 n;
    s32 tex;
    f32 a;
    f32 r;
    f32 sc;

    p = (f32 *)(a0->f68 + 0x30);
    for (i = 3; i >= 0; i--) {
        p[-4] += p[0];
        if (1.0f <= p[-4]) {
            p[-4] = 0.0f;
            p[0] = func_003824E0(D_L11_001DCFA8[0], D_L11_001DCFA8[1]) * 0.020000001f;
            p[-8] = func_003824E0(D_L11_001DCFB0[0], D_L11_001DCFB0[1]);
        }
        p++;
    }
    if (func_00382468(D_L11_001DCFF0) == 0) {
        return;
    }
    qzero(&v);
    v.z = func_003824E0(D_L11_001DCFC8[0], D_L11_001DCFC8[1]) * 0.020000001f;
    func_0038D000(&v, &v, (u8 *)a0 + 0xC0);
    a = func_00382538();
    r = func_003824E0(D_L11_001DCFE8[0], D_L11_001DCFE8[1]);
    w.x = func_0038D098(a) * r;
    w.y = func_0038D0B0(a) * r;
    w.z = 0.0f;
    func_0038D000(&w, &w, (u8 *)a0 + 0xC0);
    vec_add_ba(&w, &w, &a0->pos);
    n = (func_00382498(D_L11_001DCFE0[0], D_L11_001DCFE0[1]) * 5 + 2) / 6;
    sc = func_003824E0(D_L11_001DCFD0[0], D_L11_001DCFD0[1]);
    tex = func_00382468(2) ? D_L11_001DCFD8 : D_L11_001DCFDC;
    func_L01_0046C470(&w, &v, tex, sc, n, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
}
/* localdecomp:end func_L11_0033D310 */

/* localdecomp:start func_L11_0033D510 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    f32 x10[4];
    f32 x20[4];
} D_0033D510;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 x10;
    u8 pad20[0x68 - 0x20];
    D_0033D510 *x68;
    u8 pad6C[0xC0 - 0x6C];
    u8 xC0[0x40];
} O_0033D510;

extern f32 D_L11_001DCFF8;
extern f32 D_L11_001DCFFC;
extern s32 D_L11_001DD000;
extern f32 D_L11_001DD004;
__asm__(".extern D_L11_001DCFF8, 4");
__asm__(".extern D_L11_001DD000, 4");
__asm__(".extern D_L11_001DD004, 4");

extern void func_L11_003E5030(void);
extern void func_0038D000(void *, void *, void *);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L11_003E5058(vu0_v4 *, s32, s32, f32, f32, f32);

void func_L11_0033D510(O_0033D510 *a0) {
    D_0033D510 *d = a0->x68;
    f32 *p;
    s32 i;
    vu0_v4 out;
    vu0_v4 in;
    f32 r;
    f32 t;
    f32 k;

    func_L11_003E5030();
    p = d->x20;
    for (i = 3; i >= 0; i--, p++) {
        *(vu0_q *)&in = 0;
        in.z = p[0] * p[-4];
        out = in;
        func_0038D000(&out, &out, a0->xC0);
        vec_add_ab(&out, &out, &a0->x10);
        r = func_003C4088(D_L11_001DCFF8, D_L11_001DCFFC, *p);
        t = *p;
        if (t < 0.1f) {
            k = (f32)D_L11_001DD000 * t * 10.0f;
        } else {
            k = (f32)D_L11_001DD000 * (1.0f - t);
        }
        func_L11_003E5058(&out, (s32)k, 0, r, D_L11_001DD004, 0.08f);
    }
}
/* localdecomp:end func_L11_0033D510 */

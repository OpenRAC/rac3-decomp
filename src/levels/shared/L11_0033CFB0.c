#include "common.h"

INCLUDE_ASM("asm/levels", func_L11_0033CFB0);

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

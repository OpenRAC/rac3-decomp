#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct { u8 pad[288]; u8 sub[4020 - 288]; f32 f; } S630;

INCLUDE_ASM("asm/levels", func_L39_00632888);

INCLUDE_ASM("asm/levels", func_L39_00632988);

INCLUDE_ASM("asm/levels", func_L39_00632A20);

INCLUDE_ASM("asm/levels", func_L39_00632B68);

/* localdecomp:start func_L39_00632C48 */
s32 func_L39_00632C48(void *arg0, f32 fparg0) {
    f32 temp_f1;
    s32 var_v0;

    temp_f1 = *(f32 *)((u8 *)arg0 + 0x628);
    var_v0 = 0;
    if (fparg0 < temp_f1) {
        var_v0 = 1;
        if (!((temp_f1 - fparg0) <= (*(f32 *)((u8 *)arg0 + 0x62C)))) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
/* localdecomp:end func_L39_00632C48 */

INCLUDE_ASM("asm/levels", func_L39_00632C80);

INCLUDE_ASM("asm/levels", func_L39_00632D78);

INCLUDE_ASM("asm/levels", func_L39_00633160);

/* localdecomp:start func_L39_006331D0 */

extern void func_0038D328(Vec4 *, Vec4 *);
extern void func_0038D640(Vec4 *, Vec4 *, Vec4 *);
extern void func_003C48A8(Vec4 *, Vec4 *);

void func_L39_006331D0(u8 *m, f32 x, f32 y, f32 z) {
    Vec4 v;
    Vec4 m1[4];
    Vec4 m2[4];

    v.f[0] = x;
    v.f[1] = y;
    v.f[2] = z;
    func_0038D328(m1, &v);
    func_0038D328(m2, (Vec4 *)(m + 176));
    func_0038D640(m2, m2, m1);
    func_003C48A8(m2, (Vec4 *)(m + 176));
}
/* localdecomp:end func_L39_006331D0 */

/* localdecomp:start func_L39_00633250 */
extern void func_L39_006331D0(u8 *m, f32 x, f32 y, f32 z);

extern void func_0038D028(Vec4 *out, void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_L01_00448728(f32 *out, void *a, void *b, f32 f0, f32 f1, f32 f2, f32 f3);

void func_L39_00633250(u8 *self, void *arg, f32 a, f32 b, f32 c) {
    Vec4 v;
    f32 out;
    f32 angle;
    f32 zero = 0.0f;
    func_0038D028(&v, self + 4032, self + 96);
    angle = func_0038D160(v.f[0], v.f[1]);
    out = zero;
    *(f32 *)(self + 4056) = func_L01_00448728(&out, self + 4052, arg, angle, a, b, c);
    ((void (*)(void *self, f32 a, f32 b, f32 c))func_L39_006331D0)(self, zero, zero, out);
}
/* localdecomp:end func_L39_00633250 */

INCLUDE_ASM("asm/levels", func_L39_00633308);

INCLUDE_ASM("asm/levels", func_L39_00633428);

/* localdecomp:start func_L39_00633620 */
extern void func_003C4138(f32 *, f32, f32);
void func_L39_00633620(u8 *a, f32 x, f32 y) {
    f32 t = *(f32 *)(a + 4016);
    if (*(f32 *)(a + 4020) < t) {
        func_003C4138((f32 *)(a + 4020), t, x);
    } else {
        func_003C4138((f32 *)(a + 4020), t, y);
    }
}
/* localdecomp:end func_L39_00633620 */

/* localdecomp:start func_L39_00633670 */
extern void func_0038D028(Vec4 *out, void *a, void *b);

extern f32 func_0038D098(f32 x);
extern f32 func_0038D0B0(f32 x);
extern void func_00382760(Vec4 *out, f32 a, f32 b, f32 c);

void func_L39_00633670(u8 *self, f32 angle) {
    Vec4 v;
    Vec4 t;
    f32 r;
    f32 sel;
    f32 zero;
    sel = *(f32 *)(self + 184);
    if (angle <= 3.1415927f) {
        sel = angle;
    }
    r = *(f32 *)(self + 4020);
    if (*(u8 *)(self + 6662) != 0) {
        zero = 0.0f;
        t.f[0] = func_0038D098(zero) * r;
        t.f[1] = func_0038D0B0(zero) * r;
        t.f[2] = zero;
        ((void (*)(Vec4 *out, Vec4 *a, void *b))func_0038D028)(&t, &t, self + 32);
        v = t;
    } else {
        func_00382760(&v, r, sel, *(f32 *)(self + 692));
    }
    *(u128_t *)(self + 288) = v.q;
}
/* localdecomp:end func_L39_00633670 */

/* localdecomp:start func_L39_00633728 */
extern void func_0038CF68(void *, f32);
void func_L39_00633728(S630 *p) {
    func_0038CF68(p->sub, p->f);
}
/* localdecomp:end func_L39_00633728 */

INCLUDE_ASM("asm/levels", func_L39_00633748);

INCLUDE_ASM("asm/levels", func_L39_00633888);

INCLUDE_ASM("asm/levels", func_L39_00633980);

INCLUDE_ASM("asm/levels", func_L39_006339B0);

/* localdecomp:start func_L39_00633C78 */
extern void func_0038D028(Vec4 *out, void *a, void *b);
extern f32 func_0038D160(f32, f32);
extern void func_L01_004485E0(s32, f32, f32);

void func_L39_00633C78(u8 *a, s32 b, s32 c) {
    f32 v[4];

    ((void (*)(f32 *, s32, void *))func_0038D028)(v, b, a + 96);
    func_L01_004485E0(c, func_0038D160(v[0], v[1]), 0.0f);
}
/* localdecomp:end func_L39_00633C78 */

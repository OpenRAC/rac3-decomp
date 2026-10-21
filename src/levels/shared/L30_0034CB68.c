#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    Vec4 v;
    u8 *o;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 i20;
} S34BD48;

/* localdecomp:start func_L30_0034CB68 */
extern void func_L30_0034CC28(S34BD48 *s, u8 *o, Vec4 *pos, s32 a3, s32 a4, f32 f);
extern void func_003C2F58(u8 *a0, s32 a1, u128_t *a2);
extern s32 func_003D4D00(u128_t *a0, s32 a1, u8 *a2, s32 a3, f32 f12);
extern void func_L30_004E70A8(u8 *a0, u128_t *a1, u8 *a2, s32 a3);
void func_L30_0034CB68(u8 *a0, s32 a1, s32 a2, s32 a3, u128_t *t0, s32 t1, f32 f12, f32 f13) {
    u128_t m[3];
    u128_t pos;
    s32 r;
    ((void (*)(u128_t *a0, u8 *a1, s32 a2, s32 a3, s32 t0, f32 f12))func_L30_0034CC28)(m, a0, a1, a2, t1, f12);
    if (a3 < 0) {
        if (t0 != 0) {
            pos = *t0;
        } else {
            pos = *(u128_t *)(a0 + 16);
        }
    } else {
        func_003C2F58(a0, a3, &pos);
    }
    r = func_003D4D00(&pos, 0, a0, 0, f13);
    if (r != 0) {
        func_L30_004E70A8(a0, m, a0 + 16, r);
    }
}
/* localdecomp:end func_L30_0034CB68 */

/* localdecomp:start func_L30_0034CC28 */


extern void func_0038CF68(S34BD48 *, S34BD48 *, f32);

void func_L30_0034CC28(S34BD48 *s, u8 *o, Vec4 *pos, s32 a3, s32 a4, f32 f) {
    s->o = o;
    if (a3 != 0) {
        s->flags = 0x1000001;
        if (a4 != 0) {
            s->flags = 0x1020001;
        }
    } else {
        s->flags = 0x1010000;
    }
    s->f1C = f;
    s->i20 = 1;
    s->v.q = pos->q;
    func_0038CF68(s, s, 1.0f);
    s->v.f[3] = 5627.9248046875f;
    s->b18 = 3;
    s->b19 = 2;
    s->h1A = *(u16 *)(o + 170);
}
/* localdecomp:end func_L30_0034CC28 */

INCLUDE_ASM("asm/levels", func_L30_0034CCD0);

INCLUDE_ASM("asm/levels", func_L30_0034CDC0);

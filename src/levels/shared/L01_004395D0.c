#include "common.h"
#include "vu0.h"

LINKER_REMNANT("asm/levels", func_L01_004395D0);

/* localdecomp:start func_L01_004395E0 */
typedef struct {
    u8 pad0[4];
    s16 h4;
} S_436500b;

typedef struct {
    u8 pad0[0x40];
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    f32 f44;
    u8 pad48[0x58 - 0x48];
    S_436500b *p58;
    S_436500b *p5C;
} S_436500;

f32 func_L01_004395E0(S_436500 *s) {
    S_436500b *a;
    f32 t;

    if (s->b42 != 255) {
        a = s->p58;
    } else {
        a = s->p5C;
    }
    t = s->f44;
    if (t == 0.0f) {
        return a->h4 * 0.0625f;
    }
    if (s->b42 != s->b43 || s->b40 > s->b41) {
        return a->h4 * 0.0625f + t;
    }
    return (a->h4 * (1.0f - t) + s->p5C->h4 * t) * 0.0625f;
}
/* localdecomp:end func_L01_004395E0 */

/* localdecomp:start func_L01_004396C0 */
f32 func_L01_004396C0(u8 *a0) {
    f32 t = *(f32 *)(a0 + 36);
    u8 *a = *(u8 **)(a0 + 56);
    u8 *b;
    if (t == 0.0f) {
        return *(s16 *)(a + 4) * 0.0625f;
    }
    if (a0[34] != a0[35] || a0[32] > a0[33]) {
        return *(s16 *)(a + 4) * 0.0625f + t;
    }
    b = *(u8 **)(a0 + 60);
    return (*(s16 *)(a + 4) * (1.0f - t) + *(s16 *)(b + 4) * t) * 0.0625f;
}
/* localdecomp:end func_L01_004396C0 */

LINKER_REMNANT("asm/levels", func_L01_00439788);

/* localdecomp:start func_L01_00439790 */
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
void func_L01_00439790(u8 *o, s32 idx, u8 *v, f32 fa, f32 fb) {
    u8 mat[64] __attribute__((aligned(16)));
    vu0_v4 d;
    u8 *t;
    f32 s;
    t = *(u8 **)(o + 152);
    if (idx < (*(s32 *)(t + 4) >> 5)) {
        s = 1024.0f / *(f32 *)(o + 44);
        t = t + (idx * 32 + 16);
        func_0038D5B0(mat, o + 192);
        vec_sub_ba(&d, v, o + 16);
        func_0038D028(&d, &d, mat);
        func_0038CE20(&d, &d, s);
        *(vu0_q *)(t + 16) = *(vu0_q *)&d;
        *(f32 *)(t + 4) = fb * s;
        *(f32 *)(t + 28) = fa * s;
    }
}
/* localdecomp:end func_L01_00439790 */

/* localdecomp:start func_L01_00439880 */
#include "vu0.h"
void func_L01_00439880(u8 *o, s32 *a, s32 *b) {
    u8 *t = *(u8 **)(o + 0x24);
    s32 n = t[0x2C];
    if (n != 0) {
        s32 h = *(s16 *)(t + (n << 4) + 2);
        *a = h;
        *b = 30 - plzcw_asm(h << 1);
    } else {
        *a = 0;
        *b = 0;
    }
}
/* localdecomp:end func_L01_00439880 */

/* localdecomp:start func_L01_004398C8 */
extern void func_0038D080_004398C8(void *, long);
extern void func_003C97F0_004398C8(void *, s32, u32);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CF00(void *, void *);

void func_L01_004398C8(u8 *a, s32 idx, u8 *out) {
    struct {
        vu0_v4 v0, v1, t;
    } w;
    u8 *tbl;
    u8 *e;
    s32 c;
    s32 hi;
    vu0_q qa, qb, qr;

    tbl = *(u8 **)(a + 0x24);
    e = tbl + (tbl[0x2C] << 4);
    e += (idx << 4) + 0x40;
    c = *(s16 *)(e + 6);
    hi = *(s16 *)(e + 0xE);
    if (c < hi) {
        c = hi;
    }
    if (c >= 0) {
        func_003C97F0_004398C8(a, c + 1, 0x80000000);
    }
    func_0038D080_004398C8(&w.v0, *(long *)e);
    func_0038D080_004398C8(&w.v1, *(long *)(e + 8));
    w.v0.w = 1.0f;
    w.v1.w = 1.0f;
    if (c >= 0) {
        func_0038D028(&w.v0, &w.v0, (u8 *)0x70000000 + *(s16 *)(e + 6) * 64);
        func_0038D028(&w.v1, &w.v1, (u8 *)0x70000000 + *(s16 *)(e + 0xE) * 64);
    }
    func_0038CE20(&w.v0, &w.v0, *(f32 *)(a + 0x2C) * 0.0009765625f);
    func_0038CE20(&w.v1, &w.v1, *(f32 *)(a + 0x2C) * 0.0009765625f);
    func_0038D000(&w.v0, &w.v0, a + 0xC0);
    func_0038D000(&w.v1, &w.v1, a + 0xC0);
    /* One VU0 sequence: the position is loaded once, copied to w.t and added to w.v0. The block
     * writes w.v0 and w.t, so the whole of w is its one output (a second output operand copies the
     * input vector into another SET and adds a count to the position pointer); the two "m" inputs
     * only print the offsets. */
    __asm__(
        "lqc2 $vf1, %1\n\t"
        "lqc2 $vf2, %3\n\t"
        "sqc2 $vf2, %2\n\t"
        "vadd.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %1"
        : "+m"(w) : "m"(w.v0), "m"(w.t), "m"(*(vu0_v4 *)(a + 0x10)) : "vf1", "vf2");
    /* w.v1 += w.t: cc1 emits the lqc2/sqc2 of the "j" quantities itself (memory-unit insns) */
    qa = *(vu0_q *)&w.v1;
    qb = *(vu0_q *)&w.t;
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    *(vu0_q *)&w.v1 = qr;
    vec_add_ab(out, &w.v0, &w.v1);
    func_0038CE20(out, out, 0.5f);
    *(f32 *)(out + 0xC) = func_0038CF00(out, &w.v0);
}
/* localdecomp:end func_L01_004398C8 */

/* localdecomp:start func_L01_00439A68 */
s32 func_L01_00439A68(u8 *a0, u8 *a1) {
    u8 *t = *(u8 **)(a0 + 36);
    s16 n = *(s16 *)(t + 46);
    u8 *p;
    if (n == 0) {
        return 0;
    }
    p = a1 + ((u32)t + (n << 4));
    return p[1] != 0xff;
}
/* localdecomp:end func_L01_00439A68 */

/* localdecomp:start func_L01_00439A98 */
#include "vu0.h"
extern void func_0038CE50(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D080(void *, long);
extern void func_0038CE20(void *, void *, f32);
s32 func_L01_00439A98(u8 *m, vu0_v4 *out, vu0_v4 *arr, s32 idx) {
    u8 *c = *(u8 **)(m + 0x24);
    s32 n = *(s16 *)(c + 0x2E);
    u8 *t;
    u8 *e;
    u8 *k;
    s32 cnt, i;
    vu0_v4 *p;
    if (n == 0) return 0;
    t = c + (n << 4);
    e = (u8 *)(idx + (s32)t);
    if (e[1] == 0xFF) return 0;
    k = t + (e[1] << 4);
    func_0038CE50(out, k, *(f32 *)(m + 0x2C) * (1.0f / 1024.0f));
    k += 0x10;
    func_0038D000(out, out, m + 0xC0);
    vec_add_ab(out, out, m + 0x10);
    cnt = *(s16 *)(k + 6);
    if (arr != 0 && cnt > 0) {
        p = arr;
        i = cnt;
        do {
            i--;
            func_0038D080(p, *(long *)k);
            k += 8;
            func_0038CE20(p, p, *(f32 *)(m + 0x2C) * (1.0f / 1024.0f));
            p->w = 1.0f;
            p++;
        } while (i);
    }
    return cnt;
}
/* localdecomp:end func_L01_00439A98 */

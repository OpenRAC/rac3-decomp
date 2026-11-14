#include "common.h"

/* localdecomp:start func_L21_00338DF8 */
extern u16 *D_L21_0021B860[];
extern u8 *D_L21_001DED9C;
__asm__(".extern D_L21_001DED9C, 16");
extern s32 D_L21_001DEDD8;
extern s32 D_L21_001E065C;
__asm__(".extern D_L21_001E065C, 4");
extern s32 D_L21_001E0658;
__asm__(".extern D_L21_001E0658, 4");
extern s32 func_L21_003AB490(void *arg0);
extern s32 func_00382468(s32);
extern void func_L21_003AB440(void *arg0, s32 arg1);
extern void func_L03_003B1998(s32 a0);

/* Walks the moby group (vars +0x34), lists the members func_L21_003AB490 rejects, and
   when the moby's byte +0x20 changes from a value other than 0 and 1 runs
   func_L21_003AB440 on a random half of them; then, when the listed share is above the
   ratio in the vars of entity (vars +0x24), func_L03_003B1998 on one of them at random. */
void func_L21_00338DF8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *o;
    u16 *p;
    u8 *e;
    s32 list[0x34];
    s32 i;
    s32 n;
    s32 k;
    s32 c;
    s32 t;
    s32 flag;

    i = 0;
    n = 0;
    o = *(u8 **)(D_L21_001DED9C + (*(s32 *)(s + 0x24) << 8) + 0x68);
    p = D_L21_0021B860[*(s32 *)(s + 0x34)];
    while ((*(s32 *)(s + 0x34) & 0xFF) != 0xFF && *(s32 *)(s + 0x34) <= D_L21_001DEDD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L21_0021B860[*(s32 *)(s + 0x34)])) {
        e = D_L21_001DED9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (func_L21_003AB490(e) == 0) {
            list[n++] = i;
        }
        i++;
        p++;
    }
    if (n == 0) {
        return;
    }
    flag = 0;
    if (D_L21_001E065C == 0) {
        D_L21_001E0658 = a0[0x20];
        D_L21_001E065C = 1;
    }
    c = a0[0x20];
    t = D_L21_001E0658;
    if (c != t) {
        flag = t != 0;
        if (t == 1) {
            flag = 0;
        }
    }
    D_L21_001E0658 = c;
    if (flag) {
        for (k = 0; k < n; k++) {
            if (func_00382468(2) == 0) {
                u16 *row = D_L21_0021B860[*(s32 *)(s + 0x34)] + list[k];
                e = D_L21_001DED9C + ((*row & 0x7FFF) << 8);
                func_L21_003AB440(e, func_00382468(5));
            }
        }
    }
    if (*(f32 *)(o + 0x30) / *(s16 *)(o + 0x34) < (f32)n / (f32)i) {
        u16 *row;
        s32 *q;
        q = &list[func_00382468(n)];
        row = D_L21_0021B860[*(s32 *)(s + 0x34)] + *q;
        e = D_L21_001DED9C + ((*row & 0x7FFF) << 8);
        func_L03_003B1998((s32)e);
    }
}
/* localdecomp:end func_L21_00338DF8 */

/* localdecomp:start func_L21_00339088 */
extern s16 *D_L21_0021B860[];
extern u8 *D_L21_001DED9C;
__asm__(".extern D_L21_001DED9C, 16");
extern s32 D_L21_001DEDD8;
extern void func_L02_003A02D8(u8 *, s32);

void func_L21_00339088(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);
    s16 *p = D_L21_0021B860[*(s32 *)(s + 0x3C)];
    u8 *o;
    s32 i;

    while (i = *(s32 *)(s + 0x3C), (u8)i != 0xFF && i <= D_L21_001DEDD8 && p != 0 && (p[-1] >= 0 || p == D_L21_0021B860[i])) {
        o = D_L21_001DED9C + ((*(u16 *)p & 0x7FFF) << 8);
        if (o == 0) {
            break;
        }
        func_L02_003A02D8(o, 0);
        p++;
    }
}
/* localdecomp:end func_L21_00339088 */

/* localdecomp:start func_L21_00339148 */
extern void func_L01_003E8BD0(s32, s32, f32, f32);
extern void func_L01_003E8D48(s32, f32);

void func_L21_00339148(void) {
    func_L01_003E8BD0(0, 0, 7.0f, 0.003f);
    func_L01_003E8D48(0, 0.34906584f);
}
/* localdecomp:end func_L21_00339148 */

/* localdecomp:start func_L21_00339190 */
typedef int u128_00339190 __attribute__((mode(TI)));
extern u8 D_L21_001DCF40;
__asm__(".extern D_L21_001DCF40, 4");
extern f32 func_0038CF38(void *, void *);
extern s32 func_L05_0043F7E0(void *, void *, void *, void *, void *, void *, void *, f32);

/* func_L05_0043F7E0 takes a float (in $f12) after its seven pointers: retail loads the
   9.0f of the range test straight into $f12 because the same value is that argument. */
void func_L21_00339190(u8 *a0, f32 *target, s32 trace) {
    u8 *pos = a0 + 0x10;
    f32 hit[4] __attribute__((aligned(16)));
    f32 out[4] __attribute__((aligned(16)));
    f32 a;
    f32 b;

    if (func_0038CF38(pos, &D_L21_001DCF40) < 9.0f) {
        return;
    }
    if (trace == 0) {
        *(u128_00339190 *)(a0 + 0x10) = *(u128_00339190 *)target;
        return;
    }
    if (func_L05_0043F7E0(hit, out, &a, &b, &D_L21_001DCF40, pos, &D_L21_001DCF40, 9.0f) != 1) {
        return;
    }
    out[2] = target[2];
    *(u128_00339190 *)(a0 + 0x10) = *(u128_00339190 *)out;
}
/* localdecomp:end func_L21_00339190 */

/* localdecomp:start func_L21_00339248 */
s32 func_L21_00339248(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x20)) == 6;
}
/* localdecomp:end func_L21_00339248 */

/* localdecomp:start func_L21_00339258 */
extern void func_L01_00445170(u8 *a, u8 v);

s32 func_L21_00339258(u8 *moby, s32 idx, s32 force) {
    u8 *vars;
    s32 *p;
    s32 bit;

    if (moby == 0) {
        return 0;
    }
    vars = *(u8 **)(moby + 0x68);
    if (moby[0x95] != 0 || idx == -1) {
        *(s32 *)(vars + 0xCC) = -1;
        return 0;
    }
    p = (s32 *)(vars + 0x80);
    p += idx;
    bit = idx << 1;
    if (force != 0 || !(*(s32 *)(vars + 0x1C) & bit)) {
        *(s32 *)(vars + 0xCC) = *p;
        *(s32 *)(vars + 0x1C) |= bit;
        func_L01_00445170(moby, 1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L21_00339258 */

/* localdecomp:start func_L21_003392E0 */
typedef struct {
    u8 pad0[0x24];
    s32 i24;
    u8 pad28[0x6C - 0x28];
    s32 i6C;
    u8 pad70[6];
    s16 h76;
    u8 pad78[0x94 - 0x78];
    s32 i94;
    s16 h98;
    u8 pad9A[4];
    s16 h9E;
} G_003392E0;
extern G_003392E0 D_001CCFD0;
extern void func_L01_00445170(u8 *a, u8 v);

s32 func_L21_003392E0(u8 *moby) {
    u8 *vars;
    u16 *h;

    if (moby == 0) {
        return 0;
    }
    vars = *(u8 **)(moby + 0x68);
    if (moby[0x95] != 0) {
        if (D_001CCFD0.i6C != 0 || D_001CCFD0.i24 != -1 || D_001CCFD0.i94 != 0 ||
            (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58)) {
            h = (u16 *)&D_001CCFD0;
            if ((u16)(h[0x76 / 2] - 6) >= 2) h[0x76 / 2] = 5;
            if ((u16)(h[0x9E / 2] - 6) >= 2) h[0x9E / 2] = 5;
        }
        *(s32 *)(vars + 0xCC) = -1;
        func_L01_00445170(moby, 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L21_003392E0 */

/* localdecomp:start func_L21_003393C0 */
/* Whether the moby is set up (vars +0xCC is not -1) and its busy byte (+0x95) is clear.
   Same shape as func_L01_00335EF8: a 64-bit `long` result that the int comparison is
   widened into with a register copy. */
long func_L21_003393C0(u8 *moby) {
    long r;

    if (moby == 0) {
        return 0;
    }
    r = 0;
    if (*(s32 *)(*(u8 **)(moby + 0x68) + 0xCC) != -1) {
        s32 clear = moby[0x95] == 0;
        r = clear;
    }
    return r;
}
/* localdecomp:end func_L21_003393C0 */

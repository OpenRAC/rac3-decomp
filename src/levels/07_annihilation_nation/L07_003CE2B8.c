#include "common.h"

/* declared by functions of L07_003CDE48.c, which this file was cut from */
extern int func_L07_003CE2B8(int n);

/* localdecomp:start func_L07_003CE2B8 */
extern int D_001A71A0[];
extern int D_L07_001ECC80_003CE2B8[];

int func_L07_003CE2B8(int n) {
    int i;
    int *p;
    int v;
    i = 0;
    if (n > 0) {
        v = D_001A71A0[0];
        p = D_L07_001ECC80_003CE2B8;
        for (; ; ) {
            if (*p == v) return 1;
            i++;
            if (i >= n) break;
            p++;
        }
    }
    return 0;
}
/* localdecomp:end func_L07_003CE2B8 */

/* localdecomp:start func_L07_003CE2F8 */
void func_0038CF38(void *, s32);

void func_L07_003CE2F8(void *arg0) {
    func_0038CF38(arg0 + 0x10, (*(s32 *)((u8 *)arg0 + 0x68)) + 0x130);
}
/* localdecomp:end func_L07_003CE2F8 */

/* localdecomp:start func_L07_003CE320 */
void func_L07_003CE320(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    p[0x408] = 0;
    p[0x409] = 0;
}
/* localdecomp:end func_L07_003CE320 */

/* localdecomp:start func_L07_003CE330 */
typedef int Q_3CE330 __attribute__((mode(TI)));

static __inline__ void copy_3CE330(Q_3CE330 *d, Q_3CE330 *s) {
    *d = *s;
}

typedef struct {
    u8 pad0[0x2C0];
    Q_3CE330 a[10];
    Q_3CE330 b[10];
    u8 pad400[0x8];
    u8 head;
    u8 count;
} S_3CE330;

void func_L07_003CE330(u8 *arg0, Q_3CE330 *arg1, Q_3CE330 *arg2) {
    S_3CE330 *s = *(S_3CE330 **)(arg0 + 0x68);
    int i;

    s->count++;
    if (s->count > 10) {
        s->head = (s->head + 1) % 10;
        s->count = 10;
    }
    i = (s->head + s->count - 1) % 10;
    copy_3CE330(&s->a[i], arg1);
    copy_3CE330(&s->b[i], arg2);
}
/* localdecomp:end func_L07_003CE330 */

/* localdecomp:start func_L07_003CE3A8 */
typedef int Q_3CE3A8 __attribute__((mode(TI)));
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, u32, u32, u32, u32, f32);
extern void func_L07_003CE330(u8 *, Q_3CE3A8 *, Q_3CE3A8 *);
extern s32 func_L07_003CECD0(s32, s32);
extern void func_L07_003CE618(void *, void *, s32, s32, s32, u32, u32);

static __inline__ u32 pack_3CE3A8(s32 red, s32 blue, u32 alpha) {
    u32 c = (blue << 8) | alpha;
    return (blue << 16) | c | red;
}

void func_L07_003CE3A8(u8 *obj) {
    Q_3CE3A8 a, b;
    u8 *s = *(u8 **)(obj + 0x68);
    f32 width, thin, fine;
    u32 col, other;
    s32 r, g, bl;

    if (*(u16 *)(obj + 0x34) & 1) return;
    width = 0.75f;
    func_003C2F58(obj, 0, &a);
    thin = 0.08f;
    func_003C2F58(obj, 1, &b);
    fine = 0.025f;
    col = pack_3CE3A8(s[0x41D], s[0x41F], 0x7F000000);
    func_L01_0040A8C0(&a, &b, 14, 1, thin, width, col, col, col, col, *(f32 *)(s + 0x400));
    func_L01_0040A8C0(&a, &b, 14, 1, fine, width, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, *(f32 *)(s + 0x400));
    if (s[0x407]) {
        func_L07_003CE330(obj, &a, &b);
        other = pack_3CE3A8(s[0x41D], s[0x41F], 0x40000000);
        r = func_L07_003CECD0(s[0x41D], 128);
        g = func_L07_003CECD0(s[0x41E], 128);
        bl = func_L07_003CECD0(s[0x41F], 128);
        func_L07_003CE618(s + 0x2C0, s + 0x360, s[0x409], s[0x408], s[0x40A] + 100, other, (bl << 16) | (g << 8) | r);
    }
    func_003C2F58(obj, 2, &a);
    func_003C2F58(obj, 3, &b);
    func_L01_0040A8C0(&a, &b, 14, 1, thin, width, col, col, col, col, *(f32 *)(s + 0x400));
    func_L01_0040A8C0(&a, &b, 14, 1, fine, width, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, *(f32 *)(s + 0x400));
}
/* localdecomp:end func_L07_003CE3A8 */

INCLUDE_ASM("asm/levels", func_L07_003CE618);

/* localdecomp:start func_L07_003CE858 */
extern u16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern s32 D_L07_001DF458;

s32 func_L07_003CE858(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 v = *(s32 *)(s + 0x418);
    s32 t;
    s32 best;
    u16 *p;
    u8 *e;

    if (v != -1) return v;
    best = -1;
    p = D_L07_0021C020[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L07_001DF458 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L07_0021C020[a0[0x21]])) {
        e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (e != a0 && *(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA) && e[0x20] != 1) {
            t = *(s32 *)(s + 0x418);
            if (best < t) best = t;
        }
        p++;
    }
    return best + 1;
}
/* localdecomp:end func_L07_003CE858 */

/* localdecomp:start func_L07_003CE940 */
extern u16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern s32 D_L07_001DF458;

void func_L07_003CE940(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 v = *(s32 *)(s + 0x418);
    s32 t;
    u16 *p;
    u8 *e;
    if (v == -1) return;
    p = D_L07_0021C020[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L07_001DF458 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L07_0021C020[a0[0x21]])) {
        e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (e != a0 && *(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA) && e[0x20] != 1) {
            t = *(s32 *)(s + 0x418);
            if (t != -1 && t >= v) *(s32 *)(s + 0x418) = t - 1;
        }
        p++;
    }
    *(s32 *)(s + 0x418) = -1;
}
/* localdecomp:end func_L07_003CE940 */

/* localdecomp:start func_L07_003CEA38 */
s32 func_L07_003CEA38(void *arg0) {
    s32 temp_v0;

    temp_v0 = *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x418);
    if (temp_v0 == -1) {
        return 0;
    }
    return temp_v0 < 1;
}
/* localdecomp:end func_L07_003CEA38 */

/* localdecomp:start func_L07_003CEA60 */
extern u16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern s32 D_L07_001DF458;
void func_L07_003CEA60(u8 *obj)
{
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L07_003BB328(f32);
    extern f32 func_0038DAB8(f32, f32);
    u8 *s = *(u8 **)(obj + 0x68);
    u16 *p;
    u8 *e;
    f32 first = 100.0f, second = 100.0f;
    f32 angle, delta, a, b;
    *(f32 *)(s + 0x414) = func_0038D160(*(f32 *)(obj+0x10)-*(f32 *)(s+0x130), *(f32 *)(obj+0x14)-*(f32 *)(s+0x134));
    angle = func_L07_003BB328(*(f32 *)(s+0x414));
    if (obj[0x21] != 0xFF) {
        p = D_L07_0021C020[obj[0x21]];
        while (obj[0x21] != 0xFF && obj[0x21] <= D_L07_001DF458 && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L07_0021C020[obj[0x21]])) {
            e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
            if (e == 0) break;
            if (e != obj && *(s16 *)(e+0xAA) == *(s16 *)(obj+0xAA) && e[0x20] != 1) {
                delta = angle - func_L07_003BB328(*(f32 *)(*(u8 **)(e+0x68)+0x414));
                a = func_L07_003BB328(delta);
                b = func_L07_003BB328(-delta);
                if (a < first) first = a;
                if (b < second) second = b;
            }
            p++;
        }
        if (first > 10.0f) *(f32 *)(s+0x410) = *(f32 *)(s+0x414);
        else *(f32 *)(s+0x410) = func_0038DAB8(*(f32 *)(s+0x414), (second-first)*0.5f);
    } else *(f32 *)(s+0x410) = *(f32 *)(s+0x414);
}
/* localdecomp:end func_L07_003CEA60 */

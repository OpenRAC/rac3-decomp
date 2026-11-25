#include "common.h"

typedef struct { u8 pad[0x10]; f32 x; f32 y; } M_4574A0;
typedef struct {
    u8 pad[0xDC];
    f32 fDC;
    s16 hE0;
    s16 hE2;
    s16 hE4;
} S_4574A0;
typedef struct { u8 pad[16]; u8 sub[248 - 16]; f32 f; } S457;
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_0045BD10 */
extern void func_L01_00448890(char *a0, char *a1, int a2, float f12, float f13,
                          float f14, float f15);

/* from rac2-decomp's func_L01_00322288, renamed */
int func_L01_0045BD10(int a0, float f12) {
    char *p = func_L01_0045B958(a0);
    if (p == 0)
        return 0;
    func_L01_00448890((char *)a0 + 0xF8, p + 0xB4, 0, f12, *(float *)(p + 0x14),
                  *(float *)(p + 0x18), *(float *)(p + 0x1C));
    return 1;
}
/* localdecomp:end func_L01_0045BD10 */

LINKER_REMNANT("asm/levels", func_L01_0045BD70);

/* localdecomp:start func_L01_0045BD78 */
extern S_4574A0 *func_L01_0045B958(M_4574A0 *);
void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d)
{
    u8 *p = ((u8 * (*)(u8 *a0))func_L01_0045B958)(a0);

    if (p != 0) {
        *(f32 *)(p + 32) = a;
        *(f32 *)(p + 36) = a;
        *(f32 *)(p + 40) = b;
        *(f32 *)(p + 20) = c;
        *(f32 *)(p + 24) = c;
        *(f32 *)(p + 28) = d;
    }
}
/* localdecomp:end func_L01_0045BD78 */

LINKER_REMNANT("asm/levels", func_L01_0045BDE0);

/* localdecomp:start func_L01_0045BDE8 */
extern s32 D_L01_0021F6C0[];
extern s32 func_L01_0045BE38_0045BDE8(void *a0, s32 a1);
s32 func_L01_0045BDE8(void *a0, s32 a1) {
    s32 v;
    if (a1 == -1) return 0;
    v = D_L01_0021F6C0[a1];
    if (v == 0) return 0;
    return func_L01_0045BE38_0045BDE8(a0, v);
}
/* localdecomp:end func_L01_0045BDE8 */

/* localdecomp:start func_L01_0045BE38 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } V4;
typedef struct { s32 n; s32 pad[3]; V4 p[1]; } PathT;
typedef struct { u8 pad[0x34]; f32 rad; u32 flags; u8 pad2[0x9C - 0x3C]; s32 f9C; u8 pad3[0xC4 - 0xA0]; PathT *path; s16 cur; s16 dst; f32 fCC; } NavT;
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(f32 *, f32 *, f32);
extern s32 func_L01_0045A748(void *, void *);
extern void func_L01_0045C150_0045BE38(void *, void *, s32, s32);
s32 func_L01_0045BE38(void *a0, s32 a1) {
    u8 *self = (u8 *)a0;
    V4 *path = (V4 *)a1;
    V4 w __attribute__((aligned(16)));
    V4 v __attribute__((aligned(16)));
    V4 *e;
    f32 lim, dist, thr, dotv;
    s32 i, j;
    NavT *s = (NavT *)func_L01_0045B958((M_4574A0 *)self);
    if (s == 0) {
        return 0;
    }
    if (path != s->path || (s->f9C & 4) != 0) {
        func_L01_0045C150_0045BE38(self, path, -1, 0);
    }
    i = s->cur;
    j = s->dst;
    if (i == j) {
        func_L01_0045A748(self, &path[i + 1]);
        if (s->fCC <= s->rad) {
            return 1;
        }
    } else {
        if (j < i) {
            if (i < *(s32 *)path - 1) {
                vec_sub_ba(&v, &path[i + 1], &path[i + 2]);
            } else {
                vec_sub_ba(&v, &path[i + 1], self + 16);
            }
        } else {
            if (i > 0) {
                vec_sub_ba(&v, &path[i + 1], &path[i]);
            } else {
                vec_sub_ba(&v, &path[i + 1], self + 16);
            }
        }
        if (s->flags & 0x400) {
            func_0038CF68(&v.x, &v.x, 1.0f);
            thr = func_0038CE68(&v, &path[s->cur + 1]) - s->rad;
            dist = func_0038CF00(self + 16, &path[s->dst + 1]);
        } else {
            v.z = 0.0f;
            func_0038CF68(&v.x, &v.x, 1.0f);
            e = &path[s->cur];
            thr = (v.x * e[1].x + v.y * e[1].y) - s->rad;
            dist = func_0038CF38(self + 16, &path[s->dst + 1]);
        }
        lim = s->rad * 10.0f + 1.0f;
        if (dist < lim) {
            lim = dist;
        }
        vec_sub_ba(&w, &path[s->cur + 1], self + 16);
        if ((s->flags & 0x400) == 0) {
            w.z = 0.0f;
        }
        func_0038CF68(&w.x, &w.x, lim);
        vec_add_ab(&w, &w, self + 16);
        func_L01_0045A748(self, &w);
        if (s->flags & 0x400) {
            dotv = func_0038CE68(&v, self + 16);
        } else {
            dotv = v.x * ((V4 *)(self + 16))->x + v.y * ((V4 *)(self + 16))->y;
        }
        if (thr <= dotv) {
            if (s->cur > s->dst) {
                s->cur--;
            } else {
                s->cur++;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0045BE38 */

LINKER_REMNANT("asm/levels", func_L01_0045C148);

/* localdecomp:start func_L01_0045C150 */
extern S_4574A0 *func_L01_0045B958(M_4574A0 *);
s32 func_L01_0045C150(void *a0, u16 *a1, s32 a2, s32 a3) {
    u8 *p;

    p = ((u8 * (*)(void *))func_L01_0045B958)(a0);
    if (p == 0) {
        return 0;
    }
    *(u16 **)(p + 196) = a1;
    *(s32 *)(p + 156) &= ~4;
    if (a2 == -1) {
        *(s16 *)(p + 202) = *a1 - 1;
    } else {
        *(s16 *)(p + 202) = a2;
    }
    *(s16 *)(p + 200) = a3;
    return 1;
}
/* localdecomp:end func_L01_0045C150 */

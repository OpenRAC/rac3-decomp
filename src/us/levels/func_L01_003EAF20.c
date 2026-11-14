#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_003ECDD0 (src/levels/shared/L01_003EB9C8.c).
 * Camera-path measuring init: the three path loops are written as the retail compiles them (i << 4 byte
 * offsets keep `path` the first addu operand, no `if (n > 0)` wrapper: the for pre-test is the only test,
 * p->a60[cnt] and p->a80[cnt] let gcc reduce only the a60 pointer, one store of t in the h3A arm keeps q in $s4). */

/* localdecomp:start func_L01_003EAF20 */
typedef int u128_3EAF20 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 d;
} Pt_3EAF20;
typedef struct {
    s32 n;
    u8 pad4[0xC];
    Pt_3EAF20 pt[1];
} Path_3EAF20;
typedef struct {
    u8 pad0[0x20];
    s32 w20;
    s32 w24;
    u8 pad28[0x38 - 0x28];
    u8 b38;
    u8 pad39;
    s16 h3A;
    f32 f3C;
    u8 pad40[1];
    u8 b41;
    u8 pad42[2];
    u8 b44;
    u8 pad45;
    s16 h46;
    s32 w48;
    u8 pad4C[0x60 - 0x4C];
    f32 a60[8];
    s32 a80[8];
} Info_3EAF20;
typedef struct {
    s32 w0;
    s32 w4;
    f32 f8;
    f32 fC;
    s32 w10;
    s16 h14;
    s16 h16;
} Q_3EAF20;
typedef struct {
    u8 pad0[0x70];
    u8 *p70;
    u8 pad74[0x84 - 0x74];
    s16 h84;
    u8 pad86[0x94 - 0x86];
    s32 w94;
} Obj_3EAF20;
typedef struct {
    u8 pad0[0x54];
    u8 *p54;
    u8 pad58[0x460 - 0x58];
} Ent_3EAF20;
typedef struct {
    u8 pad0[0xB0];
    f32 fB0;
} G_3EAF20;

extern char *D_L01_001DF884;
extern Path_3EAF20 *D_L01_0021F740[];
extern Ent_3EAF20 D_L01_001E2AC0[];
extern G_3EAF20 D_L01_001E7600;
extern u8 D_L01_001D667B_003EAF20;
extern f32 func_00388A28(f32, f32);
extern f32 func_003887C8(void *, void *);
extern void func_L01_004FC518(s32, s32);

void func_L01_003EAF20(Obj_3EAF20 *obj)
{
    Info_3EAF20 *p;
    Q_3EAF20 *q;
    Path_3EAF20 *path;
    Path_3EAF20 *path2;
    s32 i;
    s32 j;
    s32 k;
    s32 cnt;
    u16 t;
    u16 x;
    s32 v;
    f32 d;
    f32 f;
    u8 *b;

    p = *(Info_3EAF20 **)(D_L01_001DF884 + obj->h84 * 32 + 28);
    p->b38 = 1;
    q = (Q_3EAF20 *)(obj->p70 + 0x40);
    q->w0 = 0;
    q->w4 = 0;
    q->f8 = 0;
    q->fC = 0;
    q->w10 = 0;
    q->h14 = 0;
    if (p->w48 != 0 || p->h46 != -1) {
        x = *(u16 *)((u8 *)p + 0x46);
        if (p->h46 == -1 || p->w48 < p->h46) {
            t = *(u16 *)((u8 *)p + 0x48);
        } else {
            t = x;
        }
        q->h16 = t;
    } else {
        t = p->h3A;
        q->h16 = t;
    }
    b = obj->p70 + 0x58;
    for (j = 0; j < 8; j++) {
        p->a60[j] = 0;
        p->a80[j] = -1;
    }
    cnt = 0;
    f = func_00388A28(1.0f, D_L01_001E7600.fB0);
    *(f32 *)(b + 0x30) = f + f;
    if (p->b44 == 0) {
        if (p->w20 >= 0) {
            path = D_L01_0021F740[p->w20];
            for (i = 0; i < path->n; i++) {
                f = *(f32 *)((u8 *)path + (i << 4) + 0x1C);
                if (f > 0.0f) {
                    p->a60[cnt] = f;
                    if (f > 180.0f) {
                        p->a60[cnt] = *(f32 *)(b + 0x30) * 57.295776f;
                    }
                    p->a80[cnt] = i;
                    cnt++;
                }
                d = func_003887C8(&path->pt[i], &path->pt[(i + 1) % path->n]);
                *(f32 *)((u8 *)path + (i << 4) + 0x1C) = d;
                if (i < path->n - 1) {
                    q->f8 += d;
                }
            }
        }
        D_L01_001D667B_003EAF20 = 1;
    }
    v = p->h3A;
    if (v > 0) {
        p->f3C = q->f8 / (f32)v * 60.0f;
    }
    if (p->w24 >= 0) {
        path2 = D_L01_0021F740[p->w24];
        for (k = 0; k < path2->n; k++) {
            d = func_003887C8(&path2->pt[k], &path2->pt[(k + 1) % path2->n]);
            *(f32 *)((u8 *)path2 + (k << 4) + 0x1C) = d;
            if (k < path2->n - 1) {
                q->fC += d;
            }
        }
    }
    {
        u8 *s = obj->p70;

        qzero(s + 0x10);
        *(f32 *)s = 0.03f;
        *(f32 *)(s + 4) = 0.2f;
    }
    {
        u8 *s = obj->p70;

        qzero(s + 0x30);
        *(f32 *)(s + 0x24) = 0.2f;
        *(f32 *)(s + 0x20) = 0.03f;
    }
    {
        Ent_3EAF20 *e = &D_L01_001E2AC0[obj->w94];

        *(u128_3EAF20 *)((u8 *)obj + 0x30) = *(u128_3EAF20 *)(e->p54 + 0x30);
        *(u128_3EAF20 *)((u8 *)obj + 0x00) = *(u128_3EAF20 *)(e->p54 + 0x00);
        *(u128_3EAF20 *)((u8 *)obj + 0x10) = *(u128_3EAF20 *)(e->p54 + 0x10);
        *(u128_3EAF20 *)((u8 *)obj + 0x20) = *(u128_3EAF20 *)(e->p54 + 0x20);
    }
    if (p->b41 == 0) {
        func_L01_004FC518(0x74, 1);
    }
    p->b44 = 1;
}
/* localdecomp:end func_L01_003EAF20 */

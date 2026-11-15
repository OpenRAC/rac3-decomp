#include "common.h"

typedef struct S_Foo_0032D228 {
    u8 pad0[0xF2];
    u16 f2;
    u8 f4;
    u8 pad1[0x108 - 0xF5];
    s32 f108;
} S_Foo_0032D228;

typedef struct S_0032D598 {
    u8 pad[0xB4];
    s32 cnt[16];
} S_0032D598;

typedef struct { u8 pad0[0x30]; u8 b30[0x40]; u8 b70[0x10]; } Ent_32CF78;
typedef struct { u8 pad0[0x68]; struct { u8 pad[0xD0]; s32 idx; } *p68; } Obj_32CF78;

/* localdecomp:start func_L03_0032D598 */
void *func_L03_0032F6A8();

s32 func_L03_0032D598(void *arg0, u8 *arg1) {
    S_0032D598 *tbl;
    s32 idx;

    arg1 = func_L03_0032F6A8(arg1);
    if (arg1[0x1C] == 1 || arg1[0x1C] == 3) {
        return 1;
    }
    if (arg0 != 0) {
        if (*(s16 *)((u8 *)arg0 + 0xAA) == 0x1936) {
            tbl = *(S_0032D598 **)((u8 *)arg0 + 0x68);
            idx = arg1[0x1D];
            if (tbl->cnt[idx] > 0) {
                goto body;
            }
        }
    }
    return 0;
body:
    arg1[0x1C] = 1;
    {
        s32 j = arg1[0x1D];
        tbl->cnt[j] = tbl->cnt[j] - 1;
    }
    return 1;
}
/* localdecomp:end func_L03_0032D598 */

/* localdecomp:start func_L03_0032D640 */
typedef struct S_0032D640 {
    u8 pad[0xB4];
    s32 cnt[16];
} S_0032D640;

void *func_L03_0032F6A8();

void func_L03_0032D640(void *arg0, void *arg1) {
    u8 *p;
    if (arg0 != 0) {
        if (*(s16 *)((u8 *)arg0 + 0xAA) == 0x1936) {
            p = func_L03_0032F6A8(arg1);
            if (p[0x1C] != 1) {
                p[0x1C] = 0;
            } else {
                S_0032D640 *tbl = *(S_0032D640 **)((u8 *)arg0 + 0x68);
                tbl->cnt[p[0x1D]]++;
                p[0x1C] = 0;
            }
        }
    }
}
/* localdecomp:end func_L03_0032D640 */

/* localdecomp:start func_L03_0032D6B8 */
typedef struct S_0032D6B8 {
    char pad0[0xC];
    struct S_0032D6B8 *tgt;
    f32 f10;
    f32 f14;
    char pad1[0x1C - 0x18];
    u8 t1C;
} S_0032D6B8;
typedef struct S_0032D6B8b {
    char pad0[0x10];
    f32 f10;
    f32 f14;
    char pad1[0x21 - 0x18];
    u8 idx;
    char pad2[0xAA - 0x22];
    short hAA;
} S_0032D6B8b;
extern int D_L03_0021C620_0032D6B8[];
extern char *D_L03_001DF99C_0032D6B8;
__asm__(".extern D_L03_001DF99C_0032D6B8, 16");
extern int D_001DF9D8_sda;
__asm__(".extern D_001DF9D8_sda, 4");
S_0032D6B8 *func_L03_0032F6A8_func_L03_0032D6B8();
f32 func_L03_0032FB70(f32 a);
f32 func_0038D160(f32 a, f32 b);
f32 func_0038DAB8(f32 a, f32 b);

void func_L03_0032D6B8(S_0032D6B8b *a) {
    S_0032D6B8 *p;
    S_0032D6B8 *q;
    S_0032D6B8b *buf;
    short *cur;
    f32 mn, mx, base, d, v, w;
    p = func_L03_0032F6A8_func_L03_0032D6B8(a);
    mn = 100.0f;
    mx = mn;
    if (p->tgt != 0) {
        p->f10 = func_0038D160(a->f10 - p->tgt->f10, a->f14 - p->tgt->f14);
        base = func_L03_0032FB70(p->f10);
        if (a->idx == 0xFF) {
            goto same;
        }
        cur = (short *)D_L03_0021C620_0032D6B8[a->idx];
        for (; a->idx != 0xFF && D_001DF9D8_sda >= a->idx && cur != 0 &&
               (cur[-1] >= 0 || cur == (short *)D_L03_0021C620_0032D6B8[a->idx]); cur++) {
            buf = (S_0032D6B8b *)(D_L03_001DF99C_0032D6B8 + ((*(unsigned short *)cur & 0x7FFF) << 8));
            if (buf == 0) break;
            if (buf == a) continue;
            if (buf->hAA != a->hAA) continue;
            q = func_L03_0032F6A8_func_L03_0032D6B8(buf);
            if (p->tgt != q->tgt) continue;
            if (p->t1C != q->t1C) continue;
            d = base - func_L03_0032FB70(q->f10);
            v = func_L03_0032FB70(d);
            w = func_L03_0032FB70(-d);
            if (v < mn) mn = v;
            if (w < mx) mx = w;
        }
        if (10.0f < mn) goto same;
        p->f14 = func_0038DAB8(p->f10, (mx - mn) * 0.5f);
        return;
same:
        p->f14 = p->f10;
    }
}
/* localdecomp:end func_L03_0032D6B8 */

/* localdecomp:start func_L03_0032D8C0 */
extern u16 *D_L03_0021C620[];
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern s32 D_L03_001DF9D8;

s32 func_L03_0032D8C0(u8 *a0) {
    s32 best;
    u16 *p;
    u8 *e;
    u8 *r;

    r = func_L03_0032F6A8(a0);
    if ((u8)(r[0x1C] - 2) < 2) return -1;
    if (*(s16 *)(r + 0x1A) != -1) return *(s16 *)(r + 0x1A);
    best = -1;
    p = D_L03_0021C620[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L03_001DF9D8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L03_0021C620[a0[0x21]])) {
        e = D_L03_001DF99C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (e != a0 && *(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA) && e[0x20] != 1) {
            r = func_L03_0032F6A8(e);
            if (r[0x1C] == 1) {
                s16 v = *(s16 *)(r + 0x1A);
                if (best < v) best = v;
            }
        }
        p++;
    }
    return best + 1;
}
/* localdecomp:end func_L03_0032D8C0 */

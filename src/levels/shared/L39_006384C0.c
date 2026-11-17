#include "common.h"

/* localdecomp:start func_L39_006384C0 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_006384C0;
typedef union {
    u8 b[16];
    u32 w[2];
} Buf_006384C0;
typedef struct {
    u8 pad0[0xA0];
    V4_006384C0 fA0;
    u8 padB0[0x120 - 0xB0];
    V4_006384C0 f120;
    u8 pad130[0x2DE - 0x130];
    s16 h2DE;
    u8 pad2E0[0x33A - 0x2E0];
    s16 h33A;
    u8 pad33C[0x377 - 0x33C];
    u8 b377;
    u8 pad378[0x19E4 - 0x378];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x2468 - 0x19E7];
    f32 f2468;
    u8 pad246C[0x2524 - 0x246C];
    s32 f2524;
} G_006384C0;
typedef struct {
    u8 pad0[0x1C];
    s32 f1C;
    u8 pad20[0x20];
    u8 f40[0x10];
} D_0025F740_006384C0;

extern u8 D_L39_004997E0[];
extern D_0025F740_006384C0 D_L39_0025F740;
extern f32 func_L39_006325D8(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L39_00632298(void *, void *, void *, f32);
extern void func_L39_00632888(void *, void *, void *, f32);
extern void func_L39_00632558(void *, void *, void *, f32);
extern void func_L39_00632988(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern f32 func_L39_00632100(void *, void *);
void func_L39_006387D0(u8 *a0, f32 s);

s32 func_L39_006384C0(G_006384C0 *g, f32 a, f32 b) {

    if (func_L39_006325D8(g, &g->f120) == 0.0f) {
        return 0;
    }
    if (g->f2468 > 0.5f) {
        u8 *q = &g->b19E6;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            Buf_006384C0 buf;
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 mm = n + 1;
            u8 *d = buf.b;
            s32 i;
            u32 x, y;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[mm + ((k + i) & 7) * 255];
            }
            x = buf.w[0] ^ (u32)q;
            y = buf.w[1] ^ x;
            buf.w[0] = x;
            buf.w[1] = y;
            r = y;
        }
        if ((r ^ 6) != 0 && g->h33A == 0 && g->b377 == 0) {
            return 0;
        }
    }
    if (g->h2DE != 0) {
        return 0;
    }
    {
    V4_006384C0 v;
    V4_006384C0 w;
    s32 ok;
    {
        u8 *q = &g->b19E4;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            Buf_006384C0 buf;
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 mm = n + 1;
            u8 *d = buf.b;
            s32 i;
            u32 x, y;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[mm + ((k + i) & 7) * 255];
            }
            x = buf.w[0] ^ (u32)q;
            y = buf.w[1] ^ x;
            buf.w[0] = x;
            buf.w[1] = y;
            r = y;
        }
        if ((r ^ 0x1F) == 0) {
            a = 2.0f;
        }
    }
    func_0038CE20(&v, &g->f120, a);
    if (0.0f < b && func_L39_006325D8(g, &v) < b) {
        func_L39_00632298(g, &v, &v, 0.0f);
        func_L39_00632888(g, &v, &v, b);
    }
    func_L39_00632558(g, &v, &v, 0.0f);
    ok = 1;
    vec_add_ab(&v, &v, &g->fA0);
    w = v;
    func_L39_00632988(g, &v, &v, 0.3f);
    func_L39_00632988(g, &w, &w, -0.35f);
    if (func_003D3CB0(&v, &w, 4, g->f2524, 0) != 0) {
        D_0025F740_006384C0 *p = &D_L39_0025F740;
        if (p->f1C > 0 && func_L39_00632100(g, p->f40) <= 0.87266463f) {
            ok = 0;
        }
    }
    if (ok == 0) {
        return 0;
    }
    func_L39_006387D0((u8 *)g, 0.0f);
    return 1;
    }
}
/* localdecomp:end func_L39_006384C0 */

#include "common.h"

/* localdecomp:start func_L30_00442950 */
typedef struct {
    s32 a;                         /* 0x00 */
    s32 b;                         /* 0x04 */
    u8 n;                          /* 0x08 */
    u8 state;                      /* 0x09 */
    s16 seed;                      /* 0x0A */
    s32 xC;                        /* 0x0C */
} Sub_00442950;

typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04 */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A */
    u32 end_rgba;                  /* 0x0C */
    u8 pad_10[0x20];
    Sub_00442950 sub;              /* 0x30 */
} P_00442950;

extern u8 *D_L30_0021F278[];
extern P_00442950 *func_L01_004618E0(s32 type);
extern s32 func_00382498(s32, s32);
extern void func_L01_00474968(u8 *a0);

P_00442950 *func_L30_00442950(s32 a, s32 b, s32 n, s32 tex) {
    P_00442950 *p = func_L01_004618E0(0x78);
    Sub_00442950 *s;
    s32 r;
    s32 r2;

    if (p == 0) {
        return 0;
    }
    s = &p->sub;
    p->rgba = 0x80808080;
    p->render2 = 0x22;
    p->end_rgba = 0x80808080;
    p->flags = 3;
    p->texture = D_L30_0021F278[0][tex];
    s->a = a;
    s->b = b;
    p->render = 0x48;
    s->n = n / 4;
    if (s->n == 0) {
        s->n = n / 4 + 1;
    }
    p->life = s->n << 2;
    s->xC = 0;
    r = func_00382498(0, 0x100);
    r2 = func_00382498(0, 0x100);
    s->state = 1;
    s->seed = (r << 8) + r2;
    func_L01_00474968((u8 *)p);
    s->state &= 0xFE;
    return p;
}
/* localdecomp:end func_L30_00442950 */

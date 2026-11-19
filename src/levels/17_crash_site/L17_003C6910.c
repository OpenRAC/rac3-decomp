#include "common.h"
#include "vu0.h"

typedef struct {
    u8 p0[0x20];
    s32 path;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 mode;
    s16 h34;
    u8 p36[6];
    u8 b3C;
} E_3C6910;
typedef struct {
    u8 p0[0x1C];
    E_3C6910 *f1C;
} R_3C6910;
typedef struct {
    f32 x, y, z, w;
} PT_3C6910;
typedef struct {
    s32 count;
    u8 p4[0xC];
    PT_3C6910 pts[1];
} P_3C6910;
typedef struct {
    u8 p0[0x10];
    P_3C6910 *f10;
    u8 p14[0xC];
} T_3C6910;

extern R_3C6910 *D_L17_001DE884;
__asm__(".extern D_L17_001DE884, 16");
extern P_3C6910 *D_L17_0021CD80[];
extern T_3C6910 *D_L17_001DED10;
__asm__(".extern D_L17_001DED10, 16");
extern f32 D_L17_001DE708;
__asm__(".extern D_L17_001DE708, 4");
extern s32 func_L01_00476B98(void *, void *, void *, s32 *, f32 *, s32, f32, f32, f32);

/* localdecomp:start func_L17_003C6910 */
void func_L17_003C6910(u8 *self) {
    E_3C6910 *e = D_L17_001DE884[*(s16 *)(self + 0x84)].f1C;
    u8 *g80, *gE0, *g00, *g30, *g100, *g150;
    u8 *s74;
    P_3C6910 *a, *b, *c, *d;
    s32 i, k, n, j0, j1;
    vu0_v4 out;
    s32 idx;
    f32 t;

    g80 = *(u8 **)(self + 0x70) + 0x80;
    *(s32 *)(g80 + 0x40) = 0;
    if (e->b3C) *(f32 *)(g80 + 0x4C) = D_L17_001DE708; else *(f32 *)(g80 + 0x4C) = 1.5f;
    if (e->mode == 3) *(f32 *)(g80 + 0x4C) = 0.5f;
    s74 = self + 0x74;
    *(f32 *)(g80 + 0x48) = 0.20943952f;
    gE0 = *(u8 **)(self + 0x70) + 0xE0;
    *(f32 *)(gE0 + 0x00) = 6.0f;
    *(f32 *)(gE0 + 0x04) = 0.5f;
    *(f32 *)(gE0 + 0x10) = 2.0f;
    g00 = *(u8 **)(self + 0x70);
    qzero(g00);
    *(f32 *)(g00 + 0x14) = 0.175f;
    *(f32 *)(g00 + 0x20) = 0.0005f;
    *(s32 *)(g00 + 0x18) = 0;
    *(s16 *)(g00 + 0x1C) = 0;
    *(s32 *)(g00 + 0x24) = 0;
    *(f32 *)(g00 + 0x10) = 0.01f;
    g30 = *(u8 **)(self + 0x70) + 0x30;
    *(f32 *)(g30 + 0x24) = 0.3f;
    *(f32 *)(g30 + 0x20) = 0.01f;
    *(f32 *)(g30 + 0x28) = 0.2f;
    *(s16 *)(g30 + 0x2C) = 0;
    qzero(g30);
    g100 = *(u8 **)(self + 0x70);
    qzero(g100 + 0x120);
    qzero(g100 + 0x100);
    g100 += 0x100;
    *(f32 *)(g100 + 0x40) = 3.0f;
    *(f32 *)(g100 + 0x30) = 0.003f;
    *(f32 *)(g100 + 0x34) = 0.1f;
    *(f32 *)(g100 + 0x38) = 0.2f;
    *(s32 *)(g100 + 0x3C) = 0;
    g150 = *(u8 **)(self + 0x70) + 0x150;
    *(s32 *)(g150 + 0x00) = 0;
    *(s32 *)(g150 + 0x04) = 0;
    *(s32 *)(g150 + 0x08) = 0;
    *(s32 *)(g150 + 0x0C) = 0;
    *(s32 *)(g150 + 0x10) = 1;
    if (e->mode == 2 && e->h34 == 0) {
        b = D_L17_0021CD80[e->path];
        d = D_L17_001DED10[e->f24].f10;
        a = D_L17_0021CD80[e->f28];
        c = D_L17_0021CD80[e->f2C];
        e->h34 = 1;
        for (i = 0; i < a->count; i++) {
            func_L01_00476B98(b, &a->pts[i], &out, &idx, &t, 0, 20.0f, 5.0f, 0.0f);
            *(f32 *)((u8 *)a + (i << 4) + 16) = *(f32 *)((u8 *)a + (i << 4) + 28);
            *(f32 *)((u8 *)a + (i << 4) + 28) = (f32)idx;
        }
        for (i = 0, k = a->count - 1; i < a->count; k = i, i++) {
            j0 = (s32)*(f32 *)((u8 *)a + (k << 4) + 28);
            n = (s32)*(f32 *)((u8 *)a + (i << 4) + 28) - j0;
            if (n < 0) n += b->count;
            t = 0.0f;
            for (j1 = 0; j1 < n; j1++) t += *(f32 *)((u8 *)b + (((j0 + i) % b->count) << 4) + 28);
            *(f32 *)((u8 *)a + (i << 4) + 20) = t;
        }
        for (i = 0; i < c->count; i++) {
            func_L01_00476B98(d, &c->pts[i], &out, &idx, &t, 0, 20.0f, 5.0f, 0.0f);
            *(f32 *)((u8 *)c + (i << 4) + 16) = *(f32 *)((u8 *)c + (i << 4) + 28);
            *(f32 *)((u8 *)c + (i << 4) + 28) = (f32)idx;
        }
        for (i = 0, k = c->count - 1; i < c->count; k = i, i++) {
            j0 = (s32)*(f32 *)((u8 *)c + (k << 4) + 28);
            n = (s32)*(f32 *)((u8 *)c + (i << 4) + 28) - j0;
            if (n < 0) n += d->count;
            t = 0.0f;
            for (j1 = 0; j1 < n; j1++) t += *(f32 *)((u8 *)d + (((j0 + i) % d->count) << 4) + 28);
            *(f32 *)((u8 *)c + (i << 4) + 20) = t;
        }
    }
    *(s16 *)(s74 + 0xA) = 0;
}
/* localdecomp:end func_L17_003C6910 */

INCLUDE_ASM("asm/levels", func_L17_003C6DA0);

#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AA060 */
extern u8 D_001D8064;
void func_003AA060(u8 a) { D_001D8064 = a; }
/* localdecomp:end func_003AA060 */

/* localdecomp:start func_003AA068 */
extern u8 D_001D8064;
u8 func_003AA068(void) {
    return D_001D8064;
}
/* localdecomp:end func_003AA068 */

/* localdecomp:start func_003AA070 */
#include "vu0.h"
typedef struct { s32 x, y, w, h; } In_003AA070;
typedef struct { long z; s16 y, x, w, h; } Out_003AA070;
typedef struct {
    u8 p0[6]; s16 n; u8 p8[4]; f32 scale;
    u8 *p10; u8 *p14; Out_003AA070 *rects; u8 *p1C; u8 *p20;
} H_003AA070;
H_003AA070 *func_003AA070(H_003AA070 *h) {
    In_003AA070 *in;
    s32 i;
    h->p10 += (s32)h;
    h->p14 += (s32)h;
    h->rects = (Out_003AA070 *)((u8 *)h->rects + (s32)h);
    h->p1C += (s32)h;
    if (h->p20 != 0) h->p20 += (s32)h;
    h->scale *= 0.0032116016f;
    in = (In_003AA070 *)h->rects;
    for (i = 0; i < h->n; i++, in++) {
        s32 x = in->x >> 4;
        s32 y = in->y >> 4;
        s32 w = 30 - plzcw_asm(in->w);
        s32 hh = 30 - plzcw_asm(in->h);
        h->rects[i].x = x;
        h->rects[i].y = y;
        h->rects[i].w = w;
        h->rects[i].h = hh;
        h->rects[i].z = 0;
    }
    return h;
}
/* localdecomp:end func_003AA070 */

typedef struct { u8 p0[0x16]; s16 h16; } F_3A4860;
typedef struct { u8 p0[4]; s16 n; u8 p6[2]; s16 nframes; s16 stride; u8 pC[0x14]; u8 *data; } A_3A4860;
typedef struct { f32 m[16]; } M_3A4860;
extern void func_0038DDF0();
extern void func_0038DE48(void *, void *, void *, f32);
extern void func_0038DD58();
extern void func_0038DA20();
/* localdecomp:start func_003AA168 */
void func_003AA168(A_3A4860 *a, M_3A4860 *out, f32 t) {
    f32 tmp[12];
    s32 i;
    s32 frame = (s32)t;
    f32 frac;
    u8 *src = a->data + frame * a->stride;
    for (i = 0; i < a->n; i++, src += 0x18) {
        func_0038DDF0(src, &out[i]);
    }
    frac = t - cvtsw_asm(cvtws_asm(t));
    if (0.001f < frac) {
        s32 next = frame + 1;
        if (!(next < a->nframes)) next = 0;
        src = a->data + next * a->stride;
        for (i = 0; i < a->n; i++, src += 0x18) {
            func_0038DDF0(src, tmp);
            func_0038DE48(&out[i], &out[i], tmp, frac);
        }
    }
    {
        F_3A4860 *f = (F_3A4860 *)(a->data + (s32)t * a->stride);
        s32 j;
        for (j = 0; j < a->n; j++, f++) {
            func_0038DD58(&out[j], &out[j].m[4], &out[j].m[8], &out[j]);
            if (f->h16 >= 0) func_0038DA20(&out[j], &out[f->h16], &out[j]);
        }
    }
}
/* localdecomp:end func_003AA168 */

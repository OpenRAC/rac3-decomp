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

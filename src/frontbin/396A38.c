#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 396838.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);

/* localdecomp:start func_00396A38 */
/* from rac2-decomp's func_0028E640 */
typedef struct { s32 addr; u16 base; u8 w; u8 h; } T_00396A38;
typedef struct { s32 data; s16 f4; u16 f6; s32 clut; u8 tw; u8 th; u16 fE; } Q_00396A38;
extern Q_00396A38 D_00225C00[];
extern s16 *D_001D9EA8_00396A38;
extern T_00396A38 *D_001D9EAC_00396A38;
extern T_00396A38 *D_001D9EB0_00396A38;
extern s32 D_001D9BFC;
extern s32 D_001D4BB0;
extern s32 D_001A1ED4[];
unsigned long func_00396A38(s32 idx) {
    s16 *pair = (s16 *)((idx << 2) + (s32)D_001D9EA8_00396A38);
    T_00396A38 *c = D_001D9EB0_00396A38 + pair[0];
    T_00396A38 *t = D_001D9EAC_00396A38 + pair[1];
    s32 done = 0;
    s32 sh, psm;
    unsigned long r, cw;
    if (!c->base || !t->base) {
        Q_00396A38 *q = D_00225C00 + D_001D9BFC;
        q->data = c->addr;
        q->f4 = 0;
        q->f6 = 0x3FF0;
        D_00225C00[D_001D9BFC].clut = c->addr;
        q->tw = 5;
        q->th = 5;
        q->fE = 0x3FF0;
    }
    if (!c->base) {
        c->base = D_001D4BB0 >> 8;
        D_001D4BB0 = D_001D4BB0 + 0x400;
        if (D_001D9BFC < 64) {
            Q_00396A38 *q = D_00225C00 + D_001D9BFC;
            done = 1;
            q->data = c->addr;
            q->f4 = 0;
            q->f6 = c->base;
        }
    }
    if (!t->base) {
        s32 v = D_001D4BB0;
        u8 ih;
        t->base = v >> 8;
        ih = t->h < t->w ? t->w : t->h;
        D_001D4BB0 = v + (1 << (ih * 2));
        if (D_001D9BFC < 64) {
            Q_00396A38 *q = D_00225C00 + D_001D9BFC;
            done = 1;
            D_00225C00[D_001D9BFC].clut = t->addr;
            q->tw = t->w;
            q->th = t->h;
            q->fE = t->base;
        }
    }
    if (done) D_001D9BFC++;
    sh = t->w - 6;
    if (sh < 0) sh = 0;
    sh = 1 << sh;
    psm = 0x13;
    if (t->base < (D_001A1ED4[0] >> 8)) psm = 0x1B;
    r = t->base | ((unsigned long)sh << 14);
    r |= (unsigned long)psm << 20;
    r |= (unsigned long)t->w << 26;
    r |= (unsigned long)t->h << 30;
    cw = (unsigned long)c->base << 37;
    cw |= (unsigned long)0x8000 << 19;
    r |= cw;
    return r | 0x8000000000000000UL;
}
/* localdecomp:end func_00396A38 */

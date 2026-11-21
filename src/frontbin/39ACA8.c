#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

typedef struct { u8 *data; u8 *clut; u8 pad8[0xC]; s32 f14; u8 pad18[0x34]; s32 tw; s32 th; u8 pad54[4]; } T_395EB8;
typedef struct { u8 *data; s16 f4; s16 f6; u8 *clut; u8 tw; u8 th; s16 fE; } E_395EB8;
extern s32 D_001D4BB0;
extern s32 D_001D9BFC;
extern E_395EB8 D_00225C00[];
/* localdecomp:start func_0039ACA8 */
#include "vu0.h"
/* BLOCKED: plzcw (twice: 30 - plzcw(w), 30 - plzcw(h)) has no C form. This draft, with plzcw as
   inline asm (forbidden), says MATCH with --as ps2as on PAL and US (66 diff with the default as).
   __builtin_plzcw (TImode) adds por/dsll32 copies: 84 diff. */
long func_0039ACA8(u8 *p) {
    T_395EB8 t;
    s32 w, h, s, a, cbp, tbp;
    long r;
    E_395EB8 *e;
    w = *(s32 *)(p + 8);
    w = plzcw_asm(w);
    h = *(s32 *)(p + 0xC);
    h = plzcw_asm(h);
    t.tw = 0x1E - w;
    t.th = 0x1E - h;
    s = t.tw - 6;
    if (s < 0) s = 0;
    a = D_001D4BB0;
    cbp = a >> 8;
    a += 0x400;
    tbp = a >> 8;
    t.data = p + 0x20;
    t.clut = p + 0x420;
    t.f14 = 0x400;
    D_001D4BB0 = a + (1 << (t.tw + t.th));
    r = (long)tbp | ((long)(1 << s) << 14) | (0x13UL << 20) | ((long)t.tw << 26) | ((long)t.th << 30) | (1UL << 34) | ((long)cbp << 37) | (4UL << 61);
    if (D_001D9BFC < 0x40) {
        e = &D_00225C00[D_001D9BFC];
        e->data = t.data;
        e->f6 = cbp;
        e->f4 = 0;
        D_00225C00[D_001D9BFC].clut = t.clut;
        e->tw = t.tw;
        e->th = t.th;
        e->fE = tbp;
        D_001D9BFC++;
    }
    return r;
}
/* localdecomp:end func_0039ACA8 */

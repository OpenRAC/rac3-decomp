#include "common.h"

/* localdecomp:start func_L39_0059F838 */
#include "vu0.h"
typedef struct { s32 tbp; u16 w; s16 h; s16 mxl; s16 cbp; s16 tbp2; s16 tbp3; } T_0059F838;
extern s32 D_L39_001FC450[];
extern unsigned long D_L39_0024BDF0[];
extern unsigned long D_L39_0024BE08[];

void func_L39_0059F838(unsigned long *q, T_0059F838 *t, s32 k, s32 mmin, s32 wm, s32 wt, s32 idx) {
    s32 base, mxl, tbp3, th, tbp2, cbp, bw1, bw0, tw;
    s16 w, h;
    unsigned long *tbl;
    w = t->w;
    h = t->h;
    bw0 = w >> 6;
    bw1 = w >> 7;
    if (bw0 <= 0) bw0 = 1;
    if (bw1 <= 0) bw1 = 1;
    mxl = t->mxl;
    base = D_L39_001FC450[8] >> 8;
    cbp = t->cbp + base;
    tw = 30 - plzcw_asm(w);
    th = 30 - plzcw_asm(h);
    tbp2 = t->tbp2 + base;
    tbp3 = t->tbp3 + base;
    if (idx >= 0) {
        if (mxl == 0) {
            s32 tbp = t->tbp;
            tbp = (D_L39_001FC450[13] + tbp * 4) >> 8;
            *q = ((unsigned long)1 << 5) | ((unsigned long)mmin << 6) | ((unsigned long)k << 32);
            q += 2;
            *q = wm | ((unsigned long)wt << 2) | ((unsigned long)idx << 24);
            q += 2;
            *q = (unsigned long)tbp | ((unsigned long)bw0 << 14) | ((unsigned long)0x1B << 20) | ((unsigned long)tw << 26) | ((unsigned long)th << 30) | ((unsigned long)1 << 34) | ((unsigned long)cbp << 37) | ((unsigned long)4 << 61);
            q += 2;
            *q = ((unsigned long)1 << 14) | ((unsigned long)1 << 34) | ((unsigned long)1 << 54);
        } else {
            *q = ((unsigned long)(mxl - 1) << 2) | ((unsigned long)1 << 5) | ((unsigned long)mmin << 6) | ((unsigned long)k << 32);
            q += 2;
            *q = wm | ((unsigned long)wt << 2) | ((unsigned long)idx << 24);
            q += 2;
            *q = ((unsigned long)bw0 << 14) | ((unsigned long)0x13 << 20) | ((unsigned long)tw << 26) | ((unsigned long)th << 30) | ((unsigned long)1 << 34) | ((unsigned long)cbp << 37) | ((unsigned long)4 << 61);
            q += 2;
            *q = ((unsigned long)bw1 << 14) | ((unsigned long)tbp2 << 20) | ((unsigned long)1 << 34) | ((unsigned long)tbp3 << 40) | ((unsigned long)1 << 54);
        }
    } else if (idx < -1) {
        tbl = D_L39_0024BDF0;
        if (idx == -3) tbl = D_L39_0024BE08;
        *q = ((unsigned long)1 << 5) | ((unsigned long)mmin << 6) | ((unsigned long)k << 32);
        q += 2;
        *q = 5;
        q += 2;
        q[0] = tbl[0];
        q[2] = tbl[2];
    } else {
        *q = ((unsigned long)1 << 5) | ((unsigned long)mmin << 6) | ((unsigned long)k << 32);
        q += 2;
        *q = 5;
        q += 2;
        q[0] = 0x80000004CC007FFBUL;
        q[2] = 0;
    }
}
/* localdecomp:end func_L39_0059F838 */

#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 1301D8.c's earlier functions (tools/port_from_us.py) */
typedef struct {
    u8 pad0[0x184];
    int f184;
    int f188;
} S_130210;
typedef struct {
    int f0;
    u8 pad4[0x10 - 4];
    int f10;
} Pic_130AA0;
typedef struct {
    int f0;
    int pad4;
    int f8;
    int fC;
    int f10;
    u8 pad14[0x140 - 0x14];
} Blk_130AA0;
typedef struct {
    u8 pad0[0x12C];
    int f12C;
    u8 pad130[0x13C - 0x130];
    int f13C;
    u8 pad140[0x184 - 0x140];
    int f184;
    u8 pad188[0x1D0 - 0x188];
    Pic_130AA0 *f1D0;
    u8 pad1D4[0x1E0 - 0x1D4];
    Pic_130AA0 *f1E0;
    u8 pad1E4[0x1F0 - 0x1E4];
    Pic_130AA0 *f1F0;
    u8 pad1F4[0x6C8 - 0x1F4];
    Blk_130AA0 blk[1];
    u8 pad808[0x820 - 0x808];
    int f820;
} S_130AA0;
extern char D_00151CF0[];
void func_0013A150(void *s, char *fmt, int x);
void func_00130398(S_130AA0 *s, int x, int y, int flags, int mode, int *mv, int *fs, int *dmvec);
void func_00132D48();

/* localdecomp:start func_00130CF0 */
typedef struct {
    u8 *dst;
    s32 x;
    s32 h0;
    s32 h1;
    s32 stride;
    u8 *src0;
    u8 *src1;
} E_00130CF0;
typedef struct {
    u8 *buf;
    s32 x04;
    void *mb0[4];
    void *mb1[4];
    void (*cbY[4])(void *);
    void (*cbC[4])(void *);
    E_00130CF0 y[4];
    E_00130CF0 c[4];
    s32 x128;
    s32 n;
    u8 pad130[0x10];
} B_00130CF0;
typedef struct {
    u8 pad0[0x5A0];
    B_00130CF0 blk[2];
    s32 f820;
    u8 pad824[0xC];
    u8 *f830;
    u8 pad834[0x48];
    s32 f87C;
} G_00130CF0;
typedef struct { void *f0; u8 pad4[0xC]; s32 f10; } R_00130CF0;
extern void (*D_001415E0[])(void *);
extern void (*D_00141600[])(void *);

void func_00130CF0(G_00130CF0 *g, R_00130CF0 *ref, s32 sfield, s32 dfield, s32 yoff, s32 h,
                   s32 bx, s32 by, s32 dx, s32 dy, s32 fld, s32 avg) {
    s32 n;
    E_00130CF0 *e;
    E_00130CF0 *c;
    u8 *dst;
    void *mb0;
    void *mb1;
    u8 *p;
    u8 *q;
    s32 x, y, mbx, mby, cmbx, cmby, t, off;
    s32 xh, yh, lmode, cmode;
    s32 cdy, cdx, h2, yo, o;

    dst = g->f830;
    n = g->blk[g->f820].n;
    e = &g->blk[g->f820].y[n];
    c = &g->blk[g->f820].c[n];

    x = (dx >> 1) + bx;
    if (fld) {
        y = ((dy >> 1) << 1) + yoff + (by + sfield);
    } else {
        y = (dy >> 1) + yoff + (by + sfield);
    }
    mbx = x >> 4;
    mby = y >> 4;
    t = mbx * ref->f10 + mby;
    mb0 = ref->f0 + t * 0x180;
    mb1 = ref->f0 + (t + ref->f10) * 0x180;
    y = y - (mby << 4);
    g->blk[g->f820].mb0[n] = mb0;
    g->blk[g->f820].mb1[n] = mb1;
    e->dst = dst + ((dfield + yoff) << 5);
    e->x = x - (mbx << 4);
    xh = dx & 1;
    yh = dy & 1;
    if (yh) {
        if (y + (h << fld) < 16) {
            e->h0 = h;
            e->h1 = 0;
        } else {
            e->h0 = (16 >> fld) - (y >> fld) - 1;
            e->h1 = h - e->h0;
        }
    } else {
        if (y + (h << fld) > 16) {
            e->h0 = (16 >> fld) - (y >> fld);
            e->h1 = h - e->h0;
        } else {
            e->h0 = h;
            e->h1 = 0;
        }
    }
    if (g->f87C == 0) {
        p = g->blk[g->f820].buf + n * 0x600;
        e->src0 = p + y * 16;
        e->src1 = p + (y * 16 + 0x300);
    } else {
        p = mb0;
        e->src0 = p + y * 16;
        e->src1 = mb1 + y * 16;
    }
    e->stride = 16 << fld;
    lmode = (avg << 2) | (xh << 1) | yh;

    cdx = dx / 2;
    cdy = dy / 2;
    h2 = h >> 1;
    yo = yoff >> 1;
    x = (cdx >> 1) + (bx >> 1);
    if (fld) {
        y = ((cdy >> 1) << 1) + yo + ((by >> 1) + sfield);
    } else {
        y = (cdy >> 1) + yo + ((by >> 1) + sfield);
    }
    cmbx = x >> 3;
    cmby = y >> 3;
    y = y - (cmby << 3);
    xh = cdx & 1;
    yh = cdy & 1;
    c->x = x - (cmbx << 3);
    c->dst = dst + (((dfield + yo) << 4) + 0x200);
    if (yh) {
        if (y + (h2 << fld) < 8) {
            c->h0 = h2;
            c->h1 = 0;
        } else {
            c->h0 = (8 >> fld) - (y >> fld) - 1;
            c->h1 = h2 - c->h0;
        }
    } else {
        if (y + (h2 << fld) > 8) {
            c->h0 = (8 >> fld) - (y >> fld);
            c->h1 = h2 - c->h0;
        } else {
            c->h0 = h2;
            c->h1 = 0;
        }
    }
    off = ((cmbx - mbx) * 2 + (cmby - mby)) * 0x180;
    q = p + off;
    if (g->f87C == 0) {
        c->src0 = q + ((y << 3) + 0x100);
        c->src1 = q + ((y << 3) + 0x400);
    } else {
        o = (y << 3) + 0x100;
        if ((u32)(off + o) <= 0x300) {
            c->src0 = mb0 + off + o;
        } else {
            c->src0 = mb1 + off + o - 0x300;
        }
        c->src1 = mb1 + off + ((y << 3) + 0x100);
    }
    c->stride = 8 << fld;
    cmode = (avg << 2) | (xh << 1) | yh;
    g->blk[g->f820].cbY[n] = D_001415E0[lmode];
    g->blk[g->f820].cbC[n] = D_00141600[cmode];
    g->blk[g->f820].n++;
}
/* localdecomp:end func_00130CF0 */

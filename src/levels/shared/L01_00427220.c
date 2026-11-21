#include "common.h"

/* localdecomp:start func_L01_00427220 */
#include "vu0.h"

typedef int u128_00427220 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[4];
    u16 w;
    s16 h;
    s16 nmip;
    s16 cbp;
    s16 tbp2;
    s16 tbp3;
} Tex_00427220;

typedef union {
    struct {
        unsigned long d0;
        unsigned long r8;
        unsigned long d10;
        unsigned long r18;
        unsigned long d20;
        unsigned long r28;
        unsigned long d30;
        unsigned long r38;
        unsigned long d40;
        unsigned long r48;
    } q;
    struct {
        s32 f0;
        s32 f4;
        s32 f8;
        s32 fC;
        s32 f10;
        s32 f14;
        s32 f18;
        s32 f1C;
        s32 f20;
        s32 f24;
        s32 f28;
        s32 f2C;
        s32 f30;
        s32 f34;
    } w;
} Rec_00427220;

typedef struct {
    s32 f0;
    s32 pad4[3];
} Sub_00427220;

typedef struct {
    s32 f[3];
    u8 b[4];
    f32 f10;
    f32 f14;
    f32 f18;
    s32 f1C;
    s32 f20;
    u8 pad24[0xC];
    s32 f30;
    s32 f34;
    u8 pad38[6];
    s16 f3E;
    u8 pad40[6];
    s16 f46;
    f32 f48;
} Obj_00427220;

extern s32 D_L01_001E0ED0;
__asm__(".extern D_L01_001E0ED0, 16");
extern u8 D_L01_0023C800[];
extern s16 D_L01_0023C700[];
extern u8 *D_L01_0023C500[];
extern s32 D_L01_00243800[];
extern u8 D_L01_00243C00[];
extern unsigned long D_L01_001F3DC0[];
extern s32 D_L01_001A1ED0[];

void func_L01_00427220(Obj_00427220 *p, Tex_00427220 *tex, u128_00427220 *src, s32 slot) {
    s32 i;
    s32 j;
    s32 k;
    u8 *pal;
    Rec_00427220 *r;

    D_L01_0023C800[slot] = D_L01_001E0ED0;
    D_L01_0023C700[D_L01_001E0ED0] = slot;
    D_L01_0023C500[D_L01_001E0ED0] = (u8 *)p;
    p->f46 = D_L01_001E0ED0;
    D_L01_00243800[D_L01_001E0ED0++] = p->f48 * 1024.0f;
    p->f20 = -1;
    p->f3E = 0;

    for (i = 0; i < 3; i++) {
        if (p->f[i] != 0) {
            p->f[i] += (s32)p;
            for (j = 0; j < p->b[i]; j++) {
                ((Sub_00427220 *)p->f[i])[j].f0 += p->f[i];
            }
        }
    }
    if (p->b[1] == 0) {
        p->f14 = 8190.0f;
    }
    if (p->b[2] == 0) {
        p->f18 = 8192.0f;
    }
    p->f30 = 0;
    p->f34 += (s32)p;
    p->f1C += (s32)p;

    pal = D_L01_00243C00 + (D_L01_0023C800[slot] << 4);
    *(u128_00427220 *)pal = *src;

    r = (Rec_00427220 *)p->f1C;
    for (k = 0; k < p->b[3]; k++) {
        s32 t = pal[k];
        s32 k10 = r->w.f10;
        s32 k14 = r->w.f14;
        s32 k30 = r->w.f30;
        s32 k34 = r->w.f34;

        if (tex != 0) {
            Tex_00427220 *e = &tex[t];
            s32 base = D_L01_001A1ED0[8] >> 8;
            s32 w = (s16)e->w;
            s32 tw = 30 - plzcw_asm(w);
            s32 th = 30 - plzcw_asm(e->h);
            s32 tbw1 = w >> 7;
            s32 tbw = w >> 6;
            s32 cbp = e->cbp + base;
            s32 mxl = e->nmip - 1;
            s32 tbp2 = e->tbp2 + base;
            s32 tbp3 = e->tbp3 + base;
            if (tbw < 1) tbw = 1;
            if (tbw1 < 1) tbw1 = 1;

            r->q.d0 = ((unsigned long)0 << 0) | ((unsigned long)tbw << 14) | ((unsigned long)0x13 << 20) |
                      ((unsigned long)tw << 26) | ((unsigned long)th << 30) | ((unsigned long)1 << 34) |
                      ((unsigned long)0 << 35) | ((unsigned long)cbp << 37) |
                      ((unsigned long)0 << 51) | ((unsigned long)0 << 55) | ((unsigned long)0 << 56) |
                      ((unsigned long)4 << 61);
            r->q.d10 = ((unsigned long)0 << 0) | ((unsigned long)mxl << 2) | ((unsigned long)1 << 5) |
                       ((unsigned long)k14 << 6) | ((unsigned long)0 << 9) | ((unsigned long)0 << 19) |
                       ((unsigned long)k10 << 32);
            r->q.d20 = ((unsigned long)0 << 0) | ((unsigned long)tbw1 << 14) | ((unsigned long)tbp2 << 20) |
                       ((unsigned long)1 << 34) | ((unsigned long)tbp3 << 40) | ((unsigned long)1 << 54);
            r->q.d30 = ((unsigned long)k30 << 0) | ((unsigned long)k34 << 2) | ((unsigned long)t << 24);
        } else {
            unsigned long v0 = D_L01_001F3DC0[t * 3];
            unsigned long v1 = D_L01_001F3DC0[t * 3 + 1];
            unsigned long v2 = D_L01_001F3DC0[t * 3 + 2];
            r->q.d0 = v0;
            r->q.d10 = (v1 & 0x1C) | ((unsigned long)1 << 5) | ((unsigned long)k14 << 6) | ((unsigned long)k10 << 32);
            r->q.d20 = v2;
            r->q.d30 = ((unsigned long)k30 << 0) | ((unsigned long)k34 << 2) | ((unsigned long)t << 24);
        }
        r++;
    }
}
/* localdecomp:end func_L01_00427220 */

INCLUDE_ASM("asm/levels", func_L01_004275F8);

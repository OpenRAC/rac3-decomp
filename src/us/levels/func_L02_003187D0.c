#include "common.h"

/* NTSC-U counterpart of func_L02_00318CA8 (src/levels/shared/L02_00317D28.c) */
typedef struct { u8 pad[0x23]; s8 v; } P_003187D0;
typedef struct { u8 pad0[0x1200]; P_003187D0 *p[3]; u8 pad1[0x50 - 12]; } E_003187D0;
typedef struct { u8 pad0[0x25C0]; P_003187D0 *q; } H_003187D0;
extern E_003187D0 D_001A4BE0_003187D0;
extern H_003187D0 D_001A4BE0_003187D0h;
__asm__(".extern D_001A4BE0_003187D0, 16");
__asm__(".extern D_001A4BE0_003187D0h, 16");

/* localdecomp:start func_L02_003187D0 */
void func_L02_003187D0(s32 d) {
    s32 i;
    E_003187D0 *e;
    H_003187D0 *h = &D_001A4BE0_003187D0h;
    h->q->v += d;
    if (h->q->v < 0) h->q->v = 0x7F;
    else if ((u8)h->q->v < 12) h->q->v = 12;
    e = &D_001A4BE0_003187D0;
    for (i = 0; i < 7; i++, e = (E_003187D0 *)((u8 *)e + 0x50)) {
        P_003187D0 *p;
        if (i == 3) continue;
        p = e->p[0];
        if (p != 0) {
            p->v += d;
            p = e->p[0];
            if (p->v < 0) p->v = 0x7F;
            else if ((u8)p->v < 12) p->v = 12;
        }
        p = e->p[1];
        if (p != 0) {
            p->v += d;
            p = e->p[1];
            if (p->v < 0) p->v = 0x7F;
            else if ((u8)p->v < 12) p->v = 12;
        }
        p = e->p[2];
        if (p != 0) {
            p->v += d;
            p = e->p[2];
            if (p->v < 0) p->v = 0x7F;
            else if ((u8)p->v < 12) p->v = 12;
        }
    }
}
/* localdecomp:end func_L02_003187D0 */

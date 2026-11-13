#include "common.h"

/* NTSC-U counterpart of func_L39_00672DD8 (src/levels/shared/L39_00672828.c) */
/* localdecomp:start func_L39_00670488 */
__asm__(".extern D_L39_00240760, 16");

typedef struct Sub_00672DD8 {
    s16 h0;
    u8 b2;
    u8 b3;
    s32 w4;
    u32 w8;
    u8 padC[0x24 - 0xC];
} Sub_00672DD8;

typedef struct Evt_00672DD8 {
    s16 h0;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 pad8[0x20 - 8];
    struct Evt_00672DD8 *next;
    Sub_00672DD8 sub;
    u8 pad48[0x50 - 0x48];
} Evt_00672DD8;

typedef struct Obj_00672DD8 {
    u8 pad0[0xAA];
    s16 hAA;
} Obj_00672DD8;

typedef struct Slot_00672DD8 {
    Obj_00672DD8 *o;
    u8 pad4[0x28 - 4];
    u16 h28;
    u8 pad2A[0x50 - 0x2A];
} Slot_00672DD8;

typedef struct Net_00672DD8 {
    u8 pad0[0x568];
    s32 w568;
} Net_00672DD8;

typedef struct G_00672DD8 {
    u8 pad0[0x450];
    Slot_00672DD8 slots[8];
    u8 pad6D0[0x1A14 - 0x6D0];
    u8 b1A14;
    u8 pad1A15[0x2534 - 0x1A15];
    Net_00672DD8 *p2534;
    u8 pad2538[0x2544 - 0x2538];
    u8 b2544;
} G_00672DD8;

typedef struct Own_00672DD8 {
    u8 pad0[0x40];
    Evt_00672DD8 evt[10];
    u8 b360;
    u8 pad361[3];
    Evt_00672DD8 *p364;
    G_00672DD8 *p368;
} Own_00672DD8;

typedef struct Def_00672DD8 {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x21 - 6];
    s8 b21;
    u8 pad22[0x70 - 0x22];
    void (*f70)(Obj_00672DD8 *, Sub_00672DD8 *);
    u8 pad74[0x80 - 0x74];
} Def_00672DD8;

typedef struct Mgr_00672DD8 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x128 - 8];
    s32 w128;
    u8 pad12C[0x170 - 0x12C];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} Mgr_00672DD8;

extern Mgr_00672DD8 D_001A5E50;
extern Def_00672DD8 D_L39_0049C950_00670488[];
extern s32 D_L39_00240760;
extern s32 func_L39_00646268(u8 *, s32);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_00670488(Own_00672DD8 *g, u8 a1, s32 a2, s16 a3, u8 a4, Sub_00672DD8 *a5) {
    Sub_00672DD8 s;
    Evt_00672DD8 *e;
    Evt_00672DD8 *p;
    s16 h;
    s32 i;
    s32 none;

    if (g->b360 < 10) {
        for (i = 0, none = -1; i < 10; i++) {
            if (g->evt[i].b2 != 0xFF) {
                continue;
            }
            e = &g->evt[i];
            e->w4 = (a2 == none) ? D_001A5E50.w128 + (s32)((f32)g->p368->p2534->w568 * 16.6666667f) : a2;
            if (a3 == none) {
                e->h0 = g->p368->slots[a4].h28;
            } else {
                e->h0 = a3;
            }
            e->b2 = a4;
            e->b3 = a1;
            e->next = 0;
            if (g->p368->b1A14 != 0) {
                s.h0 = e->h0;
                s.w4 = e->w4;
                s.b3 = a1;
                s.b2 = g->p368->b2544;
                s.w8 = 0xFFFFFFFF;
                h = e->h0;
                if ((func_L39_00646268((u8 *)g->p368, h) ? &D_L39_0049C950_00670488[D_L39_0049C950_00670488[h].b21] : &D_L39_0049C950_00670488[h])->f70 != 0) {
                    h = e->h0;
                    if ((func_L39_00646268((u8 *)g->p368, h) ? &D_L39_0049C950_00670488[D_L39_0049C950_00670488[h].b21] : &D_L39_0049C950_00670488[h])->h4 == g->p368->slots[a4].o->hAA) {
                        h = e->h0;
                        (func_L39_00646268((u8 *)g->p368, h) ? &D_L39_0049C950_00670488[D_L39_0049C950_00670488[h].b21] : &D_L39_0049C950_00670488[h])->f70(g->p368->slots[a4].o, &s);
                        e->w4 = s.w4;
                    }
                }
                e->sub = s;
                if (e->w4 != none) {
                    if (D_001A5E50.w170 == 0) {
                        func_0014AD08(D_001A5E50.b7D4 | 0x80, D_001A5E50.w4, -1, D_L39_00240760, 0x24, &s);
                    }
                } else {
                    e->w4 = D_001A5E50.w128;
                    e->sub.w4 = D_001A5E50.w128;
                }
            } else if (a5 != 0) {
                e->sub = *a5;
            }
            p = g->p364;
            while (p != 0 && p->next != 0 && p->next->w4 < e->w4) {
                p = p->next;
            }
            if (p == 0) {
                g->p364 = e;
            } else {
                p->next = e;
            }
            g->b360++;
            break;
        }
    }
}
/* localdecomp:end func_L39_00670488 */

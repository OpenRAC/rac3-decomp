#include "common.h"

/* localdecomp:start func_L39_0066D3A8 */
typedef struct {
    u8 pad0[0x2558];
    s32 *f2558;
} P_0066D3A8;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x2C - 8];
    u8 b2C;
    u8 pad2D[3];
    s32 w30;
    s32 w34;
    u8 pad38[0x44 - 0x38];
    s32 w44;
    s32 w48;
    s32 w4C;
    u8 b50;
    u8 b51;
    u8 pad52[2];
} E_0066D3A8;
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 pad0C[0x128 - 0xC];
    s32 w128;
} G_0066D3A8;

extern G_0066D3A8 D_001A5CD0;
extern s32 D_L39_00246334;
extern P_0066D3A8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern E_0066D3A8 D_L39_00343328[];
extern void func_L39_0061E278(void *);
extern void func_L39_0066DA90(s32 *, s32, u8, u8);

void func_L39_0066D3A8(s32 n, s32 id)
{
    s32 best;
    s32 i;
    E_0066D3A8 *e;

    D_L39_00246334 = D_001A5CD0.w128;
    best = -1;
    for (i = n + 1; i < 8; i++) {
        if (D_L39_0024CE20[i] != 0) {
            s32 v = *D_L39_0024CE20[i]->f2558;
            if (v != id) {
                best = v;
            }
        }
    }
    if (best == -1) {
        for (i = 0; i < n; i++) {
            if (D_L39_0024CE20[i] != 0) {
                s32 v = *D_L39_0024CE20[i]->f2558;
                if (v != id) {
                    best = v;
                }
            }
        }
    }
    for (i = 0; i < 512; i++) {
        e = &D_L39_00343328[i];
        if (e->b2C == 0) {
            continue;
        }
        if (e->w44 == id) {
            if (e->w34 == D_001A5CD0.w8) {
                func_L39_0061E278(e);
            }
            e->w4 = -1;
            e->w34 = -1;
            e->w48 = -1;
            e->w4C = -1;
            e->b50 = 0;
            e->b51 = 1;
            e->w44 = best;
        } else if (e->w44 == D_001A5CD0.w8) {
            if (e->w4C == id) {
                func_L39_0066DA90((s32 *)e, e->w48, e->b51, *(u8 *)&D_001A5CD0.w8);
                e->w4C = -1;
                e->b51++;
            } else if (e->w48 == id) {
                e->w4 = -1;
                e->w34 = -1;
                e->w48 = -1;
                e->w4C = -1;
            }
        }
    }
}
/* localdecomp:end func_L39_0066D3A8 */

/* localdecomp:start func_L39_0066D580 */
typedef struct { u8 p0[0x14]; void **vt; u8 p18[0x2C]; s32 w44; } Obj_0066D580;
typedef struct { u8 p0[3]; u8 b3; u8 p4[4]; s32 w8; } Tgt_0066D580;
extern void func_L39_00662B18(void *, void *, s32);
extern Obj_0066D580 *func_L39_0066C9F8(s32, s32, s32, s32);
extern Obj_0066D580 *func_L39_0061D1D8(s32);
extern void func_L39_0066D938(Tgt_0066D580 *, s32, s32);
extern void func_L39_0066D9A8(Tgt_0066D580 *, s32, s32);
extern void func_L39_0066DA10(Tgt_0066D580 *, s32, s32, s32);

static __inline__ void read32_0066D580(u32 *pkt, s32 *dst) {
    func_L39_00662B18(pkt, dst, 4);
}

static __inline__ void read8_0066D580(u32 *pkt, u8 *dst) {
    func_L39_00662B18(pkt, dst, 1);
}

void func_L39_0066D580(s32 unused, u32 *pkt) {
    u8 b0, b1, b2, b3, b4, b5, b6, b7, b8;
    s32 w0, w1, w2, w3, w4, w5;
    u32 type;
    Obj_0066D580 *o;
    Obj_0066D580 *t;
    Tgt_0066D580 *p;
    E_0066D3A8 *e;
    s32 i;

    type = pkt[0] & 0xF;
    switch (type) {
    case 0:
        read32_0066D580(pkt, &w0);
        read32_0066D580(pkt, &w1);
        read32_0066D580(pkt, &w2);
        o = func_L39_0066C9F8(w1, w0, 0, 1);
        o->w44 = (pkt[0] >> 10) & 7;
        ((void (*)(Obj_0066D580 *, u32 *))((void **)o->vt)[5])(o, pkt);
        t = func_L39_0061D1D8(w2);
        if (t != 0) {
            ((void (*)(Obj_0066D580 *, Obj_0066D580 *))((void **)t->vt)[6])(t, o);
        }
        break;
    case 1:
        read32_0066D580(pkt, &w3);
        read8_0066D580(pkt, &b0);
        read8_0066D580(pkt, &b1);
        p = (Tgt_0066D580 *)func_L39_0061D1D8(w3);
        if (p != 0 && (p->b3 & 0xF) == 7 && p->w8 != 2) {
            func_L39_0066D938(p, b0, b1);
        }
        break;
    case 2:
        read32_0066D580(pkt, &w4);
        read8_0066D580(pkt, &b2);
        read8_0066D580(pkt, &b3);
        p = (Tgt_0066D580 *)func_L39_0061D1D8(w4);
        if (p != 0 && (p->b3 & 0xF) == 7 && p->w8 != 2) {
            func_L39_0066D9A8(p, b2, b3);
        }
        break;
    case 3:
        read32_0066D580(pkt, &w5);
        read8_0066D580(pkt, &b4);
        read8_0066D580(pkt, &b5);
        read8_0066D580(pkt, &b6);
        p = (Tgt_0066D580 *)func_L39_0061D1D8(w5);
        if (p != 0 && (p->b3 & 0xF) == 7 && p->w8 != 2) {
            func_L39_0066DA10(p, b4, b5, b6);
        }
        break;
    case 4:
        read8_0066D580(pkt, &b7);
        read8_0066D580(pkt, &b8);
        for (i = 0; i < 512; i++) {
            e = &D_L39_00343328[i];
            if (e->b2C != 0) {
                if (e->w44 == b7) {
                    e->w4 = -1;
                    e->w34 = -1;
                    e->w48 = -1;
                    e->b50 = 0;
                    e->b51 = 1;
                    e->w44 = b8;
                } else if (e->w48 == b7) {
                    e->w4 = -1;
                    e->w34 = -1;
                    e->w48 = -1;
                }
            }
        }
        break;
    }
}
/* localdecomp:end func_L39_0066D580 */

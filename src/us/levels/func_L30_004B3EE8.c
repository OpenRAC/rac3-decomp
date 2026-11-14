#include "common.h"

/* NTSC-U counterpart of func_L30_004B7BC8 (src/levels/shared/L30_004B7BC8.c): 3 -> 4 */
/* localdecomp:start func_L30_004B3EE8 */
typedef struct {
    u8 *anim;                      /* 0x0 */
    s32 owner;                     /* 0x4 */
    f32 scale;                     /* 0x8 */
    s32 padC;
} Slot_004B7BC8;

typedef struct {
    u8 pad0[0x1AB0];
    Slot_004B7BC8 slots[2];        /* 0x1AB0 */
    u8 pad1AD0[0x25C0 - 0x1AD0];
    u8 *x25C0;                     /* 0x25C0 */
} G_004B7BC8;

extern G_004B7BC8 D_001A4BE0;
extern s32 D_001DBF18_sda[2];
extern s32 D_001DBF28_sda[2];
extern s32 D_001DBC80_sda[2];
extern u8 *func_L01_00436BD8(void *, s32, s32, s32);
extern void func_L01_00437108(void *, u8 *, s32, s32, s32, s32);
extern void func_L01_00436D30(u8 *, u8 *);

void func_L30_004B3EE8(s32 i, s32 seq, s32 a2, s32 owner) {
    G_004B7BC8 *g = &D_001A4BE0;
    u8 *p = g->slots[i].anim;
    s32 reused = 0;

    if (p == 0) {
        p = func_L01_00436BD8(g->x25C0, D_001DBF18_sda[i], D_001DBC80_sda[i], D_001DBF28_sda[i]);
        g->slots[i].anim = p;
    } else {
        reused = 1;
    }
    if (p != 0) {
        D_001A4BE0.slots[i].anim = p;
        D_001A4BE0.slots[i].scale = 1.0f;
        D_001A4BE0.slots[i].owner = owner;
        if (!reused) {
            *(s32 *)(p + 0x8) = 0;
        }
        *(s32 *)(p + 0x34) = 0;
        if (reused) {
            func_L01_00437108(D_001A4BE0.x25C0, p, seq, 0, 4, 1);
            return;
        }
        p[0x22] = seq;
        p[0x23] = seq;
        p[0x20] = a2;
        p[0x21] = a2 + 1;
        *(f32 *)(p + 0x28) = 1.0f;
        *(f32 *)(p + 0x2C) = 0.5f;
        *(s32 *)(p + 0x24) = 0;
        func_L01_00436D30(D_001A4BE0.x25C0, p);
    }
}
/* localdecomp:end func_L30_004B3EE8 */

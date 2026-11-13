#include "common.h"

/* NTSC-U counterpart of func_L39_006CD2C8 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
extern void *D_L39_0024D860;

/* localdecomp:start func_L39_006CAB40 */
extern u8 D_001A5E50[];
typedef struct { s32 w[0x31]; } B_006CD2C8;
typedef struct {
    s32 f0;
    u8 pad4[0x24];
    s32 f28;
    u8 f2C;
    u8 pad2D[3];
    u8 f30;
    u8 pad31[0x23];
    B_006CD2C8 f54;
} T_006CD2C8;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[5];
    u8 f1D;
    u8 pad1E[0x12];
    T_006CD2C8 *f30;
} G_006CD2C8;
typedef struct {
    u8 pad0[0x34];
    s32 f34;
    u8 pad38[0x38];
    s32 f70;
    u8 f74;
} D_006CD2C8;
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;

void func_L39_006CAB40(B_006CD2C8 *arg0) {
    G_006CD2C8 *g = (G_006CD2C8 *)D_L39_0024D860;
    T_006CD2C8 *t = g->f30;
    s32 v;
    s32 i;

    if (g->f1D == 0) {
        switch (arg0->w[6]) {
        case 0:
            i = 1;
            while (--i >= 0) {
            }
            break;
        case -0x3D2:
            g->f10 = 0xA;
            if (g->f14 == 0) {
                g->f14 = 0xA;
            }
            break;
        case -0x3E6:
            g->f10 = 0xF;
            if (g->f14 == 0) {
                g->f14 = 0xF;
            }
            break;
        case -0x3E5:
            g->f10 = 0x10;
            if (g->f14 == 0) {
                g->f14 = 0x10;
            }
            break;
        case -0x3DF:
            g->f10 = 1;
            if (g->f14 == 0) {
                g->f14 = 1;
            }
            break;
        case -0x3DD:
            g->f10 = 1;
            if (g->f14 == 0) {
                g->f14 = 1;
            }
            break;
        case -0x3DC:
            g->f10 = 1;
            if (g->f14 == 0) {
                g->f14 = 1;
            }
            break;
        case -0x3DB:
            g->f10 = 1;
            if (g->f14 == 0) {
                g->f14 = 1;
            }
            break;
        }
        v = arg0->w[7];
        t->f0 = v;
        ((D_006CD2C8 *)D_001A5E50)->f34 = v;
        t->f28 = 0;
        ((D_006CD2C8 *)D_001A5E50)->f70 = 0;
        t->f2C = 0;
        ((D_006CD2C8 *)D_001A5E50)->f74 = 0;
        t->f54 = *arg0;
        t->f30 = 0;
    }
}
/* localdecomp:end func_L39_006CAB40 */

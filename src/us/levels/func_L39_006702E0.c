#include "common.h"

/* NTSC-U counterpart of func_L39_00672C30 (src/levels/shared/L39_00672828.c) */
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L39_006702E0 */
typedef struct G_00672C30 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x128 - 8];
    s32 w128;
    u8 pad12C[0x170 - 0x12C];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} G_00672C30;

typedef struct Msg_00672C30 {
    u8 pad0[0xC];
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    u8 b1C;
} Msg_00672C30;

typedef struct Ent_00672C30 {
    u8 pad0[2];
    u8 b2;
    u8 b3;
    s32 w4;
    u8 pad8[0x20 - 8];
    struct Ent_00672C30 *p20;
} Ent_00672C30;

typedef struct Pl_00672C30 {
    u8 pad0[0x2544];
    s32 w2544;
} Pl_00672C30;

typedef struct Me_00672C30 {
    u8 pad0[0x360];
    u8 b360;
    u8 pad361[3];
    Ent_00672C30 *p364;
    Pl_00672C30 *p368;
    s16 h36C;
    s16 h36E;
    s16 h370[2];
} Me_00672C30;

extern G_00672C30 D_001A5E50_006702E0;
extern s32 D_L39_0024072C;
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_006702E0(Me_00672C30 *a0) {
    Msg_00672C30 m;
    s32 i;
    s32 r;
    s16 *p = a0->h370;
    Ent_00672C30 *e;

    for (i = 1; i >= 0; i--, p++) {
        if (*p != -1) {
            m.b1C = 13;
            m.w18 = (a0->p368->w2544 << 16) | *p;
            m.w10 = 16;
            m.wC = D_001A5E50_006702E0.w128;
            m.w14 = 0;
            if (D_001A5E50_006702E0.w170 == 0) {
                func_0014AD08(D_001A5E50_006702E0.b7D4 | 0x40, D_001A5E50_006702E0.w4, -1, D_L39_0024072C, 0x20, &m);
            }
            *p = -1;
        }
    }
    if (*(u8 *)((u8 *)a0->p368 + 0x458) == 0) {
        a0->h36E++;
    } else {
        a0->h36E = 0;
    }
    if (a0->h36C != 0) {
        if (a0->h36E >= 0x3D) {
            a0->h36C = 0;
        }
    }
    e = a0->p364;
    if (e != 0) {
        if (D_001A5E50_006702E0.w128 < e->w4) return;
        switch (e->b3) {
        case 1:
            a0->h36C = 1;
            a0->h36E = 0;
            r = 1;
            break;
        case 2:
            a0->h36C = 0;
            a0->h36E = 0;
            r = 1;
            break;
        default:
            r = D_001A5E50_006702E0.w128 > a0->p364->w4 + 0x1770;
            break;
        }
        if (r) {
            a0->p364->b2 = 0xFF;
            a0->p364 = a0->p364->p20;
            a0->b360--;
        }
    }
}
/* localdecomp:end func_L39_006702E0 */

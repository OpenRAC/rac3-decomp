#include "common.h"

/* localdecomp:start func_L04_003C89E0 */
typedef struct { u8 p0[0x10]; s32 w10; u8 p14[0x32]; u8 b46; } C_3C89E0_003C89E0;
typedef struct M_3C89E0_003C89E0 {
    u8 p0[0x20]; u8 b20; u8 p21[3]; C_3C89E0_003C89E0 *w24; u8 p28[9]; u8 b31; u8 p32[2]; u16 h34;
    u8 p36[0x32]; struct L_3C89E0_003C89E0 *w68; u8 p6C[0x2C]; s32 w98; u8 p9C[0xE]; s16 hAA;
} M_3C89E0_003C89E0;
typedef struct L_3C89E0_003C89E0 {
    u8 p0[0x260]; M_3C89E0_003C89E0 *w260; u8 p264[0x78]; M_3C89E0_003C89E0 *w2DC; u8 p2E0[0x1C]; M_3C89E0_003C89E0 *w2FC;
} L_3C89E0_003C89E0;
typedef struct { u8 p0[0x7C]; s8 b7C; s8 b7D; u8 p7E; s8 b7F; } S_3C89E0_003C89E0;

extern u8 *D_L04_001DFD9C_003C89E0;
__asm__(".extern D_L04_001DFD9C_003C89E0, 16");
extern s32 D_001D545C;

void func_L04_003C89E0(s32 a0, s32 a1, s32 a2) {
    S_3C89E0_003C89E0 *s = (S_3C89E0_003C89E0 *)a1;
    M_3C89E0_003C89E0 *m = (M_3C89E0_003C89E0 *)(D_L04_001DFD9C_003C89E0 + (a0 << 8));
    L_3C89E0_003C89E0 *l;

    if (m == 0 || m->b20 == 0xFE || m->b20 == 0xFD) {
        return;
    }
    if (a2 != 0) {
        if (s->b7C > 0) {
            m->h34 &= ~2;
        } else if (s->b7C < 0) {
            m->h34 |= 2;
        }
        if (s->b7D > 0 && (m == 0 || m->w24 == 0 || m->w24->b46 != 0x12)) {
            m->b31 = 1;
            m->h34 &= ~1;
        } else if (s->b7D < 0 && (m == 0 || m->w24 == 0 || m->w24->b46 != 0x12)) {
            m->b31 = 0;
            m->h34 |= 1;
        }
        if (s->b7F > 0 && m->w24 != 0) {
            m->w98 = m->w24->w10;
        } else if (s->b7F < 0 && m->w24 != 0) {
            m->w98 = 0;
        }
    } else {
        if (s->b7C > 0 && (m == 0 || m->w24 == 0 || m->w24->b46 != 0x12)) {
            m->h34 |= 2;
        } else if (s->b7C < 0 && (m == 0 || m->w24 == 0 || m->w24->b46 != 0x12)) {
            m->h34 &= ~2;
        }
        if (s->b7D > 0 && (m == 0 || m->w24 == 0 || m->w24->b46 != 0x12)) {
            m->b31 = 0;
            m->h34 |= 1;
        } else if (s->b7D < 0 && (m == 0 || m->w24 == 0 || m->w24->b46 != 0x12)) {
            m->b31 = 1;
            m->h34 &= ~1;
        }
        if (s->b7F > 0) {
            m->w98 = 0;
        } else if (s->b7F < 0) {
            m->w98 = m->w24->w10;
        }
    }
    switch (D_001D545C) {
    case 4:
        if (m->hAA == 0x16E5) {
            if ((l = m->w68) != 0 && l->w2FC != 0) {
                if (m->b31 != 0) {
                    l->w2FC->h34 &= ~1;
                    l->w2FC->b31 = 1;
                } else {
                    l->w2FC->h34 |= 1;
                    l->w2FC->b31 = 0;
                }
                if (m->w98 == 0) {
                    l->w2FC->w98 = 0;
                } else {
                    l->w2FC->w98 = l->w2FC->w24->w10;
                }
            }
        }
        break;
    case 0xE:
        if (m->hAA == 0x1612) {
            if ((l = m->w68) != 0 && l->w2DC != 0) {
                if (m->b31 != 0) {
                    l->w2DC->h34 &= ~1;
                    l->w2DC->b31 = 1;
                } else {
                    l->w2DC->h34 |= 1;
                    l->w2DC->b31 = 0;
                }
                if (m->w98 == 0) {
                    l->w2DC->w98 = 0;
                } else {
                    l->w2DC->w98 = l->w2DC->w24->w10;
                }
            }
        } else if (m->hAA == 0x1699) {
            if ((l = m->w68) != 0 && l->w260 != 0) {
                if (m->b31 != 0) {
                    l->w260->h34 &= ~1;
                    l->w260->b31 = 1;
                } else {
                    l->w260->h34 |= 1;
                    l->w260->b31 = 0;
                }
                if (m->w98 == 0) {
                    l->w260->w98 = 0;
                } else {
                    l->w260->w98 = l->w260->w24->w10;
                }
            }
        }
        break;
    }
}
/* localdecomp:end func_L04_003C89E0 */

/* localdecomp:start func_L04_003C8DA0 */
extern s16 *D_L04_0021C9A0[];
extern void func_L04_003C89E0(s32, s32, s32);

void func_L04_003C8DA0(s32 a0, s32 a1, s32 a2, s32 a3) {
    s16 *p = D_L04_0021C9A0[a2];
    if (p != 0) {
        do {
            func_L04_003C89E0(*p & 0x7fff, a1, a3);
        } while (*p++ >= 0);
    }
}
/* localdecomp:end func_L04_003C8DA0 */

INCLUDE_ASM("asm/levels", func_L04_003C8E10);

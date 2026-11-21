#include "common.h"

/* NTSC-U counterpart of func_L01_002FFCA8 (src/levels/shared/L01_002FFCA8.c): animation blend of 10 frames for 8 */
/* localdecomp:start func_L01_002FFC50 */
extern void func_003BE4F0(u8 *, s32, s32, s32);
struct O_002FFC50;
typedef struct {
    u8 pad0[0x14];
    struct O_002FFC50 *f14;
    u8 pad18[0xC];
    s32 f24;
} R_002FFC50;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    R_002FFC50 *f68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} Q_002FFC50;
typedef struct {
    Q_002FFC50 *f0;
} S_002FFC50;
typedef struct O_002FFC50 {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    u16 h34;
    u8 pad36[0x43 - 0x36];
    u8 b43;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x60 - 0x4C];
    u8 b60;
    u8 pad61[7];
    S_002FFC50 *f68;
} O_002FFC50;
extern void func_003BD360(void *);
extern void func_003C2868(void *);
extern u8 D_001A71D0[];

void func_L01_002FFC50(O_002FFC50 *p) {
    S_002FFC50 *s;

    if (p != 0) {
        s = p->f68;
        if (s != 0) {
            if (s->f0 == 0 || s->f0->hAA != 0xD0 || s->f0->b20 == 0xFE || s->f0->b20 == 0xFD ||
                s->f0->f68->f14 != p) {
                func_003BD360(p);
            } else {
                if ((s->f0->h34 & 1) != 0 || D_001A71D0[0] != 0) {
                    p->h34 |= 0x41;
                } else {
                    p->h34 &= 0xFFBE;
                }
                p->h34 |= 0x41;
                switch (p->b20) {
                case 0:
                    if (p->b60 & 2) {
                        if (p->b43 != 1) {
                            func_003BE4F0((u8 *)p, 1, 0, 10);
                        }
                        p->b20 = 1;
                        p->f48 = 1.0f;
                    }
                    break;
                case 1:
                    if (s->f0->b20 == 2) {
                        if (p->b43 != 3) {
                            func_003BE4F0((u8 *)p, 3, 0, 10);
                        }
                        p->b20 = 3;
                        p->f48 = 1.0f;
                    } else if (s->f0->b20 == 8) {
                        if (p->b43 != 2) {
                            func_003BE4F0((u8 *)p, 2, 0, 10);
                        }
                        p->b20 = 2;
                        p->f48 = 1.0f;
                    }
                    break;
                case 2:
                    if (p->b60 & 2) {
                        func_003BD360(p);
                        return;
                    }
                    break;
                case 3:
                    if (p->b60 & 2) {
                        if (p->b43 != 4) {
                            func_003BE4F0((u8 *)p, 4, 0, 10);
                        }
                        p->b20 = 4;
                    }
                    break;
                case 4:
                    if (s->f0->b20 >= 3 && s->f0->b20 <= 5) {
                        if (p->b43 != 5) {
                            func_003BE4F0((u8 *)p, 5, 0, 10);
                        }
                        p->b20 = 5;
                    }
                    break;
                case 5:
                    if (p->b60 & 2) {
                        p->f48 = 0.0f;
                    }
                    if (s->f0->b20 >= 6 && s->f0->b20 <= 7) {
                        p->f48 = 1.0f;
                        if (p->b43 != 7) {
                            func_003BE4F0((u8 *)p, 7, 0, 10);
                        }
                        p->b20 = 7;
                    }
                    break;
                case 6:
                    break;
                case 7:
                    if (!(p->b60 & 2)) {
                        break;
                    }
                default:
                    if (p->b43 != 1) {
                        func_003BE4F0((u8 *)p, 1, 0, 10);
                    }
                    p->b20 = 1;
                    break;
                }
                func_003C2868(p);
            }
        }
    }
}
/* localdecomp:end func_L01_002FFC50 */

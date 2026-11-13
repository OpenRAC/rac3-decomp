#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0052A2B8);

INCLUDE_ASM("asm/levels", func_L39_0052AA00);

/* localdecomp:start func_L39_0052B400 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_003C2F58(s32, s32, void *);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_003C7C38(u8 *);
u8 *func_L39_0052B400(u8 *a0, f32 f) {
    u8 *m;
    u8 *pv;
    m = func_003C24B0(6369, 128);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        *(f32 *)(pv + 4) = f;
        *(u8 **)pv = a0;
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        func_L01_0043B9E8(m, 128, 128, 128);
        func_003C2F58((s32)a0, 0, m + 16);
        *(u128_t *)(m + 192) = *(u128_t *)(a0 + 192);
        *(u128_t *)(m + 208) = *(u128_t *)(a0 + 208);
        *(u128_t *)(m + 224) = *(u128_t *)(a0 + 224);
        if (m[67] != 0) {
            func_003C3A10(m, 0, 0, 8);
        }
        func_003C7C38(m);
        m[32] = 0;
        *(u16 *)(m + 52) |= 5;
    }
    return m;
}
/* localdecomp:end func_L39_0052B400 */

/* localdecomp:start func_L39_0052B4E0 */
struct O_0052B4E0;
typedef struct {
    u8 pad0[0x14];
    struct O_0052B4E0 *f14;
    u8 pad18[0xC];
    s32 f24;
} R_0052B4E0;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x68 - 0x21];
    R_0052B4E0 *f68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} Q_0052B4E0;
typedef struct {
    Q_0052B4E0 *f0;
} S_0052B4E0;
typedef struct O_0052B4E0 {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x43 - 0x21];
    u8 b43;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x60 - 0x4C];
    u8 b60;
    u8 pad61[7];
    S_0052B4E0 *f68;
} O_0052B4E0;
extern void func_003C2880(void *);
extern void func_003C7DD8(void *);

void func_L39_0052B4E0(O_0052B4E0 *p) {
    S_0052B4E0 *s;

    if (p != 0) {
        s = p->f68;
        if (s != 0) {
            if (s->f0 == 0 || s->f0->hAA != 0x18DF || s->f0->b20 == 0xFE || s->f0->b20 == 0xFD ||
                s->f0->f68->f14 != p) {
                func_003C2880(p);
            } else if (s->f0->f68->f24 != 0) {
                switch (p->b20) {
                case 0:
                    if (p->b60 & 2) {
                        if (p->b43 != 1) {
                            func_003C3A10((u8 *)p, 1, 0, 8);
                        }
                        p->b20 = 1;
                        p->f48 = 1.0f;
                    }
                    break;
                case 1:
                    if (s->f0->b20 == 2) {
                        if (p->b43 != 3) {
                            func_003C3A10((u8 *)p, 3, 0, 8);
                        }
                        p->b20 = 3;
                        p->f48 = 1.0f;
                    } else if (s->f0->b20 == 8) {
                        if (p->b43 != 2) {
                            func_003C3A10((u8 *)p, 2, 0, 8);
                        }
                        p->b20 = 2;
                        p->f48 = 1.0f;
                    }
                    break;
                case 2:
                    if (p->b60 & 2) {
                        func_003C2880(p);
                        return;
                    }
                    break;
                case 3:
                    if (p->b60 & 2) {
                        if (p->b43 != 4) {
                            func_003C3A10((u8 *)p, 4, 0, 8);
                        }
                        p->b20 = 4;
                    }
                    break;
                case 4:
                    if (s->f0->b20 >= 3 && s->f0->b20 <= 5) {
                        if (p->b43 != 5) {
                            func_003C3A10((u8 *)p, 5, 0, 8);
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
                            func_003C3A10((u8 *)p, 7, 0, 8);
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
                        func_003C3A10((u8 *)p, 1, 0, 8);
                    }
                    p->b20 = 1;
                    break;
                }
                func_003C7DD8(p);
            }
        }
    }
}
/* localdecomp:end func_L39_0052B4E0 */

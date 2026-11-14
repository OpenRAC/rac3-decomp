/* func_L04_00360DF0 (NTSC-U counterpart of func_L04_00361DF8): MATCH with the PAL file's flags (-mvu0-use-vf0-vf2 ... @ps2as), no divs row.
   Retail keeps the truncated (s32)pv->f30 in the same register as the hero pointer (s0): one variable, hp, holds both. */
#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern void func_003C26C8(void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L04_00361560(void *);
extern s32 func_L04_00360DB0(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_0044CB08(void *, void *, s32, s32);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00442AA8(s32, s32);
extern void func_L04_003617C0(void *);
extern s32 func_L01_0044F5E8(void *, void *, s32);
extern void func_L01_00456960(s32);
extern void func_L01_004538E0(void *, s32);
extern s32 func_L01_004539A8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_00453210(void *, s32);

/* localdecomp:start func_L04_00360DF0 */
typedef struct { u8 p0[0x6C]; f32 f6C; u8 p70[0x80]; } T_360DF0;
extern u8 D_L04_001E28C0[];
extern u8 *D_001E0EF8_sda;
extern s32 D_001D545C_sda_00360DF0;
extern s32 D_001D67C4_sda;
extern s32 D_001DF9C0_sda;
extern u8 D_00142637[];
__asm__(".extern D_00142637, 16");
extern T_360DF0 D_L04_002C5F80[];
extern u8 D_001A4BE0[];

s32 func_L04_00360DF0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 **pp;
    s32 i;
    s32 ival;
    f32 fl;
    s32 r;
    s32 x;
    s32 tix;
    T_360DF0 *row;
    s32 cnt;
    u8 *hp;
    u8 *hero;

    if (*(f32 *)(pv + 0x30) > 0.0f) {
        pp = (u8 **)(pv + 0x4B0);
        for (i = 0; i < 8; i++) {
            if (pp[i] != 0) {
                *(s32 *)(pp[i] + 0x98) = *(s32 *)(*(u8 **)(pp[i] + 0x24) + 0x10);
                func_003C26C8(pp[i]);
            }
        }
    }
    if (a0[0x31] != 0) {
        if (func_L01_0040C018(D_L04_001E28C0, a0 + 0x10) < 576.0f) {
            func_L01_00444188(a0);
            a0[0x6F] = 0x16;
        }
    }
    if (pv[0x3E] == 2) {
        func_L04_00361560(a0);
        return 1;
    }
    if (pv[0x61] == 0x3F) {
        if (func_L04_00360DB0(a0, pv) != 0) {
            func_L01_00441FB8(a0, 0x1D, -1);
            if (a0[0x43] != 0x14) {
                func_003BE4F0(a0, 0x14, 1, 3);
            }
        }
    }
    if (D_001E0EF8_sda != 0) {
        if (func_L04_00360DB0(a0, pv) != 0) {
            if (func_00388800(a0 + 0x10, D_001E0EF8_sda + 0x10) < 6.0f) {
                tix = D_00142637[0];
                row = D_L04_002C5F80 + tix;
                if (*(f32 *)(pv + 0x30) <= row->f6C) {
                    func_L01_00441FB8(a0, 0x1D, -1);
                    if (a0[0x43] != 0x14) {
                        func_003BE4F0(a0, 0x14, 1, 3);
                    }
                }
            }
        }
    }
    if (*(void **)(pv + 0x2FC) != 0) {
        func_L01_0044CB08(a0, *(void **)(pv + 0x2FC), 0, 0);
    }
    hp = (u8 *)(s32)*(f32 *)(pv + 0x30);
    if (*(s32 *)(pv + 0x4E4) != 0) {
        fl = (f32)(s32)hp;
        r = func_L01_0044FCD0(a0, pv + 0x160, 0, 0, 1);
        if (r != 0) {
            if (r >= 2) {
                func_0039FE80(5, 0, a0);
            }
            pp = (u8 **)(pv + 0x4B0);
            for (i = 0; i < 8; i++) {
                if (pp[i] != 0) {
                    *(s32 *)(pp[i] + 0x98) = 0;
                    func_003C26C8(pp[i]);
                }
            }
            if (a0[0x21] != 0xFF) {
                func_L01_00442AA8(a0[0x21], 0);
            }
            func_L04_003617C0(a0);
        }
    } else {
        fl = (f32)(s32)hp;
        r = func_L01_0044FCD0(a0, pv + 0x160, 0, 0, 0);
        if (r != 0) {
            func_0039FE80(5, 0, a0);
            pp = (u8 **)(pv + 0x4B0);
            for (i = 0; i < 8; i++) {
                if (pp[i] != 0) {
                    *(s32 *)(pp[i] + 0x98) = 0;
                    func_003C26C8(pp[i]);
                }
            }
            if (a0[0x21] != 0xFF) {
                func_L01_00442AA8(a0[0x21], 0);
            }
            func_L04_003617C0(a0);
        }
    }
    if (*(f32 *)(pv + 0x30) < fl) {
        *(s32 *)(pv + 0x2F8) = 1;
        func_L04_003617C0(a0);
    }
    func_L01_0044F5E8(a0, pv + 0x30, 0);
    if (pv[0x5F] != 0) {
        if (D_001D545C_sda_00360DF0 == 0x16) {
            if (*(s32 *)(pv + 0x50C) == 0) {
                cnt = D_001D67C4_sda;
                *(s32 *)(pv + 0x50C) = 1;
                cnt = cnt + 1;
                D_001D67C4_sda = cnt;
                if (cnt >= 15) {
                    func_L01_00456960(0x17);
                }
            }
        }
    }
    if (pv[0x5E] != 0) {
        func_L04_00361560(a0);
        return 1;
    }
    if (!((*(unsigned long *)(a0 + 0x30) & 0x104100000000UL) == 0x4100000000UL && *(s32 *)(a0 + 0x98) == 0)) {
        if (*(f32 *)(pv + 0x30) > 0.0f) {
            if (pv[0x5F] != 0) {
                func_L01_004538E0(a0, 5);
            } else if (D_001D545C_sda_00360DF0 != 9 || *(s16 *)(a0 + 0xB2) == 0xCA || a0[0x95] == 3 || a0[0x95] == 5) {
                func_L01_004538E0(a0, 3);
            }
        }
    }
    x = D_001DF9C0_sda;
    if ((*(s16 *)(a0 + 0xB2) + 8) % 8 == x % 8) {
        if (pv[0x5F] != 0) {
            if (a0[0x95] == 1) {
                func_L01_004539A8(a0, *(s32 *)(pv + 0x2E0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(pv + 0x2E4), 10.0f, 1.0f);
            } else {
                func_L01_004539A8(a0, *(s32 *)(pv + 0x2E8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(pv + 0x2EC), 10.0f, 1.0f);
            }
        } else if (a0[0x95] == 1 || a0[0x95] == 8) {
            func_L01_004539A8(a0, *(s32 *)(pv + 0x2E0), 0, 0, 0, 0, 1, *(s32 *)(pv + 0x500) != 0, 0, *(s32 *)(pv + 0x510) != 0, *(f32 *)(pv + 0x2E4), 10.0f, 1.0f);
        } else {
            func_L01_004539A8(a0, *(s32 *)(pv + 0x2E8), 0, 0, 0, 0, 1, *(s32 *)(pv + 0x500) != 0, 0, *(s32 *)(pv + 0x510) != 0, *(f32 *)(pv + 0x2EC), 10.0f, 1.0f);
        }
    }
    if (*(s32 *)(pv + 0x4D0) == -1) {
        return 0;
    }
    if (*(s32 *)(pv + 0x4D4) == -1) {
        return 0;
    }
    if (*(s16 *)(pv + 0x234) == 1) {
        if (D_001D545C_sda_00360DF0 != 0x1D) {
            goto fail;
        }
    }
    if (a0[0x95] != 1 && a0[0x95] != 4 && a0[0x95] != 2) {
        if (D_001D545C_sda_00360DF0 != 0x1D) {
            return 0;
        }
        if (a0[0x95] != 3) {
            return 0;
        }
    }
    hp = D_001A4BE0 + 0x80;
    if (func_L01_00453210(hp, *(s32 *)(pv + 0x4D0)) != 0) {
        hero = hp - 0x80;
        *(s32 *)(pv + 0x4D8) = 1;
        *(s32 *)(pv + 0x230) = *(s32 *)(hero + 0x25C0);
        *(u128_t *)(pv + 0x220) = *(u128_t *)(hero + 0xD0);
    } else {
        *(s32 *)(pv + 0x4D8) = 0;
    }
fail:
    return 0;
}
/* localdecomp:end func_L04_00360DF0 */

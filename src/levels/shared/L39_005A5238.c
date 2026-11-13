#include "common.h"

typedef struct S_005A5238 {
    u8 pad_000[0x164];
    s32 f164;
    s32 f168;
} S_005A5238;

typedef struct S_005A57F8 {
    u8 pad0[0x18];
    u16 f18;
    u8 pad1[0x148 - 0x1A];
    s32 f148;
    u8 pad2[0x15C - 0x14C];
    s32 f15C;
    u8 pad3[0x164 - 0x160];
    s32 f164;
    u8 pad4[0x16C - 0x168];
    s32 f16C;
} S_005A57F8;

typedef struct {
    u8 pad[0x10];
    s32 f10;
    u8 pad2[0x150];
    s32 f164;
    s32 f168;
} S_005A53D0;

typedef struct {
    u8 pad0[0x15C];
    s32 mode_15c;
    u8 pad1[4];
    s32 selected_164;
    u8 pad2[4];
    s32 extra_16c;
} S_005A5400;

typedef struct S_005A54A0 {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x148];
    s32 f15C;
    s32 f160;
    s32 f164;
    s32 f168;
} S_005A54A0;

typedef struct S_005A54F8 {
    u8 pad_00[8];
    s32 f08;
    s32 f0C;
    u8 pad_10[8];
    s16 f18;
    u8 pad_1A[6];
    s32 f20;
    u8 pad_24[0x138];
    s32 f15C;
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
} S_005A54F8;

typedef struct {
    u8 pad0[0x15C];
    s32 f15C;
    u8 pad1[0x164 - 0x160];
    s32 f164;
    s32 f168;
} S_005A5798;

/* localdecomp:start func_L39_005A5238 */
extern S_005A5238 D_001A43E0;

void func_L39_005A5238(void) {
    D_001A43E0.f164 = -1;
    *(s32 *)0x2403F8 = 6;
    D_001A43E0.f168 = -1;
}
/* localdecomp:end func_L39_005A5238 */

/* localdecomp:start func_L39_005A5260 */
extern S_005A5238 D_001A43E0;

void func_L39_005A5260(void) {
    D_001A43E0.f164 = -1;
    *(s32 *)0x2403F8 = 6;
    D_001A43E0.f168 = -1;
}
/* localdecomp:end func_L39_005A5260 */

/* localdecomp:start func_L39_005A5288 */
extern s32 D_002403F8;
extern s32 D_002403FC;

void func_L39_005A5288(void) {
    s32 *s = (s32 *)&D_001A43E0;

    D_002403FC = D_002403FC & ~0x20;
    if (s[2] == 2) {
        if (s[5] == 0) {
            D_002403F8 = 7;
        } else if (s[4] != 0) {
            s[4] = 0;
            D_002403F8 = 0xB;
        } else {
            D_002403F8 = 0xB;
        }
    }
}
/* localdecomp:end func_L39_005A5288 */

/* localdecomp:start func_L39_005A52F0 */
extern s32 D_001A43E8[];
extern s32 D_001D4CE8_sda;
extern u8 D_001D729D_sda;
extern s32 D_002403F8;
extern s32 D_002403FC;

void func_L39_005A52F0(void) {
    if (D_001A43E8[0] != 2) {
        D_001D4CE8_sda = 4;
        return;
    }
    if (D_001D729D_sda != 0 || (D_002403FC & 0x12) != 0) {
        D_002403F8 = 8;
    }
}
/* localdecomp:end func_L39_005A52F0 */

/* localdecomp:start func_L39_005A5340 */
extern s32 D_001A43E8[];
extern s32 D_002403FC;
extern s32 D_002403F8;
extern u8 D_L39_002429AC;
extern s32 D_001D4CE8_sda;
extern void func_0039C028(void);

void func_L39_005A5340(void) {
    if (D_001A43E8[0] != 2) {
        D_001D4CE8_sda = 4;
        return;
    }
    if (D_002403FC & 0x20) {
        func_0039C028();
        if (D_L39_002429AC != 0) {
            D_001D4CE8_sda = 0x1A;
        } else {
            D_001D4CE8_sda = 7;
        }
        return;
    }
    if (D_002403FC & 8) {
        D_002403FC = D_002403FC ^ 8;
        D_002403F8 = 9;
    }
}
/* localdecomp:end func_L39_005A5340 */

/* localdecomp:start func_L39_005A53D0 */
extern s32 D_001D4CE8_sda;

void func_L39_005A53D0(void) {
    S_005A53D0 *p = (S_005A53D0 *)&D_001A43E0;
    p->f10 = 0;
    if (p->f164 < 0) {
        p->f168 = 0;
        p->f164 = 3;
    }
    D_001D4CE8_sda = 10;
}
/* localdecomp:end func_L39_005A53D0 */

/* localdecomp:start func_L39_005A5400 */
extern s32 D_001D4CEC_sda;

void func_L39_005A5400(void) {
    S_005A5400 *p = (S_005A5400 *)&D_001A43E0;
    if (p->mode_15c != 2 || p->selected_164 >= 0)
        return;
    if (p->extra_16c != 0) {
        *(s32 *)0x2403F8 = 0x13;
        D_001D4CEC_sda = *(s32 *)0x2403FC | 0x40;
        return;
    }
    *(s32 *)0x2403F8 = 0x10;
}
/* localdecomp:end func_L39_005A5400 */

/* localdecomp:start func_L39_005A5460 */
extern int D_001A43E8[];
extern int D_001D4CE8_sda;
extern int D_001D4CEC_sda;
extern int D_002403F8;

void func_L39_005A5460(void)
{
    if (D_001A43E8[0] != 2) {
        D_001D4CE8_sda = 4;
        return;
    }
    if (D_001D4CEC_sda & 0x806)
        D_002403F8 = 12;
}
/* localdecomp:end func_L39_005A5460 */

/* localdecomp:start func_L39_005A54A0 */
extern s32 D_001D4CEC_sda;

void func_L39_005A54A0(void)
{
    S_005A54A0 *p = (S_005A54A0 *)&D_001A43E0;

    if (p->f15C == 2 && p->f164 < 0) {
        p->f10 = 0;
        p->f164 = 7;
        p->f168 = 0;
        *(s32 *)0x002403F8 = 13;
        *(s32 *)0x002403FC = D_001D4CEC_sda & ~0x800;
    }
}
/* localdecomp:end func_L39_005A54A0 */

/* localdecomp:start func_L39_005A54F8 */
extern s32 D_001D4CE8_sda;

void func_L39_005A54F8(void) {
    S_005A54F8 *p = (S_005A54F8 *)&D_001A43E0;
    s16 phase;

    if (p->f15C != 2 || p->f164 >= 0) {
        return;
    }
    if (p->f16C != 0) {
        D_001D4CE8_sda = 14;
        return;
    }
    if (p->f08 != 2) {
        D_001D4CE8_sda = 4;
        return;
    }
    phase = p->f18;
    if (phase == -2) {
        if (p->f0C + p->f20 < 600) {
            D_001D4CE8_sda = 21;
        } else {
            D_001D4CE8_sda = 14;
        }
        return;
    }
    if (phase >= -1) {
        *(s32 *)0x2403F8 = 18;
    }
}
/* localdecomp:end func_L39_005A54F8 */

/* localdecomp:start func_L39_005A5590 */
extern s32 D_001D4CEC_sda;
extern s32 D_002403F8;
extern s32 D_002403FC;

void func_L39_005A5590(void)
{
    S_005A54A0 *p = (S_005A54A0 *)&D_001A43E0;

    if (p->f15C == 2 && p->f164 < 0) {
        p->f10 = 0;
        p->f164 = 7;
        p->f168 = 0;
        D_002403F8 = 0x20;
        D_002403FC = D_001D4CEC_sda & ~0x800;
    }
}
/* localdecomp:end func_L39_005A5590 */

/* localdecomp:start func_L39_005A55E8 */
__asm__(".extern D_001D4CEC_sda, 4");
__asm__(".extern D_001D7990_sda, 4");
__asm__(".extern D_001D79A4_sda, 4");
extern s32 D_001D4CEC_sda;
extern s32 D_001D7990_sda;
extern void (*D_001D79A4_sda)(void);
extern s32 D_002403F8;
extern s32 D_002403FC;

void func_L39_005A55E8(void) {
    S_005A54F8 *p = (S_005A54F8 *)&D_001A43E0;
    void (*cb)(void);
    s16 phase;
    s32 w;
    u16 h;

    if (p->f15C == 2 && p->f164 < 0) {
        if (p->f16C != 0) {
            D_002403F8 = 0x18;
            D_001D4CEC_sda = D_001D4CEC_sda | 0x40;
        } else if (p->f08 != 2) {
            D_002403F8 = 4;
        } else {
            phase = p->f18;
            if (phase == -2) {
                if (p->f0C + p->f20 < 600) {
                    D_002403F8 = 0x15;
                } else {
                    D_002403F8 = 0x18;
                    D_001D4CEC_sda = D_002403FC | 0x40;
                }
            } else if (phase >= -1) {
                if (phase == -1) {
                    w = D_002403FC;
                    if (w & 0x1000) {
                        h = D_001D7990_sda;
                        D_001D7990_sda = -1;
                        p->f18 = h;
                        D_002403FC = w & ~0x1000;
                    }
                }
                D_002403F8 = 0x12;
            }
        }
        cb = D_001D79A4_sda;
        if (cb != 0) {
            cb();
            D_001D79A4_sda = 0;
        }
    }
}
/* localdecomp:end func_L39_005A55E8 */

/* localdecomp:start func_L39_005A56E8 */
extern int D_001A43E8[];
extern int D_001D4CE8_sda;
extern int D_001D4CEC_sda;
extern int D_002403F8;

void func_L39_005A56E8(void) {
    if (D_001A43E8[0] != 2) {
        D_001D4CE8_sda = 4;
        return;
    }
    if (D_001D4CEC_sda & 0x12) {
        D_002403F8 = 0xF;
    }
}
/* localdecomp:end func_L39_005A56E8 */

/* localdecomp:start func_L39_005A5728 */
extern s32 D_001A43E8[];
extern s32 D_002403FC;
extern s32 D_002403F8;
extern u8 D_L39_002429AC;
extern s32 D_001D4CE8_sda;

void func_L39_005A5728(void) {
    if (D_001A43E8[0] != 2) {
        D_001D4CE8_sda = 4;
        return;
    }
    if (D_002403FC & 0x20) {
        D_002403FC = D_002403FC ^ 0x20;
        if (D_L39_002429AC != 0) {
            D_001D4CE8_sda = 0x1B;
        } else {
            D_001D4CE8_sda = 0xE;
        }
        return;
    }
    if (D_002403FC & 0x2000) {
        D_002403F8 = 0x10;
    }
}
/* localdecomp:end func_L39_005A5728 */

/* localdecomp:start func_L39_005A5798 */
extern s32 D_001D4CEC_sda;

void func_L39_005A5798(void)
{
    S_005A5798 *p = (S_005A5798 *)&D_001A43E0;
    s32 v;

    if (p->f15C == 2 && p->f164 < 0) {
        v = D_001D4CEC_sda;
        v &= ~2;
        v &= ~0x10;
        p->f164 = 9;
        *(s32 *)0x002403FC = v;
        p->f168 = 0;
        *(s32 *)0x002403F8 = 0x11;
    }
}
/* localdecomp:end func_L39_005A5798 */

/* localdecomp:start func_L39_005A57F8 */
extern s32 D_001D4CEC_sda;

void func_L39_005A57F8(void)
{
    S_005A57F8 *s = (S_005A57F8 *)&D_001A43E0;

    if (s->f15C != 2 || s->f164 >= 0)
        return;
    if (s->f16C != 0) {
        D_001D4CEC_sda = *(s32 *)0x2403FC | 0x40;
        *(s32 *)0x2403F8 = 0x14;
    } else {
        s->f148 = 0;
        *(s32 *)0x2403F8 = 0x1F;
        s->f18 = 0;
    }
}
/* localdecomp:end func_L39_005A57F8 */

/* localdecomp:start func_L39_005A5860 */
__asm__(".extern D_001D79A8_sda, 4");
__asm__(".extern D_001D7994_sda, 4");
extern s32 D_001D4CEC_sda;
extern s32 D_001D79A8_sda;
extern void (*D_001D7994_sda)(void);
extern void func_0039C028(void);

void func_L39_005A5860(void) {
    u8 *base = (u8 *)&D_001A43E0;
    void (*fp)(void);
    s32 idx;
    s32 e;
    s32 v;
    u16 h;

    if (*(s32 *)(base + 0x15C) == 2) {
        if (*(s32 *)(base + 0x164) < 0) {
            idx = D_001D79A8_sda;
            e = *(s32 *)(base + idx * 0x1C + 0x30);
            if (e == -1 || (D_001D4CEC_sda & 0x6000) != 0) {
                func_0039C028();
                fp = D_001D7994_sda;
                v = *(s32 *)0x002403FC & ~0x4000;
                D_001D4CEC_sda = v;
                if (fp != 0) {
                    fp();
                    D_001D7994_sda = 0;
                }
                h = D_001D79A8_sda;
                *(s32 *)0x002403F8 = 0x19;
                *(u16 *)(base + 0x18) = h;
            } else {
                *(s32 *)0x002403F8 = 0x21;
            }
        }
    }
}
/* localdecomp:end func_L39_005A5860 */

/* localdecomp:start func_L39_005A5920 */
__asm__(".extern D_001D799C_sda, 4");
__asm__(".extern D_001D79A8_sda, 4");
extern void (*D_001D799C_sda)(void);
extern s32 D_001D79A8_sda;
extern s32 D_002403F8;

typedef struct S_005A5920 {
    u8 pad0[0x18];
    u16 f18;
    u8 pad1[0x148 - 0x1A];
    s32 f148;
    u8 pad2[0x15C - 0x14C];
    s32 f15C;
    u8 pad3[0x164 - 0x160];
    s32 f164;
} S_005A5920;

void func_L39_005A5920(void) {
    S_005A5920 *p = (S_005A5920 *)&D_001A43E0;
    void (*fp)(void);

    if (p->f15C == 2 && p->f164 < 0) {
        fp = D_001D799C_sda;
        if (fp != 0) {
            fp();
            D_001D799C_sda = 0;
        }
        p->f18 = D_001D79A8_sda;
        p->f148 = 0;
        D_002403F8 = 0x17;
    }
}
/* localdecomp:end func_L39_005A5920 */

INCLUDE_ASM("asm/levels", func_L39_005A5990);

INCLUDE_ASM("asm/levels", func_L39_005A5A0C);

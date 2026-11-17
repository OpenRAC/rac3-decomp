#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    u8 pad[0x18];
    s32 f20;
    s32 f24;
} S_0041A528;

/* localdecomp:start func_L01_0041A4C0 */
extern s32 D_L01_001D6674;

s32 func_L01_0041A4C0(void) {
    return D_L01_001D6674 != 0;
}
/* localdecomp:end func_L01_0041A4C0 */

LINKER_REMNANT("asm/levels", func_L01_0041A4D0);

/* localdecomp:start func_L01_0041A4F0 */
extern u8 D_00142692[];

s32 func_L01_0041A4F0(void) {
    return D_00142692[0] != 0;
}
/* localdecomp:end func_L01_0041A4F0 */

LINKER_REMNANT("asm/levels", func_L01_0041A500);

/* localdecomp:start func_L01_0041A508 */
extern u8 D_L01_001D551C;

void func_L01_0041A508(void) {
    D_L01_001D551C = 0;
}
/* localdecomp:end func_L01_0041A508 */

LINKER_REMNANT("asm/levels", func_L01_0041A510);

/* localdecomp:start func_L01_0041A518 */
s32 func_L01_0041A518(s32 a0) {
    return (u32)(a0 - 30) < 7;
}
/* localdecomp:end func_L01_0041A518 */

/* localdecomp:start func_L01_0041A528 */
extern S_0041A528 D_L01_002E5F30_0041A528;

void func_L01_0041A528(void) {
    switch (D_L01_002E5F30_0041A528.f0) {
    case 0:
        D_L01_002E5F30_0041A528.f24 = -1;
        return;
    case 1:
    case 2:
        D_L01_002E5F30_0041A528.f0 = 7;
        D_L01_002E5F30_0041A528.f4 = 0;
        return;
    case 3:
        D_L01_002E5F30_0041A528.f0 = 7;
        D_L01_002E5F30_0041A528.f4 = 0;
        return;
    case 4:
        D_L01_002E5F30_0041A528.f0 = 6;
        D_L01_002E5F30_0041A528.f4 = 4 - D_L01_002E5F30_0041A528.f4;
        return;
    case 5:
        D_L01_002E5F30_0041A528.f0 = 6;
        D_L01_002E5F30_0041A528.f4 = 0;
        return;
    case 7:
        return;
    }
}
/* localdecomp:end func_L01_0041A528 */

/* localdecomp:start func_L01_0041A5B0 */
typedef struct {
    s32 f0;
    u8 pad[32];
    s32 f24;
    s32 f28;
    u8 pad2[20];
    s32 f40;
    s32 f44;
} S_00417F60;

typedef struct {
    u8 pad[36];
    s32 f24;
    u8 pad2[68];
    s32 f6C;
    u8 pad3[36];
    s32 f94;
} P_00417F60;

typedef struct {
    u16 h0;
    u8 pad[6];
    u32 x8;
} T_00417F60;

extern S_00417F60 D_L01_002E5F30;
extern P_00417F60 D_001CCFD0;
extern T_00417F60 D_001A7E18[];
extern s32 D_L01_001D6694;
extern s32 D_L01_001DFB40;
extern void func_L01_0041BD48(s32);

s32 func_L01_0041A5B0(s32 id, s32 idx) {
    S_00417F60 *s = &D_L01_002E5F30;
    P_00417F60 *p;

    if (s->f0 != 0) {
        return 0;
    }
    if (s->f24 == -1) {
        p = &D_001CCFD0;
        if (p->f6C == 0 && p->f24 == s->f24 && p->f94 == 0) {
            if (D_001A7E18[idx].h0 == 0xFFFF || D_L01_001D6694 == 6 || D_L01_001DFB40 < 6) {
                return 0;
            }
            s->f28 = idx;
            s->f24 = id;
            s->f40 = 0;
            s->f44 = 0;
            func_L01_0041BD48(id);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0041A5B0 */

INCLUDE_ASM("asm/levels", func_L01_0041A678);

/* localdecomp:start func_L01_0041A6B0 */
extern u8 D_001638C8[];

void *func_L01_0041A6B0(void) {
    return D_001638C8;
}
/* localdecomp:end func_L01_0041A6B0 */

INCLUDE_ASM("asm/levels", func_L01_0041A6BC);

/* localdecomp:start func_L01_0041A6C8 */
extern u8 D_00164548[];

void *func_L01_0041A6C8(void) {
    return D_00164548;
}
/* localdecomp:end func_L01_0041A6C8 */

INCLUDE_ASM("asm/levels", func_L01_0041A6D4);

/* localdecomp:start func_L01_0041A6E0 */
extern S_0041A528 D_L01_002E5F30_0041A6E0;
extern u32 *func_L01_0041A678(void);
extern u8 *D_L01_001DFCC0;
extern u8 D_L01_001CCFD0[];
__asm__(".extern D_L01_001DFCC0, 4");

void func_L01_0041A6E0(void) {
    S_0041A528 *s = &D_L01_002E5F30_0041A6E0;
    u32 *tab;
    s32 idx;
    u8 *c;

    if (D_L01_002E5F30_0041A6E0.f0 != 0) {
        tab = func_L01_0041A678();
        if (s->f20 != -1) {
            idx = *(s32 *)(D_L01_001DFCC0 + s->f20 * 16 + 8);
            if (idx != -1 && tab[idx] != 0) {
                c = D_L01_001CCFD0;
                if (idx == *(s16 *)(c + 0x98) - 0x1B58 || idx == *(s16 *)(c + 0x70) - 0x1B58) {
                    if ((u16)(*(u16 *)(c + 0x76) - 6) >= 2) {
                        *(s16 *)(c + 0x76) = 5;
                    }
                    if ((u16)(*(u16 *)(c + 0x9E) - 6) >= 2) {
                        *(s16 *)(c + 0x9E) = 5;
                    }
                }
            }
        }
        D_L01_002E5F30_0041A6E0.f0 = 0;
        D_L01_002E5F30_0041A6E0.f24 = -1;
        D_L01_002E5F30_0041A6E0.f20 = -1;
        D_L01_002E5F30_0041A6E0.f4 = 0;
    }
}
/* localdecomp:end func_L01_0041A6E0 */

/* localdecomp:start func_L01_0041A7D0 */
void func_L01_0041A7D0(void) {
    s32 i;
    for (i = 0; i < 0x164; i++) {
        D_001A7E18[i].x8 &= 0x7FFFFFFF;
    }
}
/* localdecomp:end func_L01_0041A7D0 */

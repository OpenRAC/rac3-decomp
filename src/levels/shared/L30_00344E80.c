#include "common.h"

/* localdecomp:start func_L30_00344E80 */
typedef struct {
    u8 pad_0[0x130];
    f32 p130[4];            /* 0x130 */
    f32 p140[4];            /* 0x140 */
    f32 p150[4];            /* 0x150 */
    f32 f160;               /* 0x160 */
    f32 f164;               /* 0x164 */
    f32 pad_168[2];
    f32 f170;               /* 0x170 */
    f32 f174;               /* 0x174 */
    f32 f178;               /* 0x178 */
    u8 pad_17C[0x180 - 0x17C];
    s32 timer;              /* 0x180 */
    u8 pad_184[0x194 - 0x184];
    s32 side;               /* 0x194 */
    u8 pad_198[0x1A0 - 0x198];
    s32 sound;              /* 0x1A0 */
    u8 pad_1A4[0x1B5 - 0x1A4];
    u8 b1B5;                /* 0x1B5 */
    u8 b1B6;                /* 0x1B6 */
    u8 b1B7;                /* 0x1B7 */
} Vars_00344E80;

typedef struct {
    u8 pad_0[0x88];
    f32 z;                  /* 0x88 */
    u8 pad_8C[0x35C - 0x8C];
    u8 *p35C;               /* 0x35C */
    u8 pad_360[0x36E - 0x360];
    s16 h36E;               /* 0x36E */
} Hero_00344E80;

extern Hero_00344E80 D_1A4BE0;
extern u8 D_1A30B0[];
extern s32 D_L30_001DCE94;
extern s32 D_L30_001DCE98;
extern f32 D_L30_001DCF14;

extern s32 func_L01_004561B8(u8 *);
extern void func_L30_003434E8(u8 *);
extern f32 func_0038CF00(void *, void *);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L05_00328FF8(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L30_003435C0(u8 *);
extern void func_L30_00343798(u8 *, f32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);

void func_L30_00344E80(u8 *moby)
{
    Vars_00344E80 *pv = *(Vars_00344E80 **)(moby + 0x68);
    u8 state = moby[0x20];
    s32 saved;
    f32 t;
    f32 r;
    u8 *e;

    switch (state) {
    case 0xB:
        if (func_L01_004561B8(moby) != 0) {
            if (pv->b1B7 == 0) {
                pv->side = (pv->side + 1) % 2;
            }
            pv->b1B7 = 0;
            pv->b1B5 = 1;
            pv->timer = 0;
        }
        func_L30_003434E8(moby);
        if (*(s16 *)(moby + 0xAA) == 0x19B9) {
            if ((pv->side != 0 && func_0038CF00(pv->p130, pv->p150) <= 0.0f)
                || (pv->side == 0 && func_0038CF00(pv->p130, pv->p140) <= 0.0f)) {
                if (pv->sound != -1) {
                    e = D_1A30B0 + (pv->sound << 7);
                    if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                        func_003A4F28(pv->sound);
                    }
                }
                pv->sound = -1;
            } else {
                if (pv->sound != -1) {
                    e = D_1A30B0 + (pv->sound << 7);
                    if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                        goto skip;
                    }
                }
                pv->sound = func_003A52A0(0, 4, moby);
            }
        }
    skip:
        if (func_L05_00328FF8(moby) == 0) {
            if (pv->b1B5 != 0) {
                pv->b1B5 = 0;
                pv->timer = 0;
            } else {
                pv->timer++;
            }
            if (pv->timer > D_L30_001DCE94) {
                pv->b1B7 = 1;
                func_L01_004450F0(moby, 0xC, -1);
            }
        } else {
            if (pv->b1B5 == 0) {
                pv->timer = 0;
                pv->b1B5 = 1;
            } else if ((pv->side != 0 && func_0038CF00(pv->p130, pv->p150) <= 0.0f)
                       || (pv->side == 0 && func_0038CF00(pv->p130, pv->p140) <= 0.0f)) {
                pv->timer++;
            }
            if (pv->timer > D_L30_001DCE98) {
                pv->timer = 0;
                pv->side = !pv->side;
            }
        }
        break;
    case 0xC:
        if (pv->b1B7 == 0 || pv->b1B6 == 0xFF) {
            func_L30_003435C0(moby);
        } else {
            saved = pv->side;
            pv->side = pv->b1B6;
            if (pv->p130[2] < D_1A4BE0.z - D_L30_001DCF14) {
                r = func_0038CF00(pv->p130, pv->p140);
                r = r / func_0038CF00(pv->p140, pv->p150);
                t = r;
                func_003C41A0(&t, &pv->f164, r, pv->f170, pv->f174, pv->f178);
                if (t > 1.0f) {
                    t = 1.0f;
                } else if (t < 0.0f) {
                    t = 0.0f;
                }
                func_L30_00343798(moby, t);
                pv->side = saved;
            } else {
                func_L30_003434E8(moby);
                pv->side = saved;
            }
        }
        if (D_1A4BE0.h36E == 0 && D_1A4BE0.p35C == moby) {
            func_L01_004450F0(moby, 0xB, -1);
        }
        break;
    }
    if (*(s16 *)(moby + 0xAA) == 0x1B16) {
        if (moby[0x20] == 0xB && pv->f164 > 0.0f) {
            if (pv->sound != -1) {
                e = D_1A30B0 + (pv->sound << 7);
                if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                    return;
                }
            }
            pv->sound = func_003A52A0(0, 4, moby);
        } else if (moby[0x20] == 0xB && pv->f164 < 0.0f) {
            if (pv->sound != -1) {
                e = D_1A30B0 + (pv->sound << 7);
                if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                    return;
                }
            }
            pv->sound = func_003A52A0(1, 4, moby);
        } else {
            if (pv->sound != -1) {
                e = D_1A30B0 + (pv->sound << 7);
                if (*(u8 **)(e + 0xDC) == moby && e[0xD0] != 0) {
                    func_003A4F28(pv->sound);
                }
            }
            pv->sound = -1;
        }
    }
}
/* localdecomp:end func_L30_00344E80 */

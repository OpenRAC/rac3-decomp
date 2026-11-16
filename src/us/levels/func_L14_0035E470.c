#include "common.h"

/* NTSC-U counterpart of func_L14_0035E0E8 (src/levels/shared/L14_0035E0E8.c) */
/* localdecomp:start func_L14_0035E470 */
extern s32 func_0037E1D8(s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004A6DF8(void *, s32);

/* Initialises a walking enemy moby's state block: sets default speeds, angles and flags, calls
 * walker_set_params, then picks its starting state (1, 0xA or 0xC) from the preset fields; returns
 * 0. */
s32 func_L14_0035E470(u8 *o) {
    u8 *st;
    s32 t;

    st = *(u8 **)(o + 0x68);
    *(s32 *)(st + 0x2FC) = 0x3C;
    *(s32 *)(st + 0x324) = func_0037E1D8(2);
    st[0x1D7] = 1;
    *(f32 *)(st + 0x78) = 1.0f;
    *(f32 *)(st + 0x7C) = 1.0f;
    st[0x170] = 0xD;
    st[0x1A8] = 3;
    *(f32 *)(st + 0x190) = 0.5f;
    *(f32 *)(st + 0x194) = 0.5f;
    *(f32 *)(st + 0x19C) = 0.15f;
    *(s32 *)(st + 0xA8) = 0x101;
    *(f32 *)(st + 0x70) = 0.9f;
    *(f32 *)(st + 0x74) = 0.1f;
    *(f32 *)(st + 0x80) = 1.483529806137085f;
    *(f32 *)(st + 0xA0) = 0.3490658402442932f;
    *(f32 *)(st + 0x9C) = 0.0024444444570690393f;
    func_L01_00458A70(o, 0.004999999888241291f, 0.10000000894069672f, 0.0069813174195587635f, 0.20943953096866608f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(f32 *)(st + 0x30) = 1.0f;
        *(s16 *)(st + 0x34) = 1;
    }
    t = *(s32 *)(st + 0x2E4);
    *(f32 *)(st + 0x40) = 1.0f;
    st[0x3E] = 1;
    st[0x39] = 0;
    if (t >= 2) {
        *(s32 *)(st + 0x2E4) = t * 2;
    }
    if (o[0x43] != 0) {
        func_003BE4F0(o, 0, 0, 0);
    }
    t = *(s32 *)(st + 0x2D0);
    if (t != 0) {
        if (t >= 2) {
            *(s32 *)(st + 0x2D0) = 1;
        } else if (t < 0) {
            *(s32 *)(st + 0x2D0) = 0;
        }
        func_L01_00441FB8(o, 1, 4);
        *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(o + 0x98) = 0;
        func_L01_004A6DF8(o, 1);
    } else if (*(s32 *)(st + 0x320) != -1) {
        func_L01_00441FB8(o, 0xA, 6);
        *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(o + 0x98) = 0;
        func_L01_004A6DF8(o, 1);
    } else {
        func_L01_00441FB8(o, 1, 0);
    }
    if (*(s32 *)(st + 0x328) != 0) {
        func_L01_00441FB8(o, 0xC, 7);
        *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(o + 0x98) = 0;
        func_L01_004A6DF8(o, 1);
        *(u16 *)(o + 0x34) |= 2;
    }
    *(s32 *)(st + 0x330) = 0;
    return 0;
}
/* localdecomp:end func_L14_0035E470 */

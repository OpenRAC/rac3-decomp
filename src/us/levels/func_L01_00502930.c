#include "common.h"

/* NTSC-U counterpart of func_L01_00506888 (src/levels/shared/L01_005063E8.c) */
extern u8 D_001A4BE0[];

/* localdecomp:start func_L01_00502930 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_506888;

typedef struct {
    u8 pad0[0x48];
    s32 sequence;       /* 0x48 */
    u8 pad4C[0x50 - 0x4C];
    s32 hand_item;      /* 0x50: the item the hand needs, -1 for any */
    u8 pad54[0x58 - 0x54];
    f32 mean;           /* 0x58: seconds between plays */
    f32 cooldown;       /* 0x5C: seconds of cooldown */
    s32 cooldown_frames; /* 0x60 */
    u8 pad64[0x70 - 0x64];
} F_506888;

typedef struct {
    u8 pad0[0xE0];
    V_506888 pickup_point; /* 0xE0 */
    u8 pad_F0[0x1B8 - 0xF0];
    s32 state_timer;       /* 0x1B8 */
    u8 pad_1BC[0x208 - 0x1BC];
    s16 fidget_gap;        /* 0x208 */
    u8 pad20A[0xC08 - 0x20A];
    u32 anim_flags;        /* 0xC08: & 2 */
    u8 pad_C0C[0x25C0 - 0xC0C];
    void *hero_moby;       /* 0x25C0 */
    s32 state;             /* 0x25C4 */
    u8 pad_25C8[0x25D4 - 0x25C8];
    s32 prev_state;        /* 0x25D4 */
    u8 pad_25D8[0x25EC - 0x25D8];
    u8 hold_type;          /* 0x25EC: 0 none, 1 one hand, 2 both */
    u8 pad_25ED[0x2850 - 0x25ED];
    s32 health;            /* 0x2850 */
} H_506888;

extern u8 D_001A4BE0[];
extern s32 D_L01_002F4520[];
extern F_506888 D_L01_002F4370[];
extern s32 D_001D545C;        /* the level number; no size hint: Ps2EeAs reads it with `lui` */
extern s32 func_L01_004DC080(void);
extern s32 func_L01_004E5470(s32 slot);
extern f32 func_0037E250(f32 lo, f32 hi);
extern s32 func_003CE740(void *from, void *to, s32 mask, void *skip, s32 unk);

/* hero_fidget_pick: each idle frame picks a fidget (into *out) to play, or none. */
s32 func_L01_00502930(s32 *out) {
    H_506888 *hero = (H_506888 *)D_001A4BE0;
    s32 ready[20];
    s32 count = 0;
    s32 i;
    f32 total;
    f32 roll;

    if (hero->fidget_gap != 0) {
        return 0;
    }
    if (func_L01_004DC080()) {
        *out = 3;
        if (D_L01_002F4520[0] != 0) {
            return 0;
        }
        if ((hero->anim_flags & 2) == 0) {
            return 0;
        }
        if (func_0037E250(0.0f, 1.0f) < 0.33f) {
            return 1;
        }
        return 0;
    }
    for (i = 0; i < 4; i++) {
        F_506888 *f = &D_L01_002F4370[i];
        s32 item;
        if (f->cooldown_frames != 0) {
            continue;
        }
        {
            /* a mean of 0 turns the fidget off (the 0 is a local so that the loop pass hoists it
               on its first run, ahead of the probe's 8.0, as retail has them) */
            f32 off = 0.0f;
            if (f->mean == off) {
                continue;
            }
        }
        item = func_L01_004E5470(0);
        if (f->hand_item != -1 && f->hand_item != item) {
            continue;
        }
        if (i == 2) {
            V_506888 top;
            V_506888 origin;
            if (D_001D545C != -1) {
                continue;
            }
            if (((H_506888 *)D_001A4BE0)->hold_type == 2) {
                continue;
            }
            origin = ((H_506888 *)D_001A4BE0)->pickup_point;
            top = ((H_506888 *)D_001A4BE0)->pickup_point;
            top.z = top.z + 8.0f;
            if (func_003CE740(&origin, &top, 2, ((H_506888 *)D_001A4BE0)->hero_moby, 0)) {
                continue;
            }
        }
        if (i == 3) {
            if (((H_506888 *)D_001A4BE0)->prev_state != 1) {
                continue;
            }
            if (!(((H_506888 *)D_001A4BE0)->state_timer < 0x33)) {
                continue;
            }
            if (!(((H_506888 *)D_001A4BE0)->health < 2)) {
                continue;
            }
        }
        ready[count] = i;
        count++;
    }
    if (count == 0) {
        return 0;
    }
    total = 0.0f;
    for (i = 0; i < count; i++) {
        total = total + 1.0f / (f32)(s32)(((F_506888 *)D_L01_002F4370)[ready[i]].mean * 60.0f);
    }
    roll = func_0037E250(0.0f, 1.0f);
    if (roll < total) {
        for (i = 0; i < count; i++) {
            *out = ready[i];
            total = total - 1.0f / (f32)(s32)(((F_506888 *)D_L01_002F4370)[ready[i]].mean * 60.0f);
            if (total < roll) {
                break;
            }
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00502930 */

#include "common.h"

/* NTSC-U counterpart of func_L01_003E9F40 (src/levels/shared/L01_003E3930.c): 100 -> 120 */
typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6C58;
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
extern Entry_3E6C58 D_L01_001E2AC0[];
#include "vu0.h"
extern f32 func_00388730(f32 *, f32 *);

/* localdecomp:start func_L01_003E80A8 */
typedef struct {
    u8 pad0[0x60];
    u8 motion[0xF0];  /* 0x060: +0x80 the hero's move, +0xA4 his speed */
    u8 hero[0x310];   /* 0x150: the camera's copy of the hero */
} Camera_003E9F40;
extern Entry_3E6C58 D_L01_001E2AC0[];
extern f32 func_00388730(f32 *, f32 *); /* the dot product */
extern void func_L01_003E6D50(s32, s32, f32, f32);

/* camera_approach_distance: the hero moving against the camera's facing (dot < -0.3):
   distance target up to 6.0 by speed (full at 0.07 u/frame), and a stiffer arm spring. */
void func_L01_003E80A8(u8 *update, f32 *gain, f32 *damping) {
    u8 *follow = *(u8 **)(update + 0x70);
    u8 *approach = follow + 0x260;
    u8 *springs = follow + 0x180;
    s32 player = *(s32 *)(update + 0x94);
    u8 *motion = ((Camera_003E9F40 *)D_L01_001E2AC0)[player].motion;
    u8 *hero = ((Camera_003E9F40 *)D_L01_001E2AC0)[player].hero;
    f32 share;
    f32 far;
    f32 distance;

    if (*(s16 *)(approach + 6) == 0) {
        if ((*(s16 *)(approach + 4) != 0 && *(f32 *)(motion + 0xA4) == 0.0f &&
             func_00388730((f32 *)(*(u8 **)(hero + 0xF0) + 0xC0), (f32 *)update) <= -0.3f) ||
            (fabs_asm(*(f32 *)(motion + 0xA4)) > 0.0001f &&
             func_00388730((f32 *)(motion + 0x80), (f32 *)update) <= -0.3f)) {
            *(s16 *)(approach + 4) = 120;
            /* full at 0.07 u a frame */
            share = *(f32 *)(motion + 0xA4) * 14.2857f;
            if (share > 1.0f) {
                share = 1.0f;
            }
            far = 4.0f;
            if (hero[0x12B] != 1) {
                far = *(f32 *)(approach + 0xC);
            }
            distance = *(f32 *)(springs + 0x58) + (far - *(f32 *)(springs + 0x58)) * share;
            if (distance > *(f32 *)(approach + 8)) {
                *(f32 *)(approach + 8) = distance;
            }
            func_L01_003E6D50(*(s32 *)(update + 0x94), 0, *(f32 *)(approach + 8), 0.003f);
            *gain = share * 0.02f + 0.02f;
            *damping = share * 0.100000009f + 0.2f;
            return;
        }
    }
    if (*(s16 *)(approach + 4) != 0) {
        *(s16 *)(approach + 4) = 0;
        *(f32 *)(approach + 8) = *(f32 *)(springs + 0x58);
    }
    if (*(s32 *)(hero + 0x100) == 0x89) {
        *gain = 0.04f;
        *damping = 0.2f;
    } else {
        *gain = 0.02f;
        *damping = 0.2f;
    }
}
/* localdecomp:end func_L01_003E80A8 */

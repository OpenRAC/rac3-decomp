#include "common.h"

/* NTSC-U counterpart of func_L01_00505380 (src/levels/shared/L01_004FE668.c) */
typedef struct {
    u8 pad0[152];
    float f98;
    u8 pad1[400 - 156];
    u8 sub190[16];
    float f1A0;
    u8 pad2[5172 - 420];
    s16 h1434;
    u8 pad3;
    u8 b1437;
    u8 pad4[5808 - 5176];
    s32 mode;
    u8 pad5[9716 - 5812];
    u8 b25F4;
} Veldin1A4BE0;
extern void func_L01_00445168(f32 *value, f32 target, f32 *rate, f32 gain, f32 damping, f32 cap);
extern Veldin1A4BE0 D_001A4BE0;
extern Veldin1A4BE0 D_001A4BE0;
extern Veldin1A4BE0 D_001A4BE0;
extern Veldin1A4BE0 D_001A4BE0;
extern Veldin1A4BE0 D_001A4BE0;
extern Veldin1A4BE0 D_001A4BE0;

/* localdecomp:start func_L01_00501458 */
/* The bob's fabs is the game's fabs_asm (include/vu0.h). */
#include "vu0.h"
typedef struct {
    u8 pad0[0x88];
    f32 pos_z;
    u8 pad8C[0x1B8 - 0x8C];
    s32 state_timer;
    u8 pad1BC[0x350 - 0x1BC];
    f32 water_height;
    u8 pad354[0x720 - 0x354];
    f32 bob;
    f32 bob_rate;
    u8 pad728[0x72C - 0x728];
    f32 float_height;
    f32 float_rate;
    u8 pad734[0x9BC - 0x734];
    f32 bob_spring_rate;
    u8 pad9C0[0x25C4 - 0x9C0];
    s32 state;
    u8 pad25C8[0x25D4 - 0x25C8];
    s32 prev_state_type;
    u8 pad25D8[0x25E0 - 0x25D8];
    s32 prev_state_type_b;
    u8 critter_mode;
} H_505380;
extern f32 func_003BEBF8(f32 *value, f32 target, f32 step);

/* hero_surface_float: sets the hero's height on the surface: a tracked surface height
   (spring 0.027, 0.3) less 0.12, plus a bobbing offset with its own rate. */
void func_L01_00501458(void) {
    if ((*(H_505380 *)&D_001A4BE0).state_timer > 10 || (*(H_505380 *)&D_001A4BE0).bob < 0.0f ||
        (*(H_505380 *)&D_001A4BE0).prev_state_type == 17 || (*(H_505380 *)&D_001A4BE0).prev_state_type_b == 17) {
        if ((*(H_505380 *)&D_001A4BE0).state == 53) {
            /* the surface swim springs the bob to 0 */
            func_L01_00445168(&(*(H_505380 *)&D_001A4BE0).bob, 0.0f, &(*(H_505380 *)&D_001A4BE0).bob_spring_rate,
                              0.03f, 0.3f, 0.025000002f);
            (*(H_505380 *)&D_001A4BE0).bob_rate = 0.0f;
        } else {
            /* a damped spring: stiffness 0.005, damping 0.045 */
            f32 rate = (*(H_505380 *)&D_001A4BE0).bob_rate;
            f32 bob = (*(H_505380 *)&D_001A4BE0).bob;
            rate -= bob * 0.005f + rate * 0.045f;
            (*(H_505380 *)&D_001A4BE0).bob_rate = rate;
            if (fabs_asm(bob) < 0.00100000005f && rate < 9.99999975e-05f) {
                (*(H_505380 *)&D_001A4BE0).bob_rate = 0.0f;
            }
        }
    }
    (*(H_505380 *)&D_001A4BE0).bob += (*(H_505380 *)&D_001A4BE0).bob_rate;
    if ((*(H_505380 *)&D_001A4BE0).state == 53 && (*(H_505380 *)&D_001A4BE0).bob > 0.0f) {
        if ((*(H_505380 *)&D_001A4BE0).bob_rate > 0.0f) {
            (*(H_505380 *)&D_001A4BE0).bob_rate = 0.0f;
        }
        func_003BEBF8(&(*(H_505380 *)&D_001A4BE0).bob, 0.0f, 0.011666667f); /* sinks 0.0117 a tick */
    }
    if ((*(H_505380 *)&D_001A4BE0).state != 0x81 && (*(H_505380 *)&D_001A4BE0).state != 0x50) {
        func_L01_00445168(&(*(H_505380 *)&D_001A4BE0).float_height, (*(H_505380 *)&D_001A4BE0).water_height,
                          &(*(H_505380 *)&D_001A4BE0).float_rate, 0.027f, 0.3f, 0.0f);
    }
    /* the feet rest 0.12 u under the surface (0.05 as Clank) */
    if ((*(H_505380 *)&D_001A4BE0).critter_mode == 0) {
        (*(H_505380 *)&D_001A4BE0).pos_z = (*(H_505380 *)&D_001A4BE0).float_height + -0.119999997f + (*(H_505380 *)&D_001A4BE0).bob;
    } else {
        (*(H_505380 *)&D_001A4BE0).pos_z = (*(H_505380 *)&D_001A4BE0).float_height + -0.0500000007f + (*(H_505380 *)&D_001A4BE0).bob;
    }
}
/* localdecomp:end func_L01_00501458 */

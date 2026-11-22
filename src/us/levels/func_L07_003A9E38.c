#include "common.h"

/* NTSC-U counterpart of func_L07_003AB678 (src/levels/07_annihilation_nation/L07_003AA9C0.c) */
#include "vu0.h"
extern void func_003BDA38(u8 *a, s32 b, f32 *out);

/* localdecomp:start func_L07_003A9E38 */
typedef struct { u8 pad0[0x164]; u8 *texture; } Effects_003AB678;
extern Effects_003AB678 D_L07_0021EC98_003A9E38;
extern void func_003BDA38(u8 *a, s32 b, f32 *out);

void func_L07_003A9E38(u8 *object) {
    extern void func_003886E8(void *, void *, f32);
    extern s32 func_0037E208(s32, s32);
    extern s32 func_0037E1D8(s32);
    extern f32 func_0037E250(f32, f32);
    extern f32 func_0037E2A8(void);
    extern void func_003BF6A8(void *, f32);
    extern void func_0037E4B8(void *, f32, f32, f32);
    extern u8 *func_L01_0046C468(void *, void *, s32, u32, s32, s32, s32, f32, f32, s32, f32);
    vu0_v4 origin;
    vu0_v4 position;
    vu0_v4 velocity;
    u8 *state = *(u8 **)(object + 0x68);
    f32 speed;
    f32 angle;
    f32 size;
    s32 n;
    s32 i;
    s32 duration;
    u8 kind;
    u8 frame;
    u8 *effect;

    if (*(f32 *)(state + 0x538) == 1.0f) {
        *(vu0_q *)&origin = *(vu0_q *)(state + 0x520);
    } else {
        func_003BDA38(object, state[0x533], (f32 *)&position);
        vec_sub_ba(&origin, state + 0x520, &position);
        func_003886E8(&origin, &origin, *(f32 *)(state + 0x538));
        vec_add_ab(&origin, &position, &origin);
    }
    n = func_0037E208(0, 2);
    for (i = 0; i < n; i++) {
        *(vu0_q *)&position = *(vu0_q *)&origin;
        func_003BF6A8(&position, 0.3f);
        speed = func_0037E250(3.0f, 5.5f) * 0.016666668f;
        angle = func_0037E2A8();
        func_0037E4B8(&velocity, speed, angle, func_0037E250(1.0471976f, 3.1415927f));
        kind = 253;
        if (func_0037E1D8(2) == 0) {
            kind = 3;
        }
        frame = func_0037E1D8(256);
        duration = func_0037E208(20, 40);
        size = func_0037E250(0.25f, 0.75f) * 210000.0f;
        effect = func_L01_0046C468(&position, &velocity, duration, 0x806020, kind, 127, 0, size, size, 0, 0.0027222224f);
        if (effect) {
            effect[2] = *D_L07_0021EC98_003A9E38.texture;
            frame = effect[8] + 32;
        }
        size *= 0.3f;
        effect = func_L01_0046C468(&position, &velocity, duration, 0xFFFFFF, kind, 127, 64, size, size, 0, 0.0027222224f);
        if (effect) {
            effect[8] = frame;
            effect[2] = *D_L07_0021EC98_003A9E38.texture;
        }
    }
}
/* localdecomp:end func_L07_003A9E38 */

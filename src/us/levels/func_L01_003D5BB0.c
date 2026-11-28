#include "common.h"
/* localdecomp:start func_L01_003D5BB0 */
#include "vu0.h"
typedef struct { s32 a, b, c, d; } Params_003D76C0;
extern f32 D_L01_001DF478, D_L01_001DF47C, D_L01_001DF480, D_L01_001DFBD0;
extern s32 D_L01_001DF484, D_L01_001DF488, D_L01_001DF48C, D_L01_001DF490;
extern s32 D_001D545C_003D5BB0;
__asm__(".extern D_L01_001DF478,4");
__asm__(".extern D_L01_001DF47C,4");
__asm__(".extern D_L01_001DF480,4");

__asm__(".extern D_L01_001DF484,4");
__asm__(".extern D_L01_001DF488,4");
__asm__(".extern D_L01_001DF48C,4");
__asm__(".extern D_L01_001DF490,4");
void func_L01_003D5BB0(u8 *obj, vu0_q *point) {
    extern f32 func_0037E250(f32, f32);
    extern f32 func_0037E2A8(void);
    extern void func_0037E4B8(void *, f32, f32, f32);
    extern void func_003886E8(void *, void *, f32);
    extern s32 func_0037E1D8(s32);
    extern s32 func_0037E208(s32, s32);
    extern u8 *func_L01_00329470(void *,void *,s32,s32,s32,u32,void *,s32,s32,s32,f32,f32);
    vu0_v4 velocity;
    vu0_v4 position;
    union {vu0_v4 temp; Params_003D76C0 params;} work;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *particle;
    f32 speed, yaw, tilt, scale;
    u32 color;
    s32 low, cheap;
    *(vu0_q *)&position = *point;
    speed = func_0037E250(3.0f, 5.0f) * 0.0166666675f * D_L01_001DF478;
    yaw = func_0037E2A8();
    tilt = func_0037E250(0.4363323152065277f, 0.7853981852531433f);
    func_0037E4B8(&velocity, speed, yaw, tilt);
    if (state[0xBE] == 0) {
        velocity.z = fabs_asm(velocity.z) + func_0037E250(*(f32 *)(state + 0xA4) * 2.75f, *(f32 *)(state + 0xA4) * 3.75f) * 0.0166666675f;
    } else {
        func_003886E8(&work.temp, state, func_0037E250(*(f32 *)(state + 0xA4) * 2.75f, *(f32 *)(state + 0xA4) * 3.75f) * 0.0166666675f);
        vec_add_ab(&velocity, &work.temp, &velocity);
    }
    if (*(u32 *)(state + 0xB4) & 0x40) {
        velocity.y *= 0.35f;
    }
    scale = 14.600000381469727f;
    color = 0;
    switch (D_001D545C_003D5BB0) {
    case 32:
        color = func_0037E1D8(3) ? 0x96B3B4 : 0x699A9C;
        scale = *(f32 *)(state + 0xA8);
        break;
    case 41: color = func_0037E1D8(3) ? 0x605129 : 0x5A523E; break;
    case 42: color = func_0037E1D8(3) ? 0x263438 : 0x273538; break;
    }
    low = 0;
    work.params = (Params_003D76C0){D_L01_001DF484,D_L01_001DF488,D_L01_001DF48C,D_L01_001DF490};
    cheap = 0;
    if (D_L01_001DFBD0 < 0.8f) {
        low = 1;
        if (!(*(u32 *)(state + 0xB4) & 4) && func_0037E1D8(3)) cheap = 1;
    }
    particle = func_L01_00329470(&position, &velocity, func_0037E208(120,150), cheap, low, color, &work.params, 0, 40, 60, 1.0f, scale);
    if (particle) {
        f32 r = func_0037E250(D_L01_001DF47C, D_L01_001DF480);
        *(f32 *)(particle + 0x2C) = *(f32 *)(*(u8 **)(particle + 0x24) + 0x24) * r;
    }
}
/* localdecomp:end func_L01_003D5BB0 */

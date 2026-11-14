#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00429840;

LINKER_REMNANT("asm/levels", func_L02_00429828);

/* localdecomp:start func_L02_00429840 */
#include "vu0.h"


extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L01_003000F8(void);
extern void *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);

void func_L02_00429840(void *owner, void *origin, s32 count, s32 mode, void *vorigin, s32 color,
                       V4_00429840 *fixed, s32 extra, f32 radius, f32 speed, f32 low, f32 high) {
    V4_00429840 velocity, position, rotation, rnd;
    u8 *effect, *payload;
    s32 variant;
    s32 r, g, b, t;
    u32 packed;
    s32 i;
    f32 life;

    for (i = 0; i < count; i++) {
        func_L01_00443B88(&velocity, 0.0f, speed * 0.020000001f);
        vec_add_ab(&velocity, &velocity, vorigin);
        func_L01_00443B88(&position, 0.0f, radius);
        vec_add_ba(&position, &position, origin);
        *(vu0_q *)&rnd = 0;
        rnd.x = func_00382538();
        rnd.z = func_00382538();
        rotation = rnd;
        if (fixed != 0)
            rotation = *fixed;
        variant = func_00382468(4);
        life = func_003824E0(10.0f, 20.0f);
        effect = func_L01_003F79D8(owner, mode ? 2 : 1,0x1C32, variant, &position, &rotation, &velocity, 0xFF, life,
                                   func_003824E0(10.0f, 20.0f), extra, 0, 0x80);
        if (effect != 0) {
            *(void (**)(void))(effect + 0x64) = func_L01_003000F8;
            r = color & 0xFF;
            t = (u32)color >> 24;
            *(f32 *)(effect + 0x2C) = *(f32 *)(*(u8 **)(effect + 0x24) + 0x24) * func_003824E0(low, high);
            b = (color >> 16) & 0xFF;
            g = (color >> 8) & 0xFF;
            payload = *(u8 **)(effect + 0x68);
            func_L01_0043B9E8(effect, r, g, b);
            effect[0x23] = t;
            if (r != g || r != b)
                t = 1;
            else
                t = 0;
            packed = t << 24;
            packed |= b << 16;
            packed |= g << 8;
            packed |= r;
            *(u32 *)(payload + 0x50) = packed;
        }
    }
}
/* localdecomp:end func_L02_00429840 */

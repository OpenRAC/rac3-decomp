#include "common.h"

/* NTSC-U timing counterpart of func_L07_003D8B18. */
/* localdecomp:start func_L07_003D6ED0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_003D8B18;
extern f32 D_L07_001DE934;
extern f32 D_L07_001DE938;
extern s32 D_L07_001DE93C;
extern s32 D_L07_001DE940;
extern s32 D_L07_001DEF40;
typedef struct { u8 pad[0x20]; f32 scale; s32 pad24, timer, state; } State_003D8B18;
extern State_003D8B18 D_L07_001E1EC0;
__asm__(".extern D_L07_001DE934, 4");
__asm__(".extern D_L07_001DE938, 4");
__asm__(".extern D_L07_001DE93C, 4");
__asm__(".extern D_L07_001DE940, 4");
void func_L07_003D6ED0(u8 *obj) {
    extern u8 *func_L01_00444358(void *, s32, s32);
    extern void func_L07_003D6D60(void *, s32, s32, f32, f32, f32, f32, s32);
    extern void func_0039FE80(s32, s32, void *);
    extern void func_003886E8(void *, void *, f32);
    extern f32 func_0037E250(f32, f32);
    extern s32 func_0037E208(s32, s32);
    extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32,
                                 f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
    extern void func_L01_0044EBF8(void *, s32, f32);
    extern void func_L01_00441FB8(s32, s32, s32);
    extern s32 func_00388398(void *);
    extern void func_003BD360(void *);
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *actor;
    f32 ratio, zero, size;
    s32 life;
    switch (obj[0x20]) {
    case 0:
        actor = func_L01_00444358(obj, -1, 1);
        if (actor == 0) break;
        *(f32 *)(state + 8) += *(f32 *)(actor + 0x2C);
        if (*(f32 *)(state + 8) > *(f32 *)(state + 0xC)) {
            f32 radius = 4.0f;
            f32 speed = 1.5f;
            *(f32 *)(state + 4) -= *(f32 *)(state + 0xC);
            *(s32 *)(state + 8) = 0;
            zero = *(f32 *)(state + 8);
            ratio = *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
            func_L07_003D6D60(obj, 5, 255, zero, radius, speed, ratio, 1);
            func_L07_003D6D60(obj, 5, 255, zero, radius, speed, ratio, 1);
        }
        if (*(f32 *)(state + 4) <= 0.0f) {
            func_0039FE80(0, 0, obj);
            {
                Vec_003D8B18 v = {0};
                v.z = 1.0f;
                func_003886E8(&v, &v, D_L07_001DE934 * 0.016666668f);
                size = func_0037E250(20.0f, 40.0f);
                life = func_0037E208(70, 100);
                func_L01_0044ED60(obj, 127, &v, 3.0f, 6.0f, 3.0f, 6.0f, 255,
                                  D_L07_001DE938, size, life, 0, 0, 35, 1.0f, 1.0f, 0, 3);
            }
            func_L01_0044EBF8(obj, 1, 0.0f);
            {
                State_003D8B18 *g = &D_L07_001E1EC0;
                g->state = 0;
                g->timer = 30;
                g->scale = 1.0f;
            }
            obj[0x31] = 0;
            {
                s32 count = D_L07_001DE93C;
                *(u16 *)(obj + 0x34) |= 1;
                *(s32 *)state = count;
            }
            func_L01_00441FB8((s32)obj, 1, -1);
        }
        break;
    case 1:
        if (D_L07_001DEF40 % D_L07_001DE940 == 0) {
            ratio = *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
            func_L07_003D6D60(obj, 5, 255, 0.0f, 4.0f, 1.5f, ratio, 2);
        }
        if (func_00388398(state)) func_L01_00441FB8((s32)obj, 2, -1);
        break;
    case 2:
        func_003BD360(obj);
        return;
    }
    obj[0xA8] = 255;
}
/* localdecomp:end func_L07_003D6ED0 */

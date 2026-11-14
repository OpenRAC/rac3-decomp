#include "common.h"
#include "structs/moby.h"

/* localdecomp:start func_L01_003CBFB8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3CBFB8;
extern s32 D_L01_001DF0E8, D_L01_001DF0E0, D_L01_001DF0E4;
extern u8 D_L01_001DF0F0[1];
extern s32 D_L01_001DF130[1], D_L01_001DF190[1];
extern f32 D_L01_001DF150[1], D_L01_001DF170[1];
extern u8 D_L01_001D66B0_003CBFB8[8];
__asm__(".extern D_L01_001DF0E8, 4");
__asm__(".extern D_L01_001DF0E0, 4");
__asm__(".extern D_L01_001DF0E4, 4");
__asm__(".extern D_L01_001DF0F0, 4");
__asm__(".extern D_L01_001DF130, 4");
__asm__(".extern D_L01_001DF150, 4");
__asm__(".extern D_L01_001DF170, 4");
__asm__(".extern D_L01_001DF190, 4");
extern void func_003BFC18(void *, void *, s32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern u8 *func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern u8 *func_L01_0046D570(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s16, s32);
extern void func_L01_0040A2D0(void *, void *);
typedef struct {u8 pad[0x20];s32 x20,x24,x28,x2C;} Vars_3CBFB8;

u8 *func_L01_003CBFB8(s32 kind, V_3CBFB8 *position, V_3CBFB8 *direction, s32 value, f32 scale, s32 owner) {
    V_3CBFB8 axis, scaled;
    u8 *moby;
    u8 *data;
    s32 i;
    s32 *colour, *extra;
    f32 *size, *start;
    s32 a, b;

    func_003BFC18(position, &axis, 1);
    moby = func_003BCFB0(0x1B3C, 0x100);
    if (moby) {
        data = *(u8 **)(moby + 0x68);
        if (owner == -1) *(s32 *)(data + 0xD0) = D_L01_001DF0E8;
        else *(s32 *)(data + 0xD0) = owner;
        ((struct Moby*)moby)->draw_dist = ((struct Moby*)moby)->pad_30[0] = 0xFF;
        ((struct Moby*)moby)->state = 0;
        *(V_3CBFB8 *)(moby + 0x10) = *position;
        *(V_3CBFB8 *)(data + 0xB0) = *direction;
        *(s32 *)(data + 0xC8) = value;
        *(f32 *)(data + 0xD4) = scale;
        *(s32 *)(data + 0xCC) = 0;
        func_00388830(&scaled, direction, 1.0f);
        *(V_3CBFB8 *)(moby + 0xC0) = scaled;
        func_00388758(moby + 0xD0, moby + 0xC0, &axis);
        func_00388830(moby + 0xD0, moby + 0xD0, 1.0f);
        func_00388758(moby + 0xE0, moby + 0xD0, moby + 0xC0);
        ((struct Moby*)moby)->matrix[0].w = ((struct Moby*)moby)->matrix[1].w = ((struct Moby*)moby)->matrix[2].w = 0.0f;
        *(s32 *)(data + 0xC4) = kind;

        for (i = 0; i < 4; i++) {
            func_L01_00467DA8(position, 14, D_L01_001DF150[i], D_L01_001DF170[i], D_L01_001DF130[i], 2, 1, D_L01_001D66B0_003CBFB8, 0.0f, 1);
        }
        for (; i < 7; i++) {
            func_L01_0046D570(position, 20, D_L01_001DF150[i], D_L01_001DF170[i], D_L01_001DF130[i], 2, 2, D_L01_001D66B0_003CBFB8, 0, D_L01_001DF190[i-4], 6, 1);
        }
        a = D_L01_001DF0E0;
        b = D_L01_001DF0E4;
        *(u8 **)(data + 0xC0) = D_L01_001DF0F0;
        ((Vars_3CBFB8*)data)->x20 = a;
        ((Vars_3CBFB8*)data)->x28 = b;
        ((Vars_3CBFB8*)data)->x24 = a;
        ((Vars_3CBFB8*)data)->x2C = b;
        func_L01_0040A2D0(data, D_L01_001DF0F0);
    }
    return moby;
}
/* localdecomp:end func_L01_003CBFB8 */

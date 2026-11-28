#include "common.h"
/* localdecomp:start func_L01_0037C818 */
#include "vu0.h"
typedef struct { u8 pad[0x30]; f32 f30; s32 f34; u8 *f38; f32 f3c; s32 f40, f44, f48, f4c; } S_0037D920;
typedef struct { u8 pad0[0x34]; u16 flags; } Obj_0037D920;
typedef struct { s32 mode, count, f8, color0, color1; f32 scale; } Settings_0037D920;
extern Settings_0037D920 D_L01_002B3B40;
extern s32 D_L01_001DFBC0_0037C818;
extern s32 D_L01_001E1E14;
extern s32 D_L01_001E1E10_0037C818;
extern u8 D_0014262F[];
extern u8 D_L01_002C5640[];
extern f32 D_L01_001DDBA0 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DDBA0, 4");
extern f32 D_L01_001DDBA4 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DDBA4, 4");
extern vu0_v4 D_L01_001E2E60[];
extern u8 D_L01_001E1DF0[8];
extern u8 D_L01_001E1E00[8];
extern s32 D_L01_001E1E20;
extern f32 D_L01_001E1E3C;
extern f32 D_L01_001E1E38;
u8 *func_L01_0037C818(u8 *owner, vu0_q *pos, vu0_q *dir, vu0_q *other, s32 a4, s32 a5, s32 alt, f32 scale)
{
    extern u8 *func_003BCFB0(s32, s32);
    extern void func_003886E8(void *, void *, f32);
    extern void func_00388830(void *, void *, f32);
    extern f32 func_0037E2A8(void);
    extern void func_L01_004A6DF8(void *, s32);
    vu0_v4 v0, v1, from, to, delta;
    u8 *obj = func_003BCFB0(0x186F, 0x80);
    u8 *s;
    u8 *second;
    Settings_0037D920 *settings;
    s32 color;
    s32 count;
    f32 sc;
    vu0_v4 *camera;
    if (obj != 0) {
        *(s16 *)(obj + 0x32) = 255; obj[0x20] = 0; obj[0x30] = 255;
        settings = &D_L01_002B3B40;
        s = *(u8 **)(obj + 0x68);
        *(vu0_q *)(obj + 0x10) = *pos;
        *(vu0_q *)(s + 0x20) = *pos;
        second = s + 0x10;
        func_003886E8(dir, dir, 0.1f);
        func_003886E8(other, other, 0.1f);
        *(vu0_q *)s = *dir;
        *(vu0_q *)(s + 0x10) = *other;
        ((S_0037D920 *)s)->f40 = a4;
        ((S_0037D920 *)s)->f38 = owner;
        *(u8 **)(obj + 0xB8) = owner;
        ((S_0037D920 *)s)->f30 = func_0037E2A8();
        ((S_0037D920 *)s)->f3c = scale;
        ((S_0037D920 *)s)->f34 = 0;
        ((S_0037D920 *)s)->f44 = a5;
        ((S_0037D920 *)s)->f48 = alt;
        ((S_0037D920 *)s)->f4c = 0;
        D_L01_001E1E10_0037C818 = 1;
        D_L01_001E1E14 = D_L01_001DFBC0_0037C818;
        settings->color0 = 0xBFB0B0B0;
        {
            u8 *weapons = D_L01_002C5640;
            u8 type = *(D_0014262F[0] * 240 + weapons + 1);
            color = 0xBFA0FFA0;
            if (type == 1) {
                color = 0xBFFFA0A0;
            }
            if (type == 2) {
                color = 0xBFFF8040;
            }
            if (type == 3) {
                color = 0xBFA0A0FF;
            }
            if (type >= 4) {
                color = 0xBFA0A0FF;
            }
        }
        settings->color1 = color;
        func_00388830(s, s, 30.0f);
        func_00388830(second, second, 30.0f);
        if (alt) {
            camera = D_L01_001E2E60;
            func_003886E8(&v0, camera, D_L01_001DDBA0);
            func_003886E8(&v1, camera - 2, D_L01_001DDBA4);
            vec_add_ba(&from, camera - 58, &v1);
            vec_add_ba(&from, &from, &v0);
            func_00388830(&delta, second, 100.0f);
            count = 5;
            sc = 0.25f;
            vec_add_ab(&to, &from, &delta);
            D_L01_002B3B40.mode = 2;
            *(vu0_q *)D_L01_001E1DF0 = *(vu0_q *)&from;
            settings->count = count;
            settings->scale = sc;
        } else {
            func_00388830(&delta, s, 100.0f);
            vec_add_ab(&to, pos, &delta);
            *(vu0_q *)D_L01_001E1DF0 = *pos;
            count = 10;
            sc = 0.75f;
            D_L01_002B3B40.mode = 4;
            settings->count = count;
            settings->scale = sc;
        }
        *(vu0_q *)D_L01_001E1E00 = *(vu0_q *)&to;
        D_L01_001E1E20 = 20;
        D_L01_001E1E38 = 0.2f;
        D_L01_001E1E3C = 0.2f;
        ((Obj_0037D920 *)obj)->flags = (((Obj_0037D920 *)obj)->flags | 0x41) & 0xEFFF;
        *(s32 *)(obj + 0x98) = 0;
        func_L01_004A6DF8(obj, 1);
    }
    return obj;
}
/* localdecomp:end func_L01_0037C818 */

#include "common.h"

/* NTSC-U counterpart of func_003F03F0 (src/boot_elf/text/3F03B0.c): the fourth argument is scale itself, no * 1.0769231f */
/* localdecomp:start func_U_003F0290 */
typedef struct Obj_U_003F0290 Obj_U_003F0290;
typedef struct Vtable_U_003F0290 { u8 pad[0x20]; void (*bounds)(Obj_U_003F0290 *, s32, f32 *, s32); } Vtable_U_003F0290;
struct Obj_U_003F0290 { u8 pad0[8]; Vtable_U_003F0290 *vt; u8 padC[0x14]; f32 x, y; u32 color; u8 pad2C[0x10]; s32 image; u8 pad40[0x10]; u32 texture; u8 pad54[8]; f32 f5C, f60; };
extern f32 D_U_001D96F4;
extern f32 D_U_001D96D8;
extern f32 D_U_001D96DC;
extern s32 func_U_003EDD50(void *, s32);
extern void func_U_003EDF48();
extern void func_U_0038EB10_003F0290(f32, f32, f32, f32, unsigned long, s32, s32, s32, s32, unsigned long, f32, f32);

void func_U_003F0290(Obj_U_003F0290 *p, s32 arg)
{
    f32 rect[4];
    f32 x, y, w, zero, h, scale, adjust;
    s32 has;
    unsigned long texture, color;
    s32 image;
    f32 z;

    if (p->image) {
        zero = 0.0f;
        w = zero;
        h = zero;
        has = 0;
        p->vt->bounds(p, arg, rect, 1);
        func_U_003EDF48(p, rect);
        x = rect[0] + (rect[2] - rect[0]) * 0.5f;
        y = rect[1] + (rect[3] - rect[1]) * 0.5f;
        if (func_U_003EDD50(p, 0x40)) {
            w = p->x;
            h = p->y;
            has = 1;
        }
        scale = p->f60;
        adjust = D_U_001D96F4 * scale;
        color = p->color;
        image = p->image;
        z = p->f5C;
        texture = p->texture;
        if (has) {
            func_U_0038EB10_003F0290((f32)(s32)(x * D_U_001D96D8), (f32)(s32)((y - adjust) * D_U_001D96DC), z, scale,
                                     texture, image, -1, 1, has, color, w * D_U_001D96D8, h * D_U_001D96DC);
        } else {
            func_U_0038EB10_003F0290((f32)(s32)(x * D_U_001D96D8), (f32)(s32)((y - adjust) * D_U_001D96DC), z, scale,
                                     texture, image, -1, 1, 0, color, zero, zero);
        }
    }
}
/* localdecomp:end func_U_003F0290 */

/* functional: high. Near-miss draft; instruction multiset equals retail except nops, only the order of an addiu and a VU0 block differs. */
/* localdecomp:start func_L01_00513FD8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80];
    f32 origin[4];
    u8 pad90[0x80];
    f32 velocity[4];
    u8 pad120[0x1D0];
    f32 point[4];
    u8 pad300[0x3C];
    f32 distance;
    u8 pad340[0x14];
    f32 height;
    u8 pad358[0x1148];
    f32 direction[4];
    u8 pad14B0[0x60];
    Vec4 transformed;
    Vec4 position;
    u8 pad1530[0x10];
    Vec4_50D4D8 rotation;
    u8 pad1550[0x50];
    f32 angle;
    u8 pad15A4[0x5C];
    f32 offset;
    u8 pad1604[0xAC];
    s32 mode;
    u8 pad16B4[0x18];
    f32 scale;
    u8 pad16D0[0xC];
    s32 blocked;
    u8 pad16E0[0xEE4];
    s32 state;
    u8 pad25C8[0x4];
    s32 state_type;
    u8 pad25D0[0x14];
    u8 character;
} Hero_00513FD8;
extern f32 D_L01_001DBD58;
extern f32 D_L01_001DBD5C;
__asm__(".extern D_L01_001DBD58, 4");
__asm__(".extern D_L01_001DBD5C, 4");
void func_L01_00513FD8(void) {
    extern void func_L01_00511508(Vec4 *, Vec4 *, f32);
    extern f32 func_L01_005114B0(f32 *);
    extern f32 func_0038CF00(void *, void *);
    extern void func_003C41A0(f32 *, f32 *, f32, f32, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    f32 scale;
    Vec4 out;
    if (((Hero_00513FD8 *)&D_001A4BE0)->scale == 0.0f) {
        if (((Hero_00513FD8 *)&D_001A4BE0)->character == 1) ((Hero_00513FD8 *)&D_001A4BE0)->scale = 1.1f;
        else if (((Hero_00513FD8 *)&D_001A4BE0)->character == 2) ((Hero_00513FD8 *)&D_001A4BE0)->scale = D_L01_001DBD58;
        else ((Hero_00513FD8 *)&D_001A4BE0)->scale = 1.75f;
    }
    switch (((Hero_00513FD8 *)&D_001A4BE0)->character) {
    case 1:
        scale = 1.1f;
        if (((Hero_00513FD8 *)&D_001A4BE0)->scale > scale) ((Hero_00513FD8 *)&D_001A4BE0)->scale = scale;
        if (((Hero_00513FD8 *)&D_001A4BE0)->offset != 0.0f) ((Hero_00513FD8 *)&D_001A4BE0)->offset = -3.0f;
        break;
    case 2:
        scale = D_L01_001DBD58;
        if (((Hero_00513FD8 *)&D_001A4BE0)->scale > scale) ((Hero_00513FD8 *)&D_001A4BE0)->scale = scale;
        if (((Hero_00513FD8 *)&D_001A4BE0)->offset != 0.0f) ((Hero_00513FD8 *)&D_001A4BE0)->offset = D_L01_001DBD5C;
        break;
    default:
        if (((Hero_00513FD8 *)&D_001A4BE0)->mode == 2) {
            scale = 1.75f;
            if (((Hero_00513FD8 *)&D_001A4BE0)->state == 4) scale = 1.0f;
        } else scale = 2.0f;
        if (((Hero_00513FD8 *)&D_001A4BE0)->offset != 0.0f) ((Hero_00513FD8 *)&D_001A4BE0)->offset = -6.0f;
    }
    {
    Vec4 *transformed = (Vec4 *)((u8 *)&D_001A4BE0 + 0x1510);
    Hero_00513FD8 *h = (Hero_00513FD8 *)((u8 *)transformed - 0x1510);
    Vec4 *velocity = (Vec4 *)((u8 *)transformed - 0x1400);
    *transformed = *velocity;
    if (h->mode == 1) {
        if (h->state_type == 4 && h->state != 0x86) {
            if (h->distance < 3.0f && !h->blocked) {
                f32 d;
                func_L01_00511508(transformed, velocity, 0.0f);
                h->scale -= func_L01_005114B0(velocity->f);
                d = func_0038CF00(h->point, h->origin);
                if (d > 1.0f) d = h->distance;
                scale = 2.0f - d;
            } else ((Hero_00513FD8 *)&D_001A4BE0)->blocked = 1;
        } else ((Hero_00513FD8 *)&D_001A4BE0)->blocked = 0;
    }
    }
    {
    f32 *current = (f32 *)((u8 *)&D_001A4BE0 + 0x16CC);
    Hero_00513FD8 *h = (Hero_00513FD8 *)((u8 *)current - 0x16CC);
    func_003C41A0(current, current + 1, scale, 0.006400000303983688f, 0.006400000303983688f, 0.64000004529953f);
    func_0038CF68((u8 *)current - 0x1AC, (u8 *)current - 0x22C, h->scale);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(Vec4 *)((u8 *)current - 0x1AC)) : "m"(*(Vec4 *)((u8 *)current - 0x1AC)), "m"(*(vu0_v4 *)h->origin) : "vf1", "vf2");
    if (h->state_type == 25 || h->state == 107) {
        if (h->position.f[2] < h->height + 0.75f) h->position.f[2] = h->height + 0.75f;
    }
    }
    {
    Hero_00513FD8 *h = (Hero_00513FD8 *)&D_001A4BE0;
    if (h->angle > 0.0f) {
        Vec4 zero = { 0 };
        zero.f[0] = func_0038D098(h->angle);
        zero.f[2] = func_0038D0B0(h->angle);
        out = zero;
        func_0038CE20(out.f, out.f, h->angle / 1.5707963705062866f * 0.44999998807907104f);
        func_0038D000((Vec4_50D4D8 *)&out, out.f, &h->rotation);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(h->position) : "m"(h->position), "m"(out) : "vf1", "vf2");
    }
    }
}
/* localdecomp:end func_L01_00513FD8 */

#include "common.h"

typedef struct LaunchState_0042CC70 {
    /* 0x00 */ f32 direction[4];
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ f32 radius;
    /* 0x1C */ f32 height;
    /* 0x20 */ u8 pad20[4];
    /* 0x24 */ s32 flags;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ s16 lifetime;
    /* 0x2E */ u8 pad2E[0x0E];
    /* 0x3C */ u8 active;
    /* 0x3D */ u8 pad3D;
    /* 0x3E */ s16 delay;
    /* 0x40 */ f32 heading;
    /* 0x44 */ s32 age;
} LaunchState_0042CC70;

/* localdecomp:start func_L08_004295F0 */
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00389380(f32, f32);
extern s32 func_0037E0B8(u8 *);
extern void func_L01_00441E00(u8 *, s32, s32, s32, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);

void func_L08_004295F0(u8 *m, LaunchState_0042CC70 *p, s32 animation, s32 flags, s32 frames, f32 angle)
{
    s32 effect;
    s32 active;
    p->direction[0] = func_00388960(angle) * p->radius;
    p->direction[1] = func_00388978(angle) * p->radius;
    p->direction[2] = p->height;
    p->direction[3] = 1.0f;
    {
        f32 heading = func_00389380(angle, 3.1415927f);
        s16 lifetime = 300;
        active = 1;
        p->age = 0;
        p->delay = 0;
        p->heading = heading;
        p->lifetime = lifetime;
        p->active = active;
    }
    effect = func_0037E0B8(m);
    if (effect && *(f32 *)effect == 0.0f) {
        p->flags |= 0x20;
        *(s32 *)(m + 0x98) = 0;
    }
    if (p->flags & 2)
        func_L01_00441E00(m, animation, frames, flags, active);
    else
        func_003BE4F0(m, animation, frames, flags);
}
/* localdecomp:end func_L08_004295F0 */

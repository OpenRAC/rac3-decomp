#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 f12;
    f32 f16;
    f32 f20;
    u8 b24;
    u8 b25;
    s16 h26;
    u8 b28;
    u8 b29;
    u8 b30;
    u8 b31;
    u8 pad32[16];
    s16 h48;
    s16 h50;
    s32 w52;
    s32 w56;
    s32 w60;
} S_003F2A50;

LINKER_REMNANT("asm/levels", func_L01_003F29F8);

INCLUDE_ASM("asm/levels", func_L01_003F2A00);

/* localdecomp:start func_L01_003F2A50 */
extern u8 D_L01_001E5C90[];

S_003F2A50 *func_L01_003F2A50(s32 a0, s32 a1) {
    S_003F2A50 *p = (S_003F2A50 *)(D_L01_001E5C90 + (a0 << 11));
    s32 i;

    for (i = 0; i < 32; i++) {
        if (p->b29 == 0) {
            p->f0 = -1.0f;
            p->f4 = -1.0f;
            p->f8 = -1.0f;
            p->f12 = -1.0f;
            p->f16 = -1.0f;
            p->f20 = -1.0f;
            p->b28 = a1;
            p->w52 = 6;
            p->h50 = 100;
            p->b29 = 1;
            p->w56 = -1;
            p->b24 = 0;
            p->b25 = 0;
            p->h26 = 0;
            p->b30 = 0;
            p->b31 = 0;
            p->w60 = 0;
            p->h48 = 0;
            return p;
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L01_003F2A50 */

LINKER_REMNANT("asm/levels", func_L01_003F2AF0);

/* localdecomp:start func_L01_003F2AF8 */
extern void func_00382810(void *, s32, s32, f32, f32, f32, f32);

void func_L01_003F2AF8(void *a0, u8 *a1) {
    a1[29] = 0;
    if (*(f32 *)(a1 + 16) >= 0.0f) {
        func_00382810(a0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
    }
}
/* localdecomp:end func_L01_003F2AF8 */

/* localdecomp:start func_L01_003F2B58 */
typedef struct {
    f32 distance;       /* each float is -1 while unset */
    f32 height;
    f32 look_height;
    f32 tilt;
    f32 fov;
    f32 drag;
    u8 stiff_look;
    u8 stiff_look2;
    s16 stick_lock;     /* 1 both axes, 2 the yaw, 3 the pitch */
    u8 priority;
    u8 in_use;
    u8 steer;
    u8 steer_when_idle;
    f32 direction[4];
    s16 idle_count;
    s16 idle_frames;
    s32 steer_speed;    /* degrees a frame */
    s32 lifetime;       /* frames, -1 for ever */
    s32 no_mode4;
} CameraVolume_3F2B58;

typedef struct {
    u8 pad[0x100];
    f32 right_x;
    f32 right_y;
} Pad_3F2B58;

extern s32 D_L01_001DF900[2];
extern Pad_3F2B58 *D_L01_001D52FC;
extern void func_L01_003E8BD0(s32 player, s32 both, f32 distance, f32 gain);
extern void func_L01_003E8E70(s32 player);
extern void func_L01_003E8C28(s32 player, f32 height, f32 gain);
extern void func_L01_003E8D48_003F2B58(s32 player, f32 tilt);
extern void func_L01_003E8C70(s32 player, s32 flag, f32 look_height, f32 gain);
extern void func_L01_003F3378(s32 player, f32 drag);
extern void func_L01_003E8F90(s32 player, s32 axes);
extern void func_L01_003EB2C0(s32 player);
extern void func_L01_003E8D80(s32 player, s32 a);
extern void func_L01_003E8EA8(s32 player);
extern void func_L01_003E8E10_003F2B58(s32 player, f32 spring, f32 damping);
extern void func_L01_003E8DB8(s32 player, f32 spring, f32 damping);
extern void func_L01_003E9250(s32 player, f32 *direction, f32 speed, f32 a);
extern s32 func_0038CB00(s16 *count);

/* camera_volumes_update: picks the player's active camera volume (the in-use slot with the
   highest priority, counting down lifetimes) and applies its overrides. */
s32 func_L01_003F2B58(s32 player) {
    CameraVolume_3F2B58 *v;
    s32 best_priority = -1;
    s32 best = -1;
    s32 i;
    s32 old;

    for (i = 0; i < 32; i++) {
        if (((CameraVolume_3F2B58 *)(D_L01_001E5C90 + (player << 11)))[i].in_use) {
            v = &((CameraVolume_3F2B58 *)(D_L01_001E5C90 + (player << 11)))[i];
            if (v->lifetime != 0 && --v->lifetime == 0) {
                func_L01_003F2AF8((void *)player, (u8 *)v);
            } else if (best_priority < v->priority) {
                best_priority = v->priority;
                best = i;
            }
        }
    }
    if (best >= 0) {
        old = D_L01_001DF900[player];
        /* leaving a slot that set the field of view for one that doesn't: back to 1.11 */
        if (old >= 0 && best != old &&
            ((CameraVolume_3F2B58 *)(D_L01_001E5C90 + (player << 11)))[old].fov >= 0.0f &&
            ((CameraVolume_3F2B58 *)(D_L01_001E5C90 + (player << 11)))[best].fov < 0.0f) {
            func_00382810((void *)player, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        }
    }
    D_L01_001DF900[player] = best;
    if (best >= 0) {
        v = &((CameraVolume_3F2B58 *)(D_L01_001E5C90 + (player << 11)))[best];
        if (v->distance >= 0.0f) {
            func_L01_003E8BD0(player, 0, v->distance, 0.001f);
            /* outside 4.64-6 u the push-back is off */
            if (v->distance < 4.64f || v->distance > 6.0f) {
                func_L01_003E8E70(player);
            }
        }
        if (v->height >= 0.0f) {
            func_L01_003E8C28(player, v->height, 0.001f);
        }
        if (__builtin_fabsf(v->tilt + 1.0f) > 0.001f) { /* set: not -1 */
            func_L01_003E8D48_003F2B58(player, v->tilt);
        }
        if (v->look_height >= 0.0f) {
            func_L01_003E8C70(player, 0, v->look_height, 0.005f);
        }
        if (v->drag >= 0.0f) {
            func_L01_003F3378(player, v->drag);
        }
        if (v->stick_lock != 0) {
            if (v->stick_lock == 1) {
                func_L01_003E8F90(player, -1);
            } else if (v->stick_lock == 2) {
                func_L01_003E8F90(player, 1);
            } else if (v->stick_lock == 3) {
                func_L01_003E8F90(player, 2);
            }
        }
        if (v->no_mode4) {
            func_L01_003EB2C0(player);
        }
        if (v->stiff_look) {
            func_L01_003E8E70(player);
            func_L01_003E8D80(player, 0);
            func_L01_003E8EA8(player);
            func_L01_003E8E10_003F2B58(player, 0.01f, 0.2f);
            func_L01_003E8DB8(player, 0.03f, 0.2f);
        }
        if (v->stiff_look2) {
            func_L01_003E8EA8(player);
            func_L01_003E8DB8(player, 0.03f, 0.2f);
            func_L01_003E8E10_003F2B58(player, 0.0075f, 0.2f);
        }
        if (v->fov >= 0.0f) {
            func_00382810((void *)player, 0, 3, v->fov, 0.005f, 0.2f, 0.0f);
        }
        if (v->steer > 0.0f) {
            func_L01_003E9250(player, v->direction, v->steer_speed * 0.017453292f /* degrees to radians */, 0.0f);
        }
        if (v->steer_when_idle > 0.0f) {
            if (func_0038CB00(&v->idle_count)) {
                func_L01_003E9250(player, v->direction, v->steer_speed * 0.017453292f, 0.0f);
            }
            if (__builtin_fabsf(D_L01_001D52FC->right_x) > 0.01f || __builtin_fabsf(D_L01_001D52FC->right_y) > 0.01f) {
                /* the right stick moved: restart the rest count */
            v->idle_count = v->idle_frames;
            }
        }
    return best;
    }
    return -1;
}
/* localdecomp:end func_L01_003F2B58 */

/* localdecomp:start func_L01_003F3068 */
typedef struct {
    u8 pad0[1056];
    s32 w420;
    f32 f424;
    f32 f428;
    f32 f42C;
    f32 f430;
    s32 w434;
    u8 b438;
    u8 b439;
    u8 pad43A[1120 - 1082];
} S_3F0EF0;
extern S_3F0EF0 D_L01_001E2A40[];
extern f32 D_L01_001E7630[];
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_003873C0(void);
void func_L01_003F3068(s32 a0) {
    S_3F0EF0 *p = &D_L01_001E2A40[a0];
    f32 s;
    p->b439 = 0;
    p->f424 = 1.11002934f;
    p->f428 = 1.11002934f;
    s = func_0038D0B0(0.55501467f);
    D_L01_001E7630[0] = s / func_0038D098(0.55501467f);
    func_003873C0();
    p->f42C = 0.00499999989f;
    p->f430 = 0.200000003f;
    p->w420 = 0;
    p->w434 = 0;
}
/* localdecomp:end func_L01_003F3068 */

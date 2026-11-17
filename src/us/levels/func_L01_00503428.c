#include "common.h"

/* NTSC-U counterpart of func_L01_00507380 (src/levels/shared/L01_005063E8.c) */
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern s32 D_001D545C;
extern u8 D_001A4BE0[];

/* localdecomp:start func_L01_00503428 */
/* hero_lock_on (open-rac-engine lock_on.rs): picks the lock-on target through target_search
   (func_L01_004E5BB8). Its float arguments come before the ints in the prototype: same
   registers either way, but that order gives retail's argument setup. */
extern u8 D_001A4BE0[];
extern u8 D_00142A60[];
extern u8 D_L01_001E2AC0[];
extern s32 D_001D4C38;
extern s32 D_001D545C;
extern f32 func_003887C8(void *, void *);
extern void *func_L01_004E5BB8(void *from, f32 range, f32 yaw, f32 cone, f32 rise, s32 cls, s32 flag);

typedef struct {
    u8 pad0[0x80];
    f32 pos[4];
    u8 pad90[0x98 - 0x90];
    f32 yaw;
    u8 pad9C[0x1228 - 0x9C];
    s32 held_item;
    u8 pad122C[0x1430 - 0x122C];
    void *lock_target;
    u8 pad1434[0x16B0 - 0x1434];
    s32 camera_mode;
    u8 pad16B4[0x25C4 - 0x16B4];
    s32 state;
} H_507380;
typedef struct {
    u8 pad0[0x1A0];
    u32 held;
    u32 pressed;
} P_507380;
typedef struct {
    u8 pad0[0x10];
    f32 pos[4];
    u8 state;
    u8 pad21[0x30 - 0x21];
    unsigned long flags;
} T_507380;
typedef struct {
    u8 pad0[0x1B0];
    u16 count;
    u8 pad1B2[0x1B4 - 0x1B2];
    u32 time;
    u32 levels;
} K_507380;
extern K_507380 D_001A7C10_507380;
extern P_507380 *D_001D52FC_507380;

/* hero_lock_on: holding L2 and R2, a new press picks a target near the middle of the view (else
   near his facing); the target is dropped beyond 30 u, when a button is let go, or when it dies,
   and a death is counted */
void func_L01_00503428(void) {
    u32 time;
    u8 *cam;
    unsigned long flag_bits;

    if (((H_507380 *)D_001A4BE0)->held_item < 0 || !(((flag_bits = D_00142A60[((H_507380 *)D_001A4BE0)->held_item]) >> 5) & 1)
        || ((H_507380 *)D_001A4BE0)->camera_mode == 1) {
        ((H_507380 *)D_001A4BE0)->lock_target = 0;
        return;
    }
    if (((H_507380 *)D_001A4BE0)->state == 0x31) {
        ((H_507380 *)D_001A4BE0)->lock_target = 0;
        return;
    }
    if (((H_507380 *)D_001A4BE0)->lock_target != 0) {
        if (func_003887C8(((H_507380 *)D_001A4BE0)->pos,
                          ((T_507380 *)((H_507380 *)D_001A4BE0)->lock_target)->pos) > 30.0f) {
            ((H_507380 *)D_001A4BE0)->lock_target = 0;
        }
        if ((D_001D52FC_507380->held & 3) != 3) {
            ((H_507380 *)D_001A4BE0)->lock_target = 0;
        }
        if (((H_507380 *)D_001A4BE0)->lock_target == 0) {
            return;
        }
        if ((((T_507380 *)((H_507380 *)D_001A4BE0)->lock_target)->flags & 0x100200000000UL) == 0x100000000000UL) {
            {
                u8 st = ((T_507380 *)((H_507380 *)D_001A4BE0)->lock_target)->state;
                if (st == 0xFE) goto drop;
                if (st == 0xFD) goto drop;
                if (((u8 *)((H_507380 *)D_001A4BE0)->lock_target)[0x31] != 0) {
                    return;
                }
            }
drop:
        }
        ((H_507380 *)D_001A4BE0)->lock_target = 0;
        if (D_001A7C10_507380.count < 0xFFFF) {
            D_001A7C10_507380.count++;
        }
        time = D_001D4C38;
        if (D_001A7C10_507380.time < time) {
            D_001A7C10_507380.time = time;
        }
        D_001A7C10_507380.levels |= 1 << D_001D545C;
        D_001A7C10_507380.levels |= 0x80000000;
        return;
    }
    if ((D_001D52FC_507380->held & 3) != 3) {
        return;
    }
    if ((D_001D52FC_507380->pressed & 3) == 0) {
        return;
    }
    cam = D_L01_001E2AC0;
    {
        u8 *aim = cam + 0x380;
        f32 yaw = *(f32 *)(cam + 0x18);
        ((H_507380 *)D_001A4BE0)->lock_target = func_L01_004E5BB8(aim, 25.0f, yaw, 0.61086524f, 1.2217305f, 5, 1);
    }
    if (((H_507380 *)D_001A4BE0)->lock_target == 0) {
        ((H_507380 *)D_001A4BE0)->lock_target = func_L01_004E5BB8(D_001A4BE0, 25.0f, ((H_507380 *)D_001A4BE0)->yaw, 0.61086524f, 1.2217305f, 5, 1);
    }
}
/* localdecomp:end func_L01_00503428 */

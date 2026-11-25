#include "common.h"

/* localdecomp:start func_L19_004E1D60 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80];
    vu0_v4 pos;
    u8 pad90[0x60];
    vu0_v4 vel;
    u8 pad100[0x10];
    vu0_v4 vel2;
    u8 pad120[0xBC];
    s16 timer;
    u8 pad1DE[0x3E];
    s16 timer2;
    u8 pad21E[0x16];
    s32 blocked;
    u8 pad238[0x3F6];
    s16 f62E;
    u8 pad630[0x34];
    u8 *f664;
    u8 pad668[0xE11];
    u8 grounded;
    u8 pad147A[0x236];
    s32 camera;
    u8 pad16B4[0xF0C];
    u8 *target;
    s32 mode;
    s32 pad25C8;
    s32 state;
    u8 pad25D0[0x14];
    u8 form;
    u8 pad25E5[0x223];
    u8 *interacted;
    u8 pad280C[0x44];
    s32 active;
} Hero_004C2ED8;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 direction;
    u8 *target;
    u32 flags;
    u8 kind;
    u8 pad29[3];
    f32 amount;
    u32 flags30;
    s32 pad34;
    u8 *owner;
    s32 pad3C;
} Contact_004C2ED8;

extern Hero_004C2ED8 D_001A4BE0;
extern vu0_v4 D_001A4CD0[];
extern s32 D_L19_001D66D4;
extern Contact_004C2ED8 D_L19_001ED0C0[];
extern u8 D_00142660[];
extern s16 D_001426A0 __attribute__((section(".data")));
extern s32 func_L01_0041A4F0(void);
extern f32 func_L01_004C93D8(void);
extern f32 func_L01_004C9360(f32);
extern f32 func_L01_004DFE88(s32);
extern void func_L01_004E1560(void);
extern void func_L01_005110E8(void *, s32, f32, f32, f32);
extern void func_L19_004F32A0(s32, s32);
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_L01_004DFEA0(s32);
extern void func_L01_003F1F20(s32, s32);
extern void func_L01_004F4E70(s32, s32);
extern void func_L01_004ED838(void *, s32, f32, f32);
extern void func_L01_00511618(void *, void *, f32);

s32 func_L19_004E1D60(s32 apply) {
    Contact_004C2ED8 *c;
    vu0_v4 move;
    u8 *other;
    s32 n;
    s32 hit;
    f32 rate;

    if (D_001A4BE0.state == 20 || D_001A4BE0.state == 7) {
        return 0;
    }
    if (D_001A4BE0.mode == 0x74) {
        return 0;
    }
    if (D_001A4BE0.mode == 0x31) {
        return 0;
    }
    if (D_001A4BE0.timer != 0) {
        return 0;
    }
    if (D_L19_001D66D4 != 0) {
        return 0;
    }
    D_001A4BE0.interacted = 0;
    if (D_001A4BE0.target[0xA8] == 0xFF) {
        return 0;
    }
    c = &D_L19_001ED0C0[D_001A4BE0.target[0xA8]];
    if (c->owner != D_001A4BE0.target) {
        return 0;
    }
    if (!(c->flags & 9)) {
        return 0;
    }
    if (D_001A4BE0.blocked != 0) {
        return 0;
    }
    if (c->amount != 0.0f && func_L01_0041A4F0() != 0 && D_001A4BE0.form != 5) {
        D_00142660[0x5A] = 0;
        D_00142660[0x5B] = 0;
    }
    if (func_L01_004C93D8() != 0.0f && D_001A4BE0.form == 0 && !(c->flags & 0x20000000)) {
        c->amount = func_L01_004C9360(c->amount);
        if (c->amount == 0.0f) {
            return 0;
        }
    }
    if ((c->flags & 0x20000000) && D_001A4BE0.form == 0) {
        n = D_001426A0;
        if (n > 4) {
            n = 4;
        }
        if (n < 0) {
            n = 0;
        }
        c->amount /= func_L01_004DFE88(n);
    }
    D_001A4BE0.interacted = c->target;
    if (D_001A4BE0.state == 15) {
        D_001A4BE0.f664 = (u8 *)c;
        D_001A4BE0.f62E = 1;
        return 0;
    }
    if (apply) {
        func_L01_004E1560();
        hit = 0;
        if (c->flags30 & 1) {
            move = c->direction;
            if (c->direction.w == 5627.9248046875f) {
                hit = 1;
            }
        } else if (c->target) {
            vec_sub_ba(&move, &D_001A4BE0.pos, c->target + 0x10);
        } else {
            func_L01_005110E8(&move, 0, -1.0f, 0.0f, 0.0f);
        }
        switch (D_001A4BE0.form) {
        case 0:
            other = D_001A4BE0.interacted;
            if (other != 0 && (*(s16 *)(other + 0xAA) == 0x4EB || *(s16 *)(other + 0xAA) == 0x558 || *(s16 *)(other + 0xAA) == 0x1C5F)) {
                func_L19_004F32A0(0x82, 1);
                return 1;
            }
            if ((D_001A4BE0.mode == 1 || D_001A4BE0.mode == 0x1D || D_001A4BE0.camera == 2) && !(c->flags & 8)) {
                other = func_L01_00447490(D_001A4BE0.target, 1, 0);
                if (other) {
                    func_L01_004DFEA0(*(f32 *)(other + 0x2C));
                }
                if (D_001A4BE0.active == 0) {
                    func_L19_004F32A0(0x16, 1);
                } else {
                    func_L01_003F1F20(0x12, 0);
                }
                D_001A4BE0.timer = 0x40;
                if (D_001A4BE0.timer2 == 0) {
                    D_001A4BE0.timer2 = 15;
                }
                func_L01_004F4E70(20, 0);
                return 0;
            }
            if (c->flags & 8) {
                func_L19_004F32A0(0x91, 1);
            } else {
                func_L19_004F32A0(0x16, 1);
            }
            if (D_001A4BE0.mode == 0x91) {
                qzero(&move);
            } else {
                rate = 0.066000007f;
                if (D_001A4BE0.grounded) {
                    rate = 0.0f;
                }
                func_L01_004ED838(&move, hit, rate, 0.034000002f);
                if (hit && c->kind == 4) {
                    func_L01_00511618(&move, &move, 2.0f);
                }
            }
            break;
        case 1:
            func_L19_004F32A0(0x42, 1);
            func_L01_004ED838(&move, hit, 0.060000002f, 0.060000002f);
            break;
        case 3:
            func_L19_004F32A0(0x55, 1);
            func_L01_004ED838(&move, hit, 0.10000001f, 0.048000004f);
            break;
        }
        vec_add_ba(&D_001A4BE0.vel, &D_001A4BE0.vel, &move);
        vec_add_ba(&D_001A4BE0.vel2, &D_001A4BE0.vel2, &move);
    } else if (D_001A4BE0.timer == 0) {
        other = func_L01_00447490(D_001A4BE0.target, 1, 0);
        if (other) {
            func_L01_004DFEA0(*(f32 *)(other + 0x2C));
        } else {
            func_L01_004DFEA0(1);
        }
        D_001A4BE0.timer = 0x40;
    }
    return 1;
}
/* localdecomp:end func_L19_004E1D60 */

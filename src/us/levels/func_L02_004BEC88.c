#include "common.h"

/* NTSC-U counterpart of func_L02_004C2ED8 (src/levels/shared/L02_004C2ED8.c) */
/* localdecomp:start func_L02_004BEC88 */
/* from rac2-decomp's func_L03_002B8708 */
/* log:
 * v1: rewrite from retail (j-form VU0, no in-body externs): 294 diff (default as: .lit4 constants)
 * v2: --as ps2as, switch (form), sb 0x5A/0x5B order: 55 diff
 * v4: one shared return 1 at the end (if (apply) ... else if (!timer)): VU tail lines up
 * v5: two vec_add_ba (hero.F0 += move, hero.110 += move; CSE'd lqc2 + spill as retail)
 * v6: `other` local for the 0x4EB/0x558/0x1C5F test (rac2's form): 20 diff, early returns only
 * v7: state tests in one if, 0x74 and 0x31 separate: 2 diff; plain small D_L02_001D6694_004BEC88: MATCH
 *     with divs row [1], --flags=-mvu0-use-vf0-vf2 --as ps2as (levels 02 and 09)
 */
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
    u8 pad238[0x1241];
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
extern s32 D_L02_001D6694_004BEC88;
extern Contact_004C2ED8 D_L02_001EC340[];
extern u8 D_00142660[];
extern s16 D_001426A0 __attribute__((section(".data")));
extern s32 func_L01_00417EA0(void);
extern f32 func_L01_004C5828(void);
extern f32 func_L01_004C57B0(f32);
extern f32 func_L01_004DC1A8(s32);
extern void func_L01_004DD850(void);
extern void func_L01_0050D110(void *, s32, f32, f32, f32);
extern void func_L02_004CF3B8(s32, s32);
extern u8 *func_L01_00444358(void *, s32, s32);
extern void func_L01_004DC1C0(s32);
extern void func_L01_003EFFE0(s32, s32);
extern void func_L01_004F1068(s32, s32);
extern void func_L01_004E9A68(void *, s32, f32, f32);
extern void func_L01_0050D640(void *, void *, f32);

s32 func_L02_004BEC88(s32 apply) {
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
    if (D_L02_001D6694_004BEC88 != 0) {
        return 0;
    }
    D_001A4BE0.interacted = 0;
    if (D_001A4BE0.target[0xA8] == 0xFF) {
        return 0;
    }
    c = &D_L02_001EC340[D_001A4BE0.target[0xA8]];
    if (c->owner != D_001A4BE0.target) {
        return 0;
    }
    if (!(c->flags & 9)) {
        return 0;
    }
    if (D_001A4BE0.blocked != 0) {
        return 0;
    }
    if (c->amount != 0.0f && func_L01_00417EA0() != 0 && D_001A4BE0.form != 5) {
        D_00142660[0x5A] = 0;
        D_00142660[0x5B] = 0;
    }
    if (func_L01_004C5828() != 0.0f && D_001A4BE0.form == 0 && !(c->flags & 0x20000000)) {
        c->amount = func_L01_004C57B0(c->amount);
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
        c->amount /= func_L01_004DC1A8(n);
    }
    D_001A4BE0.interacted = c->target;
    if (apply) {
        func_L01_004DD850();
        hit = 0;
        if (c->flags30 & 1) {
            move = c->direction;
            if (c->direction.w == 5627.9248046875f) {
                hit = 1;
            }
        } else if (c->target) {
            vec_sub_ba(&move, &D_001A4BE0.pos, c->target + 0x10);
        } else {
            func_L01_0050D110(&move, 0, -1.0f, 0.0f, 0.0f);
        }
        switch (D_001A4BE0.form) {
        case 0:
            other = D_001A4BE0.interacted;
            if (other != 0 && (*(s16 *)(other + 0xAA) == 0x4EB || *(s16 *)(other + 0xAA) == 0x558 || *(s16 *)(other + 0xAA) == 0x1C5F)) {
                func_L02_004CF3B8(0x82, 1);
                return 1;
            }
            if ((D_001A4BE0.mode == 1 || D_001A4BE0.mode == 0x1D || D_001A4BE0.camera == 2) && !(c->flags & 8)) {
                other = func_L01_00444358(D_001A4BE0.target, 1, 0);
                if (other) {
                    func_L01_004DC1C0(*(f32 *)(other + 0x2C));
                }
                if (D_001A4BE0.active == 0) {
                    func_L02_004CF3B8(0x16, 1);
                } else {
                    func_L01_003EFFE0(0x12, 0);
                }
                D_001A4BE0.timer = 0x4D;
                if (D_001A4BE0.timer2 == 0) {
                    D_001A4BE0.timer2 = 18;
                }
                func_L01_004F1068(20, 0);
                return 0;
            }
            if (D_001A4BE0.state == 18) {
                func_L02_004CF3B8(0x77, 1);
            } else if (D_001A4BE0.state == 17) {
                func_L02_004CF3B8(0x78, 1);
            } else if (c->flags & 8) {
                func_L02_004CF3B8(0x91, 1);
            } else {
                func_L02_004CF3B8(0x16, 1);
            }
            if (D_001A4BE0.mode == 0x91) {
                qzero(&move);
            } else {
                rate = 0.055000003f;
                if (D_001A4BE0.grounded) {
                    rate = 0.0f;
                }
                func_L01_004E9A68(&move, hit, rate, 0.028333336f);
                if (hit && c->kind == 4) {
                    func_L01_0050D640(&move, &move, 2.0f);
                }
            }
            break;
        case 3:
            func_L02_004CF3B8(0x55, 1);
            func_L01_004E9A68(&move, hit, 0.083333336f, 0.040000003f);
            break;
        }
        vec_add_ba(&D_001A4BE0.vel, &D_001A4BE0.vel, &move);
        vec_add_ba(&D_001A4BE0.vel2, &D_001A4BE0.vel2, &move);
    } else if (D_001A4BE0.timer == 0) {
        other = func_L01_00444358(D_001A4BE0.target, 1, 0);
        if (other) {
            func_L01_004DC1C0(*(f32 *)(other + 0x2C));
        } else {
            func_L01_004DC1C0(1);
        }
        D_001A4BE0.timer = 0x4D;
    }
    return 1;
}
/* localdecomp:end func_L02_004BEC88 */

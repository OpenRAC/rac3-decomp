/* Level 4 (Marcadia), file L04_004FCAF0.c. Needs -mvu0-use-vf0-vf2 and @ps2as on that one-function file (VU0 adds, inline float constants, the lui form of D_001D6694); measured with `check.py --as ps2as --flags=-mvu0-use-vf0-vf2`. 41 aligned differences: the first early-return block (retail keeps it right after the first test group and later returns jump back to it; here cross-jumping keeps a later copy), and the VU0 register choice in the final add/copy block (retail loads the vector into vf1). Stopped per AGENTS.md. */
#include "common.h"

/* localdecomp:start func_L04_004FCAF0 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x80];
    vu0_v4 f80;
    u8 pad90[0x60];
    vu0_v4 fF0;
    u8 pad100[0x10];
    vu0_v4 f110;
    u8 pad120[0xBC];
    s16 f1DC;
    u8 pad1DE[0x3E];
    s16 f21C;
    u8 pad21E[0x16];
    s32 f234;
    u8 pad238[0x1241];
    u8 f1479;
    u8 pad147A[0x236];
    s32 f16B0;
    u8 pad16B4[0xF0C];
    u8 * f25C0;
    s32 f25C4;
    u8 pad25C8[0x4];
    s32 f25CC;
    u8 pad25D0[0x14];
    u8 f25E4;
    u8 pad25E5[0x223];
    u8 * f2808;
    u8 pad280C[0x44];
    s32 f2850;
} Hero_L04_004FCAF0;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 *src;
    u32 flags;
    u8 kind;
    u8 pad29[3];
    f32 dmg;
    u32 f30;
    u8 pad34[4];
    u8 *target;
    u8 pad3C[4];
} Hit_L04_004FCAF0;

__asm__(".extern D_001A4BE0, 16");
extern Hero_L04_004FCAF0 D_001A4BE0;
extern s32 D_001D6694;
extern u8 D_00142660[];
extern s16 D_001426A0[];
extern Hit_L04_004FCAF0 D_L04_001ED800[];
extern s32 func_L01_0041A4F0(void);
extern f32 func_L01_004C93D8(void);
extern f32 func_L01_004C9360(f32);
extern f32 func_L01_004DFE88(s32);
extern void func_L01_004E1560(void);
extern void func_L01_005110E8(void *, s32, f32, f32, f32);
extern void func_L04_0050CB28(s32, s32);
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_L01_004DFEA0(s32);
extern s32 func_L01_003F1F20(s32, s32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L01_004ED838(void *, s32, f32, f32);
extern void func_L01_00511618(void *, void *, f32);

s32 func_L04_004FCAF0(s32 apply) {
    Hit_L04_004FCAF0 *e;
    u8 *src;
    u8 *hit;
    s32 n;
    s32 flag;
    s16 cls;
    u8 idx;
    vu0_v4 vec;
    vu0_v4 tmp;

    if (D_001A4BE0.f25CC == 0x14 || D_001A4BE0.f25CC == 7 || D_001A4BE0.f25C4 == 0x74) {
        return 0;
    }
    if (D_001A4BE0.f25C4 == 0x31 || D_001A4BE0.f1DC != 0 || D_001D6694 != 0) {
        return 0;
    }
    D_001A4BE0.f2808 = 0;
    idx = D_001A4BE0.f25C0[0xA8];
    if (idx == 0xFF) {
        return 0;
    }
    e = D_L04_001ED800 + idx;
    if (e->target != D_001A4BE0.f25C0) {
        return 0;
    }
    if (!(e->flags & 9)) {
        return 0;
    }
    if (D_001A4BE0.f234 != 0) {
        return 0;
    }
    if (e->dmg != 0.0f && func_L01_0041A4F0() && D_001A4BE0.f25E4 != 5) {
        D_00142660[0x5A] = 0;
        D_00142660[0x5B] = 0;
    }
    if (func_L01_004C93D8() != 0.0f && D_001A4BE0.f25E4 == 0 && !(e->flags & 0x20000000)) {
        e->dmg = func_L01_004C9360(e->dmg);
        if (e->dmg == 0.0f) {
            return 0;
        }
    }
    if ((e->flags & 0x20000000) && D_001A4BE0.f25E4 == 0) {
        n = D_001426A0[0];
        if (n > 4) {
            n = 4;
        }
        if (n < 0) {
            n = 0;
        }
        e->dmg /= func_L01_004DFE88(n);
    }
    D_001A4BE0.f2808 = e->src;
    if (apply != 0) {
        func_L01_004E1560();
        flag = 0;
        if (e->f30 & 1) {
            vec = e->pos;
            if (e->pos.w == 5627.9248f) {
                flag = 1;
            }
        } else {
            src = e->src;
            if (src != 0) {
                vec_sub_ba(&vec, &D_001A4BE0.f80, src + 0x10);
            } else {
                func_L01_005110E8(&vec, 0, -1.0f, 0.0f, 0.0f);
            }
        }
        switch (D_001A4BE0.f25E4) {
        case 0:
            if (D_001A4BE0.f2808 != 0) {
                cls = *(s16 *)(D_001A4BE0.f2808 + 0xAA);
                if (cls == 0x4EB || cls == 0x558 || cls == 0x1C5F) {
                    func_L04_0050CB28(0x82, 1);
                    return 1;
                }
            }
            if ((D_001A4BE0.f25C4 == 1 || D_001A4BE0.f25C4 == 0x1D || D_001A4BE0.f16B0 == 2) && !(e->flags & 8)) {
                hit = func_L01_00447490(D_001A4BE0.f25C0, 1, 0);
                if (hit != 0) {
                    func_L01_004DFEA0(*(f32 *)(hit + 0x2C));
                }
                if (D_001A4BE0.f2850 == 0) {
                    func_L04_0050CB28(0x16, 1);
                } else {
                    func_L01_003F1F20(0x12, 0);
                }
                D_001A4BE0.f1DC = 0x40;
                if (D_001A4BE0.f21C == 0) {
                    D_001A4BE0.f21C = 0xF;
                }
                func_L01_004F4E70(0x14, 0);
                return 0;
            }
            if (D_001A4BE0.f25CC == 0x12) {
                func_L04_0050CB28(0x77, 1);
            } else if (D_001A4BE0.f25CC == 0x11) {
                func_L04_0050CB28(0x78, 1);
            } else if (e->flags & 8) {
                func_L04_0050CB28(0x91, 1);
            } else {
                func_L04_0050CB28(0x16, 1);
            }
            if (D_001A4BE0.f25C4 == 0x91) {
                qzero(&vec);
            } else {
                func_L01_004ED838(&vec, flag, D_001A4BE0.f1479 ? 0.0f : 0.0660000071f, 0.0340000018f);
                if (flag && e->kind == 4) {
                    func_L01_00511618(&vec, &vec, 2.0f);
                }
            }
            break;
        case 1:
            func_L04_0050CB28(0x42, 1);
            func_L01_004ED838(&vec, flag, 0.0600000024f, 0.0600000024f);
            break;
        case 3:
            func_L04_0050CB28(0x55, 1);
            func_L01_004ED838(&vec, flag, 0.100000009f, 0.0480000041f);
            break;
        }
        vec_copy(&tmp, &vec);
        vec_add_ba(&D_001A4BE0.fF0, &D_001A4BE0.fF0, &vec);
        vec_add_ab(&D_001A4BE0.f110, &D_001A4BE0.f110, &tmp);
        return 1;
    } else {
        if (D_001A4BE0.f1DC != 0) {
            return 1;
        }
        hit = func_L01_00447490(D_001A4BE0.f25C0, 1, 0);
        if (hit != 0) {
            func_L01_004DFEA0(*(f32 *)(hit + 0x2C));
        } else {
            func_L01_004DFEA0(1);
        }
        D_001A4BE0.f1DC = 0x40;
        return 1;
    }
    return 1;
}
/* localdecomp:end func_L04_004FCAF0 */

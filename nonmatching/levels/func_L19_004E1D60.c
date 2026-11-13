/* draft (level 19, Opus): 195 diff with -mvu0-use-vf0-vf2 ... @ps2as; see nonmatching/README.md */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_004E1D60 */
typedef struct {
    vu0_v4 point;
    vu0_v4 momentum;
    u8 *attacker;
    s32 flags;
    u8 x28;
    u8 pad29[3];
    f32 damage;
    s32 x30;
    u8 pad34[4];
    u8 *victim;
    u8 pad3C[4];
} S_4E1D60h;

extern u8 D_001A4BE0[];
extern s32 D_L19_001D66D4;
extern S_4E1D60h D_L19_001ED0C0[];
extern u8 D_00142660[];
extern s16 D_001426A0[];
extern s32 func_L01_0041A4F0(void);
extern f32 func_L01_004C93D8(void);
extern f32 func_L01_004C9360(f32);
extern f32 func_L01_004DFE88(s32);
extern void func_L01_004E1560(void);
extern void func_L01_005110E8(void *, s32, f32, f32, f32);
extern s32 func_L19_004F32A0(s32, s32);
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_L01_004DFEA0(s32);
extern s32 func_L01_003F1F20(u32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L01_004ED838(void *, s32, f32, f32);
extern void func_L01_00511618(void *, void *, f32);

s32 func_L19_004E1D60(s32 knock) {
    vu0_v4 push;
    vu0_v4 push2;
    u8 *h;
    S_4E1D60h *hit;
    u8 *hm;
    u8 *att;
    u8 *m;
    s32 n;

    h = D_001A4BE0;
    if (*(s32 *)(h + 0x25CC) == 0x14 || *(s32 *)(h + 0x25CC) == 7 || *(s32 *)(h + 0x25C4) == 0x74 ||
        *(s32 *)(h + 0x25C4) == 0x31 || *(s16 *)(h + 0x1DC) != 0 || D_L19_001D66D4 != 0) {
        return 0;
    }
    *(s32 *)(h + 0x2808) = 0;
    hm = *(u8 **)(h + 0x25C0);
    if (hm[0xA8] == 0xFF) {
        return 0;
    }
    hit = &D_L19_001ED0C0[hm[0xA8]];
    if (hit->victim != hm) {
        return 0;
    }
    if ((hit->flags & 9) == 0) {
        return 0;
    }
    if (*(s32 *)(h + 0x234) != 0) {
        return 0;
    }
    if (hit->damage != 0.0f && func_L01_0041A4F0() != 0 && h[0x25E4] != 5) {
        D_00142660[0x5B] = 0;
        D_00142660[0x5A] = 0;
    }
    if (func_L01_004C93D8() != 0.0f && D_001A4BE0[0x25E4] == 0 && !(hit->flags & 0x20000000)) {
        hit->damage = func_L01_004C9360(hit->damage);
        if (hit->damage == 0.0f) {
            return 0;
        }
    }
    if ((hit->flags & 0x20000000) && D_001A4BE0[0x25E4] == 0) {
        n = D_001426A0[0];
        if (n >= 5) {
            n = 4;
        }
        if (n < 0) {
            n = 0;
        }
        hit->damage /= func_L01_004DFE88(n);
    }
    h = D_001A4BE0;
    *(u8 **)(h + 0x2808) = hit->attacker;
    if (*(s32 *)(h + 0x25CC) == 0xF) {
        *(S_4E1D60h **)(h + 0x664) = hit;
        *(s16 *)(h + 0x62E) = 1;
        return 0;
    }
    if (knock != 0) {
        func_L01_004E1560();
        knock = 0;
        if (hit->x30 & 1) {
            push = hit->point;
            if (hit->point.w == 5627.925f) {
                knock = 1;
            }
        } else if (hit->attacker != 0) {
            vec_sub_ba(&push, h + 0x80, hit->attacker + 0x10);
        } else {
            func_L01_005110E8(&push, 0, -1.0f, 0.0f, 0.0f);
        }
        switch (D_001A4BE0[0x25E4]) {
        case 0:
            att = *(u8 **)(D_001A4BE0 + 0x2808);
            if (att != 0 && (*(s16 *)(att + 0xAA) == 0x4EB || *(s16 *)(att + 0xAA) == 0x558 ||
                             *(s16 *)(att + 0xAA) == 0x1C5F)) {
                func_L19_004F32A0(0x82, 1);
                return 1;
            }
            if (*(s32 *)(D_001A4BE0 + 0x25C4) == 1 || *(s32 *)(D_001A4BE0 + 0x25C4) == 0x1D ||
                *(s32 *)(D_001A4BE0 + 0x16B0) == 2) {
                if (!(hit->flags & 8)) {
                    h = D_001A4BE0;
                    m = func_L01_00447490(*(u8 **)(h + 0x25C0), 1, 0);
                    if (m != 0) {
                        func_L01_004DFEA0(*(f32 *)(m + 0x2C));
                    }
                    if (*(s32 *)(h + 0x2850) == 0) {
                        func_L19_004F32A0(0x16, 1);
                    } else {
                        ((s32 (*)(s32, s32))func_L01_003F1F20)(0x12, 0);
                    }
                    h = D_001A4BE0;
                    *(s16 *)(h + 0x1DC) = 0x40;
                    if (*(s16 *)(h + 0x21C) == 0) {
                        *(s16 *)(h + 0x21C) = 0xF;
                    }
                    func_L01_004F4E70(0x14, 0);
                    return 0;
                }
                func_L19_004F32A0(0x91, 1);
            } else if (hit->flags & 8) {
                func_L19_004F32A0(0x91, 1);
            } else {
                func_L19_004F32A0(0x16, 1);
            }
            h = D_001A4BE0;
            if (*(s32 *)(h + 0x25C4) == 0x91) {
                qzero(&push);
            } else {
                func_L01_004ED838(&push, knock, h[0x1479] ? 0.0f : 0.066f, 0.034f);
                if (knock != 0 && hit->x28 == 4) {
                    func_L01_00511618(&push, &push, 2.0f);
                }
            }
            break;
        case 1:
            func_L19_004F32A0(0x42, 1);
            func_L01_004ED838(&push, knock, 0.06f, 0.06f);
            break;
        case 3:
            func_L19_004F32A0(0x55, 1);
            func_L01_004ED838(&push, knock, 0.1f, 0.048f);
            break;
        }
        vec_copy(&push2, &push);
        vec_add_ba(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, &push);
        vec_add_ab(D_001A4BE0 + 0x110, D_001A4BE0 + 0x110, &push2);
        return 1;
    }
    if (*(s16 *)(h + 0x1DC) == 0) {
        m = func_L01_00447490(*(u8 **)(h + 0x25C0), 1, 0);
        if (m != 0) {
            func_L01_004DFEA0(*(f32 *)(m + 0x2C));
        } else {
            func_L01_004DFEA0(1);
        }
        *(s16 *)(D_001A4BE0 + 0x1DC) = 0x40;
    }
    return 1;
}
/* localdecomp:end func_L19_004E1D60 */

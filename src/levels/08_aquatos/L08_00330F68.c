#include "common.h"

/* localdecomp:start func_L08_00330F68 */
/* func_L08_00330F68 (4364 bytes, level 08 only). Drafts by opus-d, finisher3 and r0; finished by b3.
   Needs "-mvu0-use-vf0-vf2 ... @ps2as" on this file and divs_nops "func_L08_00330F68 2 0".
   - Block-scoped hero pointers keep %hi(D_001A4BE0) in $fp (GCSE copy of the HIGH).
   - func_00439418 and func_004EBE80 take fewer arguments: retail leaves the compare's -1 / 0x66 in place.
   - D_001DCE48 is a small-data array: D_001DCE48[1..3] are symbol+offset loads that gcc counts as two
     instructions (kept out of delay slots), [0] is a $gp load in the jal slot.
   - The "moving" chain in the first block is an else-if chain (more refs, so moving gets $s5).
   - The second block re-tests the seat condition inside its then-arm (retail's doubled bc1f). */
#include "vu0.h"

extern u8 D_001A4BE0[];
extern u8 D_001A30B0[];
extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern s32 D_00142C34[];
extern u8 D_00142BA0[];
extern u8 *D_001DF21C;
extern vu0_q *D_0021D140[];
__asm__(".extern D_001DCE58, 4");
__asm__(".extern D_001DF300, 4");
extern f32 D_001DCE58;
__asm__(".extern D_001DCE48, 16");
extern s32 D_001DCE48[] __attribute__((section(".sdata")));
extern u8 *D_001DF300;

extern void func_003D0CE0(s32);
extern s32 func_003D0D88(s32);
extern void func_003D0DB8(s32);
extern s32 func_003F1710(void *);
extern f32 func_003F1C98(void *, void *);
extern void func_003F1DE0(f32, void *, void *);
extern f32 func_003F20D0(f32);
extern f32 func_003F2BB8(f32, f32);
extern s32 func_003F2D10(s32, s32, f32);
extern s32 func_003F2D58(s32, s32);
extern void func_00413218(s32, s32, s32, s32);
extern u8 *func_0041BBF0(s32, s32);
extern void func_0041F080(u8 *);
extern void func_00426064(u8 *);
extern void func_004279B0(u8 *, s32, s32);
extern void func_0042AFF8(f32, f32, f32, f32, void *, void *, s32);
extern void func_0042FD50(void *, void *, void *, void *);
extern void func_00439348(u8 *, u8 *);
extern void func_00439418(u8 *, s32);
extern u8 *func_0043E308(u8 *);
extern void func_0048CCE0(s32);
extern s32 func_0048D058(s32, s32, u8 *);
extern void func_004D59A0(void *, void *, s32, s32);
extern void func_004DD0C0(s32, s32);
extern void func_004EBDD8(void *, f32, s32);
extern s32 func_004EBE80(void);

#define PL(o, t) (*(t *)(D_001A4BE0 + (o)))
#define M(o, t) (*(t *)(a0 + (o)))
#define V(o, t) (*(t *)(pv + (o)))
#define H(o, t) (*(t *)(hero + (o)))
#define SND(i) (D_001A30B0 + ((i) << 7))

static inline void func_L08_00330F68_prompt(u8 *a0, u8 *pv) {
    if (V(0x9C, s16) == 0) {
        u8 *hero = D_001A4BE0;
        if (H(0x25C4, s32) != 0x66) {
            u8 *pos = a0 + 0x10;
            func_004EBDD8(pos, func_003F2BB8(M(0xF8, f32), 1.5707964f), 1);
        } else if (func_004EBE80()) {
            V(0x9C, s16) = 1;
        }
    } else {
        u8 *hero = D_001A4BE0;
        H(0x212, s16) = 2;
        H(0x1E0, s16) = 0x19;
        if (H(0x360, s32) == 0) {
            func_004DD0C0(0x74, 1);
        }
    }
}

static inline void func_L08_00330F68_ride(u8 *a0, u8 *pv, s32 hud) {
    u8 *snd;
    V(0x74, s32) = 0;
    V(0x84, f32) = V(0x70, f32) * 0.020000001f;
    if (V(0x78, s32) != -1 && M(0xB2, s16) != 0xAD && M(0xB2, s16) != 0xAE) {
        if (hud) {
            u8 *hero = D_001A4BE0;
            H(0x212, s16) = 2;
        }
        if (V(0x80, s32) == -1 || (snd = SND(V(0x80, s32)), *(u8 **)(snd + 0xDC) != a0) || snd[0xD0] == 0) {
            V(0x80, s32) = func_0048D058(0, 4, a0);
        }
        func_004279B0(a0, 2, -1);
        if (V(0x88, s32) != -1) {
            V(0x90, u8 *) = D_001DF300 + (V(0x88, s32) << 7);
        } else {
            V(0x90, u8 *) = 0;
        }
        if (M(0x18, f32) < 425.0f) {
            V(0x74, s32) = *(s32 *)D_0021D140[V(0x78, s32)] - 1;
            func_004279B0(a0, 3, -1);
            if (V(0x8C, s32) != -1) {
                V(0x90, u8 *) = D_001DF300 + (V(0x8C, s32) << 7);
            } else {
                V(0x90, u8 *) = 0;
            }
        }
    } else if (V(0x78, s32) != 0 && (u16)M(0xB2, s16) - 0xAD < 2U) {
        if (hud) {
            u8 *hero = D_001A4BE0;
            H(0x212, s16) = 2;
        }
        if (V(0x80, s32) == -1 || (snd = SND(V(0x80, s32)), *(u8 **)(snd + 0xDC) != a0) || snd[0xD0] == 0) {
            V(0x80, s32) = func_0048D058(0, 4, a0);
        }
        func_004279B0(a0, 2, -1);
        if (V(0x88, s32) != -1) {
            V(0x90, u8 *) = D_001DF300 + (V(0x88, s32) << 7);
        } else {
            V(0x90, u8 *) = 0;
        }
        if (M(0x18, f32) > 425.0f) {
            V(0x74, s32) = *(s32 *)D_0021D140[V(0x78, s32)] - 1;
            func_004279B0(a0, 3, -1);
            if (V(0x8C, s32) != -1) {
                V(0x90, u8 *) = D_001DF300 + (V(0x8C, s32) << 7);
            } else {
                V(0x90, u8 *) = 0;
            }
        }
    }
}

void func_L08_00330F68(u8 *a0) {
    vu0_v4 saved;
    vu0_v4 savedRot;
    vu0_v4 v;
    vu0_v4 v2;
    u8 *pv;
    u8 *hero;
    u8 *snd;
    vu0_q *path;
    u8 *t;
    u8 *o;
    u8 *t2;
    u8 *o2;
    s32 moving;
    s32 c;
    s32 a;
    f32 f;

    saved = M(0x10, vu0_v4);
    pv = M(0x68, u8 *);
    savedRot = M(0xF0, vu0_v4);
    switch (M(0x20, u8)) {
    case 0:
        if (V(0xA4, s32) != -1) {
            func_003D0DB8(V(0xA4, s32));
        }
        M(0x32, s16) = 0xFF;
        if (PL(0x88, f32) < 425.0f && V(0x78, s32) != -1 && M(0xB2, s16) != 0xAD && M(0xB2, s16) != 0xAE) {
            vu0_q *p0 = D_0021D140[V(0x78, s32)];
            M(0x10, vu0_q) = p0[*(s32 *)p0];
        }
        M(0x30, u8) = 0xFF;
        func_004279B0(a0, 1, -1);
        V(0x7C, u8 *) = func_0041BBF0(0x1A89, 0x80);
        func_00439348(V(0x7C, u8 *), a0);
        *(f32 *)(V(0x7C, u8 *) + 0x2C) = *(f32 *)(*(u8 **)(V(0x7C, u8 *) + 0x24) + 0x24) * (M(0x2C, f32) / *(f32 *)(M(0x24, u8 *) + 0x24));
        *(vu0_q *)(V(0x7C, u8 *) + 0x10) = M(0x10, vu0_q);
        V(0x70, f32) = 16.0f;
        V(0xB4, s32) = V(0xAC, s32);
        if (M(0xB0, u8) != 0xFF && (D_001BBC40[M(0xB0, u8) + D_001D545C * 16] & 0x80)) {
            V(0x9E, s16) = 1;
        }
        break;
    case 1:
        moving = 0;
        {
        u8 *hero = D_001A4BE0;
        if (H(0x35C, u8 *) == a0 && (func_003F1C98(a0 + 0x10, hero + 0x80) < 0.75f || M(0xBC, u8) != 0) && H(0x360, s32) != 0) {
            M(0xBC, u8) = 1;
            V(0xB4, s32) = V(0xA8, s32);
            if ((V(0x98, s32) != -1 && V(0x9E, s16) == 0) || ((D_00142C34[0] & 0x200000) && V(0x98, s32) != -1)) {
                func_00439418(a0, 1);
                t = D_001DF21C + (V(0x98, s32) << 8);
                o = func_0043E308(t);
                if (o == 0) {
                    moving = 1;
                } else {
                u8 *gs = D_00142BA0;
                if (*(s32 *)(gs + 0x94) & 0x200000) {
                    moving = 1;
                } else if (D_001DCE58 < func_003F1C98(a0 + 0x10, t + 0x10)) {
                    moving = 1;
                } else if (((*(u8 **)(o + 0x88) == a0 && *(s16 *)(o + 0xC0) != 0) || (*(s32 *)(gs + 0x94) & 0x200000)) && *(f32 *)(o + 0xB0) < 0.1f) {
                    moving = 1;
                }
                }
                if (!moving) {
                    func_L08_00330F68_prompt(a0, pv);
                }
            } else {
                moving = 1;
            }
            if (moving) {
                u8 *hero = D_001A4BE0;
                H(0x212, s16) = 2;
                H(0x1E0, s16) = 0x19;
                if (fabs_asm(*(f32 *)(V(0x7C, u8 *) + 0x18) - M(0x18, f32)) > 1.0f) {
                    *(f32 *)(V(0x7C, u8 *) + 0x18) = M(0x18, f32) + 1.0f;
                }
                *(f32 *)(V(0x7C, u8 *) + 0x18) += 0.120000005f;
                M(0x96, u16)++;
                if (H(0x360, s32) == 0) {
                    func_004DD0C0(0x74, 1);
                }
            }
        }
        }
        if (M(0x96, u16) >= 9) {
        u8 *hero = D_001A4BE0;
        if (H(0x35C, u8 *) == a0 && H(0x360, s32) != 0) {
            if ((V(0x98, s32) != -1 && V(0x9E, s16) == 0) || ((D_00142C34[0] & 0x200000) && V(0x98, s32) != -1)) {
                func_00439418(a0, 1);
                t2 = D_001DF21C + (V(0x98, s32) << 8);
                o2 = func_0043E308(t2);
                if (o2 == 0 || (*(u8 **)(o2 + 0x88) == a0 && *(s16 *)(o2 + 0xC0) != 0 && *(f32 *)(o2 + 0xB0) < 0.1f)) {
                    if (o2 == 0 || *(f32 *)(o2 + 0xB0) < 0.1f) {
                        moving = 1;
                        V(0x9E, s16) = 1;
                    }
                } else if (D_001DCE58 < func_003F1C98(a0 + 0x10, t2 + 0x10)) {
                    moving = 1;
                }
                if (!moving) {
                    func_L08_00330F68_prompt(a0, pv);
                }
            } else {
                moving = 1;
            }
            if (moving) {
                if (V(0xA4, s32) != -1 && V(0x78, s32) != -1 && M(0xB2, s16) != 0xAD && M(0xB2, s16) != 0xAE && M(0x18, f32) > 425.0f) {
                    func_00413218(D_001DCE48[0], D_001DCE48[1], D_001DCE48[2], D_001DCE48[3]);
                    func_003D0CE0(V(0xA4, s32));
                }
                if (func_003F1C98(a0 + 0x10, D_001A4BE0 + 0x80) < 10.0f) {
                    func_004DD0C0(0, 1);
                }
                func_L08_00330F68_ride(a0, pv, 1);
            }
        }
        }
        {
        u8 *hero = D_001A4BE0;
        if (fabs_asm(H(0x88, f32) - M(0x18, f32)) > 50.0f) {
            func_L08_00330F68_ride(a0, pv, 0);
        }
        }
        break;
    case 2:
        hero = D_001A4BE0;
        if (H(0x35C, u8 *) == a0) {
            H(0x1E0, s16) = 2;
            H(0x212, s16) = 2;
        }
        path = D_0021D140[V(0x78, s32)];
        if (V(0xA4, s32) != -1 && V(0xBC, s32) == 0 && func_003D0D88(V(0xA4, s32))) {
            M(0x10, vu0_q) = path[*(s32 *)path - 7];
            V(0x74, s32) = *(s32 *)path - 7;
            func_004D59A0(a0 + 0x10, hero + 0x90, 0, 1);
            V(0xBC, s32) = 1;
        }
        if (V(0x74, s32) >= *(s32 *)path) {
            V(0xBC, s32) = 0;
            if (V(0x80, s32) != -1 && (snd = SND(V(0x80, s32)), *(u8 **)(snd + 0xDC) == a0) && snd[0xD0] != 0) {
                func_0048CCE0(V(0x80, s32));
            }
            V(0x80, s32) = -1;
            func_004279B0(a0, 4, -1);
        } else {
            if (V(0x90, u8 *) != 0) {
                func_0042AFF8(*(f32 *)(V(0x90, u8 *) + 0x78), 6.2831859e-05f, 6.981317e-05f, 0.0069813174f, a0 + 0xF8, pv + 0x94, 0);
            }
            *(vu0_q *)(V(0x7C, u8 *) + 0xF0) = M(0xF0, vu0_q);
            v = *(vu0_v4 *)&path[V(0x74, s32) + 1];
            vec_sub_ba(&v2, &v, a0 + 0x10);
            func_003F1DE0(V(0x84, f32), &v2, &v2);
            vec_add_ab(a0 + 0x10, a0 + 0x10, &v2);
            *(vu0_q *)(V(0x7C, u8 *) + 0x10) = M(0x10, vu0_q);
            *(f32 *)(V(0x7C, u8 *) + 0x18) += 1.0f;
            if (func_003F1C98(a0 + 0x10, &v) < 0.5f) {
                V(0x74, s32)++;
            }
            if (V(0x74, s32) >= *(s32 *)path - 6 && V(0x84, f32) >= 0.060000002f) {
                V(0x84, f32) -= 0.0032000002f;
            }
            func_00426064(a0);
        }
        break;
    case 3:
        {
        u8 *hero = D_001A4BE0;
        if (H(0x35C, u8 *) == a0) {
            H(0x1E0, s16) = 2;
            H(0x212, s16) = 2;
        }
        }
        path = D_0021D140[V(0x78, s32)];
        if (V(0x74, s32) < 0) {
            if (V(0x80, s32) != -1 && (snd = SND(V(0x80, s32)), *(u8 **)(snd + 0xDC) == a0) && snd[0xD0] != 0) {
                func_0048CCE0(V(0x80, s32));
            }
            V(0x80, s32) = -1;
            func_004279B0(a0, 4, -1);
        } else {
            if (V(0x90, u8 *) != 0) {
                func_0042AFF8(*(f32 *)(V(0x90, u8 *) + 0x78), 6.2831859e-05f, 6.981317e-05f, 0.0069813174f, a0 + 0xF8, pv + 0x94, 0);
            }
            *(vu0_q *)(V(0x7C, u8 *) + 0xF0) = M(0xF0, vu0_q);
            v = *(vu0_v4 *)&path[V(0x74, s32) + 1];
            vec_sub_ba(&v2, &v, a0 + 0x10);
            func_003F1DE0(V(0x84, f32), &v2, &v2);
            vec_add_ab(a0 + 0x10, a0 + 0x10, &v2);
            *(vu0_q *)(V(0x7C, u8 *) + 0x10) = M(0x10, vu0_q);
            *(f32 *)(V(0x7C, u8 *) + 0x18) += 1.0f;
            if (func_003F1C98(a0 + 0x10, &v) < 0.5f) {
                V(0x74, s32)--;
            }
            if (V(0x74, s32) < 7 && V(0x84, f32) >= 0.060000002f) {
                V(0x84, f32) -= 0.0032000002f;
            }
            func_00426064(a0);
        }
        break;
    case 4:
        V(0xB4, s32) = V(0xAC, s32);
        *(f32 *)(V(0x7C, u8 *) + 0x18) -= 0.120000005f;
        if (++M(0x96, u16) >= 9) {
            if (func_003F1C98(a0 + 0x10, D_001A4BE0 + 0x80) < 10.0f) {
                func_004DD0C0(0, 1);
            }
            func_004279B0(a0, 5, -1);
        }
        break;
    case 5:
        if (PL(0x35C, u8 *) != a0) {
            if (V(0xA4, s32) != -1) {
                func_003D0DB8(V(0xA4, s32));
            }
            M(0xBC, u8) = 0;
            V(0x9C, s16) = 0;
            func_004279B0(a0, 1, -1);
        }
        break;
    }
    func_0041F080(V(0x7C, u8 *));
    vec_sub_ba(&v, a0 + 0x10, &saved);
    func_0042FD50(pv + 0x30, &v, &savedRot, a0 + 0xF0);
    if (V(0xB4, s32) == V(0xA8, s32)) {
        V(0xB8, f32) += 0.03f;
        if (V(0xB8, f32) > 1.0f) {
            V(0xB8, f32) = 1.0f;
        }
    } else {
        V(0xB8, f32) -= 0.03f;
        if (V(0xB8, f32) < 0.0f) {
            V(0xB8, f32) = 0.0f;
        }
    }
    c = func_003F2D10(V(0xAC, s32), V(0xA8, s32), V(0xB8, f32));
    if (func_003F1710(pv + 0xB0)) {
        V(0xB0, s32) = 50;
    }
    f = func_003F20D0((f32)V(0xB0, s32) * 6.2831855f / 50.0f) * 0.5f + 0.5f;
    a = func_003F2D58(c, 0x80B0B0B0);
    M(0x78, s32) = func_003F2D10(a, func_003F2D58(c, 0x80505050), f);
}
/* localdecomp:end func_L08_00330F68 */

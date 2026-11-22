/* func_L05_003C0EA8: a near miss (nonmatching/README.md has its count and blockers).
 * File: src/levels/shared/L05_003C0EA8.c, flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as. Placed in levels 05, 06, 17 and 21.
 * Written by hand from retail's assembly (no decompiler). The moby's update: a wake-up state
 * machine on m[0x95], then the AI state m[0x20] (cases 2 to 10, a jump table).
 * The repeated sequences of states 3 and 6 (a random target around p+0x310, the flight
 * flags, the steering) are static inline helpers here.
 */
#include "common.h"
#include "vu0.h"

extern s32 func_L05_003C2618(u8 *);
extern void func_003C2880(void *);
extern void func_L05_003C2C90(u8 *);
extern void func_L05_003C2D08(u8 *);
extern void func_L05_003C2B50(u8 *);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_0038CB00(void *);
extern void func_L02_00351780(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00454370(void *, void *);
extern void func_L01_00445BE0(s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0045D218(void *, void *);
extern void func_L01_0045A898(void *, void *, f32);
extern void func_L01_0045A748(void *, void *);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L04_0046CFE0(void *, s32);
extern s32 func_L01_0045BE38(void *, s32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_L01_00451700(void *, void *, s32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_0046B458(void *, s32, u32, s32, s32, void *, s32, f32, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_L01_004395E0(void *);
extern void func_L05_003BD448(void *, void *, void *, void *, s32, s32);

extern s32 D_001D545C;
extern s32 D_001D545C_003C0EA8;
__asm__(".extern D_001D545C_003C0EA8, 16");
extern s32 D_001DEB00;
extern s32 D_001DEB04;
extern s32 D_0021ED80[];
extern u8 D_001D66B0[];
extern s16 D_002A64C0[][4];

/* A new target at a random angle, lo to hi from the home point p+0x310. */
static __inline__ void target_003C0EA8(u8 *p, f32 lo, f32 hi) {
    f32 a = func_00382538();
    f32 r = func_003824E0(lo, hi);

    qzero(p + 0x2E0);
    *(f32 *)(p + 0x2E0) = func_0038D098(a) * r;
    *(f32 *)(p + 0x2E4) = func_0038D0B0(a) * r;
    vec_add_ab(p + 0x2E0, p + 0x2E0, p + 0x310);
}

static __inline__ void fly_003C0EA8(u8 *m, u8 *p) {
    *(s32 *)(p + 0xA8) |= 4;
    *(f32 *)(p + 0x7C) = 0.7f;
    *(f32 *)(p + 0x78) = 0.7f;
    *(u16 *)(m + 0x34) |= 0x100;
    *(f32 *)(p + 0x80) = 12.566371f;
    *(s32 *)(p + 0xA8) |= 1;
}

/* States 3 and 6: wander between random targets. */
static __inline__ void wander_003C0EA8(u8 *m, u8 *p, vu0_v4 *v90, vu0_v4 *vA0) {
    if (func_L01_004561B8(m) != 0) {
        target_003C0EA8(p, 4.0f, 8.0f);
        *(s16 *)(p + 0x2D4) = func_00382498(300, 530);
        if (*(s32 *)(p + 0x2F4) != 0) {
            fly_003C0EA8(m, p);
        }
        func_L01_0045BD78(m, 0.0032000002f, 0.050000004f, 0.010053097f, 0.25132743f);
    }
    if (*(s32 *)(p + 0x2F4) != 0) {
        func_0038CF68(vA0, m + 0xC0, 3.0f);
        vec_add_ba(v90, m + 0x10, vA0);
        func_L01_0045D218(m, v90);
        if (func_0038DBA0(*(f32 *)(m + 0xF8),
                          func_0038D160(*(f32 *)(p + 0x2E0) - *(f32 *)(m + 0x10),
                                        *(f32 *)(p + 0x2E4) - *(f32 *)(m + 0x14))) > 0.17453292f) {
            func_0038D890(m + 0xC0, m + 0xC0, m + 0xE0, 0.09075713f);
            func_0038D890(m + 0xD0, m + 0xD0, m + 0xE0, 0.09075713f);
            *(f32 *)(m + 0xF8) = func_0038D160(*(f32 *)(m + 0xC0), *(f32 *)(m + 0xC4));
        }
    } else {
        func_L01_0045A898(m, p + 0x2E0, *(f32 *)(m + 0xF8));
        func_L01_00448890(m + 0xF8, p + 0x2FC, 0,
                          func_0038D160(*(f32 *)(p + 0x2E0) - *(f32 *)(m + 0x10),
                                        *(f32 *)(p + 0x2E4) - *(f32 *)(m + 0x14)),
                          0.0018151426f, 0.0018151426f, 0.020943953f);
    }
    if (func_0038CF38(m + 0x10, p + 0x2E0) < 0.75f) {
        target_003C0EA8(p, 2.0f, 6.0f);
    }
}

/* States 8 and 9: two sparks at the two emitters (points 3 and 4). */
static __inline__ void sparks_003C0EA8(u8 *m, u8 *p, vu0_v4 *v90, s32 pt) {
    f32 a;
    f32 b;

    func_003C2F58(m, pt, v90);
    a = func_003824E0(0.75f, 1.2f) * *(f32 *)(p + 0x2F8);
    func_L01_0046B458(v90, 2, D_001DEB04, 0, (s32)func_L01_00443A18(1.0f, 4.0f), D_001D66B0, 0,
                      *(f32 *)(p + 0x2F8), a, 0.0f);
    a = *(f32 *)(p + 0x2F8) * 0.3f;
    b = func_003824E0(0.3f, 0.65f) * *(f32 *)(p + 0x2F8);
    func_L01_0046B458(v90, 2, 0x7F7F7F7F, 0, (s32)func_L01_00443A18(1.0f, 4.0f), D_001D66B0, 0, a, b,
                      0.0f);
}

/* State 9: a shot from emitter pt toward p+0x2E0, at most 2.75 long. */
static __inline__ void shot_003C0EA8(u8 *m, u8 *p, vu0_v4 *v90, vu0_v4 *vA0, s32 pt) {
    s32 i;
    s32 slot;

    func_003C2F58(m, pt, v90);
    vec_sub_ba(vA0, p + 0x2E0, v90);
    func_0038CE20(vA0, vA0, 1.5f);
    if (func_0038CEA8(vA0) > 2.75f) {
        func_0038CF68(vA0, vA0, 2.75f);
    }
    vec_add_ab(vA0, vA0, v90);
    slot = 0;
    for (i = 0; i < 10; i++) {
        if (D_002A64C0[i][0] == 0) {
            slot = i;
            break;
        }
    }
    func_L05_003BD448(v90, m, *(void **)(p + 0x230), vA0, pt, slot);
}

void func_L05_003C0EA8(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 mB0[3];
    f32 fE0;
    s32 r;
    f32 d;
    f32 lim;

    if (func_L05_003C2618(m) != 0) {
        func_003C2880(m);
        return;
    }

    switch (m[0x95]) {
    case 0:
        if (func_L01_004561E0(m) != 0 && *(s16 *)(p + 0x2D6) == 0) {
            *(s16 *)(p + 0x2D6) = (func_00382498(0, 30) * 5 + 2) / 6;
        }
        if (*(s16 *)(p + 0x234) == 1 && func_0038CB00(p + 0x2D6) != 0) {
            func_L02_00351780(m);
            if (m[0x43] != 3) {
                func_003C3A10(m, 3, 0, 5);
            }
            func_L01_004450F0(m, 7, 2);
            if (*(s32 *)(p + 0x2F0) != -1) {
                func_L01_004450F0(m, 5, -1);
            }
        } else if (*(s32 *)(p + 0x2D8) != 0 && *(s16 *)(p + 0x2D6) == 0) {
            if (*(s16 *)(p + 0x234) == 1) {
                func_L02_00351780(m);
                if (m[0x43] != 3) {
                    func_003C3A10(m, 3, 0, 5);
                }
                func_L01_004450F0(m, 7, 2);
                if (*(s32 *)(p + 0x2F0) != -1) {
                    func_L01_004450F0(m, 5, -1);
                }
            } else {
                func_L01_004450F0(m, 2, 1);
            }
            *(s32 *)(p + 0x2D8) = 0;
            if (*(s32 *)(p + 0x2D0) < 250) {
                *(s32 *)(p + 0x2D0) = (func_00382498(480, 600) * 5 + 2) / 6;
            }
        }
        if (*(s32 *)(p + 0x2D8) != 0 && *(s16 *)(p + 0x234) != 1) {
            func_0038CB00(p + 0x2D6);
        }
        break;
    case 1:
        if (*(s16 *)(p + 0x234) == 1) {
            if (m[0x43] != 3) {
                func_003C3A10(m, 3, 0, 5);
            }
            func_L01_004450F0(m, 7, 2);
        } else if (*(s32 *)(p + 0x2D0) == 0) {
            func_L01_004450F0(m, 2, 0);
        }
        break;
    case 2:
        if (*(s16 *)(p + 0x234) != 1 && func_L01_004561E0(m) == 0) {
            goto wake;
        }
        break;
    case 3:
        r = func_L01_00454370(m, p + 0x160);
        if (*(f32 *)(p + 0x30) <= 0.0f) {
            if (m[0x21] != 0xFF) {
                func_L01_00445BE0(m[0x21], 0);
            }
            func_L05_003C2B50(m);
            func_003C2F58(m, 1, &v90);
            func_L01_003303B8(&v90, 0, 9, 9, 12, 12, 22, 0, 0.23f, 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 0, 0,
                              0x10000, 0, D_001DEB00, D_001DEB00, D_001DEB00, D_001DEB00, D_001DEB00,
                              D_001DEB00, D_001DEB00, D_001DEB00, D_001DEB00, 0);
            if (*(s32 *)(p + 0x324) == 0) {
                func_003C2880(m);
            } else {
                func_L05_003C2C90(m);
            }
            return;
        }
        if (r & 2) {
            if (*(s16 *)(p + 0x234) == 1) {
                func_L01_004450F0(m, 7, 2);
            } else {
            wake:
                func_L01_004450F0(m, 4, 1);
                *(s32 *)(p + 0x2D0) = (func_00382498(580, 600) * 5 + 2) / 6;
            }
        }
        break;
    }

    switch (m[0x20]) {
    case 2:
        if (m[0x60] & 2) {
            if (m[0x43] != 3) {
                func_003C3A10(m, 3, 0, 8);
            }
            func_L01_004450F0(m, 3, -1);
        }
        break;
    case 3:
        wander_003C0EA8(m, p, &v90, &vA0);
        if (func_0038CB00(p + 0x2D4) != 0) {
            if (m[0x43] != 1) {
                func_003C3A10(m, 1, 0, 8);
            }
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 5:
        if (*(s32 *)(p + 0x2F4) != 0) {
            if (func_L04_0046CFE0(m, D_0021ED80[*(s32 *)(p + 0x2F0)]) != 0 ||
                func_0038CF38(m + 0x10, p + 0x220) < 5.0f) {
                func_L01_004450F0(m, 7, -1);
            }
            break;
        }
        *(s32 *)(p + 0xA8) |= 0x400;
        if (func_L01_0045BE38(m, D_0021ED80[*(s32 *)(p + 0x2F0)]) == 0) {
            if (D_001D545C_003C0EA8 != 6) {
                break;
            }
            if (!(func_0038CF38(m + 0x10, p + 0x220) < 5.0f)) {
                break;
            }
        }
        *(s32 *)(p + 0xA8) &= ~0x400;
        *(vu0_q *)(p + 0x310) = *(vu0_q *)(m + 0x10);
        func_L01_004450F0(m, 7, -1);
        if (D_001D545C_003C0EA8 == 6) {
            fly_003C0EA8(m, p);
        }
        if (*(s32 *)(p + 0x2C0) != -1) {
            if (D_001D545C != 6) {
                *(s32 *)(p + 0x2F4) = 1;
            }
            fly_003C0EA8(m, p);
        }
        break;
    case 6:
        wander_003C0EA8(m, p, &v90, &vA0);
        if (m[0xBC] == 0) {
            func_L01_004450F0(m, 7, -1);
            if (m[0x43] != 3) {
                func_003C3A10(m, 3, 0, 8);
            }
        }
        break;
    case 7:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.0064000003f, 0.10000001f, 0.010053097f, 0.25132743f);
            if (m[0xBC] == 0) {
                if (m[0x21] != 0xFF) {
                    func_L01_00445BE0(m[0x21], 1);
                }
            } else {
                func_L01_004450F0(m, 6, -1);
                if (m[0x43] != 0) {
                    func_003C3A10(m, 0, 0, 8);
                }
            }
        }
        if (*(s32 *)(p + 0x2F4) != 0) {
            func_L01_0045D218(m, p + 0x220);
            vec_sub_ba(&v90, m + 0x10, p + 0x220);
            d = func_0038CF38(m + 0x10, p + 0x220);
            lim = 1.8f;
        } else {
            func_L01_0045A748(m, p + 0x220);
            if (!(func_0038CF38(m + 0x10, p + 0x220) < 1.8f)) {
                break;
            }
            d = func_0038DBA0(*(f32 *)(m + 0xF8),
                              func_0038D160(*(f32 *)(p + 0x220) - *(f32 *)(m + 0x10),
                                            *(f32 *)(p + 0x224) - *(f32 *)(m + 0x14)));
            lim = 0.2617994f;
        }
        if (d < lim) {
            func_L01_004450F0(m, 8, -1);
            if (m[0x43] != 0) {
                func_003C3A10(m, 0, 0, 8);
            }
        }
        break;
    case 10:
        if (func_L01_004561B8(m) != 0) {
            func_L01_00443B88(&v90, 0.0f, 0.5f);
            vec_add_ab(p + 0x300, &v90, p + 0x310);
        }
        if (*(s32 *)(p + 0x2F4) != 0) {
            func_L01_0045D218(m, p + 0x300);
            vec_sub_ba(&v90, m + 0x10, p + 0x300);
        } else {
            func_L01_0045A748(m, p + 0x300);
        }
        if (func_0038CF38(m + 0x10, p + 0x300) < 0.5f) {
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) {
            *(f32 *)(p + 0x2F8) = 0.0f;
        }
        func_L01_0045BD10(m, func_0038D160(*(f32 *)(p + 0x220) - *(f32 *)(m + 0x10),
                                           *(f32 *)(p + 0x224) - *(f32 *)(m + 0x14)));
        if (*(s32 *)(p + 0x2F4) != 0 &&
            func_0038DBA0(*(f32 *)(m + 0xF8),
                          func_0038D160(*(f32 *)(p + 0x2E0) - *(f32 *)(m + 0x10),
                                        *(f32 *)(p + 0x2E4) - *(f32 *)(m + 0x14))) > 0.17453292f) {
            vec_sub_ba(&v90, p + 0x220, m + 0x10);
            fE0 = 0.0f;
            func_L01_00448890(&fE0, p + 0x2FC, 0, func_L01_00451700(m, &v90, 0), 0.010053097f,
                              0.010053097f, 3.1415927f);
            qzero(&vA0);
            vA0.z = *(f32 *)(p + 0x2FC);
            func_0038D308(mB0, &vA0);
            func_0038D5F0(m + 0xC0, m + 0xC0, mB0);
        }
        if (func_L01_004561B8(m) != 0) {
            *(f32 *)(p + 0x2F8) = 0.0f;
            *(f32 *)(m + 0xF8) = func_0038D160(*(f32 *)(m + 0xC0), *(f32 *)(m + 0xC4));
            func_003A52A0(6, 0, m);
        }
        sparks_003C0EA8(m, p, &v90, 3);
        sparks_003C0EA8(m, p, &v90, 4);
        if (*(u16 *)(m + 0x96) >= 0x22) {
            if (m[0x43] != 4) {
                func_003C3A10(m, 4, 0, 8);
            }
            func_L01_004450F0(m, 9, -1);
        }
        *(f32 *)(p + 0x2F8) += 0.026f;
        break;
    case 9:
        if (func_L01_0044E1B8(m, 4.0f) != 0) {
            *(vu0_q *)(p + 0x2E0) = *(vu0_q *)(p + 0x220);
        }
        if (func_L01_004395E0(m) < 6.0f || m[0x42] != 4) {
            sparks_003C0EA8(m, p, &v90, 3);
            sparks_003C0EA8(m, p, &v90, 4);
            *(f32 *)(p + 0x2F8) += 0.026f;
        }
        if (func_L01_0044E1B8(m, 8.0f) != 0) {
            func_003A52A0(1, 0, m);
            shot_003C0EA8(m, p, &v90, &vA0, 3);
            shot_003C0EA8(m, p, &v90, &vA0, 4);
        }
        if (m[0x60] & 2) {
            if (m[0x21] != 0xFF) {
                func_L01_00445BE0(m[0x21], 0);
            }
            func_L01_004450F0(m, 10, -1);
            if (m[0x43] != 3) {
                func_003C3A10(m, 3, 0, 8);
            }
        }
        break;
    }
    func_L05_003C2D08(m);
}

/* func_L01_00320088 (Claude wave 14 r64, 2026-11-28). First draft kept here. */
/* PAL near miss (wave 14 r64, a new first draft; the k8 Opus draft its README row names is not in nonmatching/):
 * hydra_update, the Spitting Hydra's per-frame update. Plain C under the file's own line, check.py first
 * placement 1031 words, 1378 words against retail's 1375: same frame (0x120; the scratch vectors at 0x30..0x5F
 * double as the target list, the query and the filter copy, as retail's stack shows), same calls, constants and
 * control flow in all three parts (charging and firing, the release burst, the lock-on volley).
 * What still differs:
 * - retail calls func_L01_003220D0 and func_L01_003220A0 with the gun in $a0 and func_L01_003218A8 with a second
 *   argument 0x7F40FF40, where the later definitions in L01_0031C1D0.c are (void), (void) and (u8 *): declared
 *   here without prototypes, so the type contract cannot pass until those three signatures change;
 * - D_L01_001E17B0, D_L01_001D6694, D_L01_001E1820 and D_L01_001DFB40 are reached gp-relative in delay slots and
 *   through lui/%lo elsewhere in retail (an assembler-expanded macro without an .extern size): here the aliases
 *   always take lui/%lo;
 * - register allocation (retail keeps %hi(D_001425C0) in $s0 for the weapon-level reads) and the scheduling that
 *   follows from it.
 */
#include "common.h"

/* localdecomp:start func_L01_00320088 */
#include "vu0.h"
typedef int q128_00320088 __attribute__((mode(TI)));
typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    u8 pad40[4];
    s32 w44;
    u8 pad48[8];
    s32 w50;
    s32 w54;
} Vars_00320088;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[0xF];
    u8 b30;
    u8 pad31[0x11];
    u8 b42;
    u8 b43;
    u8 pad44[0x1C];
    u8 b60;
    u8 pad61[7];
    Vars_00320088 *vars;
    u8 pad6C[0x10];
    s16 h7C;
    u8 pad7E[0x2C];
    u16 oclass;
} Moby_00320088;
typedef struct {
    vu0_q dir;
    void *owner;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 oclass;
    f32 damage;
    s32 w20;
} Query_00320088;
typedef struct {
    s32 a;
    s32 b;
} Filter_00320088;
typedef struct {
    u8 b0;
    u8 level;
} Row_00320088;

__asm__(".extern D_L01_001DC974, 4");
__asm__(".extern D_L01_001DC94C, 4");
__asm__(".extern D_L01_001DC940, 4");
__asm__(".extern D_L01_001DC984, 4");
__asm__(".extern D_L01_001DC98C, 4");
__asm__(".extern D_L01_001DC93C, 4");
__asm__(".extern D_L01_001DC970, 4");
__asm__(".extern D_L01_001DC988, 4");
__asm__(".extern D_L01_001DC944, 4");
extern s32 D_L01_001DC974;
extern s32 D_L01_001DC94C;
extern s32 D_L01_001DC940;
extern s32 D_L01_001DC984;
extern s32 D_L01_001DC98C;
extern s32 D_L01_001DC93C;
extern s32 D_L01_001DC970;
extern s32 D_L01_001DC988;
extern f32 D_L01_001DC944;
extern s32 D_L01_001E17B0_00320088;
extern s32 D_L01_001E17A8_00320088;
extern f32 D_L01_001E17AC_00320088;
extern f32 D_L01_001E1820_00320088;
extern s32 D_L01_001E1824_00320088;
extern s32 D_L01_001DFB40_00320088;
extern u16 D_001A82EC[];
extern u8 D_001A30B0[];
extern vu0_v4 D_L01_001E29E0_00320088[];
extern Filter_00320088 D_L01_001DC990;
extern u8 D_L01_002AE910[];
extern vu0_v4 D_L01_00276AA0_00320088[];
extern vu0_v4 D_L01_00276D20_00320088[];
extern vu0_v4 D_L01_002769C0_00320088[];
extern vu0_v4 D_L01_00276A30_00320088[];
extern u8 *D_L01_001E17B8_00320088[];
extern s32 D_L01_001E17D8_00320088[];
extern s32 D_L01_001E17F8_00320088[];
extern vu0_v4 D_L01_001E1800_00320088[];
extern vu0_v4 D_L01_001EAA20_00320088;

void func_L01_00320088(Moby_00320088 *m) {
    extern void func_L01_003220D0();
    extern void func_L01_0041A5B0(s32, s32);
    extern void func_L01_005003D0(s32, s32);
    extern void func_L01_00444F38(void *, s32, s32, s32, s32);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_L01_00424D88(s32);
    extern s32 func_L01_00450BB0(void *, void *, s32, f32, f32, f32, f32, f32);
    extern void func_L01_003F2278(s32, s32);
    extern void func_003A4F28(s32);
    extern s32 func_L01_004BA800(void);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_00322F80(void *, void *, f32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern s32 func_L01_004AA710(void *, s32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_L01_00445208(f32 *, void *, void *, void *, void *, f32);
    extern void func_00382580(void *, f32, f32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_003221B8(u8 *);
    extern void func_L01_00322398(u8 *);
    extern void func_0038CBA0(void *, s32);
    extern void func_L01_004501E8(void *, void *, f32, f32, s32 *, void *, s32, s32, f32, f32, f32, s32, void *, s32,
                                  s32, s32);
    extern s32 func_L01_003220A0();
    extern s32 func_L01_00321F88(u8 *);
    extern s32 func_L01_00322180(void);
    extern void func_L01_003218A8();
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *, s32);
    extern void func_L01_005118D0(s32, s32);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_00321608(u8 *);
    extern void func_L01_00321A80(u8 *);
    extern void func_L01_00321710(u8 *);
    extern void func_L01_0034E558(s32, s32, void *, void *, s32);
    extern s32 func_003D4D00(void *, f32, s32, void *, s32);
    Vars_00320088 *vars = m->vars;
    vu0_v4 at;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    s32 count;
    s32 level;
    s32 beam;
    u8 *slot;
    f32 grow;
    s32 i;
    s32 j;

    level = ((Row_00320088 *)((s32)D_L01_002C5600 + D_001425C0[0x47] * 0xF0))->level;
    if (level == 0) {
        D_L01_001DC94C = 30;
        D_L01_001DC940 = 3;
    } else if (level == 1) {
        D_L01_001DC94C = 30;
        D_L01_001DC940 = 4;
    } else if (level == 2) {
        D_L01_001DC94C = 35;
        D_L01_001DC940 = 5;
    } else if (level == 3) {
        D_L01_001DC94C = 35;
        D_L01_001DC940 = 6;
    } else if (level >= 4) {
        D_L01_001DC94C = 40;
        D_L01_001DC940 = 7;
    }
    if (D_L01_001DC974 != 0) {
        D_L01_001DC940 = 1;
    }
    if (m->state == 0) {
        m->b30 = 0xFF;
        D_L01_001E17B0_00320088 = 0;
        m->state = 1;
        D_L01_001DC984 = 0x7F40FF40;
        func_L01_003220D0(m);
    }
    if (D_001A82EC[0] == 0 && ((Row_00320088 *)((s32)D_L01_002C5600 + D_001425C0[0x47] * 0xF0))->level == 0) {
        func_L01_0041A5B0(0xCA4, 0x67);
    }
    if (D_L01_001DC98C >= 8) {
        func_L01_0041A5B0(0x1519, 0x124);
        D_L01_001DC98C = 0;
    }
    if (D_001A4BE0.state == 1) {
        func_L01_005003D0(0x1D, 1);
    }
    if (m->b42 == m->b43 && (m->b60 & 2)) {
        func_L01_00444F38(m, 1, 0, 2, 0);
    }
    j = ((Row_00320088 *)((s32)D_L01_002C5600 + D_001425C0[0x47] * 0xF0))->level;
    if (j == 2) {
        m->h7C = 3;
    } else if (j == 1) {
        m->h7C = 1;
    } else if ((u32)j > 2) {
        m->h7C = 7;
    }
    func_003C2F58(m, 0, &at);
    *(vu0_q *)&vars->v10 = *(vu0_q *)&at;
    if (D_L01_001DC93C != -1) {
        func_L01_00424D88(D_L01_001DC93C);
        D_L01_001DC93C = -1;
    }
    if (D_001A4BE0.state == 0x1D || D_001A4BE0.f16B0 != 0) {
        *(vu0_q *)&vars->v30 = *(vu0_q *)D_L01_001E29E0_00320088;
    } else {
        *(vu0_q *)&vars->v30 = *(vu0_q *)(D_001A4BE0.moby + 0xC0);
    }
    beam = func_L01_00450BB0(&vars->v10, &vars->v30, 1, 0.34906584f, 0.95993108f, 10.0f, 0.78539819f, 0.61086524f);
    if (D_L01_001E17B0_00320088 == 0) {
        if (vars->w54 >= 0) {
            func_L01_003F2278(vars->w54, 0);
            vars->w54 = -1;
        }
        if (vars->w50 != -1) {
            slot = D_001A30B0 + vars->w50 * 0x80;
            if (*(Moby_00320088 **)(slot + 0xDC) == m && slot[0xD0] != 0) {
                func_003A4F28(vars->w50);
            }
        }
        vars->w50 = -1;
    }
    if (D_L01_001D6694 == 6 || func_L01_004BA800() || D_001A4BE0.state == 0x65 || D_001A4BE0.state == 0x74) {
        if (vars->w50 != -1) {
            slot = D_001A30B0 + vars->w50 * 0x80;
            if (*(Moby_00320088 **)(slot + 0xDC) == m && slot[0xD0] != 0) {
                func_003A4F28(vars->w50);
            }
        }
        vars->w50 = -1;
    }
    if (!func_L01_005119E0(-1) && D_L01_001DC970 == 0 && D_L01_001E17B0_00320088 == 0 &&
        (*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0.fireButton)) {
        func_003A52A0(3, 0, (u8 *)m);
        D_L01_001E1824_00320088 = 0;
    }
    if ((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0.fireButton) && func_L01_005119E0(-1) && D_L01_001DC970 == 0 &&
        D_001A4BE0.noFiring == 0 && D_L01_001D6694 == 0 && D_001A4BE0.state != 0x74) {
        s32 n;

        D_L01_001E17B0_00320088++;
        if (D_L01_001E17B0_00320088 > 150) {
            D_L01_001E17B0_00320088 = 150;
        }
        vars->w44 = D_L01_001DC94C;
        if (D_001A4BE0.noFiring == 0) {
            f32 *p;
            f32 k;

            grow = (f32)D_L01_001E17B0_00320088 * 0.007f;
            if (0.7f < grow) {
                grow = 0.7f;
            }
            func_L01_00322F80(m, &at, grow);
            if (m->b43 != 2) {
                func_003C3A10(m, 2, 0, 0);
            }
            if (!func_L01_004AA710(m, vars->w50)) {
                if (D_L01_001D6694 == 0 && D_001A4BE0.state != 0x74) {
                    vars->w50 = func_003A52A0(2, 4, (u8 *)m);
                }
            }
            if (D_L01_001E17B0_00320088 >= 5) {
                if (D_L01_001DFB40_00320088 & 1) {
                    for (i = 0; i < 2; i++) {
                        *(vu0_q *)&a = *(vu0_q *)(D_001A4BE0.moby + 0xE0);
                        func_0038D890(&a, &a, &vars->v30, func_003824E0(-180.0f, 180.0f) * 0.017453292f);
                        func_0038CF68((f32 *)&a, (s32)&a, func_003824E0(1.0f, 4.0f) + grow);
                        vec_add_ab(&a, &vars->v10, &a);
                        if (D_001A4BE0.state == 0x1D || D_001A4BE0.f16B0 != 0) {
                            *(vu0_q *)&b = *(vu0_q *)D_L01_001E29E0_00320088;
                        } else {
                            *(vu0_q *)&b = *(vu0_q *)(D_001A4BE0.moby + 0xC0);
                        }
                        func_0038CF68((f32 *)&b, (s32)&b, -func_003824E0(1.0f, 4.0f) + grow);
                        vec_add_ab(&b, &vars->v10, &b);
                        func_003C2F58(m, 1, &c);
                        p = (f32 *)&D_L01_00276AA0_00320088[i * 20];
                        for (j = 0; j < 20; j++) {
                            k = j * 0.05f;
                            if (j == 19) {
                                k = 1.0f;
                            }
                            func_L01_00445208(p, &vars->v10, &c, &a, &b, k);
                            p[0] += func_003824E0(-0.05f, 0.05f);
                            p[1] += func_003824E0(-0.05f, 0.05f);
                            p[2] += func_003824E0(-0.05f, 0.05f);
                            p += 4;
                        }
                    }
                }
                if (D_L01_001E17B0_00320088 >= 20 && level >= 2) {
                    for (i = 0; i < 2; i++) {
                        *(vu0_q *)&a = *(vu0_q *)(D_001A4BE0.moby + 0xE0);
                        func_0038D890(&a, &a, &vars->v30, func_003824E0(-180.0f, 180.0f) * 0.017453292f);
                        func_0038CF68((f32 *)&a, (s32)&a, func_003824E0(1.0f, 4.0f) + grow);
                        vec_add_ab(&a, &vars->v10, &a);
                        if (func_0038CAD0((s32)&D_L01_001E17F8_00320088[i]) && D_001A4BE0.state != 7 &&
                            D_001A4BE0.state != 0xB && D_001A4BE0.state != 0xE && D_001A4BE0.state != 0x14) {
                            func_00382580(&b, 3.0f, 3.0f);
                            vec_add_ab(&b, &b, &vars->v10);
                            if (func_003D3CB0(&vars->v10, &b, 0x10, D_001A4BE0.moby, 0)) {
                                *(vu0_q *)&D_L01_001E1800_00320088[i] = *(vu0_q *)&D_L01_001EAA20_00320088;
                            } else {
                                f32 r = func_003824E0(-70.0f, 70.0f);
                                if (D_001A4BE0.state == 0x1D || D_001A4BE0.f16B0 != 0) {
                                    func_0038D890(&c, D_L01_001E29E0_00320088, D_L01_001E29E0_00320088 + 2,
                                                  r * 0.017453292f);
                                } else {
                                    func_0038D890(&c, D_001A4BE0.moby + 0xC0, D_001A4BE0.moby + 0xE0, r * 0.017453292f);
                                }
                                func_0038CF68((f32 *)&c, (s32)&c, 3.0f);
                                vec_add_ba(&D_L01_001E1800_00320088[i], &D_001A4C60, &c);
                            }
                            D_L01_001E17F8_00320088[i] = (func_00382498(15, 25) * 5 + 2) / 6;
                        } else {
                            vec_sub_ba(&b, &D_L01_001E1800_00320088[i], &vars->v10);
                            func_0038CF68((f32 *)&b, (s32)&b, func_003824E0(1.0f, 4.0f) + grow);
                            vec_add_ab(&b, &vars->v10, &b);
                            p = (f32 *)&D_L01_00276D20_00320088[i * 10];
                            for (j = 0; j < 10; j++) {
                                k = j * 0.1f;
                                if (j == 9) {
                                    k = 1.0f;
                                }
                                func_L01_00445208(p, &vars->v10, &D_L01_001E1800_00320088[i], &a, &b, k);
                                p[0] += func_003824E0(-0.04f, 0.04f);
                                p[1] += func_003824E0(-0.04f, 0.04f);
                                p[2] += func_003824E0(-0.04f, 0.04f);
                                p += 4;
                            }
                        }
                    }
                }
                func_L01_00404A10(func_L01_003221B8, m);
            }
        }
        {
            func_0038CBA0(&a, 0x20);
            *(Filter_00320088 *)&c = D_L01_001DC990;
            if (D_001A4BE0.state == 0x1D || D_001A4BE0.f16B0 != 0) {
                func_0038CF68((f32 *)&vars->v30, (s32)D_L01_001E29E0_00320088, 32.0f);
            } else {
                func_0038CF68((f32 *)&vars->v30, (s32)(D_001A4BE0.moby + 0xC0), 32.0f);
            }
            func_0038CF68((f32 *)&vars->v30, (s32)&vars->v30, 1.0f);
            func_L01_004501E8(&vars->v10, &vars->v30, 0.34906584f, 0.34906584f, &count, &a, 8, 0, 32.0f,
                              0.34906584f, 0.34906584f, 0, &c, 1, -1, 0);
            if ((u32)(level - 2) < 2) {
                n = 12;
            } else {
                n = 15;
                if (level >= 4) {
                    n = 10;
                }
            }
            if (count > 0 && (D_L01_001E17B0_00320088 % n == 0 || D_L01_001E17B0_00320088 == 150)) {
                if (count > 8) {
                    count = 8;
                }
                for (i = 0; i < count; i++) {
                    s32 have = func_L01_003220A0(m);
                    if (level == 0 && have >= 3) {
                        break;
                    }
                    if (level == 1 && have >= 4) {
                        break;
                    }
                    if (level == 2 && have >= 5) {
                        break;
                    }
                    if (level == 3 && have >= 6) {
                        break;
                    }
                    if (level == 4 && have >= 7) {
                        break;
                    }
                    if (func_L01_00321F88(((u8 **)&a)[i])) {
                        func_003A52A0(0, 0, (u8 *)m);
                        break;
                    }
                }
            }
        }
        if (func_L01_00322180()) {
            func_L01_003218A8(m, 0x7F40FF40);
        }
        return;
    }
    if (D_L01_001E17B0_00320088 >= 20 && D_L01_001DC988 == 0) {
        if (vars->w44 == D_L01_001DC94C) {
            f32 ang;
            f32 len;
            s32 small;
            s32 mid;

            func_L01_004EA7D8(-1);
            vars->w54 = func_L01_003F2058(D_L01_002AE910, 0);
            func_L01_005118D0(-1, 1);
            D_L01_001DC98C = -1;
            D_L01_001E1824_00320088 = 1;
            func_003A52A0(1, 0, (u8 *)m);
            if (vars->w50 != -1) {
                slot = D_001A30B0 + vars->w50 * 0x80;
                if (*(Moby_00320088 **)(slot + 0xDC) == m && slot[0xD0] != 0) {
                    func_003A4F28(vars->w50);
                }
            }
            vars->w50 = -1;
            D_L01_001DC970 = 1;
            if (D_001A4BE0.state == 0x1D || D_001A4BE0.f16B0 != 0) {
                func_0038CF68((f32 *)&vars->v30, (s32)D_L01_001E29E0_00320088, 32.0f);
            } else {
                func_0038CF68((f32 *)&vars->v30, (s32)(D_001A4BE0.moby + 0xC0), 32.0f);
            }
            vec_add_ba(&vars->v0, &vars->v30, &at);
            small = (u32)level < 2;
            *(vu0_q *)&vars->v20 = *(vu0_q *)&vars->v10;
            vars->v20.z += D_L01_001DC944;
            vec_sub_ab(&vars->v20, &vars->v20, &vars->v10);
            if (small) {
                ang = -107.0f;
            } else {
                ang = -60.0f;
                if ((u32)(level - 2) < 2) {
                    ang = -80.0f;
                }
            }
            func_0038D890(&vars->v20, &vars->v20, &vars->v30, ang * 0.017453292f);
            len = func_0038CEA8(&vars->v20);
            D_L01_001E1820_00320088 = 0.2f;
            if (func_L01_00322180()) {
                D_L01_001E1820_00320088 = func_003824E0(0.05f, 0.1f);
            }
            mid = (u32)(level - 2) < 2;
            for (i = 0; i < D_L01_001DC940; i++) {
                if (small) {
                    ang += 107.0f;
                    func_0038CF68((f32 *)&vars->v20, (s32)&vars->v20, len * D_L01_001E1820_00320088);
                } else if (mid) {
                    ang += 52.5f;
                    func_0038CF68((f32 *)&vars->v20, (s32)&vars->v20, len * D_L01_001E1820_00320088);
                } else {
                    ang += 30.0f;
                    func_0038CF68((f32 *)&vars->v20, (s32)&vars->v20, len * 0.35f);
                }
                func_0038D890(&D_L01_002769C0_00320088[i], &vars->v20, &vars->v30, ang * 0.017453292f);
                vec_add_ba(&D_L01_002769C0_00320088[i], &vars->v10, &D_L01_002769C0_00320088[i]);
            }
            for (i = 0; i < D_L01_001DC940; i++) {
                D_L01_001E17D8_00320088[i] = i * 2 + func_00382468(8);
            }
            for (i = 1; i >= 0; i--) {
                D_L01_001E17F8_00320088[i] = 0;
            }
            func_L01_00321608((u8 *)m);
            D_L01_001E17A8_00320088 = 90;
            D_L01_001E17AC_00320088 = 0.01f;
            if (D_001A4BE0.state == 0x1D || D_001A4BE0.f16B0 != 0) {
                func_0038CE20(&a, D_L01_001E29E0_00320088, 10.0f);
            } else {
                func_0038CE20(&a, D_001A4BE0.moby + 0xC0, 10.0f);
            }
            func_0038CE20(&b, D_001A4BE0.moby + 0xE0, 1.5f);
            vec_add_ba(&a, (u8 *)&D_001A4BE0 + 0x80, &a);
            vec_add_ab(&a, &b, &a);
            func_L01_0034E558(beam, 0x804020, &a, m, 0);
        }
        if (vars->w44 >= 5 && D_L01_001DC974 == 0) {
            func_L01_00322F80(m, &at, 0.7f);
        }
        if (D_L01_001DC974 == 0) {
            if (vars->w44 == 0x1B) {
                func_L01_00321A80((u8 *)m);
            }
            if (D_L01_001DFB40_00320088 % 3 != 0) {
                func_L01_00321710((u8 *)m);
            }
            func_L01_00404A10(func_L01_00322398, m);
        }
        func_0038CAD0((s32)&vars->w44);
    } else if ((u32)(D_L01_001E17B0_00320088 - 1) < 19) {
        if (D_L01_001DC98C != -1) {
            D_L01_001DC98C++;
        }
        func_003A52A0(5, 0, (u8 *)m);
    } else if (D_L01_001E17B0_00320088 >= 20 && D_L01_001DC988 != 0) {
        if (func_L01_00322180()) {
            func_L01_004EA7D8(-1);
            vars->w54 = func_L01_003F2058(D_L01_002AE910, 0);
            func_003A52A0(1, 0, (u8 *)m);
            if (vars->w50 != -1) {
                slot = D_001A30B0 + vars->w50 * 0x80;
                if (*(Moby_00320088 **)(slot + 0xDC) == m && slot[0xD0] != 0) {
                    func_003A4F28(vars->w50);
                }
            }
            vars->w50 = -1;
            D_L01_001DC970 = 1;
            func_L01_00321608((u8 *)m);
            for (i = 0; i < D_L01_001DC940; i++) {
                ((Query_00320088 *)&a)->dir = *(vu0_q *)&D_L01_00276A30_00320088[i];
                func_L01_0034E558((s32)D_L01_001E17B8_00320088[i], 0x804020, &a, m, 0);
                vec_sub_ba(&a, &D_L01_00276A30_00320088[i], &m->pos);
                ((Query_00320088 *)&a)->w20 = 1;
                ((Query_00320088 *)&a)->owner = m;
                func_0038CF68((f32 *)&a, (s32)&a, 1.0f);
                a.w = 5627.9248046875f;
                ((Query_00320088 *)&a)->oclass = m->oclass;
                ((Query_00320088 *)&a)->flags = 0x410000;
                ((Query_00320088 *)&a)->b18 = 3;
                ((Query_00320088 *)&a)->b19 = 2;
                ((Query_00320088 *)&a)->damage = D_L01_002C5600[D_001425C0[0x47]].f6C;
                func_0038CF68((f32 *)&a, (s32)&a, 0.5f);
                func_003D4D00(&D_L01_00276A30_00320088[i], 1.0f, 1, D_001A4BE0.moby, (s32)&a);
            }
        }
        if (vars->w44 >= 5 && D_L01_001DC974 == 0) {
            func_L01_00322F80(m, &at, 0.7f);
        }
        func_0038CAD0((s32)&vars->w44);
    }
    if (vars->w44 <= 0) {
        D_L01_001DC974 = 0;
        D_L01_001E17B0_00320088 = 0;
        D_L01_001DC970 = 0;
        func_L01_003220D0(m);
        D_L01_001DC988 = 0;
        D_L01_001DC984 = 0x7F40FF40;
    }
    if (D_L01_001E17B0_00320088 < 20 && D_L01_001DC974 == 0) {
        D_L01_001DC970 = 0;
        func_L01_003220D0(m);
        D_L01_001E17B0_00320088 = 0;
        D_L01_001DC988 = 0;
        D_L01_001DC984 = 0x7F40FF40;
    }
}
/* localdecomp:end func_L01_00320088 */

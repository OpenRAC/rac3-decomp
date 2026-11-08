/* func_L01_00350750: a Veldin enemy's update (9 levels: 01 04 09 12 13 16 18 22 29), the other
   member of the 0x95/0x20 two-switch scaffold. Near miss, not linked. Written from the retail
   assembly (Opus singletons, 2026-11-08); case 11 falls through into case 14 in retail (no break).
   State: 2176 of 2176 instructions, the same opcode at every row; 2167 rows equal with registers
   (check.py at level 01; 4 of the 9 rows are the snippet's own jump-table %hi/%lo).
   Left: (1) the D_L01_001D66B0 call in the dying branch: retail schedules the quadword copy into
   s10 before the a0..a2 moves and leaves `addiu $a3` in the jal delay slot, this C the other way
   (prototype orders, comma forms and temporaries do not move it); (2) state 25's
   func_L01_0045AA30(m, &s20): `move $a0` before the two copies of &s20 in retail.
   Needs, when it lands: "-mvu0-use-vf0-vf2" added to src/levels/shared/L01_003500B8.c's flag line
   (all its C functions still match with it) and the div.s row `func_L01_00350750 2` in
   config/levels/divs_nops.txt. Check it with
     tools/check.py THIS.c func_L01_00350750 --as ps2as --flags=-mvu0-use-vf0-vf2
   (with the divs_nops row in place). */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef union { u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0]; } Hero;
typedef union { u8 b[0x600]; s8 c[0x600]; s16 h[0x300]; u16 uh[0x300]; s32 i[0x180]; u32 u[0x180]; f32 f[0x180]; u8 *ptr[0x180]; u128_t q[0x60]; } Obj;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

extern Hero D_001A4BE0;
extern u8 D_001BBC40[];
extern u8 D_0014275B[];
extern u8 D_0014275C[];
extern s32 D_001D545C;
extern s32 D_L01_001D6694;
extern u8 D_L01_001D66B0[];
extern u8 D_L01_001E29C0[];
extern u8 *D_L01_001E001C;
extern Obj *D_L01_001EAA18[];
extern f32 D_L01_002F1510[];
extern f32 D_L01_002F16F0[];
extern f32 D_L01_001DAA30;
extern f32 D_L01_001DAA38;
extern s32 D_L01_001DD5A4;
__asm__(".extern D_L01_001DD5A4, 4");
extern f32 D_L01_001DD4C4;
__asm__(".extern D_L01_001DD4C4, 4");
extern f32 D_L01_001DD4CC;
__asm__(".extern D_L01_001DD4CC, 4");
extern f32 D_L01_001DD4D0;
__asm__(".extern D_L01_001DD4D0, 4");
extern f32 D_L01_001DD4D4;
__asm__(".extern D_L01_001DD4D4, 4");
extern s32 D_L01_001DD4D8;
__asm__(".extern D_L01_001DD4D8, 4");
extern void func_L01_00353880(void);

extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern f32 *func_00382348(void *);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C2880(Obj *);
extern void func_003C2EC0(Obj *, s32, void *);
extern void func_003C3A10(Obj *, s32, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_003C41A0(void *, f32, f32, f32, f32, void *);
extern void func_003C7C38(Obj *);
extern void func_L01_00315900(Obj *, s32, void *);
extern s32 func_L01_00352950(Obj *);
extern void func_L01_003534C0(Obj *);
extern void func_L01_003535F0(Obj *);
extern void func_L01_003537A0(Obj *, s32);
extern void func_L01_00353A88(Obj *, void *, f32);
extern s32 func_L01_00353DC8(Obj *, void *);
extern s32 func_L01_003FB640(void *, s32, Obj *, f32);
extern void func_L01_00409598(Obj *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_0041A4F0(void);
extern f32 func_L01_004395E0(Obj *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_004450F0(Obj *, s32, s32);
extern s32 func_L01_00446058(Obj *, s32, s32);
extern s32 func_L01_00446780(Obj *, f32, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_004468C8(Obj *, f32, f32, f32, s32, s32, s32, s32, s32);
extern void func_L01_00446A70(Obj *, Obj *, s32, void *, void *, f32);
extern void func_L01_00448890(void *, f32, f32, f32, f32, void *, s32);
extern void func_L01_0044E318(Obj *, void *);
extern void func_L01_0044E340(void *, s32, s32, f32);
extern void func_L01_0044E468(void *, s32);
extern void func_L01_0044E740(void *);
extern s32 func_L01_00454370(Obj *, void *);
extern s32 func_L01_004561B8(Obj *);
extern s32 func_L01_004561E0(Obj *);
extern void func_L01_00456230(Obj *, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_00458F78(Obj *, void *, s32, s32);
extern void func_L01_00459188(Obj *, void *, void *);
extern void func_L01_004591B8(Obj *, void *, void *);
extern u8 *func_L01_004592A8(Obj *, void *, s32, void *);
extern u8 *func_L01_004593B8(Obj *, void *, void *, void *, void *);
extern void func_L01_0045A748(Obj *, void *);
extern void func_L01_0045A898(void *, void *, f32);
extern s32 func_L01_0045A9F0(Obj *);
extern s32 func_L01_0045AA10(Obj *, f32);
extern void func_L01_0045AA30(Obj *, void *);
extern void func_L01_0045BD78(Obj *, f32, f32, f32, f32);
extern s32 func_L01_0045BDE8(Obj *, s32);
extern void func_L01_004AA7E8(Obj *, s32);
extern void func_L01_004AADE8(s32, s32, Obj *, s32);

void func_L01_00350750(Obj *m) {
    V4 s10, s20, s30, s40, s50, s60, s70, s80;
    Obj *pv;

    pv = (Obj *)m->ptr[0x68 / 4];
    if (pv->i[0x5D8 / 4] != 0 && (D_001BBC40[m->b[0xB0] + D_001D545C * 0x10] & 0x80) && m->b[0x31] == 0) {
        func_003C2880(m);
        return;
    }
    if (pv->i[0x5D0 / 4] != -1 && m->b[0x95] != 7 && m->b[0x20] != 0) {
        if (func_L01_00456500(D_L01_001E29C0, pv->i[0x5D0 / 4]) == 0) {
            m->i[0x98 / 4] = 0;
            m->uh[0x34 / 2] = (m->uh[0x34 / 2] | 0x41) & ~0x1000;
            func_L01_004AA7E8(m, 1);
            return;
        } else {
            Obj *c = (Obj *)m->ptr[0x24 / 4];
            m->uh[0x34 / 2] &= 0xFFBE;
            m->uh[0x34 / 2] |= c->uh[0x44 / 2] & 0x1000;
            m->i[0x98 / 4] = c->i[0x10 / 4];
        }
    }
    if ((D_L01_001DD5A4 != 0 || D_0014275C[0] != 0) && pv->i[0x5E0 / 4] == 0) {
        if (func_L01_00446058(m, 0x1BA0, 0x16BD) != 0) {
            if (D_001D545C == 0x10 || D_001D545C == 4 || D_001D545C == 9) {
                pv->h[0x34 / 2] = 6;
                pv->b[0x44] = 0x19;
                if (func_L01_0041A4F0() != 0) {
                    pv->h[0x34 / 2] = (f32)pv->h[0x34 / 2] * (D_001D545C == 7 && D_0014275B[0] != 0 ? D_L01_001DAA30 : D_L01_002F1510[D_001D545C]);
                    pv->b[0x44] = (f32)pv->b[0x44] * (D_001D545C == 7 && D_0014275B[0] != 0 ? D_L01_001DAA38 : D_L01_002F16F0[D_001D545C]);
                }
                pv->b[0x45] = pv->b[0x44];
                pv->b[0x46] = pv->b[0x44];
                pv->f[0x30 / 4] = pv->h[0x34 / 2];
            }
            m->h[0xAA / 2] = 0x16BD;
            pv->i[0x5E0 / 4] = 1;
            m->uh[0x34 / 2] |= 0x1000;
            ((Obj *)m->ptr[0x24 / 4])->b[0x46] = 5;
        }
    } else if ((D_001D545C == 0xD || D_001D545C == 0x10 || D_001D545C == 0x1D || D_001D545C == 0xC)
               && pv->i[0x5EC / 4] == 0 && D_0014275C[0] == 0) {
        pv->i[0x5EC / 4] = 1;
        func_L01_00446058(m, 0x1ED8, 0x16BD);
        m->h[0xAA / 2] = 0x16BD;
        m->uh[0x34 / 2] |= 0x1000;
        ((Obj *)m->ptr[0x24 / 4])->b[0x46] = 5;
    }
    if (m->b[0x95] != 4 && pv->f[0x30 / 4] <= 0.0f) {
        m->i[0x98 / 4] = ((Obj *)m->ptr[0x24 / 4])->i[0x10 / 4];
        func_003C7C38(m);
        *(u128_t *)&s10 = *(u128_t *)D_L01_001D66B0;
        func_L01_00446A70(m, m, 0x10000, &m->q[1], D_L01_001D66B0, 100.0f);
    }
    if (m->b[0x20] != 0x13) {
        m->f[0x2C / 4] = ((Obj *)m->ptr[0x24 / 4])->f[0x24 / 4] * pv->f[0x5D4 / 4];
    }
    if (func_L01_00352950(m) != 0) {
        func_L01_003537A0(m, 1);
        return;
    }
    *(u128_t *)&s10 = m->q[1];
    if (pv->h[0x234 / 2] == 1 && ((Obj *)pv->ptr[0x230 / 4])->h[0xAA / 2] == 0x173B) {
        pv->h[0x234 / 2] = 0;
    }
    if (D_L01_001D6694 == 2) {
        if ((m->b[0x34] ^ 1) & 1) {
            m->i[0x98 / 4] = 0;
            m->uh[0x34 / 2] = (m->uh[0x34 / 2] | 0x41) & ~0x1000;
            func_L01_004AA7E8(m, 1);
            pv->i[0x5E8 / 4] = 1;
        }
        return;
    }
    if (pv->i[0x5E8 / 4] != 0) {
        Obj *c = (Obj *)m->ptr[0x24 / 4];
        m->uh[0x34 / 2] &= 0xFFBE;
        m->uh[0x34 / 2] |= c->uh[0x44 / 2] & 0x1000;
        m->i[0x98 / 4] = c->i[0x10 / 4];
        pv->i[0x5E8 / 4] = 0;
    }

    switch (m->b[0x95]) {
    case 0: {
        u8 *e = D_L01_001E001C + (pv->i[0x334 / 4] << 8);
        if (pv->h[0x346 / 2] == 0 && pv->i[0x2E8 / 4] != 0) {
            m->i[0x98 / 4] = ((Obj *)m->ptr[0x24 / 4])->i[0x10 / 4];
            func_L01_00353A88(m, &m->q[1], pv->f[0x350 / 4]);
        } else if (func_L01_00456250(e) != 0) {
            func_L01_004450F0(m, 4, 1);
            if (m->b[0x43] != 3) {
                func_003C3A10(m, 3, func_00382498(0, 0xA), 0);
            }
        }
        break;
    }
    case 1: {
        s32 found;

        if (func_L01_004561E0(m) != 0 && pv->h[0x2E6 / 2] == 0) {
            pv->h[0x2E6 / 2] = (func_00382498(0, 0x28) * 5 + 2) / 6;
        }
        found = 0;
        if (pv->i[0x3E0 / 4] == -1) {
            found = 1;
        } else {
            u8 *e = D_L01_001E001C + (pv->i[0x3E0 / 4] << 8);
            f32 *q = func_00382348(e);
            if (e == 0 || e[0x20] == 0xFE) {
                found = 1;
            } else if (e[0x20] == 0xFD) {
                found = 1;
            } else if (q != 0 && *q <= 0.0f) {
                found = 1;
            }
        }
        if (pv->h[0x234 / 2] == 1 && func_0038CB00(&pv->h[0x2E6 / 2]) != 0 && found) {
            if (m->b[0x43] != 4) {
                func_003C3A10(m, 4, 0, 8);
            }
            func_L01_004450F0(m, 8, 3);
            if (pv->i[0x338 / 4] != -1) {
                func_L01_004450F0(m, 6, -1);
            }
        } else if (pv->i[0x2E8 / 4] != 0 && func_0038CB00(&pv->h[0x2E6 / 2]) != 0) {
            func_L01_004450F0(m, m->b[0x20], 2);
            pv->i[0x2E8 / 4] = 0;
            if (pv->i[0x2E0 / 4] < 0xFA) {
                pv->i[0x2E0 / 4] = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        if (func_L01_00353DC8(m, pv->ptr[0x230 / 4]) != 0) {
            func_L01_004450F0(m, 0x15, 8);
        }
        break;
    }
    case 2:
        if (pv->h[0x234 / 2] == 1) {
            if (m->b[0x43] != 4) {
                func_003C3A10(m, 4, 0, 8);
            }
            func_L01_004450F0(m, 8, 3);
        } else if (pv->i[0x2E0 / 4] == 0) {
            func_L01_004450F0(m, m->b[0x20], 1);
        }
        if (func_L01_00353DC8(m, pv->ptr[0x230 / 4]) != 0) {
            func_L01_004450F0(m, 0x15, 8);
        }
        break;
    case 3:
        if (pv->h[0x234 / 2] != 1 && func_L01_004561E0(m) == 0 && func_00382468(0x1E) == 0) {
            func_L01_004450F0(m, 4, 2);
            if (m->b[0x43] != 3) {
                func_003C3A10(m, 3, func_00382468(3), (func_00382498(8, 0xC) * 5 + 2) / 6);
            }
            pv->i[0x2E0 / 4] = (func_00382498(0x30C, 0x384) * 5 + 2) / 6;
        }
        break;
    case 4: {
        s32 r = func_L01_00454370(m, &pv->b[0x160]);
        if (r & 1) {
            func_L01_003534C0(m);
            func_L01_00315900(m, 0, func_L01_00353880);
            return;
        }
        if (r & 2) {
            if (pv->h[0x234 / 2] == 1) {
                if (m->b[0x43] != 4) {
                    func_003C3A10(m, 4, 0, 8);
                }
                func_L01_004450F0(m, 8, 3);
            } else {
                if (m->b[0x43] != 0) {
                    func_003C3A10(m, 0, 0, 8);
                }
                func_L01_004450F0(m, 7, 2);
                pv->i[0x2E0 / 4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    }
    case 7:
        if (pv->h[0x346 / 2] != 0
            && ((pv->i[0x334 / 4] != -1 && func_L01_00456250(D_L01_001E001C + (pv->i[0x334 / 4] << 8)) != 0 && func_0038CB00(&pv->h[0x2E6 / 2]) != 0)
                || (pv->h[0x234 / 2] == 1 && func_0038CB00(&pv->h[0x2E6 / 2]) != 0))) {
            Obj *c;
            if (m->b[0x43] != 0) {
                func_003C3A10(m, 0, func_00382498(0, 0xA), 0);
            }
            func_L01_00456230(m, 1);
            m->f[0x18 / 4] = func_003C3D30(&m->q[1], 0, 0, 0.5f);
            if (m->b[0x95] == 9) {
                func_L01_004450F0(m, 0x18, -1);
            } else {
                func_L01_004450F0(m, 2, 1);
            }
            c = (Obj *)m->ptr[0x24 / 4];
            m->uh[0x34 / 2] &= 0xFFBE;
            m->uh[0x34 / 2] |= c->uh[0x44 / 2] & 0x1000;
            m->i[0x98 / 4] = c->i[0x10 / 4];
            m->b[0x31] = 0;
            m->uh[0x34 / 2] |= 1;
            func_L01_00409598(m, &m->q[1], &m->b[0xF0], 0, 2, 3, 0x25, 0x25, 0x80FF40, 0x108F10);
        }
        break;
    case 8:
        if (pv->h[0x234 / 2] == 1) {
            func_L01_004450F0(m, 2, 1);
        }
        break;
    }

    switch (m->b[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_0045AA10(m, m->f[0xF8 / 4]);
        if ((m->b[0x60] & 2) && pv->i[0x340 / 4] == 0) {
            func_L01_004450F0(m, 4, -1);
            if (m->b[0x43] != 3) {
                func_003C3A10(m, 3, 0, 8);
            }
        }
        break;
    case 3:
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 4) {
                func_003C3A10(m, 4, 0, 8);
            }
            func_L01_004450F0(m, 8, 3);
        }
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            f32 a = func_00382538();
            f32 r = func_003824E0(2.0f, 6.0f);
            qzero(&pv->b[0x320]);
            pv->f[0x320 / 4] = func_0038D098(a) * r;
            pv->f[0x324 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x320], &pv->b[0x320], &pv->b[0x310]);
            if (pv->i[0x33C / 4] != -1 && func_L01_00456500(&pv->b[0x320], pv->i[0x33C / 4]) == 0) {
                pv->q[0x320 / 16] = pv->q[0x310 / 16];
            }
            pv->i[0x330 / 4] = func_00382498(0x12C, 0x212);
            func_L01_0045BD78(m, 0.00219999999f, 0.0300000012f, 0.00181514258f, 0.125663713f);
        }
        func_L01_0045A898(m, &pv->b[0x320], m->f[0xF8 / 4]);
        func_L01_00448890(&m->f[0xF8 / 4], func_0038D160(pv->f[0x320 / 4] - m->f[0x10 / 4], pv->f[0x324 / 4] - m->f[0x14 / 4]),
                          0.00181514258f, 0.00181514258f, 0.0349065885f, &pv->b[0x30C], 0);
        if (func_0038CF38(&m->q[1], &pv->b[0x320]) < 0.75f) {
            f32 a = func_00382538();
            f32 r = func_003824E0(2.0f, 6.0f);
            qzero(&pv->b[0x320]);
            pv->f[0x320 / 4] = func_0038D098(a) * r;
            pv->f[0x324 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x320], &pv->b[0x320], &pv->b[0x310]);
            if (pv->i[0x33C / 4] != -1 && func_L01_00456500(&pv->b[0x320], pv->i[0x33C / 4]) == 0) {
                pv->q[0x320 / 16] = pv->q[0x310 / 16];
            }
        }
        if (func_0038CAD0(&pv->b[0x330]) != 0) {
            if (m->b[0x43] != func_00382468(2) + 1) {
                func_003C3A10(m, func_00382468(2) + 1, 0, 8);
            }
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            f32 a = func_0038DAB8(m->f[0xF8 / 4], func_L01_00443A18(60.0f, 80.0f) * 0.0174532924f);
            f32 r = func_003824E0(3.0f, 4.0f);
            qzero(&pv->b[0x2F0]);
            pv->f[0x2F0 / 4] = func_0038D098(a) * r;
            pv->f[0x2F4 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x2F0], &m->q[1], &pv->b[0x2F0]);
            func_L01_0045BD78(m, 0.00219999999f, 0.0300000012f, 0.00181514258f, 0.125663713f);
        }
        func_L01_0045A898(m, &pv->b[0x2F0], m->f[0xF8 / 4]);
        func_L01_00448890(&m->f[0xF8 / 4], func_0038D160(pv->f[0x2F0 / 4] - m->f[0x10 / 4], pv->f[0x2F4 / 4] - m->f[0x14 / 4]),
                          0.00181514258f, 0.00181514258f, 0.0349065885f, &pv->b[0x30C], 0);
        if (func_0038CF38(&m->q[1], &pv->b[0x2F0]) < 0.75f) {
            f32 a = func_0038DAB8(m->f[0xF8 / 4], func_L01_00443A18(60.0f, 80.0f) * 0.0174532924f);
            f32 r = func_003824E0(3.0f, 4.0f);
            qzero(&pv->b[0x2F0]);
            pv->f[0x2F0 / 4] = func_0038D098(a) * r;
            pv->f[0x2F4 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x2F0], &m->q[1], &pv->b[0x2F0]);
        }
        if (pv->h[0x234 / 2] == 1
            && (func_0038DBA0(m->f[0xF8 / 4], func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 1.91986215f
                || D_001A4BE0.f[0x174 / 4] > 0.0300000012f)) {
            if (m->b[0x43] != 4) {
                func_003C3A10(m, 4, 0, 5);
            }
            func_L01_004450F0(m, 8, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.00480000023f, 0.0800000057f, 0.0100530973f, 0.251327425f);
        }
        func_L01_0045BD78(m, 0.00480000023f, 0.0800000057f, 0.0100530973f, 0.251327425f);
        if (func_L01_0045BDE8(m, pv->i[0x338 / 4]) != 0 || func_0038CF38(&m->q[1], &pv->b[0x220]) < 6.0f) {
            func_L01_004450F0(m, 8, -1);
        }
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x308 / 4] = func_L01_00443A18(0.0f, 15.0f) * 0.0174532924f;
            func_L01_00459188(m, pv->ptr[0x230 / 4], &pv->b[0x360]);
            func_L01_0045BD78(m, 0.00480000023f, 0.0800000057f, 0.0100530973f, 0.251327425f);
        }
        if (pv->ptr[0x230 / 4] != pv->ptr[0x3B0 / 4]) {
            func_L01_00459188(m, pv->ptr[0x230 / 4], &pv->b[0x360]);
        }
        func_L01_00458F78(m, &pv->b[0x360], 0, 0);
        func_L01_0045A748(m, &pv->b[0x360]);
        if (pv->f[0x120 / 4] < pv->f[0x98 / 4] * 0.8f) {
            pv->i[0x3A0 / 4]++;
        }
        *(u128_t *)&s20 = m->q[1];
        s20.z += 0.600000024f;
        if (D_001A4BE0.i[0x25CC / 4] != 0x12 && func_0038CF38(&m->q[1], &pv->b[0x220]) < 1.0f
            && func_0038DBA0(m->f[0xF8 / 4], func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.436332315f) {
            func_L01_004450F0(m, 0xA, -1);
            if (m->b[0x43] != 0xC) {
                func_003C3A10(m, 0xC, 0, 8);
            }
        }
        if (func_L01_003FB640(&s20, 1, m, 0.600000024f) != 0 && D_L01_001EAA18[0] != 0
            && D_L01_001EAA18[0] == (Obj *)pv->ptr[0x230 / 4] && (u8 *)D_L01_001EAA18[0] != D_001A4BE0.ptr[0x25C0 / 4]) {
            func_L01_004450F0(m, 0xA, -1);
            if (m->b[0x43] != 0xC) {
                func_003C3A10(m, 0xC, 0, 8);
            }
        }
        if (func_0038CF38(&m->q[1], &pv->b[0x220]) < 2.5f) {
            pv->f[0x308 / 4] = 0.0f;
        }
        if (fabs_asm(m->f[0x18 / 4] - pv->f[0x228 / 4]) > 4.0f && D_001A4BE0.i[0x360 / 4] != 0 && pv->i[0x478 / 4] != 0) {
            if (m->b[0x43] != 4) {
                func_003C3A10(m, 4, 0, 8);
            }
            func_L01_004450F0(m, 0xF, -1);
        }
        break;
    case 15:
        if (func_L01_004561B8(m) != 0) {
            u8 *n;
            pv->i[0x474 / 4] = 0;
            pv->i[0x470 / 4] = 0;
            n = func_L01_004592A8(m, &pv->b[0x410], pv->i[0x3E8 / 4], &pv->b[0x440]);
            pv->ptr[0x3EC / 4] = n;
            *(u128_t *)&s20 = *(u128_t *)(n + 0x10);
            func_L01_004591B8(m, &s20, &pv->b[0x360]);
            func_L01_0045BD78(m, 0.00480000023f, 0.0800000057f, 0.0100530973f, 0.251327425f);
        }
        if (pv->i[0x474 / 4] == 0) {
            func_L01_00458F78(m, &pv->b[0x360], 0, 0);
            func_L01_0045A748(m, &pv->b[0x360]);
        } else {
            if (pv->i[0x3A0 / 4] >= 9) {
                func_L01_004450F0(m, 8, -1);
                if (m->b[0x43] != 4) {
                    func_003C3A10(m, 4, 0, 8);
                }
            }
            func_L01_0045A748(m, pv->ptr[0x3EC / 4] + 0x10);
        }
        if (func_0038CF38(&m->q[1], pv->ptr[0x3EC / 4] + 0x10) <= 1.5f) {
            pv->i[0x474 / 4] = 1;
            *(u128_t *)&s20 = pv->q[0x220 / 16];
            pv->ptr[0x3EC / 4] = func_L01_004593B8(m, pv->ptr[0x3EC / 4], &pv->b[0x440], &pv->b[0x470], &s20);
            if (pv->ptr[0x3EC / 4] == 0) {
                func_L01_004450F0(m, 8, -1);
                if (m->b[0x43] != 4) {
                    func_003C3A10(m, 4, 0, 8);
                }
            }
        }
        break;
    case 10: {
        f32 t = func_L01_004395E0(m);
        if (t > 6.0f && t < 10.0f && m->b[0x42] == 0xC) {
            *(u128_t *)&s20 = m->q[1];
            if (pv->b[0x5F] != 0) {
                func_L01_004468C8(m, 0.5f, (f32)pv->b[0x44], 0.75f, 1, 0x10000, 0, 1, 0);
            } else {
                func_L01_004468C8(m, 0.5f, (f32)pv->b[0x44], 0.75f, 1, 1, 0, 1, 0);
            }
        }
        if (m->b[0x60] & 2) {
            func_L01_004450F0(m, 0xC, -1);
            if (m->b[0x43] != 6) {
                func_003C3A10(m, 6, 1, 3);
            }
        }
        break;
    }
    case 12:
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x2F8 / 4] = m->f[0x18 / 4];
        }
        if (m->b[0x42] == 6) {
            f32 t = func_L01_004395E0(m);
            if (t > 2.0f && t < 18.0f) {
                func_0038CF68(&s40, &m->b[0xC0], -0.0843750015f);
                vec_add_ba(&s20, &m->q[1], &s40);
            }
            if (t > 2.0f && t < 12.0f) {
                func_003C41A0(&s20.z, pv->f[0x2F8 / 4] + 1.0f, 0.1f, 0.2f, 0.1f, &pv->b[0x300]);
            }
            if (t == 12.0f) {
                pv->f[0x300 / 4] = 0.0f;
            }
            if (t > 12.0f && t < 18.0f) {
                func_003C41A0(&s20.z, func_003C3D30(&m->q[1], 0, 0, 0.5f), 0.027777778f, 0.333333343f, 0.25f, &pv->b[0x300]);
            }
            if (t > 2.0f && t < 18.0f) {
                vec_sub_ab(&s30, &s20, &m->q[1]);
                func_L01_0045AA30(m, &s30);
            } else {
                func_L01_0045AA10(m, m->f[0xF8 / 4]);
            }
            if (m->b[0x60] & 2) {
                if (func_00382468(0xA) == 0) {
                    if (m->b[0x43] != 9) {
                        func_003C3A10(m, 9, 0, 7);
                    }
                    func_L01_004450F0(m, 0xD, -1);
                } else {
                    func_L01_004450F0(m, 8, -1);
                    if (m->b[0x43] != 4) {
                        func_003C3A10(m, 4, 0, 5);
                    }
                }
            }
        }
        break;
    case 13:
        func_L01_0045AA10(m, m->f[0xF8 / 4]);
        if (m->b[0x60] & 2) {
            func_L01_004450F0(m, 8, -1);
            if (m->b[0x43] != 4) {
                func_003C3A10(m, 4, 0, 5);
            }
        }
        break;
    case 11:
        if (func_L01_004561B8(m) != 0) {
            pv->h[0x2E6 / 2] = 0;
        }
        func_L01_0045AA10(m, m->f[0xF8 / 4]);
        if (m->b[0x42] == 1) {
            f32 a;
            func_003C2EC0(m, 0, &s50);
            a = func_0038D160(s70.x, s70.y);
            if (func_0038DBA0(a, func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.436332315f) {
                pv->h[0x2E6 / 2] = m->uh[0x96 / 2] + 5;
            }
            if ((pv->h[0x2E6 / 2] != 0 && m->uh[0x96 / 2] == pv->h[0x2E6 / 2]) || D_001A4BE0.f[0x174 / 4] > 0.040000003f) {
                if (m->b[0x43] != 4) {
                    func_003C3A10(m, 4, 0, 5);
                }
                func_L01_004450F0(m, 8, -1);
            }
        }
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 2) {
                func_003C3A10(m, 2, 0, 5);
            }
            func_L01_004450F0(m, 0xE, -1);
        }
        /* falls through: no break in the original */
    case 14:
        if (func_L01_004561B8(m) != 0) {
            pv->h[0x2E6 / 2] = 0;
        }
        func_L01_0045AA10(m, m->f[0xF8 / 4]);
        if (m->b[0x42] == 2) {
            f32 a;
            func_003C2EC0(m, 0, &s20);
            a = func_0038D160(s40.x, s40.y);
            if (func_0038DBA0(a, func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.436332315f) {
                pv->h[0x2E6 / 2] = m->uh[0x96 / 2] + 5;
            }
            if (pv->h[0x234 / 2] == 1
                && ((pv->h[0x2E6 / 2] != 0 && m->uh[0x96 / 2] == pv->h[0x2E6 / 2]) || D_001A4BE0.f[0x174 / 4] > 0.040000003f)) {
                if (m->b[0x43] != 4) {
                    func_003C3A10(m, 4, 0, 5);
                }
                func_L01_004450F0(m, 8, -1);
            }
        }
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 3) {
                func_003C3A10(m, 3, 0, 3);
            }
            func_L01_004450F0(m, 5, -1);
        }
        break;
    case 21:
        if (func_L01_004561B8(m) != 0 && m->b[0x43] != 0) {
            func_003C3A10(m, 0, 0, 8);
        }
        func_L01_0045AA10(m, func_0038D160(((Obj *)pv->ptr[0x230 / 4])->f[0x10 / 4] - m->f[0x10 / 4], ((Obj *)pv->ptr[0x230 / 4])->f[0x14 / 4] - m->f[0x14 / 4]));
        if (func_L01_00353DC8(m, pv->ptr[0x230 / 4]) == 0) {
            func_L01_004450F0(m, 0x16, -1);
        }
        break;
    case 22: {
        Obj *t;
        if (m->b[0x43] != 9) {
            func_003C3A10(m, 9, 0, 8);
        }
        t = (Obj *)pv->ptr[0x230 / 4];
        func_L01_0045AA10(m, func_0038D160(t->f[0x10 / 4] - m->f[0x10 / 4], t->f[0x14 / 4] - m->f[0x14 / 4]));
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0) {
                func_003C3A10(m, 0, 0, 5);
            }
            func_L01_004450F0(m, 0x17, -1);
        }
        break;
    }
    case 23:
        func_L01_004450F0(m, 2, 1);
        break;
    case 19: {
        Obj *o;
        if (func_L01_004561B8(m) != 0) {
            pv->i[0xA8 / 4] |= 0x400;
        }
        if (pv->f[0x34C / 4] < 1.0f) {
            pv->f[0x34C / 4] += D_L01_001DD4C4;
            if (pv->f[0x34C / 4] > 1.0f) {
                pv->f[0x34C / 4] = 1.0f;
            }
            m->f[0x2C / 4] = ((Obj *)m->ptr[0x24 / 4])->f[0x24 / 4] * pv->f[0x34C / 4] * pv->f[0x5D4 / 4];
        }
        pv->f[0x118 / 4] -= 0.00392000005f;
        pv->f[0x110 / 4] *= 0.988000035f;
        pv->f[0x114 / 4] *= 0.988000035f;
        if (pv->f[0x118 / 4] < -0.540000021f) {
            pv->f[0x118 / 4] = -0.540000021f;
        }
        if (pv->ptr[0x348 / 4] != 0) {
            ((Obj *)pv->ptr[0x348 / 4])->i[0x98 / 4] = 0;
        }
        func_L01_0045AA30(m, &pv->b[0x110]);
        if ((o = (Obj *)pv->ptr[0x348 / 4]) != 0) {
            o->i[0x98 / 4] = ((Obj *)o->ptr[0x24 / 4])->i[0x10 / 4];
        }
        if (m->f[0x18 / 4] - func_003C3D30(&m->q[1], 0, 0, 0.5f) < 0.25f) {
            func_L01_0045A9F0(m);
            func_L01_004450F0(m, 0x14, -1);
        }
        break;
    }
    case 20:
        if (func_L01_004561B8(m) != 0) {
            if (m->b[0x43] != 5) {
                func_003C3A10(m, 5, 0, 8);
            }
            pv->i[0xA8 / 4] &= ~0x400;
        }
        func_L01_0045A9F0(m);
        if (m->b[0x60] & 2) {
            func_L01_004450F0(m, 8, 3);
            if (m->b[0x43] != 4) {
                func_003C3A10(m, 4, func_00382498(0, 0xA), 0);
            }
        }
        break;
    case 24: {
        f32 t;
        if (func_L01_004561B8(m) != 0) {
            if (m->b[0x43] != 4) {
                func_003C3A10(m, 4, 0, 5);
            }
            pv->f[0x300 / 4] = 0.0800000057f;
        }
        pv->f[0x300 / 4] += D_L01_001DD4D0;
        t = 1.0f - (pv->f[0x300 / 4] + 0.0800000057f) / 0.160000011f;
        *(u128_t *)&s30 = pv->q[0x2F0 / 16];
        *(u128_t *)&s40 = pv->q[0x320 / 16];
        func_003C4098(&s20, &s30, &s40, t);
        s20.z = m->f[0x18 / 4] + pv->f[0x300 / 4];
        m->f[0xF4 / 4] = t * 1.57079637f;
        vec_sub_ab(&s30, &s20, &m->q[1]);
        func_L01_0045AA30(m, &s30);
        if (t >= 1.0f) {
            func_L01_004450F0(m, 0x19, -1);
        }
        break;
    }
    case 25:
        if (func_L01_004561B8(m) != 0) {
            m->q[1] = pv->q[0x320 / 16];
            m->f[0xF4 / 4] = 1.57079637f;
            if (func_00382468(0xA) == 0) {
                if (m->b[0x43] != 9) {
                    func_003C3A10(m, 9, 0, 5);
                }
            } else if (m->b[0x43] != 0xB) {
                func_003C3A10(m, 0xB, 0, 5);
            }
            pv->f[0x328 / 4] = func_003C3D30(&pv->b[0x320], 0, 0, 0.5f);
            func_L01_0044E318(m, &pv->b[0x480]);
            func_L01_0044E340(&pv->b[0x480], 0x20, 1, D_L01_001DD4D4);
            func_L01_0044E340(&pv->b[0x480], 0x18, 2, D_L01_001DD4D4);
            func_L01_0044E340(&pv->b[0x480], 0x10, 3, D_L01_001DD4D4);
            func_L01_0044E340(&pv->b[0x480], 8, 4, D_L01_001DD4D4);
            if (D_001D545C == 0xD) {
                func_L01_004AADE8(0x13, 0, m, 0);
            }
        }
        pv->f[0x300 / 4] += D_L01_001DD4D0;
        if (pv->f[0x300 / 4] < D_L01_001DD4CC) {
            pv->f[0x300 / 4] = D_L01_001DD4CC;
        }
        qzero(&s20);
        s20.z = pv->f[0x300 / 4];
        func_L01_0045AA30(m, &s20);
        func_L01_0044E468(&pv->b[0x480], D_L01_001DD4D8);
        s30.x = func_0038D098(m->f[0xF8 / 4]) * 0.5f;
        s30.y = func_0038D0B0(m->f[0xF8 / 4]) * 0.5f;
        s30.z = 0.0f;
        vec_add_ba(&s30, &s30, &m->q[1]);
        if (func_L01_00446780(m, 0.5f, &s30, 0x2000001, 1.0f, 1.0f, 0, 1, 0) != 0
            && (u8 *)D_L01_001EAA18[0] == D_001A4BE0.ptr[0x25C0 / 4]) {
            D_001A4BE0.h[0x1DE / 2] = 0x32;
        }
        if (m->f[0x18 / 4] <= pv->f[0x328 / 4]) {
            func_L01_004450F0(m, 0x1A, -1);
        }
        break;
    case 26:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0044E740(&pv->b[0x480]);
            func_L01_00315900(m, 0, func_L01_00353880);
        }
        break;
    }
    vec_sub_ab(&s20, &s10, &m->q[1]);
    if (func_0038CEA8(&s20) < pv->f[0x98 / 4] * 0.5f) {
        pv->i[0x3A0 / 4]++;
    } else {
        pv->i[0x3A0 / 4]--;
    }
    func_L01_003535F0(m);
}

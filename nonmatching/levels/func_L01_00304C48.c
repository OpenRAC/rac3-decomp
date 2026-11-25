/* func_L01_00304C48 (2900 B, 34 places): unlinked draft, round 30 W8 (from sonnet-b33-h2d's 565-raw draft).
 * Measured: check.py FILE func_L01_00304C48 --no-context --mode S --as ps2as --flags=-mvu0-use-vf0-vf2: 608 raw, 155 aligned (difflib on the listing), 92 aligned with
 * registers normalised; 733 vs 725 insns. The file's own flags (no @ps2as, no -mvu0-use-vf0-vf2) do not match: it needs a cut at 0x304C48 with
 * "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2" (S mode).
 * What still differs: ONE allocation: retail keeps the loop counter i in $s7 and spills idx (0xE4($sp)); ours keeps idx in $s7 and spills i. Every other hunk of the
 * diff (the lw/sw 0xE4 traffic, the addiu $s7,1 / addiu $s0,$v1,-1 pairs, the hoisted address slots) follows from it. global.c priorities (tools/regalloc.py):
 * idx refs 23 live 453 -> 0.20, i refs 29 live 1144 -> 0.10, retail needs i first. Gcse PRE copies idx - 1 into the six arms (as retail's per-arm lw/addiu).
 * Tried (this round): nx = idx - 1 once at the join (this file; self lands in $s3 like retail, aligned 180 -> 155) instead of in every arm; idx--; if (idx < 0) idx = 34
 * (same bytes); idx = (idx - 1 >= 0) ? ... (same as the per-arm form); the -pi/4 / +pi/4 constants as two locals in either order (no change; retail has -pi/4 in $f21).
 * Earlier levers (h2d): idx = (nx >= 0) ? nx : 0x22 (slt vs register + movn), nested if (w34 == 0) layout, pm = m40 pointer local before the loop. */
#include "common.h"
#include "vu0.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 b0;
    u8 b1;
    u8 p2[0x6A];
    f32 f6C;
    f32 f70;
    u8 p74[0x7C];
} Row_00304C48;

typedef struct {
    u8 p0[0x18];
    u8 *w18;
    u8 p1C[4];
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
} Hit_00304C48;

typedef struct {
    u8 p0[0x25C0];
    u8 *x25C0;
    u8 p25C4[0x28C8 - 0x25C4];
    u8 shift;
} Game_00304C48;

typedef struct {
    u8 p0[0x44];
    s32 w44;
    s32 w48;
    u8 p4C[4];
    f32 f50;
    u8 p54[0x14];
    s32 w68;
} State_00304C48;

typedef struct {
    vu0_q v0;
    s32 w10;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 w20;
    f32 f24;
    s32 w28;
} Src_00304C48;

typedef struct {
    u8 p0[0x44];
    s32 w44;
} Xp_00304C48;

extern u8 *D_L01_001DC5C4;
__asm__(".extern D_L01_001DC5C4, 4");
extern Hit_00304C48 D_L01_001EAA00;
extern u8 *D_L01_001EEA80[];
extern Row_00304C48 D_L01_002C5600[];
extern u8 D_001425C0[];
extern Game_00304C48 D_001A4BE0;
extern s32 D_00142660[];
extern Xp_00304C48 D_00142DE0;
extern s32 D_001D545C;
extern u8 D_001BBE90[];
extern u8 D_L01_001D60E0[] __attribute__((section(".sdata")));
extern u8 D_L01_001D60D8[] __attribute__((section(".sdata")));
extern u8 D_0014275B[];
extern f32 D_L01_001DAA34;
extern f32 D_L01_002F1600[];

extern s32 func_0013D3E0(void);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_00382348(void *);
extern s32 func_003C4B50(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_L01_004CAB30(void *, void *);
extern void func_L01_004C8668(s32);
extern void func_L01_004C8688(s32, void *, void *);
extern void func_L01_004C7D40(void *, void *, f32);
extern void func_L01_004739D8(void *, void *, s32, f32, s32, s16, s32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_00315900(void *, s32, void *);
extern void func_L01_003E31A8(void *);
extern void func_L01_003DE198(void);
extern s32 func_L01_004006C8(u8 *, s32, s32);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00305970(void *, void *, void *);
extern void func_L01_00306628(s32, f32 *, void *, void *);

static __inline__ s32 scale_00304C48(s32 n) {
    return (f32)n * ((D_001D545C == 7 && D_0014275B[0]) ? D_L01_001DAA34 : D_L01_002F1600[D_001D545C]);
}

void func_L01_00304C48(u8 *self) {
    State_00304C48 *s;
    s32 idx;
    s32 i;
    u8 *e;
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 m40[4];
    Src_00304C48 d80;
    Src_00304C48 db0;
    u8 *t;
    u8 *st;
    u8 *m;
    s32 n;
    s32 k;
    s32 nx;
    vu0_v4 *pm;

    if (D_L01_001DC5C4 == 0) {
        return;
    }
    s = *(State_00304C48 **)(self + 0x68);
    i = 0;
    idx = s->w48;
    if (s->w44 <= 0) {
        return;
    }
    pm = m40;
    do {
        e = D_L01_001DC5C4 + (idx << 6);
        if (i != 0) {
            func_L01_004CAB30(e, e);
        }
        if (*(s32 *)(e + 0x38) >= 0) {
            func_L01_004C8688(*(s32 *)(e + 0x38), e + 0x10, e);
        }
        vec_add_ab(&v0, e, e + 0x10);
        if (*(s32 *)(e + 0x34) == 0) {
            if (func_003D3CB0(e, &v0, 0x10, self, 0) != 0) {
                *(s128 *)e = *(s128 *)&D_L01_001EAA00.v20;
                qzero(e + 0x10);
                func_0038CF68(&v10, &D_L01_001EAA00.v40, 0.1f);
                vec_add_ba(e, e, &v10);
                *(s32 *)(e + 0x34) = 1;
                func_L01_004C8668(*(s32 *)(e + 0x38));
                *(s32 *)(e + 0x38) = -1;
                *(s128 *)(e + 0x20) = *(s128 *)&v10;
                func_0038CF68(&v20, &v10, 0.01f);
                v30.x = func_003824E0(-0.7853982f, 0.7853982f);
                v30.y = func_003824E0(-0.7853982f, 0.7853982f);
                v30.z = func_003824E0(-0.7853982f, 0.7853982f);
                func_0038D328(pm, &v30);
                m40[3].x = 0;
                m40[3].y = 0;
                m40[3].z = 0;
                func_0038D028(&v20, &v20, pm);
                if ((D_L01_002C5600 + D_001425C0[0x11])->b1 >= 4) {
                    if ((func_0013D3E0() & 1) != 0) {
                        func_L01_004739D8(e, &v20, (func_00382498(0x40, 0x64) << 16) | 0x64004040, func_003824E0(0.1f, 0.2f) * 210000.0f, 0xFF0A0A, (func_00382498(0x14, 0x50) * 5 + 2) / 6, 0);
                    }
                } else {
                    func_L01_00466F50(e, &v20, 0, -1.0f, 0.0f);
                }
                qzero(&v30);
                t = D_L01_001EAA00.w18;
                if (t != 0 && t != D_001A4BE0.x25C0 && ((*(u16 *)(t + 0x34) & 0x1000) != 0 || (*(u8 **)(t + 0x24))[0x46] == 5)) {
                    st = func_00382348(t);
                    if (st != 0 && *(f32 *)st <= (D_L01_002C5600 + D_001425C0[0x11])->f6C && (D_L01_002C5600 + D_001425C0[0x11])->b1 >= 4 && func_003C4B50(D_L01_001EAA00.w18) == 0) {
                        if (st[0xE] == 3) {
                            func_L01_00446748(&d80, D_L01_001EAA00.w18, 0x10010000, (D_L01_002C5600 + D_001425C0[0x11])->f6C);
                            d80.b18 = 9;
                            func_L01_00446978(D_L01_001EAA00.w18, &d80);
                            i++;
                        } else {
                            s32 bonus;
                            s32 bits;
                            s32 id;
                            s32 reward;
                            m = D_L01_001EAA00.w18;
                            func_L01_004AAC98(1, 0, self, 0xC59);
                            func_L01_00315900(m, 5, func_L01_003DE198);
                            func_L01_003E31A8(m);
                            bonus = (D_00142660[14] + 49) / 50;
                            id = *(u16 *)(m + 0xB2);
                            bits = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
                            if (((id & 1) ? bits >> 4 : bits) & 8) {
                                reward = func_L01_004006C8(D_L01_001D60E0, *(u16 *)(m + 0xB6), *(s16 *)(m + 0xB2));
                            } else {
                                reward = func_L01_004006C8(D_L01_001D60D8, *(u16 *)(m + 0xB6), *(s16 *)(m + 0xB2));
                            }
                            reward <<= D_001A4BE0.shift;
                            if (func_L01_0041A4F0()) {
                                reward = scale_00304C48(reward);
                            }
                            D_00142DE0.w44 += reward + bonus;
                            i++;
                        }
                    } else {
                        vec_sub_ba(&d80, D_L01_001EAA00.w18 + 0x10, self + 0x10);
                        func_0038CF68(&d80, &d80, 1.0f);
                        func_0038CF68(&db0, &db0, 1.0f);
                        if ((D_L01_002C5600 + D_001425C0[0x11])->b1 >= 4) {
                            func_L01_00446760(&db0, self, 0x11010000, &d80, (D_L01_002C5600 + D_001425C0[0x11])->f6C);
                        } else {
                            func_L01_00446760(&db0, self, 0x1110000, &d80, (D_L01_002C5600 + D_001425C0[0x11])->f6C);
                        }
                        db0.v0 = d80.v0;
                        ((f32 *)&db0.v0)[3] = 5627.925f;
                        db0.b18 = 9;
                        db0.b19 = 1;
                        db0.h1A = *(u16 *)(D_L01_001EAA00.w18 + 0xAA);
                        db0.w20 = 1;
                        func_L01_00446978(D_L01_001EAA00.w18, &db0);
                        if (s->w68 == 0) {
                            if ((D_L01_002C5600 + D_001425C0[0x11])->b1 >= 4) {
                                s->w68 = 7;
                                func_L01_004AAC98(1, 0, self, 0xC59);
                            } else {
                                s->w68 = 7;
                                func_L01_004AAC98(1, 0, self, 0x5C9);
                            }
                        }
                        n = func_003D4D00(D_L01_001EAA00.w18 + 0x10, 0x10, self, 0, 1.5f);
                        if (s->w68 == 0) {
                            if ((D_L01_002C5600 + D_001425C0[0x11])->b1 >= 4) {
                                s->w68 = 7;
                                func_L01_004AAC98(1, 0, self, 0xC59);
                            } else {
                                s->w68 = 7;
                                func_L01_004AAC98(1, 0, self, 0x5C9);
                            }
                        }
                        i++;
                            if (n > 0) {
                            for (k = 0; k < n; k++) {
                                m = D_L01_001EEA80[k];
                                if (m == D_001A4BE0.x25C0) {
                                    continue;
                                }
                                vec_sub_ab(&d80, m + 0x10, self + 0x10);
                                func_0038CF68(&d80, &d80, 1.0f);
                                func_0038CF68(&db0, &db0, 1.0f);
                                if ((D_L01_002C5600 + D_001425C0[0x11])->b1 >= 4) {
                                    func_L01_00446760(&db0, self, 0x11010000, &d80, (D_L01_002C5600 + D_001425C0[0x11])->f70);
                                } else {
                                    func_L01_00446760(&db0, self, 0x1110000, &d80, (D_L01_002C5600 + D_001425C0[0x11])->f70);
                                }
                                db0.v0 = d80.v0;
                                ((f32 *)&db0.v0)[3] = 5627.925f;
                                db0.b18 = 9;
                                db0.b19 = 1;
                                db0.h1A = *(u16 *)(D_L01_001EEA80[k] + 0xAA);
                                db0.w20 = 1;
                                func_L01_00446978(D_L01_001EEA80[k], &db0);
                                if (s->w68 == 0) {
                                    if ((D_L01_002C5600 + D_001425C0[0x11])->b1 >= 4) {
                                        s->w68 = 7;
                                        func_L01_004AAC98(1, 0, self, 0xC59);
                                    } else {
                                        s->w68 = 7;
                                        func_L01_004AAC98(1, 0, self, 0x5C9);
                                    }
                                }
                            }
                        }
                    }
                } else {
                    i++;
                    if (func_0013D3E0() % 11 == 0) {
                        func_L01_00306628((s32)self, &D_L01_001EAA00.v20.x, &v10, &v30);
                    }
                }
            } else {
                func_L01_004C7D40(e, e + 0x10, 0.006f);
                i++;
            }
        } else {
            i++;
        }
        nx = idx - 1;
        idx = (nx >= 0) ? nx : 0x22;
        vec_add_ab(e, e, e + 0x10);
        if (func_0013D3E0() % 7 == 0) {
            func_0038CF68(&v10, e + 0x10, 0.05f);
            func_L01_00305970(self, e, e + 0x10);
        }
        if (func_0013D3E0() % 22 == 0) {
            func_0038CF68(&v10, e + 0x10, 0.05f);
            if ((D_L01_002C5600 + D_001425C0[0x11])->b1 >= 4) {
                if ((func_0013D3E0() & 1) != 0) {
                    func_L01_004739D8(e, &v10, (func_00382498(0x40, 0x64) << 16) | 0x64004040, func_003824E0(0.1f, 0.2f) * 210000.0f, 0xFF0A0A, (func_00382498(0x14, 0x50) * 5 + 2) / 6, 0);
                }
            } else {
                func_L01_00466F50(e, &v10, 0, -1.0f, 0.0f);
            }
        }
    } while (i < s->w44);
}

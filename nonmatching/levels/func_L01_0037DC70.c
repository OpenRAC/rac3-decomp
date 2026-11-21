/* PAL near miss (Sonnet round 20, b33 h6c): 250 raw / 19 aligned / 10 registers-masked differences in the file's flags (`@ps2as -mvu0-use-vf0-vf2`, mode S;
 * all four modes of --all-modes are worse). The raw count is large because retail has two more words than ours (the `move $s7,$v1` / `addiu $v1,$v1,0x5600`
 * of the first table lookup): every word after it shifts. Projectile (bullet) update: the object's position += velocity (`vec_add_ab`, the 16-byte copy of the old
 * position through `vu0_v4`), the row table `D_L01_002C5600[D_001425C0[0x6F]].b1` (0xF0-byte rows, read three times: head, loop, join), a segment test
 * `func_003D3CB0(&old, &pos, 0, ignore, 0)` once (rows with b1 == 0) or in a 6-iteration retry loop (b1 != 0) that remembers the hit object, the hit effect
 * (func_0038CE20 / func_L01_00446760 / func_003D4D00 with the descriptor bytes at sp+0x48..0x4a, a dead `vec_add_ab` into sp+0x60), the 0.05 step of
 * D_L01_001E1DB8 / DBC, and the counter w34 state machine with the two func_L01_00404A10 callbacks and the colour words D_L01_002B3AC0[3..4].
 * Levers found (each cut the aligned diff): the state is addressed through an UNTYPED `s32 *p` (typed struct fields do not alias the scalar globals, retail
 * reloads w34 after the stores to D_L01_001E1D90/94); `p = m->p68` loaded BEFORE the `b20 != 0` early exit (retail fills the bnez slot with it); the row
 * lookup as `(D_L01_002C5600 + D_001425C0[0x6F])->b1`; the hit object's id as `s16` (`lh`); D_L01_001EAA20 as its own vector symbol in the first block;
 * `func_003D4D00` declared `s32` (the next `lw` of w48 lands in $v1 like retail); `if (D_L01_001E1DA0 >= 5) { + } else { - }` for the 0.05 step.
 * Left: (1) the allocation of the two high parts. Retail keeps `(high D_001425C0)` in $fp and `(high D_L01_002C5600)` in $s7 (gcse's PRE reaching registers,
 * `lui $v1,0x2c; move $s7,$v1; addiu $v1,$v1,0x5600`) and recomputes the low part at each of the three lookups; ours lets loop.c hoist the in-loop low
 * part `&D_L01_002C5600` (a REG_EQUAL symbol constant, `move $fp,$a2` in the preheader), which takes $fp, so the second high part has no register and the join
 * rebuilds `lui $v0,0x2c`; `mult` / `addu` register roles follow. Table-access forms (index, pointer sum, byte arithmetic, `&D[i]`), loop shapes (for / while /
 * do-while / nested ifs) and callee types did not stop the hoist. (2) the second global store of the `w34 == 8` arm: retail keeps both stores as `lui $at; sw`
 * pairs and fills the `b` slot with `ld $s1`; ours puts `sw $v1,D_L01_001E1D94` into the slot (assembled as $gp form). Unsized-array and section(".data")
 * declarations of the two globals made it worse. (3) the order of the three descriptor byte stores in the second hit block.
 * Needs the file's context (vu0.h). Checks with the stripped file at level 01. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0037DC70 */
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 p21[0x47]; u8 *p68; u8 p6C[0x3E]; u16 hAA;
} M_37DC70;
typedef struct {
    vu0_v4 v0; vu0_v4 v10; u8 p20[0x14]; s32 w34; u8 p38[4]; f32 f3C; s32 w40; u8 p44[4]; s32 w48; s32 w4C;
} St_37DC70;
typedef struct { u8 p0[0xAA]; s16 hAA; } H_37DC70;
typedef struct { u8 p0[0x18]; H_37DC70 *w18; u8 p1C[4]; vu0_v4 v20; } T_37DC70;
typedef struct { vu0_v4 v; u8 p10[8]; u8 b18; u8 b19; u16 h1A; u8 p1C[0x14]; } S_37DC70;
typedef struct { u8 p0; u8 b1; u8 p2[0xEE]; } Row_37DC70;
extern T_37DC70 D_L01_001EAA00;
extern vu0_v4 D_L01_001EAA20;
extern vu0_v4 D_001A52D0;
extern u8 D_001425C0[];
extern Row_37DC70 D_L01_002C5600[];
extern s32 D_L01_001E1DA0;
extern f32 D_L01_001E1DB8;
extern f32 D_L01_001E1DBC;
extern s32 D_L01_001E1D90;
extern s32 D_L01_001E1D94;
extern s32 D_L01_001DFB40;
extern s32 D_L01_002B3AC0[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_0037E2E8();
extern void func_L01_0037E620();
extern void func_L01_0037E670();

void func_L01_0037DC70(M_37DC70 *m) {
    s32 *p;
    vu0_v4 old;
    vu0_v4 v10;
    vu0_v4 vA0;
    S_37DC70 sB0;
    vu0_v4 v60;
    M_37DC70 *hit;
    s32 i;

    p = (s32 *)m->p68;
    if (m->b20 != 0) {
        return;
    }
    old = m->pos;
    if (p[18] != 0) {
        vec_add_ab(&m->pos, &m->pos, (p + 4));
    } else {
        vec_add_ab(&m->pos, &m->pos, p);
    }
    p[13]++;
    hit = 0;
    if ((D_L01_002C5600 + D_001425C0[0x6F])->b1 == 0) {
        if (p[19] == 0) {
            if (!(m->pos.x < 2.0f || 1021.0f < m->pos.x || m->pos.y < 2.0f || 1021.0f < m->pos.y ||
                  m->pos.z < 2.0f || 1021.0f < m->pos.z)) {
                if (func_003D3CB0(&old, &m->pos, 0, m, 0)) {
                    p[19] = 1;
                    v10 = D_L01_001EAA20;
                    vA0 = D_001A52D0;
                    func_0038CE20(&vA0, &vA0, 1.0f);
                    vA0.w = 5627.925f;
                    func_L01_00446760(&sB0, m, p[16], &vA0, ((f32 *)p)[15]);
                    sB0.b19 = 1;
                    sB0.h1A = m->hAA;
                    sB0.b18 = 0;
                    func_003D4D00(&v10, 0, m, &sB0, 0.6f);
                    if (p[18] != 0) {
                        func_0038CF68((p + 4), (p + 4), -0.2f);
                        vec_add_ab(&v60, &v10, (p + 4));
                    } else {
                        func_0038CF68(p, p, -0.2f);
                        vec_add_ab(&v60, &v10, p);
                    }
                }
            }
        }
    } else {
        for (i = 0; i < 6; i++) {
            if (m->pos.x < 2.0f || 1021.0f < m->pos.x || m->pos.y < 2.0f || 1021.0f < m->pos.y ||
                m->pos.z < 2.0f || 1021.0f < m->pos.z) {
                continue;
            }
            if (func_003D3CB0(&old, &m->pos, 0, hit, 0)) {
                T_37DC70 *t = &D_L01_001EAA00;
                if (t->w18 != 0 && t->w18->hAA == 0x1CF7) {
                    break;
                }
                v10 = t->v20;
                hit = t->w18;
                vA0 = D_001A52D0;
                func_0038CE20(&vA0, &vA0, 1.75f);
                vA0.w = 5627.925f;
                func_L01_00446760(&sB0, m, p[16], &vA0, ((f32 *)p)[15]);
                sB0.b18 = 0;
                sB0.h1A = m->hAA;
                sB0.b19 = 1;
                if ((D_L01_002C5600 + D_001425C0[0x6F])->b1 >= 3) {
                    func_003D4D00(&v10, 0, m, &sB0, 2.5f);
                } else {
                    func_003D4D00(&v10, 0, m, &sB0, 0.8f);
                }
                if (p[18] != 0) {
                    func_0038CF68((p + 4), (p + 4), -0.2f);
                    vec_add_ab(&v60, &v10, (p + 4));
                } else {
                    func_0038CF68(p, p, -0.2f);
                    vec_add_ab(&v60, &v10, p);
                }
            }
        }
    }
    if (func_0038CAD0(&D_L01_001E1DA0) == 0 && (D_L01_002C5600 + D_001425C0[0x6F])->b1 >= 3) {
        if (D_L01_001E1DA0 >= 5) {
            D_L01_001E1DB8 += 0.05f;
            D_L01_001E1DBC += 0.05f;
        } else {
            D_L01_001E1DB8 -= 0.05f;
            D_L01_001E1DBC -= 0.05f;
        }
        func_L01_00404A10(func_L01_0037E2E8, m);
    }
    if (p[13] >= 0x16) {
        func_003C2880(m);
        return;
    }
    if (p[18] != 0) {
        if (p[13] < 0x11) {
            func_L01_00404A10(func_L01_0037E620, m);
            func_L01_00404A10(func_L01_0037E670, m);
        }
        if (p[13] == 8) {
            D_L01_001E1D90 = 2;
            D_L01_001E1D94 = D_L01_001DFB40;
        }
    } else {
        if (p[13] < 8) {
            func_L01_00404A10(func_L01_0037E620, m);
            func_L01_00404A10(func_L01_0037E670, m);
        }
        if (p[13] == 3) {
            D_L01_001E1D90 = 2;
            D_L01_001E1D94 = D_L01_001DFB40;
        }
        D_L01_002B3AC0[3] = ((0xBF - p[13] * 15) << 24) | 0x808080;
        D_L01_002B3AC0[4] = ((0xBF - p[13] * 15) << 24) | 0x8080B4;
    }
}
/* localdecomp:end func_L01_0037DC70 */

/* func_L03_004495E8 (L03_004495A8.c; also L07 0045AD08, L34 004303E8): near miss, 5 rows, and only
 * with file flags it does not have yet. The VU0 j-form helpers (vec_sub_ba, vec_add_ab, vec_sub_ab)
 * need -mvu0-use-vf0-vf2, and retail's `jal func_0038CE68; nop` after the last sqc2 needs @ps2as
 * (GNU as fills that slot with the sqc2); with both added the file's three matched functions
 * (004495A8, 004497E8, 00449838) still match. What differs is one register choice in
 * `i = m->hC8 - m->hCA`: retail loads hC8 into $v1 and hCA into $v0 and subtracts in place
 * (subu $v1,$v1,$v0; sll/sra $v1), this C loads them the other way round and computes in $v0.
 * Tried: (u16) casts on either operand or the result, i = hC8; i -= hCA (gives lh, 4 rows),
 * -hCA + hC8, s16 temporaries, s32 i with (s16) cast (78 rows), the wrap tests reworded,
 * i in an inner block: all the same 5 rows or worse. Also needs `#include "vu0.h"` in the file. */
/* NM-R7 (2026-11-22): 5 differences (tools/check.py, level 03) with -mvu0-use-vf0-vf2 @ps2as; the file's line does not compile it. 15 more wordings give 5 or 4 (nonmatching/README.md). */
/* RT-B retry (2026-11-22, rac3-w1, upstream b7be60ac): `i = m->hC8; i -= m->hCA;` (NM-R7's 4-row form) is now the
 * draft: 4 differences (tools/check.py) at levels 03, 07 and 34 with `-mvu0-use-vf0-vf2 @ps2as` on L03_004495A8.c
 * (whose three matched functions, Flavius x2 and The Boso, still match with that line at every placement).
 * Left: `lh` for hC8 where retail has `lhu`, and the difference in $v0 instead of in place in $v1. (u16) casts on
 * either or both operands, `i = (u16)i - (u16)hCA`, `-(hCA - hC8)`, `(s16)(hC8 + -hCA)`: 4 or 5. */
#include "common.h"
#include "vu0.h"
typedef struct { s32 count; s32 pad[3]; vu0_v4 pts[1]; } P_004495E8;
typedef struct { u8 pad[0x34]; f32 f34; s32 w38; u8 pad3C[0xC4 - 0x3C]; P_004495E8 *wC4; s16 hC8; s16 hCA; } S_004495E8;
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void *func_L01_0045B958(void *);
extern void func_L01_0045A748(void *, void *);
void func_L03_004495E8(int a0, int a1) {
    u8 *o = (u8 *)a0;
    P_004495E8 *t = (P_004495E8 *)a1;
    S_004495E8 *m;
    f32 v[4];
    f32 d[4];
    f32 e[4];
    s16 i;
    f32 len;
    f32 s;
    m = func_L01_0045B958(o);
    if (m == 0) {
        return;
    }
    if (t != m->wC4) {
        func_L03_00449838(a0, a1, 1, -1);
    }
    s = m->f34 * 10.0f + 1.0f;
    vec_sub_ba(v, &t->pts[m->hC8], o + 0x10);
    if (!(m->w38 & 0x400)) {
        v[2] = 0.0f;
    }
    func_0038CF68(v, v, s);
    vec_add_ab(v, v, o + 0x10);
    func_L01_0045A748(o, v);
    i = m->hC8;
    i -= m->hCA;
    if (i < 0) {
        i += t->count;
    } else if (i >= t->count) {
        i -= t->count;
    }
    vec_sub_ba(d, &t->pts[m->hC8], &t->pts[i]);
    if (!(m->w38 & 0x400)) {
        d[2] = 0.0f;
    }
    len = func_0038CEA8(d) - m->f34;
    func_0038CF68(d, d, 1.0f);
    vec_sub_ab(e, o + 0x10, &t->pts[i]);
    if (len < func_0038CE68(e, d)) {
        m->hC8 += m->hCA;
        if (m->hC8 < 0) {
            m->hC8 += t->count;
        } else if (m->hC8 >= t->count) {
            m->hC8 -= t->count;
        }
    }
}

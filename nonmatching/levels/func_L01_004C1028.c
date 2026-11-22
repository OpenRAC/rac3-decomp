/* PAL near miss (sonnet-b30-j1, round 19): 52 words differ at level 01 with the file's flags plus `@ps2as` (15 when aligned: the first
 * difference shifts everything after it; 2 of the words are the jump table's lui/addiu, which check.py resolves only once the code matches).
 * Ported from the matched twin func_L01_0049E710 (the same effect-list updater with 0x2C-byte entries; this one has 0x30-byte entries,
 * the extra func_003E7F20 / func_L01_00518010 / func_003E8898 / func_L01_00517BF8 / func_L01_00517DB8 calls in cases 4 and 5 and
 * its a/b temporaries in $a1/$a2 instead of saved registers). The function needs `@ps2as` (0.005f / 0.0005f by lui/ori/mtc1), so it also needs a cut:
 * a file of its own at 0x4C1028 (8-aligned both sides).
 * What differs: (1) retail's `a = 3; if (f & 1) a = 1; else if (f & 2) a = 2;` is `beqz; addiu $a1, 3 (slot); b; addiu $a1, 1` then
 * `movn $a1, $v0(2), $v1(f & 2)`: mine makes the old value the constant (cse knows a == 3) and emits `bnel` / `movz $a1, $a2(3), ...`;
 * the same for b (6 words); (2) the `(e->f2C & 0x10) ? 1 : 2` argument and the `e->f2C & 0x60` test load the flags into $v0 in mine and $v1 in
 * retail (the constant 2 gets $v0 there): 5 words at three sites. Block-local `a`/`b` (a function-level pair makes them saved registers: right for
 * func_L01_0049E710, wrong here), the nested-ternary / else-else / init-first forms and u32/!= 0 spellings all give the same bytes.
 * Check: python tools/check.py nonmatching/levels/func_L01_004C1028.c func_L01_004C1028 --as ps2as
 */
#include "common.h"
/* localdecomp:start func_L01_004C1028 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 type;
    s32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    s32 f20;
    s32 f24;
    f32 f28;
    s32 f2C;
} E_004C1028;
extern s32 func_L01_00518D40(s32);
extern void func_L01_00518590(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern void func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E90B8(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003E7F20(s32, s32);
extern void func_L01_00518010(s32, s32);
extern void func_003E8898(s32, f32, f32);
extern void func_L01_00516818(s32, f32);
extern void func_L01_00516728(s32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00518670(s32, s32, s32);
extern void func_L01_00517BF8(s32, s32, s32, s32, s32, s32);
extern void func_L01_00517DB8(s32, s32, f32, s32);
extern void func_L01_00516B90(s32, s32, s32);
extern void func_003E8630(s32, s32);
extern s32 func_00381FF0(s32);

void func_L01_004C1028(E_004C1028 *tbl) {
    s32 i = 0;
    E_004C1028 *e;

    while (tbl[i].f0 != 0) {
        e = &tbl[i];
        switch (e->type) {
        case 0:
            func_L01_00518D40(e->f0);
            if (e->f2C & 1) {
                func_L01_00518590(e->f0, 1, 1);
                func_L01_00516470(e->f0, e->f10, e->f14);
                func_L01_00517538(e->f0, e->f18, e->f1C);
            }
            break;
        case 1:
            func_003E8EF0(e->f0, e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 0.0f);
            break;
        case 2:
            func_003E9138(e->f0, e->fC, e->f10, e->f14, e->f18, e->f1C, e->f24);
            break;
        case 3:
            func_003E9270(e->f0, e->fC, e->f10, e->f14, e->f18, e->f1C, e->f28, e->f28);
            break;
        case 4:
            func_003E90B8(e->f0, (e->f2C & 4) ? func_00381FF0(e->f24) : e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 0.005f, 0.005f);
            func_003E7F20(e->f0, (e->f2C & 0x10) ? 1 : 2);
            if (e->f28 != 0.0f) {
                func_L01_00518010(e->f0, 1);
                func_003E8898(e->f0, e->f28, 0.0f);
            }
            break;
        case 5:
            func_003E9358(e->f0, (e->f2C & 4) ? func_00381FF0(e->f24) : e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 1.0f);
            func_L01_00516818(e->f0, e->f28);
            func_L01_00516728(e->f0, e->f28 * 0.005f, e->f28 * 0.005f);
            func_L01_00516AA0(e->f0, 0x40, 1);
            if (e->f2C & 8) func_L01_00518670(e->f0, 1, 1);
            func_003E7F20(e->f0, (e->f2C & 0x10) ? 1 : 2);
            if (e->f2C & 0x60) {
                func_L01_00517BF8(e->f0, 1, 1, 1, 0, 0);
                func_L01_00517DB8(e->f0, 0xF0, 0.0005f, 0);
            }
            break;
        }
        if (e->f20 != 0) {
            s32 a;
            s32 b;
            if (e->f20 & 1) a = 1;
            else if (e->f20 & 2) a = 2;
            else a = 3;
            if (e->f20 & 8) b = 1;
            else if (e->f20 & 0x10) b = 2;
            else b = 3;
            func_L01_00516B90(e->f0, a, b);
        }
        if (e->f2C & 2) func_L01_00516AA0(e->f0, 1, 0);
        if (e->f4 != 0) func_003E8630(e->f4, e->f0);
        i++;
    }
}
/* localdecomp:end func_L01_004C1028 */

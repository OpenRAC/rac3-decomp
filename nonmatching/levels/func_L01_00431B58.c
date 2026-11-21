/* PAL near miss (b30 J6B): 5 words differ at level 01 (the file L01_00431808.c has `@ps2as` on its text_parts line since func_L01_00431810 matched). Check with:
 *   python tools/check.py nonmatching/levels/func_L01_00431B58.c func_L01_00431B58
 * Left: reload-register choices in the object-loop preheader, `sll $a0,$fp,2; addu $a0,$a0,$v0; sw $a0,0x10($sp)` where retail has $v1 (3 words), and the
 * second `addiu $v1,$zero,0xb; bne $a0,$v1` of the `id == 11` test where retail has $v0 (2 words). Cause (loop dump): loop.c's inner loop moves the four
 * `lui/addiu` address pairs (D_00142CA0, D_00142BA0, D_L01_001F3F40, the 3F60/3F80 table) and the `&arr[i]` pointer to the preheader, and the outer loop
 * combines and moves the two `li 11` (savings 2, life 4 passes the threshold); reload then rematerialises them with rotating spill registers. Retail moves none of
 * them. Not changed by: 10 wordings of the first test, switch / short id / for-loop / goto-loop forms (for-loop fixes the first `li 11` but breaks the tail),
 * an alias for the second D_00142CA0 use (worse), every other assignment of the four array aliases.
 * What made it close (185 -> 5): `u32 D_00142BA0[]` + `[37] & 0x200000`, `s32 D_L01_001F3F40[]` + `[3]`, UNSIZED table bases (the 8-byte `la` form
 * gave the wrong hoisting), `id` assigned before the first compare, separate ifs for 0xFE / 0xFD (no range test), `i = 0` before the guard, the call arguments
 * written inline (`(s32)(e * 128.0f + 24.0f)` twice, the nested func_00396968 call as the first argument), func_L01_004316B0 declared with the floats first
 * (`(f32, f32, f32 *, f32 *, s32, s32)`: the move order of the sibling that matched), and ONE ALIAS DECLARATION PER USE of the gp array
 * (`D_L01_001D72A8` for the guard, `_00431B58a/b/c` for the first test, the inner compare and the loop test: 35 -> 5).
 * The D_001D545C reads need no alias: the slot copy is made by reorg and the assembler. D_L01_001D72B8 and D_L01_001D7290 carry `.extern X, 8 / 4` hints.
 */
#include "common.h"

/* localdecomp:start func_L01_00431B58 */
extern s32 D_001D545C;
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0020;
extern s32 D_L01_001D72A8[2];
__asm__(".extern D_L01_001D72A8, 8");
extern s32 D_L01_001D72A8_00431B58a[2];
__asm__(".extern D_L01_001D72A8_00431B58a, 8");
extern s32 D_L01_001D72A8_00431B58b[2];
__asm__(".extern D_L01_001D72A8_00431B58b, 8");
extern s32 D_L01_001D72A8_00431B58c[2];
__asm__(".extern D_L01_001D72A8_00431B58c, 8");
extern s32 D_L01_001D72B8[2];
__asm__(".extern D_L01_001D72B8, 8");
extern s32 D_L01_001D7290;
__asm__(".extern D_L01_001D7290, 4");
extern u32 D_00142BA0[];
extern u8 D_00142CA0[];
extern s32 D_L01_001F3F40[];
extern u8 D_L01_001F3F60[];
extern u8 D_L01_001F3F80[];
extern s32 func_L01_00430460(void *, s32);
extern s32 func_L01_0040F5B8(void *, void *, void *);
extern void func_L01_004316B0(f32, f32, f32 *, f32 *, s32, s32);
extern void *func_00396968(s32, s32);
extern void func_L01_004208E0(void *, s32, s32, s32, s32, s32, s32);

void func_L01_00431B58(f32 a, f32 b, f32 c, f32 d, f32 e) {
    f32 xy[2];
    u8 *o;
    s32 i;
    s32 k;
    s32 found;
    s32 v;
    s32 id;

    i = 0;
    if (D_L01_001D72A8[0] == 0) {
        return;
    }
    do {
        if (D_001D545C == 3 && D_L01_001D72A8_00431B58a[i] == 11) {
            goto next;
        }
        for (o = D_L01_001E001C; o < D_L01_001E0020; o += 0x100) {
            if (o == 0) {
                continue;
            }
            id = *(s16 *)(o + 0xAA);
            if (id != D_L01_001D72A8_00431B58b[i]) {
                continue;
            }
            if (o[0x20] == 0xFE) {
                continue;
            }
            if (o[0x20] == 0xFD) {
                continue;
            }
            if (id == 11) {
                v = func_L01_00430460(o + 0x10, 1);
                if (v == 0 && D_00142CA0[5] == 0) {
                    continue;
                }
            } else if (id == 0x1F28) {
                v = D_00142BA0[37] & 0x200000;
                if (v == 0 && D_00142CA0[5] == 0) {
                    continue;
                }
            }
            found = 0;
            for (k = D_L01_001F3F40[3] - 1; k >= 0; k--) {
                if (func_L01_0040F5B8(o + 0x10, D_L01_001F3F60 + k * 16, D_L01_001F3F80 + k * 16) != 0) {
                    found = k + 1;
                    break;
                }
            }
            func_L01_004316B0(*(f32 *)(o + 0x10), *(f32 *)(o + 0x14), xy, xy + 1, D_001D545C, found);
            xy[0] = a + xy[0] * (b - a) - e * 64.0f;
            xy[1] = c + xy[1] * (d - c) - e * 64.0f;
            func_L01_004208E0(func_00396968(0xE99A, D_L01_001D72B8[i]), (s32)xy[0], (s32)xy[1], (s32)(e * 128.0f + 24.0f),
                              (s32)(e * 128.0f + 24.0f), 100, 0x80000000);
            func_L01_004208E0(func_00396968(0xE99A, D_L01_001D72B8[i]), (s32)xy[0], (s32)xy[1], (s32)(e * 128.0f),
                              (s32)(e * 128.0f), 100, D_L01_001D7290);
        }
    next:
        i++;
    } while (D_L01_001D72A8_00431B58c[i] != 0 && i < 10);
}
/* localdecomp:end func_L01_00431B58 */

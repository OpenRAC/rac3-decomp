/* c53 cut pass (wave 14c, 2026-11-28), from r74's near. Needs the existing line of L01_003405B8.c,
 * '-O2 -G8 -fopt-stack -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as' (the file's line without
 * -fno-sched-interblock: retail's k loop hoists the call's argument loads, k++ and the pointer steps above
 * the beqz that skips the call), on a cut 0x00342640-0x00342938 (both ends 8-aligned, neighbours stay).
 * Under that line (tools/check.py --flags=-fsched-interblock) this C is 140 raw / 19 aligned rows (r74's
 * near: 184 / 52). Change against r74: the .w store of D[i][0] indexes the row by next - 1. Its own
 * multiply survives cse1, so the 160 constant of the D[i] store is used twice in loop's first pass and is
 * hoisted on its own (retail's t5, apart from the inner loops' giv constant t3); with that the whole
 * prologue and register assignment match retail. Left: retail's cse2 merges the .w multiply into the
 * D[i] one and keeps a copy (move a1,a2) for the .w store; here gcse hoists next - 1 above the first
 * inner loop and cse2 sees it equal to i only there, so the .w address keeps its own multiply (a3 copy of
 * i, mult t0,a3,t5, addu a1,t0,t6: +2 instructions). A diagnostic index i + j - 10 (j == 10 after the
 * loop, known to cse2 only) merges the multiplies but drops the copy, so the original's form is still
 * unknown. Also left: the alpha mul.s operand order (f0/f1). */
#include "common.h"

/* localdecomp:start func_L01_00342640 */
#include "vu0.h"
extern vu0_v4 D_L01_00279480[][10];
extern s16 D_L01_001E1990[] __attribute__((section(".sdata")));
extern s16 D_L01_001E19A0[] __attribute__((section(".sdata")));
extern s16 D_L01_001E19B0[] __attribute__((section(".sdata")));
extern f32 D_L01_001DD290;
__asm__(".extern D_L01_001DD290, 4");
extern f32 D_L01_001E19D4;
extern u8 D_001425C0[];
extern S_00341C10 D_L01_002C5600[];
void func_L01_00342640(u8 *self) {
    extern void func_L01_00409658(void *, s32, s32, s32, f32, f32, f32, s32, s32, s32);
    vu0_v4 origin;
    vu0_v4 delta[10];
    s32 i, j, k, level, kind, next;
    u32 alpha, color;
    vu0_v4 *p;

    *(vu0_q *)&origin = *(vu0_q *)(*(u8 **)(self + 0x68) + 0x30);
    i = 0;
    do {
        next = i + 1;
        if (D_L01_001E1990[i]) {
            for (j = 1; j < 10; j++)
                vec_sub_ab(&delta[j], &D_L01_00279480[i][j], &D_L01_00279480[i][j - 1]);
            *(vu0_q *)D_L01_00279480[i] = *(vu0_q *)&origin;
            D_L01_00279480[next - 1][0].w = 0.04f;
            for (j = 1; j < 10; j++) {
                vec_add_ab(&D_L01_00279480[i][j], &D_L01_00279480[i][j - 1], &delta[j]);
                D_L01_00279480[i][j].w = 0.04f;
            }
            if (D_L01_001E1990[i] > 0)
                D_L01_001E19A0[i] = (s32)(D_L01_001DD290 * ((f32)D_L01_001E1990[i] / (f32)D_L01_001E19B0[i]));
            else
                D_L01_001E19A0[i] = 0;
        }
        i = next;
    } while (i < 5);
    level = (D_001425C0[0x16] + D_L01_002C5600)->b;
    kind = 23;
    if ((u32)(level - 2) < 2) kind = 15;
    else if (level >= 4) kind = 48;
    for (k = 0; k < 5; k++) {
        if (D_L01_001E1990[k]) {
            alpha = (s32)(D_L01_001E19D4 * D_L01_001E19A0[k]) << 24;
            color = 0x7F7F7F;
            if (level < 4) {
                color = 0x7F4040;
                if (level != 3) {
                    color = 0x606020;
                    if (level != 2) color = level == 1 ? 0x2040DF : 0x205080;
                }
            }
            func_L01_00409658(D_L01_00279480[k], kind, 14, 10, 0.0f, 4.0f, 0.0f, alpha | 0x7F7F7F, alpha | color, 1);
        }
    }
}
/* localdecomp:end func_L01_00342640 */

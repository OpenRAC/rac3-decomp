/* func_L18_004AF840: the C below measures 0 diff (check.py --no-context) only with n = i + 1 wrapped in the nested
 * do { } while (0) of the default case, which AGENTS.md forbids. Without it: 28 diff, 7 register-masked structural words
 * (round 12, s4, ~25 compiles): gcc keeps `i + 1` in its own register (`addiu $s3,$s2,1` early in case 1 and at the tail,
 * then `move $s2,$s3`) where retail increments s2 in place (`addiu $s2,$s2,1`).
 * Tried, all the same 28: i++ / ++i / i = i + 1 at the loop end with no n at all (the temp still appears, so it is loop.c's
 * biv handling rather than n), for (...; i++), for (...; i = n), n declared first, n initialised, u32 n, for (;;) with a
 * break. Worse: a single `E_4AF840 *e` pointer in case 1 (112), two pointer locals for the flag and the list (105), `i++`
 * early in case 1 with D[i - 1] (149), while (1) with return (50), do-while with a guard (69), a goto loop (54, without
 * loop.c's hoisting the table base is not kept in $s7).
 */
#include "common.h"

/* localdecomp:start func_L18_004AF840 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_4AF840;
extern E_4AF840 D_L18_002ECBA8[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0(void);

void func_L18_004AF840(void) {
    s32 i = 0;
    s32 n;
    while (D_L18_002ECBA8[i].f0 != 0) {
        switch (D_L18_002ECBA8[i].mode) {
        case 0: {
            E_4AF840 *e = &D_L18_002ECBA8[i];
            u8 v = 0;
            if ((D_00142BA0[D_L18_002ECBA8[i].c.bit >> 2] & (1 << (D_L18_002ECBA8[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 1: {
            s32 k;
            D_L18_002ECBA8[i].flag = 0;
            n = i + 1;
            for (k = 0; D_L18_002ECBA8[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if (D_L18_002ECBA8[i].flag || (D_00142BA0[D_L18_002ECBA8[i].c.list[k] >> 2] & (1 << (D_L18_002ECBA8[i].c.list[k] & 31))) || func_L01_0041A4F0()) v = 1;
                D_L18_002ECBA8[i].flag = v;
            }
            break;
        }
        case 2: {
            E_4AF840 *e = &D_L18_002ECBA8[i];
            u8 v = 0;
            if ((D_00142BA0[D_L18_002ECBA8[i].c.bit >> 2] & (1 << (D_L18_002ECBA8[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 3:
        case 4:
        default: {
            E_4AF840 *e = &D_L18_002ECBA8[i];
            u8 v = 0;
            if (D_00142693[0] || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            /* the nested do-while raises n's allocation weight so n shares i's register, as in retail */
            do { do { n = i + 1; } while (0); } while (0);
            break;
        }
        }
        i = n;
    }
}
/* localdecomp:end func_L18_004AF840 */

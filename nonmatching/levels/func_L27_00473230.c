/* func_L27_00473230: 107 diff (level 27). Same family as func_L27_00474338 / func_L01_0049DE10 but the flag is
   `bit || func_L01_0041A4F0()` and case 1 increments i in place before its list loop. Left: the saved-register
   assignment (retail: lp=$s0, e=$s1, i=$s2, v=$s3, k=$s4, const 1=$s5, D_00142BA0=$s6, hi=$s7; this C gives
   i=$s4) and in case 1 retail keeps &entry and &entry.c in two independent registers (lp also in $s0, not
   derived from e); the jump table (0..4, 3/4/default shared) and the structure match. About 9 wordings tried. */
/* localdecomp:start func_L27_00473230 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_473230;
extern E_473230 D_L27_002EEBA8[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0();

void func_L27_00473230(void) {
    s32 i = 0;
    while (D_L27_002EEBA8[i].f0 != 0) {
        switch (D_L27_002EEBA8[i].mode) {
        case 0: {
            E_473230 *e = &D_L27_002EEBA8[i];
            u8 v = 0;
            if ((D_00142BA0[D_L27_002EEBA8[i].c.bit >> 2] & (1 << (D_L27_002EEBA8[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            break;
        }
        case 1: {
            E_473230 *e = &D_L27_002EEBA8[i];
            u32 **lp = &D_L27_002EEBA8[i].c.list;
            s32 k;
            i++;
            e->flag = 0;
            for (k = 0; (*lp)[k] != 0; k++) {
                u8 v = 0;
                if (e->flag || (D_00142BA0[(*lp)[k] >> 2] & (1 << ((*lp)[k] & 31))) || func_L01_0041A4F0()) v = 1;
                e->flag = v;
            }
            continue;
        }
        case 2: {
            E_473230 *e = &D_L27_002EEBA8[i];
            u8 v = 0;
            if ((D_00142BA0[D_L27_002EEBA8[i].c.bit >> 2] & (1 << (D_L27_002EEBA8[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            break;
        }
        case 3:
        case 4:
        default: {
            E_473230 *e = &D_L27_002EEBA8[i];
            u8 v = 0;
            if (D_00142693[0] || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            break;
        }
        }
        i++;
    }
}
/* localdecomp:end func_L27_00473230 */

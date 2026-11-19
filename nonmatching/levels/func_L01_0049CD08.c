/* near miss: 13 differences, no do { } while (0). Retail keeps i and its incremented copy in ONE register (s2: `addiu $s2,$s2,1` right after the mult of case 1, then v in s3, k in s4); this C allocates the compiler's i + 1 temporary (hoisted in front of case 1's loop by the compiler, whichever way the increment is written) after v and k, so n is s4, v s2, k s3 and case 1 ends with `move $s2,$s4`. The earlier form with n = i + 1 in every case and `i = n` at the join gives 28; do { do { n = i + 1; } while (0); } while (0) gives 0 but is a register steer, so it is not used. */
#include "common.h"

/* localdecomp:start func_L01_0049CD08 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_9CD08;
extern E_9CD08 D_L01_002EC368[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0(void);

void func_L01_0049CD08(void) {
    s32 i = 0;
    while (D_L01_002EC368[i].f0 != 0) {
        switch (D_L01_002EC368[i].mode) {
        case 0: {
            E_9CD08 *e = &D_L01_002EC368[i];
            u8 v = 0;
            if ((D_00142BA0[D_L01_002EC368[i].c.bit >> 2] & (1 << (D_L01_002EC368[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            break;
        }
        case 1: {
            s32 k;
            s32 n = i + 1;
            D_L01_002EC368[i].flag = 0;
            for (k = 0; D_L01_002EC368[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if (D_L01_002EC368[i].flag || (D_00142BA0[D_L01_002EC368[i].c.list[k] >> 2] & (1 << (D_L01_002EC368[i].c.list[k] & 31))) || func_L01_0041A4F0()) v = 1;
                D_L01_002EC368[i].flag = v;
            }
            i = n;
            continue;
        }
        case 2: {
            E_9CD08 *e = &D_L01_002EC368[i];
            u8 v = 0;
            if ((D_00142BA0[D_L01_002EC368[i].c.bit >> 2] & (1 << (D_L01_002EC368[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            break;
        }
        case 3:
        case 4:
        default: {
            E_9CD08 *e = &D_L01_002EC368[i];
            u8 v = 0;
            if (D_00142693[0] || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            break;
        }
        }
        i++;
    }
}
/* localdecomp:end func_L01_0049CD08 */

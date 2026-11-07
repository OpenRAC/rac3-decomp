/* Level 01. 28 diff, default flags, 152 instructions. Jump table: retail has five entries (0, 1, 2 separate copies; 3, 4, default share); delete the INCLUDE_RODATA jtbl_002BCCA0 line when integrating. Open: retail increments i in place in case 1 (addiu $s2,$s2,1 after the mult) keeping i live across the list loop, which pushes the flag value to $s3 and k to $s4; this C computes n = i + 1 into $s3, so v lands in $s2 and k in $s3. */
#include "common.h"
#include "common.h"
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E49;
extern E49 D_L01_002EC368[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0(void);

void func_L01_0049CD08(void) {
    s32 i = 0;
    s32 n;
    while (D_L01_002EC368[i].f0 != 0) {
        switch (D_L01_002EC368[i].mode) {
        case 0: {
            E49 *e = &D_L01_002EC368[i];
            u8 v = 0;
            if ((D_00142BA0[D_L01_002EC368[i].c.bit >> 2] & (1 << (D_L01_002EC368[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 1: {
            s32 k;
            D_L01_002EC368[i].flag = 0;
            n = i + 1;
            for (k = 0; D_L01_002EC368[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if (D_L01_002EC368[i].flag || (D_00142BA0[D_L01_002EC368[i].c.list[k] >> 2] & (1 << (D_L01_002EC368[i].c.list[k] & 31))) || func_L01_0041A4F0()) v = 1;
                D_L01_002EC368[i].flag = v;
            }
            break;
        }
        case 2: {
            E49 *e = &D_L01_002EC368[i];
            u8 v = 0;
            if ((D_00142BA0[D_L01_002EC368[i].c.bit >> 2] & (1 << (D_L01_002EC368[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 3:
        case 4:
        default: {
            E49 *e = &D_L01_002EC368[i];
            u8 v = 0;
            if (D_00142693[0] || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        }
        i = n;
    }
}

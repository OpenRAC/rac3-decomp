#include "common.h"

/* localdecomp:start func_L05_00352618 */
extern s32 D_L05_001DF6C0;
extern u8 *D_L05_001DFB9C;
extern s16 *D_L05_0021DAE0[];
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L03_0043F5D0(s32, s32, float);

void func_L05_00352618(u8 *obj) {
    int *vars = *(int **)(obj + 0x68);
    int i;
    int n;
    int first;
    int second;
    s16 *ids;
    u8 *member;
    int period;
    float phase;

    switch (obj[0x20]) {
    case 0:
        n = 0;
        first = vars[3] << 24; first |= vars[2] << 16; first |= vars[1] << 8; first |= vars[0];
        vars[10] = first;
        second = vars[7] << 24; second |= vars[6] << 16; second |= vars[5] << 8; second |= vars[4];
        vars[11] = second;
        vars[9] = 0;
        if (vars[12] != -1) {
            vars[9] = 1;
            do {
                if (++n >= 4) break;
                if (vars[12 + n] == -1) break;
                vars[9]++;
            } while (1);
        }
        if (vars[9]) {
            func_L01_004450F0(obj, 2, -1);
        } else {
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    case 1:
        if (func_L01_00445AD0(obj[0x21], -1, 0) >= 2) {
            ids = D_L05_0021DAE0[obj[0x21]];
            do {
                member = D_L05_001DFB9C + ((*(u16 *)ids & 0x7FFF) << 8);
                if (member[0x31]) {
                    period = (vars[8] * 5 + 2) / 6;
                    phase = (float)(D_L05_001DF6C0 % period) * 6.2831855f / (float)period - 3.1415927f;
                    *(int *)(member + 0x78) = func_L03_0043F5D0(vars[10], vars[11], phase);
                }
            } while (*ids++ >= 0);
        }
    case 2:
        for (i = 0; i < vars[9]; i++) {
            u8 *target = D_L05_001DFB9C + (vars[12 + i] << 8);
            if (target[0x31]) {
                period = (vars[8] * 5 + 2) / 6;
                phase = (float)(D_L05_001DF6C0 % period) * 6.2831855f / (float)period - 3.1415927f;
                *(int *)(target + 0x78) = func_L03_0043F5D0(vars[10], vars[11], phase);
            }
        }
        break;
    }
}
/* localdecomp:end func_L05_00352618 */

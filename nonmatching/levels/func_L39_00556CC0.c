/* NEAR MISS (38 diff): retail loop keeps 2 pointers (load ptr a0 + lagging store ptr a2, counter a1, no s0), loop-exit reads gp slot D_0024D588 and the tail stores via 'lui at' with no CSE of the address; mine uses 1 pointer in s0 and CSEs the 0x24D588 address. */
#include "common.h"
extern s32 D_L39_0024D548[];
extern s32 D_L39_0024D588[];
extern s32 D_L39_0024D588_b;
extern s32 func_L39_00556C40(void);
extern void func_L39_00556638(s32, s32, s32);
extern void func_L39_00556C78(s32);
extern s32 func_L39_005B4398(s32);
void func_L39_00556CC0(s32 a0) {
    s32 i;
    s32 *p;
    s32 n;
    if (func_L39_00556C40() == 0) {
        i = 0;
        p = D_L39_0024D548;
        do {
            if (*p == 0) {
                *p = a0;
                return;
            }
            i++;
            p++;
        } while (i < 16);
        n = D_L39_0024D588_b;
    } else {
        p = &D_L39_0024D548[func_L39_005B4398(16)];
        func_L39_00556638(*p, 0, 0);
        func_L39_00556C78(*p);
        *p = a0;
        n = D_L39_0024D588[0];
    }
    D_L39_0024D588[0] = n + 1;
}

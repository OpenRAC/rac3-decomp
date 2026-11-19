/* functional: high. Registers a pawn in the 16-slot table D_L39_0024D548: first empty slot if the table is not full; if full it evicts a random slot (despawn effect via func_L39_00556638 and func_L39_00556C78) and takes it; the live counter D_L39_0024D588 is bumped on the evict path (and on the unreachable loop-exhausted path), not when an empty slot was filled. 11 words differ from retail (register choice, counter via $gp) */
#include "common.h"

extern s32 D_L39_0024D548[];
extern s32 D_L39_0024D588[];
extern s32 func_L39_00556C40(void);
extern s32 func_L39_005B4398(s32);
extern void func_L39_00556638(void *, s32, s32);
extern void func_L39_00556C78(s32);

void func_L39_00556CC0(s32 a0) {
    s32 i;
    s32 *slot;

    if (func_L39_00556C40() == 0) {
        for (i = 0; i < 16; i++) {
            if (D_L39_0024D548[i] == 0) {
                D_L39_0024D548[i] = a0;
                return;
            }
        }
    } else {
        slot = &D_L39_0024D548[func_L39_005B4398(0x10)];
        func_L39_00556638((void *)*slot, 0, 0);
        func_L39_00556C78(*slot);
        *slot = a0;
    }
    D_L39_0024D588[0] = D_L39_0024D588[0] + 1;
}

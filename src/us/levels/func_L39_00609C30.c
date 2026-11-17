#include "common.h"

/* localdecomp:start func_L39_00609C30 */
extern u8 D_L39_0024CD70[] __attribute__((section(".sdata")));
extern s16 D_L39_001FC4E0[];
extern s32 func_00388398(void *);
extern void func_003B8A68(s32 a0, s32 a1, s32 a2, s32 a3);

/* Calls func_003B8A68 with the first entry of D_L39_001FC4E0 and fixed values 300, 15, 15, and
 * returns whether timer_tick on D_L39_0024CD70 expired. */
s32 func_L39_00609C30(void) {
    s32 r = func_00388398(D_L39_0024CD70) != 0;
    func_003B8A68(D_L39_001FC4E0[1], 300, 15, 15);
    return r;
}
/* localdecomp:end func_L39_00609C30 */

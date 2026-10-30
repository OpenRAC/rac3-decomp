#include "common.h"

/* localdecomp:start func_U_003B8EF8 */
extern s32 D_U_001DA340;
__asm__(".extern D_U_001DA340, 16");
extern s16 D_0016C5A2[];

extern s32 func_U_00388398(s32 *counter);
extern void func_U_003B8A68(s32 position, s32 duration,
                          s32 fadeIn, s32 fadeOut);

s32 func_U_003B8EF8(void) {
    s32 complete;

    complete = func_U_00388398(&D_U_001DA340) != 0;
    func_U_003B8A68(D_0016C5A2[0], 300, 15, 15);
    return complete;
}
/* localdecomp:end func_U_003B8EF8 */
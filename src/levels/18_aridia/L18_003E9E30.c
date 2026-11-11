#include "common.h"

/* localdecomp:start func_L18_003E9E30 */
extern s32 D_L18_001DF4C0;
s32 *func_L18_003E9E30(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 1) {
        *a2 = 28;
        return &D_L18_001DF4C0;
    }
    return 0;
}
/* localdecomp:end func_L18_003E9E30 */

/* localdecomp:start func_L18_003E9E50 */
extern void *func_L01_0043B548(s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L18_003E9E50(u8 *object) {
    u8 *parts = *(u8 **)(object + 0x68);
    void *it;

    if (object[0x20] == 0) {
        if (*(s32 *)(parts + 0x30) > 0) {
            it = func_L01_0043B548(0x19E1, 0x6C);
            *(s32 *)(parts + 0x30) = -1;
            parts[0x3E] = 2;
            ((void (*)(u8 *))(*(void **)it))(object);
        } else {
            func_L01_004450F0(object, 1, -1);
        }
    }
}
/* localdecomp:end func_L18_003E9E50 */

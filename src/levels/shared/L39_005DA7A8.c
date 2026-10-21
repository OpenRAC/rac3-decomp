#include "common.h"

/* localdecomp:start func_L39_005DA7A8 */
extern s32 D_L39_001D7F38[2];
extern s8 D_L39_001D7F48[8];
extern s32 func_L01_0047B638(void);
extern s32 func_L39_00610490(s32);
extern void func_003E82F8(s32);
extern void func_L01_00516D60(s32, s32);
void func_L39_005DA7A8(s32 a0, s32 a1) {
    if (func_L39_00610490(func_L01_0047B638()) == 1) {
        s32 *p;
        s8 *q;
        func_003E82F8(a0);
        q = D_L39_001D7F48;
        p = D_L39_001D7F38;
        p[a0] = a1;
        q[a0] = 0;
        func_L01_00516D60(0x20001, 1);
    }
}
/* localdecomp:end func_L39_005DA7A8 */

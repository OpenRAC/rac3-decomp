#include "common.h"

/* localdecomp:start func_L14_00363510 */
extern s32 D_L14_001DDA08;
extern s32 D_L14_001DDA10;
extern s32 D_L14_001DD9F0;
extern s32 D_L14_001DDA18;
extern s32 D_L14_001DDA00;
extern s32 D_L14_001DDA04;
extern void func_L14_003AD768(void *);
void func_L14_00363510(u8 *a0) {
    s32 *s = *(s32 **)(a0 + 0x68);
    s32 x, y;
    if (a0[0x20] == 0) {
        a0[0x20] = 1;
        x = D_L14_001DDA00;
        y = D_L14_001DDA04;
        s[5] = (s32)&D_L14_001DDA08;
        s[4] = (s32)&D_L14_001DDA10;
        s[3] = 1;
        s[1] = (s32)&D_L14_001DD9F0;
        s[7] = y;
        s[2] = (s32)&D_L14_001DDA18;
        s[6] = x;
        s[0] = 0;
        s[8] = x;
    }
    func_L14_003AD768(a0);
}
/* localdecomp:end func_L14_00363510 */

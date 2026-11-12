#include "common.h"

/* localdecomp:start func_L14_0034DD98 */
extern s32 D_L14_001DD3E0;
extern s32 D_L14_001DD3F8;
extern s32 D_L14_001DD410;
extern s32 D_L14_001DD3D8;
extern s32 D_L14_001DD3DC;
extern u8 D_L14_002B4A40[];
extern void func_L14_003AD768(void *);
void func_L14_0034DD98(u8 *a0) {
    s32 *s = *(s32 **)(a0 + 0x68);
    s32 x, y;
    if (a0[0x20] == 0) {
        a0[0x20] = 1;
        x = D_L14_001DD3D8;
        y = D_L14_001DD3DC;
        s[5] = (s32)&D_L14_001DD3E0;
        s[4] = (s32)&D_L14_001DD3F8;
        s[3] = 6;
        s[1] = (s32)D_L14_002B4A40;
        s[7] = y;
        s[2] = (s32)&D_L14_001DD410;
        s[6] = x;
        s[0] = 0;
        s[8] = x;
    }
    func_L14_003AD768(a0);
}
/* localdecomp:end func_L14_0034DD98 */

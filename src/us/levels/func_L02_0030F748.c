#include "common.h"

/* localdecomp:start func_L02_0030F748 */
extern u8 D_L02_001E1300_0030F748[];
extern s16 D_001A4DDE[];
extern s32 D_L02_001F1600[];
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L02_003100F0(void *);
extern void func_L02_00310500(void *);
extern void func_L01_00402560(void *, void *);
void func_L02_0030F748(u8 *m) {
    u8 *d = *(u8 **)(m + 0x68);
    if (*(s32 *)(d + 0x5C) != -1 && !func_0037E0F0(D_L02_001E1300_0030F748, *(s32 *)(d + 0x5C), 0)) return;
    D_001A4DDE[0] = 3;
    if (m[0x20] == 0) func_L02_003100F0(m);
    if (D_L02_001F1600[0] == *(s32 *)(d + 0x50) &&
        !func_0037E0F0(D_L02_001E1300_0030F748, *(s32 *)(d + 0x54), 0) &&
        !func_0037E0F0(D_L02_001E1300_0030F748, *(s32 *)(d + 0x58), 0)) {
        func_L01_00402560(func_L02_00310500, m);
    }
}
/* localdecomp:end func_L02_0030F748 */

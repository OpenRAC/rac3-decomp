#include "common.h"

/* localdecomp:start func_L01_00492B50 */
extern s32 D_L01_001D8E78;
extern u8 *D_001D52FC[];
extern u8 D_L01_001D672C[];
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern void func_003BA4F8(s32, s32);
extern s32 func_003B97B0(void);
extern s32 func_003A5348(s32, s32, s32);
extern void func_00392DF0(s32, s32);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00493150(void);
extern void func_L01_00493078(s32, s32);
extern s32 func_L01_00498110_00492B50(void);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090_00492B50(s32);

void func_L01_00492B50(s32 a0) {
    s32 s = D_L01_001D8E78;
    switch (s) {
    case 0: {
        s32 x;
        s = *(s32 *)(D_001D52FC[0] + 0x1C4);
        x = func_003B9BD0(0);
        if (func_003B9C58(x) == 3) {
            if (func_L01_0041A4F0() == 0 && (s & 0x4000)) {
                func_003A5348(3, 0, 0);
                s &= ~0x4000;
            }
        }
        x = func_003B9BD0(0);
        func_003BA4F8(x, s);
        func_L01_00493150();
        func_L01_00493078(a0, s);
        break;
    }
    case 1:
        if (func_003B97B0() == 0) {
            D_L01_001D8E78 = 0;
            if (func_L01_00498110_00492B50() == s) {
                func_00392DF0(-1, 1);
            }
        }
        break;
    }
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090_00492B50(a0);
        if (D_L01_001D672C[0] == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
/* localdecomp:end func_L01_00492B50 */

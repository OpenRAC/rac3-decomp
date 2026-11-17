#include "common.h"
/* localdecomp:start func_L01_00491E68 */
extern s32 D_L01_001D8DE8[2];
extern S_48F880e D_L01_002EB2E8[];
extern S_48F880 *D_L01_001D52FC_00491E68[];
extern u8 D_L01_001D672C;
extern s32 func_L01_00517688(void);
extern void func_003A5348(s32 a0, s32 a1, s32 a2);
extern s32 func_L01_0047FE28(void);
extern s32 func_L01_0047EBE0(void);
extern s32 func_L01_004914D0(s32);
extern s32 func_L01_0048D8D8(void);
extern s32 func_L01_004A1128(void);
extern void func_L01_00517748(s32 a0);
extern void func_L01_00516090_00491E68(s32 a0);

void func_L01_00491E68(s32 a0, s32 flags) {
    S_48F880e *t;
    s32 *d;

    if (flags & 0x40) {
        d = D_L01_001D8DE8;
        t = D_L01_002EB2E8;
        if (t[d[func_L01_00517688()]].b4 != 0 && D_L01_002EB2E8[d[func_L01_00517688()]].fn != 0) {
            t[d[func_L01_00517688()]].fn();
        } else {
            func_003A5348(5, 0, 0);
        }
    }
    if (flags & 0x10) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_0047FE28());
        func_L01_00516090_00491E68(func_L01_004914D0(0));
    } else if (flags & 0x900) {
        if (D_L01_001D672C == 0) {
            func_003A5348(4, 0, 0);
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090_00491E68(func_L01_004914D0(0));
        }
    } else if (D_L01_001D52FC_00491E68[0]->w1C4 & 1) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_0048D8D8());
        func_L01_00516090_00491E68(a0);
    } else if (D_L01_001D52FC_00491E68[0]->w1C4 & 2) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_004A1128());
        func_L01_00516090_00491E68(a0);
    }
}
/* localdecomp:end func_L01_00491E68 */

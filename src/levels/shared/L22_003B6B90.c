#include "common.h"

/* localdecomp:start func_L22_003B6B90 */
extern void func_0038CAD0(void *);
extern void func_L01_00451DF8(void *, void *, f32, s32, s32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 D_001D545C;
extern s32 D_001D545C_003B6B90[];
extern u8 D_L22_001E2B00[];

void func_L22_003B6B90(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0x68);
    s32 t;
    func_0038CAD0(vars + 0x450);
    func_0038CAD0(vars + 0x454);
    if (*(u16 *)(moby + 0x96) <= 0xFFFE) {
        *(u16 *)(moby + 0x96) = *(u16 *)(moby + 0x96) + 1;
        t = D_001D545C_003B6B90[0];
    } else {
        t = D_001D545C;
    }
    if (t != 0x1B) {
        func_L01_00451DF8(moby, vars + 0x3B0, 1.75f, 2, 1);
    }
    if (moby[0x31]) {
        if (func_L01_0040E548(D_L22_001E2B00, moby + 0x10) < 576.0f) {
            func_L01_004472C0(moby);
            moby[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L22_003B6B90 */

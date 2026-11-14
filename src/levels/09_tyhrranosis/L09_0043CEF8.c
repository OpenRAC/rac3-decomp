#include "common.h"

/* localdecomp:start func_L09_0043CEF8 */
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_0043CEF8;
extern f32 D_L09_001D6B44;
extern u8 D_L09_001D6AB0;
extern u8 D_L09_001D6AA5;
extern S_0043CEF8 D_L09_002E7120;
extern u8 D_L09_002E7170[];
extern u8 D_L09_002E71D0[];
extern u8 D_L09_002E7230[];
extern s32 D_L09_001E6EC0[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);

void func_L09_0043CEF8(void) {
    u8 *q;
    D_L09_001D6B44 = 1.0f;
    D_L09_002E7120.f20 = &D_L09_001D6AB0;
    D_L09_002E7120.f30 = 1;
    q = 0;
    D_L09_001D6AA5 = 0;
    if (D_001D545C == 9) {
        switch (D_L09_001E6EC0[12]) {
        case 0:
            if (D_L09_001E6EC0[13] < 0xCC) {
                q = D_L09_002E7170;
            } else {
                q = D_L09_002E71D0;
            }
            break;
        case 1:
            q = D_L09_002E7230;
            break;
        }
    }
    if (q != 0) func_L01_00423068(q, 0, 0, 0, 0, 1, 0);
}
/* localdecomp:end func_L09_0043CEF8 */

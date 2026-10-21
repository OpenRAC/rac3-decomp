#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_003F29F8);

INCLUDE_ASM("asm/levels", func_L01_003F2A00);

INCLUDE_ASM("asm/levels", func_L01_003F2A50);

LINKER_REMNANT("asm/levels", func_L01_003F2AF0);

/* localdecomp:start func_L01_003F2AF8 */
extern void func_00382810(void *, s32, s32, f32, f32, f32, f32);

void func_L01_003F2AF8(void *a0, u8 *a1) {
    a1[29] = 0;
    if (*(f32 *)(a1 + 16) >= 0.0f) {
        func_00382810(a0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
    }
}
/* localdecomp:end func_L01_003F2AF8 */

INCLUDE_ASM("asm/levels", func_L01_003F2B58);

/* localdecomp:start func_L01_003F3068 */
typedef struct {
    u8 pad0[1056];
    s32 w420;
    f32 f424;
    f32 f428;
    f32 f42C;
    f32 f430;
    s32 w434;
    u8 b438;
    u8 b439;
    u8 pad43A[1120 - 1082];
} S_3F0EF0;
extern S_3F0EF0 D_L01_001E2A40[];
extern f32 D_L01_001E7630[];
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_003873C0(void);
void func_L01_003F3068(s32 a0) {
    S_3F0EF0 *p = &D_L01_001E2A40[a0];
    f32 s;
    p->b439 = 0;
    p->f424 = 1.11002934f;
    p->f428 = 1.11002934f;
    s = func_0038D0B0(0.55501467f);
    D_L01_001E7630[0] = s / func_0038D098(0.55501467f);
    func_003873C0();
    p->f42C = 0.00499999989f;
    p->f430 = 0.200000003f;
    p->w420 = 0;
    p->w434 = 0;
}
/* localdecomp:end func_L01_003F3068 */

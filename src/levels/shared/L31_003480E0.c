#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

INCLUDE_ASM("asm/levels", func_L31_003480E0);

INCLUDE_ASM("asm/levels", func_L31_00348BD8);

INCLUDE_ASM("asm/levels", func_L31_00348EE8);

INCLUDE_ASM("asm/levels", func_L31_00348FE8);

INCLUDE_ASM("asm/levels", func_L31_00349270);

/* localdecomp:start func_L31_00349350 */
extern f32 D_L31_001DD018;

s32 func_L31_00349350(void *arg0, void *arg1) {
    s32 var_v0;

    var_v0 = 1;
    if (!((*(f32 *)((u8 *)arg1 + 8)) < ((*(f32 *)((u8 *)arg0 + 0x18)) + D_L31_001DD018))) {
        var_v0 = 0;
    }
    return var_v0;
}
/* localdecomp:end func_L31_00349350 */

INCLUDE_ASM("asm/levels", func_L31_00349380);

INCLUDE_ASM("asm/levels", func_L31_003494B0);

INCLUDE_ASM("asm/levels", func_L31_00349560);

INCLUDE_ASM("asm/levels", func_L31_003496E8);

/* localdecomp:start func_L31_00349830 */
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);
void func_L31_00349830(s32 a0) {
    func_L30_0034CB68(a0, D_L31_001D66B0, 1, -1, 0, 0, D_L31_001DD09C, D_L31_001DD0A0);
}
/* localdecomp:end func_L31_00349830 */

INCLUDE_ASM("asm/levels", func_L31_00349868);

INCLUDE_ASM("asm/levels", func_L31_003498F8);

INCLUDE_ASM("asm/levels", func_L31_00349A18);

#include "common.h"

/* localdecomp:start func_L39_0068A8F8 */
s32 func_L01_00516470(s32, f32, f32);
s32 func_L01_005169C8(s32, f32);
s32 func_L01_00516AA0(s32, s32, s32);
s32 func_L01_005170B8(s32, s32);
s32 func_L01_00517538(s32, f32, f32);
extern u8 D_L39_003D2880[];

void func_L39_0068A8F8(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    s32 *temp_s0;

    temp_s0 = ((arg0 + 0x94) * 4) + D_L39_003D2880;
    func_L01_00516AA0(*temp_s0, 1, 1);
    func_L01_005170B8(*temp_s0, arg1);
    func_L01_00516470(*temp_s0, fparg0, fparg1);
    func_L01_00517538(*temp_s0, fparg2, fparg3);
    func_L01_005169C8(*temp_s0, fparg4);
}
/* localdecomp:end func_L39_0068A8F8 */

INCLUDE_ASM("asm/levels", func_L39_0068A9B8);

INCLUDE_ASM("asm/levels", func_L39_0068AAB8);

INCLUDE_ASM("asm/levels", func_L39_0068ADC8);

INCLUDE_ASM("asm/levels", func_L39_0068AEF8);

INCLUDE_ASM("asm/levels", func_L39_0068AF68);

INCLUDE_ASM("asm/levels", func_L39_0068B058);

/* localdecomp:start func_L39_0068B178 */
typedef struct S_68B178_B {
    char _p0[0x4];
    s32 f4;
} S_68B178_B;
typedef struct S_68B178_A {
    char _p0[0x10C];
    s32 f10C;
    S_68B178_B *f110[1];
} S_68B178_A;

/* from rac4-decomp's func_L00_0071B768 */
s32 func_L39_0068B178(S_68B178_A *arg0) {
    s32 r = -1;
    s32 i;
    for (i = 0; i < arg0->f10C; i++) {
        if (arg0->f110[i]->f4 >= 3) {
            r = i;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L39_0068B178 */

INCLUDE_ASM("asm/levels", func_L39_0068B1E0);

INCLUDE_ASM("asm/levels", func_L39_0068B260);

INCLUDE_ASM("asm/levels", func_L39_0068B2F8);

/* localdecomp:start func_L39_0068B3C0 */
typedef struct {
    s32 pad0;
    s32 unk4;
} S1_68B3C0;
typedef struct {
    u8 pad0[0x110];
    S1_68B3C0 *unk110[(0x290 - 0x110) / 4];
    s32 unk290;
} S0_68B3C0;
s32 func_L39_0068B1E0(S0_68B3C0 *, s32);
s32 func_L39_0068B2F8(S0_68B3C0 *, s32, s32);

/* from rac4-decomp's func_L00_0071B9B0 */
s32 func_L39_0068B3C0(S0_68B3C0 *arg0) {
    s32 temp_s1;
    s32 temp_v1;
    s32 var_v0;
    temp_s1 = arg0->unk290;
    if (temp_s1 == -1) {
        var_v0 = func_L39_0068B178((S_68B178_A *)arg0);
        goto block_4;
    }
    temp_v1 = arg0->unk110[temp_s1]->unk4;
    if (temp_v1 < 3) {
        var_v0 = func_L39_0068B1E0(arg0, -1);
block_4:
        func_L39_0068B2F8(arg0, var_v0, 0);
        return temp_s1;
    }
    if (temp_v1 < 4) func_L39_0068B2F8(arg0, temp_s1, 0);
    return temp_s1;
}
/* localdecomp:end func_L39_0068B3C0 */

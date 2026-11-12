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

/* localdecomp:start func_L39_0068A9B8 */
s32 func_L01_00516AA0(s32, s32, s32);
extern u8 D_L39_003D2880[];

void func_L39_0068A9B8(s32 arg0) {
    s32 *p = (s32 *)D_L39_003D2880;
    s32 *q;
    s32 i;
    func_L01_00516AA0(p[15], 1, 0);
    for (i = 0; i < 15; i++) {
        func_L01_00516AA0(p[i], 1, (i < 6 && arg0 != 0) || (i >= 6 && arg0 == 0));
    }
    for (i = 20; i < 152; i++) {
        func_L01_00516AA0(((s32 *)D_L39_003D2880)[i], 1, 0);
    }
    q = (s32 *)D_L39_003D2880;
    func_L01_00516AA0(q[4], 1, 1);
    func_L01_00516AA0(q[5], 1, 1);
}
/* localdecomp:end func_L39_0068A9B8 */

INCLUDE_ASM("asm/levels", func_L39_0068AAB8);

INCLUDE_ASM("asm/levels", func_L39_0068ADC8);

/* localdecomp:start func_L39_0068AEF8 */
typedef struct {
    s32 pad0[0x18];
    s32 (**vt)(void *, s32);
} S1_68AEF8;
typedef struct {
    u8 pad0[0x110];
    S1_68AEF8 *unk110[(0x290 - 0x110) / 4];
    s32 unk290;
} S0_68AEF8;
/* defined later in this file with an S0_68B3C0 * parameter; no prototype here so the types agree */
s32 func_L39_0068B3C0();
extern void func_L39_00689A90(void);

s32 func_L39_0068AEF8(S0_68AEF8 *a, s32 b) {
    func_L39_0068B3C0(a);
    func_L39_00689A90();
    if (a->unk290 >= 0) {
        S1_68AEF8 *o = a->unk110[a->unk290];
        if (o->vt[5](o, b) == 1) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0068AEF8 */

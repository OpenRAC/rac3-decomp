#include "common.h"

/* NTSC-U counterpart of func_L09_003CCB50 (src/levels/09_tyhrranosis/L09_003CBEC0.c): 0.1 -> 0.0833333 */
/* localdecomp:start func_L09_003CB0A0 */
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L09_003CB150(void *, s32, f32, f32, f32, f32);
extern void func_003C2880(void *);
void func_L09_003CB0A0(u8 *a0) {
    switch (a0[0x20]) {
    case 0:
        break;
    case 1:
        if (func_L01_00444358(a0, 0x8010000, 0) != 0) {
            func_L01_00441FB8(a0, 2, -1);
        }
        a0[0xA8] = 0xFF;
        break;
    case 2:
        func_L09_003CB150(a0, 0x3C, 0.4f, 10.0f, 10.0f, 0.0833333358f);
        func_003C2880(a0);
        break;
    }
}
/* localdecomp:end func_L09_003CB0A0 */

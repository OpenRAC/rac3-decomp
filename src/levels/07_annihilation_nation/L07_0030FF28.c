#include "common.h"

/* localdecomp:start func_L07_0030FF28 */
s32 func_0038CAD0(void *);
void func_003C2880(void *);
void func_L01_00404808(void *, void *);
void func_L01_004AA760(s32, void *);
void func_L07_00310160(void *, void *);
extern u8 D_L07_00310558[];

void func_L07_0030FF28(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    *(f32 *)((u8 *)temp_s0 + 0x78) = (f32) ((*(f32 *)((u8 *)temp_s0 + 0x78)) + 1.0f);
    if (((*(s32 *)((u8 *)temp_s0 + 0x74)) != 0) && (func_0038CAD0(temp_s0 + 0x74) != 0)) {
        func_L01_004AA760(0x10, arg0);
        func_003C2880(arg0);
        return;
    }
    if (((*(f32 *)((u8 *)temp_s0 + 0x78)) > 120.0f) && ((*(s32 *)((u8 *)temp_s0 + 0x74)) == 0)) {
        *(s32 *)((u8 *)temp_s0 + 0x74) = 0xC;
    } else {
        func_L07_00310160(arg0, temp_s0);
    }
    func_L01_00404808(D_L07_00310558, arg0);
}
/* localdecomp:end func_L07_0030FF28 */

INCLUDE_ASM("asm/levels", func_L07_0030FFE8);

INCLUDE_ASM("asm/levels", func_L07_00310160);

INCLUDE_ASM("asm/levels", func_L07_00310558);

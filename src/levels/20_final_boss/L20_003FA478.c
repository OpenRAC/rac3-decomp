#include "common.h"

INCLUDE_ASM("asm/levels", func_L20_003FA478);

INCLUDE_ASM("asm/levels", func_L20_003FACD8);

INCLUDE_ASM("asm/levels", func_L20_003FAF10);

/* localdecomp:start func_L20_003FB120 */
void func_003C2880(s32);
void func_L01_004443E8(void *, s32, s32);
s32 func_L01_004AAC98(s32, s32, s32, s32);

void func_L20_003FB120(void *arg0) {
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    func_L01_004AAC98(0, 0, arg0, 0x1E00);
    func_003C2880((*(s32 *)((u8 *)temp_s1 + 0x2EC)));
    *(s32 *)((u8 *)temp_s1 + 0x240) = 0;
    func_L01_004443E8(arg0, 0, 3);
}
/* localdecomp:end func_L20_003FB120 */

/* localdecomp:start func_L20_003FB180 */
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);

void func_L20_003FB180(u8 *arg0) {
    u8 *temp_s1;
    u32 v;

    temp_s1 = *(u8 **)(arg0 + 0x68);
    func_0038CAD0(temp_s1 + 0x2E0);
    func_0038CB00(temp_s1 + 0x2E4);
    v = *(u16 *)(arg0 + 0x96);
    if (v <= 0xFFFE) {
        *(u16 *)(arg0 + 0x96) = v + 1;
    }
    func_L01_00451DF8(arg0, temp_s1 + 0x250, 0, 1, 2.5f);
}
/* localdecomp:end func_L20_003FB180 */

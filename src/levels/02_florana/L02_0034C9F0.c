#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_0034C9F0);

INCLUDE_ASM("asm/levels", func_L02_0034CB58);

INCLUDE_ASM("asm/levels", func_L02_0034F710);

INCLUDE_ASM("asm/levels", func_L02_0034F958);

/* localdecomp:start func_L02_0034FC40 */
void func_L01_004443E8(s32, s32, s32);
void func_L01_00315900(s32, s32, s32);

void func_L02_0034FC40(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_L01_004443E8((s32) arg0, 0, 3);
    func_L01_00315900((*(s32 *)((u8 *)temp_s0 + 0x2EC)), 0, 0);
    *(s32 *)((u8 *)temp_s0 + 0x2EC) = 0;
}
/* localdecomp:end func_L02_0034FC40 */

/* localdecomp:start func_L02_0034FC88 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L02_00350200(void *, s32);
extern u8 D_L02_001E1300[];

void func_L02_0034FC88(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 value;

    func_0038CAD0(p + 0x2D0);
    func_0038CB00(p + 0x2D4);
    value = *(u16 *)(a0 + 0x96);
    if (value <= 0xFFFEu) {
        *(u16 *)(a0 + 0x96) = value + 1;
    }
    func_L01_00451DF8(a0, p + 0x240, 2, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L02_001E1300, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
    if (a0[0x20] != 3) {
        func_L02_00350200(a0, 1);
    }
}
/* localdecomp:end func_L02_0034FC88 */

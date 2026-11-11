#include "common.h"

INCLUDE_ASM("asm/levels", func_L11_003A8FE0);

INCLUDE_ASM("asm/levels", func_L11_003A9260);

INCLUDE_ASM("asm/levels", func_L11_003A9860);

INCLUDE_ASM("asm/levels", func_L11_003A9B30);

/* localdecomp:start func_L11_003A9CB0 */
__asm__(".extern D_L11_001D66B0, 16");
extern u8 D_L11_001D66B0;
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004443E8(void *, s32, s32);

void func_L11_003A9CB0(u8 *a0)
{
    func_L01_00451FE0(a0, 0x3FFF, &D_L11_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    func_003A52A0(0, 0, a0);
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L11_003A9CB0 */

/* localdecomp:start func_L11_003A9D50 */
void func_0038CAD0(s32);
void func_0038CB00(s32);

void func_L11_003A9D50(void *arg0) {
    s32 temp_s0;
    u16 temp_v1;

    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    func_0038CAD0(temp_s0 + 0x2D0);
    func_0038CB00(temp_s0 + 0x2D4);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L11_003A9D50 */

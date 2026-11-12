#include "common.h"

INCLUDE_ASM("asm/levels", func_L14_0035DBA8);

/* localdecomp:start func_L14_0035DE68 */
void func_L14_0035DBA8(s32);
void func_L01_004450F0(void *, s32, s32);

void func_L14_0035DE68(void *arg0, void *arg1) {
    f32 *temp_v0;
    f32 temp_f0;

    temp_v0 = *(f32 **)((u8 *)arg0 + 0x68);
    temp_f0 = *temp_v0 - (*(f32 *)((u8 *)arg1 + 0x2C));
    *temp_v0 = temp_f0;
    if ((temp_f0 > 0.0f) && ((*(u16 *)((u8 *)arg0 + 0x7C)) != 0)) {
        func_L14_0035DBA8((s32) arg0);
        return;
    }
    *(u16 *)((u8 *)arg0 + 0x7C) = 0U;
    func_L01_004450F0(arg0, 3, -1);
}
/* localdecomp:end func_L14_0035DE68 */

/* localdecomp:start func_L14_0035DED8 */
void func_L14_0035D670(u8 *a0, s32 a1);
void func_L14_0035DE68(void *a0, void *a1);
void func_L01_00439880(u8 *a0, u16 *a1, s32 *a2);
void func_L01_004450F0(void *a0, s32 a1, s32 a2);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_0038CAD0(void *);
void func_L14_0035DED8(u8 *a0) {
    u16 tmp;
    s32 tmp2;
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 p;
    switch (a0[0x20]) {
    case 0:
        func_L01_00439880(a0, &tmp, &tmp2);
        *(u16 *)(a0 + 0x7C) = tmp;
        *(f32 *)s = *(s32 *)(s + 0x40);
        *(u16 *)(s + 4) = *(u16 *)(s + 0x40);
        *(u16 *)(s + 0x36) = tmp2;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        p = func_L01_00447490(a0, 1, 1);
        if (p != 0) {
            func_L14_0035DE68(a0, (void *)p);
        }
        break;
    case 2:
        func_L14_0035D670(a0, *(s32 *)(s + 0x48));
        if (func_0038CAD0(s + 0x44) != 0) {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    }
    a0[0xA8] = 0xFF;
}
/* localdecomp:end func_L14_0035DED8 */

/* localdecomp:start func_L14_0035DFE0 */
extern u8 D_L14_001D66B0;
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00429840(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
void func_L14_0035DFE0(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0xF, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L01_00429840(a0, a0 + 0x10, 5, 0, &D_L14_001D66B0, 0x463C5028, 0, 0xD0, 4.0f, 8.0f, 1.5f, 2.5f);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_0035DFE0 */

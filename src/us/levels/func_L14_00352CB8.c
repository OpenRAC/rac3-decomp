#include "common.h"

/* NTSC-U counterpart of func_L14_00353CD0 (src/levels/14_koros/L14_00353718.c): 125 -> 150 */
extern u8 D_L14_001D66B0_00352CB8;
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L02_00426140(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003C2880(void *);
extern u8 D_L14_001D66B0_00352CB8;
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L02_00426140(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003C2880(void *);

/* localdecomp:start func_L14_00352CB8 */
extern u8 D_L14_001D66B0_00352CB8;
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L02_00426140(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003C2880(void *);
void func_L14_00352CB8(u8 *a0) {
    if (func_L01_00444358(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_0044ED60(a0, 7, &D_L14_001D66B0_00352CB8, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L02_00426140(a0, a0 + 0x10, 5, 0, &D_L14_001D66B0_00352CB8, 0x963C6428, 0, 0x96, 2.0f, 10.0f, 1.5f, 2.0f);
        func_L01_0044EBF8(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_00352CB8 */

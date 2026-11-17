#include "common.h"

/* NTSC-U counterpart of func_L07_003E3220 (src/levels/07_annihilation_nation/L07_003E2B80.c) */
extern s32 D_L07_001E18B8_003E1430;
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L07_003E1430 */
#include "vu0.h"
extern s32 D_L07_001E18B8_003E1430;
__asm__(".extern D_L07_001E18B8_003E1430, 4");
void func_L07_003E1430(u8 *arg0) {
    extern f32 func_00389410(f32);
    extern s32 func_003883C8(void *);
    extern s32 func_L01_003F9498(void *, s32, void *, f32);
    extern void func_L01_00456960(s32);
    extern void func_00388830(void *, void *, f32);
    extern void func_L03_0043C598(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern s32 func_0039FE80(s32, s32, void *);
    extern void func_L01_0044EBF8(void *, s32, f32);
    extern void func_003BD360(void *);
    u8 *p = *(u8 **)(arg0 + 0x68);
    vu0_v4 temp;
    vu0_v4 *position = (vu0_v4 *)(arg0 + 0x10);
    vu0_v4 *velocity = (vu0_v4 *)(p + 0x220);
    *(f32 *)(arg0 + 0xF4) = func_00389410(*(f32 *)(arg0 + 0xF4) - 0.3f);
    *(f32 *)(p + 0x228) -= 0.0041666668839752674f;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*position) : "m"(*position), "m"(*velocity) : "vf1", "vf2");
    if (func_003883C8(p + 0x25C) || func_L01_003F9498(position, 0, arg0, *(f32 *)(p + 0x30))) {
        D_L07_001E18B8_003E1430++;
        if (D_L07_001E18B8_003E1430 >= 5) func_L01_00456960(11);
        func_00388830(&temp, velocity, 0.083333335816860199f);
        func_L03_0043C598(arg0, 31, &temp, 5, 2, 255, 180, 0, 5.0f, 8.0f, 4.0f, 7.0f, -1.0f, -1.0f, 1.0f);
        func_0039FE80(0, 0, arg0);
        func_L01_0044EBF8(arg0, 1, 0.0f);
        func_003BD360(arg0);
    }
}
/* localdecomp:end func_L07_003E1430 */

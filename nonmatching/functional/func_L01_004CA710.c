/* functional: high. 101 diff words are scheduling/regalloc; loop count 6, colour sets, gp floats and VU0 adds checked vs asm */
#include "common.h"
/* localdecomp:start func_L01_004CA710 */
#include "vu0.h"
extern Vec4_004C4AD8 D_L01_001E29C0[];
extern s16 D_L01_001E1100 __attribute__((section(".data")));
__asm__(".extern D_L01_001E1100, 16");
extern f32 D_L01_001DB02C, D_L01_001DB030, D_L01_001DB034, D_L01_001DB038;
__asm__(".extern D_L01_001DB02C, 4");
__asm__(".extern D_L01_001DB030, 4");
__asm__(".extern D_L01_001DB034, 4");
__asm__(".extern D_L01_001DB038, 4");
void func_L01_004CA710(void) {
    extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern void func_L01_00443B88(void *, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_0031C1D0(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32);
    Vec4_004C4AD8 temp, start, end, offset;
    s32 i;
    i=5; do {
        func_0038CE20(&temp, &D_L01_001E29C0[2], 9.0f);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(start) : "m"(temp), "m"(D_L01_001E29C0[0]) : "vf1", "vf2");
        func_L01_00443B88(&end, 0.1f, 3.0f);
        func_0038CE20(&temp, &D_L01_001E29C0[2], 3.0f);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(offset) : "m"(temp), "m"(D_L01_001E29C0[0]) : "vf1", "vf2");
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(end) : "m"(offset), "m"(end) : "vf1", "vf2");
        if (D_L01_001E1100>=3) {
            func_L01_0031C1D0(&start,&end,(func_00382498(8,12)*5+2)/6,D_L01_001DB02C,D_L01_001DB030,D_L01_001DB034,D_L01_001DB038,0x808080,0x808080,0xFF105F,0x1010FF,0x1010FF);
        } else {
            func_L01_0031C1D0(&start,&end,(func_00382498(8,12)*5+2)/6,D_L01_001DB02C,D_L01_001DB030,D_L01_001DB034,D_L01_001DB038,0x808080,0x808080,0x5F10FF,0xFF1010,0xFF1010);
        }
    } while (--i >= 0);
}
/* localdecomp:end func_L01_004CA710 */

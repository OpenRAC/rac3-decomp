#include "common.h"

/* NTSC-U counterpart of func_L02_0034C858 (src/levels/02_florana/L02_003484D8.c): 0.0432 -> 0.03; 0.432 -> 0.3 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L02_0034B878(void *);
void func_003C7C38(void *);

/* localdecomp:start func_L02_0034B878 */
s32 func_0038CAD0(void *);
s32 func_0038CB00(void *);
void func_L01_0044B5C8(void *, void *, s32, f32, f32);
void func_L01_0044EB78(void *, void *, s32, s32, f32);
void func_003C7C38(void *);

void func_L02_0034B878(void *arg0) {
    u8 *temp_s0 = *(u8 **)((u8 *)arg0 + 0x68);
    void *temp_v0;
    func_0038CAD0(temp_s0 + 0x2D0);
    func_0038CB00(temp_s0 + 0x2D4);
    if (*(u16 *)((u8 *)arg0 + 0x96) < 0xFFFF) {
        *(u16 *)((u8 *)arg0 + 0x96) = *(u16 *)((u8 *)arg0 + 0x96) + 1;
    }
    func_L01_0044B5C8(arg0, temp_s0 + 0x970, 2, 0.0299999993f, 0.300000012f);
    func_L01_0044B5C8(arg0, temp_s0 + 0x8F0, 1, 0.0299999993f, 0.300000012f);
    func_L01_0044EB78(arg0, temp_s0 + 0x240, 2, 1, 2.5f);
    temp_v0 = *(void **)(temp_s0 + 0xB14);
    if (temp_v0 != 0) {
        *(s32 *)((u8 *)temp_v0 + 0x98) = 0;
        func_003C7C38(*(void **)(temp_s0 + 0xB14));
    }
}
/* localdecomp:end func_L02_0034B878 */

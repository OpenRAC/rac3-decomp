/* near miss (level 26: one extra instruction, 96 diff) */
#include "common.h"

/* localdecomp:start func_L26_003E5330 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3E5330;
typedef struct {
    char _p0[0x44];
    u8 f44;
} A_3E5330;

extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_003C2F58(void *, s32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004443E8(void *, s32, s32);
extern s32 func_L26_003E54F8(void *, s32);
extern u8 D_001D6700[];

s32 func_L26_003E5330(void *a0, s32 a1_) {
    A_3E5330 *a1 = (A_3E5330 *)a1_;
    V4_3E5330 v;
    s32 r;

    r = func_L01_00452FB0(a0, (u8 *)a1 + 0x70, 0, 0, 0);
    if ((u32)(r - 4) < 2) {
        func_003C2F58(a0, 0);
        func_L01_00451FE0(a0, 0x3FFF, D_001D6700, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L01_003303B8((u8 *)&v, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 4, 2.5f, 30.0f, (f32)a1->f44, 15.0f,
                          0, 1, 1, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003A52A0(0, 0, a0);
        func_L01_004443E8(a0, 0, 3);
        func_L26_003E54F8(a0, 1);
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L26_003E5330 */

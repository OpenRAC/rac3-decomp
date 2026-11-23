#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L05_00355098 (src/levels/05_daxx/L05_00355098.c): 60 Hz vec.z 0.1f (PAL 0.12f), NTSC-U level data addresses */
/* localdecomp:start func_L05_003540C0 */

typedef struct {
    f32 x, y, z, w;
} V_003540C0;

extern u8 *D_001DFC1C_sda;
__asm__(".extern D_001DFC1C_sda, 4");
extern s32 D_L05_001DF740;
extern u8 D_L05_001D9B20[] __attribute__((section(".sdata")));
extern u8 D_001A4C60[];

extern s32 func_L01_00452F60(void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_00447D00(void *, void *, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00452F40(void *, s32);
extern void func_003BD360(void *);
extern f32 func_00388800(void *, void *);

void func_L05_003540C0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    V_003540C0 vec __attribute__((aligned(16)));
    s32 id;

    if (a0[0x20] == 0) {
        *(s32 *)(v + 0x6C) |= 1;
        a0[0x20] = 1;
    }
    if (func_L01_00452F60(a0) != 0) {
        qzero(&vec);
        vec.z = 0.100000009f;
        func_L01_0044ED60(a0, 0x3F, &vec, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_00447D00(a0, D_L05_001D9B20, 0, 0.5f, 1.0f, 5.0f, 2.5f, 9.0f, 1.5f, 15.0f, 10, 3, 0x10, -1, 1, 1, -1, 0, 0x01010001);
        func_0039FE80(0, 0, a0);
        id = *(s32 *)(v + 0x70);
        if (id != -1) {
            func_L01_00452F40(D_001DFC1C_sda + (id << 8), 1);
        }
        func_003BD360(a0);
    } else if (*(f32 *)(v + 0x74) != 0.0f) {
        if (a0[0xBC] == 0 && (D_L05_001DF740 & 7) == (((s32)a0 >> 8) & 7)) {
            if (func_00388800(D_001A4C60, a0 + 0x10) < *(f32 *)(v + 0x74)) {
                a0[0xBC] = v[0x78];
            }
        }
    }
}
/* localdecomp:end func_L05_003540C0 */

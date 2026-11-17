#include "common.h"

/* localdecomp:start func_L05_00355098 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} V_00355098;

extern u8 *D_001DFB9C_sda;
__asm__(".extern D_001DFB9C_sda, 4");
extern s32 D_L05_001DF6C0;
extern u8 D_L05_001D9AE0[] __attribute__((section(".sdata")));
extern u8 D_001A4C60[];

extern s32 func_L01_00456250(void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00456230(void *, s32);
extern void func_003C2880(void *);
extern f32 func_0038CF38(void *, void *);

void func_L05_00355098(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    V_00355098 vec __attribute__((aligned(16)));
    s32 id;

    if (a0[0x20] == 0) {
        *(s32 *)(v + 0x6C) |= 1;
        a0[0x20] = 1;
    }
    if (func_L01_00456250(a0) != 0) {
        qzero(&vec);
        vec.z = 0.120000005f;
        func_L01_00451FE0(a0, 0x3F, &vec, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_0044AF78(a0, D_L05_001D9AE0, 0, 0.5f, 1.0f, 5.0f, 2.5f, 9.0f, 1.5f, 15.0f, 10, 3, 0x10, -1, 1, 1, -1, 0, 0x01010001);
        func_003A52A0(0, 0, a0);
        id = *(s32 *)(v + 0x70);
        if (id != -1) {
            func_L01_00456230(D_001DFB9C_sda + (id << 8), 1);
        }
        func_003C2880(a0);
    } else if (*(f32 *)(v + 0x74) != 0.0f) {
        if (a0[0xBC] == 0 && (D_L05_001DF6C0 & 7) == (((s32)a0 >> 8) & 7)) {
            if (func_0038CF38(D_001A4C60, a0 + 0x10) < *(f32 *)(v + 0x74)) {
                a0[0xBC] = v[0x78];
            }
        }
    }
}
/* localdecomp:end func_L05_00355098 */

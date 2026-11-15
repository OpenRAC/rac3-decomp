#include "common.h"

/* localdecomp:start func_L16_003DE7E8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003DE7E8;
extern f32 D_L16_001DF2D8;
__asm__(".extern D_L16_001DF2D8, 4");
extern f32 D_L16_001DF2DC;
__asm__(".extern D_L16_001DF2DC, 4");
extern f32 D_L16_001DF2E0;
__asm__(".extern D_L16_001DF2E0, 4");
extern f32 D_L16_001DF2E4;
__asm__(".extern D_L16_001DF2E4, 4");
extern f32 D_L16_001DF2E8;
__asm__(".extern D_L16_001DF2E8, 4");
extern f32 D_L16_001DF2EC;
__asm__(".extern D_L16_001DF2EC, 4");
extern u32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L16_003DD860(void *, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L16_003E8DC0(void *, void *, void *, s32, f32, f32, f32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);

static __inline__ void sound_003DE7E8(s32 *n) {
    switch (D_001D545C) {
    case 0x401:
        *n = 0x6E;
        break;
    case 0x10:
        *n = 0x6C;
        break;
    }
}

void func_L16_003DE7E8(u8 *self) {
    s32 *m = *(s32 **)(self + 0x68);
    s32 n;

    switch (self[0x20]) {
    case 0:
        if (func_L01_004561B8(self) != 0) {
            *m = 0;
        }
        if (func_L01_00447490(self, -1, 0) == 0) {
            break;
        }
        func_L16_003DD860(self, 1.3f, 1.0f);
        {
        V4_003DE7E8 a = (V4_003DE7E8){ D_L16_001DF2D8, D_L16_001DF2DC, D_L16_001DF2E0 };
        V4_003DE7E8 b = (V4_003DE7E8){ D_L16_001DF2E4, D_L16_001DF2E8, D_L16_001DF2EC };
        func_0038CF68(&a, &a, 1.0f);
        sound_003DE7E8(&n);
        func_L16_003E8DC0(self + 0x10, &b, &a, n, 5.0f, 0.0f, 35.0f, 0x8EF3F4);
        }
        func_L01_004450F0(self, 1, -1);
        break;
    case 1:
        func_003C2880(self);
        break;
    }
}
/* localdecomp:end func_L16_003DE7E8 */

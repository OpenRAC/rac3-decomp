#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L19_0030D130 (src/levels/shared/L19_0030D130.c): velocity.z 0.05 where PAL has 0.06, the D_L19_001DC5xx data 0x40 higher */
/* localdecomp:start func_L19_0030CDE8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0030CDE8;

extern s32 D_L19_001DF720[] __attribute__((section(".sdata")));
extern s32 D_L19_001DF240[] __attribute__((section(".sdata")));
extern s32 D_L19_001DC60C[] __attribute__((section(".sdata")));
__asm__(".extern D_L19_001DC608_0030CDE8, 4");
extern s32 D_L19_001DC608_0030CDE8;
__asm__(".extern D_L19_001DC610_0030CDE8, 2");
extern u16 D_L19_001DC610_0030CDE8;
__asm__(".extern D_L19_001DC614, 2");
extern u16 D_L19_001DC614;
__asm__(".extern D_L19_001DC618, 4");
extern s32 D_L19_001DC618;
__asm__(".extern D_L19_001DC61C, 4");
extern f32 D_L19_001DC61C;
__asm__(".extern D_L19_001DC620, 4");
extern f32 D_L19_001DC620;
__asm__(".extern D_L19_001DC624, 4");
extern f32 D_L19_001DC624;
__asm__(".extern D_L19_001DC628, 4");
extern f32 D_L19_001DC628;
extern u8 D_L19_001D66F0[] __attribute__((section(".sdata")));

void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00402498(void *, void *);
void func_L19_0030D040(void *);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L02_00426140(void *, void *, s32, s32, void *, f32, f32, f32, f32, s32, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00452F40(void *, s32);

void func_L19_0030CDE8(u8 *object) {
    V4_0030CDE8 offset, velocity;

    switch (object[0x20]) {
    case 0:
        if ((s32)object < D_L19_001DF720[0]) {
            *(s32 *)(object + 0x9C) = 15;
            func_L01_00441FB8(object, 3, -1);
        } else {
            *(u16 *)(object + 0x7C) = D_L19_001DC610_0030CDE8;
            func_L01_00441FB8(object, 1, -1);
        }
        break;
    case 1:
        if (object[0x31]) {
            func_L01_00402498(func_L19_0030D040, object);
            *(s32 *)(object + 0x78) = func_003894A0(D_L19_001DC608_0030CDE8, D_L19_001DC60C[0],
                (func_00388978((f32)(D_L19_001DF240[0] % 150) / 150.0f * 6.28318f - 3.14159f) + 1.0f) * 0.5f);
        }
        if (func_L01_00444358(object, 0x10000, 0)) {
            *(u128_t *)&offset = 0;
            *(u128_t *)&velocity = 0;
            offset.z = 0.5f;
            velocity.z = 0.050000004f;
            vec_add_ba(&offset, &offset, object + 0x10);
            func_L02_00426140(object, &offset, 5, 1, &velocity, 0.333f, 3.0f, 0.5f, 1.0f, 0x504040C0, 0, 180);
            func_L01_0044ED60(object, D_L19_001DC618, D_L19_001D66F0, 255, 180, 0, 0, 35, 0, 3,
                D_L19_001DC61C, D_L19_001DC620, D_L19_001DC624, D_L19_001DC628, -1.0f, -1.0f, 1.0f, 1.0f);
            func_0039FE80(0, 0, object);
            *(u16 *)(object + 0x7C) = D_L19_001DC614;
            func_L01_00452F40(object, 1);
            *(s32 *)(object + 0x9C) = 15;
            *(u16 *)(object + 0x34) |= 2;
            func_L01_00441FB8(object, 2, -1);
        }
        break;
    }
}
/* localdecomp:end func_L19_0030CDE8 */

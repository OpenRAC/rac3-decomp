#include "common.h"

INCLUDE_ASM("asm/levels", func_L08_003BD8A0);

INCLUDE_ASM("asm/levels", func_L08_003BDA50);

/* localdecomp:start func_L08_003BDBB8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003BDBB8;
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L08_003BD8A0(void *, s32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L08_003BDA50(void *, f32, f32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L01_00452460(void *, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(u8 *);
extern s32 D_L08_001D66B0;
extern s32 D_L08_001DE7C8[] __attribute__((section(".sdata"))); __asm__(".extern D_L08_001DE7C8, 4");

void func_L08_003BDBB8(u8 *a) {
    s32 i;
    V4_003BDBB8 v;
    f32 t;

    switch (a[0x20]) {
    case 0:
        if (func_L01_00447490(a, -1, 0) != 0) {
            func_L01_004450F0(a, 1, -1);
        }
        break;
    case 1:
        (*(u16 *)(a + 0x96))++;
        for (i = 0; i < 6; i++) {
            if (*(u16 *)(a + 0x96) == D_L08_001DE7C8[i]) {
                func_L08_003BD8A0(a, *(u16 *)(a + 0x96));
            }
        }
        if (*(u16 *)(a + 0x96) == 45) {
            func_L01_004450F0(a, 2, -1);
        }
        break;
    case 2:
        func_L01_00451FE0(a, 0x1FF, &D_L08_001D66B0, 0xFF, 0x3C, 0, 0, 0x23, 0, 3, 1.0f, 3.0f, 1.0f, 3.0f, 8.0f, 20.0f, 1.0f, 1.0f);
        t = *(f32 *)(a + 0x2C) / *(f32 *)(*(u8 **)(a + 0x24) + 0x24);
        v = *(V4_003BDBB8 *)(a + 0x10);
        v.z += t * -2.2f;
        func_L01_003303B8(&v, 1, 0, 0, 0, 3, 5, 3, t * 0.5f, 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 1, 1, 0x1000000, 0, 0x40707F, 0x7F3020, 0x207F20, 0x707F30, 0, 0, 0x7F60A0FF, 0x280000FF, 0x204050, 0);
        func_L08_003BDA50(a, 1.2f, -1.5f);
        func_003A52A0(0, 0, a);
        func_L01_00452460(a, 0x1CBB, 0);
        func_L01_00451E78(a, 1, 0.0f);
        func_003C2880(a);
        break;
    }
}
/* localdecomp:end func_L08_003BDBB8 */

INCLUDE_ASM("asm/levels", func_L08_003BDE60);

/* localdecomp:start func_L08_003BDFB8 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L01_00452460(void *, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(u8 *);
extern void func_L08_003BDE60(void *, f32, f32);
extern s32 D_L08_001D66B0;

void func_L08_003BDFB8(void *arg0) {
    if (func_L01_00447490(arg0, -1, 0) != 0) {
        func_L01_00451FE0(arg0, 1, &D_L08_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L08_003BDE60(arg0, 0.7f, -2.3f);
        func_003A52A0(0, 0, arg0);
        func_L01_00452460(arg0, 0x1E90, 0);
        func_L01_00451E78(arg0, 1, 0.0f);
        func_003C2880(arg0);
    }
}
/* localdecomp:end func_L08_003BDFB8 */

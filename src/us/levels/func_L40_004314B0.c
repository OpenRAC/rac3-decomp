#include "common.h"

/* localdecomp:start func_L40_004314B0 */
extern s16 D_001DC33C_sda;
__asm__(".extern D_001DC33C_sda, 2");
extern s16 D_001DC340_sda;
__asm__(".extern D_001DC340_sda, 2");
extern s16 D_001DC344_sda;
__asm__(".extern D_001DC344_sda, 2");
extern s16 D_001DC334_sda;
__asm__(".extern D_001DC334_sda, 2");
extern f32 D_001DC320_sda_004314B0;
__asm__(".extern D_001DC320_sda_004314B0, 4");
extern s32 D_001DC324_sda_004314B0;
__asm__(".extern D_001DC324_sda_004314B0, 4");
extern s32 D_001DC328_sda_004314B0;
__asm__(".extern D_001DC328_sda_004314B0, 4");
extern s32 D_001DC32C_sda_004314B0;
__asm__(".extern D_001DC32C_sda_004314B0, 4");
extern s32 D_001DC330_sda_004314B0;
__asm__(".extern D_001DC330_sda_004314B0, 4");
extern f32 D_001DC31C_sda;
__asm__(".extern D_001DC31C_sda, 4");

extern void func_L40_004316B0(void);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L01_00402498(void (*)(void), u8 *);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_003EBE40_004314B0(u8 *);
extern void func_003BD360(u8 *);
extern void func_L01_0032FE90(u8 *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L40_004314B0(u8 *obj) {
    u8 state = obj[0x20];
    u8 *s = *(u8 **)(obj + 0x68);

    switch (state) {
    case 0:
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        func_L01_00402498(func_L40_004316B0, obj);
        func_003BEBF8((f32 *)(s + 0x4C), 1.0f, *(f32 *)(s + 0x5C));
        if (1.0f <= *(f32 *)(s + 0x4C)) {
            func_L01_00441FB8(obj, 2, -1);
            func_L01_0032FE90(s + 0x20, D_001DC320_sda_004314B0, 0, D_001DC324_sda_004314B0, D_001DC328_sda_004314B0, D_001DC32C_sda_004314B0, D_001DC330_sda_004314B0,
                              D_001DC334_sda, 2, 0.0f, 0.0f, 2.0f,
                              0, D_001DC33C_sda, D_001DC340_sda, D_001DC344_sda, 1, 0, 0, *(s32 *)(s + 0x44),
                              0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
        break;
    case 2:
        if (*(f32 *)(s + 0x58) < 1.0f) {
            func_L01_003EBE40_004314B0(obj);
            func_003BEBF8((f32 *)(s + 0x58), 1.0f, D_001DC31C_sda * 0.016666668f);
        } else {
            func_003BD360(obj);
        }
        break;
    }
}
/* localdecomp:end func_L40_004314B0 */

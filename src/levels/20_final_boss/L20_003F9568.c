#include "common.h"

INCLUDE_ASM("asm/levels", func_L20_003F9568);

/* localdecomp:start func_L20_003F9C10 */
typedef struct {
    u8 b[16];
} __attribute__((aligned(16))) Q16;

typedef struct {
    Q16 a;
    Q16 b;
} __attribute__((aligned(16))) Q32;

extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_004AA7E8(u8 *, s32);

u8 *func_L20_003F9C10(u8 *self, Q16 *src1, Q16 *src2, f32 f) {
    Q32 tmp;
    u8 *obj;
    u8 *sub;

    tmp.a = *src1;
    tmp.b = *src2;
    obj = func_003C24B0(0x1DF8, 0x20);
    if (obj != 0) {
        sub = *(u8 **)(obj + 0x68);
        func_L01_00456160(obj, self);
        *(Q16 *)(obj + 0x10) = tmp.b;
        *(s16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(obj + 0x98) = 0;
        *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + 1.0f;
        func_L01_004AA7E8(obj, 1);
        *(Q16 *)(sub + 0x10) = tmp.a;
        *(f32 *)(sub + 4) = f;
        *(f32 *)(sub + 0) = 0.35f;
    }
    return obj;
}
/* localdecomp:end func_L20_003F9C10 */

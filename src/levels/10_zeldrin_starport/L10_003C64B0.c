#include "common.h"

/* localdecomp:start func_L10_003C64B0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C64B0;
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D328(void *, void *);
extern s32 func_00382498(s32, s32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern void func_003C7C38(u8 *);

u8 *func_L10_003C64B0(u8 *src, s32 cls, s32 a2) {
    V4_3C64B0 m[2];
    V4_3C64B0 t[2];
    u8 *o;
    f32 a;

    o = func_003C24B0(cls, 0x80);
    if (o != 0) {
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        *(f32 *)(o + 0x2C) = *(f32 *)(o + 0x2C) * (*(f32 *)(src + 0x2C) / *(f32 *)(*(u8 **)(src + 0x24) + 0x24));
        *(V4_3C64B0 *)(o + 0x10) = *(V4_3C64B0 *)(src + 0x10);
        func_0038D328(m, src + 0xF0);
        a = (f32)func_00382498(0, 7) * 3.1415927f * 0.25f;
        func_0038D890(&m[0], &m[0], t, a);
        func_0038D890(&m[1], &m[1], t, a);
        func_003C48A8(m, o + 0xF0);
        *(unsigned long *)(o + 0x38) = *(unsigned long *)(src + 0x38);
        o[0x30] = a2;
        *(s16 *)(o + 0x34) = 0;
        func_003C7C38(o);
        return o;
    }
    return 0;
}
/* localdecomp:end func_L10_003C64B0 */

INCLUDE_ASM("asm/levels", func_L10_003C65D8);

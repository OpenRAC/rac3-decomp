#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

/* localdecomp:start func_L23_00309798 */
extern u8 *func_003C24B0(s32, s32);
extern s32 func_L01_00424B88(void *, s32, f32, f32);
extern u8 *D_L23_001DC5F4;
extern u8 D_L23_001D6160;
extern s32 D_L23_001D6164;
extern long D_L23_001D6168;
extern u8 D_L23_001D6170;
extern s32 D_L23_001D6174;
extern long D_L23_001D6178;
__asm__(".extern D_L23_001DC5F4, 4");
__asm__(".extern D_L23_001D6160, 16");
__asm__(".extern D_L23_001D6164, 16");
__asm__(".extern D_L23_001D6168, 16");
__asm__(".extern D_L23_001D6170, 16");
__asm__(".extern D_L23_001D6174, 16");
__asm__(".extern D_L23_001D6178, 16");
u8 *func_L23_00309798(u8 *owner, u128_t *pos) {
    u8 *o = func_003C24B0(0x5F3, 0x80);
    u8 *x;
    if (o != 0 && D_L23_001DC5F4 == 0) {
        *(u8 **)(o + 0xB8) = owner;
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        o[0x20] = 0;
        x = *(u8 **)(o + 0x68);
        *(u128_t *)(o + 0x10) = *pos;
        D_L23_001D6164 = 0xFF;
        D_L23_001D6174 = 0xFFFFFF;
        D_L23_001D6178 = 0x1F00000042L;
        D_L23_001DC5F4 = o;
        D_L23_001D6168 = 0;
        D_L23_001D6160 = 0;
        D_L23_001D6170 = 0;
        *(s32 *)(x + 0x10) = 0;
        *(s16 *)(x + 0x2C) = func_L01_00424B88(pos, 0, 0.0f, 0.0f);
    }
    return o;
}
/* localdecomp:end func_L23_00309798 */

/* localdecomp:start func_L23_00309888 */
__asm__(".extern D_L23_001DC5F4, 4");

void func_L23_00309888(u8 *owner, V4 pos, s32 id) {
    u8 *o;
    u8 *v;
    if (D_L23_001DC5F4 == 0) {
        func_L23_00309798(owner, (u128_t *)&pos);
        if (D_L23_001DC5F4 == 0) {
            return;
        }
        o = D_L23_001DC5F4;
        v = *(u8 **)(o + 0x68);
        if (*(s16 *)(o + 0xAA) != 0x5F3) {
            return;
        }
        *(s16 *)(v + 0x40) = id;
    }
    o = D_L23_001DC5F4;
    v = *(u8 **)(o + 0x68);
    *(V4 *)(o + 0x10) = pos;
    *(s16 *)(v + 0x2E) = 1;
}
/* localdecomp:end func_L23_00309888 */

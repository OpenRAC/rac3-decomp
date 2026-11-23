#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_L01_004618E0(s32);
extern f32 func_00382538(void);
extern s32 func_00382468(s32);
extern s32 D_L23_001D7F50;
extern f32 D_L23_001D7F5C;
__asm__(".extern D_L23_001D7F50, 4");
__asm__(".extern D_L23_001D7F5C, 4");
extern u8 *D_L23_0021EF44 __attribute__((section(".data")));

/* localdecomp:start func_L23_00456AA8 */
void *func_L23_00456AA8(V4 *a0, V4 *a1, f32 s, s32 a2, s32 a3, s32 a4) {
    u8 *p = func_L01_004618E0(0x7B);
    u8 *data;
    if (p) {
        data = p + 0x20;
        *(u128_t *)(p + 0x20) = *(u128_t *)a1;
        *(f32 *)(data + 0x18) = s * 210000.0f;
        data[0x15] = a2;
        data[0x16] = a3;
        data[0x17] = a4;
        data[0x14] = 0;
        *(s16 *)(data + 0x12) = *(s16 *)(data + 0x10) = data[0x15];
        *(u128_t *)(p + 0x10) = *(u128_t *)a0;
        *(s32 *)(p + 4) = D_L23_001D7F50;
        p[1] = 0;
        p[9] = 0x44;
        p[3] = 0x48;
        p[8] = (s32)(func_00382538() * 256.0f);
        p[2] = D_L23_0021EF44[func_00382468(2)];
        *(s16 *)(p + 0xA) = a2 + a3 + a4 + 4;
        *(f32 *)(p + 0xC) = D_L23_001D7F5C;
    }
    return p;
}
/* localdecomp:end func_L23_00456AA8 */

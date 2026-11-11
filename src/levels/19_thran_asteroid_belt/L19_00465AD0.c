#include "common.h"

/* localdecomp:start func_L19_00465AD0 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L19_0021F058[];
extern f32 D_L19_001D7EB8;
extern f32 D_L19_001D7EBC;
__asm__(".extern D_L19_001D7EBC, 4");
extern f32 D_L19_001D7EC0;
__asm__(".extern D_L19_001D7EC0, 4");
extern u8 *func_L01_004618E0(s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);

u8 *func_L19_00465AD0(void *a0, void *a1, s32 a2) {
    u8 *p = func_L01_004618E0(0x60);
    u8 *q;
    f32 t;
    s32 v;
    if (p != 0) {
        p[9] = 0x42;
        p[3] = 0x44;
        p[1] = 0;
        q = p + 0x20;
        p[2] = *D_L19_0021F058[0];
        *(f32 *)(p + 0xC) = func_003824E0(D_L19_001D7EB8, D_L19_001D7EBC) * 0.5f * 210000.0f;
        p[8] = func_00382468(0xFF);
        *(s32 *)(p + 4) = 0x40808080;
        *(s16 *)(p + 0xA) = (a2 * 5 + 2) / 6;
        *(u128_t *)(p + 0x10) = *(u128_t *)a0;
        *(u128_t *)(p + 0x20) = *(u128_t *)a1;
        *(s32 *)(q + 0xC) = 0;
        *(f32 *)(q + 0x18) = *(f32 *)(p + 0xC) + *(f32 *)(p + 0xC);
        v = func_00382498(0, 3);
        t = D_L19_001D7EC0;
        *(s32 *)(q + 0x14) = v;
        *(s32 *)(q + 0x10) = ((a2 / 2) * 5 + 2) / 6;
        *(f32 *)(q + 0x1C) = func_003824E0(t, t + 2.0f) * 0.00040000002f;
    }
    return p;
}
/* localdecomp:end func_L19_00465AD0 */

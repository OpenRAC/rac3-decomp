#include "common.h"

/* localdecomp:start func_L41_0041B350 */
__asm__(".extern D_00241120, 16");
extern s32 *D_00241120;
extern s32 D_L41_002412DC;
__asm__(".extern D_L41_00247700, 4");
__asm__(".extern D_L41_002476FC, 4");
extern s32 D_L41_00247700;
extern s32 D_L41_002476FC;
extern u8 *D_L41_0029B21C[];
extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);
extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);

void func_L41_0041B350(void *a0, s32 n, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6) {
    f32 v[4];
    s32 i;
    u8 *r;
    s32 c;
    f32 t;
    f32 k;

    s32 cnt = n;
    if (*D_00241120 >= 3) {
        cnt = n / 3;
    }
    n = cnt;
    i = 0;
    if (n > i) do {
        k = 0.020000001f;
        func_L01_00443B88(v, f3 * k, f4 * k);
        v[2] = func_L39_005B4410(f5, f6) * k;
        k = 0.0f;
        t = func_L39_005B4410(f1, f2);
        c = func_L39_005B4398(3) != 0 ? D_L41_00247700 : D_L41_002476FC;
        switch (D_L41_002412DC) {
        case 0x2A:
        case 0x34:
            c = func_L39_005B4398(3) != 0 ? 0x273538 : 0x263438;
            break;
        case 0x29:
        case 0x2D:
        case 0x33:
        case 0x37:
            c = func_L39_005B4398(3) != 0 ? 0x282720 : 0x272418;
            break;
        }
        r = func_L01_004713C8(a0, v, (func_L39_005B43C8(0x5A, 0x96) * 5 + 2) / 6, t * 210000.0f, c, -2, 0x7F, 0x7F, t * 210000.0f, f0 * 0.00040000002f, 0);
        if (r != 0) {
            u8 b = D_L41_0029B21C[0][func_L39_005B4398(3) + 0xA];
            r[3] = 0x44;
            r[2] = b;
        }
        i++;
    } while (i < n);
}
/* localdecomp:end func_L41_0041B350 */

INCLUDE_ASM("asm/levels", func_L41_0041B578);

INCLUDE_ASM("asm/levels", func_L41_0041B6F0);

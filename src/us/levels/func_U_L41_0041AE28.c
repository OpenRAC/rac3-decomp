#include "common.h"

/* localdecomp:start func_U_L41_0041AE28 */
typedef int u128_41B6F0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_41B6F0;

extern f32 func_U_L41_00480A08(f32, f32);
extern void func_U_L41_0045E410(void *, void *, f32);
extern void func_L39_005C5FC8(void *, void *, s32, s32, s32, s32, s32, s32);

extern s32 D_L41_002478B0;
__asm__(".extern D_L41_002478B0, 4");
extern f32 D_L41_002478B4;
__asm__(".extern D_L41_002478B4, 4");
extern f32 D_L41_002478B8;
__asm__(".extern D_L41_002478B8, 4");
extern f32 D_L41_002478BC;
__asm__(".extern D_L41_002478BC, 4");
extern f32 D_L41_002478C0;
__asm__(".extern D_L41_002478C0, 4");
extern f32 D_L41_002478C4;
__asm__(".extern D_L41_002478C4, 4");
extern s32 D_L41_002478A4;
__asm__(".extern D_L41_002478A4, 4");
extern s32 D_L41_002478A8;
__asm__(".extern D_L41_002478A8, 4");
extern s32 D_L41_002478AC;
__asm__(".extern D_L41_002478AC, 4");

extern s32 *D_L41_002412A0;
extern s32 D_L41_0024145C;
void func_U_L41_0041AE28(void *a0) {
    V4_41B6F0 out;
    V4_41B6F0 tmp;
    s32 i;
    s32 n;
    s32 flag;
    s32 ca;
    s32 cb;

    flag = 0;
    if (D_L41_0024145C == 0x2D || D_L41_0024145C == 0x37) {
        ca = 0x7FE9D09F;
        cb = 0xE9D09F;
        flag = 1;
    } else {
        ca = 0x7F325C66;
        cb = 0x4C6C74;
    }
    n = D_L41_002478B0;
    if (*D_L41_002412A0 >= 3) {
        n = n / 5;
    }
    for (i = 0; i < n; i++) {
        if (flag == 0 || (i & 1) != 0) {
            *(u128_41B6F0 *)&tmp = 0;
            tmp.x = func_U_L41_00480A08(D_L41_002478B8, D_L41_002478BC);
            tmp.y = func_U_L41_00480A08(D_L41_002478B8, D_L41_002478BC);
            tmp.z = func_U_L41_00480A08(D_L41_002478C0, D_L41_002478C4);
            *(u128_41B6F0 *)&out = *(u128_41B6F0 *)&tmp;
            func_U_L41_0045E410(&out, &out, D_L41_002478B4 * 0.0166666675f);
            func_L39_005C5FC8(a0, &out, ca, cb, D_L41_002478A4, D_L41_002478A8, D_L41_002478AC, 0);
        }
    }
}
/* localdecomp:end func_U_L41_0041AE28 */

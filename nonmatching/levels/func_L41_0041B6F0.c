/* NTSC-U draft (2026-11-14, Claude worker): C of func_L41_0041AE28, the NTSC-U twin of func_L41_0041B6F0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L41_0041B308.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_41AE28;

extern f32 func_L39_005B2510(f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L39_005C3D70(void *, void *, s32, s32, s32, s32, s32, s32);

/* localdecomp:start func_L41_0041AE28 */
extern s32 D_L41_0024145C[];
__asm__(".extern D_L41_0024145C, 16");
extern s32 *D_L41_002412A0[];
__asm__(".extern D_L41_002412A0, 16");
extern s32 D_001DC020_sda;
__asm__(".extern D_001DC020_sda, 4");
extern f32 D_001DC024_sda;
__asm__(".extern D_001DC024_sda, 4");
extern f32 D_001DC028_sda;
__asm__(".extern D_001DC028_sda, 4");
extern f32 D_001DC02C_sda;
__asm__(".extern D_001DC02C_sda, 4");
extern f32 D_001DC030_sda;
__asm__(".extern D_001DC030_sda, 4");
extern f32 D_001DC034_sda;
__asm__(".extern D_001DC034_sda, 4");
extern s32 D_001DC014_sda;
__asm__(".extern D_001DC014_sda, 4");
extern s32 D_001DC018_sda;
__asm__(".extern D_001DC018_sda, 4");
extern s32 D_001DC01C_sda;
__asm__(".extern D_001DC01C_sda, 4");

void func_L41_0041AE28(void *a0) {
    V4_41AE28 out;
    V4_41AE28 tmp;
    s32 i;
    s32 n;
    s32 flag;
    s32 ca;
    s32 cb;

    flag = 0;
    if (D_L41_0024145C[0] == 0x2D || D_L41_0024145C[0] == 0x37) {
        ca = 0x7FE9D09F;
        cb = 0xE9D09F;
        flag = 1;
    } else {
        ca = 0x7F325C66;
        cb = 0x4C6C74;
    }
    n = D_001DC020_sda;
    if (*D_L41_002412A0[0] >= 3) {
        n = n / 5;
    }
    for (i = 0; i < n; i++) {
        if (flag == 0 || (i & 1) != 0) {
            *(u128_t *)&tmp = 0;
            tmp.x = func_L39_005B2510(D_001DC028_sda, D_001DC02C_sda);
            tmp.y = func_L39_005B2510(D_001DC028_sda, D_001DC02C_sda);
            tmp.z = func_L39_005B2510(D_001DC030_sda, D_001DC034_sda);
            *(u128_t *)&out = *(u128_t *)&tmp;
            func_00388830(&out, &out, D_001DC024_sda * 0.016666668f);
            func_L39_005C3D70(a0, &out, ca, cb, D_001DC014_sda, D_001DC018_sda, D_001DC01C_sda, 0);
        }
    }
}
/* localdecomp:end func_L41_0041AE28 */

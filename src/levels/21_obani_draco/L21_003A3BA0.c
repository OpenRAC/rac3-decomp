#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_3A25C0;

INCLUDE_ASM("asm/levels", func_L21_003A3BA0);

INCLUDE_ASM("asm/levels", func_L21_003A3DE8);

/* localdecomp:start func_L21_003A3F30 */
/* PAL port of the NTSC-U match src/us/levels/func_L21_003A25C0.c */


extern u8 D_L21_001D66B0[8];
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L02_00426140(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_0032FE90(f32 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L21_003A3F30(u8 *a0) {
    V4_3A25C0 v;

    func_003A52A0(0, 0, a0);
    func_L01_00451FE0(a0, 0x3F, D_L21_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                      1.0f, 3.0f, 1.0f, 3.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    func_003C2F58(a0, 0, &v);
    func_L02_00426140(a0, &v, 0x14, 0, D_L21_001D66B0, 0x80808080, 0, 75, 1.0f, 3.0f, 0.4f, 0.7f);
    func_L02_003E2E38(a0, &v, 1.0f, D_L21_001D66B0, 0xF, 0, 1, 0.050000004f, 2.5f, 5.0f, 1.0f);
    func_L01_0032FE90((f32 *)&v, 0, 0, 0, 0, 2, 5, 0, 0.7f, 0.0f, 0.0f, 0.0f,
                      0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x8080, 0x8040, 0, 0, 0, 0, 0x7F60A0FF, 0x280000FF, 0, 0);
    func_L01_00451E78(a0, 1, 0.0f);
    func_003C2880(a0);
}
/* localdecomp:end func_L21_003A3F30 */

/* localdecomp:start func_L21_003A4148 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_L01_0043A430(u8 *a0, s32 a1, u8 *a2);
extern s32 func_00382468(s32 a0);
extern f32 func_003824E0(f32 a0, f32 a1);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);

void func_L21_003A4148(u8 *arg0, u8 *arg1) {
    f32 x;
    func_L01_0043A430(arg0, 0, arg1);
    *(u8 *)(arg0 + 0x62) = 0xFF;
    *(u128_t *)(arg1 + 0x40) = *(u128_t *)(arg0 + 0x10);
    x = *(f32 *)(arg1 + 0x48);
    *(f32 *)(arg1 + 0x48) = x - 1.0f;
    *(f32 *)(arg1 + 0x54) = func_003824E0(0.05f, 0.001f);
    *(f32 *)(arg1 + 0x54) = (f32)(func_00382468(2) + 1) * *(f32 *)(arg1 + 0x54);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L21_003A4148 */

INCLUDE_ASM("asm/levels", func_L21_003A41F8);

/* localdecomp:start func_L21_003A43E8 */
/* PAL port of the NTSC-U match src/us/levels/func_L21_003A2A78.c */
extern s32 D_L21_001DE0E4;
__asm__(".extern D_L21_001DE0E4, 4");
extern s32 D_L21_001DE8C0;
extern s32 D_L21_001DE0E8[2];
__asm__(".extern D_L21_001DE0E8, 16");
extern s32 D_L21_001E0FD0[2];
__asm__(".extern D_L21_001E0FD0, 16");
extern s32 D_L21_001E0FE0[2];
__asm__(".extern D_L21_001E0FE0, 16");
extern s32 D_L21_001E0FF0[2];
__asm__(".extern D_L21_001E0FF0, 16");
extern s32 func_0038CAD0(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern s32 func_0038DBD8(f32, s32, s32);

void func_L21_003A43E8(u8 *a0, u8 *a1) {
    s32 i;

    if (D_L21_001DE0E4 != D_L21_001DE8C0) {
        for (i = 0; i < 3; i++) {
            if (func_0038CAD0(&D_L21_001E0FD0[i]) != 0) {
                D_L21_001E0FD0[i] = func_00382498(83, 167);
                D_L21_001E0FE0[i] = D_L21_001DE0E8[func_00382468(4)];
            }
            D_L21_001E0FF0[i] = func_0038DBD8(0.020400047f, D_L21_001E0FF0[i], D_L21_001E0FE0[i]);
        }
        D_L21_001DE0E4 = D_L21_001DE8C0;
    }
    *(s32 *)(a0 + 0x78) = D_L21_001E0FF0[*(s32 *)(a1 + 0x50)];
}
/* localdecomp:end func_L21_003A43E8 */

INCLUDE_ASM("asm/levels", func_L21_003A4500);

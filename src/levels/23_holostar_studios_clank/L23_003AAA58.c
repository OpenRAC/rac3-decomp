#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L23_003AAA58);

/* localdecomp:start func_L23_003AAD58 */
#include "vu0.h"
#include "structs/hero.h"
extern u8 D_L23_001E1A40[];
extern struct Hero D_001A4BE0;
extern u8 *D_L23_001DE2D0;
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_00404A10(void *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003AAD58(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);
    u8 *hit;

    if (self[0x31] != 0 && func_L01_0040E548(D_L23_001E1A40, self + 0x10) < 1024.0f) {
        func_L01_004472C0(self);
        self[0x6F] = 0x1E;
    }
    if (self[0x20] == 0)
        return;
    func_L01_00404A10(self, 3);
    if ((fabs_asm(*(f32 *)(self + 0x18) - D_001A4BE0.pos.z) < 1.0f &&
         func_L01_0040E570(self + 0x10, &D_001A4BE0.pos) < 16.0f) ||
        (fabs_asm(*(f32 *)(self + 0x18) - *(f32 *)(D_L23_001DE2D0 + 0x18)) < 1.0f &&
         func_L01_0040E570(self + 0x10, D_L23_001DE2D0 + 0x10) < 16.0f)) {
        func_L01_004450F0(self, 4, -1);
    }
    hit = (u8 *)func_L01_00447490(self, -1, 0);
    if (hit != 0) {
        *(f32 *)(v + 8) -= *(f32 *)(hit + 0x2C);
        if (*(f32 *)(v + 8) <= 0.0f)
            func_L01_004450F0(self, 4, -1);
    }
}
/* localdecomp:end func_L23_003AAD58 */

/* localdecomp:start func_L23_003AAED8 */
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003AAED8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);

    *(u16 *)(a0 + 0x34) |= 0x10;
    *(f32 *)(a0 + 0x18) = func_003C3D30(a0 + 0x10, 0, 0, 0.5f);
    *(f32 *)(v + 8) = 40.0f;
    *(s32 *)(v + 0) = 0;
    *(s32 *)(v + 4) = 0;
    *(u128_t *)(v + 0x10) = *(u128_t *)(a0 + 0x10);
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L23_003AAED8 */

/* localdecomp:start func_L23_003AAF58 */
#include "vu0.h"
__asm__(".extern D_L23_001DE1D0, 4");
extern s32 D_L23_001DE1D0;
extern s32 D_001A71A0[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void *func_L23_003B0978(void *, void *, void *, s32, s32, s32);

void func_L23_003AAF58(u8 *self)
{
    u8 *s = *(u8 **)(self + 0x68);
    V4 a, b;

    a.x = func_0038D098(*(f32 *)(self + 0xF8)) * 0.1f;
    a.y = func_0038D0B0(*(f32 *)(self + 0xF8)) * 0.1f;
    a.z = 1.0f;
    vec_add_ba(&a, &a, self + 0x10);
    b.x = func_0038D098(*(f32 *)(self + 0xF8)) * 0.5f;
    b.y = func_0038D0B0(*(f32 *)(self + 0xF8)) * 0.5f;
    b.z = 0.5f;
    func_0038CF68(&b, &b, 0.40000004f);
    func_L23_003B0978(self, &a, &b, D_001A71A0[0], 0x96, 1);
    *(s32 *)s = D_L23_001DE1D0;
}
/* localdecomp:end func_L23_003AAF58 */

/* localdecomp:start func_L23_003AB058 */
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);

void func_L23_003AB058(u8 *a0) {
    func_L01_003303B8(a0 + 16, 1, 4, 20, 2, 10, 20, 4, 2.0f, 0.0f, 0.0f, 0.0f,
                      1, 1, 1, 1, 1, 0, 0, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 1);
    func_003A52A0(0, 0, a0);
}
/* localdecomp:end func_L23_003AB058 */

INCLUDE_ASM("asm/levels", func_L23_003AB140);

INCLUDE_ASM("asm/levels", func_L23_003AB2F0);

INCLUDE_ASM("asm/levels", func_L23_003AB5F0);

/* localdecomp:start func_L23_003AB770 */
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003AB770(u8 *self)
{
    u8 *s = *(u8 **)(self + 0x68);

    *(u16 *)(self + 0x34) |= 0x10;
    *(f32 *)(self + 0x18) = func_003C3D30(self + 0x10, 0, 0, 0.5f);
    *(f32 *)(s + 0x8) = 40.0f;
    *(s32 *)(s + 0x0) = 0;
    *(s32 *)(s + 0x4) = 0;
    *(V4 *)(s + 0x10) = *(V4 *)(self + 0x10);
    func_L01_004450F0(self, 1, -1);
}
/* localdecomp:end func_L23_003AB770 */

INCLUDE_ASM("asm/levels", func_L23_003AB7F0);

/* localdecomp:start func_L23_003ABA68 */
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);

void func_L23_003ABA68(u8 *self)
{
    func_L01_003303B8(self + 16, 1, 4, 20, 2, 10, 20, 4, 2.0f, 0.0f, 0.0f, 0.0f,
                      1, 1, 1, 1, 1, 0, 0, 0, 0x388EF7, 25591, 0x407FFF, 8447, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 1);
    func_003A52A0(0, 0, self);
}
/* localdecomp:end func_L23_003ABA68 */

INCLUDE_ASM("asm/levels", func_L23_003ABB50);

#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L05_003C0EA8);

INCLUDE_ASM("asm/levels", func_L05_003C24F0);

INCLUDE_ASM("asm/levels", func_L05_003C2618);

INCLUDE_ASM("asm/levels", func_L05_003C28C8);

INCLUDE_ASM("asm/levels", func_L05_003C2B50);

/* localdecomp:start func_L05_003C2C90 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_0038D308(u8 *a0, u8 *a1);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
void func_L05_003C2C90(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    *(s16 *)(p + 408) = 0;
    *(f32 *)(p + 48) = *(s16 *)(p + 52);
    a0[127] = 0;
    *(u128_t *)(a0 + 16) = *(u128_t *)(p + 832);
    *(u128_t *)(a0 + 240) = *(u128_t *)(p + 816);
    func_0038D308(a0 + 192, p + 816);
    *(s32 *)(a0 + 152) = *(s32 *)(*(u8 **)(a0 + 36) + 16);
    func_L01_004450F0(a0, 0, 0);
}
/* localdecomp:end func_L05_003C2C90 */

/* localdecomp:start func_L05_003C2D08 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L05_003C24F0(void);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L05_00468EA8(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2700;
__asm__(".extern D_L05_001DEB08, 4");
extern s32 D_L05_001DEB08;
__asm__(".extern D_L05_001DEB0C, 4");
extern f32 D_L05_001DEB0C;
__asm__(".extern D_L05_001DEB18, 4");
extern f32 D_L05_001DEB18;
__asm__(".extern D_L05_001DEB1C, 4");
extern f32 D_L05_001DEB1C;
__asm__(".extern D_L05_001DEB50, 8");
extern u8 D_L05_001DEB50[8];

void func_L05_003C2D08(u8 *a0) {
    u8 *v;
    s32 i;
    vu0_v4 p;
    vu0_v4 r;
    vu0_v4 d;
    vu0_v4 m[4];

    v = *(u8 **)(a0 + 0x68);
    func_0038CAD0(v + 0x2D0);
    func_0038CB00(v + 0x2D4);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        *(u16 *)(a0 + 0x96) += 1;
    }
    func_L01_00404808(func_L05_003C24F0, a0);
    func_L01_00451DF8(a0, v + 0x240, 2, 1, 2.5f);
    if (a0[0x31] != 0 && func_L01_0040E548(&D_L05_001E2700, a0 + 0x10) < 1024.0f) {
        func_L01_004472C0(a0);
        a0[0x6F] = 0x1E;
    }
    *(vu0_q *)&p = *(vu0_q *)(a0 + 0x10);
    func_0038CF68(&d, a0 + 0xE0, 0.6f);
    vec_add_ab(&p, &p, &d);
    for (i = 0; i < D_L05_001DEB08; i++) {
        func_003C4C18(&p, D_L05_001DEB0C);
        func_0038CF68(&r, a0 + 0xE0, func_003824E0(D_L05_001DEB18, D_L05_001DEB1C) * 0.020000001f);
        func_L05_00468EA8(&p, &r, D_L05_001DEB50, func_00382468(2), func_00382468(3) - 1);
    }
}
/* localdecomp:end func_L05_003C2D08 */

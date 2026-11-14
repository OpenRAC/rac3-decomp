#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L20_003CE2D0);

INCLUDE_ASM("asm/levels", func_L20_003CE4F8);

INCLUDE_ASM("asm/levels", func_L20_003CEEB0);

INCLUDE_ASM("asm/levels", func_L20_003CF108);

/* localdecomp:start func_L20_003CFB08 */
extern f32 func_0038CF38(f32 *, f32 *);
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 D_L20_001DEB80;
__asm__(".extern D_L20_001DEB80, 4");
extern void func_L20_003CE2D0(u8 *, f32);
extern f32 D_L20_001DF178;
__asm__(".extern D_L20_001DF178, 4");
extern s32 D_L20_001DF170;
__asm__(".extern D_L20_001DF170, 4");
extern s32 D_L20_001DF174;
__asm__(".extern D_L20_001DF174, 4");
extern f32 D_L20_001DF17C;
__asm__(".extern D_L20_001DF17C, 4");
extern f32 D_L20_001DF180;
__asm__(".extern D_L20_001DF180, 4");
extern f32 D_L20_001DF184;
__asm__(".extern D_L20_001DF184, 4");
extern u32 D_L20_001DF188;
__asm__(".extern D_L20_001DF188, 4");
extern u32 D_L20_001DF18C;
__asm__(".extern D_L20_001DF18C, 4");
extern f32 D_L20_001DF220;
__asm__(".extern D_L20_001DF220, 4");
extern s32 D_L20_001DF218;
__asm__(".extern D_L20_001DF218, 4");
extern s32 D_L20_001DF21C;
__asm__(".extern D_L20_001DF21C, 4");
extern f32 D_L20_001DF224;
__asm__(".extern D_L20_001DF224, 4");
extern f32 D_L20_001DF228;
__asm__(".extern D_L20_001DF228, 4");
extern f32 D_L20_001DF22C;
__asm__(".extern D_L20_001DF22C, 4");
extern u32 D_L20_001DF230;
__asm__(".extern D_L20_001DF230, 4");
extern u32 D_L20_001DF234;
__asm__(".extern D_L20_001DF234, 4");
extern f32 D_L20_001DF23C;
__asm__(".extern D_L20_001DF23C, 4");
extern f32 D_L20_001DF240;
__asm__(".extern D_L20_001DF240, 4");
extern s32 D_L20_001D66B0;
__asm__(".extern D_L20_001D66B0, 16");
extern void func_L01_00404808(void (*)(void *), void *);

void func_L20_003CFB08(u8 *p) {
    f32 len = func_0038CF38((f32 *)(p + 0x10), D_L20_001E2E80);
    if (len <= 2.0f && 1.0f < len) {
        func_003C4138(&D_L20_001DEB80, 0.5f, 0.2f);
    } else if (len <= 1.0f) {
        func_003C4138(&D_L20_001DEB80, 0.0f, 0.2f);
    } else {
        func_003C4138(&D_L20_001DEB80, 2.0f, 0.1f);
    }
    func_L20_003CE2D0(p, D_L20_001DEB80);
}
/* localdecomp:end func_L20_003CFB08 */

/* localdecomp:start func_L20_003CFBF0 */
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern f32 D_L20_001DF168;
__asm__(".extern D_L20_001DF168, 4");
extern f32 D_L20_001DEB90;
__asm__(".extern D_L20_001DEB90, 4");
extern s32 D_L20_001DEB88;
__asm__(".extern D_L20_001DEB88, 4");
extern s32 D_L20_001DEB8C;
__asm__(".extern D_L20_001DEB8C, 4");
extern f32 D_L20_001DEB94;
__asm__(".extern D_L20_001DEB94, 4");
extern f32 D_L20_001DEB98;
__asm__(".extern D_L20_001DEB98, 4");
extern f32 D_L20_001DEB9C;
__asm__(".extern D_L20_001DEB9C, 4");
extern u32 D_L20_001DEBA0;
__asm__(".extern D_L20_001DEBA0, 4");
extern u32 D_L20_001DEBA4;
__asm__(".extern D_L20_001DEBA4, 4");
extern f32 D_L20_001DF220;
__asm__(".extern D_L20_001DF220, 4");
extern s32 D_L20_001DF218;
__asm__(".extern D_L20_001DF218, 4");
extern s32 D_L20_001DF21C;
__asm__(".extern D_L20_001DF21C, 4");
extern f32 D_L20_001DF224;
__asm__(".extern D_L20_001DF224, 4");
extern f32 D_L20_001DF228;
__asm__(".extern D_L20_001DF228, 4");
extern f32 D_L20_001DF22C;
__asm__(".extern D_L20_001DF22C, 4");
extern u32 D_L20_001DF230;
__asm__(".extern D_L20_001DF230, 4");
extern u32 D_L20_001DF234;
__asm__(".extern D_L20_001DF234, 4");
extern u8 D_L20_001E2E00[];
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3, f32 e, f32 f, f32 g);
extern f32 D_L20_001DF23C;
__asm__(".extern D_L20_001DF23C, 4");
extern f32 D_L20_001DF240;
__asm__(".extern D_L20_001DF240, 4");
extern s32 D_L20_001D66B0;
__asm__(".extern D_L20_001D66B0, 16");
extern void func_L01_00404808(void (*)(void *), void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32 a, f32 b);

void func_L20_003CFBF0(u8 *a0) {
    f32 d[4] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    u8 *p;
    s32 col;
    s32 i;
    f32 nb;
    f32 pf;
    p = *(u8 **)(a0 + 0x68);
    col = func_0038DBD8(D_L20_001DEB88, D_L20_001DEB8C, func_0038D0B0(D_L20_001DEB90) * 0.5f + 0.5f);
    nb = func_0038DAB8(D_L20_001DEB90, func_003824E0(D_L20_001DEB94, D_L20_001DEB98) * 0.017453292f * 0.020000001f);
    pf = *(f32 *)p;
    D_L20_001DEB90 = nb;
    func_003D9508(a0 + 0x10, 0x43, col, 1, 2.25f, -0.1f, pf);
    func_003D9508(a0 + 0x10, 0x31, 0x7FFFFFFF, 1, 1.0f, 0.0f, -*(f32 *)(p + 4));
    func_003D9508(a0 + 0x10, 0x4B, 0x7FFFFFFF, 3, 2.0f, 0.025f, -*(f32 *)p);
    for (i = 0; i < 12; i++) {
        vec_sub_ab(d, D_L20_001E2E00, a0 + 0x10);
        func_0038D890(p + 0xC50 + i * 0x10, p + 0xC50 + i * 0x10, d, *(f32 *)(p + 0xD10 + i * 4));
        *(f32 *)(p + 0x2C) = *(f32 *)(p + 0x2C) + 0.03f;
        if (*(f32 *)(p + 0x2C) > 2.5f) {
            *(f32 *)(p + 0x2C) = 2.5f;
        }
        func_0038CF68(p + 0xC50 + i * 0x10, p + 0xC50 + i * 0x10, *(f32 *)(p + 0x2C));
        vec_add_ab(e, p + 0xC50 + i * 0x10, a0 + 0x10);
        *(u128_t *)g = *(u128_t *)(a0 + 0x10);
        func_L01_0040A8C0((u128_t *)e, (u128_t *)g, 0x12, 1, D_L20_001DEBA0, D_L20_001DEBA0, D_L20_001DEBA4, D_L20_001DEBA4, D_L20_001DEB9C, 3.0f, *(f32 *)(p + 0xD40));
    }
    *(f32 *)(p + 0xD40) = *(f32 *)(p + 0xD40) - func_003824E0(0.025f, 0.035f);
    if (*(f32 *)(p + 0xD40) <= -8.0f) {
        *(f32 *)(p + 0xD40) = *(f32 *)(p + 0xD40) + 8.0f;
    }
}
/* localdecomp:end func_L20_003CFBF0 */

INCLUDE_ASM("asm/levels", func_L20_003CFE80);

INCLUDE_ASM("asm/levels", func_L20_003D0090);

INCLUDE_ASM("asm/levels", func_L20_003D0910);

INCLUDE_ASM("asm/levels", func_L20_003D5FF0);

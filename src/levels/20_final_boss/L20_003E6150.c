#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L20_003E6150);

INCLUDE_ASM("asm/levels", func_L20_003E6378);

INCLUDE_ASM("asm/levels", func_L20_003E6D30);

INCLUDE_ASM("asm/levels", func_L20_003E6F88);

/* localdecomp:start func_L20_003E7988 */
extern f32 func_0038CF38(f32 *, f32 *);
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 D_L20_001DF168;
__asm__(".extern D_L20_001DF168, 4");
extern void func_L20_003E6150(u8 *, f32);

void func_L20_003E7988(u8 *p) {
    f32 len = func_0038CF38((f32 *)(p + 0x10), D_L20_001E2E80);

    if (len <= 2.0f && 1.0f < len) {
        func_003C4138(&D_L20_001DF168, 0.5f, 0.2f);
    } else if (len <= 1.0f) {
        func_003C4138(&D_L20_001DF168, 0.0f, 0.2f);
    } else {
        func_003C4138(&D_L20_001DF168, 2.0f, 0.1f);
    }
    func_L20_003E6150(p, D_L20_001DF168);
}
/* localdecomp:end func_L20_003E7988 */

INCLUDE_ASM("asm/levels", func_L20_003E7A70);

INCLUDE_ASM("asm/levels", func_L20_003E7D00);

INCLUDE_ASM("asm/levels", func_L20_003E8288);

INCLUDE_ASM("asm/levels", func_L20_003E84B0);

INCLUDE_ASM("asm/levels", func_L20_003E8E68);

INCLUDE_ASM("asm/levels", func_L20_003E90C0);

INCLUDE_ASM("asm/levels", func_L20_003E9AC0);

INCLUDE_ASM("asm/levels", func_L20_003E9BA8);

INCLUDE_ASM("asm/levels", func_L20_003E9E38);

INCLUDE_ASM("asm/levels", func_L20_003EA258);

INCLUDE_ASM("asm/levels", func_L20_003EA488);

INCLUDE_ASM("asm/levels", func_L20_003EAA70);

INCLUDE_ASM("asm/levels", func_L20_003EABD8);

INCLUDE_ASM("asm/levels", func_L20_003EB388);

INCLUDE_ASM("asm/levels", func_L20_003EB4E0);

/* localdecomp:start func_L20_003EB838 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 d; f32 k0, k1, k2; } Loc38;

extern f32 func_003824E0(f32 a, f32 b);
extern s32 D_L20_001DFD40;
extern void func_L01_0046E078(void *a0, void *a1, void *a2, void *a3, s32 a4);

void func_L20_003EB838(u8 *arg0, u8 *arg1) {
    Loc38 loc;

    loc.k0 = func_003824E0(-1.0f, -0.9f) * *(f32 *)(arg1 + 0x8);
    loc.k1 = func_003824E0(-0.05f, 0.05f) * *(f32 *)(arg1 + 0x8);
    loc.k2 = func_003824E0(-0.05f, 0.05f) * *(f32 *)(arg1 + 0x8);
    vec_sub_ab(&loc.d, arg0 + 0x10, arg1 + 0x10);
    if ((D_L20_001DFD40 & 3) == (((s32)arg0 >> 8) & 3)) {
        func_L01_0046E078(arg0, &loc.d, &loc.k0, arg1 + 0x30, 1);
    }
}
/* localdecomp:end func_L20_003EB838 */

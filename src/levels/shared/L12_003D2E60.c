#include "common.h"

typedef struct {
    void (*f0)(u8 *);
    void (*f4)(u8 *);
} Vt003D1AA8;
typedef struct {
    s32 a;
    f32 b;
    s32 c;
    f32 d;
} Src_3D1EB8;

INCLUDE_ASM("asm/levels", func_L12_003D2E60);

INCLUDE_ASM("asm/levels", func_L12_003D3338);

/* localdecomp:start func_L12_003D3488 */
extern s32 func_L01_00452FB0(u8 *, u8 *, s32, s32, s32);
extern void func_L12_003D3538(u8 *, u8 *, s32);
extern void func_L01_00456BD0(u8 *, s32);

s32 func_L12_003D3488(u8 *self, u8 *target) {
    s32 r = func_L01_00452FB0(self, target + 112, 0, 0, 0);

    if (r != 0) {
        if ((u32)(r - 4) < 2) {
            func_L12_003D3538(self, target, 1);
            return 0;
        }
    }
    if (target[94] != 0) {
        func_L12_003D3538(self, target, 1);
        return 0;
    }
    if (target[62] == 2) {
        func_L12_003D3538(self, target, 0);
        return 0;
    }
    func_L01_00456BD0(self, 3);
    return 1;
}
/* localdecomp:end func_L12_003D3488 */

INCLUDE_ASM("asm/levels", func_L12_003D3538);

/* localdecomp:start func_L12_003D36B0 */
extern void func_L01_0044EA78(u8 *a0, u8 *a1);
extern Vt003D1AA8 *func_L01_0043B548(s32 a0, s32 a1);
extern void func_003C2880(u8 *a0);
void func_L12_003D36B0(u8 *a0, s32 a1) {
    u8 *s0 = *(u8 **)(a0 + 104);
    Vt003D1AA8 *vt;
    func_L01_0044EA78(a0, s0 + 352);
    func_L01_0044EA78(a0, s0 + 480);
    if (*(s32 *)(s0 + 336) != 0) {
        vt = func_L01_0043B548(6625, 108);
        vt->f0(a0);
        if (a1 != 0) {
            vt->f4(a0);
        }
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L12_003D36B0 */

/* localdecomp:start func_L12_003D3748 */
extern void func_L01_00456C98(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L12_003D3748(s32 a0, u8 *a1, s32 a2) {
    if (a2) {
        func_L01_00456C98(a0, *(s32 *)(a1 + 608), 0, 0, 0, 1, 1, 0, 0, 0,
                      *(f32 *)(a1 + 612), *(f32 *)(a1 + 612) + *(f32 *)(a1 + 612), 1.0f);
    } else {
        func_L01_00456C98(a0, *(s32 *)(a1 + 616), 0, 0, 0, 1, 1, 0, 0, 0,
                      *(f32 *)(a1 + 620), *(f32 *)(a1 + 620) + *(f32 *)(a1 + 620), 1.0f);
    }
    return *(s16 *)(a1 + 332) != 0;
}
/* localdecomp:end func_L12_003D3748 */

INCLUDE_ASM("asm/levels", func_L12_003D37F0);

INCLUDE_ASM("asm/levels", func_L12_003D3978);

INCLUDE_ASM("asm/levels", func_L12_003D3A80);

/* localdecomp:start func_L12_003D3B00 */

extern void func_003C3938(void *a0, s32 a1, s32 a2);

void func_L12_003D3B00(u8 *a0, u8 *a1)
{
    Src_3D1EB8 *s = *(Src_3D1EB8 **)(a1 + 104);
    u8 *d = *(u8 **)(a0 + 104);

    *(s32 *)(d + 608) = s->a;
    if (0.0f < s->b) {
        *(f32 *)(d + 612) = s->b;
    }
    *(s32 *)(d + 616) = s->c;
    if (0.0f < s->d) {
        *(f32 *)(d + 620) = s->d;
    }
    func_003C3938(a0, 0, 0);
}
/* localdecomp:end func_L12_003D3B00 */

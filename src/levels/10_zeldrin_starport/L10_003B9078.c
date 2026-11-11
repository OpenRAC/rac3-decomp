#include "common.h"

/* localdecomp:start func_L10_003B9078 */
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L10_003B9078(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *s3 = *(u8 **)(a0 + 0x68);
    if (*(u8 *)(a0 + 0x43) != a1) {
        func_003C3A10(a0, a1, a2, a3);
        func_003C3A10(*(u8 **)(s3 + 0x2DC), a1, a2, a3);
    }
}
/* localdecomp:end func_L10_003B9078 */

INCLUDE_ASM("asm/levels", func_L10_003B90E0);

INCLUDE_ASM("asm/levels", func_L10_003B9570);

/* localdecomp:start func_L10_003B9D28 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9D28;
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 D_L10_001E8918[];

s32 func_L10_003B9D28(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x68);
    V4_3B9D28 a;
    V4_3B9D28 b;
    s32 t;
    s32 r;

    func_003C2F58(*(void **)(s1 + 0x2DC), 0, &a);
    b = *(V4_3B9D28 *)(s1 + 0x220);
    if (func_003D3CB0(&a, &b, 0x10, a0, 0) == 0) {
        return 1;
    }
    t = D_L10_001E8918[0];
    if (t != 0 && t == *(s32 *)(s1 + 0x230)) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L10_003B9D28 */

INCLUDE_ASM("asm/levels", func_L10_003B9DB0);

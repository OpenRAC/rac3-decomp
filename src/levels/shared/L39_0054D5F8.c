#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0054D5F8);

INCLUDE_ASM("asm/levels", func_L39_0054D728);

INCLUDE_ASM("asm/levels", func_L39_0054D9D8);

INCLUDE_ASM("asm/levels", func_L39_0054DD90);

INCLUDE_ASM("asm/levels", func_L39_0054E010);

INCLUDE_ASM("asm/levels", func_L39_0054F4E0);

/* localdecomp:start func_L39_0054FAB8 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

extern s32 D_L39_001D5A08;
extern void func_003C2F58(void *, s32, Vec4 *);
extern void func_L39_0054FE80(Vec4 *, s32, f32, f32, f32, f32);

void func_L39_0054FAB8(u8 *arg0) {
    Vec4 v;
    u8 *p;

    if (arg0 != 0 && *(s16 *)(arg0 + 170) == 4246 && arg0[32] != 254 && arg0[32] != 253) {
        p = *(u8 **)(arg0 + 104);
        if (p != 0 && (*(u8 **)(p + 60))[9417] == D_L39_001D5A08) {
            func_003C2F58(arg0, 0, &v);
            func_L39_0054FE80(&v, 120, 1.0f, 0.0f, 0.0f, 0.9f);
        }
    }
}
/* localdecomp:end func_L39_0054FAB8 */

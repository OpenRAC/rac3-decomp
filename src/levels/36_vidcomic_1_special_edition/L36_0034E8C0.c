#include "common.h"

typedef struct T_0034F950 {
    u8 pad_00[0xD4];
    s32 f_D4;
    s32 f_D8;
    s32 f_DC;
} T_0034F950;
typedef struct U_0034F950 {
    u8 pad_00[0x68];
    T_0034F950 *f_68;
} U_0034F950;

INCLUDE_ASM("asm/levels", func_L36_0034E8C0);

/* localdecomp:start func_L36_0034F950 */
extern f32 func_003824E0(f32, f32);
extern f32 D_L36_001DD3A8[2];

void func_L36_0034F950(U_0034F950 *a0) {
    T_0034F950 *s;
    s32 i;
    s32 old;
    f32 r;
    f32 x;

    i = 0;
    s = a0->f_68;
    s->f_D4 = 1;
    old = s->f_D8;
    s->f_DC = old;
    x = 1.0f;
    if (old != 4) {
        x = x - D_L36_001DD3A8[old];
    }
    r = func_003824E0(0.0f, x);
    if (0.0f <= r) {
        do {
            if (i != s->f_DC) {
                r = r - D_L36_001DD3A8[i];
            }
            i++;
        } while (0.0f <= r);
    }
    s->f_D8 = i - 1;
}
/* localdecomp:end func_L36_0034F950 */

INCLUDE_ASM("asm/levels", func_L36_0034FA10);

INCLUDE_ASM("asm/levels", func_L36_0034FB20);

INCLUDE_ASM("asm/levels", func_L36_0034FE78);

INCLUDE_ASM("asm/levels", func_L36_00350330);

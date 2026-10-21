#include "common.h"

/* localdecomp:start func_L03_003AE810 */
extern u8 D_L03_001E1C50[];
extern s32 func_00381FF0(s32);
extern void func_L03_0044DC40(u8 *, s32, s32, s32, s32);
void func_L03_003AE810(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 n = *(s32 *)(p + 80);
    p = p + 496 + *(s32 *)(p + 44) * 32;
    if (p[26] < n) {
        n = p[26];
    }
    func_L03_0044DC40(D_L03_001E1C50, func_00381FF0(4269), n, p[26], -1);
}
/* localdecomp:end func_L03_003AE810 */

/* localdecomp:start func_L03_003AE880 */
typedef struct { u8 pad[0x28]; s32 x28; s32 x2C; } V_3ACF48;
typedef struct { u8 pad[0x68]; V_3ACF48 *x68; } O_3ACF48;
extern u8 D_L03_001E1C90[];
extern s32 func_00381FF0(s32);
extern void func_L03_0044DC40(u8 *, s32, s32, s32, s32);
void func_L03_003AE880(O_3ACF48 *o) {
    V_3ACF48 *v = o->x68;
    s32 n = v->x2C + 1;
    if (v->x28 < n) {
        n = v->x28;
    }
    func_L03_0044DC40(D_L03_001E1C90, func_00381FF0(5072), n, v->x28, -1);
}
/* localdecomp:end func_L03_003AE880 */

INCLUDE_ASM("asm/levels", func_L03_003AE8E0);

#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00537998);

INCLUDE_ASM("asm/levels", func_L39_00537B28);

INCLUDE_ASM("asm/levels", func_L39_00539268);

INCLUDE_ASM("asm/levels", func_L39_00539398);

INCLUDE_ASM("asm/levels", func_L39_0053B6B0);

INCLUDE_ASM("asm/levels", func_L39_0053B810);

INCLUDE_ASM("asm/levels", func_L39_0053BA68);

INCLUDE_ASM("asm/levels", func_L39_0053BB08);

/* localdecomp:start func_L39_0053BE50 */
extern s16 D_L39_00293F38[][64];
extern u8 *D_L39_0024BF5C;

u8 *func_L39_0053BE50(s32 idx, s32 id) {
    s32 i;
    u8 *m;
    u8 *p;

    for (i = 1; i <= D_L39_00293F38[idx][0]; i++) {
        m = D_L39_0024BF5C + D_L39_00293F38[idx][i] * 256;
        p = *(u8 **)(m + 104);
        if (p != 0 && *(s16 *)(p + 126) == id) {
            return m;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0053BE50 */

INCLUDE_ASM("asm/levels", func_L39_0053BED0);

INCLUDE_ASM("asm/levels", func_L39_0053C110);

INCLUDE_ASM("asm/levels", func_L39_0053C1E8);

INCLUDE_ASM("asm/levels", func_L39_0053C248);

/* localdecomp:start func_L39_0053C2A0 */
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_L39_0053C1E8(void *, void *, f32);

void func_L39_0053C2A0(u8 *a0) {
    f32 v[4];
    u8 *p = *(u8 **)(a0 + 104);
    func_0038CF68(v, p + 32, 1.0f);
    func_L39_0053C1E8(a0, p, -func_0038CE68(p, v));
}
/* localdecomp:end func_L39_0053C2A0 */

INCLUDE_ASM("asm/levels", func_L39_0053C300);

INCLUDE_ASM("asm/levels", func_L39_0053C758);

INCLUDE_ASM("asm/levels", func_L39_0053CEC0);

INCLUDE_ASM("asm/levels", func_L39_0053D1C0);

INCLUDE_ASM("asm/levels", func_L39_0053D2C0);

#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038DBD8(s32, s32, f32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/handwritten", func_0038DBD8);

ASM_FUNC("asm/handwritten", func_0038DC20);

LINKER_REMNANT("asm/remnants", func_0038DD18);

ASM_FUNC("asm/handwritten", func_0038DD20);

/* localdecomp:start func_0038DE18 */
typedef struct { u32 f0; u32 f4; } E_0038DE18;
typedef struct { s32 n; E_0038DE18 e[1]; } H_0038DE18;
extern s32 D_001D55D0_0038DE18[2];
extern E_0038DE18 *D_001D55D8_0038DE18[2];
extern u8 *D_001D55E0_0038DE18[2];
void func_0038DE18(s32 i, s32 a1, H_0038DE18 *p) {
    s32 n = p->n;
    s32 j;
    D_001D55D0_0038DE18[i] = a1;
    D_001D55D8_0038DE18[i] = p->e;
    D_001D55E0_0038DE18[i] = (u8 *)p + n * 8 + 4;
    for (j = 0; j < n; j++) {
        E_0038DE18 *e = &D_001D55D8_0038DE18[i][j];
        u8 *q = D_001D55E0_0038DE18[i] + ((e->f0 >> 2) & 0x3FFC);
        if (q != 0 && q[3] != 0) {
            e->f0 &= 0xFFFF000F;
        }
    }
}
/* localdecomp:end func_0038DE18 */

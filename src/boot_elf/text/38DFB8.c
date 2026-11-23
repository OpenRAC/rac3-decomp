#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038DFB8(s32, s32, f32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_0038DFB8);

ASM_FUNC("asm/boot_elf/handwritten", func_0038E000);

LINKER_REMNANT("asm/boot_elf/remnants", func_0038E0F8);

ASM_FUNC("asm/boot_elf/handwritten", func_0038E100);

/* localdecomp:start func_0038E1F8 */
typedef struct { u32 f0; u32 f4; } E_0038E1F8;
typedef struct { s32 n; E_0038E1F8 e[1]; } H_0038E1F8;
extern void *D_001D55D0_0038E1F8[2];
extern E_0038E1F8 *D_001D55D8_0038E1F8[2];
extern u8 *D_001D55E0_0038E1F8[2];
void func_0038E1F8(s32 i, void *a1, void *table) {
    H_0038E1F8 *p = table;
    s32 n = p->n;
    s32 j;
    D_001D55D0_0038E1F8[i] = a1;
    D_001D55D8_0038E1F8[i] = p->e;
    D_001D55E0_0038E1F8[i] = (u8 *)p + n * 8 + 4;
    for (j = 0; j < n; j++) {
        E_0038E1F8 *e = &D_001D55D8_0038E1F8[i][j];
        u8 *q = D_001D55E0_0038E1F8[i] + ((e->f0 >> 2) & 0x3FFC);
        if (q != 0 && q[3] != 0) {
            e->f0 &= 0xFFFF000F;
        }
    }
}
/* localdecomp:end func_0038E1F8 */

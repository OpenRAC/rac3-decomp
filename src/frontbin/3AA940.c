#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AA910.c's earlier functions */
extern void func_003AA910(u8 *p, s32 f);

extern void func_00116F98(s32 *a0, s32 a1, s32 *a2);
extern char D_001D80B0[];
extern char D_001D80C8[];
extern void func_116F98(char *, s32, char *);
/* localdecomp:start func_003AA940 */
/* from the NTSC-U decomp's func_003A53E0 (nonmatching/frontbin draft) */
void func_003AA940(void *unused, f32 *out, f32 t) {
    if (!out) func_00116F98((s32 *)D_001D80B0, 0x3D, (s32 *)D_001D80C8);
    out[0] = t;
    out[1] = t * 0.5f;
    out[2] = 1.0f - t;
    out[3] = (1.0f - t) * 0.5f;
}
/* localdecomp:end func_003AA940 */

extern char D_001D8160[];
extern void func_003AA910();
LINKER_REMNANT("asm/remnants", func_003AA9B8);

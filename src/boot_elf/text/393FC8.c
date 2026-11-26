#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00393FC8 */
/* func_00393FC8 (PAL): US draft of rac3-uya-decomp func_00393EF8, names moved to PAL addresses.
   The only PAL change is the last constant: w78 = 25 (0x19) instead of the US 30 (0x1e). */
typedef struct { u8 pad[0x48]; s16 h48; s16 h4A; u8 p2[0x58-0x4C]; s32 w58; s32 w5C; u8 p3[0x70-0x60]; s32 w70; s32 w74; s32 w78; } S_38F3A0;
extern void func_00393F38(s32);
void func_00393FC8(S_38F3A0 *p) {
    func_00393F38(0);
    p->w58 = 0xD2; p->w5C = 0xC8; p->w74 = -2; p->w78 = 25; p->h48 = 0; p->h4A = 0; p->w70 = 0;
}
/* localdecomp:end func_00393FC8 */

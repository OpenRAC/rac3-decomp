#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */


typedef struct { u8 pad[0x38]; u16 h38; u8 pad2[0xF0 - 0x3A]; } S_38F310;
typedef struct { s32 w0; u8 pad[0x14]; s32 w18; } D_393F38;
extern s32 D_001D9EE8_00393F38;
extern s32 *D_001D9EF0_00393F38;
extern s32 D_001D5D40;
extern s32 D_001D5CAC;
extern s32 D_1D4C60[2];
extern s32 D_1D4C80[2];
extern u8 D_001425C0[];
extern S_38F310 D_001DAA40_00393F38[];
extern D_393F38 D_00331990[];
/* localdecomp:start func_00393F38 */
/* the copy of func_00393B58 */
__asm__(".extern D_001D9EE8_00393F38, 16");
__asm__(".extern D_001D9EF0_00393F38, 16");
__asm__(".extern D_001D4C60, 16");
__asm__(".extern D_001D4C80, 16");
__asm__(".extern D_001D5D40, 4");
__asm__(".extern D_001D5CAC, 4");
extern s32 D_001D4C80_a00393F38[2] __asm__("D_001D4C80");
extern s32 D_001D4C60_a00393F38[2] __asm__("D_001D4C60");
void func_00393F38(s32 a) {
    s32 *p;
    s32 i;
    S_38F310 *e;

    D_001D9EE8_00393F38 = 8;
    D_001D9EF0_00393F38 = &D_001D5D40;
    p = a ? D_001D4C80_a00393F38 : D_001D4C60_a00393F38;
    D_001D5CAC = 0;
    for (i = 0; i < 8; i++) {
        e = &D_001DAA40_00393F38[D_001425C0[p[i]]];
        D_00331990[i].w0 = e->h38;
        D_00331990[i].w18 = p[i];
    }
}
/* localdecomp:end func_00393F38 */

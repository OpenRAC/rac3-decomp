#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

extern u8 D_001D955D;
extern u8 D_001D955C;
extern s32 func_00392A18(void);
extern s32 func_003E8100(s32, s32, s32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
/* localdecomp:start func_003E4D70 */
__asm__(".extern D_001D955D, 1");
__asm__(".extern D_001D955C, 1");
typedef struct { u8 p0[0x20]; u8 x20; } S_003E4D70;
extern S_003E4D70 D_00142CA0_003E4D70;
void func_003E4D70(s32 arg0) {
    S_003E4D70 *g = &D_00142CA0_003E4D70;
    s32 a, b;
    D_001D955C = (g->x20 != D_001D955D);
    if (D_001D955C) {
        a = g->x20 ? 0x8E : 0x8C;
        b = g->x20 ? 0x8F : 0x8D;
        D_001D955D = g->x20 != 0;
        func_003E8100(0x90002, func_00392A18(), a);
        func_003E8100(0x90001, func_00392A18(), b);
        func_003E73B8(0x9000C, g->x20 ? 0.4025f : 0.4285f, 0.1315f);
        func_003E81F0(0x9000C, 0.6f, 0.6f);
        func_003E73B8(0x90007, g->x20 ? 0.4394f : 0.464136f, 0.13f);
    }
}
/* localdecomp:end func_003E4D70 */

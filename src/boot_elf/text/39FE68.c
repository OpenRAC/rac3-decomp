#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 39F890.c's earlier functions */
extern void func_0038CF58(void *, s32, s32);
extern void func_0039FE68();
extern u32 D_001D545C;
extern s32 func_0039FD58(s32 bit);

typedef struct { u8 p0[0xC]; s32 fC; s32 f10; s32 f14; u8 p1[0x10]; s32 f28; } S_39AAF0;
extern S_39AAF0 D_0022CF80_0039FE68;
extern u32 D_001D545C;
extern s32 D_00143140[];
extern s32 func_0038E100();
extern void func_0039FF28();
/* localdecomp:start func_0039FE68 */
void func_0039FE68(void *arg0) {
    S_39AAF0 *p = &D_0022CF80_0039FE68;
    s32 r;
    if (p->f10 != 0) {
        if (p->f28 == 0) {
            func_0038CF58(arg0, 0, 0x800);
            return;
        }
        func_0039FD58(D_001D545C);
        r = func_0038E100(arg0, 0x800, p->f14, p->fC);
        if (r == -1) {
            func_0039FF28(arg0);
        }
        if (D_00143140[D_001D545C] < r) D_00143140[D_001D545C] = r;
    }
}
/* localdecomp:end func_0039FE68 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0039FF18);

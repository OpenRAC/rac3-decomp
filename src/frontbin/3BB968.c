#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3BB530.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);

extern void func_0013CA20(void);
extern void func_0013BF00(s32);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern void func_0013BED0(void);
extern u32 D_001D8CE0;
extern s32 D_001DA1F4[];
extern s32 D_001D4B4C[];
/* localdecomp:start func_003BB968 */
__asm__(".extern D_001D8CE0, 4");
extern s32 D_001DA1F4_003BB968[] __attribute__((section(".sdata")));
extern s32 D_001D4B4C_003BB968;
void func_003BB968(void) {
    s32 r;
    u32 i;

    func_0013CA20();
    for (i = 1; i < D_001D8CE0; i++) {
        func_0013BF00(D_001DA1F4_003BB968[i - 1]);
    }
    func_0013CA28();
    do {
        r = func_0013B620();
    } while (r);
    func_0013BED0();
    D_001D4B4C_003BB968 = 0;
}
/* localdecomp:end func_003BB968 */

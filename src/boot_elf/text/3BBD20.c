#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

extern void func_0013CA20(void);
extern void func_0013BF00(s32);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern void func_0013BED0(void);
extern u32 D_001D8CE0;
extern s32 D_001DA1F4[];
extern s32 D_001D4B4C[];
/* localdecomp:start func_003BBD20 */
__asm__(".extern D_001D8CE0, 4");
extern void func_0013CA20(void);
extern void func_0013BF00(s32);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern void func_0013BED0(void);
extern u32 D_001D8CE0;
extern s32 D_001DA1F4[];
extern s32 D_001D4B4C_003BBD20 __attribute__((section(".data")));
void func_003BBD20(void) {
    u32 i;
    s32 *p;
    func_0013CA20();
    i = 1;
    if (i < D_001D8CE0) {
        p = D_001DA1F4;
        do {
            func_0013BF00(*p);
            p++;
            i++;
        } while (i < D_001D8CE0);
    }
    func_0013CA28();
    while (func_0013B620()) {
    }
    func_0013BED0();
    D_001D4B4C_003BBD20 = 0;
}
/* localdecomp:end func_003BBD20 */

#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003E7540();
extern void func_003E7598(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E7540 */
extern f32 D_00225900[];
extern f32 D_001DA940;
extern s32 D_001DA944;
extern s32 D_001D55E8;
extern void func_003877A0();
extern void func_003A97F8(s32, unsigned long);
void func_003E7540(void) {
    D_001DA940 = D_00225900[0xB0/4];
    D_00225900[0xB0/4] = 0.62f;
    func_003877A0();
    func_003A97F8(0x47, 0x33001);
    D_001DA944 = D_001D55E8;
}
/* localdecomp:end func_003E7540 */

/* localdecomp:start func_003E7598 */
extern s32 D_001DA944;
extern f32 D_001DA940;
extern f32 D_002259B0[];
extern void func_0038E530();
extern void func_003877A0();
void func_003E7598(void) {
    func_0038E530(D_001DA944);
    D_002259B0[0] = D_001DA940;
    func_003877A0();
}
/* localdecomp:end func_003E7598 */

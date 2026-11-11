#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005E5FA0);

/* localdecomp:start func_L39_005E5FE8 */
typedef struct {
    s32 pad[3];
    s32 val;
} S_48DA70;
extern u8 D_001A5810[];
extern void func_003A5348(s32 a0, s32 a1, s32 a2);
void func_L39_005E5FE8(s32 buttons) {
    s32 v;
    if (buttons & 0x8000) {
        S_48DA70 *p = &(*(S_48DA70 *)&D_001A5810);
        v = p->val - 30;
        p->val = (v < 0) ? 0 : v;
    } else if (buttons & 0x2000) {
        S_48DA70 *p = &(*(S_48DA70 *)&D_001A5810);
        v = p->val + 30;
        p->val = (v > 1024) ? 1024 : v;
    }
    func_003A5348(3, 0, 0);
}
/* localdecomp:end func_L39_005E5FE8 */

INCLUDE_ASM("asm/levels", func_L39_005E6060);

/* localdecomp:start func_L39_005E60D8 */
extern u8 D_001A5810[];
extern void func_L39_005F3548(s32, s32, s32);
s32 func_L39_005E60D8(s32 a0) {
    if (a0 & 0xA040) {
        u8 *p;
        func_L39_005F3548(4, 0, 0);
        p = D_001A5810;
        p[5] = p[5] == 0;
    }
}
/* localdecomp:end func_L39_005E60D8 */

INCLUDE_ASM("asm/levels", func_L39_005E6118);

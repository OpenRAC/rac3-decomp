#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003931D0 */
/* the copy of func_00392DF0 */
typedef struct { u8 pad[0x18]; s16 h18; u8 pad2[0x17C - 0x1A]; s32 x17C; } S_38E5B8_003931D0;
/* from the US decomp's func_0038E5B8 (rac3-uya-decomp); the types and externs are the file's */
__asm__(".extern D_001D5B74, 4");
__asm__(".extern D_001D9D04, 4");
extern void func_003932D0(void);
extern s32 D_001D4CEC_003931D0_a003931D0 __asm__("D_001D4CEC_003931D0");
extern s32 D_001D4CF0_a003931D0 __asm__("D_001D4CF0_a003931D0");
extern s32 D_001D5B74_a003931D0 __asm__("D_001D5B74");
extern s32 D_001D9D04_a003931D0 __asm__("D_001D9D04_a003931D0");
extern S_38E5B8_003931D0 D_00142430_003931D0_a003931D0[] __asm__("D_00142430_003931D0");
extern s32 D_001D545C_a003931D0 __asm__("D_001D545C_a003931D0");
extern s32 D_001D9D04_a003931D0 __asm__("D_001D9D04");
extern s32 D_001D4CF0_a003931D0 __asm__("D_001D4CF0_a003931D0");
extern s32 D_001D545C_a003931D0 __asm__("D_001D545C");
extern s32 D_001D4CF0_a003931D0 __asm__("D_001D4CF0");
void func_003931D0(s32 a, s32 b) {
    s32 x = a;
    s32 y;
    S_38E5B8_003931D0 *p;
    func_00393120(&x);
    y = x;
    D_001D5B74_a003931D0 = 1;
    D_001D4CF0_a003931D0 = D_001D545C_a003931D0;
    D_001D9D04_a003931D0 = y;
    if (y == -1) {
        p = D_00142430_003931D0_a003931D0;
        if (p->x17C != 0) p->x17C = 0;
        if (p->h18 >= 0) p->h18 = y;
        D_001D4CEC_003931D0_a003931D0 &= ~0x200;
    }
    if (b != 0) {
        func_003932D0();
        if (x != 0x18) func_0039F008(0, D_001D9D04_a003931D0);
        else func_0039F008(0, D_001D4CF0_a003931D0);
    }
}
/* localdecomp:end func_003931D0 */

typedef struct { u8 pad[0x18]; s16 h18; u8 pad2[0x17C - 0x1A]; s32 x17C; } S_38E5B8;
extern S_38E5B8 D_00142430_003931D0[];
extern s32 D_001D5B74;
extern s32 D_001D9D04;
extern s32 D_001D545C;
extern s32 D_001D4CF0;
extern s32 D_001D4CEC_003931D0;
extern void func_0039F008(s32, s32);

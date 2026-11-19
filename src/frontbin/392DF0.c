#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 392A18.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_00392D40(s32 *input_ptr);

typedef struct { u8 pad[0x18]; s16 h18; u8 pad2[0x17C - 0x1A]; s32 x17C; } S_38E5B8;
extern S_38E5B8 D_00142430_00392DF0[];
extern s32 D_001D5B74;
extern s32 D_001D9D04;
extern s32 D_001D545C;
extern s32 D_001D4CF0;
extern s32 D_001D4CEC_00392DF0;
extern void func_0039EC28(s32, s32);
/* localdecomp:start func_00392DF0 */
/* from the US decomp's func_0038E5B8 (rac3-uya-decomp); the types and externs are the file's */
__asm__(".extern D_001D5B74, 4");
__asm__(".extern D_001D9D04, 4");
extern void func_00392EF0(void);
void func_00392DF0(s32 a, s32 b) {
    s32 x = a;
    s32 y;
    S_38E5B8 *p;
    func_00392D40(&x);
    y = x;
    D_001D5B74 = 1;
    D_001D4CF0 = D_001D545C;
    D_001D9D04 = y;
    if (y == -1) {
        p = D_00142430_00392DF0;
        if (p->x17C != 0) p->x17C = 0;
        if (p->h18 >= 0) p->h18 = y;
        D_001D4CEC_00392DF0 &= ~0x200;
    }
    if (b != 0) {
        func_00392EF0();
        if (x != 0x18) func_0039EC28(0, D_001D9D04);
        else func_0039EC28(0, D_001D4CF0);
    }
}
/* localdecomp:end func_00392DF0 */

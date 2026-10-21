#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0039AAC0(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_0039AAC0 */
extern void func_0038CF58(void *, s32, s32);
extern u8 D_0016C690[];
void func_0039AAC0(void) {
    s32 *p;
    s32 i;
    func_0038CF58(D_0016C690, 0, 0x35840);
    *(s16 *)(D_0016C690 + 0x14) = -1;
    p = (s32 *)(D_0016C690 + 0x3C);
    for (i = 2; i >= 0; i--) {
        *p-- = -1;
    }
}
/* localdecomp:end func_0039AAC0 */

/* localdecomp:start func_0039AB28 */
extern s32 D_001D600C;
typedef struct { u8 pad[0x34]; s32 arr[8]; } T_00395958;
extern T_00395958 D_0016C690_0039AB28;
typedef struct { s32 f0; s32 f4; } S_00395958;

void func_0039AB28(S_00395958 *arg0, s32 arg1) {
    if (arg1 != 0) {
        if (arg0->f4 >= 0) {
            D_0016C690_0039AB28.arr[arg0->f4] = arg0->f0;
            if (arg0->f4 == D_001D600C) {
                D_001D600C = arg0->f4 ^ 1;
            }
        }
    }
    arg0->f0 = -1;
}
/* localdecomp:end func_0039AB28 */

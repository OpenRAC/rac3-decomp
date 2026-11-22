#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

typedef struct { unsigned long a, b; s32 c, d; } S_3AD0A0;
extern u8 *D_001DA0B4[];
/* localdecomp:start func_003B2A00 */
extern u8 *D_001DA0B4[];
extern void func_003B2590(u8 *, S_3AD0A0 *);
void func_003B2A00(u8 *p, unsigned long a, unsigned long b, s32 c, s32 d) {
    S_3AD0A0 s;
    s.a = a;
    s.b = b;
    s.c = c - *(s32 *)(p + 0x48);
    s.d = d;
    func_003B2590(D_001DA0B4[0] + 0x48, &s);
}
/* localdecomp:end func_003B2A00 */

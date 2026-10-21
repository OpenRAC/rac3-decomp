#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00398128(s32, s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00398128 */
__asm__(".extern D_001D9F48, 4");
extern s32 D_001D5F00[];
extern s32 D_001D5EE8[];
extern s32 D_001D9F4C;
extern s32 D_001D9F48;
extern void func_13B0C8();
extern void func_003980A0();
typedef struct { u8 pad[0x10]; s32 a; u16 b; u8 pad2[0x1A]; } S_3934E8;
void func_00398128(s32 x, s32 y) {
    S_3934E8 s;
    s32 *p;
    s32 *q;
    p = D_001D5EE8;
    q = &s.a;
    D_001D9F4C = (s32)q;
    s.a = D_001D5F00[0];
    s.b = ((u16 *)D_001D5F00)[2];
    D_001D9F48 = (s32)&s;
    func_13B0C8((u8 *)q + 5);
    func_003980A0(p, 2, &D_001D9F48);
}
/* localdecomp:end func_00398128 */

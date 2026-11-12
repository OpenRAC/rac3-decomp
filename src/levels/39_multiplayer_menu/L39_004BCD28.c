#include "common.h"

/* localdecomp:start func_L39_004BCD28 */
/* best: 7 diff (frame 0x30 vs retail 0x40, save order s0,s1,ra vs s0,ra,s1); body otherwise identical. Looks like ee29 layout; @ee29 needs -fopt-stack removed, cannot test. u64 -> unsigned long needed ("wide integer") */
/* ee29 near miss (needs @ee29 without -fopt-stack): only diff: retail "move a0,v1; sw v0,(a1); jal 4bef28; lw s1,(v1)", ours "move a0; lw s1; jal; sw" (delay slot pick); tried read order, temp for next, *(s32*)n */
typedef struct S_004BCD28 {
    char pad0[12]; u32 div;
    char pad1[24]; unsigned long limit;
    unsigned long count;
    char pad2[64]; unsigned long taken;
    unsigned long misses;
    char pad3[24]; s32 xA0;
} S_004BCD28;
extern s32 *func_L39_004BD178(S_004BCD28 *, s32, void *);
extern void func_L39_004BEF28(void *);
extern void func_L39_004BD050(S_004BCD28 *);
extern long func_00130760(long, long);

s32 func_L39_004BCD28(S_004BCD28 *p, s32 key)
{
    s32 tmp[4];
    s32 *slot;
    s32 *n;
    s32 value;
    p->xA0 = 0;
    slot = func_L39_004BD178(p, key, tmp);
    n = (s32 *)*slot;
    if (n == 0) { p->misses++; return 0; }
    *slot = n[1];
    value = n[0];
    func_L39_004BEF28(n);
    p->taken++; p->count--;
    if (p->div > 16) { if (p->limit >= func_00130760(p->count << 8, p->div)) { func_L39_004BD050(p); } }
    return value;
}
/* localdecomp:end func_L39_004BCD28 */

/* near miss (level 3, Starship Phoenix): 16 differences: logic is right but retail keeps the object pointer in $a0 and loads the field before the lui of the second global, with an unfilled nop in the second bnez delay slot; the C keeps it in $v1 and hoists the lui/lw into the slot; about 10 wordings tried (reassigning a0, nested if vs &&, flat u8 pointer, unsized array, hints 8/16/32, @ps2as) */
#include "common.h"

/* localdecomp:start func_L03_0032E7A0 */
extern u8 D_001BBB30;
__asm__(".extern D_001BBB30, 16");
typedef struct {
    u8 pad0[0x34];
    u16 flags;
    u8 pad1[0xCA];
} S_0032E7A0;
extern S_0032E7A0 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");

typedef struct {
    u8 pad[0x68];
    u8 *p;
} A_0032E7A0;

s32 func_L03_0032E7A0(A_0032E7A0 *a0, s32 a1) {
    s32 r;
    u8 *p;

    p = a0->p;
    r = 0;
    if (a1 == 0 && D_001BBB30 == 0) {
        r = 1;
        D_L03_001DF99C[*(s32 *)(p + 0xDC)].flags &= 0xFFFC;
    }
    return r;
}
/* localdecomp:end func_L03_0032E7A0 */

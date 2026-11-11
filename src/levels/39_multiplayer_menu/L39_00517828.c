#include "common.h"

/* localdecomp:start func_L39_00517828 */
void func_L39_00517828(u8 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 bits = (arg1 & 0xC0) | (arg3 & 0x2F);
    arg0[0x14] = bits;
    arg0[0x16] |= 8;
    if ((arg1 & 0xC0) == 0) {
        if ((u32)(arg2 - 0x10) < 2) {
            arg0[0x14] = bits | 0x20;
        }
    }
    *(u32 *)(arg0 + 0x10) = arg2;
}
/* localdecomp:end func_L39_00517828 */

/* localdecomp:start func_L39_00517868 */
typedef struct {
    unsigned long f0;
    s32 f8;
    u8 padC[0xA];
    u8 flags;
} S_00517868;

/* from rac4-decomp's func_L00_00553678 */
void func_L39_00517868(S_00517868 *p, s32 a, u32 b) {
    p->f0 = b;
    p->f8 = a;
    p->flags |= 8;
}
/* localdecomp:end func_L39_00517868 */

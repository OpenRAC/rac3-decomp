#include "common.h"

/* localdecomp:start func_L41_0041C170 */
/* PAL port of the NTSC-U match src/us/levels/func_L41_0041B870.c */


extern S_0041B870 D_001A5CD0;
extern M_0041C328 *D_L41_0024865C;
__asm__(".extern D_L41_0024865C, 16");
extern s32 D_L41_002405D4;
__asm__(".extern D_L41_002405D4, 16");
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L41_0041C170(void * a0_, s32 a1) {
    u8 * a0 = a0_;

    s32 buf[2];
    s32 *p;

    p = *(s32 **)(a0 + 0x68);
    *p = D_001A5CD0.w128 + a1;
    buf[0] = ((M_0041C328 *)a0 - D_L41_0024865C) & 0xFF;
    buf[1] = *p;
    if (D_001A5CD0.w170 == 0) {
        func_0014AD08(D_001A5CD0.b7D4 | 0x40, D_001A5CD0.w4, -1, D_L41_002405D4, 8, buf);
    }
}
/* localdecomp:end func_L41_0041C170 */

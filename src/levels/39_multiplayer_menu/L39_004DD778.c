#include "common.h"

/* declared by functions of L39_004DB038.c, which this file was cut from */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* localdecomp:start func_L39_004DD778 */
typedef struct {
    char _p0[0x10];
    void (*f10)(s32 arg0, s32 arg1, unsigned long arg2);
} S2_4DD778;
typedef struct {
    S2_4DD778 *f0;
    char _p4[0xC - 0x4];
    s32 fC;
} S1_4DD778;

/* from rac4-decomp's func_L00_00519578 */
void func_L39_004DD778(S1_4DD778 *arg0, s32 arg1, u32 arg2) {
    arg0->f0->f10(arg0->fC, arg1, arg2);
}
/* localdecomp:end func_L39_004DD778 */

INCLUDE_ASM("asm/levels", func_L39_004DD7A8);

/* localdecomp:start func_L39_004DD808 */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void *func_L39_004DBA08(void);

/* from rac4-decomp's func_L00_00519608, renamed */
s32 func_L39_004DD808(void) {
    s32 (*f)(void) = *(s32 (**)(void))((char *)func_L39_004DBA08() + 0x20);
    if (f != 0) {
        return f();
    }
    func_L39_004BC6C8(0xA, 0x68, 0xE, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004DD808 */

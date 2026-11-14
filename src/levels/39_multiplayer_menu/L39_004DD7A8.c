#include "common.h"

/* declared by functions of L39_004DB038.c, which this file was cut from */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* localdecomp:start func_L39_004DD7A8 */
extern void func_0011D534(void *, s32, s32);

typedef struct {
    char _p0[0x8];
    s32 f8;
    char _pC[0x14 - 0xC];
    void (*f14)(s32, void *);
} S2_004DD7A8;
typedef struct {
    S2_004DD7A8 *f0;
    char _p4[0x8 - 0x4];
    s32 f8;
    void *fC;
} S1_004DD7A8;

void func_L39_004DD7A8(S1_004DD7A8 *arg0, s32 arg1, s32 *arg2) {
    arg0->f0->f14(arg1, arg0->fC);
    if (arg2 != 0) {
        *arg2 = arg0->f0->f8;
    }
    func_0011D534(arg0->fC, 0, arg0->f8);
}
/* localdecomp:end func_L39_004DD7A8 */

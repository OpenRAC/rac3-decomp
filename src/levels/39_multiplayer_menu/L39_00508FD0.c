#include "common.h"

/* localdecomp:start func_L39_00508FD0 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} A_00508FD0;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    A_00508FD0 *fC;
} B_00508FD0;

extern void func_L39_004F74E8(void *, s32, s32);
extern void *func_L39_0050DA38(void *, s32, B_00508FD0 *, s32);
extern void func_L39_0050D890(void *);
extern s32 D_L39_0046F0B8[];

void func_L39_00508FD0(s32 arg0, s32 arg1, s32 arg2, A_00508FD0 *arg3) {
    A_00508FD0 a;
    B_00508FD0 b;

    func_L39_004F74E8(&b, 0, sizeof(b));
    b.f4 = arg1;
    b.f8 = arg2;
    a.f0 = arg3->f0;
    a.f4 = arg3->f4;
    a.f8 = 0;
    b.fC = &a;
    func_L39_0050D890(func_L39_0050DA38(D_L39_0046F0B8, 0, &b, arg0));
}
/* localdecomp:end func_L39_00508FD0 */

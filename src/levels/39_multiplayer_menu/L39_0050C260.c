#include "common.h"

/* localdecomp:start func_L39_0050C260 */
typedef struct { void *f0; u8 pad4[4]; s32 f8; void *fC; } S_0050C260;
typedef struct { u8 pad0[0x38]; s32 f38; } P_0050C260;
extern void func_0011D534(void *, s32, s32);
extern void func_L39_004BEF28(void *);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_0050C260(S_0050C260 *s, P_0050C260 *p) {
    if (s->f0 != 0) {
        func_0011D534(s->fC, 0, s->f8);
        if (s->f8 != p->f38) {
            func_L39_004BEF28(s->fC);
            s->fC = 0;
            s->f8 = 0;
        }
    }
    if (p != 0 && s->fC == 0) {
        if ((s->fC = func_L39_004BEED8(p->f38)) == 0) {
            func_L39_004BC6C8(6, 0x76, 0x21, 0, 0);
            return 0;
        }
    }
    s->f0 = p;
    if (p != 0) {
        s->f8 = p->f38;
    }
    if (s->f8 > 0) {
        func_0011D534(s->fC, 0, s->f8);
    }
    return 1;
}
/* localdecomp:end func_L39_0050C260 */

/* localdecomp:start func_L39_0050C338 */
void func_L39_005161F8(void *);
s32 func_L39_00516008();
s32 func_L39_00516228(u8 *, s32);
void func_L39_00516570(void *);
s32 func_L39_00516238(void *, void *);
s32 func_L39_005165D0(void *, s32, s32, s32);
s32 func_L39_00516E78(void *, s32);
void func_L39_005164E8(void *);

s32 func_L39_0050C338(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u8 buf[0xF0] __attribute__((aligned(8)));
    void *ctx;
    s32 r;

    if (arg0 == 0) {
        func_L39_005161F8(buf);
        func_L39_00516228(buf, (s32)func_L39_00516008);
        ctx = buf;
    } else {
        func_L39_00516570(arg0);
        ctx = arg0;
    }
    if (arg1 == 0 || (r = func_L39_00516238(ctx, arg1)) == 0) {
        r = func_L39_005165D0(ctx, arg3, arg4, arg5);
        if (r == 0) {
            r = func_L39_00516E78(ctx, arg2);
        }
    }
    if (arg0 == 0) {
        func_L39_005164E8(buf);
    }
    return r;
}
/* localdecomp:end func_L39_0050C338 */

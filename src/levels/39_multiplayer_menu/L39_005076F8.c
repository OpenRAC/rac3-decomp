#include "common.h"

/* declared by functions of L39_005076E0.c, which this file was cut from */
extern u8 D_L39_00507B18[];

/* localdecomp:start func_L39_005076F8 */
s32 func_L39_004F5D38(void *, void *, s32, s32);
s32 func_L39_005089B0(void *, s32, s32, s32, s32);
typedef struct P_005076F8 { s32 f0; s32 f4; } P_005076F8;
typedef struct V_005076F8 { u8 pad[0x8]; s32 (*fn)(void *, s32, s32, s32); } V_005076F8;
typedef struct O_005076F8 { u8 pad[0x8]; P_005076F8 *f8; V_005076F8 *vt; } O_005076F8;
typedef struct C_005076F8 { u8 pad[0x28]; O_005076F8 *f28; s32 f2C; } C_005076F8;

s32 func_L39_005076F8(C_005076F8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 ret;
    P_005076F8 *p;

    ret = func_L39_004F5D38(arg0, D_L39_00507B18, arg2, arg3);
    if (ret != 0) {
        return ret;
    }
    arg0->f28->f8 = 0;
    ret = arg0->f28->vt->fn(arg0->f28, arg1, arg2, arg3);
    if (ret != 0) {
        return ret;
    }
    p = arg0->f28->f8;
    if (p != 0) {
        ret = func_L39_005089B0(arg0, p->f4, 1, p->f0, arg2);
        if (ret != 0) {
            return ret;
        }
    }
    arg0->f2C |= 1;
    return 0;
}
/* localdecomp:end func_L39_005076F8 */

/* localdecomp:start func_L39_005077B8 */
s32 func_L39_004F5D38(void *, void *, s32, s32);
s32 func_L39_005089B0(void *, s32, s32, s32, s32);
typedef struct P_005077B8 { s32 f0; s32 f4; } P_005077B8;
typedef struct V_005077B8 { u8 pad[0xC]; s32 (*fn)(void *, s32, s32, s32); } V_005077B8;
typedef struct O_005077B8 { u8 pad[0x8]; P_005077B8 *f8; V_005077B8 *vt; } O_005077B8;
typedef struct C_005077B8 { u8 pad[0x28]; O_005077B8 *f28; s32 f2C; } C_005077B8;

s32 func_L39_005077B8(C_005077B8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 ret;
    P_005077B8 *p;

    ret = func_L39_004F5D38(arg0, D_L39_00507B18, arg2, arg3);
    if (ret != 0) {
        return ret;
    }
    arg0->f28->f8 = 0;
    ret = arg0->f28->vt->fn(arg0->f28, arg1, arg2, arg3);
    if (ret != 0) {
        return ret;
    }
    p = arg0->f28->f8;
    if (p != 0) {
        ret = func_L39_005089B0(arg0, p->f4, 0, p->f0, arg2);
        if (ret != 0) {
            return ret;
        }
    }
    arg0->f2C |= 1;
    return 0;
}
/* localdecomp:end func_L39_005077B8 */

#include "common.h"

/* NTSC-U counterpart of func_L40_003EBBE0 (src/levels/shared/L40_003EBB98.c) */
/* localdecomp:start func_L40_003EB788 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003EBBE0;
typedef struct {
    f32 x, y, z, w;
    s32 a1;
    s32 a3;
    s32 index;
} Msg_003EBBE0;
extern u8 *D_L40_002485DC[] __attribute__((section(".sdata")));
extern s32 D_001A5F78[];
extern s32 func_L40_003EB740(s32 id);
extern u8 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32 type, s32 uid, s32 time, s32 kind, u8 *msg);
extern s32 func_00197588(s32 n);

s32 func_L40_003EB788(V_003EBBE0 *pos, s32 a1, s32 index, s32 a3) {
    V_003EBBE0 p = *pos;
    s32 r;
    u8 *msg;
    s32 uid;
    s32 n;
    Msg_003EBBE0 *q;

    r = func_L40_003EB740((s32)(D_L40_002485DC[0] + (index << 8)));
    if (r != -1) {
        return r;
    }
    msg = func_L39_006699B0();
    if (msg == 0) {
        return -2;
    }
    uid = func_00197588(2);
    n = func_L39_00669978(0, uid, D_001A5F78[0] + 500, 0x109A, msg);
    q = (Msg_003EBBE0 *)(msg + n);
    q->x = p.x;
    q->y = p.y;
    q->z = p.z;
    q->w = p.w;
    q->a1 = a1;
    q->a3 = a3;
    q->index = index;
    *(s32 *)msg = n + 0x1C;
    return uid;
}
/* localdecomp:end func_L40_003EB788 */

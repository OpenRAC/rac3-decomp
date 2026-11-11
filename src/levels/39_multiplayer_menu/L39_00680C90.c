#include "common.h"

typedef struct S_00680198 {
    u8 pad[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_00680198;

/* declared by functions of L39_0067FAE8.c, which this file was cut from */
s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00516AA0(s32, s32, s32);
s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L39_00680C90 */
s32 func_L01_00516FD8(s32, void *);
s32 func_L01_00516AA0(s32, s32, s32);
s32 func_L01_005170B8(s32, s32);
s32 func_L01_00516470(s32, f32, f32);
s32 func_L01_00516C78(s32, s32, s32);
s32 func_L39_00611628(s32, void *);

void func_L39_00680C90(void *arg0) {
    u8 *p = arg0;
    u32 color;
    s32 st;
    f32 x, y;
    f32 x2, y2;
    f32 r[4];

    if (*(s32 *)(p + 0x1470) == -1) {
        return;
    }
    if (*(s32 *)(p + 0x4) == 0) {
        func_L01_00516AA0(*(s32 *)(p + 0x1470), 1, 0);
        func_L01_00516AA0(*(s32 *)(p + 0x1474), 1, 0);
        func_L01_00516AA0(*(s32 *)(p + 0x1478), 1, 0);
        return;
    }
    func_L01_00516AA0(*(s32 *)(p + 0x1470), 1, 1);
    func_L01_00516AA0(*(s32 *)(p + 0x1474), 1, 1);
    func_L01_00516AA0(*(s32 *)(p + 0x1478), 1, 1);
    st = *(s32 *)(p + 0x4);
    if (st == 2) {
        color = 0x80808080;
    } else if (st == 3) {
        color = 0x8066CCFF;
    } else if (st == 4) {
        color = 0x66D6EEFA;
    } else if (st == 5) {
        color = 0x66D6EEFA;
    } else {
        color = 0x8066CCFF;
    }
    (*(void (**)(void *, f32 *, f32 *))(*(u8 **)(p + 0x60) + 0x30))(p, &x, &y);
    r[2] = x;
    if (p[0x14] != 0) {
        func_L01_005170B8(*(s32 *)(p + 0x1470), color);
        func_L01_00516FD8(*(s32 *)(p + 0x1470), p + 0x14);
        func_L01_00516470(*(s32 *)(p + 0x1470), x, y);
        func_L39_00611628(*(s32 *)(p + 0x1470), r);
        func_L01_00516470(*(s32 *)(p + 0x1474), r[2] + 0.005f, y);
        func_L01_005170B8(*(s32 *)(p + 0x1474), color);
        r[2] = r[2] + 0.015f;
    }
    if (*(s32 *)(p + 0x147C) != 0) {
        (*(void (**)(void *, f32 *, f32 *))(*(u8 **)(p + 0x60) + 0x30))(p, &x2, &y2);
        func_L01_00516470(*(s32 *)(p + 0x1478), x2 + *(f32 *)(p + 0x58), y2);
    } else {
        func_L01_00516C78(*(s32 *)(p + 0x1478), 2, 3);
        func_L01_00516470(*(s32 *)(p + 0x1478), *(f32 *)(p + 0x50) + *(f32 *)(p + 0x58), y);
    }
    func_L01_005170B8(*(s32 *)(p + 0x1478), color);
    func_L01_00516FD8(*(s32 *)(p + 0x1478), p + 0x68 + *(s32 *)(p + 0x1468) * 0x50);
}
/* localdecomp:end func_L39_00680C90 */

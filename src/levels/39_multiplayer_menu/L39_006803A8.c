#include "common.h"

typedef struct S_00680198 {
    u8 pad[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_00680198;

/* declared by functions of L39_0067FAE8.c, which this file was cut from */
s32 func_L01_00516AA0(s32, s32, s32);
s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L39_006803A8 */
s32 func_L01_00516FD8(s32, void *);
s32 func_L01_00516AA0(s32, s32, s32);
s32 func_L01_005170B8(s32, s32);
s32 func_L01_00516470(s32, f32, f32);
void func_L39_00611628(s32, f32 *);
void *func_00381FF0(s32);

void func_L39_006803A8(void *arg0) {
    u8 *p = arg0;
    u32 color;
    s32 st;
    f32 x, y;
    f32 v[4];

    if (*(s32 *)(p + 0x68) == -1) {
        return;
    }
    if (*(s32 *)(p + 0x4) == 0) {
        func_L01_00516AA0(*(s32 *)(p + 0x68), 1, 0);
        func_L01_00516AA0(*(s32 *)(p + 0x6C), 1, 0);
        func_L01_00516AA0(*(s32 *)(p + 0x70), 1, 0);
        return;
    }
    func_L01_00516AA0(*(s32 *)(p + 0x68), 1, 1);
    func_L01_00516AA0(*(s32 *)(p + 0x6C), 1, 1);
    func_L01_00516AA0(*(s32 *)(p + 0x70), 1, 1);
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
    func_L01_00516470(*(s32 *)(p + 0x68), x, y);
    func_L01_00516470(*(s32 *)(p + 0x70), x + *(f32 *)(p + 0x58), y);
    func_L39_00611628(*(s32 *)(p + 0x68), v);
    x = v[2] + 0.005f;
    func_L01_00516470(*(s32 *)(p + 0x6C), x, y);
    func_L01_005170B8(*(s32 *)(p + 0x6C), color);
    func_L01_005170B8(*(s32 *)(p + 0x68), color);
    func_L01_005170B8(*(s32 *)(p + 0x70), color);
    func_L01_00516FD8(*(s32 *)(p + 0x68), p + 0x14);
    if (*(u8 *)(p + 0x64)) {
        func_L01_00516FD8(*(s32 *)(p + 0x70), func_00381FF0(0x102B));
    } else {
        func_L01_00516FD8(*(s32 *)(p + 0x70), func_00381FF0(0x102C));
    }
}
/* localdecomp:end func_L39_006803A8 */

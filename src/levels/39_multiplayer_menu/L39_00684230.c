#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* declared by functions of L39_00681758.c, which this file was cut from */
extern s32 func_L01_00516AA0(s32, s32, s32);
s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L39_00611628(s32);

/* localdecomp:start func_L39_00684230 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00518010(s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_003825F8(u32, u32, s32, s32, s32, s32);

void func_L39_00684230(void *arg0) {
    f32 buf[4];
    f32 x;
    f32 y;
    f32 x2;
    f32 y2;
    s32 color;

    if (*(s32 *)((u8 *)arg0 + 0xB4) == -1) {
        return;
    }
    func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0xB4), 1, 0);
    func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0xB8), 1, 0);
    if (*(s32 *)((u8 *)arg0 + 0x4) == 0) {
        func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0xBC), 1, 0);
        return;
    }
    func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0xBC), 1, 1);
    if (*(s32 *)((u8 *)arg0 + 0x4) == 2) {
        color = 0x80808080;
    } else if (*(s32 *)((u8 *)arg0 + 0x4) == 3) {
        color = *(s32 *)((u8 *)arg0 + 0xC8);
    } else if (*(s32 *)((u8 *)arg0 + 0x4) == 4) {
        color = func_003825F8(0x8066CCFF, 0x66D6EEFA, 0x25, 1, 0, 1);
    } else if (*(s32 *)((u8 *)arg0 + 0x4) == 5) {
        color = 0x66D6EEFA;
    } else {
        color = *(s32 *)((u8 *)arg0 + 0xC8);
    }
    (*(void (**)(void *, f32 *, f32 *))(*(u8 **)((u8 *)arg0 + 0x60) + 0x30))(arg0, &x, &y);
    if (*((u8 *)arg0 + 0x14) != 0) {
        func_L01_00516FD8(*(s32 *)((u8 *)arg0 + 0xB4), (s32)((u8 *)arg0 + 0x14));
        func_L01_00516470(*(s32 *)((u8 *)arg0 + 0xB4), x, y);
        func_L01_005170B8(*(s32 *)((u8 *)arg0 + 0xB4), color);
        ((s32 (*)(s32, f32 *))func_L39_00611628)(*(s32 *)((u8 *)arg0 + 0xB4), buf);
        x = buf[2] + 0.005f;
        func_L01_00516470(*(s32 *)((u8 *)arg0 + 0xB8), x, y);
        func_L01_005170B8(*(s32 *)((u8 *)arg0 + 0xB8), color);
        ((s32 (*)(s32, f32 *))func_L39_00611628)(*(s32 *)((u8 *)arg0 + 0xB8), buf);
        x = buf[2] + 0.005f;
        func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0xB4), 1, 1);
        func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0xB8), 1, 1);
    }
    if (*(s32 *)((u8 *)arg0 + 0xC0) != 0) {
        (*(void (**)(void *, f32 *, f32 *))(*(u8 **)((u8 *)arg0 + 0x60) + 0x30))(arg0, &x2, &y2);
        if (*((u8 *)arg0 + 0xCC) != 0) {
            if (func_L01_00518010(*(s32 *)((u8 *)arg0 + 0xBC), 1) != 0) {
                func_003E8898(*(s32 *)((u8 *)arg0 + 0xBC), x2 + *(f32 *)((u8 *)arg0 + 0x58) - x, 0.0f);
            }
        }
        func_L01_00516470(*(s32 *)((u8 *)arg0 + 0xBC), x2 + *(f32 *)((u8 *)arg0 + 0x58), y2);
    } else {
        func_L01_00516470(*(s32 *)((u8 *)arg0 + 0xBC), x, y);
    }
    func_L01_00516FD8(*(s32 *)((u8 *)arg0 + 0xBC), (s32)((u8 *)arg0 + 0x64));
    func_L01_005170B8(*(s32 *)((u8 *)arg0 + 0xBC), color);
}
/* localdecomp:end func_L39_00684230 */

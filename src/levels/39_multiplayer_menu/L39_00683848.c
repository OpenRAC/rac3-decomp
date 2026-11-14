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
extern void func_L39_0067EEC8(u8 *, s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern S_00683550 *func_L39_0067EE40(void *, void *);
s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00516AA0(s32, s32, s32);

/* declared by functions of L39_00683718.c, which this file was cut from */
extern s32 func_003E7F20(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L39_00683848 */
#include "vu0.h"
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L39_00611628(s32);

void func_L39_00683848(void *arg0) {
    f32 r[4];
    f32 v[2];
    f32 x, y, w, h;

    if (*(s32 *)((u8 *)arg0 + 0x68) == -1) {
        return;
    }
    func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x64), 1, *(s32 *)((u8 *)arg0 + 0x4) != 0);
    func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x68), 1, *(s32 *)((u8 *)arg0 + 0x4) != 0);
    func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x6C), 1, *(s32 *)((u8 *)arg0 + 0x4) != 0);
    func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x70), 1, *(s32 *)((u8 *)arg0 + 0x4) != 0);
    if (*(s32 *)((u8 *)arg0 + 0x4) == 0) {
        return;
    }
    (*(s32 (**)(void *, void *, void *))((u8 *)(*(void **)((u8 *)arg0 + 0x60)) + 0x30))(arg0, v, &v[1]);
    func_L01_00516470(*(s32 *)((u8 *)arg0 + 0x64), v[0], v[1]);
    func_L01_00516FD8(*(s32 *)((u8 *)arg0 + 0x64), (s32)((u8 *)arg0 + 0x14));
    func_L01_005170B8(*(s32 *)((u8 *)arg0 + 0x64), 0x8066CCFF);
    func_003E7F20(*(s32 *)((u8 *)arg0 + 0x64), 1);
    func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x64), *(s32 *)((u8 *)arg0 + 0x74), 3);
    ((s32 (*)(s32, f32 *))func_L39_00611628)(*(s32 *)((u8 *)arg0 + 0x64), r);
    x = (r[2] + r[0]) * 0.5f;
    y = (r[3] + r[1]) * 0.5f + -0.003f;
    w = fabs_asm(r[2] - r[0]) + 0.022f;
    h = fabs_asm(r[3] - r[1]) + 0.022f;
    func_L01_00516470(*(s32 *)((u8 *)arg0 + 0x68), x, y);
    func_L01_00516470(*(s32 *)((u8 *)arg0 + 0x6C), x, y);
    func_L01_00516470(*(s32 *)((u8 *)arg0 + 0x70), x + 0.008f, y + 0.01f);
    func_L01_00517538(*(s32 *)((u8 *)arg0 + 0x68), w, h);
    func_L01_00517538(*(s32 *)((u8 *)arg0 + 0x6C), w, h);
    func_L01_00517538(*(s32 *)((u8 *)arg0 + 0x70), w, h);
}
/* localdecomp:end func_L39_00683848 */

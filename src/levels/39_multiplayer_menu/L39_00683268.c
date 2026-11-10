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
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L39_00683268 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);

void func_L39_00683268(void *arg0) {
    u8 *self = arg0;
    f32 x, y, w, h;
    f32 pos;

    if (*(s32 *)(self + 0x70) == -1) {
        return;
    }
    if (*(s32 *)(self + 0x80) > *(s32 *)(self + 0x7C)) {
        *(s32 *)(self + 0x80) = *(s32 *)(self + 0x7C);
    } else if (*(s32 *)(self + 0x80) < *(s32 *)(self + 0x78)) {
        *(s32 *)(self + 0x80) = *(s32 *)(self + 0x78);
    }
    func_L01_00516AA0(*(s32 *)(self + 0x70), 1, *(s32 *)(self + 0x4) != 0);
    func_L01_00516AA0(*(s32 *)(self + 0x74), 1, *(s32 *)(self + 0x4) != 0);
    func_L01_00516AA0(*(s32 *)(self + 0x6C), 1, *(s32 *)(self + 0x4) != 0);
    if (*(s32 *)(self + 0x4) != 0) {
        (*(Vt_00685D48 **)(self + 0x60))->f30(self, &x, &y);
        (*(Vt_00685D48 **)(self + 0x60))->f34(self, &w, &h);
        func_L01_00516470(*(s32 *)(self + 0x6C), x, y);
        func_L01_00517538(*(s32 *)(self + 0x6C), *(f32 *)(self + 0x58), *(f32 *)(self + 0x5C) * 0.4f);
        pos = func_003C4088(x - w * 0.5f + h * 0.25f, x + w * 0.5f - h * 0.25f,
                            (f32)(*(s32 *)(self + 0x80) - *(s32 *)(self + 0x78)) /
                            (f32)(*(s32 *)(self + 0x7C) - *(s32 *)(self + 0x78)));
        func_L01_00516470(*(s32 *)(self + 0x70), pos, y);
        func_L01_00516470(*(s32 *)(self + 0x74), pos, y);
        func_L01_00517538(*(s32 *)(self + 0x70), *(f32 *)(self + 0x5C) * 0.5f, *(f32 *)(self + 0x5C));
        func_L01_00517538(*(s32 *)(self + 0x74), *(f32 *)(self + 0x5C) * 0.5f, *(f32 *)(self + 0x5C));
    }
}
/* localdecomp:end func_L39_00683268 */

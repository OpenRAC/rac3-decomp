#include "common.h"

/* localdecomp:start func_L39_0068D9D8 */
__asm__(".extern D_L39_0024D760, 16");
extern s32 *D_L39_0024D760;
extern u8 D_L39_00247C30[];
extern s32 func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern u8 *func_00381FF0(s32);
extern void func_L39_00689BD8(void *, u8 *);
extern void func_L39_00689D28(void *, u8 *);
extern void func_L39_00689E58(void *, u8 *, u32, f32, f32);
extern void func_L39_00689DB8(void *, u8 *);
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A7B8(void *, s32, u32, f32, f32, f32, f32);
extern void func_L39_0068AAB8(void *);

void func_L39_0068D9D8(u8 *self) {
    void *args[5];
    s32 *d;
    s32 n;

    func_L39_0067F100(0x220000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(self, func_00381FF0(0xFFE));
    func_L39_00689D28(self, func_00381FF0(0x218));
    func_L39_00689E58(self, func_00381FF0(0x1924), 0x706EC8FF, 0.7f, 1.0f);
    func_L39_00689DB8(self, func_00381FF0(0xCD5));
    func_L39_0068A6D0(self, 0, 0.5f, 0.27f, 0.82f, 0.27f, 0x332299DE);
    func_L39_0068A6D0(self, 1, 0.5f, 0.635f, 0.82f, 0.45f, 0x332299DE);
    func_L39_0068A7B8(self, 0, 0x331465B7, 0.5f, 0.43f, 0.41f, 0.78f);
    func_L39_0068AAB8(self);
    d = (s32 *)D_L39_0024D760[0x38 / 4];
    args[0] = func_00381FF0(0x1014);
    n = 1;
    if (*d >= 0) {
        u8 *sep = D_L39_00247C30;
        args[1] = sep;
        args[2] = func_00381FF0(0x1608);
        args[3] = sep;
        args[4] = func_00381FF0(0x1010);
        n = 5;
    }
    {
        u8 *o = *(u8 **)(self + 0x114);
        (*(void (**)(void *, s32, void **))(*(u8 **)(o + 0x60) + 0x6C))(o, n, args);
    }
    {
        u8 *o = *(u8 **)(self + 0x114);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x20))(o, 2, 0);
    }
    {
        u8 *o = *(u8 **)(self + 0x114);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 1, 0);
    }
    {
        u8 *o = *(u8 **)(self + 0x114);
        (*(void (**)(void *, s32))(*(u8 **)(o + 0x60) + 0x84))(o, 1);
    }
    {
        u8 *o = *(u8 **)(self + 0x114);
        (*(void (**)(void *, s32))(*(u8 **)(o + 0x60) + 0x40))(o, 1);
    }
    self[0x2A8] = 1;
    *(s32 *)(self + 0x770) = 0;
    *(f32 *)(self + 0x774) = 50.0f;
    self[0x2B8] = 1;
}
/* localdecomp:end func_L39_0068D9D8 */

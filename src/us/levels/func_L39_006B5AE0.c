#include "common.h"

/* NTSC-U counterpart of func_L39_006B84E8 (src/levels/39_multiplayer_menu/L39_006B8458.c) */
extern s32 func_0037DF98(s32);
extern void func_L39_006B6010(void *, s32);

/* localdecomp:start func_L39_006B5AE0 */
extern s32 func_0037DF98(s32);
extern void func_L39_006B6010(void *, s32);
extern s32 func_0011D2EC(void *, void *, s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L39_006872B0(void *, s32, u32, f32, f32);
extern void func_L39_00687210(void *, s32);
extern void func_L39_006B5488(s32, s32, s32, s32, s32);
extern s32 D_001DDA10_sda;
extern s32 D_001DDA04_sda;
extern u8 D_L39_0037C948[];
extern u8 D_L39_001FC830[];
extern u8 D_L39_00249450_006B5AE0[];
extern s32 D_001A4568[];

void func_L39_006B5AE0(void *p) {
    u8 buf[32];
    void *obj;
    s32 s;

    obj = *(void **)((u8 *)p + 0x128);
    D_001DDA10_sda = (*(s32 (**)(void *))(*(u8 **)((u8 *)obj + 0x60) + 0x8C))(obj);
    func_L39_006B6010(p, 1);
    if (func_0011D2EC(D_L39_0037C948 + D_001DDA04_sda * 0x1F0, D_L39_001FC830 + D_001DDA04_sda * 0x1F0, 0x1F0)) {
        func_00120048(buf, D_L39_00249450_006B5AE0, func_0037DF98(0x1256));
        *(s32 *)((u8 *)p + 0x2A8) = 1;
    } else {
        func_00120048(buf, D_L39_00249450_006B5AE0, func_0037DF98(0x100));
        *(s32 *)((u8 *)p + 0x2A8) = 1;
    }
    s = func_0037DF98(0x1CAB);
    if (D_001A4568[0] != 2) {
        func_L39_006872B0(p, s, 0x80404040, 1.0f, 1.0f);
    } else {
        func_L39_006872B0(p, s, 0x706EC8FF, 1.0f, 1.0f);
    }
    func_L39_00687210(p, func_0037DF98(0x100));
    obj = *(void **)((u8 *)p + 0x110);
    (*(void (**)(void *, s32, s32))(*(u8 **)((u8 *)obj + 0x60) + 0x1C))(obj, 3, 0);
    obj = *(void **)((u8 *)p + 0x118);
    if ((*(s32 (**)(void *))(*(u8 **)((u8 *)obj + 0x60) + 0x64))(obj) != 0) {
        obj = *(void **)((u8 *)p + 0x11C);
        (*(void (**)(void *, s32, s32))(*(u8 **)((u8 *)obj + 0x60) + 0x1C))(obj, 3, 0);
    } else {
        obj = *(void **)((u8 *)p + 0x11C);
        (*(void (**)(void *, s32, s32))(*(u8 **)((u8 *)obj + 0x60) + 0x1C))(obj, 2, 0);
    }
    func_L39_006B5488(1, 0x123, 0x1CC, 0, 0x1A0);
    obj = *(void **)((u8 *)p + 0x130);
    (*(void (**)(void *, u32))(*(u8 **)((u8 *)obj + 0x60) + 0x50))(obj, 0x80CCCCCC);
}
/* localdecomp:end func_L39_006B5AE0 */

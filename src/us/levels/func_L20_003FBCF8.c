#include "common.h"

/* NTSC-U counterpart of func_L20_003FDFE8 (src/levels/20_final_boss/L20_003FB630.c) */
/* localdecomp:start func_L20_003FBCF8 */
extern s32 func_L20_003FC0E0(void *);
extern void func_L20_003FC6B0(void *, s32);
extern void func_003BD360(void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_00388BD0(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern s32 func_L20_003F9120(void *);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L20_003FCAE0(void *);
extern void func_003C1A60(void *, s32 *, s32 *, s32 *);
extern void func_L01_00438908(void *, s32, s32, s32);
extern void func_L01_00452B20(void *, void *, void *);
extern s32 func_L01_0044F5E8(void *, void *, s32);
extern void func_L01_004538E0(void *, s32);
extern void func_L01_004539A8(void *, s32, f32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32);

s32 func_L20_003FBCF8(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    u8 saved;
    s32 t;
    s32 x;
    s32 y;
    s32 z;

    if (obj[0x20] == 0) {
        if (func_L20_003FC0E0(obj) != 0) {
            return 1;
        }
    }
    if (p[0x5E] != 0) {
        func_L20_003FC6B0(obj, 0);
        func_003BD360(obj);
        return 1;
    }
    if (*(u8 **)(p + 0x3EC) != 0) {
        func_003BDA38(obj, 0, *(u8 **)(p + 0x3EC) + 0x10);
        if ((*(unsigned long *)(obj + 0x30) & 0x104100000000L) != 0x4100000000L || *(s32 *)(obj + 0x98) != 0) {
            *(s32 *)(*(u8 **)(p + 0x3EC) + 0xF0) = 0;
            *(s32 *)(*(u8 **)(p + 0x3EC) + 0xF4) = 0;
            func_00388BD0(*(u8 **)(p + 0x3EC) + 0xC0, *(u8 **)(p + 0x3EC) + 0xF0);
            func_00388EB8(*(u8 **)(p + 0x3EC) + 0xC0, obj + 0xC0, *(u8 **)(p + 0x3EC) + 0xC0);
        }
    }
    if (p[0x3E] == 2) {
        func_L20_003FC6B0(obj, 0);
        return 1;
    }
    t = func_L20_003F9120(obj);
    saved = obj[0x94];
    if (func_L01_0044FCD0(obj, p + 0x160, 0, 0, *(s16 *)(p + 0x3DA)) != 0) {
        if (obj[0x94] == 2 || obj[0x94] == 0x10 || obj[0x94] == 0x11 || obj[0x94] == 0x12) {
            obj[0x94] = saved;
        }
        func_003BE4F0(obj, obj[0x43], 0, 3);
        func_003BE4F0(*(u8 **)(p + 0x3EC), (*(u8 **)(p + 0x3EC))[0x43], 0, 3);
        if (t != 0) {
            func_003BE4F0(obj, obj[0x43], 0, 0);
        }
        func_L20_003FCAE0(obj);
    }
    obj[0xA8] = 0xFF;
    if (*(u8 **)(p + 0x3EC) != 0) {
        func_003C1A60(obj, &x, &y, &z);
        func_L01_00438908(*(u8 **)(p + 0x3EC), x, y, z);
        func_L01_00452B20(*(u8 **)(p + 0x3EC), *(u8 **)(*(u8 **)(p + 0x3EC) + 0x68) + 0x30, p + 0x30);
    }
    func_L01_0044F5E8(obj, p + 0x30, 0);
    if (p[0x5F] != 0) {
        *(s16 *)(p + 0x3F4) = 0;
        *(s32 *)(p + 0x3E0) = 1;
        *(s32 *)(p + 0x394) = 1;
        *(s32 *)(p + 0x398) = 0;
        if ((*(unsigned long *)(obj + 0x30) & 0x104100000000L) != 0x4100000000L || *(s32 *)(obj + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) {
                func_L01_004538E0(obj, 5);
            }
        }
        if (obj[0x95] == 0) {
            func_L01_004539A8(obj, *(s32 *)(p + 0x370), *(f32 *)(p + 0x374), 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_004539A8(obj, *(s32 *)(p + 0x378), *(f32 *)(p + 0x37C), 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        }
    } else {
        if ((*(unsigned long *)(obj + 0x30) & 0x104100000000L) != 0x4100000000L || *(s32 *)(obj + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) {
                func_L01_004538E0(obj, 3);
            }
        }
        if (obj[0x95] == 0) {
            func_L01_004539A8(obj, *(s32 *)(p + 0x370), *(f32 *)(p + 0x374), 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 1);
        } else {
            func_L01_004539A8(obj, *(s32 *)(p + 0x378), *(f32 *)(p + 0x37C), 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 1);
        }
    }
    return 0;
}
/* localdecomp:end func_L20_003FBCF8 */

#include "common.h"

/* NTSC-U counterpart of func_L30_003417B8 (src/levels/30_vidcomic_unnamed/L30_003417B8.c) */
/* localdecomp:start func_L30_00340B50 */
extern s32 func_L01_00458A08(u8 *, f32);
extern void func_L30_003411D0(u8 *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L01_004576E8(u8 *);
extern void func_L01_00457440(void *, void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452EC8(u8 *);
extern s32 func_L01_0032FE90_00340B50(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BD360(void *);
extern void func_L30_00341120(u8 *);
extern void func_L30_003413C8(u8 *);
extern void func_L30_00340F38(u8 *);
extern u8 D_L30_001E9018_00340B50[];
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003417B8;
extern s32 D_001A71A0[];

void func_L30_00340B50(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);

    func_L01_00458A08(o, 3.1415927f);
    switch (o[0x20]) {
    case 0:
        func_L30_003411D0(o);
        func_L01_00441FB8(o, 1, -1);
        break;
    case 1:
        if (*(s16 *)(v + 0x130) != 0 && *(s16 *)(v + 0x234) == 1) {
            func_L01_00441FB8(o, 2, -1);
            break;
        }
        func_L01_004576E8(o);
        break;
    case 2: {
        f32 k = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
        f32 s;
        f32 dx;
        s32 hit = 0;
        V4_003417B8 d, a, b, c;

        s = -1.0f;
        if (*(s32 *)(v + 0x298) != 0) {
            s = 1.0f;
        }
        dx = k * s;
        a = *(V4_003417B8 *)(o + 0x10);
        c = b = d = a;
        d.z += k * 0.7f;
        a.z += k * 0.7f;
        a.x += dx;
        b.z += k * 0.7f;
        b.x += k * 0.8f * s;
        c.z += k * -0.15f;
        c.x += k * 0.8f * s;
        if (func_003CE740(&d, &a, 0x10, o, 0) != 0) {
            hit = *(s32 *)D_L30_001E9018_00340B50 != D_001A71A0[0];
        }
        if (func_003CE740(&b, &c, 0x12, o, 0) == 0) {
            hit = 1;
        }
        if (hit) {
            s32 t = *(s32 *)(v + 0x298) == 0;
            *(s32 *)(v + 0x298) = t;
            if (t) {
                if (o[0x43] != 2) {
                    func_003BE4F0(o, 2, 0, 10);
                }
            } else {
                if (o[0x43] != 0) {
                    func_003BE4F0(o, 0, 0, 10);
                }
            }
        } else {
            V4_003417B8 e = *(V4_003417B8 *)(o + 0x10);
            e.x += dx;
            func_L01_00457440(o, &e);
        }
        break;
    }
    case 3:
        if (o[0x43] != 1) {
            func_003BE4F0(o, 1, 0, 0);
        }
        func_L01_00441FB8(o, 0x42, -1);
        break;
    case 0x42:
        if (func_L01_00452EC8(o)) {
            func_L01_0032FE90_00340B50(o + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.9f, 0.0f, 0.0f, 2.0f,
                              1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            ((s32 (*)(s32, s32, void *))func_0039FE80)(1, 0, o);
            *(s32 *)(o + 0x98) = 0;
            *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(o, 1);
            if (*(void **)(v + 0x2A0) != 0) {
                func_003BD360(*(void **)(v + 0x2A0));
            }
            *(void **)(v + 0x2A0) = 0;
            return;
        }
        break;
    }
    func_L30_00341120(o);
    func_L30_003413C8(o);
    func_L30_00340F38(o);
}
/* localdecomp:end func_L30_00340B50 */

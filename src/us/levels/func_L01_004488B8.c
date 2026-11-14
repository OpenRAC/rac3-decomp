#include "common.h"

/* NTSC-U counterpart of func_L01_0044BB30 (src/levels/shared/L01_0044AF68.c) */
#include "vu0.h"

/* localdecomp:start func_L01_004488B8 */
typedef struct {
    s32 v[6];
} T6_0044BB30;
typedef struct {
    u8 pad0[0x20];
    f32 r;
    f32 g;
    f32 b;
} L_0044BB30;
extern T6_0044BB30 D_L01_001D7BF8_004488B8;
extern T6_0044BB30 D_L01_001D7C10_004488B8;
extern L_0044BB30 D_L01_002E9D20;
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00461128(u8 *, vu0_v4 *, s32, s32, f32, s32, s32, s32, s32, f32);
extern void func_L01_002F95A0(u8 *, u8 *, vu0_v4 *, s32, s32, s32, s32, s32, f32);
extern s8 func_0039FE80(s32, s32, s32);
extern void func_L01_00300650(u8 *, u8 *, s32, s32);

void func_L01_004488B8(u8 *mob, u8 *pos, s32 snd, f32 scale, f32 light) {
    vu0_v4 col;
    T6_0044BB30 a;
    T6_0044BB30 b;
    s32 i;
    f32 size;
    f32 speed;
    s32 *pa;
    s32 *pb;
    s32 x;

    qzero(&col);
    for (i = 0; i < 3; i++) {
        speed = func_0037E250(8.0f, 10.0f) * 0.016666668f;
        size = scale * 400000.0f;
        a = D_L01_001D7BF8_004488B8;
        b = D_L01_001D7C10_004488B8;
        pa = &a.v[func_0037E1D8(6)];
        pb = &b.v[func_0037E1D8(6)];
        x = func_0037E208(15, 20);
        func_L01_00461128(pos, &col, *pa, *pb, size, x, func_0037E208(25, 30), 0, 0, speed * scale);
    }
    if (mob != 0) {
        func_L01_002F95A0(mob, pos, &col, 20, 0x7F, 0x40, 0, 0x30, scale * 4.0f);
        func_L01_002F95A0(mob, pos, &col, 29, 0x60, 0x20, 0, 0x20, scale * 3.0f);
        if (mob[0x20] != 0xFE) {
            if (mob[0x20] != 0xFD) {
                if (snd != -1) {
                    func_0039FE80(snd, 0, (s32)mob);
                }
            }
        }
    }
    if (light != 0.0f) {
        if (0.0f < light) {
            D_L01_002E9D20.g = light;
            D_L01_002E9D20.b = light;
            D_L01_002E9D20.r = light;
        } else {
            D_L01_002E9D20.g = 13.0f;
            D_L01_002E9D20.b = 13.0f;
            D_L01_002E9D20.r = 13.0f;
        }
        func_L01_00300650((u8 *)&D_L01_002E9D20, pos, 0, 0);
    }
}
/* localdecomp:end func_L01_004488B8 */

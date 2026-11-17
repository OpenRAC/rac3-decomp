#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0044AF68 */
s32 func_L01_0044AF68(u8 *a) {
    return *(s16 *)(a + 0xAA) == 0xcdb;
}
/* localdecomp:end func_L01_0044AF68 */

INCLUDE_ASM("asm/levels", func_L01_0044AF78);

/* localdecomp:start func_L01_0044BB30 */
typedef struct {
    s32 v[6];
} T6_0044BB30;
typedef struct {
    u8 pad0[0x20];
    f32 r;
    f32 g;
    f32 b;
} L_0044BB30;
extern T6_0044BB30 D_L01_001D7BF8;
extern T6_0044BB30 D_L01_001D7C10;
extern L_0044BB30 D_L01_002E9CE0;
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00464690(u8 *, vu0_v4 *, s32, s32, f32, s32, s32, s32, s32, f32);
extern void func_L01_002F9578(u8 *, u8 *, vu0_v4 *, s32, s32, s32, s32, s32, f32);
extern s8 func_003A52A0(s32, s32, s32);
extern void func_L01_003006C0(u8 *, u8 *, s32, s32);

void func_L01_0044BB30(u8 *mob, u8 *pos, s32 snd, f32 scale, f32 light) {
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
        speed = func_003824E0(8.0f, 10.0f) * 0.0200000014f;
        size = scale * 400000.0f;
        a = D_L01_001D7BF8;
        b = D_L01_001D7C10;
        pa = &a.v[func_00382468(6)];
        pb = &b.v[func_00382468(6)];
        x = func_00382498(12, 17);
        func_L01_00464690(pos, &col, *pa, *pb, size, x, func_00382498(21, 25), 0, 0, speed * scale);
    }
    if (mob != 0) {
        func_L01_002F9578(mob, pos, &col, 17, 0x7F, 0x40, 0, 0x30, scale * 4.0f);
        func_L01_002F9578(mob, pos, &col, 24, 0x60, 0x20, 0, 0x20, scale * 3.0f);
        if (mob[0x20] != 0xFE) {
            if (mob[0x20] != 0xFD) {
                if (snd != -1) {
                    func_003A52A0(snd, 0, (s32)mob);
                }
            }
        }
    }
    if (light != 0.0f) {
        if (0.0f < light) {
            D_L01_002E9CE0.g = light;
            D_L01_002E9CE0.b = light;
            D_L01_002E9CE0.r = light;
        } else {
            D_L01_002E9CE0.g = 13.0f;
            D_L01_002E9CE0.b = 13.0f;
            D_L01_002E9CE0.r = 13.0f;
        }
        func_L01_003006C0((u8 *)&D_L01_002E9CE0, pos, 0, 0);
    }
}
/* localdecomp:end func_L01_0044BB30 */

LINKER_REMNANT("asm/levels", func_L01_0044BDF0);

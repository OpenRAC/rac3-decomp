#include "common.h"

typedef struct Obj_003A88E8 {
    u8 pad0[0x94C];
    s16 f94C;
    u8 pad94E[0x0E];
    s32 f95C;
    u8 pad960[0x20];
    s32 f980;
    s32 f984;
} Obj_003A88E8;


typedef struct {
    u8 pad0[0x954];
    s32 f0;
    f32 f4;
} S_3A8998;

/* localdecomp:start func_L24_003A8668 */
#include "vu0.h"
typedef struct S_003A8668 {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 f28;
    s32 f2C;
} S_003A8668;
extern S_003A8668 D_L24_001E2200;
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_004637C8(void *, void *, u32, s32, s32, s32, s32, s32);
extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);

void func_L24_003A8668(u8 *a0) {
    vu0_v4 pos;
    vu0_v4 vel;
    s32 i;
    f32 h;
    u8 r, g, b, a;
    s32 life, size, size2;
    u32 col;

    D_L24_001E2200.f20 = 0.075f;
    D_L24_001E2200.f28 = 0x21;
    D_L24_001E2200.f2C = 0;
    r = 10;
    for (i = 0; i < 90; i++) {
        qzero(&pos);
        func_003C4C18(&pos, 1.5f);
        h = 1.5f - (fabs_asm(pos.x) + fabs_asm(pos.y)) * 0.5f;
        vec_add_ab(&pos, &pos, a0 + 0x10);
        vel.x = func_003824E0(-1.0f, 1.0f) * 0.020000001f;
        vel.y = func_003824E0(-1.0f, 1.0f) * 0.020000001f;
        vel.z = func_003824E0(4.0f, h * 6.5f + 5.0f) * 0.020000001f;
        g = func_00382468(200);
        b = 0xC8;
        if (func_00382468(2) == 0) {
            b = 0xFF;
        }
        a = func_00382468(0x80) + 0x64;
        col = (a << 24) | (r << 16) | (g << 8) | b;
        life = func_00382468(10) + 30;
        size = func_00382468(50) + 50;
        size2 = func_00382468(50);
        func_L01_004637C8(&pos, &vel, col, 0, life, size, size2 + 250, i & 1);
    }
    func_L01_00446780(a0, a0 + 0x10, 0x10000, 0, 1, 0, 2.0f, 10.0f, 1.0f);
}
/* localdecomp:end func_L24_003A8668 */

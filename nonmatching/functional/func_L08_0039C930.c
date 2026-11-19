/* functional: high. Same calls, args and order as retail (checked against asm); bytes differ only in float register allocation and vec add scheduling. */
#include "vu0.h"
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0046B288(f32, f32, void *, s32, s32, s32);

void func_L08_0039C930(u8 *a0) {
    f32 v[4];
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 n;
    if (a0[0x31] == 0) return;
    if (func_00382468(14) == 0) {
        a = func_00382538();
        b = func_003824E0(0.0f, 0.1f);
        c = func_003824E0(0.0f, 1.0f);
        d = func_003824E0(1.0f, 2.0f);
        n = (s32)func_003824E0(180.0f, 240.0f);
        v[0] = func_0038D098(a) * b;
        v[1] = func_0038D0B0(a) * b;
        v[2] = 0.0f;
        vec_add_ba(v, v, a0 + 0x10);
        func_L01_0046B288(c, d, v, 0x40005840, 0x5840, (n * 5 + 2) / 6);
    }
    if (func_00382468(4) == 0) {
        a = func_00382538();
        b = func_003824E0(0.0f, 0.1f);
        c = func_003824E0(0.0f, 3.5f);
        d = func_003824E0(3.5f, 4.5f);
        n = (s32)func_003824E0(180.0f, 240.0f);
        v[0] = func_0038D098(a) * b;
        v[1] = func_0038D0B0(a) * b;
        v[2] = 0.0f;
        vec_add_ba(v, v, a0 + 0x10);
        func_L01_0046B288(c, d, v, 0x30005840, 0x7040, (n * 5 + 2) / 6);
    }
}

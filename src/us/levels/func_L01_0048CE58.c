#include "common.h"

/* NTSC-U counterpart of func_L01_004906D0 (src/levels/shared/L01_004903F0.c) */
extern s32 func_003B5C38(s32);

/* localdecomp:start func_L01_0048CE58 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
} S_004906D0;
extern s32 D_L01_001D8D90_0048CE58;
extern f32 D_L01_001D8DAC;
extern f32 D_L01_001D8DB0;
extern f32 D_L01_001D8DB4;
extern f32 D_L01_001D8DB8;
extern f32 D_L01_001D8DBC;
extern f32 D_L01_001D8DC0;
__asm__(".extern D_L01_001D8D90_0048CE58, 4");
__asm__(".extern D_L01_001D8DAC, 4");
__asm__(".extern D_L01_001D8DB0, 4");
__asm__(".extern D_L01_001D8DB4, 4");
__asm__(".extern D_L01_001D8DB8, 4");
__asm__(".extern D_L01_001D8DBC, 4");
__asm__(".extern D_L01_001D8DC0, 4");
extern s32 func_L01_0047A280(void);
extern s32 *func_003B46F0(s32);
extern void func_003B4788(s32 *, void *);
extern void func_003B56D0(s32 *, s32, f32, f32, f32, f32, f32);
extern void func_003B56F0(s32 *, f32, f32, f32, f32);
extern void func_003B5000(s32 *, s32, f32, f32, f32);
extern void func_003B4E78(s32 *, s32, s32, s32);
extern void func_L01_0048D1A8(void);

void func_L01_0048CE58(void) {
    S_004906D0 d;
    s32 n;
    s32 x;

    D_L01_001D8D90_0048CE58 = 8;
    d.f0 = func_L01_0047A280();
    d.f4 = func_003B5C38(0);
    d.f18 = 1.0f;
    d.f1C = D_L01_001D8DAC;
    d.f20 = D_L01_001D8DB4;
    d.f24 = D_L01_001D8DB8;
    d.f28 = D_L01_001D8DBC;
    d.f2C = 1.0f;
    d.f30 = 1.0f;
    d.f34 = D_L01_001D8DC0;
    x = D_L01_001D8D90_0048CE58;
    n = x < 9 ? x : 8;
    d.f10 = n;
    d.f8 = 0x14;
    d.f14 = 2;
    d.fC = x;
    d.f38 = d.f28 - d.f24 - d.f34;
    d.f3C = 0;
    d.f40 = 0;
    d.f44 = 0;
    d.f48 = 0;
    d.f4C = 0;
    d.f50 = 0;
    func_003B4788(func_003B46F0(0), &d);
    func_003B56D0(func_003B46F0(0), 0, 0.5f, 0.817342f, 0.045f, 0.0425f, 0.35f);
    func_003B56F0(func_003B46F0(0), 0.5f, 0.632204f, 0.817342f, 0.439128f);
    func_003B5000(func_003B46F0(0), 1, D_L01_001D8DB0, 0.00666f, 0.03f);
    func_003B4E78(func_003B46F0(0), 0, 1, 3);
    func_003B4E78(func_003B46F0(0), 1, 2, 3);
    func_L01_0048D1A8();
}
/* localdecomp:end func_L01_0048CE58 */

/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_0048CE58, the NTSC-U twin of func_L01_004906D0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0048B738.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_004906D0 (src/levels/shared/L01_0048B738.c) */
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
} D_0048CE58;
extern s32 D_001D8D90_sda;
extern f32 D_001D8DAC_sda;
extern f32 D_001D8DB0_sda;
extern f32 D_001D8DB4_sda;
extern f32 D_001D8DB8_sda;
extern f32 D_001D8DBC_sda;
extern f32 D_001D8DC0_sda;
__asm__(".extern D_001D8D90_sda, 4");
__asm__(".extern D_001D8DAC_sda, 4");
__asm__(".extern D_001D8DB0_sda, 4");
__asm__(".extern D_001D8DB4_sda, 4");
__asm__(".extern D_001D8DB8_sda, 4");
__asm__(".extern D_001D8DBC_sda, 4");
__asm__(".extern D_001D8DC0_sda, 4");
extern s32 func_L01_0047A280(void);
extern s32 func_003B5C38(s32);
extern s32 func_003B46F0(s32);
extern void func_003B4788(s32, void *);
extern void func_003B56D0(s32, s32, f32, f32, f32, f32, f32);
extern void func_003B56F0(s32, f32, f32, f32, f32);
extern void func_003B5000(s32, s32, f32, f32, f32);
extern void func_003B4E78(s32, s32, s32, s32);
extern void func_L01_0048D1A8(void);

void func_L01_0048CE58(void) {
    D_0048CE58 d;
    s32 n;
    s32 x;

    n = 8;
    D_001D8D90_sda = n;
    d.f0 = func_L01_0047A280();
    d.f4 = func_003B5C38(0);
    x = D_001D8D90_sda;
    n = x < 9 ? x : n;
    d.fC = x;
    d.f10 = n;
    d.f8 = 0x14;
    d.f14 = 2;
    d.f18 = 1.0f;
    d.f1C = D_001D8DAC_sda;
    d.f20 = D_001D8DB4_sda;
    d.f24 = D_001D8DB8_sda;
    d.f28 = D_001D8DBC_sda;
    d.f2C = 1.0f;
    d.f30 = 1.0f;
    d.f34 = D_001D8DC0_sda;
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
    func_003B5000(func_003B46F0(0), 1, D_001D8DB0_sda, 0.00666f, 0.03f);
    func_003B4E78(func_003B46F0(0), 0, 1, 3);
    func_003B4E78(func_003B46F0(0), 1, 2, 3);
    func_L01_0048D1A8();
}
/* localdecomp:end func_L01_0048CE58 */

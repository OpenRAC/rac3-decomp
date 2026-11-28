/* func_L01_00495088 (Claude wave 14 r57, 2026-11-28). First draft kept here. */
/* PAL first draft (wave 14 r57, 2026-11-28): func_L01_00495088 (2572 B), the menu setup, written from retail
 * over the functional port's C. Needs the existing line "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as"
 * (the next file, L01_00495A98.c, already has it): retail loads 0.21f, 0.15f, 0.112f, 0.135f, 0.145f, 0.004f,
 * 0.005f, 0.56f, 0.69f, 0.66f and 0.93f with Ps2EeAs's lui/ori/mtc1, the file's GNU as line uses .lit4 lwc1
 * (608 positional words differ under the file's own line). Cut: 0x00495088 is 8-aligned and the function
 * ends at 0x00495A94 + a 4-byte pad, so 0x00495088-0x00495A98 (or moving L01_00495A98.c's start back to
 * 0x00495088) is 8-aligned at every place. Under that line (tools/check.py --flags @ps2as, diagnostic) the
 * unified diff left is: retail's PRE keeps both stack arrays' addresses in $s6/$s7 from before the first
 * loop and computes D_L01_002EB940/D_L01_001D9138 after the second loop (ours hoists other high parts to the
 * entry block instead); the three gp tables are addressed with lui/addiu (retail: $gp, which a 20-byte
 * .extern does not give; 4 breaks more); 0x110011 + i keeps the constant in $v0 instead of the sum's $s0;
 * a1/a2 order before each func_003E8FE8 call; the store of D_L01_001D902C sits in a jal delay slot. */
#include "common.h"

/* localdecomp:start func_L01_00495088 */
extern u8 D_L01_001D90D4;
extern f32 D_L01_001D90B8;
extern s32 D_L01_001D9134;
extern s32 D_L01_001D9120[] __attribute__((section(".sdata")));
extern f32 D_L01_001D90F0[] __attribute__((section(".sdata")));
extern f32 D_L01_001D9108[] __attribute__((section(".sdata")));
extern f32 D_L01_001D90E8;
extern f32 D_L01_001D90EC;
extern f32 D_L01_001D9030;
extern f32 D_L01_001D9034;
extern s32 D_L01_001D902C;
extern f32 D_L01_001D90D8;
extern f32 D_L01_001D90DC;
extern f32 D_L01_001D90E0;
extern f32 D_L01_001D90E4;
extern f32 D_L01_001D9038;
extern f32 D_L01_001D903C;
extern f32 D_L01_001D9040;
extern f32 D_L01_001D9044;
extern f32 D_L01_001D9048;
extern f32 D_L01_001D904C;
extern f32 D_L01_001D9050;
extern f32 D_L01_001D9054;
extern f32 D_L01_001D9068;
extern f32 D_L01_001D906C;
extern f32 D_L01_001D9070;
extern f32 D_L01_001D9074;
extern f32 D_L01_001D9078;
extern f32 D_L01_001D907C;
extern f32 D_L01_001D9080;
extern f32 D_L01_001D9084;
extern f32 D_L01_001D9088;
extern f32 D_L01_001D908C;
extern f32 D_L01_001D9090;
extern f32 D_L01_001D9094;
extern f32 D_L01_001D9098;
extern f32 D_L01_001D909C;
extern f32 D_L01_001D90A0;
extern f32 D_L01_001D90A4;
extern f32 D_L01_001D90A8;
extern f32 D_L01_001D90AC;
extern f32 D_L01_001D90B0;
extern f32 D_L01_001D90B4;
extern s32 D_L01_001D9028;
__asm__(".extern D_L01_001D90D4, 1");
__asm__(".extern D_L01_001D90B8, 4");
__asm__(".extern D_L01_001D9134, 4");
__asm__(".extern D_L01_001D90E8, 4");
__asm__(".extern D_L01_001D90EC, 4");
__asm__(".extern D_L01_001D9030, 4");
__asm__(".extern D_L01_001D9034, 4");
__asm__(".extern D_L01_001D902C, 4");
__asm__(".extern D_L01_001D90D8, 4");
__asm__(".extern D_L01_001D90DC, 4");
__asm__(".extern D_L01_001D90E0, 4");
__asm__(".extern D_L01_001D90E4, 4");
__asm__(".extern D_L01_001D9038, 4");
__asm__(".extern D_L01_001D903C, 4");
__asm__(".extern D_L01_001D9040, 4");
__asm__(".extern D_L01_001D9044, 4");
__asm__(".extern D_L01_001D9048, 4");
__asm__(".extern D_L01_001D904C, 4");
__asm__(".extern D_L01_001D9050, 4");
__asm__(".extern D_L01_001D9054, 4");
__asm__(".extern D_L01_001D9068, 4");
__asm__(".extern D_L01_001D906C, 4");
__asm__(".extern D_L01_001D9070, 4");
__asm__(".extern D_L01_001D9074, 4");
__asm__(".extern D_L01_001D9078, 4");
__asm__(".extern D_L01_001D907C, 4");
__asm__(".extern D_L01_001D9080, 4");
__asm__(".extern D_L01_001D9084, 4");
__asm__(".extern D_L01_001D9088, 4");
__asm__(".extern D_L01_001D908C, 4");
__asm__(".extern D_L01_001D9090, 4");
__asm__(".extern D_L01_001D9094, 4");
__asm__(".extern D_L01_001D9098, 4");
__asm__(".extern D_L01_001D909C, 4");
__asm__(".extern D_L01_001D90A0, 4");
__asm__(".extern D_L01_001D90A4, 4");
__asm__(".extern D_L01_001D90A8, 4");
__asm__(".extern D_L01_001D90AC, 4");
__asm__(".extern D_L01_001D90B0, 4");
__asm__(".extern D_L01_001D90B4, 4");
__asm__(".extern D_L01_001D9028, 4");
__asm__(".extern D_L01_001D9120, 20");
__asm__(".extern D_L01_001D90F0, 20");
__asm__(".extern D_L01_001D9108, 20");
extern u8 D_001D554E;
__asm__(".extern D_001D554E, 16");
extern u8 D_001D554F;
__asm__(".extern D_001D554F, 16");
extern u8 D_001D5550;
__asm__(".extern D_001D5550, 16");
extern u8 D_001D5551;
__asm__(".extern D_001D5551, 16");
extern u8 D_001D5552;
__asm__(".extern D_001D5552, 16");
extern u8 D_001D5553;
__asm__(".extern D_001D5553, 16");
extern u8 D_001426E0[];
typedef struct { u8 pad0[0x4954]; s32 x4954; u8 pad4958[0x73A8 - 0x4958]; u8 x73A8[4]; } Toc_00495088;
extern Toc_00495088 D_00160C40_00495088;
extern char D_L01_002EB940[];
extern char D_L01_001D9138[];

void func_L01_00495088(void) {
    extern s32 (**func_L01_0043B548(s32, s32))(s32);
    extern s32 func_00381FF0(s32);
    extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
    extern void func_L01_00518D40(s32);
    extern void func_003E8630(s32, s32);
    extern void func_003E9138(s32, s32, s32, f32, f32, f32, f32);
    extern void func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
    extern void func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
    extern void func_003E8710(s32, void *);
    extern void func_003E7F20(s32, s32);
    extern void func_L01_00516AA0(s32, s32, s32);
    extern void func_L01_00516B90(s32, s32, s32);
    extern void func_L01_00517F50(s32, s32, s32);
    extern void func_L01_00517190(s32, s32);
    extern s32 func_003BB3A8(s32);
    extern void func_003B4528(void *, s32, s32, s32, void *);
    extern void func_0011B2E8(char *, char *, s32, s32);
    extern void func_0011A264(void *, s32, s32);
    s32 (**ops)(s32);
    s32 i;
    s32 h;
    s32 h2;
    s32 h3;
    s32 r;
    s32 str;
    s32 mem;
    f32 x;
    u8 on[6];
    u8 off[6];
    u8 flags;

    ops = func_L01_0043B548(0x18E2, 0xC);
    i = 0;
    D_L01_001D90D4 = 0;
    str = func_00381FF0(0x14EC);
    func_003B9298(0xD, 0x110000, 0x110001, 0x110002, 0x110003, 0x110004, 0x110005, 0x110007,
                  D_L01_001D90B8, 0x110006, str, 0x110008, 0x124, 0x110009, 0xCD5);
    func_L01_00518D40(0x11000B);
    func_003E8630(0x110000, 0x11000B);
    func_L01_00518D40(0x11001C);
    func_003E8630(0x110000, 0x11001C);
    x = 0.21f;
    do {
        h = 0x110011 + i;
        func_003E9138(h, D_L01_001D9134, 0, 0.15f, x, 0.112f, 0.135f);
        r = ops[1](i);
        func_L01_00516AA0(h, 1, r);
        func_003E8630(0x11000B, h);
        h2 = 0x11000C + i;
        func_003E9270(h2, 0x332299DE, 0.15f, x, 0.112f, 0.135f, 0.004f, 0.005f);
        func_003E8630(0x11000B, h2);
        h3 = 0x11001D + i;
        func_003E9138(h3, D_L01_001D9120[i], 0, D_L01_001D90F0[i] + 0.15f, x + D_L01_001D9108[i],
                      0.112f - D_L01_001D90E8 * 2.0f, 0.135f - D_L01_001D90EC * 2.0f);
        func_L01_00517F50(h3, 0xED58, i);
        r = ops[1](i);
        i++;
        func_L01_00516AA0(h3, 1, r);
        func_L01_00516AA0(h3, 0x40, 1);
        func_003E8630(0x11001C, h3);
        x += 0.145f;
    } while (i < 5);
    func_003E9270(0x110016, 0x332299DE, 0.56f, D_L01_001D9030, 0.69f, D_L01_001D9034, 0.004f, 0.005f);
    func_003E8630(0x11000B, 0x110016);
    i = 0;
    mem = func_003BB3A8(0);
    D_L01_001D902C = mem;
    func_003E9138(0x110022, 0x80808080, 0, D_L01_001D90D8 + 0.56f, D_L01_001D9030 + D_L01_001D90DC,
                  0.69f - D_L01_001D90E0 * 2.0f, D_L01_001D9034 - D_L01_001D90E4 * 2.0f);
    func_003E8630(0x11001C, 0x110022);
    func_003E9270(0x110017, 0x332299DE, 0.56f, D_L01_001D9038, 0.69f, D_L01_001D903C, 0.004f, 0.005f);
    func_003E8630(0x11000B, 0x110017);
    x = D_L01_001D9040;
    do {
        h = 0x110018 + i;
        func_003E9138(h, 0x331465B7, 0, 0.56f, x, 0.66f, 0.005f);
        i++;
        func_003E8630(0x11000B, h);
        x += D_L01_001D9044;
    } while (i < 4);
    str = func_00381FF0(0xC6E);
    func_003E8FE8(0x110023, str, 0x8066CCFF, D_L01_001D9048, D_L01_001D904C, D_L01_001D9050,
                  D_L01_001D9054);
    func_003E7F20(0x110023, 1);
    func_003E8630(0x11001C, 0x110023);
    str = func_00381FF0(0x14F7);
    func_003E8FE8(0x11002C, str, 0x8066CCFF, D_L01_001D9048, D_L01_001D9070, D_L01_001D9074,
                  D_L01_001D9078);
    func_003E8630(0x11001C, 0x11002C);
    str = func_00381FF0(0x14EF);
    func_003E8FE8(0x110024, str, 0x8066CCFF, D_L01_001D9068, D_L01_001D9070, D_L01_001D9074,
                  D_L01_001D9078);
    func_003E8630(0x11001C, 0x110024);
    func_L01_00516B90(0x110024, 1, 3);
    str = func_00381FF0(0x14EF);
    func_003E8FE8(0x110025, str, 0x8066CCFF, D_L01_001D906C, D_L01_001D9070, D_L01_001D9074,
                  D_L01_001D9078);
    func_003E8630(0x11001C, 0x110025);
    func_L01_00516B90(0x110025, 2, 3);
    str = func_00381FF0(0x14ED);
    func_003E8FE8(0x110026, str, 0x8066CCFF, D_L01_001D907C, D_L01_001D9084, D_L01_001D9088,
                  D_L01_001D908C);
    func_003E8630(0x11001C, 0x110026);
    func_L01_00516B90(0x110026, 1, 3);
    str = func_00381FF0(0x14ED);
    func_003E8FE8(0x110027, str, 0x8066CCFF, D_L01_001D9080, D_L01_001D9084, D_L01_001D9088,
                  D_L01_001D908C);
    func_003E8630(0x11001C, 0x110027);
    func_L01_00516B90(0x110027, 2, 3);
    str = func_00381FF0(0x14EE);
    func_003E8FE8(0x110028, str, 0x8066CCFF, D_L01_001D9090, D_L01_001D9098, D_L01_001D909C,
                  D_L01_001D90A0);
    func_003E8630(0x11001C, 0x110028);
    func_L01_00516B90(0x110028, 1, 3);
    str = func_00381FF0(0x14F0);
    func_003E8FE8(0x110029, str, 0x8066CCFF, D_L01_001D9094, D_L01_001D9098, D_L01_001D909C,
                  D_L01_001D90A0);
    func_003E8630(0x11001C, 0x110029);
    func_L01_00516B90(0x110029, 2, 3);
    str = func_00381FF0(0x186A);
    func_003E8FE8(0x11002A, str, 0x8066CCFF, D_L01_001D90A4, D_L01_001D90AC, D_L01_001D90B0,
                  D_L01_001D90B4);
    func_003E8630(0x11001C, 0x11002A);
    func_L01_00516B90(0x11002A, 1, 3);
    str = func_00381FF0(0x14F0);
    func_003E8FE8(0x11002B, str, 0x8066CCFF, D_L01_001D90A8, D_L01_001D90AC, D_L01_001D90B0,
                  D_L01_001D90B4);
    func_003E8630(0x11001C, 0x11002B);
    func_L01_00516B90(0x11002B, 2, 3);
    str = func_00381FF0(0xE73);
    func_0011B2E8(D_L01_002EB940, D_L01_001D9138, 0x13, str);
    func_003E8FE8(0x11002D, (s32)D_L01_002EB940, 0x8066CCFF, 0.5f, 0.93f, 1.0f, 1.0f);
    func_L01_00516B90(0x11002D, 3, 3);
    func_003E8630(0x11001C, 0x11002D);
    func_0011A264(on, 0, 6);
    func_0011A264(off, 0, 6);
    flags = D_001426E0[0x54];
    on[0] = D_001D554E;
    on[1] = D_001D554F;
    on[2] = D_001D5550;
    on[3] = D_001D5551;
    on[4] = D_001D5552;
    on[5] = D_001D5553;
    off[0] = flags & 1;
    off[1] = flags & 2;
    off[2] = flags & 4;
    off[3] = flags & 8;
    off[4] = flags & 0x10;
    off[5] = flags & 0x20;
    D_L01_001D9028 = -1;
    if (on[1] && !off[1]) D_L01_001D9028 = 0;
    else if (on[3] && !off[3]) D_L01_001D9028 = 1;
    else if (on[4] && !off[4]) D_L01_001D9028 = 2;
    else if (on[2] && !off[2]) D_L01_001D9028 = 3;
    else if (on[5] && !off[5]) D_L01_001D9028 = 4;
    else D_L01_001D9028 = 0;
    mem = (D_L01_001D902C + 0xF) & 0xFFFFFFF0;
    func_003B4528(func_003B42F8(0), mem, 0, D_00160C40_00495088.x4954, D_00160C40_00495088.x73A8);
    func_003E8710(0x110022, func_003B42F8(0));
    func_L01_00517190(0x110022, D_L01_001D9028 + 1);
}
/* localdecomp:end func_L01_00495088 */

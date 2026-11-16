/* NTSC-U draft (Claude wave B): C of func_L03_0040EB30, the NTSC-U twin of func_L03_00411C40, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 25 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L03_0040EB30", whose code is not the PAL one).
 * Worker's note: 25 diff (6 compiles): impact/spark moby handler decoded (local config struct with 6 field stores {0x64,0x64,0.5f,0.01f,0.1f,0.05f} read back as cfg.f8/cfg.f4 for func_L01_004708F8, rgb triple from func_003C1A60 -> func_L01_00438908, random scale of the two ...
 */
#include "common.h"

/* localdecomp:start func_L03_0040EB30 */
typedef int Quad_40EB30 __attribute__((mode(TI)));
typedef struct {
    s16 h0;
    s16 h2;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 pad14[0xC];
} Cfg_40EB30;
extern s32 D_L03_001E68B4;
extern s32 D_L03_001D6C88;
__asm__(".extern D_L03_001D6C88, 4");
extern s32 D_L03_001D6C8C;
__asm__(".extern D_L03_001D6C8C, 4");
extern void func_003C1A60(u8 *, s32 *, s32 *, s32 *);
extern void func_L01_00438908(u8 *, s32, s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern void func_003BF6A8(void *, f32);
extern void func_L01_004708F8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32);

void func_L03_0040EB30(u8 *a0, s32 a1, s32 a2, s32 a3) {
    s32 r;
    s32 g;
    s32 b;
    Cfg_40EB30 cfg;
    Quad_40EB30 pos;
    Quad_40EB30 zero;
    f32 f;

    cfg.h0 = 0x64;
    cfg.h2 = 0x64;
    cfg.f4 = 0.5f;
    cfg.f8 = 0.01f;
    cfg.fC = 0.1f;
    cfg.f10 = 0.05f;
    *(u16 *)(a0 + 0x34) |= 0x2000;
    a0[0x23] = 0x23;
    func_003C1A60(a0, &r, &g, &b);
    if (!(D_L03_001E68B4 & 1)) {
        b += 0x35;
        g += 0x15;
    }
    func_L01_00438908(a0, r, g, b);
    if (D_L03_001D6C88 > 0) {
        func_00388830(a0 + 0xC0, a0 + 0xC0, func_0037E250(0.96f, 1.04f));
        func_00388830(a0 + 0xD0, a0 + 0xD0, func_0037E250(0.96f, 1.04f));
        D_L03_001D6C88 = D_L03_001D6C88 - 1;
    } else if (func_0037E1D8(D_L03_001D6C8C) == 0) {
        D_L03_001D6C88 = func_0037E1D8(0x1E) + 0x14;
    }
    pos = *(Quad_40EB30 *)(a0 + 0x10);
    func_003BF6A8(&pos, 0.9f);
    zero = 0;
    f = func_0037E250(0.016666668f, 0.033333335f);
    *(f32 *)((u8 *)&zero + 8) = f;
    func_L01_004708F8(&pos, &zero, a1, a2, a3, a1, 0, cfg.f8, 1.0f, cfg.f4, 1.0f);
}
/* localdecomp:end func_L03_0040EB30 */


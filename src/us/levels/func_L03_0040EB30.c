#include "common.h"
#include "vu0.h"

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
extern struct {
    u8 p0[0x34];
    s32 w34;
} D_L03_001E6880;
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
extern void func_L01_004708F8(void *, void *, s32, s32, s32, f32, f32, f32, f32, s32, s32);

void func_L03_0040EB30(u8 *a0, s32 a1, s32 a2, s32 a3) {
    s32 r;
    s32 g;
    s32 b;
    Cfg_40EB30 cfg;
    f32 pos[4] __attribute__((aligned(16)));
    f32 zero[4] __attribute__((aligned(16)));
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
    if (!(D_L03_001E6880.w34 & 1)) {
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
    *(Quad_40EB30 *)pos = *(Quad_40EB30 *)(a0 + 0x10);
    func_003BF6A8(pos, 0.9f);
    qzero(zero);
    f = func_0037E250(0.016666668f, 0.033333335f);
    zero[2] = f;
    func_L01_004708F8(pos, zero, a1, a2, a3, cfg.f8, 1.0f, cfg.f4, 1.0f, a1, 0);
}
/* localdecomp:end func_L03_0040EB30 */


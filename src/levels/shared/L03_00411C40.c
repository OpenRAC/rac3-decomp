#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_00411C40 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_411C40;
typedef struct {
    s16 h0;
    s16 h2;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 pad14[0xC];
} Cfg_411C40;
extern s32 D_L03_001E6834[];
extern s32 D_L03_001D6C88;
__asm__(".extern D_L03_001D6C88, 4");
extern s32 D_L03_001D6C8C;
__asm__(".extern D_L03_001D6C8C, 4");
extern void func_003C6FB0(u8 *, s32 *, s32 *, s32 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern void func_003C4C18(void *, f32);
extern void func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);

void func_L03_00411C40(u8 *a0, s32 a1, s32 a2, s32 a3) {
    Cfg_411C40 cfg;
    V4_411C40 pos;
    V4_411C40 zero;
    s32 r;
    s32 g;
    s32 b;
    f32 f;

    cfg.h0 = 0x64;
    cfg.h2 = 0x64;
    cfg.f4 = 0.5f;
    cfg.f8 = 0.01f;
    cfg.fC = 0.1f;
    cfg.f10 = 0.05f;
    *(u16 *)(a0 + 0x34) |= 0x2000;
    a0[0x23] = 0x23;
    func_003C6FB0(a0, &r, &g, &b);
    if (!(D_L03_001E6834[0] & 1)) {
        b += 0x35;
        g += 0x15;
    }
    func_L01_0043B9E8(a0, r, g, b);
    if (D_L03_001D6C88 > 0) {
        func_0038CF68(a0 + 0xC0, a0 + 0xC0, func_003824E0(0.96f, 1.04f));
        func_0038CF68(a0 + 0xD0, a0 + 0xD0, func_003824E0(0.96f, 1.04f));
        D_L03_001D6C88 = D_L03_001D6C88 - 1;
    } else if (func_00382468(D_L03_001D6C8C) == 0) {
        D_L03_001D6C88 = func_00382468(0x1E) + 0x14;
    }
    pos = *(V4_411C40 *)(a0 + 0x10);
    func_003C4C18(&pos, 0.9f);
    qzero(&zero);
    f = func_003824E0(0.020000001f, 0.040000003f);
    zero.z = f;
    func_L01_00474078(&pos, &zero, a1, cfg.f8, 1.0f, cfg.f4, 1.0f, a2, a3, a1, 0);
}
/* localdecomp:end func_L03_00411C40 */

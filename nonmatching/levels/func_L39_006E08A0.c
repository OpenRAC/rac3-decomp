/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_006DDD40, the NTSC-U twin of func_L39_006E08A0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/39_multiplayer_menu/L39_006E0730.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_006DDD40 (src/levels/39_multiplayer_menu/L39_006E0730.c) */
/* localdecomp:start func_L39_006DDD40 */
typedef struct G_006DDD40 {
    u8 padDC_pre[0xDC];
    f32 fDC;
    u8 padE0[4];
    f32 fE4;
    f32 fE8;
} G_006DDD40;

extern f32 D_001A5E50[];
extern u8 D_L39_001FD968[];
extern G_006DDD40 D_001A6AD0;
extern f32 (*D_L39_0024A1E4)(f32, f32, f32, f32, f32);
extern f32 func_L39_006DDA60(s32);
extern f32 func_L39_006DDB28(s32, s32);
extern void func_L39_006DDBD0(s32 *, s32 *);
extern void func_L39_006DDC88(s32 *, s32 *);

void func_L39_006DDD40(f32 *out0, f32 *out1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2) {
    s32 io[4];
    f32 f20 = D_001A5E50[t2 + 0x26];
    f32 f21 = D_001A5E50[t2 + 0x22];
    f32 f23;
    f32 f22;
    f32 f16;
    f32 r1;
    f32 r2;
    f32 f4;
    f32 g;

    f23 = func_L39_006DDA60(t0);
    f22 = func_L39_006DDB28(t0, a2);
    func_L39_006DDBD0(&io[0], &io[1]);
    func_L39_006DDC88(&io[2], &io[3]);
    r1 = (f32)*(s16 *)(D_L39_001FD968 + t0 * 4 + 0x140) / (f32)io[1];
    r2 = 1.0f / (f32)(*(s32 *)(D_L39_001FD968 + t1 * 0xA4 + 0x374) + 1);
    f4 = (f32)(io[3] - io[2]);
    f16 = 0.5f;
    if (*(s32 *)(D_L39_001FD968 + t0 * 4 + 0x120) == *(s32 *)(D_L39_001FD968 + 0x1A8) && r2 < r1) {
        f16 = 1.0f;
    } else if (f4 > 0.0f) {
        f16 = ((f32)*(s16 *)(D_L39_001FD968 + t0 * 4 + 0x140) - (f32)io[2]) / f4;
        if (f16 > 0.9f) {
            f16 = 0.9f;
        }
        if (f16 < 0.0f) {
            f16 = 0.0f;
        }
    }
    *out0 = f21 + D_L39_0024A1E4(f21, f23, f20, f22, f16);
    if (D_001A6AD0.fE4 < f20) {
        g = f20 - D_001A6AD0.fE8;
        *out1 = g;
        if (D_001A6AD0.fDC < g) {
            *out1 = D_001A6AD0.fDC;
        }
        if (*out1 < D_001A6AD0.fE4) {
            *out1 = D_001A6AD0.fE4;
        }
    }
}
/* localdecomp:end func_L39_006DDD40 */

#include "common.h"

/* NTSC-U counterpart of func_L39_006DEB68 (src/levels/39_multiplayer_menu/L39_006DC228.c) */
/* localdecomp:start func_L39_006DC008 */
typedef struct {
    char _p0[0x120];
    s32 f120[8];
    s16 f140[8][2];
    u8 f160[16];
    u8 f170[8];
    u8 f178[8];
    f32 f180[8];
    char _p1A0[0x1A8 - 0x1A0];
    s32 f1A8;
    s32 f1AC;
    char _p1B0[0x80C - 0x1B0];
    s32 f80C;
} S_006DEB68;
extern S_006DEB68 D_L39_001FD968_006DC008;
typedef struct {
    f32 w[7][3];
    f32 maxA[3];
    f32 maxB[3];
    f32 maxC[3];
    f32 maxF[3];
    f32 maxE;
    char _p88[0xD8 - 0x88];
    f32 scale;
} T_006DEB68;
extern T_006DEB68 D_001A6AD0_006DC008;
s32 func_00197640(s32);

f32 func_L39_006DC008(s32 arg0) {
    s32 r = func_00197640(D_L39_001FD968_006DC008.f80C);
    f32 res = 0.0f;
    f32 w = 0.0f;
    f32 a = D_L39_001FD968_006DC008.f140[arg0][0];
    f32 b = D_L39_001FD968_006DC008.f140[arg0][1];
    f32 f = D_L39_001FD968_006DC008.f180[arg0];
    f32 c = D_L39_001FD968_006DC008.f160[arg0];
    f32 d = D_L39_001FD968_006DC008.f170[arg0];
    f32 e = D_L39_001FD968_006DC008.f178[arg0];
    f32 fn;
    s32 n;

    if (D_001A6AD0_006DC008.maxA[r] < a) a = D_001A6AD0_006DC008.maxA[r];
    if (a < 0.0f) a = 0.0f;
    if (D_001A6AD0_006DC008.maxB[r] < b) b = D_001A6AD0_006DC008.maxB[r];
    if (b < 0.0f) b = 0.0f;
    if (D_001A6AD0_006DC008.maxF[r] < f) f = D_001A6AD0_006DC008.maxF[r];
    if (f < 0.0f) f = 0.0f;
    if (D_001A6AD0_006DC008.maxC[r] < c) c = D_001A6AD0_006DC008.maxC[r];
    if (c < 0.0f) c = 0.0f;
    n = D_L39_001FD968_006DC008.f1AC;
    fn = n;
    if (fn < d) d = fn;
    if (d < 0.0f) d = 0.0f;
    if (D_001A6AD0_006DC008.maxE < e) e = D_001A6AD0_006DC008.maxE;
    if (e < 0.0f) e = 0.0f;
    if (D_L39_001FD968_006DC008.f1A8 == D_L39_001FD968_006DC008.f120[arg0]) w = 1.0f;
    f /= D_001A6AD0_006DC008.maxF[r];
    c /= D_001A6AD0_006DC008.maxC[r];
    a /= D_001A6AD0_006DC008.maxA[r];
    b /= D_001A6AD0_006DC008.maxB[r];
    if (n > 0) d /= fn;
    e /= D_001A6AD0_006DC008.maxE;
    res = D_001A6AD0_006DC008.scale * (D_001A6AD0_006DC008.w[0][r] * w + D_001A6AD0_006DC008.w[1][r] * a
        + D_001A6AD0_006DC008.w[2][r] * b + D_001A6AD0_006DC008.w[3][r] * f + D_001A6AD0_006DC008.w[4][r] * c
        + D_001A6AD0_006DC008.w[5][r] * d + D_001A6AD0_006DC008.w[6][r] * e);
    return res;
}
/* localdecomp:end func_L39_006DC008 */

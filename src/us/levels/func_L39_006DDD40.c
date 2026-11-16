#include "common.h"

/* NTSC-U counterpart of func_L39_006E08A0 (src/levels/39_multiplayer_menu/L39_006E08A0.c) */
extern u8 D_001A5E50[];

/* localdecomp:start func_L39_006DDD40 */
typedef struct {
    s16 v;
    s16 _pad;
} H_006E08A0;
typedef struct {
    char _p0[0x8C];
    s32 count;
    char _p90[0xA4 - 0x90];
} E_006E08A0;
typedef struct {
    char _p0[0x120];
    s32 f120[8];
    H_006E08A0 f140[8];
    char _p160[0x1A8 - 0x160];
    s32 f1A8;
    char _p1AC[0x2E8 - 0x1AC];
    E_006E08A0 ent[8];
} S_006E08A0_D;
typedef struct {
    char _p0[0x88];
    f32 f88[4];
    f32 f98[4];
} S_006E08A0;

f32 func_L39_006DDA60(s32);
f32 func_L39_006DDB28(s32, s32);
void func_L39_006DDBD0(s32 *, s32 *);
void func_L39_006DDC88(s32 *, s32 *);
extern f32 (*D_L39_0024A1E4)(f32, f32, f32, f32, f32);
extern f32 D_001A6AD0[];
extern S_006E08A0_D D_L39_001FD968_006DDD40;

void func_L39_006DDD40(f32 *x, f32 *y, s32 total, s32 num, s32 key, s32 out, s32 idx) {
    s32 l[4];
    f32 a;
    f32 b;
    f32 c;
    f32 e;
    f32 r1;
    f32 r2;
    f32 diff;
    f32 t;

    a = ((S_006E08A0 *)D_001A5E50)->f88[idx];
    b = ((S_006E08A0 *)D_001A5E50)->f98[idx];
    c = func_L39_006DDA60(key);
    e = func_L39_006DDB28(key, total);
    func_L39_006DDBD0(&l[0], &l[1]);
    func_L39_006DDC88(&l[2], &l[3]);
    r1 = (f32)D_L39_001FD968_006DDD40.f140[key].v / (f32)l[1];
    r2 = 1.0f / (f32)(D_L39_001FD968_006DDD40.ent[out].count + 1);
    t = 0.5f;
    diff = (f32)(l[3] - l[2]);
    if (D_L39_001FD968_006DDD40.f120[key] == D_L39_001FD968_006DDD40.f1A8 && r2 < r1) {
        t = 1.0f;
    } else if (0.0f < diff) {
        t = ((f32)D_L39_001FD968_006DDD40.f140[key].v - (f32)l[2]) / diff;
        if (0.9f < t) {
            t = 0.9f;
        }
        if (t < 0.0f) {
            t = 0.0f;
        }
    }
    *x = a + D_L39_0024A1E4(a, c, b, e, t);
    if (D_001A6AD0[0xE4 / 4] < b) {
        *y = b - D_001A6AD0[0xE8 / 4];
        if (D_001A6AD0[0xDC / 4] < *y) {
            *y = D_001A6AD0[0xDC / 4];
        }
        if (*y < D_001A6AD0[0xE4 / 4]) {
            *y = D_001A6AD0[0xE4 / 4];
        }
    }
}
/* localdecomp:end func_L39_006DDD40 */

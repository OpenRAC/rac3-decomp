#include "common.h"

/* NTSC-U counterpart of func_L39_00699690 (src/levels/39_multiplayer_menu/L39_00699690.c) */
/* localdecomp:start func_L39_00696EC8 */
typedef struct S3_00699690 S3_00699690;
typedef struct {
    char _p0[0x1C];
    void (*f1C)(S3_00699690 *, s32, s32);
    char _p20[0x8];
    void (*f28)(S3_00699690 *, f32, f32);
} S2_00699690;
struct S3_00699690 {
    char _p0[0x4];
    s32 f4;
    char _p8[0x58];
    S2_00699690 *f60;
};
typedef struct {
    char _p0[0x114];
    S3_00699690 *f114[6];
    char _p12C[0x180];
    s32 f2AC;
    f32 f2B0;
    u8 f2B4;
    u8 f2B5;
} S1_00699690;

void func_L39_00696EC8(S1_00699690 *arg0, s32 arg1, u8 arg2, f32 arg3) {
    S3_00699690 *o;
    s32 b0 = arg1 & 1;

    arg0->f2AC = ((arg1 >> 5) & 1) + (((arg1 >> 4) & 1) + (((arg1 >> 3) & 1) + (((arg1 >> 2) & 1) + (((arg1 >> 1) & 1) + b0))));
    arg0->f2B0 = arg3;
    arg0->f2B4 = arg2;
    arg0->f2B5 = (arg1 >> 6) & 1;
    o = arg0->f114[0];
    o->f60->f1C(o, b0 == 1 ? 3 : 0, 0);
    o = arg0->f114[1];
    o->f60->f1C(o, (arg1 & 2) ? 3 : 0, 0);
    o = arg0->f114[2];
    o->f60->f1C(o, (arg1 & 4) ? 3 : 0, 0);
    o = arg0->f114[3];
    o->f60->f1C(o, (arg1 & 8) ? 3 : 0, 0);
    o = arg0->f114[4];
    o->f60->f1C(o, (arg1 & 16) ? 3 : 0, 0);
    o = arg0->f114[5];
    o->f60->f1C(o, (arg1 & 32) ? 3 : 0, 0);
}
/* localdecomp:end func_L39_00696EC8 */

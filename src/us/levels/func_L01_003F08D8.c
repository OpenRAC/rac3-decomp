#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 f12;
    f32 f16;
    f32 f20;
    u8 b24;
    u8 b25;
    s16 h26;
    u8 b28;
    u8 b29;
    u8 b30;
    u8 b31;
    u8 pad32[16];
    s16 h48;
    s16 h50;
    s32 w52;
    s32 w56;
    s32 w60;
} S_L01_003F08D8;

/* localdecomp:start func_L01_003F08D8 */
extern u8 D_L01_001E5D10[];

/* camera_volume_add: claims the first free slot (b29 == 0) of 32 in the camera volume table for
 * group a0, fills it with -1 bounds and defaults, and returns it, or 0 when full. */
S_L01_003F08D8 *func_L01_003F08D8(s32 a0, s32 a1) {
    S_L01_003F08D8 *p = (S_L01_003F08D8 *)(D_L01_001E5D10 + (a0 << 11));
    s32 i;

    for (i = 0; i < 32; i++) {
        if (p->b29 == 0) {
            p->f0 = -1.0f;
            p->f4 = -1.0f;
            p->f8 = -1.0f;
            p->f12 = -1.0f;
            p->f16 = -1.0f;
            p->f20 = -1.0f;
            p->b28 = a1;
            p->w52 = 6;
            p->h50 = 120;
            p->b29 = 1;
            p->w56 = -1;
            p->b24 = 0;
            p->b25 = 0;
            p->h26 = 0;
            p->b30 = 0;
            p->b31 = 0;
            p->w60 = 0;
            p->h48 = 0;
            return p;
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L01_003F08D8 */

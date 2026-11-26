/* PAL near miss (k6 Opus, 2026-11-26): 148 differences (tools/check.py, level 39) with -mvu0-use-vf0-vf2 added (the file needs it for the VU0 helpers; @ps2as and split addresses come closer, 85 aligned). The trail update for the 5 grenade trails: retail does not strength-reduce the first loop (mult i*0xA0 at each use, i+1 kept in t2), this C does; loop forms and inline helpers did not change it. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_00563E40 */
extern vu0_v4 D_L39_003CD480[][10];
extern s16 D_L39_0024D6D0[] __attribute__((section(".sdata")));
extern s16 D_L39_0024D6E0[] __attribute__((section(".sdata")));
extern s16 D_L39_0024D6F0[] __attribute__((section(".sdata")));
extern f32 D_L39_0024D714;
extern f32 D_L39_0024B544;
__asm__(".extern D_L39_0024B544, 4");
extern s32 D_L39_0024B4F8;
__asm__(".extern D_L39_0024B4F8, 4");
extern s32 D_L39_0024B4FC;
__asm__(".extern D_L39_0024B4FC, 4");
extern void func_L01_00409658(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);

void func_L39_00563E40(u8 *m)
{
    vu0_v4 pos;
    vu0_v4 d[10];
    s32 i;
    s32 j;
    s32 a;
    s32 col;

    pos = *(vu0_v4 *)(*(u8 **)(m + 0x68) + 0x30);
    for (i = 0; i < 5; i++) {
        if (D_L39_0024D6D0[i] != 0) {
            for (j = 1; j < 10; j++) {
                vec_sub_ab(&d[j], &D_L39_003CD480[i][j], &D_L39_003CD480[i][j - 1]);
            }
            D_L39_003CD480[i][0] = pos;
            D_L39_003CD480[i][0].w = 0.04f;
            for (j = 1; j < 10; j++) {
                vec_add_ab(&D_L39_003CD480[i][j], &D_L39_003CD480[i][j - 1], &d[j]);
                D_L39_003CD480[i][j].w = 0.04f;
            }
            if (D_L39_0024D6D0[i] > 0) {
                D_L39_0024D6E0[i] = D_L39_0024B544 * ((f32)D_L39_0024D6D0[i] / (f32)D_L39_0024D6F0[i]);
            } else {
                D_L39_0024D6E0[i] = 0;
            }
        }
    }
    for (i = 0; i < 5; i++) {
        if (D_L39_0024D6D0[i] != 0) {
            a = (s32)((f32)D_L39_0024D6E0[i] * D_L39_0024D714) << 24;
            col = (*(s16 *)(m + 0xAA) == 0x1192) ? D_L39_0024B4FC : D_L39_0024B4F8;
            func_L01_00409658(D_L39_003CD480[i], 0.0f, 4.0f, 0.0f, 0x17, 0xE, 0xA, a | 0x7F7F7F, a | col, 1);
        }
    }
}
/* localdecomp:end func_L39_00563E40 */

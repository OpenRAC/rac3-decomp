/* Lightning segments. Round 26 W8 draft: 169 raw / 63 aligned word differences.
 * tools/check.py --no-context, --mode S --as ps2as --flags=-mvu0-use-vf0-vf2.
 * The outer row-index calculation and segment induction pointers still allocate differently. The VU subtraction/store schedule also differs.
 * A one-based index in the rebuild loop reduces the aligned difference. Tested pointer induction, countdown clamping, loop boundaries and hybrid VU assembly. A source-file cut would be needed for these flags.
 */
#include "common.h"
#include "vu0.h"

typedef struct { vu0_v4 v[5]; } E_3402E8;

extern s16 D_L01_001E18D0[];
extern s16 D_L01_001E18D8[];
extern E_3402E8 D_L01_00278E10[];
extern vu0_v4 D_L01_001E29C0;
extern f32 D_L01_001DD154;
__asm__(".extern D_L01_001DD154, 4");
extern f32 func_003824E0(f32, f32);
extern void func_00382580(void *, f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);

void func_L01_003402E8(u8 *self) {
    vu0_v4 q;
    vu0_v4 dir;
    vu0_v4 t;
    vu0_v4 d[5];
    f32 sign;
    s32 i;
    s32 j;
    vu0_v4 *dp = d;

    q = *(vu0_v4 *)(self + 0x10);
    for (i = 0; i < 4; i++) {
        if (D_L01_001E18D0[i] != 0) {
            D_L01_001E18D0[i] = D_L01_001E18D0[i] - 1;
            if (D_L01_001E18D0[i] < 0) {
                D_L01_001E18D0[i] = 0;
            }
            if (D_L01_001E18D0[i] == 0) {
                D_L01_001E18D0[i] = 4;
                D_L01_001E18D8[i] = 0x40;
                sign = 1.0f;
                func_00382580(&dir, D_L01_001DD154, D_L01_001DD154);
                *(vu0_v4 *)&D_L01_00278E10[i].v[1] = q;
                for (j = 0; j < 4; j++) {
                    vec_sub_ab(&t, &D_L01_00278E10[i].v[1 + j], &D_L01_001E29C0);
                    func_0038D890(&dir, &dir, &t, func_003824E0(0.17453292f, 0.7853982f) * sign);
                    sign = -sign;
                    vec_add_ab(&D_L01_00278E10[i].v[2 + j], &D_L01_00278E10[i].v[1 + j], &dir);
                }
            } else {
                for (j = 0; j < 4; j++) {
                    vec_sub_ba(&d[1 + j], &D_L01_00278E10[i].v[2 + j], &D_L01_00278E10[i].v[1 + j]);
                    dp[1 + j].x += func_L01_00443A18(0.0f, 0.1f);
                    dp[1 + j].y += func_L01_00443A18(0.0f, 0.1f);
                    dp[1 + j].z += func_L01_00443A18(0.0f, 0.1f);
                }
                *(vu0_v4 *)&D_L01_00278E10[i].v[1] = q;
                for (j = 1; j < 5; j++) {
                    vec_add_ab(&D_L01_00278E10[i].v[1 + j], &D_L01_00278E10[i].v[j], &d[j]);
                }
                if (D_L01_001E18D0[i] > 0) {
                    D_L01_001E18D8[i] = 0x20;
                } else {
                    D_L01_001E18D8[i] = 0;
                }
            }
        }
    }
}

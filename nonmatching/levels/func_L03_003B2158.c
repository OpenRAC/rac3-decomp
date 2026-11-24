/* PAL draft (2026-11-21, Promises): written from level 3's assembly. 4 words differ in levels 03
 * and 06, and only with -mvu0-use-vf0-vf2 and @ps2as on its file's line (src/levels/shared/
 * L03_003B1E38.c has neither; func_L03_003B1E38 still matches with both). Left: when s[0x42] == 2
 * retail sets the zero in $f2 (pitch) and copies it to $f22 (yaw), ours the other way round
 * (three wordings, same bytes); in the t+0x128 branch retail loads s+0x10 before t+0x100.
 * LV-R2 retry (2026-11-22): 4 differences (tools/check.py) at levels 03 and 06 with -mvu0-use-vf0-vf2 @ps2as and --no-context. Every zero-assignment wording gives the same bytes; vec_sub_ba in both branches 6, in the first only 171 (the cross-jumped vsub/sqc2 tail needs both branches' VU0 registers to agree).
 */
/* RT-B retry (2026-11-22, rac3-w1, upstream b7be60ac): the parameter is now `void *arg` with `u8 *s = arg;`,
 * so the draft no longer conflicts with func_L03_003B1E38's `void *` declaration: 4 differences (tools/check.py)
 * at levels 03 and 06 in the file's context and with --no-context, with `-mvu0-use-vf0-vf2 @ps2as` on L03_003B1E38.c
 * (func_L03_003B1E38, Flavius, still matches with that line at 03 and 06). Same two problems. vec_sub_ba in both
 * branches leaves the first branch's load order unchanged (scheduling, not source order); `pitch` declared before
 * `yaw` 4; the t+0x128 test inverted 90. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003B2158 */
typedef int Q_003B2158 __attribute__((mode(TI)));
extern u8 D_001A4C60[];
extern u8 D_001A4CC0[];
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L03_003B2158(void *arg) {
    u8 *s = arg;
    u8 *t;
    f32 k1;
    f32 k2;
    f32 dir[4];
    f32 tgt[4];
    f32 pos[4];
    u8 *h;
    f32 ang;
    f32 yaw;
    f32 pitch;

    t = *(u8 **)(s + 0x68);
    k1 = 0.02f;
    k2 = 0.3f;
    if (s[0x42] == 2) {
        yaw = 0.0f;
        pitch = yaw;
    } else {
        if (*(s32 *)(t + 0x128) != 0) {
            vec_sub_ab(dir, t + 0x100, s + 0x10);
        } else {
            if (func_0038CF38(s + 0x10, D_001A4C60) < 8.0f) {
                h = D_001A4C60 - 0x80;
                ang = func_0038D160(*(f32 *)(h + 0xE0) - *(f32 *)(s + 0x10), *(f32 *)(h + 0xE4) - *(f32 *)(s + 0x14));
                if (func_0038DBA0(*(f32 *)(s + 0xF8), ang) < 1.5707964f) {
                    if (func_0038CEA8(D_001A4C60 + 0x90) > 0.01f) {
                        *(s32 *)(t + 0x114) = 100;
                    } else {
                        func_0038CAD0(t + 0x114);
                    }
                    goto timer;
                }
            }
            if (*(s32 *)(t + 0x114) != 0) {
                *(s32 *)(t + 0x114) = 0;
                *(Q_003B2158 *)(t + 0x100) = *(Q_003B2158 *)D_001A4CC0;
            }
        timer:
            if (func_0038CAD0(t + 0x118)) {
                vec_add_ab(t + 0x100, s + 0x10, s + 0xC0);
            }
            if (*(s32 *)(t + 0x114) != 0) {
                k1 = 0.04f;
                k2 = 0.3f;
                *(Q_003B2158 *)tgt = *(Q_003B2158 *)D_001A4CC0;
            } else {
                *(Q_003B2158 *)tgt = *(Q_003B2158 *)(t + 0x100);
            }
            *(Q_003B2158 *)pos = *(Q_003B2158 *)(s + 0x10);
            pos[2] += 2.0f;
            vec_sub_ab(dir, tgt, pos);
        }
        yaw = func_0038DB00(func_0038D160(dir[0], dir[1]), *(f32 *)(s + 0xF8));
        pitch = -func_0038D160(func_0038CED8(dir), dir[2]);
    }
    if (yaw > 1.2217305f) {
        yaw = 1.2217305f;
    } else if (yaw < -1.2217305f) {
        yaw = -1.2217305f;
    }
    if (pitch > 0.5235988f) {
        pitch = 0.5235988f;
    } else if (pitch < -0.5235988f) {
        pitch = -0.5235988f;
    }
    *(f32 *)(t + 0x64) = pitch;
    *(f32 *)(t + 0x68) = yaw * 0.8f;
    *(f32 *)(t + 0xE8) = yaw * 0.2f;
    func_L01_0044E850(s, t, 0, k1 * 1.44f, k2 * 1.44f);
    func_L01_0044E850(s, t + 0x80, 1, k1 * 1.44f, k2 * 1.44f);
}
/* localdecomp:end func_L03_003B2158 */

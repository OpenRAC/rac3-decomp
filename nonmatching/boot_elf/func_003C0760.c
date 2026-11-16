/* PAL near miss (Codex wave 10): near miss: 209 words differ with the file's flags.
 * Replaces the earlier draft (US draft of func_003C0658; did not compile with its file's flags under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 209).
 * Worker's note: 2 word diffs/221, v4.log: div integer and table address addiu at +0xAC/+0xB0 reversed; three formulations same residual. Tested --divs 2,0,0 removes two missing nops before first div.s; no exact proof. Retained exact file signatures and vu0.h helpers.
 */
#include "common.h"
/* localdecomp:start func_003C0760 */
#include "vu0.h"
__asm__(".extern D_001D8E60, 4");
__asm__(".extern D_001D8FC8, 4");
__asm__(".extern D_001D8F94, 4");
__asm__(".extern D_001D8E80, 4");
__asm__(".extern D_001D8F9C, 4");
__asm__(".extern D_001D8F98, 4");
__asm__(".extern D_001D8FA0, 4");
__asm__(".extern D_001D8FA4, 4");
__asm__(".extern D_001D8FA8, 4");
__asm__(".extern D_001D8FAC, 4");
__asm__(".extern D_001D8FB8, 4");
__asm__(".extern D_001D8FBC, 4");
__asm__(".extern D_001D8FC0, 4");
__asm__(".extern D_001D8FC4, 4");
__asm__(".extern D_001D8FB0, 4");
__asm__(".extern D_001D8FB4, 4");
__asm__(".extern D_001D8F90, 4");
void func_003C0760(u8 *self) {
    extern void func_003C3278(u8 *, s32, u8 *);
    extern void func_003A97F8(s32, unsigned long);
    extern void func_0038CB30(void);
    extern void func_0038D408();
    extern s32 func_0038DFB8(s32, s32, f32);
    extern void func_0038D200(f32 *, void *, f32);
    extern void func_003D9AF8(void *, s32, s32, s32, s32, f32);
    vu0_v4 axis0, axis1, axis2, center, draw[4], matrix[4];
    f32 scale, phase, t, width, length;
    s32 i, j;
    s32 odd;
    u8 stagger;
    s32 color;
    vu0_v4 *table;
    scale = D_001DA334 / (D_001D8E60 * 0.020000001f);
    if (scale > D_001D8FC8) {
        func_003C3278(self, 0, (u8 *)matrix);
        scale = 1.0f;
        {
            s32 tick = D_001D9D00 % D_001D8F94;
            phase = (f32)tick / (f32)D_001D8F94;
        }
        table = (vu0_v4 *)&D_001D8E80;
        func_003A97F8(8, 0);
        func_003A97F8(20, 0xFF9000000260UL);
        func_003A97F8(71, 0x533F1);
        func_0038CB30();
        for (i = 0; i < 4; i++) {
            axis0 = matrix[1];
            axis1 = matrix[2];
            axis2 = matrix[0];
            func_0038D408(&center, (void *)((i << 4) + (s32)table), matrix);
            for (j = 0; j < D_001D8F9C; j++) {
                odd = i & 1;
                stagger = odd;
                t = (f32)((D_001DA338 + (D_001D8F98 / D_001D8F9C) * j) % D_001D8F98) / (f32)D_001D8F98;
                if (stagger) {
                    t += 0.5f;
                    if (t > 1.0f) t -= 1.0f;
                }
                t *= t;
                if (i < 2) {
                    length = (D_001D8FA4 - D_001D8FA0) * t * scale + D_001D8FA0;
                    width = (D_001D8FAC - D_001D8FA8) * t + D_001D8FA8;
                } else {
                    length = (D_001D8FBC - D_001D8FB8) * t * scale + D_001D8FB8;
                    width = (D_001D8FC4 - D_001D8FC0) * t + D_001D8FC0;
                }
                color = func_0038DFB8(D_001D8FB0, D_001D8FB4, t);
                color = (color & 0xFFFFFF) | ((s32)((f32)(((u32)color & 0xFF000000) >> 24) * scale) << 24);
                func_0038D200(&draw[0].x, &axis0, width);
                func_0038D200(&draw[1].x, &axis1, width);
                func_0038D200(&draw[2].x, &axis2, length);
                vec_sub_ab(&draw[3], &center, &draw[2]);
                func_003D9AF8(draw, D_001D8F90, color, 4, 1, phase + t + (f32)odd * 0.5f);
            }
        }
        func_003A97F8(71, 0x5360B);
    }
}
/* localdecomp:end func_003C0760 */

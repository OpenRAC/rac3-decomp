/* PAL near miss (Codex wave 10): near miss: 45 words differ with the file's flags.
 * Worker's note: 45 diff: w533/func_L01_003298C8.01.log; fixed -fopt-stack produces sd 8-byte slots/frame 0x80 vs retail sq 16-byte slots/frame 0xD0; sq_ra injection cannot resize slots. Additional colour/copy register and final float scheduling residuals. No alternate flags ...
 */
#include "common.h"
/* localdecomp:start func_L01_003298C8 */
typedef int Q_003298C8 __attribute__((mode(TI)));
u8 *func_L01_003298C8(Q_003298C8 *pos, Q_003298C8 *origin, s32 life, s32 kind, s32 a4, s32 a5, void *colours, s32 a7, s16 a8, s16 a9, f32 scale, f32 opacity) {
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038CC88(void *, void *, s32);
    extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    u8 *moby = func_003C24B0(0x1A50, 0x80);
    u8 *vars;
    if (moby) {
        vars = *(u8 **)(moby + 0x68);
        moby[0x30] = 0xFF;
        *(s16 *)(moby + 0x32) = 0xFF;
        moby[0x31] = 1;
        moby[0x23] = 0x80;
        *(s32 *)(vars + 0x34) = a4;
        *(s32 *)(vars + 0x38) = a7;
        *(f32 *)(moby + 0x2C) *= scale;
        *(s16 *)(vars + 0x3C) = a8;
        *(s16 *)(vars + 0x3E) = a9;
        if (colours) func_0038CC88(vars + 0x20, colours, 0x10);
        else {
            *(u32 *)(vars + 0x20) = 0x2FFFFFFF;
            *(u32 *)(vars + 0x24) = 0x2F808080;
            *(u32 *)(vars + 0x28) = 0x2FC0C0C0;
            *(u32 *)(vars + 0x2C) = 0x2F404040;
        }
        func_L01_0043B9E8(moby, 0x7F, 0x7F, 0x7F);
        *(Q_003298C8 *)(moby + 0x10) = *pos;
        *(Q_003298C8 *)vars = *origin;
        *(f32 *)(vars + 0x10) = func_003824E0(0.12566371262073517f, 0.25132742524147034f);
        *(f32 *)(vars + 0x14) = func_003824E0(0.12566371262073517f, 0.25132742524147034f);
        *(s16 *)(vars + 0x18) = life;
        *(s16 *)(vars + 0x1A) = life;
        *(s32 *)(vars + 0x30) = kind;
        if (kind == 3) *(s32 *)(vars + 0x30) = func_00382468(3);
        *(s16 *)(vars + 0x1E) = (s32)(opacity * 128.0f);
        *(s16 *)(vars + 0x1C) = (s32)(*(f32 *)(moby + 0x2C) * 128.0f);
        *(s32 *)(moby + 0x78) = a5;
        func_003C7C38(moby);
    }
    return moby;
}
/* localdecomp:end func_L01_003298C8 */

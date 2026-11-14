/* NTSC-U draft (2026-11-14, Codex worker): C of func_L30_00351128, the NTSC-U twin of func_L30_00352050, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 2 words differ with its file's flags.
 */
/* Near: 2 diff with assigned flags; best log check03.log.
 * Only the first VU0 pair loads temp/position into reversed registers.
 * Three other legal VU0 helper spellings yielded the same four-diff block. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L30_00351128 */
extern s32 D_L30_001DF2C0;
extern f32 D_001DDA58_sda;
extern f32 D_001DDA5C_sda;
extern vu0_v4 D_L30_001E2120[];
__asm__(".extern D_001DDA58_sda, 4");
__asm__(".extern D_001DDA5C_sda, 4");
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_003886E8(void *, void *, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u32 func_L01_00445C50(u32, s32);
extern s32 func_0037E208(s32, s32);
extern void *func_L01_00462190(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L30_00351128(void *unused, void *source, void *origin) {
    vu0_v4 v, temp;
    f32 strength;
    f32 elevation, azimuth;
    u32 color1, color2;
    s32 size;
    if (D_L30_001DF2C0 % 10 == 0) {
        strength = D_001DDA58_sda;
        elevation = func_0037E250(0.2617993950843811f, 1.0471975803375244f);
        azimuth = func_0037E2A8();
        func_003886E8(&temp, D_L30_001E2120, D_001DDA5C_sda);
        vec_add_ab(&v, &v, &temp);
        func_0037E4B8(&v, func_0037E250(7.0f, 10.5f) * 0.01666666753590107f * 0.7f, azimuth, elevation);
        func_003886E8(&temp, D_L30_001E2120, D_001DDA5C_sda);
        vec_add_ba(&v, &temp, &v);
        vec_add_ba(&v, &v, origin);
        color1 = func_L01_00445C50(0x4F007FFF, 0);
        color2 = func_L01_00445C50(0x1F00007F, 0);
        size = func_0037E208(0x28, 0x41);
        func_L01_00462190(source, &v, color1, color2, size, 1, -1, -1, 0, strength * 40000.0f);
    }
}
/* localdecomp:end func_L30_00351128 */

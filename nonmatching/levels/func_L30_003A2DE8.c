/* NTSC-U draft (2026-11-14, Claude worker): C of func_L30_003A1358, the NTSC-U twin of func_L30_003A2DE8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L30_003A2C68.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L30_003A2DE8 (src/levels/shared/...) */
/* localdecomp:start func_L30_003A1358 */
#include "vu0.h"

extern s32 D_001DEA40_sda;
__asm__(".extern D_001DEA40_sda, 4");
extern s32 D_L30_001D66B0;
extern f32 D_001DE94C_sda;
__asm__(".extern D_001DE94C_sda, 4");
extern s32 D_001DE948_sda;
__asm__(".extern D_001DE948_sda, 4");
extern s32 D_001DE954_sda;
__asm__(".extern D_001DE954_sda, 4");
extern s32 D_001DE958_sda;
__asm__(".extern D_001DE958_sda, 4");
extern f32 D_001DE95C_sda;
__asm__(".extern D_001DE95C_sda, 4");
extern f32 D_001DE960_sda;
__asm__(".extern D_001DE960_sda, 4");
extern s32 D_001DE964_sda;
__asm__(".extern D_001DE964_sda, 4");
extern u8 *D_L30_0021F16C[];
extern u8 *D_L30_0021F208[];
extern void func_003888C8(void *, void *, void *);
extern f32 func_00388770(void *);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003894A0(s32, s32, f32);
extern u8 *func_L30_004400E0(void *, s32, s32, f32, f32, s32);

void func_L30_003A1358(u8 *self) {
    vu0_v4 v0;
    vu0_v4 v10;
    f32 t;
    f32 h;
    s32 c;
    s32 q;
    u8 *p;

    func_003888C8(&v0, &D_001DEA40_sda, self + 0xC0);
    vec_add_ba(&v10, &v0, self + 0x10);
    t = -v0.y / func_00388770(&v0);
    if (t >= -0.1f) {
        if (t < 0.6f) {
            t = 0.6f;
        }
        h = D_001DE94C_sda * 0.5f;
        q = (s32)(t * 96.0f) & 0xFF;
        p = func_L01_0046DCB8(&v10, &D_L30_001D66B0, 2, D_001DE948_sda | (q << 24), 0, q, q, 0,
                              (t * h + h) * 210000.0f, (t * h + h) * 210000.0f, 0.0f);
        if (p != 0) {
            p[2] = D_L30_0021F16C[0][0];
        }
    }
    c = func_003894A0(D_001DE954_sda, D_001DE958_sda, t);
    p = func_L30_004400E0(&v10, c, c & 0xFFFFFF, D_001DE95C_sda * (t * 0.35f + 0.35f + 0.3f),
                          D_001DE960_sda, D_001DE964_sda);
    if (p != 0) {
        p[2] = D_L30_0021F208[0][1];
    }
}
/* localdecomp:end func_L30_003A1358 */

#include "common.h"

/* NTSC-U counterpart of func_L30_003A2DE8 (src/levels/shared/L30_003A2DE8.c) */
/* localdecomp:start func_L30_003A1358 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0xC0 - 0x20];
    vu0_v4 mC0;
} O_003A2DE8;

__asm__(".extern D_L30_001DEA40, 8");
extern vu0_v4 D_L30_001DEA40 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DE948_003A1358, 4");
__asm__(".extern D_L30_001DE94C, 4");
__asm__(".extern D_L30_001DE954_003A1358, 4");
__asm__(".extern D_L30_001DE958_003A1358, 4");
__asm__(".extern D_L30_001DE95C_003A1358, 4");
__asm__(".extern D_L30_001DE960_003A1358, 4");
__asm__(".extern D_L30_001DE964_003A1358, 4");

extern s32 D_L30_001DE948_003A1358;
extern f32 D_L30_001DE94C;
extern s32 D_L30_001DE954_003A1358;
extern s32 D_L30_001DE958_003A1358;
extern f32 D_L30_001DE95C_003A1358;
extern f32 D_L30_001DE960_003A1358;
extern s32 D_L30_001DE964_003A1358;
extern s32 D_L30_001D66B0_003A1358;
extern u8 *D_L30_0021F16C_003A1358 __attribute__((section(".data")));
extern u8 *D_L30_0021F208_003A1358 __attribute__((section(".data")));
extern void func_003888C8(void *, void *, void *);
extern f32 func_00388770(void *);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003894A0(s32, s32, f32);
extern u8 *func_L30_004400E0(void *, s32, s32, f32, f32, s32);

void func_L30_003A1358(O_003A2DE8 *a0) {
    vu0_v4 dir;
    vu0_v4 p;
    f32 f;
    s32 c;
    u8 *r;

    func_003888C8(&dir, &D_L30_001DEA40, &a0->mC0);
    vec_add_ba(&p, &dir, &a0->pos);
    f = -dir.y / func_00388770(&dir);
    if (f >= -0.1f) {
        if (f < 0.6f) {
            f = 0.6f;
        }
        c = (u8)(s32)(f * 96.0f);
        r = func_L01_0046DCB8(&p, &D_L30_001D66B0_003A1358, 2, D_L30_001DE948_003A1358 | (c << 24), 0, c, c, 0,
                              (f * (D_L30_001DE94C * 0.5f) + D_L30_001DE94C * 0.5f) * 210000.0f,
                              (f * (D_L30_001DE94C * 0.5f) + D_L30_001DE94C * 0.5f) * 210000.0f, 0.0f);
        if (r != 0) {
            r[2] = D_L30_0021F16C_003A1358[0];
        }
    }
    {
        s32 col = func_003894A0(D_L30_001DE954_003A1358, D_L30_001DE958_003A1358, f);
        r = func_L30_004400E0(&p, col, col & 0xFFFFFF,
                              D_L30_001DE95C_003A1358 * (f * 0.35f + 0.35f + 0.3f), D_L30_001DE960_003A1358, D_L30_001DE964_003A1358);
        if (r != 0) {
            r[2] = D_L30_0021F208_003A1358[1];
        }
    }
}
/* localdecomp:end func_L30_003A1358 */

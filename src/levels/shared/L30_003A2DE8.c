#include "common.h"

typedef struct { u8 pad[0x30]; u8 x30[0x20]; s32 x50; u8 pad54[0x6C - 0x54]; f32 x6C; u8 pad70[8]; f32 x78; } V_3A1500;
typedef struct { u8 pad[0x68]; V_3A1500 *x68; u8 pad6C[0xF0 - 0x6C]; f32 xF0; } O_3A1500;

/* localdecomp:start func_L30_003A2DE8 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0xC0 - 0x20];
    vu0_v4 mC0;
} O_003A2DE8;

__asm__(".extern D_L30_001DEA00, 8");
extern vu0_v4 D_L30_001DEA00 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DE908, 4");
__asm__(".extern D_L30_001DE90C, 4");
__asm__(".extern D_L30_001DE914, 4");
__asm__(".extern D_L30_001DE918, 4");
__asm__(".extern D_L30_001DE91C, 4");
__asm__(".extern D_L30_001DE920, 4");
__asm__(".extern D_L30_001DE924, 4");

extern s32 D_L30_001DE908;
extern f32 D_L30_001DE90C;
extern s32 D_L30_001DE914;
extern s32 D_L30_001DE918;
extern f32 D_L30_001DE91C;
extern f32 D_L30_001DE920;
extern s32 D_L30_001DE924;
extern s32 D_L30_001D66B0_003A2DE8;
extern u8 *D_L30_0021F16C __attribute__((section(".data")));
extern u8 *D_L30_0021F208 __attribute__((section(".data")));
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern u8 *func_L30_004437E8(void *, s32, s32, s32, f32, f32);

void func_L30_003A2DE8(O_003A2DE8 *a0) {
    vu0_v4 dir;
    vu0_v4 p;
    f32 f;
    s32 c;
    u8 *r;

    func_0038D000(&dir, &D_L30_001DEA00, &a0->mC0);
    vec_add_ba(&p, &dir, &a0->pos);
    f = -dir.y / func_0038CEA8(&dir);
    if (f >= -0.1f) {
        if (f < 0.6f) {
            f = 0.6f;
        }
        c = (u8)(s32)(f * 96.0f);
        r = func_L01_004713C8(&p, &D_L30_001D66B0_003A2DE8, 2, D_L30_001DE908 | (c << 24), 0, c, c, 0,
                              (f * (D_L30_001DE90C * 0.5f) + D_L30_001DE90C * 0.5f) * 210000.0f,
                              (f * (D_L30_001DE90C * 0.5f) + D_L30_001DE90C * 0.5f) * 210000.0f, 0.0f);
        if (r != 0) {
            r[2] = D_L30_0021F16C[0];
        }
    }
    {
        s32 col = func_0038DBD8(D_L30_001DE914, D_L30_001DE918, f);
        r = func_L30_004437E8(&p, col, col & 0xFFFFFF, (D_L30_001DE924 * 5 + 2) / 6,
                              D_L30_001DE91C * (f * 0.35f + 0.35f + 0.3f), D_L30_001DE920);
        if (r != 0) {
            r[2] = D_L30_0021F208[1];
        }
    }
}
/* localdecomp:end func_L30_003A2DE8 */

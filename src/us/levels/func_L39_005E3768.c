#include "common.h"

/* NTSC-U counterpart of func_L39_005E5CD8 (src/levels/shared/L39_005E5678.c) */
/* localdecomp:start func_L39_005E3768 */
extern s32 D_001A5990[];
extern f32 D_001D837C_sda;
extern f32 D_001D8380_sda;
extern f32 D_001D8384_sda;
__asm__(".extern D_001D837C_sda, 4");
__asm__(".extern D_001D8380_sda, 4");
__asm__(".extern D_001D8384_sda, 4");
extern void func_L01_00512568(s32, f32 *, f32 *);
extern void func_L01_00512480(s32, f32, f32);

void func_L39_005E3768(void) {
    f32 y1, x1, y0, x0;
    f32 a, b, base, d;
    f32 e = 0.008f;
    f32 z = 0.0f;

    b = (f32)D_001A5990[3] * (1.0f / 1024.0f);
    a = (f32)D_001A5990[4] * (1.0f / 1024.0f);
    x0 = z;
    y0 = z;
    x1 = z;
    y1 = z;
    func_L01_00512568(0x1E0009, &x0, &y0);
    func_L01_00512568(0x1E000C, &x1, &y1);
    base = D_001D837C_sda + D_001D8384_sda;
    d = D_001D8380_sda - base - e;
    base = base + e;
    x0 = base + d * b;
    x1 = base + d * a;
    func_L01_00512480(0x1E0009, x0, y0);
    func_L01_00512480(0x1E000C, x1, y1);
}
/* localdecomp:end func_L39_005E3768 */

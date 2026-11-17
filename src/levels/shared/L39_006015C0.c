#include "common.h"

/* localdecomp:start func_L39_006015C0 */
typedef struct { f32 x, y; } V2_006015C0;
typedef struct { V2_006015C0 *f0; V2_006015C0 *f4; u8 p8[4]; s32 *fC; f32 *f10; u8 p14[0x18]; f32 *f2C; u8 p30[4]; s32 f34; u8 p38[2]; u8 f3A; } O_006015C0;
extern void func_003AA320(s32, s32, f32, f32, f32, f32, f32);
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern f32 D_001D9AF8_sda;
__asm__(".extern D_001D9AF8_sda, 4");
extern f32 D_001D9AFC_sda;
__asm__(".extern D_001D9AFC_sda, 4");
extern f32 D_001D9B00_sda;
__asm__(".extern D_001D9B00_sda, 4");
extern f32 D_001D9B04_sda;
__asm__(".extern D_001D9B04_sda, 4");
extern f32 D_L39_0024CBD8;
__asm__(".extern D_L39_0024CBD8, 16");
extern s32 D_L39_0024CBD0_006015C0;
__asm__(".extern D_L39_0024CBD0_006015C0, 16");

void func_L39_006015C0(O_006015C0 *o) {
    f32 zero = 0.0f;

    if (*o->f10 != zero && o->f34 != 0) {
        f32 y = zero;
        f32 x = y;
        f32 z0, z1;
        if (o->f3A) {
            if (*D_L39_00241120 >= 2) {
                if (*D_L39_00241120 >= 3) {
                    x = D_001D9B00_sda;
                    y = D_001D9B04_sda;
                } else {
                    x = D_001D9AF8_sda;
                    y = D_001D9AFC_sda;
                }
            }
        }
        z0 = 0.0f;
        z1 = 0.0f;
        {
            V2_006015C0 *r = o->f4;
            V2_006015C0 *p = o->f0;
            f32 px = p->x + x;
            f32 py = p->y + y;
            s32 fl = *o->fC;
            f32 w = r->y * D_L39_0024CBD8 + (D_L39_0024CBD0_006015C0 == 1 ? z0 : z1);
            func_003AA320(o->f34, fl, px, py, r->x, w, *o->f2C);
        }
    }
}
/* localdecomp:end func_L39_006015C0 */

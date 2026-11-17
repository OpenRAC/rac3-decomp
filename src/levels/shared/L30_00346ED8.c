#include "common.h"

/* localdecomp:start func_L30_00346ED8 */
__asm__(".extern D_L30_001DCFC4, 4");
__asm__(".extern D_L30_001DCFC8, 4");
__asm__(".extern D_L30_001DCFD4, 4");
__asm__(".extern D_L30_001DCF3C, 4");
__asm__(".extern D_L30_001DCF58, 4");
__asm__(".extern D_L30_001DCF5C, 4");
__asm__(".extern D_L30_001DCF6C, 4");
__asm__(".extern D_L30_001DCF70, 4");
__asm__(".extern D_L30_001DCF88, 4");
__asm__(".extern D_L30_001DCF8C, 4");
__asm__(".extern D_L30_001DCFA4, 4");
__asm__(".extern D_L30_001DCFA8, 4");
extern s32 D_L30_001DCFC4;
extern s32 D_L30_001DCFC8;
extern s32 D_L30_001DCFD4;
extern s32 D_L30_001DCF3C;
extern s32 D_L30_001DCF58;
extern s32 D_L30_001DCF5C;
extern f32 D_L30_001DCF6C;
extern s32 D_L30_001DCF70;
extern s32 D_L30_001DCF88;
extern s32 D_L30_001DCF8C;
extern f32 D_L30_001DCFA4;
extern s32 D_L30_001DCFA8;
__asm__(".extern D_L30_001E1188, 16");
extern u8 D_L30_001E1188;
__asm__(".extern D_L30_001E11A8_00346ED8, 16");
extern u8 D_L30_001E11A8_00346ED8;
extern s32 func_L30_0034DBA0(s32, s32);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L30_00346DA8(u8 *);
extern void func_L30_00347060(u8 *);

typedef struct { s32 a; s32 c; } S_00346ED8;

void func_L30_00346ED8(u8 *moby) {
    S_00346ED8 *p = *(S_00346ED8 **)(moby + 0x68);
    s32 i;
    for (i = 0; i < 16; i++) {
        p->a = (f32)D_L30_001DCFD4 * (f32)i * 0.0625f;
        p->c = func_L30_0034DBA0(D_L30_001DCFC4, D_L30_001DCFC8);
        p++;
    }
    if (D_L30_001DCF3C == 0) {
        D_L30_001DCF3C = 1;
        func_L03_0034B218(&D_L30_001E1188, D_L30_001DCF58, D_L30_001DCF5C, D_L30_001DCF6C, D_L30_001DCF70, (void *)func_L30_00346DA8);
        func_L03_0034B218(&D_L30_001E11A8_00346ED8, D_L30_001DCF88, D_L30_001DCF8C, D_L30_001DCFA4, D_L30_001DCFA8, (void *)func_L30_00347060);
    }
}
/* localdecomp:end func_L30_00346ED8 */

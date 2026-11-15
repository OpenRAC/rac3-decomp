#include "common.h"

/* localdecomp:start func_L32_003554C0 */
typedef struct {
    u8 pad0[0x78];
    long f78;
    u8 pad80[0x8];
    long f88;
} S_003554C0;

extern u8 D_001A4BE0[];
extern S_003554C0 D_L32_00284700;
__asm__(".extern D_L32_001DD6A0, 4");
__asm__(".extern D_L32_001DD6A8, 4");
extern f32 D_L32_001DD6A0;
extern s32 D_L32_001DD6A8;
extern void func_L30_0034CDC0(f32 *, f32 *, f32 *, f32 *, f32);
extern void func_L24_00358F70(f32 *m, s32 a1, f32 a, f32 b, f32 c, f32 d, f32 e);
extern void func_L30_0034C460(void *, s32, s32, s32, s32);
extern void func_L30_0034C428(void *);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, void *, s32);

void func_L32_003554C0(u8 *a0) {
    f32 x0, x1, y0, y1;
    f32 w;
    u8 *h;
    u8 *p = *(u8 **)(a0 + 0x68);

    func_L30_0034CDC0(&x0, &x1, &y0, &y1, 1.0f);
    w = *(f32 *)(p + 0xD0) * D_L32_001DD6A0 * (y1 - y0);
    func_L24_00358F70((f32 *)&D_L32_00284700, 1, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
    func_L30_0034C460(&D_L32_00284700, 0x80808080, -1, -1, -1);
    func_L30_0034C428(&D_L32_00284700);
    D_L32_00284700.f78 = func_00389598(D_L32_001DD6A8);
    D_L32_00284700.f88 = (0x8000L << 24) | 0x8A;
    h = D_001A4BE0;
    func_L24_00358F70((f32 *)&D_L32_00284700, 0, x0, x1, y1, y1 - w, *(f32 *)(h + 0x84) - 3.0f);
    func_003D2DA0(&D_L32_00284700, 0, 0);
    func_L24_00358F70((f32 *)&D_L32_00284700, 0, x0, x1, y0 + w, y0, *(f32 *)(h + 0x84) - 3.0f);
    func_003D2DA0(&D_L32_00284700, 0, 0);
}
/* localdecomp:end func_L32_003554C0 */

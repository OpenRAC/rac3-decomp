#include "common.h"

/* NTSC-U counterpart of func_L39_005516B0 (src/levels/shared/L39_005515E8.c): 0.02 -> 0.0166667 */
/* localdecomp:start func_L39_00550D60 */
typedef int u128_005516B0 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x10];
    u128_005516B0 pos;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
} R_005516B0;

extern u8 D_L39_003C14E0[];
extern void func_L39_00550E78(u8 *rec, s32 index);
extern f32 func_L01_00447C00(f32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B2568(f32, f32);

void func_L39_00550D60(u8 *a0, u128_005516B0 *a1) {
    u8 *st = *(u8 **)(a0 + 0x68);
    s32 i = *(s16 *)(st + 0x30);
    s32 b = st[0x3A];
    s32 off;
    R_005516B0 *r;
    f32 v;

    off = b * 0x12C0 + i * 0x30;
    *(u128_005516B0 *)(D_L39_003C14E0 + off + 0x10) = *a1;
    v = func_L01_00447C00((f32)i * 0.69813168f);
    off = b * 0x12C0;
    r = (R_005516B0 *)(D_L39_003C14E0 + (i * 0x30 + off));
    r->f20 = v;
    r->f28 = func_L39_005B2510(3.0f, 3.0f) * 0.017453292f;
    r->f24 = 0.25f;
    r->f2C = func_L39_005B2568(0.01f, 0.2f) * 0.0166666675f;
    func_L39_00550E78(D_L39_003C14E0 + off, i);
    *(s16 *)(st + 0x30) += 1;
}
/* localdecomp:end func_L39_00550D60 */

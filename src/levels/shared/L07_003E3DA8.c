#include "common.h"

/* localdecomp:start func_L07_003E3DA8 */
#include "vu0.h"

extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_004BA800(void);
extern void func_L01_00424D88(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001A4C60[];

void func_L07_003E3DA8(u8 *a0, u8 *a1) {
    vu0_v4 v;

    func_0038CF68(&v, a1, -0.5f);
    vec_add_ba(&v, a0 + 0x10, &v);
    if (D_001D545C == 20 && func_0038CF38(a0 + 0x10, D_001A4C60) < 32.0f) {
        func_L01_003303B8(&v, 0, 10, 6, 6, 6, 6, 0,
            *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 0.5f, 0.0f, 0.0f, 0.0f,
            0, 1, 0, 0, 0, 1, 0x210000, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000, 0xFF8F00,
            0xFF6430, 0x7FFFA060, 0x28FF0000, 0xFF6430, 0);
    } else if (D_001D545C != 20 || func_L01_004BA800() != 0) {
        func_L01_003303B8(&v, 0, 15, 12, 12, 12, 12, 1,
            *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 0.5f, 0.0f, 0.0f, 0.0f,
            1, 1, 1, 1, 0, 1, 0x210000, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000, 0xFF8F00,
            0xFF6430, 0x7FFFA060, 0x28FF0000, 0xFF6430, 0);
    }
    if (*(s32 *)(a1 + 0x18) != -1) {
        func_L01_00424D88(*(s32 *)(a1 + 0x18));
    }
    *(s32 *)(a1 + 0x18) = -1;
    func_003A52A0(0, 0, a0);
    func_003C2880(a0);
}
/* localdecomp:end func_L07_003E3DA8 */

/* NTSC-U draft (2026-11-14, Claude worker): C of func_L05_003BB4D8, the NTSC-U twin of func_L05_003BD448, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 2 words differ with its file's flags.
 */
#include "common.h"

/* NTSC-U counterpart of func_L05_003BD448 (src/levels/shared/L05_003BD078.c) */
/* localdecomp:start func_L05_003BB4D8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct Row_003BD448 { s16 h[4]; } Row_003BD448;
typedef struct { u8 pad[0x32]; s16 h32; } M_003BB4D8;
typedef struct { u8 pad[0x20]; u8 b20; } M20_003BB4D8;

extern s32 D_L05_001DEB20;
__asm__(".extern D_L05_001DEB20, 4");
extern Row_003BD448 D_L05_002A6540[];
extern Row_003BD448 D_L05_002A65E0[];
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E2A8(void);

u8 *func_L05_003BB4D8(u8 *a0, u8 *a1, s32 a2, u8 *a3, s32 t0, s32 t1) {
    u8 *m;
    u8 *s;
    s32 i;
    s32 v;
    u8 one = 1;

    m = func_003BCFB0(0x1B6F, 0x80);
    if (m != 0) {
        s = *(u8 **)(m + 0x68);
        *(s32 *)(s + 0x60) = t1;
        m[0x30] = 0xFF;
        m[0x31] = one;
        ((M20_003BB4D8 *)m)->b20 = 0;
        ((M_003BB4D8 *)m)->h32 = 0xFF;
        *(u8 **)(m + 0xB8) = a1;
        *(u128_t *)(s + 0x30) = *(u128_t *)a3;
        *(u128_t *)(m + 0x10) = *(u128_t *)a0;
        v = D_L05_001DEB20;
        *(s32 *)(s + 0x10) = v;
        if (*(s16 *)(a1 + 0xAA) == 0x1BF6) {
            *(s32 *)(s + 0x10) = v * 10;
        }
        *(s32 *)(s + 0x1C) = t0;
        *(f32 *)(s + 0x14) = 1.0f / (f32)*(s32 *)(s + 0x10);
        *(f32 *)(m + 0xF0) = func_0037E2A8();
        *(f32 *)(m + 0xF4) = func_0037E2A8();
        *(f32 *)(m + 0xF8) = func_0037E2A8();
        *(f32 *)(s + 0x0) = func_0037E2A8();
        *(f32 *)(s + 0x4) = func_0037E2A8();
        *(f32 *)(s + 0x8) = func_0037E2A8();
        for (i = 0; i < 3; i++) {
            D_L05_002A6540[*(s32 *)(s + 0x60)].h[i] = -1;
            D_L05_002A65E0[*(s32 *)(s + 0x60)].h[i] = 5;
        }
        m[0x20] = 0;
    }
    return m;
}
/* localdecomp:end func_L05_003BB4D8 */

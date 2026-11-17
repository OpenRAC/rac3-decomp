/* NTSC-U draft (2026-11-14, Claude worker): C of func_L09_003BD3A0, the NTSC-U twin of func_L09_003BEC20, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/09_tyhrranosis/L09_003B8580.c's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L09_003BEC20 (src/levels/shared/L09_003BEC20.c) */
/* localdecomp:start func_L09_003BD3A0 */
typedef struct {
    u8 pad0[0x144];
    u8 *w144;
    s32 w148;
} Ply_003BD3A0;

extern u8 *D_L09_001E011C;
__asm__(".extern D_L09_001E011C, 16");
extern Ply_003BD3A0 D_L09_001E2C00[];
extern void func_L09_003BABD8(void *, s32, s32, s32, s32);
extern s32 func_0037E208(s32, s32);

s32 func_L09_003BD3A0(u8 *self, s32 a1, s32 a2, s32 a3, s32 t0) {
    u8 *base = D_L09_001E011C;
    u8 *s = *(u8 **)(self + 0x68);
    u8 *e;

    s[0xD42] &= 0xFE;
    e = base + (*(s32 *)(s + 0xCD0) << 8);
    func_L09_003BABD8(self, a1, a2, a3, t0);
    *(s16 *)(s + 0xD38) = (s16)((f32)func_0037E208(5, 10) * 60.0f);
    *(s16 *)(s + 0xD30) = (s16)((f32)func_0037E208(15, 25) * 60.0f);
    s[0xD40] = 1;
    *(s16 *)(s + 0xD34) = 0;
    if (D_L09_001E2C00[0].w144 == self) {
        D_L09_001E2C00[0].w144 = 0;
    }
    if (D_L09_001E2C00[0].w144 == 0) {
        D_L09_001E2C00[0].w144 = e;
        D_L09_001E2C00[0].w148 = 0;
    }
    return 1;
}
/* localdecomp:end func_L09_003BD3A0 */

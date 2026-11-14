/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00304888, the NTSC-U twin of func_L01_00304AA0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_00304AA0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_00304AA0 (src/levels/shared/L01_00304AA0.c) */
/* localdecomp:start func_L01_00304888 */
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[0xEE];
} Row_00304888;
extern u8 *D_001DC604_sda;
__asm__(".extern D_001DC604_sda, 4");
extern u8 D_001425D1[];
extern Row_00304888 D_L01_002C5640[];
extern s32 func_0013D3E0(void);
extern void func_L01_00305620(void *, void *);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00470258(void *, void *, s32, f32, s32, s16, s32);
extern void func_L01_00463938(void *, void *, s32, f32, f32);
void func_L01_00304888(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);
    s32 idx;
    idx = *(s32 *)(s + 0x48) - (*(s32 *)(s + 0x44) - 2);
    if (idx <= -1) {
        idx = idx + 0x23;
    }
    if (func_0013D3E0() % 7 == 0) {
        func_L01_00305620(self, D_001DC604_sda + (idx << 6));
    }
    if (func_0013D3E0() % 0x16 == 0) {
        if ((&D_L01_002C5640[D_001425D1[0]])->b1 >= 4) {
            if ((func_0013D3E0() & 1) != 0) {
                func_L01_00470258(D_001DC604_sda + (idx << 6), D_001DC604_sda + (idx << 6) + 0x10, (func_0037E208(0x40, 0x64) << 16) | 0x64004040, func_0037E250(0.1f, 0.2f) * 210000.0f, 0xFF0A0A, func_0037E208(0x14, 0x50), 0);
            }
        } else {
            func_L01_00463938(D_001DC604_sda + (idx << 6), D_001DC604_sda + (idx << 6) + 0x10, 0, -1.0f, 0.0f);
        }
    }
}
/* localdecomp:end func_L01_00304888 */

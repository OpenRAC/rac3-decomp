/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_0048B198, the NTSC-U twin of func_L01_0048EA10, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0048B738.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_0048EA10 (src/levels/shared/L01_0048B738.c) */
/* localdecomp:start func_L01_0048B198 */
extern s32 D_001E09AC_sda;
__asm__(".extern D_001E09AC_sda, 4");
extern f32 D_001D8CD4_sda;
__asm__(".extern D_001D8CD4_sda, 4");
extern f32 D_001D8CC8_sda;
__asm__(".extern D_001D8CC8_sda, 4");
extern f32 D_001E09A8_sda;
__asm__(".extern D_001E09A8_sda, 4");
extern s32 D_001E09B4_sda;
__asm__(".extern D_001E09B4_sda, 4");
extern f32 D_001E09B0_sda;
__asm__(".extern D_001E09B0_sda, 4");
extern s32 D_001D8CB0_sda;
__asm__(".extern D_001D8CB0_sda, 4");
extern s32 D_001D8CAC_sda;
__asm__(".extern D_001D8CAC_sda, 4");
extern s32 D_001D8CA8_sda;
__asm__(".extern D_001D8CA8_sda, 4");
extern f32 D_001D8CD8_sda;
__asm__(".extern D_001D8CD8_sda, 4");
extern u8 *D_001D52FC;
extern s32 D_L01_001E09D4;
extern s32 D_L01_001E09D8;
extern s32 func_0039FF28(s32, s32, s32);
extern void func_L01_00512480(s32, f32, f32);
extern void func_003B60B0(s32);

void func_L01_0048B198(void) {
    s32 flags;

    if (D_001E09AC_sda == 0) {
        D_001E09A8_sda = D_001D8CD4_sda + D_001D8CC8_sda + 0.002f;
        D_001E09AC_sda = 1;
    }
    if (D_001E09B4_sda == 0) {
        D_001E09B0_sda = D_001D8CC8_sda + 0.03846154f;
        D_001E09B4_sda = 1;
    }
    flags = *(s32 *)(D_001D52FC + 0x1C4);
    if (flags & 0x1000) {
        func_0039FF28(3, 0, 0);
        D_L01_001E09D4 = 0x14;
        D_001D8CB0_sda--;
        if (D_001D8CB0_sda < 0) {
            D_001D8CB0_sda = 0;
            if (D_001D8CAC_sda - 1 >= 0) {
                D_L01_001E09D8 = 2;
            }
        }
    } else if (flags & 0x4000) {
        if (D_001D8CB0_sda < D_001D8CA8_sda - 1) {
            func_0039FF28(3, 0, 0);
            D_L01_001E09D4 = 0x14;
            D_001D8CB0_sda++;
            if (D_001D8CB0_sda >= 3) {
                D_001D8CB0_sda = 2;
                if (D_001D8CAC_sda + 1 <= D_001D8CA8_sda - 3) {
                    D_L01_001E09D8 = 1;
                }
            }
        }
    }
    func_L01_00512480(0x160008, D_001D8CD8_sda, D_001E09A8_sda + (f32)D_001D8CB0_sda * D_001E09B0_sda);
    func_003B60B0(0x160008);
}
/* localdecomp:end func_L01_0048B198 */

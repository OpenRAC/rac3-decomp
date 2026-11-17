/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00301968, the NTSC-U twin of func_L01_00301B10, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses -mvu0-use-vf0-vf2 @ps2as (PAL line lacks vu0 + @ps2as)" (src/levels/shared/L01_002FEA20.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L01_00301968 */
extern vu0_v4 D_L01_001E2A40;
extern vu0_v4 D_001A4EC0;
extern f32 D_001DC538_sda;
__asm__(".extern D_001DC538_sda, 4");
extern f32 D_001DC53C_sda;
__asm__(".extern D_001DC53C_sda, 4");
extern s32 D_001DC540_sda;
__asm__(".extern D_001DC540_sda, 4");
extern s32 D_001DC544_sda;
__asm__(".extern D_001DC544_sda, 4");
extern s32 D_001DC548_sda;
__asm__(".extern D_001DC548_sda, 4");
extern s32 D_001DC54C_sda;
__asm__(".extern D_001DC54C_sda, 4");
extern f32 D_001DC550_sda;
__asm__(".extern D_001DC550_sda, 4");
extern f32 D_001DC554_sda;
__asm__(".extern D_001DC554_sda, 4");
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_0037E1D8(s32);
extern void func_003886E8(void *, void *, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);

void func_L01_00301968(u8 *o) {
    vu0_v4 d;
    vu0_v4 v10;
    vu0_v4 v20;
    u8 *st;
    s32 color;

    vec_sub_ab(&d, &D_L01_001E2A40, o + 0x10);
    st = *(u8 **)(o + 0x68);
    func_003886E8(&v10, &D_001A4EC0, func_0037E250(D_001DC538_sda * 0.016666668f, D_001DC53C_sda * 0.016666668f));
    func_00389158(&v20, &v10, &d, func_0037E2A8());
    if (st[0x57] != 0) {
        color = D_001DC54C_sda;
    } else {
        color = D_001DC544_sda;
    }
    func_L01_00468DC0(o + 0x10, &v20, color, D_001DC550_sda, D_001DC540_sda, func_0037E1D8(0xFF) & 0xFF, 1, 0x40, 0);
    func_L01_00468DC0(o + 0x10, &v20, D_001DC548_sda, D_001DC554_sda, D_001DC540_sda, func_0037E1D8(0xFF) & 0xFF, 1, 0x40, 0);
}
/* localdecomp:end func_L01_00301968 */

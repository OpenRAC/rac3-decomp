/* NTSC-U draft (Claude wave K): C of func_L01_0030E388, the NTSC-U twin of func_L01_0030E630, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 276 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_0030E388", whose code is not the PAL one).
 * Worker's note: rough draft only: 276 raw diff lines of 288 (shift-sensitive: mine 288 words, retail 284, 23 opcode-only regions), draft near/func_L01_0030E388.low.c; the control flow and callee/argument structure are decoded and written, the register allocation is not yet ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0030E630 (src/levels/shared/L01_0030E630.c) */
/* localdecomp:start func_L01_0030E388 */
typedef int s128 __attribute__((mode(TI)));

extern vu0_v4 D_L01_001E2A40;
extern vu0_v4 D_001A4C90;
extern s32 D_L01_001D673C;
__asm__(".extern D_L01_001D673C, 16");
extern f32 D_001DC6A4_sda;
extern f32 D_001DC6A8_sda;
extern f32 D_001DC6AC_sda;
extern f32 D_001DC6B0_sda;
extern f32 D_001DC6B4_sda;
extern f32 D_001DC6B8_sda;
extern f32 D_001DC6BC_sda;
__asm__(".extern D_001DC6A4_sda, 4");
__asm__(".extern D_001DC6A8_sda, 4");
__asm__(".extern D_001DC6AC_sda, 4");
__asm__(".extern D_001DC6B0_sda, 4");
__asm__(".extern D_001DC6B4_sda, 4");
__asm__(".extern D_001DC6B8_sda, 4");
__asm__(".extern D_001DC6BC_sda, 4");
extern void func_00388830(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00389158(void *, void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0013D3E0(void);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_00467DA8(void *, s32, u32, s32, s32, void *, f32, f32, f32, s32);

void func_L01_0030E388(f32 *pos, s32 count, s32 mode) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    s32 i;
    s32 dir;
    f32 t;
    f32 speed;
    f32 life;
    f32 sc;
    u8 *p;

    vec_sub_ab(v20, &D_L01_001E2A40, pos);
    if (D_L01_001D673C == 0) {
        v20[2] = 0.0f;
        v30[0] = 0.0f;
        v30[1] = 0.0f;
        v30[2] = 1.0f;
        v30[3] = 1.0f;
    } else {
        vec_sub_ab(v40, pos, &D_001A4C90);
        func_00388830(v30, v40, 1.0f);
        t = func_00388730(v30, v20);
        func_003886E8(v40, v30, t);
        vec_sub_ab(v20, v20, v40);
    }
    for (i = count; i > 0; i--) {
        life = func_0037E250(D_001DC6B8_sda, D_001DC6BC_sda);
        dir = func_0037E1D8(2);
        if (dir == 0) {
            dir = -1;
        }
        func_00389158(v0, v20, v30, func_0037E250(-1.0471976f, 1.0471976f));
        speed = func_0037E250(D_001DC6A4_sda, D_001DC6A8_sda) * 0.016666668f;
        func_00388830(v0, v0, speed);
        t = func_0037E250(D_001DC6AC_sda, D_001DC6B0_sda) * 0.016666668f;
        *(s128 *)v10 = *(s128 *)pos;
        v0[2] = t;
        v10[0] += func_L01_00440918(0.0f, 0.15f);
        v10[1] += func_L01_00440918(0.0f, 0.15f);
        v10[2] += func_L01_00440918(0.0f, 0.15f);
        if (mode == 0) {
            if ((func_0013D3E0() & 1) == 0) {
                sc = 3.5f;
                func_003886E8(v0, v0, 1.5f);
                p = func_L01_00467DA8(v10, 0x3C, 0x7F800000, 0, dir, v0, life * 0.1f * sc, life, D_001DC6B4_sda, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
                p = func_L01_00467DA8(v10, 0x3C, 0x7F7F7F7F, 1, -dir, v0, life * 0.07f * sc, life * 0.7f, D_001DC6B4_sda, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
            } else {
                vec_sub_ba(v40, &D_L01_001E2A40, v10);
                func_00388830(v40, v40, speed);
                sc = 20.5f;
                vec_add_ba(v0, v0, v40);
                p = func_L01_00467DA8(v10, 0x28, 0x7F800000, 0, dir, v0, life * 0.1f * sc, life, D_001DC6B4_sda, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
                p = func_L01_00467DA8(v10, 0x28, 0x7F7F7F7F, 1, -dir, v0, life * 0.07f * sc, life * 0.7f, D_001DC6B4_sda, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
            }
        } else {
            if ((func_0013D3E0() & 1) == 0) {
                sc = 3.0f;
                func_003886E8(v0, v0, 1.5f);
                p = func_L01_00467DA8(v10, 0x3C, 0x7F800000, 0, dir, v0, life * 0.1f * sc, life, D_001DC6B4_sda, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
                p = func_L01_00467DA8(v10, 0x3C, 0x7F7F7F7F, 1, -dir, v0, life * 0.07f * sc, life * 0.7f, D_001DC6B4_sda, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
            } else {
                vec_sub_ba(v40, &D_L01_001E2A40, v10);
                func_00388830(v40, v40, speed);
                sc = 2.5f;
                vec_add_ba(v0, v0, v40);
                p = func_L01_00467DA8(v10, 0x28, 0x7F800000, 0, dir, v0, life * 0.1f * sc, life, D_001DC6B4_sda, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
                p = func_L01_00467DA8(v10, 0x28, 0x7F7F7F7F, 1, -dir, v0, life * 0.07f * sc, life * 0.7f, D_001DC6B4_sda, 1);
                if (p != 0) {
                    p[9] = 0x74;
                }
            }
        }
    }
}
/* localdecomp:end func_L01_0030E388 */

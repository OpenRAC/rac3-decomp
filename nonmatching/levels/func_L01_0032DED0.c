/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_0032DA38, the NTSC-U twin of func_L01_0032DED0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0032C6B8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0032DED0 (src/levels/shared/L01_0032C6B8.c) */
/* localdecomp:start func_L01_0032DA38 */
extern vu0_v4 D_L01_001E2A40;
extern f32 D_L01_001DCED0;
__asm__(".extern D_L01_001DCED0, 4");
extern f32 D_L01_001DCED4;
__asm__(".extern D_L01_001DCED4, 4");
extern f32 D_L01_001DCED8;
__asm__(".extern D_L01_001DCED8, 4");
extern f32 D_L01_001DCEDC;
__asm__(".extern D_L01_001DCEDC, 4");
extern f32 D_L01_001DCEE0;
__asm__(".extern D_L01_001DCEE0, 4");
extern f32 D_L01_001DCEE4;
__asm__(".extern D_L01_001DCEE4, 4");
extern f32 D_L01_001DCEE8;
__asm__(".extern D_L01_001DCEE8, 4");
extern u8 D_001425C0[];
extern u8 D_L01_002C5640[];
extern void func_L01_004C41E8(void *, void *);
extern f32 func_00388730(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_00440918(f32, f32);
extern s32 func_0013D3E0(void);
extern u8 *func_L01_00467DA8(void *, s32, f32, f32, u32, s32, s32, void *, f32, s32);

void func_L01_0032DA38(u8 *pos, s32 count) {
    vu0_v4 velocity, at, delta, axis, base, t50;
    f32 size, speed;
    s32 spin, i;
    u32 colour;
    u8 *p;
    u8 *r;

    vec_sub_ab(&delta, &D_L01_001E2A40, pos);
    func_L01_004C41E8(pos, &axis);
    speed = func_00388730(&axis, &delta);
    func_003886E8(&base, &axis, speed);
    vec_sub_ab(&delta, &delta, &base);
    for (i = 0; i < count; i++) {
            colour = 0x7F000080;
            size = func_0037E250(D_L01_001DCEE4, D_L01_001DCEE8);
            spin = func_0037E1D8(2);
            if (spin == 0) spin--;
            func_00389158(&velocity, &delta, &axis, func_0037E250(-1.0471976f, 1.0471976f));
            speed = func_0037E250(D_L01_001DCED0, D_L01_001DCED4) * 0.016666668f;
            func_00388830(&velocity, &velocity, speed);
            velocity.z = func_0037E250(D_L01_001DCED8, D_L01_001DCEDC) * 0.016666668f;
            *(vu0_q *)&at = *(vu0_q *)pos;
            at.x += func_L01_00440918(0.0f, 0.15f);
            at.y += func_L01_00440918(0.0f, 0.15f);
            at.z += func_L01_00440918(0.0f, 0.15f);
            r = D_L01_002C5640 + D_001425C0[0x15] * 0xF0;
            if (r[1] >= 2) colour = 0x7F806060;
            if ((func_0013D3E0() & 1) == 0) {
                func_003886E8(&velocity, &velocity, 1.5f);
                p = func_L01_00467DA8(&at, 0x3C, size * 0.1f * 3.5f, size, colour, 0, spin, &velocity, D_L01_001DCEE0, 1);
                if (p) p[9] = 0x74;
                p = func_L01_00467DA8(&at, 0x3C, size * 0.07f * 3.5f, size * 0.7f, 0x7F7F7F7F, 1, -spin, &velocity, D_L01_001DCEE0, 1);
                if (p) p[9] = 0x74;
            } else {
                vec_sub_ba(&t50, &D_L01_001E2A40, &at);
                func_00388830(&t50, &t50, speed);
                vec_add_ab(&velocity, &velocity, &t50);
                p = func_L01_00467DA8(&at, 0x28, size * 0.1f * 20.5f, size, colour, 0, spin, &velocity, D_L01_001DCEE0, 1);
                if (p) p[9] = 0x74;
                p = func_L01_00467DA8(&at, 0x28, size * 0.07f * 20.5f, size * 0.7f, 0x7F7F7F7F, 1, -spin, &velocity, D_L01_001DCEE0, 1);
                if (p) p[9] = 0x74;
            }
        }
}
/* localdecomp:end func_L01_0032DA38 */

#include "common.h"

/* NTSC-U counterpart of func_L31_003A55A0 (src/levels/shared/L31_003A5488.c) */
#include "vu0.h"

/* localdecomp:start func_L31_003A3D20 */
typedef struct S_003A55A0 {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x43 - 0x21];
    u8 anim;
    f32 f44;
    f32 f48;
    f32 f4C;
} S_003A55A0;
extern s32 D_L31_001DE9F4_003A3D20;
extern s32 D_L31_001DE9F8_003A3D20;
extern f32 D_L31_001DE9AC_003A3D20;
extern f32 D_L31_001DE9B0_003A3D20;
extern f32 D_L31_001DE9B4_003A3D20;
extern f32 D_L31_001DE9CC_003A3D20;
extern f32 D_L31_001DE9D4_003A3D20;
extern f32 D_L31_001DE9D8_003A3D20;
extern f32 D_L31_001DE9E4_003A3D20;
extern f32 D_L31_001DE9E8_003A3D20;
extern f32 D_L31_001DE9EC_003A3D20;
extern f32 D_L31_001DEA40;
__asm__(".extern D_L31_001DE9F4_003A3D20, 4");
__asm__(".extern D_L31_001DE9F8_003A3D20, 4");
__asm__(".extern D_L31_001DE9AC_003A3D20, 4");
__asm__(".extern D_L31_001DE9B0_003A3D20, 4");
__asm__(".extern D_L31_001DE9B4_003A3D20, 4");
__asm__(".extern D_L31_001DE9CC_003A3D20, 4");
__asm__(".extern D_L31_001DE9D4_003A3D20, 4");
__asm__(".extern D_L31_001DE9D8_003A3D20, 4");
__asm__(".extern D_L31_001DE9E4_003A3D20, 4");
__asm__(".extern D_L31_001DE9E8_003A3D20, 4");
__asm__(".extern D_L31_001DE9EC_003A3D20, 4");
__asm__(".extern D_L31_001DEA40, 4");
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

void func_L31_003A3D20(u8 *a0, s32 a1) {
    S_003A55A0 *m = (S_003A55A0 *)a0;
    s32 t;

    func_L01_00441FB8(m, a1, -1);
    switch (m->state) {
    case 0:
        break;
    case 1:
        if (m->anim != 1) func_003BE4F0(m, 1, 0, D_L31_001DE9F4_003A3D20);
        break;
    case 2:
        if (m->anim != 10) func_003BE4F0(m, 10, 0, D_L31_001DE9F8_003A3D20);
        break;
    case 3:
        if (m->anim != 3) func_003BE4F0(m, 3, 0, D_L31_001DE9F4_003A3D20);
        m->f48 = D_L31_001DE9AC_003A3D20;
        break;
    case 4:
        if (m->anim != 5) func_003BE4F0(m, 5, D_L31_001DE9B4_003A3D20, 5);
        m->f48 = D_L31_001DE9B0_003A3D20;
        break;
    case 5:
        if (m->anim != 8) func_003BE4F0(m, 8, D_L31_001DE9D4_003A3D20, D_L31_001DE9D8_003A3D20);
        m->f48 = D_L31_001DE9CC_003A3D20;
        m->f44 = m->f44 + m->f4C;
        break;
    case 6:
        if (m->anim != 10) func_003BE4F0(m, 10, 0, D_L31_001DE9F8_003A3D20);
        break;
    case 7:
        t = D_L31_001DE9F4_003A3D20;
        if (m->anim == 10) t = D_L31_001DE9F8_003A3D20;
        if (m->anim != 1) func_003BE4F0(m, 1, 0, t);
        m->f48 = 1.0f;
        break;
    case 8:
        t = D_L31_001DE9F4_003A3D20;
        if (m->anim == 10 || m->anim == 7) t = D_L31_001DE9F8_003A3D20;
        if (m->anim != 2) func_003BE4F0(m, 2, 0, t);
        break;
    case 9:
        if (m->anim != 0) func_003BE4F0(m, 0, 0, D_L31_001DE9F4_003A3D20);
        m->f48 = 1.0f;
        break;
    case 10:
        func_003BE4F0(m, 7, D_L31_001DE9E8_003A3D20, D_L31_001DE9EC_003A3D20);
        m->f48 = D_L31_001DE9E4_003A3D20;
        m->f44 = m->f44 + m->f4C;
        break;
    case 11:
        if (m->anim != 6) func_003BE4F0(m, 6, 0, D_L31_001DE9F4_003A3D20);
        m->f48 = D_L31_001DEA40;
        break;
    case 12:
        if (m->anim != 2) func_003BE4F0(m, 2, 0, D_L31_001DE9F4_003A3D20);
        break;
    case 13:
        if (m->anim != 1) func_003BE4F0(m, 1, 0, D_L31_001DE9F4_003A3D20);
        m->f48 = 1.0f;
        break;
    case 66:
        break;
    }
}
/* localdecomp:end func_L31_003A3D20 */

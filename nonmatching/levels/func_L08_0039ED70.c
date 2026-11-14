/* NTSC-U draft (2026-11-14, Claude worker): C of func_L08_0039D270, the NTSC-U twin of func_L08_0039ED70, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/08_aquatos/L08_0039ED70.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L08_0039ED70 (src/levels/08_aquatos/L08_0039ED70.c) */
/* localdecomp:start func_L08_0039D270 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0039D270;
typedef struct { u8 pad0[0x10]; V_0039D270 pos; u8 pad20[0x31 - 0x20]; u8 b31; } O_0039D270;

extern s32 func_0037E1D8(s32);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00467BD8(void *, s32, s32, s32, f32, f32);

void func_L08_0039D270(O_0039D270 *o) {
    V_0039D270 v;
    f32 ang;
    f32 r;
    f32 sx;
    f32 sy;
    s32 life;

    if (o->b31 != 0) {
        if (func_0037E1D8(0xE) == 0) {
            ang = func_0037E2A8();
            r = func_0037E250(0.0f, 0.1f);
            sx = func_0037E250(0.0f, 1.0f) * 0.7f;
            sy = func_0037E250(1.0f, 2.0f) * 0.7f;
            life = (s32)func_0037E250(180.0f, 240.0f);
            v.x = func_00388960(ang) * r;
            v.y = func_00388978(ang) * r;
            v.z = 0.0f;
            vec_add_ba(&v, &v, &o->pos);
            func_L01_00467BD8(&v, 0x40005840, 0x5840, life, sx, sy);
        }
        if (func_0037E1D8(4) == 0) {
            ang = func_0037E2A8();
            r = func_0037E250(0.0f, 0.1f);
            sx = func_0037E250(0.0f, 3.5f) * 0.7f;
            sy = func_0037E250(3.5f, 4.5f) * 0.7f;
            life = (s32)func_0037E250(180.0f, 240.0f);
            v.x = func_00388960(ang) * r;
            v.y = func_00388978(ang) * r;
            v.z = 0.0f;
            vec_add_ba(&v, &v, &o->pos);
            func_L01_00467BD8(&v, 0x30005840, 0x7040, life, sx, sy);
        }
    }
}
/* localdecomp:end func_L08_0039D270 */

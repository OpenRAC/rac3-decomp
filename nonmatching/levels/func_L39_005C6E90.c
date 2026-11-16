/* NTSC-U draft (Claude wave B8): C of func_L39_005C4B80, the NTSC-U twin of func_L39_005C6E90, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L39_005C4B80", whose code is not the PAL one).
 * Worker's note: flags: needs -mvu0-use-vf0-vf2 (vec_add_ab of include/vu0.h does not compile without it: 'fixed register vf17 was spilled') and @ps2as (dual lui/gp forms of D_L39_0024BC48/BC4C, inline float literals); the worklist flags (@ps2as only) lack the vu0 flag. With ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_005C4B80 */
typedef struct Obj_5C4B80 {
    u8 pad0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    s32 wC;
    vu0_q q10;
    vu0_v4 pos;
    s32 w30;
    s32 w34;
    u8 b38;
    u8 b39;
    u8 b3A;
    u8 b3B;
    f32 f3C;
} Obj_5C4B80;

extern f32 D_L39_0024BC48;
extern f32 D_L39_0024BC4C;
extern u8 *D_L39_00296944;

extern s32 func_L39_005B2498(s32);
extern f32 func_L39_005B2510(f32, f32);
extern u8 *func_003C7B98(s32);
extern s32 func_0019D650(void);
extern void func_00388830(void *, void *, f32);

Obj_5C4B80 *func_L39_005C4B80(u8 *a0, void *a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, f32 f12, f32 f13) {
    Obj_5C4B80 *o;
    vu0_v4 w;
    vu0_v4 r;
    vu0_v4 *pos;

    if (t0 == 0) {
        return 0;
    }
    if (0.85f < D_L39_0024BC48 || 0.85f < D_L39_0024BC4C) {
        if (func_L39_005B2498(3) == 0) {
            return 0;
        }
    }
    if (0.9f < D_L39_0024BC48 || 0.9f < D_L39_0024BC4C) {
        if (func_L39_005B2498(2) == 0) {
            return 0;
        }
    }
    if (1.0f < D_L39_0024BC48 || 1.0f < D_L39_0024BC4C) {
        if (func_L39_005B2498(1) == 0) {
            return 0;
        }
    }
    o = (Obj_5C4B80 *)func_003C7B98(0xB);
    if (o != 0) {
        pos = &o->pos;
        o->q10 = *(vu0_q *)a0;
        o->w4 = a2;
        o->b9 = 0xA4;
        o->b3 = func_L39_005B2498(100) < 20 ? 0x44 : 0x48;
        o->b1 = 0;
        o->wC = 0;
        o->b8 = func_0019D650();
        o->b2 = *D_L39_00296944;
        *(vu0_q *)&r = 0;
        r.x = func_L39_005B2510(-1.0f, 1.0f);
        r.y = func_L39_005B2510(-1.0f, 1.0f);
        r.z = func_L39_005B2510(-1.0f, 1.0f);
        *(vu0_q *)&w = *(vu0_q *)&r;
        func_00388830(&w, &w, f13);
        vec_add_ab(pos, a1, &w);
        a0 = (u8 *)o + 0x20;
        *(f32 *)(a0 + 0xC) = f13 * 0.75f;
        o->hA = t0;
        a0[0x19] = t3;
        a0[0x1B] = t0;
        a0[0x18] = t1;
        *(f32 *)(a0 + 0x1C) = f12;
        *(s32 *)(a0 + 0x10) = a2;
        *(s32 *)(a0 + 0x14) = a3;
        a0[0x1A] = t2;
    }
    return o;
}
/* localdecomp:end func_L39_005C4B80 */

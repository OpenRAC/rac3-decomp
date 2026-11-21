/* PAL near miss (wave 12 retry r02): 69 diff with the file's own line
 * (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as); the draft it replaces: 71.
 * Changed against the draft: the VU0 add is the file's vu0.h vec_add_ab (the line now has the vu0
 * flag), so lqc2/lqc2/vadd.xyz/nop/nop/div.s/sqc2 interleave exactly as retail; vu0_v4/vu0_q types
 * as the sibling func_L07_003AB678; the file's own func_003C2F58/func_0038DB48 declarations.
 * Still differs: CSE merges the two 3.0f loads (first func_003824E0 call and the last call's f13)
 * into one pseudo that loop.c hoists into a sixth saved FPR (f24, -1.0f moves to f25, every save
 * slot and the last call's argument order shift); retail reloads 3.0f at both uses. An experiment
 * with a no-output (implicitly volatile) sqc2 asm, which flushes CSE's table, gives retail's float
 * registers exactly (f20-f24, 3.0f reloaded) but splits &vel into two pseudos (extra s6, a copy),
 * so retail's CSE boundary is elsewhere and unknown. Also left: retail loads the s16 at 0x530 into
 * a3 and copies it to s0 before the movz (life = m; if (m >= n) life = n with m separate); here it
 * loads straight into s0 (if/else and ternary with a separate local give movn, 89). */
#include "common.h"

/* localdecomp:start func_L07_003AB4B8 */
void func_L07_003AB4B8(u8 *obj) {
    extern f32 func_003824E0(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00474078(void *, void *, s32, u32, u32, s32, s32, f32, f32, f32, f32);
    vu0_v4 pos;
    vu0_v4 vel;
    vu0_v4 end;
    u8 *p = *(u8 **)(obj + 0x68);
    s32 i;
    s32 life;
    s32 n;
    f32 speed;
    f32 angle;

    func_003C2F58(obj, p[0x533], (f32 *)&pos);
    i = 1;
    do {
        i--;
        speed = func_003824E0(3.0f, 5.0f);
        angle = func_0038DB48(*(f32 *)(obj + 0xF8) + *(f32 *)(p + 0x2A8) + func_003824E0(-0.7853982f, 0.7853982f));
        func_00382760(&vel, speed, angle, func_003824E0(-0.7853982f, 0.7853982f));
        n = func_00382498(20, 30);
        life = *(s16 *)(p + 0x530);
        if (life >= n) {
            life = n;
        }
        *(vu0_q *)&end = *(vu0_q *)&pos;
        vec_add_ab(&end, &pos, &vel);
        func_0038CE20(&vel, &vel, -1.0f / (f32)life);
        func_L01_00474078(&end, &vel, life, 0x80808020, 0x30FF8020, 4, 0, 0.04f, 3.0f, 1.5f, 0.5f);
    } while (i >= 0);
}
/* localdecomp:end func_L07_003AB4B8 */

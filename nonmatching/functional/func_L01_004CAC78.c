/* functional: high. 10 diff words only; branch structure and arg registers checked vs asm */
#include "common.h"
/* localdecomp:start func_L01_004CAC78 */
extern Vec4_004C4AD8 D_001A6230[];
void func_L01_004CAC78(Vec4_004C4AD8 *out, Vec4_004C4AD8 *pos, f32 scale, f32 unused, f32 angle)
{
    extern f32 func_0038CEA8(Vec4_004C4AD8 *);
    extern void func_0038CF68(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern f32 func_0038CE68(Vec4_004C4AD8 *, T_004C4AD8 *);
    extern f32 func_0038D098(f32);
    extern void func_0038CE90(Vec4_004C4AD8 *, Vec4_004C4AD8 *, T_004C4AD8 *);
    extern void func_0038D890(Vec4_004C4AD8 *, T_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    Vec4_004C4AD8 axis;
    Vec4_004C4AD8 *base = D_001A6230;
    T_004C4AD8 *target;
    f32 dot;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*out) : "m"(*base), "m"(*pos) : "vf1", "vf2");
    if (func_0038CEA8(out) < 4.0f) {
        angle *= 0.1f;
        func_0038CF68(out, out, 1.0f);
        target = (T_004C4AD8 *)((u8 *)base - 0xF60);
        dot = func_0038CE68(out, target);
        if (dot < func_0038D098(angle)) goto rotate;
        func_0038CE20(out, out, scale);
    } else {
        func_0038CF68(out, out, 1.0f);
        target = (T_004C4AD8 *)((u8 *)base - 0xF60);
        dot = func_0038CE68(out, target);
        if (dot < func_0038D098(angle)) {
rotate:
            func_0038CE90(&axis, out, target);
            func_0038D890(out, target, &axis, angle);
            func_0038CF68(out, out, scale);
        } else {
            func_0038CE20(out, out, scale);
        }
    }
}
/* localdecomp:end func_L01_004CAC78 */

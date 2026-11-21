/* functional: medium. Camera turn helper (obj, vec, limit): projects vec and the follow spring vector (follow+0x180) onto the plane perpendicular to the player's up axis (D_001E2AA0 table entry +0x20), takes the signed angle between them, wraps it with func_0038DB00 against pi, and unless limit is nonzero and smaller than |turn| stores the remapped turn (clamped to 1, signed by the cross direction) in stick+0x1C; returns the wrapped turn, 0 if either projected vector is zero. func_0040F440/004451D0 semantics assumed from other callers */
#include "vu0.h"
extern u8 D_L01_001E2AA0[];
extern f32 func_0038CE68(f32 *, f32 *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern f32 func_0038CEA8(f32 *);
extern void func_0038CE90(f32 *, f32 *, f32 *);
extern f32 func_0038D0C8(f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
f32 func_L01_003E8FE8(u8 *obj, f32 *vec, f32 limit) {
    f32 proj[4] __attribute__((aligned(16)));
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    u8 *follow = *(u8 **)(obj + 0x70);
    u8 *springs = follow + 0x180;
    u8 *stick = follow + 0x1E0;
    f32 *up = (f32 *)(D_L01_001E2AA0 + *(s32 *)(obj + 0x94) * 0x460 + 0x20);
    f32 dot, len_a, len_b, angle, turn, sign, s;
    func_0038CE20(proj, up, func_0038CE68(vec, up));
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)a) : "m"(*(vu0_v4 *)vec), "m"(*(vu0_v4 *)proj) : "vf1", "vf2");
    func_0038CE20(proj, up, func_0038CE68((f32 *)springs, up));
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)b) : "m"(*(vu0_v4 *)springs), "m"(*(vu0_v4 *)proj) : "vf1", "vf2");
    dot = func_0038CE68(a, b);
    len_a = func_0038CEA8(a);
    if (len_a == 0.0f) return 0.0f;
    len_b = func_0038CEA8(b);
    len_a = len_a * len_b;
    if (len_a == 0.0f) return 0.0f;
    angle = 1.5707964f - func_0038D0C8(dot / len_a);
    sign = -1.0f;
    func_0038CE90(c, a, up);
    if (0.0f <= func_0038CE68(c, b)) sign = 1.0f;
    turn = func_0038DB00(3.1415927f, angle);
    if (limit != 0.0f && limit < __builtin_fabsf(turn)) return turn;
    s = func_L01_004451D0(-1.0f, 0.0f, 1.0f, 0.0f, turn / 1.5707964f);
    if (1.0f < s) s = 1.0f;
    *(f32 *)(stick + 0x1C) = s * sign;
    return turn;
}

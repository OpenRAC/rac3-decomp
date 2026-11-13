#include "common.h"

/* localdecomp:start func_L39_00523B68 */
#include "vu0.h"
/* layout from L05_003619F0.c's func_L05_003622D0 */
typedef struct {
    vu0_v4 m[4];
    s32 c[4];
    f32 x50, x54, x58, x5C, x60, x64, x68, x6C;
    long x70, x78, x80, x88;
} S_00523B68;
extern void func_L01_00305C50(void *);
extern long func_L39_00589890(s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L39_005B44C8(void);
extern void func_0038D328(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L39_00523B68(u8 *p, f32 *pos, s32 color, f32 scale) {
    S_00523B68 s;
    vu0_v4 mat[4];
    vu0_v4 rot;
    vu0_v4 tmp;
    u8 *o;

    o = *(u8 **)(*(u8 **)(p + 0x68) + 0x2C);
    func_L01_00305C50(&s);
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    s.x50 = 0.0f;
    s.x54 = 0.0f;
    s.x58 = 0.0f;
    s.x64 = 0.0f;
    s.x78 = func_L39_00589890(0x2C);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.x70 = 0;
    s.c[3] = color;
    s.c[2] = color;
    s.c[1] = color;
    s.c[0] = color;
    rot.w = 0.0f;
    rot.z = func_0038D160(*(f32 *)(o + 0x23A0) - pos[0], *(f32 *)(o + 0x23A4) - pos[1]);
    rot.y = -func_0038D160(func_0038CF38(pos, o + 0x23A0), *(f32 *)(o + 0x23A8) - pos[2]);
    rot.x = func_L39_005B44C8();
    func_0038D328(mat, &rot);
    vec_sub_ba(&tmp, o + 0x23A0, pos);
    func_0038CF68(&tmp, &tmp, 0.25f);
    mat[3].x = pos[0] + tmp.x;
    mat[3].y = pos[1] + tmp.y;
    mat[3].z = pos[2] + tmp.z;
    mat[3].w = 1.0f;
    func_0038CE20(&s.m[0], &s.m[0], scale);
    func_0038CE20(&s.m[1], &s.m[1], scale);
    func_0038CE20(&s.m[2], &s.m[2], scale);
    func_0038CE20(&s.m[3], &s.m[3], scale);
    func_003D2DA0(&s, mat, 0);
}
/* localdecomp:end func_L39_00523B68 */

INCLUDE_ASM("asm/levels", func_L39_00523D38);

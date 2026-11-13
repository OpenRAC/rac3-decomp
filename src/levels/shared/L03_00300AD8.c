#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L03_00300AD8);

/* localdecomp:start func_L03_00300DA0 */
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D328(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);
__asm__(".extern D_L03_001DC4B0, 4");
extern s32 D_L03_001DC4B0;

void func_L03_00300DA0(u8 *m) {
    vu0_v4 mat[4];
    vu0_v4 rot;
    vu0_v4 dir;
    u8 *v = *(u8 **)(m + 0x68);
    f32 t;
    if (v == 0 || m[0x31] == 0) {
        return;
    }
    t = *(f32 *)(v + 0x40) + 0.1f;
    *(f32 *)(v + 0x40) = t;
    if (t >= 7.0f) {
        *(f32 *)(v + 0x40) = t - 7.0f;
    }
    *(vu0_q *)&dir = *(vu0_q *)(m + 0xD0);
    rot.x = 0.0f;
    rot.y = -func_0038D160(func_0038CED8(&dir), dir.z) + -1.5707964f;
    rot.z = func_0038D160(dir.x, dir.y);
    rot.w = 1.0f;
    func_0038D328(mat, &rot);
    func_0038CE20(&dir, &dir, 2.5f);
    vec_add_ba(&mat[3], m + 0x10, &dir);
    func_0038CE20(&mat[2], &mat[2], 2.5f);
    func_003D9740(mat, D_L03_001DC4B0, 0x80084010, 5, 1, *(f32 *)(v + 0x40));
    func_0038CE20(&mat[2], &mat[2], -1.0f);
    *(vu0_q *)&dir = *(vu0_q *)(m + 0xD0);
    func_0038CE20(&dir, &dir, -2.5f);
    vec_add_ab(&mat[3], m + 0x10, &dir);
    func_003D9740(mat, D_L03_001DC4B0, 0x80084010, 5, 1, *(f32 *)(v + 0x40));
}
/* localdecomp:end func_L03_00300DA0 */

INCLUDE_ASM("asm/levels", func_L03_00300F50);

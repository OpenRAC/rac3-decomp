/* functional: medium. Near miss (66 word diffs, vector register allocation/scheduling). */
#include "common.h"
/* localdecomp:start func_L01_003D6F10 */
#include "vu0.h"
typedef struct { vu0_v4 axis; vu0_v4 normal; vu0_v4 points[8]; f32 radius; u8 padA4[0x1A]; u8 mode; } Vars_003D6F10;
extern const vu0_v4 D_L01_001D66B0;
extern vu0_v4 D_L01_001EAA40;
static __inline__ void zero_sub_003D6F10(void *d, void *a) {
    vu0_q qa, qb;
    __asm__("lqc2 %1, %3\n\tlqc2 %2, %4\n\tvsub.xyz %1, %1, %2\n\tsqc2 %1, %0"
        : "=m"(*(vu0_v4 *)d), "=&j"(qa), "=&j"(qb)
        : "i"(&D_L01_001D66B0), "m"(*(vu0_v4 *)a));
}
void func_L01_003D6F10(u8 *obj) {
    extern f32 func_003C3D30(void *, s32, s32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    vu0_v4 v;
    vu0_v4 pos;
    vu0_v4 normal;
    Vars_003D6F10 *vars = *(Vars_003D6F10 **)(obj + 0x68);
    f32 half = vars->radius * 0.5f;
    f32 radius, angle, z;
    s32 i;
    s32 j;
    if (vars->mode == 0) {
        z = func_003C3D30(obj + 0x10, 0, 0, 3.0f);
        func_0038CF68(&vars->axis, &D_L01_001EAA40, 1.0f);
        vars->axis.w = z;
        for (i = 0; i < 8; i++) {
            if (i < 3) radius = func_003824E0(0.0f, half);
            else radius = func_003824E0(half, vars->radius);
            angle = func_00382538();
            qzero(&v);
            v.x = func_0038D098(angle) * radius;
            v.y = func_0038D0B0(angle) * radius;
            vec_add_ba(&vars->points[i], &v, obj + 0x10);
            { f32 height = vars->axis.w;
            vars->points[i].w = radius;
            vars->points[i].z = height; }
        }
    } else {
        *(vu0_q *)&pos = *(vu0_q *)(obj + 0x10);
        zero_sub_003D6F10(&normal, &pos);
        func_0038CE20(&normal, &vars->axis, func_0038CE68(&vars->axis, &normal));
        vec_add_ba(&normal, &pos, &normal);
        zero_sub_003D6F10(&normal, &normal);
        func_0038CF68(&normal, &normal, 1.0f);
        *(vu0_q *)&vars->normal = *(vu0_q *)&normal;
        for (j = 0; j < 8; j++) {
            qzero(&v);
            func_0038D890(&v, &normal, &vars->axis, func_00382538());
            if (j < 3) radius = func_003824E0(0.0f, half);
            else radius = func_003824E0(half, vars->radius);
            func_0038CE20(&v, &v, radius);
            vec_add_ab(&vars->points[j], &v, obj + 0x10);
            vars->points[j].w = radius;
        }
    }
}
/* localdecomp:end func_L01_003D6F10 */

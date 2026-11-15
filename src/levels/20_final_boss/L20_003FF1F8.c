#include "common.h"

/* declared by functions of L20_003FF170.c, which this file was cut from */
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);

/* localdecomp:start func_L20_003FF1F8 */
/* from func_L05_0035AD60 (src/levels/shared/L05_00355DD8.c) */
#include "vu0.h"
extern f32 D_001DF624_sda;
__asm__(".extern D_001DF624_sda, 4");
extern f32 D_001DF62C_sda;
__asm__(".extern D_001DF62C_sda, 4");
extern f32 D_001DF630_sda;
__asm__(".extern D_001DF630_sda, 4");
extern s32 func_00382468(s32);
extern s32 func_L05_0035AC08(u8 *);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L05_003C8890(void *, void *, void *, void *, f32);
extern void func_003A52A0(s32, s32, void *);

void func_L20_003FF1F8(u8 *arg0)
{
    u8 *v;
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 t;
    vu0_v4 r;
    vu0_v4 m[4];

    v = *(u8 **)(arg0 + 0x68);
    t = *(vu0_v4 *)(v + 0x220);
    if (func_00382468(4) == 0 && func_L05_0035AC08(arg0) == 0) {
        func_L01_00443B88(&r, D_001DF62C_sda, D_001DF630_sda);
        if (func_00382468(2)) {
            r.x = -r.x;
        }
        if (func_00382468(2)) {
            r.y = -r.y;
        }
        vec_add_ab(&t, &t, &r);
    }
    func_003C2F58(*(u8 **)(v + 0x3EC), 0, (u8 *)&p);
    func_003C2EC0(*(void **)(v + 0x3EC), 0, m);
    func_0038CF68(&a, m, 0.1f);
    vec_add_ab(&p, &p, &a);
    vec_sub_ab(&d, &t, &p);
    func_0038CF68(&d, &d, D_001DF624_sda * 0.020000001f);
    func_L05_003C8890(arg0, *(void **)(v + 0x230), &p, &d, v[0x44]);
    func_003A52A0(3, 0, arg0);
}
/* localdecomp:end func_L20_003FF1F8 */

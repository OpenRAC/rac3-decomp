#include "common.h"

/* declared by functions of L39_005FE2E0.c, which this file was cut from */
extern s32 D_L39_00241128;
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L39_005FED60 */
#include "vu0.h"

typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 p20[0xE0];
} Owner_005FED60;

extern s32 D_L39_00241128;
extern s32 D_L39_002412DC;
__asm__(".extern D_L39_00241128, 16");
__asm__(".extern D_L39_002412DC, 16");
typedef struct { u8 p0[0x18]; s32 w18; s32 w1C; vu0_v4 v20; vu0_v4 v30; vu0_v4 v40; } Hit_005FED60;
extern Hit_005FED60 D_L39_0025F740;

/* func_L39_005FF538 is defined later in this file with a Vec4 * that is not declared yet here */
extern s32 func_L39_005FF538_005FED60(u8 *, void *, f32, f32, f32);
extern void func_L19_003B1A70(s32, void *, s32);
extern void func_L39_005FF060(u8 *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);
extern s32 func_0038CAD0(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004C8668(s32);

s32 func_L39_005FED60(u8 *m, vu0_v4 *from, vu0_v4 *dir, vu0_v4 *out, void *a4, void *a5, s32 a6,
                      s32 *a7, f32 step, s32 *hitp, s32 n) {
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 start;
    Owner_005FED60 owner;
    s32 timer;
    s32 result;
    s32 id;
    f32 lim;
    s32 k;
    s32 i;

    result = 0;
    if (D_L39_00241128 != 0) {
        return 0;
    }
    owner.pos = *from;
    id = func_L39_005FF538_005FED60((u8 *)&owner, 0, 1.0f, 1.0f, 1.0f);
    p = *from;
    d = *dir;
    start = p;
    for (k = 0; k < n; k++) {
        func_L19_003B1A70(id, &d, 0);
        vec_add_ab(&p, &p, &d);
        owner.pos = p;
        func_L39_005FF060(m, &p, &d, step);
    }
    timer = 250;
    lim = 20.0f;
    while (func_0038CAD0(&timer) == 0) {
        s32 fl;

        start = p;
        for (i = 0; i < 10; i++) {
            func_L19_003B1A70(id, &d, 0);
            vec_add_ab(&p, &p, &d);
            owner.pos = p;
            func_L39_005FF060(m, &p, &d, step);
        }
        fl = 0x10;
        if (D_L39_002412DC == 0x30) {
            fl = 0;
        }
        if (func_003D3CB0(&start, &p, fl | 2, a5, 0) != 0) {
            s32 r = func_003D5630();
            if (D_L39_0025F740.w1C > 0 || r != -1) {
                if (hitp != 0) {
                    *hitp = r;
                }
                *out = D_L39_0025F740.v20;
                goto done;
            }
        }
        if (fabs_asm(from->z - p.z) > lim) {
            timer = 0;
            break;
        }
    }
done:
    if (timer != 0) {
        func_0038CE20(a4, &D_L39_0025F740.v40, 0.0009765625f);
        func_0038CF68(a4, a4, 1.0f);
        if (a7 != 0) {
            *a7 = D_L39_0025F740.w18;
        }
        vec_sub_ab(&start, out, (u8 *)m + 0x23A0);
        func_0038CE20(&start, &start, 0.94f);
        result = 1;
        vec_add_ab(out, &start, (u8 *)m + 0x23A0);
    } else if (a6 != 0) {
        *out = p;
    }
    func_L01_004C8668(id);
    return result;
}
/* localdecomp:end func_L39_005FED60 */

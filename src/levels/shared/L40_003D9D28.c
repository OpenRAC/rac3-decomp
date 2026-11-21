#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    s32 (*get)(void *);
} VT_003D9D28;

typedef struct {
    u8 pad0[0x14];
    VT_003D9D28 *vt;
    u8 pad18[0x250 - 0x18];
    vu0_v4 dir;
} Obj_003D9D28;


/* localdecomp:start func_L40_003D9D28 */
#include "vu0.h"

extern vu0_v4 D_L40_00249F40;
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CE20(void *d, void *s, f32 k);
extern f32 func_L39_005B44C8(void);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_L39_005B4398(s32);
extern void func_L39_005CDE78(vu0_v4 *pos, vu0_v4 *vel, u32 colour, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f);

void func_L40_003D9D28(u8 *a0, Obj_003D9D28 *a1) {
    vu0_v4 diff;
    vu0_v4 dir;
    vu0_v4 out;

    vec_sub_ab(&diff, &D_L40_00249F40, a0 + 0x10);
    func_0038CE20(&dir, &a1->dir, func_L39_005B4410(0.020000001f, 0.040000003f));
    func_0038D890(&out, &dir, &diff, func_L39_005B44C8());
    func_L39_005CDE78((vu0_v4 *)(a0 + 0x10), &out, 0x50804040, 0x3C, func_L39_005B4398(0xFF) & 0xFF, 1, 0x40, a1->vt->get(a1), 0.4f);
    func_L39_005CDE78((vu0_v4 *)(a0 + 0x10), &out, 0x407F7F7F, 0x3C, func_L39_005B4398(0xFF) & 0xFF, 1, 0x40, a1->vt->get(a1), 0.2f);
}
/* localdecomp:end func_L40_003D9D28 */

/* localdecomp:start func_L40_003D9E78 */
#include "vu0.h"
extern vu0_v4 D_L40_00249F40;
extern const f32 D_L40_002469C0[] __attribute__((section(".sdata")));
extern const f32 D_L40_002469D0[] __attribute__((section(".sdata")));
extern const f32 D_L40_002469E0[] __attribute__((section(".sdata")));
extern u8 D_L40_0029AF58[];
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038CB00(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern u8 *func_L39_005CDCF0(void *, s32, u8, s32, s32, s32, s32, f32, s32);

typedef struct {
    u8 pad0[0x44];
    s16 timer[4];
    u8 pad4C[4];
    f32 angle[4];
} M_003D9E78;
s32 func_L40_003D9E78(u8 *self, Obj_003D9D28 *a1) {
    vu0_v4 v;
    vu0_v4 step;
    M_003D9E78 *m = *(M_003D9E78 **)(self + 0x68);
    s32 k;
    s32 result = 0;
    f32 z;
    f32 t;
    f32 size;
    s32 c;
    s32 alpha;
    u8 *p;

    vec_sub_ab(&v, &D_L40_00249F40, self + 0x10);
    func_0038CF68(&v, &v, -0.3f);
    func_0038CF68(&step, &v, 0.1f);
    vec_add_ba(&v, &v, self + 0x10);
    z = v.z;
    for (k = 0; k < 4; k++) {
        u8 *tbl = D_L40_0029AF58;

        if (func_0038CB00(&m->timer[k]) != 0) {
            continue;
        }
        if (m->timer[k] >= 0x29) {
            result = 1;
        }
        m->angle[k] += D_L40_002469C0[k];
        if (m->angle[k] >= 255.0f) {
            m->angle[k] -= 255.0f;
        } else if (m->angle[k] <= 0.0f) {
            m->angle[k] += 255.0f;
        }
        c = func_0038DBD8(0x407F2020, 0x107F2020, fabs_asm(0.5f - (f32)(0xD4 - m->timer[k]) / 212.0f));
        t = 1.0f - (f32)m->timer[k] / 75.0f;
        v.z = z + D_L40_002469E0[k];
        size = D_L40_002469D0[k];
        alpha = c >> 24;
        alpha = (s32)((f32)alpha * (1.0f - t));
        c = (alpha << 24) | (c & 0xFFFFFF);
        p = func_L39_005CDCF0(&v, c, (s32)m->angle[k], 0x35, 0, 2, 1, size * t, a1->vt->get(a1));
        if (p != 0) {
            p[2] = **(u8 **)(tbl + 0xF8);
        }
        p = func_L39_005CDCF0(&v, (alpha << 24) | 0xFFFFFF, (s32)m->angle[k], 0x35, 0, 2, 1, size * (t * 0.7f), a1->vt->get(a1));
        if (p != 0) {
            p[2] = **(u8 **)(tbl + 0xF8);
        }
        vec_add_ab(&v, &v, &step);
    }
    return result;
}
/* localdecomp:end func_L40_003D9E78 */

#include "common.h"

/* NTSC-U counterpart of func_L40_003D9E78 (src/levels/shared/L40_003D9D28.c) */
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
#include "vu0.h"
extern vu0_v4 D_L40_0024A0C0;

/* localdecomp:start func_L40_003D9C70 */
#include "vu0.h"
extern vu0_v4 D_L40_0024A0C0;
extern const f32 D_L40_00246B40[] __attribute__((section(".sdata")));
extern const f32 D_L40_00246B50[] __attribute__((section(".sdata")));
extern const f32 D_L40_00246B60[] __attribute__((section(".sdata")));
extern u8 D_L40_0029B0D8[];
extern void func_00388830(void *, void *, f32);
extern s32 func_003883C8(void *);
extern s32 func_003894A0(s32, s32, f32);
extern u8 *func_L39_005CB8E0(void *, s32, u8, s32, s32, s32, s32, f32, s32);

typedef struct {
    u8 pad0[0x44];
    s16 timer[4];
    u8 pad4C[4];
    f32 angle[4];
} M_003D9E78;
s32 func_L40_003D9C70(u8 *self, Obj_003D9D28 *a1) {
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

    vec_sub_ab(&v, &D_L40_0024A0C0, self + 0x10);
    func_00388830(&v, &v, -0.3f);
    func_00388830(&step, &v, 0.1f);
    vec_add_ba(&v, &v, self + 0x10);
    z = v.z;
    for (k = 0; k < 4; k++) {
        u8 *tbl = D_L40_0029B0D8;

        if (func_003883C8(&m->timer[k]) != 0) {
            continue;
        }
        if (m->timer[k] >= 0x31) {
            result = 1;
        }
        m->angle[k] += D_L40_00246B40[k];
        if (m->angle[k] >= 255.0f) {
            m->angle[k] -= 255.0f;
        } else if (m->angle[k] <= 0.0f) {
            m->angle[k] += 255.0f;
        }
        c = func_003894A0(0x407F2020, 0x107F2020, fabs_asm(0.5f - (f32)(0xFF - m->timer[k]) / 255.0f));
        t = 1.0f - (f32)m->timer[k] / 90.0f;
        v.z = z + D_L40_00246B60[k];
        size = D_L40_00246B50[k];
        alpha = c >> 24;
        alpha = (s32)((f32)alpha * (1.0f - t));
        c = (alpha << 24) | (c & 0xFFFFFF);
        p = func_L39_005CB8E0(&v, c, (s32)m->angle[k], 0x35, 0, 2, 1, size * t, a1->vt->get(a1));
        if (p != 0) {
            p[2] = **(u8 **)(tbl + 0xF8);
        }
        p = func_L39_005CB8E0(&v, (alpha << 24) | 0xFFFFFF, (s32)m->angle[k], 0x35, 0, 2, 1, size * (t * 0.7f), a1->vt->get(a1));
        if (p != 0) {
            p[2] = **(u8 **)(tbl + 0xF8);
        }
        vec_add_ab(&v, &v, &step);
    }
    return result;
}
/* localdecomp:end func_L40_003D9C70 */

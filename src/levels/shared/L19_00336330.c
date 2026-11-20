#include "common.h"

/* localdecomp:start func_L19_00336330 */
#include "vu0.h"

typedef int Q_00336330 __attribute__((mode(TI)));

typedef struct {
    s32 n;
    s32 pad[3];
    Q_00336330 pt[1];
} P_00336330;

typedef struct {
    u8 p0[0x28];
    s32 path[4];
    s32 count;
    s32 flags;
    u8 p40[0x44];
    f32 t84;
    f32 t88;
    u8 p8C[4];
    f32 f90;
    f32 f94;
    f32 f98;
    u8 p9C[4];
    f32 fA0;
    f32 fA4;
    f32 fA8;
    u8 pAC[0x28];
    f32 fD4;
    u8 pD8[4];
    s32 base;
    vu0_v4 offset;
} V_00336330;

extern P_00336330 *D_L19_0021D500[];
extern vu0_v4 D_L19_00276F40[][16];
extern vu0_v4 D_L19_00276E40[];
extern vu0_v4 D_001A4C60;
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_0044AE78(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);

static __inline__ void qcopy_00336330(void *d, void *s) {
    *(Q_00336330 *)d = *(Q_00336330 *)s;
}

/* from rac2-decomp's func_L03_0038B5D8 (a near miss there) */
void func_L19_00336330(u8 *m) {
    V_00336330 *v = *(V_00336330 **)(m + 0x68);
    vu0_v4 toward, rel, blend, tangent, radial, jitter;
    s32 row, col;
    f32 dist, strength, len, amount, seg, vertical, phase, angle, mag, first, fc;

    v->f94 = func_0038DAB8(v->f94, v->f98);
    v->fA8 = func_0038DAB8(v->fA8, v->f98);
    v->t84 += v->t88;
    if (v->t84 > 1.0f) {
        v->t84 -= 1.0f;
    }
    for (row = 0; row < 4; row++) {
        if ((v->flags & 1) && v->path[row] >= 0) {
            P_00336330 *p = D_L19_0021D500[v->path[row]];
            for (col = 0; col < v->count; col++) {
                *(Q_00336330 *)&D_L19_00276F40[v->base + row][col] = p->pt[col];
            }
            if (v->flags & 8) {
                vec_sub_ab(&toward, &D_001A4C60, &v->offset);
                dist = func_0038CEA8(&toward);
                func_0038CF68(&toward, &toward, 1.1f);
                if (!(v->fD4 + 1.1f < dist)) {
                    strength = 1.0f - (dist - 1.1f) / v->fD4;
                    for (col = 0; col < v->count; col++) {
                        *(Q_00336330 *)&rel = *(Q_00336330 *)&D_L19_00276F40[v->base + row][col];
                        vec_sub_ab(&rel, &rel, &v->offset);
                        len = func_0038CEA8(&rel);
                        if (len > 1.1f) {
                            len = 1.1f;
                        }
                        len = len / 1.1f;
                        amount = strength * (1.0f - len);
                        func_0038CE20(&blend, &toward, amount);
                        func_0038CE20(&rel, &rel, 1.0f - amount);
                        vec_add_ba(&blend, &blend, &rel);
                        vec_add_ab(&D_L19_00276F40[v->base + row][col], &blend, &v->offset);
                    }
                }
            }
        } else {
            *(Q_00336330 *)&tangent = 0;
            tangent.w = 1.0f;
            switch (row) {
            case 0:
                tangent.z += 1.1f;
                break;
            case 1:
                tangent.z -= 0.6395349f;
                tangent.y -= 0.6395349f;
                tangent.x -= 0.6395349f;
                break;
            case 2:
                tangent.z -= 0.6395349f;
                tangent.y -= 0.6395349f;
                tangent.x += 0.6395349f;
                break;
            default:
                tangent.z -= 0.6395349f;
                tangent.y += 0.78571433f;
                break;
            }
            for (col = 0; col < v->count; col++) {
                func_0038CF68(&radial, &tangent, (f32)col / ((f32)v->count - 0.5f));
                *(Q_00336330 *)&D_L19_00276F40[v->base + row][col] = *(Q_00336330 *)&radial;
                vec_add_ba(&D_L19_00276F40[v->base + row][col], &D_L19_00276F40[v->base + row][col], &v->offset);
            }
        }
    }
    vec_sub_ab(&tangent, &D_L19_00276F40[v->base][1], &D_L19_00276F40[v->base][0]);
    seg = func_0038CEA8(&tangent);
    for (col = 0; col < v->count; col++) {
        vertical = 0.0f;
        phase = 0.0f;
        if (!(v->flags & 0x40)) {
            func_0038CE20(&jitter, &D_L19_00276E40[col], v->f90 * seg);
        }
        if (!(v->flags & 0x80)) {
            fc = (f32)col;
            first = v->fA0 * func_0038D0B0(func_L01_0044AE78(v->f94 + fc * -1.7802358f));
            phase = func_L01_0044AE78(v->fA8 + fc * -1.5184364f);
            vertical = seg * (first * func_0038D0B0(phase));
        }
        if (!(v->flags & 0x100)) {
            angle = func_0038DAB8(func_0038D160(tangent.x, tangent.y), 1.5707964f);
            mag = seg * v->fA4 * func_0038D098(phase);
            radial.x = func_0038D098(angle) * mag;
            radial.y = func_0038D0B0(angle) * mag;
            radial.z = 0.0f;
        }
        for (row = 0; row < 4; row++) {
            qcopy_00336330(&D_L19_00276F40[v->base + row + 4][col], &D_L19_00276F40[v->base + row][col]);
            if (col != 0 && col != v->count - 1) {
                if (!(v->flags & 0x40)) {
                    vec_add_ba(&D_L19_00276F40[v->base + row + 4][col], &D_L19_00276F40[v->base + row + 4][col], &jitter);
                    vec_add_ba(&D_L19_00276F40[v->base + row][col], &D_L19_00276F40[v->base + row][col], &jitter);
                }
                if (!(v->flags & 0x80)) {
                    D_L19_00276F40[v->base + row + 4][col].z += vertical;
                }
                if (!(v->flags & 0x100)) {
                    vec_add_ba(&D_L19_00276F40[v->base + row + 4][col], &D_L19_00276F40[v->base + row + 4][col], &radial);
                }
            }
        }
    }
}
/* localdecomp:end func_L19_00336330 */

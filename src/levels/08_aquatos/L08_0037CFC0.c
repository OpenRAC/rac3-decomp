#include "common.h"

/* declared by functions of L08_0037CD98.c, which this file was cut from */
extern void func_L01_004450F0(void *, s32, s32);

/* localdecomp:start func_L08_0037CFC0 */
#include "vu0.h"
typedef struct {
    vu0_v4 h[3];
    vu0_v4 v[8][8];
    vu0_v4 uv[8][8];
    f32 a[8][8];
    f32 b[8][8];
} E_0037CFC0;
extern E_0037CFC0 D_0028FF60[];
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_00389478(void *, f32 *, f32 *);
extern f32 func_00382538(void);
extern void func_L01_00404808(void *, void *);
extern void func_L08_0037D450(void);

void func_L08_0037CFC0(u8 *a0) {
    vu0_v4 m[3];
    vu0_v4 n[3];
    vu0_v4 e1;
    vu0_v4 e2;
    vu0_v4 t1;
    vu0_v4 t2;
    f32 l1;
    f32 l2;
    f32 fj;
    s32 j;
    s32 k;

    switch (a0[0x20]) {
    case 0:
        func_L01_004450F0(a0, 1, -1);
        *(vu0_q *)&m[0] = 0;
        *(vu0_q *)&m[1] = 0;
        *(vu0_q *)&m[2] = 0;
        m[0].x = 159.95f;
        m[0].y = 194.29f;
        m[0].z = 770.0f;
        m[0].w = 1.0f;
        m[1].x = 173.05f;
        m[1].y = 198.83f;
        m[1].z = 770.0f;
        m[1].w = 1.0f;
        m[2].x = 161.59f;
        m[2].y = 192.0f;
        m[2].z = 761.52f;
        m[2].w = 1.0f;
        a0[0x30] = 0x80;
        *(vu0_q *)&D_0028FF60[0].h[0] = *(vu0_q *)&m[0];
        *(vu0_q *)&D_0028FF60[0].h[1] = *(vu0_q *)&m[1];
        *(vu0_q *)&D_0028FF60[0].h[2] = *(vu0_q *)&m[2];
        *(vu0_q *)&n[0] = 0;
        *(vu0_q *)&n[1] = 0;
        *(vu0_q *)&n[2] = 0;
        n[0].x = 175.02f;
        n[0].y = 198.48f;
        n[0].z = 769.77f;
        n[0].w = 1.0f;
        n[1].x = 188.3f;
        n[1].y = 194.39f;
        n[1].z = 769.89f;
        n[1].w = 1.0f;
        n[2].x = 175.27f;
        n[2].y = 196.06f;
        n[2].z = 761.3f;
        n[2].w = 1.0f;
        *(vu0_q *)&D_0028FF60[1].h[0] = *(vu0_q *)&n[0];
        *(vu0_q *)&D_0028FF60[1].h[1] = *(vu0_q *)&n[1];
        *(vu0_q *)&D_0028FF60[1].h[2] = *(vu0_q *)&n[2];
        {
            /* the original's C++ `for (int i = 0; ...)`: i is created after the setup above */
            s32 i;

            for (i = 0; i < 2; i++) {
                vec_sub_ab(&e1, &D_0028FF60[i].h[1], &D_0028FF60[i].h[0]);
                vec_sub_ab(&e2, &D_0028FF60[i].h[2], &D_0028FF60[i].h[0]);
                l1 = func_0038CEA8(&e1);
                l2 = func_0038CEA8(&e2);
                func_0038CF68(&e1, &e1, l1 / 7.0f);
                func_0038CF68(&e2, &e2, l2 / 7.0f);
                for (j = 0; j < 8; j++) {
                    fj = j;
                    for (k = 0; k < 8; k++) {
                        func_0038CE20(&t1, &e1, k);
                        vec_add_ba(&D_0028FF60[i].v[j][k], &D_0028FF60[i].h[0], &t1);
                        func_0038CE20(&t2, &e2, fj);
                        vec_add_ab(&D_0028FF60[i].v[j][k], &D_0028FF60[i].v[j][k], &t2);
                        func_00389478(&D_0028FF60[i].v[j][k], &D_0028FF60[i].uv[j][k].x, &D_0028FF60[i].uv[j][k].y);
                        D_0028FF60[i].b[j][k] = func_00382538();
                    }
                }
            }
        }
        break;
    case 1:
        func_L01_00404808(func_L08_0037D450, a0);
        break;
    }
}
/* localdecomp:end func_L08_0037CFC0 */

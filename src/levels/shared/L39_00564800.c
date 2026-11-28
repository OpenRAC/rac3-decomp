#include "common.h"
#include "vu0.h"
#include "structs/camera.h"

/* localdecomp:start func_L39_00564800 */
typedef struct { vu0_v4 v[4]; s32 col[4]; f32 uv[8]; unsigned long tag[4]; } P_00564800;

extern s32 D_L39_00241118;
__asm__(".extern D_L39_00241118, 16");
extern struct GameCamera D_L39_0024DE80[];
extern void func_003A9440(s32, unsigned long);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);
extern f32 func_0038CEA8(void *);

void func_L39_00564800(void *pts_, s32 n, s32 texA, s32 texB, s32 colA, s32 colAmask,
                       s32 colBmix, s32 colB, s32 start, s32 end, s32 count,
                       f32 width, f32 halfw, f32 ext) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern s32 func_0038DBD8(s32, s32, f32);
    vu0_v4 *pts = pts_;
    P_00564800 q1;
    P_00564800 q2;
    vu0_v4 S;
    vu0_v4 W;
    vu0_v4 d140;
    vu0_v4 d150;
    vu0_v4 A;
    vu0_v4 B;
    vu0_v4 d180;
    vu0_v4 d190;
    vu0_v4 d1A0;
    vu0_v4 s1B0;
    vu0_v4 s1C0;
    vu0_v4 X;
    s32 j;
    s32 first;
    s32 prev;
    s32 col;
    f32 step;
    f32 t;
    f32 len0;
    f32 len1;

    func_003D93B0(&q1, texA, 1, 0x80);
    q1.col[3] = colAmask;
    q1.col[2] = colAmask;
    q1.col[1] = colAmask;
    q1.col[0] = colAmask;
    q1.uv[0] = 0.0f;
    q1.uv[1] = 0.0f;
    q1.uv[2] = 0.0f;
    q1.uv[3] = 1.0f;
    q1.uv[4] = 1.0f;
    q1.uv[5] = 0.0f;
    q1.uv[6] = 1.0f;
    q1.uv[7] = 1.0f;
    func_003D93B0(&q2, texB, 1, 0x80);
    q2.col[3] = colB;
    q2.col[2] = colB;
    q2.col[1] = colB;
    q2.col[0] = colB;
    q2.uv[0] = 0.0f;
    q2.uv[1] = 0.0f;
    q2.uv[2] = 0.0f;
    q2.uv[3] = 1.0f;
    q2.uv[4] = 1.0f;
    q2.uv[5] = 0.0f;
    q2.uv[6] = 1.0f;
    q2.uv[7] = 1.0f;

    first = (start + 1) % n;
    vec_sub_ab(&d140, &pts[start], &D_L39_0024DE80[D_L39_00241118].position);
    vec_sub_ba(&d150, &pts[first], &pts[start]);
    j = first;
    func_0038CE90(&S, &d150, &d140);
    func_0038CF68(&S, &S, width);
    count--;
    step = 1.0f / (f32)count;
    t = step;
    vec_add_ab(&q1.v[0], &pts[start], &S);
    vec_sub_ab(&q1.v[1], &pts[start], &S);
    prev = start;
    while (j != end) {
        vec_sub_ab(&d140, &pts[j], &D_L39_0024DE80[D_L39_00241118].position);
        vec_sub_ba(&d150, &pts[j], &pts[prev]);
        func_0038CE90(&S, &d150, &d140);
        func_0038CF68(&S, &S, width);
        vec_add_ba(&q1.v[2], &pts[j], &S);
        vec_sub_ab(&q1.v[3], &pts[j], &S);
        col = func_0038DBD8(colAmask, colA, t);
        t += step;
        q1.col[3] = col;
        q1.col[2] = col;
        func_003D2DA0(&q1, 0, 0);
        prev = j;
        j = (j + 1) % n;
        q1.v[0] = q1.v[2];
        q1.v[1] = q1.v[3];
        q1.col[0] = q1.col[1] = q1.col[2];
    }

    j = first;
    t = step;
    vec_sub_ab(&d190, &pts[start], &D_L39_0024DE80[D_L39_00241118].position);
    len0 = func_0038CEA8(&d190);
    while (j != end) {
        vec_sub_ab(&d180, &pts[j], &D_L39_0024DE80[D_L39_00241118].position);
        len1 = func_0038CEA8(&d180);
        if (len0 < len1) {
            if (len0 == 0.0f) {
                s1B0 = d180;
            } else {
                func_0038CE20(&s1B0, &d190, len1 / len0);
            }
            vec_add_ba(&A, &D_L39_0024DE80[D_L39_00241118].position, &d180);
            vec_add_ab(&B, &D_L39_0024DE80[D_L39_00241118].position, &s1B0);
        } else {
            if (len1 == 0.0f) {
                s1C0 = d190;
            } else {
                func_0038CE20(&s1C0, &d180, len0 / len1);
            }
            vec_add_ba(&A, &D_L39_0024DE80[D_L39_00241118].position, &s1C0);
            vec_add_ab(&B, &D_L39_0024DE80[D_L39_00241118].position, &d190);
        }
        vec_sub_ab(&d150, &B, &A);
        len0 = len1;
        func_0038CE20(&X, &d150, ext);
        vec_sub_ab(&A, &A, &X);
        vec_add_ab(&B, &B, &X);
        vec_sub_ab(&d1A0, &D_L39_0024DE80[D_L39_00241118].position, &A);
        func_0038CE90(&S, &d1A0, &d150);
        func_0038CF68(&W, &S, halfw);
        vec_add_ab(&q2.v[0], &A, &W);
        vec_sub_ab(&q2.v[1], &A, &W);
        vec_add_ba(&q2.v[2], &B, &W);
        vec_sub_ab(&q2.v[3], &B, &W);
        col = func_0038DBD8(colB, colBmix, t);
        t += step;
        q2.col[3] = col;
        q2.col[2] = col;
        func_003D2DA0(&q2, 0, 0);
        d190 = d180;
        q2.col[0] = q2.col[1] = q2.col[2];
        j = (j + 1) % n;
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L39_00564800 */

/* PAL near miss (haiku-w4): 343 words differ with the file's flags; frame, spills and VU0 scheduling differ (statement-order tweak only). */
#include "common.h"
/* localdecomp:start func_L01_00340670 */
#include "vu0.h"
typedef struct {
    vu0_v4 p[4];
    s32 color[4];
    f32 uv[8];
    unsigned long state[4];
} Quad_00340670;
extern s32 D_001DD160_sda;
__asm__(".extern D_001DD160_sda, 4");
extern s32 D_001DD164_sda;
__asm__(".extern D_001DD164_sda, 4");
extern s32 D_001DD130_sda;
__asm__(".extern D_001DD130_sda, 4");
extern s32 D_001DD134_sda;
__asm__(".extern D_001DD134_sda, 4");
extern vu0_v4 D_L01_001E29C0;
void func_L01_00340670(vu0_v4 *points, s32 alpha1, s32 alpha2, s32 count, f32 width1, f32 width2, f32 shift)
{
    extern long func_00389598(s32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_003A9440(s32, unsigned long);
    Quad_00340670 q1, q2;
    vu0_v4 normal, offset, toward, along, start, end, d0, d1, back, move;
    s32 n = count;
    vu0_v4 copy0, copy1, camera0, camera1;
    s32 limit;
    vu0_v4 scratch;
    s32 c1, c2, i;
    f32 length, a, b, zero, one;
    vu0_v4 *p;
    q1.state[1] = func_00389598(D_001DD160_sda);
    zero = 0.0f;
    c1 = D_001DD130_sda | (alpha1 << 24);
    q1.state[0] = 0;
    q1.state[2] = 0xFF9000000260UL;
    q1.state[3] = 0x8000000048UL;
    q1.color[3] = c1; q1.color[2] = c1; q1.color[1] = c1; q1.color[0] = c1;
    q2.state[1] = func_00389598(D_001DD164_sda);
    one = 1.0f;
    vec_copy(&scratch, points);
    vec_sub_ba(&copy0, &scratch, &D_L01_001E29C0);
    c2 = D_001DD134_sda | (alpha2 << 24);
    q2.state[3] = q1.state[3];
    q2.state[2] = q1.state[2];
    q2.state[0] = q1.state[0];
    vec_sub_ab(&along, points + 1, points);
    q2.color[3] = c2; q2.color[2] = c2; q2.color[1] = c2; q2.color[0] = c2;
    q2.uv[0] = zero; q2.uv[1] = zero; q2.uv[2] = zero; q2.uv[3] = one;
    q2.uv[4] = one; q2.uv[5] = zero; q2.uv[6] = one; q2.uv[7] = one;
    q1.uv[0] = zero; q1.uv[1] = zero; q1.uv[2] = zero; q1.uv[3] = one;
    q1.uv[4] = one; q1.uv[5] = zero; q1.uv[6] = one; q1.uv[7] = one;
    vec_copy(&toward, &copy0);
    func_0038CE90(&normal, &along, &toward);
    length = func_0038CEA8(&normal);
    if (length != zero) length = one / length;
    func_0038CE20(&normal, &normal, width1 * length);
    vec_add_ba(&q1.p[0], points, &normal);
    vec_sub_ab(&q1.p[1], points, &normal);
    i = 1;
    limit = n - 1;
    if (i < limit) {
        p = points + 1;
        do {
        vec_copy(&scratch, p);
        vec_sub_ba(&scratch, &scratch, &D_L01_001E29C0);
        vec_copy(&copy1, p);
        vec_copy(&toward, &scratch);
        vec_sub_ba(&along, p + 1, &copy1);
        func_0038CE90(&normal, &along, &toward);
        length = func_0038CEA8(&normal);
        if (length != zero) length = one / length;
        func_0038CE20(&normal, &normal, width1 * length);
        vec_add_ba(&q1.p[2], p, &normal);
        vec_sub_ab(&q1.p[3], p, &normal);
        if (i == 1) q1.color[0] = q1.color[1] = D_001DD130_sda;
        else if (i == n - 2) q1.color[2] = q1.color[3] = D_001DD130_sda;
        else if (i == 2) q1.color[0] = q1.color[1] = c1;
        func_003D2DA0(&q1, 0, 0);
        *(vu0_q *)&q1.p[0] = *(vu0_q *)&q1.p[2];
        *(vu0_q *)&q1.p[1] = *(vu0_q *)&q1.p[3];
        i++; p++;
        } while (i < limit);
    }
    i = 0;
    if (limit > 0) {
        p = points;
        do {
        vec_copy(&scratch, p);
        vec_sub_ba(&scratch, &scratch, &D_L01_001E29C0);
        vec_copy(&camera0, &D_L01_001E29C0);
        vec_copy(&d0, &scratch);
        vec_sub_ba(&d1, p + 1, &camera0);
        a = func_0038CEA8(&d0);
        b = func_0038CEA8(&d1);
        if (b < a) {
            if (b == zero) *(vu0_q *)&d1 = *(vu0_q *)&d0;
            else func_0038CE20(&d1, &d1, a / b);
        } else {
            if (a == zero) *(vu0_q *)&d0 = *(vu0_q *)&d1;
            else func_0038CE20(&d0, &d0, b / a);
        }
        vec_add_ba(&start, &D_L01_001E29C0, &d0);
        vec_add_ab(&end, &D_L01_001E29C0, &d1);
        vec_sub_ba(&along, &end, &start);
        func_0038CE20(&move, &along, shift);
        vec_sub_ba(&start, &start, &move);
        vec_copy(&camera1, &D_L01_001E29C0);
        vec_add_ba(&end, &end, &move);
        vec_sub_ab(&back, &camera1, &start);
        func_0038CE90(&normal, &back, &along);
        length = func_0038CEA8(&normal);
        if (length != zero) length = one / length;
        func_0038CE20(&offset, &normal, width2 * length);
        vec_add_ba(&q2.p[0], &start, &offset);
        vec_sub_ab(&q2.p[1], &start, &offset);
        vec_add_ba(&q2.p[2], &end, &offset);
        vec_sub_ab(&q2.p[3], &end, &offset);
        if (i == 0) q2.color[0] = q2.color[1] = D_001DD134_sda;
        else if (i == n - 2) q2.color[2] = q2.color[3] = D_001DD134_sda;
        else if (i == 1) q2.color[0] = q2.color[1] = c2;
        func_003D2DA0(&q2, 0, 0);
        i++; p++;
        } while (i < limit);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_00340670 */

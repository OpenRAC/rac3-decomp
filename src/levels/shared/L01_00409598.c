#include "common.h"

/* localdecomp:start func_L01_00409598 */
s32 func_L01_00409598(s32 a, s32 b, s32 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j) {
    extern void *func_L01_003CC9C8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    return func_L01_003CC9C8(a, b, c, d, e, f, g, h, i, j);
}
/* localdecomp:end func_L01_00409598 */

/* localdecomp:start func_L01_004095C8 */
typedef s32 (*Fn004071B0)(s32, s32, s32, s32, s32);
extern s32 func_L01_0043B568(s32, s32, s32);
s32 func_L01_004095C8(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    Fn004071B0 *f = func_L01_0043B568(7721, 0, 4);
    if (f == 0) {
        return 0;
    }
    return (*f)(a0, a1, a2, a3, t0);
}
/* localdecomp:end func_L01_004095C8 */

/* localdecomp:start func_L01_00409658 */
#include "vu0.h"

typedef struct {
    vu0_q pos[4];
    s32 color[4];
    f32 uv[4][2];
    u8 data[32];
} Packet_00409658;

extern vu0_v4 D_L01_001E29C0;

void func_L01_00409658(vu0_v4 *points, s32 texture, s32 texture2,
    s32 count, s32 color, s32 color2, s32 closed, f32 unused, f32 scale, f32 scroll) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_00409658 a, b;
    vu0_v4 normal, offset, camera, direction;
    vu0_q first[2], first2[2];
    vu0_v4 *p;
    f32 zero, start, end;
    s32 i;

    func_003D93B0(&a, texture, 1, 128);
    *(s32 *)&a.uv[0][0] = 0;
    zero = a.uv[0][0];
    end = scroll + 1.0f;
    start = scroll + zero;
    a.color[3] = color;
    a.color[2] = color;
    a.color[1] = color;
    a.color[0] = color;
    *(s32 *)&a.uv[0][1] = 0;
    a.uv[1][1] = 1.0f;
    *(s32 *)&a.uv[2][1] = 0;
    a.uv[3][1] = 1.0f;
    a.uv[1][0] = start;
    a.uv[0][0] = start;
    a.uv[3][0] = end;
    a.uv[2][0] = end;
    func_003D93B0(&b, texture2, 1, 128);
    b.color[3] = color2;
    b.color[2] = color2;
    b.color[1] = color2;
    b.color[0] = color2;
    b.uv[0][1] = zero;
    b.uv[1][1] = 1.0f;
    b.uv[2][1] = zero;
    b.uv[3][1] = 1.0f;
    b.uv[1][0] = start;
    b.uv[0][0] = start;
    b.uv[3][0] = end;
    b.uv[2][0] = end;
    vec_sub_ab(&camera, &points[0], &D_L01_001E29C0);
    vec_sub_ab(&direction, &points[1], &points[0]);
    func_0038CE90(&normal, &direction, &camera);
    func_0038CF68(&offset, &normal, points[0].w);
    vec_add_ba(&a.pos[0], &points[0], &offset);
    vec_sub_ab(&a.pos[1], &points[0], &offset);
    first[0] = a.pos[0];
    first[1] = a.pos[1];
    func_0038CE20(&offset, &offset, scale);
    vec_add_ba(&b.pos[0], &points[0], &offset);
    vec_sub_ab(&b.pos[1], &points[0], &offset);
    first2[0] = b.pos[0];
    first2[1] = b.pos[1];
    for (i = 1; i < count; i++) {
        p = &points[i];
        if (i >= count - 1 && closed == 0) continue;
        {
            vec_sub_ab(&camera, p, &D_L01_001E29C0);
            vec_sub_ab(&direction, p, p - 1);
            func_0038CE90(&normal, &direction, &camera);
            func_0038CF68(&offset, &normal, p->w);
            vec_add_ba(&a.pos[2], p, &offset);
            vec_sub_ab(&a.pos[3], p, &offset);
            func_0038CE20(&offset, &offset, scale);
            vec_add_ba(&b.pos[2], p, &offset);
            vec_sub_ab(&b.pos[3], p, &offset);
            if (i == count - 1) {
                a.pos[2] = first[0]; a.pos[3] = first[1];
                b.pos[2] = first2[0]; b.pos[3] = first2[1];
            }
            func_003D2DA0(&a, 0, 0);
            func_003D2DA0(&b, 0, 0);
            a.pos[0] = a.pos[2]; a.pos[1] = a.pos[3];
            b.pos[0] = b.pos[2]; b.pos[1] = b.pos[3];
        }
    }
}
/* localdecomp:end func_L01_00409658 */

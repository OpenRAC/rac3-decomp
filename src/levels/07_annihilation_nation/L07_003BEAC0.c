#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L07_003BEAC0 */
extern void func_L07_003BEB50(void *, void *, s32, s32, s32);

void func_L07_003BEAC0(u8 *arg0) {
    u8 *s2 = *(u8 **)(arg0 + 0x68);
    u8 *p = s2 + 0x4F2;
    s32 i;

    for (i = 0; i < 2; i++) {
        if ((s2[0x4FB] >> i) & 1) {
            func_L07_003BEB50(arg0, s2 + 0x3B0 + i * 0xA0, p[i - 2], p[i], s2[0x4FC] + 0x64);
        }
    }
}
/* localdecomp:end func_L07_003BEAC0 */

/* localdecomp:start func_L07_003BEB50 */
#include "vu0.h"
extern vu0_v4 D_L07_001E1EC0;
extern f32 D_L07_001E16A0[] __attribute__((section(".sdata")));
typedef struct { f32 a[3]; f32 b[3]; } S2_3BEB50;
extern S2_3BEB50 D_L07_002A28B0[];
extern u8 D_L07_002A28BC[];
extern u32 D_L07_002A29A0[][2];
extern vu0_v4 D_L07_002A29F0[];
void func_L07_003BEB50(void *arg0_, void *points_, s32 count, s32 start, s32 arg4) {
    u8 *arg0 = arg0_;
    vu0_v4 *points = points_;
    extern void func_0038C750(void);
    extern long func_00389598(s32);
    extern void func_003A9440(s32, long);
    extern f32 func_0038CEA8(vu0_v4 *);
    extern void func_0038CE90(vu0_v4 *, vu0_v4 *, vu0_v4 *);
    extern void func_0038CF68(vu0_v4 *, vu0_v4 *, f32);
    extern void func_0038CC88(void *, void *, s32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    vu0_v4 delta;
    vu0_v4 previous;
    vu0_v4 normal;
    vu0_v4 offset;
    vu0_v4 tmp;
    f32 total, t, length;
    s32 i, j, index, next;
    u32 color;

    if (count < 2) {
        return;
    }
    func_0038C750();
    total = 0.0f;
    func_003A9440(6, func_00389598(arg4));
    func_003A9440(0x14, 0xFF9000000260L);
    func_003A9440(8, 0);
    func_003A9440(0x42, 0x4000000044L);
    for (i = 0; i < count; i++) {
        index = (i + start) % count;
        next = (index + 1) % count;
        if (i != count - 1) {
            vec_sub_ab(&delta, &points[index], &points[next]);
            length = func_0038CEA8(&delta);
            total += length;
            D_L07_001E16A0[i] = length;
        }
        if (i != 0 && i != count - 1) {
            vec_add_ab(&normal, &delta, &previous);
        } else {
            *(vu0_q *)&normal = *(vu0_q *)&delta;
        }
        if (arg0[0x42] == 7) {
            qzero(&offset);
            offset.z = 0.5f;
        } else {
            vec_sub_ab(&tmp, &D_L07_001E1EC0, &points[index]);
            func_0038CE90(&offset, &tmp, &normal);
            func_0038CF68(&offset, &offset, 0.5f);
        }
        vec_add_ab(&tmp, &points[index], &offset);
        func_0038CC88(D_L07_002A28B0[i].a, &tmp, 12);
        vec_sub_ab(&tmp, &points[index], &offset);
        func_0038CC88(D_L07_002A28B0[i].b, &tmp, 12);
    }
    total = 1.0f / total;
    t = 0.0f;
    for (j = 0; j < count; j++) {
        color = func_0038DBD8(0x804020, 0x30202080, t);
        D_L07_002A29A0[j][1] = color;
        D_L07_002A29A0[j][0] = color;
        D_L07_002A29F0[j].x = t;
        D_L07_002A29F0[j].z = t;
        D_L07_002A29F0[j].y = 0;
        D_L07_002A29F0[j].w = 1.0f;
        t += D_L07_001E16A0[j] * total;
    }
    func_003D3A24(count * 2, D_L07_002A28B0, D_L07_002A29A0, D_L07_002A29F0, 1);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L07_003BEB50 */

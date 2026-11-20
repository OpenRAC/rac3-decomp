#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t v0, v1, v2;
    u128_t matrix[3];
} Local_51FC18;

typedef struct __attribute__((packed)) { s32 values[2]; } Pair;

/* declared by functions of L39_0051F740.c, which this file was cut from */
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L39_0051FD90 */
#include "vu0.h"

typedef struct { u8 b[0x460]; } S_0051FD90_E;
typedef struct { s32 v[6]; } S_0051FD90_C;

extern S_0051FD90_E D_L39_0024DE80[];
extern S_0051FD90_C D_L39_0024A948;
extern S_0051FD90_C D_L39_0024A960;
typedef struct { u8 pad[0x20]; f32 x, y, z; } S_0051FD90_P;
extern S_0051FD90_P D_L39_0046F5E0;
extern f32 D_L39_0024A938 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024A938, 4");
extern f32 D_L39_0024A93C __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024A93C, 4");
extern f32 D_L39_0024A940 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024A940, 4");
extern f32 D_L39_0024A944 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024A944, 4");

extern f32 func_0038CEA8(void *);
extern s32 func_L39_005BE900(void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern f32 func_L39_005B44C8(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L39_005B4398(s32);
extern void func_L39_005C6E90(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L01_003006C0(u8 *, u8 *, s32, s32);
extern u32 func_L01_00448D88(u32, s32);
extern void func_L39_005C7B40(void *, void *, u32, u32, s32, s32, s32, s32, s32, f32);

void func_L39_0051FD90(u8 *obj, u8 *pos)
{
    vu0_v4 dir;
    vu0_v4 sphere;
    vu0_v4 sum;
    vu0_v4 v;
    s32 c1[6];
    s32 c2[6];
    f32 qd;
    s32 count;
    s32 flag;
    u8 *p;
    f32 dist;
    s32 n;
    s32 m;
    s32 i;
    f32 a, b, s;
    s32 *x, *y;
    s32 k;
    u32 u, w;
    S_0051FD90_P *e;

    p = *(u8 **)(*(u8 **)(obj + 0x68) + 0x30);
    if (p != 0)
        vec_sub_ba(&dir, &D_L39_0024DE80[p[0x24C9]], pos);
    else
        vec_sub_ba(&dir, &D_L39_0024DE80[0], pos);
    dist = func_0038CEA8(&dir);
    n = 5;
    m = 10;
    sphere = *(vu0_v4 *)(obj + 0x10);
    count = 50;
    flag = 1;
    sphere.w = 0.5f;
    if (func_L39_005BE900(&sphere, &qd, D_L39_0024A944) > 0) {
        if (qd < D_L39_0024A938 * D_L39_0024A938) {
        } else if (qd < D_L39_0024A93C * D_L39_0024A93C) {
            n = 2;
            m = 5;
            count = 25;
        } else if (qd < D_L39_0024A940 * D_L39_0024A940) {
            n = 0;
            m = 5;
            count = 10;
        } else {
            n = 0;
            m = 3;
            count = 0;
        }
    } else {
        count = 0;
        n = 0;
        flag = 0;
        m = 0;
    }

    if (n != 0) {
        *(u128_t *)&v = 0;
        v.x = func_L39_005B4410(-1.0f, 1.0f);
        v.y = func_L39_005B4410(-1.0f, 1.0f);
        v.z = func_L39_005B4410(-1.0f, 1.0f);
        sum = v;
        dir.z += dist * 0.5f;
        func_0038CF68(&sum, &sum, dist / 5.0f * 0.0200000014f);
        func_0038CF68(&dir, &dir, (dist + dist) * 0.0200000014f);
        vec_add_ab(&sum, &sum, &dir);
        func_L01_0040E6B8(&sum, &sum, 0.2000000179f);
        func_0038D000(&sum, &sum, obj + 0xC0);
        func_L01_002FB660(pos, &sum, func_L39_005B43C8(50, 75), 0, 0, 0);
        n--;
        for (i = 0; i < n; i++) {
            a = func_L39_005B4410(0.43633232f, 0.7853982f);
            b = func_L39_005B44C8();
            s = func_L39_005B4410(13.0f, 20.0f);
            func_00382760(&v, s * 0.0200000014f, b, a);
            func_0038D000(&v, &v, obj + 0xC0);
            func_L01_002FB660(pos, &v, func_L39_005B43C8(50, 75), 1, 0, 0);
        }
    }

    qzero(&sum);
    while (m != 0) {
        m--;
        s = func_L39_005B4410(8.0f, 10.0f) * 0.0200000014f;
        *(S_0051FD90_C *)c1 = D_L39_0024A948;
        *(S_0051FD90_C *)c2 = D_L39_0024A960;
        x = &c1[func_L39_005B4398(6)];
        y = &c2[func_L39_005B4398(6)];
        k = func_L39_005B43C8(17, 33);
        func_L39_005C6E90(pos, &sum, *x, *y, k, func_L39_005B43C8(42, 58), 0, 0, 600000.0f, s * 1.5f);
    }

    e = &D_L39_0046F5E0;
    e->y = 40.0f;
    e->z = 40.0f;
    e->x = 40.0f;
    if (flag != 0)
        func_L01_003006C0((u8 *)e, pos, 0, 0);

    for (m = 0; m < count; m++) {
        a = func_L39_005B4410(0.13962634f, 0.61086523f);
        b = func_L39_005B44C8();
        s = func_L39_005B4410(16.0f, 30.0f);
        func_00382760(&v, s * 0.0200000014f, b, a);
        u = func_L01_00448D88(0x4F007FFF, 0);
        w = func_L01_00448D88(0x1F00007F, 0);
        func_0038D000(&v, &v, obj + 0xC0);
        func_L39_005C7B40(pos, &v, u, w, func_L39_005B43C8(50, 100) - 10, 1, -1, -1, 0, 40000.0f);
    }
}
/* localdecomp:end func_L39_0051FD90 */

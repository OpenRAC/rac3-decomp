#include "common.h"

/* NTSC-U counterpart of func_L39_0051FD90 (src/levels/shared/L39_0051FD90.c) */
typedef int u128_t __attribute__((mode(TI)));
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L39_0051F928 */
#include "vu0.h"

typedef struct { u8 b[0x460]; } S_0051FD90_E;
typedef struct { s32 v[6]; } S_0051FD90_C;

extern S_0051FD90_E D_L39_0024DF80[];
extern S_0051FD90_C D_L39_0024AA58;
extern S_0051FD90_C D_L39_0024AA70_0051F928;
typedef struct { u8 pad[0x20]; f32 x, y, z; } S_0051FD90_P;
extern S_0051FD90_P D_L39_0046F6E0;
extern f32 D_L39_0024AA48 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AA48, 4");
extern f32 D_L39_0024AA4C __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AA4C, 4");
extern f32 D_L39_0024AA50 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AA50, 4");
extern f32 D_L39_0024AA54 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AA54, 4");

extern f32 func_00388770(void *);
extern s32 func_L39_005BC958(void *, void *, f32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_L01_0040C188(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L01_002FB638(void *, void *, s32, s32, s32, s32);
extern f32 func_L39_005B25C8_0051F928(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_L39_005B2498(s32);
extern void func_L39_005C4B80(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L01_00300650(u8 *, u8 *, s32, s32);
extern u32 func_L01_00445C50(u32, s32);
extern void func_L39_005C5838(void *, void *, u32, u32, s32, s32, s32, s32, s32, f32);

void func_L39_0051F928(u8 *obj, u8 *pos)
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
        vec_sub_ba(&dir, &D_L39_0024DF80[p[0x24C9]], pos);
    else
        vec_sub_ba(&dir, &D_L39_0024DF80[0], pos);
    dist = func_00388770(&dir);
    n = 5;
    m = 10;
    sphere = *(vu0_v4 *)(obj + 0x10);
    count = 50;
    flag = 1;
    sphere.w = 0.5f;
    if (func_L39_005BC958(&sphere, &qd, D_L39_0024AA54) > 0) {
        if (qd < D_L39_0024AA48 * D_L39_0024AA48) {
        } else if (qd < D_L39_0024AA4C * D_L39_0024AA4C) {
            n = 2;
            m = 5;
            count = 25;
        } else if (qd < D_L39_0024AA50 * D_L39_0024AA50) {
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
        v.x = func_L39_005B2510(-1.0f, 1.0f);
        v.y = func_L39_005B2510(-1.0f, 1.0f);
        v.z = func_L39_005B2510(-1.0f, 1.0f);
        sum = v;
        dir.z += dist * 0.5f;
        func_00388830(&sum, &sum, dist / 5.0f * 0.0166666675f);
        func_00388830(&dir, &dir, (dist + dist) * 0.0166666675f);
        vec_add_ab(&sum, &sum, &dir);
        func_L01_0040C188(&sum, &sum, 0.166666672f);
        func_003888C8(&sum, &sum, obj + 0xC0);
        func_L01_002FB638(pos, &sum, func_L39_005B24C8(60, 90), 0, 0, 0);
        n--;
        for (i = 0; i < n; i++) {
            a = func_L39_005B2510(0.43633232f, 0.7853982f);
            b = func_L39_005B25C8_0051F928();
            s = func_L39_005B2510(13.0f, 20.0f);
            func_0037E4B8(&v, s * 0.0166666675f, b, a);
            func_003888C8(&v, &v, obj + 0xC0);
            func_L01_002FB638(pos, &v, func_L39_005B24C8(60, 90), 1, 0, 0);
        }
    }

    qzero(&sum);
    while (m != 0) {
        m--;
        s = func_L39_005B2510(8.0f, 10.0f) * 0.0166666675f;
        *(S_0051FD90_C *)c1 = D_L39_0024AA58;
        *(S_0051FD90_C *)c2 = D_L39_0024AA70_0051F928;
        x = &c1[func_L39_005B2498(6)];
        y = &c2[func_L39_005B2498(6)];
        k = func_L39_005B24C8(20, 40);
        func_L39_005C4B80(pos, &sum, *x, *y, k, func_L39_005B24C8(50, 70), 0, 0, 600000.0f, s * 1.5f);
    }

    e = &D_L39_0046F6E0;
    e->y = 40.0f;
    e->z = 40.0f;
    e->x = 40.0f;
    if (flag != 0)
        func_L01_00300650((u8 *)e, pos, 0, 0);

    for (m = 0; m < count; m++) {
        a = func_L39_005B2510(0.13962634f, 0.61086523f);
        b = func_L39_005B25C8_0051F928();
        s = func_L39_005B2510(16.0f, 30.0f);
        func_0037E4B8(&v, s * 0.0166666675f, b, a);
        u = func_L01_00445C50(0x4F007FFF, 0);
        w = func_L01_00445C50(0x1F00007F, 0);
        func_003888C8(&v, &v, obj + 0xC0);
        func_L39_005C5838(pos, &v, u, w, func_L39_005B24C8(60, 120) - 10, 1, -1, -1, 0, 40000.0f);
    }
}
/* localdecomp:end func_L39_0051F928 */

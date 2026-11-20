#include "common.h"

/* declared by functions of L39_0051EB38.c, which this file was cut from */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0051EB38;
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_00382760(V4_0051EB38 *, f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern u8 D_L39_00296818[];

/* localdecomp:start func_L39_0051EF98 */
#include "vu0.h"

typedef struct { V4_0051EB38 pos; u8 pad[0x450]; } P_0051EF98;
typedef struct { s32 c[6]; } C6_0051EF98;

extern P_0051EF98 D_L39_0024DE80[];
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern C6_0051EF98 D_L39_0024A8E8;
extern C6_0051EF98 D_L39_0024A900;
extern f32 D_L39_0046F580[];
extern f32 D_L39_0024A88C;
__asm__(".extern D_L39_0024A88C, 4");
extern f32 D_L39_0024A880;
__asm__(".extern D_L39_0024A880, 4");
extern f32 D_L39_0024A884;
__asm__(".extern D_L39_0024A884, 4");
extern f32 D_L39_0024A888;
__asm__(".extern D_L39_0024A888, 4");
extern f32 D_L39_0024A8D8;
__asm__(".extern D_L39_0024A8D8, 4");
extern f32 D_L39_0024A8DC;
__asm__(".extern D_L39_0024A8DC, 4");
extern f32 D_L39_0024A8E0;
__asm__(".extern D_L39_0024A8E0, 4");
extern s32 D_L39_0024A8E4;
__asm__(".extern D_L39_0024A8E4, 4");
extern f32 D_L39_0024A8A8;
__asm__(".extern D_L39_0024A8A8, 4");
extern f32 D_L39_0024A8A0;
__asm__(".extern D_L39_0024A8A0, 4");
extern f32 D_L39_0024A8A4;
__asm__(".extern D_L39_0024A8A4, 4");
extern s32 D_L39_0024A898;
__asm__(".extern D_L39_0024A898, 4");
extern s32 D_L39_0024A89C;
__asm__(".extern D_L39_0024A89C, 4");

extern f32 func_0038CEA8(void *);
extern s32 func_L39_005BE900(void *, f32 *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_L39_005C6E90(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_00382580(void *, f32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern u32 func_L01_00448D88(u32, s32);
extern void func_L01_00470668(void *, void *, s32, f32);
extern void func_0038CE20(void *, void *, f32);

void func_L39_0051EF98(u8 *a0, V4_0051EB38 *a1) {
    V4_0051EB38 diff;
    V4_0051EB38 sph;
    V4_0051EB38 v;
    f32 dist;
    f32 len;
    s32 n;
    s32 m;
    s32 k;
    s32 i, j, l, q;
    s32 cnt;
    u8 *p;

    cnt = 20;
    p = *(u8 **)(*(u8 **)(a0 + 0x68) + 0x30);
    if (p != 0) {
        vec_sub_ba(&diff, &D_L39_0024DE80[p[0x24C9]], a1);
    } else {
        vec_sub_ba(&diff, &D_L39_0024DE80[0], a1);
    }
    len = func_0038CEA8(&diff);
    n = 5;
    sph = *(V4_0051EB38 *)(a0 + 0x10);
    sph.w = 0.5f;
    if (func_L39_005BE900(&sph, &dist, D_L39_0024A88C) > 0) {
        if (dist < D_L39_0024A880 * D_L39_0024A880) {
            m = 3;
            k = 0x96;
        } else if (dist < D_L39_0024A884 * D_L39_0024A884) {
            n = 2;
            m = 5;
            k = 0x19;
        } else if (dist < D_L39_0024A888 * D_L39_0024A888) {
            n = 0;
            m = 5;
            k = 10;
        } else {
            n = 0;
            m = 3;
            k = 0;
        }
    } else {
        k = 0;
        n = 0;
        m = 0;
    }
    if (*D_L39_00241120 >= 3) {
        n = 0;
    }
    if (n != 0) {
        n--;
        v = (V4_0051EB38){func_L39_005B4410(-1.0f, 1.0f), func_L39_005B4410(-1.0f, 1.0f), func_L39_005B4410(-1.0f, 1.0f)};
        diff.z += len * 0.5f;
        func_0038CF68(&v, &v, len / 5.0f * 0.020000001f);
        func_0038CF68(&diff, &diff, (len + len) * 0.020000001f);
        vec_add_ab(&v, &v, &diff);
        func_L01_0040E6B8(&v, &v, 0.20000002f);
        func_0038D000(&v, &v, a0 + 0xC0);
        func_L01_002FB660(a1, &v, func_L39_005B43C8(0x32, 0x4B), 0, 0, 0);
        for (i = 0; i < n; i++) {
            func_L39_0051EB38(a0, a1);
        }
    }
    qzero(&v);
    for (j = 0; j < m; j++) {
        C6_0051EF98 a;
        C6_0051EF98 b;
        s32 *pa;
        s32 *pb;
        s32 t1;
        f32 s;
        {
            s = func_L39_005B4410(8.0f, 10.0f) * 0.020000001f;
            a = D_L39_0024A8E8;
            b = D_L39_0024A900;
            pa = &a.c[func_L39_005B4398(6)];
            pb = &b.c[func_L39_005B4398(6)];
            t1 = func_L39_005B43C8(0x11, 0x21);
            func_L39_005C6E90(a1, &v, *pa, *pb, t1, func_L39_005B43C8(0x2A, 0x3A), 0, 0, 600000.0f, s * 1.5f);
            func_L39_0051ED58(a0, a1);
        }
    }
    /* store order as rac2-decomp's func_002AC728 */
    D_L39_0046F580[9] = 13.0f;
    D_L39_0046F580[10] = 13.0f;
    D_L39_0046F580[8] = 13.0f;
    for (l = 0; l < cnt; l++) {
        V4_0051EB38 vel;
        s32 c;
        s32 e;
        u8 *r;
        u8 *g = D_L39_00296818;
        {
            vel = (V4_0051EB38){0, 0, func_L39_005B4410(D_L39_0024A8D8 * 0.5f, D_L39_0024A8D8) * 0.020000001f};
            func_0038D000(&vel, &vel, a0 + 0xC0);
            {
                V4_0051EB38 pos;
                {
                    func_00382580(&pos, 0.0f, D_L39_0024A8DC);
                    vec_add_ba(&pos, a1, &pos);
                    c = (D_L39_0024A8E4 * 5 + 2) / 6;
                    e = func_L39_005B43C8(-2, 2);
                    r = func_L01_00475C60(&pos, &vel, c, e, 0x7F407FFF, 0x407FFF, 420000.0f, 252000.02f, func_L39_005B4410(D_L39_0024A8E0 * 0.6f, D_L39_0024A8E0), 0);
                    if (r != 0) {
                        r[2] = (*(u8 **)(g + 0x184))[3];
                    }
                }
            }
        }
    }
    for (q = 0; q < k; q++) {
        V4_0051EB38 w;
        f32 pitch, yaw;
        u8 *r;
        {
            pitch = func_L39_005B4410(0.13962634f, 0.61086524f);
            yaw = func_L39_005B44C8();
            func_00382760(&w, func_L39_005B4410(16.0f, 30.0f) * 0.020000001f, yaw, pitch);
            func_L01_00448D88(0x4F007FFF, 0);
            func_L01_00448D88(0x1F00007F, 0);
            func_0038D000(&w, &w, a0 + 0xC0);
            if (q < 0x28) {
                func_L01_00470668(a1, &w, (func_L39_005B43C8(0x19, 0x28) * 5 + 2) / 6, D_L39_0024A8A8 * 0.00040000002f);
            }
            func_0038CE20(&w, &w, func_L39_005B4410(0.1f, 1.2f));
            r = func_L01_00475C60(a1, &w, func_L39_005B43C8(0x32, 0x64) - 10, -2, 0x7F404040, 0x404040, D_L39_0024A8A0 * 210000.0f, D_L39_0024A8A0 * 210000.0f, D_L39_0024A8A4, 0);
            if (r != 0) {
                r[2] = ((u8 **)D_L39_00296818)[D_L39_0024A898][D_L39_0024A89C];
            }
        }
    }
}
/* localdecomp:end func_L39_0051EF98 */

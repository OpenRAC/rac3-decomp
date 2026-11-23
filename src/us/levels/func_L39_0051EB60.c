#include "common.h"

/* NTSC-U counterpart of func_L39_0051EF98 (src/levels/shared/L39_0051EF98.c) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0051EB38;
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B25C8_0051EB60(void);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_0037E4B8(V4_0051EB38 *, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern u8 D_L39_00296918[];

/* localdecomp:start func_L39_0051EB60 */
#include "vu0.h"

typedef struct { V4_0051EB38 pos; u8 pad[0x450]; } P_0051EF98;
typedef struct { s32 c[6]; } C6_0051EF98;

extern P_0051EF98 D_L39_0024DF80[];
extern s32 *D_L39_002412A0;
__asm__(".extern D_L39_002412A0, 16");
extern C6_0051EF98 D_L39_0024A9F8;
extern C6_0051EF98 D_L39_0024AA10;
extern f32 D_L39_0046F680[];
extern f32 D_L39_0024A99C;
__asm__(".extern D_L39_0024A99C, 4");
extern f32 D_L39_0024A990_0051EB60;
__asm__(".extern D_L39_0024A990_0051EB60, 4");
extern f32 D_L39_0024A994_0051EB60;
__asm__(".extern D_L39_0024A994_0051EB60, 4");
extern f32 D_L39_0024A998;
__asm__(".extern D_L39_0024A998, 4");
extern f32 D_L39_0024A9E8_0051EB60;
__asm__(".extern D_L39_0024A9E8_0051EB60, 4");
extern f32 D_L39_0024A9EC_0051EB60;
__asm__(".extern D_L39_0024A9EC_0051EB60, 4");
extern f32 D_L39_0024A9F0;
__asm__(".extern D_L39_0024A9F0, 4");
extern s32 D_L39_0024A9F4;
__asm__(".extern D_L39_0024A9F4, 4");
extern f32 D_L39_0024A9B8;
__asm__(".extern D_L39_0024A9B8, 4");
extern f32 D_L39_0024A9B0;
__asm__(".extern D_L39_0024A9B0, 4");
extern f32 D_L39_0024A9B4;
__asm__(".extern D_L39_0024A9B4, 4");
extern s32 D_L39_0024A9A8;
__asm__(".extern D_L39_0024A9A8, 4");
extern s32 D_L39_0024A9AC;
__asm__(".extern D_L39_0024A9AC, 4");

extern f32 func_00388770(void *);
extern s32 func_L39_005BC958(void *, f32 *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0040C188(void *, void *, f32);
extern void func_L01_002FB638(void *, void *, s32, s32, s32, s32);
extern void func_L39_005C4B80(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_0037E2F0(void *, f32, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern u32 func_L01_00445C50(u32, s32);
extern void func_L01_0046CF70(void *, void *, s32, f32);
extern void func_003886E8(void *, void *, f32);

void func_L39_0051EB60(u8 *a0, V4_0051EB38 *a1) {
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
        vec_sub_ba(&diff, &D_L39_0024DF80[p[0x24C9]], a1);
    } else {
        vec_sub_ba(&diff, &D_L39_0024DF80[0], a1);
    }
    len = func_00388770(&diff);
    n = 5;
    sph = *(V4_0051EB38 *)(a0 + 0x10);
    sph.w = 0.5f;
    if (func_L39_005BC958(&sph, &dist, D_L39_0024A99C) > 0) {
        if (dist < D_L39_0024A990_0051EB60 * D_L39_0024A990_0051EB60) {
            m = 3;
            k = 0x96;
        } else if (dist < D_L39_0024A994_0051EB60 * D_L39_0024A994_0051EB60) {
            n = 2;
            m = 5;
            k = 0x19;
        } else if (dist < D_L39_0024A998 * D_L39_0024A998) {
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
    if (*D_L39_002412A0 >= 3) {
        n = 0;
    }
    if (n != 0) {
        n--;
        v = (V4_0051EB38){func_L39_005B2510(-1.0f, 1.0f), func_L39_005B2510(-1.0f, 1.0f), func_L39_005B2510(-1.0f, 1.0f)};
        diff.z += len * 0.5f;
        func_00388830(&v, &v, len / 5.0f * 0.016666668f);
        func_00388830(&diff, &diff, (len + len) * 0.016666668f);
        vec_add_ab(&v, &v, &diff);
        func_L01_0040C188(&v, &v, 0.16666667f);
        func_003888C8(&v, &v, a0 + 0xC0);
        func_L01_002FB638(a1, &v, func_L39_005B24C8(60, 90), 0, 0, 0);
        for (i = 0; i < n; i++) {
            func_L39_0051E710(a0, a1);
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
            s = func_L39_005B2510(8.0f, 10.0f) * 0.016666668f;
            a = D_L39_0024A9F8;
            b = D_L39_0024AA10;
            pa = &a.c[func_L39_005B2498(6)];
            pb = &b.c[func_L39_005B2498(6)];
            t1 = func_L39_005B24C8(0x14, 0x28);
            func_L39_005C4B80(a1, &v, *pa, *pb, t1, func_L39_005B24C8(0x32, 0x46), 0, 0, 600000.0f, s * 1.5f);
            func_L39_0051E930(a0, a1);
        }
    }
    /* store order as rac2-decomp's func_002AC728 */
    D_L39_0046F680[9] = 13.0f;
    D_L39_0046F680[10] = 13.0f;
    D_L39_0046F680[8] = 13.0f;
    for (l = 0; l < cnt; l++) {
        V4_0051EB38 vel;
        s32 e;
        u8 *r;
        u8 *g = D_L39_00296918;
        {
            vel = (V4_0051EB38){0, 0, func_L39_005B2510(D_L39_0024A9E8_0051EB60 * 0.5f, D_L39_0024A9E8_0051EB60) * 0.016666668f};
            func_003888C8(&vel, &vel, a0 + 0xC0);
            {
                V4_0051EB38 pos;
                {
                    func_0037E2F0(&pos, 0.0f, D_L39_0024A9EC_0051EB60);
                    vec_add_ba(&pos, a1, &pos);
                    e = func_L39_005B24C8(-2, 2);
                    r = func_L01_00472438(&pos, &vel, D_L39_0024A9F4, e, 0x7F407FFF, 0x407FFF, 420000.0f, 252000.02f, func_L39_005B2510(D_L39_0024A9F0 * 0.6f, D_L39_0024A9F0), 0);
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
            pitch = func_L39_005B2510(0.13962634f, 0.61086524f);
            yaw = func_L39_005B25C8_0051EB60();
            func_0037E4B8(&w, func_L39_005B2510(16.0f, 30.0f) * 0.016666668f, yaw, pitch);
            func_L01_00445C50(0x4F007FFF, 0);
            func_L01_00445C50(0x1F00007F, 0);
            func_003888C8(&w, &w, a0 + 0xC0);
            if (q < 0x28) {
                func_L01_0046CF70(a1, &w, func_L39_005B24C8(0x19, 0x28), D_L39_0024A9B8 * 0.00027777778f);
            }
            func_003886E8(&w, &w, func_L39_005B2510(0.1f, 1.2f));
            r = func_L01_00472438(a1, &w, func_L39_005B24C8(60, 120) - 10, -2, 0x7F404040, 0x404040, D_L39_0024A9B0 * 210000.0f, D_L39_0024A9B0 * 210000.0f, D_L39_0024A9B4, 0);
            if (r != 0) {
                r[2] = ((u8 **)D_L39_00296918)[D_L39_0024A9A8][D_L39_0024A9AC];
            }
        }
    }
}
/* localdecomp:end func_L39_0051EB60 */

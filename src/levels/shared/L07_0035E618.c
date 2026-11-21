#include "common.h"

/* declared by functions of L07_0035DFD0.c, which this file was cut from */
extern f32 func_0038DAB8(f32, f32);

/* localdecomp:start func_L07_0035E618 */
#include "vu0.h"
typedef struct { vu0_v4 vel; u8 p10[4]; s32 w14; } P_35E618;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; P_35E618 *p68; } M_35E618;
extern u8 *D_L07_0021EC98[];
extern vu0_v4 D_001A4EC0;
extern f32 D_L07_001E0FB0[] __attribute__((section(".sdata")));
extern f32 D_L07_001DD720;
__asm__(".extern D_L07_001DD720, 4");
extern f32 D_L07_001DD724;
__asm__(".extern D_L07_001DD724, 4");
extern f32 D_L07_001DD730;
__asm__(".extern D_L07_001DD730, 4");
extern f32 D_L07_001DD734;
extern f32 D_L07_001DD738;
extern u8 D_L07_001DD6F0[8];
__asm__(".extern D_L07_001DD6F0, 8");
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_00382468(s32);
extern void func_003C4C18(f32 *, f32);
extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);

void func_L07_0035E618(void *o, vu0_v4 *pa, vu0_v4 *pb) {
    M_35E618 *m = o;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 v30;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 v60;
    vu0_v4 m70[3];
    vu0_v4 vA0;
    P_35E618 *p;
    u8 *vp;
    f32 len;
    s32 n;
    s32 i;
    s32 j;
    a = *pa;
    p = m->p68;
    b = *pb;
    len = func_0038CEA8(p);
    n = (s32)(len / 0.1f);
    c = b;
    vec_sub_ab(&d, &a, &b);
    func_0038CF68(&d, &d, len / (f32)n);
    for (i = 0; i < n; i++) {
        s32 life = (s32)func_L01_00443A18(1.0f, 3.0f);
        f32 sc = func_003824E0(0.1f, 0.2f);
        s32 r;
        s32 size;
        s32 color;
        u8 *q;
        func_0038CE20(&v30, &D_001A4EC0, -(sc * 0.020000001f));
        r = func_00382498(3, 6);
        if (func_0013D3E0() & 2) {
            size = 0x40;
            color = 0xFF7F40;
        } else {
            size = 0x60;
            color = 0xFF4040;
        }
        q = func_L01_0046A610(&c, &v30, (r * 5 + 2) / 6, size, color, life, 126000.01f, 10000.0f, 1.0f, 0.0f, 0.0f);
        vec_add_ab(&c, &c, &d);
        if (q != 0) {
            q[2] = *D_L07_0021EC98[0x5C / 4];
            q[3] = (size == 0x40) ? 0x48 : 0x44;
        }
    }
    if (func_00382468(2)) {
        s32 color;
        u8 *q;
        func_0038CE20(&v60, p, -0.040000003f);
        color = 0x7F80DFFF;
        func_003C4C18(&v60.x, 0.120000005f);
        v60.z += 0.060000002f;
        if (func_00382468(2)) color = 0x7F407FFF;
        j = func_00382498(8, 0x11);
        q = func_L01_00465738(&m->pos, &v60, color, 0xFF0000, j, 0, -1, -1, 0, 157500.0f);
        if (q != 0) {
            *(f32 *)(q + 0x2C) = 0.0024f;
            q[2] = *D_L07_0021EC98[0xD4 / 4];
        }
    }
    D_L07_001E0FB0[0] = func_0038DAB8(D_L07_001E0FB0[0], D_L07_001DD730 * 0.017453292f * 0.020000001f);
    D_L07_001E0FB0[1] = func_0038DAB8(D_L07_001E0FB0[1], D_L07_001DD734 * 0.017453292f * 0.020000001f);
    D_L07_001E0FB0[2] = func_0038DAB8(D_L07_001E0FB0[2], D_L07_001DD738 * 0.017453292f * 0.020000001f);
    func_0038D308(m70, D_L07_001E0FB0);
    for (j = 0; j < 3; j++) {
        u8 *q;
        s32 life;
        vu0_q q1, q2;
        func_0038D000(&vA0, &D_L07_001DD6F0[j * 0x10], m70);
        if (p->w14 >= 6) {
            func_0038CF68(&vA0, &vA0, D_L07_001DD720);
        } else {
            func_0038CF68(&vA0, &vA0, 0.0f);
        }
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(vA0));
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(m->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(q2) : "j"(q2), "j"(q1));
        __asm__("sqc2 %1, %0" : "=m"(vA0) : "j"(q2));
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(vA0));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(m->pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(v60) : "j"(q1));
        func_0038CF68(&v60, &v60, D_L07_001DD724 * 0.020000001f);
        life = (s32)func_L01_00443A18(2.0f, 5.0f);
        q = func_L01_004713C8(&vA0, &v60, 0xC, 0x802020, life, 0x6F, 0, 6, 126000.01f,
                              func_003824E0(0.12f, 0.18f) * 210000.0f, 0.0f);
        if (q != 0) {
            q[3] = func_00382468(4) ? 0x48 : 0x44;
        }
    }
}
/* localdecomp:end func_L07_0035E618 */

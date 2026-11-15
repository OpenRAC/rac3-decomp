#include "common.h"

/* localdecomp:start func_L39_00556D80 */
typedef int Q_00556D80 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00556D80;
typedef struct {
    u8 p00[0x10];
    V4_00556D80 pos;
    u8 state;
    u8 p21[0x21];
    u8 f42;
    u8 p43[5];
    f32 f48;
    u8 p4C[0x14];
    u8 f60;
    u8 p61[7];
    struct P_00556D80 *f68;
    u8 p6C[0x54];
    V4_00556D80 vC0;
    u8 pD0[0x28];
    f32 fF8;
} O_00556D80;
typedef struct {
    u8 p0[0xA0];
    V4_00556D80 posA0;
    u8 pB0[0x2474];
    s32 f2524;
} Q2_00556D80;
typedef struct P_00556D80 {
    u8 p0[0xB0];
    s32 fB0;
    u8 pB4[0xB4];
    u8 f168[0x18];
    s32 f180;
    u8 p184[8];
    Q2_00556D80 *f18C;
} P_00556D80;
typedef struct {
    u8 p0[0x18];
    s32 f18;
    u8 p1C[4];
    V4_00556D80 f20;
} D_00556D80;

extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L39_00557890(void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_004471A8(void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_004455E8(void *, f32, f32, void *, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_0045A898(void *, void *, f32);
extern void func_L01_00451290(void *, void *, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 D_001D72B0_sda; __asm__(".extern D_001D72B0_sda, 4");
extern s32 D_001D72AC_sda; __asm__(".extern D_001D72AC_sda, 4");
extern s32 D_L39_002429C0;
__asm__(".extern D_L39_002429C0, 16");
extern s32 D_L39_002429BC;
__asm__(".extern D_L39_002429BC, 16");
extern D_00556D80 D_L39_0025F740;

void func_L39_00556D80(O_00556D80 *obj) {
    V4_00556D80 t0;
    V4_00556D80 t1;
    V4_00556D80 pos;
    V4_00556D80 t30;
    V4_00556D80 t40;
    V4_00556D80 unused; /* never referenced: retail's frame has this 16-byte slot at 0x50 */
    Q_00556D80 x, y, r;
    P_00556D80 *p;
    Q2_00556D80 *q;
    f32 f22;
    f32 r2;
    f32 d;
    f32 ang;
    s32 n;
    void *w;

    p = obj->f68;
    if (func_L01_00447490(obj, 0x8010000, 0)) {
        func_L39_00557890(obj);
    }
    q = p->f18C;
    f22 = func_0038D160(obj->pos.x - q->posA0.x, obj->pos.y - q->posA0.y);
    func_L01_004471A8(obj, 0.4f);
    switch (obj->state) {
    case 0:
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (obj->f60 & 2) {
            r2 = func_L39_005B4410(0.0f, 100.0f);
            if (r2 >= 0.0f && r2 < 20.0f) {
                func_003C3A10(obj, 0, 0, 8);
            }
            if (r2 >= 20.0f && r2 < 40.0f) {
                func_003C3A10(obj, 1, 0, 8);
            }
            if (r2 >= 40.0f && r2 < 100.0f) {
                func_003C3A10(obj, 2, 0, 8);
            }
        }
        if (obj->f42 == 2) {
            ang = func_0038DAB8(obj->fF8, 3.14159274f);
            func_L01_004455E8(obj, ang, 0.000488692196f, p->f168, 0.000628318579f, 0.0314159282f);
        }
        d = func_0038CF38(&obj->pos, &q->posA0);
        if (d < 2.0f && D_001D72B0_sda == 0 && D_001D72AC_sda == 0) {
            func_L01_004450F0(obj, 2, -1);
            func_003C3A10(obj, 3, 0, 8);
            obj->f48 = 0.75f;
        }
        if (func_0038CAD0(&p->f180)) {
            if (D_L39_002429C0 == 0 && D_L39_002429BC == 0) {
                if (func_L39_005B4398(2)) {
                    func_L01_004450F0(obj, 5, -1);
                    p->f180 = (func_L39_005B43C8(400, 600) * 5 + 2) / 6;
                    func_003C3A10(obj, 3, 0, 8);
                    obj->f48 = 0.75f;
                } else {
                    func_L01_004450F0(obj, 6, -1);
                    p->f180 = (func_L39_005B43C8(180, 360) * 5 + 2) / 6;
                    func_003C3A10(obj, 4, 0, 8);
                }
            }
        }
        break;
    case 6:
        if (obj->f60 & 2) {
            func_003C3A10(obj, 4, 0, 8);
        }
        if (func_0038CAD0(&p->f180)) {
            func_L01_004450F0(obj, 1, -1);
            p->f180 = (func_L39_005B43C8(120, 600) * 5 + 2) / 6;
            func_003C3A10(obj, func_L39_005B4398(2), 0, 8);
        }
        break;
    case 5:
        if (obj->f60 & 2) {
            func_003C3A10(obj, 3, 0, 8);
            obj->f48 = 0.75f;
        }
        d = func_0038CF38(&obj->pos, &q->posA0);
        if (d < 2.0f) {
            func_L01_004450F0(obj, 2, -1);
            obj->f48 = 0.1f;
            func_003C3A10(obj, 3, 0, 8);
        }
        if (func_0038CAD0(&p->f180)) {
            func_L01_004450F0(obj, 1, -1);
            p->f180 = (func_L39_005B43C8(400, 600) * 5 + 2) / 6;
        }
        w = p->f168;
        func_L01_004455E8(obj, func_0038DAB8(obj->fF8, func_L39_005B4410(-45.0f, 45.0f) * 0.0174532924f), 0.000209439531f, w, 0.000628318579f, 0.0157079641f);
        func_0038CF68(&t1, &obj->vC0, 10.0f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t1));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(r));
        pos = obj->pos;
        func_L01_0045A898(obj, &t0, obj->fF8);
        if (p->fB0 >= 10) {
            func_L01_004455E8(obj, func_0038DAB8(obj->fF8, 3.14159274f), 0.000558505359f, w, 0.000628318579f, 0.0157079641f);
        }
        break;
    case 2:
        d = func_0038CF38(&obj->pos, &q->posA0);
        if (d < 2.0f) {
            w = p->f168;
            func_L01_004455E8(obj, func_0038DAB8(obj->fF8, func_L39_005B4410(-30.0f, 30.0f) * 0.0174532924f), 0.000209439531f, w, 0.000628318579f, 0.0157079641f);
            func_0038CF68(&t1, &obj->vC0, 10.0f);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t1));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(r));
            pos = obj->pos;
            func_L01_0045A898(obj, &t0, obj->fF8);
            if (p->fB0 >= 10) {
                func_L01_004455E8(obj, func_0038DAB8(obj->fF8, 3.14159274f), 8.37758125e-05f, w, 0.000628318579f, 0.0157079641f);
            } else if (func_0038DBA0(f22, obj->fF8) > 0.52359879f) {
                func_L01_004455E8(obj, f22, 0.000558505359f, w, 0.000628318579f, 0.0157079641f);
            }
        } else {
            obj->f48 = 1.0f;
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    case 4:
        func_L01_00451290(obj, &pos, 0);
        func_0038CF68(&pos, &pos, 4.0f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t30) : "j"(r));
        func_0038CF68(&pos, &pos, -1.0f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t40) : "j"(r));
        if (func_003D3CB0(&t40, &t30, 0, obj, 0)) {
            if (D_L39_0025F740.f18 != q->f2524) {
                obj->pos = D_L39_0025F740.f20;
            }
        }
        n = func_003D5630();
        if (n > 0 && n != 10 && D_001D72B0_sda == 0) {
            func_L39_00557890(obj);
            return;
        }
        func_L01_004450F0(obj, 0, -1);
        break;
    }
    pos = obj->pos;
    pos.z += 0.5f;
    obj->pos.z = func_003C3D30(&pos, 0, 0, 0.5f);
}
/* localdecomp:end func_L39_00556D80 */

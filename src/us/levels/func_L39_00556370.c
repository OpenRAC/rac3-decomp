#include "common.h"

/* NTSC-U counterpart of func_L39_00556D80 (src/levels/shared/L39_00556D80.c) */
/* localdecomp:start func_L39_00556370 */
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

extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L39_00556E10(void *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00444070(void *, f32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00389380(f32, f32);
extern void func_L01_004424B0(void *, f32, f32, void *, f32, f32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_00388398(void *);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L01_00457590(void *, void *, f32);
extern void func_L01_0044E010(void *, void *, s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_003D00C0(void);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern f32 func_00389468(f32, f32);
extern s32 D_001D72B0_sda_00556370; __asm__(".extern D_001D72B0_sda_00556370, 4");
extern s32 D_001D72AC_sda_00556370; __asm__(".extern D_001D72AC_sda_00556370, 4");
extern s32 D_L39_00242B40;
__asm__(".extern D_L39_00242B40, 16");
extern s32 D_L39_00242B3C;
__asm__(".extern D_L39_00242B3C, 16");
extern D_00556D80 D_L39_0025F840;

void func_L39_00556370(O_00556D80 *obj) {
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
    if (func_L01_00444358(obj, 0x8010000, 0)) {
        func_L39_00556E10(obj);
    }
    q = p->f18C;
    f22 = func_00388A28(obj->pos.x - q->posA0.x, obj->pos.y - q->posA0.y);
    func_L01_00444070(obj, 0.4f);
    switch (obj->state) {
    case 0:
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        if (obj->f60 & 2) {
            r2 = func_L39_005B2510(0.0f, 100.0f);
            if (r2 >= 0.0f && r2 < 20.0f) {
                func_003BE4F0(obj, 0, 0, 10);
            }
            if (r2 >= 20.0f && r2 < 40.0f) {
                func_003BE4F0(obj, 1, 0, 10);
            }
            if (r2 >= 40.0f && r2 < 100.0f) {
                func_003BE4F0(obj, 2, 0, 10);
            }
        }
        if (obj->f42 == 2) {
            ang = func_00389380(obj->fF8, 3.14159274f);
            func_L01_004424B0(obj, ang, 0.00033936958061531186f, p->f168, 0.0004363323387224227f, 0.02617994137108326f);
        }
        d = func_00388800(&obj->pos, &q->posA0);
        if (d < 2.0f && D_001D72B0_sda_00556370 == 0 && D_001D72AC_sda_00556370 == 0) {
            func_L01_00441FB8(obj, 2, -1);
            func_003BE4F0(obj, 3, 0, 10);
            obj->f48 = 0.75f;
        }
        if (func_00388398(&p->f180)) {
            if (D_L39_00242B40 == 0 && D_L39_00242B3C == 0) {
                if (func_L39_005B2498(2)) {
                    func_L01_00441FB8(obj, 5, -1);
                    p->f180 = func_L39_005B24C8(400, 600);
                    func_003BE4F0(obj, 3, 0, 10);
                    obj->f48 = 0.75f;
                } else {
                    func_L01_00441FB8(obj, 6, -1);
                    p->f180 = func_L39_005B24C8(180, 360);
                    func_003BE4F0(obj, 4, 0, 10);
                }
            }
        }
        break;
    case 6:
        if (obj->f60 & 2) {
            func_003BE4F0(obj, 4, 0, 10);
        }
        if (func_00388398(&p->f180)) {
            func_L01_00441FB8(obj, 1, -1);
            p->f180 = func_L39_005B24C8(120, 600);
            func_003BE4F0(obj, func_L39_005B2498(2), 0, 10);
        }
        break;
    case 5:
        if (obj->f60 & 2) {
            func_003BE4F0(obj, 3, 0, 10);
            obj->f48 = 0.75f;
        }
        d = func_00388800(&obj->pos, &q->posA0);
        if (d < 2.0f) {
            func_L01_00441FB8(obj, 2, -1);
            obj->f48 = 0.1f;
            func_003BE4F0(obj, 3, 0, 10);
        }
        if (func_00388398(&p->f180)) {
            func_L01_00441FB8(obj, 1, -1);
            p->f180 = func_L39_005B24C8(400, 600);
        }
        w = p->f168;
        func_L01_004424B0(obj, func_00389380(obj->fF8, func_L39_005B2510(-45.0f, 45.0f) * 0.0174532924f), 0.00014544410805683583f, w, 0.0004363323387224227f, 0.01308997068554163f);
        func_00388830(&t1, &obj->vC0, 10.0f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t1));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(r));
        pos = obj->pos;
        func_L01_00457590(obj, &t0, obj->fF8);
        if (p->fB0 >= 10) {
            func_L01_004424B0(obj, func_00389380(obj->fF8, 3.14159274f), 0.00038785094511695206f, w, 0.0004363323387224227f, 0.01308997068554163f);
        }
        break;
    case 2:
        d = func_00388800(&obj->pos, &q->posA0);
        if (d < 2.0f) {
            w = p->f168;
            func_L01_004424B0(obj, func_00389380(obj->fF8, func_L39_005B2510(-30.0f, 30.0f) * 0.0174532924f), 0.00014544410805683583f, w, 0.0004363323387224227f, 0.01308997068554163f);
            func_00388830(&t1, &obj->vC0, 10.0f);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t1));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(r));
            pos = obj->pos;
            func_L01_00457590(obj, &t0, obj->fF8);
            if (p->fB0 >= 10) {
                func_L01_004424B0(obj, func_00389380(obj->fF8, 3.14159274f), 5.8177643950330094e-05f, w, 0.0004363323387224227f, 0.01308997068554163f);
            } else if (func_00389468(f22, obj->fF8) > 0.52359879f) {
                func_L01_004424B0(obj, f22, 0.00038785094511695206f, w, 0.0004363323387224227f, 0.01308997068554163f);
            }
        } else {
            obj->f48 = 1.0f;
            func_L01_00441FB8(obj, 1, -1);
        }
        break;
    case 4:
        func_L01_0044E010(obj, &pos, 0);
        func_00388830(&pos, &pos, 4.0f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t30) : "j"(r));
        func_00388830(&pos, &pos, -1.0f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t40) : "j"(r));
        if (func_003CE740(&t40, &t30, 0, obj, 0)) {
            if (D_L39_0025F840.f18 != q->f2524) {
                obj->pos = D_L39_0025F840.f20;
            }
        }
        n = func_003D00C0();
        if (n > 0 && n != 10 && D_001D72B0_sda_00556370 == 0) {
            func_L39_00556E10(obj);
            return;
        }
        func_L01_00441FB8(obj, 0, -1);
        break;
    }
    pos = obj->pos;
    pos.z += 0.5f;
    obj->pos.z = func_003BE7F0(&pos, 0, 0, 0.5f);
}
/* localdecomp:end func_L39_00556370 */

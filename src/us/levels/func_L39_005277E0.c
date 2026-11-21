#include "common.h"

/* NTSC-U counterpart of func_L39_00527C88 (src/levels/shared/L39_00524E00.c) */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00525030;
typedef struct R_00525030 { u8 pad0[0x10]; void *p10; } R_00525030;
typedef struct M_00525030 {
    u8 pad0[0x10];
    V_00525030 pos;
    u8 pad20[4];
    R_00525030 *p24;
    u8 pad28[0x70];
    void *p98;
    u8 pad9C[0xE];
    s16 hAA;
    u8 padAC[0x14];
    V_00525030 vC0;
    u8 padD0[0x10];
    V_00525030 vE0;
    u8 padF0[8];
    f32 fF8;
} M_00525030;
typedef struct C_00525030 { u8 pad0[0x18]; M_00525030 *hit; u8 pad1C[4]; V_00525030 pos; } C_00525030;
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388800(void *, void *);
extern C_00525030 D_L39_0025F840;
extern s32 D_L39_00242B3C;
#include "vu0.h"
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388A28(f32, f32);
extern s32 func_00388398(void *);
extern s32 func_L39_005B24C8(s32, s32);
#include "vu0.h"
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L39_005B2498(s32);
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L39_005277E0 */
typedef struct {
    u8 p00[0x10];
    V_00525030 pos;
    u8 state;
    u8 p21[0x27];
    f32 f48;
    u8 p4C[0x14];
    u8 f60;
    u8 p61[7];
    struct P_00527C88 *f68;
    u8 p6C[0x54];
    V_00525030 vC0;
    u8 pD0[0x28];
    f32 fF8;
} O_00527C88;
typedef struct {
    u8 p0[0xA0];
    V_00525030 posA0;
    u8 pB0[0x2474];
    void *f2524;
} Q_00527C88;
typedef struct P_00527C88 {
    u8 p0[0x78];
    u8 f78[0x18];
    s32 f90;
    u8 p94[8];
    Q_00527C88 *f9C;
} P_00527C88;

extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L39_00528298();
extern void func_L01_00444070(void *, f32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00389380(f32, f32);
extern void func_L01_004424B0(void *, f32, f32, void *, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_00388398(void *);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L39_005B3620(void *, void *, void *, f32, s32, f32, f32, f32);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern void func_L01_0044E010(void *, void *, s32);
extern s32 func_003D00C0(void);
extern f32 func_003BE7F0(void *, s32, s32, f32);
__asm__(".extern D_L39_00242B40, 16");
extern s32 D_L39_00242B40;

void func_L39_005277E0(O_00527C88 *obj) {
    V_00525030 t0;
    V_00525030 t1;
    V_00525030 pos;
    V_00525030 t30;
    V_00525030 t40;
    P_00527C88 *p;
    Q_00527C88 *q;
    void *w;
    f32 r2;
    s32 n;

    p = obj->f68;
    if (func_L01_00444358(obj, 0x8010000, 0)) {
        func_L39_00528298(obj);
        return;
    }
    q = p->f9C;
    func_00388A28(obj->pos.x - q->posA0.x, obj->pos.y - q->posA0.y);
    func_L01_00444070(obj, 0.5f);
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
            if (r2 >= 20.0f && r2 < 50.0f) {
                func_003BE4F0(obj, 4, 0, 10);
            }
            if (r2 >= 50.0f && r2 < 100.0f) {
                func_003BE4F0(obj, 1, 0, 10);
            }
        }
        if (func_00388800(&obj->pos, &q->posA0) < 2.0f && D_L39_00242B40 == 0 && D_L39_00242B3C == 0) {
            func_L01_00441FB8(obj, 2, -1);
            func_003BE4F0(obj, 2, 0, 10);
            obj->f48 = 0.75f;
        }
        if (func_00388398(&p->f90)) {
            if (D_L39_00242B40 == 0 && D_L39_00242B3C == 0) {
                if (func_L39_005B2498(2)) {
                    func_L01_00441FB8(obj, 5, -1);
                    p->f90 = func_L39_005B24C8(400, 600);
                    func_003BE4F0(obj, 2, 0, 10);
                    obj->f48 = 0.75f;
                } else {
                    func_L01_00441FB8(obj, 6, -1);
                    p->f90 = func_L39_005B24C8(180, 360);
                    func_003BE4F0(obj, 3, 0, 10);
                }
            }
        }
        break;
    case 6:
        if (obj->f60 & 2) {
            func_003BE4F0(obj, 3, 0, 10);
        }
        if (func_00388398(&p->f90)) {
            func_L01_00441FB8(obj, 1, -1);
            p->f90 = func_L39_005B24C8(120, 600);
            func_003BE4F0(obj, func_L39_005B2498(2), 0, 10);
        }
        break;
    case 5:
        if (obj->f60 & 2) {
            func_003BE4F0(obj, 2, 0, 10);
            obj->f48 = 0.75f;
        }
        if (func_00388800(&obj->pos, &q->posA0) < 2.0f) {
            func_L01_00441FB8(obj, 2, -1);
            obj->f48 = 0.1f;
            func_003BE4F0(obj, 2, 0, 10);
        }
        if (func_00388398(&p->f90)) {
            func_L01_00441FB8(obj, 1, -1);
            p->f90 = func_L39_005B24C8(400, 600);
        }
        w = p->f78;
        func_L01_004424B0(obj, func_00389380(obj->fF8, func_L39_005B2510(-30.0f, 30.0f) * 0.0174532924f), 0.00014544411f, w, 0.00043633234f, 0.013089971f);
        func_00388830(&t1, &obj->vC0, 0.004166667f);
        vec_add_ba(&t0, &obj->pos, &t1);
        pos = obj->pos;
        if (func_L39_005B3620(obj, &obj->pos, &t0, 0.1f, 2, 0.7f, 0.25f, 0.52359879f)) {
            if (func_L01_003F9498(&obj->pos, 1, obj, 0.5f) && D_L39_0025F840.hit != 0) {
                obj->pos = pos;
            }
        } else {
            func_L01_004424B0(obj, func_00389380(obj->fF8, func_L39_005B2510(20.0f, 135.0f) * 0.0174532924f), 4.8481368e-05f, w, 0.00043633234f, 0.013089971f);
        }
        break;
    case 2:
        if (func_00388800(&obj->pos, &q->posA0) < 2.0f) {
            w = p->f78;
            func_L01_004424B0(obj, func_00389380(obj->fF8, func_L39_005B2510(-30.0f, 30.0f) * 0.0174532924f), 0.00014544411f, w, 0.00043633234f, 0.013089971f);
            func_00388830(&t1, &obj->vC0, 0.004166667f);
            vec_add_ba(&t0, &obj->pos, &t1);
            pos = obj->pos;
            if (func_L39_005B3620(obj, &obj->pos, &t0, 0.5f, 2, 0.7f, 0.25f, 0.52359879f)) {
                if (func_L01_003F9498(&obj->pos, 1, obj, 0.5f) && D_L39_0025F840.hit != 0) {
                    obj->pos = pos;
                }
            } else {
                func_L01_004424B0(obj, func_00389380(obj->fF8, func_L39_005B2510(-90.0f, -10.0f) * 0.0174532924f), 5.8177644e-05f, w, 0.00043633234f, 0.013089971f);
            }
        } else {
            obj->f48 = 1.0f;
            func_L01_00441FB8(obj, 1, -1);
        }
        break;
    case 4:
        func_L01_0044E010(obj, &pos, 0);
        func_00388830(&pos, &pos, 4.0f);
        vec_add_ba(&t30, &obj->pos, &pos);
        func_00388830(&pos, &pos, -1.0f);
        vec_add_ba(&t40, &obj->pos, &pos);
        if (func_003CE740(&t40, &t30, 0, obj, 0)) {
            if (D_L39_0025F840.hit != q->f2524) {
                obj->pos = D_L39_0025F840.pos;
            }
        }
        n = func_003D00C0();
        if (n > 0 && n != 10 && D_L39_00242B40 == 0) {
            func_L39_00528298(obj);
            return;
        }
        func_L01_00441FB8(obj, 0, -1);
        break;
    }
    if (D_L39_00242B40 == 0 && D_L39_00242B3C == 0) {
        pos = obj->pos;
        pos.z += 0.5f;
        obj->pos.z = func_003BE7F0(&pos, 0, 0, 0.5f);
    }
    if (obj->pos.x < 2.0f || 1021.0f < obj->pos.x || obj->pos.y < 2.0f || 1021.0f < obj->pos.y ||
        obj->pos.z < 2.0f || 1021.0f < obj->pos.z) {
        func_L39_00528298(obj);
    }
}
/* localdecomp:end func_L39_005277E0 */

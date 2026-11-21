#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_004C6068 */
typedef struct Cam_004C6068 {
    u8 pad0[0x80];
    vu0_v4 v80;
    vu0_v4 v90;
    u8 padA0[0xF0 - 0xA0];
    vu0_v4 vF0;
    vu0_v4 v100;
    vu0_v4 v110;
    vu0_v4 v120;
    vu0_v4 v130;
    vu0_v4 v140;
    vu0_v4 v150;
    u8 pad160[0x10];
    f32 f170;
    f32 f174;
    f32 f178;
    f32 f17C;
    f32 f180;
    f32 f184;
    u8 pad188[0x1F0 - 0x188];
    s16 h1F0;
    u8 pad1F2[0x284 - 0x1F2];
    f32 f284;
    u8 pad288[4];
    s32 w28C;
    u8 pad290[0x2A7 - 0x290];
    u8 b2A7;
    u8 pad2A8[0x33C - 0x2A8];
    f32 f33C;
    u8 pad340[0x538 - 0x340];
    s32 w538;
    u8 pad53C[0x9E0 - 0x53C];
    vu0_v4 v9E0;
    u8 pad9F0[0x25C4 - 0x9F0];
    s32 w25C4;
    u8 pad25C8[4];
    s32 w25CC;
} Cam_004C6068;

extern Cam_004C6068 D_001A4BE0;
extern void func_L01_00511B50(s32, void *, void *);
extern f32 func_L01_00511408(void *);
extern void func_L01_00511588(void *, void *, f32);
extern f32 func_L01_005114B0(void *);
extern void func_L01_00511508(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_00511320(void *, void *);
extern void func_L01_004F0AB0(void);
extern void func_L01_004EF840(void);
extern void func_L01_004F02D8(void);
extern f32 func_L01_004F05F0(void *);

void func_L02_004C6068(void) {
    vu0_v4 old;
    vu0_v4 t1;
    vu0_v4 t2;
    s32 st;

    *(vu0_q *)&old = *(vu0_q *)&D_001A4BE0.v80;
    func_L01_00511B50(D_001A4BE0.w538, &D_001A4BE0.v100, &D_001A4BE0.v90);
    st = D_001A4BE0.w25C4;
    if (st == 0x14 || st == 0x5F || st == 0x5C || st == 0xA2 || st == 0x86) {
        if (D_001A4BE0.h1F0 == 0) {
            f32 len = func_L01_00511408(&D_001A4BE0.vF0);
            f32 k = D_001A4BE0.f284 - 0.02f;
            if (k < len) {
                func_L01_00511588(&D_001A4BE0.vF0, &D_001A4BE0.vF0, k);
            }
        }
        {
            f32 x = func_L01_005114B0(&D_001A4BE0.vF0);
            if (x < 0.0f) {
                f32 lim = -D_001A4BE0.f33C;
                if (x < lim) {
                    f32 lo = lim - 0.1f;
                    if (x < lo) {
                        x = lo;
                    }
                    if (0.0f < x) {
                        x = 0.0f;
                    }
                    func_L01_00511508(&D_001A4BE0.vF0, &D_001A4BE0.vF0, x);
                }
            }
        }
        if (D_001A4BE0.w25C4 == 0x14) {
            f32 len = func_0038CEA8(&D_001A4BE0.vF0);
            f32 k = D_001A4BE0.f284 - 0.02f;
            if (k < len) {
                func_0038CE20(&D_001A4BE0.vF0, &D_001A4BE0.vF0, k / len);
            }
        }
    } else if (D_001A4BE0.w25CC == 0xD) {
    } else if (D_001A4BE0.w25CC == 0xE) {
    } else if (D_001A4BE0.h1F0 == 0) {
        f32 len = func_0038CEA8(&D_001A4BE0.vF0);
        f32 k = D_001A4BE0.f284 - 0.02f;
        if (k < len) {
            func_0038CF68(&D_001A4BE0.vF0, &D_001A4BE0.vF0, k);
        }
    }
    vec_add_ab(&D_001A4BE0.v80, &D_001A4BE0.v80, &D_001A4BE0.vF0);
    vec_add_ab(&D_001A4BE0.v80, &D_001A4BE0.v80, &D_001A4BE0.v9E0);
    qzero(&D_001A4BE0.v9E0);
    D_001A4BE0.b2A7 = 0;
    D_001A4BE0.w28C = 0;
    if (func_0038CEA8(&D_001A4BE0.v100) <= 0.0001f) {
        func_L01_004F0AB0();
        func_L01_004EF840();
        vec_sub_ab(&D_001A4BE0.v110, &D_001A4BE0.v80, &old);
        func_L01_004F02D8();
    } else {
        func_L01_004EF840();
    }
    vec_sub_ba(&D_001A4BE0.v120, &D_001A4BE0.v80, &old);
    *(vu0_q *)&D_001A4BE0.v140 = *(vu0_q *)&D_001A4BE0.v120;
    *(vu0_q *)&D_001A4BE0.v130 = *(vu0_q *)&D_001A4BE0.v120;
    func_0038CF68(&D_001A4BE0.v120, &D_001A4BE0.v120, 1.0f);
    {
        f32 d = func_0038CE68(&D_001A4BE0.v120, &D_001A4BE0.vF0);
        if (d < 0.0f) {
            d = 0.0f;
        }
        func_0038CF68(&D_001A4BE0.v120, &D_001A4BE0.vF0, d);
    }
    *(vu0_q *)&t1 = *(vu0_q *)&D_001A4BE0.vF0;
    func_L01_00511320(&t1, &t1);
    func_L01_00511320(&D_001A4BE0.v140, &D_001A4BE0.v140);
    func_0038CF68(&D_001A4BE0.v140, &D_001A4BE0.v140, 1.0f);
    {
        f32 d = func_0038CE68(&D_001A4BE0.v140, &t1);
        if (d < 0.0f) {
            d = 0.0f;
        }
        func_0038CF68(&D_001A4BE0.v140, &t1, d);
    }
    *(vu0_q *)&t2 = *(vu0_q *)&D_001A4BE0.vF0;
    func_L01_00511588(&t2, &t2, 0.0f);
    func_L01_00511588(&D_001A4BE0.v130, &D_001A4BE0.v130, 0.0f);
    func_0038CF68(&D_001A4BE0.v130, &D_001A4BE0.v130, 1.0f);
    {
        f32 d = func_0038CE68(&D_001A4BE0.v130, &t2);
        if (d < 0.0f) {
            d = 0.0f;
        }
        func_0038CF68(&D_001A4BE0.v130, &t2, d);
    }
    D_001A4BE0.f170 = func_0038CEA8(&D_001A4BE0.v120);
    D_001A4BE0.f174 = func_L01_00511408(&D_001A4BE0.v120);
    *(vu0_q *)&t1 = *(vu0_q *)&D_001A4BE0.v120;
    D_001A4BE0.f178 = func_L01_004F05F0(&t1);
    D_001A4BE0.f180 = func_L01_005114B0(&D_001A4BE0.v120);
    if (D_001A4BE0.f178 < 0.0f) {
        D_001A4BE0.f178 = 0.0f;
    }
    *(vu0_q *)&t1 = *(vu0_q *)&D_001A4BE0.v80;
    if (0.0001f < func_0038CEA8(&D_001A4BE0.v100)) {
        f32 w;
        vec_add_ba(&D_001A4BE0.v80, &D_001A4BE0.v80, &D_001A4BE0.v100);
        w = D_001A4BE0.v100.w;
        qzero(&D_001A4BE0.v100);
        D_001A4BE0.v100.w = w;
        func_L01_004F0AB0();
        func_L01_004EF840();
        vec_sub_ab(&D_001A4BE0.v110, &D_001A4BE0.v80, &old);
        func_L01_004F02D8();
    }
    vec_sub_ba(&D_001A4BE0.v150, &D_001A4BE0.v80, &t1);
    D_001A4BE0.f184 = func_0038CEA8(&D_001A4BE0.v150);
    D_001A4BE0.v150.w = D_001A4BE0.v100.w;
    D_001A4BE0.v100.w = 0.0f;
    vec_sub_ba(&D_001A4BE0.v110, &D_001A4BE0.v80, &old);
    D_001A4BE0.f17C = 0.0f;
    if (0.004f < D_001A4BE0.f174) {
        f32 q = D_001A4BE0.v110.z / D_001A4BE0.f174;
        D_001A4BE0.f17C = q;
        if (0.5f < q) {
            D_001A4BE0.f17C = 0.5f;
        } else if (q < -0.5f) {
            D_001A4BE0.f17C = -0.5f;
        }
    }
    if (1.0400001f < D_001A4BE0.f170) {
        func_0038CE20(&D_001A4BE0.v110, &D_001A4BE0.v110, 1.0400001f / D_001A4BE0.f170);
        D_001A4BE0.f170 = 1.0400001f;
    }
}
/* localdecomp:end func_L02_004C6068 */

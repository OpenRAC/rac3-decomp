#include "common.h"
#include "vu0.h"

typedef int Quad_3543C8 __attribute__((mode(TI)));
typedef struct Obj_3543C8 {
    u8 pad0[0x10];
    Quad_3543C8 pos;
    u8 pad20[4];
    u8 *def;
    u8 pad28[0xC];
    u16 flags;
    u8 pad36[0x32];
    u8 *vars;
    u8 pad6C[0x2A];
    u16 timer;
    s32 w98;
    u8 pad9C[0xC];
    u8 alpha;
    u8 padA9[0x13];
    u8 state;
    u8 padBD[0x33];
    Quad_3543C8 pos2;
} Obj_3543C8;
typedef struct Vars_3543C8 {
    u8 pad0[0x30];
    f32 hp;
    s16 maxhp;
    s16 hurt;
    u8 pad38[0x48];
    s32 w80;
    u8 pad84[0x2FE];
    u8 b382;
    u8 pad383[0x7D];
    Quad_3543C8 q400;
    Quad_3543C8 q410;
} Vars_3543C8;

/* localdecomp:start func_L18_00353138 */
typedef int Q_00353138 __attribute__((mode(TI)));

typedef struct G_00353138 {
    u8 pad0[0x19E0];
    void *x19E0;
    u8 pad19E4[0x25C4 - 0x19E4];
    s32 x25C4;
} G_00353138;

extern G_00353138 D_001A4BE0_00353138;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0044EBA0(void *, void *, void *, f32, f32, f32);
extern void func_L18_004614F8(void *, void *, void *, f32, f32, f32);

void func_L18_00353138(void *arg0) {
    u8 *a0 = arg0;
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 t;
    f32 w;

    t = func_0038DAB8(*(f32 *)(s + 0x358), 0.024434611f);
    *(f32 *)(s + 0x358) = t;
    w = func_0038D0B0(t) * 0.02f;
    *(f32 *)(s + 0x35C) = w;
    if (*(s32 *)(s + 0x3BC) != 0) {
        *(f32 *)(a0 + 0x18) = *(f32 *)(s + 0x368) + w;
        *(Q_00353138 *)v = *(Q_00353138 *)(a0 + 0xF0);
        func_L01_0044EBA0(a0, s + 0x360, s + 0x364, 0.02617994f, 0.009773845f, 0.04468043f);
        if (D_001A4BE0_00353138.x25C4 == 0x31 && D_001A4BE0_00353138.x19E0 == a0) {
            *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), v[0]);
            *(f32 *)(a0 + 0xF4) = func_0038DAB8(*(f32 *)(a0 + 0xF4), v[1]);
        }
    } else {
        func_0038CE20(v, s + 0x3C0, w);
        vec_add_ab(a0 + 0x10, s + 0x420, v);
        func_L18_004614F8(a0, s + 0x360, s + 0x364, 0.02617994f, 0.009773845f, 0.04468043f);
    }
}
/* localdecomp:end func_L18_00353138 */

/* localdecomp:start func_L18_00353280 */
extern u8 D_L18_001E2E40[];
extern u8 D_L18_001EAAA0[];
extern u8 D_L18_001E2E60[];
extern s32 D_001D545C;
extern s32 D_001D545C_00353280;
__asm__(".extern D_001D545C_00353280, 4");
extern u8 D_0014275B[];
extern f32 D_L18_001DD3B0;
__asm__(".extern D_L18_001DD3B0, 4");
extern f32 D_L18_001DA8F0;
__asm__(".extern D_L18_001DA8F0, 4");
extern f32 D_L18_002F1D50[];
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_L01_0041A4F0(void);
extern s32 func_L18_00323278(u8 *, void *, void *, u32, s32, f32, f32, f32, f32);

void func_L18_00353280(u8 *obj, f32 *vel, u32 a2) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 u70;
    vu0_v4 u80;
    vu0_v4 u90;
    u8 *p;
    f32 f;
    f32 d;
    f32 yaw;
    f32 pitch;
    f32 k;
    u8 *rot;

    p = *(u8 **)(obj + 0x68);
    *(vu0_q *)&v10 = 0;
    func_0038CE20(&v50, D_L18_001E2E40, 60.0f);
    vec_add_ab(&v30, &v50, obj + 0x10);
    if (func_003D3CB0(obj + 0x10, &v30, 0, obj, 0) != 0) {
        d = func_L01_0040E570(obj + 0x10, D_L18_001EAAA0);
        f = D_L18_001DD3B0;
        if (d < 130.0f) {
            f = f + f;
        } else if (d < 350.0f) {
            f = f * 1.5f;
        } else if (d < 2800.0f) {
            f = f * 1.25f;
        } else if (4096.0f < d) {
            f = 0.0f;
        }
        func_0038CE20(&v50, D_L18_001E2E60, f);
        vec_add_ba(vel, &v50, vel);
    } else {
        func_0038CE20(&v50, D_L18_001E2E40, 60.0f);
        vec_add_ab(&v40, &v50, &v30);
        if (func_003D3CB0(&v30, &v40, 0, obj, 0) != 0) {
            if (func_L01_0040E570(&v30, D_L18_001EAAA0) < 4096.0f) {
                func_0038CE20(&v50, D_L18_001E2E40 + 0x20, D_L18_001DD3B0 * 0.4f);
                vec_add_ba(vel, &v50, vel);
            }
        }
    }
    vec_sub_ba(&v10, vel, obj + 0x10);
    rot = obj + 0xC0;
    k = 10.0f;
    func_0038D160(v10.x, v10.y);
    func_0038D160(func_0038CED8(&v10), v10.z);
    *(vu0_q *)&v10 = *(vu0_q *)rot;
    func_0038CE20(&v20, p + 0x290, 3.0f);
    vec_add_ab(&v10, &v10, &v20);
    yaw = func_0038D160(v10.x, v10.y);
    pitch = -func_0038D160(func_0038CED8(&v10), v10.z);
    func_003C2F58(obj, p[0x380], &v0);
    func_0038D5B0(&v60, rot);
    func_0038D028(&v50, p + 0x290, &v60);
    if (D_001D545C == 0x12 || D_001D545C == 0x1A) {
        k = 50.0f;
    } else if (D_001D545C == 0x14) {
        k = 150.0f;
    }
    if (func_L01_0041A4F0() != 0) {
        if (D_001D545C_00353280 != 0x14) {
            if (D_001D545C_00353280 == 7 && D_0014275B[0] != 0) {
                k = k * D_L18_001DA8F0;
            } else {
                k = k * D_L18_002F1D50[D_001D545C_00353280];
            }
        }
    }
    if (func_L18_00323278(obj, &v0, vel, a2, 0, yaw, pitch, v50.x, k) != 0) {
        if (a2 == 0xFFFFFFFF) {
            *(s16 *)(p + 0x37E) = 0xC;
        }
        p[0x380] ^= 1;
    }
}
/* localdecomp:end func_L18_00353280 */

/* localdecomp:start func_L18_00353658 */
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003F6F20(s32, u8 *, s32, f32 *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_003F1F20(s32, s32);
extern void func_L18_00353280(u8 *, f32 *, u32);
extern s32 func_0038CB00(u8 *);
extern u8 D_L18_001E2AC0[];
extern u8 *D_001D52FC;
extern s32 D_L18_001DD320;
__asm__(".extern D_L18_001DD320, 4");

static __inline__ u8 *Ent_00353658(s32 off) {
    return D_L18_001E2AC0 + off;
}

void func_L18_00353658(u8 *a0) {
    f32 v[4];
    u8 *s;
    u8 *g;
    s32 x;
    s32 n;
    s32 m;

    g = D_001D52FC;
    *(s32 *)(a0 + 0x98) = 0;
    s = *(u8 **)(a0 + 0x68);
    func_0038CE20(v, Ent_00353658(0x380), 250.0f);
    vec_add_ab(v, v, a0 + 0x10);
    func_L01_003F6F20(0, a0, 0xFF0FFF0F, v, 0x23, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
    if (*(s32 *)(s + 0x3D4) > 0) {
        *(s32 *)(s + 0x3E4) = *(s32 *)(s + 0x3E4) + 1;
        if (*(s32 *)(s + 0x3E4) >= 0xB) {
            *(s32 *)(s + 0x3E4) = 0xA;
        }
    } else {
        *(s32 *)(s + 0x3E4) = 0;
    }
    if ((*(s32 *)(g + 0x1A0) & 0x28) != 0 && *(s16 *)(s + 0x37E) == 0 && *(s32 *)(s + 0x3D4) > 0 && *(s32 *)(s + 0x3E4) >= 3) {
        x = D_L18_001DD320;
        *(s32 *)(s + 0x3D8) = 0x15;
        func_L01_003F1F20(x, 0);
        func_L18_00353280(a0, v, 0xFFFFFFFF);
    }
    func_0038CB00(s + 0x37E);
    m = *(s32 *)(s + 0x3D8) - 1;
    *(s32 *)(s + 0x3D8) = m;
    if (m <= 0) {
        n = *(s32 *)(s + 0x3D4);
        if (n < 8) {
            *(s32 *)(s + 0x3D8) = 0x15;
            *(s32 *)(s + 0x3D4) = n + 1;
        }
    }
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
}
/* localdecomp:end func_L18_00353658 */

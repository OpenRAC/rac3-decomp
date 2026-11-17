#include "common.h"

/* localdecomp:start func_L39_005FC4C0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_005FC4C0;
typedef struct {
    V_005FC4C0 pos;
    u8 pad10[0x380 - 0x10];
    V_005FC4C0 rows[3];
} Cam_005FC4C0;
typedef struct {
    V_005FC4C0 pos;
    V_005FC4C0 rot;
} Ent_005FC4C0;
typedef struct {
    u8 pad0[0x38];
    s32 idx;
    u8 pad3C[0x64 - 0x3C];
    u8 *arr;
} Mgr_005FC4C0;
typedef struct {
    u8 pad0[0xB0];
    f32 fB0;
} View_005FC4C0;
extern Mgr_005FC4C0 D_L39_0025CEC0;
extern View_005FC4C0 D_L39_0025D6C0;
extern u8 D_L39_002412F1;
extern f32 D_L39_00242998;
extern f32 D_L39_0024299C;
extern Cam_005FC4C0 D_L39_0024DE80;
extern V_005FC4C0 D_L39_0024DEA0[];
extern void func_L39_005872D8(void);
extern void func_0013D5C0(V_005FC4C0 *);
extern void func_0013D708(V_005FC4C0 *, V_005FC4C0 *, f32);
extern void func_0013D7B0(V_005FC4C0 *, V_005FC4C0 *, f32);
extern void func_0013D660(V_005FC4C0 *, V_005FC4C0 *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_00384260(s32, void *, s32);
extern void func_L39_0057B060(s32);

s32 func_L39_005FC4C0(void) {
    V_005FC4C0 m[4];
    V_005FC4C0 t;
    u8 *e;
    V_005FC4C0 *rot;
    s32 r;
    f32 w;

    e = D_L39_0025CEC0.arr + D_L39_0025CEC0.idx * 32;
    rot = (V_005FC4C0 *)(e + 0x10);
    r = e[0xC];
    w = rot->w;
    D_L39_0025D6C0.fB0 = w;
    if (D_L39_002412F1 != 0) {
        D_L39_0025D6C0.fB0 = w * D_L39_00242998;
    }
    func_L39_005872D8();
    D_L39_0024DE80.pos = *(V_005FC4C0 *)e;
    func_0013D5C0(m);
    func_0013D708(m, m, rot->x);
    func_0013D7B0(m, m, rot->y);
    func_0013D660(m, m, rot->z);
    D_L39_0024DE80.rows[0].x = -m[2].x;
    D_L39_0024DE80.rows[1].x = -m[0].x;
    D_L39_0024DE80.rows[2].x = m[1].x;
    D_L39_0024DE80.rows[0].y = -m[2].y;
    D_L39_0024DE80.rows[1].y = -m[0].y;
    D_L39_0024DE80.rows[2].y = m[1].y;
    D_L39_0024DE80.rows[0].z = -m[2].z;
    D_L39_0024DE80.rows[1].z = -m[0].z;
    D_L39_0024DE80.rows[2].z = m[1].z;
    if (D_L39_002412F1 != 0 && D_L39_0024299C != 0.0f) {
        t = D_L39_0024DE80.rows[0];
        func_0038CF68(&t, &t, D_L39_0024299C);
        __asm__ __volatile__(
            "lqc2 $vf1, %0\n"
            "lqc2 $vf2, %1\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "+m"(D_L39_0024DE80.pos) : "m"(t));
    }
    func_00384260(0, &D_L39_0024DEA0[0], 0);
    func_00384260(0, &D_L39_0024DEA0[1], 1);
    func_00384260(0, &D_L39_0024DEA0[2], 2);
    func_L39_0057B060(0);
    return r;
}
/* localdecomp:end func_L39_005FC4C0 */

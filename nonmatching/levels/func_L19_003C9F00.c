/* func_L19_003C9F00: draft: 83 diff; needs -mvu0-use-vf0-vf2 @ps2as on L19_003C9F00.c and #include "vu0.h"; logic follows the asm. */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } V_3C9F00 __attribute__((aligned(16)));
typedef struct { V_3C9F00 v[4]; } R_3C9F00;
typedef struct { V_3C9F00 v[3]; } M_3C9F00;
typedef struct { u8 pad[0x30]; V_3C9F00 v; u8 pad2[0x40]; } P_3C9F00;
extern R_3C9F00 D_002BDEB0[];
extern R_3C9F00 D_002BDED0[];
extern R_3C9F00 D_002BDEC0[];
extern P_3C9F00 *D_001DF800;
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038D570(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);

void func_L19_003C9F00(V_3C9F00 *obj, s32 idx) {
    V_3C9F00 p0;
    V_3C9F00 p1;
    M_3C9F00 s20;
    V_3C9F00 e;
    V_3C9F00 d;
    V_3C9F00 t;
    V_3C9F00 r;
    s32 a;

    a = func_00382498(0, 5);
    switch (func_00382498(0, 3)) {
    case 0:
        p0 = D_002BDEB0[a].v[0];
        p1 = D_002BDEB0[a].v[1];
        break;
    case 1:
        p0 = D_002BDEB0[a].v[0];
        p1 = D_002BDEB0[a].v[2];
        break;
    case 2:
        p0 = D_002BDED0[a].v[0];
        p1 = D_002BDED0[a].v[1];
        break;
    case 3:
        p0 = D_002BDEC0[a].v[0];
        p1 = D_002BDEC0[a].v[2];
        break;
    }
    func_0038D570(&s20, (u8 *)D_001DF800 + (idx << 7));
    e = *(V_3C9F00 *)((u8 *)D_001DF800 + (idx << 7) + 0x30);
    e.w = 1.0f;
    vec_sub_ba(&t, &p1, &p0);
    d = t;
    func_0038CE20(&d, &d, func_003824E0(0.0f, 1.0f));
    vec_add_ab(&r, &p0, &d);
    *obj = r;
    t = r;
    func_0038D028(obj, obj, &s20);
}

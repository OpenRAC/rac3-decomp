/* functional: medium. Same calls, constants, shapes, colours and loop order as retail; vsub/vadd.xyz as plain float math; the 5-point transform loop runs i=0..4 as retail's bgez loop does; D_L01_001DC7BC/7C0 are the gp floats at gp-0xF4/-0xF0. Externs use vu0_v4 as the file's other C does. */
#include "vu0.h"
extern vu0_v4 D_L01_002AC1F0[];
extern u8 D_L01_00272340[];
extern vu0_v4 D_L01_001E1760;
extern f32 D_L01_001E176C;
extern f32 D_L01_001DC7BC;
extern f32 D_L01_001DC7A4;
extern f32 D_L01_001DC7C0;
typedef struct {
    u8 pad0[0x10];
    f32 f10;
} Vars_3163D0;
extern void func_003A9440(s32, unsigned long);
extern void func_L01_00316F50(s32 a0, f32 *e, s32 n);
extern void func_003CA4A0(void *, s32, void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_L01_00317948(u8 *obj, s32 a1, f32 *out, void *offs);
extern void func_L01_003173B0(s32 unused, s32 target, u32 color, s32 n, f32 scale);
extern void func_L01_00448340(void *, void *, void *, f32, f32, f32);
extern void func_L01_00317070(void *obj, vu0_v4 *a, vu0_v4 *b, u8 *shape);
extern void func_L01_00317238(u8 *object, vu0_v4 *center, f32 *out, f32 scale);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_0013D3E0(void);
extern void func_L01_003179F0(vu0_v4 *position, s32 count, f32 scale);

void func_L01_003163D0(u8 *obj) {
    Vars_3163D0 *vars;
    vu0_v4 q[5];
    vu0_v4 o[5];
    vu0_v4 mat[4];
    vu0_v4 vE0, vF0, v100, v110;
    s32 a124;
    s32 a120;
    s32 i;
    vu0_v4 *tgt;

    func_003A9440(0x47, 0x53001);
    vars = *(Vars_3163D0 **)(obj + 0x68);
    func_L01_00316F50((s32)obj, (f32 *)D_L01_00272340, 4);
    a120 = 0;
    func_003CA4A0(obj, 1, &a120, &mat[0]);
    mat[3].w = 1.0f;
    mat[3].x = 0.0f;
    mat[3].y = 0.0f;
    mat[3].z = 0.0f;
    ((f32 *)&D_L01_002AC1F0[1])[0] = -func_0038D098(D_L01_001DC7C0) * 0.01510000042617321f;
    ((f32 *)&D_L01_002AC1F0[1])[2] = func_0038D098(D_L01_001DC7BC) * 0.01489999983459711f;
    ((f32 *)&D_L01_002AC1F0[1])[1] = -(func_0038D0B0(D_L01_001DC7BC) * 0.014999999664723873f + 0.4000000059604645f);
    D_L01_001DC7BC = func_0038DAB8(D_L01_001DC7BC, 0.5026548504829407f);
    D_L01_001DC7C0 = func_0038DAB8(D_L01_001DC7C0, 0.4956735074520111f);
    for (i = 0; i < 5; i++) {
        func_0038D028(&o[i], &D_L01_002AC1F0[i], &mat[0]);
    }
    func_L01_00317948(obj, 0, (f32 *)&q[0], &o[0]);
    func_L01_003173B0((s32)obj, (s32)&q[0], 0x7F7F2020, 0x40, 0.10999999940395355f);
    func_L01_003173B0((s32)obj, (s32)&q[0], 0x7FFF4040, 0x78, 0.05000000074505806f);
    func_L01_00317948(obj, 0, (f32 *)&q[1], &o[1]);
    if (D_L01_001E176C == -1.0f) {
        D_L01_001E1760 = q[1];
        D_L01_001E176C = 0.0f;
    } else {
        a124 = 0;
        func_L01_00448340(&D_L01_001E1760, &q[1], &a124, 0.30000001192092896f, 0.24000000953674316f,
                          0.6000000238418579f);
    }
    func_L01_003173B0((s32)obj, (s32)&D_L01_001E1760, 0x7F00397F, 0x40, vars->f10 * 2.0f * 0.08249999582767487f);
    func_L01_003173B0((s32)obj, (s32)&D_L01_001E1760, 0x7F0072FF, 0x78, vars->f10 * 2.0f * 0.03750000149011612f);
    func_L01_00317948(obj, 1, (f32 *)&q[2], &o[2]);
    func_L01_003173B0((s32)obj, (s32)&q[2], 0x7F7F2020, 0x40, 0.054999999701976776f);
    func_L01_003173B0((s32)obj, (s32)&q[2], 0x7FFF4040, 0x78, 0.02500000037252903f);
    func_L01_00317948(obj, 2, (f32 *)&q[3], &o[3]);
    func_L01_003173B0((s32)obj, (s32)&q[3], 0x7F7F2020, 0x40, 0.054999999701976776f);
    func_L01_003173B0((s32)obj, (s32)&q[3], 0x7FFF4040, 0x78, 0.02500000037252903f);
    func_L01_00317948(obj, 3, (f32 *)&q[4], &o[4]);
    func_L01_003173B0((s32)obj, (s32)&q[4], 0x7F7F2020, 0x40, 0.054999999701976776f);
    func_L01_003173B0((s32)obj, (s32)&q[4], 0x7FFF4040, 0x78, 0.02500000037252903f);
    func_L01_00317070(obj, &q[0], &D_L01_001E1760, D_L01_00272340);
    func_L01_00317238(obj, &D_L01_001E1760, (f32 *)&vE0, vars->f10 * 0.3499999940395355f);

    for (i = 2; i <= 4; i++) {
        vF0.x = D_L01_001E1760.x - q[i].x;
        vF0.y = D_L01_001E1760.y - q[i].y;
        vF0.z = D_L01_001E1760.z - q[i].z;
        vF0.w = D_L01_001E1760.w;
        func_0038CF68(&vF0, &vF0, 1.0f);
        func_0038CE90(&vF0, &vF0, &vE0);
        func_0038CF68(&vF0, &vF0, 1.0f);
        func_0038CE90(&vF0, &vF0, &vE0);
        func_0038CF68(&vF0, &vF0, vars->f10 * 0.44999998807907104f);
        v100.x = vF0.x + D_L01_001E1760.x;
        v100.y = vF0.y + D_L01_001E1760.y;
        v100.z = vF0.z + D_L01_001E1760.z;
        v100.w = vF0.w;
        func_L01_00317070(obj, &q[i], &v100, D_L01_00272340 + (i - 1) * 0x80);
        func_L01_003173B0((s32)obj, (s32)&v100, 0x7F7F2020, 0x40, 0.054999999701976776f);
        func_L01_003173B0((s32)obj, (s32)&v100, 0x7FFF4040, 0x78, 0.02500000037252903f);
        if (func_0013D3E0() % 11 == 0 && D_L01_001DC7A4 < vars->f10) {
            func_L01_003179F0(&v100, 1, 0.0f);
        }
    }
    func_003C2F58(obj, 1, &v110);
    func_L01_00317070(obj, &v110, &q[2], D_L01_00272340 + 0x180);
    func_L01_003173B0((s32)obj, (s32)&v110, 0x7F7F2020, 0x40, 0.054999999701976776f);
    func_L01_003173B0((s32)obj, (s32)&v110, 0x7FFF4040, 0x78, 0.02500000037252903f);
    func_003C2F58(obj, 2, &v110);
    func_L01_00317070(obj, &v110, &q[3], D_L01_00272340 + 0x100);
    func_L01_003173B0((s32)obj, (s32)&v110, 0x7F7F2020, 0x40, 0.054999999701976776f);
    func_L01_003173B0((s32)obj, (s32)&v110, 0x7FFF4040, 0x78, 0.02500000037252903f);
    func_003C2F58(obj, 3, &v110);
    func_L01_00317070(obj, &v110, &q[4], D_L01_00272340 + 0x80);
    func_L01_003173B0((s32)obj, (s32)&v110, 0x7F7F2020, 0x40, 0.054999999701976776f);
    func_L01_003173B0((s32)obj, (s32)&v110, 0x7FFF4040, 0x78, 0.02500000037252903f);
    if (func_0013D3E0() % 11 == 0) {
        func_L01_003179F0(&q[1 + func_0013D3E0() % 4], 1, 0.0010000000474974513f);
    }
    func_003A9440(0x47, 0x5360B);
}

/* near miss (level 3, Starship Phoenix): 95 differences with -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as and a divs_nops-free file: structure matches (do-while over n, rand/spawn calls); the C hoists the address sp+0x30 of the up vector into $s5 (retail recomputes it in the loop and keeps the d vector in $s5), retail hoists the load of d[2] ($f22) into the loop pre-header, the C reloads it; also needs the sign as `if (s == 0) s--;` */
#include "common.h"
#include "vu0.h"
extern u8 D_L03_001E2440[];
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_0038D890(f32 *, f32 *, f32 *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046B458(u8 *pos, s32 id, s32 color, s32 mode, s32 b, f32 *v, s32 n, f32 sx, f32 sy, f32 z);
void func_L03_003C1280(f32 *p, s32 n) {
    f32 v[4];
    f32 pos[4];
    f32 d[4];
    f32 u[4];
    f32 a[4];
    f32 s;
    f32 r;
    s32 sign;
    s32 i;
    f32 z;
    u8 *e;
    vec_sub_ba(d, D_L03_001E2440, p);
    func_0038CF68(a, d, 0.3f);
    d[2] = 0.0f;
    u[0] = 0.0f;
    u[1] = 0.0f;
    u[2] = 1.0f;
    u[3] = 1.0f;
    if (n > 0) {
    z = d[2];
    i = n;
    do {
        r = func_003824E0(0.5f, 2.0f);
        sign = func_00382468(2);
        if (sign == 0) sign--;
        func_0038D890(v, d, u, func_003824E0(-1.0471976f, 1.0471976f));
        func_0038CF68(v, v, func_003824E0(0.05f, 3.0f) * 0.020000001f);
        v[2] = func_003824E0(1.0f, 5.0f) * 0.020000001f;
        vec_add_ba(pos, p, a);
        p[0] += func_L01_00443A18(d[2], 0.15f);
        p[1] += func_L01_00443A18(d[2], 0.15f);
        p[2] += func_L01_00443A18(d[2], 0.15f);
        e = func_L01_0046B458((u8 *)pos, 0x32, 0xDD10FFFF, 0, sign, v, 0, r * 0.1f, r, 0.00288000028f);
        if (e != 0) e[9] = 0x74;
        e = func_L01_0046B458((u8 *)pos, 0x32, 0xDD10FFFF, 1, -sign, v, 0, r * 0.07f, r * 0.7f, 0.00288000028f);
        if (e != 0) e[9] = 0x74;
    } while (--i);
    }
}

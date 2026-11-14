/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00357B20, the NTSC-U twin of func_L01_003586F8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -fno-sched-interblock" (src/levels/shared/L01_00356C88.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"

/* localdecomp:start func_L01_00357B20 */
#include "vu0.h"

typedef struct {
    u8 pad[0x16C];
    u8 *tbl;
} T_357B20;

extern u8 D_L01_001E2A40[];
extern u8 D_0014263F[];
extern u8 D_L01_002C5640[];
extern T_357B20 D_L01_00221118;
extern f32 func_00388A28(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L01_00357B20(f32 *a0) {
    f32 d[4] __attribute__((aligned(16)));
    f32 vel[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 angle;
    f32 r;
    f32 p;
    f32 t;
    s32 n;
    s32 life;
    s32 i;
    s32 k;
    s32 v;
    u8 *row;
    f32 size;
    u8 *e;

    vec_sub_ab(d, D_L01_001E2A40, a0);
    angle = func_00388A28(d[0], d[1]);
    k = 0;
    row = D_L01_002C5640 + D_0014263F[0] * 0xF0;
    v = row[1];
    if (v != 0 && v != 1) {
        if (v == 2 || v == 3) {
            k = 1;
        } else {
            k = v >= 4;
        }
    }
    for (i = 0; i < 3; i++) {
        r = func_0037E250(0.1f, 3.5f);
        life = func_0037E208(7, 15);
        n = func_L01_00440918(1.0f, 2.0f);
        size = func_0037E250(0.01f, 0.1f) * 210000.0f;
        p = func_0037E250(0.0f, 1.3962634f);
        t = func_00389380(angle, func_L01_00440918(0.0f, 1.3962634f));
        func_0037E4B8(vel, 0.016666668f * r, t, p);
        pos[0] = a0[0] + func_L01_00440918(0.0f, 0.3f);
        pos[1] = a0[1] + func_L01_00440918(0.0f, 0.3f);
        pos[2] = a0[2] + func_L01_00440918(0.0f, 0.3f);
        e = func_L01_00466F98(pos, vel, life, 0x7F, 0x7F7F7F, n, size, 500.0f, 1.0f, 0.0f, 2.0f);
        if (e != 0) {
            e[2] = D_L01_00221118.tbl[k];
        }
    }
}
/* localdecomp:end func_L01_00357B20 */

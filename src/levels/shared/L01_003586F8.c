#include "common.h"

/* localdecomp:start func_L01_003586F8 */
#include "vu0.h"

typedef struct {
    u8 pad[0x16C];
    u8 *tbl;
} T_357B20;

extern u8 D_L01_001E29C0[];
extern u8 D_0014263F[];
extern u8 D_L01_002C5600[];
extern T_357B20 D_L01_00221098;
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L01_003586F8(f32 *a0) {
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

    vec_sub_ab(d, D_L01_001E29C0, a0);
    angle = func_0038D160(d[0], d[1]);
    k = 0;
    row = D_L01_002C5600 + D_0014263F[0] * 0xF0;
    v = row[1];
    if (v != 0 && v != 1) {
        if (v == 2 || v == 3) {
            k = 1;
        } else {
            k = v >= 4;
        }
    }
    for (i = 0; i < 3; i++) {
        r = func_003824E0(0.1f, 3.5f);
        life = (func_00382498(7, 15) * 5 + 2) / 6;
        n = func_L01_00443A18(1.0f, 2.0f);
        size = func_003824E0(0.01f, 0.1f) * 210000.0f;
        p = func_003824E0(0.0f, 1.3962634f);
        t = func_0038DAB8(angle, func_L01_00443A18(0.0f, 1.3962634f));
        func_00382760(vel, 0.020000001f * r, t, p);
        pos[0] = a0[0] + func_L01_00443A18(0.0f, 0.3f);
        pos[1] = a0[1] + func_L01_00443A18(0.0f, 0.3f);
        pos[2] = a0[2] + func_L01_00443A18(0.0f, 0.3f);
        e = func_L01_0046A610(pos, vel, life, 0x7F, 0x7F7F7F, n, size, 500.0f, 1.0f, 0.0f, 2.0f);
        if (e != 0) {
            e[2] = D_L01_00221098.tbl[k];
        }
    }
}
/* localdecomp:end func_L01_003586F8 */

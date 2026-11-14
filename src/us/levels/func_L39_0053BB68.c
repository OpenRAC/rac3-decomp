#include "common.h"

/* NTSC-U counterpart of func_L39_0053C300 (src/levels/shared/L39_0053C300.c) */
extern void func_00388830(void *, void *, f32);
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L39_0053BB68 */
#include "vu0.h"

extern u8 *D_L39_00296918[];

extern f32 func_003BE7F0(void *, s32, s32, f32);
extern s32 func_L39_005BC958(void *, s32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B25C8_0053BB68(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L39_005CC260(void *, void *, s32, f32, f32, f32, u32, u32, s32);
extern u32 func_L01_0047D218(u32, u32, f32);
extern void func_00388830(void *, void *, f32);
extern u32 func_L01_00445C50(u32, s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L39_005C5838(void *, void *, u32, u32, f32, s32, s32, s32, s32, s32);

/* from rac1-decomp's mine detonation effect (mine_bomb_and_debris.c): cr/cg/cb colour locals, loop order */
void func_L39_0053BB68(u8 *a0) {
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 hit;
    f32 ground;
    f32 r;
    f32 ang;
    f32 size;
    s32 n1;
    s32 n2;
    s32 i;
    s32 j;
    u32 c1;
    u32 c2;
    s32 t;
    s32 cr;
    s32 cg;
    s32 cb;

    v10 = *(vu0_v4 *)(a0 + 0x10);
    v10.z += 3.5f;
    ground = func_003BE7F0(&v10, 0, 0, 0.5f);
    v20 = *(vu0_v4 *)(a0 + 0x10);
    v20.w = 1.0f;
    if (func_L39_005BC958(&v20, (s32)&hit, 64.0f) < 0) {
        return;
    }
    n1 = 100;
    n2 = 20;
    if (1024.0f <= hit.x) {
        n1 = 50;
        n2 = 5;
    }
    cr = 0x60;
    cg = 0x60;
    cb = 0x7F;
    for (i = 0; i < n1; i++) {
        *(vu0_q *)&v40 = 0;
        v40.x = func_L39_005B2510(-0.01250000111758709f, 0.01250000111758709f);
        v40.y = func_L39_005B2510(-0.01250000111758709f, 0.01250000111758709f);
        v40.z = func_L39_005B2510(0.06666667014360428f, 0.2666666805744171f);
        v30 = v40;
        r = func_L39_005B2510(0.0f, 0.35f);
        ang = func_L39_005B25C8_0053BB68();
        v40.x = func_00388960(ang) * r;
        v40.y = func_00388978(ang) * r;
        v40.z = 0.0f;
        vec_add_ba(&v40, &v40, a0 + 0x10);
        v40.z = ground + 0.5f;
        v30.z -= r * 0.01666666753590107f * 8.0f;
        func_L39_005CC260(&v40, &v30, 0, func_L39_005B2510(0.35f, 1.25f), ground, 0.0055555556900799274f, (0x16 << 24) | (cb << 16) | (cg << 8) | cr, (cb << 16) | (cg << 8) | cr, 1);
    }
    for (j = 0; j < n2; j++) {
        c1 = func_L01_0047D218(0x7F000000, (0x7F << 24) | (cb << 16) | (cg << 8) | cr, func_L39_005B2510(0.25f, 1.0f));
        c2 = func_L01_0047D218(0, ((cb / 2) << 16) | ((cg / 2) << 8) | (cr / 2), func_L39_005B2510(0.5f, 1.0f));
        v40.x = func_L39_005B2510(-3.0f, 3.0f);
        v40.y = func_L39_005B2510(-3.0f, 3.0f);
        v40.z = func_L39_005B2510(0.06666667014360428f, 0.23333334922790527f);
        func_00388830(&v40, &v40, func_L39_005B2510(1.5f, 3.0f) * 0.01666666753590107f);
        v40.z = func_L39_005B2510(3.0f, 6.0f) * 0.01666666753590107f;
        v30 = *(vu0_v4 *)(a0 + 0x10);
        v30.z = ground;
        c1 = func_L01_00445C50(c1, 0);
        c2 = func_L01_00445C50(c2, 0);
        size = func_L39_005B2510(31500.002f, 52500.0f);
        t = func_L39_005B24C8(0x5A, 0x96);
        func_L39_005C5838(&v30, &v40, c1, c2, size, t, 1, *D_L39_00296918[11], -1, 0);
    }
}
/* localdecomp:end func_L39_0053BB68 */

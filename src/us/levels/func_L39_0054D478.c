#include "common.h"

/* NTSC-U counterpart of func_L39_0054DD90 (src/levels/shared/L39_0054D5F8.c): 0.02 -> 0.0166667; 25 -> 30 */
#include "vu0.h"
extern void func_L39_0054D478(void *, u8 *);
#include "vu0.h"
extern s32 func_L39_005BC958(void *, s32, f32);
#include "vu0.h"

/* localdecomp:start func_L39_0054D478 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0054DD90;
typedef int Q_0054DD90 __attribute__((mode(TI)));

extern f32 D_L39_0024B1A0 __attribute__((section(".sdata")));
extern f32 D_L39_0024B1A4 __attribute__((section(".sdata")));
extern f32 D_L39_0024B1A8 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B1A0, 4");
__asm__(".extern D_L39_0024B1A4, 4");
__asm__(".extern D_L39_0024B1A8, 4");
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_L39_005BC958(void *, s32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L39_0054D478(void *pos, u8 *arg1) {
    V4_0054DD90 *arg0 = pos;
    V4_0054DD90 d;
    V4_0054DD90 s;
    V4_0054DD90 v;
    V4_0054DD90 pos;
    f32 res[4];
    f32 ang;
    f32 scale;
    f32 pitch;
    s32 n;
    f32 speed;
    s32 life;
    s32 i;
    f32 yaw;

    n = 15;
    vec_sub_ab(&d, arg1 + 0x23A0, arg0);
    ang = func_00388A28(d.x, d.y);
    *(Q_0054DD90 *)&s = *(Q_0054DD90 *)arg0;
    s.w = 0.5f;
    if (func_L39_005BC958(&s, (s32)res, D_L39_0024B1A8) > 0) {
        if (!(res[0] < D_L39_0024B1A0 * D_L39_0024B1A0)) {
            if (res[0] < D_L39_0024B1A4 * D_L39_0024B1A4) {
                n = 10;
            } else {
                n = 5;
            }
        }
    } else {
        n = 0;
    }
    for (i = 0; i < n; i++) {
        scale = func_L39_005B2510(0.5f, 1.0f);
        life = func_L39_005B2568(1.0f, 2.0f);
        speed = func_L39_005B2510(0.05f, 0.2f) * 210000.0f;
        pitch = func_L39_005B2510(0.0f, 1.3962634f);
        yaw = func_00389380(ang, func_L39_005B2568(0.0f, 1.3962634f));
        func_0037E4B8(&v, scale * 0.0166666675f, yaw, pitch);
        pos.x = arg0->x + func_L39_005B2568(0.0f, 0.1f);
        pos.y = arg0->y + func_L39_005B2568(0.0f, 0.1f);
        pos.z = arg0->z + func_L39_005B2568(0.0f, 0.1f);
        speed = func_L39_005B2510(0.05f, 0.2f) * 210000.0f;
        func_L01_00466F98(&pos, &v, 0x1E, 0x7F, 0x7F7F7F, life, speed, 500.0f, 1.0f, 0.0f, 0.0f);
    }
}
/* localdecomp:end func_L39_0054D478 */

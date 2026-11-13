#include "common.h"

/* localdecomp:start func_L39_00645780 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0xA0];
    f32 x;
    f32 y;
    u8 padA8[0x2C0 - 0xA8];
    f32 z;
} Obj_L39_00645780;

typedef union {
    s128 q;
    f32 f[4];
} Vec_L39_00645780;

extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B25C8_00645780(void);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00465410(f32 *, f32 *, s32, s32);
extern void func_L01_00301508(void *, s32, f32, f32);
extern void func_L39_005CA760(void *, f32 *, s32, f32, f32);

void func_L39_00645780(Obj_L39_00645780 *obj, s32 n1, s32 n2, s32 flag) {
    Vec_L39_00645780 v;
    f32 p2[4];
    s32 i;
    s32 j;

    if (flag) {
        v.q = *(s128 *)&obj->x;
        v.f[2] = obj->z;
        func_L01_00301508(&v, 3, 2.25f, 1.025f);
    }
    for (i = 0; i < n1; i++) {
        v.f[0] = obj->x + func_L39_005B2510(-0.3f, 0.3f);
        v.f[1] = obj->y + func_L39_005B2510(-0.3f, 0.3f);
        v.f[2] = obj->z;
        func_L39_005CA760(&v, &obj->z, -1, func_L39_005B2510(0.3f, 0.6f), 5250.0f);
    }
    for (j = 0; j < n2; j++) {
        f32 angle = func_L39_005B25C8_00645780();
        f32 r = func_L39_005B2510(0.0f, 0.0500000045f);
        s32 k;
        s32 life;

        v.f[0] = func_00388960(angle) * r;
        v.f[1] = func_00388978(angle) * r;
        v.f[2] = func_L39_005B2510(0.0500000045f, 0.133333340f);
        p2[0] = obj->x + v.f[0] * 8.0f;
        p2[1] = obj->y + v.f[0] * 8.0f;
        p2[2] = obj->z - func_L39_005B2510(0.0f, 0.2f);
        k = func_L39_005B2498(2);
        life = func_L39_005B24C8(90, 120);
        func_L01_00465410(p2, v.f, k, life);
    }
}
/* localdecomp:end func_L39_00645780 */

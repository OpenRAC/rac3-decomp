#include "common.h"

typedef struct Obj_003A2C98 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0xC];
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 pad34[0x20];
    f32 f54;
    f32 f58;
    u8 pad5C[4];
    f32 f60[1];
} Obj_003A2C98;

INCLUDE_ASM("asm/levels", func_L02_003A28A8);

INCLUDE_ASM("asm/levels", func_L02_003A29D0);

/* localdecomp:start func_L02_003A2C98 */
extern f32 D_L02_001DC968[];
extern f32 D_L02_001DC988[];
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

extern f32 D_001D5324;
__asm__(".extern D_001D5324, 16");
void func_L02_003A2C98(s32 a0, Obj_003A2C98 *obj) {
    f32 *tbl;
    f32 *p;
    s32 i;
    f32 zero;
    f32 fx;
    f32 fy;
    f32 a;

    if (obj->f10 != 0) {
        s32 n = obj->f14;
        tbl = D_L02_001DC988;
        if (n >= 3) {
            goto done;
        }
    }
    tbl = D_L02_001DC968;
done:
    for (i = 0; i < obj->f14; i++, tbl += 2) {
        p = &obj->f60[i * 2];
        a = D_001D5324 * obj->f24;
        {
            f32 x = p[0] + tbl[0] * a;
            f32 y = p[1] + tbl[1] * a;
            fy = y - (f32)(s32)y;
            fx = x - (f32)(s32)x;
        }
        p[1] = fy;
        p[0] = fx;
        if (obj->f54 != 0.0f || obj->f58 != 0.0f) {
            f32 x = fx + obj->f54;
            f32 y = fy + obj->f58;
            p[0] = x - (f32)(s32)x;
            p[1] = y - (f32)(s32)y;
        }
        if (obj->f28 != 0.0f) {
            f32 x, y, s, nx, ny, t;
            t = func_0038DAB8(obj->f30, obj->f2C);
            obj->f30 = t;
            a = t;
            if (i & 1) {
                a = -a;
            }
            s = func_0038D098(a);
            x = tbl[0];
            x *= obj->f28;
            x *= s;
            s = func_0038D0B0(a);
            y = tbl[1];
            y *= obj->f28;
            y *= s;
            nx = p[0] + x;
            ny = p[1] + y;
            p[0] = nx - (f32)(s32)nx;
            p[1] = ny - (f32)(s32)ny;
        }
    }
}
/* localdecomp:end func_L02_003A2C98 */

INCLUDE_ASM("asm/levels", func_L02_003A2EC8);

/* localdecomp:start func_L02_003A3878 */
s32 func_L02_003A3878(u8 *a0) {
    s32 r = 0;
    if (a0[3] & 0x80) {
        r = *(s32 *)(a0 + 92) == 0;
    }
    return r;
}
/* localdecomp:end func_L02_003A3878 */

INCLUDE_ASM("asm/levels", func_L02_003A3898);

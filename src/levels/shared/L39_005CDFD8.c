#include "common.h"
#include "vu0.h"

/* declared by functions of L39_005CDCF0.c, which this file was cut from */
extern s32 func_0038CB00(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003CD250(u8 *);

/* localdecomp:start func_L39_005CDFD8 */
#include "vu0.h"
extern s32 func_0038CB00(void *);
extern void func_003CD250(u8 *);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L39_005CDFD8(u8 *p) {
    vu0_v4 v;
    vu0_v4 g;
    u8 *q = p + 0x20;
    s32 life;

    v.w = 0.0f;
    v.x = *(f32 *)(p + 0x20);
    v.y = *(f32 *)(q + 4);
    v.z = *(f32 *)(q + 8);
    if (*(s32 *)(q + 0x1C) == 1) {
        vu0_v4 *src = *(vu0_v4 **)(q + 0xC);

        qzero(&g);
        if (src != 0) {
            g = src[1];
        }
        *(f32 *)(p + 0x10) = g.x + *(f32 *)(q + 0x10);
        *(f32 *)(p + 0x14) = g.y + *(f32 *)(q + 0x14);
        *(f32 *)(p + 0x18) = g.z + *(f32 *)(q + 0x18);
        vec_add_ab(p + 0x10, p + 0x10, &v);
        *(f32 *)(q + 0x10) = *(f32 *)(p + 0x10) - g.x;
        *(f32 *)(q + 0x14) = *(f32 *)(p + 0x14) - g.y;
        *(f32 *)(q + 0x18) = *(f32 *)(p + 0x18) - g.z;
    } else {
        vec_add_ab(p + 0x10, p + 0x10, &v);
    }
    if (*(f32 *)(p + 0x10) < 2.0f || 1021.0f < *(f32 *)(p + 0x10) ||
        *(f32 *)(p + 0x14) < 2.0f || 1021.0f < *(f32 *)(p + 0x14) ||
        *(f32 *)(p + 0x18) < 2.0f || 1021.0f < *(f32 *)(p + 0x18) ||
        func_0038CB00(p + 0xA) != 0) {
        func_003CD250(p);
        return;
    }
    life = *(s16 *)(p + 0xA);
    if (life < 250) {
        *(s32 *)(p + 4) = func_0038DBD8(*(s32 *)(p + 4) & 0xFFFFFF, *(s32 *)(p + 4), (f32)(life - 1) / (f32)life);
    }
}
/* localdecomp:end func_L39_005CDFD8 */

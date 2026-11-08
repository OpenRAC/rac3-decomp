#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00646980);

INCLUDE_ASM("asm/levels", func_L39_00646B98);

INCLUDE_ASM("asm/levels", func_L39_00647150);

/* localdecomp:start func_L39_006472D0 */
typedef struct { u8 p0[0x20]; u8 b20; } M_00644AA0;
typedef struct {
    u8 p0[0x3E0]; M_00644AA0 *m3E0;
    u8 p3E4[0x24E8 - 0x3E4]; void *r24E8;
    u8 p24EC[0x2544 - 0x24EC]; s32 w2544; s32 w2548;
} O_00644AA0;

extern s32 D_L39_0024112C;
extern f32 *func_00382348(M_00644AA0 *);
extern void *func_L39_005BB950(s32, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32);

void *func_L39_006472D0(O_00644AA0 *o, s32 a1, s32 a2, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, s32 a3) {
    u8 buf[16];
    M_00644AA0 *m;
    f32 *v;

    if (o->w2544 % 2 != D_L39_0024112C % 2) {
        return o->r24E8;
    }
    m = o->m3E0;
    if (m != 0 && m->b20 != 254 && m->b20 != 253) {
        v = func_00382348(m);
        if (v != 0 && *v > 0.0f) {
            return o->m3E0;
        }
    }
    o->r24E8 = func_L39_005BB950(a1, a2, o->w2548, buf, 0, 0, 0, f0, f1, f2, f3, f4, a3, 0, 1);
    return o->r24E8;
}
/* localdecomp:end func_L39_006472D0 */

INCLUDE_ASM("asm/levels", func_L39_00647430);

/* localdecomp:start func_L39_00647588 */
extern f32 func_0038CEA8();

f32 func_L39_00647588(s32 a, s32 b) {
    f32 r = func_0038CEA8(b);
    if (1.0f < r) {
        r = 1.0f;
    }
    return r;
}
/* localdecomp:end func_L39_00647588 */

INCLUDE_ASM("asm/levels", func_L39_006475C0);

INCLUDE_ASM("asm/levels", func_L39_00647730);

/* localdecomp:start func_L39_00647A20 */
typedef struct {
    s32 ids[8];
} IdList;

extern IdList D_L39_00246090;
extern s32 func_L39_00672208(s32);

s32 func_L39_00647A20(void) {
    IdList list = D_L39_00246090;
    s32 *p = list.ids;
    s32 i;
    s32 ret = 10;

    for (i = 0; i < 8; i++) {
        if (func_L39_00672208(*p) != 0) {
            ret = *p;
            break;
        }
        p++;
    }
    return ret;
}
/* localdecomp:end func_L39_00647A20 */

INCLUDE_ASM("asm/levels", func_L39_00647AD0);

INCLUDE_ASM("asm/levels", func_L39_00647C48);

/* localdecomp:start func_L39_00647E10 */
extern f32 func_L39_005B4410(f32 a, f32 b);
extern f32 func_L39_005B44C8(void);
extern f32 func_0038D098(f32 a);
extern f32 func_0038D0B0(f32 a);
extern s32 func_L39_005B43C8(s32 a, s32 b);
extern void *func_L01_00468A68(void *a, void *b, s32 c, s32 d);
extern s32 func_L39_005B4398(s32 a);

void func_L39_00647E10(u8 *state, s32 period, s32 threshold) {
    f32 position[4];
    f32 velocity[4];
    f32 angle;
    f32 radius;
    s32 lifetime;
    s32 c = *(s32 *)(state + 0x358) + 1;
    *(s32 *)(state + 0x358) = c;
    if (threshold < c) {
        position[0] = *(f32 *)(state + 0xA0) + func_L39_005B4410(-0.15f, 0.15f) + *(f32 *)(state + 0x140) * 8.0f;
        position[1] = *(f32 *)(state + 0xA4) + func_L39_005B4410(-0.15f, 0.15f) + *(f32 *)(state + 0x144) * 8.0f;
        position[2] = *(f32 *)(state + 0x2C0) + 0.1f;
        angle = func_L39_005B44C8();
        radius = func_L39_005B4410(0.0f, 0.060000002f);
        velocity[0] = func_0038D098(angle) * radius + *(f32 *)(state + 0x140) * 0.75f;
        velocity[1] = func_0038D0B0(angle) * radius + *(f32 *)(state + 0x144) * 0.75f;
        velocity[2] = func_L39_005B4410(0.060000002f, 0.13000001f);
        lifetime = func_L39_005B43C8(90, 120);
        if (*(f32 *)(state + 0x2C0) - *(f32 *)(state + 0xA8) < 0.25f) {
            func_L01_00468A68(position, velocity, 3, lifetime);
        } else {
            func_L01_00468A68(position, velocity, 1, lifetime);
        }
        *(s32 *)(state + 0x358) = func_L39_005B4398(period);
    }
}
/* localdecomp:end func_L39_00647E10 */

INCLUDE_ASM("asm/levels", func_L39_00647FE0);

INCLUDE_ASM("asm/levels", func_L39_006481F8);

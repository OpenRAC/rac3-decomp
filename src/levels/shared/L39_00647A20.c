#include "common.h"

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

/* localdecomp:start func_L39_00647AD0 */
extern s32 D_001DA9A0_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DA9A0_sda, 8");
extern s32 func_L39_005B4398(s32);
extern void func_L39_00673540(void *, s32, s32);
extern void func_L39_00673A80(void *, s32);
extern s32 func_L39_00647A20(void);

void func_L39_00647AD0(u8 *o, s32 want) {
    s32 i;
    s32 n;
    s32 count;
    s32 t;
    s32 j;

    n = func_L39_005B4398(4) + 3;
    for (i = 0; i < n; i++) {
        t = D_001DA9A0_sda[i];
        if (i < 3) {
            j = func_L39_005B4398(5) + 3;
        } else {
            j = func_L39_005B4398(8);
        }
        D_001DA9A0_sda[i] = D_001DA9A0_sda[j];
        D_001DA9A0_sda[j] = t;
    }
    count = 0;
    for (i = 0; i < 8; i++) {
        if (func_L39_00672208(D_001DA9A0_sda[i]) != 0) {
            u8 *g = o + 0x1A40;
            func_L39_00673540(g, D_001DA9A0_sda[i], 1);
            if (count == 0 || D_001DA9A0_sda[i] == 1) {
                func_L39_00673A80(g, D_001DA9A0_sda[i]);
            }
            count++;
            if (count == want) {
                break;
            }
        }
    }
    if (count == 0) {
        u8 *g = o + 0x1A40;
        s32 id = ((s32 (*)(void *))func_L39_00647A20)(o);
        func_L39_00673540(g, id, 1);
        func_L39_00673A80(g, id);
    }
}
/* localdecomp:end func_L39_00647AD0 */

/* localdecomp:start func_L39_00647C48 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);
extern void func_L01_0046ABC0(void *, void *, void *, f32, f32);

void func_L39_00647C48(u8 *state, s32 period, s32 threshold) {
    f32 vel[4];
    f32 pos[4];
    f32 angle;
    s32 i;
    s32 c = *(s32 *)(state + 0x354) + 1;
    *(s32 *)(state + 0x354) = c;
    if (threshold < c) {
        for (i = 0; i < 2; i++) {
            if (i == 0) {
                angle = func_0038DAB8(*(f32 *)(state + 0xB8), 0.785398006f);
            } else {
                angle = func_0038DB00(*(f32 *)(state + 0xB8), 0.785398006f);
            }
            vel[0] = func_0038D098(angle) * 0.012000001f;
            vel[1] = func_0038D0B0(angle) * 0.012000001f;
            pos[0] = *(f32 *)(state + 0xA0) + vel[0] * 18.0f;
            pos[1] = *(f32 *)(state + 0xA4) + vel[1] * 18.0f;
            pos[2] = *(f32 *)(state + 0x2C0);
            vel[2] = 0;
            vel[0] -= func_0038D098(*(f32 *)(state + 0xB8)) * 0.030000001f;
            vel[1] -= func_0038D0B0(*(f32 *)(state + 0xB8)) * 0.030000001f;
            func_L01_0046ABC0(pos, vel, state + 0x2C0, func_L39_005B4410(0.4f, 0.5f), i == 0 ? 2.0f : -2.0f);
            if (period != 0) {
                *(s32 *)(state + 0x354) = func_L39_005B4398(period);
            } else {
                *(s32 *)(state + 0x354) = 0;
            }
        }
    }
}
/* localdecomp:end func_L39_00647C48 */

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

/* localdecomp:start func_L39_00647FE0 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L01_003016B0(void *, s32, f32, f32);
extern u8 *func_L39_005CCB70(void *, s32, s32, f32, f32);

void func_L39_00647FE0(u8 *o, s32 n1, s32 n2, s32 flag) {
    f32 vel[4];
    f32 pos[4];
    f32 angle, r;
    s32 cnt;
    s32 life;
    if (flag != 0) {
        *(u128_t *)vel = *(u128_t *)(o + 0xA0);
        vel[2] = *(f32 *)(o + 0x2C0);
        func_L01_003016B0(vel, 3, 2.25f, 1.025f);
    }
    if (n1 > 0) do {
        n1--;
        vel[0] = *(f32 *)(o + 0xA0) + func_L39_005B4410(-0.3f, 0.3f);
        vel[1] = *(f32 *)(o + 0xA4) + func_L39_005B4410(-0.3f, 0.3f);
        vel[2] = *(f32 *)(o + 0x2C0);
        func_L39_005CCB70(vel, (s32)(o + 0x2C0), -1, func_L39_005B4410(0.3f, 0.6f), 5250.0f);
    } while (n1 != 0);
    if (n2 > 0) do {
        n2--;
        angle = func_L39_005B44C8();
        r = func_L39_005B4410(0.0f, 0.060000002f);
        vel[0] = func_0038D098(angle) * r;
        vel[1] = func_0038D0B0(angle) * r;
        vel[2] = func_L39_005B4410(0.060000002f, 0.16000001f);
        pos[0] = *(f32 *)(o + 0xA0) + vel[0] * 8.0f;
        pos[1] = *(f32 *)(o + 0xA4) + vel[0] * 8.0f;
        pos[2] = *(f32 *)(o + 0x2C0) - func_L39_005B4410(0.0f, 0.2f);
        cnt = func_L39_005B4398(2);
        life = func_L39_005B43C8(90, 120);
        func_L01_00468A68(pos, vel, cnt, life);
    } while (n2 != 0);
}
/* localdecomp:end func_L39_00647FE0 */

/* localdecomp:start func_L39_006481F8 */
typedef struct {
    u8 p0[0x128]; s32 w128; u8 p12C[0x170 - 0x12C]; s32 w170;
    u8 p174[0x6AD - 0x174]; u8 b6AD[0x7B0 - 0x6AD]; s32 w7B0[1];
} G_006481F8;
extern G_006481F8 D_1A5CD0;

s32 func_L39_006481F8(u8 *a) {
    G_006481F8 *g = &D_1A5CD0;
    s32 r = 0;

    if (g->w170 != 0) {
        return 1;
    }
    if (a != 0) {
        r = 1;
        if (a[0x1A14] == 0) {
            s32 *p = *(s32 **)(a + 0x2558);
            s32 t = g->w128;
            u8 idx = g->b6AD[*p];
            t -= g->w7B0[idx];
            r = t < 0x7E;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006481F8 */

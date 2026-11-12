#include "common.h"

/* localdecomp:start func_L39_00646980 */
extern u8 D_L39_004997E0[];

void func_L39_00646980(u8 *o) {
    u32 buf[2];
    s32 x;
    s32 y;
    s32 z;
    f32 fv;

    if (*(s32 *)(o + 0x1310) == 1) {
        *(f32 *)(o + 0x132C) = 2.0f;
        return;
    }
    {
        u8 *p = o + 0x19E4;
        u8 *b;
        s32 m;
        s32 k;
        s32 n;
        s32 i;
        long t;

        t = *p;
        if (t == 0) {
            x = 0;
        } else {
            n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x = buf[1];
        }
    }
    if ((x ^ 4) != 0) {
        u8 *p = o + 0x19E4;
        u8 *b;
        s32 m;
        s32 k;
        s32 n;
        s32 i;
        long t;

        y = 0;
        t = *p;
        if (t != 0) {
            n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            y = buf[1];
        }
        if ((y ^ 0x15) != 0) {
            goto L_chk;
        }
    }
    if (*(s32 *)(o + 0x1310) == 2) {
        goto L_six;
    }
L_chk:
    if (o[0x24FD] != 0) {
L_six:
        fv = 0.6f;
    } else {
        fv = 1.15f;
    }
    *(f32 *)(o + 0x132C) = fv;
    {
        u8 *p = o + 0x19E6;
        u8 *b;
        s32 m;
        s32 k;
        s32 n;
        s32 i;
        long t;

        t = *p;
        if (t == 0) {
            z = 0;
        } else {
            n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            z = buf[1];
        }
    }
    if ((z ^ 3) == 0) {
        *(f32 *)(o + 0x132C) = 1.75f;
    }
}
/* localdecomp:end func_L39_00646980 */

INCLUDE_ASM("asm/levels", func_L39_00646B98);

/* localdecomp:start func_L39_00647150 */
#include "vu0.h"

typedef struct { u8 pad[0xA4]; u8 flags[0x100]; } Tab_00647150;
extern Tab_00647150 D_001A5810;
extern void func_0038CF68(void *, s32, f32);

void func_L39_00647150(u8 *o, s32 mode) {
    if (mode == 0) {
        D_001A5810.flags[*(s32 *)(o + 0x2544)] = 0;
        qzero(o + 0x1260);
        qzero(o + 0x1270);
        *(f32 *)(o + 0x132C) = 1.15f;
        *(u16 *)(o + 0x1280) |= 1;
        *(f32 *)(o + 0x1254) = 1.5533431f;
        *(f32 *)(o + 0x1258) = -1.5533431f;
        *(s32 *)(o + 0x1310) = 0;
        *(u16 *)(o + 0x3E4) = 0;
    } else {
        func_0038CF68(o + 0x1190, *(s32 *)(o + 0x2530) + 0x380, 1.0f);
        qzero(o + 0x1260);
        qzero(o + 0x1270);
        *(u16 *)(o + 0x1280) &= 0xFFFE;
        switch (mode) {
        case 2: {
            f32 p = 1.5533431f;
            f32 n = -1.5533431f;
            f32 c = 1.15f;
            D_001A5810.flags[*(s32 *)(o + 0x2544)] = mode;
            *(s32 *)(o + 0x1310) = mode;
            *(f32 *)(o + 0x1254) = p;
            *(f32 *)(o + 0x1258) = n;
            *(f32 *)(o + 0x132C) = c;
            break;
        }
        case 1: {
            f32 a = -6.0f;
            f32 b = 6.0f;
            f32 c = 1.2217305f;
            f32 e = -1.2217305f;
            f32 g = 2.0f;
            D_001A5810.flags[*(s32 *)(o + 0x2544)] = mode;
            *(f32 *)(o + 0x132C) = g;
            *(s32 *)(o + 0x1310) = mode;
            *(f32 *)(o + 0x1260) = a;
            *(f32 *)(o + 0x12C4) = b;
            *(f32 *)(o + 0x1254) = c;
            *(f32 *)(o + 0x1258) = e;
            *(s32 *)(o + 0x1268) = 0;
            break;
        }
        }
    }
}
/* localdecomp:end func_L39_00647150 */

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

/* localdecomp:start func_L39_006475C0 */
typedef struct { u8 p0[0x180]; s32 w180; u8 p184[0x18F - 0x184]; s8 b18F; } G_006475C0;

extern s32 D_L39_002412DC;
__asm__(".extern D_L39_00241640, 16");
extern G_006475C0 *D_L39_00241640;
extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648960(void *, s32);
extern void func_L39_00648A20(void *, s32, s32);

void func_L39_006475C0(void *o) {
    if (func_L39_00648840(o, 0) == 0) {
        func_L39_00648960(o, 0);
        return;
    }
    if (func_L39_00648840(o, 2) == 0 && func_L39_00648840(o, 3) == 0) {
        func_L39_00648A20(o, 2, 3);
        return;
    }
    if (func_L39_00648840(o, 1) == 0) {
        func_L39_00648960(o, 1);
        return;
    }
    if (func_L39_00648840(o, 4) == 0 && D_L39_00241640->b18F != 0) {
        func_L39_00648960(o, 4);
        return;
    }
    if (D_L39_002412DC % 10 < 6) {
        if (func_L39_00648840(o, 5) == 0 && D_L39_00241640->w180 != 2) {
            func_L39_00648960(o, 5);
            return;
        }
    }
    if (D_L39_002412DC % 10 < 6) {
        if (func_L39_00648840(o, 20) == 0 && D_L39_00241640->w180 != 2) {
            func_L39_00648960(o, 20);
        }
    }
}
/* localdecomp:end func_L39_006475C0 */

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

INCLUDE_ASM("asm/levels", func_L39_00647FE0);

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

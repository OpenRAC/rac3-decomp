#include "common.h"

/* declared by functions of L39_00537998.c, which this file was cut from */
extern void func_L39_005FE358(u8 *, u8 *, void *, s32, f32);
extern u8 *D_L39_0024BF5C;
extern void func_0038CF68(void *, void *, f32);

/* declared by functions of L39_0053C2A0.c, which this file was cut from */
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L39_0053C300 */
#include "vu0.h"

extern u8 *D_L39_00296818[];

extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_L39_005BE900(void *, s32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L39_005CE670(void *, void *, s32, f32, f32, f32, u32, u32, s32);
extern u32 func_L01_00480A78(u32, u32, f32);
extern void func_0038CF68(void *, void *, f32);
extern u32 func_L01_00448D88(u32, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_005C7B40(void *, void *, u32, u32, f32, s32, s32, s32, s32, s32);

/* from rac1-decomp's mine detonation effect (mine_bomb_and_debris.c): cr/cg/cb colour locals, loop order */
void func_L39_0053C300(u8 *a0) {
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
    ground = func_003C3D30(&v10, 0, 0, 0.5f);
    v20 = *(vu0_v4 *)(a0 + 0x10);
    v20.w = 1.0f;
    if (func_L39_005BE900(&v20, (s32)&hit, 64.0f) < 0) {
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
        v40.x = func_L39_005B4410(-0.015000001f, 0.015000001f);
        v40.y = func_L39_005B4410(-0.015000001f, 0.015000001f);
        v40.z = func_L39_005B4410(0.080000006f, 0.32000002f);
        v30 = v40;
        r = func_L39_005B4410(0.0f, 0.35f);
        ang = func_L39_005B44C8();
        v40.x = func_0038D098(ang) * r;
        v40.y = func_0038D0B0(ang) * r;
        v40.z = 0.0f;
        vec_add_ba(&v40, &v40, a0 + 0x10);
        v40.z = ground + 0.5f;
        v30.z -= r * 0.020000001f * 8.0f;
        func_L39_005CE670(&v40, &v30, 0, func_L39_005B4410(0.35f, 1.25f), ground, 0.008f, (0x16 << 24) | (cb << 16) | (cg << 8) | cr, (cb << 16) | (cg << 8) | cr, 1);
    }
    for (j = 0; j < n2; j++) {
        c1 = func_L01_00480A78(0x7F000000, (0x7F << 24) | (cb << 16) | (cg << 8) | cr, func_L39_005B4410(0.25f, 1.0f));
        c2 = func_L01_00480A78(0, ((cb / 2) << 16) | ((cg / 2) << 8) | (cr / 2), func_L39_005B4410(0.5f, 1.0f));
        v40.x = func_L39_005B4410(-3.0f, 3.0f);
        v40.y = func_L39_005B4410(-3.0f, 3.0f);
        v40.z = func_L39_005B4410(0.080000006f, 0.28000003f);
        func_0038CF68(&v40, &v40, func_L39_005B4410(1.5f, 3.0f) * 0.020000001f);
        v40.z = func_L39_005B4410(3.0f, 6.0f) * 0.020000001f;
        v30 = *(vu0_v4 *)(a0 + 0x10);
        v30.z = ground;
        c1 = func_L01_00448D88(c1, 0);
        c2 = func_L01_00448D88(c2, 0);
        size = func_L39_005B4410(31500.002f, 52500.0f);
        t = func_L39_005B43C8(0x4B, 0x7D);
        func_L39_005C7B40(&v30, &v40, c1, c2, size, t, 1, *D_L39_00296818[11], -1, 0);
    }
}
/* localdecomp:end func_L39_0053C300 */

/* localdecomp:start func_L39_0053C758 */
#include "vu0.h"

typedef int q_0053C758 __attribute__((mode(TI)));

typedef struct V_0053C758 {
    f32 x, y, z, w;
} V_0053C758;

typedef struct O_0053C758 {
    u8 pad0[0x20];
    V_0053C758 v20;
    u8 pad30[0xA0 - 0x30];
    V_0053C758 vA0;
    u8 padB0[0x2F0 - 0xB0];
    s32 w2F0;
    u8 pad2F4[0x30C - 0x2F4];
    s32 w30C;
    u8 pad310[0x460 - 0x310];
    s32 w460;
    u8 pad464[0x730 - 0x464];
    q_0053C758 q730;
    u8 pad740[0x18F0 - 0x740];
    union {
        q_0053C758 q;
        f32 f;
    } u18F0;
    u8 pad1900[0x19E4 - 0x1900];
    u8 b19E4;
    u8 pad19E5[0x1A07 - 0x19E5];
    u8 b1A07;
    u8 pad1A08[0x1A0D - 0x1A08];
    u8 b1A0D;
    u8 pad1A0E[0x1A14 - 0x1A0E];
    u8 b1A14;
    u8 pad1A15[0x1A40 - 0x1A15];
    u8 b1A40[0x2470 - 0x1A40];
    s32 w2470;
    u8 pad2474[0x24FF - 0x2474];
    u8 b24FF;
    u8 pad2500[0x2534 - 0x2500];
    s32 w2534;
    u8 pad2538[0x2544 - 0x2538];
    s32 w2544;
} O_0053C758;

typedef struct M_0053C758 {
    q_0053C758 q0;
    V_0053C758 v10;
    V_0053C758 v20;
    V_0053C758 v30;
    s32 w40;
    s32 w44;
    s32 w48;
    u8 pad4C[0x50 - 0x4C];
    O_0053C758 *o;
    u8 pad54[0x58 - 0x54];
    s32 w58;
} M_0053C758;

typedef struct S_0053C758 {
    u8 pad0[0x3C];
    f32 x, y, z;
    u8 pad48[0x50 - 0x48];
} S_0053C758;

typedef union Buf_0053C758 {
    u8 b[8];
    u32 w[2];
} Buf_0053C758;

extern u8 D_L39_004997E0[];
extern u8 D_L39_0025F760[];
extern V_0053C758 D_L39_0024ADD0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024ADD0, 4");
extern V_0053C758 D_L39_0024ADE0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024ADE0, 4");

extern void func_L39_0061C4D0(u8 *, u8 **);
extern void func_0038D028(void *, void *, void *);
extern void func_L39_005FE6A0(O_0053C758 *, V_0053C758 *, void *, s32, s32, f32, f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_L39_006732D0(void *p, s32 a1, s32 a2, s32 a3);
extern s32 func_L39_00554DD8(s32 arg0);
extern s32 func_L39_005C2F50(s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_00621D60(void *, s32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040E790(f32 *, f32 *, f32 *);
extern void func_L39_00620E28(void *, s32, s32);
extern u8 *func_L39_00552750(s32 a0, u8 *a1, u8 *a2, u8 *a3, s32 a4, f32 a5);
extern void func_L39_00632180(u8 *, f32 *, s32, f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L39_005FED60(u8 *, f32, u8 *, u8 *, u8 *, u8 *, s32, s32, s32, s32, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L39_0053CEC0(u8 *a0);

static __inline__ u32 decode_0053C758(u8 *p) {
    Buf_0053C758 buf;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)p;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

void func_L39_0053C758(u8 *a0) {
    M_0053C758 *m;
    O_0053C758 *o;
    s32 res;
    s32 flag;
    s32 r;
    V_0053C758 pos;
    u8 net;
    s32 kind;

    kind = 0;
    m = *(M_0053C758 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        func_L39_0061C4D0(a0, (u8 **)&m->o);
    }
    o = m->o;
    func_0038D028(&pos, &D_L39_0024ADD0, &o->v20);
    vec_add_ab(&pos, &pos, &o->vA0);
    func_L39_005FE6A0(o, &m->v20, &pos, 0, 0, 1.5f,
                      (decode_0053C758(&o->b19E4) ^ 0x1D) == 0 ? 8.0f : 5.0f, 0.020000001f * 6.0f, 0.0048f);
    if ((decode_0053C758(&o->b19E4) ^ 0x1D) == 0) {
        func_0038CAD0(&o->w2470);
    } else {
        o->w2470 = 0x21;
    }
    switch (a0[0x20]) {
    case 0:
        a0[0x20] = 1;
        m->w48 = 1;
        m->w44 = 0;
        o->b1A0D = 0;
    case 1: {
        S_0053C758 s;

        res = func_L39_006732D0(o->b1A40, 0, 1, (s32)&s);
        if (res == 8) {
            V_0053C758 *v = &m->v30;
            v->x = s.x;
            v->y = s.y;
            v->z = s.z;
            v->w = 0.0f;
        }
        if (func_L39_00554DD8(o->w2544) != 0 || m->w48 == 0) {
            o->b1A0D = 1;
        } else if (o->b1A07 == 0) {
            o->b1A0D = 0;
        }
        if (o->b1A14 != 0 && o->b1A0D != 0 && (func_L39_005C2F50(o->w2534) & o->w460) != 0 &&
            m->w58 == 0 && o->b1A07 == 0) {
            if ((decode_0053C758(&o->b19E4) ^ 0x22) != 0) {
                func_L39_005F33E0(3, 0, a0);
                m->w58 = 1;
            }
        }
        if ((func_L39_005C2F50(o->w2534) & o->w460) == 0) {
            m->w58 = 0;
        }
        if ((decode_0053C758(&o->b19E4) ^ 0x1D) == 0 && res == 8) {
            func_L39_00621D60(o, -1);
        }
        if (o->b1A14 != 0 && o->b1A07 != 0 && o->w30C == 1) {
            func_L39_005F33E0(2, 0, a0);
        }
        net = o->b1A14;
        if (net != 0 && kind == 4) {
            func_L39_005F33E0(1, 0, a0);
        }
        if (func_L39_00554DD8(o->w2544) == 0 &&
            (o->b24FF != 0 || (o->b1A07 != 0 && o->w30C == 0xE) ||
             ((decode_0053C758(&o->b19E4) ^ 0x22) == 0 && o->w2F0 == 0xD))) {
            V_0053C758 tmp;

            flag = o->b24FF != 0;
            if (o->b24FF != 0) {
                if (o->u18F0.f != 0.0f) {
                    *(q_0053C758 *)&pos = o->u18F0.q;
                }
                o->b24FF = 0;
            } else {
                V_0053C758 *pp = &pos;

                *(q_0053C758 *)pp = o->q730;
                func_0038D000(&tmp, &D_L39_0024ADE0, a0 + 0xC0);
                vec_add_ab(pp, pp, &tmp);
                if (o->u18F0.f != 0.0f && func_003D3CB0(&o->u18F0, pp, 0x22, 0, 0) != 0) {
                    *(q_0053C758 *)&pos = o->u18F0.q;
                    flag = 1;
                }
            }
            if (flag) {
                func_0038CF68(&tmp, &o->v20, -1.0f);
                func_L01_0040E790((f32 *)&m->v30, (f32 *)&m->v30, (f32 *)&tmp);
                vec_add_ab(&pos, &pos, &m->v30);
            }
            func_L39_00620E28(o, 0xC, 1);
            func_L39_00552750((s32)a0, (u8 *)o, (u8 *)&pos, (u8 *)&m->v30, flag, 1.0f);
            a0[0x20] = 3;
            m->w40 = 0x25;
        }
        break;
    }
    case 3:
        o->b1A0D = 1;
        if (func_0038CAD0(&m->w40) != 0) {
            a0[0x20] = 1;
        }
        break;
    }
    r = 0;
    if (o->b1A14 != 0) {
        V_0053C758 tmp;

        func_L39_00632180((u8 *)o, (f32 *)&tmp, 1, 0.0f, 0.0f, 0.37f);
        if (func_003D3CB0(&tmp, &pos, 0x32, a0, 0) != 0) {
            func_0038CE20(&m->v10, D_L39_0025F760 + 0x20, 0.0009765625f);
            m->q0 = *(q_0053C758 *)D_L39_0025F760;
            r = 1;
        } else {
            r = func_L39_005FED60((u8 *)o, 0.0044f, (u8 *)&pos, (u8 *)&m->v20, (u8 *)m, (u8 *)&m->v10, 0, 1, 0, 0, 0);
        }
    }
    m->w44 = r;
    if (r != 0) {
        func_L01_00404A10(func_L39_0053CEC0, a0);
    }
}
/* localdecomp:end func_L39_0053C758 */

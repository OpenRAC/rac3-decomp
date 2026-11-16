#include "common.h"

/* NTSC-U counterpart of func_L39_0053C758 (src/levels/shared/L39_0053C300.c) */
extern void func_00388830(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L39_0053BFC0 */
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

extern u8 D_L39_004998A0[];
extern u8 D_L39_0025F860[];
extern V_0053C758 D_L39_0024AEE0_0053BFC0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AEE0_0053BFC0, 4");
extern V_0053C758 D_L39_0024AEF0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AEF0, 4");

extern void func_L39_00619D58(u8 *, u8 **);
extern void func_003888F0(void *, void *, void *);
extern void func_L39_005FBF00(O_0053C758 *, V_0053C758 *, void *, s32, s32, f32, f32, f32, f32);
extern s32 func_00388398(void *);
extern s32 func_L39_00670988(void *p, s32 a1, s32 a2, s32 a3);
extern s32 func_L39_00554480(s32 arg0);
extern s32 func_L39_005C0F08(s32);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern void func_L39_0061F5C0(void *, s32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0040C260(f32 *, f32 *, f32 *);
extern void func_L39_0061E688(void *, s32, s32);
extern u8 *func_L39_00551E00(s32 a0, u8 *a1, u8 *a2, u8 *a3, s32 a4, f32 a5);
extern void func_L39_0062F938(u8 *, f32 *, s32, f32, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L39_005FC5C0(u8 *, f32, u8 *, u8 *, u8 *, u8 *, s32, s32, s32, s32, s32);
extern void func_L01_004026A0(void *, void *);
extern void func_L39_0053C728(u8 *a0);

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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)p;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

void func_L39_0053BFC0(u8 *a0) {
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
        func_L39_00619D58(a0, (u8 **)&m->o);
    }
    o = m->o;
    func_003888F0(&pos, &D_L39_0024AEE0_0053BFC0, &o->v20);
    vec_add_ab(&pos, &pos, &o->vA0);
    func_L39_005FBF00(o, &m->v20, &pos, 0, 0, 1.5f,
                      (decode_0053C758(&o->b19E4) ^ 0x1D) == 0 ? 8.0f : 5.0f, 0.0166666675f * 6.0f, 0.003333333414f);
    if ((decode_0053C758(&o->b19E4) ^ 0x1D) == 0) {
        func_00388398(&o->w2470);
    } else {
        o->w2470 = 0x28;
    }
    switch (a0[0x20]) {
    case 0:
        a0[0x20] = 1;
        m->w48 = 1;
        m->w44 = 0;
        o->b1A0D = 0;
    case 1: {
        S_0053C758 s;

        res = func_L39_00670988(o->b1A40, 0, 1, (s32)&s);
        if (res == 8) {
            V_0053C758 *v = &m->v30;
            v->x = s.x;
            v->y = s.y;
            v->z = s.z;
            v->w = 0.0f;
        }
        if (func_L39_00554480(o->w2544) != 0 || m->w48 == 0) {
            o->b1A0D = 1;
        } else if (o->b1A07 == 0) {
            o->b1A0D = 0;
        }
        if (o->b1A14 != 0 && o->b1A0D != 0 && (func_L39_005C0F08(o->w2534) & o->w460) != 0 &&
            m->w58 == 0 && o->b1A07 == 0) {
            if ((decode_0053C758(&o->b19E4) ^ 0x22) != 0) {
                func_L39_005F0CE0(3, 0, a0);
                m->w58 = 1;
            }
        }
        if ((func_L39_005C0F08(o->w2534) & o->w460) == 0) {
            m->w58 = 0;
        }
        if ((decode_0053C758(&o->b19E4) ^ 0x1D) == 0 && res == 8) {
            func_L39_0061F5C0(o, -1);
        }
        if (o->b1A14 != 0 && o->b1A07 != 0 && o->w30C == 1) {
            func_L39_005F0CE0(2, 0, a0);
        }
        net = o->b1A14;
        if (net != 0 && kind == 4) {
            func_L39_005F0CE0(1, 0, a0);
        }
        if (func_L39_00554480(o->w2544) == 0 &&
            (o->b24FF != 0 || (o->b1A07 != 0 && o->w30C == 0x11) ||
             ((decode_0053C758(&o->b19E4) ^ 0x22) == 0 && o->w2F0 == 0x10))) {
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
                func_003888C8(&tmp, &D_L39_0024AEF0, a0 + 0xC0);
                vec_add_ab(pp, pp, &tmp);
                if (o->u18F0.f != 0.0f && func_003CE740(&o->u18F0, pp, 0x22, 0, 0) != 0) {
                    *(q_0053C758 *)&pos = o->u18F0.q;
                    flag = 1;
                }
            }
            if (flag) {
                func_00388830(&tmp, &o->v20, -1.0f);
                func_L01_0040C260((f32 *)&m->v30, (f32 *)&m->v30, (f32 *)&tmp);
                vec_add_ab(&pos, &pos, &m->v30);
            }
            func_L39_0061E688(o, 0xC, 1);
            func_L39_00551E00((s32)a0, (u8 *)o, (u8 *)&pos, (u8 *)&m->v30, flag, 1.0f);
            a0[0x20] = 3;
            m->w40 = 0x2D;
        }
        break;
    }
    case 3:
        o->b1A0D = 1;
        if (func_00388398(&m->w40) != 0) {
            a0[0x20] = 1;
        }
        break;
    }
    r = 0;
    if (o->b1A14 != 0) {
        V_0053C758 tmp;

        func_L39_0062F938((u8 *)o, (f32 *)&tmp, 1, 0.0f, 0.0f, 0.37f);
        if (func_003CE740(&tmp, &pos, 0x32, a0, 0) != 0) {
            func_003886E8(&m->v10, D_L39_0025F860 + 0x20, 0.0009765625f);
            m->q0 = *(q_0053C758 *)D_L39_0025F860;
            r = 1;
        } else {
            r = func_L39_005FC5C0((u8 *)o, 0.003055555746f, (u8 *)&pos, (u8 *)&m->v20, (u8 *)m, (u8 *)&m->v10, 0, 1, 0, 0, 0);
        }
    }
    m->w44 = r;
    if (r != 0) {
        func_L01_004026A0(func_L39_0053C728, a0);
    }
}
/* localdecomp:end func_L39_0053BFC0 */

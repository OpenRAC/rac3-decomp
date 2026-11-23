#include "common.h"
#include "structs/moby.h"
#include "vu0.h"

/* localdecomp:start func_L07_003B6800 */
extern f32 func_0038CF38(void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);

void func_L07_003B6800(u8 *arg0) {
    u8 *p;
    f32 v[3];
    f32 d;

    p = *(u8 **)(arg0 + 0x68);
    func_003C2F58(arg0, (u8)(p[0x31D] + 2), v);
    d = -func_0038D160(func_0038CF38(v, p + 0x80), *(f32 *)(p + 0x88) - v[2]);
    *(f32 *)(p + 0x294) = d;
    *(f32 *)(p + 0x214) = d * 1.4f;
}
/* localdecomp:end func_L07_003B6800 */

/* localdecomp:start func_L07_003B6870 */
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L07_003B6870(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    func_L01_0044E850(a0, s + 0x1B0, 0, 0.0432f, 0.43200004f);
    func_L01_0044E850(a0, s + 0x230, 1, 0.0432f, 0.43200004f);
}
/* localdecomp:end func_L07_003B6870 */

/* localdecomp:start func_L07_003B68F0 */
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448890(char *a0, char *a1, int a2, float f12, float f13,
                              float f14, float f15);

void func_L07_003B68F0(u8 *arg0) {
    u8 *s;
    u8 *p;
    u8 *q;
    u8 flag;
    f32 r;

    s = *(u8 **)(arg0 + 0x68);
    flag = s[0x323];
    if (0.0f < *(f32 *)(s + 0x148)) {
        if (flag & 1) {
            p = *(u8 **)(s + 0x190) + 0x10;
        } else {
            p = s + 0x80;
        }
    } else {
        if (flag & 2) {
            p = *(u8 **)(s + 0x190) + 0x10;
        } else {
            p = s + 0x80;
        }
    }
    q = arg0 + 0xF8;
    r = func_0038D160(*(f32 *)p - *(f32 *)(arg0 + 0x10),
                      *(f32 *)(p + 4) - *(f32 *)(arg0 + 0x14));
    func_L01_00448890((char *)q, (char *)s + 0x154, 0, r,
                      *(f32 *)(s + 0xB4), *(f32 *)(s + 0xB8), *(f32 *)(s + 0xBC));
}
/* localdecomp:end func_L07_003B68F0 */

/* localdecomp:start func_L07_003B6998 */
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L03_0032FAF0(f32 *, f32 *, f32, f32);
extern void func_L07_003B64D0(u8 *, s32);

void func_L07_003B6998(u8 *arg0) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    f32 a = func_0038D160(
        *(f32 *)(s + 0x80) - *(f32 *)(*(u8 **)(s + 0x190) + 0x10),
        *(f32 *)(s + 0x84) - *(f32 *)(*(u8 **)(s + 0x190) + 0x14));
    f32 b = func_0038D160(
        *(f32 *)(arg0 + 0x10) - *(f32 *)(*(u8 **)(s + 0x190) + 0x10),
        *(f32 *)(arg0 + 0x14) - *(f32 *)(*(u8 **)(s + 0x190) + 0x14));
    f32 r = func_003824E0(1.3962633609771729f, 2.7925267219543457f);

    if (0.0f < func_0038DB00(b, a)) {
        r = func_0038DAB8(b, r);
    } else {
        r = func_0038DB00(b, r);
    }
    func_L03_0032FAF0((f32 *)(s + 0x2F0), (f32 *)(*(u8 **)(s + 0x190) + 0x10),
                      (f32)(s32)(r / 0.785398006439209f) * 0.785398006439209f,
                      20.0f);
    s[0x323] = 0;
    s[0x322] = 0xFF;
    func_L07_003B64D0(arg0, 0x13);
}
/* localdecomp:end func_L07_003B6998 */

/* localdecomp:start func_L07_003B6AE8 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L07_001DF500_003B6AE8;
extern void func_L07_003B64D0(u8 *, s32);

void func_L07_003B6AE8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);

    p[0x324] = 0;
    *(u128_t *)(p + 0x2F0) = *(u128_t *)(&D_L07_001DF500_003B6AE8[(*(s32 *)(p + 0x30C) << 7) + 0x30]);
    p[0x323] = 2;
    p[0x322] = 0x16;
    func_L07_003B64D0(a0, 0x13);
}
/* localdecomp:end func_L07_003B6AE8 */

#include "vu0.h"

/* localdecomp:start func_L07_003B6B38 */
extern void func_0038CF68(void *, void *, f32);
extern void func_L07_003B64D0(u8 *, s32);

void func_L07_003B6B38(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    vec_sub_ab(s + 0x2F0, a0 + 0x10, *(u8 **)(s + 0x190) + 0x10);
    *(s32 *)(s + 0x2F8) = 0;
    func_0038CF68(s + 0x2F0, s + 0x2F0, 20.0f);
    vec_add_ba(s + 0x2F0, *(u8 **)(s + 0x190) + 0x10, s + 0x2F0);
    s[0x324] = 1;
    *(u16 *)(a0 + 0x34) |= 0x5000;
    s[0x322] = 0xB;
    s[0x323] = 1;
    func_L07_003B64D0(a0, 0x13);
    a0[0xBC] = 0;
}
/* localdecomp:end func_L07_003B6B38 */

/* localdecomp:start func_L07_003B6BD8 */
extern void func_L07_003B64D0(u8 *, s32);
extern s32 func_L07_003A2380(u8, s32, u8, s16);
extern s32 func_00382468(s32);
extern void func_L01_00456230(void *, s32);

void func_L07_003B6BD8(u8 *arg0, s32 arg1) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    u32 diff = (u32)s[0x31F] ^ (u32)arg1;
    s32 changed = diff != 0;

    if (changed) {
        f32 t = *(f32 *)(s + 0x30);

        s[0x31F] = arg1;
        *(f32 *)(s + 0x310) = t;
        s[0x320] = 0;
    }
    if (arg1 == 0) {
        if (changed || func_00382468(4) == 0) {
            func_L07_003B64D0(arg0, 6);
        } else {
            func_L07_003B64D0(arg0, 7);
        }
    } else if (arg1 == 1) {
        if (*(s16 *)(s + 0x328) == 0) {
            func_L07_003A2380(4, (s32)arg0, 0, 0x64);
            *(s16 *)(s + 0x328) = 0x1F4;
        }
        if (changed || func_00382468(4) == 0) {
            func_L07_003B64D0(arg0, 0xB);
        } else {
            func_L07_003B64D0(arg0, 0xC);
        }
    }
    func_L01_00456230(arg0, 0);
}
/* localdecomp:end func_L07_003B6BD8 */

/* localdecomp:start func_L07_003B6CD8 */
extern u8 *D_L07_001DF41C_003B6CD8;
extern s32 func_L01_00456250(void *);
extern s32 func_L07_003A2380(u8, s32, u8, s16);

s32 func_L07_003B6CD8(u8 *arg0, u8 arg1) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    u8 *p;
    f32 d;

    if (s[0x321] != 0) {
        return 0;
    }
    if (s[0x320] >= 4) {
        return 1;
    }
    if (func_L01_00456250(arg0) != 0) {
        if (*(s16 *)(s + 0x32A) == 0) {
            p = D_L07_001DF41C_003B6CD8 + (*(s32 *)(s + 0x300) << 8);
            if (p[0xBC] == 0) {
                p[0xBC] = 1;
            }
            func_L07_003A2380(0xC, (s32)p, 0, 0x64);
            *(s16 *)(s + 0x32A) = 0x3E8;
        }
        return 1;
    }
    if (arg1 != 0) {
        return 0;
    }
    d = *(f32 *)(s + 0x310) - *(f32 *)(s + 0x30);
    if ((f32)*(s16 *)(s + 0x34) * 0.1f < d) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L07_003B6CD8 */

/* localdecomp:start func_L07_003B6DC8 */
extern f32 func_0038CF38(void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_0038DAB8(f32 a, f32 b);

f32 func_L07_003B6DC8(u8 *arg0, u8 *arg1) {
    f32 t;
    f32 off;
    f32 a;

    t = func_0038CF38(arg0 + 0x10, arg1) / 50.0f;
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    off = t * -0.139626339f + 0.17453292f;
    a = func_0038D160(*(f32 *)(arg1 + 0) - *(f32 *)(arg0 + 0x10),
                      *(f32 *)(arg1 + 4) - *(f32 *)(arg0 + 0x14));
    return func_0038DAB8(a, off);
}
/* localdecomp:end func_L07_003B6DC8 */

/* localdecomp:start func_L07_003B6E98 */
typedef struct V4_3B6E98 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_3B6E98;
typedef struct Obj_3B6E98 {
    u8 pad0[0x68];
    u8 *vars;
    u8 pad6C[0xF8 - 0x6C];
    f32 fF8;
} Obj_3B6E98;
typedef struct Vars_3B6E98 {
    u8 pad0[0x44];
    u8 b44;
    u8 pad45[0x80 - 0x45];
    V4_3B6E98 q80;
    u8 pad90[0x31A - 0x90];
    s16 h31A;
    u8 pad31C;
    u8 b31D;
} Vars_3B6E98;
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L07_003B6DC8(u8 *, u8 *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
typedef int Quad_003B1958 __attribute__((mode(TI)));
extern u8 *func_L07_003B1958(void *, Quad_003B1958 *, f32, f32, u8);
extern void func_L07_00473C80(void *, s32, u32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

/* Aims a joint of the moby (joint arg1+2) at a point: reads the joint with moby_point_position,
 * computes a pitch angle, calls func_L07_003B1958, then emits four func_L07_00473C80 effects at the
 * joint. */
void func_L07_003B6E98(Obj_3B6E98 *obj, s32 arg1) {
    V4_3B6E98 a;
    V4_3B6E98 b;
    Vars_3B6E98 *vars = (Vars_3B6E98 *)obj->vars;
    s32 id = (u8)(arg1 + 2);
    f32 one;
    f32 ratio;
    f32 ang;
    f32 s;
    f32 t;

    func_003C2F58(obj, id, &a);
    one = 1.0f;
    ratio = func_0038DBA0(func_L07_003B6DC8((u8 *)obj, (u8 *)&vars->q80), obj->fF8) / 0.5235988f;
    if (ratio > one) {
        ratio = one;
    }
    s = -0.5f;
    t = func_003C3BE8(s, -2.0f, ratio);
    b = vars->q80;
    b.z = b.z + t;
    ang = func_0038D160(func_0038CF38(&a, &b), b.z - a.z);
    if (vars->h31A != 0) {
        ang = ang * ((f32)vars->h31A / 90.0f + one);
    }
    func_L07_003B1958(obj, (Quad_003B1958 *)&a, obj->fF8, -ang, vars->b44);
    if ((u8)(vars->b31D - 1) < 2) {
        s = 0.5f;
    }
    func_L07_00473C80(obj, id, 0xBF804020, 0, 7, 0, 1, 0x35, 0, 735000.0f, 21000.0f, s);
    func_L07_00473C80(obj, id, 0xBFA04020, 0, 7, 0, 1, 0x35, 0, 525000.0f, 21000.0f, s);
    func_L07_00473C80(obj, id, 0xC0FFFFFF, 0, 7, 0, 1, 0x35, 0, 367500.0f, 21000.0f, s);
    func_L07_00473C80(obj, id, 0xB0FFFFFF, 0, 7, 0, 1, 0x35, 0, 262500.0f, 21000.0f, s);
}
/* localdecomp:end func_L07_003B6E98 */

/* localdecomp:start func_L07_003B70F0 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003B70F0;
void func_L07_003B70F0(u8 *obj, u8 mask) {
    extern void func_003C2EC0(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382468(s32);
    extern s32 func_L07_003D41D8(void *, void *, void *, s32, f32);
    V_003B70F0 matrix[4];
    V_003B70F0 position;
    V_003B70F0 velocity;
    s32 i;
    u8 *state = *(u8 **)(obj + 0x68);
    for (i=0;i<6;i++) {
        if ((mask >> i) & 1) {
            u8 flags;
            func_003C2EC0(obj, i+6, matrix);
            position=matrix[3];
            func_0038CF68(&velocity, &matrix[1], i>=3 ? -0.40000003576278687f : 0.40000003576278687f);
            flags=func_00382468(20)==0;
            if (state[0x321]==5) flags |= 2;
            if (state[0x321]==5 || state[0x321]==2) {
                if (func_00382468(3)==0) flags |= 4;
            }
            *(s32 *)(state+0x308)=func_L07_003D41D8(obj,&position,&velocity,flags,(f32)state[0x45]);
        }
    }
}
/* localdecomp:end func_L07_003B70F0 */

/* localdecomp:start func_L07_003B7230 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003B7230;

typedef struct {
    V4_003B7230 v;
    void *owner;
    s32 f14;
    u8 f18;
    u8 f19;
    u16 f1A;
    f32 f1C;
    s32 f20;
    f32 f24;
    s32 f28;
} S_003B7230;

extern void func_0038CE20(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);

void func_L07_003B7230(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    S_003B7230 s;
    V4_003B7230 v;

    s.owner = arg0;
    s.f1A = *(u16 *)(arg0 + 0xAA);
    s.f24 = (f32)p[0x46];
    s.f1C = (f32)p[0x46];
    s.f14 = 1;
    s.f20 = 1;
    s.f19 = 2;
    s.f28 = -1;
    s.f18 = 0;
    func_0038CE20(&s.v, arg0 + 0xC0, 6.0f);
    s.v.z = 2.0f;
    s.v.w = 5627.925f;
    func_003C2F58(arg0, 1, &v);
    func_003D4D00(&v, 0, 2.0f, arg0, &s);
    func_003C2F58(arg0, 0xC, &v);
    func_003D4D00(&v, 0, 2.5f, arg0, &s);
    func_003C2F58(arg0, 0xD, &v);
    func_003D4D00(&v, 0, 2.5f, arg0, &s);
}
/* localdecomp:end func_L07_003B7230 */

/* localdecomp:start func_L07_003B7378 */
extern void func_L07_003B7408(void *, s32, f32, f32);

void func_L07_003B7378(void *self) {
    f32 a;
    f32 b;

    func_L07_003B7408(self, 14, 1.0f, 0.43633232f);
    a = 0.4f;
    b = 0.7853982f;
    func_L07_003B7408(self, 15, a, b);
    func_L07_003B7408(self, 16, a, b);
}
/* localdecomp:end func_L07_003B7378 */

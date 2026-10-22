#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_00424920);

/* localdecomp:start func_L40_00424B10 */
s32 func_L40_00424B10(void *arg0) {
    return (*(s16 *)((u8 *)arg0 + 0xAA)) == 0xCBE;
}
/* localdecomp:end func_L40_00424B10 */

INCLUDE_ASM("asm/levels", func_L40_00424B20);

/* localdecomp:start func_L40_00424BA0 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern u8 *D_L40_0025B998[];
extern u8 *func_003D3CB0(Vec4 *a0, Vec4 *a1, s32 a2, s32 a3, s32 t0);

u8 *func_L40_00424BA0(Vec4 *from, Vec4 *to, s32 arg) {
    Vec4 a;
    Vec4 b;
    u8 *hit;
    u8 *m;
    s16 type;

    a = *from;
    b = *to;
    hit = func_003D3CB0(&a, &b, 18, arg, 0);
    if (hit != 0) {
        m = D_L40_0025B998[0];
        if (m != 0) {
            type = *(s16 *)(m + 170);
            if (type == 4220 || type == 4222 || type == 4290) {
                hit = 0;
            }
        }
    }
    return hit;
}
/* localdecomp:end func_L40_00424BA0 */

/* localdecomp:start func_L40_00424C20 */
typedef struct { u8 pad[0x2A0]; s32 f2A0; } V_424328;
typedef struct { u8 pad[0x20]; u8 state; u8 p21[0x47]; V_424328 *vars; } S_424328;
extern void func_L01_004450F0(S_424328 *, s32, s32);

void func_L40_00424C20(S_424328 *m) {
    V_424328 *v = m->vars;
    if (v->f2A0 != 0) {
        v->f2A0 = 0;
        if (m->state == 1 || m->state == 4) {
            func_L01_004450F0(m, 2, -1);
        }
    }
}
/* localdecomp:end func_L40_00424C20 */

INCLUDE_ASM("asm/levels", func_L40_00424C68);

/* localdecomp:start func_L40_00424D98 */
typedef struct O_4244A0 O_4244A0;
typedef struct {
    u8 pad0[16];
    s32 (*fn)(O_4244A0 *);
} V_4244A0;
struct O_4244A0 {
    u8 pad0[20];
    V_4244A0 *vt;
};

extern u8 *func_L39_006685D8(u32);
extern O_4244A0 *func_L39_0061D1D8(u32);

s32 func_L40_00424D98(u32 a0) {
    s32 r = 0;
    O_4244A0 *o;
    if (((a0 >> 24) & 0xF) == 3) {
        r = *(s32 *)(func_L39_006685D8(a0) + 720);
    } else {
        o = func_L39_0061D1D8(a0);
        if (o != 0) {
            r = o->vt->fn(o);
        }
    }
    return r;
}
/* localdecomp:end func_L40_00424D98 */

/* localdecomp:start func_L40_00424E00 */
extern u8 *func_L39_0066DD30(s32, s32, s32);
extern void func_L39_00662B18(u8 *, void *, s32);

f32 func_L40_00424E00(s32 a0, void *a1) {
    f32 v = 0.0f;
    u8 *o = func_L39_0066DD30(a0, 2, 1);
    if (o != 0) {
        o[84] = 0;
        func_L39_00662B18(o, &v, 4);
        func_L39_00662B18(o, a1, 8);
    }
    return v;
}
/* localdecomp:end func_L40_00424E00 */

INCLUDE_ASM("asm/levels", func_L40_00424E68);

/* localdecomp:start func_L40_00424F88 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
void func_L40_00424F88(s32 a0, s32 a1) {
    s32 x;
    s32 r = func_L39_0066DCC8(a0, 0, 0, 250);
    x = a1;
    func_L39_00662AA0(r, &x, 4);
}
/* localdecomp:end func_L40_00424F88 */

/* localdecomp:start func_L40_00424FD0 */
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
extern void func_L39_006626E8(u8 *a0);

void func_L40_00424FD0(s32 id, s32 value) {
    u8 *p;

    ((void (*)(u8 *a0, s32 a1, s32 a2))func_L39_00662AA0)(((u8 * (*)(s32 a0, s32 a1, s32 a2, s32 a3))func_L39_0066DCC8)(id, 1, 0, 250), value, 8);
    p = func_L39_0066DD30(id, 2, 0);
    if (p != 0 && p[85] != 0) {
        func_L39_006626E8(p);
    }
}
/* localdecomp:end func_L40_00424FD0 */

/* localdecomp:start func_L40_00425050 */
extern u8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
s32 func_L40_00425050(s32 a0) {
    return ((s32 (*)(s32, s32, s32))func_L39_0066DD30)(a0, 0, 0) != 0;
}
/* localdecomp:end func_L40_00425050 */

/* localdecomp:start func_L40_00425078 */
extern u8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
s32 func_L40_00425078(s32 a0) {
    return ((s32 (*)(s32, s32, s32))func_L39_0066DD30)(a0, 1, 0) != 0;
}
/* localdecomp:end func_L40_00425078 */

INCLUDE_ASM("asm/levels", func_L40_004250A0);

INCLUDE_ASM("asm/levels", func_L40_004255A0);

/* localdecomp:start func_L40_004259E0 */
s32 func_L40_004259E0(u8 *a0, u8 **a1, s32 *a2) {
    u8 *p = *(u8 **)(a0 + 104);
    *a2 = 16;
    *a1 = p + 544;
    return 0;
}
/* localdecomp:end func_L40_004259E0 */

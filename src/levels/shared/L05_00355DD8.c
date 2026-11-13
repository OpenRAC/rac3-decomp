#include "common.h"
#include "vu0.h"

typedef struct { u8 pad[0x3EC]; void *x3EC; u8 pad2[4]; s16 x3F4; } V_35EE8;
typedef struct { u8 pad[0x68]; V_35EE8 *x68; } O_35EE8;

/* localdecomp:start func_L05_00355DD8 */
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045AA10(void *, f32);
extern void func_L01_0045D218(void *, void *);

void func_L05_00355DD8(u8 *a0, vu0_v4 *pt) {
    vu0_v4 p = *pt;
    vu0_v4 d;
    if (*(s16 *)(*(u8 **)(a0 + 0x68) + 0x3DA) == 0) {
        f32 x = p.x;
        f32 y = p.y;
        func_L01_0045AA10(a0, func_0038D160(x - *(f32 *)(a0 + 0x10), y - *(f32 *)(a0 + 0x14)));
    } else {
        vec_sub_ab(&d, &p, a0 + 0x10);
        func_L01_0045D218(a0, a0 + 0x10);
    }
}
/* localdecomp:end func_L05_00355DD8 */

/* localdecomp:start func_L05_00355E58 */
typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } Vec4;
extern f32 func_L05_00355D00(u8 *, Vec4 *);
extern s32 func_L02_003E6F38(f32, f32, f32);
s32 func_L05_00355E58(u8 *a0, Vec4 *a1) {
    s32 r = 0;
    Vec4 v;
    v = *a1;
    if (func_L05_00355D00(a0, &v) < 3.0f) {
        r = func_L02_003E6F38(*(f32 *)(a0 + 24) + 1.0f, a1->f[2], 1.5f) != 0;
    }
    return r;
}
/* localdecomp:end func_L05_00355E58 */

/* localdecomp:start func_L05_00355EE8 */
extern s32 func_L05_00355B30(u8 *a0);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L05_0035AA68();

void func_L05_00355EE8(O_35EE8 *o) {
    V_35EE8 *v = o->x68;
    if (func_L05_00355B30((u8 *)o) == 0) {
        if (v->x3F4 != 0) {
            func_L05_0035AA68(o, 5, 0, 8);
        } else {
            func_L05_0035AA68(o, 6, 0, 8);
        }
    } else {
        func_003C3A10(v->x3EC, 5, 0, 8);
    }
}
/* localdecomp:end func_L05_00355EE8 */

/* localdecomp:start func_L05_00355F60 */
extern s32 func_L05_0035AC08(u8 *);
extern s32 func_L05_0035ACD8(u8 *);

s32 func_L05_00355F60(u8 *obj) {
    s32 ret;
    if ((*(u8 **)(obj + 104))[95] != 0) {
        return func_L05_0035AC08(obj);
    }
    ret = 0;
    if (obj[188] == 0) {
        ret = func_L05_0035ACD8(obj) != 0;
    }
    return ret;
}
/* localdecomp:end func_L05_00355F60 */

/* localdecomp:start func_L05_00355FB0 */
extern s32 D_L05_001DFBD8;
extern void *D_L05_0021DAE0[];
extern void func_L01_00445BE0(s32, s32);
void func_L05_00355FB0(u8 *a0) {
    if (a0[188] == 0) {
        s32 i = a0[33];
        if (i < D_L05_001DFBD8 && D_L05_0021DAE0[i] != 0) {
            func_L01_00445BE0(i, 1);
            a0[188] = 0;
        }
    }
}
/* localdecomp:end func_L05_00355FB0 */

/* localdecomp:start func_L05_00356018 */
extern void *D_L05_0021DAE0[];
extern s32 D_L05_001DFBD8;
extern void func_L01_00445BE0(s32, s32);
void func_L05_00356018(u8 *a0) {
    if (a0[188] == 0) {
        u8 i = a0[33];
        if (i < D_L05_001DFBD8 && ((s32 *)&D_L05_0021DAE0)[i] != 0) {
            func_L01_00445BE0(i, 0);
        }
    }
}
/* localdecomp:end func_L05_00356018 */

/* localdecomp:start func_L05_00356070 */
extern f32 D_L05_001DF6CC;
extern f32 D_L05_001DF6D0;

s32 func_L05_00356070(f32 fparg0) {
    s32 var_v0;

    var_v0 = 0;
    if ((D_L05_001DF6D0 < fparg0) && (D_L05_001DF6CC < fparg0)) {
        var_v0 = 1;
    }
    return var_v0;
}
/* localdecomp:end func_L05_00356070 */

/* localdecomp:start func_L05_003560A8 */
__asm__(".extern D_L05_001DD600, 8");
extern u8 D_L05_001DD600[8];
u8 *func_L05_003560A8(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 2) {
        *a2 = 12;
        return D_L05_001DD600;
    }
    return 0;
}
/* localdecomp:end func_L05_003560A8 */

INCLUDE_ASM("asm/levels", func_L05_003560C8);

INCLUDE_ASM("asm/levels", func_L05_00358FF8);

INCLUDE_ASM("asm/levels", func_L05_00359878);

INCLUDE_ASM("asm/levels", func_L05_00359C78);

INCLUDE_ASM("asm/levels", func_L05_0035A2B0);

INCLUDE_ASM("asm/levels", func_L05_0035A380);

/* localdecomp:start func_L05_0035A558 */
void func_L05_0035A558(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x3F0) = 0;
}
/* localdecomp:end func_L05_0035A558 */

INCLUDE_ASM("asm/levels", func_L05_0035A568);

INCLUDE_ASM("asm/levels", func_L05_0035A880);

INCLUDE_ASM("asm/levels", func_L05_0035A980);

/* localdecomp:start func_L05_0035AA68 */
typedef struct { u8 pad[0x3EC]; void *x3EC; } V_359930;
typedef struct { u8 pad[0x68]; V_359930 *x68; } O_359930;
extern void func_003C3A10(void *, s32, s32, s32);
void func_L05_0035AA68(O_359930 *o, s32 a, s32 b, s32 c) {
    V_359930 *v = o->x68;
    func_003C3A10(o, a, b, c);
    func_003C3A10(v->x3EC, a, b, c);
}
/* localdecomp:end func_L05_0035AA68 */

/* localdecomp:start func_L05_0035AAC8 */
extern s32 func_L05_00355E58(u8 *a0, Vec4 *a1);
typedef struct { u8 pad[0x68]; u8 *x68; } O_359990;
extern s32 func_L05_00355BD8(O_359990 *, u8 *);
s32 func_L05_0035AAC8(O_359990 *o) {
    s32 r = 0;
    u8 *p = o->x68 + 0x220;
    if (((s32 (*)(O_359990 *, u8 *))func_L05_00355E58)(o, p) == 0) {
        r = func_L05_00355BD8(o, p) != 0;
    }
    return r;
}
/* localdecomp:end func_L05_0035AAC8 */

/* localdecomp:start func_L05_0035AB28 */
extern void func_0038CF68(void *, void *, f32);
extern u8 *D_L05_001EA6D8[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L05_0035AB28(u8 *arg0, f32 h)
{
    vu0_v4 p;
    vu0_v4 d;
    u8 *v;
    u8 *o;
    s32 r;

    *(vu0_q *)&p = *(vu0_q *)(arg0 + 0x10);
    v = *(u8 **)(arg0 + 0x68);
    p.z += h;
    vec_sub_ba(&d, v + 0x220, &p);
    d.z = 0.0f;
    func_0038CF68(&d, &d, 3.0f);
    vec_add_ab(&d, &d, &p);
    if (func_003D3CB0(&p, &d, 0x10, arg0, 0) == 0) {
        return 1;
    }
    o = D_L05_001EA6D8[0];
    r = 0;
    if (o != 0 && (*(s16 *)(o + 0xAA) == 0x1625 || o == *(u8 **)(v + 0x230))) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L05_0035AB28 */

INCLUDE_ASM("asm/levels", func_L05_0035AC08);

/* localdecomp:start func_L05_0035ACD8 */
extern u8 *D_L05_001EA6D8[];
extern void func_003C2F58(s32, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L05_0035ACD8(u8 *arg0)
{
    u8 *v;
    u8 *o;
    s32 buf[4];

    v = *(u8 **)(arg0 + 104);
    func_003C2F58(*(s32 *)(v + 1004), 0, buf);
    if (func_003D3CB0(buf, v + 544, 0, arg0, 0)) {
        o = D_L05_001EA6D8[0];
        if (o != 0 && *(s16 *)(o + 170) == 5669) {
            return o == *(u8 **)(v + 560);
        }
    }
    return 1;
}
/* localdecomp:end func_L05_0035ACD8 */

/* localdecomp:start func_L05_0035AD60 */
extern s32 func_00382468(s32);
extern s32 func_L05_0035AC08(u8 *);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_003C2F58(s32, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L05_003C8890(void *, void *, void *, void *, f32);
extern void func_003A52A0(s32, s32, void *);

void func_L05_0035AD60(u8 *arg0)
{
    u8 *v;
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 t;
    vu0_v4 r;
    vu0_v4 m[4];

    v = *(u8 **)(arg0 + 0x68);
    t = *(vu0_v4 *)(v + 0x220);
    if (func_00382468(4) == 0 && func_L05_0035AC08(arg0) == 0) {
        func_L01_00443B88(&r, 0.8f, 1.2f);
        if (func_00382468(2)) {
            r.x = -r.x;
        }
        if (func_00382468(2)) {
            r.y = -r.y;
        }
        vec_add_ab(&t, &t, &r);
    }
    func_003C2F58(*(s32 *)(v + 0x3EC), 0, &p);
    func_003C2EC0(*(void **)(v + 0x3EC), 0, m);
    func_0038CF68(&a, m, 0.1f);
    vec_add_ba(&p, &p, &a);
    vec_sub_ab(&d, &t, &p);
    func_0038CF68(&d, &d, 0.200000018f);
    func_L05_003C8890(arg0, *(void **)(v + 0x230), &p, &d, v[0x44]);
    func_003A52A0(3, 0, arg0);
}
/* localdecomp:end func_L05_0035AD60 */

INCLUDE_ASM("asm/levels", func_L05_0035AEC8);

INCLUDE_ASM("asm/levels", func_L05_0035AFB8);

INCLUDE_ASM("asm/levels", func_L05_0035B1A0);

/* localdecomp:start func_L05_0035B308 */
extern void func_003C2F58(s32, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003C5458(void *, s32, f32, f32);
__asm__(".extern D_L05_001DD6F0, 8");
extern u8 D_L05_001DD6F0[8];
__asm__(".extern D_L05_001DD710, 8");
extern s32 D_L05_001DD710[2];
__asm__(".extern D_L05_001DD6E0, 8");
extern f32 D_L05_001DD6E0[2];
__asm__(".extern D_L05_001DD6D8, 8");
extern f32 D_L05_001DD6D8[2];

void func_L05_0035B308(u8 *arg0)
{
    u8 *v;
    s32 i;
    vu0_v4 p;
    u8 m[0x40];
    vu0_v4 d;

    v = *(u8 **)(arg0 + 0x68);
    for (i = 0; i < 2; i++) {
        func_003C2F58(*(s32 *)(v + 0x3EC), 2, &p);
        func_003C2EC0(*(void **)(v + 0x3EC), 2, m);
        func_0038D028(&d, D_L05_001DD6F0 + i * 0x10, m);
        vec_add_ab(&p, &p, &d);
        func_003C5458(&p, D_L05_001DD710[i], D_L05_001DD6E0[i], D_L05_001DD6D8[i]);
    }
}
/* localdecomp:end func_L05_0035B308 */

INCLUDE_ASM("asm/levels", func_L05_0035B3F0);

INCLUDE_ASM("asm/levels", func_L05_0035CE98);

INCLUDE_ASM("asm/levels", func_L05_0035D078);

/* localdecomp:start func_L05_0035D300 */
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
extern void func_L01_004443E8(u8 *, s32, s32);
extern void func_003C2880(u8 *);

void func_L05_0035D300(u8 *arg0)
{
    u8 *v;
    s32 i;
    u8 *e;

    v = *(u8 **)(arg0 + 104);
    i = *(s32 *)(v + 748);
    if (i != -1) {
        e = D_001A30B0 + (i << 7);
        if (*(u8 **)(e + 220) == arg0 && e[208] != 0) {
            func_003A4F28(i);
        }
    }
    *(s32 *)(v + 748) = -1;
    func_L01_004443E8(arg0, 0, 3);
    func_003C2880(arg0);
}
/* localdecomp:end func_L05_0035D300 */

INCLUDE_ASM("asm/levels", func_L05_0035D388);

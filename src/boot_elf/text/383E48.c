#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 383AA8.c's earlier functions */
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern f32 func_003C3FA0(f32, f32, f32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_00222480[];
extern void (*D_001D9A40[2])(s32);
extern void func_0038DE98(f32, f32);
extern f32 func_0038DEE0(f32, f32);
extern f32 func_0038D248(void *, void *);
extern f32 func_0038D288(void *);
extern f32 func_0038D4A8(f32);
extern void func_0038DC70(void *, void *, void *, f32);
extern void func_0038D348(s32 a, s32 b, f32 x);
extern void func_003838B0();
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_00222720[];

/* localdecomp:start func_00383E48 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00383E48;
typedef union { u128_t q; struct { f32 x, y, z, w; } v; } U_00383E48;
typedef struct {
    f32 f0, f4; u8 p8[8]; f32 f10, f14; u8 p18[8];
    V_00383E48 v20; V_00383E48 v30; U_00383E48 u40; u8 m50[0x40];
} B_00383E48;
typedef struct { u8 p0[0x30]; f32 f30, f34, f38; u8 p3C[0x94 - 0x3C]; s32 f94; } O_00383E48;
typedef struct { u128_t q0; u8 p10[0x1C0 - 0x10]; V_00383E48 v1C0; u8 p1D0[0x380 - 0x1D0]; u8 m380[0x40]; u8 p3C0[0x460 - 0x3C0]; } E_00383E48;
extern E_00383E48 D_00222480_00383E48[];
extern void func_003C4BA0(void *, void *);
extern void func_0038D970(void *, void *);
extern void func_0038DAA8_00383E48(void *, void *, void *, f32);
extern void func_0038DC10_00383E48(void *, void *);

/* the engine's quadword copy (rac2-decomp's qcopy) */
static __inline__ void qcopy_00383E48(void *d, void *s) {
    *(u128_t *)d = *(u128_t *)s;
}

s32 func_00383E48(void *arg, void *state) {
    O_00383E48 *o = arg;
    B_00383E48 *s = state;
    V_00383E48 v;
    u128_t matrix[4];
    f32 t;

    if (s->f10 == 1.0f && s->f0 == 1.0f) {
        return 1;
    }
    t = func_003C3FA0(0.0f, 1.0f, s->f10);
    vec_add_ba(&s->v30, &D_00222480_00383E48[o->f94].v1C0, &s->v30);
    s->u40.v.x = s->v30.x + (o->f30 - s->v30.x) * t;
    s->u40.v.y = s->v30.y + (o->f34 - s->v30.y) * t;
    s->u40.v.z = s->v30.z + (o->f38 - s->v30.z) * t;
    qcopy_00383E48(&D_00222480_00383E48[o->f94].q0, &s->u40);
    func_003C4BA0(&v, o);
    t = func_003C3FA0(0.0f, 1.0f, s->f0);
    func_0038DAA8_00383E48(s->m50, &s->v20, &v, t);
    func_0038DC10_00383E48(s->m50, matrix);
    func_0038D970(D_00222480_00383E48[o->f94].m380, matrix);
    s->f10 += s->f14 * 1.2f;
    if (s->f10 > 1.0f) {
        s->f10 = 1.0f;
    }
    s->f0 += s->f4 * 1.2f;
    if (s->f0 > 1.0f) {
        s->f0 = 1.0f;
    }
    return 0;
}
/* localdecomp:end func_00383E48 */

typedef struct { f32 f0, f4, f8, fC, f10, f14, f18, f1C; } A_37F588;
typedef struct { s32 p0[3]; s32 fC; f32 f10; s32 f14; } R_37F588;
typedef struct {
    s16 f0; u8 b2; u8 b3; u8 p4[0xC]; A_37F588 a; u128_t q30; u128_t q40; u128_t q50; u128_t q60; R_37F588 r;
} E_37F588;
extern u8 D_00222480_00383C18[];
extern void func_003C4BA0();
typedef int Q_37F7A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F7A8;
typedef struct { f32 f0, f4; u8 p8[8]; f32 f10, f14; u8 p18[8]; V_37F7A8 v20; V_37F7A8 v30; u128_t q40; u8 m50[0x40]; } B_37F7A8;
typedef struct { u8 p0[0x30]; f32 f30, f34, f38; u8 p3C[0x94 - 0x3C]; s32 f94; } O_37F7A8;
typedef struct { u128_t q0; u8 p10[0x1C0 - 0x10]; V_37F7A8 v1C0; u8 p1D0[0x380 - 0x1D0]; u8 m380[0x40]; u8 p3C0[0x460 - 0x3C0]; } E_37F7A8;
extern E_37F7A8 D_00222480_00383E38[];
extern void func_003C4BA0(void *, void *);
extern void func_0038D970(void *, void *);
extern void func_0038DAA8_00383E38(void *, void *, void *, f32);
extern void func_0038DC10_00383E38(void *, void *);
extern f32 func_003C3FA0(f32, f32, f32);
/* localdecomp:start func_00384028 */
#include "vu0.h"
extern void func_0038D270_00384028(void *, void *, void *);
extern void func_0038DBF0_00384028(void *, void *);
extern void func_0038D200(f32 *, void *, f32);
extern void func_003C4BF8(f32 *, void *, f32);
extern void func_0038DC30_00384028(void *, void *, void *);
extern s32 func_0038CEB0(void *);
s32 func_00384028(u8 *obj, u8 *state) {
    vu0_v4 angles, a, cross, b, base, offset, diff, projected;
    vu0_v4 basis[3], turnedA, turnedB, full, rotation;
    f32 fraction, delta, angle, sign, step, dot, height;
    u8 *entry, *model;
    if (*(s32 *)(state + 0xC) <= 0) return 1;
    entry = (u8 *)&D_00222480[*(s32 *)(obj + 0x94)];
    fraction = 1.0f / func_003C3FA0(1.0f, (f32)*(s32 *)(state + 0x14), (f32)*(s32 *)(state + 0xC) * *(f32 *)(state + 0x10));
    model = entry + 0x150;
    if (entry[0x2A2] == 2) {
        base = *(vu0_v4 *)(entry + 0x190);
        a = *(vu0_v4 *)(state + 0x20);
        b = *(vu0_v4 *)(state + 0x30);
        func_0038D270_00384028(&cross, &a, &b);
        func_003838B0(&angles, obj + 0x30, &base, &a, &cross, &b);
    } else {
        base = *(vu0_v4 *)(obj + 0x30);
        func_0038D348((s32)&a, *(s32 *)(model + 0xF0) + 0xC0, 1.0f);
        func_0038D348((s32)&b, *(s32 *)(model + 0xF0) + 0xE0, 1.0f);
        angles.z = 0.0f; angles.x = 3.1415927f; angles.y = 0.0f;
    }
    delta = func_0038DEE0(angles.x, *(f32 *)state);
    *(f32 *)state = ((f32 (*)(f32, f32))func_0038DE98)(*(f32 *)state, delta * fraction);
    *(f32 *)(state + 4) = ((f32 (*)(f32, f32))func_0038DE98)(*(f32 *)(state + 4), func_0038DEE0(angles.y, *(f32 *)(state + 4)) * fraction);
    *(f32 *)(state + 8) += (angles.z - *(f32 *)(state + 8)) * fraction;
    func_0038D348((s32)&offset, (s32)&a, *(f32 *)(state + 8));
    func_0038DC70(&offset, &offset, &b, *(f32 *)state);
    func_0038D270_00384028(&cross, &offset, &b);
    func_0038D348((s32)&cross, (s32)&cross, 1.0f);
    func_0038DC70(&offset, &offset, &cross, *(f32 *)(state + 4));
    vec_add_ba(state + 0x50, &base, &offset);
    *(vu0_v4 *)entry = *(vu0_v4 *)(state + 0x50);
    func_0038DBF0_00384028(state + 0x40, basis);
    height = func_0038D248(&basis[2], obj);
    func_0038D200((f32 *)&projected, &basis[2], height);
    vec_sub_ba(&diff, obj, &projected);
    dot = func_0038D248(&basis[0], &diff);
    angle = 1.5707964f - func_0038D4A8(dot / func_0038D288(&diff));
    sign = func_0038D248(&diff, &basis[1]) >= 0.0f ? 1.0f : -1.0f;
    angle *= sign;
    if (fabs_asm(delta) > 1.5707964f && ((delta >= 0.0f && sign < 0.0f) || (delta < 0.0f && sign >= 0.0f))) {
        if (angle < 0.0f) angle += 6.2831855f;
        else angle -= 6.2831855f;
    }
    step = angle * fraction;
    if (fabs_asm(step) < 0.00001f) {
        turnedA = basis[0]; turnedB = basis[1];
    } else {
        func_003C4BF8((f32 *)&full, &basis[2], step);
        func_0038DC30_00384028(&turnedA, &basis[0], &full);
        func_0038DC30_00384028(&turnedB, &basis[1], &full);
    }
    if (fabs_asm(angle) < 0.00001f) full = basis[0];
    else {
        func_003C4BF8((f32 *)&rotation, &basis[2], angle);
        func_0038DC30_00384028(&full, &basis[0], &rotation);
    }
    angle = 1.5707964f - func_0038D4A8(func_0038D248(&full, obj));
    sign = func_0038D248(&full, obj + 0x20) >= 0.0f ? 1.0f : -1.0f;
    angle *= sign;
    func_0038DC70(&turnedA, &turnedA, &turnedB, angle * fraction);
    func_0038D348((s32)(entry + 0x380), (s32)&turnedA, 1.0f);
    func_0038D270_00384028(entry + 0x390, entry + 0x380, model + 0x80);
    func_0038D348((s32)(entry + 0x390), (s32)(entry + 0x390), -1.0f);
    func_0038D270_00384028(entry + 0x3A0, entry + 0x390, entry + 0x380);
    func_003C4BA0(state + 0x60, entry + 0x380);
    func_003C4BA0(state + 0x40, entry + 0x380);
    func_0038CEB0(state + 0xC);
    return 0;
}
/* localdecomp:end func_00384028 */

extern u8 D_00222720[];
extern u8 D_00222480_00384598[];
extern s32 func_00384028();
/* localdecomp:start func_00384598 */
typedef int Q_00384598 __attribute__((mode(TI)));
extern u8 D_00222720[];
extern u8 D_00222480_00384598[];
void func_00384598(u8 *arg) {
    extern s32 func_00383E48(void *,void *);
    extern s32 func_00384028();
    u8 *p = D_00222480_00384598 + 0x2A0 + *(s32 *)(arg+0x94)*0x460;
    s32 ok;
    if(p[2]==0) ok=func_00383E48(arg,p+0x10);
    else ok=func_00384028(arg,p+0x70);
    if(ok) {
        u8 *q = D_00222480_00384598 + *(s32 *)(arg+0x94)*0x460;
        *(Q_00384598 *)(q+0x380)=*(Q_00384598 *)(arg+0);
        *(Q_00384598 *)(q+0x390)=*(Q_00384598 *)(arg+0x10);
        *(Q_00384598 *)(q+0x3A0)=*(Q_00384598 *)(arg+0x20);
        *(Q_00384598 *)(q)=*(Q_00384598 *)(arg+0x30);
        *(s16 *)p=0;
        p[2]=0;
    }
}
/* localdecomp:end func_00384598 */

/* localdecomp:start func_00384640 */
#include "vu0.h"
typedef struct { f32 strength, value; s32 timer, duration; } Shake_00384640;
extern f32 D_001D57B4;
__asm__(".extern D_001D57B4, 4");
extern s32 func_0038CEB0(void *);
extern f32 func_0038DF28(f32);
extern void func_003C50A0_00384640(void *, void *, f32);
extern void func_0038DBF0_00384640(void *, void *);
extern void func_0038D9D0_00384640(void *, void *, void *);
void func_00384640(s32 player, Shake_00384640 *shake, s32 mode) {
    vu0_v4 v;
    vu0_v4 matrix[3];
    u8 *entry = (u8 *)&D_00222480[player];
    f32 ratio, cube, elapsed, fade, angle;
    if (*(u8 **)(entry + 0x50) && *(s16 *)(*(u8 **)(entry + 0x50) + 0x86) == 6) {
        shake->timer = 0;
        shake->duration = 0;
    } else if (shake->timer != 0) {
        if (shake->duration < shake->timer) shake->duration = shake->timer;
        func_0038CEB0(&shake->timer);
        ratio = (f32)shake->timer / (f32)shake->duration;
        switch (mode) {
        case 0:
            shake->value = shake->strength * func_0038D478(func_0038DF28((f32)shake->timer * 2.0f)) * ratio * ratio;
            func_0038D348((s32)&v, (s32)(entry + 0x3A0), shake->value);
            vec_add_ab(entry, entry, &v);
            break;
        case 1:
            shake->value = shake->strength * func_0038D478(func_0038DF28((f32)shake->timer * 2.0f)) * ratio * ratio;
            func_0038D348((s32)&v, (s32)(entry + 0x380), shake->value);
            vec_add_ab(entry, entry, &v);
            break;
        case 2:
            cube = ratio * ratio * ratio;
            elapsed = (f32)(shake->duration - shake->timer) / 50.33333206176758f;
            fade = elapsed * 6.0f;
            angle = D_001D57B4 * 0.01745329238474369f;
            if (fade > 1.0f) fade = 1.0f;
            shake->value = shake->strength * func_0038D490(func_0038DF28(elapsed * angle - angle * 8.0f)) * cube * fade;
            func_003C50A0_00384640(&v, entry + 0x380, shake->value);
            func_0038DBF0_00384640(&v, matrix);
            func_0038D9D0_00384640(entry + 0x380, matrix, entry + 0x380);
            break;
        }
    } else {
        shake->duration = 0;
    }
}
/* localdecomp:end func_00384640 */

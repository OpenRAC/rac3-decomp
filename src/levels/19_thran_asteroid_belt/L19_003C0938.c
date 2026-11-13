#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { char p[0x444]; int f444; char q[0x470-0x448]; u128_t v; } B;
typedef struct { char p[0x10]; u128_t v; char q[0x68-0x20]; B *b; } A;

/* localdecomp:start func_L19_003C0938 */
extern void func_L19_003C2628(void *, void *, int, float);

void func_L19_003C0938(char *m) {
    func_L19_003C2628(m, m + 0x10, 3, *(float *)(m + 0xF8));
}
/* localdecomp:end func_L19_003C0938 */

INCLUDE_ASM("asm/levels", func_L19_003C0960);

INCLUDE_ASM("asm/levels", func_L19_003C1F18);

INCLUDE_ASM("asm/levels", func_L19_003C2388);

/* localdecomp:start func_L19_003C2628 */
typedef struct { f32 x, y, z, w; } V_3C2628 __attribute__((aligned(16)));
__asm__(".extern D_L19_001DE800, 4");
__asm__(".extern D_L19_001DE840, 4");
__asm__(".extern D_L19_001DE808, 8");
__asm__(".extern D_L19_001DE820, 8");
extern s32 D_L19_001DE800;
extern f32 D_L19_001DE840;
extern f32 D_L19_001DE808[2];
extern f32 D_L19_001DE820[2];
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045AA10(void *, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern void func_L01_0045A748(void *, void *);
extern void func_L01_0045AA30(void *, void *);

void func_L19_003C2628(void *objp, void *a5, int state, float fv) {
    u8 *obj = objp;
    u8 *p = *(u8 **)(obj + 0x68);
    V_3C2628 v;
    f32 s;

    if (state != *(s32 *)(p + 0x418)) {
        if (state == 2)
            *(f32 *)(obj + 0x48) = D_L19_001DE840;
        if (D_L19_001DE800 != 0)
            *(f32 *)(obj + 0x48) = 0.1f;
        s = *(f32 *)(obj + 0x48);
        func_L01_0045BD78(obj, D_L19_001DE820[state] * s, D_L19_001DE808[state] * s, s * 0.0050265486f, s * 0.12566371f);
        if (state == 3)
            *(s32 *)(p + 0xA8) = 0x514;
        else
            *(s32 *)(p + 0xA8) = 0;
    }
    *(s32 *)(p + 0x418) = state;
    switch (state) {
    case 0:
        func_L01_0045AA10(obj, fv);
        func_L01_0045BD10(obj, fv);
        break;
    case 1:
    case 2:
        func_L01_0045A748(obj, a5);
        break;
    case 3:
        v = *(V_3C2628 *)(p + 0x110);
        v.z = *(f32 *)(p + 0x448);
        *(f32 *)(p + 0x448) = *(f32 *)(p + 0x448) - (*(f32 *)(p + 0x9C) + *(f32 *)(p + 0x9C));
        func_L01_0045AA30(obj, &v);
        break;
    }
}
/* localdecomp:end func_L19_003C2628 */

/* localdecomp:start func_L19_003C27A8 */
typedef struct { f32 x, y, z, w; } V_3C27A8 __attribute__((aligned(16)));
extern u8 D_001A71C4[];
extern u8 *D_001A73E8[];
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern f32 func_L01_004395E0(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_L01_00446780(u8 *, void *, f32, s32, s32, s32, s32, f32, f32);

void func_L19_003C27A8(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    V_3C27A8 a;
    V_3C27A8 b;
    V_3C27A8 c;
    f32 f;
    f32 f13;
    u8 r = 0;

    if (*(s32 *)(p + 0x41C) == 2) {
        func_003C2F58(obj, 1, (u8 *)&a);
        func_003C2F58(obj, 2, (u8 *)&b);
        f = func_L01_004395E0(obj);
        r = 20.0f <= f;
    } else if (*(s32 *)(p + 0x41C) == 1) {
        func_003C2F58(obj, 3, (u8 *)&a);
        func_003C2F58(obj, 4, (u8 *)&b);
        f = func_L01_004395E0(obj);
        r = 9.0f <= f;
    }
    if (*(s32 *)(p + 0x45C) == 0 && D_001A73E8[0] == obj)
        *(s32 *)(p + 0x45C) = 1;
    if (r != 0) {
        vec_sub_ab(&c, &b, &a);
        func_0038CE20(&c, &c, 0.5f);
        f = func_0038CEA8(&c);
        vec_add_ab(&c, &c, &a);
        f13 = (f32)p[0x44];
        if (D_001A71C4[0] == 1)
            f13 = 1.0f;
        func_L01_00446780(obj, &c, f, 1, 0, 1, 0, f13, 1.0f);
    }
}
/* localdecomp:end func_L19_003C27A8 */

/* localdecomp:start func_L19_003C2930 */
void func_0038CAD0(s32);
void func_0038CB00(s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L19_001E2100[];

void func_L19_003C2930(void *arg0) {
    s32 temp_s1;
    u16 temp_v1;

    temp_s1 = *(s32 *)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L19_001E2100, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
    func_0038CB00(temp_s1 + 0x414);
    func_0038CB00(temp_s1 + 0x416);
    func_0038CAD0(temp_s1 + 0x458);
}
/* localdecomp:end func_L19_003C2930 */

/* localdecomp:start func_L19_003C29D0 */
extern void func_L01_004450F0(void *, int, int);
extern void func_003C2880(A *);
void func_L19_003C29D0(A *a) {
    B *b = a->b;
    if (b->f444 != 0) {
        a->v = b->v;
        func_L01_004450F0(a, 1, 1);
    } else {
        func_003C2880(a);
    }
}
/* localdecomp:end func_L19_003C29D0 */

/* localdecomp:start func_L19_003C2A20 */
void func_L01_004443E8(s32, s32, s32);
void func_L01_00315900(void *, s32, void *);
extern u8 D_L19_003C29D0[];

void func_L19_003C2A20(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_L01_004443E8((s32) arg0, 0, 3);
    if ((*(s32 *)((u8 *)temp_s0 + 0x444)) != 0) {
        *(s8 *)((u8 *)arg0 + 0x7F) = 0;
        *(u16 *)((u8 *)arg0 + 0xB6) = (u16) ((u16) (*(u16 *)((u8 *)arg0 + 0xB6)) >> 1);
        *(u16 *)((u8 *)arg0 + 0xB4) = (u16) ((s32) ((*(u16 *)((u8 *)arg0 + 0xB4)) << 0x10) >> 0x11);
    }
    func_L01_00315900(arg0, 0, D_L19_003C29D0);
}
/* localdecomp:end func_L19_003C2A20 */

/* localdecomp:start func_L19_003C2A98 */
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
__asm__(".extern D_L19_001DF71C, 16");
extern s32 D_L19_001DF758;
extern void func_L01_004450F0(void *a0, s32 a1, s32 a2);

void func_L19_003C2A98(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L19_0021C260[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L19_001DF758 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L19_0021C260[a0[0x21]])) {
        e = D_L19_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (e != a0 && *(s16 *)(e + 0xAA) == 0x1C13) {
            if (e[0x20] == 2) {
                func_L01_004450F0(e, 3, e[0x95]);
            } else if (e[0x95] == 4) {
                if (e[0x20] != 0x10 && e[0x20] != 1 && e[0x20] != 0x11) {
                    func_L01_004450F0(e, 8, 5);
                }
            }
        }
        p++;
    }
}
/* localdecomp:end func_L19_003C2A98 */

/* localdecomp:start func_L19_003C2BC0 */
s32 func_L19_003C2BC0(void *arg0) {
    s32 var_a1;

    var_a1 = 0;
    if ((arg0 != 0) && ((*(s16 *)((u8 *)arg0 + 0xAA)) == 0x1C13)) {
        var_a1 = (*(u8 *)((u8 *)arg0 + 0x95)) == 1;
    }
    return var_a1;
}
/* localdecomp:end func_L19_003C2BC0 */

/* localdecomp:start func_L19_003C2BF0 */
extern f32 func_0038D160(f32, f32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L19_003C2BF0(u8 *obj, u128_t *a1, f32 *v) {
    u8 *p;
    u8 *t;
    u16 flags;
    f32 f;

    qzero(obj + 0xF0);
    p = *(u8 **)(obj + 0x68);
    *(u128_t *)(obj + 0x10) = *a1;
    *(u128_t *)(p + 0x110) = *(u128_t *)v;
    *(f32 *)(obj + 0xF8) = func_0038D160(v[0], v[1]);
    *(s32 *)(p + 0x118) = 0;
    *(f32 *)(p + 0x448) = v[2];
    p[0x60] = 0;
    *(f32 *)(p + 0x30) = (f32)*(s16 *)(p + 0x34);
    *(s16 *)(p + 0x198) = 0;
    p[0x5E] = 0;
    p[0x5F] = 0;
    *(s32 *)(p + 0x68) = 0;
    p[0x3E] = 3;
    t = *(u8 **)(obj + 0x24);
    f = *(f32 *)(t + 0x24);
    flags = *(u16 *)(obj + 0x34) & 0xFFBE;
    *(u16 *)(obj + 0x34) = flags;
    *(f32 *)(obj + 0x2C) = f;
    *(u16 *)(obj + 0x34) = flags | (*(u16 *)(t + 0x44) & 0x1000);
    *(s32 *)(obj + 0x98) = *(s32 *)(t + 0x10);
    func_L01_004450F0(obj, 5, 3);
}
/* localdecomp:end func_L19_003C2BF0 */

INCLUDE_ASM("asm/levels", func_L19_003C2CC8);

/* localdecomp:start func_L19_003C3788 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L19_003C3898(void *);
extern void func_L01_0043A430(void *, s32, void *);
extern void func_0038D750(void *, s32, f32);

void func_L19_003C3788(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    f32 f0;
    f32 f1;

    p[0x58] = 10;
    p[0x5A] = 4;
    *(f32 *)(p + 0x40) = 0.5f;
    p[0x3E] = 3;
    p[0x39] = 0;
    p[0x63] = 0;
    p[0x3F] = 0;
    p[0x64] = 0;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 10;
        *(f32 *)(p + 0x30) = 10.0f;
    }
    *(s32 *)(p + 0x9C) = 0;
    *(s32 *)(p + 0xA8) = 0;
    *(s32 *)(p + 0xB4) = 0;
    *(s32 *)(p + 0xAC) = 0;
    *(s32 *)(p + 0xA0) = -1;
    func_L19_003C3898(obj);
    func_L01_0043A430(obj, 0, p + 0xC0);
    func_L01_0043A430(obj, 1, p + 0x100);
    f0 = *(f32 *)(p + 0xAC);
    f1 = *(f32 *)(p + 0xB8);
    *(f32 *)(p + 0xB0) = f0;
    *(f32 *)(p + 0xBC) = f1;
    func_0038D750(p + 0xD0, 2, f0);
    func_0038D750(p + 0x110, 1, 1.5707964f - *(f32 *)(p + 0xBC));
    func_L01_004450F0(obj, 1, -1);
}
/* localdecomp:end func_L19_003C3788 */

/* localdecomp:start func_L19_003C3898 */
typedef struct { f32 x, y, z, w; } V_3C3898 __attribute__((aligned(16)));
typedef struct { u8 pad[0x12]; s16 h12; u8 pad2[0xC]; s32 *x20; u8 pad3[0xC]; } E_3C3898;
typedef struct { u8 pad[0x20]; E_3C3898 e[1]; } T_3C3898;
typedef struct { u8 pad[0x30]; V_3C3898 v; u8 pad2[0x40]; } P_3C3898;
typedef struct { u8 pad[0x84]; s32 x84; u8 pad2[0x14]; s32 x9C; u8 pad3[0xC]; f32 xAC; u8 pad4[8]; f32 xB8; } Q_3C3898;
extern T_3C3898 *D_L19_001DF34C;
extern P_3C3898 *D_L19_001DF800;
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_003824E0(f32, f32);

void func_L19_003C3898(void *objp) {
    u8 *obj = objp;
    Q_3C3898 *p = *(Q_3C3898 **)(obj + 0x68);
    E_3C3898 *e = &D_L19_001DF34C->e[p->x84];
    V_3C3898 v;
    f32 a;

    if (e->h12 == 1) {
        p->x9C = 0;
        v = D_L19_001DF800[e->x20[0]].v;
    } else {
        P_3C3898 *tab = D_L19_001DF800;
        s32 n = (p->x9C + 1) % e->h12;

        p->x9C = n;
        v = tab[e->x20[n]].v;
    }
    a = func_0038D160(v.x - *(f32 *)(obj + 0x10), v.y - *(f32 *)(obj + 0x14));
    p->xAC = func_0038DB48(a - *(f32 *)(obj + 0xF8));
    p->xB8 = func_003824E0(0.5235988f, 1.0471976f);
}
/* localdecomp:end func_L19_003C3898 */

/* localdecomp:start func_L19_003C3998 */
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
__asm__(".extern D_L19_001DF71C, 16");
extern s32 D_L19_001DF758;
extern s32 func_L19_003C2BC0(void *a);

s32 func_L19_003C3998(u8 *object) {
    u8 *o = *(u8 **)(object + 0x68);
    s32 count;
    u16 *p;
    u8 *e;
    if (*(s32 *)(o + 0x80) < 0)
        return 0;
    count = 0;
    p = D_L19_0021C260[*(s32 *)(o + 0x80)];
    while ((*(s32 *)(o + 0x80) & 0xFF) != 0xFF && D_L19_001DF758 >= *(s32 *)(o + 0x80) && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L19_0021C260[*(s32 *)(o + 0x80)])) {
        e = D_L19_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        p++;
        if (func_L19_003C2BC0(e))
            count++;
    }
    return count;
}
/* localdecomp:end func_L19_003C3998 */

/* localdecomp:start func_L19_003C3A78 */
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
__asm__(".extern D_L19_001DF71C, 16");
extern s32 D_L19_001DF758;
extern s32 func_L19_003C2BC0(void *e);

u8 *func_L19_003C3A78(u8 *object) {
    u16 *p;
    u8 *e;
    u8 *vars = *(u8 **)(object + 0x68);
    if (*(s32 *)(vars + 0x80) < 0)
        return 0;
    p = D_L19_0021C260[*(s32 *)(vars + 0x80)];
    while ((*(s32 *)(vars + 0x80) & 0xFF) != 0xFF && *(s32 *)(vars + 0x80) <= D_L19_001DF758 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L19_0021C260[*(s32 *)(vars + 0x80)])) {
        e = D_L19_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return 0;
        if (func_L19_003C2BC0(e) != 0)
            return e;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L19_003C3A78 */

/* localdecomp:start func_L19_003C3B60 */
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, f32, u32, u32, u32, u32);

void func_L19_003C3B60(u8 *self) {
    V_3C3898 base;
    V_3C3898 p;
    u8 *v = *(u8 **)(self + 0x68);
    E_3C3898 *e;

    func_003C2F58(self, 0, (u8 *)&base);
    p.x = func_0038D098(func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xAC))) * 10.0f;
    p.y = func_0038D0B0(func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xAC))) * 10.0f;
    p.z = 0.0f;
    vec_add_ba(&p, &p, &base);
    func_L01_0040A8C0(&base, &p, 0x16, 1, 0.025f, 1.0f, 0.0f, 0x60000080, 0x60000080, 0x60000080, 0x60000080);
    p.x = func_0038D098(func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xB0))) * 5.0f;
    p.y = func_0038D0B0(func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xB0))) * 5.0f;
    p.z = 0.0f;
    vec_add_ba(&p, &p, &base);
    func_L01_0040A8C0(&base, &p, 0x16, 1, 0.1f, 1.0f, 0.0f, 0x40000040, 0x40000040, 0x40000040, 0x40000040);
    func_00382760(&p, 10.0f, func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xAC)), *(f32 *)(v + 0xB8));
    vec_add_ab(&p, &p, &base);
    func_L01_0040A8C0(&base, &p, 0x16, 1, 0.025f, 1.0f, 0.0f, 0x60008000, 0x60008000, 0x60008000, 0x60008000);
    func_00382760(&p, 5.0f, func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xAC)), *(f32 *)(v + 0xBC));
    vec_add_ab(&p, &p, &base);
    func_L01_0040A8C0(&base, &p, 0x16, 1, 0.1f, 1.0f, 0.0f, 0x40004000, 0x40004000, 0x40004000, 0x40004000);
    e = (E_3C3898 *)((u8 *)D_L19_001DF34C->e + *(s32 *)(v + 0x84) * 0x30);
    p = D_L19_001DF800[e->x20[*(s32 *)(v + 0x9C)]].v;
    func_L01_0040A8C0(&base, &p, 0x16, 1, 0.05f, 1.0f, 0.0f, 0x60808080, 0x60808080, 0x60808080, 0x60808080);
}
/* localdecomp:end func_L19_003C3B60 */

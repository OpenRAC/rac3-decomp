#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct Obj_003951E8 {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    u8 pad18[8];
    u8 b20;
    u8 pad21[0x10];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0xC];
    u8 b42;
    u8 b43;
    u8 pad44[0x24];
    struct St_003951E8 *st;
    u8 pad6C[0x54];
    vu0_v4 v0C0;
    u8 padD0[0x28];
    f32 fF8;
    u8 padFC[4];
} Obj_003951E8;
typedef struct St_003951E8 {
    u8 pad0[0xB4];
    Obj_003951E8 *fB4;
    u8 padB8[0x68];
    vu0_v4 v120;
    vu0_v4 v130;
    s32 f140;
    u8 pad144[4];
    s32 f148;
    s32 f14C;
    u8 pad150[8];
    s32 f158;
    s16 h15C;
    s16 h15E;
    u8 pad160[0x14];
    Obj_003951E8 *f174;
    u8 pad178;
    u8 b179;
    s16 h17A;
} St_003951E8;
typedef struct {
    s32 n;
    u8 pad4[0xC];
    vu0_v4 pt[1];
} Path_003951E8;

typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L03_003967C8 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_q v10; u8 pad20[0x40]; s32 f68; u8 pad6C[0x84]; vu0_q vF0; } A_003967C8;
typedef struct { u8 pad0[0x30]; u8 b30[0x40]; u8 b70[0x30]; vu0_q vA0; vu0_q vB0; s32 fC0; } P_003967C8;
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C4DA8(void *, void *, void *, void *);
extern void func_L03_0043C610(void *, void *, s32);
void func_L03_003967C8(void *arg) {
    A_003967C8 *a = arg;
    P_003967C8 *p = *(P_003967C8 **)((u8 *)arg + 0x68);
    vu0_v4 v;
    if (*(u8 *)((u8 *)arg + 0x20) == 0) {
        p->vA0 = a->v10;
        p->vB0 = a->vF0;
        func_L01_004450F0(arg, 1, -1);
    }
    vec_sub_ba(&v, &a->v10, &p->vA0);
    func_003C4DA8(p->b30, &v, &p->vB0, &a->vF0);
    func_L03_0043C610(arg, p->b70, p->fC0);
    p->vA0 = a->v10;
    p->vB0 = a->vF0;
}
/* localdecomp:end func_L03_003967C8 */

/* localdecomp:start func_L03_00396860 */
/* PAL port of the NTSC-U match src/us/levels/func_L03_003951E8.c */
#include "vu0.h"


extern u8 *D_L03_001DF99C;
extern u128_t *D_L03_0021D8C0[];
extern s32 D_L03_001D6694_003951E8;
extern void func_L03_00396E00(u8 *self);
extern s32 func_L01_004BA800(void);
extern void func_L03_00396FF0(void *);
extern s32 func_L01_0045A748(void *, void *);
extern s32 func_L03_00397260(void *);
extern s32 func_L01_00446720(void);
extern void func_L03_00397138(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_L03_003971B0(void *);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045AA10(void *, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0045A9F0(void *);
extern s32 func_0038CB00(void *);

void func_L03_00396860(Obj_003951E8 *o) {
    St_003951E8 *s;
    Path_003951E8 *path;
    Path_003951E8 *path2;
    s32 flags;
    Obj_003951E8 *other;
    s32 dir;
    f32 ang;
    f32 d;

    if (o->b20 == 0) {
        func_L03_00396E00(o);
    }
    if (o != 0 && o->b20 != 0xFE && o->b20 != 0xFD) {
        s = o->st;
        if (D_L03_001D6694_003951E8 == 2) {
            o->b31 = 0;
            o->h34 = o->h34 | 1;
            ((Obj_003951E8 *)D_L03_001DF99C)[s->f140].h34 = ((Obj_003951E8 *)D_L03_001DF99C)[s->f140].h34 | 1;
            ((Obj_003951E8 *)D_L03_001DF99C)[s->f140].b31 = 0;
            return;
        }
        if (func_L01_004BA800() == 0) {
            o->b31 = 1;
            o->h34 = o->h34 & 0xFFFE;
            ((Obj_003951E8 *)D_L03_001DF99C)[s->f140].h34 = ((Obj_003951E8 *)D_L03_001DF99C)[s->f140].h34 & 0xFFFE;
            ((Obj_003951E8 *)D_L03_001DF99C)[s->f140].b31 = 1;
        }
        if (o->h34 & 2) {
            return;
        }
        func_L03_00396FF0(o);
        switch (o->b20) {
        case 1:
            break;
        case 2:
            flags = func_L01_0045A748(o, &s->v120);
            func_L03_00397260(o);
            if (s->fB4 != 0) {
                if (s->f148 != -1 && s->fB4 == ((Obj_003951E8 *)D_L03_001DF99C) + s->f148) {
                    goto walk;
                }
                if (s->f158 != -1 && s->fB4 == ((Obj_003951E8 *)D_L03_001DF99C) + s->f158) {
                    goto walk;
                }
                if (func_L01_00446720() == 0) {
                    s->f174 = s->fB4;
                    func_L03_00397138(o, 6, 0, 10);
                    func_L01_004450F0(o, 5, -1);
                    return;
                }
            }
        walk:
            if (flags & 0x80) {
                path2 = (Path_003951E8 *)D_L03_0021D8C0[s->f14C];
                s->h15C = s->h15C + s->h15E;
                if (s->h15C >= path2->n) {
                    s->h15C = path2->n - 2;
                    s->h15E = -1;
                }
                if (s->h15C < 0) {
                    s->h15C = 1;
                    s->h15E = 1;
                }
                s->v120 = *(&path2->pt[0] + s->h15C);
                s->v130 = o->v0C0;
                if (func_L03_003971B0(o) < 0.0f) {
                    func_L01_004450F0(o, 3, -1);
                    return;
                }
            }
            break;
        case 5:
            d = func_L01_0040E570(&s->f174->x, &o->x);
            if (!(16.0f < d)) {
                if (func_L03_00397260(o) == 0) {
                    break;
                }
            }
            func_L03_00397138(o, 2, 0, 8);
            func_L01_004450F0(o, 2, -1);
            return;
        case 3:
            if (o->b42 == 2) {
                ang = func_0038D160(s->v120.x - o->x, s->v120.y - o->y);
                func_L01_0045AA10(o, ang);
                d = func_0038DBA0(ang, o->fF8);
                if (d < 0.08726646f) {
                    if (o->b43 != 0) {
                        func_003C3A10(o, 0, 0, 7);
                    }
                }
            } else {
                func_L01_0045A9F0(o);
            }
            if (func_L03_003971B0(o) >= 0.0f) {
                if (s->b179 ? s->h15E == 1 : s->h15E == -1) {
                    goto fin3;
                }
                s->h17A = 42;
                func_L01_004450F0(o, 4, -1);
                return;
            }
            other = ((Obj_003951E8 *)D_L03_001DF99C) + s->f148;
            if (other->b20 != 3) {
                return;
            }
            dir = s->h15C < other->st->h15C ? 1 : -1;
            if (dir != s->h15E) {
                path = (Path_003951E8 *)D_L03_0021D8C0[s->f14C];
                s->h15E = dir;
                s->h15C = s->h15C + dir;
                if (s->h15C >= path->n) {
                    s->h15C = path->n - 2;
                    s->h15E = -1;
                }
                if (s->h15C < 0) {
                    s->h15C = 1;
                    s->h15E = 1;
                }
                s->v120 = *(&path->pt[0] + s->h15C);
            }
        fin3:
            if (o->b43 != 2) {
                func_003C3A10(o, 2, 0, 7);
            }
            func_L01_004450F0(o, 2, -1);
            return;
        case 4:
            if (o->b42 == 2) {
                ang = func_0038D160(s->v120.x - o->x, s->v120.y - o->y);
                func_L01_0045AA10(o, ang);
                d = func_0038DBA0(ang, o->fF8);
                if (d < 0.08726646f) {
                    if (o->b43 != 0) {
                        func_003C3A10(o, 0, 0, 7);
                    }
                }
            } else {
                func_L01_0045A9F0(o);
            }
            if (func_0038CB00(&s->h17A) != 0) {
                if (o->b43 != 2) {
                    func_003C3A10(o, 2, 0, 7);
                }
                func_L01_004450F0(o, 2, -1);
            }
            break;
        }
    }
}
/* localdecomp:end func_L03_00396860 */

/* localdecomp:start func_L03_00396E00 */
/* PAL port of the NTSC-U match src/us/levels/func_L03_00395788.c */


extern u8 D_001426E8[];
extern u8 *D_L03_001DF99C;
extern u128_t *D_L03_0021D8C0[];
__asm__(".extern D_L03_001DF99C, 16");

extern void func_003C2880(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L03_00397138(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_00396E00(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);
    u8 *e;
    s32 id;

    if (D_001426E8[0] == 0) {
        if (s[0x17C] == 1) {
            func_003C2880(self);
            func_003C2880(D_L03_001DF99C + (*(s32 *)(s + 0x140) << 8));
            return;
        }
    } else {
        if (s[0x17C] == 2) {
            func_003C2880(self);
            func_003C2880(D_L03_001DF99C + (*(s32 *)(s + 0x140) << 8));
            return;
        }
    }
    id = *(s32 *)(s + 0x14C);
    if (id != -1) {
        e = D_L03_0021D8C0[id];
        if (*(s32 *)e >= 2) {
            *(s32 *)(s + 0x170) = 0;
            *(s16 *)(s + 0x15E) = 1;
            *(s16 *)(s + 0x15C) = 1;
            *(s128 *)(self + 0x10) = *(s128 *)(e + 0x10);
            *(f32 *)(self + 0x18) = func_003C3D30(self + 0x10, 0, 0, 0.5f);
            *(s128 *)(s + 0x120) = *(s128 *)(e + 0x10 + (*(s16 *)(s + 0x15C) << 4));
            *(f32 *)(s + 0x30) = 0.6f;
            *(f32 *)(s + 0x38) = 1.0f;
            *(f32 *)(s + 0x34) = 0.4f;
            *(f32 *)(s + 0x3C) = 1.0f;
            *(f32 *)(s + 0x50) = 0.0050265486f;
            *(f32 *)(s + 0x40) = 1.4835298f;
            *(f32 *)(s + 0x60) = 0.34906584f;
            *(f32 *)(s + 0x5C) = 0.00392f;
            *(f32 *)(s + 0x64) = 0.01f;
            *(f32 *)(s + 0x58) = 0.050000004f;
            *(f32 *)(s + 0x4C) = 0.25132743f;
            *(f32 *)(s + 0x54) = 0.0050265486f;
            func_L03_00397138(self, 2, 0, 0);
            func_L01_004450F0(self, 2, -1);
        } else {
            func_L01_004450F0(self, 1, -1);
        }
    } else {
        func_L01_004450F0(self, 1, -1);
    }
}
/* localdecomp:end func_L03_00396E00 */

/* localdecomp:start func_L03_00396FF0 */
typedef struct { u8 b[0x100]; } E_00396FF0;
typedef struct { u8 pad0[0x140]; s32 idx; } S_00396FF0;
typedef struct { u8 pad0[0x10]; f32 pos[4]; u8 pad1[0x11]; u8 on; u8 pad2[0x35]; S_00396FF0 *p; u8 pad3[0x8c]; f32 f; } A_00396FF0;
extern E_00396FF0 *D_L03_001DF99C_00396FF0;
extern E_00396FF0 *D_001DF99C_sda;
__asm__(".extern D_001DF99C_sda, 4");
extern u8 D_L03_001E24C0[];
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
void func_L03_00396FF0(void *arg) {
    A_00396FF0 *a = arg;
    S_00396FF0 *p = a->p;
    func_003C2F58(a, 0, D_L03_001DF99C_00396FF0[p->idx].b + 0x10);
    func_L01_00448890(D_L03_001DF99C_00396FF0[p->idx].b + 0xF8, (u8 *)p + 0x144, 0, a->f, 0.0025132743f, 0.0025132743f, 0.12566371f);
    if (a->on) {
        if (func_L01_0040E548(D_L03_001E24C0, a->pos) < 576.0f) {
            func_L01_004472C0(a);
            ((u8 *)a)[0x6F] = 0x16;
        }
    }
    {
        E_00396FF0 *e;
        if (D_L03_001DF99C_00396FF0[p->idx].b[0x31]) {
            e = D_L03_001DF99C_00396FF0 + p->idx;
            if (func_L01_0040E548(D_L03_001E24C0, e->b + 0x10) < 576.0f) {
                func_L01_004472C0(D_001DF99C_sda[p->idx].b);
                D_L03_001DF99C_00396FF0[p->idx].b[0x6F] = 0x16;
            }
        }
    }
}
/* localdecomp:end func_L03_00396FF0 */

/* localdecomp:start func_L03_00397138 */
typedef struct { u8 pad0[0x140]; s32 idx; } S_00397138;
typedef struct { u8 pad0[0x43]; u8 st; u8 pad1[0x24]; S_00397138 *p; } A_00397138;
extern u8 *D_L03_001DF99C;
extern void func_003C3A10(void *, s32, s32, s32);
void func_L03_00397138(void *a, s32 b, s32 c, s32 d) {
    A_00397138 *o = a;
    S_00397138 *s;
    if (o->st != b) {
        s = o->p;
        func_003C3A10(a, b, c, d);
        func_003C3A10(D_L03_001DF99C + (s->idx << 8), b, c, d);
    }
}
/* localdecomp:end func_L03_00397138 */

/* localdecomp:start func_L03_003971B0 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 v10; u8 pad20[0x48]; u8 *p68; } A_003971B0;
typedef struct { u8 pad0[0x10]; vu0_v4 v10; } E_003971B0;
typedef struct { u8 pad0[0x120]; vu0_v4 v120; vu0_v4 v130; u8 pad140[8]; s32 i148; u8 pad14C[0x12]; s16 h15E; u8 pad160[0x19]; u8 b179; } P_003971B0;
extern f32 func_0038CE68(void *, void *);
f32 func_L03_003971B0(void *arg) {
    A_003971B0 *a = arg;
    P_003971B0 *p = (P_003971B0 *)a->p68;
    vu0_v4 v;
    vu0_v4 w;
    E_003971B0 *e;
    if (p->i148 != -1) {
        e = (E_003971B0 *)D_001DF99C_sda[p->i148].b;
        vec_sub_ba(&v, &e->v10, &a->v10);
        if (p->b179 != 0 ? p->h15E == 1 : p->h15E == -1) {
            vec_sub_ab(&w, &p->v120, &a->v10);
            return func_0038CE68(&v, &w);
        }
        return func_0038CE68(&v, &p->v130) + 0.1f;
    }
    return 0.0f;
}
/* localdecomp:end func_L03_003971B0 */

/* localdecomp:start func_L03_00397260 */
typedef struct {
    char pad0[0x120];
    u128_t v120;
    char pad130[0x18];
    int i148;
    int i14C;
    int i150;
    int i154;
    char pad158[4];
    short s15C;
    short s15E;
} S_00397260;
typedef struct {
    char pad0[0x68];
    S_00397260 *p68;
} O_00397260;
extern u128_t *D_L03_0021D8C0[];
__asm__(".extern D_L03_0021D8C0, 16");
extern u8 *D_L03_001DF99C;
extern f32 func_L03_00397390(void *);
extern void func_L03_003975A8(void *, int, int);

int func_L03_00397260(void *a) {
    O_00397260 *o = a;
    S_00397260 *s = o->p68;
    u128_t *t = D_L03_0021D8C0[s->i14C];
    int d, c;
    f32 f;
    if (s->i150 != -1) {
        c = s->s15C;
        d = c - s->s15E;
        if (c >= s->i150) {
            if (s->i154 >= c) {
                f = func_L03_00397390(a);
                if (f != 0.0f) {
                    if (f > 0.0f) {
                        s->s15E = -1;
                        s->s15C = d < s->s15C ? d : s->s15C;
                    } else if (f < 0.0f) {
                        s->s15E = 1;
                        s->s15C = s->s15C < d ? d : s->s15C;
                    }
                    s->v120 = t[s->s15C + 1];
                    if (s->i148 != -1) func_L03_003975A8(D_L03_001DF99C + (s->i148 << 8), s->s15C, s->s15E);
                    return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L03_00397260 */

INCLUDE_ASM("asm/levels", func_L03_00397390);

/* localdecomp:start func_L03_003975A8 */
typedef struct {
    char pad0[0x120];
    u128_t v120;
    char pad130[0x1C];
    int i14C;
    char pad150[0xC];
    short s15C;
    short s15E;
} S_003975A8;
typedef struct {
    char pad0[0x68];
    S_003975A8 *p68;
    char pad6C[0x3E];
    short sAA;
} O_003975A8;
extern u128_t *D_L03_0021D8C0[];
__asm__(".extern D_L03_0021D8C0, 16");

void func_L03_003975A8(void *a, int b, int c) {
    O_003975A8 *o = a;
    S_003975A8 *s;
    if (o->sAA == 0x18DE) {
        s = o->p68;
        if (s->i14C != -1 && s->s15E != c) {
            u128_t *t = D_L03_0021D8C0[s->i14C];
            s->s15E = c;
            s->s15C = b;
            s->v120 = t[b + 1];
        }
    }
}
/* localdecomp:end func_L03_003975A8 */

/* localdecomp:start func_L03_00397608 */
extern u8 D_001DE308_sda[4];
__asm__(".extern D_001DE308_sda, 4");
extern void *D_001DE310_sda;
__asm__(".extern D_001DE310_sda, 8");
extern s32 D_00142C10[];
extern void func_L03_0034B348(s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_00397608(s32 idx) {
    if (D_00142C10[0] & 0x80000) {
        func_L03_0034B348(D_001DE308_sda[idx]);
        func_L01_004450F0(D_001DE310_sda, 3, 0);
    }
}
/* localdecomp:end func_L03_00397608 */

/* localdecomp:start func_L03_00397650 */
extern u8 D_001DE308_sda[4];
__asm__(".extern D_001DE308_sda, 4");
extern u8 D_001D5530[8];
s32 func_L03_00397650(s32 i) { return D_001D5530[D_001DE308_sda[i]] != 0; }
/* localdecomp:end func_L03_00397650 */

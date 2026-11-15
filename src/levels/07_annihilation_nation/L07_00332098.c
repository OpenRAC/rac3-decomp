#include "common.h"

typedef struct {
    u8 pad0[0x44];
    s32 ids[3];
} Grp_003326D8;

typedef struct { u8 pad[0x44]; s32 ids[3]; } Grp_00332298;

INCLUDE_ASM("asm/levels", func_L07_00332098);

/* localdecomp:start func_L07_00332230 */
extern u8 *D_L07_001DF41C_00332230;
extern void func_L07_003A3BB0(u8 *p, s32 a1);

void func_L07_00332230(u8 *a0, s32 a1) {
    s32 *p = (s32 *)(*(u8 **)(a0 + 0x68) + 0x50);
    s32 i;

    for (i = 7; i >= 0; i--) {
        func_L07_003A3BB0(D_L07_001DF41C_00332230 + ((*p) << 8), a1);
        p++;
    }
}
/* localdecomp:end func_L07_00332230 */

/* localdecomp:start func_L07_00332298 */
extern s32 D_L07_001DF458_00332298;
extern u8 *D_L07_001DF41C_00332298;
extern u16 *D_L07_0021C020[];
extern s32 *func_L07_00333B20_00332298(u8 *e);
extern void func_L07_00333D40(s32 a, u8 *e);

void func_L07_00332298(u8 *a0) {
    Grp_00332298 *o = *(Grp_00332298 **)(a0 + 0x68);
    u16 *q;
    u8 *e;
    s32 i;

    for (i = 0; i < 3; i++) {
        for (q = D_L07_0021C020[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L07_001DF458_00332298 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L07_0021C020[o->ids[i]]);
             q++) {
            e = D_L07_001DF41C_00332298 + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            func_L07_00333D40(func_L07_00333B20_00332298(e)[1], e);
        }
    }
}
/* localdecomp:end func_L07_00332298 */

INCLUDE_ASM("asm/levels", func_L07_003323F8);

/* localdecomp:start func_L07_003326D8 */
extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458[];
extern u8 *D_L07_001DF41C[];
extern u8 *func_L07_00333B20(u8 *);

s32 func_L07_003326D8(u8 *a0) {
    Grp_003326D8 *o = *(Grp_003326D8 **)(a0 + 0x68);
    u16 *q;
    u8 *e;
    u8 *r;
    s32 i = 0;

    for (; i < 3; i++) {
        for (q = D_L07_0021C020[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= *(s32 *)0x1DF458 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L07_0021C020[o->ids[i]]);
             q++) {
            e = *(u8 **)0x1DF41C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            r = func_L07_00333B20(e);
            if (e[0x20] != r[8])
                return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L07_003326D8 */

/* localdecomp:start func_L07_00332848 */
typedef struct {
    s32 f0;
    s32 f4;
} E_332848;

typedef struct {
    u8 pad0[0x8A];
    u16 f8A;
    u8 pad8C[0xF0 - 0x8C];
} T_332848;

typedef struct {
    u8 pad0[0xBF];
    u8 fBF;
} B_332848;

typedef struct {
    u8 pad0[0x68];
    B_332848 *p68;
} O_332848;

extern u8 D_001425C0[];
extern s32 D_001427F0_00332848[];
extern E_332848 D_L07_002B0EB0_00332848[];
extern T_332848 D_L07_002C72C0[];
extern s32 D_L07_001E0CD0[] __attribute__((section(".sdata")));

void func_L07_00332848(u8 *a0) {
    s32 i;

    for (i = 0; i < 16; i++) {
        s32 idx = D_L07_002B0EB0_00332848[i].f0;
        s32 v = D_001427F0_00332848[idx];
        u8 t = D_001425C0[idx];
        T_332848 *e = &D_L07_002C72C0[t];

        D_L07_001E0CD0[i] = v;
        D_001427F0_00332848[idx] = e->f8A;
    }
    ((O_332848 *)a0)->p68->fBF = 1;
}
/* localdecomp:end func_L07_00332848 */

/* localdecomp:start func_L07_003328D0 */
typedef struct { s32 idx; s32 x; } E_003328D0;
extern E_003328D0 D_L07_002B0EB0_003328D0[];
extern s32 D_L07_001E0CD0[] __attribute__((section(".sdata")));
extern s32 D_001427F0_003328D0[];

void func_L07_003328D0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    s32 i;

    if (p[0xBF] != 0) {
        for (i = 0; i < 16; i++) {
            s32 k = D_L07_002B0EB0_003328D0[i].idx;
            D_001427F0_003328D0[k] = D_L07_001E0CD0[i];
        }
        p[0xBF] = 0;
    }
}
/* localdecomp:end func_L07_003328D0 */

/* localdecomp:start func_L07_00332928 */
void func_L07_00332928(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    u8 *q = p + 0x8F;
    s32 i;
    for (i = 15; i >= 0; i--) {
        *q-- = i;
    }
}
/* localdecomp:end func_L07_00332928 */

/* localdecomp:start func_L07_00332958 */
typedef struct {
    u8 pad0[0x80];
    u8 order[0x10];
    u8 pad90[0x20];
    u8 cur;
    u8 idx;
    u16 fB2;
    u16 fB4;
} Ent_00332958;

typedef struct {
    s32 f0;
    u8 f4;
    u8 pad5[3];
} Row_00332958;

typedef struct {
    u16 h;
    u16 pad;
} Half_00332958;

extern Row_00332958 D_L07_002B0EB0[];
extern u8 D_00142CA0[];
extern Half_00332958 D_001427F0[];
extern void func_L07_00334968(u8 *arg0, s32 arg1);
extern s32 func_00382468(s32);

s32 func_L07_00332958(u8 *a0) {
    Ent_00332958 *o = *(Ent_00332958 **)(a0 + 0x68);
    Row_00332958 *r;
    u8 *p;
    s32 n;
    u8 t;
    s32 i;

    if (o->idx == 0xFF) {
        o->cur = 0;
        p = o->order;
    } else {
        o->cur = o->order[o->idx];
        p = o->order;
    }

    for (;;) {
        n = o->idx + 1;
        o->idx = n;
        if ((u8)n >= 16) {
            o->idx = 0;
            func_L07_00334968(p, 16);
            if (o->order[0] == o->cur) {
                i = func_00382468(15) + 1;
                t = p[i];
                o->order[0] = t;
                p[i] = o->cur;
            }
        }
        r = &D_L07_002B0EB0[p[o->idx]];
        if (D_00142CA0[r->f0] != 0)
            break;
    }
    r = &D_L07_002B0EB0[o->cur];
    o->fB2 = D_001427F0[r->f0].h;
    o->fB4 = r->f4;
    return r->f0;
}
/* localdecomp:end func_L07_00332958 */

/* localdecomp:start func_L07_00332A90 */
typedef struct {
    u8 pad0[0x44];
    s32 ids[3];
} Grp_00332A90;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
} Sub_00332A90;

typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x3];
    Sub_00332A90 *f24;
    u8 pad28[0x70];
    s32 f98;
} Ent_00332A90;

extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458_00332A90;
extern u8 *D_L07_001DF41C_00332A90;

s32 func_L07_00332A90(u8 *a0) {
    Grp_00332A90 *o = *(Grp_00332A90 **)(a0 + 0x68);
    Ent_00332A90 *e;
    u16 *q;
    s32 i;
    s32 r = 0;

    for (i = 0; i < 3; i++) {
        for (q = D_L07_0021C020[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L07_001DF458_00332A90 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L07_0021C020[o->ids[i]]);
             q++) {
            e = (Ent_00332A90 *)(D_L07_001DF41C_00332A90 + ((*q & 0x7FFF) << 8));
            if (e == 0)
                break;
            if (e->f20 != 1) {
                r = 1;
                e->f98 = e->f24->f10;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L07_00332A90 */

/* localdecomp:start func_L07_00332BE0 */
typedef struct { u8 pad[0x44]; s32 ids[3]; } Grp_00332BE0;
typedef struct { u8 pad[0x98]; s32 f98; } Ent_00332BE0;

extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458_00332BE0;
extern u8 *D_L07_001DF41C_00332BE0;

void func_L07_00332BE0(u8 *a0) {
    Grp_00332BE0 *o = *(Grp_00332BE0 **)(a0 + 0x68);
    u16 *q;
    Ent_00332BE0 *e;
    s32 i;

    for (i = 0; i < 3; i++) {
        for (q = D_L07_0021C020[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L07_001DF458_00332BE0 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L07_0021C020[o->ids[i]]);
             q++) {
            e = (Ent_00332BE0 *)(D_L07_001DF41C_00332BE0 + ((*q & 0x7FFF) << 8));
            if (e == 0)
                break;
            e->f98 = 0;
        }
    }
}
/* localdecomp:end func_L07_00332BE0 */

INCLUDE_ASM("asm/levels", func_L07_00332CF0);

/* localdecomp:start func_L07_00332F90 */
typedef struct {
    u8 pad0[0x10];
    f32 x;
    f32 y;
} Vec_00332F90;

typedef struct {
    f32 x;
    f32 y;
} Pos_00332F90;

extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);

f32 func_L07_00332F90(u8 *a0, u8 *a1, u8 *a2, f32 d) {
    Vec_00332F90 *p = (Vec_00332F90 *)a0;
    Vec_00332F90 *e = (Vec_00332F90 *)a1;
    Pos_00332F90 *t = (Pos_00332F90 *)a2;
    f32 dist = func_0038CF38(a0 + 0x10, a2);
    f32 k;
    f32 ang1;
    f32 ang2;
    f32 r;

    if (24.8f < dist) {
        k = (dist - 24.8f) / 10.0f;
        if (1.0f < k)
            k = 1.0f;
        else if (k < 0.0f)
            k = 0.0f;

        ang1 = func_0038D160(e->x - p->x, e->y - p->y);
        ang2 = func_0038D160(t->x - p->x, t->y - p->y);
        r = func_0038DB00(ang2, ang1);
        return func_0038DAB8(d, k * (0.0f < r ? 1.5707964f : -1.5707964f));
    }
    return d;
}
/* localdecomp:end func_L07_00332F90 */

/* localdecomp:start func_L07_003330E8 */
extern f32 func_L07_00333858(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);

f32 func_L07_003330E8(u8 *a0, u8 *a1, f32 a2, f32 a3) {
    f32 spd = func_L07_00333858(a1);
    f32 d = func_0038CF38(a0 + 0x10, a1 + 0x10) - spd;
    f32 dy, dx, ang, ang2, sum, diff, ds, dd, r;

    if (d < 0.0f)
        d = 0.0f;
    dx = *(f32 *)(a1 + 0x10) - *(f32 *)(a0 + 0x10);
    dy = *(f32 *)(a1 + 0x14) - *(f32 *)(a0 + 0x14);
    ang = func_0038D160(dx, dy);
    ang2 = func_0038D160(d, spd);
    diff = func_0038DB00(ang, ang2);
    sum = func_0038DAB8(ang, ang2);
    dd = func_0038DBA0(a3, diff);
    ds = func_0038DBA0(a3, sum);
    do {
    } while (0);
    r = diff;
    if (!(dd < ds))
        r = sum;
    return func_0038DB00(r, a2);
}
/* localdecomp:end func_L07_003330E8 */

/* localdecomp:start func_L07_00333200 */
extern u8 *D_L07_001E8C18[];
extern void func_L07_00332A90(u8 *);
extern s32 func_003FBBB0(u8 *, u8 *, s32, u8 *, s32);
extern f32 func_L01_0040E570(u8 *, u8 *);
extern void func_L07_00332BE0(u8 *);
extern s32 func_L07_00333878(u8 *);

s32 func_L07_00333200(u8 *a0, u8 *a1, u8 *a2) {
    s32 r;

    func_L07_00332A90(a0);
    r = 1;
    if (func_003FBBB0(a1 + 0x10, a2, 9, a1, 0) != 0) {
        if (D_L07_001E8C18[0] != 0 && func_L07_00333878(D_L07_001E8C18[0]) != 0)
            r = 0;
    }
    func_L07_00332BE0(a0);
    if (615.04f < func_L01_0040E570(a0 + 0x10, a2))
        r = 0;
    return r;
}
/* localdecomp:end func_L07_00333200 */

/* localdecomp:start func_L07_003332B8 */
extern void func_003C2880(void *);
void func_L07_003332B8(u8 *arg0) {
    switch (*(s16 *)(arg0 + 0xAA)) {
    case 0xABE:
    case 0x19F3:
    case 0x1A9F:
    case 0x1C81:
        func_003C2880(arg0);
    }
}
/* localdecomp:end func_L07_003332B8 */

/* localdecomp:start func_L07_00333310 */
extern s32 D_L07_001DEF40[1];
extern s32 func_L07_00333AB8(u8 *);
extern s32 func_L07_00333D20(void *);
extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32);

void func_L07_00333310(void *arg0, u8 *arg1, u8 *arg2, s32 arg3, u8 arg4) {
    s32 flag = 0;
    s32 v;

    if (*(s16 *)(arg1 + 0x14) != 1 ||
        func_L07_00333AB8(*(void **)(arg1 + 0x10)) != 0 || arg4 != 0) {
        flag = 1;
    }
    v = D_L07_001DEF40[0];
    if (((((s32)arg0 >> 8) ^ v) & *(u8 *)(arg2 + 0x1F)) == 0) {
        flag = 1;
    }
    if (flag) {
        func_L01_00456C98(arg0, 0.0f, 0.0f, 1.0f,
                           func_L07_00333D20(*(void **)arg2), 0, 1, 0, 0, arg3,
                           0, 0, 0);
    }
}
/* localdecomp:end func_L07_00333310 */

/* localdecomp:start func_L07_003333F8 */
void func_L07_003333F8(void *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f3;
    void *temp_a0;

    if (!(fparg0 <= fparg1)) {
        temp_a0 = *(void **)((u8 *)arg0 + 0x68);
        temp_f3 = fparg0 - fparg1;
        *(f32 *)((u8 *)temp_a0 + 0xC0) = (f32) ((*(f32 *)((u8 *)temp_a0 + 0xC0)) + temp_f3);
        *(f32 *)((u8 *)temp_a0 + 0xC4) = (f32) ((*(f32 *)((u8 *)temp_a0 + 0xC4)) + temp_f3);
        if (fparg1 <= 0.0f) {
            *(s32 *)((u8 *)temp_a0 + 0xC8) = (s32) ((*(s32 *)((u8 *)temp_a0 + 0xC8)) + 1);
            *(f32 *)((u8 *)temp_a0 + 0xCC) = (f32) ((*(f32 *)((u8 *)temp_a0 + 0xCC)) + 1.0f);
        }
    }
}
/* localdecomp:end func_L07_003333F8 */

/* localdecomp:start func_L07_00333460 */
extern u8 D_L07_002B0D40[];

s32 func_L07_00333460(s32 arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = (arg0 * 0x10) + D_L07_002B0D40;
    if ((*(u8 *)((u8 *)temp_a0 + 0xC)) != 0) {
        if (arg1 == -1) {
            return 0;
        }
        return (*(s32 *)((u8 *)temp_a0 + 8)) + (arg1 * 0xC);
    }
    return (*(s32 *)((u8 *)temp_a0 + 8));
}
/* localdecomp:end func_L07_00333460 */

INCLUDE_ASM("asm/levels", func_L07_003334A8);

/* localdecomp:start func_L07_003337A8 */
extern u8 *D_L07_001DF428_003337A8 __asm__("D_L07_001DF428");
__asm__(".extern D_L07_001DF428, 16");

s32 func_L07_003337A8(s32 *ids) {
    u8 *n;
    s32 i;

    for (n = D_L07_001DF428_003337A8; n != 0; n = *(u8 **)(n + 0x28)) {
        if (*(f32 *)(n + 0x14) > 700.0f && n != 0 && n[0x20] != 0xFE && n[0x20] != 0xFD) {
            s32 h = *(s16 *)(n + 0xAA);

            for (i = 0; i < 4 && ids[i] != -1; i++) {
                if (ids[i] == h) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L07_003337A8 */

/* localdecomp:start func_L07_00333858 */
f32 func_L07_00333858(void *arg0) {
    return (*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x98))) + 0x2C)) * (*(f32 *)((u8 *)arg0 + 0x2C)) * 0.0009765625f;
}
/* localdecomp:end func_L07_00333858 */

/* localdecomp:start func_L07_00333878 */
s32 func_L07_00333878(u8 *arg0) {
    switch (*(s16 *)(arg0 + 0xAA)) {
    case 0x1C91:
    case 0x1CC4:
    case 0x1D4C:
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L07_00333878 */

/* localdecomp:start func_L07_003338C0 */
typedef struct { s32 f0; u8 *f4; s32 f8; s32 fC; } S_003338C0;
extern S_003338C0 D_L07_002B0D40_003338C0[];
s32 func_L07_003338C0(s32 a, s32 b) {
    u8 *q = D_L07_002B0D40_003338C0[a].f4 + b * 12 + 9;
    s32 i;
    for (i = 0; i < 3; i++) {
        if (q[i] != 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L07_003338C0 */

/* localdecomp:start func_L07_00333918 */
u8 *func_L07_00333918(u8 *arg0) {
    switch (*(s16 *)(arg0 + 0xAA)) {
    case 0x1769:
        return *(u8 **)(arg0 + 0x68) + 0x240;
    case 0x195E:
        return *(u8 **)(arg0 + 0x68) + 0x270;
    case 0x19BD:
        return *(u8 **)(arg0 + 0x68) + 0x240;
    case 0x19BE:
        return *(u8 **)(arg0 + 0x68) + 0x240;
    case 0x19D2:
        return *(u8 **)(arg0 + 0x68) + 0x240;
    case 0x1A18:
        return *(u8 **)(arg0 + 0x68) + 0x190;
    case 0x1A1C:
        return *(u8 **)(arg0 + 0x68) + 0x190;
    case 0x1A1F:
        return *(u8 **)(arg0 + 0x68) + 0x190;
    case 0x1D88:
        return *(u8 **)(arg0 + 0x68) + 0x240;
    case 0x1D89:
        return *(u8 **)(arg0 + 0x68) + 0x240;
    case 0x1D8A:
        return *(u8 **)(arg0 + 0x68) + 0x240;
    case 0x1D8B:
        return *(u8 **)(arg0 + 0x68) + 0x240;
    case 0x1D8C:
        return *(u8 **)(arg0 + 0x68) + 0x270;
    }
    return 0;
}
/* localdecomp:end func_L07_00333918 */

/* localdecomp:start func_L07_00333A18 */
s32 func_L07_00333A18(void *arg0) {
    s16 id;

    id = *(s16 *)((u8 *)arg0 + 0xAA);
    switch (id) {
    case 0x19D2:
    case 0x195E:
    case 0x1769:
    case 0x19BD ... 0x19BE:
    case 0x1A18:
    case 0x1A1C:
    case 0x1A1F:
    case 0x1D88 ... 0x1D8C:
        return 1;
    default:
        return 0;
    }
}
/* localdecomp:end func_L07_00333A18 */

/* localdecomp:start func_L07_00333AB8 */
s32 func_L07_00333AB8(u8 *arg0) {
    s32 r;
    if (func_L07_00333A18(arg0) != 0) {
        return arg0[0x20] == 1;
    }
    r = 0;
    if (arg0 == 0 || arg0[0x20] == 0xFE || arg0[0x20] == 0xFD) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L07_00333AB8 */

/* localdecomp:start func_L07_00333B20 */
u8 *func_L07_00333B20(u8 *arg0) {
    switch (*(s16 *)(arg0 + 0xAA)) {
    case 0x1C91:
    case 0x1CC4:
    case 0x1D4C:
        return *(u8 **)(arg0 + 0x68);
    }
    return 0;
}
/* localdecomp:end func_L07_00333B20 */

/* localdecomp:start func_L07_00333B68 */
s32 func_L07_00333B68(void *arg0) {
    s16 temp_v1;

    temp_v1 = *(s16 *)((u8 *)arg0 + 0xAA);
    if ((temp_v1 == 0x19E7) || (temp_v1 == 0x1CF6)) {
        return (*(s32 *)((u8 *)arg0 + 0x68));
    }
    return 0;
}
/* localdecomp:end func_L07_00333B68 */

/* localdecomp:start func_L07_00333B90 */
extern u8 *D_L07_001DF428;

s32 func_L07_00333B90(void) {
    u8 *e = D_L07_001DF428;
    s32 n = 0;

    while (e != 0) {
        if (*(s16 *)(e + 0xAA) == 0xCDB && e[0x20] < 0xFE && *(f32 *)(e + 0x14) > 750.0f) {
            n++;
        }
        e = *(u8 **)(e + 0x28);
    }
    return n;
}
/* localdecomp:end func_L07_00333B90 */

/* localdecomp:start func_L07_00333BF8 */
extern u8 *D_L07_001DF41C_00333BF8;
extern s32 func_L07_003A3B40(u8 *p);

s32 func_L07_00333BF8(u8 *a0) {
    s32 *q = (s32 *)(*(u8 **)(a0 + 0x68) + 0x50);
    s32 i;

    for (i = 0; i < 8; i++) {
        if (func_L07_003A3B40(D_L07_001DF41C_00333BF8 + (*q << 8)) == 1) {
            return 1;
        }
        q++;
    }
    return 0;
}
/* localdecomp:end func_L07_00333BF8 */

/* localdecomp:start func_L07_00333C70 */
extern s32 D_L07_001DF600[2];
extern u8 D_L07_0021DB38[];
extern void func_0038CB78(void *, s32, s32);

void func_L07_00333C70(u8 *a0, s32 a1) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 i = p[0xA9];

    if (D_L07_001DF600[i] == 0) {
        D_L07_001DF600[i] = a1;
        func_0038CB78(&D_L07_0021DB38[i * 0x270], 0, 0x270);
    }
    p[0xA9] = p[0xA9] + 1;
}
/* localdecomp:end func_L07_00333C70 */

/* localdecomp:start func_L07_00333CE0 */
/* from rac4-decomp's func_005011A8, renamed, constants adapted */
s32 func_L07_00333CE0(void *arg0, s32 arg1) {
    u8 *temp = *(u8 **)((u8 *)arg0 + 104);
    return *(s32 *)(temp + (arg1 << 2) + 0x1c);
}
/* localdecomp:end func_L07_00333CE0 */

/* localdecomp:start func_L07_00333CF8 */
typedef struct { u8 pad[0x38]; s32 a[1]; } S_00333CF8;
extern u8 *D_L07_001DF41C_00333CF8;
u8 *func_L07_00333CF8(void *arg0, s32 arg1) {
    S_00333CF8 *p = *(S_00333CF8 **)((u8 *)arg0 + 0x68);
    return D_L07_001DF41C_00333CF8 + (p->a[arg1] << 8);
}
/* localdecomp:end func_L07_00333CF8 */

/* localdecomp:start func_L07_00333D20 */
s32 func_L07_00333D20(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    if (*((u8 *)arg0 + 0x20) == 8) {
        return -1;
    }
    return *(s32 *)(p + 0x78);
}
/* localdecomp:end func_L07_00333D20 */

/* localdecomp:start func_L07_00333D40 */
void func_L07_00333D40(s32 a, u8 *e) {
    if (a != 0 && e != 0) {
        ((void (*)(u8 *))a)(e);
    }
}
/* localdecomp:end func_L07_00333D40 */

/* localdecomp:start func_L07_00333D70 */
s32 func_L07_00333D70(u8 *p, s32 limit, s32 count, s32 start) {
    s32 sum = 0;
    s32 i;

    for (i = 0; i < count; i++) {
        sum += p[start + i];
        if (limit < sum)
            return start + i;
    }
    return -1;
}
/* localdecomp:end func_L07_00333D70 */

INCLUDE_ASM("asm/levels", func_L07_00333DB8);

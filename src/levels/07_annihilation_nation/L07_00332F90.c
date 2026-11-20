#include "common.h"

typedef struct {
    u8 pad0[0x44];
    s32 ids[3];
} Grp_003326D8;

typedef struct { u8 pad[0x44]; s32 ids[3]; } Grp_00332298;

/* declared by functions of L07_00332098.c, which this file was cut from */
extern s32 func_L07_00333B90(void);
extern s32 func_L07_00333BF8(u8 *);
extern u16 *D_L07_0021C020[];
extern void func_L07_00333D40(s32 a, u8 *e);
extern u8 *func_L07_00333B20(u8 *);
typedef struct {
    u8 pad0[0x8A];
    u16 f8A;
    u8 pad8C[0xF0 - 0x8C];
} T_332848;
extern u8 D_001425C0[];
extern T_332848 D_L07_002C72C0[];
typedef struct {
    u16 h;
    u16 pad;
} Half_00332958;
extern Half_00332958 D_001427F0[];

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

/* localdecomp:start func_L07_003334A8 */
typedef struct { s32 ids[4]; } Ids_003334A8;
typedef struct { u8 pad0; u8 level; u8 pad2[0x82]; u16 h84; u8 pad86[0x6A]; } Row_003334A8;
extern s32 D_L07_001DF458_003334A8;
extern u8 *D_L07_001DF41C_003334A8;
extern Ids_003334A8 D_L07_001DD108;
__asm__(".extern D_L07_001DD108, 16");
__asm__(".extern D_L07_001DF458_003334A8, 4");
__asm__(".extern D_L07_001DF41C_003334A8, 16");
s32 func_L07_003334A8(u8 *obj, s32 id) {
    extern s32 func_L07_003670F0(void);
    extern s32 func_L07_003337A8(s32 *);
    u8 *vars=*(u8 **)(obj+0x68);
    s32 mode;
    s32 delay;
    Ids_003334A8 ids;
    if (((Row_003334A8 *)D_L07_002C72C0)[D_001425C0[id]].h84==0 && id!=0x87) return 0;
    if (((s32 *)D_001427F0)[id]>0) {
        *(s16 *)(vars+0xB6)=0;
        return 0;
    }
    mode=0;
    ids=D_L07_001DD108;
    delay=100;
    switch(id) {
    case 0x7F: {
        s32 level=((Row_003334A8 *)D_L07_002C72C0)[D_001425C0[0x7F]].level;
        delay=150;
        if(level>=3) {
            ids.ids[0]=0x307;
            mode=2;
            if(level>=4) ids.ids[1]=0x1CB8;
        } else mode=1;
        break;
    }
    case 0x47: mode=1; delay=137; break;
    case 0x87: {
        u16 *q;
        u8 *e;
        if(obj[0x20]!=6 || func_L07_003670F0()) {
            *(s16 *)(vars+0xB6)=0;
            return 0;
        }
        
        for(q=D_L07_0021C020[*(s32 *)(vars+0x34)]; (*(s32 *)(vars+0x34)&255)!=255 && *(s32 *)(vars+0x34)<=D_L07_001DF458_003334A8 && q && ((s16)q[-1]>=0 || q==D_L07_0021C020[*(s32 *)(vars+0x34)]); q++) {
            e=D_L07_001DF41C_003334A8+((*q&0x7FFF)<<8);
            if(!e) break;
            if(e[0x20]!=1) {
                *(s16 *)(vars+0xB6)=0;
                return 0;
            }
        }
        mode=2;
        if(((Row_003334A8 *)D_L07_002C72C0)[D_001425C0[0x87]].level>=4) ids.ids[0]=0x1893;
        else ids.ids[0]=0x1872;
        break;
    }
    case 0x4F: mode=2; ids.ids[0]=0x1867; break;
    case 0x5F: mode=2; ids.ids[0]=0x186B; break;
    case 0x8F: return 0;
    }
    switch(mode) {
    case 0: return 1;
    case 2: if(func_L07_003337A8(ids.ids)) return 0;
    case 1:
        if(++*(s16 *)(vars+0xB6)>delay) return 1;
        break;
    }
    return 0;
}
/* localdecomp:end func_L07_003334A8 */

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

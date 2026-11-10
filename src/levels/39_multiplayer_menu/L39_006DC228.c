#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006DC228);

INCLUDE_ASM("asm/levels", func_L39_006DC308);

INCLUDE_ASM("asm/levels", func_L39_006DC3D0);

/* localdecomp:start func_L39_006DC788 */
void *func_L39_006DC788(void *arg0) {
    *(s8 *)((u8 *)arg0 + 0x98) = 0;
    *(s8 *)((u8 *)arg0 + 0x99) = 0;
    *(s8 *)((u8 *)arg0 + 0x9A) = 0;
    *(s8 *)((u8 *)arg0 + 0x9B) = 0;
    *(s8 *)((u8 *)arg0 + 0x9C) = 0;
    *(s8 *)((u8 *)arg0 + 0x9D) = 0;
    return arg0;
}
/* localdecomp:end func_L39_006DC788 */

/* localdecomp:start func_L39_006DC7A8 */
void func_L39_006DC7A8(void *arg0) {
    *(s8 *)((u8 *)arg0 + 0x98) = 0;
    *(s8 *)((u8 *)arg0 + 0x99) = 0;
    *(s8 *)((u8 *)arg0 + 0x9A) = 0;
    *(s8 *)((u8 *)arg0 + 0x9B) = 0;
    *(s8 *)((u8 *)arg0 + 0x9C) = 0;
    *(s8 *)((u8 *)arg0 + 0x9D) = 0;
}
/* localdecomp:end func_L39_006DC7A8 */

INCLUDE_ASM("asm/levels", func_L39_006DC7C8);

INCLUDE_ASM("asm/levels", func_L39_006DCAD0);

/* localdecomp:start func_L39_006DCC80 */
s32 func_0017DF20();
void func_001961E8(s32);
extern void *D_001E2050_sda;

s32 func_L39_006DCC80(void) {
    s32 temp_v0;
    void *temp_s1;

    temp_s1 = D_001E2050_sda;
    temp_v0 = func_0017DF20();
    func_001961E8(temp_v0);
    if (temp_v0 != 0) {
        *(s32 *)((u8 *)temp_s1 + 0x10) = 0x4D;
        if ((*(s32 *)((u8 *)temp_s1 + 0x14)) == 0) {
            *(s32 *)((u8 *)temp_s1 + 0x14) = 0x4D;
        }
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_006DCC80 */

/* localdecomp:start func_L39_006DCCE0 */
typedef struct { u32 words[7]; } S_6DCCE0_Copy;
typedef struct { char pad[0x9a]; u8 flag; char pad2[0x35]; S_6DCCE0_Copy data; } S_6DCCE0_Target;
typedef struct { char pad[0x1d]; u8 flag; char pad2[0x2F]; S_6DCCE0_Target *target; } S_6DCCE0_Owner;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

/* from rac4-decomp's func_L00_007797B0 */
void func_L39_006DCCE0(S_6DCCE0_Copy *arg0) {
    S_6DCCE0_Owner *owner = ((S_6DCCE0_Owner *)D_L39_0024D760);
    S_6DCCE0_Target *target = owner->target;
    if (!owner->flag) {
        target->flag = 0;
        target->data = *arg0;
    }
}
/* localdecomp:end func_L39_006DCCE0 */

/* localdecomp:start func_L39_006DCD38 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { int words[12]; } Data_6DCD38;
typedef struct { char pad[0x99]; unsigned char flag; char pad2[6]; Data_6DCD38 data; } Target_6DCD38;
typedef struct { char pad[0x1D]; unsigned char flag; char pad2[0x32]; Target_6DCD38 *target; } Global_6DCD38;

/* from rac4-decomp's func_L00_00779808 */
void func_L39_006DCD38(Data_6DCD38 *arg) {
    Global_6DCD38 *g = ((Global_6DCD38 *)D_L39_0024D760);
    Target_6DCD38 *t = g->target;
    if (!g->flag) {
        t->flag = 0;
        t->data = *arg;
    }
}
/* localdecomp:end func_L39_006DCD38 */

INCLUDE_ASM("asm/levels", func_L39_006DCDB8);

/* localdecomp:start func_L39_006DD028 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u8 D_001A5FB5[];

typedef struct { char pad[0x1D]; u8 flag; char pad2[0x32]; u8 *target; } S_6DD028_Owner;

void func_L39_006DD028(s32 arg0) {
    S_6DD028_Owner *owner = (S_6DD028_Owner *)D_L39_0024D760;
    u8 *target = owner->target;
    if (!owner->flag && arg0) {
        D_001A5FB5[0] = 1;
        target[0x9D] = 1;
        target[0x9B] = 0;
    }
}
/* localdecomp:end func_L39_006DD028 */

INCLUDE_ASM("asm/levels", func_L39_006DD060);

/* localdecomp:start func_L39_006DD340 */
s32 func_0017E140();
s32 func_001961F8();
void func_001961E8(s32);
extern void *D_001E2050_sda;
extern u8 D_001A5FB5[];

s32 func_L39_006DD340(void *arg0) {
    void *temp_s0;
    s32 temp_v0;

    temp_s0 = D_001E2050_sda;
    temp_v0 = func_0017E140();
    func_001961E8(temp_v0);
    temp_v0 = func_001961F8();
    if (temp_v0 != -0x10 && temp_v0 != 0) {
        *(s32 *)((u8 *)temp_s0 + 0x10) = 0x50;
        if (*(s32 *)((u8 *)temp_s0 + 0x14) == 0) {
            *(s32 *)((u8 *)temp_s0 + 0x14) = 0x50;
        }
        return 0;
    }
    D_001A5FB5[0] = 0;
    *(u8 *)((u8 *)arg0 + 0x9D) = 0;
    return 1;
}
/* localdecomp:end func_L39_006DD340 */

/* localdecomp:start func_L39_006DD3C0 */
void func_L39_006DD3C0(void) {

}
/* localdecomp:end func_L39_006DD3C0 */

/* localdecomp:start func_L39_006DD3C8 */
void func_L39_006DD3C8(void) {

}
/* localdecomp:end func_L39_006DD3C8 */

/* localdecomp:start func_L39_006DD3D0 */
typedef struct {
    char pad0[0x10];
    s32 f10;
    s32 f14;
    char pad18[0x38];
    u8 *f50;
} S_6DD3D0;

__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_0077A320 */
s32 func_L39_006DD3D0(void *arg0)
{
    S_6DD3D0 *base = ((S_6DD3D0 *)D_L39_0024D760);
    s32 result = *(s32 *)((u8 *)arg0 + 0x18);
    u8 *target = base->f50;
    if (*(s32 *)((u8 *)arg0 + 0x18)) {
        result = base->f14;
        base->f10 = 0x51;
        if (!result)
            base->f14 = 0x51;
    }
    target[0x9c] = 0;
    return result;
}
/* localdecomp:end func_L39_006DD3D0 */

/* localdecomp:start func_L39_006DD400 */
typedef struct { s8 b0; s8 pad1[0x5F]; s8 b60; s8 pad2[0x2EEB]; s8 b4C; s8 p3[7]; s8 b54; s8 p4[7]; s8 b5C; s8 p5[0x2B]; s8 b88; s8 b89; s8 p6[2]; s32 w8C; s32 w90; s32 w94; } S_006DD400;
void *func_L39_006DD400(S_006DD400 *a) {
    a->b0 = 0;
    a->b60 = 0;
    a->b4C = 0;
    a->b54 = 0;
    a->b5C = 0;
    a->b88 = 0;
    a->b89 = 0;
    a->w8C = -1;
    a->w90 = -1;
    a->w94 = -1;
    return a;
}
/* localdecomp:end func_L39_006DD400 */

/* localdecomp:start func_L39_006DD438 */
typedef struct { s8 b0; s8 pad1[0x5F]; s8 b60; s8 pad2[0x2EEB]; s8 b4C; s8 p3[7]; s8 b54; s8 p4[7]; s8 b5C; s8 p5[0x2B]; s8 b88; s8 b89; s8 p6[2]; s32 w8C; s32 w90; s32 w94; } S_006DD438;
void func_L39_006DD438(S_006DD438 *a) {
a->b0 = 0;
a->b60 = 0;
a->b4C = 0;
a->b54 = 0;
a->b5C = 0;
a->b89 = 0;
a->w8C = -1;
a->w90 = -1;
a->w94 = -1;
}
/* localdecomp:end func_L39_006DD438 */

INCLUDE_ASM("asm/levels", func_L39_006DD468);

INCLUDE_ASM("asm/levels", func_L39_006DD4D0);

/* localdecomp:start func_L39_006DD5B8 */
extern u8 D_001B3331[];

void func_L39_006DD5B8(s32 arg0, u8 *arg1) {
    u8 *p = arg1;
    s32 c;
    s32 r;
    if (*p != 0) {
        do {
            c = *p;
            r = c;
            if (D_001B3331[c] & 2) {
                r = c - 0x20;
            }
            *p = r;
            p++;
        } while (*p != 0);
    }
}
/* localdecomp:end func_L39_006DD5B8 */

LINKER_REMNANT("asm/levels", func_L39_006DD600);

INCLUDE_ASM("asm/levels", func_L39_006DD608);

INCLUDE_ASM("asm/levels", func_L39_006DD770);

INCLUDE_ASM("asm/levels", func_L39_006DD860);

INCLUDE_ASM("asm/levels", func_L39_006DD9B0);

/* localdecomp:start func_L39_006DDDE8 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0x60]; char a; char pad2[0xb]; char b; } T_6DDDE8;
typedef struct { char pad[0x54]; T_6DDDE8 *p; } S_6DDDE8;

/* from rac4-decomp's func_L00_0077C368 */
void func_L39_006DDDE8(void) {
    T_6DDDE8 *t = ((S_6DDDE8 *)D_L39_0024D760)->p;
    t->a = 0;
    t->b = 0;
}
/* localdecomp:end func_L39_006DDDE8 */

INCLUDE_ASM("asm/levels", func_L39_006DDE00);

INCLUDE_ASM("asm/levels", func_L39_006DDF78);

/* localdecomp:start func_L39_006DE010 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0x2f4c]; char flag; char pad2[3]; int val; } T_006DE010;
typedef struct { char pad[0x54]; T_006DE010 *p; } S_006DE010;

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006DE010(char *arg0) {
    T_006DE010 *t = ((S_006DE010 *)D_L39_0024D760)->p;
    t->flag = 0;
    t->val = *(int *)(arg0 + 0x18);
}
/* localdecomp:end func_L39_006DE010 */

INCLUDE_ASM("asm/levels", func_L39_006DE030);

INCLUDE_ASM("asm/levels", func_L39_006DE180);

/* localdecomp:start func_L39_006DE2D0 */
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_0077C700 */
void func_L39_006DE2D0(void *arg0) {
    void *temp_v1;
    temp_v1 = (*(void **)((u8 *)D_L39_0024D760 + 0x54));
    (*(s8 *)((u8 *)(temp_v1) + 0x2f54)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0x2f58)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
/* localdecomp:end func_L39_006DE2D0 */

/* localdecomp:start func_L39_006DE2F0 */
s32 func_12DCB0(void *);
long func_130760(void *, long);
void func_L39_006DD860(void *, s32);

s32 func_L39_006DE2F0(void *arg0) {
    s32 ret = 1;
    s32 t;

    if (*(u8 *)((u8 *)arg0 + 0x2F88) != 0) {
        if (*(u8 *)((u8 *)arg0 + 0x2F89) != 0) {
            s32 p = func_12DCB0(arg0);

            t = func_130760((void *)p, 0x24000);
            if ((t - *(s32 *)((u8 *)arg0 + 0x2F8C)) >= 0x3A99) {
                *(u8 *)((u8 *)arg0 + 0x2F89) = 0;
                ret = 0;
                func_L39_006DD860(arg0, *(u8 *)((u8 *)arg0 + 0x2F8A));
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006DE2F0 */

INCLUDE_ASM("asm/levels", func_L39_006DE380);

/* localdecomp:start func_L39_006DE4E0 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { unsigned long x[5]; } __attribute__((packed)) Block_6DE4E0;

/* from rac4-decomp's func_L00_0077C7B0 */
void func_L39_006DE4E0(Block_6DE4E0 *arg0) {
    unsigned char *state = *(unsigned char **)((unsigned char *)D_L39_0024D760 + 0x54);
    state[0x2F5C] = 0;
    *(Block_6DE4E0 *)(state + 0x2F60) = *arg0;
}
/* localdecomp:end func_L39_006DE4E0 */

INCLUDE_ASM("asm/levels", func_L39_006DE548);

INCLUDE_ASM("asm/levels", func_L39_006DE688);

/* localdecomp:start func_L39_006DE8D8 */
s32 func_001205B0(s32, s32);
s32 func_L39_0057D548(s32, s32);
void func_L39_00672470(s32, s32);
s32 func_L39_006E1478(s32, s32);
extern u8 D_L39_0024A038[];

void func_L39_006DE8D8(s32 arg0, s32 arg1) {
    if ((func_001205B0(arg0, (s32) D_L39_0024A038) != 0) && (func_L39_006E1478(arg0, arg1) == 0) && (func_L39_0057D548(arg0, arg1) == 0)) {
        func_L39_00672470(arg0, arg1);
    }
}
/* localdecomp:end func_L39_006DE8D8 */

INCLUDE_ASM("asm/levels", func_L39_006DE948);

/* localdecomp:start func_L39_006DEA18 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

typedef struct { char pad[0x54]; u8 *p; } S_6DEA18_Owner;

void func_L39_006DEA18(void *arg0) {
    u8 *owner = (u8 *)arg0;
    u8 *target = ((S_6DEA18_Owner *)D_L39_0024D760)->p;
    *(s32 *)(target + 0x2FD4) = *(s32 *)(owner + 0x1E0);
    if (*(s32 *)(owner + 0x1DC) == 3 || *(s32 *)(owner + 0x1E0) != 0) {
        target[0x2FD0] = 0;
    }
}
/* localdecomp:end func_L39_006DEA18 */

/* localdecomp:start func_L39_006DEA58 */
typedef struct {
    u8 pad0[0x2FD8];
    s8 f2FD8;
    u8 pad1[3];
    s32 f2FDC;
} S_6DEA58_B;
typedef struct {
    u8 pad0[0xAC];
    s32 fAC;
} S_6DEA58_C;
typedef struct {
    u8 pad0[0x54];
    S_6DEA58_B *f54;
} S_6DEA58_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006DEA58(S_6DEA58_C *arg0) {
    S_6DEA58_B *p = ((S_6DEA58_A *)D_L39_0024D760)->f54;
    p->f2FD8 = 0;
    p->f2FDC = arg0->fAC;
}
/* localdecomp:end func_L39_006DEA58 */

/* localdecomp:start func_L39_006DEA78 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

typedef struct { char pad[0x54]; void *target; } S_006DEA78_Owner;

void func_L39_006DEA78(void *arg0) {
    S_006DEA78_Owner *owner = (S_006DEA78_Owner *)D_L39_0024D760;
    u8 *target = owner->target;
    *(u8 *)(target + 0x2FC4) = 0;
    *(s32 *)(target + 0x2FC8) = *(s32 *)((u8 *)arg0 + 0x1C0);
    *(s32 *)(target + 0x2FCC) = *(s32 *)((u8 *)arg0 + 0x98);
}
/* localdecomp:end func_L39_006DEA78 */

/* localdecomp:start func_L39_006DEAA0 */
typedef struct {
    u8 pad0[0x2fe0];
    s8 f2FE0;
    u8 pad1[0x2fe4 - 0x2fe0 - 1];
    s32 f2FE4;
} S_006DEAA0_B;
typedef struct {
    s32 f0;
} S_006DEAA0_C;
typedef struct {
    u8 pad0[0x54];
    S_006DEAA0_B *f54;
} S_006DEAA0_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006DEAA0(S_006DEAA0_C *arg0) {
    S_006DEAA0_B *p = ((S_006DEAA0_A *)D_L39_0024D760)->f54;
    p->f2FE0 = 0;
    p->f2FE4 = arg0->f0;
}
/* localdecomp:end func_L39_006DEAA0 */

INCLUDE_ASM("asm/levels", func_L39_006DEAC0);

INCLUDE_ASM("asm/levels", func_L39_006DEB68);

INCLUDE_ASM("asm/levels", func_L39_006DEDF8);

INCLUDE_ASM("asm/levels", func_L39_006DF018);

INCLUDE_ASM("asm/levels", func_L39_006DF118);

INCLUDE_ASM("asm/levels", func_L39_006DF168);

/* localdecomp:start func_L39_006DF450 */
extern u8 D_1A6950[];

void func_L39_006DF450(s32 *a0, s32 a1, s32 a2, s32 a3) {
    s32 v;
    f32 f0;
    f32 f1;
    f32 f2;
    u8 *p;

    p = D_1A6950;
    f2 = (f32)a0[a2];
    if (*(f32 *)(p + 0xD0) < f2) {
        v = a0[a3];
        if (v > 0) {
            f1 = (f32)a0[11];
            if (*(f32 *)(p + 0xEC) <= f1) {
                f0 = *(f32 *)(p + 0xD4);
                f1 = (f32)v;
                a0[a1] = (s32)(f0 * f2 / f1);
                return;
            }
        }
    }
    a0[a1] = 0;
}
/* localdecomp:end func_L39_006DF450 */

/* localdecomp:start func_L39_006DF4E8 */
extern f32 D_001A6950[];

void func_L39_006DF4E8(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 v6 = arg0[arg2];
    s32 v7 = arg0[arg3];

    if (D_001A6950[52] < (f32)(v6 + v7)) {
        if (v7 > 0 && D_001A6950[59] <= (f32)arg0[11]) {
            arg0[arg1] = (s32)(D_001A6950[53] * (f32)v6 / (f32)v7);
            return;
        }
    }
    arg0[arg1] = 0;
}
/* localdecomp:end func_L39_006DF4E8 */

/* localdecomp:start func_L39_006DF598 */
extern f32 D_001A6950[];

s32 func_L39_006DF598(f32 arg0, f32 arg1) {
    s32 lo;
    s32 hi;
    lo = 1;
    if (arg1 <= D_001A6950[0x114 / 4]) {
        if (!(arg0 <= D_001A6950[0x120 / 4])) {
            if (arg0 <= D_001A6950[0x124 / 4]) {
                lo = 2;
            } else if (arg0 <= D_001A6950[0x128 / 4]) {
                lo = 3;
            } else {
                lo = 4;
            }
        }
        hi = 1;
        if (arg1 <= D_001A6950[0x11C / 4]) {
            hi = 3;
        } else if (arg1 <= D_001A6950[0x118 / 4]) {
            hi = 2;
        }
        if (hi >= lo) {
            lo = hi;
        }
    } else {
        lo = 1;
    }
    return lo;
}
/* localdecomp:end func_L39_006DF598 */

INCLUDE_ASM("asm/levels", func_L39_006DF640);

INCLUDE_ASM("asm/levels", func_L39_006DF760);

INCLUDE_ASM("asm/levels", func_L39_006E0150);

INCLUDE_ASM("asm/levels", func_L39_006E0220);

INCLUDE_ASM("asm/levels", func_L39_006E0298);

INCLUDE_ASM("asm/levels", func_L39_006E05C0);

INCLUDE_ASM("asm/levels", func_L39_006E0688);

INCLUDE_ASM("asm/levels", func_L39_006E0730);

INCLUDE_ASM("asm/levels", func_L39_006E07E8);

INCLUDE_ASM("asm/levels", func_L39_006E08A0);

/* localdecomp:start func_L39_006E0B18 */
extern void func_L39_006E0298();
 
void func_L39_006E0B18(void) {
    func_L39_006E0298();
}
/* localdecomp:end func_L39_006E0B18 */

INCLUDE_ASM("asm/levels", func_L39_006E0B38);

INCLUDE_ASM("asm/levels", func_L39_006E0CC8);

/* localdecomp:start func_L39_006E0CF0 */
f32 func_L39_006E0CC8();

f32 func_L39_006E0CF0(void) {
    f32 temp_f0;

    temp_f0 = func_L39_006E0CC8();
    return temp_f0 * temp_f0;
}
/* localdecomp:end func_L39_006E0CF0 */

INCLUDE_ASM("asm/levels", func_L39_006E0D10);

INCLUDE_ASM("asm/levels", func_L39_006E0D90);

INCLUDE_ASM("asm/levels", func_L39_006E0DE8);

INCLUDE_ASM("asm/levels", func_L39_006E0E58);

INCLUDE_ASM("asm/levels", func_L39_006E0EF0);

INCLUDE_ASM("asm/levels", func_L39_006E0F78);

INCLUDE_ASM("asm/levels", func_L39_006E0FF8);

INCLUDE_ASM("asm/levels", func_L39_006E1040);

/* localdecomp:start func_L39_006E10D0 */
s32 func_L39_006E10D0(u8 *arg0) {
    s32 var_v1;
    u8 *var_a1;
    u8 temp_v1;

    var_a1 = arg0;
    var_v1 = 0;
    if (*var_a1 != 0) {
        do {
            temp_v1 = *var_a1;
            var_a1 += 1;
            var_v1 = temp_v1 + (var_v1 * 0x25);
        } while (*var_a1 != 0);
    }
    return var_v1;
}
/* localdecomp:end func_L39_006E10D0 */

INCLUDE_ASM("asm/levels", func_L39_006E1108);

INCLUDE_ASM("asm/levels", func_L39_006E1478);

/* localdecomp:start func_L39_006E1538 */
/* Round arg0 up to a multiple of arg1 (divu remainder, then add the gap). */
s32 func_L39_006E1538(u32 arg0, u32 arg1) {
    u32 rem = arg0 % arg1;
    if (rem != 0) {
        arg0 += arg1 - rem;
    }
    return arg0;
}
/* localdecomp:end func_L39_006E1538 */

INCLUDE_ASM("asm/levels", func_L39_006E1558);

/* localdecomp:start func_L39_006E1648 */
s32 func_L01_00521C90(s32, s32);
void func_L39_006E1558(s32, s32, s32, s32);

void func_L39_006E1648(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_L39_006E1558(func_L01_00521C90(0x20, arg0), arg1, arg2, arg3);
}
/* localdecomp:end func_L39_006E1648 */

INCLUDE_ASM("asm/levels", func_L39_006E16A0);

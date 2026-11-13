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

INCLUDE_ASM("asm/levels", func_L07_00332848);

INCLUDE_ASM("asm/levels", func_L07_003328D0);

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

INCLUDE_ASM("asm/levels", func_L07_00332958);

INCLUDE_ASM("asm/levels", func_L07_00332A90);

INCLUDE_ASM("asm/levels", func_L07_00332BE0);

INCLUDE_ASM("asm/levels", func_L07_00332CF0);

INCLUDE_ASM("asm/levels", func_L07_00332F90);

INCLUDE_ASM("asm/levels", func_L07_003330E8);

INCLUDE_ASM("asm/levels", func_L07_00333200);

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

INCLUDE_ASM("asm/levels", func_L07_00333310);

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

INCLUDE_ASM("asm/levels", func_L07_003337A8);

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

INCLUDE_ASM("asm/levels", func_L07_00333918);

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

INCLUDE_ASM("asm/levels", func_L07_00333B90);

INCLUDE_ASM("asm/levels", func_L07_00333BF8);

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

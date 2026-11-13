#include "common.h"

typedef struct S_004E56D0 {
    u8 pad0[0x1B04];
    s32 x1B04;
    u8 pad1[0x1B24 - 0x1B08];
    u8 *x1B24;
    u8 pad2[0x25C0 - 0x1B28];
    u8 *x25C0;
} S_004E56D0;

typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;

extern S_004E6988 D_001A4BE0;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L30_004CF4B0(s32, s32);

typedef struct {
    u8 pad0[0x43];
    u8 b43;
} P_004E6D08;
typedef struct {
    u8 pad0[0xC08];
    s32 w_C08;
    u8 pad1[0x1AC0 - 0xC0C];
    s32 w_1AC0;
    u8 pad2[0x25C0 - 0x1AC4];
    P_004E6D08 *p_25C0;
    s32 w_25C4;
    u8 pad3[0x25CC - 0x25C8];
    s32 w_25CC;
    u8 pad4[0x25E9 - 0x25D0];
    u8 b_25E9;
    u8 pad5[0x25EB - 0x25EA];
    u8 b_25EB;
} S_004E6D08;

INCLUDE_ASM("asm/levels", func_L30_004E5158);

/* localdecomp:start func_L30_004E5370 */
typedef struct {
    u8 pad0[0xBDC];
    s16 hBDC;
    u8 pad1[0xC0C - 0xBDE];
    s32 wC0C;
    u8 pad2[0xC18 - 0xC10];
    f32 fC18;
    u8 pad3[0x1AC0 - 0xC1C];
    u8 *p1AC0;
    u8 pad4[0x1ACC - 0x1AC4];
    f32 f1ACC;
    u8 pad5[0x25C4 - 0x1AD0];
    s32 w25C4;
} S_004E5370;

extern f32 D_001DBF80_sda[] __attribute__((section(".sdata")));
extern f32 D_001DBF90_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DBF80_sda, 8");
__asm__(".extern D_001DBF90_sda, 8");

s32 func_L30_004E5370(void) {
    s32 flag = 0;
    f32 f;

    if (((S_004E5370 *)&D_001A4BE0)->p1AC0 != 0) {
        flag = ((S_004E5370 *)&D_001A4BE0)->p1AC0[0x23] == 0x21;
    }
    if (((S_004E5370 *)&D_001A4BE0)->w25C4 != 0x9D && !flag) {
        return 0;
    }
    f = ((S_004E5370 *)&D_001A4BE0)->fC18;
    if (flag) {
        f = ((S_004E5370 *)&D_001A4BE0)->f1ACC;
    }
    if (((S_004E5370 *)&D_001A4BE0)->wC0C == 0) {
        s32 i = ((S_004E5370 *)&D_001A4BE0)->hBDC;
        if (D_001DBF80_sda[i] <= f && f <= D_001DBF90_sda[i]) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L30_004E5370 */

/* localdecomp:start func_L30_004E5410 */
#include "vu0.h"
/* log: (s32)func_L30_0041FE40(...) switch; -4 passed through an s32 local (retail converts it
 * at run time with cvt.s.w; a literal folds to lui 0xc080); fabs_asm (not __builtin_fabsf)
 * fixes the f2260/f2264 load order -> MATCH. */
typedef struct {
    u8 pad0[0x43];
    u8 b43;
} P_004E5410;

typedef struct {
    u8 pad0[0xC08];
    s32 wC08;
    u8 pad1[0x1B24 - 0xC0C];
    void *p1B24;
    u8 pad2[0x2260 - 0x1B28];
    f32 f2260;
    f32 f2264;
    u8 pad3[0x25C0 - 0x2268];
    P_004E5410 *p25C0;
    u8 pad4[0x2838 - 0x25C4];
    f32 f2838;
} S_004E5410;

extern u8 *D_001D52FC;
extern f32 func_0038D160(f32, f32);
extern f32 func_L30_0041FE40(s32, f32);

void func_L30_004E5410(void) {
    f32 v[2];
    s32 anim;
    s32 cur;
    s32 blend = -4;

    if ((((S_004E5410 *)&D_001A4BE0)->f2838 < 0.2f && !(*(s32 *)(D_001D52FC + 0x1A0) & 0x20))
        || ((S_004E5410 *)&D_001A4BE0)->p1B24 == 0) {
        if (((S_004E5410 *)&D_001A4BE0)->p25C0->b43 != 0x10) {
            func_L01_0050FB40(0x10, 0, 6.0f);
        }
        return;
    }
    anim = 0x17;
    v[0] = fabs_asm(((S_004E5410 *)&D_001A4BE0)->f2260);
    v[1] = ((S_004E5410 *)&D_001A4BE0)->f2264;
    switch ((s32)func_L30_0041FE40(0, func_0038D160(v[0], v[1]) / 0.7853982f)) {
    case -1:
        anim = 0x1A;
        break;
    case 1:
        anim = 0x14;
        break;
    case 2:
        anim = 0x11;
        break;
    case -2:
        anim = 0x1D;
        break;
    }
    cur = ((S_004E5410 *)&D_001A4BE0)->p25C0->b43;
    if (cur == anim) {
        return;
    }
    if (!(((S_004E5410 *)&D_001A4BE0)->wC08 & 2) && (u32)(cur - 0x11) < 0xF) {
        return;
    }
    func_L01_0050FB40(anim, 0, blend);
}
/* localdecomp:end func_L30_004E5410 */

/* localdecomp:start func_L30_004E5598 */
#include "vu0.h"
/* log: switch with three separate (identical) case bodies gives retail's 1/<2/0/2 decision tree
 * (a merged case 0..2 gives a range check); fabs_asm (as func_L30_004E5410) schedules abs.s after
 * c.lt.s where __builtin_fabsf put it before -> MATCH. 0x3E6147AF is 0.22000001f. */
typedef struct {
    u8 pad0[0x1B4];
    f32 f1B4;
    s32 w1B8;
    u8 pad1[0x344 - 0x1BC];
    f32 f344;
    u8 pad2[0xBDC - 0x348];
    s16 hBDC;
    u8 pad3[0x25C0 - 0xBDE];
    u8 *p25C0;
    s32 w25C4;
} S_004E5598;

extern void func_L01_004F40A8(void *, void *);
extern void func_L01_004EF178(f32);

void func_L30_004E5598(void) {
    f32 g;
    f32 dir;
    s32 n;
    f32 buf[4];

    if (((S_004E5598 *)&D_001A4BE0)->w25C4 != 0x9D) {
        return;
    }
    dir = 1.0f;
    if (*(u16 *)(((S_004E5598 *)&D_001A4BE0)->p25C0 + 0x34) & 0x8000) {
        dir = -1.0f;
    }
    g = 0.0f;
    n = 0;
    switch (((S_004E5598 *)&D_001A4BE0)->hBDC) {
    case 0:
        g = 0.22000001f;
        n = 6;
        break;
    case 1:
        g = 0.22000001f;
        n = 6;
        break;
    case 2:
        g = 0.22000001f;
        n = 6;
        break;
    }
    dir *= 1.7f;
    func_L01_004F40A8((u8 *)&D_001A4BE0 + 0x2C0, buf);
    ((S_004E5598 *)&D_001A4BE0)->f344 = buf[1];
    if (((S_004E5598 *)&D_001A4BE0)->w1B8 < n) {
        ((S_004E5598 *)&D_001A4BE0)->f1B4 = fabs_asm(g * dir);
        if (dir > 0.0f) {
            func_L01_004EF178(0.0f);
        } else {
            func_L01_004EF178(3.1415927f);
        }
    } else {
        ((S_004E5598 *)&D_001A4BE0)->f1B4 = 0.0f;
    }
}
/* localdecomp:end func_L30_004E5598 */

/* localdecomp:start func_L30_004E56D0 */
void func_L30_004E56D0(void) {
    u8 *obj = 0;

    switch (((S_004E56D0 *)&D_001A4BE0)->x1B04) {
    case 1:
        obj = func_003C24B0(0x15D5, 0x80);
        break;
    case 2:
        obj = func_003C24B0(0x1C7D, 0x80);
        break;
    case 4:
        obj = func_003C24B0(0x1C7E, 0x80);
        break;
    case 3:
    case 5:
        obj = func_003C24B0(0x1C7C, 0x80);
        break;
    default:
        break;
    }

    if (obj != 0) {
        ((S_004E56D0 *)&D_001A4BE0)->x1B24 = obj;
        *(s16 *)(obj + 0x32) = 0xFF;
        obj[0x31] = 1;
        *(long *)(obj + 0x38) = *(long *)(((S_004E56D0 *)&D_001A4BE0)->x25C0 + 0x38);
    }
}
/* localdecomp:end func_L30_004E56D0 */

/* localdecomp:start func_L30_004E5788 */
typedef struct {
    u8 pad0[0x2708];
    s32 ring[16];
    s32 idx;
} S_004E5788;

extern u8 *D_001D52FC;
typedef struct {
    u8 pad[7];
    u8 b7;
} B_004E5788;
extern B_004E5788 D_001D5468_004E5788;
extern B_004E5788 D_001D5498_004E5788;
__asm__(".extern D_001D5468_004E5788, 16");
__asm__(".extern D_001D5498_004E5788, 16");
extern s32 D_001DBFA0_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DBFA0_sda, 8");
extern void func_L30_004E71F0(s32);

s32 func_L30_004E5788(void) {
    s32 v = *(s32 *)(D_001D52FC + 0x1A4);
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 t;

    if (v == 0) {
        return 0;
    }
    ((S_004E5788 *)&D_001A4BE0)->ring[((S_004E5788 *)&D_001A4BE0)->idx] = v;
    ((S_004E5788 *)&D_001A4BE0)->idx++;
    for (i = 0; i < 1; i++) {
        n = 0;
        while (D_001DBFA0_sda[n] != 0) {
            n++;
        }
        if (n == 0) {
            continue;
        }
        k = ((S_004E5788 *)&D_001A4BE0)->idx - n;
        if (k < 0) {
            k += 16;
        }
        for (j = 0; j < n; j++) {
            if (((S_004E5788 *)&D_001A4BE0)->ring[k] != D_001DBFA0_sda[j]) {
                j = -1;
                break;
            }
            k++;
            if (k >= 16) {
                k -= 16;
            }
        }
        if (j == n) {
            D_001D5498_004E5788.b7 = 1;
            t = !D_001D5468_004E5788.b7;
            D_001D5468_004E5788.b7 = t;
            func_L30_004E71F0(t);
            break;
        }
    }
    if (((S_004E5788 *)&D_001A4BE0)->idx >= 16) {
        ((S_004E5788 *)&D_001A4BE0)->idx = 0;
    }
    return 0;
}
/* localdecomp:end func_L30_004E5788 */

/* localdecomp:start func_L30_004E58F8 */
typedef struct S_004E58F8 {
    u8 pad0[0x1B04];
    s32 x1B04;
    s32 x1B08;
    u8 pad1[0x1B10 - 0x1B0C];
    s32 x1B10;
    u8 pad2[0x1B24 - 0x1B14];
    u8 *x1B24;
    u8 pad3[0x1B34 - 0x1B28];
    s32 x1B34;
    u8 pad4[0x25C0 - 0x1B38];
    u8 *x25C0;
    u8 pad5[0x25CC - 0x25C4];
    s32 x25CC;
} S_004E58F8;

extern s32 D_L30_001DBE38[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DBE38, 8");
extern s32 D_L30_001DBE50[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DBE50, 8");
extern s32 D_L30_001DBE68;
__asm__(".extern D_L30_001DBE68, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_L30_001DF2C0;
__asm__(".extern D_L30_001DF2C0, 16");
extern s32 D_L30_001DF2C0_004E58F8;
__asm__(".extern D_L30_001DF2C0_004E58F8, 4");
extern u8 *D_001D52FC;
extern void func_003C2880(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L30_003514D8(s32);
extern void func_L30_004E56D0(void);
extern void func_L30_004E6AD0(s32);

void func_L30_004E58F8(void) {
    u8 *obj;
    s32 v;

    if (((S_004E58F8 *)&D_001A4BE0)->x1B04 != 0 && ((S_004E58F8 *)&D_001A4BE0)->x1B08 != 0 && ((S_004E58F8 *)&D_001A4BE0)->x1B24 == 0) {
        func_L30_004E56D0();
    }
    if (((S_004E58F8 *)&D_001A4BE0)->x1B04 == 0) {
        if (((S_004E58F8 *)&D_001A4BE0)->x1B24 != 0) {
            func_003C2880(((S_004E58F8 *)&D_001A4BE0)->x1B24);
        }
        ((S_004E58F8 *)&D_001A4BE0)->x1B24 = 0;
    }
    obj = ((S_004E58F8 *)&D_001A4BE0)->x1B24;
    if (obj != 0) {
        if (!((*(u8 **)(obj + 0x24))[0xC] < 2) && obj[0x43] != 0) {
            if (obj[0x60] & 2) {
                func_003C3A10(obj, 0, 0, 4);
            }
        }
        if (((S_004E58F8 *)&D_001A4BE0)->x1B24 != 0) {
            func_L01_0044FD88(((S_004E58F8 *)&D_001A4BE0)->x25C0, (s32)((S_004E58F8 *)&D_001A4BE0)->x1B24, 4, 0);
        }
    }
    if (((S_004E58F8 *)&D_001A4BE0)->x1B04 != 0) {
        v = D_L30_001DBE38[((S_004E58F8 *)&D_001A4BE0)->x1B04];
        if (D_001D545C == 0x22) {
            v = 0x32;
        }
        if (v < ((S_004E58F8 *)&D_001A4BE0)->x1B08) {
            ((S_004E58F8 *)&D_001A4BE0)->x1B08 = v;
        }
    }
    if (((S_004E58F8 *)&D_001A4BE0)->x25CC != 0x14 && ((S_004E58F8 *)&D_001A4BE0)->x25CC != 6 && ((S_004E58F8 *)&D_001A4BE0)->x25CC != 9 && ((S_004E58F8 *)&D_001A4BE0)->x25CC != 0x24 && ((S_004E58F8 *)&D_001A4BE0)->x25CC != 3) {
        if (func_L01_004606E8(0x20, 3, 0, 0) != 0) {
            if (((S_004E58F8 *)&D_001A4BE0)->x1B04 != 0 && ((S_004E58F8 *)&D_001A4BE0)->x1B08 > 0
                && (((S_004E58F8 *)&D_001A4BE0)->x1B34 == -1 || ((S_004E58F8 *)&D_001A4BE0)->x1B34 + D_L30_001DBE50[((S_004E58F8 *)&D_001A4BE0)->x1B04] < D_L30_001DF2C0)) {
                if (((S_004E58F8 *)&D_001A4BE0)->x1B24 == 0) {
                    func_L30_004E56D0();
                }
                func_L30_004E6AD0(0);
                ((S_004E58F8 *)&D_001A4BE0)->x1B08 = ((S_004E58F8 *)&D_001A4BE0)->x1B08 - 1;
                ((S_004E58F8 *)&D_001A4BE0)->x1B34 = D_L30_001DF2C0;
            } else if (((S_004E58F8 *)&D_001A4BE0)->x1B04 != 0 && ((S_004E58F8 *)&D_001A4BE0)->x1B08 <= 0
                       && (((S_004E58F8 *)&D_001A4BE0)->x1B34 == -1 || ((S_004E58F8 *)&D_001A4BE0)->x1B34 + D_L30_001DBE50[((S_004E58F8 *)&D_001A4BE0)->x1B04] < D_L30_001DF2C0)) {
                func_L01_004F4E70(0xD, 0);
            }
        }
    }
    if (((S_004E58F8 *)&D_001A4BE0)->x1B10 != 0) {
        if (((S_004E58F8 *)&D_001A4BE0)->x1B04 != 4 || ((S_004E58F8 *)&D_001A4BE0)->x1B08 <= 0 || ((S_004E58F8 *)&D_001A4BE0)->x25CC == 0x14 || ((S_004E58F8 *)&D_001A4BE0)->x25CC == 6 || ((S_004E58F8 *)&D_001A4BE0)->x25CC == 9
            || ((S_004E58F8 *)&D_001A4BE0)->x25CC == 0x24 || ((S_004E58F8 *)&D_001A4BE0)->x25CC == 3 || ((S_004E58F8 *)&D_001A4BE0)->x1B34 < 0
            || !(*(s32 *)(D_001D52FC + 0x1A0) & 0x20)) {
            func_L30_003514D8(((S_004E58F8 *)&D_001A4BE0)->x1B10);
            ((S_004E58F8 *)&D_001A4BE0)->x1B10 = 0;
            ((S_004E58F8 *)&D_001A4BE0)->x1B34 = -1;
        } else if (D_L30_001DF2C0_004E58F8 % D_L30_001DBE68 == 0) {
            ((S_004E58F8 *)&D_001A4BE0)->x1B08 = ((S_004E58F8 *)&D_001A4BE0)->x1B08 - 1;
        }
    }
}
/* localdecomp:end func_L30_004E58F8 */

INCLUDE_ASM("asm/levels", func_L30_004E5BF0);

/* localdecomp:start func_L30_004E5DD8 */
typedef struct {
    u8 pad0[0x98];
    f32 f98;
    u8 pad1[0x33C - 0x9C];
    f32 f33C;
    u8 pad2[0x25C4 - 0x340];
    s32 w25C4;
} S_004E5DD8;

typedef struct {
    u8 pad0[0x40];
    f32 f40;
    f32 f44;
} S2_004E5DD8;

extern S2_004E5DD8 D_L30_001E9000;
extern s32 func_L01_004E63F0(f32 *out, f32 scale, f32 amount);
extern s32 func_L01_00500240(s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);

s32 func_L30_004E5DD8(void) {
    f32 buf[4];
    f32 s;

    if (((S_004E5DD8 *)&D_001A4BE0)->f33C < 0.5f) {
        return 0;
    }
    if (!func_L01_004E63F0(buf, 0.3f, 2.0f)) {
        return 0;
    }
    s = 4.0f;
    if (((S_004E5DD8 *)&D_001A4BE0)->w25C4 == 0xA7 || func_L01_00500240(0xA7, 0x4B)) {
        s = 2.0f;
    }
    if (func_L01_00500240(0xA9, 8)) {
        s = 2.0f;
    }
    if (!func_L01_004E63F0(buf, s, 2.0f)) {
        return 0;
    }
    if (0.1f < buf[0]) {
        return 0;
    }
    if (func_0038DBA0(func_0038D160(D_L30_001E9000.f40, D_L30_001E9000.f44), ((S_004E5DD8 *)&D_001A4BE0)->f98) < 1.5707964f) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L30_004E5DD8 */

/* localdecomp:start func_L30_004E5F28 */
extern void func_L01_005110E8(s32, f32, f32, f32, s32);

void func_L30_004E5F28(s32 a) {
    func_L01_005110E8(a, 0.0f, 0.0f, 2.3f, 1);
}
/* localdecomp:end func_L30_004E5F28 */

/* localdecomp:start func_L30_004E5F58 */
typedef struct V_004E5F58 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_004E5F58;

typedef struct S_004E5F58 {
    u8 pad0[0x204];
    s16 x204;
    u8 pad1[0x670 - 0x206];
    V_004E5F58 x670;
    u8 pad1b[0x690 - 0x680];
    s32 x690;
    s32 x694;
    f32 x698;
    s32 x69C;
    u8 pad2[0x6AC - 0x6A0];
    s32 x6AC;
    u8 pad3[0x25CC - 0x6B0];
    s32 x25CC;
} S_004E5F58;

extern s32 func_L01_004E8BC8(V_004E5F58 *, s32 *, V_004E5F58 *, s32 *, f32 *, s32 *, s32, s32, s32);

void func_L30_004E5F58(void) {
    V_004E5F58 a;
    V_004E5F58 b;
    s32 c;
    s32 d;
    f32 e;
    s32 g;
    f32 dz;

    ((S_004E5F58 *)&D_001A4BE0)->x69C = 0;
    if (((S_004E5F58 *)&D_001A4BE0)->x204 != 0) {
        return;
    }
    func_L01_005110E8((s32)&a, 0.0f, 0.0f, 2.3f, 1);
    if (((S_004E5F58 *)&D_001A4BE0)->x25CC == 4 || ((S_004E5F58 *)&D_001A4BE0)->x25CC == 2) {
        if (func_L01_004E8BC8(&a, &c, &b, &d, &e, &g, 0, 0, 1) != 0) {
            dz = a.z - b.z;
            if (-1.1f < dz && dz < 1.0f) {
                ((S_004E5F58 *)&D_001A4BE0)->x670 = b;
                ((S_004E5F58 *)&D_001A4BE0)->x690 = c;
                ((S_004E5F58 *)&D_001A4BE0)->x694 = d;
                ((S_004E5F58 *)&D_001A4BE0)->x698 = e;
                ((S_004E5F58 *)&D_001A4BE0)->x6AC = g;
                ((S_004E5F58 *)&D_001A4BE0)->x69C = 1;
            }
        }
    }
}
/* localdecomp:end func_L30_004E5F58 */

INCLUDE_ASM("asm/levels", func_L30_004E6068);

INCLUDE_ASM("asm/levels", func_L30_004E6200);

/* localdecomp:start func_L30_004E6988 */
f32 func_L30_004E6988(void) {
    s32 x = D_001A4BE0.p25C0[0x43];
    f32 f = 0.0f;
    if (D_001A4BE0.w25C4 == 0xA3) {
        if ((u32)(x - 0x11) < 3) {
            f = 1.5707964f;
        }
        if ((u32)(x - 0x14) < 3) {
            f = 0.7853982f;
        }
        if ((u32)(x - 0x1A) < 3) {
            f = -0.7853982f;
        }
        if ((u32)(x - 0x1D) < 3) {
            f = -1.5707964f;
        }
    }
    if (*(u16 *)(D_001A4BE0.p25C0 + 0x34) & 0x8000) {
        f = 3.1415927f - f;
    }
    return f;
}
/* localdecomp:end func_L30_004E6988 */

INCLUDE_ASM("asm/levels", func_L30_004E6A48);

/* localdecomp:start func_L30_004E6AD0 */
typedef struct S_004E6AD0 {
    u8 pad0[0x1B04];
    s32 x1B04;
    u8 pad1[0x1B10 - 0x1B08];
    void *x1B10;
    u8 pad2[0x1B24 - 0x1B14];
    u8 *x1B24;
    u8 pad3[0x25C0 - 0x1B28];
    u8 *x25C0;
    s32 x25C4;
    u8 pad4[0x25E9 - 0x25C8];
    u8 x25E9;
    u8 pad5;
    u8 x25EB;
} S_004E6AD0;

typedef struct V_004E6AD0 {
    f32 v[4];
} V_004E6AD0;

extern f32 func_L30_004E6988(void);
extern void func_L30_004E6A48(V_004E6AD0 *, f32);
extern void func_L30_004B7BC8(s32, s32, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004AAC98(s32, s32, u8 *, s32);
extern void func_L30_00350DB0(V_004E6AD0 *, f32);
extern void func_L30_0034F1A8(V_004E6AD0 *, f32);
extern void func_L30_00347348(V_004E6AD0 *, f32);
extern void *func_L30_00351CB0(void *);

void func_L30_004E6AD0(s32 a0) {
    V_004E6AD0 v;
    f32 f;
    u8 *obj;

    ((S_004E6AD0 *)&D_001A4BE0)->x25E9 = 1;
    ((S_004E6AD0 *)&D_001A4BE0)->x25EB = a0;
    f = func_L30_004E6988();
    func_L30_004E6A48(&v, f);
    if (((S_004E6AD0 *)&D_001A4BE0)->x25C4 == 0x9A) {
        func_L01_0050FB40(((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4 ? 0x3F : 0xF, 0, 3.0f);
    } else if (((S_004E6AD0 *)&D_001A4BE0)->x25C4 == 0xA3) {
        s32 a;

        a = ((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4 ? 0x17 : 0x19;

        if (((S_004E6AD0 *)&D_001A4BE0)->x25C0[0x43] != 0x10) {
            s32 off = ((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4;
            if (((S_004E6AD0 *)&D_001A4BE0)->x25C0[0x43] % 3 == 2) {
                off = 2;
                if (((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4) {
                    off = 0;
                }
            }
            if (((S_004E6AD0 *)&D_001A4BE0)->x25C0[0x43] % 3 == 0) {
                off = 1;
                if (((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4) {
                    off = 2;
                }
            }
            a = ((S_004E6AD0 *)&D_001A4BE0)->x25C0[0x43] + off;
        }
        func_L01_0050FB40(a, 0, 3.0f);
    } else if (((S_004E6AD0 *)&D_001A4BE0)->x1B04 != 4) {
        func_L30_004B7BC8(1, 0x3E, 0, 0);
    }
    obj = ((S_004E6AD0 *)&D_001A4BE0)->x1B24;
    if (obj != 0 && !((*(u8 **)(obj + 0x24))[0xC] < 2) && obj[0x43] != 1) {
        func_003C3A10(obj, 1, 0, 4);
    }
    switch (((S_004E6AD0 *)&D_001A4BE0)->x1B04) {
    case 0:
        break;
    case 2:
        func_003A52A0(0x1F, 0, ((S_004E6AD0 *)&D_001A4BE0)->x25C0);
        func_L30_00350DB0(&v, f);
        break;
    case 3:
        func_L01_004AAC98(0, 0, ((S_004E6AD0 *)&D_001A4BE0)->x1B24, 0x1C7D);
        func_L30_0034F1A8(&v, f);
        break;
    case 4:
        if (((S_004E6AD0 *)&D_001A4BE0)->x1B10 == 0) {
            ((S_004E6AD0 *)&D_001A4BE0)->x1B10 = func_L30_00351CB0(((S_004E6AD0 *)&D_001A4BE0)->x25C0);
        }
        break;
    case 1:
    case 5:
        func_003A52A0(0, 0, ((S_004E6AD0 *)&D_001A4BE0)->x25C0);
        func_L30_00347348(&v, f);
        break;
    }
}
/* localdecomp:end func_L30_004E6AD0 */

LINKER_REMNANT("asm/levels", func_L30_004E6D00);

/* localdecomp:start func_L30_004E6D08 */
void func_L30_004E6D08(void) {
    if (((*(S_004E6D08 *)&D_001A4BE0).w_C08 & 2) != 0 && (*(S_004E6D08 *)&D_001A4BE0).b_25EB == 0) {
        s32 t = (*(S_004E6D08 *)&D_001A4BE0).p_25C0->b43;
        if (t == 19 || t == 22 || t == 25 || t == 28 || t == 31) {
            func_L01_0050FB40((*(S_004E6D08 *)&D_001A4BE0).p_25C0->b43 - 2, 0, 3.0f);
        }
        (*(S_004E6D08 *)&D_001A4BE0).b_25E9 = 0;
    }
    if ((*(S_004E6D08 *)&D_001A4BE0).w_25CC != 0) {
        if ((*(S_004E6D08 *)&D_001A4BE0).w_1AC0 == 0) {
            (*(S_004E6D08 *)&D_001A4BE0).b_25E9 = 0;
        }
    }
}
/* localdecomp:end func_L30_004E6D08 */

/* localdecomp:start func_L30_004E6DC8 */
s32 func_L30_004E6DC8(s32 a0) {
    u8 *b = (u8 *)&D_001A4BE0;
    s32 on;
    if (*(u8 **)(b + 0x1B24) != 0) {
        on = 1;
    } else {
        on = 0;
    }
    switch (a0) {
    case 0x2C:
        if (on) {
            return 0x30;
        }
        break;
    case 7:
        if (on) {
            return 0x2F;
        }
        break;
    case 1:
        if (on) {
            return *(s32 *)(b + 0x1B10) == 0 ? 0x31 : 0x3F;
        }
        break;
    }
    return a0;
}
/* localdecomp:end func_L30_004E6DC8 */

/* localdecomp:start func_L30_004E6E50 */
void func_L30_004E6E50(void) {
    u8 *b = (u8 *)&D_001A4BE0;
    u8 *q = *(u8 **)(b + 0x25C0);
    s32 a1 = 0xE;
    s32 f = 2;
    s32 v;

    if (q[0x43] == 0x3A) {
        a1 = 0xB;
        f = 4;
    }
    func_L01_0050FB40(0x3A, a1, (f32)f);
    v = *(s32 *)(b + 0x25CC);
    *(s16 *)(b + 0x1B3C) = 1;
    *(s16 *)(b + 0xBDC) = 0;
    if (v != 2) {
        func_L30_004CF4B0(0x9C, 0);
    }
    *(s16 *)(b + 0x1E0) = 0x11;
}
/* localdecomp:end func_L30_004E6E50 */

/* localdecomp:start func_L30_004E6ED8 */
typedef int Q_004E6ED8 __attribute__((mode(TI)));

typedef struct V_004E6ED8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_004E6ED8;

typedef struct S_004E6ED8 {
    u8 pad0[0xC08];
    s32 xC08;
    s32 xC0C;
    u8 pad1[0xC18 - 0xC10];
    f32 xC18;
    u8 pad2[0x1AE4 - 0xC1C];
    f32 x1AE4;
    u8 pad3[0x1B3C - 0x1AE8];
    s16 x1B3C;
    u8 pad4[0x25C0 - 0x1B3E];
    u8 *x25C0;
    u8 pad5[0x25CC - 0x25C4];
    s32 x25CC;
} S_004E6ED8;

extern f32 D_L30_001DBFD4;
__asm__(".extern D_L30_001DBFD4, 4");
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_004EE7F8(f32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L30_0034CB68(void *, void *, s32, s32, s32, s32, f32, f32);
extern s32 func_L30_004E6DC8(s32);

void func_L30_004E6ED8(void) {
    V_004E6ED8 v;

    if (((S_004E6ED8 *)&D_001A4BE0)->x1B3C == 0) {
        return;
    }
    *(Q_004E6ED8 *)&v = 0;
    v.x = 1.0f;
    v.w = 1.0f;
    if (*(u16 *)(((S_004E6ED8 *)&D_001A4BE0)->x25C0 + 0x34) & 0x8000) {
        func_0038CE20(&v, &v, -1.0f);
    }
    if (func_L01_004EE7F8(D_L30_001DBFD4) != 0) {
        func_L01_004F4E70(7, 0);
    }
    if (((S_004E6ED8 *)&D_001A4BE0)->xC0C == 0 && 11.0f < ((S_004E6ED8 *)&D_001A4BE0)->xC18
        && ((S_004E6ED8 *)&D_001A4BE0)->xC18 < 19.0f) {
        func_L30_0034CB68(((S_004E6ED8 *)&D_001A4BE0)->x25C0, &v, 0, 0, 0, 0, ((S_004E6ED8 *)&D_001A4BE0)->x1AE4, 0.75f);
    }
    if (((S_004E6ED8 *)&D_001A4BE0)->x25CC == 2 && ((S_004E6ED8 *)&D_001A4BE0)->x25C0[0x43] == 0x3A
        && 27.5f <= ((S_004E6ED8 *)&D_001A4BE0)->xC18 && ((S_004E6ED8 *)&D_001A4BE0)->xC0C == 0) {
        func_L01_0050FB40(0x2D, 0, 6.0f);
    }
    if (((S_004E6ED8 *)&D_001A4BE0)->x25CC == 0 && ((S_004E6ED8 *)&D_001A4BE0)->x25C0[0x43] == 0x3A
        && (((S_004E6ED8 *)&D_001A4BE0)->xC08 & 2)) {
        func_L01_0050FB40(func_L30_004E6DC8(1), 0, 4.0f);
    }
    if (((S_004E6ED8 *)&D_001A4BE0)->x25C0[0x43] != 0x3A) {
        ((S_004E6ED8 *)&D_001A4BE0)->x1B3C = 0;
    }
}
/* localdecomp:end func_L30_004E6ED8 */

INCLUDE_ASM("asm/levels", func_L30_004E70A8);

/* localdecomp:start func_L30_004E71F0 */
typedef int Q_004E71F0 __attribute__((mode(TI)));

typedef struct E_004E71F0 {
    s32 x0;
    u8 pad[0xC];
} E_004E71F0;

typedef struct S_004E71F0 {
    u8 pad0[0x80];
    Q_004E71F0 x80;
    Q_004E71F0 x90;
    u8 pad1[0x1AB0 - 0xA0];
    E_004E71F0 x1AB0[3];
    u8 pad2[0x1AFC - 0x1AE0];
    s32 x1AFC;
    u8 pad3[0x25C0 - 0x1B00];
    u8 *x25C0;
} S_004E71F0;

typedef struct G_004E71F0 {
    u8 pad[0x77];
    u8 x77;
} G_004E71F0;

extern G_004E71F0 D_00142660_004E71F0;
__asm__(".extern D_00142660_004E71F0, 16");
extern void func_003C2880(void *);
extern s32 func_L01_0044E7D8(void *);
extern void func_L01_0044E820(void *, s32);

void func_L30_004E71F0(s32 a0) {
    u8 s[2];
    u8 r[2];
    u8 *o;
    s32 i;
    s32 cls = a0 != 0 ? 0x1EF9 : 0x1363;

    s[0] = ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x42];
    s[1] = ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x43];
    r[0] = ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x40];
    r[1] = ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x41];
    if (a0 != 0) {
        D_00142660_004E71F0.x77 |= 0x80;
    } else {
        D_00142660_004E71F0.x77 &= 0x7F;
    }
    o = func_003C24B0(cls, 0x80);
    if (o == 0) {
        return;
    }
    *(s16 *)(o + 0x32) = 0xFF;
    *(Q_004E71F0 *)(o + 0x10) = ((Q_004E71F0 *)((u8 *)&D_001A4BE0 + 0x80))[0];
    *(Q_004E71F0 *)(o + 0xF0) = ((Q_004E71F0 *)((u8 *)&D_001A4BE0 + 0x80))[1];
    *(long *)(o + 0x38) = *(long *)(((S_004E71F0 *)&D_001A4BE0)->x25C0 + 0x38);
    func_003C2880(((S_004E71F0 *)&D_001A4BE0)->x25C0);
    ((S_004E71F0 *)&D_001A4BE0)->x25C0 = o;
    *(s32 *)(o + 0x64) = 0;
    *(u16 *)(((S_004E71F0 *)&D_001A4BE0)->x25C0 + 0x34) |= 2;
    *(f32 *)(((S_004E71F0 *)&D_001A4BE0)->x25C0 + 0x2C) *= 0.83f;
    if (*(s16 *)(((S_004E71F0 *)&D_001A4BE0)->x25C0 + 0xAA) == 0x1EF9) {
        ((S_004E71F0 *)&D_001A4BE0)->x1AFC = func_L01_0044E7D8(((S_004E71F0 *)&D_001A4BE0)->x25C0);
        func_L01_0044E820(((S_004E71F0 *)&D_001A4BE0)->x25C0, 0x606060);
    } else {
        func_L01_0044E820(((S_004E71F0 *)&D_001A4BE0)->x25C0, ((S_004E71F0 *)&D_001A4BE0)->x1AFC);
    }
    ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x42] = s[0];
    ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x43] = s[1];
    ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x40] = r[0];
    ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x41] = r[1];
    for (i = 2; i >= 0; i--) {
        ((S_004E71F0 *)&D_001A4BE0)->x1AB0[i].x0 = 0;
    }
}
/* localdecomp:end func_L30_004E71F0 */

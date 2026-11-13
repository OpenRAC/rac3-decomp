#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L14_00361598 */
__asm__(".extern D_L14_001DF71C, 16");
extern u8 *D_L14_001DF71C;
extern char D_001A4C60[];
extern s32 func_L01_00456500(void *, s32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003C7C38(void *);
extern s32 func_0038CB00(void *);
void func_L14_00361598(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *o;
    f32 t;
    if (a0[0x20] == 0) {
        a0[0x20] = 1;
    }
    switch (a0[0x20]) {
    case 1:
        if (func_L01_00456500(D_001A4C60, *(s32 *)s) != 0) {
            a0[0x20] = 2;
            *(s16 *)(s + 0x12) = (*(s16 *)(s + 0x10) * 5 + 2) / 6;
            *(f32 *)(s + 0x14) = *(f32 *)(a0 + 0xF0);
            *(f32 *)(s + 0x18) = *(f32 *)(a0 + 0xF4);
            *(f32 *)(s + 0x1C) = *(f32 *)(a0 + 0xF8);
        }
        break;
    case 2:
        o = D_L14_001DF71C + (*(s32 *)(s + 0x20) << 8);
        t = 1.0f - (f32)*(s16 *)(s + 0x12) / (f32)((*(s16 *)(s + 0x10) * 5 + 2) / 6);
        if (*(f32 *)(s + 4) != 0.0f) {
            *(f32 *)(o + 0xF0) = *(f32 *)(s + 0x14) + func_003C3BE8(0.0f, *(f32 *)(s + 4) * 0.017453292f, t);
        }
        if (*(f32 *)(s + 8) != 0.0f) {
            *(f32 *)(o + 0xF4) = *(f32 *)(s + 0x18) + func_003C3BE8(0.0f, *(f32 *)(s + 8) * 0.017453292f, t);
        }
        if (*(f32 *)(s + 0xC) != 0.0f) {
            *(f32 *)(o + 0xF8) = *(f32 *)(s + 0x1C) + func_003C3BE8(0.0f, *(f32 *)(s + 0xC) * 0.017453292f, t);
        }
        func_003C7C38(o);
        if (func_0038CB00(s + 0x12) != 0) {
            a0[0x20] = 3;
        }
        break;
    case 3:
        break;
    }
}
/* localdecomp:end func_L14_00361598 */

/* localdecomp:start func_L14_00361788 */
s32 func_L14_00362868(s32, s32);
void func_L01_00404A10(void *, void *);
void func_L01_0044F450(void *, s32);
void func_L14_00361F40(void *, s32);
void func_L14_00361F98(void *, s32);
extern u8 D_L14_00362D30[];

void func_L14_00361788(void *arg0) {
    s32 temp_s0;

    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    if (func_L14_00362868((s32) arg0, temp_s0) != 0) {
        func_L01_0044F450(arg0, temp_s0 + 0x60);
        func_L14_00361F40(arg0, temp_s0);
        func_L14_00361F98(arg0, temp_s0);
        func_L01_00404A10(D_L14_00362D30, arg0);
    }
}
/* localdecomp:end func_L14_00361788 */

/* localdecomp:start func_L14_003617F8 */
extern u16 **D_L14_001D6764;
extern u8 *D_L14_001E05D4;
extern u8 D_L14_0023B0C0[];
__asm__(".extern D_L14_001DD860, 4");
__asm__(".extern D_L14_001DD864, 4");
__asm__(".extern D_L14_001DD868, 1");
__asm__(".extern D_L14_001DD86C, 4");
__asm__(".extern D_L14_001DD898, 4");
__asm__(".extern D_L14_001DD89C, 4");
__asm__(".extern D_L14_001DD8A0, 4");
extern s32 D_L14_001DD860;
extern f32 D_L14_001DD864;
extern u8 D_L14_001DD868;
extern f32 D_L14_001DD86C;
extern s32 D_L14_001DD898;
extern f32 D_L14_001DD89C;
extern f32 D_L14_001DD8A0;
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044F888(void *, s32, s32, void *, s32);
extern void func_0038D308(void *, void *);
extern void func_L14_00361E90(u8 *, u8 *, f32 *);
extern s32 func_L01_00470150(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
s32 func_L14_003617F8(u8 *a0, u8 *a1) {
    f32 loc[3];
    f32 saved;
    s32 r;
    f32 f;
    f32 g;
    s32 q;
    u16 *p;
    u8 *e;
    a0[0x30] = 0xFF;
    *(s16 *)(a0 + 0x32) = 0x1FF;
    saved = *(f32 *)(a0 + 0xF8);
    qzero(a0 + 0xF0);
    func_L01_0044ED88(a0, a1 + 0x60, 5, -1, *(s32 *)a1, -1, 7, 0);
    a1[0xAD] = 1;
    p = D_L14_001D6764[*(s32 *)a1];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L14_001D6764[*(s32 *)a1])) {
        e = D_L14_001E05D4 + ((*p & 0x7FFF) << 5);
        if (e == 0) {
            break;
        }
        if (D_L14_0023B0C0[*(s32 *)(a1 + 4)] == e[0x1D]) {
            func_L01_0044F888(a1 + 0x60, 1, *(u16 *)(e + 0x12), a1 + 0x1F0, 0xA0);
        } else if (D_L14_0023B0C0[*(s32 *)(a1 + 8)] == e[0x1D]) {
            func_L01_0044F888(a1 + 0x60, 1, *(u16 *)(e + 0x12), a1 + 0x210, 0xA0);
        }
        p++;
    }
    *(f32 *)(a0 + 0xF8) = saved;
    func_0038D308(a0 + 0xC0, a0 + 0xF0);
    *(s32 *)(a1 + 0x20) = 0;
    *(s32 *)(a1 + 0x24) = 0;
    *(s32 *)(a1 + 0x28) = 0;
    *(s32 *)(a1 + 0x38) = 0;
    *(s32 *)(a1 + 0x3C) = 0;
    *(s32 *)(a1 + 0x40) = 0;
    *(s32 *)(a1 + 0x44) = 0;
    *(s32 *)(a1 + 0x48) = -1;
    func_L14_00361E90(a0, a1, loc);
    r = func_L01_00470150(loc, a0, D_L14_001DD860, -1, 1, -1, 0, 0x1FF, D_L14_001DD864 * 210000.0f, D_L14_001DD86C, 1.0f, D_L14_001DD868, 0);
    f = D_L14_001DD89C * 210000.0f;
    g = D_L14_001DD8A0;
    q = D_L14_001DD898;
    *(s32 *)(a1 + 0x2C) = r;
    *(s32 *)(a1 + 0x30) = func_L01_00470150(loc, a0, q, -1, 0, -1, 1, 0x1FF, f, g, 1.0f, 0, 0);
    func_L01_004450F0(a0, 1, 1);
    return 4;
}
/* localdecomp:end func_L14_003617F8 */

/* localdecomp:start func_L14_00361A50 */
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
void func_L14_00361A50(u8 *a0, u8 *a1) {
    *(f32 *)(a1 + 0x18) = func_003824E0(-(*(f32 *)(a1 + 0xC) * 0.017453292f), *(f32 *)(a1 + 0x10) * 0.1f * 0.017453292f);
    *(f32 *)(a1 + 0x1C) = func_0038DB48(func_003824E0(*(f32 *)(a1 + 0x50) * 0.017453292f, *(f32 *)(a1 + 0x54) * 0.017453292f));
    if (func_0038DB00(*(f32 *)(a1 + 0x1C), *(f32 *)(a0 + 0xF8)) < 0.0f) {
        *(f32 *)(a1 + 0x1C) = func_0038DAB8(*(f32 *)(a1 + 0x1C), -0.2617994f);
    } else {
        *(f32 *)(a1 + 0x1C) = func_0038DAB8(*(f32 *)(a1 + 0x1C), 0.2617994f);
    }
}
/* localdecomp:end func_L14_00361A50 */

/* localdecomp:start func_L14_00361B30 */
__asm__(".extern D_L14_001DD840, 4");
__asm__(".extern D_L14_001DD844, 4");
__asm__(".extern D_L14_001DD848, 4");
__asm__(".extern D_L14_001DD84C, 4");
__asm__(".extern D_L14_001DD85C, 4");
extern f32 D_L14_001DD840;
extern f32 D_L14_001DD844;
extern f32 D_L14_001DD848;
extern f32 D_L14_001DD84C;
extern f32 D_L14_001DD85C;
extern u8 D_001A30B0[];
extern f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_0038D308(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern void func_003A4F28(s32);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_L01_004AADE8(s32, s32, void *, s32);
s32 func_L14_00361B30(u8 *a0, u8 *a1) {
    s32 r1 = 0;
    s32 r2 = 0;
    s32 idx;
    u8 *e;
    f32 t;
    func_L01_00448890(a0 + 0xF8, a1 + 0x20, 0, *(f32 *)(a1 + 0x1C), D_L14_001DD844 * 0.017453292f * 0.00040000002f, D_L14_001DD844 * 0.017453292f * 0.00040000002f, D_L14_001DD840 * 0.017453292f * 0.020000001f);
    func_0038D308(a0 + 0xC0, a0 + 0xF0);
    func_L01_00448890(a1 + 0x1F4, a1 + 0x24, 0, *(f32 *)(a1 + 0x18), D_L14_001DD84C * 0.017453292f * 0.00040000002f, D_L14_001DD84C * 0.017453292f * 0.00040000002f, D_L14_001DD848 * 0.017453292f * 0.020000001f);
    *(f32 *)(a1 + 0x214) = *(f32 *)(a1 + 0x1F4);
    if (fabs_asm(func_0038DBA0(*(f32 *)(a1 + 0x1C), *(f32 *)(a0 + 0xF8))) < D_L14_001DD85C) {
        *(s32 *)(a1 + 0x20) = 0;
        r1 = 1;
    }
    if (fabs_asm(func_0038DBA0(*(f32 *)(a1 + 0x18), *(f32 *)(a1 + 0x1F4))) < D_L14_001DD85C) {
        *(s32 *)(a1 + 0x24) = 0;
        r2 = 1;
    }
    if (r1 != 0 && r2 != 0) {
        idx = *(s32 *)(a1 + 0x48);
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        *(s32 *)(a1 + 0x48) = -1;
    } else if (func_L01_004AA710(a0, *(s32 *)(a1 + 0x48)) == 0) {
        *(s32 *)(a1 + 0x48) = func_L01_004AADE8(0x10, 4, a0, 0);
    }
    return r1 && r2;
}
/* localdecomp:end func_L14_00361B30 */

/* localdecomp:start func_L14_00361D00 */
extern u8 *D_L14_001E05DC;
__asm__(".extern D_L14_001DD820, 4");
extern f32 D_L14_001DD820;
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(f32 *, void *, f32);
void func_L14_00361D00(u8 *a0, u8 *a1, void *a2, void *a3) {
    vu0_v4 v;
    u8 *p;
    for (p = a1 + 0x60;; p += 0x50) {
        if (*(s32 *)(p + 0x40) == (s32)(a1 + 0x1F0)) {
            func_0038CF68(a3, D_L14_001E05DC + (*(s16 *)(p + 0x48) << 6), 1.0f);
            func_0038CE20((f32 *)&v, a3, D_L14_001DD820 + *(f32 *)(a1 + 0x200));
            vec_add_ba(a2, &v, a0 + 0x10);
            return;
        }
        if (*(u8 *)(p + 0x4A) == 1) {
            break;
        }
    }
}
/* localdecomp:end func_L14_00361D00 */

/* localdecomp:start func_L14_00361DC0 */
extern vu0_q D_L14_001E9160;
__asm__(".extern D_L14_001DD8DC, 4");
extern f32 D_L14_001DD8DC;
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
void func_L14_00361DC0(void *a0, u8 *a1) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    func_L14_00361D00(a0, a1, &a, &b);
    func_0038CE20((f32 *)&c, &b, 5.0f);
    vec_add_ab(&c, &c, &a);
    func_0038CE20((f32 *)&d, &b, D_L14_001DD8DC);
    vec_add_ab(&d, &d, &a);
    if (func_003D3CB0(&c, &d, 2, 0, 0) != 0) {
        *(vu0_q *)(a1 + 0x230) = D_L14_001E9160;
    } else {
        *(vu0_q *)(a1 + 0x230) = *(vu0_q *)&d;
    }
}
/* localdecomp:end func_L14_00361DC0 */

/* localdecomp:start func_L14_00361E90 */
__asm__(".extern D_L14_001DD824, 4");
extern f32 D_L14_001DD824;
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_0038CE68(void *, void *);
void func_L14_00361E90(u8 *a0, u8 *a1, f32 *a2) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 e;
    vu0_v4 c;
    func_L14_00361D00(a0, a1, &a, &b);
    func_0038CE20((f32 *)&c, &b, D_L14_001DD824);
    vec_add_ba(&e, &c, &a);
    vec_sub_ba(&e, &e, a0 + 0x10);
    a2[0] = func_0038CE68(&e, a0 + 0xC0);
    a2[1] = func_0038CE68(&e, a0 + 0xD0);
    a2[2] = func_0038CE68(&e, a0 + 0xE0);
}
/* localdecomp:end func_L14_00361E90 */

INCLUDE_ASM("asm/levels", func_L14_00361F40);

/* localdecomp:start func_L14_00361F98 */
__asm__(".extern D_L14_001DD830, 4");
__asm__(".extern D_L14_001DD838, 4");
__asm__(".extern D_L14_001DD860, 4");
__asm__(".extern D_L14_001DD870, 4");
__asm__(".extern D_L14_001DD874, 4");
__asm__(".extern D_L14_001DD878, 4");
__asm__(".extern D_L14_001DD87C, 4");
__asm__(".extern D_L14_001DD880, 4");
__asm__(".extern D_L14_001DD884, 4");
__asm__(".extern D_L14_001DD888, 4");
__asm__(".extern D_L14_001DD88C, 4");
__asm__(".extern D_L14_001DD890, 4");
__asm__(".extern D_L14_001DD894, 4");
__asm__(".extern D_L14_001DD898, 4");
__asm__(".extern D_L14_001DD8A4, 4");
__asm__(".extern D_L14_001DD8A8, 4");
__asm__(".extern D_L14_001DD8AC, 4");
__asm__(".extern D_L14_001DD8B0, 4");
__asm__(".extern D_L14_001DD8B4, 4");
__asm__(".extern D_L14_001DD8B8, 4");
__asm__(".extern D_L14_001DD8BC, 4");
__asm__(".extern D_L14_001DD8C0, 4");
__asm__(".extern D_L14_001DD8C4, 4");
__asm__(".extern D_L14_001DD8C8, 4");
extern s32 D_L14_001DD830;
extern s32 D_L14_001DD838;
extern s32 D_L14_001DD860;
extern f32 D_L14_001DD870;
extern f32 D_L14_001DD874;
extern f32 D_L14_001DD878;
extern s32 D_L14_001DD87C;
extern s32 D_L14_001DD880;
extern f32 D_L14_001DD884;
extern f32 D_L14_001DD888;
extern f32 D_L14_001DD88C;
extern s32 D_L14_001DD890;
extern s32 D_L14_001DD894;
extern s32 D_L14_001DD898;
extern f32 D_L14_001DD8A4;
extern f32 D_L14_001DD8A8;
extern f32 D_L14_001DD8AC;
extern s32 D_L14_001DD8B0;
extern s32 D_L14_001DD8B4;
extern f32 D_L14_001DD8B8;
extern f32 D_L14_001DD8BC;
extern f32 D_L14_001DD8C0;
extern s32 D_L14_001DD8C4;
extern s32 D_L14_001DD8C8;
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
typedef struct {
    u8 pad0[4];
    s32 pitch;
    u8 pad8[4];
    f32 vol;
} S_361F98;
void func_L14_00361F98(void *obj, s32 vars) {
    u8 *a0 = obj;
    u8 *a1 = (u8 *)vars;
    f32 t;
    f32 v;
    switch (a0[0x20]) {
    case 3:
        t = 1.0f - (f32)*(s32 *)(a1 + 0x14) / (f32)D_L14_001DD830;
        v = D_L14_001DD870 + (D_L14_001DD874 - D_L14_001DD870) * t;
        v *= func_003824E0(1.0f, D_L14_001DD878 + 1.0f);
        (*(S_361F98 **)(a1 + 0x2C))->vol = v * 210000.0f;
        (*(S_361F98 **)(a1 + 0x2C))->pitch = func_0038DBD8(D_L14_001DD87C, D_L14_001DD880, t);
        v = D_L14_001DD8A4 + (D_L14_001DD8A8 - D_L14_001DD8A4) * t;
        v *= func_003824E0(1.0f, D_L14_001DD8AC + 1.0f);
        (*(S_361F98 **)(a1 + 0x30))->vol = v * 210000.0f;
        (*(S_361F98 **)(a1 + 0x30))->pitch = func_0038DBD8(D_L14_001DD8B0, D_L14_001DD8B4, t);
        break;
    case 4:
        v = D_L14_001DD874 * func_003824E0(1.0f, D_L14_001DD878 + 1.0f);
        (*(S_361F98 **)(a1 + 0x2C))->vol = v * 210000.0f;
        v = D_L14_001DD8A8 * func_003824E0(1.0f, D_L14_001DD8AC + 1.0f);
        (*(S_361F98 **)(a1 + 0x30))->vol = v * 210000.0f;
        (*(S_361F98 **)(a1 + 0x2C))->pitch = D_L14_001DD880;
        (*(S_361F98 **)(a1 + 0x30))->pitch = D_L14_001DD8B4;
        break;
    case 5:
        t = 1.0f - (f32)*(s32 *)(a1 + 0x14) / (f32)D_L14_001DD838;
        t *= 0.75f;
        if (t < 1.0f) {
            v = D_L14_001DD888 - (D_L14_001DD888 - D_L14_001DD884) * t;
            v *= func_003824E0(1.0f, D_L14_001DD88C + 1.0f);
            (*(S_361F98 **)(a1 + 0x2C))->vol = v * 210000.0f;
            (*(S_361F98 **)(a1 + 0x2C))->pitch = func_0038DBD8(D_L14_001DD890, D_L14_001DD894, t);
            t *= 1.25f;
            if (t < 1.0f) {
                v = D_L14_001DD8BC - (D_L14_001DD8BC - D_L14_001DD8B8) * t;
                v *= func_003824E0(1.0f, D_L14_001DD8C0 + 1.0f);
                (*(S_361F98 **)(a1 + 0x30))->vol = v * 210000.0f;
                (*(S_361F98 **)(a1 + 0x30))->pitch = func_0038DBD8(D_L14_001DD8C4, D_L14_001DD8C8, t);
            } else {
                (*(S_361F98 **)(a1 + 0x30))->pitch = D_L14_001DD898;
            }
            break;
        }
    default:
        (*(S_361F98 **)(a1 + 0x2C))->pitch = D_L14_001DD860;
        (*(S_361F98 **)(a1 + 0x30))->pitch = D_L14_001DD898;
        break;
    }
}
/* localdecomp:end func_L14_00361F98 */

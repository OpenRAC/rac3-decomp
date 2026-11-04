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

INCLUDE_ASM("asm/levels", func_L39_006DC7A8);

INCLUDE_ASM("asm/levels", func_L39_006DC7C8);

INCLUDE_ASM("asm/levels", func_L39_006DCAD0);

/* localdecomp:start func_L39_006DCC80 */
s32 func_0017DF20();
void func_001961E8(s32);
extern void *D_001E2050;

s32 func_L39_006DCC80(void) {
    s32 temp_v0;
    void *temp_s1;

    temp_s1 = D_001E2050;
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

INCLUDE_ASM("asm/levels", func_L39_006DCCE0);

INCLUDE_ASM("asm/levels", func_L39_006DCD38);

INCLUDE_ASM("asm/levels", func_L39_006DCDB8);

INCLUDE_ASM("asm/levels", func_L39_006DD028);

INCLUDE_ASM("asm/levels", func_L39_006DD060);

/* localdecomp:start func_L39_006DD340 */
s32 func_0017E140();
s32 func_001961F8();
void func_001961E8(s32);
extern void *D_001E2050;
extern u8 D_001A5FB5[];

s32 func_L39_006DD340(void *arg0) {
    void *temp_s0;
    s32 temp_v0;

    temp_s0 = D_001E2050;
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

INCLUDE_ASM("asm/levels", func_L39_006DD3D0);

INCLUDE_ASM("asm/levels", func_L39_006DD400);

INCLUDE_ASM("asm/levels", func_L39_006DD438);

INCLUDE_ASM("asm/levels", func_L39_006DD468);

INCLUDE_ASM("asm/levels", func_L39_006DD4D0);

INCLUDE_ASM("asm/levels", func_L39_006DD5B8);

LINKER_REMNANT("asm/levels", func_L39_006DD600);

INCLUDE_ASM("asm/levels", func_L39_006DD608);

INCLUDE_ASM("asm/levels", func_L39_006DD770);

INCLUDE_ASM("asm/levels", func_L39_006DD860);

INCLUDE_ASM("asm/levels", func_L39_006DD9B0);

INCLUDE_ASM("asm/levels", func_L39_006DDDE8);

INCLUDE_ASM("asm/levels", func_L39_006DDE00);

INCLUDE_ASM("asm/levels", func_L39_006DDF78);

INCLUDE_ASM("asm/levels", func_L39_006DE010);

INCLUDE_ASM("asm/levels", func_L39_006DE030);

INCLUDE_ASM("asm/levels", func_L39_006DE180);

INCLUDE_ASM("asm/levels", func_L39_006DE2D0);

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

INCLUDE_ASM("asm/levels", func_L39_006DE4E0);

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

INCLUDE_ASM("asm/levels", func_L39_006DEA18);

INCLUDE_ASM("asm/levels", func_L39_006DEA58);

INCLUDE_ASM("asm/levels", func_L39_006DEA78);

INCLUDE_ASM("asm/levels", func_L39_006DEAA0);

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

INCLUDE_ASM("asm/levels", func_L39_006DF598);

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

INCLUDE_ASM("asm/levels", func_L39_006E1538);

INCLUDE_ASM("asm/levels", func_L39_006E1558);

/* localdecomp:start func_L39_006E1648 */
s32 func_L01_00521C90(s32, s32);
void func_L39_006E1558(s32, s32, s32, s32);

void func_L39_006E1648(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_L39_006E1558(func_L01_00521C90(0x20, arg0), arg1, arg2, arg3);
}
/* localdecomp:end func_L39_006E1648 */

INCLUDE_ASM("asm/levels", func_L39_006E16A0);

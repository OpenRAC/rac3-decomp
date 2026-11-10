#include "common.h"

/* localdecomp:start func_L39_006B6A80 */
typedef struct S_6B6A80_C S_6B6A80_C;
typedef struct S_6B6A80_B {
    char _p0[0x24];
    void (*f24)(S_6B6A80_C *arg0);
} S_6B6A80_B;
struct S_6B6A80_C {
    char _p0[0x60];
    S_6B6A80_B *f60;
};
typedef struct S_6B6A80_A {
    char _p0[0x110];
    S_6B6A80_C *f110;
} S_6B6A80_A;

/* from rac4-decomp's func_L00_0071AB38 */
void func_L39_006B6A80(S_6B6A80_A *arg0) {
    S_6B6A80_C *o = arg0->f110;
    o->f60->f24(o);
}
/* localdecomp:end func_L39_006B6A80 */

/* localdecomp:start func_L39_006B6AA8 */
typedef struct T3_6B6AA8 T3_6B6AA8;
typedef struct T2_6B6AA8 {
    char _p0[0xB8];
    void (*fB8)(T3_6B6AA8 *arg0);
} T2_6B6AA8;
struct T3_6B6AA8 {
    char _p0[0x60];
    T2_6B6AA8 *f60;
};
typedef struct T1_6B6AA8 {
    char _p0[0x114];
    T3_6B6AA8 *f114;
} T1_6B6AA8;

/* from rac4-decomp's func_L00_0071AB38 */
void func_L39_006B6AA8(T1_6B6AA8 *arg0) {
    T3_6B6AA8 *o = arg0->f114;
    o->f60->fB8(o);
}
/* localdecomp:end func_L39_006B6AA8 */

/* localdecomp:start func_L39_006B6AD0 */
s32 func_L39_006B6AD0(s32 arg0) {
    return arg0 + 0x2A8;
}
/* localdecomp:end func_L39_006B6AD0 */

/* localdecomp:start func_L39_006B6AD8 */
typedef struct V_006B6AD8 {
    char _p0[0x1C];
    s32 (*f1C)(void *, s32, s32);
} V_006B6AD8;
typedef struct O_006B6AD8 {
    char _p0[0x60];
    V_006B6AD8 *f60;
} O_006B6AD8;
typedef struct S_006B6AD8 {
    char _p0[0x118];
    O_006B6AD8 *f118;
    O_006B6AD8 *f11C;
    O_006B6AD8 *f120;
    O_006B6AD8 *f124;
    char _p1[0x1F4];
    s32 f31C;
} S_006B6AD8;

void func_L39_006B6AD8(S_006B6AD8 *arg0, s32 arg1) {
    arg0->f31C = ((arg1 >> 4) & 1) + (((arg1 >> 3) & 1) + (((arg1 >> 2) & 1) + (arg1 & 1)));
    arg0->f11C->f60->f1C(arg0->f11C, (arg1 & 1) ? 3 : 0, 0);
    arg0->f118->f60->f1C(arg0->f118, (arg1 & 4) ? 3 : 0, 0);
    arg0->f120->f60->f1C(arg0->f120, (arg1 & 8) ? 3 : 0, 0);
    arg0->f124->f60->f1C(arg0->f124, (arg1 & 0x10) ? 3 : 0, 0);
}
/* localdecomp:end func_L39_006B6AD8 */

/* localdecomp:start func_L39_006B6BC0 */
s32 func_L39_006B6BC0(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x318));
}
/* localdecomp:end func_L39_006B6BC0 */

LINKER_REMNANT("asm/levels", func_L39_006B6BC8);

/* localdecomp:start func_L39_006B6BD0 */
void func_0038CC88(void *, void *, s32);
extern u8 D_001FC6B0[];
extern u8 D_L39_0037C848[];

void func_L39_006B6BD0(void) {
    func_0038CC88(D_001FC6B0, D_L39_0037C848, 0xF80);
}
/* localdecomp:end func_L39_006B6BD0 */

/* localdecomp:start func_L39_006B6C00 */
void func_0038CC88(void *, void *, s32);
extern u8 D_001FC6B0[];
extern u8 D_L39_0037C848[];

void func_L39_006B6C00(void) {
    func_0038CC88(D_L39_0037C848, D_001FC6B0, 0xF80);
}
/* localdecomp:end func_L39_006B6C00 */

/* localdecomp:start func_L39_006B6C30 */
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");
extern u8 D_001DDA58_sda;

void func_L39_006B6C30(void) {
    D_00241440 = 7;
    D_001DDA58_sda = 1;
}
/* localdecomp:end func_L39_006B6C30 */

INCLUDE_ASM("asm/levels", func_L39_006B6C48);

INCLUDE_ASM("asm/levels", func_L39_006B6CC8);

LINKER_REMNANT("asm/levels", func_L39_006B7180);

/* localdecomp:start func_L39_006B7188 */
extern u8 D_L39_0047E680[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B7188(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E680;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B7188 */

LINKER_REMNANT("asm/levels", func_L39_006B71B0);

INCLUDE_ASM("asm/levels", func_L39_006B71B8);

/* localdecomp:start func_L39_006B72B0 */
extern s32 func_L39_0067F168();
extern void func_003C2880(s32);
extern void func_L39_0068ADC8(void *);
extern s32 D_L39_0037C7F0[];
extern s32 D_L39_0024D258;
__asm__(".extern D_L39_0024D258, 16");
extern s32 D_001DDA50_sda;
extern s32 D_001E1B48_sda;

void func_L39_006B72B0(void *arg0) {
    s32 i;
    func_L39_0067F168();
    for (i = 0; i < 10; i++) {
        if (D_L39_0037C7F0[i] != 0) {
            func_003C2880(D_L39_0037C7F0[i]);
        }
        D_L39_0037C7F0[i] = 0;
    }
    if (D_L39_0024D258 != 0) {
        func_003C2880(D_L39_0024D258);
    }
    D_001DDA50_sda = -1;
    D_001E1B48_sda = 0;
    func_L39_0068ADC8(arg0);
}
/* localdecomp:end func_L39_006B72B0 */

/* localdecomp:start func_L39_006B7340 */
typedef struct V_006B7340 {
    char _p0[0xF0];
    void (*fF0)(void *);
} V_006B7340;
typedef struct S_006B7340 {
    char _p0[0x60];
    V_006B7340 *f60;
    char _p1[0x259];
    u8 f2BD;
} S_006B7340;

extern void func_L01_00517918(s32);
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern void func_L39_00689A70(void);
extern void func_L39_006B6C48(void *);
extern void func_L39_006B8AC8(void *, s32);
extern s32 D_001A43E8 __attribute__((section(".data")));
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403F8, 16");
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");
extern s32 D_001DDA44_sda;
extern s32 D_001DDA64_sda;
extern u8 D_L39_0037C848[];

void func_L39_006B7340(S_006B7340 *arg0) {
    s32 v;
    arg0->f2BD = 0;
    v = D_001A43E8;
    if (v == 2) {
        if (D_L39_002403F8 == 1) {
            func_L01_00517918(0xA);
            func_L39_005BF798(0x12, 1, 3, 0, 0);
            D_00241440 = 7;
            arg0->f60->fF0(arg0);
            func_L39_00689A70();
        }
        D_001DDA64_sda = v;
    } else {
        func_L39_006B6C48(D_L39_0037C848 + D_001DDA44_sda * 0x1F0);
        func_L39_006B8AC8(arg0, 0);
        D_001DDA64_sda = 3;
    }
}
/* localdecomp:end func_L39_006B7340 */

/* localdecomp:start func_L39_006B7410 */
typedef struct V_006B7410 {
    char _p0[0xF0];
    void (*fF0)(void *);
} V_006B7410;
typedef struct S_006B7410 {
    char _p0[0x60];
    V_006B7410 *f60;
} S_006B7410;

extern void func_L01_00517918(s32);
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern void func_L39_00689A70(void);
extern s32 D_001A43E8 __attribute__((section(".data")));
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");
extern s32 D_001DDA64_sda;

void func_L39_006B7410(S_006B7410 *arg0) {
    if (D_001A43E8 == 2) {
        func_L01_00517918(0xA);
        func_L39_005BF798(0x12, 1, 3, 0, 0);
        D_00241440 = 7;
        arg0->f60->fF0(arg0);
        func_L39_00689A70();
    }
    D_001DDA64_sda = 2;
}
/* localdecomp:end func_L39_006B7410 */

/* localdecomp:start func_L39_006B7490 */
extern s32 D_1A43E0[];
extern s32 D_001DDA44_sda;
extern s32 D_001DDA48_sda;
extern s32 D_001DDA64_sda;
extern u8 D_L39_0037C848[];
void func_L39_006B6C00(void);
void func_L39_006B6C48(void *);
void func_L39_006B8AC8(void *, s32);

void func_L39_006B7490(void *a0) {
    D_001DDA64_sda = 3;
    if (D_1A43E0[2] == 2) {
        if (D_1A43E0[0x5B] == 0) {
            func_L39_006B6C00();
            if (D_001DDA48_sda != 0) {
                func_L39_006B6C48(D_L39_0037C848 + D_001DDA44_sda * 0x1F0);
                D_001DDA48_sda = 0;
            }
            func_L39_006B8AC8(a0, 0);
            *(u8 *)((u8 *)a0 + 0x2BC) = 1;
        }
    }
}
/* localdecomp:end func_L39_006B7490 */

INCLUDE_ASM("asm/levels", func_L39_006B7520);

LINKER_REMNANT("asm/levels", func_L39_006B7650);

INCLUDE_ASM("asm/levels", func_L39_006B7658);

LINKER_REMNANT("asm/levels", func_L39_006B7830);

INCLUDE_ASM("asm/levels", func_L39_006B7838);

/* localdecomp:start func_L39_006B78F8 */
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
extern s32 D_001DDA64_sda;
s32 func_L39_00688340(s32, s32, s32);
extern s32 func_00381FF0(s32);
s32 func_L39_006872E8(s32 *, s32, s32, s32, s32, f32);

s32 func_L39_006B78F8(void) {
    func_L39_00688340(0x17, 0, 0);
    if (func_L39_006872E8(D_L39_00247914, 0, func_00381FF0(0x1CAA), 3, 0, 0.0f) == 1) {
        D_001DDA64_sda = 7;
    }
    return 1;
}
/* localdecomp:end func_L39_006B78F8 */

INCLUDE_ASM("asm/levels", func_L39_006B7958);

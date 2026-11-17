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

/* localdecomp:start func_L39_006B6C48 */
extern u8 D_00249170 __attribute__((section(".data")));
void *func_0011D534(void *, s32, s32);
typedef struct { u8 a; u8 b; s32 c; } E_006B6C48;
typedef struct { u8 pad0[4]; E_006B6C48 e[3]; u8 f1C; u8 f1D; u8 pad1E[0x3D-0x1E]; u8 f3D; u8 pad3E[0x50-0x3E]; u8 f50; u8 pad51[0x171-0x51]; u8 f171; s16 f172; } S_006B6C48;
void func_L39_006B6C48(void *arg0) {
    S_006B6C48 *p = arg0;
    func_0011D534(p, 0, 0x1F0);
    p->f1D = D_00249170;
    p->f3D = D_00249170;
    p->f1C = 0;
    p->f50 = 0;
    p->e[0].a = 1; p->e[0].b = 1; p->e[0].c = 0x32;
    p->e[1].a = 1; p->e[1].b = 1; p->e[1].c = 0x32;
    p->e[2].a = 1; p->e[2].b = 1;
    p->f172 = 0x300;
    p->f171 = 1;
    p->e[2].c = 0x32;
}
/* localdecomp:end func_L39_006B6C48 */

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

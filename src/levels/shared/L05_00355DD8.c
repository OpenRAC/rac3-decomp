#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_00355DD8);

/* localdecomp:start func_L05_00355E58 */
typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } Vec4;
extern f32 func_L05_00355D00(u8 *, Vec4 *);
extern s32 func_L02_003E6F38(f32, f32, f32);
s32 func_L05_00355E58(u8 *a0, Vec4 *a1) {
    s32 r = 0;
    Vec4 v;
    v = *a1;
    if (func_L05_00355D00(a0, &v) < 3.0f) {
        r = func_L02_003E6F38(*(f32 *)(a0 + 24) + 1.0f, a1->f[2], 1.5f) != 0;
    }
    return r;
}
/* localdecomp:end func_L05_00355E58 */

INCLUDE_ASM("asm/levels", func_L05_00355EE8);

/* localdecomp:start func_L05_00355F60 */
extern s32 func_L05_0035AC08(u8 *);
extern s32 func_L05_0035ACD8(u8 *);

s32 func_L05_00355F60(u8 *obj) {
    s32 ret;
    if ((*(u8 **)(obj + 104))[95] != 0) {
        return func_L05_0035AC08(obj);
    }
    ret = 0;
    if (obj[188] == 0) {
        ret = func_L05_0035ACD8(obj) != 0;
    }
    return ret;
}
/* localdecomp:end func_L05_00355F60 */

/* localdecomp:start func_L05_00355FB0 */
extern s32 D_L05_001DFBD8;
extern void *D_L05_0021DAE0[];
extern void func_L01_00445BE0(s32, s32);
void func_L05_00355FB0(u8 *a0) {
    if (a0[188] == 0) {
        s32 i = a0[33];
        if (i < D_L05_001DFBD8 && D_L05_0021DAE0[i] != 0) {
            func_L01_00445BE0(i, 1);
            a0[188] = 0;
        }
    }
}
/* localdecomp:end func_L05_00355FB0 */

/* localdecomp:start func_L05_00356018 */
extern void *D_L05_0021DAE0[];
extern s32 D_L05_001DFBD8;
extern void func_L01_00445BE0(s32, s32);
void func_L05_00356018(u8 *a0) {
    if (a0[188] == 0) {
        u8 i = a0[33];
        if (i < D_L05_001DFBD8 && ((s32 *)&D_L05_0021DAE0)[i] != 0) {
            func_L01_00445BE0(i, 0);
        }
    }
}
/* localdecomp:end func_L05_00356018 */

INCLUDE_ASM("asm/levels", func_L05_00356070);

INCLUDE_ASM("asm/levels", func_L05_003560A8);

INCLUDE_ASM("asm/levels", func_L05_003560C8);

INCLUDE_ASM("asm/levels", func_L05_00358FF8);

INCLUDE_ASM("asm/levels", func_L05_00359878);

INCLUDE_ASM("asm/levels", func_L05_00359C78);

INCLUDE_ASM("asm/levels", func_L05_0035A2B0);

INCLUDE_ASM("asm/levels", func_L05_0035A380);

INCLUDE_ASM("asm/levels", func_L05_0035A558);

INCLUDE_ASM("asm/levels", func_L05_0035A568);

INCLUDE_ASM("asm/levels", func_L05_0035A880);

INCLUDE_ASM("asm/levels", func_L05_0035A980);

/* localdecomp:start func_L05_0035AA68 */
typedef struct { u8 pad[0x3EC]; void *x3EC; } V_359930;
typedef struct { u8 pad[0x68]; V_359930 *x68; } O_359930;
extern void func_003C3A10(void *, s32, s32, s32);
void func_L05_0035AA68(O_359930 *o, s32 a, s32 b, s32 c) {
    V_359930 *v = o->x68;
    func_003C3A10(o, a, b, c);
    func_003C3A10(v->x3EC, a, b, c);
}
/* localdecomp:end func_L05_0035AA68 */

/* localdecomp:start func_L05_0035AAC8 */
extern s32 func_L05_00355E58(u8 *a0, Vec4 *a1);
typedef struct { u8 pad[0x68]; u8 *x68; } O_359990;
extern s32 func_L05_00355BD8(O_359990 *, u8 *);
s32 func_L05_0035AAC8(O_359990 *o) {
    s32 r = 0;
    u8 *p = o->x68 + 0x220;
    if (((s32 (*)(O_359990 *, u8 *))func_L05_00355E58)(o, p) == 0) {
        r = func_L05_00355BD8(o, p) != 0;
    }
    return r;
}
/* localdecomp:end func_L05_0035AAC8 */

INCLUDE_ASM("asm/levels", func_L05_0035AB28);

INCLUDE_ASM("asm/levels", func_L05_0035AC08);

/* localdecomp:start func_L05_0035ACD8 */
extern u8 *D_L05_001EA6D8[];
extern void func_003C2F58(s32, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L05_0035ACD8(u8 *arg0)
{
    u8 *v;
    u8 *o;
    s32 buf[4];

    v = *(u8 **)(arg0 + 104);
    func_003C2F58(*(s32 *)(v + 1004), 0, buf);
    if (func_003D3CB0(buf, v + 544, 0, arg0, 0)) {
        o = D_L05_001EA6D8[0];
        if (o != 0 && *(s16 *)(o + 170) == 5669) {
            return o == *(u8 **)(v + 560);
        }
    }
    return 1;
}
/* localdecomp:end func_L05_0035ACD8 */

INCLUDE_ASM("asm/levels", func_L05_0035AD60);

INCLUDE_ASM("asm/levels", func_L05_0035AEC8);

INCLUDE_ASM("asm/levels", func_L05_0035AFB8);

INCLUDE_ASM("asm/levels", func_L05_0035B1A0);

INCLUDE_ASM("asm/levels", func_L05_0035B308);

INCLUDE_ASM("asm/levels", func_L05_0035B3F0);

INCLUDE_ASM("asm/levels", func_L05_0035CE98);

INCLUDE_ASM("asm/levels", func_L05_0035D078);

/* localdecomp:start func_L05_0035D300 */
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
extern void func_L01_004443E8(u8 *, s32, s32);
extern void func_003C2880(u8 *);

void func_L05_0035D300(u8 *arg0)
{
    u8 *v;
    s32 i;
    u8 *e;

    v = *(u8 **)(arg0 + 104);
    i = *(s32 *)(v + 748);
    if (i != -1) {
        e = D_001A30B0 + (i << 7);
        if (*(u8 **)(e + 220) == arg0 && e[208] != 0) {
            func_003A4F28(i);
        }
    }
    *(s32 *)(v + 748) = -1;
    func_L01_004443E8(arg0, 0, 3);
    func_003C2880(arg0);
}
/* localdecomp:end func_L05_0035D300 */

INCLUDE_ASM("asm/levels", func_L05_0035D388);

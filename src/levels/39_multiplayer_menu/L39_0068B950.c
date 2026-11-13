#include "common.h"

typedef struct { char pad[0xF0]; void (*fn)(void *); } VT;
typedef struct { char pad[0x60]; VT *vt; } Obj;

/* declared by functions of L39_0068B768.c, which this file was cut from */
extern s32 D_001DC3F4_sda;

/* localdecomp:start func_L39_0068B950 */
extern void func_L01_00418C80(void);
extern void func_L01_00415C98(int, int);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00415D40();
extern void func_L01_00517918(int);
extern void func_L39_005BF798(int, int, int, int, int);
extern void func_L39_00689A70(void);
extern s32 D_001DC3F4_sda;
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");

void func_L39_0068B950(Obj *a) {
    s32 s1;
    s32 s2;

    func_L01_00418C80();
    func_L01_00415C98(0x20, 0x10);
    s1 = func_00381FF0(0x8E3);
    s2 = func_00381FF0(0x8DF);
    func_L01_00415D40(s1, s2, func_00381FF0(0x11E9), 0);
    func_L01_00517918(10);
    func_L39_005BF798(4, 1, 9, 0, 0);
    D_00241440 = 2;
    a->vt->fn(a);
    func_L39_00689A70();
    D_001DC3F4_sda = 5;
}
/* localdecomp:end func_L39_0068B950 */

/* localdecomp:start func_L39_0068BA10 */
extern int func_L39_0059A1F0(void);
extern int D_001DC3F4_sda;

void func_L39_0068BA10(void)
{
    switch (func_L39_0059A1F0()) {
    case 2:
        D_001DC3F4_sda = 6;
        break;
    default:
        D_001DC3F4_sda = 7;
    }
}
/* localdecomp:end func_L39_0068BA10 */

/* localdecomp:start func_L39_0068BA40 */
extern s32 D_001DC3F4_sda;
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");
extern void func_L39_0068B460(void);
extern void func_L01_004792D8(void (*)(void));
extern void func_L39_005BF798(int, int, int, int, int);
extern void func_L39_00689A70(void);

void func_L39_0068BA40(Obj *a)
{
    VT *v;
    func_L01_004792D8(func_L39_0068B460);
    func_L39_005BF798(0x12, 1, 1, 0, 0);
    v = a->vt;
    D_00241440 = 2;
    v->fn(a);
    func_L39_00689A70();
    D_001DC3F4_sda = 3;
}
/* localdecomp:end func_L39_0068BA40 */

/* localdecomp:start func_L39_0068BAB0 */
void func_L39_0067CE08();
extern s32 D_001DC3F4_sda;

s32 func_L39_0068BAB0(void) {
    func_L39_0067CE08();
    D_001DC3F4_sda = 3;
    return 1;
}
/* localdecomp:end func_L39_0068BAB0 */

INCLUDE_ASM("asm/levels", func_L39_0068BAD8);

/* localdecomp:start func_L39_0068C0E0 */
typedef struct { char pad[0x284]; s32 f284; } W_0068C0E0;

extern u8 D_00247A34;
__asm__(".extern D_00247A34, 16");
extern f32 D_00247A30;
__asm__(".extern D_00247A30, 16");
extern W_0068C0E0 *D_001DC204_sda;

extern void func_L39_0068B768(Obj *);
extern void func_L39_0068B828(Obj *);
extern s32 func_L39_0068BAD8(Obj *, s32 *);
extern void func_L39_0068B8A0(void);
extern void func_L39_0068BA10(void);
extern s32 func_L39_0068BAB0(void);

s32 func_L39_0068C0E0(Obj *a, s32 state) {
    s32 ret;

    if (D_00247A34) {
        if (D_00247A30 <= 0.0f) {
            D_001DC204_sda->f284 = 0x18;
        }
        return 1;
    }
    ret = 0;
    switch (D_001DC3F4_sda) {
    case 0:
        func_L39_0068B768(a);
        break;
    case 1:
        func_L39_0068B828(a);
        break;
    case 2:
        ((void (*)(Obj *))func_L39_0068B8A0)(a);
        break;
    case 3:
        ret = func_L39_0068BAD8(a, &state);
        break;
    case 4:
        func_L39_0068B950(a);
        break;
    case 5:
        ((void (*)(Obj *))func_L39_0068BA10)(a);
        break;
    case 6:
        func_L39_0068BA40(a);
        break;
    case 7:
        ret = ((s32 (*)(Obj *))func_L39_0068BAB0)(a);
        break;
    }
    return ret;
}
/* localdecomp:end func_L39_0068C0E0 */

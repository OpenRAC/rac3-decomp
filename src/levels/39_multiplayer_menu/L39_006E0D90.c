#include "common.h"

/* declared by functions of L39_006DC228.c, which this file was cut from */
s32 func_001205B0(s32, s32);
s32 func_L39_006E1478(s32, s32);

/* localdecomp:start func_L39_006E0D90 */
__asm__(".extern D_L39_0024A0C0, 16");
extern void *D_L39_0024A0C0;
extern f32 D_L39_001A6A44[];

f32 func_L39_006E0D90(f32 arg0, f32 arg1, f32 arg2) {
    f32 (*temp_v0)(f32) = (f32 (*)(f32))D_L39_0024A0C0;
    f32 temp_f0;

    temp_f0 = temp_v0(arg2);
    return (-temp_f0) * (arg0 - arg1) / D_L39_001A6A44[0];
}
/* localdecomp:end func_L39_006E0D90 */

/* localdecomp:start func_L39_006E0DE8 */
__asm__(".extern D_L39_0024A0C4, 16");
extern void *D_L39_0024A0C4;
double func_001321C8(f32);
double func_00136C98(double, double);
double func_00131680(double, double);
double func_001319E8(double, double);
void func_00131ED8(double);

void func_L39_006E0DE8(void) {
    double v = func_001321C8(((f32 (*)(void))D_L39_0024A0C4)());
    v = func_00136C98(10.0, v);
    v = func_00131680(v, 1.0);
    v = func_001319E8(1.0, v);
    func_00131ED8(v);
}
/* localdecomp:end func_L39_006E0DE8 */

/* localdecomp:start func_L39_006E0E58 */
__asm__(".extern D_L39_0024A0C0, 16");
extern void *D_L39_0024A0C0;
__asm__(".extern D_L39_0024A0C8, 16");
extern void *D_L39_0024A0C8;
__asm__(".extern D_L39_0024A0BC, 16");
extern void *D_L39_0024A0BC;

f32 func_L39_006E0E58(f32 arg0, f32 arg1, f32 arg2) {
    f32 a = ((f32 (*)(f32))D_L39_0024A0C0)(arg2);
    f32 b = ((f32 (*)(f32, f32, f32))D_L39_0024A0C8)(arg0, arg1, arg2);
    f32 c = ((f32 (*)(void))D_L39_0024A0BC)();
    return 1.0f / (c * (a * a) * b * (1.0f - b));
}
/* localdecomp:end func_L39_006E0E58 */

/* localdecomp:start func_L39_006E0EF0 */
__asm__(".extern D_L39_0024A0CC, 16");
extern void *D_L39_0024A0CC;
__asm__(".extern D_L39_0024A0C0, 16");
extern void *D_L39_0024A0C0;
extern void *D_001DE9A8_sda;

f32 func_L39_006E0EF0(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 a = ((f32 (*)(f32, f32, f32))D_L39_0024A0CC)(arg0, arg1, arg3);
    f32 b = ((f32 (*)(f32))D_L39_0024A0C0)(arg3);
    f32 c = ((f32 (*)(void))D_001DE9A8_sda)();
    return c / (1.0f / (arg2 * arg2) + 1.0f / a) * b;
}
/* localdecomp:end func_L39_006E0EF0 */

/* localdecomp:start func_L39_006E0F78 */
__asm__(".extern D_L39_0024A0D0, 16");
extern void *D_L39_0024A0D0;
__asm__(".extern D_L39_0024A0C8, 16");
extern void *D_L39_0024A0C8;

f32 func_L39_006E0F78(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 a = ((f32 (*)(f32, f32, f32, f32))D_L39_0024A0D0)(arg0, arg1, arg2, arg3);
    f32 b = ((f32 (*)(f32, f32, f32))D_L39_0024A0C8)(arg0, arg1, arg3);
    return a * (arg4 - b);
}
/* localdecomp:end func_L39_006E0F78 */

INCLUDE_ASM("asm/levels", func_L39_006E0FF8);

/* localdecomp:start func_L39_006E1040 */
f32 func_L39_006E0FF8(s32, f32 *);
double func_001321C8(f32);
double func_00136CB0(double);
void func_00131ED8(double);

void func_L39_006E1040(s32 arg0, f32 *arg1) {
    f32 mean = func_L39_006E0FF8(arg0, arg1);
    f32 sum = 0.0f;
    s32 i;
    for (i = 0; i < arg0; i++) {
        f32 d = arg1[i] - mean;
        sum += d * d;
    }
    func_00131ED8(func_00136CB0(func_001321C8(sum / arg0)));
}
/* localdecomp:end func_L39_006E1040 */

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

/* localdecomp:start func_L39_006E1478 */
typedef struct { s32 key; f32 *ptr; } S_006E1478;
extern S_006E1478 D_L39_004B2258[];
s32 func_00118F70(s32);
void func_00131ED8(double);
s32 func_001205B0(s32, s32);

s32 func_L39_006E1478(s32 arg0, s32 arg1) {
    s32 ret = 0;
    s32 i;
    f32 f;

    if (arg0 != 0 && arg1 != 0) {
        i = 0;
        f = ((f32 (*)(s32))func_00131ED8)(func_00118F70(arg1));
        while (D_L39_004B2258[i].key != 0) {
            if (func_001205B0(arg0, D_L39_004B2258[i].key) == 0) {
                ret = 1;
                *D_L39_004B2258[i].ptr = f;
                break;
            }
            i++;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006E1478 */

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

/* localdecomp:start func_L39_006E1558 */
s32 func_L39_006E1538(u32, u32);

typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
    s32 fC;
    u8 *f10;
    s32 f14;
    s32 f18;
    u8 *f1C;
} S_006E1558;

s32 func_L39_006E1558(s32 arg0, s32 size, s32 arg2, s32 arg3) {
    S_006E1558 *s = (S_006E1558 *)arg0;
    u8 *cur;
    u8 *prev;
    s32 off;
    u32 sz;
    u32 arg1;

    s->f4 = arg2;
    s->fC = func_L39_006E1538(arg2, 4);
    s->f8 = func_L39_006E1538(s->fC + 4, arg3);
    s->f18 = 0;
    off = func_L39_006E1538(arg0 + 0x20, arg3) - arg0;
    cur = s->f10 = (u8 *)arg0 + off;
    arg1 = size - off;
    prev = 0;
    sz = s->f8;
    while (arg1 >= sz) {
        u8 *next = cur + sz;
        *(u8 **)(cur + s->fC) = next;
        prev = cur;
        cur = next;
        arg1 -= s->f8;
        s->f18++;
        sz = s->f8;
    }
    s->f14 = s->f18;
    if (prev != 0) {
        *(u8 **)(prev + s->fC) = 0;
    }
    s->f1C = s->f10;
    return arg0;
}
/* localdecomp:end func_L39_006E1558 */

/* localdecomp:start func_L39_006E1648 */
s32 func_L01_00521C90(s32, s32);
s32 func_L39_006E1558(s32, s32, s32, s32);

void func_L39_006E1648(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_L39_006E1558(func_L01_00521C90(0x20, arg0), arg1, arg2, arg3);
}
/* localdecomp:end func_L39_006E1648 */

/* localdecomp:start func_L39_006E16A0 */
s32 func_L39_006E16A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s0;
    s32 temp_v0;

    temp_v0 = func_L39_006E1538(arg2, 4);
    temp_s0 = func_L39_006E1538(temp_v0 + 4, arg3);
    temp_v0 = func_L39_006E1538(arg0 + 0x20, arg3);
    return temp_v0 + temp_s0 * arg1 - arg0;
}
/* localdecomp:end func_L39_006E16A0 */

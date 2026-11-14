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

/* localdecomp:start func_L39_006E1108 */
typedef struct {
    u8 x[0x10];
} S_006E1108_Half;
typedef struct {
    S_006E1108_Half h0;
    S_006E1108_Half h1;
} S_006E1108_Hdr;
typedef struct {
    u8 b0;
    u8 b1;
} S_006E1108_Pair;
typedef struct {
    f32 a[8];
    f32 b[8];
    f32 c[8];
    S_006E1108_Hdr hdr;
    char names[8][15];
    u8 f0F8[8];
    u8 f100[8];
    S_006E1108_Pair f108[8];
    u8 f118[8];
    u8 f120[8];
    s16 f128[8];
    u8 f138[8];
    u8 f140[8];
    u8 f148;
    u8 f149;
    u8 f14A[8];
    S_006E1108_Pair f152[8][9];
    u8 f1E2;
    u8 f1E3;
    u8 f1E4;
    u8 f1E5;
    char pad[2];
} S_006E1108;
typedef struct {
    S_006E1108_Hdr hdr;
    char pad[0x30 - 0x20];
    u8 f30;
} S_006E1108_Src;
typedef struct {
    s32 ids[8];
    f32 a[8];
    f32 b[8];
    f32 c[8];
    char pad[0x8C - 0x80];
    s32 count;
    char pad2[0xA4 - 0x90];
} S_006E1108_Ent;
typedef struct { u8 v; u8 pad[3]; } S_006E1108_B4;
typedef struct { u8 f0; u8 f1; u8 f2; u8 f3; } S_006E1108_Q4;
typedef struct {
    u8 names[8][0x20];
    S_006E1108_B4 f100[8];
    S_006E1108_B4 f120[8];
    S_006E1108_Q4 f140[8];
    u8 f160[8];
    u8 f168[8];
    u8 f170[8];
    u8 f178[8];
    f32 f180[8];
    char pad1A0[8];
    u8 f1A8;
    char pad1A9[3];
    u8 f1AC;
    char pad1AD[0x1B8 - 0x1AD];
    s16 f1B8[8];
    u8 f1C8[8][36];
    char pad2E8[0x2E8 - 0x1C8 - 8 * 36];
    S_006E1108_Ent ent[8];
    char pad808[4];
    u8 f80C;
    char pad80D[3];
    u8 f810;
} S_006E1108_D;
extern S_006E1108_D D_001FD7E8;
extern S_006E1108_Src D_001A5D58;
__asm__(".extern D_L39_00240400, 16");
extern u8 D_L39_00240400;
extern char D_L39_0024A0E8[];
extern u8 D_001FD9A0[];
extern u8 D_001FD9B0[];
extern char D_001A5EB2[];
void func_0011D534(void *, s32, s32);
s32 func_00120048(char *, char *, ...);
s32 func_00120884(void *);
void func_0014C280(char *, char *);
void func_0014AB98(s32, char *, s32, s32, s32, void *);
s32 func_L39_006E10D0(u8 *arg0);

void func_L39_006E1108(void) {
    S_006E1108 s;
    char buf[0x10];
    s32 i;
    s32 k;
    s32 h;

    i = 0;
    func_0011D534(&s, 0, sizeof(s));
    s.hdr.h0 = D_001A5D58.hdr.h0;
    s.hdr.h1 = D_001A5D58.hdr.h1;
    s.f148 = D_001FD7E8.f1A8;
    s.f149 = D_001FD7E8.f1AC;
    s.f1E2 = D_001FD7E8.f80C;
    s.f1E3 = D_001FD7E8.f810;
    s.f1E4 = D_L39_00240400;
    s.f1E5 = D_001A5D58.f30;
    for (; i < 8; i++) {
        for (k = 0; k < D_001FD7E8.ent[i].count; k++) {
            s32 id = D_001FD7E8.ent[i].ids[k];
            s.a[id] = D_001FD7E8.ent[i].a[k];
            s.b[id] = D_001FD7E8.ent[i].b[k];
            s.c[id] = D_001FD7E8.ent[i].c[k];
        }
        h = func_L39_006E10D0(D_001FD7E8.names[i]);
        func_00120048(s.names[i], D_L39_0024A0E8, h);
        s.f0F8[i] = D_001FD7E8.f100[i].v;
        s.f100[i] = D_001FD7E8.f120[i].v;
        s.f108[i].b0 = D_001FD7E8.f140[i].f0;
        s.f108[i].b1 = D_001FD7E8.f140[i].f2;
        s.f118[i] = D_001FD7E8.f160[i];
        s.f120[i] = D_001FD7E8.f168[i];
        s.f128[i] = D_001FD7E8.f180[i];
        s.f138[i] = D_001FD7E8.f170[i];
        s.f140[i] = D_001FD7E8.f178[i];
        s.f14A[i] = D_001FD7E8.f1B8[i];
        for (k = 0; k < 9; k++) {
            s.f152[i][k].b0 = D_001FD7E8.f1C8[i][k * 4];
            s.f152[i][k].b1 = D_001FD7E8.f1C8[i][k * 4 + 2];
        }
    }
    if (func_00120884(D_001A5EB2) != 0) {
        func_0014C280(buf, D_001A5EB2);
        func_0014AB98(0, buf, 2, 0, sizeof(s), &s);
    }
}
/* localdecomp:end func_L39_006E1108 */

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

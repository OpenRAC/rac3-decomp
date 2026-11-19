#include "common.h"

/* declared by functions of L39_0068A8F8.c, which this file was cut from */
extern u8 D_L39_003D2880[];

/* localdecomp:start func_L39_0068AAB8 */
typedef struct S_0068AAB8_O S_0068AAB8_O;
typedef struct {
    char _p0[0xC];
    void (*fC)(S_0068AAB8_O *);
    char _p10[0xC];
    void (*f1C)(S_0068AAB8_O *, s32, s32);
} S_0068AAB8_OV;
struct S_0068AAB8_O {
    char _p0[0x60];
    S_0068AAB8_OV *f60;
};
typedef struct S_0068AAB8_A S_0068AAB8_A;
typedef struct {
    char _p0[0xF4];
    void (*fF4)(S_0068AAB8_A *);
} S_0068AAB8_AV;
struct S_0068AAB8_A {
    char _p0[0x50];
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    S_0068AAB8_AV *f60;
    char _p64[0x10C - 0x64];
    s32 f10C;
    S_0068AAB8_O *f110[(0x290 - 0x110) / 4];
    s32 f290;
    char _p294[0x8];
    u8 f29C;
};

extern s32 D_L39_0024736C;
extern s32 D_001DBC5C_sda;
extern u8 D_001DC324_sda;
__asm__(".extern D_001DC324_sda, 1");
__asm__(".extern D_001DBC5C_sda, 4");
s32 func_L39_0067F1B0(void);
extern s32 func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_L01_00517190(s32, s32);
void func_L39_00689610(void);
s32 func_L39_0068B3C0();

void func_L39_0068AAB8(S_0068AAB8_A *arg0) {
    s32 *p;
    s32 r;
    s32 i;

    if (arg0->f29C) {
        r = func_L39_0067F1B0();
        func_003E9138(r, 0x39000000, arg0->f50 + arg0->f58 * 0.5f, arg0->f54 + arg0->f5C * 0.5f, arg0->f58, arg0->f5C, 0);
        func_003E8630(D_L39_0024736C, r);
        arg0->f60->fF4(arg0);
    }
    for (i = 0; i < arg0->f10C; i++) {
        arg0->f110[i]->f60->fC(arg0->f110[i]);
    }
    if (!arg0->f29C) {
        s32 id = func_L39_0067F1B0();
        p = (s32 *)D_L39_003D2880;
        p[152] = id;
        func_003E9138(p[152], 0x60000000, 0.5f, 0.5f, 0.12f, 0.1475f, 0);
        func_003E8630(D_L39_0024736C, p[152]);
        p[153] = func_L39_0067F1B0();
        func_003E9138(p[153], 0x331465B7, 0.5f, 0.5f, 0.12f, 0.1475f, 0);
        func_003E8630(D_L39_0024736C, p[153]);
        p[154] = func_L39_0067F1B0();
        func_003E9138(p[154], 0, 0.0f, 0.0f, 0.0f, 0.0f, 0);
        func_003E8630(D_L39_0024736C, p[154]);
        p[155] = func_L39_0067F1B0();
        func_003E9270(p[155], 0x332299DE, 0.5f, 0.5f, 0.12f, 0.1475f, 0.004f, 0.005f);
        func_003E8630(D_L39_0024736C, p[155]);
        p[156] = func_L39_0067F1B0();
        func_003E9138(p[156], 0, 0.0f, 0.0f, 0.0f, 0.0f, 0);
        func_003E8630(D_L39_0024736C, p[156]);
        p[157] = func_L39_0067F1B0();
        func_003E9138(p[157], 0x80808080, 0.5f, 0.5f, 0.1f, 0.125f, 0);
        func_L01_00517190(p[157], 0xED5C);
        func_003E8630(D_001DBC5C_sda, p[157]);
        func_L39_00689610();
    }
    func_L39_0068B3C0(arg0);
    if (arg0->f290 >= 0) {
        S_0068AAB8_O *o = arg0->f110[arg0->f290];
        o->f60->f1C(o, 4, 0);
    }
    D_001DC324_sda = 0;
}
/* localdecomp:end func_L39_0068AAB8 */

/* localdecomp:start func_L39_0068ADC8 */
typedef struct S_0068ADC8_O S_0068ADC8_O;
typedef struct {
    char _p0[0x10];
    void (*f10)(S_0068ADC8_O *);
    char _p14[0x8];
    void (*f1C)(S_0068ADC8_O *, s32, s32);
} S_0068ADC8_V;
struct S_0068ADC8_O {
    char _p0[0x4];
    s32 f4;
    char _p8[0x58];
    S_0068ADC8_V *f60;
};
typedef struct {
    char _p0[0x10C];
    s32 f10C;
    S_0068ADC8_O *f110[(0x290 - 0x110) / 4];
    s32 f290;
    char _p294[0x8];
    u8 f29C;
} S_0068ADC8_A;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_0068ADC8_Q;

extern S_0068ADC8_Q D_L39_0024CD50;
s32 func_L39_0068B3C0();
extern s32 func_L05_0050D800_0068ADC8(void);
extern void func_L01_004D2110(void);
extern void func_L39_00689610(void);
extern s16 func_L39_005C2B10(s32);
extern void *func_003E6C08();
extern void func_003E69F8(void *);

void func_L39_0068ADC8(S_0068ADC8_A *a) {
    S_0068ADC8_O *o;
    S_0068ADC8_Q *q;
    void *base;
    s32 *p;
    s32 s;
    s32 i;
    s32 j;

    if (a->f290 >= 0) {
        o = a->f110[a->f290];
        if (o->f4 >= 4) {
            o->f60->f1C(o, 3, 0);
        }
    }
    func_L39_0068B3C0(a);
    for (i = 0; i < a->f10C; i++) {
        a->f110[i]->f60->f10(a->f110[i]);
    }
    s = func_L05_0050D800_0068ADC8();
    ((void (*)(s32))func_L01_004D2110)(0);
    func_L39_00689610();
    ((void (*)(s32))func_L01_004D2110)(s);
    if (!a->f29C) {
        p = (s32 *)D_L39_003D2880;
        p += 152;
        for (j = 5; j >= 0; j--) {
            *p++ = 0;
        }
    }
    func_L39_005C2B10(1);
    q = &D_L39_0024CD50;
    if (q->f4 != 0) {
        base = q;
    } else {
        base = func_003E6C08(q);
    }
    func_003E69F8(base);
}
/* localdecomp:end func_L39_0068ADC8 */

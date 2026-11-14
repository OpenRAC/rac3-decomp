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

INCLUDE_ASM("asm/levels", func_L39_0068ADC8);

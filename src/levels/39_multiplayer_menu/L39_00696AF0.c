#include "common.h"

/* declared by functions of L39_00695FC0.c, which this file was cut from */
typedef struct S_00695FC0_T { s32 f0; u8 pad[0x30]; u8 f34; } S_00695FC0_T;
typedef struct S_00695FC0_G { u8 pad[0x38]; S_00695FC0_T *f38; } S_00695FC0_G;
extern S_00695FC0_G *D_L39_0024D760;

/* localdecomp:start func_L39_00696AF0 */
__asm__(".extern D_L39_00248020, 16");
typedef struct S_00696AF0_W S_00696AF0_W;
typedef struct S_00696AF0_V {
    u8 pad0[0x1C];
    void (*f1C)(S_00696AF0_W *, s32, s32);
    u8 pad20[4];
    void (*f24)(S_00696AF0_W *, char *);
    u8 pad28[0x18];
    void (*f40)(S_00696AF0_W *, s32);
    void (*f44)(S_00696AF0_W *, s32, f32, f32);
    u8 pad48[4];
    void (*f4C)(S_00696AF0_W *, s32, s32);
    u8 pad50[4];
    void (*f54)(S_00696AF0_W *, s32);
    u8 pad58[4];
    void (*f5C)(S_00696AF0_W *, f32);
    u8 pad60[0xC];
    s32 (*f6C)(S_00696AF0_W *, s32, u8 **);
    u8 pad70[0x14];
    void (*f84)(S_00696AF0_W *, s32);
    u8 pad88[8];
    void (*f90)(S_00696AF0_W *, f32);
    u8 pad94[0x20];
    void (*fB4)(S_00696AF0_W *);
    u8 padB8[0x2C];
    void (*fE4)(S_00696AF0_W *, f32);
} S_00696AF0_V;
struct S_00696AF0_W {
    u8 pad[0x60];
    S_00696AF0_V *f60;
};
typedef struct S_00696AF0_O {
    u8 pad0[0x110];
    S_00696AF0_W *items[17];
    u8 pad154[0x2A8 - 0x154];
    u8 f2A8;
    u8 pad2A9[0x3B4 - 0x2A9];
    s32 f3B4;
    s32 f3B8;
    u8 pad3BC[0x4BC - 0x3BC];
    s32 f4BC;
    s32 f4C0;
} S_00696AF0_O;
extern u8 D_L39_00248020[];
extern char D_L39_00248028[];
extern u8 *func_00381FF0(s32);
extern s32 func_00120048(char *, char *, ...);
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern void func_L39_00689BD8(void *, u8 *);
extern void func_L39_00689D28(void *, u8 *);
extern void func_L39_00689DB8(void *, u8 *);
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, s32);
extern void func_L39_0068A7B8(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_0068B2F8(void *, s32, s32);

void func_L39_00696AF0(S_00696AF0_O *o)
{
    s32 i;
    s32 j;

    func_L39_0067F100(0x2A0000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(o, (u8 *)D_L39_0024D760->f38 + 4);
    func_L39_00689D28(o, func_00381FF0(0x124));
    func_L39_00689DB8(o, func_00381FF0(0xCD5));
    func_L39_0068A6D0(o, 0, 0.274f, 0.5f, 0.365f, 0.72f, 0x332299DE);
    func_L39_0068A6D0(o, 1, 0.688f, 0.314f, 0.445f, 0.348f, 0x332299DE);
    func_L39_0068A6D0(o, 2, 0.688f, 0.679f, 0.445f, 0.362f, 0x332299DE);
    func_L39_0068A4A8(o, 0, 1, 0.274f, 0.24499997f, 0.048f, 0.32500002f, 0x331465B7);
    func_L39_0068A4A8(o, 1, 6, 0.688f, 0.19685715f, 0.04685715f, 0.405f, 0x331465B7);
    func_L39_0068A4A8(o, 2, 6, 0.688f, 0.55685717f, 0.048857093f, 0.405f, 0x331465B7);
    func_L39_0068A7B8(o, 0, 0.274f, 0.19999999f, 0.6400001f, 0.34500003f, 0x332299DE);
    func_L39_0068AAB8(o);
    {
        u8 *e[2] = { D_L39_00248020, func_00381FF0(0x100E) };
        o->items[1]->f60->f6C(o->items[1], 2, e);
    }
    o->items[1]->f60->f1C(o->items[1], 2, 0);
    o->items[1]->f60->f84(o->items[1], 1);
    o->items[1]->f60->f40(o->items[1], 1);
    o->items[1]->f60->f90(o->items[1], 0.049999982f);
    o->items[1]->f60->fE4(o->items[1], 0.32500002f);
    {
    char buf[0x50];
    char *s = buf;
    for (i = 9; i < 17; i++) {
        o->items[i]->f60->f1C(o->items[i], 3, 0);
        o->items[i]->f60->f4C(o->items[i], 0x40, 1);
        o->items[i]->f60->f44(o->items[i], 1, 0.405f, 0.0f);
    }
    o->items[12]->f60->f1C(o->items[12], 2, 0);
    o->items[13]->f60->f1C(o->items[13], 0, 0);
    o->items[14]->f60->f1C(o->items[14], 2, 0);
    o->items[8]->f60->fB4(o->items[8]);
    for (j = 3; j < 9; j++) {
        o->items[j]->f60->f1C(o->items[j], 1, 0);
        o->items[j]->f60->f40(o->items[j], 1);
        o->items[j]->f60->f54(o->items[j], 1);
        o->items[j]->f60->f5C(o->items[j], 0.405f);
        o->items[j]->f60->f4C(o->items[j], 0x40, 1);
    }
    func_00120048(s, D_L39_00248028, func_00381FF0(0x1334), func_00381FF0(0x1335));
    o->items[5]->f60->f24(o->items[5], s);
    func_00120048(s, D_L39_00248028, func_00381FF0(0x1336), func_00381FF0(0x1337));
    o->items[6]->f60->f24(o->items[6], s);
    o->items[2]->f60->f4C(o->items[2], 0x40, 1);
    o->items[0]->f60->f4C(o->items[0], 0x40, 1);
    o->items[2]->f60->f1C(o->items[2], 1, 0);
    o->items[0]->f60->f1C(o->items[0], 1, 0);
    o->items[2]->f60->f44(o->items[2], 1, 0.405f, 0.0f);
    o->items[0]->f60->f44(o->items[0], 1, 0.32500002f, 0.0f);
    func_L39_0068B2F8(o, 9, 0);
    o->f3B4 = 9;
    o->f4BC = -1;
    o->f4C0 = -1;
    o->f3B8 = 0;
    o->items[8]->f60->fE4(o->items[8], 0.25f);
    o->f2A8 = 1;
    }
}
/* localdecomp:end func_L39_00696AF0 */

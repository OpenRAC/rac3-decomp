#include "common.h"

/* localdecomp:start func_L39_00690890 */
typedef struct S_00690890_V S_00690890_V;
typedef struct S_00690890_O { u8 pad[0x60]; S_00690890_V *vt; } S_00690890_O;
struct S_00690890_V {
    u8 p0[0x1C]; void (*f1C)(S_00690890_O *, s32, s32);
    u8 p20[0x18]; void (*f38)(S_00690890_O *, f32, f32);
    u8 p3C[4]; void (*f40)(S_00690890_O *, s32);
    u8 p44[8]; void (*f4C)(S_00690890_O *, s32, s32);
    u8 p50[0x1C]; void (*f6C)(S_00690890_O *, s32, void *);
    u8 p70[0x14]; void (*f84)(S_00690890_O *, s32);
    u8 p88[8]; void (*f90)(S_00690890_O *, f32);
    void (*f94)(S_00690890_O *, f32);
    u8 p98[0x1C]; void (*fB4)(S_00690890_O *);
    u8 pB8[0x2C]; void (*fE4)(S_00690890_O *, f32);
};
typedef struct S_00690890_E { s32 a; u8 pad[0x24]; } S_00690890_E;

extern u8 D_L39_00247D38[];
extern f32 D_L39_00247D44;
extern f32 D_L39_00247D48;
extern f32 D_L39_00247D4C;
extern f32 D_L39_00247D54;
extern f32 D_L39_00247D58;
extern f32 D_L39_00247D5C;
__asm__(".extern D_001DC630_sda, 4");
__asm__(".extern D_001DC640_sda, 4");
extern f32 D_001DC630_sda, D_001DC640_sda;
extern S_00690890_E D_001FD630[];
extern s32 func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern s32 func_00381FF0(s32);
extern void func_L39_00689BD8(void *, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689DB8(void *, s32);
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A7B8(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_006918A8(void *);

void func_L39_00690890(u8 *arg0) {
    void *local[1];
    S_00690890_O **objs;
    S_00690890_O *o;
    f32 one;
    s32 i;
    s32 any;
    s32 j;

    local[0] = D_L39_00247D38;
    func_L39_0067F100(0x230000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(arg0, func_00381FF0(0xFC0));
    func_L39_00689D28(arg0, func_00381FF0(0x124));
    func_L39_00689DB8(arg0, func_00381FF0(0xCD5));
    func_L39_0068A6D0(arg0, 0, 0.273f, 0.5f, 0.367f, 0.72f, 0x332299DE);
    func_L39_0068A7B8(arg0, 0, D_001DC640_sda, D_L39_00247D54, D_L39_00247D58, D_L39_00247D5C, 0x331465B7);
    func_L39_0068A4A8(arg0, 0, 10, 0.273f, 0.2747f, 0.056f, 0.35f, 0x332299DE);
    func_L39_0068A2D0(arg0, 0, 3, 3, 2.0f, 2.0f);
    func_L39_0068A6D0(arg0, 1, 0.687f, 0.773f, 0.45f, 0.172f, 0x332299DE);
    func_L39_0068A4A8(arg0, 1, 2, D_001DC630_sda, D_L39_00247D44, D_L39_00247D48, D_L39_00247D4C, 0x332299DE);
    func_L39_0068A6D0(arg0, 2, 0.687f, 0.411f, 0.45f, 0.539f, 0x332299DE);
    func_L39_0068A4A8(arg0, 2, 10, 0.687f, 0.203f, 0.047f, 0.4f, 0x332299DE);
    func_L39_0068AAB8(arg0);

    o = *(S_00690890_O **)(arg0 + 0x120); o->vt->f1C(o, 1, 0);
    o = *(S_00690890_O **)(arg0 + 0x110); o->vt->f6C(o, 1, local);
    o = *(S_00690890_O **)(arg0 + 0x110); o->vt->f1C(o, 2, 0);
    o = *(S_00690890_O **)(arg0 + 0x110); o->vt->f84(o, 1);
    o = *(S_00690890_O **)(arg0 + 0x110); o->vt->f90(o, 0.056f);
    o = *(S_00690890_O **)(arg0 + 0x110); o->vt->f94(o, 0.8f);
    o = *(S_00690890_O **)(arg0 + 0x110); o->vt->fE4(o, 0.34f);
    o = *(S_00690890_O **)(arg0 + 0x124); o->vt->f1C(o, 1, 0);

    objs = (S_00690890_O **)(arg0 + 0x124);
    i = 10;
    one = 1.0f;
    do {
        i--;
        o = *objs; o->vt->f38(o, one, one);
        o = *objs; o->vt->f40(o, 1);
        o = *objs; o->vt->f4C(o, 0x40, 1);
        o = *objs; o->vt->fB4(o);
        objs++;
    } while (i >= 0);

    o = *(S_00690890_O **)(arg0 + 0x150); o->vt->f1C(o, 0, 0);
    o = *(S_00690890_O **)(arg0 + 0x154); o->vt->f1C(o, 0, 0);
    o = *(S_00690890_O **)(arg0 + 0x158); o->vt->f1C(o, 0, 0);
    o = *(S_00690890_O **)(arg0 + 0x15C); o->vt->f1C(o, 0, 0);
    o = *(S_00690890_O **)(arg0 + 0x114); o->vt->f4C(o, 0x40, 1);
    o = *(S_00690890_O **)(arg0 + 0x118); o->vt->f4C(o, 0x40, 1);
    o = *(S_00690890_O **)(arg0 + 0x11C); o->vt->f4C(o, 0x40, 1);
    o = *(S_00690890_O **)(arg0 + 0x120); o->vt->f4C(o, 0x40, 1);

    any = 0;
    j = 0;
    do {
        s32 t = any | (D_001FD630[j].a >= 0);
        any = t != 0;
        if (any) break;
        j++;
    } while (j < 11);
    if (any) {
        o = *(S_00690890_O **)(arg0 + 0x118); o->vt->f1C(o, 3, 0);
        o = *(S_00690890_O **)(arg0 + 0x118); o->vt->f4C(o, 0x40, 1);
    } else {
        o = *(S_00690890_O **)(arg0 + 0x118); o->vt->f1C(o, 2, 0);
        o = *(S_00690890_O **)(arg0 + 0x118); o->vt->f4C(o, 0x40, 0);
    }
    func_L39_006918A8(arg0);
    arg0[0x2A8] = 1;
}
/* localdecomp:end func_L39_00690890 */

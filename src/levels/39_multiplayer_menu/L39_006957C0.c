#include "common.h"

/* declared by functions of L39_00695328.c, which this file was cut from */
extern s32 *D_L39_0024D760;
extern s32 func_00381FF0(s32);
extern void func_L39_00689E58(void *, s32, u32, f32, f32);

/* localdecomp:start func_L39_006957C0 */
typedef struct VT_006957C0 {
    u8 pad0[0x1C];
    void (*fn1C)(void *, s32, s32);
    u8 pad20[0x40 - 0x20];
    void (*fn40)(void *, s32);
    u8 pad44[0x4C - 0x44];
    void (*fn4C)(void *, s32, s32);
    u8 pad50[0x6C - 0x50];
    void (*fn6C)(void *, s32, s32 *);
    u8 pad70[0x84 - 0x70];
    void (*fn84)(void *, s32);
    u8 pad88[0x90 - 0x88];
    void (*fn90)(void *, f32);
    u8 pad94[0xB8 - 0x94];
    void (*fnB8)(void *, s32);
} VT_006957C0;
typedef struct Obj_006957C0 {
    u8 pad0[0x60];
    VT_006957C0 *vt;
} Obj_006957C0;
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern void func_L39_00689BD8(void *, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689DB8(void *, s32);
extern void func_L39_0068A6D0(void *, s32, u32, f32, f32, f32, f32);
extern void func_L39_0068A4A8(void *, s32, s32, u32, f32, f32, f32, f32);
extern void func_L39_0068A7B8(void *, s32, u32, f32, f32, f32, f32);
extern void func_L39_0068AAB8(void *);
extern s32 func_L39_006CEA18(void *, s32);

s32 func_L39_006957C0(u8 *arg0)
{
    s32 str[1];
    s32 r;
    Obj_006957C0 *o;
    VT_006957C0 *vt;

    func_L39_0067F100(0x290000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(arg0, func_00381FF0(0xFC8));
    func_L39_00689D28(arg0, func_00381FF0(0x124));
    func_L39_00689E58(arg0, func_00381FF0(0xFCB), 0x706EC8FF, 1.0f, 1.0f);
    func_L39_00689DB8(arg0, func_00381FF0(0xCD5));
    func_L39_0068A6D0(arg0, 0, 0x332299DE, 0.274f, 0.418f, 0.365f, 0.554f);
    func_L39_0068A6D0(arg0, 1, 0x332299DE, 0.688f, 0.418f, 0.445f, 0.554f);
    func_L39_0068A6D0(arg0, 2, 0x332299DE, 0.501f, 0.783f, 0.82f, 0.155f);
    func_L39_0068A4A8(arg0, 0, 1, 0x331465B7, 0.274f, 0.2528f, 0.053f, 0.32500002f);
    func_L39_0068A7B8(arg0, 0, 0x332299DE, 0.274f, 0.2044f, 0.47060007f, 0.34500003f);
    func_L39_0068AAB8(arg0);
    str[0] = func_00381FF0(0x100F);
    o = *(Obj_006957C0 **)(arg0 + 0x118);
    o->vt->fn6C(o, 1, str);
    o = *(Obj_006957C0 **)(arg0 + 0x118);
    o->vt->fn1C(o, 2, 0);
    o = *(Obj_006957C0 **)(arg0 + 0x118);
    o->vt->fn40(o, 1);
    o = *(Obj_006957C0 **)(arg0 + 0x118);
    o->vt->fn90(o, 0.053399995f);
    o = *(Obj_006957C0 **)(arg0 + 0x118);
    o->vt->fn84(o, 1);
    o = *(Obj_006957C0 **)(arg0 + 0x114);
    o->vt->fn1C(o, 1, 0);
    o = *(Obj_006957C0 **)(arg0 + 0x114);
    o->vt->fn4C(o, 0x40, 1);
    o = *(Obj_006957C0 **)(arg0 + 0x11C);
    o->vt->fn1C(o, 1, 0);
    vt = (*(Obj_006957C0 **)(arg0 + 0x11C))->vt;
    vt->fnB8(*(void **)(arg0 + 0x11C), func_00381FF0(0x1662));
    o = *(Obj_006957C0 **)(arg0 + 0x11C);
    o->vt->fn40(o, 1);
    arg0[0x2B4] = 0;
    r = func_L39_006CEA18((void *)D_L39_0024D760[0x38 / 4], 0);
    arg0[0x2AC] = 1;
    return r;
}
/* localdecomp:end func_L39_006957C0 */

/* localdecomp:start func_L39_00695AE0 */
void func_L39_00695AE0(void *object)
{
    s32 temp_v0;

    temp_v0 = *(s32 *)((u8 *)object + 0x2A8) + 1;
    *(s32 *)((u8 *)object + 0x2A8) = temp_v0;
    if ((f32)temp_v0 > 750.0f) {
        *(s32 *)((u8 *)object + 0x2A8) = 0;
        *(u8 *)((u8 *)object + 0x2AC) = 1;
    }
}
/* localdecomp:end func_L39_00695AE0 */

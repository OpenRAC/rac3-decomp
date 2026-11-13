#include "common.h"

/* NTSC-U counterpart of func_L39_0069A170 (src/levels/39_multiplayer_menu/L39_0069A170.c) */
/* localdecomp:start func_L39_00697960 */
typedef struct VT_0069A170 {
    u8 pad0[0x24];
    void (*fn24)(void *, s32);
    u8 pad28[0x40 - 0x28];
    void (*fn40)(void *, s32);
    void (*fn44)(void *, s32, f32, f32);
    u8 pad48[0x4C - 0x48];
    void (*fn4C)(void *, s32, s32);
    u8 pad50[0x60 - 0x50];
    void (*fn60)(void *, s32);
    u8 pad64[0xA8 - 0x64];
    void (*fnA8)(void *, s32);
    u8 padAC[0xB8 - 0xAC];
    void (*fnB8)(void *, void *);
} VT_0069A170;
typedef struct Obj_0069A170 {
    u8 pad0[0x60];
    VT_0069A170 *vt;
} Obj_0069A170;
typedef struct Tbl_0069A170 {
    s32 v[16];
} Tbl_0069A170;
typedef struct P_0069A170 {
    u8 pad0[0x110];
    Obj_0069A170 *objs[14];
    u8 pad148[0x2A8 - 0x148];
    s32 f2A8;
    u8 pad2AC[0x2DC - 0x2AC];
    s32 f2DC;
    u8 pad2E0[0x304 - 0x2E0];
    u8 buf[1];
} P_0069A170;
extern Tbl_0069A170 D_L39_00248368;
extern u8 D_001A5EAE[];
extern void func_L39_0067C5E0(s32);
extern void func_L39_00687E10(s32);
extern s32 func_0037DF98(s32);
extern void func_L39_00687030(void *, s32);
extern void func_L39_00687180(void *, s32);
extern void func_L39_006872B0(void *, s32, f32, f32, u32);
extern void func_L39_00687210(void *, s32);
extern void func_L39_00687B28(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_00687900(void *, s32, s32, f32, f32, f32, f32, u32);
extern void func_L39_00687358(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L39_00687F10(void *);
extern void func_L39_00688750(void *, s32, s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_0037E368(s32, s32, s32, s32, s32, s32);
extern void func_L39_00699240(void *);
extern void func_L39_006996C8(void *);

void func_L39_00697960(P_0069A170 *arg0)
{
    Tbl_0069A170 tbl;
    Obj_0069A170 *o;
    s32 v;
    s32 i;

    func_L39_0067C5E0(0x2D0000);
    func_L39_00687E10(0);
    func_L39_00687030(arg0, func_0037DF98(0xFE5));
    func_L39_00687180(arg0, func_0037DF98(0x124));
    func_L39_006872B0(arg0, func_0037DF98(0x132B), 1.0f, 1.0f, 0x706EC8FF);
    func_L39_00687210(arg0, func_0037DF98(0xCD5));
    func_L39_00687B28(arg0, 0, 0.293000013f, 0.5f, 0.409999996f, 0.725000024f, 0x332299DE);
    func_L39_00687B28(arg0, 1, 0.708000004f, 0.266000003f, 0.405000001f, 0.254999995f, 0x332299DE);
    func_L39_00687B28(arg0, 2, 0.708000004f, 0.630999982f, 0.405000001f, 0.460999995f, 0x332299DE);
    func_L39_00687900(arg0, 0, 10, 0.293000013f, 0.19685711f, 0.050357163f, 0.389999986f, 0x332299DE);
    func_L39_00687900(arg0, 1, 2, 0.293000013f, 0.700428605f, 0.050357163f, 0.389999986f, 0x332299DE);
    func_L39_00687358(arg0, 0, 3, 3, 1.5f, 1.5f, 0.389999986f, 0.0350000001f, 0.0410000011f, 0.100000001f);
    func_L39_00687F10(arg0);
    func_L39_00688750(arg0, 0, 0);
    o = arg0->objs[7];
    o->vt->fnA8(o, arg0->f2DC);
    o = arg0->objs[8];
    o->vt->fn60(o, 0);
    func_00120048(arg0->buf, (u8 *)func_0037DF98(0x1423), 14, D_001A5EAE);
    o = arg0->objs[0];
    o->vt->fnB8(o, arg0->buf);
    tbl = D_L39_00248368;
    v = tbl.v[func_0037E368(0, 15, 16, 1, 0, 0)];
    if (arg0->f2A8 != 4) {
        o = arg0->objs[9];
        o->vt->fn24(o, v);
    }
    o = arg0->objs[9];
    o->vt->fn44(o, 1, 0.358900011f, 0.0f);
    o = arg0->objs[0];
    o->vt->fn44(o, 1, 1.0f, 0.0f);
    o = arg0->objs[1];
    o->vt->fn44(o, 1, 0.25f, 0.0f);
    o = arg0->objs[12];
    o->vt->fn4C(o, 0x8000, 1);
    o = arg0->objs[13];
    o->vt->fn4C(o, 0x8000, 1);
    for (i = 0; i < 12; i++) {
        o = arg0->objs[i];
        o->vt->fn40(o, 1);
        o = arg0->objs[i];
        o->vt->fn4C(o, 0x40, 1);
    }
    func_L39_00699240(arg0);
    func_L39_006996C8(arg0);
}
/* localdecomp:end func_L39_00697960 */

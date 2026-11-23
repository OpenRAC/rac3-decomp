#include "common.h"

/* NTSC-U counterpart of func_L02_003A4CC0 (src/levels/shared/L02_003A3988.c) */
#include "vu0.h"
#include "vu0.h"
extern f32 func_0037E2A8(void);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L02_003A2DA8(void *);
extern s32 D_001D545C;

/* localdecomp:start func_L02_003A2DA8 */
/* from the NTSC-U draft nonmatching/levels/func_L02_003A2DA8.c (func_L02_003A2DA8), with PAL names and constants */
typedef struct {
    u8 pad000[0x30];
    f32 f030;
    s16 h034;
    u8 pad036[0x3];
    u8 b039;
    u8 pad03A[0x4];
    u8 b03E;
    u8 pad03F[0x1];
    f32 f040;
    u8 pad044[0x14];
    u8 b058;
    u8 pad059[0x1];
    u8 b05A;
    u8 pad05B[0x15];
    f32 f070;
    f32 f074;
    f32 f078;
    f32 f07C;
    f32 f080;
    u8 pad084[0x18];
    f32 f09C;
    f32 f0A0;
    u8 pad0A4[0x4];
    s32 i0A8;
    u8 pad0AC[0xC4];
    u8 b170;
    u8 pad171[0x5];
    u8 b176;
    u8 pad177[0x5];
    f32 f17C;
    f32 f180;
    f32 f184;
    f32 f188;
    f32 f18C;
    f32 f190;
    f32 f194;
    u8 pad198[0x4];
    f32 f19C;
    f32 f1A0;
    u8 pad1A4[0x4];
    u8 b1A8;
    u8 pad1A9[0x29];
    u8 b1D2;
    u8 b1D3;
    u8 pad1D4[0x2];
    u8 b1D6;
    u8 b1D7;
    u8 b1D8;
    u8 b1D9;
    u8 b1DA;
    u8 b1DB;
    u8 pad1DC[0xE8];
    f32 f2C4;
    u8 pad2C8[0x18];
    vu0_v4 home;
    u8 pad2F0[0x18];
    f32 f308;
    u8 pad30C[0x4];
    f32 f310;
} Vars_003A4CC0;
typedef struct {
    u8 pad000[0x24];
    f32 scale;
} Class_003A4CC0;
typedef struct {
    u8 pad000[0x10];
    vu0_v4 pos;
    u8 pad020[0x4];
    Class_003A4CC0 *cls;
    u8 pad028[0x4];
    f32 scale;
    u8 pad030[0x13];
    u8 anim;
    u8 pad044[0x24];
    Vars_003A4CC0 *vars;
} Object_003A4CC0;
extern s32 D_L02_001D67B0_003A2DA8;
__asm__(".extern D_L02_001D67B0_003A2DA8, 4");
extern s32 D_001D545C;
extern s32 D_001D545C_003A2DA8;
__asm__(".extern D_001D545C_003A2DA8, 16");
extern f32 func_0037E2A8(void);
extern f32 func_003BE7F0(void *, s32, f32, void *);
extern f32 func_L01_00440918(f32, f32);

s32 func_L02_003A2DA8(void *arg) {
    Object_003A4CC0 *obj = arg;
    Vars_003A4CC0 *v = obj->vars;
    vu0_v4 *pos = &obj->pos;

    v->home = obj->pos;
    D_L02_001D67B0_003A2DA8 = 0;
    v->f308 = func_0037E2A8();
    obj->pos.z = func_003BE7F0(pos, 0, 0.5f, 0) + 0.5f;
    if (obj->pos.z < 2.0f) {
        obj->pos.z = v->home.z;
    }
    if (v->f2C4 < 1.0f && D_001D545C == 2) {
        return 1;
    }
    v->f310 = func_L01_00440918(15.0f, 35.0f) * 0.017453292f;
    v->b170 = 6;
    v->b176 = 0;
    v->b1D6 = 1;
    v->f184 = 0.0069444445f;
    v->f190 = 0.5f;
    v->b1A8 = 3;
    v->b1D3 = 15;
    v->b1D2 = 6;
    v->f17C = 0.25f;
    v->f180 = 0.016666668f;
    v->f188 = 0.0069444445f;
    v->f18C = 0.00027777778f;
    v->f194 = 0.5f;
    v->f19C = 0.15f;
    v->b1D7 = 1;
    v->b1DB = 255;
    v->b1D8 = 0;
    v->b1D9 = 0;
    v->b1DA = 0;
    if (v->home.z > 310.0f) {
        if (D_001D545C_003A2DA8 == 2) {
            v->f1A0 = 310.0f;
        }
    } else {
        if (D_001D545C_003A2DA8 == 2) {
            v->f1A0 = 25.0f;
        }
    }
    if (D_001D545C_003A2DA8 == 5) {
        v->f1A0 = obj->pos.z - 25.0f;
    }
    obj->scale = obj->cls->scale * 4.0f;
    v->f07C = 1.0f;
    v->i0A8 |= 4;
    v->f070 = 0.45f;
    v->f074 = 0.05f;
    v->f078 = 0.5f;
    v->f080 = 0.7853982f;
    v->f0A0 = 0.34906584f;
    v->f09C = 0.0027222224f;
    func_L01_00458A70(obj, 0.0044444446f, 0.10000001f, 0.0069813174f, 0.20943953f);
    v->b058 = 20;
    v->b05A = 14;
    if (v->h034 == 0) {
        v->f030 = 1.0f;
        v->h034 = 1;
    }
    v->b039 = 1;
    v->b03E = 1;
    v->f040 = 0.3f;
    func_L01_00441FB8(obj, 1, 0);
    if (obj->anim != 1) {
        func_003BE4F0(obj, 1, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L02_003A2DA8 */

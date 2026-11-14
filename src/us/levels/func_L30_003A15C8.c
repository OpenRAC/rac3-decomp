#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L30_003A15C8 */
typedef struct Src_3A15C8 {
    u8 pad0[0x24];
    f32 f24;
} Src_3A15C8;

typedef struct Ctx_3A15C8 {
    f32 f0;
    u8 pad4[0xC];
    vu0_q q10;
    u8 pad20[0x10];
    vu0_q q30;
    f32 f40;
    f32 f44;
    u8 pad48[4];
    s32 state;
    u8 pad50[0xC];
    f32 f5C;
    u8 pad60[0xC];
    f32 f6C;
    f32 f70;
    u8 pad74[8];
    s32 w7C;
} Ctx_3A15C8;

typedef struct Obj_3A15C8 {
    u8 pad0[0x24];
    Src_3A15C8 *src;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0x10];
    u8 b40;
    u8 b41;
    u8 pad42;
    u8 b43;
    u8 pad44[0x24];
    Ctx_3A15C8 *ctx;
    u8 pad6C[0x88];
    f32 fF4;
    f32 fF8;
} Obj_3A15C8;

extern f32 D_001DE8E0_sda;
__asm__(".extern D_001DE8E0_sda, 4");
extern f32 D_001DE8E4_sda;
__asm__(".extern D_001DE8E4_sda, 4");
extern f32 D_001DE8E8_sda;
__asm__(".extern D_001DE8E8_sda, 4");
extern s32 D_001DE990_sda;
__asm__(".extern D_001DE990_sda, 4");
extern f32 D_001DE998_sda;
__asm__(".extern D_001DE998_sda, 4");
extern f32 D_001DE99C_sda;
__asm__(".extern D_001DE99C_sda, 4");
extern f32 D_001DE9A0_sda;
__asm__(".extern D_001DE9A0_sda, 4");
extern f32 D_001DE9A4_sda;
__asm__(".extern D_001DE9A4_sda, 4");
extern s32 D_L30_001DF2C0_003A15C8;
__asm__(".extern D_L30_001DF2C0_003A15C8, 16");
extern f32 D_001A4C60[];

extern s32 func_L01_00452EC8(void *);
extern void func_L01_00442E08(void *, s32);
extern void func_003C2868(void *);
extern void func_L01_00445758(void *, f32, void *, s32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_L30_0034BB18(void *);
extern f32 func_00389380(f32, f32);
extern s32 func_L01_00452F60(void *);
extern void func_L30_003A1210(void *, s32);

void func_L30_003A15C8(Obj_3A15C8 *obj) {
    Ctx_3A15C8 *c = obj->ctx;
    f32 t;
    f32 a;

    if (func_L01_00452EC8(obj) != 0) {
        func_L01_00442E08(obj, 0x1C1A);
        func_003C2868(obj);
        obj->b40 = 0;
        obj->b41 = 0;
        c->f6C = D_001DE8E0_sda * c->f70;
        obj->f2C = c->f70 * obj->src->f24;
    }
    c->w7C = D_L30_001DF2C0_003A15C8;
    c->q30 = c->q10;
    if ((u32)c->state < 2) {
        func_L01_00445758(&obj->fF4, 0.0f, &c->f40, 0, D_001DE998_sda, D_001DE99C_sda, D_001DE9A4_sda);
        if (obj->b43 != 3) {
            func_003BE4F0(obj, 3, 0, D_001DE990_sda);
        }
    } else if (c->state == 2) {
        t = D_001DE9A0_sda * (c->f5C - 0.25f);
        a = func_L30_0034BB18((u8 *)c + 0x20);
        a = func_00389380(-a, -1.5707964f);
        func_L01_00445758(&obj->fF4, a, &c->f40, 0, t * D_001DE998_sda, t * D_001DE99C_sda, t * D_001DE9A4_sda);
        func_L01_00445758(&obj->fF8, D_001DE8E8_sda, &c->f44, 0, t * D_001DE998_sda, t * D_001DE99C_sda, t * D_001DE9A4_sda);
        if (obj->b43 != 0) {
            func_003BE4F0(obj, 0, 0, D_001DE990_sda);
        }
    }
    if (c->state == 0) {
        func_L01_00445758(&obj->fF8, c->f0 < 0.0f ? D_001DE8E4_sda : D_001DE8E8_sda, &c->f44, 0, D_001DE998_sda, D_001DE99C_sda, D_001DE9A4_sda);
    } else if (c->state == 1) {
        func_L01_00445758(&obj->fF8, D_001A4C60[0] < *(f32 *)((u8 *)c + 0x30) ? D_001DE8E4_sda : D_001DE8E8_sda, &c->f44, 0, D_001DE998_sda, D_001DE99C_sda, D_001DE9A4_sda);
    }
    if (func_L01_00452F60(obj) != 0) {
        func_L30_003A1210(obj, 0x42);
    }
}
/* localdecomp:end func_L30_003A15C8 */

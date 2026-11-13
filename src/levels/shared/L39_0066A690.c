#include "common.h"

/* declared by functions of L39_00668620.c, which this file was cut from */
typedef struct { s32 a, b, c, d, e, f, g; } S_00668C90;
extern S_00668C90 D_L39_0033AB08[];
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
extern s32 func_L39_0061BF68(void *);

/* localdecomp:start func_L39_0066A690 */
typedef struct Hd_0066A690 { u8 pad0[0x14]; f32 f14; } Hd_0066A690;
typedef struct Slf_0066A690 {
    u8 pad0[0x20];
    u8 v20[0x10];
    u8 pad30[0xB0 - 0x30];
    u8 vB0[0x10];
    u8 padC0[0x110 - 0xC0];
    Hd_0066A690 *p110;
    u8 pad114[0x120 - 0x114];
    Vec4 q120;
    u8 pad130[0x1F0 - 0x130];
    Vec4 q1F0;
    Vec4 q200;
    u8 pad210[0x230 - 0x210];
    Vec4 q230;
    Vec4 q240;
    u8 pad250[0x2D0 - 0x250];
    void *o2D0;
    u8 pad2D4[4];
    void *p2D8;
    u8 pad2DC[4];
    s32 w2E0;
    u8 pad2E4[0x2F8 - 0x2E4];
    s32 w2F8;
    s16 h2FC;
    u8 pad2FE[2];
    u8 b300;
    u8 pad301[0x310 - 0x301];
    f32 f310;
} Slf_0066A690;
typedef void (*Fn_0066A690)(void *);
typedef struct { s32 a; Fn_0066A690 b; s32 c, d, e, f, g; } Ent_0066A690;
extern void func_L39_0061ECE0(void *, void *, s32);
extern void func_L39_0061F3F0(void *);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern void func_L39_006670C0(void *, s32, s32, s32, s32);
extern void func_L39_0061FBC8(void *, void *, s32);
extern void func_L39_0066A490(void *);

void func_L39_0066A690(Slf_0066A690 *self, s32 arg1) {
    s32 found = 0;
    s32 r;

    if (self->w2F8 & 8) {
        return;
    }
    r = func_L39_0061BF68(self->p2D8);
    if ((*(unsigned long *)&self->w2F8 & 6) == 6 || r >= 0) {
        if (D_L39_0033AB08[self->h2FC].b != 0) {
            ((Ent_0066A690 *)D_L39_0033AB08)[self->h2FC].b(self->o2D0);
        }
        if ((*(unsigned long *)&self->w2F8 & 0x802) == 0x802 && self->f310 == 0.0f && self->b300 == 0) {
            self->w2F8 &= 0xFFFFF7F9;
            func_L39_0061ECE0(self->v20, &self->q230, arg1);
            found = 1;
            self->w2F8 |= 8;
        } else {
            self->q120 = self->q230;
            func_L39_0061F3F0(self->v20);
        }
        if (arg1 >= self->w2E0 + 0x43) {
            f32 d = func_L01_0040E548(self->vB0, &self->q230);
            if (self->p110->f14 < d) {
                found = 1;
            }
            if (func_0038DBA0(self->q200.f[0], self->q240.f[0]) > 0.1f ||
                func_0038DBA0(self->q200.f[1], self->q240.f[1]) > 0.1f ||
                func_0038DBA0(self->q200.f[2], self->q240.f[2]) > 0.1f) {
                found = 1;
            }
        }
        if (found != 0) {
            func_L39_006670C0(self, arg1, 0, (self->w2F8 >> 3) & 1, 0);
            self->q1F0 = self->q230;
            self->w2E0 = arg1;
            self->q200 = self->q240;
            func_L39_0061FBC8(self->v20, &self->q1F0, arg1);
        }
    } else if (self->w2F8 & 0x20) {
        func_L39_0066A490(self);
    }
}
/* localdecomp:end func_L39_0066A690 */

/* localdecomp:start func_L39_0066A8C8 */
#include "vu0.h"
typedef union {
    u128_t q;
    f32 f[4];
} V_0066A8C8;
extern s32 D_001A5DF8[];
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern u8 *func_L01_004669B0(f32, f32, f32, f32, void *, s32, void *, u32, s32);

/* from the shape of func_L01_0040D510 */
void func_L39_0066A8C8(u8 *a0, u8 *a1) {
    V_0066A8C8 vel;
    V_0066A8C8 pt;
    u8 *particle;
    u8 *data;
    s32 r;

    if (a1[0xBC] == 9 && *(s32 *)(a0 + 0x2E8) - 100 >= D_001A5DF8[0]) {
        pt.q = *(u128_t *)(a1 + 0x10);
        qzero(&vel);
        pt.f[2] += 0.75f;
        vel.f[2] += (func_L39_005B4410(0.0f, 1.25f) + 0.25f) * 0.020000001f;
        particle = func_L01_004669B0(0.0f, 1.0f, 1.01f, 210000.0f, &pt, 1, &vel, 0x101010, 0);
        if (particle != 0) {
            particle[3] = 0x44;
            *(s16 *)(particle + 0xA) = (func_L39_005B43C8(0x3C, 0xA0) * 5 + 2) / 6;
            particle[9] = 100;
            data = particle + 0x20;
            r = func_L39_005B43C8(1, 10);
            *(s32 *)(data + 4) = 3;
            data[0xA] = 0x7F;
            *(f32 *)(data + 0x1C) = (r * 5 + 2) / 6;
            data[0xB] = particle[0xA];
        }
    }
}
/* localdecomp:end func_L39_0066A8C8 */

/* localdecomp:start func_L39_0066AA50 */
typedef struct Slf_0066AA50 { u8 pad0[0x2E8]; s32 w2E8; } Slf_0066AA50;
typedef struct Obj_0066AA50 { u8 pad0[0xBC]; u8 bBC; } Obj_0066AA50;
extern s32 D_001A5DF8[];
extern f32 D_001DAB08_sda;
extern f32 D_001DAB00_sda;
extern f32 D_001DAB04_sda;
__asm__(".extern D_001DAB08_sda, 4");
__asm__(".extern D_001DAB00_sda, 4");
__asm__(".extern D_001DAB04_sda, 4");
extern s32 func_L39_005B4398(s32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_003D8E60(void *, void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L39_0066AA50(Slf_0066AA50 *self, Obj_0066AA50 *obj, s32 arg2, s32 *arg3) {
    s32 i;
    s32 idx;
    f32 v90[4];
    Vec4 a;
    Vec4 b;
    f32 d;

    if (obj->bBC != 9) {
        return;
    }
    if (self->w2E8 - 100 < D_001A5DF8[0]) {
        return;
    }
    idx = func_L39_005B4398(15) ? -1 : func_L39_005B4398(arg2);
    b.q = 0;
    b.f[2] = D_001DAB08_sda * 0.020000001f;
    a.q = b.q;
    for (i = 0; i < 3; i++) {
        d = func_L39_005B4410(D_001DAB00_sda, D_001DAB00_sda + 0.3f);
        func_003C2F58(obj, arg3[i], v90);
        func_L01_003D8E60(v90, &a, -100000.0f, d, D_001DAB04_sda, 10, 2, 0, 2, 0x40, 0);
        func_L01_003D8E60(v90, &a, -100000.0f, d, D_001DAB04_sda, 20, 2, 0, 2, 0x40, 0);
        if (idx == i) {
            func_L01_003303B8(v90, 0, 5, 0, 5, 10, 0, 0, 0.5f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    }
}
/* localdecomp:end func_L39_0066AA50 */

INCLUDE_ASM("asm/levels", func_L39_0066ACA8);

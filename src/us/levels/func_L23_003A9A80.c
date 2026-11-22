#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef int u128_t __attribute__((mode(TI)));
typedef struct { s32 x0; f32 x4; u8 pad8[8]; u128_t pos; } Vars_3AB2F0;

/* NTSC-U counterpart of func_L23_003AB2F0. */
/* localdecomp:start func_L23_003A9A80 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern s32 D_L23_001DECC0;
__asm__(".extern D_L23_001DECC0, 16");
extern struct Moby *D_L23_001E8818[];
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00445758(void *a0, f32 f12, f32 f13, f32 f14, f32 f15, void *a1, s32 a2);
extern f32 func_00389468(f32, f32);
extern s32 func_L01_00452EC8(u8 *);
extern void func_L01_00402560(void *, u8 *);
extern s32 func_00388398(void *);
void func_L23_003A9D80(u8 *self);
void func_L23_003A9F00(u8 *self);
void func_L23_003A9F80(u8 *self);
void func_L23_003AA1F0(u8 *self);
void func_L23_003AA2D8(u8 *self);

void func_L23_003A9A80(u8 *self)
{
    Vars_3AB2F0 *v = *(Vars_3AB2F0 **)(self + 0x68);
    V4 t;
    u8 *pos;
    f32 ang;

    if (self[0x20] != 4)
        func_L23_003A9D80(self);
    switch (self[0x20]) {
    case 0:
        func_L23_003A9F00(self);
        break;
    case 1:
        if ((D_L23_001DECC0 & 0xF) == (((s32)self >> 8) & 0xF)) {
            if (func_L01_0040C040(self + 0x10, &D_001A4BE0.pos) < 800.0f) {
                t = *(V4 *)(self + 0x10);
                t.z += 1.5f;
                if (func_003CE740(&t, &D_001A4BE0.pickup_point, 0, self, 0) == 0 ||
                    D_L23_001E8818[0] == D_001A4BE0.hero_moby)
                    func_L01_00441FB8(self, 2, -1);
            }
        }
        *(u128_t *)(self + 0x10) = v->pos;
        break;
    case 2:
        ang = func_00388A28(D_001A4BE0.pos.x - *(f32 *)(self + 0x10), D_001A4BE0.pos.y - *(f32 *)(self + 0x14));
        func_L01_00445758(self + 0xF8, ang, 0.00174532935f, 0.00174532935f, 0.104719765f, &v->x4, 0);
        *(u128_t *)(self + 0x10) = v->pos;
        if (func_L01_0040C040(self + 0x10, &D_001A4BE0.pos) > 800.0f)
            func_L01_00441FB8(self, 1, -1);
        if (func_00389468(*(f32 *)(self + 0xF8), ang) < 0.08726646f) {
            if (fabs_asm(v->x4) < 0.000727220555f) {
                v->x4 = 0.0f;
                func_L01_00441FB8(self, 3, -1);
            }
        }
        break;
    case 3:
        if (func_L01_00452EC8(self) != 0)
            func_L23_003A9F80(self);
        pos = self + 0x10;
        *(u128_t *)pos = v->pos;
        if (v->x0 <= 0) {
            if (func_003CE740(pos, D_001A4BE0.pad_A0 + 0x30, 0, self, 0) != 0 &&
                D_L23_001E8818[0] != D_001A4BE0.hero_moby)
                func_L01_00441FB8(self, 1, -1);
            else
                func_L01_00441FB8(self, 2, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(self) != 0) {
            func_L23_003AA1F0(self);
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) |= 0x41;
        }
        func_L01_00402560(func_L23_003AA2D8, self);
        return;
    }
    (*(u16 *)(self + 0x96))++;
    func_00388398(v);
}
/* localdecomp:end func_L23_003A9A80 */

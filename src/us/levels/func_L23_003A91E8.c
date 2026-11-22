#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef int u128_t __attribute__((mode(TI)));

/* NTSC-U counterpart of func_L23_003AAA58. */
/* localdecomp:start func_L23_003A91E8 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern f32 func_L01_0040C040(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
void func_L23_003A94E8(u8 *self);
void func_L23_003A9668(u8 *a0);
void func_L23_003A96E8(u8 *self);
void func_L23_003A97E8(u8 *a0);
extern s32 D_L23_001DECC0;
__asm__(".extern D_L23_001DECC0, 16");
extern struct Moby *D_L23_001E8818[];
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L01_004576E8();
extern f32 func_00388A28(f32, f32);
extern void func_L01_00445758(void *a0, f32 f12, f32 f13, f32 f14, f32 f15, void *a1, s32 a2);
extern f32 func_00389468(f32, f32);
extern s32 func_L01_00452EC8(u8 *);
extern void func_L01_00402560(void *, u8 *);
extern s32 func_00388398(void *);
void func_L23_003A98D0(u8 *self);

void func_L23_003A91E8(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);
    V4 p;
    f32 ang;
    u8 *pos;

    if (self[0x20] != 4)
        func_L23_003A94E8(self);
    switch (self[0x20]) {
    case 0:
        func_L23_003A9668(self);
        break;
    case 1:
        if ((D_L23_001DECC0 & 0xF) == (((s32)self >> 8) & 0xF) &&
            func_L01_0040C040(self + 0x10, &D_001A4BE0.pos) < 800.0f) {
            p = *(V4 *)(self + 0x10);
            p.z += 1.5f;
            if (func_003CE740(&p, &D_001A4BE0.pickup_point, 0, self, 0) == 0 || D_L23_001E8818[0] == D_001A4BE0.hero_moby)
                func_L01_00441FB8(self, 2, -1);
        }
        func_L01_004576E8(self);
        break;
    case 2:
        ang = func_00388A28(D_001A4BE0.pos.x - *(f32 *)(self + 0x10), D_001A4BE0.pos.y - *(f32 *)(self + 0x14));
        func_L01_00445758(self + 0xF8, ang, 0.00174532935f, 0.00174532935f, 0.104719765f, v + 4, 0);
        *(u128_t *)(self + 0x10) = *(u128_t *)(v + 0x10);
        if (func_L01_0040C040(self + 0x10, &D_001A4BE0.pos) > 800.0f)
            func_L01_00441FB8(self, 1, -1);
        if (func_00389468(*(f32 *)(self + 0xF8), ang) < 0.08726646f) {
            if (fabs_asm(*(f32 *)(v + 4)) < 0.000727220555f) {
                *(f32 *)(v + 4) = 0.0f;
                func_L01_00441FB8(self, 3, -1);
            }
        }
        break;
    case 3:
        if (func_L01_00452EC8(self) != 0)
            func_L23_003A96E8(self);
        pos = self + 0x10;
        *(u128_t *)pos = *(u128_t *)(v + 0x10);
        if (*(s32 *)v <= 0) {
            if (func_003CE740(pos, D_001A4BE0.pad_A0 + 0x30, 0, self, 0) != 0 && D_L23_001E8818[0] != D_001A4BE0.hero_moby)
                func_L01_00441FB8(self, 1, -1);
            else
                func_L01_00441FB8(self, 2, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(self) != 0) {
            func_L23_003A97E8(self);
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) |= 0x41;
        }
        func_L01_00402560(func_L23_003A98D0, self);
        return;
    }
    *(u16 *)(self + 0x96) += 1;
    func_00388398(v);
}
/* localdecomp:end func_L23_003A91E8 */

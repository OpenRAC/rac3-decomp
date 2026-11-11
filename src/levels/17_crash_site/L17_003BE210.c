#include "common.h"

/* localdecomp:start func_L17_003BE210 */
typedef struct { s32 f0; } S_E210_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_E210_D *f68; } S_E210_O;
extern u8 D_001A4C60[];
extern s32 D_001D545C;
extern s32 D_00143D70[];
extern s16 D_001426A0[];
extern u32 D_001A8AEC[];
extern s32 func_00382380(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L17_003BE338();
extern void func_L17_003BE2F8();
extern void func_L01_0041A5B0(s32, s32);
void func_L17_003BE210(S_E210_O *self) {
    s32 i;
    S_E210_D *d = self->f68;
    switch (self->b20) {
    case 0:
        func_L17_003BE2F8(self);
        break;
    case 1:
        if (func_00382380(D_001A4C60, d->f0, 0) != 0) {
            func_003A52A0(0, 0, self);
            func_L17_003BE338(self);
        }
        break;
    case 2:
        break;
    }
    i = D_001D545C;
    if (D_00143D70[i] < 5) return;
    if (D_001426A0[0] < 3) {
        if ((D_001A8AEC[0] & (1 << i)) == 0) func_L01_0041A5B0(0x140F, 0x111);
    }
}
/* localdecomp:end func_L17_003BE210 */

/* localdecomp:start func_L17_003BE2F8 */
typedef struct { u8 p0[0x30]; u8 b30; u8 p31[3]; u16 h34; } S_E2F8_O;
extern void func_L01_004450F0(S_E2F8_O *, s32, s32);
void func_L17_003BE2F8(S_E2F8_O *a0) {
    func_L01_004450F0(a0, 1, -1);
    a0->b30 = 0xFF;
    a0->h34 &= ~1;
}
/* localdecomp:end func_L17_003BE2F8 */

/* localdecomp:start func_L17_003BE338 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BE338;
extern f32 D_L17_001DE628;
extern f32 D_L17_001DE62C;
extern s32 D_L17_001DE630;
extern s32 D_L17_001DE634;
extern f32 D_L17_001DE638;
extern f32 D_L17_001DE63C;
extern f32 D_L17_001DE640;
extern f32 D_L17_001DE644;
extern f32 D_L17_001DE648;
extern f32 D_L17_001DE64C;
extern s32 D_L17_001DE650;
extern s32 D_L17_001DE654;
extern s32 D_L17_001DE658;
extern f32 D_L17_001DE65C;
extern f32 D_L17_001DE660;
extern f32 D_L17_001DE664;
extern f32 D_L17_001DE668;
__asm__(".extern D_L17_001DE628, 4");
__asm__(".extern D_L17_001DE62C, 4");
__asm__(".extern D_L17_001DE630, 4");
__asm__(".extern D_L17_001DE634, 4");
__asm__(".extern D_L17_001DE638, 4");
__asm__(".extern D_L17_001DE63C, 4");
__asm__(".extern D_L17_001DE640, 4");
__asm__(".extern D_L17_001DE644, 4");
__asm__(".extern D_L17_001DE648, 4");
__asm__(".extern D_L17_001DE64C, 4");
__asm__(".extern D_L17_001DE650, 4");
__asm__(".extern D_L17_001DE654, 4");
__asm__(".extern D_L17_001DE658, 4");
__asm__(".extern D_L17_001DE65C, 4");
__asm__(".extern D_L17_001DE660, 4");
__asm__(".extern D_L17_001DE664, 4");
__asm__(".extern D_L17_001DE668, 4");
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L17_003BE338(u8 *self) {
    V4_3BE338 v, pos, dir;
    f32 sx, sy, s;
    s32 i, j;

    func_0038CE20(&v, self + 0xE0, 0.08f);
    func_L01_00451FE0(self, 0xFFFF, &v, 0xFF, 0x32, 0, 0, 0x23, 0, 3,
                      2.0f, 4.0f, D_L17_001DE664, D_L17_001DE668, -1.0f, 0.0f, 1.0f, 1.0f);
    sy = 1.0f / (f32)D_L17_001DE634;
    sx = 1.0f / (f32)D_L17_001DE630;
    for (i = 0; i < D_L17_001DE630; i++) {
        for (j = 0; j < D_L17_001DE634; j++) {
            f32 r;
            pos.x = *(f32 *)(self + 0x10) + (((f32)i + (f32)i) * sx - 1.0f) * D_L17_001DE628;
            r = func_003824E0(-D_L17_001DE638, D_L17_001DE638);
            pos.y = *(f32 *)(self + 0x14) + (((f32)j + (f32)j) * sy - 1.0f) * D_L17_001DE62C + r;
            pos.z = *(f32 *)(self + 0x18);
            s = func_003824E0(D_L17_001DE63C, D_L17_001DE640) * 0.020000001f;
            dir.x = func_003824E0(-1.0f, 1.0f);
            dir.y = func_003824E0(-1.0f, 1.0f);
            dir.z = 0.0f;
            func_0038CF68(&dir, &dir, s);
            dir.z = func_003824E0(D_L17_001DE644, D_L17_001DE648) * 0.020000001f;
            func_L01_00475C60(&pos, &dir, (D_L17_001DE650 * 5 + 2) / 6, 1, D_L17_001DE654, D_L17_001DE658, 0,
                              D_L17_001DE65C * 210000.0f, D_L17_001DE660 * 210000.0f, D_L17_001DE64C);
        }
    }
    self[0x31] = 0;
    *(s32 *)(self + 0x98) = 0;
    self[0x20] = 2;
    *(u16 *)(self + 0x34) |= 1;
}
/* localdecomp:end func_L17_003BE338 */

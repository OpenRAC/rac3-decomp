#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L12_003D5A50 (src/levels/shared/L12_003D5A50.c): 60, 10 and 40 for 42, 8 and 33; data moved */
/* localdecomp:start func_L12_003D3DA0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x20];
    f32 f20;
    s32 i24;
    s32 i28;
    s32 i2C;
    u8 p30[0x380 - 0x30];
    vu0_v4 v380;
    u8 p390[0x460 - 0x390];
} E_003D3DA0;

extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
extern E_003D3DA0 D_L12_001E2800[];
extern const s32 D_L12_001DEFF0;
__asm__(".extern D_L12_001DEFF0, 4");
extern const s32 D_L12_001DF008;
__asm__(".extern D_L12_001DF008, 4");
extern void func_0039FE80(s32, s32, void *);
extern void func_003C7CE0(void *);
extern void func_003BFC18(void *, void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern s32 func_003894E8(void *, f32);
extern f32 func_L01_0040C018(void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388990(f32);
extern void func_L12_003D4058(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L12_003D3DA0(u8 *self, u8 *v) {
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 g;
    vu0_v4 h;
    E_003D3DA0 *p;

    self[0x31] = 0;
    self[0x30] = 0xFF;
    *(u16 *)(self + 0x34) |= 1;
    func_L01_00441FB8(self, 4, -1);
    func_0039FE80(1, 0, self);
    if (*(void **)(v + 0x2C) != 0) {
        func_003C7CE0(*(void **)(v + 0x2C));
        *(void **)(v + 0x2C) = 0;
    }
    p = &D_L12_001E2800[D_001D52F0];
    *(f32 *)(self + 0x1C) = 1.0f;
    vec_sub_ba(&d, p, self + 0x10);
    func_00388830(&d, &d, 1.0f);
    func_003BFC18(self + 0x10, &e, 1);
    *(u128_t *)(self + 0xC0) = *(u128_t *)&d;
    func_00388758(self + 0xD0, self + 0xC0, &e);
    func_00388830(self + 0xD0, self + 0xD0, 1.0f);
    func_00388758(self + 0xE0, self + 0xD0, self + 0xC0);
    {
        f32 z = 0.0f;
        *(f32 *)(self + 0xEC) = z;
        *(f32 *)(self + 0xDC) = z;
        *(f32 *)(self + 0xCC) = z;
    }
    *(s32 *)(v + 0x24) = 60;
    *(u128_t *)&g = *(u128_t *)(self + 0x10);
    g.w = 5.25f;
    if (func_003894E8(&g, 128.0f) == 1) {
        *(s32 *)(v + 0x34) = 10;
        if (D_L12_001DEFF0 != 0) {
            if (func_L01_0040C018(self + 0x10, &D_L12_001E2800[D_001D52F0]) < 2304.0f) {
                D_L12_001E2800[0].i28 = 40;
                D_L12_001E2800[0].f20 = 0.075f;
                D_L12_001E2800[0].i2C = 0;
            }
        }
        if (D_L12_001DF008 != 0) {
            f32 a;
            vec_sub_ab(&h, self + 0x10, &D_L12_001E2800[D_001D52F0]);
            func_00388830(&h, &h, 1.0f);
            a = func_00388990(func_00388730(&h, &D_L12_001E2800[D_001D52F0].v380));
            *(s32 *)(v + 0x30) = 0;
            if (1.5707964f - a < 0.45378560f) {
                *(s32 *)(v + 0x30) = 1;
            }
        }
    } else {
        *(s32 *)(v + 0x34) = 0;
        *(s32 *)(v + 0x30) = 0;
    }
    func_L12_003D4058(self, &e);
}
/* localdecomp:end func_L12_003D3DA0 */

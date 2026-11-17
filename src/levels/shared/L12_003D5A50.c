#include "common.h"

typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; void *w68; } M_3D5548;
typedef struct {
    void (*fn0)(void *);
} Iface;
typedef struct {
    char pad0[0x30];
    int timer;
    char pad34[0x3E - 0x34];
    unsigned char b62;
    char pad3F[0x40 - 0x3F];
    float f64;
} Vars;
typedef struct {
    char pad0[0x30];
    unsigned char b48;
    char pad31[0x32 - 0x31];
    short h50;
} Obj;

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L12_003D4B18.c, which this file was cut from */
extern void func_L01_004450F0(Obj *, int, int);

/* localdecomp:start func_L12_003D5A50 */
#include "vu0.h"

/* func_L12_003D5A50 log:
   - first draft: 100 diff (missing func_0038CF68 prototype), then 12 diff.
   - idx/array pointer taken before the 1.0f store; .extern 4 on the .lit flags (they go through $gp).
   - the three 0.0f stores through a float temporary in the order EC, DC, CC give retail's swc1 order.
   - else-branch stores 0x34 then 0x30; 26 deg constant 0.45378560f.
   - last 6 diff: the 0x2700($gp) load scheduled after the v+0x34 store; D_L12_001DEFB0/DEFC8 are
     tunables in the level's .lit (read-only), declared const: MATCH.
*/

typedef struct {
    u8 p0[0x20];
    f32 f20;
    s32 i24;
    s32 i28;
    s32 i2C;
    u8 p30[0x380 - 0x30];
    vu0_v4 v380;
    u8 p390[0x460 - 0x390];
} E_003D5A50;

extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
extern E_003D5A50 D_L12_001E2780[];
extern const s32 D_L12_001DEFB0;
__asm__(".extern D_L12_001DEFB0, 4");
extern const s32 D_L12_001DEFC8;
__asm__(".extern D_L12_001DEFC8, 4");
extern void func_003A52A0(s32, s32, void *);
extern void func_003CD250(void *);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_0038DC20(void *, f32);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_L12_003D5D08(void *, void *);

void func_L12_003D5A50(u8 *self, u8 *v) {
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 g;
    vu0_v4 h;
    E_003D5A50 *p;

    self[0x31] = 0;
    self[0x30] = 0xFF;
    *(u16 *)(self + 0x34) |= 1;
    func_L01_004450F0((Obj *)self, 4, -1);
    func_003A52A0(1, 0, self);
    if (*(void **)(v + 0x2C) != 0) {
        func_003CD250(*(void **)(v + 0x2C));
        *(void **)(v + 0x2C) = 0;
    }
    p = &D_L12_001E2780[D_001D52F0];
    *(f32 *)(self + 0x1C) = 1.0f;
    vec_sub_ba(&d, p, self + 0x10);
    func_0038CF68(&d, &d, 1.0f);
    func_003C5180(self + 0x10, &e, 1);
    *(u128_t *)(self + 0xC0) = *(u128_t *)&d;
    func_0038CE90(self + 0xD0, self + 0xC0, &e);
    func_0038CF68(self + 0xD0, self + 0xD0, 1.0f);
    func_0038CE90(self + 0xE0, self + 0xD0, self + 0xC0);
    {
        f32 z = 0.0f;
        *(f32 *)(self + 0xEC) = z;
        *(f32 *)(self + 0xDC) = z;
        *(f32 *)(self + 0xCC) = z;
    }
    *(s32 *)(v + 0x24) = 42;
    *(u128_t *)&g = *(u128_t *)(self + 0x10);
    g.w = 5.25f;
    if (func_0038DC20(&g, 128.0f) == 1) {
        *(s32 *)(v + 0x34) = 8;
        if (D_L12_001DEFB0 != 0) {
            if (func_L01_0040E548(self + 0x10, &D_L12_001E2780[D_001D52F0]) < 2304.0f) {
                D_L12_001E2780[0].i28 = 33;
                D_L12_001E2780[0].f20 = 0.075f;
                D_L12_001E2780[0].i2C = 0;
            }
        }
        if (D_L12_001DEFC8 != 0) {
            f32 a;
            vec_sub_ab(&h, self + 0x10, &D_L12_001E2780[D_001D52F0]);
            func_0038CF68(&h, &h, 1.0f);
            a = func_0038D0C8(func_0038CE68(&h, &D_L12_001E2780[D_001D52F0].v380));
            *(s32 *)(v + 0x30) = 0;
            if (1.5707964f - a < 0.45378560f) {
                *(s32 *)(v + 0x30) = 1;
            }
        }
    } else {
        *(s32 *)(v + 0x34) = 0;
        *(s32 *)(v + 0x30) = 0;
    }
    func_L12_003D5D08(self, &e);
}
/* localdecomp:end func_L12_003D5A50 */

#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L06_00358630. */
/* localdecomp:start func_L06_00357930 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00357930;
typedef struct {
    V_00357930 dir;
    u8 pad10[8];
    u8 b18;
    u8 pad19;
    u16 h1A;
    u8 pad1C[4];
    s32 flags;
    u8 pad24[0x30 - 0x24];
} D_00357930;
extern s32 func_00388398(s32 *a0);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern s32 func_L01_003F9498(void *, f32, s32, u8 *);
extern s32 func_003CF790(void *, f32, s32, void *, void *);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern void func_L01_004026A0(void *, void *);
/* The native callback and a carried PAL function share an address-based name. */
extern void func_L06_00357D58_00357930(u8 *);
typedef struct { u8 pad[0x18]; u8 *target; } G_00357930;
extern G_00357930 D_L06_001E8440;
__asm__(".extern D_L06_001DD3A0, 4");
extern f32 D_L06_001DD3A0;
__asm__(".extern D_L06_001DD3A4, 4");
extern f32 D_L06_001DD3A4;
__asm__(".extern D_L06_001DD3A8, 4");
extern f32 D_L06_001DD3A8;
__asm__(".extern D_L06_001DD3B0, 4");
extern f32 D_L06_001DD3B0;
__asm__(".extern D_L06_001DD3B4, 4");
extern f32 D_L06_001DD3B4;

void func_L06_00357930(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    V_00357930 pos;
    D_00357930 d;
    u8 *owner;
    u8 *m;
    s32 hit;
    f32 f;
    f32 lo;

    if (*(f32 *)(v + 0x24) < 1.0f) {
        f = *(f32 *)(v + 0x24) + D_L06_001DD3A0;
        *(f32 *)(v + 0x24) = f;
        if (1.0f < f) {
            *(f32 *)(v + 0x24) = 1.0f;
        }
    }
    vec_add_ba(&pos, a0 + 0x10, v);
    func_L01_00443628(&d, *(void **)(v + 0x18), 0x10001, v, *(f32 *)(v + 0x14));
    d.h1A = *(u16 *)(a0 + 0xAA);
    vec_sub_ab(&d.dir, a0 + 0x10, *(u8 **)(v + 0x18) + 0x10);
    d.dir.z = 0.0f;
    func_00388830(&d.dir, &d.dir, 1.66666675f);
    d.b18 = 1;
    d.dir.w = 5627.925f;
    d.flags |= 1;
    owner = *(u8 **)(v + 0x18);
    func_L01_004C76B8();
    hit = func_003CE740(a0 + 0x10, &pos, 0, owner, &d);
    if (hit) {
        m = D_L06_001E8440.target;
        if (m != 0 && *(s16 *)(m + 0xAA) == 0x186D && m[0x20] != 2 && m[0x20] != 5) {
            m[0x20] = 4;
        }
    }
    func_L01_004C76F0();
    if (hit || func_L01_003F9498(a0 + 0x10, D_L06_001DD3A4, 1, *(u8 **)(v + 0x18)) ||
        func_00388398((s32 *)(v + 0x1C))) {
        func_003CF790(a0 + 0x10, D_L06_001DD3A8, 0, *(u8 **)(v + 0x18), &d);
        func_L01_0032FE90(a0 + 0x10, 0, 8, 5, 8, 8, 0, 0, 0.4f, 0.0f, 0.0f, 1.0f,
                          0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x8EF738, 0x63F700, 0x7FFF40, 0x20FF00, 0x8FFF00,
                          0x64FF30, 0x7FA0FF60, 0x2800FF00, 0x64FF30, 0);
        func_003BD360(a0);
        return;
    }
    *(vu0_q *)(a0 + 0x10) = *(vu0_q *)&pos;
    if (func_00388398((s32 *)(v + 0x28))) {
        lo = D_L06_001DD3B4;
        if (lo < *(f32 *)(v + 0x2C)) {
            f = *(f32 *)(v + 0x2C) - D_L06_001DD3B0;
            *(f32 *)(v + 0x2C) = f;
            if (f < lo) {
                *(f32 *)(v + 0x2C) = lo;
            }
        }
    }
    func_L01_004026A0(func_L06_00357D58_00357930, a0);
}
/* localdecomp:end func_L06_00357930 */

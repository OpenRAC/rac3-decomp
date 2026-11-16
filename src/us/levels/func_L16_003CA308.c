#include "common.h"

/* NTSC-U counterpart of func_L16_003CBC88 (src/levels/16_kerwan/L16_003CBC88.c) */
/* localdecomp:start func_L16_003CA308 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003CBC88;

typedef struct {
    u8 pad0[0x50];
    f32 f50;
    u8 pad54[0x34];
    f32 f88;
    f32 f8C;
    f32 f90;
    u8 pad94[0x18];
    f32 fAC;
    u8 padB0[8];
    s32 wB8;
    u8 padBC[0xDC];
    f32 f198;
    u8 pad19C[0x18];
    s32 w1B4;
    u8 pad1B8[4];
    s32 w1BC;
    u8 pad1C0[0x48];
    s32 w208;
} S_003CBC88;

extern u8 D_001A30B0[];
extern f32 D_L16_001DE960_003CA308;
extern f32 D_L16_001DE954_003CA308;
extern f32 D_L16_001DE964;
__asm__(".extern D_L16_001DE954_003CA308, 4");
__asm__(".extern D_L16_001DE960_003CA308, 4");
__asm__(".extern D_L16_001DE964, 4");
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L01_00457440(void *, void *);
extern s32 func_L01_00458A08(void *, f32);
extern void func_L01_00457590(void *, void *, f32);

void func_L16_003CA308(u8 *a0, V_003CBC88 *a1, f32 f)
{
    V_003CBC88 v = *a1;
    S_003CBC88 *q = *(S_003CBC88 **)(a0 + 0x68);
    s32 h;
    u8 *e;

    if (q->w1BC == 2) {
        s32 k = q->w208;
        if (k < 0) {
            if (k == -1 || *(u8 **)((e = D_001A30B0 + (k << 7)) + 0xDC) != a0 || e[0xD0] == 0) {
                q->w208 = func_0039FE80(10, 4, a0);
            }
        }
        if (q->w1BC != q->w1B4) {
            q->fAC = 0.0f;
            q->f8C = q->f88 = 20.0f;
            q->wB8 = 0x415;
            q->f90 = 1.5707964f;
            func_L01_00458A70(a0, 0.008333333767950535f, 0.5f, 0.0034906587097793818f, 0.20943953096866608f);
            q->f50 = D_L16_001DE960_003CA308;
        }
        if (a0[0x20] == 6) {
            func_L01_00458A70(a0, 0.01666666753590107f, 1.0f, 0.0034906587097793818f, 0.20943953096866608f);
        }
        q->f198 = sqrt_asm(func_00388800(a0 + 0x10, &v));
        v.z = func_003BE7F0(&v, 0, 0, 0.5f) + q->f198;
        if (v.z < 100.0f) {
            v.z = *(f32 *)(a0 + 0x18);
        }
        func_L01_00457440(a0, &v);
        func_L01_00458A08(a0, f);
    } else if (q->w1BC == 0) {
        h = q->w208;
        if (h >= 0) {
            if (h != -1) {
                e = D_001A30B0 + (h << 7);
                if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_0039FB08(h);
                }
            }
            q->w208 = -1;
        }
        if (q->w1BC != q->w1B4) {
            q->wB8 = 0;
            q->f88 = 1.5f;
            q->fAC = D_L16_001DE954_003CA308;
            q->f8C = 1.5f;
            q->f90 = 1.3962634f;
            q->f50 = D_L16_001DE964;
        }
        func_L01_00457590(a0, &v, f);
    } else {
        h = q->w208;
        if (h >= 0) {
            if (h != -1) {
                e = D_001A30B0 + (h << 7);
                if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_0039FB08(h);
                }
            }
            q->w208 = -1;
        }
    }
    q->w1B4 = q->w1BC;
}
/* localdecomp:end func_L16_003CA308 */

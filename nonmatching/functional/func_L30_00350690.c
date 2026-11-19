/* functional: high. Same branch structure, calls and stores as retail (gp slots named by their story address); only register scheduling differs (checks close). */
#include "vu0.h"
__asm__(".extern D_L30_001DD740, 4");
__asm__(".extern D_L30_001DD7D4, 4");
__asm__(".extern D_L30_001DD7D8, 4");
__asm__(".extern D_L30_001DD7DC, 1");
__asm__(".extern D_L30_001DD7E0, 4");
__asm__(".extern D_L30_001DD7E4, 4");
__asm__(".extern D_L30_001DD7E8, 4");
__asm__(".extern D_L30_001DD7EC, 4");
__asm__(".extern D_L30_001DD7F0, 4");
__asm__(".extern D_L30_001DD7F4, 4");
__asm__(".extern D_L30_001DD7F8, 4");
__asm__(".extern D_L30_001DD7FC, 4");
__asm__(".extern D_L30_001DD800, 4");
__asm__(".extern D_L30_001DD804, 4");
__asm__(".extern D_L30_001DD808, 4");
__asm__(".extern D_L30_001DD850, 4");
__asm__(".extern D_L30_001DD854, 4");
__asm__(".extern D_L30_001DD858, 4");
__asm__(".extern D_L30_001DD85C, 4");
extern s32 D_L30_001DD740;
extern s32 D_L30_001DD7D4;
extern s32 D_L30_001DD7D8;
extern u8 D_L30_001DD7DC;
extern s32 D_L30_001DD7E0;
extern s32 D_L30_001DD7E4;
extern f32 D_L30_001DD7E8;
extern s32 D_L30_001DD7EC;
extern s32 D_L30_001DD7F0;
extern f32 D_L30_001DD7F4;
extern f32 D_L30_001DD7F8;
extern f32 D_L30_001DD7FC;
extern f32 D_L30_001DD800;
extern s32 D_L30_001DD804;
extern s32 D_L30_001DD808;
extern s32 D_L30_001DD850;
extern s32 D_L30_001DD854;
extern f32 D_L30_001DD858;
extern s32 D_L30_001DD85C;
extern u8 D_L30_001E1340[];
extern f32 D_001D66B0;
extern u8 *D_L30_0021F098[];
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L30_0034C958(void *, f32);
extern void func_L30_0034CF28(void *, void *, s32, f32, f32);
extern void func_L30_0034DAC0(void *);
typedef struct { u8 pad0[4]; s32 x4; f32 x8; u8 padC[4]; u8 x10[0x10]; } V_350690;
typedef struct { u8 pad0[0x10]; u8 x10[0x10]; u8 pad20[0x68 - 0x20]; V_350690 *x68; } O_350690;

void func_L30_00350690(O_350690 *self) {
    V_350690 *v = self->x68;

    if (D_L30_001DD740 >= v->x4) {
        if (D_L30_001DD740 - D_L30_001DD850 < v->x4) {
            func_L30_0034C8A8(D_L30_001E1340, self);
        }
        if (D_L30_001DD740 >= v->x4) {
            if (D_L30_001DD740 - D_L30_001DD808 < v->x4) {
                v->x8 += D_L30_001DD800;
                if (v->x8 > 1.0f) {
                    do {
                        f32 tmp[4] __attribute__((aligned(16)));
                        s32 a, b, c, col, g, r, bl, packed;
                        u8 *p;
                        f32 sz;

                        v->x8 -= 1.0f;
                        vec_copy(tmp, self->x10);
                        func_L30_0034C958(tmp, D_L30_001DD7E8);
                        a = func_00382498(D_L30_001DD7E4, D_L30_001DD7E0);
                        b = func_00382498(D_L30_001DD7F0, D_L30_001DD7EC);
                        c = func_00382498(0, 1);
                        if (c != 0) {
                            b = -b;
                        }
                        col = func_0038DBD8(D_L30_001DD7D4, D_L30_001DD7D8, func_003824E0(0.0f, 1.0f));
                        r = (col >> 7) & 0x1FE;
                        if (r > 0x80) r = 0x80;
                        g = (col >> 15) & 0x1FE;
                        if (g > 0x80) g = 0x80;
                        bl = (col & 0xFF) << 1;
                        if (bl > 0x80) bl = 0x80;
                        packed = (g << 16) | (r << 8) | bl;
                        sz = func_003824E0(D_L30_001DD7FC, D_L30_001DD7F8);
                        p = func_L01_00475C60(tmp, &D_001D66B0, a, b, col, packed, sz, sz * D_L30_001DD7F4, 0.0f, 0);
                        if (p != 0) {
                            p[2] = D_L30_0021F098[117][D_L30_001DD804];
                            p[3] = D_L30_001DD7DC;
                        }
                    } while (v->x8 > 1.0f);
                }
            }
            if (D_L30_001DD740 >= v->x4 && D_L30_001DD740 - D_L30_001DD85C < v->x4) {
                f32 t = func_L03_0034B440(1, 0, 5, (f32)(v->x4 - D_L30_001DD740 + D_L30_001DD85C),
                                          (f32)(D_L30_001DD85C + 1), 1.0f);
                func_L30_0034CF28(self->x10, v->x10, D_L30_001DD854,
                                  func_003C4088(0.0f, D_L30_001DD858, 1.0f - t), 0.0f);
                return;
            }
        }
    }
    func_L30_0034DAC0(v->x10);
}

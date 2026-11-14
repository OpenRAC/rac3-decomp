#include "common.h"

/* localdecomp:start func_L39_0066A490 */
#include "vu0.h"

typedef struct {
    void (*f0)(void *);
    void *p4;
    void (*f8)(void *);
    u8 pC[0x1C - 0xC];
} S_0066A490;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0066A490;

extern S_0066A490 D_L39_0033AB08[];
extern s32 D_001A5DF8[];
extern void func_0038CE20(void *, void *, f32);
extern void func_L39_0061ECE0(void *, void *, s32);
extern void func_L39_0061ED80(void *, void *, s32 *);

void func_L39_0066A490(u8 *self) {
    V_0066A490 v;
    s32 t;
    void *q;
    u8 *a;
    u8 *x;
    s32 n;
    u32 f;

    q = 0;
    a = *(u8 **)(self + 0x2D0);
    x = *(u8 **)(self + 0x2D8);
    if (x != 0 && *(x + 0x1A14) == 0 && (*(s32 *)(x + 0x4D84) & 1)) {
        return;
    }
    x = *(u8 **)(self + 0x2DC);
    if (x != 0 && *(x + 0x1A14) == 0 && (*(s32 *)(x + 0x4D84) & 1)) {
        return;
    }
    t = 0;
    if (*(u32 *)(self + 0x2F8) & 1) {
        t = *(s32 *)(self + 0x2E0);
        *(u32 *)(self + 0x2F8) &= ~1;
        q = self + 0x1F0;
    }
    if (*(u32 *)(self + 0x2F8) & 2) {
        func_0038CE20(&v, self + 0x2C0, 1.0f - (f32)*(s32 *)(self + 0x318) / 25.0f);
        vec_add_ab(self + 0xB0, self + 0x2B0, &v);
        n = *(s32 *)(self + 0x318) - 1;
        *(s32 *)(self + 0x318) = n;
        if (n <= 0) {
            func_L39_0061ECE0(self + 0x20, self + 0xB0, D_001A5DF8[0]);
            qzero(self + 0x270);
            *(s32 *)(self + 0x310) = 0;
            *(u32 *)(self + 0x2F8) = (*(u32 *)(self + 0x2F8) & ~0x22) | 8;
        }
    } else {
        func_L39_0061ED80(self + 0x20, q, &t);
    }
    f = *(u32 *)(self + 0x2F8);
    if (f & 0x10) {
        t = *(s32 *)(self + 0x2E0);
        *(u32 *)(self + 0x2F8) = (f & ~0x10) | 8;
        func_L39_0061ECE0(self + 0x20, self + 0x290, t);
        if (D_L39_0033AB08[*(s16 *)(self + 0x2FC)].f0 != 0) {
            D_L39_0033AB08[*(s16 *)(self + 0x2FC)].f0(a);
        }
        *(V_0066A490 *)(a + 0x10) = *(V_0066A490 *)(self + 0x290);
        *(V_0066A490 *)(a + 0xF0) = *(V_0066A490 *)(self + 0x2A0);
        *(V_0066A490 *)(self + 0x1F0) = *(V_0066A490 *)(a + 0x10);
        *(V_0066A490 *)(self + 0x200) = *(V_0066A490 *)(a + 0xF0);
    }
    if (D_L39_0033AB08[*(s16 *)(self + 0x2FC)].f8 != 0) {
        (D_L39_0033AB08 + *(s16 *)(self + 0x2FC))->f8(a);
    }
}
/* localdecomp:end func_L39_0066A490 */

#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_003BBA80 */
void func_L01_004AA7E8(s32, s32);
void func_L02_003BBA80(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(s32 *)((u8 *)arg0 + 0x98) = 0;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41) & 0xEFFF);
        func_L01_004AA7E8((s32) arg0, 1);
    }
}
/* localdecomp:end func_L02_003BBA80 */

/* localdecomp:start func_L02_003BBAC0 */
typedef struct { s32 f0, f4, f8, fC, f10, f14, f18; } T_3BBAC0;
typedef struct { u8 pad0[0x20]; u8 state; u8 pad21[0xF]; u8 f30; u8 pad31[0x37]; T_3BBAC0 *p; } S_3BBAC0;
extern u8 D_001A4C60[];
s32 func_00382380(void *, s32, s32);
void func_L01_0045F1E8(s32, s32);
void func_L01_004450F0(void *, s32, s32);
void func_L02_003BBAC0(S_3BBAC0 *a) {
    T_3BBAC0 *p = a->p;
    switch (a->state) {
    case 0:
        a->f30 = 0xFF;
        func_L01_004450F0(a, 1, -1);
        break;
    case 1:
        if (func_00382380(D_001A4C60, p->f4, 0)) {
            func_L01_0045F1E8(p->f14, -1);
            func_L01_004450F0(a, 2, -1);
        } else if (func_00382380(D_001A4C60, p->f8, 0)) {
            func_L01_0045F1E8(p->f18, -1);
            func_L01_004450F0(a, 3, -1);
        }
        break;
    case 2:
        if (func_00382380(D_001A4C60, p->f0, 0) || func_00382380(D_001A4C60, p->fC, 0)) {
            func_L01_0045F1E8(p->f10, -1);
            func_L01_004450F0(a, 1, -1);
        } else if (func_00382380(D_001A4C60, p->f8, 0)) {
            func_L01_0045F1E8(p->f18, -1);
            func_L01_004450F0(a, 3, -1);
        }
        break;
    case 3:
        if (func_00382380(D_001A4C60, p->f0, 0) || func_00382380(D_001A4C60, p->fC, 0)) {
            func_L01_0045F1E8(p->f10, -1);
            func_L01_004450F0(a, 1, -1);
        }
        if (func_00382380(D_001A4C60, p->f4, 0)) {
            func_L01_0045F1E8(p->f14, -1);
            func_L01_004450F0(a, 2, -1);
        }
        break;
    }
}
/* localdecomp:end func_L02_003BBAC0 */

/* localdecomp:start func_L02_003BBC98 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L02_001D66B0[2];
extern f32 D_L02_001DDFB0;
extern f32 D_L02_001DDFB4;
__asm__(".extern D_L02_001DDFB0, 4");
__asm__(".extern D_L02_001DDFB4, 4");
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_003E2E38(void *, void *, void *, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L02_003BBC98(u8 *self) {
    vu0_v4 a, b;
    f32 inv;

    if (func_L01_00447490(self, -1, 0) == 0) return;
    func_003A52A0(0, 0, self);
    func_L01_00451FE0(self, 0x1F, D_L02_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                      3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    func_L01_00452460(self, 0x1EA2, 0);
    inv = 1.0f / *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    *(u128_t *)&a = 0;
    func_0038CE20(&a, &a, inv);
    *(u128_t *)&b = 0;
    b.z = 0.14000002f;
    func_L02_003E2E38(self, &a, &b, 0x14, 0, 0, 0.1f, 0.18f, D_L02_001DDFB4 * inv * *(f32 *)(self + 0x2C), 20.0f, 1.0f);
    func_0038CE20(&a, &a, *(f32 *)(self + 0x2C));
    func_0038D000(&a, &a, self + 0xC0);
    vec_add_ab(&a, &a, self + 0x10);
    func_L01_003303B8((u8 *)&a, 0, 0, 0, 0, 2, 5, 0, D_L02_001DDFB0 * inv * *(f32 *)(self + 0x2C), 0.0f, 0.0f, 0.0f,
                      0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
    func_L01_00451E78(self, 1, 0.0f);
    func_003C2880(self);
}
/* localdecomp:end func_L02_003BBC98 */

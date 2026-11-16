#include "common.h"

/* NTSC-U counterpart of func_L24_003B7DE8 (src/levels/24_insomniac_museum/L24_003B7820.c) */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
struct M_003B7DE8;
extern void func_L24_003B61F0(struct M_003B7DE8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

/* localdecomp:start func_L24_003B61F0 */
typedef struct P_003B7DE8 {
    u8 pad0[0x70];
    f32 f70, f74, f78, f7C, f80;
    u8 pad84[0x18];
    f32 f9C, fA0;
    u8 padA4[0x898];
    s32 f93C;
    u8 pad940[0x20];
    f32 f960;
} P_003B7DE8;
typedef struct O_003B7DE8 {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x30];
    u16 f44;
} O_003B7DE8;
typedef struct M_003B7DE8 {
    u8 pad0[0x10];
    u128_t f10;
    u8 pad20[4];
    O_003B7DE8 *f24;
    u8 pad28[0xC];
    u16 f34;
    u8 pad36[0xD];
    u8 f43;
    u8 pad44[0x24];
    P_003B7DE8 *f68;
    u8 pad6C[0x2C];
    s32 f98;
} M_003B7DE8;
extern s32 D_L24_001DD5C4_003B61F0;
__asm__(".extern D_L24_001DD5C4_003B61F0, 16");
extern f32 D_L24_001DD5C0_003B61F0;
__asm__(".extern D_L24_001DD5C0_003B61F0, 16");
extern f32 D_L24_001DD5BC;
__asm__(".extern D_L24_001DD5BC, 16");
extern void func_L01_00458A70(void *, f32, f32, f32, f32);

void func_L24_003B61F0(M_003B7DE8 *a0) {
    O_003B7DE8 *obj;
    P_003B7DE8 *p;

    a0->f34 &= ~0x41;
    obj = a0->f24;
    p = a0->f68;
    a0->f34 |= obj->f44 & 0x1000;
    a0->f98 = obj->f10;
    p->f70 = 0.5f;
    p->f74 = 0.1f;
    p->f78 = 0.5f;
    p->f7C = 1.0f;
    p->f80 = 0.785398185f;
    p->fA0 = 0.34906584f;
    p->f9C = 0.0027222224f;
    p->f93C = D_L24_001DD5C4_003B61F0;
    p->f960 = D_L24_001DD5C0_003B61F0;
    *(u128_t *)((u8 *)p + 0x300) = a0->f10;
    func_L01_00458A70(a0, D_L24_001DD5BC, D_L24_001DD5BC, 0.41887906f, 0.41887906f);
    if (a0->f43 != 0) func_003BE4F0(a0, 0, 0, 4);
    func_L01_00441FB8(a0, 1, -1);
}
/* localdecomp:end func_L24_003B61F0 */

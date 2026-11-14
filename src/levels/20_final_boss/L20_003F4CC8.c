#include "common.h"

/* localdecomp:start func_L20_003F4CC8 */
#include "vu0.h"
extern s32 D_L20_001DEBF0;
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_00456250(void *);
extern void func_0038CF68(void *, void *, f32);
void func_L20_003F4CC8(u8 *self) {
    s32 *p;
    u8 *q;
    vu0_v4 d;
    p = *(s32 **)(self + 0x68);
    if (*p != 0 && self[0x20] == 0) {
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & ~0x1000;
        *(s32 *)(self + 0x98) = 0;
        func_L01_004AA7E8(self, 1);
        self[0x20] = 1;
    }
    if (self[0x20] == 1 && D_L20_001DEBF0 != 0) {
        q = *(u8 **)(self + 0x24);
        *(u16 *)(self + 0x34) &= ~0x41;
        *(u16 *)(self + 0x34) |= *(u16 *)(q + 0x44) & 0x1000;
        *(s32 *)(self + 0x98) = *(s32 *)(q + 0x10);
        *p = 0;
        self[0x20] = 0;
    }
    if (func_L01_00456250(self) != 0) {
        self[0x20] = 2;
    }
    if (self[0x20] == 2) {
        func_0038CF68(&d, self + 0xC0, -0.16000001f);
        vec_add_ba(self + 0x10, &d, self + 0x10);
        if (++*(u16 *)(self + 0x96) > 50) {
            self[0x20] = 3;
        }
    }
    if (self[0x20] == 3 && D_L20_001DEBF0 != 0) {
        self[0x20] = 4;
    }
    if (self[0x20] == 4) {
        func_0038CF68(&d, self + 0xC0, 0.16000001f);
        vec_add_ba(self + 0x10, &d, self + 0x10);
        if (--*(u16 *)(self + 0x96) == 0) {
            self[0x20] = 5;
        }
    }
}
/* localdecomp:end func_L20_003F4CC8 */

INCLUDE_ASM("asm/levels", func_L20_003F4E60);

/* localdecomp:start func_L20_003F51F8 */
#include "vu0.h"
typedef int u128_003F51F8 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x30]; u128_003F51F8 v; u8 pad1[0x40]; } A_003F51F8;
typedef struct { u8 pad0[0x10]; u128_003F51F8 pos; u8 pad1[0xB0]; u8 xD0[0x30]; } M_003F51F8;
extern A_003F51F8 *D_L20_001E0380;
__asm__(".extern D_L20_001E0380, 16");
extern M_003F51F8 *D_L20_001E029C;
__asm__(".extern D_L20_001E029C, 16");
extern void func_0038CF68(void *, void *, f32);
void func_L20_003F51F8(u8 *self, vu0_v4 *out) {
    s32 *p;
    vu0_v4 off;
    p = *(s32 **)(self + 0x68);
    if (p[1] == -1) {
        *(u128_003F51F8 *)out = D_L20_001E0380[p[0]].v;
    } else {
        *(u128_003F51F8 *)out = D_L20_001E029C[p[1]].pos;
        func_0038CF68(&off, D_L20_001E029C[p[1]].xD0, 5.0f);
        vec_add_ab(out, out, &off);
    }
}
/* localdecomp:end func_L20_003F51F8 */

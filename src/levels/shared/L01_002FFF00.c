#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_002FFF00 */
extern u8 *D_L01_001DAFEC;
__asm__(".extern D_L01_001DAFEC, 16");
extern f32 D_L01_001DFB50[];
extern void func_L01_002FFFF0(u8 *, u8 *);
extern s32 func_L01_003F7EE8(void *);
extern s32 func_00382468(s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);

void func_L01_002FFF00(u8 *self) {
    if (D_L01_001DAFEC != 0)
        func_L01_002FFFF0(self, D_L01_001DAFEC);
    switch (self[0x20]) {
    case 0:
        if (func_L01_003F7EE8(self) != 0 || (D_L01_001DFB50[0] > 0.95f && func_00382468(10) == 0)) {
            func_L01_004450F0(self, 1, -1);
            *(u16 *)(self + 0x34) |= 0x2800;
        }
        break;
    case 1:
        func_L01_003F7EE8(self);
        if (self[0x23] < 2)
            func_003C2880(self);
        else
            self[0x23] -= 2;
        break;
    }
}
/* localdecomp:end func_L01_002FFF00 */

LINKER_REMNANT("asm/levels", func_L01_002FFFE8);

/* localdecomp:start func_L01_002FFFF0 */
extern u8 *func_003C4D58(u8 *);
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D5F0(void *, void *, void *);
void func_L01_002FFFF0(u8 *a, u8 *b) {
    u8 m0[64];
    u8 m1[64];
    u8 m2[64];
    u8 *r;
    r = func_003C4D58(b);
    if (r != 0) {
        func_0038D328(m0, r);
        vec_add_ba(a + 16, a + 16, r + 16);
        vec_sub_ab(a + 16, a + 16, b + 16);
        if (*(s32 *)(r + 60) & 2) {
            func_0038D328(m2, r + 32);
            func_0038D5B0(m1, m2);
            func_0038D000(a + 16, a + 16, m1);
            func_0038D000(a + 16, a + 16, b + 192);
        } else {
            func_0038D000(a + 16, a + 16, m0);
        }
        vec_add_ba(a + 16, a + 16, b + 16);
        func_0038D5F0(a + 192, m0, a + 192);
    }
}
/* localdecomp:end func_L01_002FFFF0 */

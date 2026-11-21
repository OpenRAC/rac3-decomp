#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_00305880 */
#include "vu0.h"
typedef struct { u8 b[0xF0]; } RecF0_00305880;
typedef struct { s32 v[2]; } Pair_00305880;
extern u8 D_001425C0[];
extern RecF0_00305880 D_L01_002C5600[];
extern Pair_00305880 D_L01_001DC5D0 __attribute__((section(".data")));
extern s32 D_L01_001DC5D8;
__asm__(".extern D_L01_001DC5D8, 4");
extern void *func_L01_00472F58(void *, void *, f32, s32);

void func_L01_00305880(void *self, void *pos) {
    u8 *v = *(u8 **)((u8 *)self + 0x68);
    Vec4 vel;
    Pair_00305880 tbl;
    qzero(&vel);
    tbl = D_L01_001DC5D0;
    if ((D_L01_002C5600 + D_001425C0[0x11])->b[1] >= 4) {
        func_L01_00472F58(pos, &vel, *(f32 *)(v + 0x50) * 0.25f * 0.1f, 0x48);
    } else {
        func_L01_00472F58(pos, &vel, *(f32 *)(v + 0x50) * 0.25f * 0.1f, tbl.v[D_L01_001DC5D8 % 2]);
    }
    D_L01_001DC5D8++;
}
/* localdecomp:end func_L01_00305880 */

INCLUDE_ASM("asm/levels", func_L01_00305970);

INCLUDE_ASM("asm/levels", func_L01_00305AB8);

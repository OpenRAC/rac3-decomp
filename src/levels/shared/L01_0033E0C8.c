#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    f32 f18;
} S_33BDC8;
typedef void (*Fn_33CA98)(u8 *);


INCLUDE_ASM("asm/levels", func_L01_0033E0C8);

/* localdecomp:start func_L01_0033E290 */
void func_L01_0033E290(vu0_v4 *a0, s32 a1) {
    vu0_v4 t;

    vec_sub_ab(&t, &a0[a1 - 2], &a0[a1 - 3]);
    vec_add_ab(&a0[a1 - 1], &a0[a1 - 2], &t);
}
/* localdecomp:end func_L01_0033E290 */

INCLUDE_ASM("asm/levels", func_L01_0033E2D0);

LINKER_REMNANT("asm/levels", func_L01_0033E758);

INCLUDE_ASM("asm/levels", func_L01_0033E760);

LINKER_REMNANT("asm/levels", func_L01_0033ED28);

INCLUDE_ASM("asm/levels", func_L01_0033ED30);

/* localdecomp:start func_L01_0033EE50 */
#include "vu0.h"

typedef struct {
    vu0_v4 v;
    u8 *owner;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    s32 w1C;
    s32 w20;
} S_33EE50_0033EE50;

extern s32 D_L01_001DFB40_0033EE50;
extern s32 D_001A71A0[];
extern f32 D_L01_001DD020_0033EE50;
__asm__(".extern D_L01_001DD020_0033EE50, 4");
extern u8 *D_L01_001E0028_0033EE50;
__asm__(".extern D_L01_001E0028_0033EE50, 4");
extern s32 func_003D4D00(void *, s32, f32, s32, S_33EE50_0033EE50 *);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_002F8F10_0033EE50(u8 *, u8 *);

void func_L01_0033EE50(u8 *a0) {
    S_33EE50_0033EE50 s;
    u8 *m;

    if (!(D_L01_001DFB40_0033EE50 & 1)) return;
    qzero(&s.v);
    s.flags = 0x10000;
    s.b18 = 8;
    s.h1A = *(u16 *)(a0 + 0xAA);
    s.v.w = 5627.9248f;
    s.owner = a0;
    s.b19 = 0;
    s.w1C = 0;
    s.w20 = 0;
    func_003D4D00(a0 + 0x10, 0, D_L01_001DD020_0033EE50, D_001A71A0[0], &s);
    if (!(D_L01_001DFB40_0033EE50 & 1)) return;
    for (m = D_L01_001E0028_0033EE50; m != 0; m = *(u8 **)(m + 0x28)) {
        if (m[0x20] == 0xFE) return;
        if (m[0x20] == 0xFD) return;
        if (m != 0 && *(u8 **)(m + 0x24) != 0 && (*(u8 **)(m + 0x24))[0x46] == 0x13) {
            if (func_0038CF00(m + 0x10, a0 + 0x10) < D_L01_001DD020_0033EE50) {
                func_L01_002F8F10_0033EE50(m, a0);
            }
        }
    }
}
/* localdecomp:end func_L01_0033EE50 */

INCLUDE_ASM("asm/levels", func_L01_0033EF90);

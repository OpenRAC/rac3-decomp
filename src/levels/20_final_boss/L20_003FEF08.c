#include "common.h"

/* localdecomp:start func_L20_003FEF08 */
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
__asm__(".extern D_001DF650, 4");
__asm__(".extern D_001DF660, 4");
extern f32 D_001DF650;
extern f32 D_001DF660;

s32 func_L20_003FEF08(void *arg0) {
    s32 r = 0;
    void *s68 = *(void **)((u8 *)arg0 + 0x68);
    f32 d;

    d = func_0038CF38((u8 *)arg0 + 0x10, *(void **)((u8 *)s68 + 0x230) + 0x10);
    if (D_001DF650 < d) {
        void *p = *(void **)((u8 *)s68 + 0x230);
        f32 a = func_0038DBA0(*(f32 *)((u8 *)arg0 + 0xF8),
                              func_0038D160(*(f32 *)((u8 *)p + 0x10) - *(f32 *)((u8 *)arg0 + 0x10),
                                            *(f32 *)((u8 *)p + 0x14) - *(f32 *)((u8 *)arg0 + 0x14)));
        if (a < D_001DF660 * 0.017453292f) {
            r = 1;
        }
    }
    return r;
}
/* localdecomp:end func_L20_003FEF08 */

INCLUDE_ASM("asm/levels", func_L20_003FEFC0);

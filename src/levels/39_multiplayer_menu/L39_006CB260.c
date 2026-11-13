#include "common.h"

/* localdecomp:start func_L39_006CB260 */
typedef struct S2_006CB260 S2_006CB260;
typedef struct {
    char _p0[0xD8];
    void (*fD8)(S2_006CB260 *, f32, f32);
} S1_006CB260;
struct S2_006CB260 {
    char _p0[0x60];
    S1_006CB260 *f60;
};
typedef struct {
    char _p0[0x114];
    S2_006CB260 *f114;
    char _p1[0x2B4 - 0x118];
    f32 f2B4;
} S0_006CB260;
extern f32 D_001DE300_sda;
__asm__(".extern D_001DE300_sda, 4");
extern void func_L39_006CB348(void *);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_003C4138(f32 *, f32, f32);

s32 func_L39_006CB260(S0_006CB260 *o, s32 mode) {
    func_L39_006CB348(o);
    if (func_L39_0068AEF8(o, mode)) return 1;
    if (mode == 1) {
        func_003C4138(&o->f2B4, 0.0f, 0.03f);
        o->f114->f60->fD8(o->f114, 0.0f, o->f2B4);
        return 1;
    }
    if (mode == 2) {
        func_003C4138(&o->f2B4, D_001DE300_sda, 0.03f);
        o->f114->f60->fD8(o->f114, 0.0f, o->f2B4);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_006CB260 */

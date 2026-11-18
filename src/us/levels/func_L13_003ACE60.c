#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* declared by functions of L13_003ADA98.c, which this file was cut from */
extern void func_L13_004220E8(u8 *, s32, s32, s32);
extern void func_L13_003ACD60(void *);
extern void func_L13_003ACDE0(void *);

/* localdecomp:start func_L13_003ACE60 */
#include "vu0.h"
extern f32 D_L13_001DE70C, D_L13_001DE710, D_L13_001DE71C;
__asm__(".extern D_L13_001DE70C, 4");
__asm__(".extern D_L13_001DE710, 4");
__asm__(".extern D_L13_001DE71C, 4");
extern void func_L13_0042C000(void *, void *, void *, f32, f32, f32);

void func_L13_003ACE60(u8 *obj) {
    f32 *o = (f32 *)obj;
    u8 *d = *(u8 **)(obj + 0x68);
    f32 k;

    func_L13_0042C000(obj, d + 0x3B0, d + 0x3B4, D_L13_001DE70C, D_L13_001DE710 * 0.017453292f * 0.0166666675f, -1.0f);
    qzero(d + 0x1F0);
    k = 1.0f - D_L13_001DE71C;
    *(s32 *)(d + 0x204) = 0;
    o[0xF0 / 4] *= k;
    o[0xF4 / 4] *= k;
}
/* localdecomp:end func_L13_003ACE60 */

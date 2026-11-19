#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* declared by functions of L13_003ADA98.c, which this file was cut from */
extern void func_L13_004220E8(u8 *, s32, s32, s32);
extern void func_L13_003ACD60(void *);
extern void func_L13_003ACDE0(void *);

/* localdecomp:start func_L13_003ACDE0 */
extern f32 D_L13_001DE6B4;
__asm__(".extern D_L13_001DE6B4, 4");
extern f32 D_L13_001DE6B8;
__asm__(".extern D_L13_001DE6B8, 4");
extern f32 D_L13_001DE6BC;
__asm__(".extern D_L13_001DE6BC, 4");
extern void func_L13_003AD260(u8 *, f32, f32, f32);
extern void func_L13_004220E8(u8 *, s32, s32, s32);

void func_L13_003ACDE0(void *arg) {
    u8 *obj = arg;
    func_L13_003AD260(*(u8 **)(obj + 0x68) + 0x150, D_L13_001DE6B4 * 0.0166666675f, D_L13_001DE6B8 * 0.000277777785f, D_L13_001DE6BC * 0.000277777785f);
    if (obj[0x43] != 3) {
        func_L13_004220E8(obj, 3, 0, 10);
    }
}
/* localdecomp:end func_L13_003ACDE0 */

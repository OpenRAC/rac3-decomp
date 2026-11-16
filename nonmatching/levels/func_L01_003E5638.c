/* PAL near miss (Codex wave 6): near miss: 29 words differ with the file's flags.
 * Worker's note: 29 diffs; fixed VU0 blocks do not share final store; context correction required: existing void func_L01_003E5638 declaration must return s32. Retail switch decoded in func_L01_003E5638.table.log; wrapper log retained
 */
#include "common.h"
/* localdecomp:start func_L01_003E5638 */
typedef struct { f32 f[4]; } __attribute__((aligned(16))) Vec_003E5638;
static __inline__ void add_003E5638(Vec_003E5638 *d, Vec_003E5638 *a, Vec_003E5638 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
s32 func_L01_003E5638(u8 *obj, s32 src, void *dst, s32 mode) {
    extern void func_L01_003E4028(u8 *, u128_t *);
    Vec_003E5638 temp;
    Vec_003E5638 *base = (Vec_003E5638 *)(*(u8 **)(obj+0x70)+0x60);
    s32 result = 1;
    switch (mode) {
    case 6: case 7:
        add_003E5638(dst, (Vec_003E5638 *)src, base);
        result = 0;
        break;
    case 3: case 4: case 5:
        add_003E5638(dst, (Vec_003E5638 *)src, base);
        result = 0;
        break;
    case 1:
        func_L01_003E4028(obj, (u128_t *)&temp);
        add_003E5638(dst, (Vec_003E5638 *)src, &temp);
        break;
    case 2:
    default:
        add_003E5638(dst, (Vec_003E5638 *)src, base);
        break;
    }
    return result;
}
/* localdecomp:end func_L01_003E5638 */

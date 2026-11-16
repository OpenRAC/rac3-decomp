/* PAL near miss (Claude wave S/pal): near miss: 2 words differ with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: 2 diff with @ps2as (needed: file line L07_003CC2B0.c lacks it; 0.15f lui/ori/mtc1): retail has addiu v1,v1,-0x190c right after the lui, before sd s1 (mine puts sd s1 between); 4 source variants + -mno-split-addresses did not move it; C in ...
 */
#include "common.h"

/* localdecomp:start func_L07_003CD610 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 v[4]; u128_t pos; } L_003CD610;
extern S_003CD938 D_L07_001DE6F4[];
extern void func_L07_003BB2A8(f32 *, f32 *, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_0045A7A8(void *, void *, f32);
extern void func_L07_003CEA60(void *);

void func_L07_003CD610(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    L_003CD610 l;
    f32 f;

    func_L07_003BB2A8(l.v, (f32 *)(s + 0x130), *(f32 *)(s + 0x410), D_L07_001DE6F4[s[0x404]].f0 - 0.5f);
    f = func_0038DB00(*(f32 *)(s + 0x414), *(f32 *)(s + 0x410));
    l.pos = *(u128_t *)(a0 + 0x10);
    func_L01_0045A7A8(a0, &l, f * 0.15f);
    func_L07_003CEA60(a0);
}
/* localdecomp:end func_L07_003CD610 */

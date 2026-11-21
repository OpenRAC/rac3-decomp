/* functional: high. none */
#include "common.h"
#include "structs/moby.h"
typedef int TI_003CD610 __attribute__((mode(TI)));
extern S_003CD938 D_L07_001DE6F4[] __attribute__((section(".sdata")));
extern void func_L07_003BB2A8(f32 *, f32 *, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern s32 func_L01_0045A7A8(void *, f32 *, f32);
extern void func_L07_003CEA60(void *);

void func_L07_003CD610(struct Moby *m) {
    TI_003CD610 vectors[2];
    u8 *p = m->pvar;
    f32 angle;
    func_L07_003BB2A8((f32 *)vectors, (f32 *)(p + 0x130), *(f32 *)(p + 0x410), D_L07_001DE6F4[p[0x404]].f0 - 0.5f);
    angle = func_0038DB00(*(f32 *)(p + 0x414), *(f32 *)(p + 0x410)) * 0.15f;
    vectors[1] = *(TI_003CD610 *)&m->position;
    func_L01_0045A7A8(m, (f32 *)vectors, angle);
    func_L07_003CEA60(m);
}

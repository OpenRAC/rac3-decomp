/* functional: low. Near miss (183 word diffs); redeclares D_L01_001DFB40 against the file context. */
#include "common.h"
/* localdecomp:start func_L01_003D8780 */
typedef struct {
    u8 pad[0x20];
    f32 phase;
    s32 index, count;
    u8 pad2[4];
    u128_t position[8];
    u128_t rotation[8];
    u8 pad3[16];
    u8 output[1];
} Trail_003D8780;
extern s32 D_L01_001DFB40[] __attribute__((section(".data")));
extern s32 D_L01_001DF4BC, D_L01_001DF4B4, D_L01_001DF4B8;
__asm__(".extern D_L01_001DF4BC, 4");
__asm__(".extern D_L01_001DF4B4, 4");
__asm__(".extern D_L01_001DF4B8, 4");
extern f32 D_L01_001E23A0[][4] __attribute__((section(".sdata")));
extern f32 D_L01_001E23E0[][4] __attribute__((section(".sdata")));
void func_L01_003D8780(u8 *moby) {
    extern void func_003C3FC0(void *, void *);
    extern void func_L01_00408C98(void *, s32, void *, void *, s32, s32, s32, s32, s32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
    extern void func_L01_0035A218(f32 (*)[4], s32, s32, s32, s32, s32, f32, f32);
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    Trail_003D8780 *trail = *(Trail_003D8780 **)(moby + 0x68);
    f32 width, life;
    s32 i;
    f32 (*p)[4] = D_L01_001E23A0;
    trail->phase = (f32)(D_L01_001DFB40[0] % 8) * 0.125f;
    if (trail->phase == 0) {
        trail->index = (trail->index + 1) % 8;
        if (trail->count < 8) trail->count++;
    }
    func_003C3FC0(&trail->rotation[trail->index], moby + 0xF0);
    trail->position[trail->index] = *(u128_t *)(moby + 0x10);
    func_L01_00408C98(trail->output, 2, trail->position, trail->rotation, trail->index, trail->count,
                     D_L01_001DF4B4, D_L01_001DF4B8, D_L01_001DF4BC, trail->phase);
    width = func_003824E0(0.03f, 0.05f);
    life = func_003824E0(3.0f, 5.0f);
    func_003C2F58(moby, 0, a);
    func_003C2F58(moby, 3, b);
    func_003C2F58(moby, 6, c);
    for (i=0; i<4; i++, p++) {
        f32 spread = 0.175f;
        func_0038CDF8(*p, b, c, (f32)i * 0.25f);
        (*p)[0] += func_003824E0(-spread, 0.175f);
        (*p)[1] += func_003824E0(-spread, 0.175f);
        (*p)[2] += func_003824E0(-spread, 0.175f);
    }
    func_L01_0035A218(D_L01_001E23A0, 4, 0x4F, 0x7F7F7F, 0xFF8040, 0, width, life);
    p = D_L01_001E23E0;
    for (i=0; i<4; i++, p++) {
        f32 spread = 0.175f;
        func_0038CDF8(*p, b, a, (f32)i * 0.25f);
        (*p)[0] += func_003824E0(-spread, 0.175f);
        (*p)[1] += func_003824E0(-spread, 0.175f);
        (*p)[2] += func_003824E0(-spread, 0.175f);
    }
    func_L01_0035A218(D_L01_001E23E0, 4, 0x4F, 0x7F7F7F, 0xFF8040, 0, width, life);
}
/* localdecomp:end func_L01_003D8780 */

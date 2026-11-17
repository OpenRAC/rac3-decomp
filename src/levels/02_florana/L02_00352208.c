#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_00352208 */
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00408C98(void *, s32, void *, void *, s32, s32, s32, s32, f32, s32);

void func_L02_00352208(u8 *self) {
    u8 *m = *(u8 **)(self + 0x68);
    u8 *p = *(u8 **)(*(u8 **)(self + 0xB8) + 0x68);
    vu0_v4 v;

    vec_sub_ba(&v, m + 0x30, self + 0x10);
    v.z = 0.0f;
    func_0038CF68(&v, &v, 1.0f);
    func_0038CF68(&v, &v, 1.5f);
    *(vu0_v4 *)(p + 0x700) = v;
    *(f32 *)(p + 0x70C) = 1.0f;
    vec_sub_ba(&v, m + 0x30, self + 0x10);
    v.z = 0.0f;
    func_0038CF68(&v, &v, 1.0f);
    func_0038CF68(&v, &v, -1.5f);
    *(vu0_v4 *)(p + 0x6F0) = v;
    *(f32 *)(p + 0x6FC) = 1.0f;
    func_L01_00408C98(p + 0x6F0, 0x10, p + 0x2F0, p + 0x4F0, *(s32 *)(p + 0x2E8), *(s32 *)(p + 0x2EC),
                      0x2096006B, 0x450030, *(f32 *)(p + 0x2E4), 5);
}
/* localdecomp:end func_L02_00352208 */

/* localdecomp:start func_L02_00352320 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_352320;
typedef struct { char pad0[0x2E4]; s32 f2E4; s32 f2E8; s32 f2EC; V4_352320 hist[16]; } P_352320;
typedef struct { char pad0[0x10]; V4_352320 v10; char pad20[0x98]; struct { char pad[0x68]; P_352320 *p68; } *fB8; } O_352320;
extern void func_003C3FC0(void *a, V4_352320 *b);
void func_L02_00352320(O_352320 *o) {
    P_352320 *p;
    V4_352320 z;
    p = *(P_352320 **)((char *)o->fB8 + 0x68);
    p->f2E4 = 0;
    p->f2E8 = (p->f2E8 + 1) % 16;
    if (p->f2EC < 16) p->f2EC++;
    z.x = 0; z.y = 0; z.z = 0; z.w = 0;
    func_003C3FC0((char *)p + 0x4F0 + p->f2E8 * 16, &z);
    *(V4_352320 *)((char *)p + 0x2F0 + p->f2E8 * 16) = o->v10;
}
/* localdecomp:end func_L02_00352320 */

/* localdecomp:start func_L02_003523D0 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L02_001D66B0[2];

void func_L02_003523D0(u8 *a0) {
    u8 *p = *(u8 **)(*(u8 **)(a0 + 0xB8) + 0x68);
    u128_t *src;
    s32 i;
    src = (u128_t *)D_L02_001D66B0;
    for (i = 0xF; i >= 0; i--) {
        *(u128_t *)(p + 0x2F0 + *(s32 *)(p + 0x2E8) * 16) = *src;
        *(s32 *)(p + 0x2E8) = 0;
        *(s32 *)(p + 0x2EC) = 0;
        *(s32 *)(p + 0x2E4) = 0;
    }
}
/* localdecomp:end func_L02_003523D0 */

INCLUDE_ASM("asm/levels", func_L02_00352418);

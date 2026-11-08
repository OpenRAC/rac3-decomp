#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_00352208);

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

INCLUDE_ASM("asm/levels", func_L02_003523D0);

INCLUDE_ASM("asm/levels", func_L02_00352418);

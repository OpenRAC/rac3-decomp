/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_00467A08, the NTSC-U twin of func_L01_0046B0B8, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 2 words differ with its file's flags.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00467A08 */
typedef struct Motion_467A08 {
    f32 x, y, z, w;
    f32 floor;
    u8 increment;
    u8 pad[3];
    f32 gravity;
} Motion_467A08;
typedef struct Particle_467A08 {
    u8 a, b, c, d;
    s32 color;
    u8 angle, unused;
    s16 life;
    f32 size;
    vu0_v4 pos;
    Motion_467A08 motion;
} Particle_467A08;
extern u8 *D_L01_002211E0[];
extern f32 D_001D7F34_sda;
__asm__(".extern D_001D7F34_sda, 4");
extern s32 func_003883C8(s16 *);
extern void func_003C7CE0(void *);

void func_L01_00467A08(Particle_467A08 *p) {
    Motion_467A08 *motion = &p->motion;
    if (func_003883C8(&p->life)) motion->z -= motion->gravity;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(p->pos) : "m"(p->pos), "m"(*(vu0_v4 *)motion) : "vf1", "vf2");
    p->angle += motion->increment;
    if (p->c == D_L01_002211E0[0][0]) {
        p->size += D_001D7F34_sda * 0.0166666675f * 210000.0f;
    }
    if (p->pos.z < motion->floor) func_003C7CE0(p);
}
/* localdecomp:end func_L01_00467A08 */

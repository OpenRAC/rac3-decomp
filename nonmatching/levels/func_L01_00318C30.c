/* PAL near miss (haiku-w2): 55 words differ with the file's flags; no divs_nops row for func_L01_00318C30 (retail has 2 nops before its div.s, config/levels/divs_nops.txt needs "func_L01_00318C30 2"). With those 2 nops inserted the residual is only their placement, so the C itself is believed to match once the row exists (not verified). */
#include "common.h"
/* localdecomp:start func_L01_00318C30 */
#include "vu0.h"
typedef struct {
    vu0_v4 position, velocity;
    u8 pad20[8];
    f32 step, angle;
    s32 base_size, size, unused, life, full_life;
    u8 *owner;
    u8 pad48[8];
} Particle_00318C30;
extern E_L01_00272780_00318408 D_L01_00272780[];
extern G_00318408 D_001A4BE0;
void func_L01_00318C30(u8 *moby)
{
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern s32 func_0038CAD0(void *);
    u8 *base = (u8 *)D_L01_00272780;
    s32 *life = (s32 *)(base + 0x3C);
    Particle_00318C30 *p = (Particle_00318C30 *)base;
    Particle_00318C30 *end = p + 64;
    s32 *vars = *(s32 **)(moby + 0x68);
    vu0_v4 v;
    do {
        if (p->owner == moby) {
            p->size = (s32)((f32)p->base_size * ((f32)p->life / (f32)p->full_life));
            p->angle = func_0038DAB8(p->angle, p->step);
            vec_add_ba(&p->position, &p->position, &p->velocity);
            func_L01_004C7D98((u8 *)D_001A4BE0.x25C0 + 0x10, &v);
            func_0038CE20((f32 *)&v, (f32 *)&v, -0.0009f);
            vec_add_ba(&p->velocity, &p->velocity, &v);
            if (func_0038CAD0(life)) {
                if (p->size > 0) {
                    p->size--;
                } else {
                    p->owner = 0;
                    vars[0]--;
                }
            }
        }
        p++;
        life += 20;
    } while ((s32)p < (s32)end);
}
/* localdecomp:end func_L01_00318C30 */

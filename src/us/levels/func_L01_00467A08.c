#include "common.h"

/* NTSC-U counterpart of func_L01_0046B0B8 (src/levels/shared/L01_0046A938.c): 0.02 -> 0.0166667 */
#include "vu0.h"
typedef struct {
    f32 target;
    f32 base;
    s32 b;
    s32 a;
    f32 scale;
} Sub;
typedef struct {
    char pad0[0x4];
    s32 result;
    char pad8[0xA - 0x8];
    s16 timer;
    f32 out;
    char vec[0x20 - 0x10];
    Sub sub;
} Obj;
extern s32 func_003883C8(s16 *);
extern s32 func_003883C8(s16 *);

/* localdecomp:start func_L01_00467A08 */
typedef struct {
    f32 x, y, z, w;
    f32 floor;
    u8 increment;
    u8 pad[3];
    f32 gravity;
} Motion_46B0B8;
typedef struct {
    u8 a, b, c, d;
    s32 color;
    u8 angle, unused;
    s16 life;
    f32 size;
    vu0_v4 pos;
    Motion_46B0B8 motion;
} Particle_46B0B8;
extern u8 *D_L01_002211E0_00467A08[];
extern f32 D_L01_001D7F34_00467A08;
__asm__(".extern D_L01_001D7F34_00467A08, 4");
extern s32 func_003883C8(s16 *);

void func_L01_00467A08(Particle_46B0B8 *p)
{
    Motion_46B0B8 *motion = &p->motion;
    if (func_003883C8(&p->life)) {
        motion->z -= motion->gravity;
    }
    vec_add_ab(&p->pos, &p->pos, motion);
    p->angle += motion->increment;
    if (p->c == D_L01_002211E0_00467A08[0][0]) {
        p->size += D_L01_001D7F34_00467A08 * 0.0166666675f * 210000.0f;
    }
    if (p->pos.z < motion->floor) {
        func_003C7CE0((Obj *)p);
    }
}
/* localdecomp:end func_L01_00467A08 */

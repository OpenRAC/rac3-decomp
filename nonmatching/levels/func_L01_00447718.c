#include "common.h"

/* localdecomp:start func_L01_00447718 */
#include "vu0.h"

typedef struct {
    vu0_v4 velocity;
    u8 *source;
    s32 flags;
    u8 type, mode;
    u16 id;
    f32 damage;
    s32 flags2;
    s32 unused;
    s32 extra;
} Hit_00447718;

void func_L01_00447718(u8 *source, vu0_v4 *position, u8 **objects, s32 count, u8 *ignore,
                       s32 flags, s32 type, s32 mode, s32 extra, f32 damage, f32 speed, f32 z)
{
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_00446978(u8 *, Hit_00447718 *);
    vu0_v4 pos;
    Hit_00447718 hit;
    f32 angle;
    vu0_v4 *posp = &pos;

    *(vu0_q *)&pos = *(vu0_q *)position;
    if (count > 0) {
        u8 **list = objects;
        s32 n = count;

        do {
            if (*list != ignore) {
                hit.source = source;
                hit.id = *(u16 *)(source + 0xAA);
                hit.flags = flags;
                hit.damage = damage;
                hit.flags2 = flags;
                hit.type = type;
                hit.mode = mode;
                hit.extra = extra;
                angle = func_0038D160(*(f32 *)(*list + 0x10) - posp->x,
                                      *(f32 *)(*list + 0x14) - posp->y);
                hit.velocity.x = func_0038D098(angle) * speed;
                hit.velocity.y = func_0038D0B0(angle) * speed;
                hit.velocity.z = z;
                hit.velocity.w = 5627.9248046875f;
                func_L01_00446978(*list, &hit);
            }
            n--;
            list++;
        } while (n != 0);
    }
}
/* localdecomp:end func_L01_00447718 */

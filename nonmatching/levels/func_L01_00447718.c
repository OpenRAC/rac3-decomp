/* PAL near miss (Codex wave 8): near miss: 50 words differ with the file's flags.
 * Worker's note: Best wrapper log w431/func_L01_00447718.02.log: 49 diff with sq_ra injection; loop body matches, but fixed -fopt-stack emits 8-byte saves versus retail 16-byte sq/lq frame; sq_ra alone cannot resize frame. No alternate flags tested.
 */
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
void func_L01_00447718(u8 *source, vu0_v4 *position, u8 **objects, s32 count, u8 *ignore, s32 flags, s32 type, s32 mode, s32 extra, f32 damage, f32 speed, f32 z)
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
    if (count > 0) do {
        if (*objects != ignore) {
            hit.source = source;
            hit.id = *(u16 *)(source + 0xAA);
            hit.flags = flags;
            hit.damage = damage;
            hit.flags2 = flags;
            hit.type = type;
            hit.mode = mode;
            hit.extra = extra;
            angle = func_0038D160(*(f32 *)(*objects + 0x10) - posp->x, *(f32 *)(*objects + 0x14) - posp->y);
            hit.velocity.x = func_0038D098(angle) * speed;
            hit.velocity.y = func_0038D0B0(angle) * speed;
            hit.velocity.z = z;
            hit.velocity.w = 5627.9248046875f;
            func_L01_00446978(*objects, &hit);
        }
        count--;
        objects++;
    } while (count != 0);
}
/* localdecomp:end func_L01_00447718 */

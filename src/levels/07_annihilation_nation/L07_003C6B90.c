#include "common.h"

/* localdecomp:start func_L07_003C6B90 */
#include "vu0.h"
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; u8 *vars; u8 p6C[0x8C]; f32 angle; } Moby_003C6B90;
extern vu0_v4 D_L07_001E8C40;
s32 func_L07_003C6B90(Moby_003C6B90 *m)
{
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_003C3D30(void *, s32, s32, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    vu0_v4 pos, offset, normal;
    u8 *vars = m->vars;
    f32 height, second, angle;
    pos = m->pos;
    offset.x = func_0038D098(m->angle);
    offset.y = func_0038D0B0(m->angle);
    offset.z = 0.0f;
    vec_add_ab(&pos, &pos, &offset);
    height = func_003C3D30(&pos, 0x22, 0, 0.5f);
    if (height < m->pos.z && fabs_asm(height - m->pos.z) > *(f32 *)(vars + 0x3C)) {
        offset.x = func_0038D098(m->angle) * 9.0f;
        offset.y = func_0038D0B0(m->angle) * 9.0f;
        offset.z = 0.0f;
        vec_add_ba(&pos, &m->pos, &offset);
        *(vu0_v4 *)(vars + 0x160) = pos;
        height = func_003C3D30(&pos, 0x22, 0, 6.0f);
        normal = D_L07_001E8C40;
        second = m->pos.z - 2.0f;
        angle = func_0038CED8(&normal);
        angle = func_0038D160(normal.z, angle);
        if (second < height && angle < 0.1745329201221466f) {
            *(f32 *)(vars + 0x1CC) = height;
            return 1;
        }
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L07_003C6B90 */

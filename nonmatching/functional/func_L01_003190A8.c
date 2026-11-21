/* functional: high. 14 words differ (packet setup scheduling/store order/constant register); all stores, args, offsets and call order verified vs retail. */
/* PAL near miss (Codex wave 8): near miss: 14 words differ with the file's flags.
 * Worker's note: 14/108 words differ, only integer packet setup scheduling/constant register/store order; three formulations same residual; best build/codex/w433/func_L01_003190A8.attempt07.log
 */
#include "common.h"
/* localdecomp:start func_L01_003190A8 */
#include "vu0.h"
typedef struct {
    f32 v[4][4];
    u32 color[4];
    f32 uv[4][2];
    unsigned long f70, f78, f80, f88;
} Draw_003190A8;
extern u8 D_L01_001E2880[];
void func_L01_003190A8(vu0_v4 *pos, u32 color, s32 alpha, s32 texture, s32 mode, f32 scale, f32 roll, f32 distance) {
    extern void func_L01_00318FB8(u8 *);
    extern unsigned long func_00389598(s32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CF38(void *, void *);
    extern void func_0038D328(void *, void *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_L01_00319040(f32 *, f32);
    extern void func_003D2DA0(void *, void *, s32);
    Draw_003190A8 d;
    vu0_v4 m[4];
    vu0_v4 angles;
    vu0_v4 delta;
    unsigned long tex;
    unsigned long drawmode;
    u8 *g;
    f32 dx, dy;
    func_L01_00318FB8((u8 *)&d);
    tex = func_00389598(texture);
    g = D_L01_001E2880;
    dx = *(f32 *)(g + 0x140) - pos->x;
    dy = *(f32 *)(g + 0x144) - pos->y;
    drawmode = 0x8000000040 | ((unsigned long)mode << 2);
    color += alpha << 24;
    d.f80 = 0xFF9000000260;
    d.f88 = drawmode;
    d.color[0] = color;
    d.color[1] = color;
    d.color[2] = color;
    d.color[3] = color;
    d.f78 = tex;
    d.f70 = 0;
    angles.w = 0;
    angles.z = func_0038D160(dx, dy);
    angles.y = -func_0038D160(func_0038CF38(pos, g + 0x140), *(f32 *)(g + 0x148) - pos->z);
    angles.x = roll;
    func_0038D328(m, &angles);
    vec_sub_ab(&delta, g + 0x140, pos);
    func_0038CF68(&delta.x, &delta.x, distance);
    m[3].x = pos->x + delta.x;
    m[3].y = pos->y + delta.y;
    m[3].z = pos->z + delta.z;
    m[3].w = 1.0f;
    func_L01_00319040((f32 *)&d, scale);
    func_003D2DA0(&d, m, 0);
}
/* localdecomp:end func_L01_003190A8 */

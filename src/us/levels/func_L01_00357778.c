#include "common.h"

/* NTSC-U counterpart of func_L01_00358338 (src/levels/shared/L01_00356C88.c) */
#include "vu0.h"

/* localdecomp:start func_L01_00357778 */
typedef int Q_358338 __attribute__((mode(TI)));
typedef union { f32 f[4]; Q_358338 q; } V_358338;
typedef union { u8 b[0x2600]; s16 h[0x1300]; u16 uh[0x1300]; s32 i[0x980]; f32 f[0x980]; void *p[0x980]; Q_358338 q[0x260]; } O_358338;
typedef union { V_358338 v[5]; u8 b[0x50]; } Hit_358338;
extern O_358338 D_001A4BE0;
extern s32 D_L01_001D673C_00357778;
extern s32 D_L01_001D6740_00357778;
extern s32 D_L01_001D6694_00357778;
extern s32 D_L01_001DD6C0;
extern O_358338 *D_L01_001E1AA0_00357778;
extern void func_003BD9A0(void *, s32, void *);
extern void func_003C1A90(void *);
extern void func_003C26C8(void *);
extern void func_L01_004C41E8(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388800(void *, void *);
extern void func_00388BD0(void *, void *);
extern void func_003C2868(void *);
extern s32 func_L01_0050DA08(s32);
extern s32 func_00388398(s32 *);

void func_L01_00357778(O_358338 *owner, O_358338 *m, s32 kind, V_358338 *pos, s32 count, O_358338 *other) {
    V_358338 newpos;
    Hit_358338 hit;
    V_358338 up, side, dir;
    O_358338 *vars;
    f32 yaw, angle, weight;
    newpos.q = pos->q;
    vars = other->p[0x68/4];
    func_003BD9A0(owner, kind, &hit);
    hit.v[4].q = m->q[1];
    m->q[1] = newpos.q;
    func_003C1A90(m);
    if (!(m->uh[0x34/2] & 4)) func_003C26C8(m);
    if (D_L01_001D673C_00357778 || D_L01_001D6740_00357778 || D_001A4BE0.h[0x368/2]) {
        func_L01_004C41E8(&m->q[1], &up);
        vec_sub_ba(&dir, &m->q[1], &hit.v[3]);
        func_00388830(&dir, &dir, 1.0f);
        func_00388758(&side, &dir, &up);
        func_00388830(&side, &side, 1.0f);
        func_00388758(&up, &side, &dir);
        func_00388830(&up, &up, 1.0f);
        m->q[0xC0/16] = dir.q;
        m->q[0xD0/16] = side.q;
        m->q[0xE0/16] = up.q;
    } else {
        yaw = func_00389380(func_00388A28(hit.v[3].f[0] - m->f[0x10/4], hit.v[3].f[1] - m->f[0x14/4]), 3.1415927f);
        if (D_001A4BE0.i[0x25C4/4] == 19) {
            weight = 2 / count;
            vec_sub_ab(&up, &D_L01_001E1AA0_00357778->q[1], &vars->q[0]);
            angle = func_00388A28(up.f[0], up.f[1]);
            if (count < 5) angle *= weight * 2.0f;
            else if (count > 5) angle = 0.0f;
            yaw = func_00389380(angle, yaw);
        }
        m->f[0xF8/4] = yaw;
        m->f[0xF4/4] = func_00388A28(func_00388800(&m->q[1], &hit.v[3]), hit.v[3].f[2] - m->f[0x18/4]);
        if (D_001A4BE0.i[0x25C4/4] == 19) m->i[0xF4/4] = 0;
        m->f[0xF0/4] = 1.5707964f;
        if (D_001A4BE0.i[0x25C4/4] == 19) m->i[0xF0/4] = 0;
        func_00388BD0(&m->q[0xC0/16], &m->f[0xF0/4]);
    }
    func_003C2868(m);
    if ((owner && (owner->uh[0x34/2] & 1)) || D_001A4BE0.b[0x25ED] || D_001A4BE0.i[0x25C4/4] == 29 || D_001A4BE0.i[0x16B0/4] == 2 || D_L01_001D6694_00357778 || D_001A4BE0.i[0x25C4/4] == 116) {
        m->uh[0x34/2] |= 0x41;
    } else if (func_L01_0050DA08(-1)) {
        m->uh[0x34/2] &= 0xFFBE;
    }
    if ((D_001A4BE0.i[0x16B0/4] || D_001A4BE0.i[0x25C4/4] == 29) && vars->i[0x20/4]) m->uh[0x34/2] &= 0xFFBE;
    if (!func_L01_0050DA08(-1) && !vars->i[0x20/4]) {
        if (func_00388398(&vars->i[0x30/4])) m->uh[0x34/2] |= 0x41;
    } else vars->i[0x30/4] = D_L01_001DD6C0;
    m->uh[0x34/2] |= 6;
}
/* localdecomp:end func_L01_00357778 */

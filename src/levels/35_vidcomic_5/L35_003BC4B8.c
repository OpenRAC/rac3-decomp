#include "common.h"

typedef struct {
    u8 pad0[0x84];
    s32 f84;
} S_Sub_003BC958;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x47];
    S_Sub_003BC958 *f68;
} S_Obj_003BC958;
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x44];
    s32 f6C;
    s16 f70;
    u8 pad2[4];
    s16 f76;
    u8 pad3[0x1C];
    s32 f94;
    s16 f98;
    u8 pad4[4];
    s16 f9E;
} S_1CCFD0_003BC958;

/* localdecomp:start func_L35_003BC4B8 */
#include "vu0.h"
typedef struct {
    vu0_v4 v0;
    f32 f10;
    f32 f14;
    f32 f18;
    u8 pad1C[4];
    s32 w20;
    u8 pad24[4];
    f32 f28;
} P_003BC4B8;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 b20;
    u8 pad21[3];
    u8 *p24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0x38];
    P_003BC4B8 *p68;
    u8 pad6C[0xF0 - 0x6C];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} M_003BC4B8;
typedef struct {
    u8 pad0[0x14];
    s32 flags;
    u8 pad18[0x18];
} B_003BC4B8;
extern f32 D_L35_001DEE90;
__asm__(".extern D_L35_001DEE90, 4");
extern f32 D_L35_001DEE94;
__asm__(".extern D_L35_001DEE94, 4");
extern vu0_v4 D_L35_001E92E0;
extern u8 D_L35_001D66B0[8];
extern u8 *D_L35_0021F258[];
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L30_0034CC28(void *, void *, void *, s32, s32, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_003C2880(void *);

void func_L35_003BC4B8(u8 *arg) {
    M_003BC4B8 *m = (M_003BC4B8 *)arg;
    s32 st = m->b20;
    P_003BC4B8 *p = m->p68;
    vu0_v4 v10;
    vu0_v4 d;
    B_003BC4B8 buf;
    s32 i;
    u8 *e;

    switch (st) {
    case 0:
        m->fF0 += p->f10;
        m->fF4 += p->f14;
        m->fF8 += p->f18;
        qzero(&d);
        d.z = p->f28;
        vec_add_ba(&p->v0, &p->v0, &d);
        vec_add_ba(&m->pos, &m->pos, &p->v0);
        if ((func_L01_003FB640(&m->pos, 0, arg, D_L35_001DEE94 * m->f2C / *(f32 *)(m->p24 + 0x24)) != 0 &&
             (vec_sub_ba(&v10, &D_L35_001E92E0, &m->pos), func_0038CE68(&v10, &d) > 0.0f)) ||
            func_L30_0034D8D8(&m->pos, D_L35_001DEE90) == 0) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (func_L01_004561B8(m)) {
            func_003A52A0(0, 0, m);
            func_L30_0034CC28(&buf, m, p, 1, 0, 20.0f);
            if (p->w20 != 0) {
                buf.flags |= 0x30000;
            }
            func_003D4D00(&m->pos, 1, m, &buf, D_L35_001DEE94 * m->f2C / *(f32 *)(m->p24 + 0x24));
            for (i = 19; i >= 0; i--) {
                func_00382580(&d, 0.060000002f, 0.16000001f);
                func_00382580(&v10, 0.0f, 0.016f);
                vec_add_ab(&v10, &v10, &m->pos);
                e = func_L01_00475C60(&v10, &d, 0x19, func_00382498(-3, 3), 0x7FFFF38F, 0x10FFF38F,
                                      147000.0f, 42000.0f, 10.0f, 0);
                if (e != 0) {
                    e[2] = func_00382468(3) ? D_L35_0021F258[127][func_00382498(1, 3)] : D_L35_0021F258[53][0];
                    e[3] = func_00382468(2) ? 0x44 : 0x48;
                }
            }
            func_L01_00451FE0(m, 0x3F, D_L35_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0x50, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            func_003C2880(m);
        }
        break;
    }
}
/* localdecomp:end func_L35_003BC4B8 */

/* localdecomp:start func_L35_003BC828 */
typedef struct {
    vu0_q v0;
    f32 f10;
    f32 f14;
    f32 f18;
    u8 pad1C[4];
    s32 f20;
    s32 f24;
    f32 f28;
} Vars_003BC828;
typedef struct {
    u8 pad0[0x24];
    f32 f24;
} Cls_003BC828;
typedef struct {
    u8 pad0[0x10];
    vu0_q pos;
    u8 pad20[3];
    u8 f23;
    Cls_003BC828 *f24;
    u8 pad28[4];
    f32 f2C;
    u8 f30;
    u8 pad31;
    s16 f32_;
    u8 pad34[0x34];
    Vars_003BC828 *f68;
} Moby_003BC828;
extern u8 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);

Moby_003BC828 *func_L35_003BC828(vu0_q *pos, vu0_q *v, f32 scale, s32 a2, f32 b) {
    Moby_003BC828 *m = (Moby_003BC828 *)func_003C24B0(0x1E16, 0x80);
    Vars_003BC828 *vars;

    if (m == 0) {
        return 0;
    }
    m->f30 = 0xFF;
    m->f32_ = 0x40;
    m->f2C = scale * m->f24->f24;
    vars = m->f68;
    m->f23 = 0x50;
    m->pos = *pos;
    vars->v0 = *v;
    vars->f20 = a2;
    vars->f28 = b;
    vars->f24 = 3;
    vars->f10 = func_003824E0(-0.06f, 0.06f);
    vars->f14 = func_003824E0(-0.06f, 0.06f);
    vars->f18 = func_003824E0(-0.06f, 0.06f);
    func_L01_004450F0(m, 0, -1);
    return m;
}
/* localdecomp:end func_L35_003BC828 */

#include "common.h"

/* NTSC-U counterpart of func_L35_003BC4B8, with regional particle timing. */
/* localdecomp:start func_L35_003BA758 */
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
} P_003BA758;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 b20;
    u8 pad21[3];
    u8 *p24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0x38];
    P_003BA758 *p68;
    u8 pad6C[0xF0 - 0x6C];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} M_003BA758;
typedef struct {
    u8 pad0[0x14];
    s32 flags;
    u8 pad18[0x18];
} B_003BA758;
extern f32 D_L35_001DEED0;
__asm__(".extern D_L35_001DEED0, 4");
extern f32 D_L35_001DEED4;
__asm__(".extern D_L35_001DEED4, 4");
extern vu0_v4 D_L35_001E9360;
extern u8 D_L35_001D66B0[8];
extern u8 *D_L35_0021F2D8[];
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);
extern f32 func_00388730(void *, void *);
extern s32 func_L30_0034C9F8_003BA758(void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_0039FE80(s32, s32, void *);
extern void func_L30_0034BD48(void *, void *, void *, s32, s32, f32);
extern void func_003CF790(void *, s32, void *, void *, f32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_003BD360(void *);

void func_L35_003BA758(u8 *arg) {
    M_003BA758 *m = (M_003BA758 *)arg;
    s32 st = m->b20;
    P_003BA758 *p = m->p68;
    vu0_v4 v10;
    vu0_v4 d;
    B_003BA758 buf;
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
        if ((func_L01_003F9498(&m->pos, 0, arg, D_L35_001DEED4 * m->f2C / *(f32 *)(m->p24 + 0x24)) != 0 &&
             (vec_sub_ba(&v10, &D_L35_001E9360, &m->pos), func_00388730(&v10, &d) > 0.0f)) ||
            func_L30_0034C9F8_003BA758(&m->pos, D_L35_001DEED0) == 0) {
            func_L01_00441FB8(m, 1, -1);
        }
        break;
    case 1:
        if (func_L01_00452EC8(m)) {
            func_0039FE80(0, 0, m);
            func_L30_0034BD48(&buf, m, p, 1, 0, 20.0f);
            if (p->w20 != 0) {
                buf.flags |= 0x30000;
            }
            func_003CF790(&m->pos, 1, m, &buf, D_L35_001DEED4 * m->f2C / *(f32 *)(m->p24 + 0x24));
            for (i = 19; i >= 0; i--) {
                func_0037E2F0(&d, 0.050000004f, 0.13333334f);
                func_0037E2F0(&v10, 0.0f, 0.013333335f);
                vec_add_ab(&v10, &v10, &m->pos);
                e = func_L01_00472438(&v10, &d, 0x1E, func_0037E208(-3, 3), 0x7FFFF38F, 0x10FFF38F,
                                      147000.0f, 42000.0f, 10.0f, 0);
                if (e != 0) {
                    e[2] = func_0037E1D8(3) ? D_L35_0021F2D8[127][func_0037E208(1, 3)] : D_L35_0021F2D8[53][0];
                    e[3] = func_0037E1D8(2) ? 0x44 : 0x48;
                }
            }
            func_L01_0044ED60(m, 0x3F, D_L35_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0x50, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            func_003BD360(m);
        }
        break;
    }
}
/* localdecomp:end func_L35_003BA758 */

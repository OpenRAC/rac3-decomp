#include "common.h"

/* localdecomp:start func_L35_003A2728 */
#include "vu0.h"
typedef struct {
    vu0_v4 v0;
    s32 w10;
    u8 pad14[4];
    f32 f18;
} P_003A2728;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 b20;
    u8 pad21[3];
    u8 *p24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0x38];
    P_003A2728 *p68;
} M_003A2728;
extern f32 D_L35_001DE954;
__asm__(".extern D_L35_001DE954, 4");
extern f32 D_L35_001DE958;
__asm__(".extern D_L35_001DE958, 4");
extern f32 D_L35_001DE95C;
__asm__(".extern D_L35_001DE95C, 4");
extern vu0_v4 D_L35_001E92E0;
extern u8 D_L35_001D66B0[8];
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L30_0034CB68(u8 *, void *, s32, s32, f32, s32, s32, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L35_003A2728(u8 *arg) {
    M_003A2728 *m = (M_003A2728 *)arg;
    s32 st = m->b20;
    P_003A2728 *p = m->p68;
    vu0_v4 v90;
    vu0_v4 d;

    switch (st) {
    case 0:
        qzero(&d);
        d.z = p->f18;
        vec_add_ba(&p->v0, &p->v0, &d);
        vec_add_ba(&m->pos, &m->pos, &p->v0);
        if ((func_L01_003FB640(&m->pos, 0, arg, D_L35_001DE95C * m->f2C / *(f32 *)(m->p24 + 0x24)) != 0 &&
             (vec_sub_ba(&v90, &D_L35_001E92E0, &m->pos), func_0038CE68(&v90, &d) > 0.0f)) ||
            func_L30_0034D8D8(&m->pos, D_L35_001DE958) == 0) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (func_L01_004561B8(m)) {
            func_L30_0034CB68(arg, D_L35_001D66B0, 1, -1, 1.0f, 0, 0, D_L35_001DE95C * m->f2C / *(f32 *)(m->p24 + 0x24));
            if (p->w10 != 0) {
                func_L30_0034CB68(arg, D_L35_001D66B0, 0, -1, 1.0f, 0, 0, D_L35_001DE95C * m->f2C / *(f32 *)(m->p24 + 0x24));
            }
            func_L01_003303B8(&m->pos, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, D_L35_001DE954, 0.0f, 0.0f, 2.0f, 1, 1, 0, 0, 1,
                              1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF,
                              0x280000FF, 0x3064FF, 0);
            func_003C2880(m);
        }
        break;
    }
}
/* localdecomp:end func_L35_003A2728 */

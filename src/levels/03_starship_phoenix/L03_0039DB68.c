#include "common.h"

/* localdecomp:start func_L03_0039DB68 */
#include "vu0.h"
typedef int Q_0039DB68 __attribute__((mode(TI)));
typedef struct { vu0_v4 dir; s32 i10; s32 i14; s32 i18; s32 i1C; f32 f20; u8 b24; } V_0039DB68;
typedef struct {
    u8 pad0[0x10]; vu0_v4 pos; u8 b20; u8 pad21[0xF]; u8 b30; u8 b31; s16 h32; u16 h34;
    u8 pad36[0x68 - 0x36]; V_0039DB68 *p68; u8 pad6C[0xB8 - 0x6C]; void *pB8; u8 padBC[0xF0 - 0xBC];
    f32 fF0; f32 fF4; f32 fF8; s32 iFC;
} M_0039DB68;
extern s32 D_001DE3A0_sda;
__asm__(".extern D_001DE3A0_sda, 4");
extern s32 D_001DE3A8_sda;
__asm__(".extern D_001DE3A8_sda, 4");
extern M_0039DB68 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00447878(f32 *a, f32 *b, f32 *out, f32 d, f32 e);
extern f32 func_003824E0(f32, f32);
extern void func_003C7C38(void *);

M_0039DB68 *func_L03_0039DB68(vu0_v4 *from, vu0_v4 *to, u8 *parent, s32 a3, s32 a4, f32 speed, f32 f) {
    M_0039DB68 *m = func_003C24B0(0x1960, 0x80);
    V_0039DB68 *v;
    vu0_v4 dir;
    if (m != 0) {
        m->b30 = 0xFF;
        m->h32 = 0x1FF;
        v = m->p68;
        m->b31 = 1;
        m->b20 = 1;
        if (parent != 0) {
            m->pB8 = parent;
            parent[0xBC] = 0;
            v->b24 = 0;
        }
        vec_sub_ba(&dir, to, from);
        dir.z = 0.0f;
        func_0038CF68(&dir, &dir, speed);
        dir.z = func_L01_00447878(&from->x, &to->x, 0, speed, -0.00392f);
        *(Q_0039DB68 *)&m->pos = *(Q_0039DB68 *)from;
        *(Q_0039DB68 *)&v->dir = *(Q_0039DB68 *)&dir;
        v->i10 = (D_001DE3A0_sda * 5 + 2) / 6;
        v->f20 = f;
        v->i1C = a3;
        v->i18 = a4;
        v->i14 = (D_001DE3A8_sda * 5 + 2) / 6;
        m->fF0 = func_003824E0(-3.1415927f, 3.1415927f);
        m->fF4 = func_003824E0(-3.1415927f, 3.1415927f);
        m->fF8 = func_003824E0(-3.1415927f, 3.1415927f);
        m->iFC = 0;
        m->h34 |= 0x10;
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L03_0039DB68 */

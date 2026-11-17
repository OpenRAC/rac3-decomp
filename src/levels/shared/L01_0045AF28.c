#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_0045AF28 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
} M_45AF28;
typedef struct {
    u8 pad0[0x28];
    f32 x28;
    u8 pad2C[0xC];
    unsigned long x38;
    u8 pad40[0x20];
    vu0_v4 x60;
    vu0_v4 x70;
    s32 x80;
    s32 x84;
    u8 pad88[8];
    f32 x90;
    u8 pad94[0xC];
    vu0_v4 xA0;
    f32 xB0;
} S_45AF28;
extern u128_t D_L01_001E0240[] __attribute__((section(".sdata")));
extern s32 func_L01_0045B968(u8 *, u8 *);
extern s32 func_L01_0045BAC0(u8 *, u8 *);
extern f32 func_0038CEA8(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038CAD0(void *);

void func_L01_0045AF28(u8 *a0, u8 *a1) {
    M_45AF28 *self = (M_45AF28 *)a0;
    S_45AF28 *m = (S_45AF28 *)a1;
    vu0_q old;
    s32 any;
    s32 i;
    s32 r;
    f32 len;

    if ((m->x38 & 0x404) == 4) {
        m->xA0.z = 0.0f;
    }
    vec_add_ab(&self->pos, &self->pos, &m->xA0);
    any = 0;
    old = *(vu0_q *)&self->pos;
    m->x84 = 0;
    qzero(&m->x60);
    for (i = 0; i < 8; i++) {
        r = func_L01_0045B968(a0, a1);
        r |= func_L01_0045BAC0(a0, a1);
        any |= r;
        if (r == 0) {
            break;
        }
    }
    if (any) {
        vec_sub_ab(&m->xA0, &self->pos, (vu0_v4 *)D_L01_001E0240);
        len = func_0038CEA8((u8 *)&m->xA0);
        if (m->xB0 < len) {
            func_0038CF68(&m->xA0, &m->xA0, m->xB0);
        } else {
            m->xB0 = len;
        }
        if (self->pos.z <= m->x90) {
            if (0.0f < m->x90) {
                if (self->pos.z < m->x90) {
                    self->pos.z = m->x90;
                }
            } else {
                if (self->pos.z < ((vu0_v4 *)D_L01_001E0240)->z) {
                    self->pos.z = ((vu0_v4 *)D_L01_001E0240)->z;
                }
            }
            if (m->xA0.z < 0.0f) {
                m->xA0.z = 0.0f;
            }
        }
        if (m->xB0 < m->x28 * 0.5f) {
            m->x80++;
        } else {
            func_0038CAD0(&m->x80);
        }
    } else {
        func_0038CAD0(&m->x80);
    }
    vec_sub_ab(&m->x70, &self->pos, &old);
}
/* localdecomp:end func_L01_0045AF28 */

INCLUDE_ASM("asm/levels", func_L01_0045B110);

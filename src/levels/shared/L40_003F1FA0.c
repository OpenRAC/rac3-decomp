#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct Moby Moby;
typedef struct {
    u8 pad0[0x29C];
    s32 field_29C;
    u8 pad2A0[0x5C];
    s32 count;
    s32 field_300;
    s32 field_304;
    u8 pad308[8];
    Moby *items[1];
} Vars;
typedef struct {
    u8 pad0[0x354];
    s32 field_354;
    u8 pad358[8];
    Vec4 pos;
} VarsB;
struct Moby {
    u8 pad0[0x10];
    Vec4 pos;
    u8 field_20;
    u8 pad21[0x47];
    void *pVar;
};
typedef int u128_3F1460 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec4_003F1538;

/* localdecomp:start func_L40_003F1FA0 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x28];
    f32 x28;
    u8 pad2C[0xC];
    unsigned long x38;
    u8 pad40[0x20];
    Vec4 x60;
    Vec4 x70;
    s32 x80;
    s32 x84;
    u8 pad88[8];
    f32 x90;
    u8 pad94[0xC];
    Vec4 xA0;
    f32 xB0;
} S_003F1FA0;
extern s32 func_L01_0045B968(Moby *, S_003F1FA0 *);
extern s32 func_L01_0045BAC0(Moby *, S_003F1FA0 *);
extern f32 func_0038CED8(void *);
extern void func_0038CFB8(void *, void *, f32);
extern s32 func_0038CAD0(void *);

void func_L40_003F1FA0(Moby *self, S_003F1FA0 *m, Vec4 *dst) {
    Vec4 old;
    s32 any;
    s32 i;
    s32 r;
    f32 len;

    if ((m->x38 & 0x404) == 4) {
        m->xA0.z = 0.0f;
    }
    vec_add_ab(&self->pos, &self->pos, &m->xA0);
    any = 0;
    old = self->pos;
    m->x84 = 0;
    qzero(&m->x60);
    for (i = 0; i < 8; i++) {
        r = func_L01_0045B968(self, m);
        r |= func_L01_0045BAC0(self, m);
        any |= r;
        if (r == 0) {
            break;
        }
    }
    if (any) {
        vec_sub_ab(&m->xA0, &self->pos, dst);
        len = func_0038CED8(&m->xA0);
        if (m->xB0 < len) {
            func_0038CFB8(&m->xA0, &m->xA0, m->xB0);
        } else {
            m->xB0 = len;
        }
        if (self->pos.z <= m->x90) {
            if (self->pos.z < dst->z) {
                self->pos.z = dst->z;
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
/* localdecomp:end func_L40_003F1FA0 */

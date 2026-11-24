#include "common.h"

/* localdecomp:start func_L01_003E1F68 */
#include "common.h"

extern f32 D_L01_001DF590;
__asm__(".extern D_L01_001DF590, 4");
extern f32 D_L01_001DF594;
__asm__(".extern D_L01_001DF594, 4");
extern f32 D_L01_001DF598;
__asm__(".extern D_L01_001DF598, 4");
extern f32 D_L01_001DF59C;
__asm__(".extern D_L01_001DF59C, 4");
extern f32 D_L01_001DF5A0;
__asm__(".extern D_L01_001DF5A0, 4");

typedef struct M_003E1F68 {
    u8 p0[0x20];
    u8 x20;
    u8 p21[2];
    u8 x23;
    u8 p24[0x31 - 0x24];
    u8 x31;
    u8 p32[2];
    u16 x34;
    u8 p36[0x68 - 0x36];
    struct V_003E1F68 *x68;
    u8 p6C[0xB8 - 0x6C];
    struct M_003E1F68 *xB8;
} M_003E1F68;

typedef struct V_003E1F68 {
    s32 x0;
    s32 x4;
    f32 x8;
    s32 xC;
    u8 p10[0x10];
    M_003E1F68 *x20[4];
} V_003E1F68;

extern void func_L01_003E2418(M_003E1F68 *, V_003E1F68 *);
extern void func_L01_003E2BD8(M_003E1F68 *, V_003E1F68 *);
extern void func_L01_003E2DB8(u8 *);
extern void func_L01_004048D0(void *, void *);
extern void func_L01_004450F0(M_003E1F68 *, s32, s32);
extern void func_L01_00439300(M_003E1F68 *);

void func_L01_003E1F68(M_003E1F68 *m) {
    V_003E1F68 *v = m->x68;
    s32 i;
    s32 a;
    f32 t;

    switch (m->x20) {
    case 1:
        v->x8 += D_L01_001DF590;
        if (!(v->x8 >= 1.0f)) {
            func_L01_003E2418(m, v);
            func_L01_004048D0(func_L01_003E2DB8, m);
            return;
        }
        v->x8 = 0.0f;
        func_L01_004450F0(m, 2, -1);
    case 2:
        v->x8 += D_L01_001DF594;
        if (v->x8 >= 1.0f) {
            m->xB8->x23 = 0x80;
            for (i = 0; i < v->xC; i++) {
                v->x20[i]->x23 = 0x80;
            }
            v->x8 = 0.0f;
            func_L01_004450F0(m, 3, -1);
            goto state3;
        }
        func_L01_003E2BD8(m, v);
        t = v->x8;
        if (t <= D_L01_001DF59C) {
            a = 0;
        } else if (D_L01_001DF5A0 <= t) {
            a = 0x80;
        } else {
            a = (t - D_L01_001DF59C) / (D_L01_001DF5A0 - D_L01_001DF59C) * 128.0f;
        }
        if (a >= 2) {
            m->xB8->x34 &= ~1;
            m->xB8->x31 = 1;
            m->xB8->x23 = a;
            for (i = 0; i < v->xC; i++) {
                v->x20[i]->x34 &= ~1;
                v->x20[i]->x31 = 1;
                v->x20[i]->x23 = a;
            }
        }
        func_L01_004048D0(func_L01_003E2DB8, m);
        return;
    case 3:
    state3:
        v->x8 += D_L01_001DF598;
        if (v->x8 >= 1.0f) {
            func_L01_00439300(m);
        } else {
            func_L01_003E2BD8(m, v);
        }
        return;
    }
}
/* localdecomp:end func_L01_003E1F68 */

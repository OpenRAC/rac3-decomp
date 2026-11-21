#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L08_003A8388 */
typedef struct {
    u8 p0[0x10];
    s32 w10;
} P_3A8388;

typedef struct {
    u8 p0[0x10];
    f32 x;
    f32 y;
    u8 p18[0x20 - 0x18];
    u8 b20;
    u8 p21[3];
    P_3A8388 *p24;
    u8 p28[0x34 - 0x28];
    u16 h34;
    u8 p36[0x68 - 0x36];
    void *p68;
    u8 p6C[0x98 - 0x6C];
    s32 w98;
    u8 p9C[0xAA - 0x9C];
    s16 hAA;
    u8 pAC[0xB0 - 0xAC];
    u8 bB0;
} M_3A8388;

typedef struct {
    u8 p0[0x80];
    f32 f80;
    f32 f84;
    u8 p88[0x90 - 0x88];
    s32 w90;
    f32 f94;
    f32 f98;
} C_3A8388;

extern s32 D_001D545C;
__asm__(".extern D_001D545C, 4");
extern u8 D_001BBC40[];
extern u8 *D_L08_001DF21C;
__asm__(".extern D_L08_001DF21C, 16");
extern u8 *D_L08_001DF21C_003A8388;
__asm__(".extern D_L08_001DF21C_003A8388, 4");
extern s32 func_L01_0044C108(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004AA760(s32, void *);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L08_003A8388(M_3A8388 *m) {
    C_3A8388 *c;
    vu0_v4 d;
    f32 step;
    f32 nv;

    if (func_L01_0044C108((u8 *)m + 0x10) == 0) {
        return;
    }
    c = (C_3A8388 *)m->p68;
    switch (m->b20) {
    case 0:
        if (c->w90 == -1 || (D_001BBC40[m->bB0 + (D_001D545C << 4)] & 0x80) != 0) {
            func_L01_004450F0(m, 3, -1);
        } else {
            *(vu0_v4 *)((u8 *)c + 0x80) = *(vu0_v4 *)((u8 *)m + 0x10);
            if (c->f94 != -1.0f) {
                m->x = c->f94;
                m->w98 = 0;
                m->h34 |= 0x41;
            } else if (c->f98 != -1.0f) {
                m->y = c->f98;
                m->w98 = 0;
                m->h34 |= 0x41;
            }
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (func_L01_00456250(D_L08_001DF21C + (c->w90 << 8)) != 0) {
            m->h34 &= 0xFFBE;
            m->w98 = m->p24->w10;
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0 && D_001D545C == 8 && c->w90 != -1 &&
            *(s16 *)(D_L08_001DF21C_003A8388 + (c->w90 << 8) + 0xAA) != m->hAA) {
            func_003A52A0(0, 0x14, m);
        }
        if (c->f94 != -1.0f) {
            nv = m->x + (c->f94 < c->f80 ? 0.1f : -0.1f);
            m->x = nv;
            if (fabs_asm(nv - c->f94) >= 1.95f) {
                func_L01_00456230(m, 1);
            }
            if (fabs_asm(m->x - c->f80) < 0.05f) {
                func_L01_004AA760(0, m);
                func_L01_004450F0(m, 3, -1);
            }
        } else if (c->f98 != -1.0f) {
            nv = m->y + (c->f98 < c->f84 ? 0.1f : -0.1f);
            m->y = nv;
            if (fabs_asm(nv - c->f98) >= 1.95f) {
                func_L01_00456230(m, 1);
            }
            if (fabs_asm(m->y - c->f84) < 0.05f) {
                func_L01_004AA760(0, m);
                func_L01_004450F0(m, 3, -1);
            }
        }
        break;
    }
    vec_sub_ab(&d, (u8 *)m + 0x10, (u8 *)c + 0x70);
    func_003C4DA8((u8 *)c + 0x30, &d, (u8 *)m + 0xF0, (u8 *)m + 0xF0);
    *(vu0_v4 *)((u8 *)c + 0x70) = *(vu0_v4 *)((u8 *)m + 0x10);
}
/* localdecomp:end func_L08_003A8388 */

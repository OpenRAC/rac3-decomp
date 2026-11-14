#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L08_003A56E8 */
typedef struct {
    u8 p0[0x24];
    f32 f24;
} T_003A56E8;

typedef struct {
    u8 p0[0x30];
    f32 f30;
    s16 h34;
    u8 p36[0x3];
    u8 b39;
    u8 p3A[0x4];
    u8 b3E;
    u8 b3F;
    f32 f40;
    u8 p44[0x14];
    u8 b58;
    u8 p59[0x1];
    u8 b5A;
    u8 p5B[0x15];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 p84[0x18];
    s32 w9C;
    f32 fA0;
    u8 pA4[0x4];
    s32 wA8;
    u8 pAC[0xC4];
    u8 b170;
    u8 b171;
    u8 p172[0x4];
    u8 b176;
    u8 p177[0x19];
    f32 f190;
    f32 f194;
    u8 p198[0x4];
    f32 f19C;
    u8 p1A0[0x8];
    u8 b1A8;
    u8 p1A9[0x2E];
    u8 b1D7;
    u8 b1D8;
    u8 b1D9;
    u8 b1DA;
    u8 b1DB;
    u8 p1DC[0x100];
    s32 w2DC;
    vu0_v4 v2E0;
    u8 p2F0[0x20];
    f32 f310;
    u8 p314[0x10];
    s32 w324;
    u8 p328[0x4];
    s32 w32C;
    u8 p330[0x1C];
    s32 w34C;
} P_003A56E8;

typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 p20[4];
    T_003A56E8 *p24;
    u8 p28[4];
    f32 f2C;
    u8 p30[4];
    u16 h34;
    u8 p36[0xD];
    u8 b43;
    u8 p44[0x24];
    P_003A56E8 *p68;
    u8 p6C[0x2C];
    s32 w98;
    u8 p9C[0x20];
    u8 bBC;
} M_003A56E8;

extern f32 D_001DE2DC_sda;
__asm__(".extern D_001DE2DC_sda, 4");
extern f32 func_0037E2A8(void);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004A6DF8(void *, s32);

s32 func_L08_003A56E8(M_003A56E8 *m) {
    P_003A56E8 *p;

    p = m->p68;
    p->f310 = func_0037E2A8();
    p->w32C = 0;
    p->w34C = 0;
    m->bBC = 0;
    p->b170 = 0x10;
    p->b1A8 = 3;
    p->b171 = 0xE;
    p->f190 = 0.5f;
    p->f194 = 0.5f;
    p->b176 = 0x12;
    p->b1D7 = 1;
    p->f19C = 0.15f;
    p->b1D8 = 0;
    p->b1D9 = 0;
    p->b1DA = 0;
    p->b1DB = 0xFF;
    p->v2E0 = m->pos;
    p->f74 = 0.5f;
    p->f70 = 1.25f;
    p->w9C = 0;
    p->f78 = 0.5f;
    p->f7C = 1.0f;
    p->f80 = 1.4835298f;
    p->fA0 = 0.34906584f;
    p->wA8 |= 5;
    func_L01_00458A70(m, 0.0044444446f, 0.125f, 0.0069813174f, 0.20943953f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 10;
        p->f30 = 10.0f;
    }
    p->b39 = 1;
    p->b3F = 0;
    p->f40 = 2.0f;
    m->f2C = m->p24->f24 * D_001DE2DC_sda;
    p->b3E = 1;
    if (m->b43 != 5) {
        func_003BE4F0(m, 5, 0, 10);
    }
    func_L01_00441FB8(m, 0xD, -1);
    if (p->w324 != -1) {
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        func_L01_004A6DF8(m, 1);
    }
    if (p->w2DC != 0) {
        func_L01_00441FB8(m, 1, 0);
        if (m->b43 != 0) {
            func_003BE4F0(m, 0, 0, 10);
        }
    }
    return 0;
}
/* localdecomp:end func_L08_003A56E8 */

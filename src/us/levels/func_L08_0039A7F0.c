#include "common.h"

/* NTSC-U counterpart of func_L08_0039C220 (src/levels/08_aquatos/L08_0039C028.c) */
extern s32 func_L08_0039A7F0(void *);

/* localdecomp:start func_L08_0039A7F0 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 p20[0x14]; u16 h34; u8 p36[0xD]; u8 b43; u8 p44[0x24]; u8 *p68;
    u8 p6C[0x2C]; s32 w98;
} M_0039C220;
typedef struct {
    u8 p0[0x30]; f32 f30; s16 h34; u8 p36[3]; u8 b39; u8 p3A[4]; u8 b3E; u8 b3F; f32 f40;
    u8 p44[0x14]; u8 b58; u8 p59; u8 b5A; u8 p5B[0x15]; f32 f70; f32 f74; f32 f78; f32 f7C; f32 f80;
    u8 p84[0x18]; f32 f9C; f32 fA0; u8 pA4[0xCC]; u8 b170; u8 p171[0x1F];
    f32 f190; f32 f194; u8 p198[4]; f32 f19C; u8 p1A0[8]; u8 b1A8;
    u8 p1A9[0x2E]; u8 b1D7; u8 b1D8; u8 b1D9; u8 b1DA; u8 b1DB; u8 p1DC[0x34]; f32 f210;
    u8 p214[0xCC]; vu0_v4 v2E0; u8 p2F0[0x10]; s32 w300; u8 p304[4]; s32 w308; u8 p30C[8];
    s32 w314; u8 p318[4]; f32 f31C;
} P_0039C220;
extern s32 D_001D545C;
extern f32 func_0037E2A8(void);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);

s32 func_L08_0039A7F0(void *arg) {
    M_0039C220 *m = arg;
    P_0039C220 *p = (P_0039C220 *)m->p68;
    f32 h;
    f32 z;

    p->v2E0 = m->pos;
    p->f31C = func_0037E2A8();
    p->b170 = 8;
    p->b1A8 = 3;
    p->f19C = 0.15f;
    p->f190 = 0.5f;
    p->b1DB = 0xFF;
    p->f194 = 0.5f;
    p->b1D7 = 1;
    p->b1D8 = 0;
    p->b1D9 = 0;
    p->b1DA = 0;
    p->f210 = 1.0f;
    p->f70 = 0.5f;
    p->f74 = 0.25f;
    p->f78 = 1.0f;
    p->f7C = 1.25f;
    p->f80 = 1.6580628f;
    p->fA0 = 0.34906584f;
    p->f9C = 0.0027222223579883575f;
    func_L01_00458A70(m, 0.004444444552063942f, 0.06666667014360428f, 0.0069813174195587635f, 0.20943953096866608f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 1;
        p->f30 = 1.0f;
    }
    p->f40 = 1.0f;
    p->b39 = 1;
    p->b3E = 1;
    p->b3F = 0;
    func_L01_00441FB8(m, 1, 0);
    if (m->b43 != 3) func_003BE4F0(m, 3, 0, 0);
    if ((p->w300 != -1 || p->w308 != -1) && D_001D545C != 8) {
        func_L01_00441FB8(m, 9, 4);
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        func_L01_004A6DF8(m, 1);
    }
    if (p->w314 != 0) {
        h = func_003BE7F0(&m->pos, 0, 0, 0.5f);
        z = m->pos.z;
        if (z - h > 3.0f) h = z;
        m->pos.z = h - 1.0f;
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        func_L01_004A6DF8(m, 1);
    }
    return 0;
}
/* localdecomp:end func_L08_0039A7F0 */

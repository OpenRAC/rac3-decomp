#include "common.h"

/* NTSC-U counterpart of func_L08_003A34C8 (src/levels/shared/L08_003A34C8.c): 0.00392 -> 0.00272222; 0.016 -> 0.0111111; 0.12 -> 0.1; 0.0100531 -> 0.00698132; 0.251327 -> 0.20944; 8 -> 10 */
#include "vu0.h"
typedef struct {
    u8 p0[0x30];
    u8 v30[0x0E];
    u8 b3E;
    u8 p3F[0x5E - 0x3F];
    u8 b5E;
    u8 b5F;
    u8 p60[0x160 - 0x60];
    u8 v160[0x304 - 0x160];
    s32 i304;
    f32 f308;
} S_Vars3A1638;
typedef struct {
    u8 p0[0x20]; u8 state;
    u8 p21[0x68 - 0x21]; S_Vars3A1638 *vars;
} S_Moby3A1638;
extern s32 func_L08_003A1780(S_Moby3A1638 *);

/* localdecomp:start func_L08_003A1780 */
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 p20[4]; u8 *p24; u8 p28[4]; f32 f2C; u8 p30[4]; u16 h34; u8 p36[0xD]; u8 b43; u8 p44[0x24]; u8 *p68;
    u8 p6C[0x2C]; s32 w98; u8 p9C[0x16]; u16 hB2;
} M_003A34C8;
typedef struct {
    u8 p0[0x30]; f32 f30; s16 h34; u8 p36[3]; u8 b39; u8 p3A[4]; u8 b3E; u8 b3F; f32 f40;
    u8 p44[0x14]; u8 b58; u8 p59; u8 b5A; u8 p5B[9]; u8 b64; u8 p65[0xB]; f32 f70; f32 f74; f32 f78; f32 f7C; f32 f80;
    u8 p84[0x18]; f32 f9C; f32 fA0; u8 pA4[0xCC]; u8 b170; u8 b171; u8 p172[4]; u8 b176; u8 p177[0x19];
    f32 f190; f32 f194; u8 p198[4]; f32 f19C; u8 p1A0[8]; u8 b1A8;
    u8 p1A9[0x2E]; u8 b1D7; u8 b1D8; u8 b1D9; u8 b1DA; u8 b1DB; u8 p1DC[0x3C]; s32 w218;
    u8 p21C[0xA4]; vu0_v4 v2C0; u8 p2D0[0x10]; s32 w2E0; u8 p2E4[0x14]; s32 w2F8; u8 p2FC[0x24];
    s32 w320; s32 w324;
} P_003A34C8;
typedef struct { u8 pad[0x464]; u8 spent[1]; } S_003A34C8;
extern S_003A34C8 D_L08_00235280_003A1780;
extern u8 D_001BBE90[];
extern s32 D_001D545C;
extern u8 *D_L08_001DF21C_003A1780;
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_L01_004412D0(u8 *, s32, s32);
extern void func_003BD360(u8 *);

s32 func_L08_003A1780(S_Moby3A1638 *arg) {
    M_003A34C8 *m = (M_003A34C8 *)arg;
    P_003A34C8 *p = (P_003A34C8 *)m->p68;
    s32 id;
    s32 b;

    p->b170 = 10;
    p->b1A8 = 2;
    p->b171 = 7;
    p->b176 = 7;
    p->f19C = 0.15f;
    p->b1D7 = 1;
    p->b1DB = 0xFF;
    p->f190 = 0.5f;
    p->f194 = 0.5f;
    p->b1D8 = 0;
    p->b1D9 = 0;
    p->b1DA = 0;
    p->w218 = 1;
    m->f2C = *(f32 *)(m->p24 + 0x24) * 1.25f;
    p->f70 = 2.6f;
    p->f74 = 0.5f;
    p->f78 = 0.5f;
    p->f7C = 1.0f;
    p->f80 = 0.7853982f;
    p->fA0 = 0.34906584f;
    p->f9C = 0.00272222236f;
    func_L01_00458A70(m, 0.0111111114f, 0.100000009f, 0.00698131742f, 0.209439531f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 20;
        p->f30 = 20.0f;
    }
    p->f40 = 2.0f;
    p->b39 = 1;
    p->b3F = 0;
    p->b64 = 0;
    p->b3E = 1;
    func_L01_00441FB8(m, 1, 0);
    if (m->b43 != 1) func_003BE4F0(m, 1, 0, 10);
    if (p->w2E0 != -1 || p->w2F8 != -1) {
        func_L01_00441FB8(m, 11, 3);
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        func_L01_004A6DF8(m, 1);
    }
    id = m->hB2;
    if (D_L08_00235280_003A1780.spent[(s16)id] || (b = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)], (id & 1) ? (b >> 4) & 7 : b & 7)) {
        if (p->w2E0 != -1) {
            u8 *o = D_L08_001DF21C_003A1780 + (p->w2E0 << 8);
            func_L01_004412D0(o, 0, 3);
            func_003BD360(o);
        }
        if (p->w2F8 != -1) {
            u8 *o = D_L08_001DF21C_003A1780 + (p->w2F8 << 8);
            func_L01_004412D0(o, 0, 3);
            func_003BD360(o);
        }
        return 1;
    }
    p->v2C0 = m->pos;
    p->w320 = 0;
    p->w324 = 0;
    return 0;
}
/* localdecomp:end func_L08_003A1780 */

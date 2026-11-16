#include "common.h"

/* NTSC-U counterpart of func_L20_003FE3D0 (src/levels/20_final_boss/L20_003FE3D0.c) */
extern void func_L05_00359930(void *, s32, s32, s32);
extern s32 func_L20_003FC0E0(void *);
extern void func_003BD360(void *);
extern void func_00388BD0(void *, void *);
extern void func_003BE4F0(void *, s32, s32, s32);

/* localdecomp:start func_L20_003FC0E0 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) V_003FE3D0;
typedef struct {
    u8 p0[0x10]; V_003FE3D0 pos; u8 p20[4]; struct { u8 p0[0x24]; f32 f24; } *x24; u8 p28[4]; f32 f2C; u8 b30; u8 p31; u16 h32; u16 h34;
    u8 p36[2]; unsigned long d38; u8 p40[0x3C]; s16 h7C; u8 p7E[0x1A]; s32 x98; u8 p9C[0x1C]; void *xB8;
    u8 pBC[4]; V_003FE3D0 vC0; u8 pD0[0x20]; V_003FE3D0 vF0;
} M_003FE3D0;
typedef struct {
    u8 p0[0x30]; f32 f30; s16 h34; u8 p36[3]; u8 b39; u8 p3A[4]; u8 b3E; u8 p3F;
    f32 f40; u8 b44; u8 b45; u8 b46; u8 p47[0x11]; u8 b58; u8 p59; u8 b5A; u8 p5B[0x15];
    f32 f70; f32 f74; f32 f78; f32 f7C; f32 f80; u8 p84[0x18]; f32 f9C; f32 fA0; u8 pA4[4]; s32 xA8;
    u8 pAC[0xC4]; u8 b170; u8 b171; u8 b172; u8 p173[9]; f32 f17C; f32 f180; f32 f184; f32 f188; f32 f18C;
    f32 f190; f32 f194; s16 h198; u8 p19A[2]; f32 f19C; u8 p1A0[8]; u8 b1A8; u8 p1A9[0xF]; f32 f1B8; f32 f1BC;
    u8 p1C0[0xC]; u8 b1CC; u8 b1CD; u8 b1CE; u8 b1CF; u8 p1D0[7]; u8 b1D7; u8 b1D8; u8 b1D9; u8 p1DA; u8 b1DB;
    u8 p1DC[0x64]; M_003FE3D0 *x240; u8 p244[0x11C]; V_003FE3D0 v360; u8 p370[0x24]; s32 x394; u8 p398[4];
    s32 x39C; s32 x3A0; s32 x3A4; s32 x3A8; s32 x3AC; u8 p3B0[4]; f32 f3B4; s16 h3B8; u8 p3BA[6]; s32 x3C0;
    u8 p3C4[4]; s32 x3C8; u8 p3CC[0xE]; s16 h3DA; u8 p3DC[0x10]; M_003FE3D0 *x3EC; u8 p3F0[6]; s16 h3F6;
    u8 p3F8[4]; s32 x3FC;
} P_003FE3D0;
extern f32 D_001DF63C_sda_003FC0E0;
__asm__(".extern D_001DF63C_sda_003FC0E0, 4");
extern u8 D_001DF640_sda;
__asm__(".extern D_001DF640_sda, 1");
extern f32 D_001DF600_sda_003FC0E0;
__asm__(".extern D_001DF600_sda_003FC0E0, 4");
extern f32 D_001DF604_sda;
__asm__(".extern D_001DF604_sda, 4");
extern f32 D_001DF608_sda;
__asm__(".extern D_001DF608_sda, 4");
extern f32 D_001DF60C_sda;
__asm__(".extern D_001DF60C_sda, 4");
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_003C26C8(void *);
extern void func_L20_003FD048(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004A6DF8(void *, s32);

static __inline__ void activate_003FE3D0(M_003FE3D0 *a0, P_003FE3D0 *p) {
    a0->x98 = 0;
    a0->h34 |= 0x41;
    a0->h34 &= ~0x1000;
    func_L01_004A6DF8(a0, 1);
    p->x3EC->h34 |= 0x41;
    p->x3EC->h34 &= ~0x1000;
    p->x3EC->x98 = 0;
    func_L01_004A6DF8(p->x3EC, 1);
}

s32 func_L20_003FC0E0(void *arg) {
    M_003FE3D0 *a0 = arg;
    P_003FE3D0 *p = *(P_003FE3D0 **)((u8 *)a0 + 0x68);
    f32 s;

    p->b1A8 = 3;
    p->b170 = 6;
    p->b171 = 0x10;
    p->b172 = 0x11;
    p->f190 = D_001DF63C_sda_003FC0E0 * 0.55f;
    p->f194 = D_001DF63C_sda_003FC0E0 * 0.75f;
    p->b1DB = 0x1B;
    p->b1D7 = 0;
    p->b1D8 = 0;
    p->b1D9 = 0;
    p->b1CC = 6;
    p->b1CD = 0xC;
    p->b1CE = 6;
    p->b1CF = 0xC;
    p->f19C = 0.15f;
    p->f17C = 0.25f;
    p->f184 = 0.004166666883975267f;
    p->f180 = 0.01666666753590107f;
    p->f188 = 0.01805555634200573f;
    p->f18C = 0.0005555555690079927f;
    p->f1BC = 0.5f;
    p->f1B8 = 0.1f;
    p->f78 = D_001DF63C_sda_003FC0E0;
    p->f70 = D_001DF63C_sda_003FC0E0 * 0.55f;
    p->f74 = D_001DF63C_sda_003FC0E0 * 0.25f;
    p->f7C = D_001DF63C_sda_003FC0E0 * 1.75f;
    p->f80 = 1.6580628f;
    p->h198 = 0;
    p->fA0 = 0.34906584f;
    p->f9C = 0.0027222223579883575f;
    func_L01_00458A70(a0, D_001DF604_sda * 0.00027777778450399637f, D_001DF600_sda_003FC0E0 * 0.01666666753590107f,
                      D_001DF60C_sda * 0.017453292f * 0.00027777778450399637f, D_001DF608_sda * 0.017453292f * 0.01666666753590107f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 10;
        p->f30 = 10.0f;
        p->b44 = 10;
        p->b45 = 10;
        p->b46 = 10;
    }
    p->f40 = 1.0f;
    p->b39 = D_001DF640_sda;
    p->b3E = 1;
    p->x3EC = (M_003FE3D0 *)func_003BCFB0(0x1610, 0x80);
    if (p->x3EC == 0) {
        func_003BD360(a0);
        return 1;
    }
    p->x3EC->xB8 = a0;
    p->x3EC->pos = a0->pos;
    p->x3EC->vF0 = a0->vF0;
    p->x3EC->d38 = a0->d38;
    func_003C26C8(p->x3EC);
    p->x3EC->h32 = a0->h32;
    p->x3EC->b30 = a0->b30;
    p->x3EC->h34 |= 0x100;
    p->x3EC->pos = a0->pos;
    p->x3EC->vF0 = a0->vF0;
    func_00388BD0(&p->x3EC->vC0, &p->x3EC->vF0);
    p->x240 = p->x3EC;
    p->x240->h7C = 7;
    p->h3F6 = 1;
    s = D_001DF63C_sda_003FC0E0;
    a0->f2C = a0->x24->f24 * s;
    p->x3EC->f2C = p->x3EC->x24->f24 * s;
    func_L20_003FD048(a0);
    if (p->h3B8 != 0) {
        p->v360 = a0->pos;
        p->f3B4 = a0->vF0.v[2];
        func_L01_00441FB8(a0, 7, 4);
        activate_003FE3D0(a0, p);
        p->x3EC->h34 |= 2;
        p->x3EC->h34 |= 4;
    } else if (p->x3A4 != -1) {
        func_L01_00441FB8(a0, 3, 4);
        activate_003FE3D0(a0, p);
        p->x3EC->h34 |= 2;
        p->x3EC->h34 |= 4;
    } else if (p->x3A8 != -1) {
        if (p->x3AC != 0) {
            func_L01_00441FB8(a0, 4, 4);
            p->x3EC->h34 |= 2;
            p->x3EC->h34 |= 4;
        } else {
            func_L01_00441FB8(a0, 5, 4);
            p->x39C = 0;
        }
        activate_003FE3D0(a0, p);
        p->x3EC->h34 |= 2;
        p->x3EC->h34 |= 4;
    } else {
        func_L01_00441FB8(a0, 1, 0);
        func_L05_00359930(a0, 0, 0, 0);
        if (p->x3A0 != 0) {
            func_L01_00441FB8(a0, 7, 0);
            activate_003FE3D0(a0, p);
            p->x3EC->h34 |= 2;
            p->x3EC->h34 |= 4;
        }
    }
    if (p->x3C8 != 0) {
        activate_003FE3D0(a0, p);
        func_L01_00441FB8(a0, 7, 4);
        p->x3EC->h34 |= 2;
        p->x3EC->h34 |= 4;
    }
    if (p->h3DA != 0) {
        p->xA8 |= 4;
        p->f78 = 0.7f;
        p->f7C = 0.7f;
        a0->h34 |= 0x100;
        p->f80 = 12.566371f;
        p->xA8 |= 1;
    }
    if (p->x3FC != 0) {
        p->x394 = 1;
        p->f1BC = 1.0f;
        p->f1B8 = 0.2f;
        func_003BE4F0(a0, 0x13, 0, 0);
        func_003BE4F0(p->x3EC, 2, 0, 0);
        func_003BE4F0(a0, 0x13, 0, 1);
        func_003BE4F0(p->x3EC, 2, 0, 1);
        p->xA8 |= 0x404;
    }
    return 0;
}
/* localdecomp:end func_L20_003FC0E0 */

#include "common.h"

/* NTSC-U counterpart of func_L01_003BD9A8 (src/levels/01_veldin/L01_003BCDF8.c): 0.0004 -> 0.000277778; 0.02 -> 0.0166667; 0.00392 -> 0.00272222 */
typedef struct { char p0[0x18]; float f18; } B;
extern B *D_L01_0021F740[];
extern int func_L01_003BC160(void *);

/* localdecomp:start func_L01_003BC160 */
#include "vu0.h"
typedef struct { u8 p0[0x24]; f32 f24; } C_BD9A8;
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 p20[4]; C_BD9A8 *p24; u8 p28[4]; f32 f2C;
    u8 p30[0x13]; u8 b43; u8 p44[0x24]; u8 *p68; u8 p6C[0x10]; s16 h7C;
    u8 p7E[0x72]; vu0_v4 rot;
} M_BD9A8;
typedef struct {
    u8 p0[0x30]; f32 f30; s16 h34; u8 p36[2]; u8 b38; u8 b39; u8 p3A[4]; u8 b3E; u8 b3F; f32 f40;
    u8 p44[0x14]; u8 b58; u8 p59; u8 b5A; u8 p5B[3]; u8 b5E; u8 b5F; u8 p60[4]; u8 b64;
    u8 p65[0xB]; f32 f70; f32 f74; f32 f78; f32 f7C; f32 f80; u8 p84[0x18]; f32 f9C; f32 fA0;
    u8 pA4[4]; s32 wA8; u8 pAC[0xC4]; u8 b170; u8 b171; u8 b172; u8 p173[0x1D];
    f32 f190; f32 f194; u8 p198[4]; f32 f19C; u8 p1A0[8]; u8 b1A8; u8 p1A9[0x2E];
    u8 b1D7; u8 b1D8; u8 b1D9; u8 b1DA; u8 b1DB; u8 p1DC[0x64]; s32 w240; u8 p244[0xA];
    u8 b24E; u8 b24F; u8 p250[0xB0]; f32 f300; u8 p304[0xC]; vu0_v4 v310; s32 w320;
    u8 p324[8]; s16 h32C; s16 h32E; s32 w330; f32 f334; f32 f338;
} P_BD9A8;
typedef struct { void (*f0)(void *); } V_BD9A8;
extern f32 func_0037E2A8(void);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388A28(f32, f32);
extern void *func_L01_00438468(s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
int func_L01_003BC160(void *arg) {
    M_BD9A8 *m = arg;
    P_BD9A8 *p = (P_BD9A8 *)m->p68;
    m->f2C = m->p24->f24;
    p->f300 = func_0037E2A8();
    m->h7C = 0x1F;
    p->f190 = 0.5f;
    p->b1D7 = 1;
    p->b171 = 2;
    p->b1A8 = 0xFF;
    p->b172 = 2;
    p->b1D8 = 2;
    p->b1D9 = 2;
    p->b1DA = 0;
    p->f194 = 0.5f;
    p->f7C = 1.0f;
    p->b170 = 8;
    p->f19C = 0.15f;
    p->b1DB = 0xFF;
    p->f70 = 0.9f;
    p->f74 = 0.05f;
    p->f78 = 0.5f;
    p->f80 = 0.7853982f;
    p->fA0 = 0.34906584f;
    p->wA8 |= 4;
    p->f9C = 0.00272222236f;
    func_L01_00458A70(m, p->f338 * 0.000277777785f, p->f334 * 0.0166666675f,
                      p->f338 * 0.017453292f * 0.000277777785f, p->f334 * 0.017453292f * 0.0166666675f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 4;
        p->f30 = 4.0f;
    }
    p->f40 = 0.75f;
    p->b38 = 2;
    p->b39 = 1;
    p->b3E = 1;
    p->b3F = 0;
    p->b64 = 0;
    if (p->w320 != -1) {
        vu0_v4 *b = (vu0_v4 *)D_L01_0021F740[p->w320];
        vu0_v4 up;
        vu0_v4 d;
        vu0_v4 out;
        m->pos = b[1];
        *(vu0_q *)&up = 0;
        up.z = 1.0f;
        if (p->h32E == 0) vec_sub_ba(&d, &b[*(s32 *)b], &b[1]);
        else vec_sub_ab(&d, &b[1], &b[*(s32 *)b]);
        func_00388758(&out, &d, &up);
        m->rot.z = func_00388A28(out.x, out.y);
        p->v310 = m->rot;
    }
    p->b5E = 0;
    p->b5F = 0;
    p->h32C = 0;
    p->w330 = 0;
    if (p->w240 > 0) {
        V_BD9A8 *r = func_L01_00438468(0x19E1, 0x6C);
        p->w240 = -1;
        if (m->b43 != 1) func_003BE4F0(m, 1, 0, 0);
        p->b24E = 7;
        p->b24F = 2;
        r->f0(m);
    } else {
        func_L01_00441FB8(m, 1, 0);
    }
    return 0;
}
/* localdecomp:end func_L01_003BC160 */

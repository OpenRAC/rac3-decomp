#include "common.h"

/* NTSC-U counterpart of func_L01_003B08A0 (src/levels/01_veldin/L01_003AF290.c): 0.00392 -> 0.00272222; 0.0024 -> 0.00166667; 0.16 -> 0.133333; 0.0100531 -> 0.00698132; 0.251327 -> 0.20944 */
#include "vu0.h"
typedef struct { u8 p0[0x18]; f32 f18; } T18;
extern T18 *D_L01_0021F740[];
extern s32 func_L01_003AF0D0(void *);

/* localdecomp:start func_L01_003AF0D0 */
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 p20[0x10]; u8 b30; u8 p31[0x37]; u8 *p68;
    u8 p6C[0x10]; s16 h7C; u8 p7E[0x1A]; s32 w98; s32 w9C; u8 pA0[0x50]; vu0_v4 rot;
} M_3B08A0;
typedef struct {
    u8 p0[0x30]; f32 f30; s16 h34; u8 p36[3]; u8 b39; u8 p3A[4]; u8 b3E; u8 b3F; f32 f40;
    u8 b44; u8 p45[0x13]; u8 b58; u8 p59; u8 b5A; u8 p5B[9]; u8 b64; u8 p65; s16 h66;
    u8 p68[8]; f32 f70; f32 f74; f32 f78; f32 f7C; f32 f80; u8 p84[0x18]; f32 f9C; f32 fA0;
    f32 fA4; s32 wA8; u8 pAC[0xC4]; u8 b170; u8 b171; u8 b172; u8 p173[9]; s32 w17C; s32 w180;
    u8 p184[0xC]; f32 f190; f32 f194; u8 p198[4]; f32 f19C; u8 p1A0[8]; u8 b1A8; u8 p1A9[0x2E];
    u8 b1D7; u8 b1D8; u8 b1D9; u8 b1DA; u8 b1DB; u8 p1DC[0xF4]; f32 f2D0; u8 p2D4[0x1C];
    s32 w2F0; s16 h2F4; u8 p2F6[0x1A]; vu0_v4 v310; vu0_v4 v320; u8 p330[0x14]; s32 w344;
    s32 w348; s32 w34C; s32 w350;
} P_3B08A0;
extern f32 func_0037E2A8(void);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
s32 func_L01_003AF0D0(void *arg) {
    M_3B08A0 *m = arg;
    P_3B08A0 *p = (P_3B08A0 *)m->p68;
    p->f2D0 = func_0037E2A8();
    m->b30 = 0x32;
    m->h7C = 0x1F;
    p->b1A8 = 0xFF;
    p->w17C = 0;
    p->w180 = 0;
    p->f190 = 0.5f;
    p->b1D7 = 1;
    p->f194 = 0.5f;
    p->b171 = 2;
    p->b172 = 2;
    p->b1D8 = 2;
    p->b1DA = 0;
    p->f7C = 1.0f;
    p->fA4 = 1.0f;
    p->b170 = 0xD;
    p->f19C = 0.15f;
    p->b1D9 = 2;
    p->b1DB = 0xFF;
    p->f70 = 0.9f;
    p->f74 = 0.05f;
    p->f78 = 0.5f;
    p->f80 = 0.7853982f;
    p->fA0 = 0.34906584f;
    p->wA8 |= 4;
    p->f9C = 0.00272222236f;
    func_L01_00458A70(m, 0.00166666671f, 0.13333334f, 0.00698131742f, 0.209439531f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 4;
        p->f30 = 4.0f;
    }
    if (p->b44 == 0) p->b44 = 1;
    p->f40 = 0.75f;
    p->b39 = 1;
    p->b3E = 3;
    p->b3F = 0;
    p->b64 = 0;
    p->h66 = 0;
    if (p->w2F0 != -1) {
        p->h2F4 = 0;
        m->w98 = 0;
        m->pos.z -= 5.0f;
    }
    if (p->w348 != -1) {
        vu0_v4 *b = (vu0_v4 *)D_L01_0021F740[p->w348];
        vu0_v4 up;
        vu0_v4 d;
        vu0_v4 out;
        m->pos = b[1];
        *(vu0_q *)&up = 0;
        up.z = 1.0f;
        if (p->w34C == 0) vec_sub_ba(&d, &b[*(s32 *)b], &b[1]);
        else vec_sub_ab(&d, &b[1], &b[*(s32 *)b]);
        func_00388758(&out, &d, &up);
        m->rot.z = func_00388A28(out.x, out.y);
        p->v320 = m->rot;
        vec_sub_ab(&d, &b[1], &b[*(s32 *)b]);
        func_00388830(&d, &d, func_00388770(&d) * 0.5f);
        vec_add_ba(&d, &b[*(s32 *)b], &d);
        m->pos = d;
    }
    p->v310 = m->pos;
    func_L01_00441FB8(m, 1, 0);
    if (p->w344 != -1) func_L01_00441FB8(m, 0xB, -1);
    if (p->w350 == 0) m->w9C |= 0x80;
    return 0;
}
/* localdecomp:end func_L01_003AF0D0 */

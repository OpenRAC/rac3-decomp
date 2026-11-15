#include "common.h"

INCLUDE_ASM("asm/levels", func_L20_003FA478);

/* localdecomp:start func_L20_003FACD8 */
extern s32 func_L20_003FAF10(void *);
extern void func_L20_003FB120(void *);
extern void func_L20_003FB1F0(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L20_003FACD8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);

    if (a0[0x20] == 0 && func_L20_003FAF10(a0) != 0) return 1;
    if (p[0x3E] == 2) goto done;
    if (func_L01_00452FB0(a0, p + 0x160, 0, 0, 0) != 0) func_L20_003FB1F0(a0);
    func_L01_00452860(a0, p + 0x30, 0);
    if (p[0x5E] != 0) {
done:
        func_L20_003FB120(a0);
        return 1;
    }
    func_L01_0044FD88(a0, *(s32 *)(p + 0x2EC), 0, 0);
    if (p[0x5F] != 0) {
        if ((*(unsigned long *)(a0 + 0x30) & 0x104100000000ul) != 0x4100000000ul || *(s32 *)(a0 + 0x98) != 0) {
            func_L01_00456BD0(a0, 5);
        }
        if (a0[0x95] == 0) func_L01_00456C98(a0, *(s32 *)(p + 0x2D0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2D4), 10.0f, 1.0f);
        else func_L01_00456C98(a0, *(s32 *)(p + 0x2D8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2DC), 10.0f, 1.0f);
    } else {
        if ((*(unsigned long *)(a0 + 0x30) & 0x104100000000ul) != 0x4100000000ul || *(s32 *)(a0 + 0x98) != 0) {
            func_L01_00456BD0(a0, 3);
        }
        if (a0[0x95] == 0) func_L01_00456C98(a0, *(s32 *)(p + 0x2D0), 0, 0, 0, 0, 1, 0, 0, 1, *(f32 *)(p + 0x2D4), 10.0f, 1.0f);
        else func_L01_00456C98(a0, *(s32 *)(p + 0x2D8), 0, 0, 0, 0, 1, 0, 0, 1, *(f32 *)(p + 0x2DC), 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L20_003FACD8 */

/* localdecomp:start func_L20_003FAF10 */
typedef struct { u8 p0[0x24]; f32 f24; } C_003FAF10;
typedef struct {
    u8 p0[0x24]; C_003FAF10 *p24; u8 p28[4]; f32 f2C; u8 p30[2]; s16 h32; u16 h34;
    u8 p36[0x32]; u8 *p68; u8 p6C[0x2C]; s32 w98; u8 p9C[0x16]; s16 hB2;
} M_003FAF10;
typedef struct {
    u8 p0[0x30]; f32 f30; s16 h34; u8 p36[3]; u8 b39; u8 p3A[4]; u8 b3E; u8 p3F[1]; f32 f40;
    u8 p44[0x14]; u8 b58; u8 p59; u8 b5A; u8 p5B[0x15]; f32 f70; f32 f74; f32 f78; f32 f7C; f32 f80;
    u8 p84[0x18]; f32 f9C; f32 fA0; u8 pA4[8]; s32 wAC; u8 pB0[0xC0]; u8 b170; u8 p171[0x1F];
    f32 f190; f32 f194; u8 p198[4]; f32 f19C; u8 p1A0[8]; u8 b1A8; u8 p1A9[0x2E];
    u8 b1D7; u8 b1D8; u8 b1D9; u8 b1DA; u8 b1DB; u8 p1DC[0x64]; void *w240; u8 p244[0xA8];
    M_003FAF10 *w2EC; u8 p2F0[8]; s32 w2F8; u8 p2FC[0x14]; s32 w310;
} P_003FAF10;
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L20_003FB2A8(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

s32 func_L20_003FAF10(void *arg)
{
    M_003FAF10 *m = (M_003FAF10 *)arg;
    P_003FAF10 *p = (P_003FAF10 *)m->p68;
    u8 one;

    p->f190 = 0.5f;
    p->b170 = 6;
    p->b1A8 = 3;
    p->f19C = 0.15f;
    one = 1;
    p->b1DB = 0xFF;
    p->f194 = 0.5f;
    p->f70 = 0.7f;
    p->f74 = 0.5f;
    p->f78 = 0.75f;
    p->f7C = 1.0f;
    p->f80 = 1.4835298f;
    p->fA0 = 0.34906584f;
    p->f9C = 0.00392f;
    p->b1D7 = one;
    p->b1D8 = 0;
    p->b1D9 = 0;
    p->b1DA = 0;
    if (m->hB2 != 0x25) {
        p->wAC = p->w310;
    }
    func_L01_0045BD78(m, 0.0056000003f, 0.10000001f, 0.010053097f, 0.25132743f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 100;
        p->f30 = 100.0f;
    }
    p->b39 = one;
    p->b3E = one;
    p->f40 = 2.0f;
    p->w2EC = (M_003FAF10 *)func_003C24B0(0x1E00, 0x80);
    if (p->w2EC) {
        p->w240 = p->w2EC;
    }
    func_L01_00456160((u8 *)p->w2EC, (u8 *)m);
    m->h32 = 0xFF;
    m->f2C = m->p24->f24 + m->p24->f24;
    p->w2EC->f2C = p->w2EC->p24->f24 + p->w2EC->p24->f24;
    func_L01_004450F0(m, 1, 0);
    func_L20_003FB2A8(m, 0, 0, 0);
    if (p->w2F8) {
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    }
    return 0;
}
/* localdecomp:end func_L20_003FAF10 */

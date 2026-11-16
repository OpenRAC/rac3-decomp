#include "common.h"

/* NTSC-U counterpart of func_L08_003A7750 (src/levels/08_aquatos/L08_003A4E60.c) */
#include "vu0.h"
extern f32 func_00388800(void *, void *);
#include "vu0.h"

/* localdecomp:start func_L08_003A5990 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 p20[0x11]; u8 b31; u8 p32[0x10]; u8 b42; u8 p43[0x2C]; u8 b6F;
    u8 p70[0x25]; u8 b95; u16 h96;
} M_003A7750;
typedef struct {
    u8 p0[0x220]; vu0_v4 v220; u8 p230[0x10]; u8 v240[0x90]; s32 w2D0; s32 w2D4; u8 p2D8[0x38];
    f32 f310; f32 f314; u8 p318[0x38]; u8 v350[0x64]; f32 f3B4;
} P_003A7750;
extern s32 D_L08_001DEDC0_003A5990;
__asm__(".extern D_L08_001DEDC0_003A5990, 16");
extern u8 D_L08_001E1D40_003A5990[];
extern f32 D_001DE2E0_sda;
__asm__(".extern D_001DE2E0_sda, 4");
extern f32 D_001DE2E4_sda;
__asm__(".extern D_001DE2E4_sda, 4");
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);
extern f32 func_0037E250(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_0037E208(s32, s32);
extern void *func_L01_00460318(void *, void *, u32, u32, s32, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern void func_L01_0044EB78(u8 *, void *, s32, s32, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);

void func_L08_003A5990(void *arg) {
    M_003A7750 *m = arg;
    P_003A7750 *p = *(P_003A7750 **)((u8 *)m + 0x68);
    vu0_v4 out;
    vu0_v4 vel;
    vu0_v4 v;
    s32 t;

    func_00388398(&p->w2D0);
    func_003883C8(&p->w2D4);
    if (m->h96 < 0xFFFF) m->h96++;
    *(vu0_q *)&v = 0;
    v.z = -(func_0037E250(2.5f, 3.5f) * 0.016666668f);
    *(vu0_q *)&vel = *(vu0_q *)&v;
    func_003BDA38(m, 1, &out);
    out.z -= 0.25f;
    if (D_L08_001DEDC0_003A5990 & 1) {
        func_L01_00460318(&out, &vel, 0xCF0000FF, 0xCF, func_0037E208(0x12, 0x16), 0xA0, -10, 1);
    } else {
        func_L01_00460318(&out, &vel, 0x6000FFFF, 0x80, func_0037E208(0x14, 0x18), 0xD2, -10, 1);
    }
    t = func_0037E208(0x14, 0x5A);
    func_L01_00460318(&out, &vel, 0xEFFF7F4F, 0xFF0000, func_0037E208(0xA, 0xF), t, -t, 1);
    if ((m->b42 == 0x14 || m->b42 == 0x16) && m->b95 == 2) {
        func_003BDA38(m, 3, &v);
        p->f3B4 = -func_00388A28(func_00388800(&v, &p->v220), p->v220.z - v.z);
    }
    func_L01_0044B5C8(m, p->v350, 3, 0.03f, 0.3f);
    func_L01_0044EB78((u8 *)m, p->v240, 4, 1, 2.5f);
    if (m->b31 != 0 && func_L01_0040C018(D_L08_001E1D40_003A5990, &m->pos) < 576.0f) {
        func_L01_00444188(m);
        m->b6F = 0x16;
    }
    func_L01_0044B860(m, &p->f310, &p->f314, D_001DE2E0_sda, D_001DE2E4_sda * 0.017453292f * 0.016666668f, -1.0f);
}
/* localdecomp:end func_L08_003A5990 */

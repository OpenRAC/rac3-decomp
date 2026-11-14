/* NTSC-U draft (2026-11-14, Codex worker): C of func_L08_003A5990, the NTSC-U twin of func_L08_003A7750, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 2 words differ with its file's flags.
 */
#include "common.h"

/* localdecomp:start func_L08_003A5990 */
typedef int Q_3A5990 __attribute__((mode(TI)));
typedef union { f32 f[4]; Q_3A5990 q; } V_3A5990;
typedef union { u8 b[0x400]; u16 h[0x200]; s32 i[0x100]; f32 f[0x100]; void *p[0x100]; Q_3A5990 q[0x40]; } O_3A5990;
extern s32 D_L08_001DEDC0;
extern u8 D_L08_001E1D40[];
extern f32 D_001DE2E4_sda, D_001DE2E0_sda;
__asm__(".extern D_001DE2E4_sda, 4");
__asm__(".extern D_001DE2E0_sda, 4");
extern s32 func_00388398(s32 *);
extern s32 func_003883C8(s32 *);
extern f32 func_0037E250(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00460318(void *, void *, u32, u32, s32, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern void func_L01_0044EB78(void *, void *, s32, s32, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);

void func_L08_003A5990(O_3A5990 *m) {
    V_3A5990 pos, velocity, temp;
    O_3A5990 *v = m->p[0x68/4];
    s32 lifetime;
    func_00388398(&v->i[0x2D0/4]);
    func_003883C8(&v->i[0x2D4/4]);
    if (m->h[0x96/2] < 0xFFFF) m->h[0x96/2]++;
    temp.q = 0;
    temp.f[2] = -(func_0037E250(2.5f, 3.5f) * 0.016666668f);
    velocity.q = temp.q;
    func_003BDA38(m, 1, &pos);
    pos.f[2] -= 0.25f;
    if (D_L08_001DEDC0 & 1) {
        func_L01_00460318(&pos, &velocity, 0xCF0000FF, 0xCF, func_0037E208(18, 22), 160, -10, 1);
    } else {
        func_L01_00460318(&pos, &velocity, 0x6000FFFF, 128, func_0037E208(20, 24), 210, -10, 1);
    }
    lifetime = func_0037E208(20, 90);
    func_L01_00460318(&pos, &velocity, 0xEFFF7F4F, 0xFF0000, func_0037E208(10, 15), lifetime, -lifetime, 1);
    if ((m->b[0x42] == 20 || m->b[0x42] == 22) && m->b[0x95] == 2) {
        func_003BDA38(m, 3, &temp);
        v->f[0x3B4/4] = -func_00388A28(func_00388800(&temp, &v->q[0x220/16]), v->f[0x228/4] - temp.f[2]);
    }
    func_L01_0044B5C8(m, (u8 *)v + 0x350, 3, 0.03f, 0.3f);
    func_L01_0044EB78(m, (u8 *)v + 0x240, 4, 1, 2.5f);
    if (m->b[0x31] && func_L01_0040C018(D_L08_001E1D40, &m->q[1]) < 576.0f) {
        func_L01_00444188(m);
        m->b[0x6F] = 22;
    }
    func_L01_0044B860(m, &v->f[0x310/4], &v->f[0x314/4], D_001DE2E0_sda, D_001DE2E4_sda * 0.017453292f * 0.016666668f, -1.0f);
}
/* localdecomp:end func_L08_003A5990 */

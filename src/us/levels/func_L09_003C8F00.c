#include "common.h"

/* NTSC-U counterpart of func_L09_003CA998. */
/* localdecomp:start func_L09_003C8F00 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003C8F00;
typedef struct {
    u8 pad0[0xC0];
    V_003C8F00 f270;
    u8 pad280[0x110 - 0xD0];
    s32 f2E8;
    u8 pad2EC[0x138 - 0x114];
    f32 f310;
} G_003C8F00;
typedef struct {
    u8 pad0[0x2B0];
    u8 f2B0[0x100];
    u8 f3B0[0x6D0 - 0x3B0];
    G_003C8F00 *f6D0;
    u8 pad6D4[0x6F0 - 0x6D4];
    f32 f6F0;
    f32 f6F4;
    u8 pad6F8[0x74C - 0x6F8];
    f32 f74C;
    f32 f750;
} P_003C8F00;
typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1C[0x20 - 0x1C];
    u8 f20;
    u8 pad21[0x68 - 0x21];
    P_003C8F00 *f68;
    u8 pad6C[0xBC - 0x6C];
    u8 fBC;
    u8 padBD[3];
    V_003C8F00 fC0;
    V_003C8F00 fD0;
    V_003C8F00 fE0;
    f32 fF0;
    f32 fF4;
} M_003C8F00;

__asm__(".extern D_L09_001DE9E0, 4");
extern f32 D_L09_001DE9E0;
__asm__(".extern D_L09_001DE9E4, 4");
extern f32 D_L09_001DE9E4;
__asm__(".extern D_L09_001DE9E8, 4");
extern f32 D_L09_001DE9E8;
__asm__(".extern D_L09_001DE9F0, 4");
extern f32 D_L09_001DE9F0;
__asm__(".extern D_L09_001DE9F4, 4");
extern f32 D_L09_001DE9F4;
extern f32 D_001A6E40[];
extern void func_0039FE80(s32, s32, void *);
extern float func_0037E250(float, float);
extern void func_003886E8(void *, void *, f32);
extern int func_0037E208(int, int);
extern void func_L09_003C6408(void *, void *, s32, s32, s32);
extern s32 func_00388398(void *);
extern float func_00389380(float, float);
extern f32 func_L01_004455F0(s32, f32, s32, f32, f32, f32, s32);
extern void func_003BEA80(void *, void *);
extern void func_L09_003C8C10(void *, s32);
extern void func_L09_003C8D50(void *, s32);
void func_L09_003C8F00(M_003C8F00 *m) {
    V_003C8F00 v0;
    V_003C8F00 v1;
    P_003C8F00 *p = m->f68;
    G_003C8F00 *g = p->f6D0;

    if (m->fBC == 11) {
        if (g->f2E8 >= 0xB2) {
            if (g->f2E8 == 0xB4) {
                func_0039FE80(10, 0, m);
            }
            func_003886E8(&v0, &m->fC0, func_0037E250(-1.5f, 1.5f));
            func_003886E8(&v1, &m->fD0, func_0037E250(-1.5f, 1.5f));
            vec_add_ba(&v0, &v0, &v1);
            func_003886E8(&v1, &m->fE0, func_0037E250(-1.0f, 0.0f));
            vec_add_ab(&v0, &v0, &v1);
            func_L09_003C6408(m, &v0, 5, func_0037E208(0x14, 0x23), 2);
        }
        m->fF0 += 0.003f;
        m->fF4 += 0.003f;
        m->f18 -= 0.01f;
        g->f310 = 0.0f;
        qzero(&g->f270);
        func_00388398(&g->f2E8);
    }
    p->f6F4 = g->f310 * D_L09_001DE9E0;
    p->f6F0 = func_00389380(p->f6F0, p->f6F4);
    if (m->f20 == 2) {
        func_L01_004455F0((s32)&p->f74C, D_001A6E40[0] * D_L09_001DE9E8, (s32)&p->f750,
                          D_L09_001DE9F0 * 0.017453292f * 0.00027777778f, D_L09_001DE9F4 * 0.017453292f * 0.00027777778f, 0.0f, 0);
        if (D_L09_001DE9E4 < p->f74C) {
            p->f74C = D_L09_001DE9E4;
        }
        if (p->f74C < -D_L09_001DE9E4) {
            p->f74C = -D_L09_001DE9E4;
        }
    }
    qzero(&v0);
    v0.x = p->f6F0;
    v0.y = p->f74C;
    func_003BEA80(p->f2B0, &v0);
    qzero(&v0);
    v0.x = p->f6F0;
    v0.y = -p->f74C;
    func_003BEA80(p->f3B0, &v0);
    func_L09_003C8C10(p, 0);
    func_L09_003C8C10(p, 1);
    func_L09_003C8D50(p, 2);
    func_L09_003C8D50(p, 3);
}
/* localdecomp:end func_L09_003C8F00 */

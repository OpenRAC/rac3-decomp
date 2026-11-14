#include "common.h"

/* NTSC-U counterpart of func_L39_00530B00 (src/levels/shared/L39_00530B00.c): 148 -> 178; 150 -> 180; 0.0004 -> 0.000277778 */
/* localdecomp:start func_L39_005304B8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00530B00;
typedef struct {
    u8 pad0[0x270];
    V_00530B00 f270;
    u8 pad280[0x2D8 - 0x280];
    u8 *f2D8;
    u8 pad2DC[0x2E8 - 0x2DC];
    s32 f2E8;
    u8 pad2EC[0x310 - 0x2EC];
    f32 f310;
} G_00530B00;
typedef struct {
    u8 pad0[0x2B0];
    u8 f2B0[0x100];
    u8 f3B0[0x6D0 - 0x3B0];
    G_00530B00 *f6D0;
    u8 pad6D4[0x6F0 - 0x6D4];
    f32 f6F0;
    f32 f6F4;
    u8 pad6F8[0x74C - 0x6F8];
    f32 f74C;
    f32 f750;
} P_00530B00;
typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1C[0x68 - 0x1C];
    P_00530B00 *f68;
    u8 pad6C[0xBC - 0x6C];
    u8 fBC;
    u8 padBD[3];
    V_00530B00 fC0;
    V_00530B00 fD0;
    V_00530B00 fE0;
    f32 fF0;
    f32 fF4;
} M_00530B00;
__asm__(".extern D_L39_0024AD2C, 4");
extern f32 D_L39_0024AD2C;
__asm__(".extern D_L39_0024AD30, 4");
extern f32 D_L39_0024AD30;
__asm__(".extern D_L39_0024AD34, 4");
extern f32 D_L39_0024AD34;
__asm__(".extern D_L39_0024AD3C, 4");
extern f32 D_L39_0024AD3C;
__asm__(".extern D_L39_0024AD40, 4");
extern f32 D_L39_0024AD40;
__asm__(".extern D_L39_0024AC20_005304B8, 8");
extern u8 D_L39_0024AC20_005304B8[] __attribute__((section(".sdata")));
extern void func_L39_005F0CE0(s32, s32, void *);
extern f32 func_L39_005B2510(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L09_003C6408(void *, void *, s32, s32, s32);
extern s32 func_00388398(void *);
extern f32 func_00389380(f32, f32);
extern f32 func_L01_004455F0(s32, f32, s32, f32, f32, f32, s32);
extern void func_003BEA80(void *, void *);
extern void func_L09_003C8C10(void *, s32);
extern void func_L09_003C8D50(void *, s32);
extern void func_L39_00668148(int a, u8 *b, int c, void *d);
void func_L39_005304B8(M_00530B00 *m) {
    V_00530B00 v0;
    V_00530B00 v1;
    P_00530B00 *p = m->f68;
    G_00530B00 *g = p->f6D0;

    if (m->fBC == 11) {
        if (g->f2E8 >= 0xB2) {
            if (g->f2E8 == 0xB4) {
                func_L39_005F0CE0(10, 0, m);
            }
            func_003886E8(&v0, &m->fC0, func_L39_005B2510(-1.5f, 1.5f));
            func_003886E8(&v1, &m->fD0, func_L39_005B2510(-1.5f, 1.5f));
            vec_add_ba(&v0, &v0, &v1);
            func_003886E8(&v1, &m->fE0, func_L39_005B2510(-1.0f, 0.0f));
            vec_add_ab(&v0, &v0, &v1);
            func_L09_003C6408(m, &v0, 5, func_L39_005B24C8(0x14, 0x23), 2);
        }
        m->fF0 += 0.003f;
        m->fF4 += 0.003f;
        m->f18 -= 0.01f;
        g->f310 = 0.0f;
        qzero(&g->f270);
        func_00388398(&g->f2E8);
    }
    p->f6F4 = g->f310 * D_L39_0024AD2C;
    p->f6F0 = func_00389380(p->f6F0, p->f6F4);
    if (g->f2D8 != 0) {
        func_L01_004455F0((s32)&p->f74C, *(f32 *)(g->f2D8 + 0x110) * D_L39_0024AD34, (s32)&p->f750,
                          D_L39_0024AD3C * 0.017453292f * 0.000277777785f, D_L39_0024AD40 * 0.017453292f * 0.000277777785f, 0.0f, 0);
        if (D_L39_0024AD30 < p->f74C) {
            p->f74C = D_L39_0024AD30;
        }
        if (p->f74C < -D_L39_0024AD30) {
            p->f74C = -D_L39_0024AD30;
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
    func_L39_00668148((int)g, (u8 *)m, 5, D_L39_0024AC20_005304B8);
}
/* localdecomp:end func_L39_005304B8 */

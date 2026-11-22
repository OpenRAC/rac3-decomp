#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct {
    u8 pad0[0x78]; f32 f78; f32 f7C; f32 f80; u8 pad84[0x9C - 0x84]; f32 f9C;
    u8 padA0[4]; f32 fA4; s32 wA8; u8 padAC[0x110 - 0xAC]; f32 a110[2]; f32 f118;
    u8 pad11C[0x300 - 0x11C]; s32 w300; u8 pad304[0x310 - 0x304]; s32 w310; u8 a314[0x10];
    f32 f324; f32 f328; u8 pad32C[0x334 - 0x32C]; s32 w334; u8 pad338[8]; s32 w340; f32 f344;
    u8 pad348[8]; u8 a350[0x28]; f32 f378; u8 pad37C[0x39C - 0x37C]; f32 f39C;
} V_3B3BB8;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 pad20[0x48]; V_3B3BB8 *vars; u8 pad6C[0xF4 - 0x6C]; s32 wF4;
} M_3B3BB8;

/* localdecomp:start func_L23_003B22B0 */
extern f32 D_L23_001DE328_003B22B0[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE328_003B22B0, 4");
extern f32 D_L23_001DE338_003B22B0[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE338_003B22B0, 4");
extern f32 D_L23_001DE348[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE348, 4");
extern f32 D_L23_001DE358[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE358, 4");
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern f32 func_003BEC60(f32 *, void *, f32, f32, f32, f32);
extern s32 func_L23_003B25A0(u8 *, s32, f32 *, void *, void *, s32);
extern void func_L01_00457590(void *, void *, f32);
extern s32 func_L01_00458A08(void *, f32);
extern f32 func_L01_0040C040(void *a, void *b);
extern void func_L01_00457708(void *, f32);
extern void func_L01_00457440(void *, void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern f32 func_00388770(f32 *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_L01_00445758(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);

void func_L23_003B22B0(M_3B3BB8 *m, V4 *target, s32 mode, f32 speed)
{
    V_3B3BB8 *v = m->vars;
    V4 t;
    f32 d;

    v->w300 = mode;
    func_L01_00458A70(m, D_L23_001DE338_003B22B0[mode], D_L23_001DE328_003B22B0[mode], D_L23_001DE358[mode], D_L23_001DE348[mode]);
    if (v->w300 == 3) {
        v->wA8 |= 0x514;
        v->f78 = 20.0f;
        v->f9C = 0.0f;
        v->f7C = 20.0f;
        v->f80 = 1.5707964f;
        v->f324 -= 0.0027222224f;
        func_003BEC60(&v->f328, &v->f324, v->f39C, 0.0055555557f, 0.0055555557f, 0.33333334f);
        target->z = v->f378 + v->f328;
    } else {
        v->wA8 &= ~0x514;
        v->f9C = 0.0027222224f;
        v->f78 = 1.5f;
        v->f7C = 1.5f;
        v->f80 = 1.3962634f;
    }
    t = *target;
    if (v->w300 == 3) {
        func_L23_003B25A0((u8 *)m, v->w310, &t.x, v->a350, v->a314, 0);
        func_L01_00457590(m, &t, speed);
        func_L01_00458A08(m, speed);
    } else {
        if (mode == 0 || func_L01_0040C040(&m->pos, target) < v->fA4 * v->fA4) {
            func_L01_00457708(m, speed);
        } else {
            func_L01_00457440(m, &t);
        }
        if (0.0f < v->f118) {
            v->f118 = 0.0f;
        }
        m->pos.z = func_003BE7F0(&m->pos, 0, 0, 0.5f);
        d = func_00388770(v->a110);
        if (D_L23_001DE328_003B22B0[v->w300] < d) {
            func_003886E8(v->a110, v->a110, D_L23_001DE328_003B22B0[v->w300] / d);
        }
    }
    if (mode == 3) {
        if (v->w334 != 0) {
            func_L01_00445758((u8 *)&m->wF4, (u8 *)&v->w340, v->f344, 0.0034906587f, 0.0034906587f, 0.20943953f, 0);
        } else {
            func_L01_00445758((u8 *)&m->wF4, (u8 *)&v->w340, 0.0f, 0.0034906587f, 0.0034906587f, 0.20943953f, 0);
        }
    } else {
        v->w340 = 0;
        m->wF4 = 0;
    }
}
/* localdecomp:end func_L23_003B22B0 */

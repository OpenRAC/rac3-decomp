#include "common.h"

typedef struct {
    f32 value;
    s32 pad;
} Item_408D28;

LINKER_REMNANT("asm/levels", func_L01_0040A8B8);

/* localdecomp:start func_L01_0040A8C0 */
#include "vu0.h"
typedef struct {
    vu0_v4 pos[4];
    s32 color[4];
    f32 uv[4][2];
    u8 data[32];
} Packet_0040A8C0;
typedef struct {
    vu0_v4 p0;
    vu0_v4 p1;
    Packet_0040A8C0 pkt;
    vu0_v4 dir;
    vu0_v4 view;
    vu0_v4 side;
} Frame_0040A8C0;
extern vu0_v4 D_L01_001E29C0;
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, void *, s32);
void func_L01_0040A8C0(vu0_v4 *a, vu0_v4 *b, s32 tex, s32 arg, f32 w0, f32 ratio, f32 scroll, s32 c0, s32 c1, s32 c2, s32 c3) {
    Frame_0040A8C0 f;
    f32 w1, one, zero, u0, u1;
    one = 1.0f;
    f.p0 = *a;
    f.p1 = *b;
    func_003D93B0(&f.pkt, tex, arg, 128);
    vec_sub_ba(&f.dir, &f.p1, &f.p0);
    vec_sub_ab(&f.view, &D_L01_001E29C0, &f.p0);
    func_0038CF68(&f.view, &f.view, one);
    func_0038CE90(&f.side, &f.dir, &f.view);
    func_0038CF68(&f.side, &f.side, w0);
    vec_add_ba(&f.pkt.pos[0], &f.side, &f.p0);
    func_0038CF68(&f.side, &f.side, -w0);
    vec_add_ba(&f.pkt.pos[1], &f.side, &f.p0);
    func_0038CE90(&f.side, &f.dir, &f.view);
    w1 = w0 * ratio;
    func_0038CF68(&f.side, &f.side, w1);
    vec_add_ba(&f.pkt.pos[2], &f.side, &f.p1);
    func_0038CF68(&f.side, &f.side, -w1);
    vec_add_ab(&f.pkt.pos[3], &f.side, &f.p1);
    zero = 0.0f;
    u0 = scroll + zero;
    u1 = scroll + one;
    f.pkt.pos[3].w = one;
    f.pkt.pos[2].w = one;
    f.pkt.pos[1].w = one;
    f.pkt.pos[0].w = one;
    f.pkt.uv[0][0] = u0;
    f.pkt.uv[0][1] = zero;
    f.pkt.uv[1][0] = u0;
    f.pkt.uv[1][1] = one;
    f.pkt.uv[2][0] = u1;
    f.pkt.uv[2][1] = zero;
    f.pkt.uv[3][0] = u1;
    f.pkt.uv[3][1] = one;
    f.pkt.color[0] = c0;
    f.pkt.color[1] = c1;
    f.pkt.color[2] = c2;
    f.pkt.color[3] = c3;
    func_003D2DA0(&f.pkt, 0, 0);
}
/* localdecomp:end func_L01_0040A8C0 */

INCLUDE_ASM("asm/levels", func_L01_0040AAC8);

LINKER_REMNANT("asm/levels", func_L01_0040AF50);

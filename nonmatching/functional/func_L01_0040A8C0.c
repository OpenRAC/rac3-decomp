/* functional: high. Instruction-for-instruction the same calls and stores as retail; only register assignment and scheduling of the float moves differ. Vector ops are plain C (xyz only, w from the first operand) so no asm; formerly needed -mvu0-use-vf0-vf2 on the file flags to compile the vector helpers. */
#include "vu0.h"
/* plain-C stand-ins for the vector library's vsub.xyz/vadd.xyz: x/y/z of a op b, w kept from a */
static void fvsub3_L01(void *d, void *a, void *b) {
    vu0_v4 r = *(vu0_v4 *)a;
    r.x = r.x - ((vu0_v4 *)b)->x;
    r.y = r.y - ((vu0_v4 *)b)->y;
    r.z = r.z - ((vu0_v4 *)b)->z;
    *(vu0_v4 *)d = r;
}
static void fvadd3_L01(void *d, void *a, void *b) {
    vu0_v4 r = *(vu0_v4 *)a;
    r.x = r.x + ((vu0_v4 *)b)->x;
    r.y = r.y + ((vu0_v4 *)b)->y;
    r.z = r.z + ((vu0_v4 *)b)->z;
    *(vu0_v4 *)d = r;
}
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
void func_L01_0040A8C0(vu0_v4 *a, vu0_v4 *b, s32 tex, s32 arg, s32 c0, s32 c1, s32 c2, s32 c3, f32 w0, f32 ratio, f32 scroll) {
    Frame_0040A8C0 f;
    f32 w1, one, zero, end;
    one = 1.0f;
    w1 = w0 * ratio;
    f.p0 = *a;
    f.p1 = *b;
    func_003D93B0(&f.pkt, tex, arg, 128);
    fvsub3_L01(&f.dir, &f.p1, &f.p0);
    fvsub3_L01(&f.view, &D_L01_001E29C0, &f.p0);
    func_0038CF68(&f.view, &f.view, one);
    func_0038CE90(&f.side, &f.dir, &f.view);
    func_0038CF68(&f.side, &f.side, w0);
    fvadd3_L01(&f.pkt.pos[0], &f.side, &f.p0);
    func_0038CF68(&f.side, &f.side, -w0);
    fvadd3_L01(&f.pkt.pos[1], &f.side, &f.p0);
    func_0038CE90(&f.side, &f.dir, &f.view);
    func_0038CF68(&f.side, &f.side, w1);
    fvadd3_L01(&f.pkt.pos[2], &f.side, &f.p1);
    func_0038CF68(&f.side, &f.side, -w1);
    zero = 0.0f;
    end = scroll + one;
    fvadd3_L01(&f.pkt.pos[3], &f.side, &f.p1);
    scroll = scroll + zero;
    f.pkt.uv[3][1] = one;
    f.pkt.uv[1][0] = scroll;
    f.pkt.color[0] = c0;
    f.pkt.color[1] = c1;
    f.pkt.color[2] = c2;
    f.pkt.color[3] = c3;
    f.pkt.pos[3].w = one;
    f.pkt.pos[2].w = one;
    f.pkt.pos[1].w = one;
    f.pkt.pos[0].w = one;
    f.pkt.uv[0][0] = scroll;
    f.pkt.uv[1][1] = one;
    f.pkt.uv[2][1] = zero;
    f.pkt.uv[3][0] = end;
    f.pkt.uv[0][1] = zero;
    f.pkt.uv[2][0] = end;
    func_003D2DA0(&f.pkt, 0, 0);
}

/* functional: high. Same calls and stores as retail; register allocation and scheduling differ. The packet is 0x90 bytes as retail's frame has it (sp+0x40..0xCF): func_003D93B0 fills +0x70..+0x8F, which the earlier 0x80-byte struct let it write past the frame's locals into the saved registers. f.m[1].w and f.m[3].w are stored explicitly after the vector ops, so the helpers' w lane does not matter. */
#include "vu0.h"
typedef struct {
    vu0_v4 pos[4];
    s32 color[4];
    f32 uv[4][2];
    u8 data[32]; /* +0x70..+0x8F: func_003D93B0 stores 64-bit words at +0x70/+0x78/+0x80/+0x88 */
} Packet_0040A4A0;
typedef struct {
    vu0_v4 m[4];
    Packet_0040A4A0 pkt;
} Frame_0040A4A0;
extern vu0_v4 D_L01_001E29C0;
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, void *, s32);
void func_L01_0040A4A0(u8 *obj, vu0_v4 *pts, s32 n, s32 colA, s32 colB, s32 tex, f32 lenC, f32 lenA, f32 scroll) {
    Frame_0040A4A0 f;
    f32 one, zero, end;
    s32 i;
    func_0038CE20(&f.m[0], obj + 0xC0, -1.0f);
    vec_sub_ba(&f.m[1], &D_L01_001E29C0, obj + 0x10);
    func_0038CE90(&f.m[2], &f.m[1], &f.m[0]);
    func_0038CF68(&f.m[2], &f.m[2], lenC);
    func_0038CF68(&f.m[0], &f.m[0], lenA);
    f.m[0].w = 0.0f;
    f.m[1].w = 0.0f;
    f.m[2].w = 0.0f;
    func_003D93B0(&f.pkt, tex, 1, 128);
    one = 1.0f;
    zero = 0.0f;
    end = scroll + one;
    f.pkt.uv[3][1] = one;
    scroll = scroll + zero;
    f.pkt.uv[2][1] = zero;
    f.pkt.uv[0][1] = zero;
    f.pkt.uv[1][0] = scroll;
    f.pkt.uv[3][0] = end;
    f.pkt.uv[0][0] = scroll;
    f.pkt.uv[2][0] = end;
    f.pkt.uv[1][1] = one;
    for (i = 0; i < 4; i++) {
        qzero(&f.pkt.pos[i]);
        if (i < 2) {
            f.pkt.pos[i].x = 0.0f;
        } else {
            f.pkt.pos[i].x = one;
        }
        f.pkt.pos[i].y = 0.0f;
        if (i & 1) {
            f.pkt.pos[i].z = one;
        } else {
            f.pkt.pos[i].z = -1.0f;
        }
        f.pkt.pos[i].w = one;
        f.pkt.color[i] = (i > 1) ? colB : colA;
    }
    for (i = 0; i < n; i++) {
        func_0038D000(&f.m[3], &pts[i], obj + 0xC0);
        vec_add_ab(&f.m[3], &f.m[3], obj + 0x10);
        f.m[3].w = 1.0f;
        func_003D2DA0(&f.pkt, &f.m[0], 0);
    }
}

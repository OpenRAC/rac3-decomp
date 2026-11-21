#include "common.h"

/* NTSC-U counterpart of func_003A66D0 (boot_elf). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0D58;
extern f32 func_U_00382938(void);
#include "vu0.h"

/* localdecomp:start func_U_003A6590 */
typedef int Quad_003A66D0 __attribute__((mode(TI)));
typedef struct Packet_003A66D0 {
    f32 pos[4];
    f32 vel[4];
    f32 f20, f24, f28;
    s32 color0, color1, time0, time1, flags, time2, time3;
    u8 pad48[4];
    s32 kind;
} Packet_003A66D0;
extern s32 D_U_001D6FA0[2];
__asm__(".extern D_U_001D6FA0, 8");
extern s32 D_U_001DA090[2];
extern s32 D_U_002257B4[];
extern void func_U_003C3160(u8 *, s32, u8 *);
extern void func_U_003A6438(V4_3A0D58 *, V4_3A0D58 *, s32, f32, f32, f32, s32);
extern void func_U_0038D350_003A6590(f32 *, f32 *, f32 *);
extern s32 func_U_0038DF00_003A6590(s32, s32, f32);
extern void func_U_0038D148(f32 *, void *, f32);
extern f32 func_U_003828E0(f32, f32);
extern s32 func_U_00382898(s32, s32);
extern void func_U_003A85C0(s32, s32);
extern void func_U_003A8520(s32, u8 *);
void func_U_003A6590(u8 *p, s32 n, s32 special) {
    f32 pos[4] __attribute__((aligned(16)));
    f32 off[4] __attribute__((aligned(16)));
    f32 mat[16] __attribute__((aligned(16)));
    Packet_003A66D0 packet __attribute__((aligned(16)));
    f32 f, j, e, g, a, d, h, c, b;
    s32 color0, color1, time0, time1;
    f32 *row;

    func_U_003C3160(p, 0, (u8 *)mat);
    row = (f32 *)D_U_001D6FA0 + n * 4;
    func_U_0038D350_003A6590(pos, row, mat);
    f = p[0x95] * 0.0078125f * row[3];
    time0 = f * 5.0f + 25.0f;
    time1 = f * 5.0f + 15.0f;
    a = f * 0.0599999987f + 0.0599999987f;
    d = f * 0.0399999991f + 0.0399999991f;
    e = f * 0.375f + 0.375f;
    g = f * 0.099999994f + 0.099999994f;
    h = f * 0.0249999985f + 0.0249999985f;
    j = f * 0.0749999955f + 0.0749999955f;
    c = f * 0.0249999911f + 0.174999997f;
    b = f * 0.0f + 0.0749999955f;
    color0 = func_U_0038DF00_003A6590(0x40204080, 0x40205080, f);
    color1 = func_U_0038DF00_003A6590(-1, -1, f);
    if (!special && (s8)p[0x95] >= 0) {
        color0 = (color0 & 0xFFFFFF) | ((((color0 >> 24) * p[0x95]) >> 7) << 24);
        color1 = (color1 & 0xFFFFFF) | ((((color1 >> 24) * p[0x95]) >> 7) << 24);
    }
    func_U_0038D148(off, mat, -a);
    func_U_003A6438((V4_3A0D58 *)pos, (V4_3A0D58 *)off, time0, e, g, j, color0);
    if (!n) {
        func_U_0038D148(off, mat, -d);
        func_U_003A6438((V4_3A0D58 *)pos, (V4_3A0D58 *)off, time1, c, h, b, color1);
    }
    func_U_003A85C0((s32)p, 0x3F3F3F);
    packet.color1 = packet.color0 = func_U_0038DF00_003A6590(0x2F7F, 0x7F7F, func_U_003828E0(0.0f, 1.0f));
    *(Quad_003A66D0 *)packet.pos = *(Quad_003A66D0 *)pos;
    packet.pos[0] += func_U_003828E0(-0.025f, 0.025f);
    packet.pos[1] += func_U_003828E0(-0.025f, 0.025f);
    packet.pos[2] += func_U_003828E0(-0.025f, 0.025f);
    *(Quad_003A66D0 *)packet.vel = *(Quad_003A66D0 *)D_U_001DA090;
    packet.f24 = func_U_00382938();
    packet.f20 = func_U_003828E0(90.0f, 180.0f) * 0.0174532924f * 0.0166666675f;
    packet.kind = 5;
    packet.flags = 1;
    if (special) {
        packet.time1 = packet.time0 = func_U_00382898(40, 56);
        packet.time2 = packet.time3 = func_U_00382898(50, 60);
        packet.f28 = func_U_003828E0(0.8f, 1.5f);
        if (p[0x95] > 64) {
            func_U_003A8520((s32)p, (u8 *)&packet);
        }
    } else {
        packet.time1 = packet.time0 = func_U_00382898(31, 63);
        packet.time2 = packet.time3 = func_U_00382898(70, 90);
        packet.f28 = func_U_003828E0(1.0f, 2.0f);
        packet.flags |= ((D_U_002257B4[0] & 1) + 1) * 2;
        func_U_003A8520((s32)p, (u8 *)&packet);
    }
}
/* localdecomp:end func_U_003A6590 */

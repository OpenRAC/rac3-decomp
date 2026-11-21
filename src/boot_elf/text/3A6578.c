#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3A56A8.c's earlier functions (tools/port_from_us.py) */
extern u8 D_001A30B0[];
#define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
extern s32 D_001D6E1C;
extern u8 D_1A3100[];
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_13C170(void);
extern s32 func_12C908(s32);
extern void func_003A5A20(void);
typedef struct { u8 x0; s8 x1; s8 x2; s8 x3; u16 x4; u16 x6; s32 x8; s32 xC; u32 x10; s32 x14; s32 x18; u8 pad[0x60-0x1C]; } S_3A0200;
extern S_3A0200 D_0022D430[];
extern s32 D_0022D8B0[];
extern void func_003C2C38(s32 p);
typedef struct O2_3A02D8 { u8 pad[8]; void *f8; } O2_3A02D8;
typedef struct { u8 pad[0x30]; u8 f30; u8 pad31; s16 f32; u16 f34; u8 pad36[0x63 - 0x36]; u8 f63; u8 pad64[4]; O2_3A02D8 *f68; } O_3A02D8;
typedef struct { O_3A02D8 *f0; u8 pad[0x40]; } S_16C580_3A02D8;
extern S_16C580_3A02D8 D_0016C580_003A5AF8;
extern u32 D_001D54D0;
extern s16 D_001D5BB0[4];
extern s16 D_001D5BB6;
extern s16 D_001D5BB8;
extern s16 D_001D5BBA;
extern s16 D_001D5BBC;
extern O_3A02D8 *func_003C2868_003A5AF8(s32, s32);
extern void func_003A5AA0(void);

typedef struct { u8 p0[0x20]; s16 f20; } S_16C580_3A0D58;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0D58;
extern S_16C580_3A0D58 D_16C580_003A6578;
extern f32 func_00382918(void);
extern void func_003C4FD0(f32 *v, f32 r);
/* localdecomp:start func_003A6578 */
#include "vu0.h"
void func_003A6578(V4_3A0D58 *start, V4_3A0D58 *step, s32 count, f32 a, f32 b, f32 scale, s32 color) {
    extern f32 func_00382918(void);
    extern void func_003C4FD0(f32 *, f32);
    extern void func_003D98C0(f32 *, s32, s32, s32, f32, f32, f32);
    V4_3A0D58 pos;
    V4_3A0D58 tmp;
    f32 inv;
    s32 i;
    *(vu0_q *)&pos = *(vu0_q *)start;
    inv = 1.0f / count;
    for (i = 0; i < count; i++) {
        f32 value = a + (b - a) * ((f32)i * inv);
        f32 random = func_00382918();
        *(vu0_q *)&tmp = *(vu0_q *)&pos;
        func_003C4FD0((f32 *)&tmp, scale);
        func_003D98C0((f32 *)&tmp, D_16C580_003A6578.f20 == 2 ? 5 : 0x2E, color, 1, value, 0.0f, random);
        vec_add_ab(&pos, &pos, step);
    }
}
/* localdecomp:end func_003A6578 */

/* localdecomp:start func_003A66D0 */
typedef int Quad_003A66D0 __attribute__((mode(TI)));
typedef struct Packet_003A66D0 {
    f32 pos[4];
    f32 vel[4];
    f32 f20, f24, f28;
    s32 color0, color1, time0, time1, flags, time2, time3;
    u8 pad48[4];
    s32 kind;
} Packet_003A66D0;
extern s32 D_001D6FA0[2];
__asm__(".extern D_001D6FA0, 8");
extern s32 D_001DA010[2];
extern s32 D_00225734[];
extern void func_003C3278(u8 *, s32, u8 *);
extern void func_003A6578(V4_3A0D58 *, V4_3A0D58 *, s32, f32, f32, f32, s32);
extern void func_0038D408_003A66D0(f32 *, f32 *, f32 *);
extern s32 func_0038DFB8_003A66D0(s32, s32, f32);
extern void func_0038D200(f32 *, void *, f32);
extern f32 func_003828C0(f32, f32);
extern s32 func_00382878(s32, s32);
extern void func_003A8708(s32, s32);
extern void func_003A8668(s32, u8 *);
void func_003A66D0(u8 *p, s32 n, s32 special) {
    f32 pos[4] __attribute__((aligned(16)));
    f32 off[4] __attribute__((aligned(16)));
    f32 mat[16] __attribute__((aligned(16)));
    Packet_003A66D0 packet __attribute__((aligned(16)));
    f32 f, j, e, g, a, d, h, c, b;
    s32 color0, color1, time0, time1;
    f32 *row;

    func_003C3278(p, 0, (u8 *)mat);
    row = (f32 *)D_001D6FA0 + n * 4;
    func_0038D408_003A66D0(pos, row, mat);
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
    color0 = func_0038DFB8_003A66D0(0x40204080, 0x40205080, f);
    color1 = func_0038DFB8_003A66D0(-1, -1, f);
    if (!special && (s8)p[0x95] >= 0) {
        color0 = (color0 & 0xFFFFFF) | ((((color0 >> 24) * p[0x95]) >> 7) << 24);
        color1 = (color1 & 0xFFFFFF) | ((((color1 >> 24) * p[0x95]) >> 7) << 24);
    }
    func_0038D200(off, mat, -a);
    func_003A6578((V4_3A0D58 *)pos, (V4_3A0D58 *)off, time0, e, g, j, color0);
    if (!n) {
        func_0038D200(off, mat, -d);
        func_003A6578((V4_3A0D58 *)pos, (V4_3A0D58 *)off, time1, c, h, b, color1);
    }
    func_003A8708((s32)p, 0x3F3F3F);
    packet.color1 = packet.color0 = func_0038DFB8_003A66D0(0x2F7F, 0x7F7F, func_003828C0(0.0f, 1.0f));
    *(Quad_003A66D0 *)packet.pos = *(Quad_003A66D0 *)pos;
    packet.pos[0] += func_003828C0(-0.025f, 0.025f);
    packet.pos[1] += func_003828C0(-0.025f, 0.025f);
    packet.pos[2] += func_003828C0(-0.025f, 0.025f);
    *(Quad_003A66D0 *)packet.vel = *(Quad_003A66D0 *)D_001DA010;
    packet.f24 = func_00382918();
    packet.f20 = func_003828C0(90.0f, 180.0f) * 0.0174532924f * 0.0200000014f;
    packet.kind = 5;
    packet.flags = 1;
    if (special) {
        packet.time1 = packet.time0 = func_00382878(40, 56);
        packet.time2 = packet.time3 = (func_00382878(50, 60) * 5 + 2) / 6;
        packet.f28 = func_003828C0(0.8f, 1.5f);
        if (p[0x95] > 64) {
            func_003A8668((s32)p, (u8 *)&packet);
        }
    } else {
        packet.time1 = packet.time0 = func_00382878(31, 63);
        packet.time2 = packet.time3 = (func_00382878(70, 90) * 5 + 2) / 6;
        packet.f28 = func_003828C0(1.0f, 2.0f);
        packet.flags |= ((D_00225734[0] & 1) + 1) * 2;
        func_003A8668((s32)p, (u8 *)&packet);
    }
}
/* localdecomp:end func_003A66D0 */

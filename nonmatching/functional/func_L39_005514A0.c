/* functional: high. PAL twin of the NTSC draft: sends the multiplayer-menu "projectile hit" network/game message (type 3, size 0x24) with the owner player id (|0x40, |0x80 if kind 1), the target id from func_L39_0061D780 (-1 if none), the relative or absolute hit vector, and the projectile position, then marks the projectile as notified (state+0x3B = 1); PAL addresses/names (D_001A5CD0, D_L39_002405E0, func_L39_0061D780) verified; 69 words differ (register allocation). */
#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z; } V3_005514A0;
typedef struct {
    s16 h0;
    u8 b2;
    u8 b3;
    s32 w4;
    s32 w8;
    V3_005514A0 c;
    V3_005514A0 a;
} Buf_005514A0;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x128 - 8];
    s32 f128;
    u8 pad12C[0x170 - 0x12C];
    s32 f170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} G_005514A0;
extern G_005514A0 D_001A5CD0;
extern s32 D_L39_002405E0[];
extern s32 func_L39_0061D780(void *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_005514A0(u8 *self, u8 *other) {
    Buf_005514A0 buf;
    vu0_v4 d;
    u8 *s2;
    u8 *t;
    u8 v;
    V3_005514A0 *p;
    V3_005514A0 *q;

    s2 = *(u8 **)(self + 0x68);
    buf.w4 = D_001A5CD0.f128;
    buf.h0 = 3;
    buf.b3 = 8;
    t = *(u8 **)(s2 + 0x3C);
    v = t[0x2544] | 0x40;
    buf.b2 = v;
    if (s2[0x38] == 1) {
        buf.b2 = v | 0x80;
    }
    buf.w8 = func_L39_0061D780(other);
    if (buf.w8 != -1 && other != 0) {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(d) : "m"(*(vu0_v4 *)(self + 0x10)), "m"(*(vu0_v4 *)(other + 0x10)));
        buf.a.x = d.x;
        buf.a.y = d.y;
        buf.a.z = d.z;
    } else {
        q = (V3_005514A0 *)(self + 0x10);
        buf.a.x = q->x;
        buf.a.y = q->y;
        buf.a.z = q->z;
    }
    p = (V3_005514A0 *)(s2 + 0x10);
    buf.c.x = p->x;
    buf.c.y = p->y;
    buf.c.z = p->z;
    if (D_001A5CD0.f170 == 0) {
        func_0014AD08(D_001A5CD0.b7D4 | 0x80, D_001A5CD0.f4, -1, D_L39_002405E0[0], 0x24, &buf);
    }
    s2[0x3B] = 1;
}

/* NTSC-U draft (Claude wave K): C of func_L39_00550B50, the NTSC-U twin of func_L39_005514A0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 69 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_L39_00550B50", whose code is not the PAL one).
 * Worker's note: 69 diff (hoisting of the D_001A5E50 base into s3 and param/reg numbering; all fields decoded): message sender void f(u8 *self, u8 *other): Buf{s16 h0=3; b2 = (self->0x68->0x3C->0x2544 / 0x40) / (0x80 if state byte 0x38 == 1); b3=8; w4=D_001A5E50.f128; ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L39_00550D48 (src/levels/shared/L39_00550D48.c) */
/* localdecomp:start func_L39_00550B50 */
typedef struct { f32 x, y, z; } V3_00550B50;
typedef struct {
    s16 h0;
    u8 b2;
    u8 b3;
    s32 w4;
    s32 w8;
    V3_00550B50 c;
    V3_00550B50 a;
} Buf_00550B50;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x128 - 8];
    s32 f128;
    u8 pad12C[0x170 - 0x12C];
    s32 f170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} G_00550B50;
extern G_00550B50 D_001A5E50;
extern s32 D_L39_00240760[];
extern s32 func_L39_0061B008(void *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_00550B50(u8 *self, u8 *other) {
    Buf_00550B50 buf;
    vu0_v4 d;
    u8 *s2;
    u8 *t;
    u8 v;
    V3_00550B50 *p;
    V3_00550B50 *q;

    s2 = *(u8 **)(self + 0x68);
    buf.w4 = D_001A5E50.f128;
    buf.h0 = 3;
    buf.b3 = 8;
    t = *(u8 **)(s2 + 0x3C);
    v = t[0x2544] | 0x40;
    buf.b2 = v;
    if (s2[0x38] == 1) {
        buf.b2 = v | 0x80;
    }
    buf.w8 = func_L39_0061B008(other);
    if (buf.w8 != -1 && other != 0) {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(d) : "m"(*(vu0_v4 *)(self + 0x10)), "m"(*(vu0_v4 *)(other + 0x10)));
        buf.a.x = d.x;
        buf.a.y = d.y;
        buf.a.z = d.z;
    } else {
        q = (V3_00550B50 *)(self + 0x10);
        buf.a.x = q->x;
        buf.a.y = q->y;
        buf.a.z = q->z;
    }
    p = (V3_00550B50 *)(s2 + 0x10);
    buf.c.x = p->x;
    buf.c.y = p->y;
    buf.c.z = p->z;
    if (D_001A5E50.f170 == 0) {
        func_0014AD08(D_001A5E50.b7D4 | 0x80, D_001A5E50.f4, -1, D_L39_00240760[0], 0x24, &buf);
    }
    s2[0x3B] = 1;
}
/* localdecomp:end func_L39_00550B50 */

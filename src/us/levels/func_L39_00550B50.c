#include "common.h"

/* NTSC-U counterpart of func_L39_005514A0 (src/levels/shared/L39_00550D48.c) */
#include "vu0.h"
extern void func_L39_00550B50(u8 *, u8 *);
#include "vu0.h"

/* localdecomp:start func_L39_00550B50 */
#include "vu0.h"

typedef struct { f32 x, y, z; } V3_005514A0;
typedef struct {
    s16 h0;
    u8 b2;
    u8 b3;
    s32 w4;
    u32 w8;
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
extern G_005514A0 D_001A5E50;
extern s32 D_L39_00240760_00550B50;
extern s32 func_L39_0061B008_00550B50(void *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

static __inline__ void v3copy_005514A0(V3_005514A0 *d, V3_005514A0 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

void func_L39_00550B50(u8 *self, u8 *other) {
    Buf_005514A0 buf;
    vu0_v4 d;
    u8 *s2;
    u8 *t;
    u8 v;

    s2 = *(u8 **)(self + 0x68);
    t = *(u8 **)(s2 + 0x3C);
    buf.w4 = D_001A5E50.f128;
    buf.h0 = 3;
    buf.b3 = 8;
    v = t[0x2544] | 0x40;
    buf.b2 = v;
    if (s2[0x38] == 1) {
        buf.b2 = v | 0x80;
    }
    buf.w8 = func_L39_0061B008_00550B50(other);
    if (buf.w8 != 0xFFFFFFFF && other != 0) {
        vec_sub_ab(&d, self + 0x10, other + 0x10);
        v3copy_005514A0(&buf.a, (V3_005514A0 *)&d);
    } else {
        v3copy_005514A0(&buf.a, (V3_005514A0 *)(self + 0x10));
    }
    v3copy_005514A0(&buf.c, (V3_005514A0 *)(s2 + 0x10));
    if (D_001A5E50.f170 == 0) {
        func_0014AD08(D_001A5E50.b7D4 | 0x80, D_001A5E50.f4, -1, D_L39_00240760_00550B50, 0x24, &buf);
    }
    s2[0x3B] = 1;
}
/* localdecomp:end func_L39_00550B50 */

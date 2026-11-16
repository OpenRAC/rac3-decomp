#include "common.h"

/* NTSC-U counterpart of func_L39_006670C0 (src/levels/shared/L39_00666F88.c) */
/* localdecomp:start func_L39_006647E8 */
typedef struct { f32 x, y, z; } V3_006670C0;
typedef struct {
    V3_006670C0 a;
    V3_006670C0 b;
    s32 c;
    s32 d;
    u8 flags;
} Buf_006670C0;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x168];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} Hud_006670C0;
__asm__(".extern D_L39_00240734, 16");
extern s32 D_L39_00240734;
extern Hud_006670C0 D_001A5E50;
extern void func_00388440(void *, s32, s32);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

static __inline__ void cp_006670C0(V3_006670C0 *d, V3_006670C0 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}
void func_L39_006647E8(u8 *obj, s32 a1, s32 a2, s32 a3, s32 a4) {
    Buf_006670C0 s;
    if (a4) {
        func_00388440(&s, 0, 12);
        cp_006670C0(&s.b, (V3_006670C0 *)(obj + 0x210));
    } else {
        cp_006670C0(&s.a, (V3_006670C0 *)(obj + 0x230));
        cp_006670C0(&s.b, (V3_006670C0 *)(obj + 0x240));
    }
    s.d = *(s32 *)obj;
    s.c = a1;
    if (a2) {
        s.flags = 1;
    } else if (a4) {
        s.flags = 4;
    } else {
        s.flags = 0;
    }
    if (obj[0x300]) {
        s.flags |= 8;
    }
    if (a3) {
        s.flags |= 2;
    }
    if (D_001A5E50.w170 == 0) {
        func_0014AD08(D_001A5E50.b7D4 | 0x10, D_001A5E50.w4, -1, D_L39_00240734, 0x24, &s);
    }
}
/* localdecomp:end func_L39_006647E8 */

#include "common.h"

/* localdecomp:start func_L39_006B6890 */
typedef struct O_006B6890 O_006B6890;
typedef struct {
    u8 pad0[0x30];
    void (*f30)(O_006B6890 *, f32 *, f32 *);
} V_006B6890;
struct O_006B6890 {
    u8 pad0[0x60];
    V_006B6890 *vt;
};
typedef struct {
    u8 pad0[0x110];
    O_006B6890 *f110[(0x290 - 0x110) / 4];
    s32 f290;
    u8 pad294[0x14];
    char f2A8[0x70];
    s32 f318;
    s32 f31C;
} S_006B6890;
typedef struct {
    u8 pad0[0x284];
    s32 f284;
} G_006B6890;

__asm__(".extern D_L39_00247914, 16");
extern G_006B6890 *D_L39_00247914;
extern char D_L39_002490D8[];
void func_L39_00689F00(void *, s32, f32, f32, f32, f32, f32, f32, s32, s32);
s32 func_L39_0068B1E0(void *, s32);
s32 func_L39_0068B2F8(void *, s32, s32);
s32 func_L39_0068AEF8(void *, s32);
s32 func_L39_00687450(void *, void *, void *, s32, s32, s32, s32);
s32 func_001205B0(void *, void *);

s32 func_L39_006B6890(S_006B6890 *p, s32 a1) {
    f32 x;
    f32 y;
    s32 ok;

    if (p->f290 >= 0) {
        O_006B6890 *o = p->f110[p->f290];
        o->vt->f30(o, &x, &y);
        func_L39_00689F00(p, 0, x, y, 0.2f, 0.07f, 0.0f, 0.0f, 3, 3);
    }
    if (a1 >= 1 && a1 <= 4) {
        if (a1 == 3 || a1 == 4) {
            func_L39_0068B2F8(p, func_L39_0068B1E0(p, -1), a1);
        }
        return 1;
    }
    if (a1 == 7) {
        ok = 0;
        if (p->f290 == 3) {
            p->f318 = 1;
            ok = 1;
        } else if (p->f290 == 2) {
            p->f2A8[0] = 0;
            func_L39_00687450(D_L39_00247914, D_L39_002490D8, p->f2A8, 0, 0x3E, 0, 0);
            p->f318 = 4;
            ok = func_001205B0(p->f2A8, D_L39_002490D8) != 0;
        } else if (p->f290 == 4) {
            p->f318 = 8;
            ok = 1;
        } else if (p->f290 == 5) {
            p->f318 = 0x10;
            ok = 1;
        }
        if (ok == 1) {
            D_L39_00247914->f284 = 0x2C;
            return 1;
        }
    } else if (a1 == 5) {
        if (p->f31C >= 2) {
            return 1;
        }
    }
    return func_L39_0068AEF8(p, a1) == 1;
}
/* localdecomp:end func_L39_006B6890 */

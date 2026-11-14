#include "common.h"

/* NTSC-U counterpart of func_L40_0041DC00 (src/levels/shared/L40_0041DC00.c): 0.084 -> 0.07 */
/* localdecomp:start func_L40_0041D398 */
typedef struct {
    s32 links[8];
    u8 pad20[0xC];
    s32 active;
    s32 target;
    u8 pad34[8];
    s32 src;
} SVars_0041DC00;

typedef struct {
    u8 pad0[0x68];
    void *vars;
    u8 pad6C[0xC];
    s32 color;
    u8 pad7C[0x84];
} SMoby_0041DC00;

extern f32 D_L40_002477D8;
extern SMoby_0041DC00 *D_L40_002485DC;
extern u8 D_L40_00246448[];
extern u8 D_L40_0024644B[];
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_003894A0(s32, s32, f32);

void func_L40_0041D398(SMoby_0041DC00 *moby, s32 reset) {
    SVars_0041DC00 *vars = moby->vars;
    u8 *lo = D_L40_00246448;
    u8 *hi = D_L40_0024644B;
    u8 *c;
    f32 t = 0.5f;
    s32 col;
    s32 i;
    SMoby_0041DC00 *mobys;
    f32 u;

    c = lo;
    if (vars->active < 0) {
        return;
    }
    if (vars->src >= 0) {
        SMoby_0041DC00 *src = &D_L40_002485DC[vars->src];
        t = *(f32 *)src->vars;
        if (0.5f < t) {
            t += 0.0001f;
        }
        if (1.0f < t) {
            t = 1.0f;
        }
        if (t < 0.0f) {
            t = 0.0f;
        }
    }
    col = 0x80FFFFFF;
    if (t < 0.5f) {
        c = lo;
        col = (0x80 << 24) | (lo[2] << 16) | (lo[1] << 8) | lo[0];
    } else if (0.5f < t) {
        c = hi;
        col = (0x80 << 24) | (hi[2] << 16) | (hi[1] << 8) | hi[0];
    }
    if (reset) {
        vars->target = col;
        moby->color = col;
    }
    if (vars->target == moby->color && (t == 0.0f || t == 0.5f || t == 1.0f)) {
        vars->target = col;
        if (col == moby->color) {
            if (t != 0.5f) {
                vars->target = (0x80 << 24) | ((c[2] >> 2) << 16) | ((c[1] >> 2) << 8) | (c[0] >> 2);
            } else {
                vars->target = 0x803F3F3F;
            }
        }
    } else if (t < 0.5f && 0.0f < t) {
        u = t + 0.5f + func_L39_005B2510(-D_L40_002477D8, D_L40_002477D8);
        if (1.0f < u) {
            u = 1.0f;
        }
        if (u < 0.5f) {
            u = 0.5f;
        }
        vars->target = func_003894A0((0x80 << 24) | (lo[2] << 16) | (lo[1] << 8) | lo[0], 0x80FFFFFF, u);
    } else if (0.5f < t) {
        if (t < 1.0f) {
            u = (1.0f - t) + 0.5f + func_L39_005B2510(-D_L40_002477D8, D_L40_002477D8);
            if (1.0f < u) {
                u = 1.0f;
            }
            if (u < 0.5f) {
                u = 0.5f;
            }
            vars->target = func_003894A0((0x80 << 24) | (hi[2] << 16) | (hi[1] << 8) | hi[0], 0x80FFFFFF, u);
        }
    }
    col = func_003894A0(moby->color, vars->target, 0.0700000003f);
    if (col == moby->color) {
        col = vars->target;
    }
    moby->color = col;
    mobys = D_L40_002485DC;
    for (i = 0; i < 8; i++) {
        if (vars->links[i] >= 0) {
            mobys[vars->links[i]].color = col;
        }
    }
}
/* localdecomp:end func_L40_0041D398 */

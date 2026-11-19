/* functional: high. Per-frame update of a multiplayer-menu screen-flash/overlay effect object (type 0x18AB): advances an animation timer in the object state by the elapsed-frames * per-effect rate, and while it runs builds and submits one textured quad per animation step (colours from the effect table, vertices and UVs from the effect's tables) via func_003D2DA0; ends the effect when the timer passes its length. Written from the PAL disassembly. */
#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0055A880;

typedef struct {
    s16 h[4];       /* 0x00 step numbers that use the per-step colour sets */
    u32 col[4][4];  /* 0x08 colour sets, 4 corners each */
    f32 f48;        /* 0x48 timer rate per frame */
    u8 *p4C;        /* 0x4C vertex positions (16 bytes each) */
    u8 *p50;        /* 0x50 per-step 4 x {vertex index, uv index} */
    f32 *p54;       /* 0x54 uv pairs (8 bytes each) */
    s16 h58;        /* 0x58 number of steps */
    s16 pad5A;
    f32 f5C;        /* 0x5C uv scroll rate */
    u8 pad60[0];
} E_0055A880;

typedef struct {
    V_0055A880 pos[4];  /* 0x00 */
    u32 col[4];         /* 0x40 */
    f32 uv[4][2];       /* 0x50 */
    long kind;          /* 0x70 */
    long tex;           /* 0x78 */
    long f80;           /* 0x80 */
    long f88;           /* 0x88 */
    s32 h[4];           /* 0x90 */
} Pkt_0055A880;

extern E_0055A880 D_L39_00472488[];
extern s32 D_0024112C;
extern s32 D_L39_0024D5D0;
extern f32 D_L39_0024B3B0;
extern u8 *func_L39_0061D1D8(s32);
extern long func_L39_00589890(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L39_0055A880(u8 *obj) {
    Pkt_0055A880 pkt;
    u8 *st;
    u8 *pl;
    u8 *pp;
    E_0055A880 *e;
    u32 col;
    s32 idx;
    s32 count;
    s32 kind;
    s32 type;
    s32 now;
    s32 d;
    s32 i;
    s32 j;
    f32 f21;
    f32 f22;
    f32 limit;
    s32 vi;
    s32 ui;

    if (obj == 0) {
        return;
    }
    if (*(s16 *)(obj + 0xAA) != 0x18AB) {
        return;
    }
    if (obj[0x20] == 0xFE || obj[0x20] == 0xFD) {
        return;
    }
    st = *(u8 **)(obj + 0x68);
    if (st == 0) {
        return;
    }
    if (*(f32 *)(st + 0x70) == 0.0f) {
        return;
    }
    pl = func_L39_0061D1D8(*(s32 *)(obj + 0x90));
    if (pl == 0) {
        return;
    }
    pp = *(u8 **)(pl + 0x2524);
    if (*(f32 *)(st + 0x70) == 1.0f) {
        if (pp[0x42] != pp[0x43]) {
            *(f32 *)(st + 0x70) = 0.0f;
            return;
        }
        if (pp[0x42] == 0xFF) {
            *(f32 *)(st + 0x70) = 0.0f;
            return;
        }
    }
    col = 0x808080;
    count = 0x14;
    kind = 1;
    f21 = 1.0f;
    f22 = 1.0f;
    type = pp[0x42];
    if ((u8)(type - 0x17) >= 3) {
        if (type != 0x27) {
            type = *(s16 *)(st + 0x78);
        }
    }
    if (type == 0x17) {
        *(s16 *)(st + 0x78) = type;
        idx = 0;
    } else if (type == 0x18) {
        *(s16 *)(st + 0x78) = type;
        idx = 1;
    } else if (type == 0x19) {
        *(s16 *)(st + 0x78) = type;
        idx = 2;
    } else {
        *(s16 *)(st + 0x78) = 0x27;
        col = 0x408080;
        f22 = 0.7f;
        idx = 3;
        f21 = 1.25f;
        count = 0xC;
        kind = 2;
    }
    e = &D_L39_00472488[idx];
    pkt.h[0] = e->h[0];
    pkt.h[1] = e->h[1];
    pkt.h[2] = e->h[2];
    pkt.h[3] = e->h[3];
    if (*(f32 *)(st + 0x70) == 1.0f) {
        *(V_0055A880 *)(st + 0x00) = *(V_0055A880 *)(*(u8 **)(pl + 0x2524) + 0xC0);
        *(V_0055A880 *)(st + 0x10) = *(V_0055A880 *)(*(u8 **)(pl + 0x2524) + 0xD0);
        *(V_0055A880 *)(st + 0x20) = *(V_0055A880 *)(*(u8 **)(pl + 0x2524) + 0xE0);
        D_L39_0024D5D0 = D_0024112C;
    }
    now = D_0024112C;
    d = now - D_L39_0024D5D0;
    if (!(d > 0)) {
        d = 1;
    }
    *(f32 *)(st + 0x70) = *(f32 *)(st + 0x70) + (f32)d * e->f48;
    D_L39_0024D5D0 = now;
    limit = (f32)(e->h58 * 2);
    if (limit <= *(f32 *)(st + 0x70)) {
        type = (*(u8 **)(pl + 0x2524))[0x42];
        if ((u8)(type - 0x17) < 3) {
            return;
        }
        if (type != 0x27) {
            *(f32 *)(st + 0x70) = 0.0f;
        }
        return;
    }
    pkt.tex = func_L39_00589890(count);
    pkt.f80 = 0xFF90000000000260L;
    pkt.kind = 5;
    pkt.f88 = 0x8000000040L | (kind << 2);
    *(V_0055A880 *)(st + 0x30) = *(V_0055A880 *)(*(u8 **)(pl + 0x2524) + 0x10);
    if (e->h58 <= 0) {
        return;
    }
    for (i = 0; i < e->h58; i++) {
        for (j = 0; j < 4; j++) {
            vi = *(s16 *)(e->p50 + i * 16 + j * 4);
            if (i == pkt.h[0]) {
                pkt.col[j] = e->col[0][j];
            } else if (i == pkt.h[1]) {
                pkt.col[j] = e->col[1][j];
            } else if (i == pkt.h[2]) {
                pkt.col[j] = e->col[2][j];
            } else if (i == pkt.h[3]) {
                pkt.col[j] = e->col[3][j];
            } else {
                pkt.col[j] = 0x50808080;
            }
            pkt.col[j] = ((s32)((f32)(s8)(pkt.col[j] >> 24) * f22) << 24) | col;
            func_0038CE20(&pkt.pos[j], e->p4C + vi * 16, f21);
            ui = *(s16 *)(e->p50 + i * 16 + j * 4 + 2);
            {
                f32 t = *(f32 *)(st + 0x70) * e->f5C;
                f32 one = 1.0f;
                pkt.uv[j][0] = (e->p54[ui * 2] - 0.5f) * D_L39_0024B3B0 + 0.5f;
                pkt.uv[j][1] = (e->p54[ui * 2 + 1] - 0.5f) * D_L39_0024B3B0 + 0.5f + (one - t);
            }
        }
        func_003D2DA0(&pkt, st, 0);
    }
}

#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003A33C0 */
struct Pst_3A33C0;
struct Def_3A33C0;
typedef struct {
    u8 p0[0x24];
    struct Def_3A33C0 * f24;
    u8 p28[0x70];
    s32 f98;
    u8 p9C[0xE];
    s16 hAA;
} Obj_3A33C0;
struct Def_3A33C0 {
    u8 p0[0x10];
    s32 f10;
};
typedef struct {
    u8 p0[0x18];
    f32 f18;
    u8 p1C[0x4];
    u8 b20;
    u8 b21;
    u8 p22[0xF];
    u8 b31;
    u8 p32[0x36];
    struct Pst_3A33C0 * f68;
    u8 p6C[0x3];
    u8 b6F;
    u8 p70[0xC];
    s16 h7C;
    u8 p7E[0x17];
    u8 b95;
    u8 p96[0x2];
    s32 f98;
    u8 p9C[0x16];
    s16 hB2;
    u8 pB4[0xC];
} Mob_3A33C0;
struct Pst_3A33C0 {
    u8 p0[0x30];
    f32 f30;
    u8 p34[0xA];
    u8 b3E;
    u8 p3F[0x1F];
    u8 b5E;
    u8 b5F;
    u8 p60[0x1D0];
    s32 f230;
    s16 h234;
    u8 p236[0x9A];
    s32 f2D0;
    f32 f2D4;
    s32 f2D8;
    f32 f2DC;
    u8 p2E0[0x10];
    Obj_3A33C0 * f2F0;
    Obj_3A33C0 * f2F4;
    u8 p2F8[0xB8];
    s32 f3B0;
    u8 p3B4[0x4];
    u8 * f3B8;
    u8 p3BC[0x4];
    s32 f3C0;
    u8 p3C4[0x2C];
    Obj_3A33C0 * f3F0[8];
    s32 f410;
    s32 f414;
    s32 f418;
    u8 p41C[0x8];
    s32 f424;
    u8 p428[0x4];
    s32 f42C;
    u8 p430[0x10];
};
typedef struct Pst_3A33C0 Pst_3A33C0;
extern u8 *D_L01_001E0100_003A33C0;
__asm__(".extern D_L01_001E0100_003A33C0, 4");
extern s32 D_001D545C;
extern s32 D_L01_001DFB40_003A33C0;
extern u8 D_L01_001E2A40_003A33C0[];
extern u8 D_L01_001D66B0_003A33C0[8];
extern u8 D_001A4C60[];
extern s32 func_L01_003A39A0(Mob_3A33C0 *);
extern void func_003C7C38(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_00367260(void *, s32, s32, void *, void *, s32);
extern void func_003C2880(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00445BE0(s32, s32);
extern void func_L01_003A4320(void *);
extern void func_L01_003A3F68(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, f32, f32, s32, s32, f32, s32, s32, s32);
extern s32 func_L01_00456500(void *, s32);

s32 func_L01_003A33C0(Mob_3A33C0 *a0) {
    Pst_3A33C0 *p;
    s32 n;
    s32 m;
    s32 r;
    u8 *o;
    u8 *hero;

    p = a0->f68;
    if (a0->b20 == 0) {
        if (func_L01_003A39A0(a0) != 0) return 1;
    }
    if (p->f3B0 != -1) {
        o = D_L01_001E0100_003A33C0 + (p->f3B0 << 7);
        if (a0->f18 < *(f32 *)(o + 0x38) && 4.0f < fabs_asm(a0->f18 - *(f32 *)(o + 0x38))) p->f3B0 = -1;
    }
    if (0.0f < p->f30) {
        for (n = 0; n < 8; n++) {
            if (p->f3F0[n] != 0) {
                p->f3F0[n]->f98 = p->f3F0[n]->f24->f10;
                func_003C7C38(p->f3F0[n]);
            }
        }
    }
    if (p->f3C0 != 0 || p->f42C != 0) {
        if (D_001D545C == 1) a0->h7C = 0;
    }
    if (p->f3B8 != 0) {
        if (p->f3B8[0x20] == 0xFE) p->f3B8 = 0;
        else if (p->f3B8[0x20] == 0xFD) p->f3B8 = 0;
    }
    if (a0->b31 != 0) {
        if (func_L01_0040E548(D_L01_001E2A40_003A33C0, (u8 *)a0 + 0x10) < 4096.0f) {
            func_L01_004472C0(a0);
            a0->b6F = 0x3C;
        }
    }
    if (p->b3E == 2) {
        func_L01_003A3F68(a0);
        return 1;
    }
    r = func_L01_00452FB0(a0, (u8 *)p + 0x160, 0, 0, 0);
    if (r != 0) {
        if (r >= 2) {
            if (p->f2F0 != 0 && p->f2F0->hAA == 0x1939) {
                func_L01_00367260(p->f2F0, 0, 0, D_L01_001D66B0_003A33C0, D_L01_001D66B0_003A33C0, 0x2F2020FF);
                func_003C2880(p->f2F0);
                p->f2F0 = 0;
            }
            if (p->f2F4 != 0 && p->f2F4->hAA == 0x1939) {
                func_L01_00367260(p->f2F4, 0, 0, D_L01_001D66B0_003A33C0, D_L01_001D66B0_003A33C0, 0x2F2020FF);
                func_003C2880(p->f2F4);
                p->f2F4 = 0;
            }
        }
        func_003A52A0(6, 0, a0);
        for (m = 0; m < 8; m++) {
            if (p->f3F0[m] != 0) {
                p->f3F0[m]->f98 = 0;
                func_003C7C38(p->f3F0[m]);
            }
        }
        if (a0->b21 != 0xFF) func_L01_00445BE0(a0->b21, 0);
        func_L01_003A4320(a0);
    }
    if (p->b5E != 0) {
        func_L01_003A3F68(a0);
        return 1;
    }
    func_L01_00452860(a0, (u8 *)p + 0x30, 0);
    if (!((*(unsigned long *)((u8 *)a0 + 0x30) & 0x104100000000UL) == 0x4100000000UL && a0->f98 == 0) && 0.0f < p->f30) {
        if (p->b5F != 0) {
            func_L01_00456BD0(a0, 5);
        } else if (D_001D545C != 9 || a0->hB2 == 0xC8 || a0->b95 == 2 || a0->b95 == 4) {
            func_L01_00456BD0(a0, 3);
        }
    }
    if ((a0->hB2 + 8) % 8 == D_L01_001DFB40_003A33C0 % 8) {
        if (p->b5F != 0) {
            if (a0->b95 == 0) {
                func_L01_00456C98(a0, p->f2D0, 0, 0, 0, p->f2D4, 10.0f, 0, 3, 1.0f, 0, 0, 0);
            } else {
                func_L01_00456C98(a0, p->f2D8, 0, 0, 0, p->f2DC, 10.0f, 0, 3, 1.0f, 0, 0, 0);
            }
        } else if (a0->b95 == 0) {
            func_L01_00456C98(a0, p->f2D0, 0, 0, 0, p->f2D4, 10.0f, 0, 1, 1.0f, p->f424 != 0, 0, 0);
            if (p->h234 == 1) {
                func_L01_00456C98(a0, p->f2D0, 0, 0, 0, p->f2D4, 10.0f, 0, 1, 1.0f, p->f424 != 0, 0, 0);
            }
        } else {
            func_L01_00456C98(a0, p->f2D8, 0, 0, 0, p->f2DC, 10.0f, 0, 1, 1.0f, p->f424 != 0, 0, 0);
        }
    }
    if (p->f410 != -1 && p->f414 != -1) {
        if (p->h234 != 1 || D_001D545C == 0x1D) {
            if (a0->b95 == 0 || a0->b95 == 3 || a0->b95 == 1 || (D_001D545C == 0x1D && a0->b95 == 2)) {
                if (func_L01_00456500(D_001A4C60, p->f410) != 0) {
                    p->f418 = 1;
                    hero = D_001A4C60 - 0x80;
                    p->f230 = *(s32 *)(hero + 0x25C0);
                    *(vu0_v4 *)((u8 *)p + 0x220) = *(vu0_v4 *)(hero + 0xD0);
                } else {
                    p->f418 = 0;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003A33C0 */

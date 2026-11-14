/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_006C9180, the NTSC-U twin of func_L39_006CBC70, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/39_multiplayer_menu/L39_006CBC28.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_006CBC70 (src/levels/39_multiplayer_menu/L39_006CBC28.c).
 * Byte-exact only with `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as`: the PAL file's flag line has
 * -mno-split-addresses (retail splits the addresses) and lacks @ps2as (float literals as lui/ori/mtc1, the $gp
 * reads in delay slots). */

/* localdecomp:start func_L39_006C9180 */
typedef struct VT_6C9180 {
    u8 pad0[0x30];
    void (*f30)(void *, f32 *, f32 *);
    u8 pad34[0x88 - 0x34];
    void (*f88)(void *, s32);
    s32 (*f8C)(void *);
} VT_6C9180;

typedef struct Obj_6C9180 {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x60 - 8];
    VT_6C9180 *vt;
} Obj_6C9180;

typedef struct Menu_6C9180 {
    u8 pad0[0x110];
    Obj_6C9180 *items[0x60];
    s32 cur;
    u8 pad294[0x2A8 - 0x294];
    s32 *p2A8;
    s32 *p2AC;
    s32 f2B0;
    u8 pad2B4[0x2B9 - 0x2B4];
    u8 b2B9;
    u8 b2BA;
} Menu_6C9180;

typedef struct Pads_6C9180 {
    u8 pad0[0xE0];
    s16 hE0[8];
    s16 hF0[8];
} Pads_6C9180;

typedef struct G_1A5E50 {
    s32 f0;
    s32 f4;
    s32 f8;
} G_1A5E50;

extern u8 *D_L39_00247A74;
extern Pads_6C9180 *D_L39_002417C0;
extern s32 D_L39_002492A0;
extern s32 D_L39_002492A4;
extern G_1A5E50 D_001A5E50;
extern s32 func_L39_00683618(void *, s32);
extern void func_L39_006C9528(void *);
extern s32 func_L39_00685798(s32, s32, s32);
extern s32 func_L39_00688638(void *, s32);
extern s32 func_L39_006886B8(void *, s32);
extern s32 func_L39_00688750(void *, s32, s32);
extern s32 func_L39_00688350(void *, s32);
extern void func_L39_00687728(void *, s32, s32, s32, f32, f32);

s32 func_L39_006C9180(Menu_6C9180 *arg0, s32 arg1)
{
    f32 pos[2];
    s32 sel;
    s32 first;
    s32 last;
    s32 flags;
    s32 idx;
    s32 i;
    s32 k;
    s32 r;
    s32 t;
    s32 ret;

    if (arg0->f2B0 != 0) {
        arg1 = func_L39_00683618(D_L39_00247A74, arg0->f2B0);
    }
    func_L39_006C9528(arg0);
    if (arg0->cur == 1) {
        sel = arg0->items[1]->vt->f8C(arg0->items[1]);
        if (arg1 == 3 || arg1 == 4) {
            func_L39_00685798(3, 0, 0);
            if (arg1 == 3) {
                sel--;
                if (sel < 0) {
                    sel = arg0->b2B9 ? 0x15 : 0x14;
                }
                if (sel == 0x12 && arg0->b2BA == 0) {
                    sel = 0x11;
                }
            } else if (arg1 == 4) {
                sel++;
                if (sel == 0x12 && arg0->b2BA == 0) {
                    sel = 0x13;
                }
                if (sel == 0x15 && arg0->b2B9 == 0) {
                    sel = 0x16;
                }
                if (sel >= 0x16) {
                    sel = 0;
                }
            }
            arg0->items[1]->vt->f88(arg0->items[1], sel);
            *arg0->p2AC = sel;
            D_L39_002492A0 = sel;
            return 1;
        }
    }
    if (arg0->p2A8 != 0) {
        *arg0->p2A8 = arg0->items[0]->vt->f8C(arg0->items[0]);
    }
    if (arg0->p2AC != 0) {
        *arg0->p2AC = arg0->items[1]->vt->f8C(arg0->items[1]);
    }
    D_L39_002492A0 = *arg0->p2AC;
    D_L39_002492A4 = *arg0->p2A8;
    idx = -1;
    for (i = 0; i < 8; i++) {
        if (D_L39_002417C0->hE0[i] == D_001A5E50.f8) {
            idx = i;
            break;
        }
    }
    if (D_L39_002417C0 != 0) {
        if (idx >= 0 && D_L39_002417C0->hF0[idx] == 5) {
            *(s32 *)(D_L39_00247A74 + 0x284) = 0x2C;
            return 1;
        }
    }
    if (arg0->f2B0 != 0) {
        if (arg1 == 2) {
            r = func_L39_00688638(arg0, -1);
            func_L39_00688750(arg0, r, 0);
            return 1;
        }
        if (arg1 == 1) {
            r = func_L39_006886B8(arg0, -1);
            func_L39_00688750(arg0, r, 0);
            return 1;
        }
        if (arg1 == 5) {
            *(s32 *)(D_L39_00247A74 + 0x284) = 0x2C;
            return 1;
        }
    }
    if (arg1 == 7) {
        *(s32 *)(D_L39_00247A74 + 0x284) = 0x2C;
        return 1;
    }
    if (func_L39_00688350(arg0, arg1)) {
        return 1;
    }
    arg0->items[arg0->cur]->vt->f30(arg0->items[arg0->cur], &pos[0], &pos[1]);
    first = -1;
    last = -1;
    for (k = 0; k < 2; k++) {
        t = arg0->items[k]->f4;
        /* three compares in a row: 	 == 3 || t == 4 || t == 5 would fold into a range test */
        if (t == 3) goto hit;
        if (t == 4) goto hit;
        if (t == 5) {
hit:
            if (first == -1) {
                first = k;
            }
            last = k;
        }
    }
    flags = 0;
    if (arg0->cur != first) {
        flags |= 1;
    }
    flags |= (arg0->cur != last) ? 2 : 0;
    func_L39_00687728(arg0, flags, 3, 3, 0.602f, pos[1] + -0.0015f);
    ret = 0;
    if (arg0->f2B0 != 0) {
        ret = 1;
    }
    return ret;
}
/* localdecomp:end func_L39_006C9180 */

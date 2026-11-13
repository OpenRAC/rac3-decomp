#include "common.h"

/* NTSC-U counterpart of func_L39_0059AC60 (src/levels/shared/L39_0059AA30.c) */
typedef struct {
    s32 index;
    u8 pad04;
    u8 flag;
    u8 pad06[10];
} Cfg_0059AA38;
extern Cfg_0059AA38 D_001A5990;

/* localdecomp:start func_L39_00599908 */
typedef struct {
    s32 state;      /* 00 */
    s32 timer;      /* 04 */
    u8 pad08[0x18];
    s32 sel;        /* 20 */
    s32 pending;    /* 24 */
    s32 player;     /* 28 */
    s32 pad2C;
    s32 ready;      /* 30 */
    s32 wait;       /* 34 */
    s16 h38;
    s16 h3A;
    u8 sub3C[0xC];
    s32 f48;
} S_0059AC60;
typedef struct { u16 h0; u16 pad2; u32 w4; u32 w8; } Rec_0059AC60;
typedef struct { u8 pad0[0x1A0]; u32 f1A0; u32 f1A4; } Pad_0059AC60;
typedef struct { s32 w0; s32 w4; s32 w8; s16 hC; s16 pad; } Ent_0059AC60;
typedef struct { u8 pad0[0x70]; s16 h70; u8 pad72[4]; u16 u76; u8 pad78[0x20]; s16 h98; u8 pad9A[4]; s16 h9E; } Net_0059AC60;

extern S_0059AC60 D_L39_00498AA0_00599908;
extern Rec_0059AC60 D_L39_00200628[];
extern Net_0059AC60 D_L39_002257E0;
extern Pad_0059AC60 *D_L39_002412E4;
extern Ent_0059AC60 *D_L39_0024BDC0_00599908;
typedef struct { u8 pad0[0x2648]; s32 list[1]; } List_0059AC60;
extern List_0059AC60 D_L39_001F0B80;
extern s32 D_L39_00240508_00599908;
extern s32 D_L39_0024145C;
extern s32 D_L39_002412A8;

extern s32 func_00388398(void *);
extern void func_L39_005996E0(void);
extern s32 func_0037DF28(s32);
extern void func_L39_0059A890(u16);
extern void func_L39_005BB3B8(s32, s32, s32, s32, s32, s32, s32);

void func_L39_00599908(void) {
    s32 v1, v2, v3, v4, v5, v6, v7;

    if (D_L39_00498AA0_00599908.ready == 0) {
        if (D_L39_0024145C >= 0) {
            D_L39_00498AA0_00599908.ready = 1;
            D_L39_00498AA0_00599908.wait = 120;
        } else {
            if (D_L39_00498AA0_00599908.wait == 0) {
                if (D_L39_002412E4->f1A0 & 0xF000) {
                    D_L39_00498AA0_00599908.wait = 1;
                }
            }
            if (D_L39_00498AA0_00599908.wait != 0) {
                D_L39_00498AA0_00599908.wait++;
                if (D_L39_00498AA0_00599908.wait >= 120) {
                    D_L39_00498AA0_00599908.ready = 1;
                }
            }
        }
    }
    if ((D_L39_002412A8 != 0 && D_L39_002412A8 != 7) || D_L39_00498AA0_00599908.ready == 0) {
        D_L39_00498AA0_00599908.pending = -1;
        D_L39_00498AA0_00599908.state = 0;
        D_L39_00498AA0_00599908.timer = 0;
    } else {
        D_L39_00498AA0_00599908.timer++;
        switch (D_L39_00498AA0_00599908.state) {
        case 8:
            if (D_L39_00498AA0_00599908.h38 != 0) {
                return;
            }
            if (D_L39_00498AA0_00599908.sel >= 0) {
                if (D_L39_00498AA0_00599908.h3A == 0) {
                    if (func_00388398(&D_L39_00498AA0_00599908.sub3C) == 0) {
                        return;
                    }
                    func_L39_005996E0();
                    D_L39_00498AA0_00599908.h3A++;
                    break;
                }
                if (D_L39_00200628[D_L39_00498AA0_00599908.player].h0 < 0xFFFF) {
                    D_L39_00200628[D_L39_00498AA0_00599908.player].h0++;
                }
            }
            v1 = D_L39_00240508_00599908;
            if (D_L39_00200628[D_L39_00498AA0_00599908.player].w4 < v1) {
                D_L39_00200628[D_L39_00498AA0_00599908.player].w4 = v1;
            }
            D_L39_00498AA0_00599908.sel = -1;
            D_L39_00498AA0_00599908.state = 0;
            D_L39_00498AA0_00599908.h3A = 0;
            D_L39_00200628[D_L39_00498AA0_00599908.player].w8 = D_L39_00200628[D_L39_00498AA0_00599908.player].w8 | (1 << D_L39_0024145C) | 0x80000000;
            break;
        case 0:
            if (D_L39_00498AA0_00599908.pending < 0) {
                return;
            }
            D_L39_00498AA0_00599908.sel = func_0037DF28(D_L39_00498AA0_00599908.pending);
            if (D_L39_0024BDC0_00599908[D_L39_00498AA0_00599908.sel].hC >= 0 && D_L39_00200628[D_L39_00498AA0_00599908.player].h0 != 0) {
                D_L39_00498AA0_00599908.sel = func_0037DF28(D_L39_0024BDC0_00599908[D_L39_00498AA0_00599908.sel].hC);
            }
            ((void (*)(s32))func_L39_0059A890)(D_L39_00498AA0_00599908.pending);
            D_L39_00498AA0_00599908.pending = -1;
            if (D_L39_00498AA0_00599908.sel < 0) {
                break;
            }
            func_L39_005996E0();
            return;
        case 1:
        case 2:
            if (D_L39_002412E4->f1A4 & 0x10) {
                if (D_L39_00200628[D_L39_00498AA0_00599908.player].h0 < 0xFFFF) {
                    D_L39_00200628[D_L39_00498AA0_00599908.player].h0++;
                }
                v2 = D_L39_00240508_00599908;
                if (D_L39_00200628[D_L39_00498AA0_00599908.player].w4 < v2) {
                    D_L39_00200628[D_L39_00498AA0_00599908.player].w4 = v2;
                }
                D_L39_00498AA0_00599908.state = 7;
                D_L39_00498AA0_00599908.timer = 0;
                D_L39_00200628[D_L39_00498AA0_00599908.player].w8 = D_L39_00200628[D_L39_00498AA0_00599908.player].w8 | (1 << D_L39_0024145C) | 0x80000000;
                break;
            }
            if (D_L39_00498AA0_00599908.timer <= 0) {
                break;
            }
            if (!(D_L39_002257E0.h9E == 3 && D_L39_002257E0.h98 >= 0x1B58)) {
                v7 = D_L39_0024BDC0_00599908[D_L39_00498AA0_00599908.sel].w8;
                if (v7 != -1 && D_L39_001F0B80.list[v7] != 0) {
                    if (v7 == D_L39_002257E0.h98 - 0x1B58) {
                        return;
                    }
                    if (v7 == D_L39_002257E0.h70 - 0x1B58) {
                        return;
                    }
                }
            }
            D_L39_00498AA0_00599908.state = 3;
            D_L39_00498AA0_00599908.timer = 0;
            break;
        case 3:
            func_L39_005BB3B8(0, 0x10, 0, 1, 0, 0, 0);
            if (D_L39_002412E4->f1A4 & 0x10) {
            if (D_L39_00200628[D_L39_00498AA0_00599908.player].h0 < 0xFFFF) {
                D_L39_00200628[D_L39_00498AA0_00599908.player].h0++;
            }
            v3 = D_L39_00240508_00599908;
            if (D_L39_00200628[D_L39_00498AA0_00599908.player].w4 < v3) {
                D_L39_00200628[D_L39_00498AA0_00599908.player].w4 = v3;
            }
            D_L39_00498AA0_00599908.state = 7;
            D_L39_00498AA0_00599908.timer = 0;
            D_L39_00200628[D_L39_00498AA0_00599908.player].w8 = D_L39_00200628[D_L39_00498AA0_00599908.player].w8 | (1 << D_L39_0024145C) | 0x80000000;
                break;
            }
            if (D_L39_00498AA0_00599908.timer < 8) {
                return;
            }
            D_L39_00498AA0_00599908.state = 4;
            D_L39_00498AA0_00599908.timer = 0;
            break;
        case 4:
            func_L39_005BB3B8(0, 0x10, 0, 1, 0, 0, 0);
            if (D_L39_002412E4->f1A4 & 0x10) {
            if (D_L39_00200628[D_L39_00498AA0_00599908.player].h0 < 0xFFFF) {
                D_L39_00200628[D_L39_00498AA0_00599908.player].h0++;
            }
            v4 = D_L39_00240508_00599908;
            if (D_L39_00200628[D_L39_00498AA0_00599908.player].w4 < v4) {
                D_L39_00200628[D_L39_00498AA0_00599908.player].w4 = v4;
            }
            D_L39_00498AA0_00599908.state = 6;
            D_L39_00200628[D_L39_00498AA0_00599908.player].w8 = D_L39_00200628[D_L39_00498AA0_00599908.player].w8 | (1 << D_L39_0024145C) | 0x80000000;
            D_L39_00498AA0_00599908.timer = 4 - D_L39_00498AA0_00599908.timer;
                break;
            }
            if (D_L39_00498AA0_00599908.timer < 4) {
                return;
            }
            D_L39_00498AA0_00599908.state = 5;
            D_L39_00498AA0_00599908.timer = 0;
            break;
        case 5:
            func_L39_005BB3B8(0, 0x10, 0, 1, 0, 0, 0);
            if (D_L39_00498AA0_00599908.timer < D_L39_00498AA0_00599908.f48 && !(D_L39_002412E4->f1A4 & 0x10)) {
                return;
            }
            if (D_L39_00200628[D_L39_00498AA0_00599908.player].h0 < 0xFFFF) {
                D_L39_00200628[D_L39_00498AA0_00599908.player].h0++;
            }
            v5 = D_L39_00240508_00599908;
            if (D_L39_00200628[D_L39_00498AA0_00599908.player].w4 < v5) {
                D_L39_00200628[D_L39_00498AA0_00599908.player].w4 = v5;
            }
            D_L39_00498AA0_00599908.state = 6;
            D_L39_00498AA0_00599908.timer = 0;
            D_L39_00200628[D_L39_00498AA0_00599908.player].w8 = D_L39_00200628[D_L39_00498AA0_00599908.player].w8 | (1 << D_L39_0024145C) | 0x80000000;
            break;
        case 6:
            if (D_001A5990.flag != 0 && D_L39_00498AA0_00599908.timer < 4 && !(D_L39_002412E4->f1A4 & 0x10)) {
                return;
            }
            D_L39_00498AA0_00599908.state = 7;
            D_L39_00498AA0_00599908.timer = 0;
            break;
        case 7:
            func_L39_005BB3B8(0, 0x10, 0, 1, 0, 0, 0);
            v6 = D_L39_0024BDC0_00599908[D_L39_00498AA0_00599908.sel].w8;
            if (v6 == D_L39_002257E0.h98 - 0x1B58 || v6 == D_L39_002257E0.h70 - 0x1B58) {
                if ((u16)(D_L39_002257E0.u76 - 6) >= 2) {
                    D_L39_002257E0.u76 = 5;
                }
                if ((u16)(D_L39_002257E0.h9E - 6) >= 2) {
                    D_L39_002257E0.h9E = 5;
                }
            }
            if (D_L39_00498AA0_00599908.timer < 8) {
                return;
            }
            if (D_L39_00498AA0_00599908.h38 != 0) {
                D_L39_00498AA0_00599908.state = 8;
            } else {
                D_L39_00498AA0_00599908.state = 0;
                D_L39_00498AA0_00599908.sel = -1;
            }
            D_L39_00498AA0_00599908.timer = 0;
            break;
        }
    }
}
/* localdecomp:end func_L39_00599908 */

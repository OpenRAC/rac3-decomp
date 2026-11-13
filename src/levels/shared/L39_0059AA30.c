#include "common.h"

typedef struct {
    s32 unk00;
    s32 pad04;
    s32 pad08;
    s32 pad0C;
} Entry_0059AA38;
typedef struct {
    s32 active;
    s32 timer;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 entryIndex;
    s32 pad24[9];
    s32 unk48;
} State_0059AA38;
typedef struct {
    s32 index;
    u8 pad04;
    u8 flag;
    u8 pad06[10];
} Cfg_0059AA38;

LINKER_REMNANT("asm/levels", func_L39_0059AA30);

/* localdecomp:start func_L39_0059AA38 */
extern State_0059AA38 D_L39_004989E0;


extern Cfg_0059AA38 D_001A5810;
extern Entry_0059AA38 *D_L39_0024BCC0;
__asm__(".extern D_001D7360_sda, 4");
__asm__(".extern D_001D7364_sda, 4");
__asm__(".extern D_001D7368_sda, 4");
__asm__(".extern D_001D736C_sda, 4");
__asm__(".extern D_001D7370_sda, 4");
__asm__(".extern D_001D7374_sda, 4");
__asm__(".extern D_001D7378_sda, 4");
__asm__(".extern D_001D737C_sda, 4");
__asm__(".extern D_001D7380_sda, 4");
__asm__(".extern D_001D7384_sda, 4");
__asm__(".extern D_001D7388_sda, 4");
__asm__(".extern D_001D738C_sda, 4");
__asm__(".extern D_001D7390_sda, 4");
__asm__(".extern D_001D7394_sda, 4");
__asm__(".extern D_001D7398_sda, 4");
__asm__(".extern D_001D739C_sda, 4");
extern s32 D_001D7360_sda;
extern s32 D_001D7364_sda;
extern s32 D_001D7368_sda;
extern s32 D_001D736C_sda;
extern s32 D_001D7370_sda;
extern s32 D_001D7374_sda;
extern s32 D_001D7378_sda;
extern s32 D_001D737C_sda;
extern s32 D_001D7380_sda;
extern s32 D_001D7384_sda;
extern s32 D_001D7388_sda;
extern s32 D_001D738C_sda;
extern s32 D_001D7390_sda;
extern s32 D_001D7394_sda;
extern s32 D_001D7398_sda;
extern s32 D_001D739C_sda;
__asm__(".extern D_001D73A0_sda, 8");
extern s32 D_001D73A0_sda[2];

extern void func_L39_005F3548(s32, s32, s32);
extern s32 func_L39_00589890(s32);
extern s32 func_120884(s32);
extern void func_003910C0(u16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_003911F0(u16 *p, long a, s32 b, s32 c, s32 d, s32 e, f32 f, unsigned long g);
extern void func_0038E150(s32);

void func_L39_0059AA38(void) {
    u16 metrics[16];
    s32 id;
    s32 mode;
    s32 x, y, w, h, e, f, g;
    s32 screenH;

    D_L39_004989E0.active = 1;
    D_L39_004989E0.timer = 0;
    if (D_001A5810.flag != 0) {
        func_L39_005F3548(0, 1, 0);
    }
    id = D_L39_0024BCC0[D_L39_004989E0.entryIndex].unk00;
    mode = **(s32 **)0x241120;
    x = 0xF0;
    y = 0x1E0;
    w = 0x2C;
    h = D_001D7364_sda + 0x1D4;
    e = D_001D7360_sda + 0x100;
    f = 0x168;
    g = 0x10;
    if (mode == 2) {
        x = D_001D7368_sda;
        y = D_001D736C_sda;
        w = D_001D7370_sda;
        h = D_001D7374_sda;
        e = D_001D7378_sda;
        f = D_001D737C_sda;
        g = D_001D7380_sda;
    } else if (mode == 4) {
        x = D_001D7384_sda;
        y = D_001D7388_sda;
        w = D_001D738C_sda;
        h = D_001D7390_sda;
        e = D_001D7394_sda;
        f = D_001D7398_sda;
        g = D_001D739C_sda;
    }
    func_003910C0(metrics, x, y, w, h, e, f, g, 7);
    metrics[9] |= 0x20;
    metrics[12] = 2;
    metrics[13] = 2;
    func_0038E150(1);
    func_003911F0(metrics, 0x8066CCFFL, id, -1, func_L39_00589890(1), *(s32 *)0x24144C, 1.0f, 0x80000000UL);
    D_L39_004989E0.unk08 = ((s16)metrics[6] >> 1) + 10;
    D_L39_004989E0.unk0C = ((s16)metrics[7] >> 1) + 5;
    D_L39_004989E0.unk10 = e;
    D_L39_004989E0.unk14 = D_001D73A0_sda[D_001A5810.index];
    D_L39_004989E0.unk18 = 8;
    D_L39_004989E0.unk1C = 8;
    D_L39_004989E0.unk48 = 0;
    if (id != 0) {
        D_L39_004989E0.unk48 = func_120884(id) * 7;
    }
    screenH = *(s32 *)0x240304;
    D_L39_004989E0.unk14 = screenH - 0x3C;
    if (screenH - 0xC < D_L39_004989E0.unk14 + D_L39_004989E0.unk0C) {
        s32 bottom = D_L39_004989E0.unk0C + 0xC;
        D_L39_004989E0.unk14 = screenH - bottom;
    }
}
/* localdecomp:end func_L39_0059AA38 */

/* localdecomp:start func_L39_0059AC60 */
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

extern S_0059AC60 D_L39_004989E0_0059AC60;
extern Rec_0059AC60 D_2004A8[];
extern Net_0059AC60 D_225660;
extern Pad_0059AC60 *D_L39_00241164;
extern Ent_0059AC60 *D_L39_0024BCC0_0059AC60;
extern s32 D_L39_00240388;
extern s32 D_L39_002412DC;
extern s32 D_L39_00241128;

extern s32 *func_L39_0059A7A8(void);
extern s32 func_0038CAD0(void *);
extern void func_L39_0059AA38(void);
extern s32 func_00381F80(s32);
extern void func_L39_0059BC28(u16);
extern void func_L39_005BD368(s32, s32, s32, s32, s32, s32, s32);

void func_L39_0059AC60(void) {
    s32 *list;
    s32 v1, v2, v3, v4, v5, v6;

    if (D_L39_004989E0_0059AC60.ready == 0) {
        if (D_L39_002412DC >= 0) {
            D_L39_004989E0_0059AC60.ready = 1;
            D_L39_004989E0_0059AC60.wait = 100;
        } else {
            if (D_L39_004989E0_0059AC60.wait == 0) {
                if (D_L39_00241164->f1A0 & 0xF000) {
                    D_L39_004989E0_0059AC60.wait = 1;
                }
            }
            if (D_L39_004989E0_0059AC60.wait != 0) {
                D_L39_004989E0_0059AC60.wait++;
                if (D_L39_004989E0_0059AC60.wait >= 100) {
                    D_L39_004989E0_0059AC60.ready = 1;
                }
            }
        }
    }
    if ((D_L39_00241128 != 0 && D_L39_00241128 != 7) || D_L39_004989E0_0059AC60.ready == 0) {
        D_L39_004989E0_0059AC60.pending = -1;
        D_L39_004989E0_0059AC60.state = 0;
        D_L39_004989E0_0059AC60.timer = 0;
    } else {
        D_L39_004989E0_0059AC60.timer++;
        list = func_L39_0059A7A8();
        switch (D_L39_004989E0_0059AC60.state) {
        case 8:
            if (D_L39_004989E0_0059AC60.h38 != 0) {
                return;
            }
            if (D_L39_004989E0_0059AC60.sel >= 0) {
                if (D_L39_004989E0_0059AC60.h3A == 0) {
                    if (func_0038CAD0(&D_L39_004989E0_0059AC60.sub3C) == 0) {
                        return;
                    }
                    func_L39_0059AA38();
                    D_L39_004989E0_0059AC60.h3A++;
                    break;
                }
                if (D_2004A8[D_L39_004989E0_0059AC60.player].h0 < 0xFFFF) {
                    D_2004A8[D_L39_004989E0_0059AC60.player].h0++;
                }
            }
            v1 = (D_L39_00240388 * 5 + 2) / 6;
            if (D_2004A8[D_L39_004989E0_0059AC60.player].w4 < v1) {
                D_2004A8[D_L39_004989E0_0059AC60.player].w4 = v1;
            }
            D_L39_004989E0_0059AC60.sel = -1;
            D_L39_004989E0_0059AC60.state = 0;
            D_L39_004989E0_0059AC60.h3A = 0;
            D_2004A8[D_L39_004989E0_0059AC60.player].w8 = D_2004A8[D_L39_004989E0_0059AC60.player].w8 | (1 << D_L39_002412DC) | 0x80000000;
            break;
        case 0:
            if (D_L39_004989E0_0059AC60.pending < 0) {
                return;
            }
            D_L39_004989E0_0059AC60.sel = func_00381F80(D_L39_004989E0_0059AC60.pending);
            if (D_L39_0024BCC0_0059AC60[D_L39_004989E0_0059AC60.sel].hC >= 0 && D_2004A8[D_L39_004989E0_0059AC60.player].h0 != 0) {
                D_L39_004989E0_0059AC60.sel = func_00381F80(D_L39_0024BCC0_0059AC60[D_L39_004989E0_0059AC60.sel].hC);
            }
            ((void (*)(s32))func_L39_0059BC28)(D_L39_004989E0_0059AC60.pending);
            D_L39_004989E0_0059AC60.pending = -1;
            if (D_L39_004989E0_0059AC60.sel < 0) {
                break;
            }
            func_L39_0059AA38();
            return;
        case 1:
        case 2:
            if (D_L39_00241164->f1A4 & 0x10) {
                goto confirm;
            }
            if (D_L39_004989E0_0059AC60.timer <= 0) {
                break;
            }
            if (!(D_225660.h9E == 3 && D_225660.h98 >= 0x1B58)) {
                v2 = D_L39_0024BCC0_0059AC60[D_L39_004989E0_0059AC60.sel].w8;
                if (v2 != -1 && list[v2] != 0) {
                    if (v2 == D_225660.h98 - 0x1B58) {
                        return;
                    }
                    if (v2 == D_225660.h70 - 0x1B58) {
                        return;
                    }
                }
            }
            D_L39_004989E0_0059AC60.state = 3;
            D_L39_004989E0_0059AC60.timer = 0;
            break;
        case 3:
            func_L39_005BD368(0, 0x10, 0, 1, 0, 0, 0);
            if (D_L39_00241164->f1A4 & 0x10) {
            confirm:
            if (D_2004A8[D_L39_004989E0_0059AC60.player].h0 < 0xFFFF) {
                D_2004A8[D_L39_004989E0_0059AC60.player].h0++;
            }
            v3 = (D_L39_00240388 * 5 + 2) / 6;
            if (D_2004A8[D_L39_004989E0_0059AC60.player].w4 < v3) {
                D_2004A8[D_L39_004989E0_0059AC60.player].w4 = v3;
            }
            D_L39_004989E0_0059AC60.state = 7;
            D_L39_004989E0_0059AC60.timer = 0;
            D_2004A8[D_L39_004989E0_0059AC60.player].w8 = D_2004A8[D_L39_004989E0_0059AC60.player].w8 | (1 << D_L39_002412DC) | 0x80000000;
                break;
            }
            if (D_L39_004989E0_0059AC60.timer < 8) {
                return;
            }
            D_L39_004989E0_0059AC60.state = 4;
            D_L39_004989E0_0059AC60.timer = 0;
            break;
        case 4:
            func_L39_005BD368(0, 0x10, 0, 1, 0, 0, 0);
            if (D_L39_00241164->f1A4 & 0x10) {
            if (D_2004A8[D_L39_004989E0_0059AC60.player].h0 < 0xFFFF) {
                D_2004A8[D_L39_004989E0_0059AC60.player].h0++;
            }
            v4 = (D_L39_00240388 * 5 + 2) / 6;
            if (D_2004A8[D_L39_004989E0_0059AC60.player].w4 < v4) {
                D_2004A8[D_L39_004989E0_0059AC60.player].w4 = v4;
            }
            D_L39_004989E0_0059AC60.state = 6;
            D_L39_004989E0_0059AC60.timer = 4 - D_L39_004989E0_0059AC60.timer;
            D_2004A8[D_L39_004989E0_0059AC60.player].w8 = D_2004A8[D_L39_004989E0_0059AC60.player].w8 | (1 << D_L39_002412DC) | 0x80000000;
                break;
            }
            if (D_L39_004989E0_0059AC60.timer < 4) {
                return;
            }
            D_L39_004989E0_0059AC60.state = 5;
            D_L39_004989E0_0059AC60.timer = 0;
            break;
        case 5:
            func_L39_005BD368(0, 0x10, 0, 1, 0, 0, 0);
            if (D_L39_004989E0_0059AC60.timer < (D_L39_004989E0_0059AC60.f48 * 5 + 2) / 6 && !(D_L39_00241164->f1A4 & 0x10)) {
                return;
            }
            if (D_2004A8[D_L39_004989E0_0059AC60.player].h0 < 0xFFFF) {
                D_2004A8[D_L39_004989E0_0059AC60.player].h0++;
            }
            v5 = (D_L39_00240388 * 5 + 2) / 6;
            if (D_2004A8[D_L39_004989E0_0059AC60.player].w4 < v5) {
                D_2004A8[D_L39_004989E0_0059AC60.player].w4 = v5;
            }
            D_L39_004989E0_0059AC60.state = 6;
            D_L39_004989E0_0059AC60.timer = 0;
            D_2004A8[D_L39_004989E0_0059AC60.player].w8 = D_2004A8[D_L39_004989E0_0059AC60.player].w8 | (1 << D_L39_002412DC) | 0x80000000;
            break;
        case 6:
            if (D_001A5810.flag != 0 && D_L39_004989E0_0059AC60.timer < 4 && !(D_L39_00241164->f1A4 & 0x10)) {
                return;
            }
            D_L39_004989E0_0059AC60.state = 7;
            D_L39_004989E0_0059AC60.timer = 0;
            break;
        case 7:
            func_L39_005BD368(0, 0x10, 0, 1, 0, 0, 0);
            v6 = D_L39_0024BCC0_0059AC60[D_L39_004989E0_0059AC60.sel].w8;
            if (v6 == D_225660.h98 - 0x1B58 || v6 == D_225660.h70 - 0x1B58) {
                if ((u16)(D_225660.u76 - 6) >= 2) {
                    D_225660.u76 = 5;
                }
                if ((u16)(D_225660.h9E - 6) >= 2) {
                    D_225660.h9E = 5;
                }
            }
            if (D_L39_004989E0_0059AC60.timer < 8) {
                return;
            }
            if (D_L39_004989E0_0059AC60.h38 != 0) {
                D_L39_004989E0_0059AC60.state = 8;
            } else {
                D_L39_004989E0_0059AC60.state = 0;
                D_L39_004989E0_0059AC60.sel = -1;
            }
            D_L39_004989E0_0059AC60.timer = 0;
            break;
        }
    }
}
/* localdecomp:end func_L39_0059AC60 */

/* functional: high. compiled under level_39 (263 diff lines, regalloc/stack); all branches read against asm; callee arg widths guessed (func_003910C0 takes 9 args, last on stack); D_001A5810 = core settings struct (bytes 6, 0xAD, 0xB7); dividing by 6 is retail signed div (a*5+2)/6 */
typedef struct {
    u8 pad0[0x34];
    s32 cur;
    u8 pad38[0x14];
    u8 *blob;
} Menu_0058A8B0;

typedef struct {
    u8 pad0[0x6];
    u8 b6;
    u8 pad7[0xA6];
    u8 bAD;
    u8 padAE[9];
    u8 bB7;
} Cfg_0058A8B0;

typedef struct {
    u8 pad0[0xA];
    u16 fA;
    u16 fC;
    u16 fE;
    u8 pad10[2];
    u16 f12;
    u8 pad14[0xC];
} Rect_0058A8B0;

extern Menu_0058A8B0 D_L39_0025CEC0;
extern Cfg_0058A8B0 D_001A5810;
extern s32 D_L39_00240304;

extern void func_00390E60(s32, s32, u32, void *, s32);
extern void func_00390FB0(s32, s32, u32, void *, s32);
extern void func_003910C0(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00391130(void *, u32, void *, s32);
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern u32 func_120884(void *);

void func_L39_0058A8B0(void) {
    s32 sel;
    s16 *p;
    s16 *end;
    s32 ypos;
    s32 cur;
    s32 lo;
    s32 hi;
    s32 x;
    s32 py;
    s32 alpha;
    s32 a15;
    s32 h;
    s32 w;
    s32 y;
    s32 hh;
    s32 hw;
    u32 c;
    u32 color;
    u8 *txt;
    Rect_0058A8B0 rect;
    s32 b;

    if (D_L39_0025CEC0.blob == 0) {
        return;
    }
    sel = 0;
    b = D_001A5810.bB7;
    if (b == 5) {
        sel = b - 2;
    } else if (b == 4) {
        sel = D_001A5810.bB7;
    } else if ((u32)(b - 2) < 4) {
        sel = D_001A5810.bB7 - 1;
    }
    p = (s16 *)D_L39_0025CEC0.blob;
    end = (s16 *)(D_L39_0025CEC0.blob + p[2]);
    ypos = 0xD0;
    for (; (u32)p < (u32)end; p = (s16 *)((u8 *)p + 0x12)) {
        cur = D_L39_0025CEC0.cur;
        lo = (p[0] * 5 + 2) / 6;
        if (cur < lo) {
            continue;
        }
        hi = (p[1] * 5 + 2) / 6;
        if (hi < cur) {
            continue;
        }
        txt = D_L39_0025CEC0.blob + p[2 + sel];
        if (D_001A5810.b6 == 0 && txt[0] != 0x2A) {
            continue;
        }
        if (txt[0] == 0x2A) {
            c = 0xB0000000;
            if (txt[1] != 0x2A) {
                x = D_L39_00240304 - 0xC8;
            } else {
                x = 0x40;
                if (D_001A5810.bAD != 0) {
                    x = 0x18;
                }
            }
            cur = D_L39_0025CEC0.cur;
            hi = (p[1] * 5 + 2) / 6;
            if (hi - cur < 0x12) {
                c = (hi - (cur - 1)) << 27;
            } else {
                lo = (p[0] * 5 + 2) / 6;
                if (cur - lo < 0x12) {
                    c = (cur - (lo - 1)) << 27;
                }
            }
            txt = D_L39_0025CEC0.blob + p[2 + sel];
            if (txt[1] != 0x2A) {
                func_00390E60(0x100, ypos, c | 0xE0E0E0, txt + 1, -1);
                ypos += 0x14;
            } else {
                func_00390FB0(0x20, x, c | 0xE0E0E0, txt + 2, -1);
            }
        } else {
            w = D_L39_00240304;
            py = w - 0x64;
            if (D_001A5810.bAD != 0) {
                py = w - 0x36;
            }
            alpha = 0x80;
            if (hi - cur < 8) {
                alpha = (hi - (cur - 1)) << 4;
            } else if (cur - lo < 8) {
                alpha = (cur - (lo - 1)) << 4;
            }
            func_003910C0(&rect, 0xC8, 0x1A4, 0x28, 0x1D8, 0x100, py, 0x12, 7);
            a15 = alpha + (alpha >> 1);
            color = a15 | (a15 << 8) | (a15 << 16) | (alpha << 24);
            func_00391130(&rect, color, D_L39_0025CEC0.blob + p[2 + sel], -1);
            h = (s16)rect.fE >> 1;
            hh = h + 5;
            hw = (s16)rect.fC >> 1;
            y = (s16)(rect.fA - 4);
            rect.fA = rect.fA - 4;
            if (D_L39_00240304 - 0x14 < y + hh) {
                rect.fA = (u16)D_L39_00240304 - (h + 0x19);
            }
            rect.f12 &= 0xFFFB;
            if (func_120884(D_L39_0025CEC0.blob + p[2 + sel]) >= 0x96) {
                return;
            }
            func_0038C3B0((s16)rect.fA - hh, (s16)rect.fA + hh, 0x100 - (hw + 10),
                          hw + 0x10A, (alpha >> 1) + (alpha >> 2), 0x40404);
            func_00391130(&rect, color, D_L39_0025CEC0.blob + p[2 + sel], -1);
            return;
        }
    }
}

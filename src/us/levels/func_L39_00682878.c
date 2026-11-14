#include "common.h"

/* NTSC-U counterpart of func_L39_00685398 (src/levels/39_multiplayer_menu/L39_00685398.c): 37 -> 45 */
extern s32 func_L01_00512AB0(s32, s32, s32);
s32 func_L01_00512C88(s32, s32, s32);
s32 func_L01_00512AB0(s32, s32, s32);
extern s32 func_L01_00512C88(s32, s32, s32);
void func_0011D534(s32, s32, s32);
extern s32 func_L01_00512AB0(s32, s32, s32);
extern s32 func_L01_00512FE8(s32, s32);
extern s32 func_L01_00512480(s32, f32, f32);
extern s32 func_L01_005130C8(s32, s32);
void func_00120D28(s32, s32, s32);
extern void func_00120D28(s32, s32, s32);
extern s32 func_L01_00512C88(s32, s32, s32);
extern void *func_001206F4(void *, void *);

/* localdecomp:start func_L39_00682878 */
extern void func_0011D534(s32, s32, s32);
extern s32 func_00120884(s32);
extern void func_001202F4(s32, void *);
extern void func_00120D28(s32, s32, s32);
extern void *func_001206F4(void *, void *);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_0037E368(u32, u32, s32, s32, s32, s32);
extern s32 func_L01_00512AB0(s32, s32, s32);
extern s32 func_L01_00512C88(s32, s32, s32);
extern s32 func_L01_00512FE8(s32, s32);
extern s32 func_L01_00512480(s32, f32, f32);
extern s32 func_L01_005130C8(s32, s32);
extern s32 func_L01_00514020(s32, s32);
extern s32 func_003E3330(s32, f32, f32);
extern void func_L39_0060EF10(s32, s32 *);
extern u8 D_L39_002478F0[];
extern u8 D_L39_002479B0[];
extern u8 D_L39_002479B8[];
extern u8 D_L39_002479C0[];


typedef struct Vt_00685398 {
    u8 pad_00[0x30];
    void (*f30)(void *, void *, void *);
    void (*f34)(void *, void *, void *);
} Vt_00685398;

typedef struct {
    u8 pad0[0x4];
    s32 f4;
    u8 pad8[0x14 - 0x8];
    u8 f14[0x50 - 0x14];
    f32 f50;
    u8 pad54[0x58 - 0x54];
    f32 f58;
    u8 pad5C[0x60 - 0x5C];
    Vt_00685398 *vt;
    u8 name[0xC8];
    u8 pad12C[0x130 - 0x12C];
    s32 h130;
    s32 h134;
    s32 h138;
    s32 h13C;
    s32 h140;
    u8 pad144[0x164 - 0x144];
    u8 f164;
    u8 text[0xC8];
    u8 pad22D[0x230 - 0x22D];
    s32 len;
    s32 cursor;
    s32 blink;
    s32 f23C;
    u8 pad240[0x248 - 0x240];
    u8 f248;
    char before[0xC8];
    char cursorText[2];
    char after[0xC8];
    u8 f3DB;
    u8 alt[0xC8];
} S_00685398;

void func_L39_00682878(S_00685398 *o) {
    f32 buf[4];
    f32 pos[4];
    s32 color;
    s32 n;
    s32 i;

    if (o->f3DB != 0) {
        func_0011D534((s32)o->alt, 0, 0xC8);
        n = func_00120884((s32)o->name);
        for (i = 0; i < n; i++) {
            func_001202F4((s32)o->alt, D_L39_002478F0);
        }
    }
    if (o->h130 == -1) {
        return;
    }
    if (o->f4 == 0) {
        func_L01_00512AB0(o->h130, 1, 0);
        func_L01_00512AB0(o->h134, 1, 0);
        func_L01_00512AB0(o->h138, 1, 0);
        func_L01_00512AB0(o->h13C, 1, 0);
        func_L01_00512AB0(o->h140, 1, 0);
        return;
    }
    func_L01_00512AB0(o->h130, 1, 1);
    func_L01_00512AB0(o->h134, 1, 1);
    if (o->f4 == 2) {
        color = 0x80808080;
    } else if (o->f4 == 3) {
        color = 0x8066CCFF;
    } else if (o->f4 == 4) {
        color = func_0037E368(0x8066CCFF, 0x66D6EEFA, 0x2D, 1, 0, 1);
    } else if (o->f4 == 5) {
        color = 0x66D6EEFA;
    } else {
        color = 0x8066CCFF;
    }
    o->vt->f30(o, &pos[0], &pos[1]);
    o->vt->f34(o, &pos[2], &pos[3]);
    if (o->f164 != 0) {
        func_L01_00512FE8(o->h130, (s32)o->f14);
        func_L01_00512480(o->h130, pos[0], pos[1]);
        func_L01_005130C8(o->h130, color);
        func_L39_0060EF10(o->h130, (s32 *)buf);
        pos[0] = buf[2] + 0.005f;
        func_L01_00512480(o->h134, pos[0], pos[1]);
        func_L39_0060EF10(o->h134, (s32 *)buf);
        pos[0] = buf[2] + 0.005f;
        if (o->cursor > 0) {
            ((char *(*)(s32, s32, s32))func_00120D28)((s32)o->before, (s32)o->text, o->cursor);
            o->before[o->cursor] = 0;
            o->vt->f30(o, &pos[0], &pos[1]);
            func_L01_00512FE8(o->h138, (s32)o->before);
            func_L01_00512480(o->h138, pos[0] + o->f58, pos[1]);
            func_L01_005130C8(o->h138, color);
            func_L01_00512AB0(o->h138, 1, 1);
            func_L39_0060EF10(o->h138, (s32 *)buf);
            pos[0] = buf[2];
        } else {
            func_L01_00512AB0(o->h138, 1, 0);
        }
        if (o->cursor >= 0) {
            if (o->text[o->cursor] != ' ') {
                func_00120048((u8 *)o->cursorText, D_L39_002479B0, o->text[o->cursor]);
            } else {
                o->blink = (o->blink + 1) % 20;
                if (o->blink >= 10) {
                    func_00120048((u8 *)o->cursorText, D_L39_002479B8);
                } else {
                    func_00120048((u8 *)o->cursorText, D_L39_002479C0);
                }
            }
            func_L01_00512FE8(o->h13C, (s32)o->cursorText);
            func_L01_00512480(o->h13C, pos[0], pos[1]);
            func_L01_005130C8(o->h13C, 0x80FFFFFF);
            func_L01_00512AB0(o->h13C, 1, 1);
            func_L39_0060EF10(o->h13C, (s32 *)buf);
            pos[0] = buf[2];
        } else {
            func_L01_00512AB0(o->h13C, 1, 0);
        }
        if (o->cursor < o->len - 1) {
            if (o->cursor >= 0) {
                ((char *(*)(s32, s32, s32))func_00120D28)((s32)o->after, (s32)&o->text[o->cursor + 1], o->len - o->cursor - 1);
                o->after[o->len - o->cursor - 1] = 0;
            } else {
                func_001206F4(o->after, o->text);
            }
            func_L01_00512FE8(o->h140, (s32)o->after);
            func_L01_00512480(o->h140, pos[0], pos[1]);
            func_L01_005130C8(o->h140, color);
            func_L01_00512AB0(o->h140, 1, 1);
        } else {
            func_L01_00512AB0(o->h140, 1, 0);
        }
    } else {
        func_L01_00512AB0(o->h138, 1, 1);
        func_L01_00512AB0(o->h13C, 1, 0);
        func_L01_00512AB0(o->h140, 1, 0);
        func_L01_00512FE8(o->h130, (s32)o->f14);
        func_L01_00512480(o->h130, pos[0], pos[1]);
        func_L01_005130C8(o->h130, color);
        func_L39_0060EF10(o->h130, (s32 *)buf);
        pos[0] = buf[2] + 0.005f;
        func_L01_00512480(o->h134, pos[0], pos[1]);
        func_L01_005130C8(o->h134, color);
        if (o->f23C != 0) {
            o->vt->f30(o, &pos[0], &pos[1]);
            func_L01_00512480(o->h138, pos[0] + o->f58, pos[1]);
        } else {
            if (o->f248 != 0) {
                if (func_L01_00514020(o->h138, 1) != 0) {
                    func_003E3330(o->h138, o->f58 - (pos[0] - o->f50), 0.0f);
                }
            } else {
                func_L01_00514020(o->h138, 0);
            }
            func_L01_00512C88(o->h138, 2, 3);
            func_L01_00512480(o->h138, o->f50 + o->f58, pos[1]);
        }
        if (o->f3DB != 0) {
            func_L01_00512FE8(o->h138, (s32)o->alt);
        } else {
            func_L01_00512FE8(o->h138, (s32)o->name);
        }
        func_L01_005130C8(o->h138, color);
    }
}
/* localdecomp:end func_L39_00682878 */

#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* declared by functions of L39_00681758.c, which this file was cut from */
extern void func_L39_0067EEC8(u8 *, s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516818(s32);
extern S_00683550 *func_L39_0067EE40(void *, void *);
s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00517538(s32, f32, f32);

/* declared by functions of L39_00684488.c, which this file was cut from */
void func_0011D534(s32, s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
void func_00120D28(s32, s32, s32);
extern void func_00120D28(s32, s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);
extern void *func_001206F4(void *, void *);

/* localdecomp:start func_L39_00685398 */
extern void func_0011D534(s32, s32, s32);
extern s32 func_00120884(s32);
extern void func_001202F4(s32, void *);
extern void func_00120D28(s32, s32, s32);
extern void *func_001206F4(void *, void *);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_003825F8(u32, u32, s32, s32, s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00518010(s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern void func_L39_00611628(s32, s32 *);
extern u8 D_00247790[];
extern u8 D_L39_00247850[];
extern u8 D_L39_00247858[];
extern u8 D_L39_00247860[];


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

void func_L39_00685398(S_00685398 *o) {
    f32 buf[4];
    f32 pos[4];
    s32 color;
    s32 n;
    s32 i;

    if (o->f3DB != 0) {
        func_0011D534((s32)o->alt, 0, 0xC8);
        n = func_00120884((s32)o->name);
        for (i = 0; i < n; i++) {
            func_001202F4((s32)o->alt, D_00247790);
        }
    }
    if (o->h130 == -1) {
        return;
    }
    if (o->f4 == 0) {
        func_L01_00516AA0(o->h130, 1, 0);
        func_L01_00516AA0(o->h134, 1, 0);
        func_L01_00516AA0(o->h138, 1, 0);
        func_L01_00516AA0(o->h13C, 1, 0);
        func_L01_00516AA0(o->h140, 1, 0);
        return;
    }
    func_L01_00516AA0(o->h130, 1, 1);
    func_L01_00516AA0(o->h134, 1, 1);
    if (o->f4 == 2) {
        color = 0x80808080;
    } else if (o->f4 == 3) {
        color = 0x8066CCFF;
    } else if (o->f4 == 4) {
        color = func_003825F8(0x8066CCFF, 0x66D6EEFA, 0x25, 1, 0, 1);
    } else if (o->f4 == 5) {
        color = 0x66D6EEFA;
    } else {
        color = 0x8066CCFF;
    }
    o->vt->f30(o, &pos[0], &pos[1]);
    o->vt->f34(o, &pos[2], &pos[3]);
    if (o->f164 != 0) {
        func_L01_00516FD8(o->h130, (s32)o->f14);
        func_L01_00516470(o->h130, pos[0], pos[1]);
        func_L01_005170B8(o->h130, color);
        func_L39_00611628(o->h130, (s32 *)buf);
        pos[0] = buf[2] + 0.005f;
        func_L01_00516470(o->h134, pos[0], pos[1]);
        func_L39_00611628(o->h134, (s32 *)buf);
        pos[0] = buf[2] + 0.005f;
        if (o->cursor > 0) {
            ((char *(*)(s32, s32, s32))func_00120D28)((s32)o->before, (s32)o->text, o->cursor);
            o->before[o->cursor] = 0;
            o->vt->f30(o, &pos[0], &pos[1]);
            func_L01_00516FD8(o->h138, (s32)o->before);
            func_L01_00516470(o->h138, pos[0] + o->f58, pos[1]);
            func_L01_005170B8(o->h138, color);
            func_L01_00516AA0(o->h138, 1, 1);
            func_L39_00611628(o->h138, (s32 *)buf);
            pos[0] = buf[2];
        } else {
            func_L01_00516AA0(o->h138, 1, 0);
        }
        if (o->cursor >= 0) {
            if (o->text[o->cursor] != ' ') {
                func_00120048((u8 *)o->cursorText, D_L39_00247850, o->text[o->cursor]);
            } else {
                o->blink = (o->blink + 1) % 20;
                if (o->blink >= 10) {
                    func_00120048((u8 *)o->cursorText, D_L39_00247858);
                } else {
                    func_00120048((u8 *)o->cursorText, D_L39_00247860);
                }
            }
            func_L01_00516FD8(o->h13C, (s32)o->cursorText);
            func_L01_00516470(o->h13C, pos[0], pos[1]);
            func_L01_005170B8(o->h13C, 0x80FFFFFF);
            func_L01_00516AA0(o->h13C, 1, 1);
            func_L39_00611628(o->h13C, (s32 *)buf);
            pos[0] = buf[2];
        } else {
            func_L01_00516AA0(o->h13C, 1, 0);
        }
        if (o->cursor < o->len - 1) {
            if (o->cursor >= 0) {
                ((char *(*)(s32, s32, s32))func_00120D28)((s32)o->after, (s32)&o->text[o->cursor + 1], o->len - o->cursor - 1);
                o->after[o->len - o->cursor - 1] = 0;
            } else {
                func_001206F4(o->after, o->text);
            }
            func_L01_00516FD8(o->h140, (s32)o->after);
            func_L01_00516470(o->h140, pos[0], pos[1]);
            func_L01_005170B8(o->h140, color);
            func_L01_00516AA0(o->h140, 1, 1);
        } else {
            func_L01_00516AA0(o->h140, 1, 0);
        }
    } else {
        func_L01_00516AA0(o->h138, 1, 1);
        func_L01_00516AA0(o->h13C, 1, 0);
        func_L01_00516AA0(o->h140, 1, 0);
        func_L01_00516FD8(o->h130, (s32)o->f14);
        func_L01_00516470(o->h130, pos[0], pos[1]);
        func_L01_005170B8(o->h130, color);
        func_L39_00611628(o->h130, (s32 *)buf);
        pos[0] = buf[2] + 0.005f;
        func_L01_00516470(o->h134, pos[0], pos[1]);
        func_L01_005170B8(o->h134, color);
        if (o->f23C != 0) {
            o->vt->f30(o, &pos[0], &pos[1]);
            func_L01_00516470(o->h138, pos[0] + o->f58, pos[1]);
        } else {
            if (o->f248 != 0) {
                if (func_L01_00518010(o->h138, 1) != 0) {
                    func_003E8898(o->h138, o->f58 - (pos[0] - o->f50), 0.0f);
                }
            } else {
                func_L01_00518010(o->h138, 0);
            }
            func_L01_00516C78(o->h138, 2, 3);
            func_L01_00516470(o->h138, o->f50 + o->f58, pos[1]);
        }
        if (o->f3DB != 0) {
            func_L01_00516FD8(o->h138, (s32)o->alt);
        } else {
            func_L01_00516FD8(o->h138, (s32)o->name);
        }
        func_L01_005170B8(o->h138, color);
    }
}
/* localdecomp:end func_L39_00685398 */

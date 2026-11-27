#include "common.h"

/* localdecomp:start func_L39_0058A5D0 */
__asm__(".extern D_L39_0024B9C8_b, 4");
__asm__(".extern D_L39_0024CAD0_b, 4");
extern s32 D_L39_0024B9C8;
extern s32 D_L39_0024B9C8_b;
extern u32 *D_L39_0024CAD0;
extern u32 *D_L39_0024CAD0_b;
extern u8 D_1A3940[];
extern void func_003A92F0(s32);
extern s32 func_139E08(s32);
extern void func_003A9108(void);
extern void func_003A9150(void);
extern void func_L39_00597E70(void);
extern void func_00392350(s32);
extern void func_003923D0(void);
extern void func_003A9440(s32, unsigned long);
extern void func_L39_005FCDF8(void);

void func_L39_0058A5D0(s32 arg0) {
    s32 i;
    s32 t;

    func_003A92F0(1);
    i = arg0 - 1;
    func_139E08(0);
    D_L39_0024B9C8_b = D_L39_0024B9C8 + 1;
    func_003A9108();

    while (i >= 0) {
        func_L39_00597E70();
        func_00392350(1);
        func_003923D0();
        func_003A9440(0x42, 0x8000000044UL);
        t = (i << 7) / (i + 1);
        i--;
        func_003A9440(1, (long)(0x80 - t) << 24);

        D_L39_0024CAD0[0] = 0x30000014;
        D_L39_0024CAD0[1] = (u32)D_1A3940;
        D_L39_0024CAD0[2] = 0;
        D_L39_0024CAD0[3] = 0x50000014;
        D_L39_0024CAD0_b = D_L39_0024CAD0 + 4;

        func_003A92F0(1);
        func_139E08(0);
        D_L39_0024B9C8_b = D_L39_0024B9C8 + 1;
        func_L39_005FCDF8();
        func_003A9150();
    }

    func_003A92F0(1);
    func_139E08(0);
    D_L39_0024B9C8_b = D_L39_0024B9C8 + 1;
    func_003A9108();
    func_L39_00597E70();
    func_00392350(1);
}
/* localdecomp:end func_L39_0058A5D0 */

/* localdecomp:start func_L39_0058A750 */
extern s32 D_L39_00240468;
extern s32 D_L39_0025CEF4[];
extern s32 D_L39_00241470;
extern u8 D_001A58BD[];
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_0038E150(s32);
extern s32 func_00381FF0(s32);
extern void func_0038E7E8_0058A750(long, f32, s32, f32, s32, f32, f32, s32, s32, unsigned long, f32, f32);

void func_L39_0058A750(void) {
    s32 col;
    f32 colf;
    f32 t;
    s32 save;

    if (D_L39_00240468 == 1) {
        col = 0x5A;
        t = (f32)(D_L39_0025CEF4[0] % 100) / 50.0f - 1.0f;
        if (D_001A58BD[0] != 0) {
            col = 0x30;
        }
        if (t < -1.0f) t = -1.0f;
        if (t > 1.0f) t = 1.0f;
        colf = (f32)col;
        col = func_0038DBD8((func_0038D098(t * 3.14159274f) + 1.0f) * 0.5f, 0x7FE0E0E0, 0x5F66CCFF);
        save = D_L39_00241470;
        func_0038E150(0);
        func_0038E7E8_0058A750(col, 480.0f, func_00381FF0(0x244), colf, -1, 1.0f, 1.0f, 2, 1, 0x80000000, 1.0f, 1.0f);
        func_0038E150(save);
    }
}
/* localdecomp:end func_L39_0058A750 */

/* localdecomp:start func_L39_0058A8B0 */
typedef struct { s16 start, end, text[7]; } R_0058A8B0;
typedef struct { u8 pad[0x34]; s32 time; u8 pad38[0x14]; u8 *subs; } S_0058A8B0;
extern S_0058A8B0 D_L39_0025CEC0_0058A8B0;
extern u8 D_001A5810_0058A8B0[];
typedef struct { s32 w, h; } Z_0058A8B0;
extern Z_0058A8B0 D_L39_00240300_0058A8B0;
extern void func_00390E60_0058A8B0(s32, s32, unsigned long, u8 *, s32);
extern void func_00390FB0_0058A8B0(s32, s32, s32, u8 *, s32);
extern void func_003910C0_0058A8B0(u16 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00391130_0058A8B0(u16 *, unsigned long, u8 *, s32);
extern u32 func_00120884_0058A8B0(u8 *);
extern void func_0038C3B0_0058A8B0(s32, s32, s32, s32, s32, s32);

void func_L39_0058A8B0(void) {
    R_0058A8B0 *end;
    R_0058A8B0 *p;
    s32 idx;
    s32 ty;
    s32 t, s, e;

    if (!D_L39_0025CEC0_0058A8B0.subs) return;
    idx = 0;
    if (D_001A5810_0058A8B0[0xB7] == 5) idx = D_001A5810_0058A8B0[0xB7] - 2;
    else if (D_001A5810_0058A8B0[0xB7] == 4) idx = D_001A5810_0058A8B0[0xB7];
    else if (D_001A5810_0058A8B0[0xB7] >= 2 && D_001A5810_0058A8B0[0xB7] < 6) idx = D_001A5810_0058A8B0[0xB7] - 1;

    end = (R_0058A8B0 *)(D_L39_0025CEC0_0058A8B0.subs + ((R_0058A8B0 *)D_L39_0025CEC0_0058A8B0.subs)->text[0]);
    p = (R_0058A8B0 *)D_L39_0025CEC0_0058A8B0.subs;
    ty = 0xD0;
    for (; p < end; p++) {
        t = D_L39_0025CEC0_0058A8B0.time;
        s = (p->start * 5 + 2) / 6;
        if (t < s) continue;
        e = (p->end * 5 + 2) / 6;
        if (e < t) continue;
        if (!D_001A5810_0058A8B0[6] && D_L39_0025CEC0_0058A8B0.subs[p->text[idx]] != '*') continue;
        if (D_L39_0025CEC0_0058A8B0.subs[p->text[idx]] == '*') {
            s32 y = 0x40;
            s32 alpha = 0xB0000000;
            s32 now;
            if (D_L39_0025CEC0_0058A8B0.subs[p->text[idx] + 1] != '*') y = D_L39_00240300_0058A8B0.h - 0xC8;
            else if (D_001A5810_0058A8B0[0xAD]) y = 0x18;
            now = D_L39_0025CEC0_0058A8B0.time;
            if ((p->end * 5 + 2) / 6 - now < 0x12)
                alpha = (s32)((p->end * 5 + 2) / 6 - (long)(now - 1)) << 27;
            else if (now - (p->start * 5 + 2) / 6 < 0x12)
                alpha = (s32)(now - (long)((p->start * 5 + 2) / 6 - 1)) << 27;
            if ((D_L39_0025CEC0_0058A8B0.subs + p->text[idx])[1] != '*') {
                func_00390E60_0058A8B0(0x100, ty, alpha | 0xE0E0E0, (D_L39_0025CEC0_0058A8B0.subs + p->text[idx]) + 1, -1);
                ty += 0x14;
            } else {
                func_00390FB0_0058A8B0(0x20, y, alpha | 0xE0E0E0, (D_L39_0025CEC0_0058A8B0.subs + p->text[idx]) + 2, -1);
            }
        } else {
            u16 win[16];
            s32 fade = 0x80;
            s32 c, color, hh, hw, w, n;
            s32 ext = D_L39_00240300_0058A8B0.h;
            n = D_001A5810_0058A8B0[0xAD] ? ext - 0x36 : ext - 0x64;
            if (e - t < 8) fade = (s32)(e - (long)(t - 1)) << 4;
            else if (t - s < 8) fade = (s32)(t - (long)(s - 1)) << 4;
            func_003910C0_0058A8B0(win, 0xC8, 0x1A4, 0x28, 0x1D8, 0x100,
                          n, 0x12, 7);
            color = fade + (fade >> 1);
            color = color | (color << 8) | (color << 16) | (fade << 24);
            func_00391130_0058A8B0(win, color, D_L39_0025CEC0_0058A8B0.subs + p->text[idx], -1);
            win[5] -= 4;
            hh = ((s16)win[7] >> 1) + 5;
            w = (s16)win[6] >> 1;
            hw = w + 10;
            if ((s16)win[5] + hh > D_L39_00240300_0058A8B0.h - 0x14)
                win[5] = D_L39_00240300_0058A8B0.h - (((s16)win[7] >> 1) + 0x19);
            win[9] &= ~4;
            if (func_00120884_0058A8B0(D_L39_0025CEC0_0058A8B0.subs + p->text[idx]) < 0x96) {
                func_0038C3B0_0058A8B0((s16)win[5] - hh, (s16)win[5] + hh, 0x100 - hw, 0x100 + hw,
                              (fade >> 1) + (fade >> 2), 0x40404);
                func_00391130_0058A8B0(win, color, D_L39_0025CEC0_0058A8B0.subs + p->text[idx], -1);
            }
            return;
        }
    }
}
/* localdecomp:end func_L39_0058A8B0 */

INCLUDE_ASM("asm/levels", func_L39_0058ACE0);

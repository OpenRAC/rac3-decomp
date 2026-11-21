#include "common.h"

/* NTSC-U counterpart of func_0038A8F8 (boot_elf). */
extern void func_U_0038A8A0(void);

/* localdecomp:start func_U_0038A8A0 */
typedef struct { s16 start, end, text[7]; } R_0038A8F8;
typedef struct { u8 pad[0x34]; s32 time; u8 pad38[0x14]; u8 *subs; } S_0038A8F8;
extern S_0038A8F8 D_U_00225780_0038A8A0;
extern u8 D_00143950_0038A8A0[];
typedef struct { s32 w, h; } Z_0038A8F8;
extern Z_0038A8F8 D_001D4BC0_0038A8A0;
extern void func_U_00391180_0038A8A0(s32, s32, unsigned long, u8 *, s32);
extern void func_U_003912D0_0038A8A0(s32, s32, s32, u8 *, s32);
extern void func_U_003913E0_0038A8A0(u16 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_U_00391450_0038A8A0(u16 *, unsigned long, u8 *, s32);
extern u32 func_0011B868_0038A8A0(u8 *);
extern void func_U_0038C6D8_0038A8A0(s32, s32, s32, s32, s32, s32);

/* from frontbin's func_0038A518 (src/frontbin/382380.c) */
void func_U_0038A8A0(void) {
    R_0038A8F8 *end;
    R_0038A8F8 *p;
    s32 idx;
    s32 ty;
    s32 t, s, e;

    if (!D_U_00225780_0038A8A0.subs) return;
    idx = 0;
    if (D_00143950_0038A8A0[0xB7] == 5) idx = D_00143950_0038A8A0[0xB7] - 2;
    else if (D_00143950_0038A8A0[0xB7] == 4) idx = D_00143950_0038A8A0[0xB7];
    else if (D_00143950_0038A8A0[0xB7] >= 2 && D_00143950_0038A8A0[0xB7] < 6) idx = D_00143950_0038A8A0[0xB7] - 1;

    end = (R_0038A8F8 *)(D_U_00225780_0038A8A0.subs + ((R_0038A8F8 *)D_U_00225780_0038A8A0.subs)->text[0]);
    p = (R_0038A8F8 *)D_U_00225780_0038A8A0.subs;
    ty = 0xD0;
    for (; p < end; p++) {
        s = p->start;
        t = D_U_00225780_0038A8A0.time;
        if (t < s) continue;
        e = p->end;
        if (e < t) continue;
        if (!D_00143950_0038A8A0[6] && D_U_00225780_0038A8A0.subs[p->text[idx]] != '*') continue;
        if (D_U_00225780_0038A8A0.subs[p->text[idx]] == '*') {
            s32 y = 0x40;
            s32 alpha = 0xB0000000;
            s32 now;
            if (D_U_00225780_0038A8A0.subs[p->text[idx] + 1] != '*') y = D_001D4BC0_0038A8A0.h - 0xC8;
            else if (D_00143950_0038A8A0[0xAD]) y = 0x18;
            now = D_U_00225780_0038A8A0.time;
            if (p->end - now < 0x12)
                alpha = (s32)(p->end - (long)(now - 1)) << 27;
            else if (now - p->start < 0x12)
                alpha = (s32)(now - (long)(p->start - 1)) << 27;
            if ((D_U_00225780_0038A8A0.subs + p->text[idx])[1] != '*') {
                func_U_00391180_0038A8A0(0x100, ty, alpha | 0xE0E0E0, (D_U_00225780_0038A8A0.subs + p->text[idx]) + 1, -1);
                ty += 0x14;
            } else {
                func_U_003912D0_0038A8A0(0x20, y, alpha | 0xE0E0E0, (D_U_00225780_0038A8A0.subs + p->text[idx]) + 2, -1);
            }
        } else {
            u16 win[16];
            s32 fade = 0x80;
            s32 c, color, hh, hw, w, n;
            s32 ext = D_001D4BC0_0038A8A0.h;
            n = D_00143950_0038A8A0[0xAD] ? ext - 0x36 : ext - 0x64;
            if (e - t < 8) fade = (s32)(e - (long)(t - 1)) << 4;
            else if (t - s < 8) fade = (s32)(t - (long)(s - 1)) << 4;
            func_U_003913E0_0038A8A0(win, 0xC8, 0x1A4, 0x28, 0x1D8, 0x100,
                          n, 0x12, 7);
            color = fade + (fade >> 1);
            color = color | (color << 8) | (color << 16) | (fade << 24);
            func_U_00391450_0038A8A0(win, color, D_U_00225780_0038A8A0.subs + p->text[idx], -1);
            win[5] -= 4;
            hh = ((s16)win[7] >> 1) + 5;
            w = (s16)win[6] >> 1;
            hw = w + 10;
            if ((s16)win[5] + hh > D_001D4BC0_0038A8A0.h - 0x14)
                win[5] = D_001D4BC0_0038A8A0.h - (((s16)win[7] >> 1) + 0x19);
            win[9] &= ~4;
            if (func_0011B868_0038A8A0(D_U_00225780_0038A8A0.subs + p->text[idx]) < 0x96) {
                func_U_0038C6D8_0038A8A0((s16)win[5] - hh, (s16)win[5] + hh, 0x100 - hw, 0x100 + hw,
                              (fade >> 1) + (fade >> 2), 0x40404);
                func_U_00391450_0038A8A0(win, color, D_U_00225780_0038A8A0.subs + p->text[idx], -1);
            }
            return;
        }
    }
}
/* localdecomp:end func_U_0038A8A0 */

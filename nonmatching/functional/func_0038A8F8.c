/* functional: high. EXACT: tools/check.py <file> func_0038A8F8 --target boot_elf reports MATCH under src/boot_elf/text/389978.c flags; ported from the matched frontbin twin func_0038A518 (src/frontbin/382380.c) by renaming callees to their boot_elf addresses. */
typedef struct { s16 start, end, text[7]; } R_0038A8F8;
typedef struct { u8 pad[0x34]; s32 time; u8 pad38[0x14]; u8 *subs; } S_0038A8F8;
extern S_0038A8F8 D_00225700_0038A8F8;
extern u8 D_00143950_0038A8F8[];
typedef struct { s32 w, h; } Z_0038A8F8;
extern Z_0038A8F8 D_001D4BC0_0038A8F8;
extern void func_00391240(s32, s32, unsigned long, u8 *, s32);
extern void func_00391390(s32, s32, s32, u8 *, s32);
extern void func_003914A0_0038A8F8(u16 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00391510(u16 *, unsigned long, u8 *, s32);
extern u32 func_0011B868_0038A8F8(u8 *);
extern void func_0038C790(s32, s32, s32, s32, s32, s32);

void func_0038A8F8(void) {
    R_0038A8F8 *end;
    R_0038A8F8 *p;
    s32 idx;
    s32 ty;
    s32 t, s, e;

    if (!D_00225700_0038A8F8.subs) return;
    idx = 0;
    if (D_00143950_0038A8F8[0xB7] == 5) idx = D_00143950_0038A8F8[0xB7] - 2;
    else if (D_00143950_0038A8F8[0xB7] == 4) idx = D_00143950_0038A8F8[0xB7];
    else if (D_00143950_0038A8F8[0xB7] >= 2 && D_00143950_0038A8F8[0xB7] < 6) idx = D_00143950_0038A8F8[0xB7] - 1;

    end = (R_0038A8F8 *)(D_00225700_0038A8F8.subs + ((R_0038A8F8 *)D_00225700_0038A8F8.subs)->text[0]);
    p = (R_0038A8F8 *)D_00225700_0038A8F8.subs;
    ty = 0xD0;
    for (; p < end; p++) {
        t = D_00225700_0038A8F8.time;
        s = (p->start * 5 + 2) / 6;
        if (t < s) continue;
        e = (p->end * 5 + 2) / 6;
        if (e < t) continue;
        if (!D_00143950_0038A8F8[6] && D_00225700_0038A8F8.subs[p->text[idx]] != '*') continue;
        if (D_00225700_0038A8F8.subs[p->text[idx]] == '*') {
            s32 y = 0x40;
            s32 alpha = 0xB0000000;
            s32 now;
            if (D_00225700_0038A8F8.subs[p->text[idx] + 1] != '*') y = D_001D4BC0_0038A8F8.h - 0xC8;
            else if (D_00143950_0038A8F8[0xAD]) y = 0x18;
            now = D_00225700_0038A8F8.time;
            if ((p->end * 5 + 2) / 6 - now < 0x12)
                alpha = (s32)((p->end * 5 + 2) / 6 - (long)(now - 1)) << 27;
            else if (now - (p->start * 5 + 2) / 6 < 0x12)
                alpha = (s32)(now - (long)((p->start * 5 + 2) / 6 - 1)) << 27;
            if ((D_00225700_0038A8F8.subs + p->text[idx])[1] != '*') {
                func_00391240(0x100, ty, alpha | 0xE0E0E0, (D_00225700_0038A8F8.subs + p->text[idx]) + 1, -1);
                ty += 0x14;
            } else {
                func_00391390(0x20, y, alpha | 0xE0E0E0, (D_00225700_0038A8F8.subs + p->text[idx]) + 2, -1);
            }
        } else {
            u16 win[16];
            s32 fade = 0x80;
            s32 c, color, hh, hw, w, n;
            s32 ext = D_001D4BC0_0038A8F8.h;
            n = D_00143950_0038A8F8[0xAD] ? ext - 0x36 : ext - 0x64;
            if (e - t < 8) fade = (s32)(e - (long)(t - 1)) << 4;
            else if (t - s < 8) fade = (s32)(t - (long)(s - 1)) << 4;
            func_003914A0_0038A8F8(win, 0xC8, 0x1A4, 0x28, 0x1D8, 0x100,
                          n, 0x12, 7);
            color = fade + (fade >> 1);
            color = color | (color << 8) | (color << 16) | (fade << 24);
            func_00391510(win, color, D_00225700_0038A8F8.subs + p->text[idx], -1);
            win[5] -= 4;
            hh = ((s16)win[7] >> 1) + 5;
            w = (s16)win[6] >> 1;
            hw = w + 10;
            if ((s16)win[5] + hh > D_001D4BC0_0038A8F8.h - 0x14)
                win[5] = D_001D4BC0_0038A8F8.h - (((s16)win[7] >> 1) + 0x19);
            win[9] &= ~4;
            if (func_0011B868_0038A8F8(D_00225700_0038A8F8.subs + p->text[idx]) < 0x96) {
                func_0038C790((s16)win[5] - hh, (s16)win[5] + hh, 0x100 - hw, 0x100 + hw,
                              (fade >> 1) + (fade >> 2), 0x40404);
                func_00391510(win, color, D_00225700_0038A8F8.subs + p->text[idx], -1);
            }
            return;
        }
    }
}

/* functional: high. Rewritten from the PAL asm (sibling of func_L01_00431810, with a zone lookup and per-type visibility tests). Register allocation and scheduling differ only. */
extern s32 D_L01_001D72A8[];   /* up to 10 object ids (0 terminated) */
extern s32 D_L01_001D72B8[];   /* per-id sprite parameter */
extern s32 D_L01_001D7290;
extern s32 D_001D545C;
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0020;
extern u8 D_00142BA0[];
extern u8 D_00142CA0[];
extern s32 D_L01_001F3F40[];
extern u8 D_L01_001F3F60[];
extern u8 D_L01_001F3F80[];
extern s32 func_L01_00430460(f32 *, s32);
extern s32 func_L01_0040F5B8(f32 *, void *, void *);
extern s32 func_L01_004316B0(f32, f32, f32 *, f32 *, s32, s32);
extern s32 func_00396968(s32, s32);
extern void func_L01_004208E0(s32, s32, s32, s32, s32, s32, s32);

void func_L01_00431B58(f32 x0, f32 x1, f32 y0, f32 y1, f32 size) {
    f32 pos[2];
    f32 big, dx, dy;
    u8 *p;
    s32 i, id, draw, zone, k, h;
    if (D_L01_001D72A8[0] == 0) return;
    for (i = 0; ; ) {
        if (D_001D545C == 3 && D_L01_001D72A8[i] == 0xB) goto next;
        for (p = D_L01_001E001C; p < D_L01_001E0020; p += 0x100) {
            if (p == 0) continue;
            id = *(s16 *)(p + 0xAA);
            if (id != D_L01_001D72A8[i]) continue;
            if (p[0x20] == 0xFE) continue;
            if (p[0x20] == 0xFD) continue;
            draw = 1;
            if (id == 0xB) {
                draw = func_L01_00430460((f32 *)(p + 0x10), 1);
                if (draw == 0 && D_00142CA0[5] == 0) continue;
                draw = 1;
            } else if (id == 0x1F28) {
                draw = *(s32 *)(D_00142BA0 + 0x94) & 0x200000;
                if (draw == 0 && D_00142CA0[5] == 0) continue;
                draw = 1;
            }
            zone = 0;
            for (k = D_L01_001F3F40[3] - 1; k >= 0; k--) {
                if (func_L01_0040F5B8((f32 *)(p + 0x10), D_L01_001F3F60 + k * 16, D_L01_001F3F80 + k * 16) != 0) {
                    zone = k + 1;
                    break;
                }
            }
            dx = x1 - x0;
            dy = y1 - y0;
            func_L01_004316B0(*(f32 *)(p + 0x10), *(f32 *)(p + 0x14), &pos[0], &pos[1], D_001D545C, zone);
            pos[0] = x0 + pos[0] * dx - size * 64.0f;
            pos[1] = y0 + pos[1] * dy - size * 64.0f;
            h = func_00396968(0xE99A, D_L01_001D72B8[i]);
            big = size * 128.0f;
            func_L01_004208E0(h, (s32)pos[0], (s32)pos[1], (s32)(big + 24.0f), (s32)(big + 24.0f), 0x64, 0x80000000);
            h = func_00396968(0xE99A, D_L01_001D72B8[i]);
            func_L01_004208E0(h, (s32)pos[0], (s32)pos[1], (s32)big, (s32)big, 0x64, D_L01_001D7290);
        }
next:
        if (D_L01_001D72A8[i + 1] == 0) return;
        i++;
        if (i >= 10) return;
    }
}

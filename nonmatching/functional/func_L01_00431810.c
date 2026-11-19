/* functional: high. Rewritten from the PAL asm. Retail reads pos[] stale (uninitialised on the first hit) when a 0x199F/0x19C2 object fails its map-visibility test: pos is function-scope here so it stays stale the same way. Registers and scheduling differ only. */
extern u8 D_L01_001D7294;   /* blip alpha */
extern u8 D_L01_001D7298;   /* alpha step up */
extern u8 D_L01_001D729C;   /* alpha step down */
extern u8 D_L01_001D72A0;   /* alpha direction */
extern s32 D_L01_001D7278[];   /* up to 10 object ids (0 terminated) */
extern s32 D_L01_001D728C;
extern s32 D_001D545C;
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0020;
extern u8 D_L01_00237C64[];
extern u8 D_001BBE90[];
extern s32 func_L01_004316B0(f32, f32, f32 *, f32 *, s32, s32);
extern s32 func_00396968(s32, s32);
extern void func_L01_004208E0(s32, s32, s32, s32, s32, s32, s32);

void func_L01_00431810(f32 x0, f32 x1, f32 y0, f32 y1, f32 size) {
    f32 pos[2];
    f32 big, half;
    u8 *p;
    s32 i, id, v, nib, call, h, a;
    if (D_L01_001D72A0 != 0) a = D_L01_001D7294 + D_L01_001D7298;
    else a = D_L01_001D7294 - D_L01_001D729C;
    D_L01_001D7294 = a;
    if ((u8)(a - 0x60) >= 0x91) {
        D_L01_001D72A0 ^= 1;
        if ((a & 0xFF) > 0xF0) D_L01_001D7294 = 0xF0;
        if (D_L01_001D7294 < 0x30) D_L01_001D7294 = 0x30;
    }
    if (D_L01_001D7278[0] == 0) return;
    p = D_L01_001E001C;
    for (i = 0; ; ) {
        for (; p < D_L01_001E0020; p += 0x100) {
            if (p == 0) continue;
            id = *(s16 *)(p + 0xAA);
            if (id != D_L01_001D7278[i]) continue;
            if (p[0x20] == 0xFE) continue;
            if (p[0x20] == 0xFD) continue;
            call = 1;
            if (id == 0x199F || id == 0x19C2) {
                call = 0;
                v = *(s16 *)(p + 0xB2);
                if (D_L01_00237C64[v] == 0) {
                    nib = D_001BBE90[D_001D545C * 1024 + (v >> 1)];
                    nib = (v & 1) ? (nib >> 4) & 7 : nib & 7;
                    if (nib == 0) call = 1;
                }
            }
            if (call) func_L01_004316B0(*(f32 *)(p + 0x10), *(f32 *)(p + 0x14), &pos[0], &pos[1], D_001D545C, -1);
            big = size * 96.0f;
            half = big * 0.5f;
            pos[0] = x0 + pos[0] * (x1 - x0) - half;
            pos[1] = y0 + pos[1] * (y1 - y0) - half;
            h = func_00396968(0xEAA2, 1);
            func_L01_004208E0(h, (s32)pos[0], (s32)pos[1], (s32)(big + 24.0f), (s32)(big + 24.0f), D_L01_001D7294, 0x80000000);
            h = func_00396968(0xEAA2, 1);
            func_L01_004208E0(h, (s32)pos[0], (s32)pos[1], (s32)big, (s32)big, D_L01_001D7294, D_L01_001D728C);
        }
        if (D_L01_001D7278[i + 1] == 0) return;
        i++;
        if (i >= 10) return;
        p = D_L01_001E001C;
    }
}

/* US draft of func_003C1318 (rac3-uya-decomp func_003C1210, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C1318 */
typedef struct { u8 p0[0x24]; struct { u8 p[0x24]; f32 f24; } *w24; u8 p28[4]; f32 f2C; u8 p30[0x32]; u8 b62; u8 p63[0x32]; u8 b95; u8 p96[0x14]; s16 hAA; } Q_3BBA50;
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x12]; Q_3BBA50 *w54; } G_3BBA50;
extern G_3BBA50 D_00225700_003C1318[];
extern u8 D_002D2008_003C1318[];
extern u32 D_001DA49C;
extern u32 D_001DA4A0;
extern f32 D_001D6EF0;
extern Q_3BBA50 *D_001DA008;
extern Q_3BBA50 *D_0022D8B0_003C1318[];
extern void func_003C8190();
extern void func_003A5CC0();
__asm__(".extern D_001DA49C, 16");
__asm__(".extern D_001DA4A0, 16");
__asm__(".extern D_001DA008, 16");
s32 func_003C1318(s32 a) {
    u32 p;
    s32 r;
    f32 f;
    Q_3BBA50 **pp;
    Q_3BBA50 *q;
    s32 i;
    Q_3BBA50 *g;
    r = 0;
    for (p = D_001DA49C; p < D_001DA4A0; p += 0x100) {
        func_003C8190(p);
    }
    D_002D2008_003C1318[0x50] = func_003BDFB0();
    D_00225700_003C1318->w54->b95 = 0xE8;
    D_00225700_003C1318->w54->b62 = 0xFF;
    if (D_002D2008_003C1318[0x51] != 0) {
        if (D_00225700_003C1318->h40 - 0x50 < D_00225700_003C1318->w34) {
            f = (f32)(D_00225700_003C1318->h40 - D_00225700_003C1318->w34 - 4) * 0.013157895f;
            if (f < 0.0f) f = 0.0f;
            D_00225700_003C1318->w54->f2C = D_00225700_003C1318->w54->w24->f24 * f;
            D_001D6EF0 = f;
            g = *(Q_3BBA50 * volatile *)&D_001DA008;
            if (g != 0) {
                g->f2C = g->w24->f24 * f;
            }
            D_00225700_003C1318->w54->b95 = (s32)(f * 232.0f);
            if (D_00225700_003C1318->w54->hAA == 0xD54 && D_001DA008 == 0 && D_0022D8B0_003C1318[0] != 0) {
                i = 0;
                do {
                    D_0022D8B0_003C1318[i]->f2C = D_0022D8B0_003C1318[i]->w24->f24 * f;
                    i++;
                } while (D_0022D8B0_003C1318[i] != 0);
            }
        }
    }
    if (D_002D2008_003C1318[0x50] != 0) {
        if (a != 0) r = D_002D2008_003C1318[0x51] != 0;
    }
    func_003A5CC0(D_00225700_003C1318->w54, 1);
    return r;
}
/* localdecomp:end func_003C1318 */

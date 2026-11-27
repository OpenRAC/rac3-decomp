#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CC88_00391678(void *, void *, s32) __asm__("func_0038CC88");
u8 func_003BDBF8(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C0F60 */
typedef struct { u8 p0[0x24]; struct { u8 p[0x24]; f32 f24; } *w24; u8 p28[4]; f32 f2C; u8 p30[0x32]; u8 b62; u8 p63[0x32]; u8 b95; u8 p96[0x14]; s16 hAA; } Q_3BBA50;
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x12]; Q_3BBA50 *w54; } G_3BBA50;
extern G_3BBA50 D_00225700_003C0F60[];
extern u8 D_002D2008_003C0F60[];
extern u32 D_001DA49C;
extern u32 D_001DA4A0;
extern f32 D_001D6EF0;
extern Q_3BBA50 *D_001DA008;
extern Q_3BBA50 *D_0022D8B0_003C0F60[];
extern void func_003C7DD8();
extern void func_003A58C0();
__asm__(".extern D_001DA49C, 16");
__asm__(".extern D_001DA4A0, 16");
__asm__(".extern D_001DA008, 16");
s32 func_003C0F60(s32 a) {
    u32 p;
    s32 r;
    f32 f;
    Q_3BBA50 **pp;
    Q_3BBA50 *q;
    s32 i;
    Q_3BBA50 *g;
    r = 0;
    for (p = D_001DA49C; p < D_001DA4A0; p += 0x100) {
        func_003C7DD8(p);
    }
    D_002D2008_003C0F60[0x50] = func_003BDBF8();
    D_00225700_003C0F60->w54->b95 = 0xE8;
    D_00225700_003C0F60->w54->b62 = 0xFF;
    if (D_002D2008_003C0F60[0x51] != 0) {
        if (D_00225700_003C0F60->h40 - 0x50 < D_00225700_003C0F60->w34) {
            f = (f32)(D_00225700_003C0F60->h40 - D_00225700_003C0F60->w34 - 4) * 0.013157895f;
            if (f < 0.0f) f = 0.0f;
            D_00225700_003C0F60->w54->f2C = D_00225700_003C0F60->w54->w24->f24 * f;
            D_001D6EF0 = f;
            g = *(Q_3BBA50 * volatile *)&D_001DA008;
            if (g != 0) {
                g->f2C = g->w24->f24 * f;
            }
            D_00225700_003C0F60->w54->b95 = (s32)(f * 232.0f);
            if (D_00225700_003C0F60->w54->hAA == 0xD54 && D_001DA008 == 0 && D_0022D8B0_003C0F60[0] != 0) {
                i = 0;
                do {
                    D_0022D8B0_003C0F60[i]->f2C = D_0022D8B0_003C0F60[i]->w24->f24 * f;
                    i++;
                } while (D_0022D8B0_003C0F60[i] != 0);
            }
        }
    }
    if (D_002D2008_003C0F60[0x50] != 0) {
        if (a != 0) r = D_002D2008_003C0F60[0x51] != 0;
    }
    func_003A58C0(D_00225700_003C0F60->w54, 1);
    return r;
}
/* localdecomp:end func_003C0F60 */

/* US draft of func_003C1158 (rac3-uya-decomp func_003BBC48, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003C1158 */
extern s32 D_001D9030_003C1158;
extern u8 D_002D2008_003C1158[];
extern u8 D_00225700_003C1158[];
extern void func_003BC768();
extern s32 func_003BDF10();
extern s32 func_003BDF18();
extern void func_003BB968();
extern void func_003BE168();
extern s32 func_003BDD38();
extern void func_003BDE60();
extern void func_003BE308();
extern void func_003BDF40();
extern void func_003C0CA0();
extern void func_003BDF60();
extern void func_003C0F00();
__asm__(".extern D_001D9030_003C1158, 4");
void func_003C1158(s32 a0) {
    s32 v4;
    s32 v5;
    u8 *g;
    if (D_002D2008_003C1158[0x50] != 0) {
        func_003BC768();
        if (func_003BDF10() == 1) {
            func_003BE168();
        }
        if (func_003BDF10() > 0 && func_003BDF18() != 0) {
            func_003BB968();
        }
        if (D_002D2008_003C1158[0x51] == 0) {
            if (func_003BDF10() > 0 && a0 != 0) {
                v4 = D_001D9030_003C1158;
                D_002D2008_003C1158[0x51] = 1;
            } else {
                v4 = func_003BDD38();
            }
            func_003BDE60(v4);
            func_003BE308(func_003C0F00);
            func_003BDF40();
            func_003C0CA0();
        }
    }
    g = D_00225700_003C1158;
    v5 = *(s16 *)(g + 0x40);
    if (D_002D2008_003C1158[0x51] != 0) {
        if (*(s32 *)(g + 0x34) >= 0x1F) v5 += 0x1E;
    }
    func_003BDF60(*(s32 *)(g + 0x34), v5, 6, 6);
}
/* localdecomp:end func_003C1158 */

/* US draft of func_003C1280 (rac3-uya-decomp func_003BBD70, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003BBD98. */


/* localdecomp:start func_003C1280 */
extern void func_00389D60(void (*)(), s32);
extern void func_003C12A8();
 
void func_003C1280(s32 a0) {
    func_00389D60(func_003C12A8, a0);
}
/* localdecomp:end func_003C1280 */

#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003A0090();
/* --- end of declarations from other files --- */

/* localdecomp:start func_0039FDA0 */
typedef struct { u8 b[0x20]; } R_39AE08;
typedef struct { u8 p0[0x80]; f32 f80; f32 f84; f32 f88; } S_39AE08;
__asm__(".extern D_001D68E0, 8");
__asm__(".extern D_001D6900, 8");
__asm__(".extern D_001D6920, 8");
__asm__(".extern D_001D6960, 8");
__asm__(".extern D_001D69A0, 8");
__asm__(".extern D_001D69E0, 8");
__asm__(".extern D_001D6A20, 8");
__asm__(".extern D_001D6A40, 8");
__asm__(".extern D_001D6A60, 8");
extern u8 D_001D68E0[8];
extern u8 D_001D6900[8];
extern u8 D_001D6920[8];
extern u8 D_001D6960[8];
extern u8 D_001D6980[8];
extern u8 D_001D69A0[8];
extern u8 D_001D69C0[8];
extern u8 D_001D69E0[8];
extern u8 D_001D6A00[8];
extern u8 D_001D6A20[8];
extern u8 D_001D6A40[8];
extern u8 D_001D6A60[8];
extern R_39AE08 D_00333BB8[];
extern R_39AE08 D_00334398;
extern R_39AE08 D_00334378;
extern R_39AE08 D_00334358;
extern R_39AE08 D_00333CD8;
extern R_39AE08 D_00333E18;
extern R_39AE08 D_00333E58;
extern R_39AE08 D_00333E98;
extern s32 D_0022CC50[];
extern f32 D_001A4C60[];
extern u8 D_001A71C4[];
extern S_39AE08 D_1A4BE0;
R_39AE08 *func_0039FDA0(s32 lvl, s32 sub) {
    s32 k;
    f32 x, y;
    if (sub == -1) k = D_0022CC50[0] - 1; else k = sub;
    if (sub == -1) sub = D_0022CC50[0];
    switch (lvl) {
    case 1:
        if (D_001A4C60[0] <= 300.0f) return (R_39AE08 *)D_001D68E0;
        return &D_00333BB8[lvl];
    case 2:
        x = D_1A4BE0.f80;
        if (116.91f <= x) {
            y = D_1A4BE0.f84;
            if (y <= 331.38f && x <= 276.94f && 155.16f <= y) return (R_39AE08 *)D_001D6900;
        }
        return &D_00333BB8[lvl];
    case 3:
        x = D_001A4C60[0];
        if (452.0f < x) return &D_00334398;
        if (261.0f < x) return &D_00334378;
        return &D_00334358;
    case 4:
        if (sub > 0) return (R_39AE08 *)D_001D6920 + k;
        break;
    case 7:
        if (D_1A4BE0.f88 < 130.0f) return (R_39AE08 *)D_001D6980;
        if (600.0f < D_1A4BE0.f84) return (R_39AE08 *)D_001D6960;
        return &D_00333BB8[lvl];
    case 9:
        if (sub == 2) return (R_39AE08 *)D_001D69A0;
        if (sub == 1) return (R_39AE08 *)D_001D69C0;
        return &D_00333CD8;
    case 10:
        if (sub > 0) return (R_39AE08 *)D_001D6A00;
        return (R_39AE08 *)D_001D69E0;
    case 19:
        if (sub > 0) return (R_39AE08 *)D_001D6A20;
        return &D_00333E18;
    case 21:
        if (525.0f < D_001A4C60[0]) return (R_39AE08 *)D_001D6A40;
        return &D_00333E58;
    case 23:
        if (D_001A71C4[0] == 2) return (R_39AE08 *)D_001D6A60;
        return &D_00333E98;
    case 5: case 6: case 8: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 20: case 22:
        break;
    }
    return &D_00333BB8[lvl];
}
/* localdecomp:end func_0039FDA0 */

LINKER_REMNANT("asm/remnants", func_003A0080);

/* func_003A0090: from the US C of func_0039B0F8 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003A0090 */
extern u32 D_001D545C_003A0090;
__asm__(".extern D_001D545C_003A0090, 16");
typedef struct { u8 pad[0x10]; f32 f10; f32 f14; u8 pad2[0xE0]; f32 fF8; } O_39B0F8;
typedef struct { f32 x, y, z, w; } V_39B0F8;
/* retail reaches 0x1D545C with lui/lw (destination reused), not through $gp:
   the load goes through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did) */
extern s32 D_003374F0[];
extern O_39B0F8 *D_0022C8E0[];
extern V_39B0F8 D_143230[];
void func_003A0090(void) {
    u32 idx = D_001D545C_003A0090;
    s32 i;
    if (idx < 0x13) {
        for (i = D_003374F0[idx]; i < D_003374F0[idx + 1]; i++) {
            O_39B0F8 *o = D_0022C8E0[i];
            if (o) {
                D_143230[i].x = o->f10;
                D_143230[i].y = o->f14;
                D_143230[i].z = o->fF8;
            }
        }
    }
}
/* localdecomp:end func_003A0090 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A0130);
TEXT_PADDING(8);

#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void func_003A8630(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003A8678();
extern s32 func_003A8770(s32);


typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A2EE0;
typedef struct {
    V4_3A2EE0 v0; V4_3A2EE0 v10;
    f32 f20; f32 f24; f32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C;
    s32 f40; s32 f44; s32 f48; s32 f4C;
} E_3A2EE0;
extern u8 *D_001D6EEC;
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_0038CAD0(void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003A8308);

typedef struct { u8 pad0[0x24]; f32 f24; f32 f28; u8 pad2C[4]; s32 f30; u8 pad34[4]; s32 f38; s32 f3C; u8 pad40[8]; s32 f48; s32 f4C; } E_3A3028;
extern E_3A3028 *D_001D6EEC_003A8450;
extern f32 D_001D6EF0;
/* localdecomp:start func_003A8450 */
/* PAL candidate for func_003A8450 (from the US draft, rac3-uya-decomp func_003A8708, commit 13cf5c5).
   The US callee func_003D9760 is at 0x003D98C0 in PAL: it is func_003D9508 there. */


__asm__(".extern D_001D6EEC_003A8450_003A8450, 4");
__asm__(".extern D_001D6EF0_003A8450, 4");
typedef struct { u8 pad0[0x24]; f32 f24; f32 f28; u8 pad2C[4]; s32 f30; u8 pad34[4]; s32 f38; s32 f3C; u8 pad40[8]; s32 f48; s32 f4C; } E_3A3028_003A8450;
extern E_3A3028_003A8450 *D_001D6EEC_003A8450_003A8450;
extern f32 D_001D6EF0_003A8450;
extern void func_003D9508(E_3A3028_003A8450 *, s32, s32, s32, f32, f32, f32);
void func_003A8450(void) {
    s32 i;
    s32 off;
    if (D_001D6EEC_003A8450_003A8450) {
        off = 0;
        for (i = 0x1FF; i >= 0; i--) {
            E_3A3028_003A8450 *e = (E_3A3028_003A8450 *)((u8 *)D_001D6EEC_003A8450_003A8450 + off);
            if (e->f48) {
                s32 s = e->f3C >> 1;
                s32 flag = 1;
                if (s) { s = s ^ 1; flag = s != 0; }
                func_003D9508(e, e->f4C, e->f30 | ((s32)((f32)e->f38 * D_001D6EF0_003A8450) << 24), flag, e->f28, 0.001f, e->f24);
            }
            off += 0x50;
        }
    }
}
/* localdecomp:end func_003A8450 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A8500);

LINKER_REMNANT("asm/remnants", func_003A8628);

/* PAL retail bytes for func_003A8630.
   The three globals are reached through `lui $at` in retail (not through $gp): the
   assembler's expansion, through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did)
   (docs/wiki/Matching-Patterns.md, "Globals: gp vs lui"). */

extern s32 D_0022DF20[];

/* localdecomp:start func_003A8630 */
extern s32 D_001D4B34_003A8630;
extern s32 D_001D4B30_003A8630;
extern s32 D_001D4B00_003A8630;
__asm__(".extern D_001D4B34_003A8630, 16");
__asm__(".extern D_001D4B30_003A8630, 16");
__asm__(".extern D_001D4B00_003A8630, 16");
extern s32 D_0022DF20[];
void func_003A8630(void) {
    s32 i;
    s32 *p = D_0022DF20;
    D_001D4B34_003A8630 = 0;
    D_001D4B30_003A8630 = D_001D4B00_003A8630;
    for (i = 0x3F; i >= 0; i--) {
        p[0] = 0;
        p[1] = 0;
        p += 4;
    }
}
/* localdecomp:end func_003A8630 */

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } E_3A3128;
extern s32 D_001D4B00;
extern s32 D_001D4B04;
extern s32 D_001D4B30;
extern s32 D_001D4B34;
extern E_3A3128 D_0022DF20_3A3128[];
extern s32 func_11F1E0();
INCLUDE_ASM("asm/nonmatchings/text", func_003A8678);

extern u8 D_001D7FC0;
/* localdecomp:start func_003A8770 */
extern u8 D_001D7FC0_003A8770;
__asm__(".extern D_001D7FC0_003A8770, 8");
s32 func_003A8770(s32 arg0) {
    s32 i;
    s32 v;
    if (arg0 >= 100) {
        for (i = 0x3B; i >= 0; i--) {
            v = *(&D_001D7FC0_003A8770 + i);
            if (arg0 >= v && v != 0) {
                arg0 -= v;
                break;
            }
        }
    }
    return arg0;
}
/* localdecomp:end func_003A8770 */

#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003BCB20();
extern void func_003BE2F8();
extern void func_003C1058();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C1848 */
/* PAL candidate for func_003C1848 (frontbin). The US draft called func_003A26D0;
   in PAL that callee is func_003A7EF8 (src/frontbin/3A53E8.c). */

extern void func_003A6B90_003C1848(void *);
extern void func_003A7EF8(void *);
extern void func_003A8850_003C1848();
void func_003C1848(u8 *p) {
    if (p[0x95] < 11) return;
    func_003A6B90_003C1848(p);
    func_003A7EF8(p);
    func_003A8850_003C1848();
}
/* localdecomp:end func_003C1848 */

/* localdecomp:start func_003C1890 */
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3BBFC8;
extern u8 D_002D2008[];
extern S_3BBFC8 D_00225700_003C1890;
extern void func_003BCEB0();
extern void func_0038E530(s32);
extern void func_00389620();
extern void func_00389750();
extern void func_0038EBC8_003C1890(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
void func_003C1890(void) {
    s32 v;
    u8 *s;
    S_3BBFC8 *g;
    func_003BCEB0();
    s = D_002D2008;
    if (s[0x51] != 0) {
        func_0038E530(1);
        func_00389620(1);
        g = &D_00225700_003C1890;
        v = 0xE0 - (g->h40 - g->f34) * 3;
        if (v < 0) v = 0;
        if (v > 0xC0) v = 0xC0;
        if (v > 0) {
            func_0038EBC8_003C1890(70.0f, (f32)(*(s32 *)0x1D4BC4 - 0x5A), (v << 24) | 0xC37A33, s + 0x10, -1, 1.5f, 1.5f, 0, 1, (unsigned long)(s32)0x80000000, 2.0f, 2.0f);
        }
        func_00389750();
    }
}
/* localdecomp:end func_003C1890 */

/* localdecomp:start func_003C1980 */
extern s16 D_0016C5AC[];
 
void func_003C1980(void) {
    func_003BE2F8();
    func_003BCB20();
    func_003C1058();
    D_0016C5AC[0] = 1;
}
/* localdecomp:end func_003C1980 */

extern s32 func_003823D0(s32);
extern void func_003BBDC0(s32, s32);
extern void func_003BC7C0(s32, s32);
extern s32 func_0011B754(void *, s32);
extern u8 D_001D9088;
extern volatile s32 D_001D4B4C;
typedef struct { u8 n0[0x10]; u8 n1[0x10]; u8 n2[0x10]; s32 f30, f34, f38, f3C, f40, f44, f48, f4C, f50; u8 p54[0xC]; s8 f60; } S_BC0F0;
extern S_BC0F0 D_002D2060[];
typedef struct { u8 pad[0x1AF8]; s32 f1AF8; u8 p2[0x1B14-0x1AFC]; s32 f1B14, f1B18, f1B1C; } S_BC0F0b;
extern S_BC0F0b D_001A4BE0[];
/* localdecomp:start func_003C19B8 */
typedef struct { s32 f0; s32 f4; } S_003C19B8;
__asm__(".extern D_001D4B48_003C19B8, 16");
extern S_003C19B8 D_001D4B48_003C19B8;
s32 func_003C19B8(s32 arg0, s32 arg1) {
    S_BC0F0 *p = D_002D2060;
    S_BC0F0b *q;
    func_0011B754(p->n0, func_003823D0(0x1645));
    func_0011B754(p->n1, func_003823D0(0x1646));
    func_0011B754(p->n2, func_003823D0(0xF07));
    p->f30 = 0;
    q = D_001A4BE0;
    p->f34 = q->f1B14;
    p->f38 = q->f1B1C;
    p->f3C = q->f1B18;
    p->f40 = arg1;
    if (arg1 != 0 && q->f1AF8 != 0) {
        p->f40 = 0;
    }
    D_002D2060->f44 = arg0;
    D_002D2060->f60 = 0;
    func_003BBDC0(0, 0);
    if (D_002D2060->f40 == 0) {
        D_002D2060->f48 = 0;
        D_002D2060->f4C = 0x32;
        D_002D2060->f50 = 0;
        D_001D4B48_003C19B8.f4 = 0;
    } else {
        D_002D2060->f48 = 0;
        D_002D2060->f4C = 0x32;
        func_003BC7C0(3, (s32)&D_001D9088);
    }
    return 1;
}
/* localdecomp:end func_003C19B8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C1AE0);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C9D0);

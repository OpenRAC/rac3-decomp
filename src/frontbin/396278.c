#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CC88_00391678(void *, void *, s32) __asm__("func_0038CC88");
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
extern s32 func_00393620(S_38EDE8 *p, s32 *x, s32 *y);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00396278 */
/* the copy of func_00396658 */
typedef struct { u8 p0[8]; s32 w8; u8 pC[0x44]; s32 w50; s32 w54; s32 w58; s32 w5C; u8 p60[0xC]; s32 w6C; u8 p70[4]; s32 w74; } O_91A18_00396278;
extern s32 func_00396968();
extern void func_00396C60();
extern void func_003970D8();
extern void func_00393690();
extern s16 D_001A666A[];
s32 func_00396278(O_91A18_00396278 *o) {
    s32 x, y, h;
    x = o->w50;
    y = o->w54;
    o->w58 = 0x100;
    o->w5C = 0x40;
    func_00393620(o, &x, &y);
    func_00393690(o, &x, &y, o->w6C, 0);
    h = o->w74 * 0xDD / o->w8 + 0x1B;
    func_003970D8(func_00396968(0x7558, 1), x, y, h, 0x40, 0x80);
    func_00396C60(func_00396968(0x7558, 0), x, y, 0x100, 0x40, 0x80);
    func_00396C60(func_00396968(0x7558, 2), x, y, 0x20, 0x20, D_001A666A[0] == 0 ? 0 : 0x80);
    return o->w58;
}
/* localdecomp:end func_00396278 */

typedef struct { u8 p0[8]; s32 w8; u8 pC[0x44]; s32 w50; s32 w54; s32 w58; s32 w5C; u8 p60[0xC]; s32 w6C; u8 p70[4]; s32 w74; } O_91A18;
extern void func_00396C60();
extern void func_003970D8();
extern void func_00393690();
extern s16 D_001A666A[];

/* PAL candidate for func_00396390 (frontbin).
   Same shape as the US draft; the constant stored at offset 0x7C is 0x82 in PAL
   retail (0x96 in the US build). */

/* localdecomp:start func_00396390 */
extern void func_00393808(void *);
 
void func_00396390(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0x82;
    *(s32 *)((u8 *)p + 0x58) = 0x20;
    *(s32 *)((u8 *)p + 0x5C) = 0x20;
    func_00393808(p);
}
/* localdecomp:end func_00396390 */

/* localdecomp:start func_003963C0 */
s32 func_003963C0(void) {
    return 0;
}
/* localdecomp:end func_003963C0 */

LINKER_REMNANT("asm/remnants", func_003963C8);

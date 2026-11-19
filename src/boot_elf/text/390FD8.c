#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003914A0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 38E518.c's earlier functions */
extern s32 D_001D55E8;
extern void func_0038E7A0(s32 a);
extern s32 func_0038E928(u8 *str, s32 len, f32 scale);
extern void func_0038FDC0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);

/* localdecomp:start func_00390FD8 */
f32 func_00390FD8(s32 a, s32 unused, s32 c, f32 f) {
    f32 r = 1.0f;
    s32 t;
    if (a) t = ((s32 (*)(f32))func_0038E928)(1.0f); else t = 0;
    if (c < t) {
        r = (f32)c / (f32)t;
        if (r < f) r = f;
    }
    return r;
}
/* localdecomp:end func_00390FD8 */

/* localdecomp:start func_00391068 */
extern void func_0038E5C8(void);

void func_00391068(void) {
    func_0038E5C8();
}
/* localdecomp:end func_00391068 */

/* localdecomp:start func_00391088 */
extern void func_0038E7A0();

void func_00391088(void) {
    func_0038E7A0(1);
}
/* localdecomp:end func_00391088 */

/* localdecomp:start func_003910A8 */
extern void func_0038E7A0();
 
void func_003910A8(void) {
    func_0038E7A0(0);
}
/* localdecomp:end func_003910A8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003910C8);

/* localdecomp:start func_00391100 */

void func_00391100(void) {
    ((void (*)())func_0038E928)();
}
/* localdecomp:end func_00391100 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391120);

/* localdecomp:start func_00391128 */
 
void func_00391128(void) {
    ((void (*)())func_0038E928)();
}
/* localdecomp:end func_00391128 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391148);

/* localdecomp:start func_00391150 */
 
void func_00391150(s32 a, s32 b, s32 c, f32 d) {
    ((void (*)())func_0038E928)();
}
/* localdecomp:end func_00391150 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391170);

/* localdecomp:start func_00391198 */
extern void func_0038EBC8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
s32 func_00391198(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    ((void (*)(float, float, float, float, float, float, s32, s32, s32, s32, s32, unsigned long))func_0038EBC8)((float)a0, (float)a1, 1.0f, 1.0f, 0.0f, 0.0f, a2, a3, a4, 1, 0, 0x80000000UL);
    return a0 - (((s32 (*)(s32, s32, float))func_0038E928)(a3, a4, 1.0f) >> 1);
}
/* localdecomp:end func_00391198 */

/* localdecomp:start func_00391240 */
extern s32 D_001D55E8;
extern void func_0038E530(s32);
extern void func_0038EBC8_00391240(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
extern s32 func_0038E928_00391240(s32, s32, f32);
s32 func_00391240(s32 x, s32 y, s32 a, s32 b, s32 c) {
    s32 saved;
    saved = D_001D55E8;
    func_0038E530(1);
    func_0038EBC8_00391240(a, b, c, 1, 0, 0x80000000UL, (f32)x, (f32)y, 1.0f, 1.0f, 0.0f, 0.0f);
    x -= func_0038E928_00391240(b, c, 1.0f) >> 1;
    func_0038E530(saved);
    return x;
}
/* localdecomp:end func_00391240 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391320);

/* localdecomp:start func_00391330 */
extern void func_0038EBC8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
void func_00391330(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, f32 p) {
    func_0038EBC8((f32)a0, (f32)a1, p, p, a2, a3, a4, 1, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_00391330 */

/* localdecomp:start func_00391390 */
__asm__(".extern D_001D55E8, 4");
extern s32 D_001D55E8;
extern void func_0038E530(s32);
void func_00391390(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 save;
    save = D_001D55E8;
    func_0038E530(1);
    ((void (*)(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32))func_0038EBC8)(c, d, e, 0, 0, 0x80000000, (f32)a, (f32)b, 1.0f, 1.0f, 0.0f, 0.0f);
    func_0038E530(save);
}
/* localdecomp:end func_00391390 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391448);

/* localdecomp:start func_00391458 */
extern void func_0038EBC8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
void func_00391458(s32 a0, s32 a1, s32 a2, f32 x, f32 y, f32 z) {
    func_0038EBC8(x, y, z, z, a0, a1, a2, 0, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_00391458 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391490);

/* localdecomp:start func_003914A0 */
void func_003914A0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    func_0038FDC0(p, a, b, c, d, e, f, g, h);
}
/* localdecomp:end func_003914A0 */

/* PAL candidate for func_003914C0.
   The US draft called func_0038FD40; in PAL that callee lives at func_0038FDF8.
   The argument list and the expression order are unchanged from the draft, so the
   only difference from the US draft's output is the jal target. */

/* localdecomp:start func_003914C0 */
extern void func_0038FDF8(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_003914C0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038FDF8(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_003914C0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003914F0);

/* PAL draft of func_00391510 (US rac3-uya-decomp func_00391450, commit 13cf5c5).
   The US callee func_0038FD40 is func_0038FDF8 in the PAL retail. */


/* localdecomp:start func_00391510 */
extern s32 D_001D55E8;
extern void func_0038E530(s32);
extern void func_0038FDF8(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_00391510(s32 a, s32 b, s32 c, s32 d) {
    s32 old = D_001D55E8;
    func_0038E530(1);
    ((void (*)(s32, s32, s32, s32, f32, f32, unsigned long))func_0038FDF8)(a, b, c, d, 1.0f, 1.0f, 0x80000000UL);
    func_0038E530(old);
}
/* localdecomp:end func_00391510 */

/* func_00391598: the PAL retail calls func_0038FDF8; the US draft's callee
   func_0038FD40 was never mapped to a PAL address, so it kept the US name
   (and the wrong jal target). Same call, PAL name. */

/* localdecomp:start func_00391598 */
extern void func_0038FDF8(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_00391598(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038FDF8(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_00391598 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003915C8);

/* PAL adaptation of the US draft of func_003915D0 (rac3-uya-decomp func_00391510,
   commit 13cf5c5): the callee the US version calls (func_0038FD40) is func_0038FDF8
   in the PAL retail program, which is what the retail jal here targets. */


/* localdecomp:start func_003915D0 */
extern void func_0038FDF8(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_003915D0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g, s32 h, f32 x) {
    func_0038FDF8(a, b, c, d, h, g, x, x);
}
/* localdecomp:end func_003915D0 */

/* localdecomp:start func_003915F0 */
extern void func_00390768();
void func_003915F0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s16 g, long h, s32 x, s32 y) {
    func_00390768(a, b, c, d, g, h, x, y);
}
/* localdecomp:end func_003915F0 */

/* localdecomp:start func_00391620 */
extern f32 func_00390FD8(s32, s32, s32, f32);
extern void func_0038EBC8_00391620(s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, unsigned long, f32);
void func_00391620(s32 x, s32 y, s32 a, s32 b, s32 c, s32 d, f32 p) {
    f32 r = func_00390FD8(b, c, d, p);
    func_0038EBC8_00391620(a, b, c, (f32)x, (f32)y, r, r, 0.0f, 1, 0, 0x80000000UL, 0.0f);
}
/* localdecomp:end func_00391620 */

/* localdecomp:start func_003916C8 */
extern void func_0038E2B0();
 
void func_003916C8(void) {
    func_0038E2B0();
}
/* localdecomp:end func_003916C8 */

/* localdecomp:start func_003916E8 */
extern f32 func_00390FD8();
 
void func_003916E8(void) {
    func_00390FD8();
}
/* localdecomp:end func_003916E8 */

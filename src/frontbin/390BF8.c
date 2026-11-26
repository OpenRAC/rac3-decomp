#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00390BF8 */
extern void func_0038E548_00390BF8();
f32 func_00390BF8(s32 a, s32 unused, s32 c, f32 f) {
    f32 r = 1.0f;
    s32 t;
    if (a) t = ((s32 (*)(f32))func_0038E548_00390BF8)(1.0f); else t = 0;
    if (c < t) {
        r = (f32)c / (f32)t;
        if (r < f) r = f;
    }
    return r;
}
/* localdecomp:end func_00390BF8 */

/* localdecomp:start func_00390C88 */
extern void func_0038E1E8(void);

void func_00390C88(void) {
    func_0038E1E8();
}
/* localdecomp:end func_00390C88 */

/* localdecomp:start func_00390CA8 */
extern void func_0038E3C0();

void func_00390CA8(void) {
    func_0038E3C0(1);
}
/* localdecomp:end func_00390CA8 */

/* localdecomp:start func_00390CC8 */
extern void func_0038E3C0();
 
void func_00390CC8(void) {
    func_0038E3C0(0);
}
/* localdecomp:end func_00390CC8 */

LINKER_REMNANT("asm/remnants", func_00390CE8);

/* localdecomp:start func_00390D20 */
extern void func_0038E548_00390D20();

void func_00390D20(void) {
    func_0038E548_00390D20();
}
/* localdecomp:end func_00390D20 */

LINKER_REMNANT("asm/remnants", func_00390D40);

/* localdecomp:start func_00390D48 */
extern void func_0038E548_00390D48();
 
void func_00390D48(void) {
    func_0038E548_00390D48();
}
/* localdecomp:end func_00390D48 */

LINKER_REMNANT("asm/remnants", func_00390D68);

/* localdecomp:start func_00390D70 */
extern void func_0038E548_00390D70();
 
void func_00390D70(s32 a, s32 b, s32 c, f32 d) {
    func_0038E548_00390D70();
}
/* localdecomp:end func_00390D70 */

LINKER_REMNANT("asm/remnants", func_00390D90);

/* localdecomp:start func_00390DB8 */
extern void func_0038E7E8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
extern void func_0038E548_00390DB8();
s32 func_00390DB8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    ((void (*)(float, float, float, float, float, float, s32, s32, s32, s32, s32, unsigned long))func_0038E7E8)((float)a0, (float)a1, 1.0f, 1.0f, 0.0f, 0.0f, a2, a3, a4, 1, 0, 0x80000000UL);
    return a0 - (((s32 (*)(s32, s32, float))func_0038E548_00390DB8)(a3, a4, 1.0f) >> 1);
}
/* localdecomp:end func_00390DB8 */

/* localdecomp:start func_00390E60 */
extern s32 D_001D55E8;
extern void func_0038E150(s32);
extern void func_0038E7E8_00390E60(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
extern s32 func_0038E548_00390E60(s32, s32, f32);
s32 func_00390E60(s32 x, s32 y, s32 a, s32 b, s32 c) {
    s32 saved;
    saved = D_001D55E8;
    func_0038E150(1);
    func_0038E7E8_00390E60(a, b, c, 1, 0, 0x80000000UL, (f32)x, (f32)y, 1.0f, 1.0f, 0.0f, 0.0f);
    x -= func_0038E548_00390E60(b, c, 1.0f) >> 1;
    func_0038E150(saved);
    return x;
}
/* localdecomp:end func_00390E60 */

LINKER_REMNANT("asm/remnants", func_00390F40);

/* localdecomp:start func_00390F50 */
extern void func_0038E7E8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
void func_00390F50(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, f32 p) {
    func_0038E7E8((f32)a0, (f32)a1, p, p, a2, a3, a4, 1, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_00390F50 */

/* localdecomp:start func_00390FB0 */
__asm__(".extern D_001D55E8, 4");
extern s32 D_001D55E8;
extern void func_0038E150(s32);
void func_00390FB0(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 save;
    save = D_001D55E8;
    func_0038E150(1);
    ((void (*)(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32))func_0038E7E8)(c, d, e, 0, 0, 0x80000000, (f32)a, (f32)b, 1.0f, 1.0f, 0.0f, 0.0f);
    func_0038E150(save);
}
/* localdecomp:end func_00390FB0 */

LINKER_REMNANT("asm/remnants", func_00391068);

/* localdecomp:start func_00391078 */
extern void func_0038E7E8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
void func_00391078(s32 a0, s32 a1, s32 a2, f32 x, f32 y, f32 z) {
    func_0038E7E8(x, y, z, z, a0, a1, a2, 0, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_00391078 */

LINKER_REMNANT("asm/remnants", func_003910B0);

/* localdecomp:start func_003910C0 */
void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    func_0038F9E0(p, a, b, c, d, e, f, g, h);
}
/* localdecomp:end func_003910C0 */

/* PAL candidate for func_003910E0 (US draft of func_0038C8A8).
   The called helper is PAL's func_0038FA18 (the US func_0038B1E8), which lives in
   this same source file (src/frontbin/38DED0.c). */


/* localdecomp:start func_003910E0 */
extern void func_0038FA18(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_003910E0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038FA18(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_003910E0 */

LINKER_REMNANT("asm/remnants", func_00391110);

/* Candidate for func_00391130 (frontbin, PAL).
   US draft of rac3-uya-decomp func_0038C8F8; the US callee func_0038B1E8 is
   func_0038FA18 in PAL (same file, still INCLUDE_ASM there), so the call
   target changes with the symbol. */

/* localdecomp:start func_00391130 */
extern s32 D_001D55E8;
extern void func_0038E150(s32);
extern void func_0038FA18(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_00391130(s32 a, s32 b, s32 c, s32 d) {
    s32 old = D_001D55E8;
    func_0038E150(1);
    ((void (*)(s32, s32, s32, s32, f32, f32, unsigned long))func_0038FA18)(a, b, c, d, 1.0f, 1.0f, 0x80000000UL);
    func_0038E150(old);
}
/* localdecomp:end func_00391130 */

/* PAL version of the US draft of func_003911B8 (rac3-uya-decomp func_0038C980).
   The US callee func_0038B1E8 is func_0038FA18 in PAL. */

/* localdecomp:start func_003911B8 */
extern void func_0038FA18(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_003911B8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038FA18(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_003911B8 */

LINKER_REMNANT("asm/remnants", func_003911E8);

/* US draft of func_003911F0 (rac3-uya-decomp func_0038C9B8, commit 13cf5c5), names moved to PAL addresses
   where known. The callee is the PAL func_0038FA18 (US func_0038B1E8). */


/* localdecomp:start func_003911F0 */
extern void func_0038FA18(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_003911F0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g, s32 h, f32 x) {
    func_0038FA18(a, b, c, d, h, g, x, x);
}
/* localdecomp:end func_003911F0 */

/* localdecomp:start func_00391210 */
extern void func_00390388();
void func_00391210(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s16 g, long h, s32 x, s32 y) {
    func_00390388(a, b, c, d, g, h, x, y);
}
/* localdecomp:end func_00391210 */

/* localdecomp:start func_00391240 */
extern f32 func_00390BF8(s32, s32, s32, f32);
extern void func_0038E7E8_00391240(s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, unsigned long, f32);
void func_00391240(s32 x, s32 y, s32 a, s32 b, s32 c, s32 d, f32 p) {
    f32 r = func_00390BF8(b, c, d, p);
    func_0038E7E8_00391240(a, b, c, (f32)x, (f32)y, r, r, 0.0f, 1, 0, 0x80000000UL, 0.0f);
}
/* localdecomp:end func_00391240 */

/* localdecomp:start func_003912E8 */
extern void func_0038DED0();
 
void func_003912E8(void) {
    func_0038DED0();
}
/* localdecomp:end func_003912E8 */

/* localdecomp:start func_00391308 */
extern f32 func_00390BF8();
 
void func_00391308(void) {
    func_00390BF8();
}
/* localdecomp:end func_00391308 */

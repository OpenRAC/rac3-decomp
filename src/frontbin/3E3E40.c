#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

typedef struct { u8 pad[0xAA]; s16 xAA; } M_3DE8F0;
typedef struct { f32 f0; s16 h4; } R_3DE8F0;
typedef struct {
    u8 pad0[0x19E0];
    M_3DE8F0 *x19E0;
    u8 pad19E4[0x25C4 - 0x19E4];
    s32 x25C4;
    u8 pad25C8[0x25E4 - 0x25C8];
    u8 x25E4;
    u8 pad25E5[0x2850 - 0x25E5];
    s32 x2850;
} W_3DE8F0;
typedef struct { u8 pad[0x20]; u8 x20; } F_3DE8F0;
extern s32 D_001D9550;
extern f32 D_001D9558;
extern W_3DE8F0 D_1A4BE0[];
extern F_3DE8F0 D_142CA0[];
extern s32 D_00142668[];
extern s32 D_001DA7E8[2];
extern char D_001D9560[];
extern R_3DE8F0 *func_00382348(M_3DE8F0 *);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038D098(f32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E7A18(s32, s32);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E7D70(s32, s32);
extern s32 func_003E7B80_003E3E40(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_11B2E8(void *, char *, s32);
/* localdecomp:start func_003E3E40 */
/* func_003E3E40: from boot_elf's twin func_003E41F8 (src/boot_elf/text/3E41F8.c), callees renamed
   through config/frontend_pairs.tsv; the twin's in-body externs moved to file scope. */
__asm__(".extern D_001D9550, 4");
__asm__(".extern D_001D9558, 4");
extern void func_003E5070(f32 *, f32);
extern s32 func_003E3E30_003E3E40(s32);
void func_003E3E40(void) {
    s32 current = D_1A4BE0[0].x2850;
    s32 maximum;
    s32 initial;
    s32 ones, tens, hundreds, showHundreds, digit, color;
    f32 bar0, bar1, x0, y, x1;
    f32 start, left, pulse, health, capacity, first, center, fade;
    if ((u8)(D_1A4BE0[0].x25E4 ^ 1) == 0) initial = 4;
    else initial = D_00142668[0];
    maximum = initial;
    if (D_1A4BE0[0].x25C4 == 0x31 && D_1A4BE0[0].x19E0 &&
        (D_1A4BE0[0].x19E0->xAA == 0x1A17 || D_1A4BE0[0].x19E0->xAA == 0x107E)) {
        R_3DE8F0 *r = func_00382348(D_1A4BE0[0].x19E0);
        if (r) {
            current = (s32)(r->f0 * 100.0f / r->h4);
            maximum = 100;
        }
    }
    health = current;
    capacity = maximum;
    if (D_142CA0[0].x20 == 0) {
        bar0 = health / capacity * 0.230333f;
        func_003E5070(&bar0, 0.230333f);
        func_003E81F0(0x9000A, 0.230333f - bar0, 0.05f);
        func_003E73B8(0x9000A, 0.615581036f, 0.0739995018f);
        func_003E81F0(0x9000B, bar0, 0.05f);
        func_003E73B8(0x9000B, 0.385248005f, 0.0739995018f);
        func_003E7A18(0x90008, 0);
    } else {
        bar1 = health / capacity * 0.226833001f;
        func_003E5070(&bar1, 0.226833001f);
        func_003E81F0(0x9000A, 0.226833001f - bar1, 0.05f);
        func_003E73B8(0x9000A, 0.587747991f, 0.0739995018f);
        func_003E81F0(0x9000B, bar1, 0.05f);
        func_003E73B8(0x9000B, 0.360915005f, 0.0739995018f);
        func_003E7A18(0x90008, 1);
        func_003E73B8(0x90008, 0.598917007f, 0.074000001f);
    }
    digit = current / 10;
    ones = func_003E3E30_003E3E40(current % 10);
    tens = func_003E3E30_003E3E40(digit % 10);
    digit = (current / 100) % 10;
    showHundreds = digit != 0;
    hundreds = func_003E3E30_003E3E40(digit);
    func_003E7E48(0x90003, ones);
    func_003E7E48(0x90004, tens);
    func_003E7E48(0x90005, hundreds);
    func_003E7838(0x90005, 1, showHundreds);
    start = 0.0900000036f;
    if (showHundreds) start = 0.135000005f;
    func_11B2E8(D_001DA7E8, D_001D9560, maximum);
    x0 = 0.0f;
    x1 = 0.0f;
    func_003E7B80_003E3E40(0x90006, &x0, &y, &x1, &y);
    first = x0;
    pulse = start + (x1 - first);
    center = 0.5f;
    if (D_142CA0[0].x20) center = 0.475f;
    left = center - pulse * 0.5f;
    if (showHundreds) {
        func_003E73B8(0x90005, left, 0.074000001f);
        left += 0.045f;
    }
    func_003E73B8(0x90004, left, 0.074000001f);
    left += 0.045f;
    func_003E73B8(0x90003, left, 0.074000001f);
    func_003E73B8(0x90006, left + 0.045f, 0.0689999983f);
    if (health < capacity * 0.15f) {
        D_001D9558 += 0.0600000024f;
        if (D_001D9558 >= 2.0f) D_001D9558 -= 2.0f;
        D_001D9550++;
    } else {
        if (D_001D9558 > 1.0f) D_001D9558 = 2.0f - D_001D9558;
        D_001D9558 *= 0.94f;
    }
    if (D_001D9558 > 1.0f) fade = 2.0f - D_001D9558;
    else fade = D_001D9558;
    color = func_0038DBD8(0x8066CCFF, 0x60202080, (1.0f - func_0038D098(fade * 3.14159274f)) * 0.5f);
    func_003E7D70(0x90003, color);
    func_003E7D70(0x90004, color);
    func_003E7D70(0x90005, color);
    func_003E7D70(0x90006, color);
}
/* localdecomp:end func_003E3E40 */

typedef struct { u8 pad[0x28B4]; s32 a; s32 b; } S_003DEEF0;
extern S_003DEEF0 D_001A4BE0;
extern s32 D_00142694[];
extern void func_00381D30();
extern s32 func_003E81F0(s32, f32, f32);
/* localdecomp:start func_003E4440 */
s32 func_003E4440(void) {
    s32 l[3];
    s32 pos;
    f32 den;
    f32 num;
    f32 t;
    pos = D_00142694[0] >> 5;
    l[0] = D_001A4BE0.b;
    l[1] = D_001A4BE0.a;
    if (l[0] == 0) {
        l[2] = 0;
        func_00381D30(l, l + 1, l + 2);
    }
    num = (f32)(pos - l[0]);
    den = (f32)(l[1] - l[0]);
    t = (den <= 0.0f) ? 0.0f : num / den;
    return func_003E81F0(0x90007, t * 0.1285f, 0.009f);
}
/* localdecomp:end func_003E4440 */

extern u8 D_00142CC0[];
extern u8 D_001426E0[];
extern s32 func_003E81F0(s32, f32, f32);
/* localdecomp:start func_003E4508 */
extern u8 D_00142CC0_003E4508[];
extern u8 D_001426E0_003E4508[];
extern s32 func_003E81F0_003E4508(s32, f32, f32);
void func_003E4508(void) {
    if (D_00142CC0_003E4508[0]) {
        u8 *s = D_001426E0_003E4508;
        f32 r = 0.0f;
        if (s[0xD4]) r = (f32)s[0xD3] / (f32)s[0xD4];
        func_003E81F0_003E4508(0x90008, r * 0.0430830009f, 0.0504160002f);
    }
}
/* localdecomp:end func_003E4508 */

typedef struct { s32 x0, x4, x8, xC; } S_3DF038;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3DF038;
typedef struct { u8 pad[8]; VT_3DF038 *vt; u8 padC[0x3E]; s16 x4A; } W_3DF038;
extern u8 D_001D9554;
extern u8 D_001D955D;
extern u8 D_001D955C;
extern s32 D_001D9760;
extern s32 D_001DA7E8[2];
extern S_3DF038 D_001DA938[];
extern void func_003E73B0_003E4588(s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_003B5060(s32);
extern s32 func_00381FF0(s32);
extern s32 func_00392A18(void);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_003E7928(s32, s32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E7FF8(s32, s32, s32, s32, s32);
extern s32 func_003E8100(s32, s32, s32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E7590(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E7D70(s32, s32);
extern s32 func_003E7C90_003E4588(s32, void *);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern void func_003E6FF0_003E4588(s32, s32);
extern void func_003E3E40(void);
extern S_3DF038 *func_003E6C08_003E4588(S_3DF038 *);
extern s32 func_003E6DE8_003E4588(S_3DF038 *);
extern W_3DF038 *func_003E6378(s32, s32);
/* localdecomp:start func_003E4588 */
/* func_003E4588 (from rac3-uya-decomp func_003E47F8, commit 13cf5c5), names moved to PAL
   addresses where known. Matches the PAL retail bytes with this file's own compiler flags.
   PAL differs from the US draft in three float constants: 0.13f (was 0.1335f), 0.009f
   (was 0.008f), and 0.05f (was 0.049333f, in both func_003E9138_003E4588 calls, where it is shared). */


__asm__(".extern D_001D9554_003E4588, 1");
__asm__(".extern D_001D955D_003E4588, 1");
__asm__(".extern D_001D955C_003E4588, 1");
__asm__(".extern D_001D9760_003E4588, 4");
typedef struct { s32 x0, x4, x8, xC; } S_3DF038_003E4588;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3DF038_003E4588;
typedef struct { u8 pad[8]; VT_3DF038_003E4588 *vt; u8 padC[0x3E]; s16 x4A; } W_3DF038_003E4588;

extern u8 D_001D9554_003E4588;
extern u8 D_001D955D_003E4588;
extern u8 D_001D955C_003E4588;
extern s32 D_001D9760_003E4588;
extern s32 D_001DA7E8_003E4588[2];
extern S_3DF038_003E4588 D_001DA938_003E4588[];

extern void func_003E73B0_003E4588_003E4588(s32);
extern void func_0038CB78_003E4588(void *, s32, s32);
extern void func_003B5060_003E4588(s32);
extern s32 func_003E5090(s32);
extern s32 func_003E51F8(s32);
extern s32 func_003E5360(s32);
extern s32 func_00381FF0_003E4588(s32);
extern s32 func_00392A18_003E4588(void);
extern s32 func_003E8FE8_003E4588(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9138_003E4588(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7AC8_003E4588(s32, s32);
extern s32 func_003E7928_003E4588(s32, s32, s32);
extern s32 func_003E7838_003E4588(s32, s32, s32);
extern s32 func_003E7FF8_003E4588(s32, s32, s32, s32, s32);
extern s32 func_003E8100_003E4588(s32, s32, s32);
extern s32 func_003E73B8_003E4588(s32, f32, f32);
extern s32 func_003E7590_003E4588(s32, f32, f32);
extern s32 func_003E81F0_003E4588(s32, f32, f32);
extern s32 func_003E7F20_003E4588(s32, s32);
extern s32 func_003E7D70_003E4588(s32, s32);
extern s32 func_003E7C90_003E4588_003E4588(s32, void *);
extern s32 func_003E7E48_003E4588(s32, s32);
extern s32 func_003E8630_003E4588(s32, s32);
extern s32 func_003E8348_003E4588(s32, s32);
extern void func_003E6FF0_003E4588_003E4588(s32, s32);
extern void func_003E3E40_003E4588(void);
extern S_3DF038_003E4588 *func_003E6C08_003E4588_003E4588(S_3DF038_003E4588 *);
extern s32 func_003E6DE8_003E4588_003E4588(S_3DF038_003E4588 *);
extern W_3DF038_003E4588 *func_003E6378_003E4588(s32, s32);

void func_003E4588(s32 arg0) {
    S_3DF038_003E4588 *p;
    S_3DF038_003E4588 *q;
    W_3DF038_003E4588 *t;
    W_3DF038_003E4588 *v;

    D_001D9554_003E4588 = 1;
    func_003E73B0_003E4588_003E4588(1);
    func_0038CB78_003E4588(D_001DA7E8_003E4588, 0, 8);
    func_003B5060_003E4588(0x90000);
    func_003E5090(0x90001);
    func_003E5090(0x90002);
    func_003E51F8(0x90003);
    func_003E51F8(0x90004);
    func_003E51F8(0x90005);
    func_003E5360(0x90006);
    func_003E51F8(0x90007);
    func_003E8FE8_003E4588(0x9000C, func_00381FF0_003E4588(0x182D), 0x8066CCFF, 0.4285f, 0.1315f, 0.6f, 0.6f);
    func_003E7AC8_003E4588(0x9000C, 1);
    func_003E9138_003E4588(0x90008, 0x706EC8FF, 0, 0.598917f, 0.074f, 0.043083f, 0.050416f);
    func_003E7928_003E4588(0x90008, 1, 3);
    func_003E7FF8_003E4588(0x90008, 0x601465B7, 0x6066CCFF, 0x601465B7, 0x6066CCFF);
    func_003E8100_003E4588(0x90002, func_00392A18_003E4588(), 0x8C);
    func_003E8100_003E4588(0x90001, func_00392A18_003E4588(), 0x8D);
    func_003E73B8_003E4588(0x90003, 0.487997f, 0.074f);
    func_003E73B8_003E4588(0x90004, 0.440497f, 0.074f);
    func_003E73B8_003E4588(0x90005, 0.39347f, 0.074f);
    func_003E73B8_003E4588(0x90006, 0.627999f, 0.069f);
    func_003E7590_003E4588(0x90006, 0.003f, 0.003f);
    func_003E7F20_003E4588(0x90006, 1);
    func_003E73B8_003E4588(0x90007, 0.464136f, 0.13f);
    func_003E81F0_003E4588(0x90003, 0.035f, 0.035f);
    func_003E81F0_003E4588(0x90004, 0.035f, 0.035f);
    func_003E81F0_003E4588(0x90005, 0.035f, 0.035f);
    func_003E81F0_003E4588(0x90006, 1.0f, 1.0f);
    func_003E81F0_003E4588(0x90007, 0.0f, 0.009f);
    func_003E7D70_003E4588(0x90001, 0x331465B7);
    func_003E7D70_003E4588(0x90002, 0x332299DE);
    func_003E7D70_003E4588(0x90003, 0x8066CCFF);
    func_003E7D70_003E4588(0x90004, 0x8066CCFF);
    func_003E7D70_003E4588(0x90005, 0x8066CCFF);
    func_003E7D70_003E4588(0x90006, 0x8066CCFF);
    func_003E7D70_003E4588(0x90007, 0x706EC8FF);
    func_003E7C90_003E4588_003E4588(0x90006, D_001DA7E8_003E4588);
    func_003E7928_003E4588(0x90006, 1, 1);
    func_003E7928_003E4588(0x90007, 1, 3);
    func_003E7838_003E4588(0x90006, 0x40, 1);
    func_003E7838_003E4588(0x90003, 0x40, 1);
    func_003E7838_003E4588(0x90004, 0x40, 1);
    func_003E7838_003E4588(0x90005, 0x40, 1);
    func_003E7928_003E4588(0x90003, 1, 3);
    func_003E7928_003E4588(0x90004, 1, 3);
    func_003E7928_003E4588(0x90005, 1, 3);

    func_003E7E48_003E4588(0x90003, 0xED1C);
    p = D_001DA938_003E4588;
    if (p->x4) q = p; else q = func_003E6C08_003E4588_003E4588(p);
    t = func_003E6378_003E4588(func_003E6DE8_003E4588_003E4588(q), 0x90003);
    v = (t != 0 && t->vt->isA(t, D_001D9760_003E4588) != 0) ? t : 0;
    v->x4A = 0;

    func_003E7E48_003E4588(0x90004, 0xED1D);
    p = D_001DA938_003E4588;
    if (p->x4) q = p; else q = func_003E6C08_003E4588_003E4588(p);
    t = func_003E6378_003E4588(func_003E6DE8_003E4588_003E4588(q), 0x90004);
    v = (t != 0 && t->vt->isA(t, D_001D9760_003E4588) != 0) ? t : 0;
    v->x4A = 0;

    func_003E7E48_003E4588(0x90005, 0xED1E);
    p = D_001DA938_003E4588;
    if (p->x4) q = p; else q = func_003E6C08_003E4588_003E4588(p);
    t = func_003E6378_003E4588(func_003E6DE8_003E4588_003E4588(q), 0x90005);
    v = (t != 0 && t->vt->isA(t, D_001D9760_003E4588) != 0) ? t : 0;
    v->x4A = 0;

    func_003E9138_003E4588(0x9000A, 0x59000000, 0, 0.61558104f, 0.0739995f, 0.230333f, 0.05f);
    func_003E7928_003E4588(0x9000A, 2, 3);
    func_003E9138_003E4588(0x9000B, 0x59000000, 0, 0.385248f, 0.0739995f, 0.230333f, 0.05f);
    func_003E7928_003E4588(0x9000B, 1, 3);
    func_003E7FF8_003E4588(0x9000B, 0x601465B7, 0x6066CCFF, 0x601465B7, 0x6066CCFF);
    func_003E8630_003E4588(0x90000, 0x90001);
    func_003E8630_003E4588(0x90000, 0x90002);
    func_003E8630_003E4588(0x90000, 0x9000A);
    func_003E8630_003E4588(0x90000, 0x9000B);
    func_003E8630_003E4588(0x90000, 0x90006);
    func_003E8630_003E4588(0x90000, 0x90007);
    func_003E8630_003E4588(0x90000, 0x90008);
    func_003E8630_003E4588(0x90000, 0x90003);
    func_003E8630_003E4588(0x90000, 0x90004);
    func_003E8630_003E4588(0x90000, 0x90005);
    func_003E8630_003E4588(0x90000, 0x9000C);
    func_003E8348_003E4588(7, 0x90000);
    func_003E6FF0_003E4588_003E4588(arg0, 1);
    func_003E3E40_003E4588();
    func_003E73B0_003E4588_003E4588(0);
    D_001D955D_003E4588 = 0;
    D_001D955C_003E4588 = 1;
}
/* localdecomp:end func_003E4588 */

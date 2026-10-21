#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00392640(s32, long, long);
extern void func_00392670(void);
extern void func_0038E530(s32);
extern void func_003914A0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void (*D_001D9A40[2])(s32);
extern void func_0038E518(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 38E1F8.c's earlier functions (tools/port_from_us.py) */
typedef struct { s16 x; s16 y; } P_3896E8;
typedef struct {
    u8 n0; u8 n1; u8 p2[0x2E];
    u8 k30[0x10];
    u8 k40[0x10];
    P_3896E8 pt[0x10];
    s32 o90[0x10];
    s32 oD0[0x10];
} T_3896E8;
extern T_3896E8 *D_001D55D0_0038E2B0[2];
extern s32 D_001D9BC8_0038E2B0;
extern s32 D_001D5B34;
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D5B30;
extern s32 D_001D55E8;
extern s32 D_0031CFD0_0038E2B0[][16];
extern s32 D_0031CF50_0038E2B0[][16];
extern s32 func_0038A028(s32 a, s32 b);
extern s32 func_00389EF0(s32, s32, s32, s32);

/* localdecomp:start func_0038E488 */
s32 func_0038E488(u8 *p, s32 off, s32 *out) {
    u8 *q = p + off;
    s32 r = 0;
    s32 b = q[0];
    *out = b;
    if (b & 0x80) {
        r = 1;
        *out = (((b & 0x7F) << 8) | q[1]) + 0x7F;
    }
    return r;
}
/* localdecomp:end func_0038E488 */

extern u8 D_00144440[];
extern u8 D_00143E40[];
extern u8 D_0014A840[];
extern u8 D_0014A240[];
extern void func_0038E1F8(s32, void *, void *);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038E4C8);

extern s32 D_001D9BC8[];

/* localdecomp:start func_0038E518 */
extern s32 D_001D9BC8[];
extern s32 D_001D5B34;
void func_0038E518(void) { D_001D5B34 = D_001D9BC8[0] - 1; }
/* localdecomp:end func_0038E518 */

extern s32 D_001D55D0[];
extern s32 D_001D55D8[];
extern s32 D_001D55E0[];
extern s32 D_001D55C0;
extern s32 D_001D55C4_0038E530;
extern s32 D_001D55C8;
extern u8 D_0031CF50[];
extern u8 D_0031CFD0[];
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D55E8;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038E530);

/* localdecomp:start func_0038E5A8 */
extern s32 *D_001D55C4[];
s32 func_0038E5A8(void) {
    s32 *p = D_001D55C4[0];
    s32 r = -1;
    if (p) r = p[-1];
    return r;
}
/* localdecomp:end func_0038E5A8 */

typedef struct { u32 w0; u32 w4; } E_3899B8;
extern E_3899B8 *D_001D55C4_0038E5C8;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038E5C8);

/* localdecomp:start func_0038E7A0 */
extern u8 D_001D5B42;
void func_0038E7A0(s32 a) { D_001D5B42 = a; }
/* localdecomp:end func_0038E7A0 */

typedef struct { u32 w0; u32 w4; } E_389B98;
/* localdecomp:start func_0038E7A8 */
s32 func_0038E7A8(u8 *str, s32 len, f32 scale) {
    s32 i = 0;
    s32 ok = 1;
    f32 max = 0.0f;
    s32 idx = 0;
    for (; ok && i != len; i++) {
        if (str[i] == 0) {
            ok = 0;
        } else {
            f32 w, h, v;
            i += func_0038E488(str, i, &idx);
            w = (f32)((((E_389B98 *)D_001D55C4[0])[idx].w4 >> 17) & 0x3F) * scale;
            h = (f32)((((E_389B98 *)D_001D55C4[0])[idx].w4 >> 9) & 0xFF) * scale;
            v = w + h * 0.25f;
            if (max < v) max = v;
        }
    }
    return (s32)max;
}
/* localdecomp:end func_0038E7A8 */

extern s32 D_001D55C8;
extern s32 *D_001D55C4[];
typedef struct { u32 w0; u32 w4; } E_389D18;
typedef struct { s16 ch; s8 adj; u8 end; } K_389D18;
/* localdecomp:start func_0038E928 */
__asm__(".extern D_001D55C8, 16");
extern s32 func_0038E488(u8 *p, s32 off, s32 *out);
s32 func_0038E928(u8 *str, s32 len, f32 scale) {
    s32 idx[2];
    f32 q = scale * 0.25f;
    s32 i;
    s32 ok;
    f32 kern;
    f32 x;
    f32 first;
    idx[0] = 0;
    idx[1] = 0;
    func_0038E488(str, 0, &idx[0]);
    kern = 0.0f;
    first = (f32)(-(s32)(((E_389D18 *)D_001D55C4[0])[idx[0]].w0 >> 25)) * q;
    x = 0.0f;
    ok = 1;
    i = 0;
    for (; ok && i != len; i++) {
        if (str[i] == 0) {
            ok = 0;
        } else {
            E_389D18 *e;
            f32 w, b, c, adv;
            i += func_0038E488(str, i, &idx[0]);
            e = &((E_389D18 *)D_001D55C4[0])[idx[0]];
            w = (f32)((e->w4 >> 23) & 0x3F) * scale;
            b = (f32)(s32)(((e->w0 >> 25) + 2) & 0xFC) * q;
            c = (f32)(((e->w4 >> 29) + 2) & 0xFC);
            x += w - b;
            adv = (kern + c) * q;
            if (i != len - 1) {
                s32 nx;
                func_0038E488(str, i + 1, &idx[1]);
                nx = idx[1];
                if (nx >= 0x10) {
                    f32 t;
                    if (e->w0 & 0xFFF0) {
                        K_389D18 *k = (K_389D18 *)((u8 *)D_001D55C8 + ((e->w0 >> 2) & 0x3FFC));
                        s32 r;
                        t = x + adv;
                        if (k != 0) {
                            s32 j;
                            for (j = 0; k[j].end == 0; j++) {
                                if (k[j].ch == nx) { r = k[j].adj; goto done; }
                            }
                        }
                        r = 0;
                    done:
                        kern = (f32)r;
                        kern = kern * q;
                    } else {
                        t = x + adv;
                        kern = 0.0f;
                    }
                    x = t;
                }
            }
        }
    }
    return (s32)(x - first);
}
/* localdecomp:end func_0038E928 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038EBC8);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C070);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038F458);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C0A0);

/* localdecomp:start func_0038FDC0 */
void func_0038FDC0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    p[4] = e;
    p[5] = f;
    p[8] = g;
    p[9] = h;
    p[6] = 0;
    p[7] = 0;
    p[10] = 0;
    p[11] = 0;
}
/* localdecomp:end func_0038FDC0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038FDF8);

typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 fl; s16 h14, h16, h18, h1A; } O_0038B1E8;
typedef struct { s16 key; s8 val; u8 end; } K_0038B1E8;
extern s32 D_001D5B94;
extern u8 D_001D5B41, D_001D5B42, D_001D5B40;
extern s32 D_001D5B68;
extern s32 D_001D5B48[2];
extern s32 D_001D9C80;
extern u16 D_001D9C88[4], D_001D9CA0[4], D_001D9CB8[4], D_001D9CD0[4];
extern s32 D_001D55C4_0038FD40;
extern s32 D_001D55C8_0038FD40;
extern s32 D_001D4BC0_0038FD40, D_001D4BC4_0038FD40;
extern void func_003A98B8(s32, s32, s32, s32);
extern s32 func_0038E928_0038FD40(u8 *, s32, f32);
extern void func_0038EBC8_0038FD40(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 h12; s16 h14, h16; } B_38BB50;
typedef struct { u32 w0, w1; } G_38BB50;
extern s32 D_001D5B94;
extern u8 D_001D5B41;
extern s32 D_001D5B48[2];
extern s32 D_001D5B5C[];
extern s32 D_001D4BC0[];
extern s32 D_001D4BC4[];
extern void func_003A98B8(s32, s32, s32, s32);
extern s32 func_0038E928_00390768(u8 *, s32, f32);
extern void func_0038EBC8_00390768(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00390768);

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

extern s32 D_00143950[];
extern s32 D_001D5520;
extern void func_12A950(void);
extern void func_12BEE8(s32, s32, s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00391708);

/* localdecomp:start func_00391778 */
extern s32 D_001D4D08[];
extern s32 D_001D4D0C[];
extern s32 D_001D4D10[];
extern s32 D_001D4D14[];
extern s32 D_001D4D18[];
extern s32 D_001D4D1C[];
extern s32 D_001D4CF8[];
void func_00391778(void) {
    *(unsigned long *)((u8 *)D_001D4CF8[0] + 0x18) = (long)D_001D4D08[0] | ((long)D_001D4D0C[0] << 12) | ((long)D_001D4D10[0] << 23) | ((long)D_001D4D14[0] << 27) | ((long)D_001D4D18[0] << 32) | ((long)D_001D4D1C[0] << 44);
}
/* localdecomp:end func_00391778 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003917E0);

extern s32 D_001D4D08_003917E8;
extern s32 D_001D4D0C_003917E8;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003917E8);

LINKER_REMNANT("asm/boot_elf/remnants", func_00391870);

typedef struct {
    u8 p0[0x150];
    s16 h150, h152, h154, h156, h158, h15A;
} E_38CC68;
extern unsigned long D_001D0560[];
extern E_38CC68 *D_001D4CF8_00391880;
extern u8 D_001439FD[];
extern s32 D_001D5520;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00391880);

typedef int Q_38CE40 __attribute__((mode(TI)));
typedef struct { unsigned long v : 9; unsigned long r : 55; } FB_38CE40;
typedef struct {
    unsigned long dx : 12;
    unsigned long dy : 11;
    unsigned long magh : 4;
    unsigned long magv : 2;
    unsigned long p0 : 3;
    unsigned long dw : 12;
    unsigned long dh : 11;
    unsigned long p1 : 9;
} DI_38CE40;
typedef struct {
    unsigned long nloop : 15;
    unsigned long eop : 1;
    unsigned long p0 : 16;
    unsigned long id : 14;
    unsigned long pre : 1;
    unsigned long prim : 11;
    unsigned long flg : 2;
    unsigned long nreg : 4;
    unsigned long regs0 : 4;
    unsigned long regs : 60;
} GT_38CE40;
typedef struct {
    u8 p0[0x10];
    FB_38CE40 q10;
    DI_38CE40 q18;
    u8 p20[0x10];
    GT_38CE40 t30;
    FB_38CE40 q40;
    unsigned long q48;
    unsigned long q50;
    u8 p58[0x68];
    GT_38CE40 tC0;
    FB_38CE40 qD0;
    unsigned long qD8;
    unsigned long qE0;
    u8 pE8[0x68];
    s16 h150, h152, h154, h156, h158, h15A, h15C, h15E;
    s16 h160, h162, h164, h166, h168, h16A, h16C, h16E;
    s32 w170;
} E_38CE40;
extern E_38CE40 D_001CFEC0_00391A58[];
extern E_38CE40 *D_001D4CF8_00391A58;
extern s32 D_001A1ED0_00391A58[];
extern s32 D_001D5520;
extern u8 D_001D551D;
extern s32 D_001D4D08_00391A58;
extern s32 D_001D4D0C_00391A58;
extern s32 D_001D4D10_00391A58;
extern s32 D_001D4D14_00391A58;
extern s32 D_001D4D18_00391A58;
extern s32 D_001D4D1C_00391A58;
extern s32 D_001D4D20_00391A58;
extern s32 D_001D4D24_00391A58;
extern s32 D_001D4D28_00391A58;
extern s32 D_001D4D2C_00391A58;
extern s32 D_001D4D30_00391A58;
extern s32 D_001D4D34_00391A58;
extern unsigned long D_001D02D0_00391A58[];
extern unsigned long D_001D0070_00391A58[];
extern unsigned long D_001D07B0_00391A58[];
extern unsigned long D_001D0900_00391A58[];
extern unsigned long D_00141850_00391A58[];
extern unsigned long D_00141990_00391A58[];
extern unsigned long D_00141AD0_00391A58[];
extern unsigned long D_00141DC0_00391A58[];
extern unsigned long D_001420B0_00391A58[];
extern void func_0012C138(void *, s32, s16, s16, s16, s16);
extern void func_0012C638(s32, s32, s32, s32, s32, s32);
extern void func_00391880(s32, s32);
extern void func_0038D068();
extern void func_11F0A0(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00391A58);

extern unsigned long D_001D07E8[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00392640);

LINKER_REMNANT("asm/boot_elf/remnants", func_00392668);

/* localdecomp:start func_00392670 */
extern void func_12C4B0(s32);
extern s32 D_001D4CF8[];

void func_00392670(void) {
    func_12C4B0(D_001D4CF8[0]);
}
/* localdecomp:end func_00392670 */

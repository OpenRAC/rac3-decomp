#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_0011A264(s32, s32, s32);
extern void func_00392260(s32, long, long);
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_00392290(void);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern s32 func_00392B20();
extern s32 func_00392C78();
extern void func_0038E150(s32);
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_00397CC0();
extern void (*D_001D9A40[2])(s32);
extern void func_00392440(s32, s32, s32, s32);
extern void func_00392868(s32, s32);
extern void func_003926E8(void);
extern void func_00396838(void);
extern void func_0038E138(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

typedef struct { s16 x; s16 y; } P_3896E8;
typedef struct {
    u8 n0; u8 n1; u8 p2[0x2E];
    u8 k30[0x10];
    u8 k40[0x10];
    P_3896E8 pt[0x10];
    s32 o90[0x10];
    s32 oD0[0x10];
} T_3896E8;
extern T_3896E8 *D_001D55D0_0038DED0[2];
extern s32 D_001D9BC8_0038DED0;
extern s32 D_001D5B34;
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D5B30;
extern s32 D_001D55E8;
extern s32 D_0031CFD0_0038DED0[][16];
extern s32 D_0031CF50_0038DED0[][16];
extern s32 func_00389C48(s32 a, s32 b);
extern s32 func_00389B10(s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038DED0);

/* localdecomp:start func_0038E0A8 */
s32 func_0038E0A8(u8 *p, s32 off, s32 *out) {
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
/* localdecomp:end func_0038E0A8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038E0E8);

LINKER_REMNANT("asm/remnants", func_0038E130);

extern s32 D_001D9BC8[];
/* localdecomp:start func_0038E138 */
extern s32 D_001D9BC8[];
extern s32 D_001D5B34;
void func_0038E138(void) { D_001D5B34 = D_001D9BC8[0] - 1; }
/* localdecomp:end func_0038E138 */

extern s32 D_001D55D0[];
extern s32 D_001D55D8[];
extern s32 D_001D55E0[];
extern s32 D_001D55C0;
extern s32 D_001D55C4_0038E150;
extern s32 D_001D55C8;
extern u8 D_0031CF50[];
extern u8 D_0031CFD0[];
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D55E8;
INCLUDE_ASM("asm/nonmatchings/text", func_0038E150);

/* localdecomp:start func_0038E1C8 */
extern s32 *D_001D55C4[];
s32 func_0038E1C8(void) {
    s32 *p = D_001D55C4[0];
    s32 r = -1;
    if (p) r = p[-1];
    return r;
}
/* localdecomp:end func_0038E1C8 */

typedef struct { u32 w0; u32 w4; } E_3899B8;
extern E_3899B8 *D_001D55C4_0038E1E8;
INCLUDE_ASM("asm/nonmatchings/text", func_0038E1E8);

/* localdecomp:start func_0038E3C0 */
extern u8 D_001D5B42;
void func_0038E3C0(s32 a) { D_001D5B42 = a; }
/* localdecomp:end func_0038E3C0 */

typedef struct { u32 w0; u32 w4; } E_389B98;
/* localdecomp:start func_0038E3C8 */
s32 func_0038E3C8(u8 *str, s32 len, f32 scale) {
    s32 i = 0;
    s32 ok = 1;
    f32 max = 0.0f;
    s32 idx = 0;
    for (; ok && i != len; i++) {
        if (str[i] == 0) {
            ok = 0;
        } else {
            f32 w, h, v;
            i += func_0038E0A8(str, i, &idx);
            w = (f32)((((E_389B98 *)D_001D55C4[0])[idx].w4 >> 17) & 0x3F) * scale;
            h = (f32)((((E_389B98 *)D_001D55C4[0])[idx].w4 >> 9) & 0xFF) * scale;
            v = w + h * 0.25f;
            if (max < v) max = v;
        }
    }
    return (s32)max;
}
/* localdecomp:end func_0038E3C8 */

/* Candidate for func_0038E548 (frontbin, PAL).
   Base: the US draft (rac3-uya-decomp func_00389D18).
   PAL differences so far:
     - the kernel table base is read through D_001D55C4[1] (the same word as
       D_001D55C8, but an array element, so the compiler addresses it with
       lui/lw like retail instead of a $gp-relative load),
     - the inner "k" search loop is restructured. */

/* localdecomp:start func_0038E548 */
typedef struct { u32 w0; u32 w4; } E_389D18;
typedef struct { s16 ch; s8 adj; u8 end; } K_389D18;
s32 func_0038E548(u8 *str, s32 len, f32 scale) {
    s32 idx[2];
    f32 q = scale * 0.25f;
    s32 i;
    s32 ok;
    f32 kern;
    f32 x;
    f32 first;
    idx[0] = 0;
    idx[1] = 0;
    func_0038E0A8(str, 0, &idx[0]);
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
            i += func_0038E0A8(str, i, &idx[0]);
            e = &((E_389D18 *)D_001D55C4[0])[idx[0]];
            w = (f32)((e->w4 >> 23) & 0x3F) * scale;
            b = (f32)(s32)(((e->w0 >> 25) + 2) & 0xFC) * q;
            c = (f32)(((e->w4 >> 29) + 2) & 0xFC);
            x += w - b;
            adv = (kern + c) * q;
            if (i != len - 1) {
                s32 nx;
                func_0038E0A8(str, i + 1, &idx[1]);
                nx = idx[1];
                if (nx >= 0x10) {
                    f32 t;
                    if (e->w0 & 0xFFF0) {
                        K_389D18 *k = (K_389D18 *)((u8 *)D_001D55C4[1] + ((e->w0 >> 2) & 0x3FFC));
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
/* localdecomp:end func_0038E548 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038E7E8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C040);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F078);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C070);

/* localdecomp:start func_0038F9E0 */
void func_0038F9E0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
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
/* localdecomp:end func_0038F9E0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038FA18);

typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 fl; s16 h14, h16, h18, h1A; } O_0038B1E8;
typedef struct { s16 key; s8 val; u8 end; } K_0038B1E8;
extern s32 D_001D5B94;
extern u8 D_001D5B41, D_001D5B42, D_001D5B40;
extern s32 D_001D5B68;
extern s32 D_001D5B48[2];
extern s32 D_001D9C80;
extern u16 D_001D9C88[4], D_001D9CA0[4], D_001D9CB8[4], D_001D9CD0[4];
extern s32 D_001D55C4_0038B1E8;
extern s32 D_001D55C8_0038B1E8;
extern s32 D_001D4BC0_0038B1E8, D_001D4BC4_0038B1E8;
extern void func_003A9500(s32, s32, s32, s32);
extern s32 func_0038E548_0038B1E8(u8 *, s32, f32);
extern void func_0038E7E8_0038B1E8(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 h12; s16 h14, h16; } B_38BB50;
typedef struct { u32 w0, w1; } G_38BB50;
extern s32 D_001D5B94;
extern u8 D_001D5B41;
extern s32 D_001D5B48[2];
extern s32 D_001D5B5C[];
extern s32 D_001D4BC0[];
extern s32 D_001D4BC4[];
extern void func_003A9500(s32, s32, s32, s32);
extern s32 func_0038E548_00390388(u8 *, s32, f32);
extern void func_0038E7E8_00390388(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_00390388);

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

extern s32 D_00143950[];
extern s32 D_001D5520;
extern void func_12A950(void);
extern void func_12BEE8(s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00391328);

/* localdecomp:start func_00391398 */
extern s32 D_001D4D08[];
extern s32 D_001D4D0C[];
extern s32 D_001D4D10[];
extern s32 D_001D4D14[];
extern s32 D_001D4D18[];
extern s32 D_001D4D1C[];
extern s32 D_001D4CF8[];
void func_00391398(void) {
    *(unsigned long *)((u8 *)D_001D4CF8[0] + 0x18) = (long)D_001D4D08[0] | ((long)D_001D4D0C[0] << 12) | ((long)D_001D4D10[0] << 23) | ((long)D_001D4D14[0] << 27) | ((long)D_001D4D18[0] << 32) | ((long)D_001D4D1C[0] << 44);
}
/* localdecomp:end func_00391398 */

LINKER_REMNANT("asm/remnants", func_00391400);

extern s32 D_001D4D08_00391408;
extern s32 D_001D4D0C_00391408;
INCLUDE_ASM("asm/nonmatchings/text", func_00391408);

LINKER_REMNANT("asm/remnants", func_00391490);

typedef struct {
    u8 p0[0x150];
    s16 h150, h152, h154, h156, h158, h15A;
} E_38CC68;
extern unsigned long D_001D0560[];
extern E_38CC68 *D_001D4CF8_003914A0;
extern u8 D_001439FD[];
extern s32 D_001D5520;
INCLUDE_ASM("asm/nonmatchings/text", func_003914A0);

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
extern E_38CE40 D_001CFEC0_00391678[];
extern E_38CE40 *D_001D4CF8_00391678;
extern s32 D_001A1ED0_00391678[];
extern s32 D_001D5520;
extern u8 D_001D551D;
extern s32 D_001D4D08_00391678;
extern s32 D_001D4D0C_00391678;
extern s32 D_001D4D10_00391678;
extern s32 D_001D4D14_00391678;
extern s32 D_001D4D18_00391678;
extern s32 D_001D4D1C_00391678;
extern s32 D_001D4D20_00391678;
extern s32 D_001D4D24_00391678;
extern s32 D_001D4D28_00391678;
extern s32 D_001D4D2C_00391678;
extern s32 D_001D4D30_00391678;
extern s32 D_001D4D34_00391678;
extern unsigned long D_001D02D0_00391678[];
extern unsigned long D_001D0070_00391678[];
extern unsigned long D_001D07B0_00391678[];
extern unsigned long D_001D0900_00391678[];
extern unsigned long D_00141850_00391678[];
extern unsigned long D_00141990_00391678[];
extern unsigned long D_00141AD0_00391678[];
extern unsigned long D_00141DC0_00391678[];
extern unsigned long D_001420B0_00391678[];
extern void func_0012C138(void *, s32, s16, s16, s16, s16);
extern void func_0012C638(s32, s32, s32, s32, s32, s32);
extern void func_003914A0(s32, s32);
extern void func_0038CC88();
extern void func_11F0A0(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00391678);

extern unsigned long D_001D07E8[];
INCLUDE_ASM("asm/nonmatchings/text", func_00392260);

LINKER_REMNANT("asm/remnants", func_00392288);

/* localdecomp:start func_00392290 */
extern void func_12C4B0(s32);
extern s32 D_001D4CF8[];

void func_00392290(void) {
    func_12C4B0(D_001D4CF8[0]);
}
/* localdecomp:end func_00392290 */

extern u32 *D_001DA050;
extern s32 D_001D4CF8_003922B8;
extern void func_12C820(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003922B8);

extern u32 *D_001DA050;
extern u8 D_1D07B0[], D_1D0900[];
INCLUDE_ASM("asm/nonmatchings/text", func_00392350);

extern u32 *D_001DA050;
extern s32 D_001D4CF8_003923D0;
INCLUDE_ASM("asm/nonmatchings/text", func_003923D0);

typedef struct { unsigned long lo : 9; unsigned long hi : 55; } BF_38DC08;
typedef struct { u8 p0[0x160]; s16 h160; s16 h162; s16 h164; s16 h166; u8 p168[4]; u16 h16C; s16 h16E; } S_38DC08;
extern S_38DC08 D_001CFEC0_00392440[];
extern s32 D_001DA050_00392440;
extern long D_001D4C30;
extern void func_0038CBA0();
extern void func_0012C638(s32, s32, s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00392440);

extern u32 *D_001DA050;
extern u8 D_001D0070[];
INCLUDE_ASM("asm/nonmatchings/text", func_003926E8);

extern u32 *D_001DA050;
extern u8 D_001D7370[];
extern u8 D_001D7390[];
extern u8 D_001D02D0[];
extern u8 D_001D7300[];
INCLUDE_ASM("asm/nonmatchings/text", func_00392748);

extern u32 *D_001DA050_00392868;
extern void func_003A9440(s32, unsigned long);
INCLUDE_ASM("asm/nonmatchings/text", func_00392868);

/* localdecomp:start func_00392A18 */
extern s32 D_001D5C78;
s32 func_00392A18(void) { s32 v = D_001D5C78; if (v != 0) return v + 0x7090; return 0; }
/* localdecomp:end func_00392A18 */

/* localdecomp:start func_00392A38 */
void *func_00392A38(p) u8 *p; {  /* K&R: a later caller uses an unprototyped call */
    void *r;
    *(s32 *)(p + 0x58) = 0; *(s32 *)(p + 0x5C) = 0; *(s32 *)(p + 0x60) = 0;
    r = ((void *(*)(void *, s32, s32))func_0011A264)(p + 8, 0xCD, 0x50);
    p[0x6C] = 0; *(s32 *)(p + 0x68) = 1;
    return r;
}
/* localdecomp:end func_00392A38 */

typedef struct { s32 a, b; } E_38E;
typedef struct { u8 pad[8]; E_38E e[10]; s32 f58, f5C, f60, f64, f68; u8 f6C; } S_38E;
/* localdecomp:start func_00392A80 */
s32 func_00392A80(S_38E *p, s32 *a, s32 *b) {
    s32 i;
    if (p->f60 == 0) return 0;
    if (--p->f60 == 0) p->f6C = 0;
    *a = p->e[p->f5C].a;
    *b = p->e[p->f5C].b;
    p->e[p->f5C].a = -1;
    p->e[p->f5C].b = -1;
    i = p->f5C + 1;
    if (i == 10) i = 0;
    p->f5C = i;
    return 1;
}
/* localdecomp:end func_00392A80 */

/* localdecomp:start func_00392B20 */
s32 func_00392B20(S_38E *p, s32 v) {
    s32 i, n;
    if (p->f60 == 10 || p->f6C != 0) return 0;
    p->e[p->f58].a = v;
    p->e[p->f58].b = v >= 100;
    i = p->f58 + 1;
    n = p->f60 + 1;
    if (i == 10) i = 0;
    p->f60 = n;
    p->f58 = i;
    return 1;
}
/* localdecomp:end func_00392B20 */

/* localdecomp:start func_00392B98 */
extern void *func_00392A38();
 
void func_00392B98(s32 *p) {
    func_00392A38();
}
/* localdecomp:end func_00392B98 */

extern s32 func_0039EF28();
typedef struct { u8 p0[8]; struct { s32 id; s32 x; } e[10]; s32 head; s32 tail; } S_E380;
extern u8 D_00142BA0[];
INCLUDE_ASM("asm/nonmatchings/text", func_00392BB8);

/* localdecomp:start func_00392C48 */
extern void func_00392BB8(s32 *);
extern void func_00392B98(s32 *);
void func_00392C48(s32 *p) {
    func_00392BB8(p);
    *p = 0;
    func_00392B98(p);
}
/* localdecomp:end func_00392C48 */

typedef struct {
    u8 pad0[0x60];
    s32 active;
    u8 flag64;
    u8 pad65[3];
    s32 mode68;
    u8 flag6C;
} Object_0038E440;
extern s32 D_001D5B94;
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
/* localdecomp:start func_00392C78 */
s32 func_00392C78(Object_0038E440 *object) {
    register s32 result __asm__("$17");
    s32 values[2];
    s32 mode;

    if (object->active == 0) {
        goto inactive;
    }
    object->flag64 = 0;
    object->flag6C = 1;
    values[0] = 0;
    result = 0;
    values[1] = 0;
    func_00392A80(object, &values[0], &values[1]);

    mode = 1;
    if ((u32)(D_001D5B94 - 1) < 2) {
        mode = 2;
    }
    object->mode68 = mode;

    if (values[1] == 0) {
        result = func_003A0EC0(1, mode, 0, values[0], 0);
    } else if (values[1] == 1) {
        result = func_003A0EC0(2, mode, values[0], 0, 0);
    }
    if (result < 0) {
        func_00392B98((s32 *)object);
    }
    return result == 0;
inactive:
    return 0;
}
/* localdecomp:end func_00392C78 */

/* localdecomp:start func_00392D40 */
extern s32 func_0039EF28();

void func_00392D40(s32 *input_ptr) {
    s32 *value_ptr = input_ptr;
    register u8 *page_temp __asm__("$2") = (u8 *)0x140000;
    register u8 *page __asm__("$17");
    register u8 *late_base __asm__("$3");
    register s32 output __asm__("$2");
    u8 *base;
    u8 flags;
    s32 value;

    __asm__ volatile("" : "+r"(page_temp));
    base = page_temp + 0x26E0;
    page = page_temp;
    flags = base[0x82];

    if ((flags & 1) == 0) {
        value = *value_ptr;
    } else {
        if (base[0x14] != 0) {
            value = *value_ptr;
            if (value == 3) {
                goto evaluate;
            }
            base[0x82] = flags & 0xFE;
            func_0039EF28();
        }
        value = *value_ptr;
    }

evaluate:
    if (value == 0xD && *(u8 *)0x1D5587 == 0) {
        output = 0x17;
    } else {
        if (value != 3) {
            return;
        }
        late_base = page + 0x26E0;
        __asm__ volatile("" : "+r"(late_base));
        if ((late_base[0x82] & 1) == 0) {
            return;
        }
        output = 6;
    }
    *value_ptr = output;
}
/* localdecomp:end func_00392D40 */

typedef struct { u8 pad[0x18]; s16 h18; u8 pad2[0x17C - 0x1A]; s32 x17C; } S_38E5B8;
extern S_38E5B8 D_00142430_00392DF0[];
extern s32 D_001D5B74;
extern s32 D_001D9D04;
extern s32 D_001D545C;
extern s32 D_001D4CF0;
extern s32 D_001D4CEC_00392DF0;
extern void func_0039EC28(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00392DF0);

LINKER_REMNANT("asm/remnants", func_00392EC0);

/* localdecomp:start func_00392EF0 */
extern u8 D_001D551C;
void func_00392EF0(void) {
    D_001D551C = 0;
}
/* localdecomp:end func_00392EF0 */

LINKER_REMNANT("asm/remnants", func_00392EF8);

extern u8 D_001D5BDC;
extern s32 D_001D5C90;
extern s32 D_0022758C;
extern s32 D_001DA058;
INCLUDE_ASM("asm/nonmatchings/text", func_00392F08);

/* localdecomp:start func_00392F60 */
extern s32 D_001D5C90;
void func_00392F60(s32 a) {
    D_001D5C90 = a;
}
/* localdecomp:end func_00392F60 */

/* localdecomp:start func_00392F68 */
typedef struct LookupEntry_38E730 {
    u16 key;
    u8 reserved[6];
} LookupEntry_38E730;
extern LookupEntry_38E730 *D_001D9EA4_00392F68[];
s32 func_00392F68(s32 key) {
    LookupEntry_38E730 *entry = *D_001D9EA4_00392F68;
    s32 index = 0;
    if (entry->key != 0xFFFF && entry->key != key) {
        LookupEntry_38E730 *cursor = entry;
        s32 current;
        for (;;) {
            cursor++;
            current = cursor->key;
            index++;
            if (current == 0xFFFF || current == key) break;
        }
    }
    return index <= 0x3FF ? index : -1;
}
/* localdecomp:end func_00392F68 */

LINKER_REMNANT("asm/remnants", func_00392FC0);

/* localdecomp:start func_00392FD0 */
typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_0038E798;
typedef struct { u32 w; u32 x; } E_0038E798;
extern S_0038E798 *D_001D9EA0_00392FD0[];
extern E_0038E798 *D_001D9EAC_00392FD0[];
extern E_0038E798 *D_001D9EB0_00392FD0[];
void func_00392FD0(s32 n, s32 size) {
    s32 i;
    s32 j;
    s32 end;
    if (D_001D9EA0_00392FD0[0]->c[n] == 0) {
        size = (size + 0xF) & 0xFFFFFFF0;
        D_001D9EA0_00392FD0[0]->c[n] = size;
        i = (n != 0) ? D_001D9EA0_00392FD0[0]->a[n - 1] : 0;
        end = D_001D9EA0_00392FD0[0]->a[n];
        for (j = i; j < end; j++) {
            D_001D9EB0_00392FD0[0][j].w &= 0x7FFFFFFF;
            D_001D9EB0_00392FD0[0][j].w += size;
        }
        i = (n != 0) ? D_001D9EA0_00392FD0[0]->b[n - 1] : 0;
        end = D_001D9EA0_00392FD0[0]->b[n];
        for (j = i; j < end; j++) {
            D_001D9EAC_00392FD0[0][j].w &= 0x7FFFFFFF;
            D_001D9EAC_00392FD0[0][j].w += size;
        }
    }
}
/* localdecomp:end func_00392FD0 */

LINKER_REMNANT("asm/remnants", func_00393130);

/* localdecomp:start func_00393138 */
extern u32 D_001D5D50;
u32 func_00393138(void) {
    u32 v = D_001D5D50;
    u32 r = 0;
    if (v <= 0x1CFFFF) r = (0x1D0000 - v) >> 2;
    return r;
}
/* localdecomp:end func_00393138 */

typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_38E930;
typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } E_38E930;
extern S_38E930 * volatile D_001D9EA0_00393168;
extern E_38E930 *D_001D9EAC_00393168;
extern volatile s32 D_001A1F08_00393168[];
extern void func_00392FD0_00393168();
extern void func_00397980(s32, s32, s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00393168);

extern s32 D_00227600[];
extern s32 D_001D9E98;
extern s32 D_001D9E9C;
INCLUDE_ASM("asm/nonmatchings/text", func_00393290);

/* localdecomp:start func_003932C0 */
__asm__(".extern D_001D9E98, 16");
__asm__(".extern D_001D9E9C, 16");
s32 func_003932C0(s32 size) {
    register s32 amount __asm__("$16") = size;
    register s32 current __asm__("$4");
    register s32 result __asm__("$2");
    if (D_001D9E98 == 0) {
        func_00393290();
    }
    result = D_001D9E9C;
    current = D_001D9E98;
    if (amount > result - current) {
        goto failure;
    }
    {
        register u32 mask __asm__("$3") = 0xfffffff0U;
        register s32 rounded __asm__("$5") = amount + 0xF;
        result = current;
        amount = rounded & mask;
        current += amount;
        D_001D9E98 = current;
        __asm__ volatile("" : : : "memory");
    }
    goto done;
failure:
    result = 0;
    __asm__ volatile("");
done:
    return result;
}
/* localdecomp:end func_003932C0 */
TEXT_PADDING(2);

typedef struct { s32 f0; s32 f4; u8 p8[0x18]; s32 f20; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; u8 p3C[0x28]; s32 f64; s32 f68; u8 p6C[4]; s32 f70; u8 p74[8]; s32 f7C; u8 p80[0x10]; } S_EB;
extern S_EB D_00331AE0_00393348[];
extern s32 D_001D5B94_00393348;
extern s32 D_001D9E88_00393348;
INCLUDE_ASM("asm/nonmatchings/text", func_00393348);

/* localdecomp:start func_00393450 */
typedef struct S_38EC18 {
    s32 pad0;
    s32 v4, v8, vC;
    void (*f10)(struct S_38EC18 *);
    s32 v14, v18, pad1C;
    s32 a20, a24, a28, a2C;
    void (*a30)(struct S_38EC18 *);
    s32 a34, a38;
    s32 pad3C[11];
    s32 x68;
} S_38EC18;
extern void func_00393538();
void func_00393450(S_38EC18 *p) {
    func_00393538(p, p->a20);
    p->v4 = p->a24;
    p->v14 = p->a34;
    p->v18 = p->a38;
    p->vC = p->a2C;
    p->v8 = p->a28;
    p->f10 = p->a30;
    if (p->f10) p->f10(p);
    p->x68 = 0;
}
/* localdecomp:end func_00393450 */

typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_00331AE0[];
extern void func_00393348();
INCLUDE_ASM("asm/nonmatchings/text", func_003934B8);

/* localdecomp:start func_00393538 */
typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
typedef struct { s32 x0; u8 pad[0x3C]; s16 x40; u8 x42; u8 x43; s32 x44; } S_38ED00;
extern E_38ED00 *D_001D9EA4[];
s32 func_00392F68(s32);
void func_00393538(S_38ED00 *d, s32 a) {
    s32 i = func_00392F68(a);
    if (i < 0) i = 0;
    d->x0 = D_001D9EA4[0][i].x0;
    d->x40 = i;
    d->x42 = D_001D9EA4[0][i].x6;
    d->x44 = D_001D9EA4[0][i].x4;

}
/* localdecomp:end func_00393538 */

INCLUDE_ASM("asm/nonmatchings/text", func_003935B0);

/* localdecomp:start func_00393620 */
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
s32 func_00393620(S_38EDE8 *p, s32 *x, s32 *y) {
    s32 w = p->w;
    s32 h = p->h;
    if ((p->u.c ^ 1) & 1) {
        if (!(p->u.flags & 2)) *y -= h >> 1;
    }
    if (!(p->u.flags & 4)) {
        if (p->u.flags & 8) *x -= w;
        else *x -= w >> 1;
    }
    return 0;
}
/* localdecomp:end func_00393620 */

typedef struct { u8 p0[0x58]; s32 f58; s32 f5C; u32 f60; u8 p64[0x18]; s32 f7C; } S_38EE58;
extern f32 D_00332230[];
extern f32 D_00332290[];
INCLUDE_ASM("asm/nonmatchings/text", func_00393690);

/* localdecomp:start func_00393808 */
typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p1[0x48]; s32 f58; s32 f5C; s32 f60; u8 p2[0x10]; s32 f74; s32 f78; } S;
void func_00393808(void *arg) {
    S *s = (S *)arg;
    s32 *q;
    s32 n, x, a, t;
    q = s->fC;
    if (q != 0 && ((s32)q & 3) == 0) {
        s->f78 = *q;
        if (s->f8 < s->f78) s->f78 = s->f8;
        s->f74 = s->f78;
    } else {
        s->f78 = 99999;
        s->f74 = 99999;
    }
    n = 0;
    x = s->f8;
    a = s->f60;
    t = s->f5C;
    if (x >= 10) {
        do { x /= 10; n++; } while (x >= 10);
    }
    if ((a & 3) == 0 && (a & 0xC) != 0) {
        s->f5C = t + (n + 1) * 12;
        if (s->f58 < 0xE) s->f58 = 0xE;
    } else {
        if (t < 12) s->f5C = 12;
        s->f58 = s->f58 + (n + 1) * 14;
    }
}
/* localdecomp:end func_00393808 */

/* US draft of func_003938F8 (rac3-uya-decomp func_0038F0C0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003938F8 */
extern void func_00393808(void *);
 
void func_003938F8(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0xB4;
    *(s16 *)((u8 *)p + 0x48) = 0;
    *(s16 *)((u8 *)p + 0x4A) = 0;
    func_00393808(p);
}
/* localdecomp:end func_003938F8 */

LINKER_REMNANT("asm/remnants", func_00393928);

INCLUDE_ASM("asm/nonmatchings/text", func_00393930);

typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p10[0x5C]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_38F0F8;
extern s32 func_003963D0();

LINKER_REMNANT("asm/remnants", func_00393AF0);

typedef struct { u8 pad[0x38]; u16 h38; u8 pad2[0xF0 - 0x3A]; } S_38F310;
typedef struct { s32 w0; u8 pad[0x14]; s32 w18; } D_393B58;
extern s32 D_001D9EE8_00393B58;
extern s32 *D_001D9EF0_00393B58;
extern s32 D_001D5D40;
extern s32 D_001D5CAC;
extern s32 D_1D4C60[2];
extern s32 D_1D4C80[2];
extern u8 D_001425C0[];
extern S_38F310 D_001DAA40_00393B58[];
extern D_393B58 D_00331990[];
INCLUDE_ASM("asm/nonmatchings/text", func_00393B58);

/* US draft of func_00393BE8 (rac3-uya-decomp func_0038F3A0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00393BE8 */
typedef struct { u8 pad[0x48]; s16 h48; s16 h4A; u8 p2[0x58-0x4C]; s32 w58; s32 w5C; u8 p3[0x70-0x60]; s32 w70; s32 w74; s32 w78; } S_38F3A0;
extern void func_00393B58(s32);
void func_00393BE8(S_38F3A0 *p) {
    func_00393B58(0);
    p->w58 = 0xD2; p->w5C = 0xC8; p->w74 = -2; p->w78 = 25; p->h48 = 0; p->h4A = 0; p->w70 = 0;
}
/* localdecomp:end func_00393BE8 */

INCLUDE_ASM("asm/nonmatchings/text", func_00393C40);

typedef struct {
    u8 pad0[0x64];
    s32 f64;
    u8 pad68[4];
    s32 f6C;
    u8 st[4];
    s32 f74;
    s32 f78;
    s32 f7C;
} O_38F3F8;
typedef struct {
    u8 pad0[0x148];
    f32 f148;
    f32 f14C;
    u8 pad150[0x1C0 - 0x150];
    s32 f1C0;
    volatile s32 f1C4;
    u8 pad1C8[4];
    s32 f1CC;
    u8 pad1D0[8];
    s32 f1D8;
} PAD_38F3F8;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
} E_38F3F8;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x84 - 0x14];
    u16 f84;
    u8 pad86[4];
    u16 f8A;
    u8 pad8C[0xF0 - 0x8C];
} T_38F3F8;
typedef struct { u8 pad[0xB6]; u8 b; } B6_38F3F8;
typedef struct { u8 pad0[0x1228]; s32 f1228; u8 pad122C[0x25F8 - 0x122C]; s32 f25F8; } W_38F3F8;
typedef struct { u8 pad0[0xF0]; u16 fF0; u8 padF2[2]; u32 fF4; s32 fF8; } X_38F3F8;
extern s32 D_0031D050[];
extern u8 D_00143950_b[];
extern s32 D_001D5C98;
extern s32 D_001D5D5C;
extern u8 D_001D5D58;
extern f32 D_001D5D54;
extern s32 D_001D5CAC;
extern PAD_38F3F8 *D_001D52FC;
extern u8 D_1A745E[];
extern s32 D_001D9EE8_0038F3F8;
extern s32 D_001D9EF0_0038F3F8;
extern volatile s32 D_001D5D00;
extern volatile s32 D_001D5D04;
extern volatile s32 D_001D5D08;
extern volatile s32 D_001D5D0C;
extern u8 D_1425C0[];
extern T_38F3F8 D_001DAA40_0038F3F8[];
extern s16 D_001CCFD4[];
extern u8 D_1A4BE0[];
extern u8 D_1A7C10[];
extern s32 D_1427F0[];
extern u32 D_001D4C38;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern s32 D_001D9F28;
extern s32 D_001D9BC8_0038F3F8;
extern s32 func_003E3DF0(void);
extern void func_003E3E08(void);
extern void func_003E3DC0(void);
extern void func_003AEB48(void *, s32);
extern s32 func_003A3BB8(s32, s32);
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_003A2558(void);
extern s32 func_0039AC08(s32);
extern void func_0039AA38(s32);
extern void func_00381CA8(s32);
extern void func_00381D70(s32);
extern s32 func_003934B8(s32);
#define ROW_38F3F8 ((E_38F3F8 *)((s32 *)D_001D9EF0_0038F3F8)[D_001D5CAC])
INCLUDE_ASM("asm/nonmatchings/text", func_00394620);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C0A0);

/* US draft of func_00394F48 (rac3-uya-decomp func_003906E8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00394F48 */
extern s32 D_001D9EE8[];
extern s32 D_001D9EF0[];
extern s32 D_001D5D38;
extern s32 D_001D5CAC;
void func_00394F48(u8 *p) {
    D_001D9EE8[0] = 4;
    D_001D9EF0[0] = (s32)&D_001D5D38;
    *(s32 *)(p + 0x58) = 0xD2;
    *(s32 *)(p + 0x5C) = 0xC8;
    *(s32 *)(p + 0x74) = -2;
    *(s16 *)(p + 0x48) = 0;
    *(s16 *)(p + 0x4A) = 0;
    *(s32 *)(p + 0x78) = 0x19;
    D_001D5CAC = 0;
}
/* localdecomp:end func_00394F48 */

typedef struct { u8 p0[0x64]; s32 f64; u8 p68[4]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_390730;
typedef struct { u8 p0[0x148]; f32 f148; f32 f14C; u8 p150[0x70]; s32 f1C0; s32 f1C4; s32 f1C8; s32 f1CC; } P_390730;
typedef struct { u8 p0[8]; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; } T_390730;
typedef struct { u8 p0[0x286C]; s32 f286C; } G_390730;
extern P_390730 *D_001D52FC_00394F90;
extern s16 D_001D9EB4;
extern s16 D_001D9EB8;
extern s16 D_001D9EBA;
extern s16 D_001D9EBC;
extern s32 D_001D9EE8_00394F90;
extern s32 D_001D9EF0_00394F90;
extern s32 D_001D9BC8_00394F90;
extern volatile s32 D_001D5D20;
extern volatile s32 D_001D5D24;
extern volatile s32 D_001D5D28;
extern volatile s32 D_001D5D2C;
extern s32 D_001D9F28;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern u8 D_00143A06[];
extern G_390730 D_001A4BE0_00394F90;
extern void func_003E3E08(void);
extern f32 func_0038D160(f32, f32);
extern s32 func_003A5348(s32, s32, s32);
extern void func_003E3DC0(void);
extern s32 func_003934B8(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00394F90);

INCLUDE_ASM("asm/nonmatchings/text", func_00395478);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C0C0);

LINKER_REMNANT("asm/remnants", func_00396240);

typedef struct { u8 p0[8]; s32 w8; u8 pC[0x44]; s32 w50; s32 w54; s32 w58; s32 w5C; u8 p60[0xC]; s32 w6C; u8 p70[4]; s32 w74; } O_91A18;
extern void func_00396C60();
extern void func_003970D8();
extern void func_00393690();
extern s16 D_001A666A[];
INCLUDE_ASM("asm/nonmatchings/text", func_00396278);

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

/* PAL candidate for func_003963D0 (US draft: rac3-uya-decomp func_00391B70).

   PAL differences from the US draft:
   - the retail reads D_001D9EA4 and D_001D9D00 with lui/lw, not through $gp,
     so both globals are declared as arrays (size > 8 / unknown) here;
   - the constant passed to func_00382468 is 0x19, not 0x1E;
   - the value added to its result is 8, not 10. */

/* localdecomp:start func_003963D0 */
extern s32 func_00382468(s32, s32);
typedef struct { s16 f0; u8 b2; u8 p3[9]; s32 fC; } O_391B70;
typedef struct { u16 h0; u16 h2; u16 h4; u8 b6; u8 b7; } E_391B70;
extern s32 D_001D9D00[4];
s32 func_003963D0(O_391B70 *o) {
    E_391B70 *e = (E_391B70 *)((u8 *)D_001D9EA4[0] + o->f0 * 8);
    s32 r = 0;
    if (e->h0 != 0xFFFF) {
        switch (o->b2) {
        case 0:
            r = e->h4;
            break;
        case 1:
            r = e->h4 + ((D_001D9D00[0] - o->fC) / e->b7) % e->h2;
            break;
        case 2: {
            s32 n = e->h2 * 2;
            r = ((D_001D9D00[0] - o->fC) / e->b7) % (n - 2);
            if (r >= e->h2) {
                s32 u = r + 2;
                r = n - u;
            }
            goto add;
        }
        case 3: {
            s32 t = o->fC;
            do {
                if (t < D_001D9D00[0]) {
                    s32 n;
                    r = (D_001D9D00[0] - t) / e->b7;
                    n = e->h2 * 2;
                    if (r < n - 2) {
                        if (r >= e->h2) {
                            s32 u = r + 2;
                            r = n - u;
                        }
                    add:
                        r += e->h4;
                    } else {
                        s32 k;
                        r = e->h4;
                        k = func_00382468(0x19, t) + 8;
                        o->fC = e->h2 * 2 + k;
                    }
                } else {
                    r = *(s32 *)((u8 *)o + 4);
                }
            } while (0);
        }
        }
    }
    *(s32 *)((u8 *)o + 4) = r;
    return r;
}
/* localdecomp:end func_003963D0 */

typedef struct S_391D08 {
    s32 f0;
    s32 f4;
    u8 p8[0xC];
    void (*f14)(struct S_391D08 *);
    u8 p18[0x50];
    s32 f68;
    s32 f6C;
    u8 p70[0xC];
    s32 f7C;
    u8 p80[0x10];
} S_391D08;
extern S_391D08 D_00331AE0_00396568[];
extern s32 D_001D9E8C_00396568;
extern void func_003966D8();
INCLUDE_ASM("asm/nonmatchings/text", func_00396568);

typedef struct {
    u8 pad[0x84];
    u16 f84;
    u8 pad2[0xF0 - 0x86];
} S_391E30;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern S_391E30 D_001DAA40[];
INCLUDE_ASM("asm/nonmatchings/text", func_00396690);

typedef struct {
    u8 f0;
    u8 p1[0x37];
    u16 f38;
    u8 p3A[0x50];
    u16 f8A;
    u8 p8C[0xF0 - 0x8C];
} S_391E78;
extern u8 D_001D5EA4;
extern s32 D_001D5E98;
extern s32 D_001D5E9C;
extern s32 D_001D5EA0;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern S_391E78 D_001DAA40_003966D8[];
extern s32 func_00396690(void);
extern void func_003935B0(s32 id, s32 v);
extern void func_00396390();
extern void func_00397B10();
extern s32 func_003963C0(void);
extern void func_003938F8();
extern s32 func_00396278();
INCLUDE_ASM("asm/nonmatchings/text", func_003966D8);

typedef struct { u8 p0[0x18]; void (*f18)(void *); u8 p1c[0x74]; } S_391FD8;
extern S_391FD8 D_00331AE0_00396838[];
extern s32 D_001D9EC0;
extern s32 D_001D9BDC;
extern s32 D_001D9E94;
extern s32 D_001D9DF8;
extern s32 D_001D9DFC;
extern s32 D_001D9E00;
extern s32 D_001D5B94;
INCLUDE_ASM("asm/nonmatchings/text", func_00396838);

/* localdecomp:start func_00396968 */
typedef struct { s16 a; s16 b; } P_392108;
typedef struct { s32 w; s32 pad; } W_392108;
extern u8 D_001D5EA5;
extern P_392108 *D_001D9EA8[];
extern W_392108 *D_001D9EAC[];
extern W_392108 *D_001D9EB0[];
s32 func_00396968(s32 key, s32 n) {
    s32 r;
    s32 idx;
    u32 mask;
    E_38ED00 *e;
    P_392108 *p;
    if (D_001D5EA5 == 0) {
        r = func_00392F68(key);
        D_001D5EA5 = (u32)r >> 31;
        e = (E_38ED00 *)((r << 3) + (s32)D_001D9EA4[0]);
        if (e->x0 != 0xFFFF && n < e->x2) {
            idx = e->x4 + n;
            p = (P_392108 *)((idx << 2) + (s32)D_001D9EA8[0]);
            if ((D_001D9EB0[0][p->a].w & 0x80000000) == 0) {
                return (D_001D9EAC[0][p->b].w & 0x80000000) ? 0 : idx;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_00396968 */

INCLUDE_ASM("asm/nonmatchings/text", func_00396A38);

typedef struct { s32 w; u8 pad[2]; u8 b6; u8 b7; } W_392400;
extern P_392108 *D_001D9EA8_00396C60;
extern W_392400 *D_001D9EAC_00396C60;
extern u32 *D_001DA050;
extern s32 func_00396A38_00396C60();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001D9E94;
INCLUDE_ASM("asm/nonmatchings/text", func_00396C60);

typedef int u128_3925F0 __attribute__((mode(TI)));
extern u8 D_001D76F0[];
extern P_392108 *D_001D9EA8_00396E50;
extern W_392108 *D_001D9EAC_00396E50;
extern s32 D_001DA050_00396E50;
extern s32 D_001D9E94;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern unsigned long func_00396A38(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00396E50);

extern u32 *D_001DA050;
extern s32 func_00396A38_003970D8();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001D9E94;
INCLUDE_ASM("asm/nonmatchings/text", func_003970D8);

LINKER_REMNANT("asm/remnants", func_00397280);

typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } E_392A40;
extern P_392108 *D_001D9EA8_003972A0;
extern E_392A40 *D_001D9EAC_003972A0;
typedef int Q_392A40 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } V4_392A40;
extern u32 *D_001DA050;
extern s32 func_00396A38_003972A0();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern Q_392A40 D_001D76F0_003972A0[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003972A0);

typedef int Q_392DD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } V4_392DD8;
extern u32 *D_001DA050;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001D9E94;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
INCLUDE_ASM("asm/nonmatchings/text", func_00397638);

/* PAL candidate for func_00397980 (US draft: rac3-uya-decomp func_00393120, commit 13cf5c5).
   The US matched it with `@ps2as`; here the file's own flags (-mno-split-addresses, default
   assembler) must do it, so the global is reached the way retail reaches it: the reads of the
   pointer at 0x001DA050 go through an unsized alias (never small data, so `lui`/`lw`), while the
   writes of the pointer itself stay on the sized declaration ($gp). */

/* localdecomp:start func_00397980 */
extern u32 *D_001DA050_00397980;
extern u32 D_001DA050_00397980_lui[];
extern void func_12C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, s32);
void func_00397980(s32 a0, s32 a1, s32 a2, s32 d, s32 e, s32 f) {
    u32 tmp[24];
    u32 *buf;
    s32 c, m;
    c = (1 << d) >> 6;
    m = 1 << (d + e - 4);
    if (c <= 0) c = 1;
    if (f == 0) {
        ((u32 *)D_001DA050_00397980_lui[0])[0] = 0x10000006;
        ((u32 *)D_001DA050_00397980_lui[0])[1] = 0;
        ((u32 *)D_001DA050_00397980_lui[0])[2] = 0;
        ((u32 *)D_001DA050_00397980_lui[0])[3] = 0x50000006;
        buf = (u32 *)D_001DA050_00397980_lui[0] + 4;
        D_001DA050_00397980 = (u32 *)((u8 *)D_001DA050_00397980_lui[0] + 0x70);
    } else {
        buf = tmp;
    }
    func_12C9A0(buf, a1, c, a2, 0, 0, 1 << d, 1 << e);
    if (f == 0) {
        D_001DA050_00397980[0] = m | 0x30000000;
        ((u32 *)D_001DA050_00397980_lui[0])[1] = a0;
        ((u32 *)D_001DA050_00397980_lui[0])[2] = 0;
        ((u32 *)D_001DA050_00397980_lui[0])[3] = m | 0x50000000;
        D_001DA050_00397980 = (u32 *)D_001DA050_00397980_lui[0] + 4;
    } else {
        func_11F0A0(0);
        func_12CCC8(buf, a0);
    }
}
/* localdecomp:end func_00397980 */

LINKER_REMNANT("asm/remnants", func_00397AF0);

typedef struct {
    u8 pad0[8]; s32 f8; s32 *fC; u8 pad10[0x5C]; s32 f6C; u8 b[2]; u8 pad72[2]; s32 f74; u8 pad78[4]; s32 f7C;
} S_3932B0;
/* US draft of func_00397B10 (rac3-uya-decomp func_003932B0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00397B10 */
typedef struct {
    u8 pad0[8]; s32 f8; s32 *fC; u8 pad10[0x5C]; s32 f6C; u8 b[2]; u8 pad72[2]; s32 f74; u8 pad78[4]; s32 f7C;
} S_3932B0_00397B10;
void func_00397B10(S_3932B0_00397B10 *p) {
    u8 *b = p->b;
    s32 t = *p->fC;
    s32 a = p->f8;
    p->f74 = t;
    if (a < t) {
        p->f74 = a;
    } else if (t < 0) {
        p->f74 = 0;
    }
    if (p->f7C >= 4) {
        p->f7C = 4;
        if (b[0] < 8) {
            b[0]++;
        } else if (b[1] < 8) {
            b[1]++;
        }
    } else {
        p->f6C = 1;
        if (b[1] != 0) {
            b[1]--;
        } else if (b[0] != 0) {
            b[0]--;
        } else {
            p->f6C = -6;
        }
    }
}
/* localdecomp:end func_00397B10 */

LINKER_REMNANT("asm/remnants", func_00397BC0);

/* localdecomp:start func_00397BD0 */
extern u8 D_001D5EDC;
void func_00397BD0(void) { D_001D5EDC = 1; }
/* localdecomp:end func_00397BD0 */

extern u8 D_001D5EDC;
extern s32 D_001D5ED8;
extern void func_0038AE20();
INCLUDE_ASM("asm/nonmatchings/text", func_00397BE0);

LINKER_REMNANT("asm/remnants", func_00397C78);

/* localdecomp:start func_00397C80 */
extern u8 D_001D5EDD;
void func_00397C80(void) {
    D_001D5EDD = 0;
}
/* localdecomp:end func_00397C80 */

/* localdecomp:start func_00397C88 */
extern s32 D_001D5EE0;
void func_00397C88(void) {
    D_001D5EE0 = 0;
}
/* localdecomp:end func_00397C88 */

/* localdecomp:start func_00397C90 */
extern s32 D_001D5EE0;
void func_00397C90(void) {
    if (D_001D5EE0 == 0) D_001D5EE0 = 1;
}
/* localdecomp:end func_00397C90 */

/* localdecomp:start func_00397CA8 */
extern s32 D_001D5EE0;
s32 func_00397CA8(void) {
    return D_001D5EE0 == 3;
}
/* localdecomp:end func_00397CA8 */

LINKER_REMNANT("asm/remnants", func_00397CB8);

/* localdecomp:start func_00397CC0 */
extern void func_0038A238(s32);
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_003A5430(void);
extern void func_003A2558(void);
extern void func_003A1C28(void);
extern void func_12EF10(void);
extern void func_121B38(void);
extern void func_124ED8(s32, s32, s32);
void func_00397CC0(s32 a, s32 b, s32 c) {
    func_0038A238(5);
    func_13CA28();
    func_13B620();
    func_003A5430();
    func_003A2558();
    func_003A1C28();
    func_12EF10();
    func_121B38();
    func_124ED8(a, b, c);
}
/* localdecomp:end func_00397CC0 */

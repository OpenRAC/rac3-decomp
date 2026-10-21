#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00392698(void);
extern void func_00392730(s32);
extern void func_003927B0(void);
extern void func_00392B28(s32);
extern void (*D_001D9A40[2])(s32);
extern void func_00392820(s32, s32, s32, s32);
extern void func_00392C48(s32, s32);
extern void func_00392AC8(void);
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
extern u8 D_00144440[];
extern u8 D_00143E40[];
extern u8 D_0014A840[];
extern u8 D_0014A240[];
extern void func_0038E1F8(s32, void *, void *);
extern s32 D_001D9BC8[];
extern s32 D_001D9BC8[];
extern s32 D_001D5B34;
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
extern s32 *D_001D55C4[];
typedef struct { u32 w0; u32 w4; } E_3899B8;
extern E_3899B8 *D_001D55C4_0038E5C8;
extern u8 D_001D5B42;
typedef struct { u32 w0; u32 w4; } E_389B98;
extern s32 D_001D55C8;
extern s32 *D_001D55C4[];
extern s32 func_0038E488(u8 *p, s32 off, s32 *out);
typedef struct { u32 w0; u32 w4; } E_389D18;
typedef struct { s16 ch; s8 adj; u8 end; } K_389D18;
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 h12; s16 h14, h16; } B_38BB50;
typedef struct { u32 w0, w1; } G_38BB50;
extern s32 D_001D5B94;
extern u8 D_001D5B41;
extern s32 D_001D5B48[2];
extern s32 D_001D5B5C[];
extern s32 D_001D4BC0[];
extern s32 D_001D4BC4[];
extern void func_003A98B8(s32, s32, s32, s32);
extern s32 func_0038E488(u8 *p, s32 off, s32 *out);
extern s32 func_0038E928_00390768(u8 *, s32, f32);
extern void func_0038EBC8_00390768(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
extern void func_0038E928();
extern void func_0038E5C8(void);
extern void func_0038E7A0();
extern void func_0038E7A0();
extern void func_0038E928();
extern void func_0038E928();
extern void func_0038E928();
extern void func_0038EBC8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
extern void func_0038E928();
extern s32 D_001D55E8;
extern void func_0038E530(s32);
extern void func_0038EBC8_00391240(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
extern s32 func_0038E928_00391240(s32, s32, f32);
extern void func_0038EBC8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
extern s32 D_001D55E8;
extern void func_0038E530(s32);
extern void func_0038EBC8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
extern s32 D_001D55E8;
extern void func_0038E530(s32);
extern void func_00390768();
extern f32 func_00390FD8(s32, s32, s32, f32);
extern void func_0038EBC8_00391620(s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, unsigned long, f32);
extern void func_0038E2B0();
extern f32 func_00390FD8();
extern s32 D_00143950[];
extern s32 D_001D5520;
extern void func_12A950(void);
extern void func_12BEE8(s32, s32, s32, s32);
extern s32 D_001D4D08[];
extern s32 D_001D4D0C[];
extern s32 D_001D4D10[];
extern s32 D_001D4D14[];
extern s32 D_001D4D18[];
extern s32 D_001D4D1C[];
extern s32 D_001D4CF8[];
extern s32 D_001D4D08_003917E8;
extern s32 D_001D4D0C_003917E8;
extern void func_00391778(void);
typedef struct {
    u8 p0[0x150];
    s16 h150, h152, h154, h156, h158, h15A;
} E_38CC68;
extern unsigned long D_001D0560[];
extern E_38CC68 *D_001D4CF8_00391880;
extern u8 D_001439FD[];
extern s32 D_001D5520;
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
extern void func_00391778(void);
extern void func_00391880(s32, s32);
extern void func_0038D068();
extern void func_11F0A0(s32);
extern unsigned long D_001D07E8[];
extern void func_12C4B0(s32);
extern s32 D_001D4CF8[];

/* localdecomp:start func_00392698 */
extern u32 *D_001DA050;
extern s32 D_001D4CF8_00392698; 
extern void func_12C820(s32);

void func_00392698(void) {
    if (D_001DA050 != 0) {
        D_001DA050[0] = 0x30000009;
        D_001DA050[1] = (D_001D4CF8_00392698 + 0x30) & 0xFFFFFFF;
        D_001DA050[2] = 0;
        D_001DA050[3] = 0x50000009;
        D_001DA050 += 4;
    } else {
        func_12C820(D_001D4CF8_00392698 + 0x30);
    }
}
/* localdecomp:end func_00392698 */

/* localdecomp:start func_00392730 */
extern u32 *D_001DA050;
extern u8 D_1D07B0[], D_1D0900[];
void func_00392730(s32 a) {
    if (D_001DA050 != 0) {
        D_001DA050[0] = 0x30000015;
        if (a == 0) D_001DA050[1] = (u32)D_1D07B0;
        else D_001DA050[1] = (u32)D_1D0900;
        D_001DA050[2] = 0;
        D_001DA050[3] = 0x50000015;
        D_001DA050 += 4;
    }
}
/* localdecomp:end func_00392730 */

/* localdecomp:start func_003927B0 */
extern u32 *D_001DA050;
extern s32 D_001D4CF8_003927B0;
void func_003927B0(void) {
    D_001DA050[0] = 0x30000009;
    D_001DA050[1] = (D_001D4CF8_003927B0 + 0xC0) & 0xFFFFFFF;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000009;
    D_001DA050 += 4;
}
/* localdecomp:end func_003927B0 */

/* localdecomp:start func_00392820 */
/* func_00392820: MATCH (try_func.py and try_in_context.py). Flags: S mode + @ps2as, a single-function override
 * (the file's range is N): text_parts line 0x0038DC08 "... @ps2as" plus a restore line at 0x0038DEB0 if needed
 * (0x0038DEB0 already has its own override). Aliases: D_001CFEC0_00392820 = 0x1CFEC0, D_001DA050_00392820 = 0x1DA0D0.
 * Fix over the 4-diff draft: the second packet's stores in plain order (t[0]..t[7]) and the tail's struct pointer as
 * its own variable with an empty register fence (__asm__("" : "+r"(s2)), the documented barrier form) after the
 * t[7] store. The fence insn takes an issue slot in sched1, so the 0x8000 constant is born one insn later and
 * local-alloc gives 0xE and 0x8000 the same $a2, as retail. Without the fence: 7.
 */
typedef struct { unsigned long lo : 9; unsigned long hi : 55; } BF_38DC08;
typedef struct { u8 p0[0x160]; s16 h160; s16 h162; s16 h164; s16 h166; u8 p168[4]; u16 h16C; s16 h16E; } S_38DC08;
extern S_38DC08 D_001CFEC0_00392820[];
extern s32 D_001DA050_00392820;
extern long D_001D4C30;
extern void func_0038CF80();
extern void func_0012C638(s32, s32, s32, s32, s32, s32);
void func_00392820(s32 tw, s32 th, s32 tbp, s32 mode) {
    S_38DC08 *s = D_001CFEC0_00392820;
    s32 tbw;
    long tex;
    u8 *p;
    long *q;
    long v;
    long w;

    tbw = tw - 6;
    if (tbw <= 0) tbw = 1;
    s->h166 = tbp >> 13;
    s->h160 = 1 << tw;
    s->h162 = 1 << th;
    tex = (tbp >> 8) | ((long)(1 << tbw) << 14) | ((long)tw << 26) | ((long)th << 30) | (0x8000UL << 19);
    D_001D4C30 = tex;
    func_0038CF80(D_001DA050_00392820, 0xF0);
    *(u32 *)(D_001DA050_00392820 + 0) = 0x1000000E;
    *(u32 *)(D_001DA050_00392820 + 4) = 0;
    *(u32 *)(D_001DA050_00392820 + 8) = 0;
    *(u32 *)(D_001DA050_00392820 + 0xC) = 0x5000000E;
    w = 0x4410;
    v = 0x106;
    {
        long *t = (long *)(D_001DA050_00392820 + 0x10);
        D_001DA050_00392820 = (s32)t;
        t[0] = 0x1000000000000008UL;
        t[1] = 0xE;
    }
    p = (u8 *)D_001DA050_00392820;
    q = (long *)(p + 0x10);
    D_001DA050_00392820 = (s32)q;
    func_0012C638((s32)q, s->h164, s->h160, s->h162, 3, 0);
    ((BF_38DC08 *)(p + 0x10))->lo = s->h166;
    if (mode == 0) {
        q[2] = s->h16E | ((long)(s->h16C & 0xF) << 24);
    } else {
        s32 n = tw + th;
        if (n > 16) n = 16;
        q[2] = ((tbp - (4 << n)) >> 13) | ((long)(s->h16C & 0xF) << 24);
    }
    {
        long *t = (long *)(D_001DA050_00392820 + 0x80);
        S_38DC08 *s2 = D_001CFEC0_00392820;
        D_001DA050_00392820 = (s32)t;
        t[0] = 0x1000000000000001UL;
        t[1] = 0xE;
        t[2] = 0x30003;
        t[3] = 0x47;
        t[4] = 0x4400000000008001UL;
        t[5] = w;
        t[6] = v;
        t[7] = 0;
        __asm__("" : "+r"(s2));
        t[8] = (0x8000 - s2->h160 * 8) | ((long)(0x8000 - s2->h162 * 8) << 16);
        t[9] = (s2->h160 * 8 + 0x8000) | ((long)(s2->h162 * 8 + 0x7FF0) << 16);
    }
    D_001DA050_00392820 += 0x50;
}
/* localdecomp:end func_00392820 */

/* localdecomp:start func_00392AC8 */
extern u32 *D_001DA050;
extern u8 D_001D0070[];
void func_00392AC8(void) {
    D_001DA050[0] = 0x30000026;
    D_001DA050[1] = (u32)D_001D0070;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000026;
    D_001DA050 += 4;
}
/* localdecomp:end func_00392AC8 */

/* localdecomp:start func_00392B28 */
extern u32 *D_001DA050;
extern u8 D_001D7370[];
extern u8 D_001D7390[];
extern u8 D_001D02D0[];
extern u8 D_001D7300[];
void func_00392B28(s32 a0) {
    D_001DA050[0] = 0x30000002;
    if (a0 != 0) {
        D_001DA050[1] = (u32)D_001D7370;
    } else {
        D_001DA050[1] = (u32)D_001D7390;
    }
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000002;
    D_001DA050 += 4;
    D_001DA050[0] = 0x30000029;
    D_001DA050[1] = (u32)D_001D02D0;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000029;
    D_001DA050 += 4;
    D_001DA050[0] = 0x30000003;
    D_001DA050[1] = (u32)D_001D7300;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000003;
    D_001DA050 += 4;
}
/* localdecomp:end func_00392B28 */

/* localdecomp:start func_00392C48 */
extern u32 *D_001DA050_00392C48;
extern void func_003A97F8(s32, unsigned long);
void func_00392C48(s32 x, s32 y) {
    s32 n = x / 32;
    unsigned long *p, *q, *r;
    s32 i, a, b, lo, hi;
    func_003A97F8(0x42, (0x8000UL << 24) | 0x4A);
    D_001DA050_00392C48[0] = (n + 5) | 0x10000000;
    D_001DA050_00392C48[1] = 0;
    D_001DA050_00392C48[2] = 0;
    D_001DA050_00392C48[3] = (n + 5) | 0x50000000;
    p = (unsigned long *)D_001DA050_00392C48;
    r = p + 2;
    D_001DA050_00392C48 = (u32 *)r;
    p[2] = (0x8000UL << 45) | 1;
    r[1] = 0xE;
    r[2] = 0x32003;
    r[3] = 0x47;
    r[4] = (0x9000UL << 46) | 1;
    r[5] = 0x10;
    r[6] = 0x146;
    r[7] = (0x8000UL << 16) | 0x8080;
    r[8] = n | 0x8000 | (0x9000UL << 46);
    r[9] = 0x44;
    i = 0;
    if (n > i) {
        unsigned long t0, t1;
        a = y * 8;
        t0 = (unsigned long)(0x8000 - a) << 16;
        t1 = (unsigned long)(a + 0x7FF0) << 16;
        b = -(x * 8);
        lo = b + 0x8000;
        hi = b + 0x8200;
        q = p + 12;
        do {
            *q++ = lo | t0;
            *q++ = hi | t1;
            hi += 0x200;
            lo += 0x200;
            i++;
        } while (i < n);
    }
    D_001DA050_00392C48 += n * 4 + 0x14;
}
/* localdecomp:end func_00392C48 */

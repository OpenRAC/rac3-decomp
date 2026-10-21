/* Near miss of func_00392440 with its file's own flags: tools/check.py reports 134 diff
   (the version it replaces: 160).
   What differs: The global at 0x001DA050 now matches retail exactly (each access uses its own
   unsized alias so the symbol stays in the load/store and the default assembler forms
   `lui`+`lw %lo`/`sw %lo`; the one write before the func_0012C638 call stays on the sized
   declaration for the `$gp` store), but 133 words still differ because retail's remaining
   addresses/constants are split-address shapes that -mno-split-addresses cannot produce:
   retail keeps the %hi of D_001CFEC0 in $s1 and re-derives the address with `addiu` at each
   use (`lui $s1; addiu $s4,$s1,%lo` ... `addiu $5,$s1,%lo`) and builds the 64-bit...
*/

/* PAL candidate for func_00392440 (frontbin).
   The global at 0x001DA050 is reached the way retail reaches it: every access is its own
   unsized alias (an array type is never small data, so the compiler keeps the symbol in
   the load/store and the address is formed per access), except the write just before the
   func_0012C638 call, which stays on the sized declaration ($gp relative). */

/* localdecomp:start func_00392440 */
typedef struct { unsigned long lo : 9; unsigned long hi : 55; } BF_38DC08;
typedef struct { u8 p0[0x160]; s16 h160; s16 h162; s16 h164; s16 h166; u8 p168[4]; u16 h16C; s16 h16E; } S_38DC08;
extern S_38DC08 D_001CFEC0_00392440[];
extern s32 D_001DA050_00392440;
extern u32 D_001DA050_00392440_r0[];
extern u32 D_001DA050_00392440_r1[];
extern u32 D_001DA050_00392440_r2[];
extern u32 D_001DA050_00392440_r3[];
extern u32 D_001DA050_00392440_r4[];
extern u32 D_001DA050_00392440_r5[];
extern u32 D_001DA050_00392440_r6[];
extern u32 D_001DA050_00392440_r7[];
extern u32 D_001DA050_00392440_r8[];
extern u32 D_001DA050_00392440_w0[];
extern u32 D_001DA050_00392440_w1[];
extern u32 D_001DA050_00392440_w2[];
extern long D_001D4C30;
extern void func_0038CBA0();
extern void func_0012C638(s32, s32, s32, s32, s32, s32);
void func_00392440(s32 tw, s32 th, s32 tbp, s32 mode) {
    S_38DC08 *s = D_001CFEC0_00392440;
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
    func_0038CBA0(D_001DA050_00392440_r0[0], 0xF0);
    *(u32 *)(D_001DA050_00392440_r1[0] + 0) = 0x1000000E;
    *(u32 *)(D_001DA050_00392440_r2[0] + 4) = 0;
    *(u32 *)(D_001DA050_00392440_r3[0] + 8) = 0;
    *(u32 *)(D_001DA050_00392440_r4[0] + 0xC) = 0x5000000E;
    w = 0x4410;
    v = 0x106;
    {
        long *t = (long *)(D_001DA050_00392440_r5[0] + 0x10);
        D_001DA050_00392440_w0[0] = (u32)t;
        t[0] = 0x1000000000000008UL;
        t[1] = 0xE;
    }
    p = (u8 *)D_001DA050_00392440_r6[0];
    q = (long *)(p + 0x10);
    D_001DA050_00392440 = (s32)q;
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
        long *t = (long *)(D_001DA050_00392440_r7[0] + 0x80);
        S_38DC08 *s2 = D_001CFEC0_00392440;
        D_001DA050_00392440_w1[0] = (u32)t;
        t[0] = 0x1000000000000001UL;
        t[1] = 0xE;
        t[2] = 0x30003;
        t[3] = 0x47;
        t[4] = 0x4400000000008001UL;
        t[5] = w;
        t[6] = v;
        t[7] = 0;
        t[8] = (0x8000 - s2->h160 * 8) | ((long)(0x8000 - s2->h162 * 8) << 16);
        t[9] = (s2->h160 * 8 + 0x8000) | ((long)(s2->h162 * 8 + 0x7FF0) << 16);
    }
    D_001DA050_00392440_w2[0] = D_001DA050_00392440_r8[0] + 0x50;
}
/* localdecomp:end func_00392440 */

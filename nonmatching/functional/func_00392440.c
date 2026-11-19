/* functional: high. Appends a texture-setup block to the GS/DMA list at D_001DA050: computes the TEX0-style value (tbp>>8 | 1<<max(tw-6,1) at bit 14 | tw<<26 | th<<30 | 1<<34... as the asm) into D_001D4C30 and the texture width/height/base into D_001CFEC0 (+0x160/+0x162/+0x166), zero-fills 0xF0 bytes of list (func_0038CBA0), writes a header tag + an A+D pair, lets func_0012C638 fill the next block, patches its first doubleword's low 9 bits with the base, sets a second doubleword (mode 0: h16E | (h16C&15)<<24; else (tbp-(4<<min(tw+th,16)))>>13 | same), then appends a 10-doubleword register block (scissor from the width/height *8 around 0x8000) and advances the list pointer by 0x50 past it. Rewritten as plain C from the PAL asm (the draft's per-access aliasing is a byte-matching device); stores in the jal delay slots (D_001D4C30 and the list pointer) are done before the calls, and the list pointer is reloaded after func_0012C638 because it advances it. */
typedef struct { u8 p0[0x160]; s16 h160; s16 h162; s16 h164; s16 h166; u8 p168[4]; u16 h16C; s16 h16E; } S_392440;
extern S_392440 D_001CFEC0;
extern u8 *D_001DA050;
extern long D_001D4C30;
extern void func_0038CBA0();
extern void func_0012C638(void *, s32, s32, s32, s32, s32);

void func_00392440(s32 tw, s32 th, s32 tbp, s32 mode)
{
    S_392440 *s = &D_001CFEC0;
    s32 tbw;
    long tex;
    long *q;
    long *t;
    u8 *p;

    tbw = tw - 6;
    if (tbw <= 0) {
        tbw = 1;
    }
    s->h166 = tbp >> 13;
    s->h160 = 1 << tw;
    s->h162 = 1 << th;
    tex = (tbp >> 8) | ((long)(1 << tbw) << 14) | ((long)tw << 26) | ((long)th << 30) | (0x8000L << 19);
    D_001D4C30 = tex;
    func_0038CBA0(D_001DA050, 0xF0);
    *(u32 *)(D_001DA050 + 0) = 0x1000000E;
    *(u32 *)(D_001DA050 + 4) = 0;
    *(u32 *)(D_001DA050 + 8) = 0;
    *(u32 *)(D_001DA050 + 0xC) = 0x5000000E;
    p = D_001DA050;
    D_001DA050 = p + 0x10;
    *(long *)(p + 0x10) = 0x1000000000000008L;
    *(long *)(p + 0x18) = 0xE;
    p = D_001DA050;
    q = (long *)(p + 0x10);
    D_001DA050 = (u8 *)q;
    func_0012C638(q, s->h164, s->h160, s->h162, 3, 0);
    q[0] = (q[0] & ~0x1FFL) | (s->h166 & 0x1FF);
    if (mode == 0) {
        q[2] = s->h16E | ((long)(s->h16C & 0xF) << 24);
    } else {
        s32 n = tw + th;

        if (n > 16) {
            n = 16;
        }
        q[2] = ((tbp - (4 << n)) >> 13) | ((long)(s->h16C & 0xF) << 24);
    }
    p = D_001DA050;
    t = (long *)(p + 0x80);
    D_001DA050 = (u8 *)t;
    t[0] = 0x1000000000000001L;
    t[1] = 0xE;
    t[2] = 0x30003;
    t[3] = 0x47;
    t[4] = 0x4400000000008001L;
    t[5] = 0x4410;
    t[6] = 0x106;
    t[7] = 0;
    t[8] = (0x8000 - s->h160 * 8) | ((long)(0x8000 - s->h162 * 8) << 16);
    t[9] = (s->h160 * 8 + 0x8000) | ((long)(s->h162 * 8 + 0x7FF0) << 16);
    D_001DA050 = D_001DA050 + 0x50;
}

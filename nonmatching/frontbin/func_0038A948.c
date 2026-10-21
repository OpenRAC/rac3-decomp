/* Near miss of func_0038A948 with its file's own flags: tools/check.py reports 118 diff
   (the version it replaces: 155).
   What differs: the addressing and register allocation now match retail exactly (unsized-array
   names plus early `.extern X, 16` size hints give retail's `lui`/`lw` for the globals, while
   the sized aliases D_001D9BE0_0038A948 / D_001DA050_g keep the two branch-delay-slot accesses
   in `$gp`; every instruction up to the constant matches word for word); the one difference
   left is the expansion of the 64-bit constant 0xFFFFF30000000000 - the file's flags (default
   assembler) build it as `lui $t0,0xff; ori $t0,$t0,0xfff3; dsll32 $t0,$t0,0` (3 words) while
   retail has SN's Ps2EeAs form `ori $t0,$zero,0xffff; dsll...
*/

/* PAL candidate for func_0038A948 (US draft: rac3-uya-decomp func_00386210).

   Retail reaches most of these globals through `lui`/`lw` and only through
   `$gp` for the accesses that sit in a branch delay slot.  With the default
   assembler a sized scalar is small data (`$gp`), so the `lui` globals get
   their own name plus an early `.extern` size hint of 16, which makes the
   assembler build them with `lui`/`lw` (the macro form) instead; the `$gp`
   ones keep the plain sized names. */

/* localdecomp:start func_0038A948 */
extern s32 D_001D9BDC_l;
__asm__(".extern D_001D9BDC_l, 16");
extern s32 D_001D9BE0_l;
__asm__(".extern D_001D9BE0_l, 16");
extern s32 D_001DA050_l;
__asm__(".extern D_001DA050_l, 16");
extern s32 D_001D4BD0_l;
__asm__(".extern D_001D4BD0_l, 16");
extern s32 D_001D4BD4_l;
__asm__(".extern D_001D4BD4_l, 16");
extern s32 D_001D4BD8_l;
__asm__(".extern D_001D4BD8_l, 16");
extern s32 D_001D4BDC_l;
__asm__(".extern D_001D4BDC_l, 16");
void func_0038A948(void) {
    s32 n, t, n4;
    u8 *r;
    u8 *p;
    u8 *q0;
    u8 *s;
    u8 *u;
    u8 *q;
    if (D_001D9BDC_l != 0) {
        if (D_001D9BE0_0038A948 < 0x34) D_001D9BE0_0038A948 = D_001D9BE0_0038A948 + 1;
    } else {
        if (D_001D9BE0_l == 0) return;
        D_001D9BE0_l = D_001D9BE0_l - 1;
    }
    n = D_001D9BE0_l;
    if (n == 0) return;
    if (D_001439FD[0] != 0) return;
    *(s32 *)(D_001DA050_g + 0) = 0x10000007;
    *(s32 *)(D_001DA050_l + 4) = 0;
    *(s32 *)(D_001DA050_l + 8) = 0;
    *(s32 *)(D_001DA050_l + 0xC) = 0x50000007;
    r = (u8 *)D_001DA050_l;
    D_001DA050_l = (s32)r + 0x10;
    *(u128_t *)(r + 0x10) = *(u128_t *)D_001D76A0;
    *(s16 *)D_001DA050_l = -0x7FFF;
    p = (u8 *)D_001DA050_l;
    q0 = p + 0x10;
    D_001DA050_l = (s32)q0;
    *(long *)(p + 0x10) = 0x104;
    *(long *)(q0 + 8) = 0x80000000UL;
    s = (u8 *)D_001DA050_l;
    D_001DA050_l = (s32)s + 0x10;
    *(u128_t *)(s + 0x10) = *(u128_t *)D_001D76B0;
    *(s16 *)D_001DA050_l = -0x7FF8;
    n4 = n << 4;
    u = (u8 *)D_001DA050_l;
    q = u + 0x10;
    D_001DA050_l = (s32)q;
    *(long *)(u + 0x10) = D_001D4BD0_l | ((long)D_001D4BD4_l << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 8) = D_001D4BD0_l | ((long)(D_001D4BD4_l + n4) << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x10) = D_001D4BD8_l | ((long)D_001D4BD4_l << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x18) = D_001D4BD8_l | ((long)(D_001D4BD4_l + n4) << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x20) = D_001D4BD8_l | ((long)D_001D4BDC_l << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x28) = D_001D4BD8_l | ((long)(D_001D4BDC_l - n4) << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x30) = D_001D4BD0_l | ((long)D_001D4BDC_l << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x38) = D_001D4BD0_l | ((long)(D_001D4BDC_l - n4) << 16) | 0xFFFFF300000000UL;
    D_001DA050_l = D_001DA050_l + 0x40;
}
/* localdecomp:end func_0038A948 */

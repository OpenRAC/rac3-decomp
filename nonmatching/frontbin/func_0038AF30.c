/* US draft of func_0038AF30 (rac3-uya-decomp func_003867F8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0038AF30 */
extern s32 D_001D4BD0_0038AF30;
extern s32 D_001D4BD4_0038AF30;
extern u8 D_001D76A0[];
extern u8 D_001D76B0[];
void func_0038AF30(s32 y0, s32 y1, s32 x0, s32 x1, unsigned long c) {
    u8 *r;
    u8 *p;
    u8 *q;
    u8 *s;
    u8 *t;
    u8 *q0;
    *(s32 *)(D_001DA050 + 0) = 0x10000005;
    *(s32 *)(D_001DA050 + 4) = 0;
    *(s32 *)(D_001DA050 + 8) = 0;
    *(s32 *)(D_001DA050 + 0xC) = 0x50000005;
    r = (u8 *)D_001DA050;
    D_001DA050 = (s32)r + 0x10;
    *(u128_t *)(r + 0x10) = *(u128_t *)D_001D76A0;
    *(s16 *)D_001DA050 = -0x7FFF;
    p = (u8 *)D_001DA050;
    q0 = p + 0x10;
    D_001DA050 = (s32)q0;
    *(long *)(p + 0x10) = 0x144;
    *(unsigned long *)(q0 + 8) = c;
    s = (u8 *)D_001DA050;
    D_001DA050 = (s32)s + 0x10;
    *(u128_t *)(s + 0x10) = *(u128_t *)D_001D76B0;
    *(s16 *)D_001DA050 = -0x7FFC;
    t = (u8 *)D_001DA050;
    q = t + 0x10;
    D_001DA050 = (s32)q;
    *(long *)(t + 0x10) = ((x0 << 4) + D_001D4BD0_0038AF30 - 8) | ((long)((y0 << 4) + D_001D4BD4_0038AF30 - 8) << 16) | 0xFFFFF000000000UL;
    *(long *)(q + 8) = ((x1 << 4) + D_001D4BD0_0038AF30 - 8) | ((long)((y0 << 4) + D_001D4BD4_0038AF30 - 8) << 16) | 0xFFFFF000000000UL;
    *(long *)(q + 0x10) = ((x0 << 4) + D_001D4BD0_0038AF30 - 8) | ((long)((y1 << 4) + D_001D4BD4_0038AF30 - 8) << 16) | 0xFFFFF000000000UL;
    *(long *)(q + 0x18) = ((x1 << 4) + D_001D4BD0_0038AF30 - 8) | ((long)((y1 << 4) + D_001D4BD4_0038AF30 - 8) << 16) | 0xFFFFF000000000UL;
    D_001DA050 = D_001DA050 + 0x20;
}
/* localdecomp:end func_0038AF30 */

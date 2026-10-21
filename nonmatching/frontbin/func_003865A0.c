/* US draft of func_003865A0 (rac3-uya-decomp func_003822C8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003865A0 */
extern u8 *D_001D9D40[];
s32 func_003865A0(s32 a0, s32 a1, s32 a2) {
    u8 *b = D_001D9D40[0];
    u8 *res = b + *(s32 *)b;
    u16 *p = (u16 *)(b + 4);
    s32 y = a2 - p[0];
    s32 x, z;
    if (y < 0 || y >= p[1]) return 0;
    if ((*(volatile u16 *)&p[2 + y]) == 0) return 0;
    p = (u16 *)(b + p[2 + y] * 4);
    x = a1 - p[0];
    if (x < 0 || x >= p[1]) return 0;
    if ((*(volatile u16 *)&p[2 + x]) == 0) return 0;
    p = (u16 *)(b + p[2 + x] * 4);
    z = a0 - p[0];
    if (z < 0 || z >= p[1]) return 0;
    if (p[2 + z] == 0xFFFF) return 0;
    return (s32)(res + (p[2 + z] << 7));
}
/* localdecomp:end func_003865A0 */

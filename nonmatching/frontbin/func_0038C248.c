/* US draft of func_0038C248 (rac3-uya-decomp func_00387B10, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0038C248 */
typedef int u128_387B10 __attribute__((mode(TI)));
extern s32 D_001DA050;
extern u8 D_001D7740[];
void func_0038C248(long *a, s32 *b) {
    u8 *p;
    u8 *q;
    u8 *r;
    *(s32 *)(D_001DA050 + 0) = 0x10000005;
    *(s32 *)(D_001DA050 + 4) = 0;
    *(s32 *)(D_001DA050 + 8) = 0;
    *(s32 *)(D_001DA050 + 0xC) = 0x50000005;
    r = (u8 *)D_001DA050;
    D_001DA050 = (s32)r + 0x10;
    *(u128_387B10 *)(r + 0x10) = *(u128_387B10 *)D_001D7740;
    p = (u8 *)D_001DA050;
    q = p + 0x10;
    D_001DA050 = (s32)q;
    *(long *)(p + 0x10) = 0x4C;
    *(long *)(q + 8) = b[0];
    *(long *)(q + 0x10) = a[0];
    *(long *)(q + 0x18) = a[2];
    *(long *)(q + 0x20) = b[1];
    *(long *)(q + 0x28) = a[1];
    *(long *)(q + 0x30) = a[3];
    *(long *)(q + 0x38) = 0;
    D_001DA050 = D_001DA050 + 0x40;
}
/* localdecomp:end func_0038C248 */

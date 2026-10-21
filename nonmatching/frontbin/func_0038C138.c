/* US draft of func_0038C138 (rac3-uya-decomp func_00387A00, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0038C138 */
typedef int u128_387A00 __attribute__((mode(TI)));
extern s32 D_001DA050;
extern u8 D_001D7770[];
void func_0038C138(long *a, s32 *b, s32 *c, long d, s32 e) {
    u8 *r;
    u8 *p;
    u8 *q;
    *(s32 *)(D_001DA050 + 0) = 0x10000009;
    *(s32 *)(D_001DA050 + 4) = 0;
    *(s32 *)(D_001DA050 + 8) = 0;
    *(s32 *)(D_001DA050 + 0xC) = 0x50000009;
    r = (u8 *)D_001DA050;
    D_001DA050 = (s32)r + 0x10;
    *(u128_387A00 *)(r + 0x10) = *(u128_387A00 *)D_001D7770;
    p = (u8 *)D_001DA050;
    q = p + 0x10;
    D_001DA050 = (s32)q;
    if (e) {
        *(long *)(p + 0x10) = 5;
    } else {
        *(long *)(p + 0x10) = 0;
    }
    *(long *)(q + 8) = d;
    *(long *)(q + 0x10) = 0x154;
    *(long *)(q + 0x18) = c[0];
    *(long *)(q + 0x20) = b[0];
    *(long *)(q + 0x28) = a[0];
    *(long *)(q + 0x30) = c[1];
    *(long *)(q + 0x38) = b[1];
    *(long *)(q + 0x40) = a[1];
    *(long *)(q + 0x48) = c[2];
    *(long *)(q + 0x50) = b[2];
    *(long *)(q + 0x58) = a[2];
    *(long *)(q + 0x60) = c[3];
    *(long *)(q + 0x68) = b[3];
    *(long *)(q + 0x70) = a[3];
    *(long *)(q + 0x78) = 0;
    D_001DA050 = D_001DA050 + 0x80;
}
/* localdecomp:end func_0038C138 */

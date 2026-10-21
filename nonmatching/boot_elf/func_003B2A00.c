/* US draft of func_003B2A00 (rac3-uya-decomp func_003B2860, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003B2A00 */
typedef struct { unsigned long a, b; s32 c, d; } S_3AD0A0;
extern u8 *D_001DA0B4[];
extern void func_003B2590(u8 *, S_3AD0A0 *);
void func_003B2A00(u8 *p, unsigned long a, unsigned long b, s32 c, s32 d) {
    S_3AD0A0 s;
    s.a = a;
    s.b = b;
    s.c = c - *(s32 *)(p + 0x48);
    s.d = d;
    func_003B2590(D_001DA0B4[0] + 0x48, &s);
}
/* localdecomp:end func_003B2A00 */

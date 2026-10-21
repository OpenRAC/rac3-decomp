/* US draft of func_00398498 (rac3-uya-decomp func_003936A8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00398498 */
/* MATCH */
extern u8 D_002FD0F0[];
extern s32 D_002FCE98[];
typedef struct { s32 a, b; } P_3936A8;
extern P_3936A8 D_002FC840[];
extern s32 D_001DA5D4;
extern void func_0038CC88();
void func_00398498(s32 *hdr, s32 base, s32 *src, s32 n) {
    s32 *list = hdr + 4;
    s32 cnt = hdr[0];
    s32 off = hdr[2];
    s32 size = hdr[3];
    s32 i;
    for (i = 0; i < cnt; i++, list++) {
        s32 v = *list;
        if (v == 0) D_002FCE98[i] = (s32)D_002FD0F0;
        else D_002FCE98[i] = v - (off - (s32)D_002FD0F0);
    }
    func_0038CC88(D_002FD0F0, (u8 *)hdr + off, size);
    for (D_001DA5D4 = 0; D_001DA5D4 < n; D_001DA5D4++) {
        s32 a = *src++;
        s32 b = *src++;
        s32 c = *src++;
        s32 d = *src++;
        s32 e;
        __asm__("plzcw %0, %1" : "=r"(e) : "r"(d));
        e = 30 - e;
        D_002FC840[D_001DA5D4].a = ((base + a) << 4) + b;
        D_002FC840[D_001DA5D4].b = ((base + c) << 4) + e;
    }
}
/* localdecomp:end func_00398498 */

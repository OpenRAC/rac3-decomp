/* US draft of func_00396690 (rac3-uya-decomp func_00391E30, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_00396690 */
typedef struct {
    u8 pad[0x84];
    u16 f84;
    u8 pad2[0xF0 - 0x86];
} S_391E30;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern S_391E30 D_001DAA40[];
s32 func_00396690(void) {
    u8 *b = D_001A4BE0;
    s32 r = *(s32 *)(b + 0x1228);
    u8 f = b[0x25E4];
    u8 *q = (u8 *)D_001425C0 + r;
    S_391E30 *t = D_001DAA40;
    if (t[*q].f84 == 0) {
        r = 0;
    }
    if (f != 0) {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_00396690 */

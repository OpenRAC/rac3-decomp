/* US draft of func_00122278 (rac3-uya-decomp func_00122278, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-check-zero-division` (a single-function override). */


/* localdecomp:start func_00122278 */
typedef struct { u8 pad[0x14]; s32 x14; s32 x18; u8 pad2[8]; s32 x24; } S_122278;
s32 func_00122278(S_122278 *p) {
    s32 i = p->x24 % p->x18;
    s32 r = p->x14 + i * 64;
    p->x24 = i + 1;
    return r;
}
/* localdecomp:end func_00122278 */

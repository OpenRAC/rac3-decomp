/* US draft of func_003E6FC0 (rac3-uya-decomp func_003E6E78, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003E6FC0 */
void func_0038CF58(void *, s32, s32);
typedef struct { u8 pad0[0x4]; u8 *f4; } S_001DA9B8_003E16B8;
extern S_001DA9B8_003E16B8 D_001DA938[];
extern u8 D_0031B750[];

void *func_003E6FC0() {
    D_001DA938->f4 = D_0031B750;
    func_0038CF58(D_0031B750 + 0x18, 0, 8);
    func_0038CF58(D_001DA938->f4, 0, 0x14);
    func_0038CF58(D_001DA938->f4 + 0x20, 0, 0x30);
    func_0038CF58(D_001DA938->f4 + 0x50, 0, 0x10);
    func_0038CF58(D_001DA938->f4 + 0x64, 0, 0x10);
    (*(s32 *)((u8 *)(D_001DA938->f4) + 0x60)) = 0;
    (*(s32 *)((u8 *)(D_001DA938->f4) + 0x74)) = 0;
    (*(s32 *)((u8 *)(D_001DA938->f4) + 0x14)) = 0;
    return D_001DA938;
}
/* localdecomp:end func_003E6FC0 */

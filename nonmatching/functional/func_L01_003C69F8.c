/* functional: high. Register allocation only (s-regs swapped) differs from retail; branch, offsets, callee order and args verified against PAL asm. Hero-state/globals names D_001DF95C, D_001A71A0 as retail. */
#include "common.h"
/* localdecomp:start func_L01_003C69F8 */
extern f32 D_L01_001DEC70;
__asm__(".extern D_L01_001DEC70, 4");
extern u8 *D_L01_001E0100_003C69F8;
extern s32 D_L01_001DF95C_003C69F8;
extern s32 D_001A71A0[];
extern f32 func_0038CF00(void *, void *);
extern void func_L01_003C5A78(M3C4E78 *, V3C4E78 *, s32);
extern void func_L01_003C5728(u8 *, u8 *, void *, void *);
extern void func_L01_003C7810(M3C4E78 *, V3C4E78 *, s32, s32, s32);
extern void func_L01_003C5290(M3C4E78 *, V3C4E78 *);
extern void func_L01_003C6EF0(s32, u8 *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003C5CE8(M3C4E78 *, V3C4E78 *);
extern void func_L01_003C5DF0(M3C4E78 *, V3C4E78 *, s32);
extern void func_L01_0043B260(s32);
extern void func_L01_004450F0(M3C4E78 *, s32, s32);
s32 func_L01_003C69F8(M3C4E78 *m) {
    u8 *v = (u8 *)m->pVars;
    s32 *tab = (s32 *)(v + 0x790);
    u8 *node;
    if (tab[*(s32 *)(v + 0x6BC)] == -1) {
        return 0;
    }
    func_L01_003C5A78(m, (V3C4E78 *)v, *(s32 *)(v + 0x6BC));
    node = D_L01_001E0100_003C69F8 + (*(s32 *)(v + 0x770 + *(s32 *)(v + 0x6BC) * 4) << 7);
    if (D_L01_001DEC70 < func_0038CF00((u8 *)m + 0x10, node + 0x30)) {
        func_L01_003C5728((u8 *)m, v, node + 0x30, node + 0x70);
    }
    func_L01_003C7810(m, (V3C4E78 *)v, tab[*(s32 *)(v + 0x6BC)], -1, 0);
    *(s32 *)(v + 0xC8) = 0;
    func_L01_003C5290(m, (V3C4E78 *)v);
    if (*(s32 *)(v + 0xB0) != 2) {
        func_L01_003C6EF0((s32)m, v);
    }
    node = D_L01_001E0100_003C69F8 + (*(s32 *)(v + 0x760 + *(s32 *)(v + 0x6BC) * 4) << 7);
    func_L01_003EB438(0, node + 0x30, node + 0x70, 4, 0, 0);
    func_L01_003C5CE8(m, (V3C4E78 *)v);
    func_L01_003C5DF0(m, (V3C4E78 *)v, 1);
    func_L01_0043B260(D_001A71A0[0]);
    D_L01_001DF95C_003C69F8 = 1;
    func_L01_004450F0(m, 8, -1);
    return 1;
}
/* localdecomp:end func_L01_003C69F8 */

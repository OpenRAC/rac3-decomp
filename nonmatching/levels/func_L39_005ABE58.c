/* PAL near miss (Codex wave 4): held at landing: the C of its NTSC-U twin func_L39_005A9F78, which matches NTSC-U, renamed to PAL names: it matches PAL at level 39 but not at level 40 (1 word differs), so it cannot be the one source of every place.
 * Replaces the earlier draft (rac2-decomp's func_002A0180, ported (7 instructions differ at level 39)).
 */
#include "common.h"
/* localdecomp:start func_L39_005ABE58 */
extern u8 D_L39_0047FB60[];
extern s32 D_L39_0024BB70;
__asm__(".extern D_L39_0024BB70, 16");
extern s32 D_001E0468_sda;

void func_L39_005ABE58(void) {
    extern void func_001264E0(s32);
    extern void func_0038CD28(s32 *, s32 *, s32);
    extern void func_003CB300(s32, s32);
    func_001264E0(0);
    func_0038CD28((s32 *)0x70003800, (s32 *)D_L39_0047FB60, 0x800);
    func_003CB300(D_L39_0024BB70, D_001E0468_sda);
}
/* localdecomp:end func_L39_005ABE58 */

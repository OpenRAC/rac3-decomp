#include "common.h"

/* NTSC-U version of func_003BE770 (boot_elf): 5 -> 6; 250 -> 300 */
/* localdecomp:start func_U_003BE680 */
extern void func_U_003BBCE8(s32, s32);
extern void func_U_0038A5C0(s32);
extern s32 D_U_001DA340;
s32 func_U_003BE680(void) {
    func_U_003BBCE8(0, 0);
    func_U_0038A5C0(6);
    D_U_001DA340 = 300;
    return 1;
}
/* localdecomp:end func_U_003BE680 */

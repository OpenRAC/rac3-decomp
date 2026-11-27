#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_003C3800(void);
extern void func_003C3860(void);
extern void func_003C3780(s32, s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CC88_00391678(void *, void *, s32) __asm__("func_0038CC88");
extern void func_003C3860();
extern int func_003C38E0();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C3780 */
/* func_003C3780: from the US C of func_003BE260 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */
extern void *D_001DA498_003C3780;
extern void *D_001DA498_003C3780_x;
__asm__(".extern D_001DA498_003C3780_x, 16");
extern void func_003A9440(s32, unsigned long);
extern void func_11F0A0(s32);
extern void func_003C3690(void);
extern void *func_003CB3E0(s32, void *, s32, s32);
extern void func_003C3660(void);
void func_003C3780(s32 a0, s32 a1) {
    func_003A9440(0x47, 0x5360B);
    func_11F0A0(0);
    func_003C3690();
    D_001DA498_003C3780 = func_003CB3E0(a0, D_001DA498_003C3780_x, a1, 0);
    func_003C3660();
    D_001DA498_003C3780_x = (u8 *)D_001DA498_003C3780_x - 0x10;
}
/* localdecomp:end func_003C3780 */

/* func_003C3800: retail reaches the word at 0x001DA4E4 and the word at 0x001DA530
   through lui/lw in the destination register, not $gp: the assembler's expansion
   (see func_003C35F0 in this file).
   The pointer compared against &D_002FC1A0 is read from the global D_001DA530
   (through $gp) before the test and re-read after the call in the taken path. */

/* localdecomp:start func_003C3800 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001DA4E4_003C3800;
extern u32 D_001DA530_003C3800;
__asm__(".extern D_001DA4E4_003C3800, 16");
__asm__(".extern D_001DA530_003C3800, 16");
extern void func_003C30C0(void);
extern void func_003C35F0(void);
extern void func_003C3288(void);
extern void func_003C33C8(void);
extern s32 D_001DA4E4[];
extern u8 *D_001DA530;
extern u8 D_002FC1A0[];
void func_003C3800(void) {
    u8 *p;
    func_003C30C0();
    func_003C35F0();
    p = D_001DA530;
    if (D_001DA4E4_003C3800 != 0) {
        func_003C3288();
        p = (u8 *)D_001DA530_003C3800;
    }
    if (p > D_002FC1A0) {
        func_003C33C8();
    }
}
/* localdecomp:end func_003C3800 */

extern void func_003C36C0();
extern void func_003C3800();
s32 func_003CB3E0_003C3860(s32, s32, s32, s32);
extern s32 D_001DA498;
extern s32 D_001DA49C;
extern s32 D_001DA4D4;
/* localdecomp:start func_003C3860 */
extern void func_003C36C0();
extern void func_003C3638();
extern void func_003C3800();
s32 func_003CB3E0_003C3860(s32, s32, s32, s32);
extern s32 D_001DA498;
extern s32 D_001DA49C_003C3860;
__asm__(".extern D_001DA49C_003C3860, 16");
extern s32 D_001DA4D4_003C3860;
__asm__(".extern D_001DA4D4_003C3860, 16");

void func_003C3860(void) {
    s32 var_a3;

    func_003C36C0();
    func_003C3638();
    var_a3 = 1;
    if (D_001DA4D4_003C3860 != 0) {
        D_001DA4D4_003C3860 = 0;
        var_a3 = 3;
    }
    D_001DA498 = func_003CB3E0_003C3860(D_001DA49C_003C3860, D_001DA498, -1, var_a3);
    func_003C3800();
}
/* localdecomp:end func_003C3860 */

LINKER_REMNANT("asm/remnants", func_003C38C0);

extern int D_001DA49C;
extern int D_001DA4A4;
/* localdecomp:start func_003C38E0 */
extern int D_001DA49C;
extern int D_001DA4A4;
/* from rac4-decomp's func_0046D5C0 */
int func_003C38E0(void) {
    int p = D_001DA49C;
    int v;
    for (v = D_001DA4A4; p != D_001DA4A4; p += 0x100) {
        v = *(int *)(p + 0x24);
    }
    return v;
}
/* localdecomp:end func_003C38E0 */

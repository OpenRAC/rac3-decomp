/* Near miss of func_003A0EC0 with its file's own flags: tools/check.py reports 7 diff
   (the version it replaces: 47).
   What differs: 7 words differ, all in the final block: retail loads the counter D_001D6DA4
   into $v1 and computes the D_001D9FD0 table base in $a0, ours does the opposite (counter in
   $a0, base in $v1), which flips the operands of the following sll/addu/addiu/sw. Every
   instruction, every branch target and the whole function prologue now match retail byte for
   byte; only gcc's choice of $v1 vs $a0 for those two values is swapped. Reached by: scalars +
   `.extern X, 16` size hints for D_001D5B90/D_001D5B94/D_001D4CEC (assembler macro lui form,
   high half in the destination register), unsized arrays for...
*/

/* PAL candidate for func_003A0EC0 (frontbin).

   Retail reaches D_001D5B90, D_001D5B94 and D_001D4CEC with the assembler's
   macro form (lui + lw/sw with the high half in the destination register), so
   they are scalars whose size hint keeps the assembler out of $gp; the size
   hints of 4 let D_001D6D9C, D_001D6DA0, D_001D6DA8 and D_001D6DA4 be
   reached through $gp, as retail does.  D_001D5B78, D_001D9FD0 and
   D_001A7430 are unsized arrays, which gcc splits into %hi/%lo. */

extern s32 D_001D5B90_003A0EC0;
extern s32 D_001D5B94_003A0EC0;
extern s32 D_001D4CEC_003A0EC0;
extern u8  D_001D5B78[];
extern s32 D_001D9FD0[];
extern s32 D_001A7430[];
extern s32 D_001D6DA4_003A0EC0;
extern s32 D_001D6D9C_003A0EC0;
extern s32 D_001D6DA0_003A0EC0;
extern s32 D_001D6DA8_003A0EC0;

__asm__(".extern D_001D5B90_003A0EC0, 16");
__asm__(".extern D_001D5B94_003A0EC0, 16");
__asm__(".extern D_001D4CEC_003A0EC0, 16");
__asm__(".extern D_001D6DA4_003A0EC0, 4");
__asm__(".extern D_001D6D9C_003A0EC0, 4");
__asm__(".extern D_001D6DA0_003A0EC0, 4");
__asm__(".extern D_001D6DA8_003A0EC0, 4");

s32 func_003A0EC0(s32 screenId, s32 mode, s32 arg2, s32 arg3, u8 *outPtr) {
    s32 result;
    s32 flag;

    if (outPtr != 0) {
        *outPtr = 0;
    }
    result = (D_001D5B90_003A0EC0 == -2) ? 0 : -1;
    if (mode == 1) {
        result = (D_001D6DA4_003A0EC0 < 8) ? result : -2;
    }
    do {
        flag = 0;
    } while (0);
    if (screenId >= 0) flag = D_001D5B78[screenId];
    if (flag) {
        result = -3;
    }
    if (D_001A7430[0] == 0) {
        if ((D_001D5B94_003A0EC0 != 0) || ((D_001D4CEC_003A0EC0 & 1) == 0)) {
            result = -1;
        }
    }
    if (result == 0) {
        D_001D5B90_003A0EC0 = screenId;
        D_001D6D9C_003A0EC0 = arg2;
        D_001D6DA0_003A0EC0 = arg3;
        D_001D6DA8_003A0EC0 = (s32)outPtr;
        if (mode == 1) {
            D_001D9FD0[D_001D6DA4_003A0EC0++] = D_001D5B94_003A0EC0;
        }
    }
    return result;
}

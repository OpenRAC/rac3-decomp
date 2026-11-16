/* PAL near miss (Codex wave 7): held at landing (0c7bdf5e): the C matches on its own (tools/check.py, every place), but in the level build its .rodata lands at another address than retail's.
 */
#include "common.h"
/* localdecomp:start func_L07_003BCB10 */
void func_L07_003BCB10(void *arg0, s32 arg1) {
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    switch (arg1) {
    case 1: case 2: case 3: case 4: case 5:
    case 6: case 7: case 8: case 9: case 10:
        if (((u8 *)arg0)[0x43] != 0) func_003C3A10(arg0, 0, 0, 7);
        break;
    case 11:
        if (((u8 *)arg0)[0x43] != 1) func_003C3A10(arg0, 1, 0, 7);
        break;
    case 12:
        if (((u8 *)arg0)[0x43] != 3) func_003C3A10(arg0, 3, 0, 7);
        break;
    case 13: case 14:
        if (((u8 *)arg0)[0x43] != 3) func_003C3A10(arg0, 3, 0, 7);
        break;
    }
    func_L01_004450F0(arg0, arg1, -1);
}
/* localdecomp:end func_L07_003BCB10 */

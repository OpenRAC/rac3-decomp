/* PAL near miss (Codex wave 10): near miss: 104 words differ with the file's flags.
 * Worker's note: 96 differing words; fixed default assembler puts eight nontrivial li.s constants in literal pools instead of retail inline lui/ori/mtc1; store scheduling also differs. a01.log; decoded table in .table.txt
 */
#include "common.h"
/* localdecomp:start func_L07_003AEAA0 */
typedef int Quad_003AEAA0 __attribute__((mode(TI)));
void func_L07_003AEAA0(s32 arg0, s32 state) {
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L07_003AF240(void *);
    extern void func_L01_004450F0(void *, s32, s32);
    u8 *obj = (u8 *)arg0;
    u8 *p = *(u8 **)(obj + 0x68);
    switch (state) {
    case 1: break;
    case 2:
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 0);
        break;
    case 3: break;
    case 4:
        *(s32 *)(p + 0x68) |= 0x404;
        *(f32 *)(p + 0x54) = 0.0048f;
        *(f32 *)(p + 0x58) = 0.24000001f;
        *(f32 *)(p + 0x50) = 0.0048f;
        *(u16 *)(obj + 0x34) |= 0x5000;
        *(Quad_003AEAA0 *)(p + 0x260) = *(Quad_003AEAA0 *)(*(u8 **)(p + 0x240) + 0x10);
        *(f32 *)(p + 0x268) = *(f32 *)(obj + 0x18);
        break;
    case 5: break;
    case 6:
        *(s32 *)(p + 0x68) |= 0x414;
        *(f32 *)(p + 0x58) = 0.24000001f;
        *(f32 *)(p + 0x54) = 0.0048f;
        *(f32 *)(p + 0x50) = 0.0048f;
        func_L07_003AF240(obj);
        break;
    case 7:
        *(s32 *)(p + 0x68) = (*(s32 *)(p + 0x68) | 0x404) & ~0x10;
        *(f32 *)(p + 0x54) = 0.024f;
        *(f32 *)(p + 0x58) = 0.6f;
        *(f32 *)(p + 0x50) = 0.024f;
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 2);
        break;
    case 8:
        if (obj[0x43] != 1) func_003C3A10(obj, 1, 0, 2);
        break;
    case 9:
        if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 2);
        *(s16 *)(p + 0x284) = 42;
        break;
    case 10:
        *(f32 *)(p + 0x54) = 0.0016f;
        *(f32 *)(p + 0x58) = 0.060000002f;
        *(f32 *)(p + 0x50) = 0.0016f;
        if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 2);
        break;
    case 11: case 12: case 13: break;
    case 14:
        *(s16 *)(p + 0x284) = 25;
        break;
    }
    func_L01_004450F0(obj, state, -1);
}
/* localdecomp:end func_L07_003AEAA0 */

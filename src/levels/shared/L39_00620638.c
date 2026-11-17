#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00620638);

/* localdecomp:start func_L39_00620AF8 */
typedef struct { u8 pad0[0x1A14]; u8 f1A14; } O_00620AF8;
extern s32 func_L39_006626C8_00620AF8(void *, s32);
extern s32 func_L39_006625A8(void *, s32, s32, s32);
extern void func_L39_00662AA0(s32, void *, s32);

void func_L39_00620AF8(O_00620AF8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 buf;
    s32 h;
    if (arg0->f1A14 != 0) {
        if (arg2 != 0) {
            if (func_L39_006626C8_00620AF8(arg0, 8) == 0) {
                h = func_L39_006625A8(arg0, 8, 0, 0);
                buf = arg1;
                func_L39_00662AA0(h, &buf, 1);
                buf = arg3;
                func_L39_00662AA0(h, &buf, 1);
            }
        } else {
            if (func_L39_006626C8_00620AF8(arg0, 6) == 0) {
                h = func_L39_006625A8(arg0, 6, 0, 0);
                buf = arg1;
                func_L39_00662AA0(h, &buf, 1);
                buf = arg3;
                func_L39_00662AA0(h, &buf, 1);
            }
        }
    }
}
/* localdecomp:end func_L39_00620AF8 */

/* localdecomp:start func_L39_00620BE8 */
void func_L01_00443EA0(s32, s32);

void func_L39_00620BE8(void) {
    func_L01_00443EA0(0x18CB, 0x171C);
    func_L01_00443EA0(0x18CC, 0x171C);
    func_L01_00443EA0(0x18CF, 0x171C);
    func_L01_00443EA0(0x18CD, 0x171C);
    func_L01_00443EA0(0x1ADC, 0x171C);
    func_L01_00443EA0(0x16DB, 0x171C);
    func_L01_00443EA0(0x1CFC, 0x171C);
    func_L01_00443EA0(0x1E68, 0x171C);
    func_L01_00443EA0(0x1E07, 0x171C);
    func_L01_00443EA0(0x1CFB, 0x171C);
    func_L01_00443EA0(0x1E77, 0x171C);
    func_L01_00443EA0(0x1E78, 0x171C);
    func_L01_00443EA0(0x1CFD, 0x171C);
    func_L01_00443EA0(0x1CFE, 0x171C);
    func_L01_00443EA0(0x1E4C, 0x171C);
    func_L01_00443EA0(0x1E65, 0x171C);
    func_L01_00443EA0(0x1E4D, 0x171C);
    func_L01_00443EA0(0x1E69, 0x171C);
    func_L01_00443EA0(0x1E59, 0x171C);
    func_L01_00443EA0(0x1E7A, 0x171C);
    func_L01_00443EA0(0x1E83, 0x171C);
}
/* localdecomp:end func_L39_00620BE8 */

INCLUDE_ASM("asm/levels", func_L39_00620CF8);

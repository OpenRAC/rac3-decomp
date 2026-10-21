#include "common.h"

/* localdecomp:start func_L01_004D7378 */
extern void func_003A9440(s32, unsigned long);
extern void func_L01_004D7378();

extern void func_003CE250(void);
extern void func_003CE1B0(void);
extern void func_003CE2C0(void);
extern s32 D_001A1ED8[];
void func_L01_004D7378(void) {
    func_003CE250();
    func_003CE1B0();
    func_003CE2C0();
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_L01_004D7378 */

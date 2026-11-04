#include "common.h"

typedef struct { u8 p0[8]; s32 w8; } Cfg_0058CE50;

INCLUDE_ASM("asm/levels", func_L39_0058CC68);

/* localdecomp:start func_L39_0058CE50 */
extern Cfg_0058CE50 D_001FC450;
extern void func_003CE250(void);
extern void func_003CE1B0(void);
extern void func_003CE2C0(void);
extern void func_003A9440(s32, unsigned long);

void func_L39_0058CE50(void) {
    func_003CE250();
    func_003CE1B0();
    func_003CE2C0();
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x4E, 0x1000000 | (D_001FC450.w8 >> 13));
}
/* localdecomp:end func_L39_0058CE50 */

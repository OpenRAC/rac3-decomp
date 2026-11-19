#include "common.h"

/* localdecomp:start func_L01_004126A8 */
extern void func_0038E1E8_004126A8();

void func_L01_004126A8(void) {
    func_0038E1E8_004126A8();
}
/* localdecomp:end func_L01_004126A8 */

/* localdecomp:start func_L01_004126C8 */
extern void func_L01_0040FDE0_004126C8(s32);

/* from rac2-decomp's func_0034F3B8, renamed */
void func_L01_004126C8(void) {
    func_L01_0040FDE0_004126C8(1);
}
/* localdecomp:end func_L01_004126C8 */

/* localdecomp:start func_L01_004126E8 */
extern void func_L01_0040FDE0_004126E8();

void func_L01_004126E8(void) {
    func_L01_0040FDE0_004126E8(0);
}
/* localdecomp:end func_L01_004126E8 */

/* localdecomp:start func_L01_00412708 */
extern void func_0038E548_00412708(f32);

void func_L01_00412708(void) {
    func_0038E548_00412708(1.0f);
}
/* localdecomp:end func_L01_00412708 */

LINKER_REMNANT("asm/levels", func_L01_00412730);

/* localdecomp:start func_L01_00412750 */
extern s32 D_L01_001D55E8;
extern void func_0038E150(s32);
extern s32 func_0038E548(u8 *str, s32 len, f32 scale);

s32 func_L01_00412750(u8 *str, s32 len) {
    s32 old = D_L01_001D55E8;
    s32 r;

    func_0038E150(1);
    r = func_0038E548(str, len, 1.0f);
    func_0038E150(old);
    return r;
}
/* localdecomp:end func_L01_00412750 */

LINKER_REMNANT("asm/levels", func_L01_004127B8);

/* localdecomp:start func_L01_004127C0 */
extern void func_0038E548_004127C0();

void func_L01_004127C0(void) {
    func_0038E548_004127C0();
}
/* localdecomp:end func_L01_004127C0 */

LINKER_REMNANT("asm/levels", func_L01_004127E0);

/* localdecomp:start func_L01_004127E8 */
extern void func_0038E548_004127E8();

void func_L01_004127E8(void) {
    func_0038E548_004127E8();
}
/* localdecomp:end func_L01_004127E8 */

LINKER_REMNANT("asm/levels", func_L01_00412808);

/* localdecomp:start func_L01_00412810 */
extern void func_0038E548_00412810();

void func_L01_00412810(void) {
    func_0038E548_00412810();
}
/* localdecomp:end func_L01_00412810 */

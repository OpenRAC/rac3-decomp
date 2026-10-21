#include "common.h"

/* localdecomp:start func_L01_00438D40 */
typedef struct {
    unsigned char id;
    unsigned char pad;
} Slot00435C80;

extern Slot00435C80 D_00143B30[];
extern int func_0039F4B0(Slot00435C80 *p);

Slot00435C80 *func_L01_00438D40(int id)
{
    Slot00435C80 *r = 0;
    int i;

    if (id != -1) {
        for (i = 0; i < 96; i++) {
            if (func_0039F4B0(&D_00143B30[i]) == 0 && D_00143B30[i].id - 1 == id) {
                r = &D_00143B30[i];
                break;
            }
        }
    } else {
        r = &D_00143B30[0];
    }
    return r;
}
/* localdecomp:end func_L01_00438D40 */

INCLUDE_ASM("asm/levels", func_L01_00438DD8);

/* localdecomp:start func_L01_00438E70 */
s32 func_L01_00438E70(void) {
    return 0;
}
/* localdecomp:end func_L01_00438E70 */

/* localdecomp:start func_L01_00438E78 */
s32 func_L01_00438E78(void) {
    return 0;
}
/* localdecomp:end func_L01_00438E78 */

/* localdecomp:start func_L01_00438E80 */
s32 func_L01_00438E80(void) {
    return 0;
}
/* localdecomp:end func_L01_00438E80 */

/* localdecomp:start func_L01_00438E88 */
s32 func_L01_00438E88(s32 a, s32 *b, s32 *c) {
    *b = 0;
    *c = 0;
    return -1;
}
/* localdecomp:end func_L01_00438E88 */

/* localdecomp:start func_L01_00438E98 */
s32 func_L01_00438E98(void) {
    return 0;
}
/* localdecomp:end func_L01_00438E98 */

INCLUDE_ASM("asm/levels", func_L01_00438EA0);

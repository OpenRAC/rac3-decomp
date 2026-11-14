#include "common.h"

/* declared by functions of L39_004DF158.c, which this file was cut from */
extern void *func_L39_004BEED8(s32);

/* localdecomp:start func_L39_004E5090 */
/* from rac4-decomp's func_L00_00520E90 */
typedef struct S_004E5090 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} S_004E5090;

extern S_004E5090 D_L39_0046D330;
extern s32 D_L39_0046D344[];
extern S_004E5090 *func_L39_004E9D70(s32);

S_004E5090 *func_L39_004E5090(void) {
    if (D_L39_0046D344[0] != 0) {
        D_L39_0046D330 = *func_L39_004E9D70(0);
        D_L39_0046D344[0] = 0;
    }
    return &D_L39_0046D330;
}
/* localdecomp:end func_L39_004E5090 */

/* localdecomp:start func_L39_004E5108 */
/* from rac4-decomp's func_L00_00520F08 */
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern s32 func_L39_004E4C68(void *);

s32 func_L39_004E5108(void) {
    void *obj = func_L39_004BEED8(0xC);
    s32 result = 0;

    if (obj != 0) {
        result = func_L39_004E4C68(obj);
        if (result == 0) {
            func_L39_004BEF28(obj);
        }
    }
    return result;
}
/* localdecomp:end func_L39_004E5108 */

/* localdecomp:start func_L39_004E5168 */
void func_L39_004E5168(s32 p) {
    func_L39_004BEF28((void *)p);
}
/* localdecomp:end func_L39_004E5168 */

INCLUDE_ASM("asm/levels", func_L39_004E5170);

LINKER_REMNANT("asm/levels", func_L39_004E51A8);

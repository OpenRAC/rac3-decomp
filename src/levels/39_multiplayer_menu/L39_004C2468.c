#include "common.h"

/* localdecomp:start func_L39_004C2468 */
s32 func_L39_004C2468(void) {
    return 0x23;
}
/* localdecomp:end func_L39_004C2468 */

INCLUDE_ASM("asm/levels", func_L39_004C2470);

INCLUDE_ASM("asm/levels", func_L39_004C24C8);

INCLUDE_ASM("asm/levels", func_L39_004C2588);

INCLUDE_ASM("asm/levels", func_L39_004C2648);

INCLUDE_ASM("asm/levels", func_L39_004C2778);

INCLUDE_ASM("asm/levels", func_L39_004C28F0);

INCLUDE_ASM("asm/levels", func_L39_004C2978);

INCLUDE_ASM("asm/levels", func_L39_004C2C10);

INCLUDE_ASM("asm/levels", func_L39_004C3000);

/* localdecomp:start func_L39_004C3198 */
s32 func_L39_004C3198(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x20) == 0) {
        return 1;
    }
    arg0 = *(u8 **)(arg0 + 0x54);
    if ((s32)(*(long *)arg0 & 1) == 0) {
        *(s32 *)(arg0 + 0x114) = 1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_004C3198 */

INCLUDE_ASM("asm/levels", func_L39_004C31D8);

/* localdecomp:start func_L39_004C3278 */
void func_L39_004C32C8();
s32 func_L39_004C4EF8(void);
void func_L39_004CC7A8();
void func_L39_004DB0D8();
void func_L39_004DB660();
void func_L39_004E4F28(s32);
s32 func_L39_004E9D70(s32);

s32 func_L39_004C3278(void) {
    func_L39_004C4EF8();
    func_L39_004C32C8();
    func_L39_004DB660();
    func_L39_004DB0D8();
    func_L39_004E4F28(func_L39_004E9D70(0));
    func_L39_004CC7A8();
    return 1;
}
/* localdecomp:end func_L39_004C3278 */

INCLUDE_ASM("asm/levels", func_L39_004C32C8);

/* localdecomp:start func_L39_004C33C8 */
void func_L39_004DEB90(void);
s32 func_L39_004E5090(void);
void func_L39_004E5008(s32);
void func_L39_004E0698(s32);
void func_L39_004E09E0(void);
void func_L39_004BC300(void);
s32 func_L39_004C4EF8(void);
void func_L39_004DE280(s32);
void func_L39_004DE050(void);

s32 func_L39_004C33C8(void) {
    func_L39_004DEB90();
    func_L39_004E5008(func_L39_004E5090());
    func_L39_004E0698(-1);
    func_L39_004E09E0();
    func_L39_004BC300();
    func_L39_004C4EF8();
    func_L39_004DE280(0);
    func_L39_004DE050();
    return 1;
}
/* localdecomp:end func_L39_004C33C8 */

INCLUDE_ASM("asm/levels", func_L39_004C3428);

INCLUDE_ASM("asm/levels", func_L39_004C3498);

INCLUDE_ASM("asm/levels", func_L39_004C35C8);

INCLUDE_ASM("asm/levels", func_L39_004C35D8);

#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006AB098);

INCLUDE_ASM("asm/levels", func_L39_006AB300);

INCLUDE_ASM("asm/levels", func_L39_006AB6D0);

/* localdecomp:start func_L39_006AB6F8 */
void func_L39_006AB6F8(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)arg0 + 0x3BC) = arg1;
}
/* localdecomp:end func_L39_006AB6F8 */

INCLUDE_ASM("asm/levels", func_L39_006AB700);

/* localdecomp:start func_L39_006AB778 */
void func_L39_006AB778(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)arg0 + 0x2AB) = arg1;
}
/* localdecomp:end func_L39_006AB778 */

INCLUDE_ASM("asm/levels", func_L39_006AB780);

/* localdecomp:start func_L39_006AB7E0 */
extern void func_L39_006AB098(void *);

void func_L39_006AB7E0(void *arg0, s32 arg1) {
    u8 *buf;
    s32 n;
    u8 c;
    unsigned long sel;

    buf = (u8 *)arg0 + 0x2C8;
    sel = 0;
    c = arg1;
    n = *(s32 *)((u8 *)arg0 + 0x390);
    if (n < *(s32 *)((u8 *)arg0 + 0x394)) {
        if (n > 0) {
            unsigned long b = buf[n - 1];
            sel = b >> 7;
        }
        if (c == 0x20 && (n == 0 || buf[n - 1] == 0x20) && sel == 0) {
            return;
        }
        buf[*(s32 *)((u8 *)arg0 + 0x390)] = c;
        buf[*(s32 *)((u8 *)arg0 + 0x390) + 1] = 0;
        *(s32 *)((u8 *)arg0 + 0x390) = *(s32 *)((u8 *)arg0 + 0x390) + 1;
        if (*(u8 *)((u8 *)arg0 + 0x2A9) != 0) {
            s32 f = *(s32 *)((u8 *)arg0 + 0x2AC);
            *(u8 *)((u8 *)arg0 + 0x2A9) = 0;
            if (f == 1) {
                *(s32 *)((u8 *)arg0 + 0x2AC) = 0;
            }
            *(s32 *)((u8 *)arg0 + 0x2B0) = (*(u8 *)((u8 *)arg0 + 0x2A8) != 0) ? 1 : *(s32 *)((u8 *)arg0 + 0x2AC);
        }
        func_L39_006AB098(arg0);
    }
}
/* localdecomp:end func_L39_006AB7E0 */

INCLUDE_ASM("asm/levels", func_L39_006AB8A8);

INCLUDE_ASM("asm/levels", func_L39_006AB8F8);

INCLUDE_ASM("asm/levels", func_L39_006ABA80);

INCLUDE_ASM("asm/levels", func_L39_006ABBB8);

LINKER_REMNANT("asm/levels", func_L39_006ABC28);

INCLUDE_ASM("asm/levels", func_L39_006ABC38);

LINKER_REMNANT("asm/levels", func_L39_006AC170);

INCLUDE_ASM("asm/levels", func_L39_006AC178);

INCLUDE_ASM("asm/levels", func_L39_006AC1A0);

/* localdecomp:start func_L39_006AC438 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006AC438(void *);

extern void func_L39_0067F168();
void func_L39_006AC438(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006AC438 */

INCLUDE_ASM("asm/levels", func_L39_006AC468);

#include "common.h"

/* localdecomp:start func_L39_004F9B38 */
void func_L39_0050A098(s32, s32, s32, s32);
void func_L39_004F9B38(s32 arg0, s32 arg1) {
    func_L39_0050A098(arg0, arg1, 0x17, 0);
}
/* localdecomp:end func_L39_004F9B38 */

INCLUDE_ASM("asm/levels", func_L39_004F9B58);

INCLUDE_ASM("asm/levels", func_L39_004F9C00);

INCLUDE_ASM("asm/levels", func_L39_004F9E08);

/* localdecomp:start func_L39_004F9F38 */
s32 func_L39_004F9F38(u8 **pp, s32 *outp, long *out, s32 n) {
    u8 *p;
    long v;
    s32 len;
    s32 c;
    s32 c2;
    long c3;

    p = *pp;
    v = 0;
    if (n-- <= 0) {
        return 0;
    }
    c = *p;
    if (c == 0x80) {
        *outp = 1;
        p++;
        goto done;
    }
    *outp = 0;
    c2 = *p++;
    len = c2 & 0x7F;
    if (c2 & 0x80) {
        if ((u32)len >= 9) {
            return 0;
        }
        n--;
        if (n == -1) {
            return 0;
        }
        if (len-- > 0) {
            do {
                v <<= 8;
                c3 = *p++;
                v |= c3;
                n--;
                if (n == -1) {
                    return 0;
                }
            } while (len-- > 0);
        }
    } else {
        v = len;
    }
done:
    if (v >= 0) {
        *pp = p;
        *out = v;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_004F9F38 */

INCLUDE_ASM("asm/levels", func_L39_004F9FF8);

INCLUDE_ASM("asm/levels", func_L39_004FA100);

INCLUDE_ASM("asm/levels", func_L39_004FA1A0);

INCLUDE_ASM("asm/levels", func_L39_004FA228);

INCLUDE_ASM("asm/levels", func_L39_004FA2A8);

INCLUDE_ASM("asm/levels", func_L39_004FA380);

/* localdecomp:start func_L39_004FA460 */
extern void func_L39_004FA480(s32);

void func_L39_004FA460(void) {
    func_L39_004FA480(4);
}
/* localdecomp:end func_L39_004FA460 */

INCLUDE_ASM("asm/levels", func_L39_004FA480);

INCLUDE_ASM("asm/levels", func_L39_004FA4E8);

INCLUDE_ASM("asm/levels", func_L39_004FA538);

INCLUDE_ASM("asm/levels", func_L39_004FA5B0);

INCLUDE_ASM("asm/levels", func_L39_004FA638);

INCLUDE_ASM("asm/levels", func_L39_004FA7F8);

INCLUDE_ASM("asm/levels", func_L39_004FAAB0);

INCLUDE_ASM("asm/levels", func_L39_004FAB48);

INCLUDE_ASM("asm/levels", func_L39_004FAB88);

INCLUDE_ASM("asm/levels", func_L39_004FAC00);

/* localdecomp:start func_L39_004FAC48 */
void func_L39_0050A098(s32, s32, s32, s32);
void func_L39_004FAC48(s32 arg0, s32 arg1) {
    func_L39_0050A098(arg0, arg1, 4, 0);
}
/* localdecomp:end func_L39_004FAC48 */

/* localdecomp:start func_L39_004FAC68 */
extern int func_L39_0050A178(int, int, int, int, int);
extern void func_L39_004BC6C8(int, int, int, int, int);
int func_L39_004FAC68(int a0, int a1, int a2)
{
    if (func_L39_0050A178(a0, a1, a2, 4, 0) == 0) {
        func_L39_004BC6C8(0xD, 0x82, 4, 0, 0);
        return 0;
    }
}
/* localdecomp:end func_L39_004FAC68 */

INCLUDE_ASM("asm/levels", func_L39_004FACB0);

INCLUDE_ASM("asm/levels", func_L39_004FADD8);

INCLUDE_ASM("asm/levels", func_L39_004FB050);

INCLUDE_ASM("asm/levels", func_L39_004FB2A0);

INCLUDE_ASM("asm/levels", func_L39_004FB5C8);

INCLUDE_ASM("asm/levels", func_L39_004FB620);

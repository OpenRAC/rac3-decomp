#include "common.h"

/* localdecomp:start func_L39_004F9FF8 */
extern void func_L39_004FA100(u8 **pp, s32 length);

/* OpenSSL ASN1_put_object */
void func_L39_004F9FF8(u8 **pp, s32 constructed, s32 length, s32 tag, s32 xclass) {
    u8 *p = *pp;
    s32 i;

    i = (constructed) ? 0x20 : 0;
    i |= (xclass & 0xC0);
    if (tag < 31) {
        *(p++) = i | (tag & 0x1F);
    } else {
        *(p++) = i | 0x1F;
        while (tag > 0x7F) {
            *(p++) = (tag & 0x7F) | 0x80;
            tag >>= 7;
        }
        *(p++) = (tag & 0x7F);
    }
    if (constructed == 2 && length == 0) {
        *(p++) = 0x80;
    } else {
        func_L39_004FA100(&p, length);
    }
    *pp = p;
}
/* localdecomp:end func_L39_004F9FF8 */

INCLUDE_ASM("asm/levels", func_L39_004FA100);

INCLUDE_ASM("asm/levels", func_L39_004FA1A0);

INCLUDE_ASM("asm/levels", func_L39_004FA228);

INCLUDE_ASM("asm/levels", func_L39_004FA2A8);

INCLUDE_ASM("asm/levels", func_L39_004FA380);

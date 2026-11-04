#include "common.h"

/* localdecomp:start func_L01_00443EA0 */
extern u8 D_L01_001FDBD0[];
extern u8 *D_L01_001FD180[];

void func_L01_00443EA0(s32 a0, s32 a1) {
    u8 *src;
    u8 *dst;
    s32 i;

    if (a0 == a1) {
        return;
    }
    src = D_L01_001FD180[D_L01_001FDBD0[a1]];
    dst = D_L01_001FD180[D_L01_001FDBD0[a0]];
    dst[0xC] = src[0xC];
    dst[0xA] = src[0xA];
    dst[0xD] = src[0xD];
    *(s32 *)(dst + 0x18) = *(s32 *)(src + 0x18);
    *(s32 *)(dst + 0x1C) = *(s32 *)(src + 0x1C);
    *(s32 *)(dst + 0x28) = *(s32 *)(src + 0x28);
    i = 0;
    if (src[0xC] != 0) {
        s32 *d;
        s32 *s;

        d = (s32 *)(dst + 0x48);
        s = (s32 *)(src + 0x48);
        do {
            *d = *s;
            i++;
            s++;
            d++;
        } while (i < src[0xC]);
    }
}
/* localdecomp:end func_L01_00443EA0 */

/* localdecomp:start func_L01_00443F50 */
s32 func_L01_00443F50(s32 a0) {
    s32 r = 0;
    if (a0 != 22 && a0 != 167 && a0 != 192 && a0 != 193 && a0 != 194 && a0 != 195 && a0 != 196 && a0 != 111 && a0 != 87) {
        r = a0 != 151;
    }
    return r;
}
/* localdecomp:end func_L01_00443F50 */

INCLUDE_ASM("asm/levels", func_L01_00443FB0);

/* localdecomp:start func_L01_00444200 */
extern s32 func_L01_0041A4F0(void);
extern void func_003E54E0(s32 a);
extern u8 D_00142660[];

void func_L01_00444200(void)
{
    u8 *q;

    if (func_L01_0041A4F0() != 0) {
        q = D_00142660;
        if (q[0x5A] + 1 < 0x14) {
            q[0x5B] = q[0x5B] + 1;
            if (((q[0x5B] & 0xFF) << 1) >= q[0x5A] + 1) {
                func_003E54E0(0x96);
                q[0x5B] = 0;
                q[0x5A] = q[0x5A] + 1;
            }
        }
    }
}
/* localdecomp:end func_L01_00444200 */

INCLUDE_ASM("asm/levels", func_L01_00444288);

INCLUDE_ASM("asm/levels", func_L01_00444350);

INCLUDE_ASM("asm/levels", func_L01_004443E8);

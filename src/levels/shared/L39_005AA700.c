#include "common.h"

/* localdecomp:start func_L39_005AA700 */
extern u8 D_001FE020[];
extern void func_L39_005F3088(int);
extern int func_L39_005F33E0(int, int, char *);

void func_L39_005AA700(void *object)
{
    u8 *s = (u8 *)object;
    if (s[0x6D] != 0xFF) {
        u8 *e = D_001FE020 + s[0x6D] * 0x80;
        if (*(int *)(e + 0xDC) != (int)s) {
            s[0x6D] = 0xFF;
        } else if (*(short *)(e + 0xCA) != s[0x6C] ||
                   (*(unsigned short *)(s + 0x34) & 0x40) != 0 ||
                   (*(unsigned short *)(s + 0x7C) & 0x8000) != 0) {
            func_L39_005F3088(s[0x6D]);
            s[0x6D] = 0xFF;
        }
    } else if (s[0x6C] != 0xFF &&
               (*(unsigned short *)(s + 0x34) & 0x40) == 0 &&
               (*(long *)(s + 0x78) & 0x0004800000000000L) == 0) {
        s[0x6D] = (u8)func_L39_005F33E0(s[0x6C], 4, (char *)s);
    }
}
/* localdecomp:end func_L39_005AA700 */

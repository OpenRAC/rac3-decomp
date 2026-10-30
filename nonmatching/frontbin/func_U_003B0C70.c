#include "common.h"


/* localdecomp:start func_U_003B0C70 */
extern s32 D_001D5520;
extern s32 D_U_001D89E0;
extern s32 D_U_001D8A14;
extern char D_U_0037B6D0[];
extern s32 D_001D5520_003B0C70[] __asm__("D_001D5520");

extern char *func_U_0037DF98(s32 id);
extern s32 func_0011B2E8(char *dest, const char *format, ...);
extern void func_U_003B0F58(void);
extern s32 func_U_003B4220(
    s32 type,
    const char *first,
    const char *second,
    const char *message,
    s32 flags);
extern void func_U_003B41F8(s32 first, s32 second);

void func_U_003B0C70(void)
{
        long mode;
    char *first;
    char *second;

    do {
        mode = D_001D5520_003B0C70[0];
    } while (0);

    if (mode != 0) {
        D_001D5520 = (mode == 0);
        func_U_003B0F58();
    } else {
        func_0011B2E8(
            D_U_0037B6D0,
            func_U_0037DF98(0x50A),
            D_U_001D89E0);

        first = func_U_0037DF98(0x8E2);
        second = func_U_0037DF98(0x8DF);

        func_U_003B4220(0, first, second, D_U_0037B6D0, 0);
        func_U_003B41F8(0x40, 0x10);
        D_U_001D8A14 = 1;
    }
}

/* localdecomp:end func_U_003B0C70 */

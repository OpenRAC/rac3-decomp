#include "common.h"

/* localdecomp:start func_U_003B6430 */
extern s32 D_001D5520;
extern s32 D_U_001D89E0;
extern s32 D_U_001D8A14;
extern char D_U_0037F710[];
/* This alias keeps the absolute load separate from the GP-relative store. */
extern s32 D_001D5520_003B6430[] __attribute__((section(".sdata")));

extern char *func_U_003823F0(s32 id);
extern s32 func_0011B2E8(char *dest, const char *format, ...);
extern void func_U_003B6718(void);
extern s32 func_U_003B99E0(
    s32 type,
    const char *first,
    const char *second,
    const char *message,
    s32 flags);
extern void func_U_003B99B8(s32 first, s32 second);

void func_U_003B6430(void)
{
    long mode;
    char *first;
    char *second;

    mode = D_001D5520_003B6430[0];

    if (mode != 0) {
        D_001D5520 = (mode == 0);
        func_U_003B6718();
    } else {
        func_0011B2E8(
            D_U_0037F710,
            func_U_003823F0(0x50A),
            D_U_001D89E0);

        first = func_U_003823F0(0x8E2);
        second = func_U_003823F0(0x8DF);

        func_U_003B99E0(0, first, second, D_U_0037F710, 0);
        func_U_003B99B8(0x40, 0x10);
        D_U_001D8A14 = 1;
    }
}
/* localdecomp:end func_U_003B6430 */

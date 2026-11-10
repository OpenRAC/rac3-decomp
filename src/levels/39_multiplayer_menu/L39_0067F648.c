#include "common.h"

typedef struct S_0067EF00 {
    s32 f0;
    s32 f4;
    s32 f8;
} S_0067EF00;

/* localdecomp:start func_L39_0067F648 */
typedef struct E_0067F648 { char b[0x70]; } E_0067F648;
extern s32 D_L39_0024D770;
extern s32 D_L39_0024D7A8;
extern void *D_L39_0024D778;
extern E_0067F648 D_L39_003D2140[12];
char *func_00120D28(char *, const char *, s32);

void func_L39_0067F648(void *arg0, const char *arg1) {
    if (D_L39_0024D770 < 12) {
        (&D_L39_0024D778)[D_L39_0024D770] = arg0;
        func_00120D28(D_L39_003D2140[D_L39_0024D770].b, arg1, 0x6F);
        D_L39_003D2140[D_L39_0024D770].b[0x6F] = 0;
        D_L39_0024D770++;
        D_L39_0024D7A8++;
    }
}
/* localdecomp:end func_L39_0067F648 */

INCLUDE_ASM("asm/levels", func_L39_0067F6E8);

INCLUDE_ASM("asm/levels", func_L39_0067F7B0);

#include "common.h"

typedef void (*FnVt_006C7F08)(void *, s32, s32);

INCLUDE_ASM("asm/levels", func_L39_006C69C0);

INCLUDE_ASM("asm/levels", func_L39_006C6B30);

INCLUDE_ASM("asm/levels", func_L39_006C7128);

INCLUDE_ASM("asm/levels", func_L39_006C7800);

/* localdecomp:start func_L39_006C7B40 */
typedef struct { s32 a, b, c, type; } S_006C7B40;
extern S_006C7B40 D_L39_004B1768[][25];
extern f32 D_001A6A24 __attribute__((section(".data")));
extern char D_002497E8[];
extern char D_002497F0[];
extern char D_002497F8[];
s32 func_001321C8(f32);
s32 func_00120048(char *, const char *, ...);

void func_L39_006C7B40(u8 *arg0, char *buf, s32 value, s32 arg3) {
    s32 type = D_L39_004B1768[*(s32 *)(arg0 + 0xD4C)][*(s32 *)(arg0 + 0xB64)].type;

    if (type == 1) {
        func_00120048(buf, D_002497F0, func_001321C8(value / D_001A6A24));
    } else if (type == 2) {
        func_00120048(buf, D_002497E8, arg3);
    } else if (value > 99999) {
        value = (value + 500) / 1000;
        func_00120048(buf, D_002497F8, value);
    } else {
        func_00120048(buf, D_002497E8, value);
    }
}
/* localdecomp:end func_L39_006C7B40 */

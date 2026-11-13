#include "common.h"

/* NTSC-U counterpart of func_L39_006C7B40 (src/levels/39_multiplayer_menu/L39_006C69C0.c) */
/* localdecomp:start func_L39_006C5050 */
typedef struct { s32 a, b, c, type; } S_006C7B40;
extern S_006C7B40 D_L39_004B1598[][25];
extern f32 D_001A6BA4 __attribute__((section(".data")));
extern char D_L39_00249930[];
extern char D_L39_00249938[];
extern char D_L39_00249940[];
s32 func_001321C8(f32);
s32 func_00120048(char *, const char *, ...);

void func_L39_006C5050(u8 *arg0, char *buf, s32 value, s32 arg3) {
    s32 type = D_L39_004B1598[*(s32 *)(arg0 + 0xD4C)][*(s32 *)(arg0 + 0xB64)].type;

    if (type == 1) {
        func_00120048(buf, D_L39_00249938, func_001321C8(value / D_001A6BA4));
    } else if (type == 2) {
        func_00120048(buf, D_L39_00249930, arg3);
    } else if (value > 99999) {
        value = (value + 500) / 1000;
        func_00120048(buf, D_L39_00249940, value);
    } else {
        func_00120048(buf, D_L39_00249930, value);
    }
}
/* localdecomp:end func_L39_006C5050 */

#include "common.h"

/* declared by functions of L39_0066C808.c, which this file was cut from */
typedef struct {
    char pad0[0x44];
    union {
        u8 b;
        s32 w;
    } team;
    char pad48[0x50 - 0x48];
    u8 unk50;
} Obj;

/* localdecomp:start func_L39_0066D938 */
typedef struct {
    s32 pad0;
    s32 f4;
    u8 pad8[0x2C];
    s32 f34;
    u8 pad38[0x18];
    u8 f50;
} S_0066D938;
typedef struct {
    s32 pad[2];
    s32 f8;
} G_0066D938;
extern void func_L39_0061E1B8(S_0066D938 *, s32);
extern G_0066D938 D_001A5CD0;

void func_L39_0066D938(S_0066D938 *arg0, u8 arg1, u8 arg2) {
    if (func_L39_0066D888((Obj *)arg0, arg1, arg2) != 0) {
        arg0->f50 = arg1;
        if (arg0->f34 != D_001A5CD0.f8) {
            arg0->f34 = D_001A5CD0.f8;
            arg0->f4 = D_001A5CD0.f8;
            func_L39_0061E1B8(arg0, 0);
        }
    }
}
/* localdecomp:end func_L39_0066D938 */

INCLUDE_ASM("asm/levels", func_L39_0066D9A8);

INCLUDE_ASM("asm/levels", func_L39_0066DA10);

#include "common.h"

/* NTSC-U counterpart of func_L39_0066D938 (src/levels/shared/L39_0066D938.c) */
typedef struct {
    char pad0[0x44];
    union {
        u8 b;
        s32 w;
    } team;
    char pad48[0x50 - 0x48];
    u8 unk50;
} Obj;

/* localdecomp:start func_L39_0066B030 */
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
extern void func_L39_0061BA40(S_0066D938 *, s32);
extern G_0066D938 D_001A5E50;

void func_L39_0066B030(S_0066D938 *arg0, u8 arg1, u8 arg2) {
    if (func_L39_0066AF80((Obj *)arg0, arg1, arg2) != 0) {
        arg0->f50 = arg1;
        if (arg0->f34 != D_001A5E50.f8) {
            arg0->f34 = D_001A5E50.f8;
            arg0->f4 = D_001A5E50.f8;
            func_L39_0061BA40(arg0, 0);
        }
    }
}
/* localdecomp:end func_L39_0066B030 */

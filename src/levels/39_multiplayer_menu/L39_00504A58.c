#include "common.h"

typedef struct S_00504410 {
    u8 pad[0x20];
    u8 *f20;
    void (*f24)(void);
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} S_00504410;

/* localdecomp:start func_L39_00504A58 */
typedef struct {
    u8 pad[0x1C];
    s32 f1C;
} S_00504A58_B;

typedef struct {
    S_00504A58_B *f0;
    u8 pad4[0x74 - 0x4];
    s32 f74;
    void *f78;
    u8 pad7C[0x80 - 0x7C];
    s32 f80;
    u8 pad84[0x88 - 0x84];
    s64 f88;
} S_00504A58;

extern void *func_0011D534(void *, s32, s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);

s32 func_L39_00504A58(S_00504A58 *arg0, S_00504A58_B *arg1) {
    if (arg0->f0 != 0) {
        if (arg0->f78 != 0) {
            func_0011D534(arg0->f78, 0, arg0->f74);
        }
        if (arg1 == 0 || arg0->f74 != arg1->f1C) {
            func_L39_004BEF28(arg0->f78);
            arg0->f78 = 0;
        }
    }
    if (arg1 != 0 && arg0->f78 == 0 && arg1->f1C > 0) {
        arg0->f78 = func_L39_004BEED8(arg1->f1C);
        if (arg0->f78 == 0) {
            func_L39_004BC6C8(6, 0x6E, 0x21, 0, 0);
            return 0;
        }
    }
    if (arg1 != 0) {
        arg0->f74 = arg1->f1C;
        if (arg1->f1C > 0) {
            func_0011D534(arg0->f78, 0, arg1->f1C);
        }
        arg0->f0 = arg1;
    }
    arg0->f80 = 0;
    arg0->f88 = 0;
    return 1;
}
/* localdecomp:end func_L39_00504A58 */

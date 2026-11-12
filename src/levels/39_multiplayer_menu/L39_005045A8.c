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

/* localdecomp:start func_L39_005045A8 */
typedef struct Type1 {
    s32 f0;
    s32 f4;
    char _p8[0x58 - 0x8];
    s32 f58;
    s32 f5C;
} Type1;

/* from rac4-decomp's func_L00_005403B8, renamed */
void func_L39_005045A8(Type1 *arg0) {
    arg0->f5C = 0;
    arg0->f0 = 0;
    arg0->f58 = 0;
    arg0->f4 = 30;
}
/* localdecomp:end func_L39_005045A8 */

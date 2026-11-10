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

/* localdecomp:start func_L39_00504A30 */
typedef struct S_504A30_B S_504A30_B;
typedef struct {
    char _p0[0x14];
    void (*f14)(S_504A30_B *arg0);
} S_504A30_A;
struct S_504A30_B {
    S_504A30_A *f0;
};

/* from rac4-decomp's func_L00_0051EE28 */
void func_L39_00504A30(S_504A30_B *arg0) {
    arg0->f0->f14(arg0);
}
/* localdecomp:end func_L39_00504A30 */

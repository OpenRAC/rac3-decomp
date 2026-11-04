#include "common.h"

typedef struct Handles_0045E798 {
    u8 pad0[0x90];
    u32 handles[4];
} Handles_0045E798;
typedef struct Table_0045E798 {
    u8 pad0[0x79A4];
    s32 base;
    u8 pad1[0x40];
    s32 entries[1][2];
} Table_0045E798;

/* localdecomp:start func_L01_0045E798 */
extern Handles_0045E798 D_1A30B0;
extern Table_0045E798 D_160C40;
extern void func_13BF00(s32);
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_13BED0(void);
extern s32 func_13B918(s32, s32);

void func_L01_0045E798(int index)
{
    int i;
    int address;
    for (i = 0; i < 3; i++) {
        Handles_0045E798 *rs = &D_1A30B0;
        u32 *handle = &rs->handles[i + 1];
        if (*handle != 0) {
            func_13BF00(*handle);
            *handle = 0;
        }
    }
    func_13CA28();
    while (func_13B620() != 0) { }
    func_13BED0();
    while (func_13B620() != 0) { }
    address = D_160C40.entries[index][0];
    if (address != 0) {
        address += D_160C40.base;
        D_1A30B0.handles[index + 1] = 0xFFFFFFFF;
        D_1A30B0.handles[index + 1] = func_13B918(address, 0);
    }
    func_13BED0();
}
/* localdecomp:end func_L01_0045E798 */

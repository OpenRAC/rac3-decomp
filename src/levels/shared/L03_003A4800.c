#include "common.h"

/* localdecomp:start func_L03_003A4800 */
typedef struct {
    u8 pad0[0x234];
    s32 f234;
    u8 pad238[0x25F2 - 0x238];
    u8 f25F2;
    u8 pad25F3[0x28C9 - 0x25F3];
    u8 f28C9;
    u8 pad28CA[2];
    void *f28CC;
} H_003A4800;
typedef struct {
    u8 pad0[0x40];
    u16 f40;
    u8 pad42[0x78 - 0x42];
    u16 f78;
} G_003A4800;
extern H_003A4800 D_001A4BE0;
extern G_003A4800 D_00142660;
extern u8 *D_L03_001DE520;
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0041A7D0(void);
extern void func_0038A238(s32);
extern void func_L01_00425978(s32);
extern void func_003C2880(void *);

void func_L03_003A4800(u8 *m) {
    if (m[0x20] == 0) {
        D_L03_001DE520 = m;
        func_L01_004450F0(m, 1, -1);
    }
    if (m[0x20] == 2) {
        func_L01_0041A7D0();
        func_0038A238(0xD);
        if (D_001A4BE0.f234 != 0) {
            D_00142660.f40 = D_00142660.f78;
            func_L01_00425978((s16)D_00142660.f78);
            D_001A4BE0.f28C9 = 0;
            if (D_001A4BE0.f28CC != 0) {
                func_003C2880(D_001A4BE0.f28CC);
                D_001A4BE0.f28CC = 0;
            }
        }
        D_001A4BE0.f25F2 = 1;
        func_L01_004450F0(m, 1, -1);
    }
}
/* localdecomp:end func_L03_003A4800 */

/* localdecomp:start func_L03_003A48D0 */
extern u8 *D_L03_001DE520;

void func_L03_003A48D0(void) {
    D_L03_001DE520[32] = 2;
}
/* localdecomp:end func_L03_003A48D0 */

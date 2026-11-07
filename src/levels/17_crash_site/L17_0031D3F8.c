#include "common.h"

/* localdecomp:start func_L17_0031D3F8 */
typedef struct { s32 f0; } S_D3F8_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0xF]; u8 b30; u8 p31[0x37]; S_D3F8_D *f68; } S_D3F8_O;
extern void func_L01_004450F0(S_D3F8_O *, s32, s32);
void func_L17_0031D3F8(S_D3F8_O *a0) {
    S_D3F8_O *p = a0;
    S_D3F8_D *d = p->f68;
    if (p->b20 == 0) {
        p->b30 = 0xFF;
        d->f0 = 0;
        func_L01_004450F0(a0, 1, -1);
    }
}
/* localdecomp:end func_L17_0031D3F8 */

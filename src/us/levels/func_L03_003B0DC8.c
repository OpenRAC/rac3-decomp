#include "common.h"

/* localdecomp:start func_L03_003B0DC8 */
typedef struct {
    u8 p0[0x128];
    s32 f128;
    s32 f12C;
} S_L03_003B0DC8;

extern u8 D_00142CBE[];
__asm__(".extern D_00142CBE, 16");
extern s32 D_L03_001D6694_003B0DC8;
extern s32 func_L01_00452EC8(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BD360(void *);
extern s32 func_0037E208(s32, s32);
extern s32 func_00388398(void *);
extern s32 func_L01_004B6C68(void);
extern void func_L03_003B1000(void *);

void func_L03_003B0DC8(u8 *a) {
    S_L03_003B0DC8 *s = *(S_L03_003B0DC8 **)(a + 0x68);
    switch (a[0x20]) {
    case 0:
        if (s->f12C != 0 || D_00142CBE[0] == 0) {
            if (a[0x43] != 1) func_003BE4F0(a, 1, 0, 10);
            func_L01_00441FB8(a, 2, -1);
        } else {
            func_003BD360(a);
            return;
        }
    case 2:
        if (func_L01_00452EC8(a) != 0) {
            if (a[0x43] != 1) func_003BE4F0(a, 1, 0, 10);
            s->f128 = func_0037E208(0x226, 0x352);
        }
        if (func_00388398(&s->f128) != 0) {
            s->f128 = func_0037E208(0x226, 0x352);
            if (a[0x43] != 2) func_003BE4F0(a, 2, 0, 20);
        } else if ((a[0x60] & 2) != 0) {
            if (a[0x43] != 1) func_003BE4F0(a, 1, 0, 20);
        }
        break;
    case 4:
        if (func_L01_00452EC8(a) != 0 && a[0x43] != 3) func_003BE4F0(a, 3, 0, 10);
        break;
    case 3:
        if (func_L01_00452EC8(a) != 0 && a[0x43] != 4) func_003BE4F0(a, 4, 0, 10);
        break;
    case 5:
        if (func_L01_00452EC8(a) != 0 && a[0x43] != 5) func_003BE4F0(a, 5, 0, 10);
        break;
    }
    if (D_L03_001D6694_003B0DC8 == 2) {
        a[0x31] = 0;
        *(u16 *)(a + 0x34) |= 1;
    } else {
        if (func_L01_004B6C68() == 0) {
            a[0x31] = 1;
            *(u16 *)(a + 0x34) &= 0xFFFE;
        }
        func_L03_003B1000(a);
    }
}
/* localdecomp:end func_L03_003B0DC8 */

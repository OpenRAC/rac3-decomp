#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 p0[0x3D]; u8 b3D; u8 p3E[0x85 - 0x3E]; u8 b85; } S_1426E0_3B03A8;
typedef struct { u8 p0[0x1E]; u8 b1E; } S_142CA0_3B03A8;
typedef struct { u8 p0[0x114]; s32 f114; u8 p118[8]; s32 f120; u8 p124[8]; s32 f12C; } S_3B03A8;

extern s32 func_L01_004B6C68();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BD360(void *);
extern s32 func_00388398(void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_0037E208(s32, s32);
extern void func_L03_003B06A0(void *);
extern void func_L03_003B0A38(void *);

/* localdecomp:start func_L03_003B03A8 */
extern s32 D_L03_001D6694_003B03A8;
__asm__(".extern D_L03_001D6694_003B03A8, 16");
extern char *D_L03_001DFB00_003B03A8;
__asm__(".extern D_L03_001DFB00_003B03A8, 16");
extern S_1426E0_3B03A8 D_001426E0;
extern S_142CA0_3B03A8 D_00142CA0;

void func_L03_003B03A8(u8 *a) {
    S_3B03A8 *s = *(S_3B03A8 **)(a + 0x68);

    if (D_L03_001D6694_003B03A8 == 2) {
        a[0x31] = 0;
        *(u16 *)(a + 0x34) |= 1;
        return;
    }
    if (func_L01_004B6C68() == 0) {
        a[0x31] = 1;
        *(u16 *)(a + 0x34) &= 0xFFFE;
    }
    switch (a[0x20]) {
    case 0:
        if (D_001426E0.b3D != 0 && D_001426E0.b85 == 0) {
            char *e = D_L03_001DFB00_003B03A8 + (s->f120 << 7);
            *(u128_t *)(a + 0x10) = *(u128_t *)(e + 0x30);
            *(u128_t *)(a + 0xF0) = *(u128_t *)(e + 0x70);
            if (a[0x43] != 0) {
                func_003BE4F0(a, 0, 0, 10);
            }
            func_L01_00441FB8(a, 1, -1);
        } else if (D_00142CA0.b1E != 0) {
            if (a[0x43] != 1) {
                func_003BE4F0(a, 1, 0, 10);
            }
            func_L01_00441FB8(a, 2, -1);
        } else {
            func_003BD360(a);
            return;
        }
        break;
    case 2:
        if (func_L01_00452EC8(a) != 0) {
            if (a[0x43] != 1) {
                func_003BE4F0(a, 1, 0, 10);
            }
            s->f12C = func_0037E208(600, 800);
        }
        if (s->f114 == 0) {
            if (func_00388398(&s->f12C) != 0) {
                s->f12C = func_0037E208(600, 800);
                if (a[0x43] != 2) {
                    func_003BE4F0(a, 2, 0, 0x14);
                }
            }
        }
        if ((a[0x60] & 2) != 0) {
            if (a[0x43] != 1) {
                func_003BE4F0(a, 1, 0, 0x14);
            }
        }
        break;
    case 3:
        if (func_L01_00452EC8(a) != 0) {
            if (a[0x43] != 3) {
                func_003BE4F0(a, 3, 0, 10);
            }
        }
        break;
    case 4:
        if (func_L01_00452EC8(a) != 0) {
            if (a[0x43] != 4) {
                func_003BE4F0(a, 4, 0, 10);
            }
        }
        break;
    case 5:
        if (func_L01_00452EC8(a) != 0) {
            if (a[0x43] != 5) {
                func_003BE4F0(a, 5, 0, 10);
            }
        }
        break;
    }
    func_L03_003B06A0(a);
    if (D_00142CA0.b1E != 0 && a[0x20] != 1) {
        func_L03_003B0A38(a);
    }
}
/* localdecomp:end func_L03_003B03A8 */

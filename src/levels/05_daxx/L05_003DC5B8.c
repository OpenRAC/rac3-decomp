#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003DC5B8);

INCLUDE_ASM("asm/levels", func_L05_003DC798);

/* localdecomp:start func_L05_003DC900 */
typedef struct {
    char pad0[0x20];
    u8 f20;
    char pad1[0x75];
    u16 f96;
} S_3DC900;

void func_L05_003DC5B8(S_3DC900 *p, s32 a, s32 b, f32 c);
void func_L05_003DC798(S_3DC900 *p, f32 c);
s32 func_L01_00447490(S_3DC900 *p, s32 a, s32 b);
void func_L01_004450F0(S_3DC900 *p, s32 a, s32 b);
void func_003C2880(S_3DC900 *p);

void func_L05_003DC900(S_3DC900 *p) {
    switch (p->f20) {
    case 0:
        if (func_L01_00447490(p, -1, 0) != 0) {
            func_L05_003DC5B8(p, 0x1FF, 0x1EA7, 7.5f);
            func_L01_004450F0(p, 2, -1);
        }
        break;
    case 1: {
        s32 v = p->f96 + 1;
        p->f96 = v;
        if ((u16)v >= 0x1E) {
            func_L01_004450F0(p, 2, -1);
        }
        break;
    }
    case 2:
        func_L05_003DC798(p, 7.5f);
        func_L01_004450F0(p, 3, -1);
        break;
    case 3:
        func_003C2880(p);
        break;
    }
}
/* localdecomp:end func_L05_003DC900 */

INCLUDE_ASM("asm/levels", func_L05_003DC9E8);

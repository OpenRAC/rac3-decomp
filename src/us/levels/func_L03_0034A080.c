#include "common.h"

/* NTSC-U counterpart of func_L03_0034AC40 (src/levels/shared/L03_0034A2C0.c): 120 (60 Hz) for 100 in the func_L01_003E9588 call */
/* localdecomp:start func_L03_0034A080 */
typedef int q128 __attribute__((mode(TI)));

typedef struct {
    char pad0[0x150];
    q128 unk150;
    char pad160[0x190 - 0x160];
    q128 unk190;
    char pad1A0[0x300 - 0x1A0];
    q128 unk300;
    char pad310[0x940 - 0x310];
    q128 unk940;
} Vars;

typedef struct {
    char pad0[0x10];
    q128 pos;
    char pad20[0x34 - 0x20];
    u16 flags;
    char pad36[0x68 - 0x36];
    Vars *vars;
    char pad6C[0xA8 - 0x6C];
    u8 unkA8;
    char padA9[0xAA - 0xA9];
    s16 oClass;
} Moby;
extern u8 D_001426E0[];
extern s32 func_L01_00452EC8(u8 *);
extern void func_L01_004FC518(s32, s32);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern void func_L01_003E9510(s32, void *);
extern void func_L01_003E94A0(s32, void *);
extern s32 func_00399C90(s32, s32);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_0038E5B8(s32, s32);
extern s32 func_L03_0034A2A8(u8 *, s32);
extern void func_L03_0034A318(void *, Moby *);
extern u8 D_L03_001E2540[];
extern u8 *D_L03_001DFB00;
extern s32 D_L03_001E1490[] __attribute__((section(".sdata")));
typedef struct {
    u8 pad0[0x558];
    u8 f558;
    u8 pad559[0x5C0 - 0x559];
} P_0034AC40;
extern P_0034AC40 D_001CD0C0[];
extern u8 *D_001D52FC;
extern u8 *D_L03_001DFA28;
typedef struct {
    u8 pad[0x100];
} S_0034AC40;
extern S_0034AC40 *D_L03_001DFA1C_0034A080;
__asm__(".extern D_L03_001DD67C, 4");
extern s32 D_L03_001DD67C;

void func_L03_0034A080(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 n = 0;
    s32 i;
    s32 j;
    u8 *m;

    if (func_L01_00452EC8(a0) != 0) {
        func_L01_004FC518(0x74, 1);
        func_L01_003E9588(0, D_L03_001E2540, D_L03_001E2540 + 0x10, 1, 120, 0);
        func_L01_003E9510(0, D_L03_001DFB00 + (*(s32 *)(v + 0xC) << 7) + 0x70);
        func_L01_003E94A0(0, D_L03_001DFB00 + (*(s32 *)(v + 0xC) << 7) + 0x30);
        D_001426E0[0xDB] = 0;
        func_00399C90(0, 3);
        D_L03_001DD67C = 0;
        for (j = 3; j >= 0; j--) {
            D_L03_001E1490[j] = -1;
        }
        for (j = 0; j < 8 && n < 5; j++) {
            if (D_001CD0C0[j].f558 != 0) {
                D_L03_001E1490[n] = j;
                n++;
            }
        }
        func_L01_0044F2E8(0, 5, 0xE79, 1, 0, 0, 0);
    }
    if (*(s32 *)(D_001D52FC + 0x1A4) & 0x800) {
        func_0038E5B8(3, 1);
    }
    if (func_L03_0034A2A8(a0, 1) < 2) {
        D_L03_001DD67C = 1;
        for (m = D_L03_001DFA28; m != 0; m = *(u8 **)(m + 0x28)) {
            if (*(s16 *)(m + 0xAA) == 0x1B9B) {
                m[0xBC] = 1;
            }
        }
    }
    if (func_L03_0034A2A8(a0, 0) < 2) {
        for (i = 0; i < 4; i++) {
            func_L03_0034A318(a0, (Moby *)&D_L03_001DFA1C_0034A080[((s32 *)(v + 0x10))[i]]);
        }
        D_L03_001DD67C = 0;
    }
}
/* localdecomp:end func_L03_0034A080 */

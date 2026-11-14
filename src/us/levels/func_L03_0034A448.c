#include "common.h"

/* NTSC-U counterpart of func_L03_0034B008 (src/levels/shared/L03_0034AF98.c) */
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004FC518(s32, s32);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern void func_L01_003E9510(s32, void *);
extern void func_L01_003E94A0(s32, void *);
extern void func_00399C90(s32, s32);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_0038E5B8(s32, s32);

/* localdecomp:start func_L03_0034A448 */
typedef struct { u8 b[0x80]; } E80_0034A448;
extern E80_0034A448 *D_L03_001DFB00;
extern u8 D_L03_001E2540[];
extern u8 D_001427BB[];
extern u8 *D_001D52FC;

void func_L03_0034A448(u8 *a0) {
    s32 *s1 = *(s32 **)(a0 + 0x68);

    if (func_L01_00452EC8(a0) != 0) {
        *(u16 *)(a0 + 0x96) = 0;
        func_L01_004FC518(0x74, 1);
        func_L01_003E9588(0, D_L03_001E2540, D_L03_001E2540 + 0x10, 1, 0x78, 0);
        func_L01_003E9510(0, D_L03_001DFB00[*s1].b + 0x70);
        func_L01_003E94A0(0, D_L03_001DFB00[*s1].b + 0x30);
        D_001427BB[0] = 0;
        func_00399C90(0, 3);
    }
    if (*(u16 *)(a0 + 0x96) < 0x64) {
        *(u16 *)(a0 + 0x96) += 1;
    }
    func_L01_0044F2E8(0, 5, 0x1A5C, 1, 0, 0, 0);
    if (0x800 & *(s32 *)(D_001D52FC + 0x1A4)) {
        D_001427BB[0] = 0;
        func_0038E5B8(3, 1);
    }
}
/* localdecomp:end func_L03_0034A448 */

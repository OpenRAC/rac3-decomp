#include "common.h"

/* NTSC-U counterpart of func_L28_0039D038 (src/levels/28_aquatos_sewers/L28_0039B910.c): 0.0004 -> 0.000277778; 0.02 -> 0.0166667; 0.00392 -> 0.00272222; 0.0100531 -> 0.00698132; 0.251327 -> 0.20944 */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 D_L28_001DDE00_0039B2D8;
extern f32 D_L28_001DDE04_0039B2D8;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L28_0039B2D8(void *);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L28_0039B2D8 */
/* stores to 0x34 and 0xB8 go through a struct so sched1 sees them as not aliasing the $gp scalars */

typedef int u128_0039D038 __attribute__((mode(TI)));
extern f32 D_L28_001DDE00_0039B2D8;
extern f32 D_L28_001DDE04_0039B2D8;
extern u8 D_L28_001DDE30_0039B2D8;
__asm__(".extern D_L28_001DDE00_0039B2D8, 4");
__asm__(".extern D_L28_001DDE04_0039B2D8, 4");
__asm__(".extern D_L28_001DDE30_0039B2D8, 1");
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003C2868(void *);
typedef struct { u8 pad[0x23]; u8 f23; u8 pad2[0x10]; u16 f34; u8 pad3[0x82]; s32 fB8; } S_0039D038;
s32 func_L28_0039B2D8(void *self) {
    u8 *a0 = self;
    f32 fa, fb;
    u8 *st = *(u8 **)(a0 + 0x68);
    *(u128_0039D038 *)(st + 0x190) = *(u128_0039D038 *)(a0 + 0x10);
    if (*(s16 *)(a0 + 0xB2) == 0) {
        *(s32 *)(st + 0x1B0) = -1;
        *(s32 *)(st + 0x1B8) = -1;
    }
    a0[0x23] = 0x70;
    ((S_0039D038 *)a0)->f34 |= 0x2100;
    ((S_0039D038 *)a0)->fB8 = 0;
    fa = D_L28_001DDE04_0039B2D8 * 0.000277777785f;
    fb = D_L28_001DDE00_0039B2D8 * 0.0166666675f;
    *(s32 *)(st + 0xA8) |= 5;
    *(f32 *)(st + 0x78) = 0.7f;
    *(f32 *)(st + 0x70) = 0.4f;
    *(f32 *)(st + 0x74) = 0.15000001f;
    *(f32 *)(st + 0x7C) = 0.7f;
    *(f32 *)(st + 0x80) = 12.566371f;
    *(f32 *)(st + 0xA0) = 0.34906584f;
    *(f32 *)(st + 0x9C) = 0.00272222236f;
    func_L01_00458A70(a0, fa, fb, 0.00698131742f, 0.209439531f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(s16 *)(st + 0x34) = 1;
        *(f32 *)(st + 0x30) = 1.0f;
    }
    *(f32 *)(st + 0x40) = 0.25f;
    st[0x39] = D_L28_001DDE30_0039B2D8;
    st[0x3F] = 1;
    st[0x64] = 1;
    st[0x3E] = 1;
    func_L01_00441FB8(a0, 3, -1);
    if (a0[0x43] != 1) func_003BE4F0(a0, 1, 0, 0);
    if (*(s32 *)(st + 0x1B0) != -1 || *(unsigned long *)(st + 0x1B8) != 0xFFFFFFFFUL) {
        func_L01_00441FB8(a0, 1, -1);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004A6DF8(a0, 1);
    }
    func_003C2868(a0);
    return 0;
}
/* localdecomp:end func_L28_0039B2D8 */

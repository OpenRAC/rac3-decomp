/* NTSC-U draft (Claude wave S/us): C of func_L39_0052B740, the NTSC-U twin of func_L39_0052BCA8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 16 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L39_0052B740", whose code is not the PAL one).
 * Worker's note: 16 diff unchanged (C near/func_L39_0052B740.xhigh.c). The product r=val*mul: retail has it in v1 (mult v1,v1,v0 reusing val's register, then addiu a0,-1; movn a0,v1,v1 = NE cond-move prefilled with -1), mine puts it in a0 (mult a0,v0,v1; movz a0,v0(-1),a0 = ...
 */
#include "common.h"

/* localdecomp:start func_L39_0052B740 */
typedef struct {
    u8 pad0[0x170];
    s32 f170;
    u8 pad174[0x490];
    s32 f604;
    u8 pad608[0x30];
    s16 f638;
} S_1A5E50;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0xF];
    u8 f30;
    u8 pad31[0x37];
    u8 *f68;
} Obj_52B740;

extern S_1A5E50 D_001A5E50;
extern s32 D_L39_00352A40 __attribute__((section(".data")));
extern s32 D_L39_002407B0 __attribute__((section(".data")));
extern void func_L39_0066CCD8(s32, u8 *, u8 *, u8 *);
extern void func_L39_0061A4F8(void);

void func_L39_0052B740(Obj_52B740 *obj) {
    if (D_001A5E50.f638 != 0) {
        D_L39_00352A40 = -1;
    }
    if (obj->f20 == 0) {
        s32 r;
        s32 val;
        s32 mul;
        u8 *p;
        mul = 60000;
        if (D_001A5E50.f170 == 0) {
            val = D_001A5E50.f604 & 7;
            mul = 300000;
        } else {
            val = D_L39_002407B0;
        }
        r = val * mul;
        p = obj->f68;
        func_L39_0066CCD8(r != 0 ? r : -1, p, p + 0x1B0, p + 0x200);
        obj->f30 = 0xFF;
        obj->f20 = 1;
    } else {
        func_L39_0061A4F8();
    }
}
/* localdecomp:end func_L39_0052B740 */

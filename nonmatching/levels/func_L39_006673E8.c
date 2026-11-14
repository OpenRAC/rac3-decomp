/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_00664B10, the NTSC-U twin of func_L39_006673E8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L39_00666F88.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_006673E8 (src/levels/shared/L39_00666F88.c). MATCH with the PAL flags plus -mvu0-use-vf0-vf2
   (the vec_add_ab helper does not compile without it). */
#include "vu0.h"

/* localdecomp:start func_L39_00664B10 */
typedef struct {
    s32 w0;
    u8 pad4[4];
    s32 w8;
    u8 padC[0x10];
} Rec_00664B10;
extern Rec_00664B10 D_L39_00484160[];
extern s32 D_L39_002440A0;
__asm__(".extern D_L39_002440A0, 16");
extern void func_00388830(void *, void *, f32);

void func_L39_00664B10(u8 *a0, u8 *a1, s32 a2) {
    vu0_v4 vec;
    u8 saved;
    u8 *p;

    saved = a1[0x1A0A];
    *(s32 *)(a0 + 0x2DC) = 0;
    if (a1 != 0) {
        *(s32 *)(a1 + 0x2578) = *(s32 *)(a0 + 0x2D0);
        *(s32 *)(a1 + 0x360) = 0x3C;
        *(s32 *)(a1 + 0x2528) = 0;
        *(s32 *)(a1 + 0x254C) = 0;
        ((void (*)(void *, s32, s32, s32, s32))(*(u32 *)(*(u8 **)(a1 + 0x14) + 0x34)))(a1, 0, 1, 0, 1);
        D_L39_00484160[*(s32 *)(a1 + 0x2544)].w0 = 5;
        D_L39_00484160[*(s32 *)(a1 + 0x2544)].w8 = 10;
        if (a2 != 0) {
            a1[0x1A0A] = 0;
        } else {
            a1[0x1A0A] = saved;
        }
        *(s16 *)(a0 + 0x306) = *(u16 *)(a0 + 0x306) + 1;
        if (*(s16 *)(a0 + 0x306) >= 4) {
            *(s16 *)(a0 + 0x306) = 0;
        }
        if (a1[0x1A14] != 0) {
            func_00388830(&vec, &D_L39_002440A0, *(f32 *)(a1 + 0x132C));
            vec_add_ab(a1 + 0x1180, a1 + 0xA0, &vec);
        }
    }
    if (*(u8 **)(a0 + 0x2D8) != 0) {
        *(s32 *)(*(u8 **)(a0 + 0x2D0) + 0xB8) = *(s32 *)(*(u8 **)(a0 + 0x2D8) + 0x2524);
    } else {
        *(u8 *)(*(u8 **)(a0 + 0x2D0) + 0xBE) &= 0xF7;
        *(u8 *)(*(u8 **)(a0 + 0x2D0) + 0xBE) &= 0xEF;
        *(s32 *)(*(u8 **)(a0 + 0x2D0) + 0xB8) = 0;
    }
}
/* localdecomp:end func_L39_00664B10 */

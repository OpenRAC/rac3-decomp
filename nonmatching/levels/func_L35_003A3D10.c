/* NTSC-U draft (2026-11-14, Claude worker): C of func_L35_003A2460, the NTSC-U twin of func_L35_003A3D10, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/35_vidcomic_5/L35_003A29A8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L35_003A3D10 (src/levels/35_vidcomic_5/L35_003A29A8.c) */
/* localdecomp:start func_L35_003A2460 */
extern u8 (*D_L35_001DFA00)[0x80];
__asm__(".extern D_L35_001DFA00, 16");
extern s32 func_0037E208(s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_L30_0034BB18(void *);

void func_L35_003A2460(u8 *self) {
    u8 *st;
    u8 *e;
    vu0_v4 v;

    st = *(u8 **)(self + 0x68);
    if (*(s32 *)(st + 0x184) != 0) {
        *(s32 *)(st + 0x180) = func_0037E208(0, *(s32 *)(st + 0x188) - 1);
    } else {
        *(s32 *)(st + 0x180) = (*(s32 *)(st + 0x180) + 1) % *(s32 *)(st + 0x188);
    }
    e = st + 0x100 + (*(s32 *)(st + 0x180) << 5);
    if (*(s32 *)(e + 0x1C) != 2) {
        func_003BDA38(self, 2, &v);
        vec_sub_ba(&v, D_L35_001DFA00[*(s32 *)e] + 0x30, &v);
        *(f32 *)(e + 8) = func_L30_0034BB18(&v);
        func_003BDA38(self, 2, &v);
        vec_sub_ba(&v, D_L35_001DFA00[*(s32 *)(e + 4)] + 0x30, &v);
        *(f32 *)(e + 0xC) = func_L30_0034BB18(&v);
    }
    *(s32 *)(st + 0x19C) = *(s32 *)(e + 0x18);
}
/* localdecomp:end func_L35_003A2460 */

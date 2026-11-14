/* NTSC-U draft (2026-11-14, Codex worker): C of func_L08_003A6298, the NTSC-U twin of func_L08_003A8090, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L08_003A8090.c's current line.
 * Worker's note: 34 diff; allowed assembler emits lit4 lwc1 for +/-0x3D6EEEF0 where retail has inline lui/ori/mtc1; remaining VU and logic align; no flags_alt; forbidden flags not tried; best log func_L08_003A6298.check02.log
 */
#include "common.h"

/* localdecomp:start func_L08_003A6298 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003A6298;
extern f32 D_001A4C60[];
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00452F40(void *, s32);
extern s32 func_L01_00452F60(void *);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);

void func_L08_003A6298(u8 *o)
{
    V_003A6298 a, b, c;
    if (o[0x20] == 0) {
        if (o[0x21] != 0xFF) {
            if (o[0xBC]) {
                func_L01_00441FB8(o, 1, -1);
                func_L01_00452F40(o, 1);
            } else {
                if (func_L01_00452F60(o))
                    func_L01_00441FB8(o, 1, -1);
            }
        } else if (func_00388800(o + 0x10, D_001A4C60) < 7.0f) {
            func_L01_00441FB8(o, 1, -1);
            func_L01_00452F40(o, 1);
        }
    }
    if (o[0x20] == 1) {
        (*(u16 *)(o + 0x96))++;
        func_00388830(&a, o + 0xE0, 0.05833333730697632f);
        func_00388830(&b, o + 0xC0, -0.05833333730697632f);
        __asm__(
            "lqc2 $vf1, %2
	"
            "lqc2 $vf2, %1
	"
            "vadd.xyz $vf2, $vf2, $vf1
	"
            "lqc2 $vf1, %3
	"
            "sqc2 $vf1, %0
	"
            "sqc2 $vf2, %1
	"
            "lqc2 $vf1, %1
	"
            "lqc2 $vf2, %0
	"
            "vadd.xyz $vf1, $vf1, $vf2
	"
            "sqc2 $vf1, %1"
            : "=m"(c), "+m"(*(V_003A6298 *)(o + 0x10))
            : "m"(a), "m"(b)
            : "vf1", "vf2");
        if (*(u16 *)(o + 0x96) >= 31)
            func_L01_00441FB8(o, 2, -1);
    }
}
/* localdecomp:end func_L08_003A6298 */

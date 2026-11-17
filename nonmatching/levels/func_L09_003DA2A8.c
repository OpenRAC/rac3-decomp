/* NTSC-U draft (2026-11-14, Claude worker): C of func_L09_003D87A0, the NTSC-U twin of func_L09_003DA2A8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/09_tyhrranosis/L09_003D9E60.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* localdecomp:start func_L09_003D87A0 */
extern f32 D_001A4C68[];

extern void func_L01_004479A8(void *, void *);
extern s32 func_003883C8(void *);
extern u8 *func_L01_00444358(void *, s32, s32);
extern void func_003BF4F8(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_0039FE80(s32, s32, void *);

void func_L09_003D87A0(u8 *o) {
    u8 *p;
    u8 *s2;
    u8 *r;
    u8 *x;
    s32 h;

    if (o[0x20] == 0) {
        return;
    }
    p = *(u8 **)(o + 0x68);
    s2 = p + 0x70;
    func_L01_004479A8(o, s2);
    if (func_003883C8(p + 0x8C) != 0) {
        if (*(f32 *)(o + 0x18) - D_001A4C68[0] < 10.0f) {
            r = func_L01_00444358(o, 0x30000, 0);
            if (r != 0) {
                x = *(u8 **)(r + 0x20);
                if (x != 0) {
                    h = *(s16 *)(x + 0xAA);
                    if (h != 0xABC && h != 0x1A17) {
                        *(u16 *)(p + 0x8A) = *(u16 *)(p + 0x8A) - (s32)*(f32 *)(r + 0x2C);
                        *(s16 *)(p + 0x8C) = 10;
                        p[0x77] = 0xFF;
                        func_003BF4F8(o, s2);
                        *(f32 *)(p + 0x98) = 0.26179938f;
                        if (*(s16 *)(p + 0x8A) > 0) {
                            func_0039FE80(1, 0, o);
                        } else {
                            func_L01_00441FB8(o, 2, -1);
                        }
                    }
                }
            }
        }
    }
    o[0xA8] = 0xFF;
    *(f32 *)(p + 0x30) = (f32)*(s16 *)(p + 0x8A);
}
/* localdecomp:end func_L09_003D87A0 */

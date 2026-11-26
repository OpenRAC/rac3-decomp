/* PAL near miss (k6 agent 2, 2026-11-26), from its functional C. Needs -fopt-stack: retail saves with sd in a 0x160 frame, which
 * this file's line (`-O2 -G8 -mno-check-zero-division @ps2as`) gives as sq in a 0x1B0 frame, and func_L39_00602930, the file's
 * other C function, stops matching with -fopt-stack (23 words): so this function would be a file of its own (it starts the file
 * and func_L39_00602930 starts 8-aligned, build-fidelity.md "Choosing a file's flags"). With -fopt-stack, tools/check.py at
 * level 39: 207 = 207 instructions, 31 aligned rows. What it took: the three mode tests as a switch on the stored mode word
 * (self+0x1A4) with an empty `case 2` (retail's compare tree is ==1, <2, !=0, which {0, 1} alone does not give), the running
 * maximum as a ternary store (retail's movn), the entry table as a local (self+0x1B8). Left: register allocation (retail: idx $s4,
 * count $s5, the table $s3 copied to $s6 for the loop and $s3 then the q pointer; the constant 1 hoisted into $fp), the entry
 * `tab[n - 1]` index (retail addiu -1 before the shift, here folded into the store's -4), and the character test (retail
 * lbu + andi 0xff, the unmasked byte stored into buf).
 */
#include "common.h"
/* localdecomp:start func_L39_006025F0 */
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern s32 D_L39_00241470;
extern f32 D_L39_00241150[] __attribute__((section(".sdata")));
extern void func_0011D534(void *, s32, s32);
extern void func_0038E150(s32);
extern s32 func_L01_00412750(u8 *, s32);
extern s32 func_L01_00412708(u8 *, s32);
extern s32 func_L01_00447470(u8 *, s32, f32);

void func_L39_006025F0(u8 *self, s32 mode, f32 x, f32 y, s32 a4) {
    u8 buf[256];
    s32 saved;
    s32 w = 1;
    s32 idx = 0;
    s32 cnt = 0;
    s32 nobreak = 1;
    s32 k;
    u8 *p;
    u8 *q;
    u8 **tab;
    u8 c;

    (*(f32 **)self)[0] = x;
    (*(f32 **)self)[1] = y;
    *(s32 *)(self + 0x198) = a4;
    *(s32 *)(self + 0x1A4) = mode;
    self[0x187] = 0;
    *(s32 *)(self + 0x190) = 1;
    *(s32 *)(self + 0x1B4) = 0;
    tab = (u8 **)(self + 0x1B8);
    func_0011D534(buf, 0, 0x100);
    func_0011D534(tab, 0, 0x78);
    saved = D_L39_00241470;
    p = self + 0x88;
    tab[*(s32 *)(self + 0x190) - 1] = p;
    func_0038E150(1);
    q = self + 0x89;
    while (*p != 0) {
        c = *p;
        if (c == 1) {
            *p = 0;
            buf[idx] = 0;
            nobreak = 0;
            tab[*(s32 *)(self + 0x190)] = q;
            *(s32 *)(self + 0x190) += 1;
            switch (*(s32 *)(self + 0x1A4)) {
            case 0:
                w = func_L01_00412750(buf, -1);
                break;
            case 1:
                k = *D_L39_00241120;
                if (k >= 2) {
                    w = func_L01_00447470(buf, -1, D_L39_00241150[k - 1] / D_L39_00241150[0]);
                } else {
                    w = func_L01_00412708(buf, -1);
                }
                break;
            case 2:
                break;
            }
            idx = 0;
            *(s32 *)(self + 0x1B4) = *(s32 *)(self + 0x1B4) < w ? w : *(s32 *)(self + 0x1B4);
        } else {
            buf[idx] = c;
            idx++;
        }
        cnt++;
        q++;
        if (cnt >= 0xFF) {
            break;
        }
        p++;
    }
    if (nobreak != 0) {
        switch (*(s32 *)(self + 0x1A4)) {
        case 0:
            *(s32 *)(self + 0x1B4) = func_L01_00412750(buf, -1);
            break;
        case 1:
            k = *D_L39_00241120;
            if (k >= 2) {
                *(s32 *)(self + 0x1B4) = func_L01_00447470(buf, -1, D_L39_00241150[k - 1] / D_L39_00241150[0]);
            } else {
                *(s32 *)(self + 0x1B4) = func_L01_00412708(buf, -1);
            }
            break;
        case 2:
            break;
        }
    } else {
        switch (*(s32 *)(self + 0x1A4)) {
        case 0:
            w = func_L01_00412750(buf, -1);
            break;
        case 1:
            k = *D_L39_00241120;
            if (k >= 2) {
                w = func_L01_00447470(buf, -1, D_L39_00241150[k - 1] / D_L39_00241150[0]);
            } else {
                w = func_L01_00412708(buf, -1);
            }
            break;
        case 2:
            break;
        }
        *(s32 *)(self + 0x1B4) = *(s32 *)(self + 0x1B4) < w ? w : *(s32 *)(self + 0x1B4);
    }
    func_0038E150(saved);
    (*(f32 **)(self + 4))[0] = 1.0f;
}
/* localdecomp:end func_L39_006025F0 */

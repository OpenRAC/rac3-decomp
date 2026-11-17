/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00458F98, the NTSC-U twin of func_L01_0045C2A0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0045A6F0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0045C2A0 (src/levels/shared/L01_0045A6F0.c) */
extern u8 *func_L01_00458650(u8 *);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00436500(void *);
extern void func_L01_00458A08(void *, f32);
extern void func_L01_00457728(u8 *, void *);
extern s32 func_L01_00443080(f32 *, f32 *, f32, f32, f32);
extern void func_L01_00457708(void *, f32);

/* localdecomp:start func_L01_00458F98 */
extern s32 D_L01_001DFBC0_00458F98;

s32 func_L01_00458F98(u8 *a0, f32 a, f32 b, f32 c) {
    u8 *s;
    f32 ang;
    f32 cur;
    f32 t;
    f32 v;
    f32 out[2];
    s32 r;

    s = func_L01_00458650(a0);
    if (s == 0) {
        return 0;
    }
    ang = func_00388A28(*(f32 *)(s + 0xA0), *(f32 *)(s + 0xA4));
    cur = func_L01_00436500(a0);
    if (a0[0x42] == a0[0x43] && a <= cur && cur <= c) {
        if (!(*(s32 *)(s + 0x38) & 0x10)) {
            func_L01_00458A08(a0, ang);
        }
        *(f32 *)(s + 0xA8) = *(f32 *)(s + 0xA8) - *(f32 *)(s + 0x2C);
        func_L01_00457728(a0, s + 0xA0);
        if (0.0f < *(f32 *)(s + 0xA8)) {
            *(f32 *)(a0 + 0x48) = (b - cur) * 2.0f / (*(f32 *)(s + 0xA8) / *(f32 *)(s + 0x2C));
        } else if (*(f32 *)(a0 + 0x18) > *(f32 *)(s + 0x90)) {
            r = func_L01_00443080(&out[0], &out[1], *(f32 *)(s + 0x2C) * -0.5f,
                                  *(f32 *)(s + 0xA8) - *(f32 *)(s + 0x2C) * -0.5f,
                                  *(f32 *)(a0 + 0x18) - *(f32 *)(s + 0x90));
            t = 600.0f;
            if (r > 0) {
                v = out[0];
                if (0.0f < v && v < 60.0f) {
                    t = v;
                }
            }
            *(f32 *)(a0 + 0x48) = (c - cur) * 2.0f / t;
        } else {
            *(f32 *)(a0 + 0x18) = *(f32 *)(s + 0x90);
            *(f32 *)(a0 + 0x48) = 1.0f;
        }
        if (*(f32 *)(a0 + 0x48) > 5.0f) {
            *(f32 *)(a0 + 0x48) = 5.0f;
        } else if (*(f32 *)(a0 + 0x48) < 0.0f) {
            *(f32 *)(a0 + 0x48) = 0.0f;
        }
    } else if (a <= 0.0f || a < cur) {
        func_L01_00457708(a0, ang);
        *(f32 *)(a0 + 0x48) = 1.0f;
    }
    *(s32 *)(s + 0xBC) = D_L01_001DFBC0_00458F98;
    if (a0[0x60] & 2) {
        qzero(s + 0xA0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00458F98 */

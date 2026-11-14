/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_004688C8, the NTSC-U twin of func_L01_0046BF78, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0046A938.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0046BF78 (src/levels/shared/L01_0046A938.c) */
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_003883C8(void *);
extern void func_003C7CE0(void *);
extern void func_003BF6A8(void *, f32);
extern u8 *func_L01_004686D8(void *, u8, u8, u8, u8, u8, s32, f32, f32);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443938(s32, s32, s32, void *, void *, f32);
extern s32 func_0013D3E0(void);

/* localdecomp:start func_L01_004688C8 */
extern u8 D_001A4BE0[];
extern u8 *D_L01_00221200[];
extern u8 *D_L01_001E02F8;

void func_L01_004688C8(u8 *o) {
    u8 *c = o + 0x20;
    u8 *h;
    u8 *hp;
    vu0_v4 t;
    f32 f;
    f32 sc;
    s32 i;
    s32 r;

    switch (c[0x14]) {
    case 0:
        *(s32 *)(o + 4) = func_003894A0(0xFF4080FF, 0, ((f32)c[0x11] - (f32)*(s16 *)(o + 0xA)) / (f32)c[0x11]);
        if (func_003883C8(o + 0xA) == 0) {
            return;
        }
        if (c[0x10] == 1) {
            func_003C7CE0(o);
            return;
        }
        c[0x14] = 1;
        *(s16 *)(o + 0xA) = c[0x12];
        return;
    case 1:
        i = 0;
        if (c[0x13] != 0) {
            do {
                t = *(vu0_v4 *)(o + 0x10);
                func_003BF6A8(&t, 0.05f);
                sc = 1.0f;
                if (*(s16 *)(o + 0xA) < 10) {
                    sc = (f32)*(s16 *)(o + 0xA) / 10.0f;
                }
                i++;
                func_L01_004686D8(&t, 2, c[0x11], c[0x12], c[0x13], c[0x15], *(s32 *)(c + 0x18), *(f32 *)(c + 0x1C), sc);
            } while (i < c[0x13]);
        }
        if (func_003883C8(o + 0xA) != 0) {
            func_003C7CE0(o);
        }
        if (func_00388800(o + 0x10, D_001A4BE0 + 0x80) < 0.3f) {
            hp = D_001A4BE0 + 0x80;
            h = hp - 0x80;
            if (*(f32 *)(h + 0x88) < *(f32 *)(o + 0x18) + 1.2f) {
                vec_sub_ab(&t, hp, o + 0x10);
                func_00388830(&t, &t, 1.0f);
                t.z = 1.0f;
                func_L01_00443938(*(s32 *)(h + 0x25C0), *(s32 *)(c + 0x18), 1, o + 0x10, &t, *(f32 *)(c + 0x1C));
            }
        }
        return;
    case 2:
        vec_add_ab(o + 0x10, o + 0x10, o + 0x20);
        f = ((f32)c[0x15] - (f32)*(s16 *)(o + 0xA)) / (f32)c[0x15];
        *(s32 *)(o + 4) = func_003894A0((c[0x16] << 24) | 0x4060, 0x8FAFFF, f);
        if (f < 0.6f) {
            *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) + 9030.0f;
        } else {
            *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) - 16800.0f;
        }
        r = func_0013D3E0();
        o[2] = D_L01_00221200[0][r & 7];
        if (((o - D_L01_001E02F8) >> 6) & 1) {
            o[8] = o[8] + 1;
        } else {
            o[8] = o[8] - 1;
        }
        if (func_003883C8(o + 0xA) != 0) {
            func_003C7CE0(o);
        }
        return;
    }
}
/* localdecomp:end func_L01_004688C8 */

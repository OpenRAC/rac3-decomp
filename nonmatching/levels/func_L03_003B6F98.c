/* NTSC-U draft (Claude wave K): C of func_L03_003B5390, the NTSC-U twin of func_L03_003B6F98, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 26 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L03_003B5390", whose code is not the PAL one).
 * Worker's note: 26 diff words of 124 (same length, 31 structural after alignment), first draft; everything outside the colour block is byte-exact (toggle of f3C between D_001DEAA4/EAA8 when func_003BEBF8(&st->f38, st->f3C, D_001DEAAC_sda) == 0.0f; ang = func_00389380(0.0f, ...
 */
/* near (xhigh): 26 diff words of 124 with the entry's flags '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as'; all in the colour-fade block
 * (a0/a1 hold -1/B in retail, B/-1 in mine; A' is computed mid-chain in retail, last in mine). */
#include "common.h"

typedef struct { u8 p0[0x34]; f32 f34; f32 f38; f32 f3C; } S_3B5390;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_3B5390 *st; u8 p6C[0x96 - 0x6C]; u16 h96; } O_3B5390;

extern f32 func_003BEBF8(void *, f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_L03_003B51F0(void *, s32, s32, s32, f32, f32, f32);

/* localdecomp:start func_L03_003B5390 */
extern f32 D_001DEAAC_sda;
__asm__(".extern D_001DEAAC_sda, 4");
extern f32 D_001DEAA4_sda;
__asm__(".extern D_001DEAA4_sda, 4");
extern f32 D_001DEAA8_sda;
__asm__(".extern D_001DEAA8_sda, 4");
extern u32 D_001DEAB4_sda;
__asm__(".extern D_001DEAB4_sda, 4");
extern u32 D_001DEAB8_sda;
__asm__(".extern D_001DEAB8_sda, 4");
extern s32 D_001DEABC_sda;
__asm__(".extern D_001DEABC_sda, 4");
extern s32 D_001DEAC0_sda;
__asm__(".extern D_001DEAC0_sda, 4");
extern f32 D_001DEAC4_sda;
__asm__(".extern D_001DEAC4_sda, 4");

void func_L03_003B5390(O_3B5390 *o) {
    S_3B5390 *st;
    f32 ang;
    u32 a;
    u32 b;
    s32 al;

    st = o->st;
    if (func_003BEBF8(&st->f38, st->f3C, D_001DEAAC_sda) == 0.0f) {
        if (st->f3C == D_001DEAA4_sda) {
            st->f3C = D_001DEAA8_sda;
        } else {
            st->f3C = D_001DEAA4_sda;
        }
    }
    ang = func_00389380(0.0f, st->f34 * 0.017453292f);
    if (o->b20 == 6) {
        a = D_001DEAB4_sda;
        b = D_001DEAB8_sda;
        al = (a >> 24) - (o->h96 << 2);
        if (al < 0) {
            al = 0;
        }
        a = (al << 24) | (a & 0xFF0000) | (a & 0xFF00) | (a & 0xFF);
        al = (b >> 24) - (o->h96 << 2);
        if (al < 0) {
            al = 0;
        }
        b = (al << 24) | (b & 0xFF0000) | (b & 0xFF00) | (b & 0xFF);
        func_L03_003B51F0(o, D_001DEAC0_sda, b, 1, st->f38, D_001DEAC4_sda, -ang);
        func_L03_003B51F0(o, D_001DEABC_sda, a, 1, st->f38, D_001DEAC4_sda, ang);
    } else {
        func_L03_003B51F0(o, D_001DEAC0_sda, D_001DEAB8_sda, 1, st->f38, D_001DEAC4_sda, -ang);
        func_L03_003B51F0(o, D_001DEABC_sda, D_001DEAB4_sda, 1, st->f38, D_001DEAC4_sda, ang);
    }
    st->f34 = st->f34 + 1.0f;
    if (st->f34 > 359.0f) {
        st->f34 = 0.0f;
    } else if (st->f34 < 0.0f) {
        st->f34 = 359.0f;
    }
}
/* localdecomp:end func_L03_003B5390 */

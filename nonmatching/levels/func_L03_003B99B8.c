/* NTSC-U draft (Claude wave K): C of func_L03_003B7D18, the NTSC-U twin of func_L03_003B99B8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 35 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L03_003B7D18", whose code is not the PAL one).
 * Worker's note: 35 diff words with the two extras the PAL line lacks (vec_add_ba needs -mvu0-use-vf0-vf2, float immediates need @ps2as); about 12 of them are the $gp relocation print, the rest is a pure callee-saved register permutation in the init loop: mine obj=s3, n=s1, ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003B7D18 */
/* Needs -mvu0-use-vf0-vf2 (vec_* helpers) and @ps2as (float immediates) beyond the PAL file's flags. */
typedef struct {
    u8 pad0[0x7C];
    s16 h7C;
    u8 pad7E[0xF0 - 0x7E];
    f32 fF0;
} Child_003B7D18;

typedef struct {
    Child_003B7D18 *p[4];
    union { s32 w10[4]; struct { f32 f10; f32 f14; f32 f18; f32 f1C; } f; } u;
} St_003B7D18;

extern s32 D_001DEB00_sda;
extern f32 D_001DEAF4_sda;
extern f32 D_001DEAF8_sda;
extern f32 D_001DEAF0_sda;
extern s32 D_L03_001DEB04;
extern s32 D_L03_001DEB08;
__asm__(".extern D_001DEB00_sda, 4");
__asm__(".extern D_001DEAF4_sda, 4");
__asm__(".extern D_001DEAF8_sda, 4");
__asm__(".extern D_001DEAF0_sda, 4");

extern Child_003B7D18 *func_L03_003B7C98(void *);
extern void func_L03_003B8068(void *);
extern s32 func_L01_00452F60(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_00388BD0(void *, void *);
extern f32 func_00389380(f32, f32);
extern f32 func_003887C8(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BD360(void *);

void func_L03_003B7D18(void *self) {
    u8 *o = self;
    St_003B7D18 *st;
    Child_003B7D18 **pp;
    vu0_v4 tmp;
    s32 n;

    st = *(St_003B7D18 **)(o + 0x68);
    switch (o[0x20]) {
    case 0:
        o[0x30] = 0xFF;
        for (n = 0; n < 4; n++) {
            st->u.w10[n] = 0;
            st->p[n] = func_L03_003B7C98(o);
            if (st->p[n] != 0) st->p[n]->h7C = 1 << n;
        }
        func_L01_00441FB8(o, 1, -1);
        break;
    case 1:
        if (*(u8 **)(o + 0xB8) != 0 && *(s16 *)(*(u8 **)(o + 0xB8) + 0xAA) == 0x1AE0) {
            *(f32 *)(o + 0xF0) = *(f32 *)(*(u8 **)((u8 *)st + 0x20) + 0xF0);
            func_00388BD0(o + 0xC0, o + 0xF0);
            func_L03_003B8068(o);
        }
        if (func_L01_00452F60(o) != 0) {
            func_L01_00441FB8(o, 2, -1);
        }
        break;
    case 2:
        if ((f32)D_001DEB00_sda <= st->u.f.f10) {
            st->p[0]->h7C = 0;
            func_L01_00441FB8(o, 3, -1);
        } else if (st->p[0] != 0) {
            func_L03_003B8068(o);
            st->u.f.f10 = st->u.f.f10 + D_001DEAF4_sda;
            st->p[0]->fF0 = func_00389380(*(f32 *)(o + 0xF0), st->u.f.f10 * 0.017453292f);
            func_00388BD0((u8 *)st->p[0] + 0xC0, (u8 *)st->p[0] + 0xF0);
        }
        break;
    case 3:
        if ((f32)D_L03_001DEB04 <= st->u.f.f14) {
            st->p[1]->h7C = 0;
            func_L01_00441FB8(o, 4, -1);
        } else if (st->p[1] != 0) {
            func_L03_003B8068(o);
            st->u.f.f14 = st->u.f.f14 + D_001DEAF4_sda;
            st->p[1]->fF0 = func_00389380(*(f32 *)(o + 0xF0), st->u.f.f14 * 0.017453292f);
            func_00388BD0((u8 *)st->p[1] + 0xC0, (u8 *)st->p[1] + 0xF0);
        }
        break;
    case 4:
        func_L03_003B8068(o);
        if ((f32)D_L03_001DEB08 <= st->u.f.f18) {
            st->p[2]->h7C = 0;
            func_L01_00441FB8(o, 5, -1);
        } else if (st->p[2] != 0) {
            func_L03_003B8068(o);
            st->u.f.f18 = st->u.f.f18 + D_001DEAF4_sda;
            st->p[2]->fF0 = func_00389380(*(f32 *)(o + 0xF0), st->u.f.f18 * 0.017453292f);
            func_00388BD0((u8 *)st->p[2] + 0xC0, (u8 *)st->p[2] + 0xF0);
        }
        break;
    case 5:
        if (D_001DEAF8_sda <= func_003887C8((u8 *)st->p[3] + 0x10, o + 0x10)) {
            func_L01_00441FB8(o, 6, -1);
        } else if (st->p[3] != 0) {
            st->u.f.f1C = st->u.f.f1C + D_001DEAF0_sda * 0.016666668f;
            func_00388830(&tmp, (u8 *)st->p[3] + 0xD0, st->u.f.f1C);
            vec_add_ba((u8 *)st->p[3] + 0x10, o + 0x10, &tmp);
        }
        break;
    case 6:
        pp = st->p;
        for (n = 3; n >= 0; n--) {
            if (*pp != 0) func_003BD360(*pp);
            pp++;
        }
        break;
    }
}
/* localdecomp:end func_L03_003B7D18 */

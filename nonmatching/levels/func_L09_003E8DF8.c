/* NTSC-U draft (2026-11-14, Claude worker): C of func_L09_003E7100, the NTSC-U twin of func_L09_003E8DF8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/09_tyhrranosis/L09_003E8DF8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3E7100;
typedef struct {
    u8 p0[0x40];
    s32 w40[4];
    V4_3E7100 v50;
    s32 w60;
    u8 p64[2];
    s16 h66;
    s32 w68;
    f32 f6C;
    s32 w70;
    f32 f74;
    f32 f78;
} S_3E7100;
typedef struct { u8 p0[0x10]; V4_3E7100 pos; } O_3E7100;
typedef struct { u8 p0[0x10]; V4_3E7100 pos; } R_3E7100;

extern void func_L09_003E74C0(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern s32 func_00388398(void *);
extern void func_L09_003E75A0(void *, s32);
extern void func_L01_00440A88(void *, f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_003BD360(void *);

/* localdecomp:start func_L09_003E7100 */
extern u8 *D_001E011C_sda;
__asm__(".extern D_001E011C_sda, 4");

void func_L09_003E7100(u8 *o) {
    S_3E7100 *s;
    V4_3E7100 tmp;
    u8 *r;
    s32 i;
    s32 *pw;

    s = *(S_3E7100 **)(o + 0x68);
    func_L09_003E74C0(o);
    switch (o[0x20]) {
    case 0:
        *(s16 *)(o + 0x32) = o[0x30] = 0xC8;
        *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
        s->w70 = 0x96;
        func_L01_00441FB8(o, 1, -1);
        break;
    case 2:
        if (func_L01_00452EC8(o) != 0) {
            s->w68 = s->w70;
        }
        if (func_00388398(&s->w68) != 0) {
            func_L01_00441FB8(o, 3, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(o) != 0) {
            pw = s->w40;
            for (i = 0; i < 4; i++) {
                if (pw[i] != -1) {
                    func_L09_003E75A0(D_001E011C_sda + (pw[i] << 8), s->w70 - 10);
                }
            }
            if (s->w60 != -1) {
                r = D_001E011C_sda + (s->w60 << 8);
                *(s32 *)(*(u8 **)(D_001E011C_sda + (*(s32 *)*(u8 **)(r + 0x68) << 8) + 0x68) + 0xDC) = 8;
            }
            s->w68 = 0x5A;
        }
        if (func_00388398(&s->w68) != 0) {
            func_L01_00441FB8(o, 4, -1);
            break;
        }
        if (s->h66 != 0) {
            *(u128_t *)&s->v50 = *(u128_t *)(o + 0x10);
            func_L01_00440A88(&tmp, 0.0f, 0.1f);
            vec_add_ab(o + 0x10, o + 0x10, &tmp);
            if (s->w60 != -1) {
                r = D_001E011C_sda + (s->w60 << 8);
                vec_add_ba(r + 0x10, r + 0x10, &tmp);
            }
            s->h66 = 0;
        } else {
            vec_sub_ab(&tmp, &s->v50, o + 0x10);
            *(u128_t *)(o + 0x10) = *(u128_t *)&s->v50;
            if (s->w60 != -1) {
                r = D_001E011C_sda + (s->w60 << 8);
                vec_add_ba(r + 0x10, r + 0x10, &tmp);
            }
            s->h66 = 1;
        }
        break;
    case 4:
        if (func_L01_00452EC8(o) != 0) {
            vec_sub_ab(&tmp, &s->v50, o + 0x10);
            *(u128_t *)(o + 0x10) = *(u128_t *)&s->v50;
            if (s->w60 != -1) {
                r = D_001E011C_sda + (s->w60 << 8);
                vec_add_ba(r + 0x10, r + 0x10, &tmp);
            }
            s->h66 = 1;
            s->f74 = func_L01_00440918(0.1f, 0.5f) * 0.017453292f;
            s->f78 = func_L01_00440918(0.1f, 0.5f) * 0.017453292f;
            s->w68 = 0xF0;
        }
        s->f6C = s->f6C + -0.0027222224f;
        if (-0.16333334f < s->f6C) {
            s->f6C = -0.16333334f;
        }
        *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + s->f6C;
        *(f32 *)(o + 0xF0) = func_00389380(*(f32 *)(o + 0xF0), s->f74);
        *(f32 *)(o + 0xF4) = func_00389380(*(f32 *)(o + 0xF4), s->f78);
        if (s->w60 != -1) {
            r = D_001E011C_sda + (s->w60 << 8);
            *(f32 *)(r + 0x18) = *(f32 *)(r + 0x18) + s->f6C;
        }
        if (func_00388398(&s->w68) != 0) {
            func_003BD360(o);
        }
        break;
    }
}
/* localdecomp:end func_L09_003E7100 */

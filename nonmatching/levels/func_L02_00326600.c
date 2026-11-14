/* NTSC-U draft (2026-11-14, Claude worker): C of func_L02_00325D78, the NTSC-U twin of func_L02_00326600, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as + divs row 2 2" (src/levels/shared/L02_00326430.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_325D78;
typedef struct { u8 p0[0x20]; f32 f20[4]; f32 f30[4]; s32 f40[4]; f32 f50[4]; } S_325D78;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_325D78 *st; } O_325D78;

extern V4_325D78 D_L02_001E1300;
extern s32 D_001DC94C_sda;
__asm__(".extern D_001DC94C_sda, 4");
extern s32 D_001DC950_sda;
__asm__(".extern D_001DC950_sda, 4");
extern s32 D_001DC954_sda;
__asm__(".extern D_001DC954_sda, 4");
extern s32 D_001DC958_sda;
__asm__(".extern D_001DC958_sda, 4");
extern void func_003886E8(void *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_L01_00436500(void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_00388398(void *);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_00468C38(void *, s32, s32, s32, s32, s32, s32, s32, f32);

/* localdecomp:start func_L02_00325D78 */
void func_L02_00325D78(O_325D78 *o) {
    V4_325D78 d;
    V4_325D78 v10;
    V4_325D78 e;
    S_325D78 *st;
    f32 mul;
    f32 f;
    s32 i;

    mul = 1.0f;
    st = o->st;
    if (o->b20 == 1) {
        func_003886E8(&v10, o, 0.0009765625f);
    } else {
        func_003BDA38(o, 0, &v10);
        mul = (160.0f - func_L01_00436500(o)) / 160.0f * 5.0f;
        if (1.0f < mul) {
            mul = 1.0f;
        }
    }
    vec_sub_ba(&d, &D_L02_001E1300, &v10);
    func_00388830(&d, &d, -0.3f);
    func_00388830(&e, &d, 0.1f);
    vec_add_ab(&d, &d, &v10);
    for (i = 0; i < 4; i++) {
        st->f20[i] = st->f20[i] + st->f30[i];
        if (st->f20[i] >= 255.0f) {
            st->f20[i] = st->f20[i] - 255.0f;
        } else if (st->f20[i] <= 0.0f) {
            st->f20[i] = st->f20[i] + 255.0f;
        }
        if (func_00388398(&st->f40[i]) != 0) {
            st->f40[i] = 0xFF;
        }
        func_L01_00468C38(&d, func_003894A0(D_001DC94C_sda, D_001DC950_sda, fabs_asm(0.5f - (f32)(0xFF - st->f40[i]) / 255.0f)),
                          (s32)st->f20[i] & 0xFF, D_001DC958_sda, D_001DC954_sda, 2, 0, 0, st->f50[i] * mul);
        vec_add_ab(&d, &d, &e);
    }
}
/* localdecomp:end func_L02_00325D78 */

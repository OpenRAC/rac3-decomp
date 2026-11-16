/* NTSC-U draft (Claude wave C2): C of func_L18_00352A50, the NTSC-U twin of func_L18_00353658, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L18_00352A50", whose code is not the PAL one).
 * Worker's note: flags: working flags '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (PAL file: '-O2 -G8 -fopt-stack -mno-check-zero-division'). MATCH only with -mvu0-use-vf0-vf2 and @ps2as added (vec_add_ab; float constants); the PAL flags have ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L18_00352A50 */
extern void func_003886E8(f32 *, u8 *, f32);
extern void func_L01_003F4D78(s32, u8 *, s32, f32 *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_003EFFE0(s32, s32);
extern void func_L18_00352678(u8 *, f32 *, u32);
extern s32 func_003883C8(u8 *);
extern u8 D_L18_001E2B40[];
extern u8 *D_001D52FC;
extern s32 D_L18_001DD360;
__asm__(".extern D_L18_001DD360, 4");

static __inline__ u8 *Ent(s32 off) {
    return D_L18_001E2B40 + off;
}

void func_L18_00352A50(u8 *a0) {
    f32 v[4];
    u8 *s;
    u8 *g;
    s32 x;
    s32 k;
    s32 n;
    s32 m;

    g = D_001D52FC;
    *(s32 *)(a0 + 0x98) = 0;
    s = *(u8 **)(a0 + 0x68);
    func_003886E8(v, Ent(0x380), 250.0f);
    vec_add_ab(v, v, a0 + 0x10);
    func_L01_003F4D78(0, a0, 0xFF0FFF0F, v, 0x23, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
    if (*(s32 *)(s + 0x3D4) > 0) {
        *(s32 *)(s + 0x3E4) = *(s32 *)(s + 0x3E4) + 1;
        if (*(s32 *)(s + 0x3E4) >= 0xB) {
            *(s32 *)(s + 0x3E4) = 0xA;
        }
    } else {
        *(s32 *)(s + 0x3E4) = 0;
    }
    if ((*(s32 *)(g + 0x1A0) & 0x28) != 0 && *(s16 *)(s + 0x37E) == 0 && *(s32 *)(s + 0x3D4) > 0 && *(s32 *)(s + 0x3E4) >= 3) {
        x = D_L18_001DD360;
        *(s32 *)(s + 0x3D8) = 0x19;
        func_L01_003EFFE0(x, 0);
        func_L18_00352678(a0, v, 0xFFFFFFFF);
    }
    func_003883C8(s + 0x37E);
    m = *(s32 *)(s + 0x3D8) - 1;
    *(s32 *)(s + 0x3D8) = m;
    if (m <= 0) {
        n = *(s32 *)(s + 0x3D4);
        if (n < 8) {
            *(s32 *)(s + 0x3D8) = 0x19;
            *(s32 *)(s + 0x3D4) = n + 1;
        }
    }
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
}
/* localdecomp:end func_L18_00352A50 */

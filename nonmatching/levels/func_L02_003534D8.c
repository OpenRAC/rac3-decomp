/* NTSC-U draft (2026-11-14, Claude worker): C of func_L02_00352398, the NTSC-U twin of func_L02_003534D8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L02_00352C80.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L02_003534D8 (src/levels/shared/L02_00352C80.c) */
/* localdecomp:start func_L02_00352398 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00352398;
typedef struct {
    u8 pad0[4];
    f32 f4;
    u8 pad8[2];
    u8 bA;
    u8 padB[0x51];
    s32 w5C;
} O_00352398;

extern f32 D_001DD008_sda;
extern f32 D_001DCFE0_sda;
extern f32 D_001DCFF8_sda;
extern f32 D_001DD00C_sda;
extern s32 D_001DCFFC_sda;
extern s32 D_001DD000_sda;
extern s32 D_001DCFF4_sda;
extern f32 D_001DCFE4_sda;
extern f32 D_001DCFE8_sda;
extern f32 D_001DCFEC_sda;
extern f32 D_001DCFF0_sda;
extern f32 D_001DD004_sda;
extern u8 D_L02_001E1300[];
extern u8 *D_L02_0021E1B4[];
__asm__(".extern D_001DD008_sda, 4");
__asm__(".extern D_001DCFE0_sda, 4");
__asm__(".extern D_001DCFF8_sda, 4");
__asm__(".extern D_001DD00C_sda, 4");
__asm__(".extern D_001DCFFC_sda, 4");
__asm__(".extern D_001DD000_sda, 4");
__asm__(".extern D_001DCFF4_sda, 4");
__asm__(".extern D_001DCFE4_sda, 4");
__asm__(".extern D_001DCFE8_sda, 4");
__asm__(".extern D_001DCFEC_sda, 4");
__asm__(".extern D_001DCFF0_sda, 4");
__asm__(".extern D_001DD004_sda, 4");
__asm__(".extern D_L02_0021E1B4, 16");
extern s32 func_L02_00351E50(s32, void *, V4_00352398 *, f32);
extern f32 func_003887C8(void *, void *);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L02_00352398(s32 a0, O_00352398 *o) {
    V4_00352398 v0;
    V4_00352398 v1;
    s32 r;
    s32 s0;
    s32 s1;
    s32 s3;
    f32 d;
    f32 f20;
    f32 f22;
    u8 *rr;

    r = func_L02_00351E50(a0, o, &v0, D_001DD008_sda);
    if (r == 0) {
        return 0;
    }
    if (r == -1) {
        return 1;
    }
    *(u128_t *)&v1 = 0;
    v0.z = v0.z - D_001DCFE0_sda;
    v1.z = D_001DCFF8_sda * 0.016666668f;
    d = func_003887C8(&v0, D_L02_001E1300);
    d = d / (D_001DD008_sda * o->f4);
    if (d < 0.75f) {
        s3 = o->w5C;
    } else {
        s3 = func_003894A0(o->w5C, 0, (d - 0.75f) * 4.0f);
    }
    f22 = 1.0f;
    if (o->bA != 0) {
        f22 = D_001DD00C_sda;
    }
    s1 = func_0037E208(D_001DCFFC_sda, D_001DD000_sda);
    s0 = func_0037E208(-D_001DCFF4_sda, D_001DCFF4_sda);
    f20 = func_0037E250(D_001DCFE4_sda, D_001DCFE8_sda) * f22;
    f20 = f20 * 210000.0f;
    rr = func_L01_0046C468(&v0, &v1, s1, s3, s0, 0x7F, 0, 0, f20, func_0037E250(D_001DCFEC_sda, D_001DCFF0_sda) * f22 * 210000.0f, D_001DD004_sda);
    if (rr != 0) {
        rr[2] = D_L02_0021E1B4[0][0];
    }
    return 1;
}
/* localdecomp:end func_L02_00352398 */

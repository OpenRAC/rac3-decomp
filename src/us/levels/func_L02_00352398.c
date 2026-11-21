#include "common.h"

/* NTSC-U counterpart of func_L02_003534D8 (src/levels/shared/L02_00353398.c) */
typedef struct B_L02_00352C80 {
    s32 id;
    u8 pad04[0x1C];
    s32 cnt20;
    s32 a24;
    s32 a28;
    s32 r2C;
    u8 pad30[0x10];
    s32 cnt40;
    s32 a44;
    s32 a48;
    s32 r4C;
    s32 flag50;
    f32 f54;
    f32 f58;
} B_L02_00352C80;
typedef struct A_L02_00352C80 {
    u8 pad00[0x20];
    u8 b20;
    u8 pad21[0x47];
    B_L02_00352C80 *sub;
} A_L02_00352C80;
extern s32 func_0037E208(s32, s32);
extern s32 func_L02_00351E50(A_L02_00352C80 *, B_L02_00352C80 *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);

/* localdecomp:start func_L02_00352398 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003534D8;
typedef struct {
    u8 pad0[4];
    f32 f4;
    u8 pad8[2];
    u8 bA;
    u8 padB[0x51];
    s32 w5C;
} O_003534D8;

extern f32 D_L02_001DD008_00352398;
extern f32 D_L02_001DCFE0;
extern f32 D_L02_001DCFF8;
extern f32 D_L02_001DD00C_00352398;
extern s32 D_L02_001DCFFC;
extern s32 D_L02_001DD000_00352398;
extern s32 D_L02_001DCFF4;
extern f32 D_L02_001DCFE4;
extern f32 D_L02_001DCFE8;
extern f32 D_L02_001DCFEC;
extern f32 D_L02_001DCFF0;
extern f32 D_L02_001DD004_00352398;
__asm__(".extern D_L02_001DD008_00352398, 4");
__asm__(".extern D_L02_001DCFE0, 4");
__asm__(".extern D_L02_001DCFF8, 4");
__asm__(".extern D_L02_001DD00C_00352398, 4");
__asm__(".extern D_L02_001DCFFC, 4");
__asm__(".extern D_L02_001DD000_00352398, 4");
__asm__(".extern D_L02_001DCFF4, 4");
__asm__(".extern D_L02_001DCFE4, 4");
__asm__(".extern D_L02_001DCFE8, 4");
__asm__(".extern D_L02_001DCFEC, 4");
__asm__(".extern D_L02_001DCFF0, 4");
__asm__(".extern D_L02_001DD004_00352398, 4");
extern u8 D_L02_001E1300_00352398[];
extern u8 *D_L02_0021E1B4[];
__asm__(".extern D_L02_0021E1B4, 16");
extern s32 func_L02_00351E50(A_L02_00352C80 *, B_L02_00352C80 *, void *, f32);
extern f32 func_003887C8(void *, void *);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L02_00352398(A_L02_00352C80 *a0, B_L02_00352C80 *b) {
    O_003534D8 *o = (O_003534D8 *)b;
    V4_003534D8 v0;
    V4_003534D8 v1;
    s32 r;
    s32 s0;
    s32 s1;
    s32 s3;
    f32 d;
    f32 f20;
    f32 f22;
    u8 *rr;
    V4_003534D8 *pv;

    r = func_L02_00351E50(a0, b, &v0, D_L02_001DD008_00352398);
    if (r == 0) {
        return 0;
    }
    if (r == -1) {
        return 1;
    }
    qzero(&v1);
    v0.z = v0.z - D_L02_001DCFE0;
    v1.z = D_L02_001DCFF8 * 0.016666668f;
    d = func_003887C8(&v0, D_L02_001E1300_00352398);
    d = d / (D_L02_001DD008_00352398 * o->f4);
    if (d < 0.75f) {
        s3 = o->w5C;
    } else {
        s3 = func_003894A0(o->w5C, 0, (d - 0.75f) * 4.0f);
    }
    f22 = 1.0f;
    if (o->bA != 0) {
        f22 = D_L02_001DD00C_00352398;
    }
    pv = &v1;
    s1 = func_0037E208(D_L02_001DCFFC, D_L02_001DD000_00352398);
    s0 = func_0037E208(-D_L02_001DCFF4, D_L02_001DCFF4);
    f20 = func_0037E250(D_L02_001DCFE4, D_L02_001DCFE8) * f22 * 210000.0f;
    rr = func_L01_0046C468(&v0, pv, s1, s3, s0, 0x7F, 0, 0, f20, func_0037E250(D_L02_001DCFEC, D_L02_001DCFF0) * f22 * 210000.0f, D_L02_001DD004_00352398);
    if (rr != 0) {
        rr[2] = D_L02_0021E1B4[0][0];
    }
    return 1;
}
/* localdecomp:end func_L02_00352398 */

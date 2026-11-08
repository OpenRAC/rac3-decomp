#include "common.h"

/* localdecomp:start func_L03_003A4550 */
typedef struct S_003A4550 {
    s32 w0, w4, w8; u8 c, d, e, pad0F; s32 w10; f32 f14; s32 pad18; s16 h1C; u8 f1E, f1F; u8 pad20[4]; s32 w24;
} S_003A4550;
typedef struct A_003A4550 { char pad[0x20]; u8 f20; } A_003A4550;
typedef struct G_003A4550 { char p0[0x30C]; u16 h30C; char p1[0xA]; u16 h318; char p2[4]; u16 h31E_; char p3[4]; u16 h324; char p4[0x226]; u16 h54C; char p5[0xAD2]; u16 h1020; } G_003A4550;
extern u8 D_001426E0[]; extern G_003A4550 D_001A7E18; extern u8 D_001A4C60[];
extern f32 D_001DF5B0; __asm__(".extern D_001DF5B0, 16");
extern s32 D_001DF4C0_sda; __asm__(".extern D_001DF4C0_sda, 4");
extern s32 D_L03_001DF4C0_003A4550; __asm__(".extern D_L03_001DF4C0_003A4550, 16");
extern s32 func_00382380();
extern void func_L01_0041BE28();
extern s32 func_L01_00513EF0();
extern void func_L01_0041A5B0();
extern void func_0039EF28();
extern s32 func_0038CB00();
extern void func_L01_0041A528();
extern s32 func_L01_0044CD60();
void func_L03_003A4550(A_003A4550 *a) {
    S_003A4550 *p = *(S_003A4550 **)((char *)a + 0x68);
    s32 n;
    u8 *q;
    if (a->f20 == 0) { p->f14 = D_001DF5B0; a->f20 = 1; }
    if (D_001426E0[0x85] == 0) {
        if (D_001A7E18.h324 == 0 && p->c == 0) {
            if (func_00382380(D_001A4C60, p->w0, 0)) { func_L01_0041BE28(0xBA0, 0x43); p->c = 1; }
        }
        if (D_001A7E18.h30C == 0 && D_001A7E18.h1020 == 0 && p->d == 0 && func_00382380(D_001A4C60, p->w4, 0)) {
            if (func_L01_00513EF0()) { func_L01_0041BE28(0x185F, 0x158); } else { func_L01_0041BE28(0xB9E, 0x41); }
            p->d = 1;
            n = D_L03_001DF4C0_003A4550;
        } else n = D_001DF4C0_sda;
        if (n < 0x1E && D_001A7E18.h318 == 0 && (D_001426E0[0xDE] & 1) && !(D_001426E0[0xDE] & 2)) func_L01_0041A5B0(0xB9F, 0x42);
        if (func_00382380(D_001A4C60, p->w8, 0)) { D_001426E0[0xDE] |= 2; func_0039EF28(); }
        q = D_001A4C60;
        q -= 0x80;
        if (*(s32 *)(q + 0xA48) != 0) { p->h1C = 0x96; *(s32 *)(q + 0xA48) = 0; }
        if (func_0038CB00(&p->h1C) == 0 && *(s32 *)(q + 0x25C4) == 0x79) { D_001426E0[0xDE] |= 1; func_0039EF28(); }
        if (func_00382380(D_001A4C60, p->w24, 0)) func_L01_0041A528();
        if (D_001A7E18.h54C == 0 && p->e == 0 && func_00382380(D_001A4C60, p->w8, 0)) { func_L01_0041BE28(0xCC7, 0x71); p->e = 1; }
    }
    if (func_00382380(D_001A4C60, p->w10, 0)) {
        D_001DF5B0 = 92.0f;
        if (p->f1E == 0) { func_L01_0044CD60(0xB); p->f1E = 1; }
    } else { D_001DF5B0 = p->f14; p->f1E = 0; }
}
/* localdecomp:end func_L03_003A4550 */

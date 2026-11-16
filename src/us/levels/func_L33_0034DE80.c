#include "common.h"

/* NTSC-U counterpart of func_L33_0034EA80 (src/levels/33_vidcomic_2/L33_0034E8C0.c) */
/* localdecomp:start func_L33_0034DE80 */
#include "vu0.h"

extern void func_L31_00345E88(void *, void *);
extern void func_L03_0034A658(u8 *, s32, s32, f32, s32, void *);
void func_L33_0034E630(u8 *, u8 *);
void func_L33_0034E1E0(u8 *, u8 *);
void func_L33_0034E910(u8 *, u8 *);
extern f32 D_L33_001DD678;
extern f32 D_L33_001DD5DC;
extern f32 D_L33_001DD5E0;
extern s32 D_L33_001DD650;
extern s32 D_L33_001DD71C;
extern s32 D_L33_001DD720;
extern f32 D_L33_001DD734;
extern s32 D_L33_001DD73C_0034DE80;
extern s32 D_L33_001DD718;
extern s32 D_L33_001DD6C0;
extern s32 D_L33_001DD6C4;
extern f32 D_L33_001DD6E0_0034DE80;
extern s32 D_L33_001DD6E8;
extern s32 D_L33_001DD6BC;
extern s32 D_L33_001DD778;
extern s32 D_L33_001DD77C_0034DE80;
extern f32 D_L33_001DD780_0034DE80;
extern s32 D_L33_001DD78C_0034DE80;
extern s32 D_L33_001DD76C_0034DE80;
extern f32 D_L33_001DD618_0034DE80;

typedef struct {
    u8 pad0[0xC0];
    s32 fC0;
    s32 fC4;
} S_0034EA80;

typedef struct {
    u8 obj[0x10];
    s32 val;
} E_0034EA80;

typedef struct {
    u8 pad0[8];
    f32 f8;
    u8 padC[4];
} H_0034EA80;

extern H_0034EA80 D_L33_001E1820 __attribute__((section(".sdata")));
extern E_0034EA80 D_L33_001E1830_0034DE80 __attribute__((section(".sdata")));
extern E_0034EA80 D_L33_001E1850 __attribute__((section(".sdata")));
extern E_0034EA80 D_L33_001E1870 __attribute__((section(".sdata")));

void func_L33_0034DE80(u8 *p) {
    u8 *s = *(u8 **)(p + 0x68);
    f32 lim;

    if (*(s16 *)(s + 0x14) == 0) {
        *(s16 *)(s + 0x14) = 3;
        *(f32 *)(s + 0x10) = 3.0f;
    }
    if (s[0x24] == 0) {
        s[0x24] = 0x14;
    }
    *(f32 *)(s + 0x20) = 1.5f;
    func_L31_00345E88(p, s + 0x50);
    *(s32 *)(s + 0xA0) = 0;
    qzero(s + 0x80);
    *(s32 *)(s + 0xA4) = 0;
    *(s32 *)(s + 0xA8) = 0;
    *(s32 *)(s + 0xAC) = 0;
    lim = *(f32 *)(s + 0xA0);
    if (*(f32 *)(s + 0xB4) < lim) {
        *(f32 *)(s + 0xB4) = D_L33_001DD678;
    }
    if (*(f32 *)(s + 0xB8) < lim) {
        *(f32 *)(s + 0xB8) = D_L33_001DD5DC;
    }
    if (*(f32 *)(s + 0xBC) < lim) {
        *(f32 *)(s + 0xBC) = D_L33_001DD5E0;
    }
    ((S_0034EA80 *)s)->fC4 = -1;
    ((S_0034EA80 *)s)->fC0 = 0;
    if (D_L33_001DD650 == 0) {
        D_L33_001DD650 = 1;
        func_L03_0034A658(D_L33_001E1850.obj, D_L33_001DD71C, D_L33_001DD720, D_L33_001DD734, D_L33_001DD73C_0034DE80, (void *)func_L33_0034E630);
        D_L33_001E1850.val = D_L33_001DD718;
        func_L03_0034A658(D_L33_001E1830_0034DE80.obj, D_L33_001DD6C0, D_L33_001DD6C4, D_L33_001DD6E0_0034DE80, D_L33_001DD6E8, (void *)func_L33_0034E1E0);
        D_L33_001E1830_0034DE80.val = D_L33_001DD6BC;
        func_L03_0034A658(D_L33_001E1870.obj, D_L33_001DD778, D_L33_001DD77C_0034DE80, D_L33_001DD780_0034DE80, D_L33_001DD78C_0034DE80, (void *)func_L33_0034E910);
        qzero(&D_L33_001E1820);
        D_L33_001E1870.val = D_L33_001DD76C_0034DE80;
        D_L33_001E1820.f8 = D_L33_001DD618_0034DE80;
    }
}
/* localdecomp:end func_L33_0034DE80 */

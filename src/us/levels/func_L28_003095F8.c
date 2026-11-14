#include "common.h"

/* NTSC-U counterpart of func_L28_00309958 (src/levels/28_aquatos_sewers/L28_003098F0.c) */
/* localdecomp:start func_L28_003095F8 */
typedef struct { s32 a, b, c, d; } C16_003095F8;
__asm__(".extern D_001DC5A0_sda, 4");
__asm__(".extern D_001DC584_sda, 4");
__asm__(".extern D_001DC5A8_sda, 4");
__asm__(".extern D_001DC5A4_sda, 4");
__asm__(".extern D_001DC5AC_sda, 4");
__asm__(".extern D_001DC580_sda, 4");
__asm__(".extern D_001DC578_sda, 4");
__asm__(".extern D_001DC594_sda, 4");
__asm__(".extern D_001DC598_sda, 4");
extern u8 *D_001DC5A0_sda;
extern f32 D_001DC584_sda;
extern s32 D_001DC5A8_sda;
extern s32 D_001DC5A4_sda;
extern f32 D_001DC5AC_sda;
extern f32 D_001DC580_sda;
extern f32 D_001DC578_sda;
extern s32 D_001DC594_sda;
extern s32 D_001DC598_sda;
extern s32 D_L28_001DFE20;
extern f32 D_L28_001DFE24;
extern u8 *D_L28_001D67C8;
extern s32 D_001D4BC4;
extern C16_003095F8 D_L28_001DC5B0;
extern char D_L28_001DC5C0[];
extern void func_L01_004C2220(void);
extern s32 func_L28_003E3B08(void);
extern void func_L24_00400048(void);
extern s32 func_003A6830(u8 *, s32);
extern void func_003A4DC8(s32, s32, f32, f32, f32, f32, f32);
extern void func_L28_003E3B38(void);
extern s32 func_L28_003095C8(void);
extern s32 func_00392108(s32, s32);
extern void func_003925F0(s32, s32, s32, s32, s32, void *);
extern void func_0011B2E8(char *, char *, s32);
extern s32 func_0011B868(char *);
extern s32 func_L01_00410228(s32, s32, unsigned long, char *, s32);

static inline s32 sy_003095F8(f32 v, f32 o) {
    return (s32)(v * D_L28_001DFE24 + 0.5f + (D_L28_001DFE20 == 1 ? o : 0.0f));
}

s32 func_L28_003095F8(void) {
    u8 *s = *(u8 **)(D_001DC5A0_sda + 0x68);
    f32 f20;
    f32 f21;
    s32 h;
    s32 w;
    s32 x;
    s32 y;
    f32 k;
    C16_003095F8 col;
    char buf[16];

    func_L01_004C2220();
    k = 32.0f;
    *(f32 *)(s + 4) += D_001DC584_sda;
    if (*(f32 *)(s + 4) > 1.0f) {
        *(f32 *)(s + 4) = 1.0f;
    }
    if (D_L28_001D67C8 != 0) {
        func_L28_003E3B08();
        func_L24_00400048();
        h = func_003A6830(D_L28_001D67C8 + 0x7090, 0x77);
        func_003A4DC8(h, 0x411465B7, (f32)D_001DC5A4_sda,
                      (f32)sy_003095F8((f32)D_001DC5A8_sda, 0.0f), 1.0f, 1.0f, D_001DC5AC_sda);
        h = func_003A6830(D_L28_001D67C8 + 0x7090, 0x76);
        func_003A4DC8(h, 0x462299DE, (f32)D_001DC5A4_sda,
                      (f32)sy_003095F8((f32)D_001DC5A8_sda, 0.0f), 1.0f, 1.0f, D_001DC5AC_sda);
        func_L28_003E3B38();
    }
    f20 = k * (1.0f - *(f32 *)(s + 4)) * 0.5f;
    f21 = (f32)(D_001D4BC4 - sy_003095F8(D_001DC580_sda, 0.0f));
    col = D_L28_001DC5B0;
    h = func_L28_003095C8();
    h = func_00392108(0xEAA2, h);
    w = (s32)(k * *(f32 *)(s + 4));
    func_003925F0(h, (s32)(D_001DC578_sda + f20), (s32)f21, w, sy_003095F8((f32)w, 0.0f), &col);
    func_0011B2E8(buf, D_L28_001DC5C0, *(s32 *)s);
    x = (s32)(D_001DC578_sda + (f32)D_001DC594_sda);
    y = (s32)f21 + sy_003095F8((f32)D_001DC598_sda, 4.0f);
    func_L01_00410228(x, y, 0x80F0F0F0, buf, func_0011B868(buf));
    return 0;
}
/* localdecomp:end func_L28_003095F8 */

/* functional: high. textures: same calls, args and output words as retail; only register allocation/stack layout differ (117 diff words). */
#include "vu0.h"
typedef struct { u8 p0[8]; s32 w; s32 h; s32 f10; s32 f14; } Img_3824D0;
typedef struct {
    u8 *f0; u8 *f4; u8 p8[0xC]; s32 f14; s32 f18; u8 p1C[0x10]; s32 f2C; u8 p30[0xC]; s32 f3C;
    u8 p40[0xC]; s32 f4C; s32 f50;
} Tex_3824D0;
extern void func_0038CF58(void *, s32, s32);
extern void func_12C9A0(void *, s16, s16, s16, s16, s16, s16, s16);
extern void func_11F0A0(s32);
extern int func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_003824D0(Img_3824D0 *img, long *out, s32 tbp, s32 cbp) {
    Tex_3824D0 t;
    u8 buf[0x60];
    s32 c;
    func_0038CF58(&t, 0, 0x54);
    t.f0 = (u8 *)img + 0x20;
    if (img->f14 == 0) t.f14 = 0x400; else t.f14 = 0x200;
    t.f4C = 30 - plzcw_asm(img->w);
    t.f50 = 30 - plzcw_asm(img->h);
    t.f4 = (u8 *)img + (t.f14 + 0x20);
    t.f18 = img->w * img->h;
    c = cbp >> 8;
    func_12C9A0(buf, c, 1, img->f14, 0, 0, 0x10, 0x10);
    func_11F0A0(0);
    func_12CCC8(buf, t.f0);
    func_12A9F0(0, 0);
    t.f3C = img->w >> 6;
    if (t.f3C <= 0) t.f3C = 1;
    t.f2C = tbp >> 8;
    func_12C9A0(buf, t.f2C, t.f3C, 0x1B, 0, 0, img->w, img->h);
    func_11F0A0(0);
    func_12CCC8(buf, t.f4);
    func_12A9F0(0, 0);
    out[0] = (long)t.f2C | ((long)t.f3C << 14) | ((long)0x1B << 20) | ((long)t.f4C << 26)
        | ((long)t.f50 << 30) | (1L << 34) | ((long)c << 37) | ((long)img->f14 << 51) | (1L << 63);
    out[1] = 1;
    out[2] = 0;
}

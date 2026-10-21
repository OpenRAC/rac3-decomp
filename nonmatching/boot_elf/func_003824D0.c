/* US draft of func_003824D0 (rac3-uya-decomp func_003824F0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003824D0 */
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; u8 pE[6]; s32 f14; } Img_3824F0;
typedef struct {
    u8 *f0; u8 *f4; u8 p8[0xC]; s32 f14; s32 f18; u8 p1C[0x10]; s32 f2C; u8 p30[0xC]; s32 f3C;
    u8 p40[0xC]; s32 f4C; s32 f50;
} Tex_3824F0;
extern void func_0038CF58(void *, s32, s32);
extern void func_12C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_003824D0(Img_3824F0 *img, unsigned long *out, s32 tbp, s32 cbp) {
    Tex_3824F0 t;
    u8 buf[0x60];
    s32 w, h, lz, lz2, c;
    func_0038CF58(&t, 0, sizeof(t));
    t.f0 = (u8 *)img + 0x20;
    if (img->f14 == 0) t.f14 = 0x400; else t.f14 = 0x200;
    w = *(s32 *)((u8 *)img + 8);
    h = *(s32 *)((u8 *)img + 0xC);
    __asm__("plzcw %0, %1" : "=r"(lz) : "r"(w));
    t.f4C = 30 - lz;
    __asm__("plzcw %0, %1" : "=r"(lz2) : "r"(h));
    t.f50 = 30 - lz2;
    t.f4 = (u8 *)img + (t.f14 + 0x20);
    t.f18 = w * h;
    c = cbp >> 8;
    func_12C9A0(buf, c, 1, img->f14, 0, 0, 0x10, 0x10);
    func_11F0A0(0);
    func_12CCC8(buf, t.f0);
    func_12A9F0(0, 0);
    t.f3C = *(s32 *)((u8 *)img + 8) >> 6;
    if (t.f3C <= 0) t.f3C = 1;
    t.f2C = tbp >> 8;
    func_12C9A0(buf, t.f2C, t.f3C, 0x1B, 0, 0, img->h8, img->hC);
    func_11F0A0(0);
    func_12CCC8(buf, t.f4);
    func_12A9F0(0, 0);
    out[0] = ((unsigned long)t.f2C << 0) | ((unsigned long)t.f3C << 14) | ((unsigned long)0x1B << 20)
        | ((unsigned long)t.f4C << 26) | ((unsigned long)t.f50 << 30) | ((unsigned long)1 << 34)
        | ((unsigned long)0 << 35) | ((unsigned long)c << 37) | ((unsigned long)img->f14 << 51)
        | ((unsigned long)0 << 55) | ((unsigned long)0 << 56) | ((unsigned long)4 << 61);
    out[1] = 1;
    out[2] = 0;
}
/* localdecomp:end func_003824D0 */

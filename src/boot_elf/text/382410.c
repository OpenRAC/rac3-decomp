#include "common.h"

/* localdecomp:start func_00382410 */
__asm__(".extern D_001D99A0, 16");
__asm__(".extern D_001D52FC, 16");
extern void *D_001D52FC;
s32 func_00382410(fallback)
s32 fallback;
{
    s32 index = func_00382360(fallback);
    register s32 value __asm__("$4") = *(s16 *)((u8 *)D_001D99A0 + (index * 0x10) + 0xC);
    register s32 result __asm__("$2") = fallback;
    if (value > 0) {
        register u8 flag __asm__("$3");
        result = (s32)D_001D52FC;
        flag = *(volatile u8 *)(result + 0x550);
        result = value;
        __asm__ volatile("" : "+r"(result));
        if (flag == 0) {
            result = fallback;
        }
    }
    return result;
}
/* localdecomp:end func_00382410 */

/* localdecomp:start func_00382468 */
extern s32 func_00382410();
void func_00382468(void) {
    func_003823D0(func_00382410());
}
/* localdecomp:end func_00382468 */

/* localdecomp:start func_00382490 */
extern s32 D_001D5688;
void func_00382490(void) { D_001D5688 = 0; }
/* localdecomp:end func_00382490 */

/* US draft of func_00382498 (rac3-uya-decomp func_003824B8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


extern s32 D_001D5680;

/* localdecomp:start func_00382498 */
extern s32 D_001D5680;
void func_00382498(void) { D_001D5680 = 8; }
/* localdecomp:end func_00382498 */

/* localdecomp:start func_003824A8 */
extern void func_003980A0();
extern u8 D_001D5790[];
 
void func_003824A8(void) {
    func_003980A0(D_001D5790, 0, 0);
}
/* localdecomp:end func_003824A8 */

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
/* localdecomp:start func_003824D0 */
/* the copy of func_003820F0 */
#include "vu0.h"
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; u8 pE[6]; s32 f14; } Img_003824D0;
typedef struct {
    u8 *f0; u8 *f4; u8 p8[0xC]; s32 f14; s32 f18; u8 p1C[0x10]; s32 f2C; u8 p30[0xC]; s32 f3C;
    u8 p40[0xC]; s32 f4C; s32 f50;
} Tex_003824D0;
extern void func_0038CF58(void *, s32, s32);
extern void func_0012C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_0011F0A0(s32);
extern void func_0012CCC8(void *, void *);
extern s32 func_0012A9F0(s32, s32);
void func_003824D0(Img_003824D0 *img, unsigned long *out, s32 tbp, s32 cbp) {
    Tex_003824D0 t;
    u8 buf[0x60];
    s32 w, h, lz, lz2, c;
    func_0038CF58(&t, 0, sizeof(t));
    t.f0 = (u8 *)img + 0x20;
    if (img->f14 == 0) t.f14 = 0x400; else t.f14 = 0x200;
    w = *(s32 *)((u8 *)img + 8);
    h = *(s32 *)((u8 *)img + 0xC);
    lz = plzcw_asm(w);
    t.f4C = 30 - lz;
    lz2 = plzcw_asm(h);
    t.f50 = 30 - lz2;
    t.f4 = (u8 *)img + (t.f14 + 0x20);
    t.f18 = w * h;
    c = cbp >> 8;
    func_0012C9A0(buf, c, 1, img->f14, 0, 0, 0x10, 0x10);
    func_0011F0A0(0);
    func_0012CCC8(buf, t.f0);
    func_0012A9F0(0, 0);
    t.f3C = *(s32 *)((u8 *)img + 8) >> 6;
    if (t.f3C <= 0) t.f3C = 1;
    t.f2C = tbp >> 8;
    func_0012C9A0(buf, t.f2C, t.f3C, 0x1B, 0, 0, img->h8, img->hC);
    func_0011F0A0(0);
    func_0012CCC8(buf, t.f4);
    func_0012A9F0(0, 0);
    out[0] = ((unsigned long)t.f2C << 0) | ((unsigned long)t.f3C << 14) | ((unsigned long)0x1B << 20)
        | ((unsigned long)t.f4C << 26) | ((unsigned long)t.f50 << 30) | ((unsigned long)1 << 34)
        | ((unsigned long)0 << 35) | ((unsigned long)c << 37) | ((unsigned long)img->f14 << 51)
        | ((unsigned long)0 << 55) | ((unsigned long)0 << 56) | ((unsigned long)4 << 61);
    out[1] = 1;
    out[2] = 0;
}
/* localdecomp:end func_003824D0 */

/* localdecomp:start func_003826A8 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern unsigned long D_001D4D38_003826A8;
__asm__(".extern D_001D4D38_003826A8, 16");
typedef struct { u8 p0[0x64C]; s32 f64C; s32 f650; s32 f654; } S_160C40_3826C8;
extern S_160C40_3826C8 D_160C40_003826A8;
extern u8 D_2D2100[];
extern s32 D_1A1F0C[];
extern s32 func_003A2AF0(s32, s32, s32);
extern void func_003824D0_003826A8(void *, unsigned long *, s32, s32);
void func_003826A8(void) {
    unsigned long out[4];
    S_160C40_3826C8 *g = &D_160C40_003826A8;
    func_003A2AF0((s32)D_2D2100, g->f650 + g->f64C, g->f654);
    func_003824D0_003826A8(D_2D2100, out, D_1A1F0C[0], 0x3FFC00);
    D_001D4D38_003826A8 = out[0];
}
/* localdecomp:end func_003826A8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00382714);

/* localdecomp:start func_00382728 */
s32 func_00382728(u8 *p) {
    s32 *q;
    if (p == 0 || (q = *(s32 **)(p + 0x68)) == 0 || !(*(u16 *)(p + 0x34) & 0x20)) {
        return 0;
    }
    return *q;
}
/* localdecomp:end func_00382728 */

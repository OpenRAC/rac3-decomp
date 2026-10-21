/* US draft of func_00398C80 (rac3-uya-decomp func_00393E90, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00398C80 */
/* MATCH */
typedef struct { u8 p0[0x30]; s32 x30; u8 p34[4]; unsigned long x38; } S_16C580_00393E90;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAF0]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393E90;
typedef struct { u8 p0[0x18]; s32 x18; u8 p1c[0x10]; s32 x2C; } S_1A1ED0_00393E90;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393E90;
extern S_16C580_00393E90 D_16C580_00398C80;
extern S_160C40_00393E90 D_160C40_00398C80;
extern S_1A1ED0_00393E90 D_1A1ED0_00398C80;
__asm__(".extern D_001DA05C, 16");
extern s32 D_001DA05C;
extern s32 D_001DA048[];
extern s32 func_003A2750(s32);
extern s32 func_003A26F0(s32, s32, s32);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_00398C80(s32 n) {
    u8 buf[0x60];
    S_16C580_00393E90 *g = &D_16C580_00398C80;
    S_160C40_00393E90 *b;
    S_1A1ED0_00393E90 *r;
    u8 *t;
    u8 *q;
    s32 w, h, k, lz;
    g->x30 = n;
    func_003A92F0(1);
    t = (u8 *)D_001DA048[1 - D_001DA05C];
    func_003A2750(1);
    b = &D_160C40_00398C80;
    q = t + 0x20;
    func_003A26F0((s32)t, b->e[n].a + b->f1284, b->e[n].b);
    r = &D_1A1ED0_00398C80;
    func_12C9A0(buf, r->x18 >> 8, 1, 0, 0, 0, 0x10, 0x10);
    func_11F0A0(0);
    func_12CCC8(buf, q);
    func_12A9F0(0, 0);
    w = *(s32 *)(t + 8);
    __asm__("plzcw %0, %1" : "=r"(lz) : "r"(w));
    k = 30 - lz;
    h = w >> 6;
    if (h <= 0) h = 1;
    func_12C9A0(buf, r->x2C >> 8, h, 0x1B, 0, 0, ((T_00393E90 *)t)->h8, ((T_00393E90 *)t)->hC);
    func_11F0A0(0);
    func_12CCC8(buf, t + 0x420);
    func_12A9F0(0, 0);
    g->x38 = (unsigned long)(r->x2C >> 8) | ((unsigned long)h << 14) | ((unsigned long)0x1B << 20)
           | ((unsigned long)k << 26) | ((unsigned long)k << 30) | ((unsigned long)1 << 34)
           | ((unsigned long)(r->x18 >> 8) << 37) | ((unsigned long)4 << 61);
}
/* localdecomp:end func_00398C80 */

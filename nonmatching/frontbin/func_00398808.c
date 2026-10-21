/* US draft of func_00398808 (rac3-uya-decomp func_00393A18, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00398808 */
typedef struct { s32 a, b, c, d; } E_00393A18;
typedef struct { u8 p0[0x1EB4]; s32 x1EB4; E_00393A18 e[1]; } S_160C40_00393A18;
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0x10]; s32 x24; } S_1A1ED0_00393A18;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393A18;
extern S_160C40_00393A18 D_160C40_00398808;
extern S_1A1ED0_00393A18 D_1A1ED0_00398808;
extern unsigned long D_1D4B70[1];
extern s32 func_003A2750(s32);
extern s32 func_003A26F0(s32, s32, s32);
extern s32 func_00381CB0(void);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_00398808(s32 n0) {
    s32 n;
    u8 buf[0x60];
    u8 *p;
    s32 *list;
    S_160C40_00393A18 *b;
    S_1A1ED0_00393A18 *r;
    s32 i, a, c;
    func_003A92F0(1);
    n = n0;
    p = *(u8 **)0x1D4B64;
    func_003A2750(1);
    if (func_00381CB0() > 0) n = func_00381CB0();
    b = &D_160C40_00398808;
    func_003A26F0((s32)p, b->e[n].c + b->x1EB4, b->e[n].d);
    list = (s32 *)(p + 4);
    r = &D_1A1ED0_00398808;
    c = r->x24;
    a = r->x10;
    *(s32 *)0x1D4B68 = *(s32 *)p;
    for (i = 0; i < *(s32 *)0x1D4B68; i++) {
        {
            s32 tbp = a >> 8;
            u8 *q = p + *list;
            u8 *q20 = q + 0x20;
            s32 cbp, w, h, k, lz;
            func_12C9A0(buf, tbp, 1, 0, 0, 0, 0x10, 0x10);
            cbp = c >> 8;
            a += 0x400;
            func_11F0A0(0);
            list++;
            func_12CCC8(buf, q20);
            func_12A9F0(0, 0);
            w = *(s32 *)(q + 8);
            __asm__("plzcw %0, %1" : "=r"(lz) : "r"(w));
            k = 30 - lz;
            h = w >> 6;
            if (h <= 0) h = 1;
            func_12C9A0(buf, cbp, h, 0x1B, 0, 0, ((T_00393A18 *)q)->h8, ((T_00393A18 *)q)->hC);
            func_11F0A0(0);
            func_12CCC8(buf, q + 0x420);
            func_12A9F0(0, 0);
            D_1D4B70[i] = (unsigned long)cbp | ((unsigned long)h << 14) | ((unsigned long)0x1B << 20)
                | ((unsigned long)k << 26) | ((unsigned long)k << 30) | ((unsigned long)1 << 34)
                | ((unsigned long)tbp << 37) | ((unsigned long)4 << 61);
            c += *(s32 *)(q + 8) * *(s32 *)(q + 0xC) * 4;
        }
    }
    func_003A26F0((s32)p, D_160C40_00398808.e[n].a + D_160C40_00398808.x1EB4, D_160C40_00398808.e[n].b);
}
/* localdecomp:end func_00398808 */

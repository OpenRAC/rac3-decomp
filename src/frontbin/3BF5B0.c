#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
u8 func_003BDBF8(void);


/* localdecomp:start func_003BF5B0 */
extern s32 func_003BDEF0(void);
extern void func_003BF390(void *a);
void func_003BF5B0(void *a) {
    if (func_003BDEF0() == 2) return;
    if (func_003BDEF0() == 3) return;
    func_003BF390(a);
}
/* localdecomp:end func_003BF5B0 */

/* func_003BF600 (PAL), from the US draft of rac3-uya-decomp func_003BA108 (commit 13cf5c5).
   PAL fixes over the US draft: the byte global is at 0x1DA311 (US 0x1DA391), and the
   last two arguments of func_003BDF60 are 12, 12 (US 15, 15). */


/* localdecomp:start func_003BF600 */
/* The flag pair at 0x1DA310: retail reaches the second byte with `lui` (the assembler's
   expansion), so the pair is declared sized (gcc leaves the accesses to the assembler as
   macros) with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md). The first byte goes through $gp, as the plain D_001DA310. */
extern u8 D_001DA310_003BF600[2];
__asm__(".extern D_001DA310_003BF600, 16");
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x15E]; s32 w1A0; } S_3BA108;
extern S_3BA108 D_00225700_003BF600[];
extern u32 D_001DA49C;
extern u32 D_001DA4A0;
extern u8 D_001DA310;
extern s32 D_001D8DF0;
extern void func_003C7DD8();
extern void func_003BC768();
extern s32 func_003BDF10();
extern s32 func_003BDF18();
extern void func_003BB968();
extern void func_003BE168();
extern s32 func_003BDD38();
extern void func_003BDE60();
extern void func_003BE308();
extern void func_003BDF40();
extern void func_00387EF0();
extern void func_003BF0E0();
extern void func_003BDF60();
extern void func_003BF5B0();
__asm__(".extern D_001DA49C, 16");
__asm__(".extern D_001DA4A0, 16");
s32 func_003BF600(s32 a) {
    u32 p;
    s32 r;
    u8 t;
    S_3BA108 *g;
    r = 0;
    for (p = D_001DA49C; p < D_001DA4A0; p += 0x100) {
        func_003C7DD8(p);
    }
    D_001DA310 = func_003BDBF8();
    if (D_001DA310 != 0) {
        func_003BC768();
        if (func_003BDF10() == 1) {
            func_003BE168();
        }
        if (func_003BDF10() > 0 && func_003BDF18() != 0) {
            func_003BB968();
        }
        t = D_001DA310_003BF600[1];
        if (a != 0) { if (t != 0) r = 1; }
        if (t == 0) {
            s32 v4;
            if (func_003BDF10() > 0 && a != 0) {
                v4 = D_001D8DF0;
                D_001DA310_003BF600[1] = 1;
            } else {
                v4 = func_003BDD38();
            }
            func_003BDE60(v4);
            func_003BE308(func_003BF0E0);
            func_003BDF40();
            func_00387EF0();
        }
    }
    g = D_00225700_003BF600;
    if (g->w1A0 != 0) func_003BF5B0(g->w1A0);
    func_003BDF60(g->w34, g->h40, 12, 12);
    return r;
}
/* localdecomp:end func_003BF600 */

/* localdecomp:start func_003BF778 */
extern void func_003BDF40();
extern void func_003BC768();
 
void func_003BF778(void) {
    func_003BDF40();
    func_003BC768();
}
/* localdecomp:end func_003BF778 */

extern f32 D_001DA340;
extern s32 D_001DA338;
extern u8 D_001DA33C;
extern u8 D_001DA344[2];
extern s32 D_001D8E30;
extern u8 D_001D8E34[];
extern void *D_002FCDA4[];
extern void func_003BBA08(s32, s32);
extern void func_003BC408();
extern s32 func_003BDD38(void);
extern void func_003BDE20(s32);
extern void func_003BE308(void *);
extern void func_003BF860();
extern void func_003BFC58();
INCLUDE_ASM("asm/nonmatchings/text", func_003BF7A0);

/* localdecomp:start func_003BF848 */
extern s32 D_0016C5E4[];
s32 func_003BF848(void) {
    return D_0016C5E4[0] == 1;
}
/* localdecomp:end func_003BF848 */

/* US draft of func_003BF860 (rac3-uya-decomp func_003BA368, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003BB210. */


/* localdecomp:start func_003BF860 */
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x2E]; void *x64; u8 pad3[0x42]; s16 hAA; } S_3BA368;
extern void func_003C0720();
extern void func_003BFD60(S_3BA368 *p);
void func_003BF860(S_3BA368 *p) {
    s32 r = 0;
    if (p->hAA == 0x1E01) {
        p->x64 = func_003C0720;
        func_003BFD60(p);
        r = 1;
    }
    if (r) p->h34 &= ~2;
    else p->h34 |= 2;
}
/* localdecomp:end func_003BF860 */

/* localdecomp:start func_003BF8C0 */
extern void func_003A8220(void *);
extern u8 D_0031D130[];
 
void func_003BF8C0(void) {
    func_003A8220(D_0031D130);
}
/* localdecomp:end func_003BF8C0 */

/* localdecomp:start func_003BF8E0 */
extern u8 *D_001D6EEC[];
void func_003BF8E0(s32 a0, u8 *src) {
    u8 *p;
    s32 i;
    if (D_001D6EEC[0] == 0) return;
    p = D_001D6EEC[0];
    i = 0;
    do {
        i++;
        if (*(s32 *)(p + 0x48) == 0) {
            *(s32 *)(p + 0x38) = *(s32 *)(src + 0x38);
            *(s32 *)(p + 0x3C) = *(s32 *)(src + 0x3C);
            *(s32 *)(p + 0x30) = *(s32 *)(src + 0x30);
            *(s32 *)(p + 0x44) = *(s32 *)(src + 0x44);
            *(f32 *)(p + 0x24) = *(f32 *)(src + 0x24);
            *(f32 *)(p + 0x20) = *(f32 *)(src + 0x20);
            *(f32 *)(p + 0x28) = *(f32 *)(src + 0x28);
            *(s32 *)(p + 0x34) = *(s32 *)(src + 0x34);
            *(s32 *)(p + 0x2C) = *(s32 *)(src + 0x2C);
            *(s32 *)(p + 0x40) = *(s32 *)(src + 0x40);
            *(s32 *)(p + 0x4C) = *(s32 *)(src + 0x4C);
            *(u128_t *)(p + 0) = *(u128_t *)(src + 0);
            *(u128_t *)(p + 0x10) = *(u128_t *)(src + 0x10);
            *(s32 *)(p + 0x48) = a0;
            return;
        }
        p += 0x50;
    } while (i < 0x15E);
}
/* localdecomp:end func_003BF8E0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BF988);

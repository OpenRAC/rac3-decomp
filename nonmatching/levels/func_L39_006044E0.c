/* k4 Sonnet first pass, func_L39_006044E0 (4972 B, 1243 instructions, 15 places 39..53), PAL near miss.
 * Check (mode S, `--as ps2as`, i.e. the file needs `@ps2as` on its text_parts.txt line, as its neighbours
 * L39_00605878.c / L39_006023D8.c have; without it every float constant is a `$gp` literal): "561 diff" in
 * the checker's positional count, but only 3 real hunks: all 1243 instructions have the same opcodes, the
 * rest is a shift of 2 words. With the default assembler 1159 diff.
 * It is a whole function (prologue saves $s0-$s7/$fp/$ra and $f20-$f30, 0x120 frame), NOT a fragment:
 * the constructor of one player's menu widget block (struct 0xB50), the same routine as the matched
 * frontbin func_003AD7D8 (src/frontbin/3AD7D8.c). This C is that C with the L39 callees and data
 * (func_003AB250 -> func_L39_00601478 ...), the 15 `$gp` slots re-derived (D_001D9F24..F5C_sda from
 * `$gp - 0x298C..-0x2954` on story gp 0x1DC8B0) and the 21 strings D_L39_002454E8..00245628.
 * Prototypes: all taken from the frontbin twin (same shapes); callee map in the code. Confidence high.
 * Equal: prologue, every call sequence, the 8-widget loop, the two ring loops, the FX blocks, the tail.
 * Needed to get here: reading the retail flag word as `D_001A5810[0]` (array, extern s32 D_001A5810[]):
 * with a scalar the `lui` lands in the lw's destination register and 100 words shift (561 vs 612 diff).
 * What still differs (all in the angle loops, `(f32)i * 2.0f * 3.1415927f * 0.125f - 3.1415927f`):
 *   - retail loads 0.125f ONCE (`lui $at,0x3e00; mtc1 $at,$f24`) at the top of the first (item+ring) loop
 *     body in callee-saved $f24 and the second loop (rings, `for j<8`) reuses $f24 with no load; here
 *     both loops build 0.125f inline in $f0 right before the mul. (pi in loop 1 is $f29 hoisted early, in
 *     loop 2 $f23 hoisted in its pre-header; those match.) So the two retail loops share one pseudo for
 *     0.125f; cse/loop.c does not give that here. Tried without effect: `/ 8.0f`, a local `f32 k = 0.125f`
 *     at function top or before loop 1, swapping the w550/w58C blocks, 52.0f/281.0f in locals.
 *   - the 2 extra words (lui/mtc1) per loop then shift the rest of the listing by 2.
 * Next steps: see why loop.c/cse would keep the 0.125f load live from loop 1 into loop 2 (check
 * whether the retail loop 1 body is the end of the cse extended basic block that includes loop 2's
 * pre-header, so loop 2's hoisted `li.s 0.125` is cse'd against loop 1's: that needs loop.c to hoist
 * it in loop 2 but not in loop 1; the item loop's call count / register pressure may decide). Also try
 * writing the two loops with the same loop variable or one `f32` angle helper.
 * Other checks left: the 15 places (`--target level_40..53`) once it matches; the file's flag line needs @ps2as.
 * Oddities kept from the twin: the colour words passed to the 3 `func_L39_00603F90` calls are built with
 * `*(u32 *)&fcf = 0x...` (retail computes the f32 argument from an integer immediate).
 */
#include "common.h"

/* localdecomp:start func_L39_006044E0 */
typedef struct { u8 p0[0x18]; f32 f18; s32 f1C; s32 f20; f32 f24; s8 b28; u8 p29[3]; s32 f2C; u8 p30[0x50]; s32 f80; s32 f84; } S_3A7E80;
typedef struct { u8 pad[0x30]; f32 m[4][4]; f32 v[4]; } S_3A7F90;
typedef struct { f32 a[3]; f32 b[3]; } V_7FC8;
extern u8 D_L39_002454E8[];
extern u8 D_L39_002454F8[];
extern u8 D_L39_00245508[];
extern u8 D_L39_00245510[];
extern u8 D_L39_00245520[];
extern u8 D_L39_00245530[];
extern u8 D_L39_00245540[];
extern u8 D_L39_00245550[];
extern u8 D_L39_00245560[];
extern u8 D_L39_00245570[];
extern u8 D_L39_00245580[];
extern u8 D_L39_00245590[];
extern u8 D_L39_002455A0[];
extern u8 D_L39_002455B0[];
extern u8 D_L39_002455C0[];
extern u8 D_L39_002455D0[];
extern u8 D_L39_002455E8[];
extern u8 D_L39_002455F8[];
extern u8 D_L39_00245608[];
extern u8 D_L39_00245618[];
extern u8 D_L39_00245628[];
extern s32 D_001A5810[];
extern s32 D_001D9F24_sda;
__asm__(".extern D_001D9F24_sda, 4");
extern s32 D_001D9F28_sda;
__asm__(".extern D_001D9F28_sda, 4");
extern f32 D_001D9F2C_sda;
__asm__(".extern D_001D9F2C_sda, 4");
extern f32 D_001D9F30_sda;
__asm__(".extern D_001D9F30_sda, 4");
extern f32 D_001D9F34_sda;
__asm__(".extern D_001D9F34_sda, 4");
extern s32 D_001D9F38_sda;
__asm__(".extern D_001D9F38_sda, 4");
extern s32 D_001D9F3C_sda;
__asm__(".extern D_001D9F3C_sda, 4");
extern s32 D_001D9F40_sda;
__asm__(".extern D_001D9F40_sda, 4");
extern s32 D_001D9F44_sda;
__asm__(".extern D_001D9F44_sda, 4");
extern f32 D_001D9F48_sda;
__asm__(".extern D_001D9F48_sda, 4");
extern f32 D_001D9F4C_sda;
__asm__(".extern D_001D9F4C_sda, 4");
extern f32 D_001D9F50_sda;
__asm__(".extern D_001D9F50_sda, 4");
extern s32 D_001D9F54_sda;
__asm__(".extern D_001D9F54_sda, 4");
extern s32 D_001D9F58_sda;
__asm__(".extern D_001D9F58_sda, 4");
extern s32 D_001D9F5C_sda;
__asm__(".extern D_001D9F5C_sda, 4");
extern void func_L39_00601478();
extern void func_L39_00601698(u8 *, u8 *, s32);
extern void func_L39_006010F8(void *, f32, f32, f32, f32);
extern void func_L39_00601220(void *, f32, f32, f32, f32);
extern s32 *func_L39_006010E0(void *);
extern s32 *func_L39_006010D8(void *);
extern void func_L39_00601128(void *, s32);
extern void func_L39_00601148(void *, s32);
extern void func_L39_006011B8(void *, s32);
extern void func_L39_00601A58();
extern void func_L39_00601C60(u8 *, s32, s32);
extern void func_L39_00601CD0();
extern void func_L39_00601D58(void *, s32);
extern void func_L01_004CD398(void *, s32);
extern void func_L39_00603E70(S_3A7E80 *);
extern void func_L01_004CF390(void *, s32);
extern void func_L39_00603F78(void *, s32);
extern u8 func_L39_00603F80(void *, u8);
extern void func_L39_00603F90(S_3A7F90 *, s32, f32, f32, f32, f32, f32);
extern void func_L39_00603FC8(V_7FC8 *, s32, f32, f32);
extern void func_L39_00603FE0(void *, s32);
extern void func_L39_00603FE8(u8 *, s32);
extern void func_L39_00604028(void *, s32);
extern void func_L39_00604030(void *, f32);
extern s32 func_L01_00521C90(s32, s32);
extern void *func_L39_00602190(void *);
extern void func_11D534(void *, s32, s32);
extern void func_120048(char *, u8 *, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
typedef struct { s32 pad0[0xE]; u8 pad38[2]; u8 flag3A; u8 pad3B; } T3C_006044E0;
typedef struct { s32 pad0[0xC]; } T30_006044E0;
typedef struct { s32 pad0[0x10]; } T40_006044E0;
typedef struct { s32 pad0[0x22]; } T88_006044E0;
typedef struct {
    T3C_006044E0 w000;
    T3C_006044E0 w03C;
    T3C_006044E0 w078;
    u8 bufB4[0x18];
    u8 padCC[4];
    T40_006044E0 w0D0;
    T30_006044E0 w110;
    T3C_006044E0 w140;
    T3C_006044E0 w17C;
    u8 buf1B8[0x18];
    T40_006044E0 w1D0;
    T30_006044E0 w210;
    u8 pad240[4];
    T3C_006044E0 w244;
    T3C_006044E0 w280;
    T3C_006044E0 items[8];
    T3C_006044E0 w49C;
    T3C_006044E0 w4D8;
    T3C_006044E0 w514;
    T3C_006044E0 w550;
    T3C_006044E0 w58C;
    T30_006044E0 w5C8;
    T30_006044E0 w5F8;
    T3C_006044E0 w628;
    T30_006044E0 rings[8];
    f32 *f7E4;
    T88_006044E0 fx7E8;
    T88_006044E0 fx870;
    T88_006044E0 fx8F8;
    T88_006044E0 fx980;
    T88_006044E0 fxA08;
    T88_006044E0 fxA90;
    void *fB18;
    void *fB1C;
    u8 padB20[8];
    s32 fB28;
    s32 fB2C;
    s32 fB30;
    s32 fB34;
    s32 fB38;
    s32 fB3C;
    u8 fB40;
    u8 padB41[3];
    s32 fB44;
} S_006044E0;





typedef void (*Init_006044E0)(void *, s32);

void func_L39_006044E0(S_006044E0 *p, u8 *base, s32 c) {
    char buf[16];
    s32 j;
    f32 *v;
    f32 x, y, a;
    s32 col;
    f32 fcf;

    p->fB40 = 0;
    p->fB44 = 0;
    func_L39_00601478(&p->w000, D_L39_002454E8, c);
    func_L39_00601698((u8 *)&p->w000, base + 0x7090, 0);
    func_L39_006010F8(&p->w000, 10.0f, 10.0f, 0.0f, 0.0f);
    p->w000.flag3A = 1;
    func_L39_00601478(&p->w03C, D_L39_002454F8, c);
    func_L39_006010F8(&p->w03C, 10.0f, 10.0f, 0.0f, 0.0f);
    func_L39_00601698((u8 *)&p->w03C, base + 0x7090, 0);
    p->w03C.flag3A = 1;
    func_L39_00601478(&p->w078, D_L39_00245508, c);
    func_L39_006010F8(&p->w078, 10.0f, 18.5f, 0.0f, 0.0f);
    func_L39_00601698((u8 *)&p->w078, base + 0x7090, 0);
    p->w078.flag3A = 1;

    func_11D534(p->bufB4, 0, 0x18);
    func_L39_00601CD0(&p->w0D0, D_L39_00245510, c);
    func_L39_00601220(&p->w0D0, 0.9f, 0.0f, 0.0f, 0.0f);
    func_L01_004CD398(&p->w0D0, (s32)p->bufB4);
    func_L39_006010F8(&p->w0D0, 64.0f, 15.0f, 0.0f, 0.0f);
    func_L39_00601D58(&p->w0D0, 0);
    func_L39_00601A58(&p->w110, D_L39_00245520, c);
    func_L39_00601220(&p->w110, 32.0f, 32.0f, 0.0f, 0.0f);
    func_L39_006010F8(&p->w110, 20.0f, 15.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_006010E0(&p->w110) = 0x60F0F0B0;

    func_L39_00601478(&p->w140, D_L39_00245530, c);
    func_L39_006010F8(&p->w140, 498.0f, 10.0f, 0.0f, 0.0f);
    func_L39_00601698((u8 *)&p->w140, base + 0x7090, 0);
    func_L39_00601478(&p->w17C, D_L39_00245540, c);
    func_L39_006010F8(&p->w17C, 498.0f, 10.0f, 0.0f, 0.0f);
    func_L39_00601698((u8 *)&p->w17C, base + 0x7090, 0);

    func_11D534(p->buf1B8, 0, 0x18);
    func_L39_00601CD0(&p->w1D0, D_L39_00245550, c);
    func_L39_00601220(&p->w1D0, 0.9f, 0.0f, 0.0f, 0.0f);
    func_L01_004CD398(&p->w1D0, (s32)p->buf1B8);
    func_L39_006010F8(&p->w1D0, 440.0f, 15.0f, 0.0f, 0.0f);
    func_L39_00601D58(&p->w1D0, 2);
    func_L39_00601A58(&p->w210, D_L39_00245560, c);
    func_L39_00601220(&p->w210, 32.0f, 32.0f, 0.0f, 0.0f);
    func_L39_006010F8(&p->w210, 457.0f, 15.0f, 0.0f, 0.0f);
    func_L39_00601C60((u8 *)&p->w210, 0x7567, 0);

    if (c != 0) {
        v = (f32 *)func_L01_00521C90(0x10, (s32)func_L39_00602190(c));
        p->f7E4 = v;
        v[1] = 0.0f;
        v[2] = 0.0f;
        v[3] = 0.0f;
        v[0] = 0.0f;
    }

    col = 0x1465B7;
    func_L39_00601478(&p->w244, D_L39_00245570, c);
    func_L39_00601698((u8 *)&p->w244, base + 0x7090, 0x29);
    func_L39_00601220(&p->w244, 1.0f, 1.0f, 0.0f, 0.0f);
    func_L39_006010F8(&p->w244, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_006010E0(&p->w244) = col;
    func_L39_006011B8(&p->w244, (s32)p->f7E4);
    p->w244.flag3A = 1;

    col = 0x2299DE;
    func_L39_00601478(&p->w280, D_L39_00245580, c);
    func_L39_00601698((u8 *)&p->w280, base + 0x7090, 0x25);
    func_L39_00601220(&p->w280, 1.0f, 1.0f, 0.0f, 0.0f);
    func_L39_006010F8(&p->w280, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_006010E0(&p->w280) = col;
    func_L39_006011B8(&p->w280, (s32)p->f7E4);
    p->w280.flag3A = 1;

    col = 0xFFFEED;
    func_L39_00601478(&p->w628, D_L39_00245590, c);
    func_L39_00601698((u8 *)&p->w628, base + 0x7090, 0x2A);
    func_L39_006010F8(&p->w628, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_006010E0(&p->w628) = col;
    func_L39_00601128(&p->w628, 0);
    p->w628.flag3A = 1;

    col = 0x8000FFFF;
    func_L39_00601478(&p->w49C, D_L39_002455A0, c);
    func_L39_00601698((u8 *)&p->w49C, base + 0x7090, 0x27);
    func_L39_006010F8(&p->w49C, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_006010E0(&p->w49C) = col;
    func_L39_006011B8(&p->w49C, (s32)p->f7E4);
    p->w49C.flag3A = 1;

    col = 0x80FFFF00;
    func_L39_00601478(&p->w4D8, D_L39_002455B0, c);
    func_L39_00601698((u8 *)&p->w4D8, base + 0x7090, 0x28);
    func_L39_006010F8(&p->w4D8, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_006010E0(&p->w4D8) = col;
    func_L39_006011B8(&p->w4D8, (s32)p->f7E4);
    p->w4D8.flag3A = 1;

    col = 0x800000FF;
    func_L39_00601478(&p->w514, D_L39_002455C0, c);
    func_L39_00601698((u8 *)&p->w514, base + 0x7090, 0x26);
    func_L39_006010F8(&p->w514, 125.0f, 208.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_006010E0(&p->w514) = col;
    func_L39_006011B8(&p->w514, (s32)p->f7E4);
    p->w514.flag3A = 1;

    col = 0x800000FF;
    func_L39_00601478(&p->w550, D_L39_002455D0, c);
    func_L39_00601698((u8 *)&p->w550, base + 0x7090, 0x8B);
    func_L39_006010F8(&p->w550, 52.0f, 281.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_006010E0(&p->w550) = col;
    func_L39_006011B8(&p->w550, (s32)p->f7E4);
    p->w550.flag3A = 1;
    v = (f32 *)func_L39_006010D8(&p->w550);
    *v = -*v;

    col = 0x800000FF;
    func_L39_00601478(&p->w58C, D_L39_002455E8, c);
    func_L39_00601698((u8 *)&p->w58C, base + 0x7090, 0x8A);
    func_L39_006010F8(&p->w58C, 52.0f, 281.0f, 0.0f, 0.0f);
    *(s32 *)func_L39_006010E0(&p->w58C) = col;
    func_L39_006011B8(&p->w58C, (s32)p->f7E4);
    p->w58C.flag3A = 1;
    v = (f32 *)func_L39_006010D8(&p->w58C);
    *v = -*v;

    func_L39_00601A58(&p->w5C8, D_L39_002455F8, c);
    func_L39_00601220(&p->w5C8, 32.0f, 32.0f, 0.0f, 0.0f);
    func_L39_006010F8(&p->w5C8, 24.0f, 278.0f, 0.0f, 0.0f);
    func_L39_00601C60((u8 *)&p->w5C8, 0xED51, 0);
    func_L39_00601128(&p->w5C8, 0);
    *(s32 *)func_L39_006010E0(&p->w5C8) = 0xF0F0B0;

    func_L39_00601A58(&p->w5F8, D_L39_00245608, c);
    func_L39_00601220(&p->w5F8, 32.0f, 32.0f, 0.0f, 0.0f);
    func_L39_006010F8(&p->w5F8, 23.0f, 277.0f, 0.0f, 0.0f);
    func_L39_00601C60((u8 *)&p->w5F8, 0xED56, 0);
    func_L39_00601128(&p->w5F8, 0);
    *(s32 *)func_L39_006010E0(&p->w5F8) = 0xF0F0B0;

    {
    s32 i;
    for (i = 0; i < 8; i++) {
        col = 0x1465B7;
        func_120048(buf, D_L39_00245618, i);
        func_L39_00601478(&p->items[i], buf, c);
        func_L39_00601698((u8 *)&p->items[i], base + 0x7090, i + 3);
        func_L39_00601220(&p->items[i], 1.0f, 1.0f, 0.0f, 0.0f);
        func_L39_006010F8(&p->items[i], 125.0f, 208.0f, 0.0f, 0.0f);
        func_L39_006011B8(&p->items[i], (s32)p->f7E4);
        p->items[i].flag3A = 1;
        *(s32 *)func_L39_006010E0(&p->items[i]) = col;

        col = 0xF0F0B0;
        func_120048(buf, D_L39_00245628, i);
        func_L39_00601A58(&p->rings[i], buf, c);
        func_L39_00601128(&p->rings[i], 0);
        a = func_0038DAB8((f32)i * 2.0f * 3.1415927f * 0.125f - 3.1415927f, 1.5707964f);
        x = (f32)(D_001D9F38_sda + D_001D9F24_sda + (s32)(D_001D9F2C_sda * func_0038D098(a) * D_001D9F30_sda));
        y = (f32)(D_001D9F3C_sda + D_001D9F28_sda + (s32)(D_001D9F2C_sda * func_0038D0B0(a) * D_001D9F34_sda));
        func_L39_006010F8(&p->rings[i], x, y, 0.0f, 0.0f);
        func_L39_00601220(&p->rings[i], 32.0f, 32.0f, 0.0f, 0.0f);
        *(s32 *)func_L39_006010E0(&p->rings[i]) = col;
    }
    }

    {
        s32 *q = (s32 *)func_L39_006010E0(&p->w5C8);
        *q = (*q & 0xFF000000) | 0x1465B7;
    }
    {
        s32 *q = (s32 *)func_L39_006010E0(&p->w5F8);
        *q = (*q & 0xFF000000) | 0x1465B7;
    }

    for (j = 0; j < 8; j++) {
        a = func_0038DAB8((f32)j * 2.0f * 3.1415927f * 0.125f - 3.1415927f, 1.5707964f);
        x = (f32)(D_001D9F54_sda + D_001D9F40_sda + (s32)(D_001D9F48_sda * func_0038D098(a) * D_001D9F4C_sda));
        y = (f32)(D_001D9F58_sda + D_001D9F44_sda + (s32)(D_001D9F48_sda * func_0038D0B0(a) * D_001D9F50_sda));
        func_L39_006010F8(&p->rings[j], x, y, 0.0f, 0.0f);
        func_L39_00601220(&p->rings[j], 32.0f, 32.0f, 0.0f, 0.0f);
        {
            s32 *q = (s32 *)func_L39_006010E0(&p->rings[j]);
            *q = (*q & 0xFF000000) | (D_001D9F5C_sda & 0xFFFFFF);
        }
    }

    for (j = 1; j < 8; j++) {
        func_L39_00601148(&p->items[j], func_L39_006010D8(&p->items[0]));
        func_L39_00601148(&p->rings[j], func_L39_006010D8(&p->rings[0]));
    }
    func_L39_00601148(&p->w244, func_L39_006010D8(&p->items[0]));

    ((Init_006044E0)func_L39_00603E70)(&p->fx7E8, c);
    func_L39_00603FE0(&p->fx7E8, 3);
    *(u32 *)&fcf = 0x442D00;
    func_L39_00603F90((S_3A7F90 *)&p->fx7E8, 0, 0.0f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x331465B7;
    func_L39_00603F90((S_3A7F90 *)&p->fx7E8, 1, 0.3f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x331465B7;
    func_L39_00603F90((S_3A7F90 *)&p->fx7E8, 2, 1.0f, fcf, 0.0f, 0.0f, 0.0f);
    func_L39_00603FC8((V_7FC8 *)&p->fx7E8, 1, 0.0f, 2.0f);
    func_L01_004CF390(&p->fx7E8, (s32)func_L39_006010E0(&p->items[0]));
    func_L39_00604028(&p->fx7E8, 0);
    func_L39_00603F78(&p->fx7E8, (s32)&p->fB1C);
    func_L39_00603FE8((u8 *)&p->fx7E8, -1);
    func_L39_00604030(&p->fx7E8, D_001A5810[0] ? 1.0f : 0.8333333f);
    func_L39_00603F80(&p->fx7E8, 0);

    ((Init_006044E0)func_L39_00603E70)(&p->fx870, c);
    func_L39_00603FE0(&p->fx870, 3);
    func_L39_00603F90((S_3A7F90 *)&p->fx870, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_L39_00603F90((S_3A7F90 *)&p->fx870, 1, 0.3f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_L39_00603F90((S_3A7F90 *)&p->fx870, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_L01_004CF390(&p->fx870, func_L39_006010D8(&p->items[0]));
    func_L39_00604028(&p->fx870, 0);
    func_L39_00603F78(&p->fx870, (s32)&p->fB18);
    func_L39_00603FE8((u8 *)&p->fx870, -1);
    func_L39_00604030(&p->fx870, D_001A5810[0] ? 1.0f : 0.8333333f);
    func_L39_00603F80(&p->fx870, 0);

    ((Init_006044E0)func_L39_00603E70)(&p->fxA08, c);
    func_L39_00603FE0(&p->fxA08, 3);
    *(u32 *)&fcf = 0xF0F0B0;
    func_L39_00603F90((S_3A7F90 *)&p->fxA08, 0, 0.0f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0xF0F0B0;
    func_L39_00603F90((S_3A7F90 *)&p->fxA08, 1, 0.5f, fcf, 0.0f, 0.0f, 0.0f);
    func_L39_00603FC8((V_7FC8 *)&p->fxA08, 0, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x80FFFFFF;
    func_L39_00603F90((S_3A7F90 *)&p->fxA08, 2, 1.0f, fcf, 0.0f, 0.0f, 0.0f);
    func_L39_00603FC8((V_7FC8 *)&p->fxA08, 1, 0.0f, 0.0f);
    func_L01_004CF390(&p->fxA08, (s32)func_L39_006010E0(&p->rings[0]));
    func_L39_00604028(&p->fxA08, 0);
    func_L39_00603F78(&p->fxA08, (s32)&p->fB1C);
    func_L39_00603FE8((u8 *)&p->fxA08, -1);
    func_L39_00604030(&p->fxA08, D_001A5810[0] ? 1.0f : 0.8333333f);
    func_L39_00603F80(&p->fxA08, 0);

    ((Init_006044E0)func_L39_00603E70)(&p->fx8F8, c);
    func_L39_00603FE0(&p->fx8F8, 3);
    *(u32 *)&fcf = 0xF0C070;
    func_L39_00603F90((S_3A7F90 *)&p->fx8F8, 0, 0.0f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x332299DE;
    func_L39_00603F90((S_3A7F90 *)&p->fx8F8, 1, 0.3f, fcf, 0.0f, 0.0f, 0.0f);
    *(u32 *)&fcf = 0x332299DE;
    func_L39_00603F90((S_3A7F90 *)&p->fx8F8, 2, 1.0f, fcf, 0.0f, 0.0f, 0.0f);
    func_L39_00603FC8((V_7FC8 *)&p->fx8F8, 1, 0.0f, 3.0f);
    func_L01_004CF390(&p->fx8F8, (s32)func_L39_006010E0(&p->w280));
    func_L39_00604028(&p->fx8F8, 0);
    func_L39_00603F78(&p->fx8F8, (s32)&p->fB1C);
    func_L39_00603FE8((u8 *)&p->fx8F8, -1);
    func_L39_00604030(&p->fx8F8, D_001A5810[0] ? 1.0f : 0.8333333f);
    func_L39_00603F80(&p->fx8F8, 0);

    ((Init_006044E0)func_L39_00603E70)(&p->fx980, c);
    func_L39_00603FE0(&p->fx980, 3);
    func_L39_00603F90((S_3A7F90 *)&p->fx980, 0, 0.0f, 1.2f, 1.2f, 0.0f, 0.0f);
    func_L39_00603F90((S_3A7F90 *)&p->fx980, 1, 0.3f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_L39_00603F90((S_3A7F90 *)&p->fx980, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_L01_004CF390(&p->fx980, func_L39_006010D8(&p->w280));
    func_L39_00604028(&p->fx980, 0);
    func_L39_00603F78(&p->fx980, (s32)&p->fB18);
    func_L39_00603FE8((u8 *)&p->fx980, -1);
    func_L39_00604030(&p->fx980, D_001A5810[0] ? 1.0f : 0.8333333f);
    func_L39_00603F80(&p->fx980, 0);

    ((Init_006044E0)func_L39_00603E70)(&p->fxA90, c);
    func_L39_00603FE0(&p->fxA90, 3);
    func_L39_00603F90((S_3A7F90 *)&p->fxA90, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_L39_00603F90((S_3A7F90 *)&p->fxA90, 1, 0.01f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_L39_00603F90((S_3A7F90 *)&p->fxA90, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_L01_004CF390(&p->fxA90, (s32)p->f7E4);
    func_L39_00604028(&p->fxA90, 0);
    func_L39_00603F78(&p->fxA90, (s32)&p->fB18);
    func_L39_00603FE8((u8 *)&p->fxA90, -1);
    func_L39_00604030(&p->fxA90, D_001A5810[0] ? 1.0f : 0.8333333f);
    func_L39_00603F80(&p->fxA90, 0);

    p->fB28 = 0;
    p->fB2C = -1;
    p->fB30 = 0;
    p->fB34 = -1;
    p->fB38 = 0;
    p->fB3C = -1;
}
/* localdecomp:end func_L39_006044E0 */

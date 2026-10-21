#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void func_003D9CF0(void);
extern void func_003D8640(void);
extern void func_003D9C30(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003D9DA8();
extern void func_003D8640();
extern void func_003D9450();
extern void func_003D9740(void *, s32, s32, s32, s32, f32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003D6A20 */
void func_003D6A20(s32 *p, s32 n) { s32 t = *p; t = (t + 0x1FFF) & -0x2000; *p = t + n; }
/* localdecomp:end func_003D6A20 */

/* localdecomp:start func_003D6A40 */
void func_003D6A40(long **pp, s32 x0, s32 y0, s32 x1, s32 y1, s32 z) {
    s32 n, step, i, d;
    unsigned long *p, *q;
    s32 x;
    d = x1 - x0;
    x = x0;
    n = d >> 9;
    step = d / n;
    p = (unsigned long *)*pp;
    *p = (unsigned long)(n | 0x8000) | 0x2400000000000000UL;
    p += 1;
    *pp = (long *)p;
    *p = 0x55;
    *pp = (long *)(p + 1);
    for (i = 0; i < n; i++) {
        q = (unsigned long *)*pp;
        *q = (unsigned long)x | ((long)y0 << 16) | ((long)z << 32);
        q += 1;
        *pp = (long *)q;
        x += step;
        *q = (unsigned long)x | ((long)y1 << 16) | ((long)z << 32);
        *pp = (long *)(q + 1);
    }
}
/* localdecomp:end func_003D6A40 */

/* localdecomp:start func_003D6AE0 */
void func_003D6AE0(long **pp, s32 x0, s32 y0, s32 u0, s32 v0, s32 x1, s32 y1, s32 u1, s32 v1) {
    s32 n, dx, du, i;
    unsigned long *p, *q;
    s32 x, u, nu, nx;
    dx = x1 - x0;
    du = u1 - u0;
    x = x0;
    u = u0;
    n = dx >> 9;
    dx = dx / n;
    du = du / n;
    p = (unsigned long *)*pp;
    *p = (unsigned long)(n | 0x8000) | 0x4400000000000000UL;
    p += 1;
    *pp = (long *)p;
    *p = 0x5353;
    *pp = (long *)(p + 1);
    for (i = 0; i < n; i++) {
        q = (unsigned long *)*pp;
        *q = (unsigned long)u | ((long)v0 << 16);
        q += 1;
        *pp = (long *)q;
        *q = (unsigned long)x | ((long)y0 << 16);
        *pp = (long *)(q + 1);
        nu = u + du;
        *(q + 1) = (unsigned long)nu | ((long)v1 << 16);
        *pp = (long *)(q + 2);
        nx = x + dx;
        *(q + 2) = (unsigned long)nx | ((long)y1 << 16);
        *pp = (long *)(q + 3);
        u = nu;
        x = nx;
    }
}
/* localdecomp:end func_003D6AE0 */

extern s32 D_001D5600;
extern s32 D_001D5604;
extern s32 D_001D4BD0_003D6BC0;
extern s32 D_001D4BD4_003D6BC0;
INCLUDE_ASM("asm/nonmatchings/text", func_003D6BC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D6EE8);

LINKER_REMNANT("asm/remnants", func_003D7078);

INCLUDE_ASM("asm/nonmatchings/text", func_003D7080);

/* localdecomp:start func_003D72B0 */
void func_003D72B0(u8 **pp, s32 a1, s32 w, s32 h, s32 a4, s32 w2, s32 h2) {
    s32 lw, lh;
    s32 sw, sh, ow, oh;
    s32 k1, k2;
    sw = w << 4;
    sh = h << 4;
    ow = (w2 << 4) + 0x98;
    oh = (h2 << 4) + 0x98;
    k1 = 0x98;
    k2 = 0x98;
    w = (w > 0x3F) ? w : 0x40;
    h = (h > 0x3F) ? h : 0x40;
    w2 = (w2 > 0x3F) ? w2 : 0x40;
    h2 = (h2 > 0x3F) ? h2 : 0x40;
    if (w & (w - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(w));
        lw = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(w));
        lw = 0x1E - t; }
    }
    if (h & (h - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(h));
        lh = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(h));
        lh = 0x1E - t; }
    }
    func_003D7080((long **)pp, a1, w, h, w >> 6, lw, lh, a4, w2, h2, w2 >> 6, k1, k2,
                  ow, oh, 0, 0, sw, sh);
}
/* localdecomp:end func_003D72B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003D73D8);

LINKER_REMNANT("asm/remnants", func_003D7848);

/* localdecomp:start func_003D7850 */
extern void func_003D73D8(s32, s32, s32, s32, s32);
 
void func_003D7850(s32 a0, s32 a1, s32 a2) {
    func_003D73D8(a0, a1, 0x100, 0x100, a2);
}
/* localdecomp:end func_003D7850 */

/* localdecomp:start func_003D7878 */
extern void func_003D73D8(s32, s32, s32, s32, s32);
 
void func_003D7878(s32 a0, s32 a1, s32 a2) {
    func_003D73D8(a0, a1, 0x80, 0x80, a2);
}
/* localdecomp:end func_003D7878 */

/* localdecomp:start func_003D78A0 */
extern void func_003D73D8(s32, s32, s32, s32, s32);
 
void func_003D78A0(s32 a0, s32 a1, s32 a2) {
    func_003D73D8(a0, a1, 0x40, 0x40, a2);
}
/* localdecomp:end func_003D78A0 */

LINKER_REMNANT("asm/remnants", func_003D78C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D78E0);

/* func_003D7D30: from the US C of func_003D27C0 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags.

   PAL: retail reaches D_001D5608/D_001D5610/D_001D5614/D_001D561C through $gp and
   D_001D5624/D_001D560C/D_001D5620/D_001D55EC with lui/%lo, so the second group is declared
   to the assembler as not small data (the same trick the matched func_003D9100 of this
   file uses for its own globals). */


/* localdecomp:start func_003D7D30 */
extern s32 func_003D6A20_003D7D30(s32 *, s32);
extern void func_003D7DE8(void);
extern void func_003D8500(void);
__asm__(".extern D_001D5608, 4");
__asm__(".extern D_001D5610, 4");
__asm__(".extern D_001D5614, 4");
__asm__(".extern D_001D561C, 4");
__asm__(".extern D_001D5624, 16");
__asm__(".extern D_001D560C, 16");
__asm__(".extern D_001D5620, 16");
__asm__(".extern D_001D55EC, 16");
extern s32 D_001D5608, D_001D5610, D_001D5614, D_001D561C;
extern s32 D_001D5624, D_001D560C, D_001D5620, D_001D55EC;
extern s32 D_001A1ED4[];
void func_003D7D30(void) {
    s32 p, r1, r2, r3;
    D_001D5608 = 0x3FA000;
    D_001D560C = 0x3FE000;
    D_001D5624 = 0x400000;
    p = 0x379000;
    r1 = func_003D6A20_003D7D30(&p, 0x40000);
    p = 0x379000;
    D_001D5614 = r1;
    r2 = func_003D6A20_003D7D30(&p, 0x40000);
    D_001D561C = r2;
    r3 = func_003D6A20_003D7D30(&p, 0x40000);
    D_001D5620 = r3;
    D_001D5610 = D_001A1ED4[0];
    func_003D7DE8();
    func_003D8500();
    D_001D55EC = D_001D55EC | 1;
}
/* localdecomp:end func_003D7D30 */

extern s32 D_001D0A50[];
extern s32 D_001D5600, D_001D5604, D_001D5608_003D7DE8, D_001D5610_003D7DE8, D_001D5614_003D7DE8, D_001D561C_003D7DE8, D_001D5620, D_001D55F0;
extern u8 D_001D936C;
extern s32 D_001D9350, D_001D9354, D_001D9358, D_001D935C;
extern void func_003D6EE8(long **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003D78E0(long **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003D7DE8);

extern s32 D_001D5608_003D8500, D_001D5620, D_001D561C_003D8500, D_001D9360, D_001D55F4;
extern u8 D_001D2A50[];
extern void func_003D6BC0(u8 **, s32, s32, s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003D8500);

extern s32 D_001D55F0;
extern u32 *D_001DA050;
extern s32 D_001D934C;
extern s32 D_001D0A50[];
INCLUDE_ASM("asm/nonmatchings/text", func_003D85C0);

/* Candidate for func_003D8640 (frontbin, PAL).
   Retail loads D_001D55F4 and D_001DA050 through lui/%lo (the assembler picks
   the non-$gp form for them), but writes D_001D934C and D_001DA050 through
   $gp.  A scalar declaration plus a ".extern X, 16" size hint gives the lui
   form for the reads, the plain sized name gives $gp for the writes. */

extern u32 *D_001DA050;
extern s32 D_001D934C;
extern u8 D_001D2A50[];
extern int D_001D55F4_003D8640;
__asm__(".extern D_001D55F4_003D8640, 16");
extern int D_001DA050_003D8640;
__asm__(".extern D_001DA050_003D8640, 16");

/* localdecomp:start func_003D8640 */
extern u32 *D_001DA050;
extern u8 D_001D2A50[];
extern s32 D_001D934C;
void func_003D8640(void) {
    ((u32 *)D_001DA050_003D8640)[0] = (D_001D55F4_003D8640 >> 4) | 0x30000000;
    ((u32 *)D_001DA050_003D8640)[1] = (u32)D_001D2A50;
    ((u32 *)D_001DA050_003D8640)[2] = 0;
    ((u32 *)D_001DA050_003D8640)[3] = (D_001D55F4_003D8640 >> 4) | 0x50000000;
    D_001D934C = 0;
    D_001DA050 = (u32 *)D_001DA050_003D8640 + 4;
}
/* localdecomp:end func_003D8640 */

extern s32 D_001A1ED0[];
INCLUDE_ASM("asm/nonmatchings/text", func_003D86B8);

extern s32 D_001A1ED0[];
INCLUDE_ASM("asm/nonmatchings/text", func_003D8998);

typedef struct { s32 f0; s32 f4; s32 f8; } T_3D3780;
extern T_3D3780 D_001A1ED0_003D8CF0;
INCLUDE_ASM("asm/nonmatchings/text", func_003D8CF0);

extern s32 D_001D5600_003D8FC0;
extern s32 D_001D5604_003D8FC0;
extern s32 D_001D5628_003D8FC0;
extern s32 D_001D5630_003D8FC0;
extern s32 D_001D5634_003D8FC0;
extern s32 D_001D55F8_003D8FC0;
extern u8 D_001D3650_003D8FC0[];
INCLUDE_ASM("asm/nonmatchings/text", func_003D8FC0);

/* localdecomp:start func_003D9100 */
extern s32 D_001D5600_003D9100;
__asm__(".extern D_001D5600_003D9100, 16");
extern s32 D_001D5604_003D9100;
__asm__(".extern D_001D5604_003D9100, 16");
extern s32 D_001D5628_003D9100;
__asm__(".extern D_001D5628_003D9100, 16");
extern s32 D_001D55FC_003D9100;
__asm__(".extern D_001D55FC_003D9100, 16");
extern u8 D_001D3EF0[];
extern s32 func_003D86B8();
extern s32 func_003D8998();
extern s32 func_003D8CF0();
extern void func_003D6BC0(u8 **, s32, s32, s32, s32, s32, s32);
void func_003D9100(void) {
    u8 *p;
    p = D_001D3EF0;
    func_003D86B8(&p, D_001D5600_003D9100, D_001D5604_003D9100, D_001D5600_003D9100 >> 6, 0, 0, (D_001D5600_003D9100 + 1) << 4, (D_001D5604_003D9100 + 1) << 4);
    func_003D8998(&p, 1);
    func_003D8CF0(&p, D_001D5600_003D9100, D_001D5604_003D9100, D_001D5600_003D9100 >> 6, 0, 0, (D_001D5600_003D9100 + 1) << 4, (D_001D5604_003D9100 + 1) << 4, 0xFF82FF);
    func_003D6BC0(&p, D_001D5628_003D9100, 0x100, 0x100, 0, 1, 0x80);
    D_001D55FC_003D9100 = (s32)p - (s32)D_001D3EF0;
}
/* localdecomp:end func_003D9100 */

extern void func_003D8FC0(void);
extern s32 D_001D5634;
extern s32 D_001D5630;
extern s32 D_001D5628;
extern s32 D_001A1ED4[];
extern s32 D_001D55EC;
INCLUDE_ASM("asm/nonmatchings/text", func_003D91F0);

/* localdecomp:start func_003D9260 */
/* PAL candidate for func_003D9260 (frontbin).
 *
 * Retail reaches D_001D55F8, D_001D55FC and D_001DA050 through lui/lo, not
 * through $gp: the .extern size hints tell the assembler the globals are not
 * small data, so it expands the $gp access into lui + lw (or lui $at + sw).
 * The last store of the pointer is the one retail reaches through $gp (it
 * sits in the delay slot of the jr), so it uses a second name for the same
 * address, without a size hint.
 */

extern u32 *D_001DA050;
__asm__(".extern D_001DA050, 16");
extern u32 *D_001DA050_003D9260;
extern s32 D_001D55F8;
__asm__(".extern D_001D55F8, 16");
extern s32 D_001D55FC;
__asm__(".extern D_001D55FC, 16");
extern u8 D_001D3650[];
extern u8 D_001D3EF0[];

void func_003D9260(void) {
    D_001DA050[0] = (D_001D55F8 >> 4) | 0x30000000;
    D_001DA050[1] = (u32)D_001D3650;
    D_001DA050[2] = 0;
    D_001DA050[3] = (D_001D55F8 >> 4) | 0x50000000;
    D_001DA050 += 4;
    D_001DA050[0] = (D_001D55FC >> 4) | 0x30000000;
    D_001DA050[1] = (u32)D_001D3EF0;
    D_001DA050[2] = 0;
    D_001DA050[3] = (D_001D55FC >> 4) | 0x50000000;
    D_001DA050_003D9260 = D_001DA050 + 4;
}
/* localdecomp:end func_003D9260 */

/* func_003D9338: from the US C of func_003D3DC8 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003D9338 */
extern s32 D_001D5604_003D9338;
extern s32 D_001D5604_003D9338 __attribute__((section(".bss")));
typedef struct { u8 pad[0x150]; s16 h150; s16 h152; } S_1CFEC0;
extern S_1CFEC0 D_1CFEC0;
extern s32 D_001D5604;
extern s32 D_001D5600;
extern void func_003D7D30_003D9338();
extern void func_003D91F0();
void func_003D9338(void) {
    S_1CFEC0 *p = &D_1CFEC0;
    D_001D5600 = p->h150;
    /* retail reaches 0x001D5604 with lui $at + sw (not through $gp): with the
       default assembler no single declaration gives that mixed access, so the
       store goes through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did). */
    D_001D5604_003D9338 = p->h152;
    func_003D7D30_003D9338();
    func_003D91F0();
}
/* localdecomp:end func_003D9338 */

LINKER_REMNANT("asm/remnants", func_003D9378);

/* localdecomp:start func_003D93B0 */
extern long func_00389598(s32);
extern u8 D_00380E60[];

void func_003D93B0(void *arg0, s32 arg1, s32 arg2, long arg3) {
    void *temp_s0;

    (*(long *)((u8 *)(arg0) + 0x78)) = func_00389598(arg1);
    (*(long *)((u8 *)(arg0) + 0x80)) = (long) (0xFF9000000000 | 0x260);
    (*(long *)((u8 *)(arg0) + 0x70)) = 0;
    temp_s0 = (arg2 * 0x14) + D_00380E60;
    (*(long *)((u8 *)(arg0) + 0x88)) = (long) ((*(s32 *)((u8 *)(temp_s0) + 0)) | ((long) (*(s32 *)((u8 *)(temp_s0) + 4)) * 4) | ((long) (*(s32 *)((u8 *)(temp_s0) + 8)) * 0x10) | ((long) (*(s32 *)((u8 *)(temp_s0) + 0xC)) << 6) | (arg3 << 0x20));
}
/* localdecomp:end func_003D93B0 */

/* localdecomp:start func_003D9450 */
typedef int u128_3D3EE0 __attribute__((mode(TI)));
extern void func_003D93B0(void *, s32, s32, long);
void func_003D9450(u8 *p, s32 a1, s32 a2, f32 *src, u128_3D3EE0 *q, s32 a5) {
    s32 i;
    f32 *fp;
    s32 *ip;
    func_003D93B0(p, a1, a5, 0x80);
    ip = (s32 *)(p + 0x40);
    fp = (f32 *)(p + 0x54);
    for (i = 0; i < 4; i++) {
        fp[i * 2 - 1] = src[i * 2];
        fp[i * 2] = src[i * 2 + 1];
        ip[i] = a2;
        ((u128_3D3EE0 *)p)[i] = q[i];
    }
}
/* localdecomp:end func_003D9450 */

INCLUDE_ASM("asm/nonmatchings/text", func_003D94E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D9508);

typedef int Q_3D3FA0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3D3FA0;
typedef struct { V_3D3FA0 v[4]; s32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } B_3D3FA0;
extern V_3D3FA0 D_00222400_003D3FA0[];
extern V_3D3FA0 D_001D9180[];
typedef struct { u8 pad[0x80]; f32 f80[4]; u8 pad2[0x3D0]; } G_3D3FA0;
extern G_3D3FA0 D_002225D0_003D3FA0[];
extern u8 D_002225D0[];
extern s32 D_001D52F0;
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

LINKER_REMNANT("asm/remnants", func_003D96F8);

typedef struct { f32 x, y, z; } P_3D41E0;
typedef struct { f32 a, b; } T_3D41E0;
extern f32 D_001D9390;
extern f32 D_001D93C0;
extern s32 D_001D9348;
extern P_3D41E0 D_002FF880[];
extern s32 D_002FF988[];
extern T_3D41E0 D_002FF9E0[];
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern void func_0038D028();
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003D9740);

INCLUDE_ASM("asm/nonmatchings/text", func_003D9BE0);

/* func_003D9C00: PAL frontbin.
 *
 * Retail (PAL, 0x003D9C00):
 *   addiu $sp, $sp, -0x10
 *   lui   $4, 0x1d
 *   lw    $4, 0x4bb0($4)
 *   sd    $31, 0($sp)
 *   jal   func_003DCBF0
 *   jal   func_003A9618
 *   ld    $31, 0($sp)
 *   jr    $31
 *
 * The global read is the "no split" form: the high part of the address is
 * materialised in the destination register itself ($4), so the load reads
 * %lo(D)($4) instead of %lo(D)($2).  With a plain, size-less declaration
 * gcc materialises the address in the split-address register ($2), giving
 * "lui $2 / lw $4, lo($2)".  A sized declaration makes gcc emit a $gp
 * relative reference, and the assembler expands that back into the
 * lui/lw pair with the destination register as the base, which is exactly
 * what retail has.
 */

/* localdecomp:start func_003D9C00 */
extern s32 D_001D4BB0_003D9C00;
__asm__(".extern D_001D4BB0_003D9C00, 16");
extern void func_003DCBF0(s32);
extern void func_003A9618(void);
void func_003D9C00(void) {
    func_003DCBF0(D_001D4BB0_003D9C00);
    func_003A9618();
}
/* localdecomp:end func_003D9C00 */

/* localdecomp:start func_003D9C30 */
typedef struct { s16 a; s16 b; } T_D46E0;
typedef struct { u8 p0[0x33]; u8 f33; } E_D46E0;
typedef struct { u8 p0[0xF]; u8 cnt; u8 q[0xC]; E_D46E0 *ent; } O_D46E0;
extern s32 D_00304EC0[];
extern O_D46E0 *D_002FFAC0[];
extern T_D46E0 D_003048C0[];
void func_003D9C30(void) {
    s32 *p;
    s32 i;
    O_D46E0 *o;
    u8 *e;
    for (p = D_00304EC0; *p >= 0; p++) {
        o = D_002FFAC0[*p];
        e = (u8 *)o->ent;
        for (i = 0; i < o->cnt; i++) {
            T_D46E0 *t = &D_003048C0[e[0x33]];
            if (t->a != 0) { *(u32 *)e = (*(u32 *)e & 0xFFFFC000) | t->a; }
            if (t->b != 0) { *(u32 *)(e + 0x20) = (*(u32 *)(e + 0x20) & 0xFFFFC000) | t->b; }
            e += 0x50;
        }
    }
}
/* localdecomp:end func_003D9C30 */

extern s32 D_001D4BB4;
void func_0038CD28(s32, s32 *, s32);
void func_003A8F90(s32 *);
extern void func_003A9440(s32, unsigned long);
void func_003DAD90();
void func_003DC160();
void func_003DCEA0();
void func_11F0A0(s32);
extern s32 D_001D4BB0_003D9CF0;
extern u8 D_001D7960[];
extern s32 D_001DA050_003D9CF0;
extern u8 D_100AE0[];
extern u8 D_1159B0[];
INCLUDE_ASM("asm/nonmatchings/text", func_003D9CF0);

LINKER_REMNANT("asm/remnants", func_003D9DA0);

typedef struct {
    u8 pad[0x7614];
    s32 value;
} SourceBlock_003D4858;
extern u8 *D_001DA704;
extern u8 *D_001DA708;
extern s32 D_001DA710;
extern s32 D_001DA728;
extern s32 D_001DA72C;
extern s32 D_001DA730;
extern u8 *D_001DA734;
INCLUDE_ASM("asm/nonmatchings/text", func_003D9DA8);

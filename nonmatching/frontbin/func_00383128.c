/* Near miss of func_00383128 with its file's own flags: tools/check.py reports 20 diff
   (the version it replaces: 88).
*/

/* PAL candidate for func_00383128 (US draft rac3-uya-decomp func_0037EE80, commit 13cf5c5).

   The US matched this with @ps2as, where Ps2EeAs expands a $gp-relative load of a
   sized scalar into "lui $r, %hi(sym); lw $r, %lo(sym)($r)".  Retail PAL does
   reach D_001D9A84 that way, but with this file's flags (default assembler) a
   sized scalar comes out $gp-relative.  An unsized array is never small data,
   so gcc itself emits the split form (lui %hi / lw %lo) with the same
   register, as in the matched func_003B2A00 (D_001DA0B4[0]).

   The file already declares D_001D9A84_00383128 as a sized pointer (small
   data), so the lui form needs a second name for the same address:
   D_001D9A84_00383128_lui (add "D_001D9A84_00383128_lui = 0x001D9A84;" to
   config/frontbin/symbol_addrs_resolved.txt when integrating). */


/* localdecomp:start func_00383128 */
typedef struct { u8 p0[0xC]; s32 fC; u8 p10[0x24 - 0x10]; s32 f24; } T_37EE80;
typedef struct { u8 p0[0x1C]; T_37EE80 *f1C; } R_37EE80;
typedef struct { u8 p0[0x5D0]; s32 f5D0; u8 p5D4[0x5E0 - 0x5D4]; s32 f5E0; u8 p5E4[0x690 - 0x5E4]; s32 f690; u8 p694[0x6A0 - 0x694]; s32 f6A0; u8 p6A4[0x25CC - 0x6A4]; s32 f25CC; } A_37EE80;
typedef struct { u8 p0[0x24C]; s32 f24C; u8 p250[0x460 - 0x250]; } E_37EE80;
extern u8 *D_001D9A84_00383128_lui[];
typedef struct { u8 p0[0x10]; s32 f10; u8 p14[0xC]; } G2_37EE80;
extern G2_37EE80 *D_001D9E50;
extern A_37EE80 D_001A4BE0_00383128;
extern E_37EE80 D_00222480_00383128[];
extern u8 D_002225D0[];
extern s32 func_00382380(void *, s32, s32);
s32 func_00383128(s32 idx, u8 *o, u8 *t) {
    u8 *s = o + 0x74;
    s32 (*f)(u8 *, u8 *);
    s32 r;
    if (o[0x7C] == 0) return 0;
    f = (s32 (*)(u8 *, u8 *))D_00380F80[*(s16 *)(o + 0x8C)].b;
    if (f != 0) {
        r = f(o, t);
        if (r == -1) return 0;
        if (r == 1) return 1;
    }
    switch (*(s32 *)s) {
    case 1:
    case 2:
        if (s[9] == 0) break;
    case 0:
        if (t == 0) return 1;
        if (*(s16 *)(t + 0x7E) != 0) return 1;
        if (s[8] > t[0x7C]) return 1;
        break;
    case 4: {
        T_37EE80 *e = ((R_37EE80 *)(D_001D9A84_00383128_lui[0] + *(s16 *)(o + 0x84) * 32))->f1C;
        if (t != 0 && *(s16 *)(t + 0x7E) == 0 && !(s[8] > t[0x7C])) break;
        { u8 *p = D_002225D0 + idx * 0x460; if (func_00382380(p + 0x40, e->fC, 0) != 0) return 1; }
        break;
    }
    case 7: {
        s32 h = *(s16 *)(o + 0x86);
        T_37EE80 *e;
        s32 a5, a7, k;
        if (h != ((E_37EE80 *)(idx * 0x460 + (s32)D_00222480_00383128))->f24C) break;

        if (*(s16 *)(t + 0x7E) == 0 && !(s[8] > t[0x7C])) break;
        if (h != 3) return 1;
        e = ((R_37EE80 *)((s32)D_001D9A84_00383128_lui[0] + (*(s16 *)(o + 0x84) << 5)))->f1C;
        if (D_001A4BE0_00383128.f25CC == 0x1A) {
            a5 = D_001A4BE0_00383128.f690;
            a7 = D_001A4BE0_00383128.f6A0;
        } else {
            a5 = D_001A4BE0_00383128.f5D0;
            a7 = D_001A4BE0_00383128.f5E0;
        }
        k = e->f24;
        if (k < 0) return 1;
        if (a5 != D_001D9E50[k].f10) break;
        if (a7 == 0) return 1;
        break;
    }
    }
    return 0;
}
/* localdecomp:end func_00383128 */

/* Near miss of func_00398A88 with its file's own flags: tools/check.py reports 7 diff
   (the version it replaces: 69).
*/

/* PAL candidate for func_00398A88 (frontbin).
 *
 * The retail PAL bytes were produced with SN's Ps2EeAs assembler.  Two of its
 * effects show up in this function and the file's flags here use GNU as
 * (ee-as) instead, so the C is written so that the compiler itself emits the
 * retail's instructions:
 *
 *  - The retail loads D_001D4B64/D_001D4B68/D_001D4B70 through %hi/%lo pairs
 *    (lui/lw, lui/addiu); Ps2EeAs does that conversion for symbols it has no
 *    size hint for, ee-as keeps them $gp-relative.  The size hints below tell
 *    ee-as the symbols are not in the small data section, so it converts them
 *    the same way Ps2EeAs did.
 *  - The 64-bit constant 0x40000400004000 is an or/shift chain in the retail
 *    (Ps2EeAs's expansion of the compiler's "dli"); ee-as expands the same
 *    "dli" into a lui/ori/dsll32/ori sequence instead.
 */

extern unsigned long D_0022CAD0[3];
extern s32 D_002DDC30[];
extern s32 D_002DA740[];
extern s32 D_001D4B64;
extern s32 D_001D4B68;
extern unsigned long D_001D4B70[1];
__asm__(".extern D_001D5F40, 4");
extern s32 D_001D5F40;
extern s32 D_002DE3B0[];
typedef struct { u8 p0[8]; u8 f8; u8 f9; u8 pa[5]; u8 fF; u8 p10[4]; s32 f14; } S_393C98;
typedef struct { s32 a; s32 b; } E_393C98;
extern E_393C98 D_00337480[];
extern void func_00399928();
extern void func_0038CB78();
extern s32 func_00381CB0();
extern void func_0038CD28();
__asm__(".extern D_001D4B64, 16");
__asm__(".extern D_001D4B68, 16");
__asm__(".extern D_001D4B70, 16");
void func_00398A88(s32 a) {
    s32 i, n;
    S_393C98 *p;
    n = D_001D4B68;
    for (i = 0; i < n; i++) {
        D_0022CAD0[i * 3] = D_001D4B70[i];
        D_0022CAD0[i * 3 + 1] = 0xFFA0000000E0;
        D_0022CAD0[i * 3 + 2] = 0x40000400004000;
    }
    func_00399928(D_001D4B64, 0, &D_001D5F40);
    D_002DDC30[0] = 0xFFFC0000;
    func_0038CB78(D_002DE3B0, -1, 0x10);
    {
        S_393C98 *p1 = ((S_393C98 **)D_002DA740)[0];
        p1->f9 = p1->f8;
    }
    if (func_00381CB0() > 0) a = func_00381CB0();
    p = ((S_393C98 **)D_002DA740)[0];
    func_0038CD28(p->f14 - (p->f14 & 0) - (p->fF << 4), D_00337480[a].a, D_00337480[a].b);
}

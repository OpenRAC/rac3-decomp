/* Near miss of func_0039EC28 with its file's own flags: tools/check.py reports 144 diff
   (the version it replaces: 166).
   What differs: Retail reaches every global through lui/lo (it was assembled with SN's
   Ps2EeAs, which only uses $gp when it already knows the symbol is small, and uses $gp in a
   branch delay slot). With this file's flags (default ee-as, -fno-force-mem) gcc has to
   produce those lui/lo pairs itself: raw addresses give the one-register form retail has,
   unsized per-use aliases give the %hi/%lo form retail has for addresses it computes into a
   register, and only the delay-slot load of D_001D545C stays on the sized symbol. Still
   differs: (1) the first read of D_001D4CF0 - retail has `lui $v0,0x1d; lw...
*/

/* US draft of func_0039EC28 (rac3-uya-decomp func_00399C90, commit 13cf5c5), names moved to PAL addresses
   where known. PAL: retail reaches these globals through lui/lo (the US build used Ps2EeAs). The raw
   addresses below reproduce that with this file's own flags; the unsized aliases give the %hi/%lo
   form for the addresses retail computes into a register. Only the load of D_001D545C that sits in a
   branch delay slot stays on the sized symbol, which is what retail does there. */

/* localdecomp:start func_0039EC28 */
extern s32 func_0039EC28(s32, s32);
typedef struct { u8 b[8]; } V8_399C90;
typedef struct { s32 f0, f4, f8, fC; V8_399C90 f10; s32 f18; } E_399C90;
typedef struct { u8 p0[0x18]; s16 h18; u8 p1a[0x16]; E_399C90 e[4]; u8 pA0[0xA8]; s32 f148; s32 f14C; s32 f150; u8 p154[8]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; u8 p16C[0x10]; s32 f17C; } S_399C90;
typedef struct { s32 f0; u8 p4[0x2E]; u8 b32; } T_399C90;
extern S_399C90 D_142430_0039EC28;
extern T_399C90 D_142660_0039EC28;
extern u32 D_001D545C;
extern s32 D_001D4CEC_0039EC28a[];
extern s32 D_001D4CF0_0039EC28[];
extern V8_399C90 D_001D4BE0_0039EC28a[];
extern V8_399C90 D_001D4BE0_0039EC28b[];
extern V8_399C90 D_001D4BE0_0039EC28c[];
extern u8 D_001D5570_0039EC28a[];
extern u8 D_001D5570_0039EC28b[];
extern u8 D_1A9318[];
extern u8 D_001C5BD0[];
extern u8 D_001CBBD0[];
extern u8 D_00332388[];
extern u8 D_00332618[];
extern void func_003A0090();
s32 func_0039EC28(s32 a, s32 b) {
    u8 *q;
    s32 old;
    if ((u32)(D_001D4CF0_0039EC28[0] - 0x1E) < 7) return 0;
    if (b == 0x18) return 0;
    if ((u32)(b - 0x1F) < 5) b = 3;
    if (*(u32 *)0x1D545C == 0x1E) return 0;
    if (*(u32 *)0x1D545C == 0x24) return 0;
    if (b == 0x1E) return 0;
    if (b == 0x24) return 0;
    func_12BE28(D_001D4BE0_0039EC28a);
    func_13AD58(D_001D4BE0_0039EC28b);
    func_003A0090();
    func_0039FA88(D_1A9318 + (*(u32 *)0x1D545C << 11));
    if (D_142430_0039EC28.f148 == -1 || ((S_399C90 *)((u8 *)&D_142430_0039EC28 + D_142430_0039EC28.f148 * 0xA0))->h18 < 0) return a == 0;
    D_142430_0039EC28.f17C |= a;
    if (D_142430_0039EC28.f17C != 0) {
        if (a == 0) *(s32 *)0x1D4CEC = D_001D4CEC_0039EC28a[0] | 0x200;
        if (D_142430_0039EC28.f15C < 3 && D_142430_0039EC28.f164 < 0) {
            D_142430_0039EC28.f150 = *(u32 *)0x1D545C;
            old = 0;
            if (b >= 0) {
                *(u32 *)0x1D545C = b;
                q = &D_001D5570_0039EC28a[b];
                old = *q;
                if (old == 0) *q = 1;
            }
            D_142430_0039EC28.e[D_142430_0039EC28.h18].f4 = D_142660_0039EC28.f0;
            D_142430_0039EC28.e[D_142430_0039EC28.h18].f0 = *(u32 *)0x1D545C;
            D_142430_0039EC28.e[D_142430_0039EC28.h18].fC = *(s32 *)0x1D5528;
            *(V8_399C90 *)((u8 *)&D_142430_0039EC28 + D_142430_0039EC28.h18 * 0x1C + 0x40) = D_001D4BE0_0039EC28c[0];
            D_142430_0039EC28.e[D_142430_0039EC28.h18].f8 = D_142660_0039EC28.b32;
            func_0039E7C8(D_001C5BD0, 0, D_00332388);
            func_0039E7C8(D_001CBBD0, D_142430_0039EC28.f150, D_00332618);
            if (b >= 0) {
                D_001D5570_0039EC28b[D_001D545C] = old;
                *(u32 *)0x1D545C = D_142430_0039EC28.f150;
            }
            if (D_142430_0039EC28.f164 < 0) {
                D_142430_0039EC28.f164 = 0xF;
                D_142430_0039EC28.f168 = D_142430_0039EC28.f148;
            }
        }
    }
    return D_142430_0039EC28.f164 == 0xF;
}
/* localdecomp:end func_0039EC28 */

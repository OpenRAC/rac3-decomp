/* functional: high. Verified vs asm: D_1D9EE8=8, D_1D9EF0=&D_001D5D40 (gp-0x6B70), D_001D5CAC=0 (gp-0x6C04), source list chosen by a (a?4C80:4C60), 8 iterations copying lhu 0x38 of 0xF0-byte records indexed by the byte read at p[i]+D_001425C0 and p[i] itself into 0x1C-byte output records. 17 words differ (prologue scheduling), loop body byte-identical. */
typedef struct { u8 pad[0x38]; u16 h38; u8 pad2[0xF0 - 0x3A]; } S_38F310;
typedef struct { s32 w0; u8 pad[0x14]; s32 w18; } D_393F38;
extern s32 D_001D9EE8[];
extern s32 D_001D9EF0[];
extern s32 D_1D4C60_00393F38[];
extern s32 D_1D4C80_00393F38[];
extern s32 D_001D5D40;
extern s32 D_001D5CAC;
extern u8 D_001425C0[];
extern S_38F310 D_001DAA40_00393F38[];
extern D_393F38 D_00331990[];
void func_00393F38(s32 a) {
    s32 *p;
    s32 i;
    s32 v;
    s32 k;
    u8 *tbl;
    S_38F310 *tab;
    D_393F38 *out;
    D_001D9EE8[0] = 8;
    D_001D9EF0[0] = (s32)&D_001D5D40;
    D_001D5CAC = 0;
    p = a ? D_1D4C80_00393F38 : D_1D4C60_00393F38;
    tbl = D_001425C0;
    tab = D_001DAA40_00393F38;
    out = D_00331990;
    for (i = 0; i < 8; i++) {
        k = *((u8 *)((u32)p[i] + (u32)tbl));
        v = tab[k].h38;
        out->w0 = v;
        out->w18 = p[i];
        out++;
    }
}

/* func_L14_0035CD38: near miss, 4 diff rows (delay-slot placement of p++ / nop in the 0x16CA and else paths)
   Size 252, 1 place (L14), file L14_0035C810.c; same engine routine as func_L03_0032EF78 (MATCH, wave2)
   Left: p++ is in the delay of beq 0x16CA and of the jal 0x356098; ours hoists it differently */
extern u16 *D_L14_0021CCE0[];
extern u8 *D_L14_001DF71C;
__asm__(".extern D_L14_001DF71C, 16");
extern s32 D_L14_001DF758;
extern void func_L14_00356098(u8 *);
extern void func_L14_0035FA00(u8 *);
void func_L14_0035CD38(void *a0, u8 *a1) {
    s32 j = *(s32 *)(a1 + 4);
    s32 k;
    u16 *p;
    u8 *e;
    s16 h;
    if (j != -1) {
        p = D_L14_0021CCE0[j];
        while (1) {
            k = *(s32 *)(a1 + 4);
            if ((k & 0xFF) == 0xFF) break;
            if (D_L14_001DF758 < k) break;
            if (p == 0) break;
            if (!((s16)p[-1] >= 0 || p == D_L14_0021CCE0[k])) break;
            e = D_L14_001DF71C + ((*p & 0x7FFF) << 8);
            if (e == 0) break;
            h = *(s16 *)(e + 0xAA);
            if (h != 0x1699 && h != 0x16CA) {
                p++;
            } else if (h == 0x1699) {
                p++;
                func_L14_00356098(e);
            } else {
                p++;
                func_L14_0035FA00(e);
            }
        }
        *(s32 *)(a1 + 4) = -1;
    }
}

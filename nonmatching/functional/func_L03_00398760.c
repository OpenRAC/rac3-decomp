/* functional: high. Written from the PAL assembly (no draft). Walks two zero-terminated halfword lists (D_001D6764[d+0x4C0] and D_0021C620[d+0x4C4]) of object handles and flags them: first list sets bit 0 of the u16 at +0x3C of the object found through D_0023A700[class byte at +0x1D of the D_001E0854 entry]; second list sets bits 0x41 (clears 0x1000) in the object's flags at +0x34, zeroes +0x98 and calls func_L01_004AA7E8(obj, 1). The odd negative-halfword guard (a handle stream marker) is kept as in retail: a negative previous halfword ends the walk unless the pointer is at the list start. */
/* localdecomp:start func_L03_00398760 */
extern s32 *D_L03_001D6764_00398760;
__asm__(".extern D_L03_001D6764_00398760, 4");
extern s32 D_L03_0021C620_00398760[];
extern u8 *D_L03_001E0854_00398760;
extern u8 *D_L03_001DF99C_00398760;
extern s32 D_L03_001DF9D8_00398760;
__asm__(".extern D_L03_001DF9D8_00398760, 4");
extern u8 *D_L03_0023A700_00398760[];
extern void func_L01_004AA7E8_00398760(void *, s32);
void func_L03_00398760(u8 *o) {
    u8 *d = *(u8 **)(o + 0x68);
    u16 *p = (u16 *)((s32 *)D_L03_001D6764_00398760)[*(s32 *)(d + 0x4C0)];
    u8 *q, *m, *r;
    u16 v;
    while (p != 0) {
        if ((s16)p[-1] < 0 && (u8 *)p != (u8 *)((s32 *)D_L03_001D6764_00398760)[*(s32 *)(d + 0x4C0)]) break;
        q = D_L03_001E0854_00398760 + ((p[0] & 0x7FFF) << 5);
        if (q == 0) break;
        r = D_L03_0023A700_00398760[q[0x1D]];
        *(u16 *)(r + 0x3C) |= 1;
        p++;
    }
    if ((*(s32 *)(d + 0x4C4) & 0xFF) == 0xFF) return;
    p = (u16 *)D_L03_0021C620_00398760[*(s32 *)(d + 0x4C4)];
    if (D_L03_001DF9D8_00398760 < *(s32 *)(d + 0x4C4)) return;
    if (p == 0) return;
    v = p[0];
    for (;;) {
        m = D_L03_001DF99C_00398760 + ((v & 0x7FFF) << 8);
        if (m == 0) return;
        v = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = v;
        p++;
        func_L01_004AA7E8_00398760(m, 1);
        if ((*(s32 *)(d + 0x4C4) & 0xFF) == 0xFF) return;
        if (D_L03_001DF9D8_00398760 < *(s32 *)(d + 0x4C4)) return;
        if (p == 0) return;
        if ((s16)p[-1] >= 0) { v = p[0]; continue; }
        if ((u8 *)p == (u8 *)D_L03_0021C620_00398760[*(s32 *)(d + 0x4C4)]) { v = p[0]; continue; }
        return;
    }
}
/* localdecomp:end func_L03_00398760 */

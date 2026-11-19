/* functional: high. Rewritten from the asm: nearest-entry search over zone lists. gp-relative D_L03_001D6764/001D6768 are the same globals retail also reaches via lui (declared small with .extern as the neighbours do). Not byte-matched. */
__asm__(".extern D_L03_001D6764, 4");
__asm__(".extern D_L03_001D6768, 4");
extern s16 **D_L03_001D6764;
extern s32 D_L03_001D6768;
extern u8 *D_L03_001E085C;
extern f32 func_0038CF00(void *, void *);
s32 func_L03_0043C438(u8 *obj, s32 zone) {
    s32 best = -1;
    f32 bestDist = 10000.0f;
    s16 *p;
    u8 *e;
    f32 d;
    s32 t;
    if (zone != -1) {
        p = D_L03_001D6764[zone];
        while (p != 0) {
            if (p[-1] < 0 && p != D_L03_001D6764[zone]) break;
            e = D_L03_001E085C + (((u16)p[0] & 0x7FFF) << 6);
            if (e == 0) break;
            d = func_0038CF00(e + 0x30, obj + 0x10);
            if (d < bestDist) {
                bestDist = d;
                best = (u16)p[0] & 0x7FFF;
            }
            p += 1;
        }
    }
    if (best != -1) {
        return best;
    }
    bestDist = 10000.0f;
    for (t = 0; t < D_L03_001D6768; t++) {
        p = D_L03_001D6764[t];
        while (p != 0) {
            if (p[-1] < 0 && p != D_L03_001D6764[t]) break;
            e = D_L03_001E085C + (((u16)p[0] & 0x7FFF) << 6);
            if (e == 0) break;
            d = func_0038CF00(e + 0x30, obj + 0x10);
            if (d < bestDist) {
                bestDist = d;
                best = (u16)p[0] & 0x7FFF;
            }
            p += 1;
        }
    }
    return best;
}

/* functional: high. Per-frame loop over the object array D_L03_001DF9A0..9A4: kills types 1C04-06/1C16 (and 1C3E when mode==1), turns type 1C19 into state 1; types 1C01/1C40/1C3F/1C4F are left alone. Not byte-exact. */
extern u8 *D_L03_001DF9A0;
extern u8 *D_L03_001DF9A4;
extern void func_003C2880(void *);

void func_L03_003AD740(s32 mode) {
    u8 *p;
    s32 s;

    for (p = D_L03_001DF9A0; p <= D_L03_001DF9A4; p += 0x100) {
        if (p == 0 || p[0x20] == 0xFE || p[0x20] == 0xFF) {
            continue;
        }
        s = *(s16 *)(p + 0xAA);
        if ((u32)(*(u16 *)(p + 0xAA) - 0x1C04) < 3 || s == 0x1C16) {
            func_003C2880(p);
        } else if (s == 0x1C19) {
            p[0x20] = 1;
        } else if (s == 0x1C3E) {
            if (mode == 1) {
                func_003C2880(p);
            }
        }
    }
}

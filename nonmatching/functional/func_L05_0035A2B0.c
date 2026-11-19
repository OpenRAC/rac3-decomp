/* functional: high. Same as retail up to loop rotation/hoisting; the object-base global D_L05_001DFB9C is lui-addressed in retail but $gp in this C (declaration size), same address. Retail's $a3=0 bnez never fires so it is dropped. */
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x89]; s16 hAA; } Rec35A2B0;
extern void *D_L05_0021DAE0[];
extern u8 *D_L05_001DFB9C;
extern s32 D_L05_001DFBD8;
Rec35A2B0 *func_L05_0035A2B0(s32 x) {
    s16 *q = (s16 *)D_L05_0021DAE0[x];
    if ((x & 0xFF) != 0xFF && x <= D_L05_001DFBD8 && q != 0) {
        Rec35A2B0 *r = (Rec35A2B0 *)(D_L05_001DFB9C + ((*(u16 *)q & 0x7FFF) << 8));
        while (r != 0) {
            if (r->hAA == 0x1625 && r->b20 == 7) return r;
            q++;
            if (!((x & 0xFF) != 0xFF && q != 0 && (q[-1] >= 0 || (void *)q == D_L05_0021DAE0[x]))) break;
            r = (Rec35A2B0 *)(D_L05_001DFB9C + ((*(u16 *)q & 0x7FFF) << 8));
        }
    }
    return 0;
}

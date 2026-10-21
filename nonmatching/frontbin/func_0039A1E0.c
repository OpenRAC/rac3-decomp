/* US draft of func_0039A1E0 (rac3-uya-decomp func_003953F0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0039A1E0 */
typedef struct { u8 p0[0x79A4]; s32 f79A4; u8 p79A8[8]; s32 f79B0; s32 f79B4; u8 p79B8[8]; s32 f79C0; s32 f79C4; } S_160C40_003953F0;
typedef struct { u8 p0[0x90]; u32 f90; u32 f94; } S_1A30B0_003953F0;
extern S_160C40_003953F0 D_160C40_0039A1E0;
extern S_1A30B0_003953F0 D_001A30B0[];
extern s32 D_002275EC[];
extern s32 D_001D4D00;
extern s32 D_001D4D04;
extern s32 D_001D52E0;
extern s32 D_001D4B48;
extern s32 D_001D4B4C;
extern s32 D_001D4B54;
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern s32 func_13CDF0(s32);
extern s32 func_13CEB0(void);
extern s32 func_12BC00(void);
extern void func_003A4260(void);
extern void func_003A1198(void);
extern void func_003A1238(s32);
extern void func_13BED0(void);
s32 func_0039A1E0(void) {
    func_13CA28();
    func_13B620();
    if (func_13CDF0(1) != 0) {
        D_001D4D00++;
        if (D_001D52E0 != 1) return 0;
        if (D_001D4D00 < 0x2D1) return 0;
        D_001D4D04 = D_001D52E0;
        D_001D52E0 = 0;
        if (D_001D4B48 < 3) D_001D4B48--;
        func_13CEB0();
        return 0;
    }
    if (func_12BC00() != 0) {
        if (D_001D4D04 == 0) {
            D_001D4D04 = 1;
            D_001D52E0 = 0;
            if (D_001D4B48 < 3) D_001D4B48--;
        }
    }
    switch (D_001D4B48) {
    case 0: {
        S_160C40_003953F0 *b = &D_160C40_0039A1E0;
        u32 m = 0xFFFFF000;
        s32 a, x, c;
        x = ((b->f79C4 << 11) + 0xFFF) & m;
        a = D_002275EC[0] - x;
        D_001D4B54 = a;
        x = ((b->f79B4 << 11) + 0xFFF) & m;
        c = a - x;
        /* D_001D4B50 by address: as a declared scalar, reorg moves this store into the b delay slot */
        *(s32 *)0x1D4B50 = c;
        func_003A2680(c, b->f79B0 + b->f79A4, b->f79B4);
        D_001D4B48++;
        break;
    }
    case 1: {
        S_160C40_003953F0 *b = &D_160C40_0039A1E0;
        func_003A2680(D_001D4B54, b->f79C0 + b->f79A4, b->f79C4);
        D_001D4B48++;
        break;
    }
    case 2:
        if (D_001D4B4C != 0) return 0;
        func_003A4260();
        func_003A1198();
        D_001D4B48++;
        break;
    case 3:
        func_13B620();
        if (D_001A30B0[0].f90 == 0xFFFFFFFF) break;
        D_001D4B48++;
        break;
    case 4:
        func_003A1238(0);
        D_001D4B48++;
        break;
    case 5:
        func_13B620();
        if (D_001A30B0[0].f94 == 0xFFFFFFFF) return 0;
        func_13BED0();
        return 1;
    }
    return 0;
}
/* localdecomp:end func_0039A1E0 */

/* Near miss of func_003A6F28 with its file's own flags: tools/check.py reports 38 diff
   (the version it replaces: 182).
*/

/* PAL candidate for func_003A6F28 (frontbin), from the US draft (rac3-uya-decomp
   func_003A1AD0). PAL differences: func_0038A238 takes 5, the wait loop calls
   func_003A4288, and the small globals are declared with an unknown size (so the
   compiler addresses them with %hi/%lo, as retail does, instead of $gp-relative);
   they need an alias name of their own, because the source file's own
   declarations (which the build puts in front of this function) give them a
   known size. */

/* localdecomp:start func_003A6F28 */
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[4]; s32 f3C; u8 pad40[8]; s16 f48; u8 pad4A[2]; s32 f4C;
    u8 pad50[8]; s32 f58; u8 pad5C[0x68 - 0x5C]; s32 f68; s32 f6C; u8 pad70[0x1E0 - 0x70];
} S_225780_3A1AD0;
typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad10[0x14C - 0x10]; } R_3A1AD0;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad1288[0x1300 - 0x1288]; R_3A1AD0 r[1]; } S_160C40_3A1AD0;
typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_1CCFD0_3A1AD0;
typedef struct { u8 pad[6]; u8 f6; u8 pad7[9]; } S_143950_3A1AD0;
extern S_225780_3A1AD0 D_00225700_003A6F28;
extern S_160C40_3A1AD0 D_160C40_003A6F28;
extern S_1CCFD0_3A1AD0 D_1CCFD0_003A6F28;
extern S_143950_3A1AD0 D_00143950_003A6F28;
extern u32 D_142BA0[];
extern s32 D_002275EC[];
extern u8 D_1A5DC0[];
extern u8 D_001D9960_003A6F28[];
extern u8 D_001D98A0_003A6F28[];
extern u8 D_001E2240[];
extern u8 D_001D98E0_003A6F28[];
extern u8 D_001D9920_003A6F28[];
extern f32 D_001D5BC8_003A6F28[];
extern s32 D_001D5BCC_003A6F28[];
extern s32 D_001D5B94_003A6F28[];
extern s32 D_001D9BDC[];
extern s32 D_001D9BE0_003A6F28;
extern f32 D_001D9BD0[];
extern s32 D_001D9BD8[];
extern void func_0038CB78(void *, s32, s32);
extern s32 func_003A6EF8(s32);
extern void func_0038A238(s32);
extern s32 func_003A6808(s32);
extern void func_003A6CC8(void);
extern void func_003A7FE8(void);
extern void func_003A2B68(s32, s32);
extern void func_003A4288(void);
extern s32 func_12C908(s32);
extern s32 func_003A1798(void);
__asm__(".extern D_001D9BE0_003A6F28, 4");
s32 func_003A6F28(s32 lvl) {
    s32 slot;
    s32 b;
    s32 i;
    s32 dst;
    s32 n;
    s32 off;
    S_143950_3A1AD0 *p;
    if (lvl >= 0) { u32 *w = &D_142BA0[(u32)lvl >> 2]; *w |= 1 << (lvl & 0x1F); }
    slot = func_003A6EF8(lvl);
    if (slot < 0) return 0;
    func_0038CB78(D_1A5DC0, 0, 0x230);
    func_0038CB78(&D_00225700_003A6F28, 0, 0x1E0);
    func_0038CB78(D_001D9960_003A6F28, 0, 0x40);
    func_0038CB78(D_001D98A0_003A6F28, 0, 0x40);
    func_0038CB78(D_001E2240, 0, 0x40);
    func_0038CB78(D_001E2240 + 0x40, 0, 0x40);
    func_0038CB78(D_001D98E0_003A6F28, 0, 0x40);
    func_0038CB78(D_001D9920_003A6F28, 0, 0x40);
    b = D_002275EC[0];
    D_00225700_003A6F28.f30 = slot;
    D_00225700_003A6F28.f68 = b - 0x82000;
    D_00225700_003A6F28.f6C = b - 0x102000;
    D_001D5BC8_003A6F28[0] = 1.0f;
    D_001D5BCC_003A6F28[0] = 0;
    D_00225700_003A6F28.f34 = 0;
    D_00225700_003A6F28.f3C = 0;
    D_00225700_003A6F28.f58 = b - 0x90000;
    { s32 j; for (j = 0; j < 1; j++) { D_001D9BD0[j] = 1.0f; D_001D9BD8[j] = 0; } }
    D_001D5B94_003A6F28[0] = 2;
    D_001D9BDC[0] = 1;
    D_001D9BE0_003A6F28 = 0x34;
    p = &D_00143950_003A6F28;
    if (p->f6 != 0) {
        D_00225700_003A6F28.f4C = 0;
        dst = D_00225700_003A6F28.f58 + 0x8E000;
        n = D_160C40_003A6F28.r[D_00225700_003A6F28.f30].fC;
        off = D_160C40_003A6F28.r[D_00225700_003A6F28.f30].f8;
        if (n > 0) {
            func_003A2598(dst, off + D_160C40_003A6F28.f1284, n);
            func_003A2750(1);
            D_00225700_003A6F28.f4C = dst;
        }
    }
    if (D_1CCFD0_003A6F28.f4 != 0) {
        func_0038A238(5);
        func_003A2750(1);
        func_003A6808(0);
    } else {
        func_003A6808(0);
        func_0038A238(5);
    }
    if (D_1CCFD0_003A6F28.f4 != 0) func_003A2750(1);
    func_003A6CC8();
    func_003A7FE8();
    func_003A2B68(D_00225700_003A6F28.f30 + 4000, 0);
    while (D_1CCFD0_003A6F28.f76 != 0 || D_1CCFD0_003A6F28.f9E != 3 || D_1CCFD0_003A6F28.f98 >= 7000) {
        func_003A4288();
        func_12C908(0);
    }
    D_00225700_003A6F28.f48 = -3;
    func_003A1798();
    func_003A6808(1);
    for (i = 0; D_00225700_003A6F28.f48 < i; i--) func_12C908(0);
    return 1;
}
/* localdecomp:end func_003A6F28 */

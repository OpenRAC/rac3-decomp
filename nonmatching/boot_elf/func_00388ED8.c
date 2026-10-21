/* US draft of func_00388ED8 (rac3-uya-decomp func_00388E80, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00388ED8 */
__asm__(".extern D_001D58D0, 4");
__asm__(".extern D_001D5884, 1");

typedef int u128_00384420 __attribute__((mode(TI)));
typedef struct { u8 pad[0x450]; s32 x450; u8 pad454[0xC]; } P_00384420;
typedef struct { u8 pad0[4]; s16 x4; } C_00384420;
typedef struct { u128_00384420 q[4]; } Q_00384420;

extern C_00384420 *D_001DA5F0;
extern s32 D_001D9BC4;
extern s32 D_001D9D1C;
extern s32 D_001D9348;
extern s32 D_001D934C;
extern s32 D_001D9C10_00388ED8;
extern s32 D_001D9C14_00388ED8;
extern u8 D_001D58D0;
extern s32 D_001D5B94;
extern s32 D_001D9C08_00388ED8;
extern s32 D_001D9C0C_00388ED8;
extern s32 D_001D9364;
extern s32 D_001D9368;
extern s32 D_001D9C38_00388ED8;
extern volatile s32 D_001D9EC0;
extern s32 D_001D52F0;
extern P_00384420 D_00222480_00388ED8[];
extern u8 D_001D5780;
extern u8 D_001D5781;
extern u8 D_001D5782;
extern u8 D_001D5783;
extern f32 D_001D9BD0;
extern f32 D_001D9BD8[2];
extern s32 D_001D5B98;
extern u8 D_001D5884;
extern s32 D_001D58B8;
extern u8 D_100AE0[];
extern s32 D_00143950[];
extern f32 D_001D9D10;
extern s32 D_001D9D50_00388ED8;
extern u8 D_002FDC00[];
extern u8 D_003064C0[];
extern Q_00384420 D_00225AA0;
extern Q_00384420 D_00334EC0;

extern void func_00392730(s32);
extern void func_003865D0(void);
extern void func_003C3178(void);
extern void func_003875F8(void);
extern void func_00388348(void);
extern void func_0038CD90(void);
extern void func_003CF4A8(void);
extern void func_003AA028_00388ED8(s32);
extern void func_003DA0A8(void);
extern void func_003A9A90(void);
extern void func_00389620(s32);
extern void func_0038A208(void);
extern void func_00389750(void);
extern void func_003A9A30(void);
extern void func_003DF2E0(void);
extern void func_0038B120_00388ED8(u8 *);
extern void func_0038A280(void);
extern void func_00388A90(void);
extern void func_003C3C18(void);
extern void func_0038A190(void);
extern void func_003A97F8(s32, unsigned long);
extern void func_00385400(void);
extern void func_0038A438(void);
extern void func_11F0A0(s32);
extern void func_003CD790(void);
extern void func_0038A348(void);
extern void func_003D8978_00388ED8(s32);
extern void func_003D89F8(void);
extern void func_003D9618_00388ED8(s32);
extern void func_0038A3C0(void);
extern void func_00386108(s32);
extern void func_00392AC8(void);
extern s32 func_003A12A8(s32);
extern void func_0038AD28(void);
extern void func_003AA060_00388ED8(s32);
extern void func_003AFA18(void);
extern void func_00396C18(void);
extern void func_003B34A0(void);
extern void func_003B3510(s32);
extern void func_003B34D8(void);
extern void func_00381C70(void);
extern void func_0038A8A0(void);
extern void func_0038B200(s32, s32, s32, s32);
extern void func_0038AFA0(void);
extern void func_003A9348_00388ED8(void *);
extern void func_003A96A8(s32);
extern void func_003D0538(void *);
extern void func_003CF408(void);
extern void func_003DDB20(void);
extern void func_003D9FE8(void);
extern void func_003E0EC8(void *);
extern void func_003DF1D8(void);
extern void func_003C3568(void);
extern void func_003868A0(s32);

void func_00388ED8(s32 arg0) {
    s32 t;
    s32 t2;
    f32 d, n;
    u128_00384420 *src, *dst;

    if (D_001DA5F0 == 0 || D_001DA5F0->x4 != 0 || ((*(u8 *)&D_001D9BC4 ^ 1) & 1)) {
        func_00392730(0);
    }
    func_003865D0();
    func_003C3178();
    func_003875F8();
    func_00388348();
    D_001D9D1C = -1;
    D_001D9348 = 0;
    D_001D934C = 0;
    if (D_001DA5F0 != 0 && (D_001D9BC4 & 1)) {
        func_0038CD90();
    }
    if (D_001D9BC4 & 2) {
        func_003CF4A8();
    }
    func_003AA028_00388ED8(0x2010000);
    if (D_001D9BC4 & 4) {
        func_003DA0A8();
    }
    func_003AA028_00388ED8(0x2020000);
    if ((D_001D9BC4 & 0x20) && D_001D9C10_00388ED8 != 0) {
        func_003A9A90();
        func_00389620(1);
        func_0038A208();
        func_00389750();
        func_003A9A30();
    }
    if (D_001D9BC4 & 8) {
        func_003DF2E0();
    }
    func_003AA028_00388ED8(0x2040000);
    if (D_001D58D0) {
        func_0038B120_00388ED8(&D_001D58D0);
    }
    if ((D_001D9BC4 & 0x20) && D_001D9C14_00388ED8 != 0) {
        func_003A9A90();
        func_00389620(1);
        func_0038A280();
        func_00389750();
        func_003A9A30();
    }
    if (D_001D9BC4 & 0x10) {
        if (D_001D5B94 == 2) {
            func_00388A90();
        } else {
            func_003C3C18();
        }
    }
    func_003AA028_00388ED8(0x2080000);
    func_00389620(0);
    if (D_001D9BC4 & 0x20) {
        func_003A9A90();
        if (D_001D9C08_00388ED8 != 0) {
            func_0038A190();
        }
        func_003A97F8(0x42, 0x8000000048);
        func_00385400();
        func_003A9A90();
        func_0038A438();
        func_003A97F8(8, 5);
        func_003A9A90();
        func_003A97F8(0x47, 0x53001);
        func_11F0A0(0);
        func_003CD790();
        D_001D9D1C = 9;
        func_003A97F8(0x47, 0x5360B);
        if (D_001D9C0C_00388ED8 != 0) {
            func_003A9A90();
            func_0038A348();
        }
        func_00389750();
        if (D_001D9348 != 0) {
            func_003D8978_00388ED8(0);
            if (D_001D9348 != 0) {
                func_003D89F8();
            }
        }
        if (D_001D9364 != 0) {
            func_003D9618_00388ED8(0);
        }
        t2 = D_001D9364;
        D_001D9364 = 0;
        D_001D9368 = t2;
        func_00389620(0);
        if (D_001D9C38_00388ED8 != 0) {
            func_003A9A90();
            func_0038A3C0();
        }
        func_003A97F8(0x42, 0x8000000044);
        func_00386108(arg0);
        func_00389750();
    }
    func_00392AC8();
    func_00389620(0);
    func_003A9A90();
    if ((D_001D9BC4 & 0x180) && func_003A12A8(3) == 0) {
        func_003A97F8(0x47, 0x33001);
        func_0038AD28();
        if (D_001D9BC4 & 0x80) {
            func_003AA060_00388ED8(0);
            func_003AFA18();
            t = D_001D9EC0;
            func_00396C18();
            D_001D9EC0 = t;
            func_003B34A0();
            func_003B3510(D_001D52F0);
            func_003B34D8();
            func_00381C70();
        }
    }
    if (D_001D5B94 == 2) {
        func_0038A8A0();
    }
    func_00389750();
    if (D_001D9BC4 & 0x40) {
        func_003A97F8(0x42, 0x8000000044);
        if (((P_00384420 *)((u8 *)D_00222480_00388ED8 + arg0 * sizeof(P_00384420)))->x450 != 0) {
            func_0038B200(D_001D5780, D_001D5781, D_001D5782, D_001D5783);
        }
        if (D_001D9BD0 > 0.0f && D_001D5B98 == 0) {
            if (D_001D9BD0 > 1.0f) {
                D_001D9BD0 = 1.0f;
            }
            func_0038B200(0, 0, 0, D_001D9BD0 * 128.0f);
        }
        if (D_001D9BD8[0] > 0.0f && D_001D5B98 == 0) {
            if (D_001D9BD8[0] > 1.0f) {
                D_001D9BD8[0] = 1.0f;
            }
            func_0038B200(0xFF, 0xFF, 0xFF, D_001D9BD8[arg0] * 128.0f);
        }
        if (D_001D5884 && D_001D58B8 != 0) {
            func_0038AFA0();
        }
    }
    func_003A9348_00388ED8(D_100AE0);
    func_11F0A0(0);
    n = *(volatile u32 *)0x10000800;
    D_001D9D10 = n / (D_00143950[0] != 0 ? 11520.0f : 9600.0f);
    func_003A96A8(2);
    if (D_001D9BC4 & 2) {
        func_003D0538(D_002FDC00);
        func_003CF408();
    }
    func_003A96A8(4);
    if (D_001D9BC4 & 4) {
        src = (u128_00384420 *)&D_00225AA0;
        dst = (u128_00384420 *)&D_00334EC0;
        dst[0] = src[0];
        dst[1] = src[-1];
        dst[2] = src[2];
        func_003DDB20();
        func_003D9FE8();
    }
    func_003A96A8(8);
    if (D_001D9BC4 & 8) {
        func_003E0EC8(D_003064C0);
        func_003DF1D8();
    }
    func_003A96A8(0x10);
    if (D_001D9BC4 & 0x10) {
        func_003C3568();
    }
    func_003868A0(arg0);
    D_001D9D50_00388ED8 = 0;
}
/* localdecomp:end func_00388ED8 */

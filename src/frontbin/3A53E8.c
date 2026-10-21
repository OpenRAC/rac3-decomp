#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
typedef struct {
    u8 pad[0x84];
    s32 f84;
} Struct227600;
extern void func_003A8630(void);
extern void func_003A9050(void);
extern void func_003A9A40(void);
extern void func_003A9440(s32, unsigned long);
extern void func_003A8B10(void);
extern void func_003A92F0(s32);
extern void (*D_001D9A40[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void func_003A96D8(void);
extern void func_003A9678(void);
extern void func_003A9618();
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003A9338(s32, u32);
extern void func_003A9740(void);
extern void func_003A9500(s32, s32, s32, s32);
extern void func_003A5430(void);
extern s32 func_003A8678();
extern void func_003A8A58(void);
extern void func_003A88B8();
extern s32 func_003A53E8(u32, s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003A53E8 */
extern u8 D_001A30B0[];
s32 func_003A53E8(u32 a0, s32 a1) {
    if (a0 < 0x34) {
        u8 *p = (u8 *)&D_001A30B0[0] + a0 * 0x80;
        *(u16 *)(p + 0xcc) = a1;
    }
    return 1;
}
/* localdecomp:end func_003A53E8 */

LINKER_REMNANT("asm/remnants", func_003A5410);

/* localdecomp:start func_003A5430 */
/* sq $zero has no C form (the compiler always emits por+sq from a zero); this is the inline-asm macro the original used */
#define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
extern s32 D_001D6E1C;
extern u8 D_1A3100[];
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_13C170(void);
extern s32 func_12C908(s32);
extern void func_003A5620(void);
void func_003A5430(void) {
    s32 c;
    s32 i;
    u8 *p;
    func_13CA28();
    func_13B620();
    func_13C170();
    D_001D6E1C = 0xB4;
    while (func_13B620() != 0) {
        func_12C908(0);
        c = D_001D6E1C;
        if (c == 0) break;
        D_001D6E1C = c - 1;
    }
    for (i = 3; i >= 0; i--) {
        QZERO(D_1A3100 + i * 0x10);
    }
    p = D_001A30B0;
    *(s32 *)(p + 0x48) = 0;
    for (i = 0x33; i >= 0; i--) {
        *(s32 *)(p + 0xC0) = 0;
        *(u8 *)(p + 0xD0) = 0;
        p += 0x80;
    }
    func_003A5620();
}
/* localdecomp:end func_003A5430 */

/* localdecomp:start func_003A54F0 */
void func_003A54F0(s32 a0, long a1) {
    s32 *p = (s32 *)(u32)a1;
    if (p != 0) {
        *p = a0;
    }
}
/* localdecomp:end func_003A54F0 */

/* localdecomp:start func_003A5508 */
void func_003A5508(s32 a0, long a1) {
    u8 *p = (u8 *)(s32)a1;
    if (p != 0) {
        *(s32 *)p = a0;
        if (a0 != 0) {
            if (p[0x10] == 1) {
                p[0x10] = 2;
            }
        } else {
    *(s32 *)(p + 0x1C) = 0;
    *(s32 *)(p + 0x40) = 0;
    p[0x10] = 0;
        }
    }
}
/* localdecomp:end func_003A5508 */

/* localdecomp:start func_003A5550 */
void func_003A5550(s32 a, long l) {
    u8 *p = (u8 *)(u32)l;
    if (p == 0) return;
    if (p[0x13] != *(s32 *)(p + 0x4C)) return;
    *(s32 *)p = a;
    if (a == 0) {
        *(s32 *)(p + 0x1C) = 0;
        *(s32 *)(p + 0x40) = 0;
        p[0x10] = 0;
    }
    p[0x13] = 0;
}
/* localdecomp:end func_003A5550 */

LINKER_REMNANT("asm/remnants", func_003A5590);

/* localdecomp:start func_003A5598 */
void func_003A5598(u8 *p, s32 i, s32 *v) {
    switch (i) {
    case 3:
        *(s32 *)(p + 0xC) = *v;
        break;
    case 0:
        *(u128_t *)(p + 0x40) = *(u128_t *)v;
        break;
    case 1:
        *(u128_t *)(p + 0x50) = *(u128_t *)v;
        break;
    case 2:
        *(f32 *)(p + 8) = *(f32 *)v;
        break;
    case 4:
        *(s32 *)(p + 0x10) = *v;
        break;
    case 5:
        *(s32 **)(p + 0x14) = v;
        break;
    case 6:
        *(s32 *)(p + 0x18) = *v;
        break;
    }
}
/* localdecomp:end func_003A5598 */

LINKER_REMNANT("asm/remnants", func_003A5618);

/* localdecomp:start func_003A5620 */
typedef struct { u8 x0; s8 x1; s8 x2; s8 x3; u16 x4; u16 x6; s32 x8; s32 xC; u32 x10; s32 x14; s32 x18; u8 pad[0x60-0x1C]; } S_3A0200;
extern S_3A0200 D_0022D430[];
void func_003A5620(void) {
    s32 i;
    for (i = 0; i < 12; i++) {
        S_3A0200 *p = &D_0022D430[i];
        p->x0 = 0;
        p->x1 = -1;
        p->x2 = -1;
        p->x3 = -1;
        p->xC = 0;
        p->x8 = 0;
        p->x4 = 0xFFFF;
        p->x10 = 0xFFFFFFFF;
        p->x14 = 0;
        p->x18 = -1;
    }
}
/* localdecomp:end func_003A5620 */

LINKER_REMNANT("asm/remnants", func_003A5688);

/* localdecomp:start func_003A56A0 */
extern s32 D_0022D8B0[];
extern void func_003C2880(s32 p);
void func_003A56A0(void) {
    s32 *p = D_0022D8B0;
    s32 i;
    for (i = 19; i >= 0; i--) {
        if (*p) func_003C2880(*p);
        *p = 0;
        p++;
    }
}
/* localdecomp:end func_003A56A0 */

typedef struct O2_3A02D8 { u8 pad[8]; void *f8; } O2_3A02D8;
typedef struct { u8 pad[0x30]; u8 f30; u8 pad31; s16 f32; u16 f34; u8 pad36[0x63 - 0x36]; u8 f63; u8 pad64[4]; O2_3A02D8 *f68; } O_3A02D8;
typedef struct { O_3A02D8 *f0; u8 pad[0x40]; } S_16C580_3A02D8;
extern S_16C580_3A02D8 D_0016C580_003A56F8;
extern u32 D_001D54D0;
extern s16 D_001D5BB0[4];
extern s16 D_001D5BB6;
extern s16 D_001D5BB8;
extern s16 D_001D5BBA;
extern s16 D_001D5BBC;
extern O_3A02D8 *func_003C24B0_003A56F8(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003A56F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A58C0);

LINKER_REMNANT("asm/remnants", func_003A6140);

typedef struct { u8 p0[0x20]; s16 f20; } S_16C580_3A0D58;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0D58;
extern S_16C580_3A0D58 D_16C580_003A6178;
extern f32 func_00382538(void);
extern void func_003C4C18(f32 *v, f32 r);
INCLUDE_ASM("asm/nonmatchings/text", func_003A6178);

INCLUDE_ASM("asm/nonmatchings/text", func_003A62D0);

typedef struct { f32 x, y, z, w; } V_3A0EB0;
typedef struct { f32 x, y, z, w; } E_3A0EB0;
typedef struct {
    V_3A0EB0 v;
    u128_t q10;
    f32 f20; f32 f24; f32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; s32 f44; s32 f48; s32 f4C;
} T_3A0EB0;
extern s32 D_001D6FA0[2];
extern s32 D_001DA010[2];
extern s32 D_00225734[];
extern void func_003C2EC0();
extern void func_0038D028();
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003A6178(void *, void *, s32, f32, f32, f32, s32);
extern void func_003A8308_003A0EB0(void *, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382498(s32, s32);

/* PAL candidate for func_003A6790. The US draft called the US build's func_003A0EB0;
   in the PAL retail the same callee lives at 0x3A62D0, so only the call target
   changes (the argument passing is identical). */


/* localdecomp:start func_003A6790 */
extern void func_003A62D0(void *, s32, s32);
void func_003A6790(void *p) {
    func_003A62D0(p, 1, 0);
    func_003A62D0(p, 2, 0);
}
/* localdecomp:end func_003A6790 */

LINKER_REMNANT("asm/remnants", func_003A67D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6800);

/* localdecomp:start func_003A6808 */
typedef struct { u8 pad[0x30]; s32 f30; u8 pad2[0x38]; s32 f6C; } S_225780;
typedef struct { s32 v[0x53]; } E_160C40;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad2[0xB0]; E_160C40 e[1]; } S_160C40;
extern S_225780 D_00225700_003A6808;
extern S_160C40 D_160C40;
extern s32 func_003A2598(s32, s32, s32);
extern s32 func_003A2750(s32);
s32 func_003A6808(s32 a) {
    s32 idx = D_00225700_003A6808.f30;
    s32 h = D_00225700_003A6808.f6C;
    s32 lo = D_160C40.e[idx].v[a];
    s32 d = D_160C40.e[idx].v[a + 1] - lo;
    if (d > 0) {
        func_003A2598(h, lo + D_160C40.f1284, d);
        func_003A2750(0);
    }
    return 1;
}
/* localdecomp:end func_003A6808 */

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A1438;
typedef struct {
    u8 pad[0x10]; V4_3A1438 f10; u8 pad20[0x40 - 0x20]; u8 f40; u8 f41; u8 pad42[2]; f32 f44;
    u8 pad48[0x61 - 0x48]; u8 f61; u8 pad62; u8 f63; u8 pad64[4]; u8 *f68; u8 pad6C[0xAA - 0x6C]; s16 fAA;
} O_3A1438;
typedef struct { u8 pad[0x20]; u8 f20; u8 pad21[0x34 - 0x21]; u16 f34; u8 pad36[0xAA - 0x36]; s16 fAA; u8 padAC[0x100 - 0xAC]; } E_3A1438;
typedef struct {
    u8 pad[0x34]; s32 f34; s32 f38; s32 f3C; s16 f40; u8 pad42[2]; s16 f44; u8 pad46[2]; s16 f48;
    u8 pad4A[0x60 - 0x4A]; s8 f60; u8 pad61[0x1A0 - 0x61]; O_3A1438 *f1A0[1];
} S_225780_3A1438;
typedef struct { u8 pad[0x1A0]; unsigned long f1A0; } Pad_3A1438;
typedef struct { u8 pad[0x25C0]; O_3A1438 *f25C0; } S_1A4BE0_3A1438;
extern S_225780_3A1438 D_00225700_003A6890;
extern S_1A4BE0_3A1438 D_001A4BE0_003A6890;
extern f32 D_001D9BD0_003A6890;
extern s32 D_001D5B90_003A6890;
extern Pad_3A1438 *D_001D52FC_003A6890;
extern s32 D_00142690_003A6890[];
extern s32 D_001D4D40_003A6890;
extern s32 D_001D545C_003A6890;
extern s32 D_00143950_003A6890[];
extern s16 D_001CCFD4_003A6890[];
extern O_3A1438 *D_001DA008;
extern s32 D_001D4B60_003A6890;
extern E_3A1438 *D_001DA49C_003A6890;
extern E_3A1438 *D_001DA4A4_003A6890;
extern void func_003E5520(void);
extern s32 func_003A1798(void);
extern void func_003C29B0_003A6890(O_3A1438 *);
extern void func_0038CE20_003A6890(void *, void *, f32);
extern void func_003A58C0(O_3A1438 *, s32);
extern void func_00389F18_003A6890(void (*)(), O_3A1438 *);
extern void func_003C7C38_003A6890(O_3A1438 *);
extern void func_00381D68(O_3A1438 *, s32);
extern void func_00381C90(O_3A1438 *);
extern s32 func_00381CB0_003A6890(void);
extern void func_003D0B20(void);
extern void func_003A6CC8(void);
extern s32 func_003A2750(s32);
extern void func_003E55B8(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003A6890);

typedef struct { u8 pad[6]; u8 f6; u8 pad7[5]; u8 fC; u8 padD[0x48 - 0xD]; void *f48[1]; } T_3A1870;
typedef struct { u8 pad[0x10]; u8 n; u8 pad11[0xB]; s32 a[1]; } E_3A1870;
typedef struct {
    u8 pad[0x24]; T_3A1870 *f24; u8 pad28[0x32 - 0x28]; s16 f32; u16 f34; u8 pad36[2];
    long f38; u8 pad40[2]; u8 f42; u8 f43; u8 pad44[0x62 - 0x44]; u8 f62; u8 f63; u8 pad64[4];
    u8 *f68; u8 pad6C[0x98 - 0x6C]; s32 f98; u8 pad9C[0xAA - 0x9C]; s16 fAA;
} O_3A1870;
typedef struct {
    u8 pad[0x38]; s32 f38; u8 pad3C[4]; s16 f40; u8 pad42[2]; s16 f44; u8 pad46[2]; s16 f48;
    u8 pad4A[0x54 - 0x4A]; O_3A1870 *f54; u8 pad58[0x64 - 0x58]; u8 *f64; u8 *f68; s32 f6C;
    u8 pad70[0x1A0 - 0x70]; O_3A1870 *f1A0[1];
} S_225780_3A1870;
extern S_225780_3A1870 D_00225700_003A6CC8;
extern O_3A1870 *D_001D9BCC;
extern void func_11F0A0(s32);
extern void func_003A0760(u8 *, u32);
extern O_3A1870 *func_003C24B0_003A6CC8(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003A6CC8);

/* localdecomp:start func_003A6EF8 */
extern s32 D_001D6EF8[2];
s32 func_003A6EF8(s32 k) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (D_001D6EF8[i] == k) return i;
    }
    return -1;
}
/* localdecomp:end func_003A6EF8 */

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
extern u8 D_001D9960[8];
extern u8 D_001D98A0[8];
extern u8 D_001E2240[];
extern u8 D_001D98E0[8];
extern u8 D_001D9920[8];
extern f32 D_001D5BC8;
extern s32 D_001D5BCC;
extern s32 D_001D5B94;
extern s32 D_001D9BDC_003A6F28;
extern s32 D_001D9BE0_003A6F28;
extern f32 D_001D9BD0_003A6F28[1];
extern s32 D_001D9BD8_003A6F28[1];
extern void func_0038CB78(void *, s32, s32);
extern void func_0038A238(s32);
extern void func_003A6CC8(void);
extern void func_003A2B68(s32, s32);
extern s32 func_12C908(s32);
extern s32 func_003A1798(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003A6F28);

typedef struct { u8 p0[0x24]; s32 f24; u8 p28[0x44]; s32 f6C; u8 p70[6]; u16 f76; u8 p78[0x1C]; s32 f94; u8 p98[6]; u16 f9E; } S_3A1E48a;
typedef struct { u8 p0[0xC]; u8 bC; u8 pD[0x3B]; s32 f48[1]; } S_3A1E48c;
typedef struct { u8 p0[0x24]; S_3A1E48c *f24; } S_3A1E48d;
typedef struct { u8 p0[0x44]; s16 n44; u8 p46[0x15A]; S_3A1E48d *e[1]; } S_3A1E48b;
typedef struct { u8 p0[0x34]; u16 h34; } S_3A1E48e;
extern S_3A1E48a D_001CCFD0_003A72A0;
extern u8 D_00225900_003A72A0[];
extern S_3A1E48b D_00225700_003A72A0;
extern u8 D_001A4BE0_003A72A0[];
extern S_3A1E48e *D_001D9DD8;
extern s32 D_001D9BDC;
extern s32 D_001D9BE0;
extern s32 D_001D9BD0[1];
extern void func_0038A238(s32);
extern s32 func_12C908(s32);
extern void func_13B620_003A72A0(void);
extern void func_003873C0();
extern void func_003C2880(s32 p);
INCLUDE_ASM("asm/nonmatchings/text", func_003A72A0);

typedef struct { u8 pad[0x44]; s16 h44; u8 pad2[0x15A]; s32 tbl[1]; } S_225780_3A2028;
typedef struct { u8 pad[0x28]; s32 f28; } E_3A2028;
extern S_225780_3A2028 D_00225700_3A2028;
extern E_3A2028 *D_001DA49C_3A2028;
extern s32 D_001D5B94;
extern s32 D_001D5B90;
extern s32 D_001D9BC4;
extern s32 D_001D9BC8;
extern s32 D_001D9D1C;
extern void func_003A91D0();
extern void func_003A9150();
extern void func_003923D0();
extern void func_00392748();
extern void func_003922B8();
extern void func_0039C410();
extern void func_003861F0();
extern void func_003C2DC0();
extern void func_00387F68();
extern void func_003A3B70();
extern s32 func_003A6890();
extern void func_00392350();
extern void func_00388AF8();
extern void func_003A72A0();
INCLUDE_ASM("asm/nonmatchings/text", func_003A7480);

typedef struct { u8 p0[0x34]; s32 f34; u8 p38[0x14]; s32 f4C; } S_225780_3A21C0;
extern S_225780_3A21C0 D_00225700_003A7618;
extern u8 D_00160C40_003A88B8[];
extern u8 D_00142BA0[];
extern u8 D_001A30B0[];
extern u8 D_00143A07[];
extern u8 D_001D52E0;
extern u8 D_13D208[];
extern s32 D_002275EC[];
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
extern s32 D_001D5B94;
extern s32 D_001D9BC8;
extern void func_003A1C28(void);
extern s32 func_003A8770(s32);
extern void func_13CF80(s32, s32, s32, s32, s32);
extern void func_0038A238(s32);
extern s32 func_12C908(s32);
extern void func_00387F68();
extern void func_003912E8(void);
extern void func_003A91D0();
extern void func_003A9150();
extern void func_11F0A0(s32);
extern long func_13CDF0_003A7618(s32);
extern s32 func_13CD28(s32, s32, s32, void *);
extern s32 func_003AF890(s32, s32, s32 (*)(s32, s32), s32, s32);
extern s32 func_12A9F0(s32, s32);
extern void func_12D4D8(u8 *);
extern void func_003A9108(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003A7618);

INCLUDE_ASM("asm/nonmatchings/text", func_003A78B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7AF8);

typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_3A2460;
typedef struct { u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C; u8 p240[0x10]; s32 f250; s32 f254; s32 f258; } S_225980_3A2460;
extern S_142430_3A2460 D_00142430_003A2460;
extern u8 D_001CCFD0_003A2460[];
extern u8 D_001A30B0[];
extern S_225980_3A2460 D_00225900_003A2460;
extern s32 D_001D9D04;
extern u32 D_001D545C;
extern s32 D_001D4B48;
extern s32 D_001D9D2C;
extern u8 D_001D9C44, D_001D9C45, D_001D9C46;
extern f32 D_001D9C48, D_001D9C4C, D_001D9C50, D_001D9C54;
extern u8 D_002D2100[];
extern s32 func_003BD4B8();
extern void func_0038A238(s32);
extern void func_11F0A0(s32);
extern void func_13CF80();
extern void func_13CA28(void);
extern void func_13B620_003A2460(void);
extern void func_003A1C28(void);
extern void func_13BF00();
extern void func_13BED0();
extern void func_00392260(s32, long, long);
extern void func_13D310();
extern s32 func_12C908(s32);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern s32 func_0039A1E0();
extern void func_13CF40();
extern void func_13CDF0(s32);
extern void func_003A9AD0();

/* localdecomp:start func_003A7FE8 */
typedef struct { u8 pad[0x20]; void *p20; u8 pad2[0x1C]; s32 p40; } S2_3A2BC0;
typedef struct { u8 pad[0x30]; s32 f30; u8 pad2[0x1C]; S2_3A2BC0 *f50; u8 pad3[0x14C]; s32 f1A0[4]; } B_3A2BC0;
extern B_3A2BC0 D_00225700;
extern S2_3A2BC0 D_00334B90[];
extern s32 D_001D7000;
extern void *D_001D7080;
extern s32 D_001D7090;
void func_003A7FE8(void) {
    B_3A2BC0 *base = &D_00225700;
    s32 idx = -1;
    S2_3A2BC0 *p;
    if (base->f30 == 0) idx = 3;
    if (idx != -1) {
        p = D_00334B90;
        base->f50 = p;
        D_001D7080 = &D_001D7000;
        p->p20 = &D_001D7090;
        p->p40 = base->f1A0[idx];
    }
}
/* localdecomp:end func_003A7FE8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A8040);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A2C18;
typedef struct { u8 pad0[0x10]; V4_3A2C18 f10; u8 pad20[0x8A]; s16 hAA; } E_3A2C18;
typedef struct { u8 pad[0x20]; V4_3A2C18 *f20; u8 pad2[0x1C]; s32 f40; } S3_3A2C18;
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[0xC]; s16 h44; u8 pad46[0xA];
    S3_3A2C18 *f50; u8 pad54[0x14C]; E_3A2C18 *tbl[4];
} B_3A2C18;
extern B_3A2C18 D_00225700_003A2C18;
extern V4_3A2C18 D_00222400_003A2C18[];
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
typedef struct { u8 pad[0x48]; s32 f48; s32 f4C; } E_3A2DF8;
extern u8 *D_001D6EEC;
extern f32 D_001D6EF0;
extern s32 D_001DA010[2];
/* localdecomp:start func_003A8220 */
__asm__(".extern D_001D6EEC, 4");
__asm__(".extern D_001D6EF0, 4");
/* Retail forms the address of this 8-byte global with lui/addiu, not $gp: an unsized
   array is never small data. The shared declaration in this file is the sized
   `extern s32 D_001DA010[2];`, so this block uses a per-function alias for it. */
extern s32 D_001DA010_003A8220[];
void func_003A8220(E_3A2DF8 *a0) {
    s32 i;
    f32 one;
    D_001D6EEC = (u8 *)a0;
    for (i = 0x1FF; i >= 0; i--) {
        a0[i].f48 = 0;
    }
    do { one = 1.0f; } while (0);
    QZERO(D_001DA010_003A8220);
    D_001D6EF0 = one;
}
/* localdecomp:end func_003A8220 */

/* localdecomp:start func_003A8268 */
extern u8 *D_001D6EEC;
void func_003A8268(s32 a0, u8 *src) {
    u8 *p;
    s32 i;
    if (D_001D6EEC == 0) return;
    p = D_001D6EEC;
    i = 0;
    do {
        i++;
        if (*(s32 *)(p + 0x48) == 0) {
            *(s32 *)(p + 0x38) = *(s32 *)(src + 0x38);
            *(s32 *)(p + 0x3C) = *(s32 *)(src + 0x3C);
            *(s32 *)(p + 0x30) = *(s32 *)(src + 0x30);
            *(s32 *)(p + 0x44) = *(s32 *)(src + 0x44);
            *(f32 *)(p + 0x24) = *(f32 *)(src + 0x24);
            *(f32 *)(p + 0x20) = *(f32 *)(src + 0x20);
            *(f32 *)(p + 0x28) = *(f32 *)(src + 0x28);
            *(s32 *)(p + 0x34) = *(s32 *)(src + 0x34);
            *(s32 *)(p + 0x2C) = *(s32 *)(src + 0x2C);
            *(s32 *)(p + 0x40) = *(s32 *)(src + 0x40);
            *(s32 *)(p + 0x4C) = *(s32 *)(src + 0x4C);
            *(u128_t *)(p + 0) = *(u128_t *)(src + 0);
            *(u128_t *)(p + 0x10) = *(u128_t *)(src + 0x10);
            *(s32 *)(p + 0x48) = a0;
            return;
        }
        p += 0x50;
    } while (i < 0x200);
}
/* localdecomp:end func_003A8268 */

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A2EE0;
typedef struct {
    V4_3A2EE0 v0; V4_3A2EE0 v10;
    f32 f20; f32 f24; f32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C;
    s32 f40; s32 f44; s32 f48; s32 f4C;
} E_3A2EE0;
extern u8 *D_001D6EEC;
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_0038CAD0(void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003A8308);

typedef struct { u8 pad0[0x24]; f32 f24; f32 f28; u8 pad2C[4]; s32 f30; u8 pad34[4]; s32 f38; s32 f3C; u8 pad40[8]; s32 f48; s32 f4C; } E_3A3028;
extern E_3A3028 *D_001D6EEC_003A8450;
extern f32 D_001D6EF0;
INCLUDE_ASM("asm/nonmatchings/text", func_003A8450);

INCLUDE_ASM("asm/nonmatchings/text", func_003A8500);

LINKER_REMNANT("asm/remnants", func_003A8628);

/* PAL retail bytes for func_003A8630.
   The three globals are reached through `lui $at` in retail (not through $gp): the
   assembler's expansion, through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did)
   (docs/wiki/Matching-Patterns.md, "Globals: gp vs lui"). */

extern s32 D_0022DF20[];

/* localdecomp:start func_003A8630 */
extern s32 D_001D4B34_003A8630;
extern s32 D_001D4B30_003A8630;
extern s32 D_001D4B00_003A8630;
extern s32 D_001D4B34_003A8630 __attribute__((section(".bss")));
extern s32 D_001D4B30_003A8630 __attribute__((section(".bss")));
extern s32 D_001D4B00_003A8630 __attribute__((section(".bss")));
extern s32 D_0022DF20[];
void func_003A8630(void) {
    s32 i;
    s32 *p = D_0022DF20;
    D_001D4B34_003A8630 = 0;
    D_001D4B30_003A8630 = D_001D4B00_003A8630;
    for (i = 0x3F; i >= 0; i--) {
        p[0] = 0;
        p[1] = 0;
        p += 4;
    }
}
/* localdecomp:end func_003A8630 */

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } E_3A3128;
extern s32 D_001D4B00;
extern s32 D_001D4B04;
extern s32 D_001D4B30;
extern s32 D_001D4B34;
extern E_3A3128 D_0022DF20_3A3128[];
extern s32 func_11F1E0();
INCLUDE_ASM("asm/nonmatchings/text", func_003A8678);

extern u8 D_001D7FC0;
INCLUDE_ASM("asm/nonmatchings/text", func_003A8770);

/* localdecomp:start func_003A87D8 */
extern s32 D_001D8000;
extern s32 D_001D8004;
extern s32 D_001D8008;
extern s32 D_001D800C;
extern s32 D_001D8010;
extern void func_0038CBC8(s32, s32);
void func_003A87D8(s32 a, s32 b, s32 c, s32 d) {
    a = (a + 63) & ~63;
    c = (c + 63) & ~63;
    D_001D8008 = c;
    D_001D800C = d;
    D_001D8000 = a;
    D_001D8004 = b;
    D_001D8010 = 0;
    func_0038CBC8(a, b);
    func_0038CBC8(D_001D8008, D_001D800C);
}
/* localdecomp:end func_003A87D8 */

/* localdecomp:start func_003A8830 */
extern u32 D_001D8010_003A8830;
extern u32 D_001D8004_003A8830;
extern s32 D_001D8000;
extern s32 D_001D8008;
u32 func_003A8830(s32 arg0, u32 arg1) {
    s32 temp_4;
    u32 temp_2;
    u32 temp_2_2;
    u32 temp_6;
    u32 var_2;
    u32 var_3;
    temp_2 = D_001D8010_003A8830;
    temp_6 = D_001D8004_003A8830;
    temp_4 = (arg0 + 0x3F) & 0xFFFFFFC0;
    if (temp_2 < temp_6) {
        if (temp_6 < (u32) (temp_2 + temp_4)) {
            D_001D8010_003A8830 = temp_6;
        }
        temp_2_2 = D_001D8010_003A8830;
        if (temp_2_2 < temp_6) {
            goto A;
        }
    }
    var_2 = (D_001D8010_003A8830 - D_001D8004_003A8830) + D_001D8008;
    goto done;
A:
    var_2 = temp_2_2 + D_001D8000;
done:
    var_3 = var_2 % arg1;
    if (var_3 != 0) {
        var_3 = arg1 - var_3;
        var_2 += var_3;
    }
    D_001D8010_003A8830 = (u32) (D_001D8010_003A8830 + (temp_4 + var_3));
    return var_2;
}
/* localdecomp:end func_003A8830 */

/* localdecomp:start func_003A88B8 */
extern s32 func_003A8770(s32);
extern s32 D_001DA034;
extern u8 D_00142BA0[];
extern s32 D_00227400[];
extern u8 D_00143A07[];
extern u8 D_00160C40_003A88B8[];
extern void func_00392BB8(s32 *);
extern void func_003A8980(s32, s32, s32, s32, s32);
void func_003A88B8(s32 arg) {
    u32 *p;
    s32 idx;
    s32 v;
    s32 d;
    s32 x;
    s32 arr;
    u8 *q;
    s32 f;
    if (arg < 0) {
        D_001DA034 = 0;
        return;
    }
    idx = func_003A8770(arg);
    p = (u32 *)(D_00142BA0 + (((u32)arg >> 2) << 2));
    *p |= 1 << (arg & 0x1F);
    func_00392BB8(D_00227400);
    q = D_00160C40_003A88B8;
    arr = (s32)q + 8;
    x = (idx * 4 + 2) << 2;
    v = *(s32 *)(x + arr);
    d = D_00143A07[0];
    if (D_00227400[0]) d = 0;
    f = idx == 0x1F;
    func_003A8980(v + *(s32 *)(q + 4), *(s32 *)(D_00160C40_003A88B8 + x + 0xC), (idx << 4) + arr, d, f);
}
/* localdecomp:end func_003A88B8 */

extern u8 D_001A30B0[];
extern s32 D_001DA030;
extern s32 D_001DA034;
extern s32 D_001DA038;
extern s32 D_001DA03C;
extern s32 D_001DA040;
extern s32 D_001DA044;
extern s16 D_001CD018[];
extern void func_13CF80();
extern void func_11F0A0();
extern void func_003A1C28();
extern void func_0038A238();
extern void func_003A0D40();
INCLUDE_ASM("asm/nonmatchings/text", func_003A8980);

extern s32 D_001D4D40;
extern void *D_001DA044_003A8A58;
extern u8 D_001A30B0[];
extern void (*D_001D5BD4)(s32);
extern s32 D_00227460[];
extern s32 D_001D5B90;
extern s32 D_001D5BD8;
extern void func_0038A238(s32);
extern void func_003A1930(void *, s32, s32);
extern void func_003A1D00(void);
extern void func_003A9108(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003A8A58);

INCLUDE_ASM("asm/nonmatchings/text", func_003A8B10);

/* localdecomp:start func_003A8F50 */
extern s32 D_001425AC[];
extern s16 D_0016C5A8[];
extern s32 D_001D4D40;
extern void func_00392DF0(s32, s32);
void func_003A8F50(void) {
    D_001D4D40 = 1;
    D_0016C5A8[0] = 1;
    D_001425AC[0] = 1;
    func_00392DF0(1, 1);
}
/* localdecomp:end func_003A8F50 */
TEXT_PADDING(2);

/* localdecomp:start func_003A8F90 */
extern void func_0038CB50();
void func_003A8F90(u32 a) {
    while (*(volatile u32 *)0x10008000 & 0x100) {
        func_0038CB50(0x10);
    }
    *(volatile u32 *)0x10008020 = 0;
    *(volatile u32 *)0x10008030 = a & 0xFFFFFFF;
    *(volatile u32 *)0x10008000 = 0x145;
    while (*(volatile u32 *)0x10008000 & 0x100) {
        func_0038CB50(0x10);
    }
}
/* localdecomp:end func_003A8F90 */

extern u32 D_001D545C;
extern u32 D_00334CB0[];
extern s32 D_001DA058;
extern s32 D_001D5BA4;
extern void func_003A90A0(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003A9050);

extern s32 D_001DA05C;
extern s32 D_001DA048[];
extern s32 D_001DA058;
extern s32 D_001D5BA4;
extern s32 D_001D5BA8;
extern s32 D_001D9D30;
extern s32 D_001D9D34;
extern s32 D_001D9D38;
INCLUDE_ASM("asm/nonmatchings/text", func_003A90A0);

extern Struct227600 D_00227580;
extern s32 D_001DA048[];
extern u32 *D_001DA050_g;
extern s32 D_001DA05C_g;
extern void func_003A90A0(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003A9108);

/* func_003A9150 (frontbin), PAL retail bytes, compiled with the file's own flags
   (src/frontbin/3A53E8.c: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division).

   Retail reaches D_001D5BA4, D_001D5BA8, D_001DA050, D_001DA058, D_001DA05C,
   D_001D9D34 and D_001D9D38 through lui/%lo and D_001D9D30 through $gp.  With
   -G8 every one of them is small data, so gcc emits a $gp reference and the
   assembler keeps it.  The size hints below tell the assembler these seven
   are not small data (16 > the -G8 limit), so it expands each $gp reference
   into the lui/%lo form retail has; D_001D9D30 keeps no hint and stays on
   $gp, as in retail. */

/* localdecomp:start func_003A9150 */
extern s32 D_001D5BA4;
extern s32 D_001D5BA8;
extern s32 D_001D9D30;
extern s32 D_001D9D34;
extern s32 D_001D9D38;
extern u8 D_001DA048_003A9150[];
extern s32 D_001DA050;
extern s32 D_001DA058;
extern s32 D_001DA05C;

/* Ps2EeAs (retail's assembler) did not know these sizes and used lui/%lo;
   the size hints reproduce that with the file's own assembler. */
__asm__(".extern D_001D5BA4, 16");
__asm__(".extern D_001D5BA8, 16");
__asm__(".extern D_001D9D34, 16");
__asm__(".extern D_001D9D38, 16");
__asm__(".extern D_001DA050, 16");
__asm__(".extern D_001DA058, 16");
__asm__(".extern D_001DA05C, 16");

void func_003A9150(void) {
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_t0;
    s32 temp_v1;

    temp_a2 = 1 - D_001DA05C;
    temp_t0 = *(s32 *)(D_001DA048_003A9150 + (temp_a2 * 4));
    temp_v1 = (temp_t0 + D_001DA058) & 0xFFFFE000;
    D_001DA05C = temp_a2;
    temp_a0 = temp_v1 - D_001D5BA4;
    D_001DA050 = temp_t0;
    D_001D9D34 = temp_v1 - D_001D5BA8;
    D_001D9D38 = temp_a0 - 0x2000;
    D_001D9D30 = temp_a0;
}
/* localdecomp:end func_003A9150 */

extern s32 D_001D8014_003A91D0;
extern s32 D_001DA060_g_003A91D0;
extern s32 D_001DA060_003A91D0;
extern s32 D_001DA058_003A91D0;
extern s32 D_001DA05C_003A91D0;
extern s32 D_001DA048_003A91D0[];
extern u32 *D_001DA050_003A91D0;
extern s32 *func_12D650();
extern void func_12D938();
extern void func_11F0A0();
extern void func_003D9DA8();
extern void func_003A9150();
INCLUDE_ASM("asm/nonmatchings/text", func_003A91D0);

/* localdecomp:start func_003A92F0 */
extern s32 D_001D8014;
extern void func_0038CB50(s32);
void func_003A92F0(s32 a) {
    while (D_001D8014 & a) {
        func_0038CB50(0x400);
    }
}
/* localdecomp:end func_003A92F0 */

extern u32 *D_001DA050_003A9338;
INCLUDE_ASM("asm/nonmatchings/text", func_003A9338);

LINKER_REMNANT("asm/remnants", func_003A9388);

/* PAL candidate for func_003A9390.
 *
 * Retail reaches the packet pointer global two different ways in this one
 * function: the reads (and the last write) are the split lui/lw form, while the
 * write in the jal delay slot is a $gp relative store.  That is the documented
 * "mixed access in one function" shape: the assembler expands a $gp access of a
 * symbol it knows is not small data into lui/lw, and keeps $gp in a branch
 * delay slot where it cannot expand.
 *
 * So the reads use an alias of the global whose size the assembler is told
 * (16, not small data), and the delay slot store uses the file's own sized
 * declaration, which stays $gp relative. */

/* localdecomp:start func_003A9390 */
extern u32 *D_001DA050_003A9390;
extern void func_0038CD28(u32 *, s32, s32);
extern u32 *D_001DA050_003A9390_x;
__asm__(".extern D_001DA050_003A9390_x, 16");
void func_003A9390(u32 a0, s32 a1, u32 a2) {
    D_001DA050_003A9390_x[0] = a2 | 0x10000000;
    D_001DA050_003A9390_x[1] = 0;
    D_001DA050_003A9390_x[2] = 0x1000404;
    D_001DA050_003A9390_x[3] = a0 | (a2 << 16) | 0x6C000000;
    D_001DA050_003A9390 = (u32 *)((u8 *)D_001DA050_003A9390_x + 0x10);
    func_0038CD28(D_001DA050_003A9390, a1, a2 << 4);
    D_001DA050_003A9390_x = (u32 *)((u8 *)D_001DA050_003A9390_x + (a2 << 4));
}
/* localdecomp:end func_003A9390 */

LINKER_REMNANT("asm/remnants", func_003A9438);

extern u32 *D_001DA050_003A9440;
INCLUDE_ASM("asm/nonmatchings/text", func_003A9440);

LINKER_REMNANT("asm/remnants", func_003A94F8);

/* PAL candidate for func_003A9500 (US draft func_003A3FB0).

   Retail reaches the global pointer D_001DA050 through `lui`/`lw` for every
   load of the pointer - the address is re-materialised in the register each
   load goes into - but through `$gp` for the store that writes the advanced
   pointer back.  One symbol cannot be reached both ways, so the loads use
   their own name and the store uses the sized one, exactly like the matched
   func_003C30C0 in this repository does for the same global (0x1DA050). */

/* localdecomp:start func_003A9500 */
typedef struct { u8 pad[0x150]; s16 w; s16 h; } S_1CFEC0_3A3FB0;
extern S_1CFEC0_3A3FB0 D_001CFEC0_003A9500;
extern u32 *D_001DA050_003A9500;
extern u32 *D_001DA050_003A9500_lui;
__asm__(".extern D_001DA050_003A9500_lui, 16");
void func_003A9500(s32 x0, s32 x1, s32 y0, s32 y1) {
    s32 w = D_001CFEC0_003A9500.w - 1;
    s32 h = D_001CFEC0_003A9500.h - 1;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (w < x1) x1 = w;
    if (h < y1) y1 = h;
    D_001DA050_003A9500_lui[0] = 0x10000002;
    D_001DA050_003A9500_lui[1] = 0;
    D_001DA050_003A9500_lui[2] = 0;
    D_001DA050_003A9500_lui[3] = 0x50000002;
    D_001DA050_003A9500_lui[4] = 0x8001;
    D_001DA050_003A9500_lui[5] = 0x10000000;
    D_001DA050_003A9500_lui[6] = 0xE;
    D_001DA050_003A9500_lui[7] = 0;
    *(unsigned long *)(D_001DA050_003A9500_lui + 8) = (unsigned long)x0 | ((unsigned long)x1 << 16) | ((unsigned long)y0 << 32) | ((unsigned long)y1 << 48);
    D_001DA050_003A9500_lui[10] = 0x40;
    D_001DA050_003A9500_lui[11] = 0;
    D_001DA050_003A9500 = D_001DA050_003A9500_lui + 12;
}
/* localdecomp:end func_003A9500 */

extern u32 *D_001DA050_g;
extern u8 D_001D7830[];
INCLUDE_ASM("asm/nonmatchings/text", func_003A9618);

extern u32 *D_001DA050_g;
extern u8 D_001D7300[];
INCLUDE_ASM("asm/nonmatchings/text", func_003A9678);

extern u32 *D_001DA050_g;
extern u8 D_001D7330[];
INCLUDE_ASM("asm/nonmatchings/text", func_003A96D8);

LINKER_REMNANT("asm/remnants", func_003A9738);

extern u32 *D_001DA050_003A9740;
extern u8 D_00142120[];
extern u8 D_001D5330[];
extern void func_0038CC88();
INCLUDE_ASM("asm/nonmatchings/text", func_003A9740);

LINKER_REMNANT("asm/remnants", func_003A9820);

extern void func_12C9A0(s32, s16, s16, s16, s16, s16, s16, s16);
INCLUDE_ASM("asm/nonmatchings/text", func_003A9830);

/* Candidate for func_003A9A40 (PAL frontbin).
   Retail reaches D_001DA068/D_001DA06C with lui/lo (not $gp): the compiler emits a
   plain `lw $2,sym` for a small-data scalar and the assembler turns that into the
   $gp form because the symbol's size (4) says it is small data.  Declaring the size
   as 16 before the first use tells the assembler the symbol is not small data, so
   it expands the macro to lui + access, the way retail has it. */

/* localdecomp:start func_003A9A40 */
__asm__(".extern D_001DA068, 16");
__asm__(".extern D_001DA06C, 16");
extern s32 D_001DA068;
extern s32 D_001DA06C;
extern void func_003A9B40();
extern void func_003A9C40();
extern s32 func_11EB30();
extern void func_11F9A8();
void func_003A9A40(void) {
    if (D_001DA068 == 0 && D_001DA06C == 0) {
        volatile u32 *r = (volatile u32 *)0x1000E010;
        if ((*r & 0x20000) == 0) {
            *(u32 *)0x1000E010 = 0x20000;
        }
        D_001DA068 = func_11EB30(1, func_003A9B40, 0);
        D_001DA06C = func_11EB30(0xF, func_003A9C40, 0);
        func_11F9A8(1);
    }
}
/* localdecomp:end func_003A9A40 */

extern s32 D_001DA068;
extern s32 D_001DA06C;
extern void func_11EB50(s32, s32);
extern void func_11F940(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003A9AD0);

ASM_FUNC("asm/handwritten", func_003A9B40);

ASM_FUNC("asm/handwritten", func_003A9C40);

typedef struct { u32 a, b, c, d; } S_3A4720;
extern S_3A4720 *D_001DA050_003A9C70;
INCLUDE_ASM("asm/nonmatchings/text", func_003A9C70);

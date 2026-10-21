#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003A8C70();
extern void func_003A8B90(s32, s32, s32, s32);
extern u32 func_003A8BE8(s32, u32);
/* --- end of declarations from other files --- */

/* declarations of 3A56A8.c's earlier functions (tools/port_from_us.py) */
extern u8 D_001A30B0[];
#define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
extern s32 D_001D6E1C;
extern u8 D_1A3100[];
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_13C170(void);
extern s32 func_12C908(s32);
extern void func_003A5A20(void);
typedef struct { u8 x0; s8 x1; s8 x2; s8 x3; u16 x4; u16 x6; s32 x8; s32 xC; u32 x10; s32 x14; s32 x18; u8 pad[0x60-0x1C]; } S_3A0200;
extern S_3A0200 D_0022D430[];
extern s32 D_0022D8B0[];
extern void func_003C2C38(s32 p);
typedef struct O2_3A02D8 { u8 pad[8]; void *f8; } O2_3A02D8;
typedef struct { u8 pad[0x30]; u8 f30; u8 pad31; s16 f32; u16 f34; u8 pad36[0x63 - 0x36]; u8 f63; u8 pad64[4]; O2_3A02D8 *f68; } O_3A02D8;
typedef struct { O_3A02D8 *f0; u8 pad[0x40]; } S_16C580_3A02D8;
extern S_16C580_3A02D8 D_0016C580_003A5AF8;
extern u32 D_001D54D0;
extern s16 D_001D5BB0[4];
extern s16 D_001D5BB6;
extern s16 D_001D5BB8;
extern s16 D_001D5BBA;
extern s16 D_001D5BBC;
extern O_3A02D8 *func_003C2868_003A5AF8(s32, s32);
extern void func_003A5AA0(void);
typedef struct { u8 p0[0x20]; s16 f20; } S_16C580_3A0D58;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0D58;
extern S_16C580_3A0D58 D_16C580_003A6578;
extern f32 func_00382918(void);
extern void func_003C4FD0(f32 *v, f32 r);
typedef struct { u8 pad[0x30]; s32 f30; u8 pad2[0x38]; s32 f6C; } S_225780;
typedef struct { s32 v[0x53]; } E_160C40;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad2[0xB0]; E_160C40 e[1]; } S_160C40;
extern S_225780 D_00225700_003A6C08;
extern S_160C40 D_160C40;
extern s32 func_003A2998(s32, s32, s32);
extern s32 func_003A2B50(s32);
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
extern S_225780_3A1438 D_00225700_003A6C90;
extern S_1A4BE0_3A1438 D_001A4BE0_003A6C90;
extern f32 D_001D9BD0_003A6C90;
extern s32 D_001D5B90_003A6C90;
extern Pad_3A1438 *D_001D52FC_003A6C90;
extern s32 D_00142690_003A6C90[];
extern s32 D_001D4D40_003A6C90;
extern s32 D_001D545C_003A6C90;
extern s32 D_00143950_003A6C90[];
extern s16 D_001CCFD4_003A6C90[];
extern O_3A1438 *D_001DA008;
extern s32 D_001D4B60_003A6C90;
extern E_3A1438 *D_001DA49C_003A6C90;
extern E_3A1438 *D_001DA4A4_003A6C90;
extern void func_003E58D8(void);
extern s32 func_003A1B98(void);
extern void func_003C2D68_003A6C90(O_3A1438 *);
extern void func_0038D200_003A6C90(void *, void *, f32);
extern void func_003A5CC0(O_3A1438 *, s32);
extern void func_0038A2F8_003A6C90(void (*)(), O_3A1438 *);
extern void func_003C7FF0_003A6C90(O_3A1438 *);
extern void func_00381C78(O_3A1438 *, s32);
extern void func_00381BA0(O_3A1438 *);
extern s32 func_00381BC0_003A6C90(void);
extern void func_003D0ED8(void);
extern void func_003A70C8(void);
extern s32 func_003A6C08(s32);
extern s32 func_003A2B50(s32);
extern void func_003E5970(void);
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
extern S_225780_3A1870 D_00225700_003A70C8;
extern O_3A1870 *D_001D9BCC;
extern void func_11F0A0(s32);
extern void func_003A0B60(u8 *, u32);
extern O_3A1870 *func_003C2868_003A70C8(s32, s32);
extern s32 D_001D6EF8[2];
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[4]; s32 f3C; u8 pad40[8]; s16 f48; u8 pad4A[2]; s32 f4C;
    u8 pad50[8]; s32 f58; u8 pad5C[0x68 - 0x5C]; s32 f68; s32 f6C; u8 pad70[0x1E0 - 0x70];
} S_225780_3A1AD0;
typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad10[0x14C - 0x10]; } R_3A1AD0;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad1288[0x1300 - 0x1288]; R_3A1AD0 r[1]; } S_160C40_3A1AD0;
typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_1CCFD0_3A1AD0;
typedef struct { u8 pad[6]; u8 f6; u8 pad7[9]; } S_143950_3A1AD0;
extern S_225780_3A1AD0 D_00225700_003A7328;
extern S_160C40_3A1AD0 D_160C40_003A7328;
extern S_1CCFD0_3A1AD0 D_1CCFD0_003A7328;
extern S_143950_3A1AD0 D_00143950_003A7328;
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
extern s32 D_001D9BDC_003A7328;
extern s32 D_001D9BE0_003A7328;
extern f32 D_001D9BD0_003A7328[1];
extern s32 D_001D9BD8_003A7328[1];
extern void func_0038CF58(void *, s32, s32);
extern s32 func_003A72F8(s32);
extern void func_0038A618(s32);
extern s32 func_003A6C08(s32);
extern void func_003A70C8(void);
extern void func_003A83E8(void);
extern void func_003A2F68(s32, s32);
extern s32 func_12C908(s32);
extern s32 func_003A1B98(void);
typedef struct { u8 p0[0x24]; s32 f24; u8 p28[0x44]; s32 f6C; u8 p70[6]; u16 f76; u8 p78[0x1C]; s32 f94; u8 p98[6]; u16 f9E; } S_3A1E48a;
typedef struct { u8 p0[0xC]; u8 bC; u8 pD[0x3B]; s32 f48[1]; } S_3A1E48c;
typedef struct { u8 p0[0x24]; S_3A1E48c *f24; } S_3A1E48d;
typedef struct { u8 p0[0x44]; s16 n44; u8 p46[0x15A]; S_3A1E48d *e[1]; } S_3A1E48b;
typedef struct { u8 p0[0x34]; u16 h34; } S_3A1E48e;
extern S_3A1E48a D_001CCFD0_003A76A0;
extern u8 D_00225900_003A76A0[];
extern S_3A1E48b D_00225700_003A76A0;
extern u8 D_001A4BE0_003A76A0[];
extern S_3A1E48e *D_001D9DD8;
extern s32 D_001D9BDC;
extern s32 D_001D9BE0;
extern s32 D_001D9BD0[1];
extern void func_0038A618(s32);
extern s32 func_12C908(s32);
extern void func_13B620_003A76A0(void);
extern void func_003877A0();
extern void func_003C2C38(s32 p);
typedef struct { u8 pad[0x44]; s16 h44; u8 pad2[0x15A]; s32 tbl[1]; } S_225780_3A2028;
typedef struct { u8 pad[0x28]; s32 f28; } E_3A2028;
extern S_225780_3A2028 D_00225700_3A7708;
extern E_3A2028 *D_001DA49C_3A7708;
extern s32 D_001D5B94;
extern s32 D_001D5B90;
extern s32 D_001D9BC4;
extern s32 D_001D9BC8;
extern s32 D_001D9D1C;
extern void func_003A9588();
extern void func_003A9508();
extern void func_003927B0();
extern void func_00392B28();
extern void func_00392698();
extern void func_0039C7F0();
extern void func_003865D0();
extern void func_003C3178();
extern void func_00388348();
extern void func_003A3F70();
extern s32 func_003A6C90();
extern void func_00392730();
extern void func_00388ED8();
extern void func_003A96A8();
extern void func_003A76A0();
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[0x14]; s32 f4C; } S_225780_3A21C0;
extern S_225780_3A21C0 D_00225700_003A7A18;
extern u8 D_00160C40_003A8C70[];
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
extern void func_003A2028(void);
extern s32 func_003A8B28(s32);
extern void func_13CF80(s32, s32, s32, s32, s32);
extern void func_0038A618(s32);
extern void func_003A96A8(s32);
extern s32 func_12C908(s32);
extern void func_00388348();
extern void func_003916C8(void);
extern void func_003A9588();
extern void func_003A9508();
extern void func_11F0A0(s32);
extern void func_003A5830(void);
extern long func_13CDF0_003A7A18(s32);
extern s32 func_13CD28(s32, s32, s32, void *);
extern s32 func_003AFC48(s32, s32, s32 (*)(s32, s32), s32, s32);
extern s32 func_12A9F0(s32, s32);
extern void func_12D4D8(u8 *);
extern void func_003A94C0(void);
typedef struct { u8 pad[0x20]; void *p20; u8 pad2[0x1C]; s32 p40; } S2_3A2BC0;
typedef struct { u8 pad[0x30]; s32 f30; u8 pad2[0x1C]; S2_3A2BC0 *f50; u8 pad3[0x14C]; s32 f1A0[4]; } B_3A2BC0;
extern B_3A2BC0 D_00225700;
extern S2_3A2BC0 D_00334B90[];
extern s32 D_001D7000;
extern void *D_001D7080;
extern s32 D_001D7090;
typedef struct { u8 pad[0x48]; s32 f48; s32 f4C; } E_3A2DF8;
extern u8 *D_001D6EEC;
extern f32 D_001D6EF0;
extern s32 D_001DA010[2];
extern u8 *D_001D6EEC;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A2EE0;
typedef struct {
    V4_3A2EE0 v0; V4_3A2EE0 v10;
    f32 f20; f32 f24; f32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C;
    s32 f40; s32 f44; s32 f48; s32 f4C;
} E_3A2EE0;
extern u8 *D_001D6EEC;
extern s32 func_0038DFB8(s32, s32, f32);
extern f32 func_0038DE98(f32, f32);
extern f32 func_003828C0(f32, f32);
extern void func_0038D200(f32 *, void *, f32);
extern s32 func_0038CEB0(void *);
typedef struct { u8 pad0[0x24]; f32 f24; f32 f28; u8 pad2C[4]; s32 f30; u8 pad34[4]; s32 f38; s32 f3C; u8 pad40[8]; s32 f48; s32 f4C; } E_3A3028;
extern E_3A3028 *D_001D6EEC_003A8850;
extern f32 D_001D6EF0;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } E_3A3128;
extern s32 D_001D4B00;
extern s32 D_001D4B04;
extern s32 D_001D4B30;
extern s32 D_001D4B34;
extern E_3A3128 D_0022DF20_3A88E8[];
extern s32 func_11F1E0();
extern u8 D_001D7FC0;

/* localdecomp:start func_003A8B90 */
extern s32 D_001D8000;
extern s32 D_001D8004;
extern s32 D_001D8008;
extern s32 D_001D800C;
extern s32 D_001D8010;
extern void func_0038CFA8(s32, s32);
void func_003A8B90(s32 a, s32 b, s32 c, s32 d) {
    a = (a + 63) & ~63;
    c = (c + 63) & ~63;
    D_001D8008 = c;
    D_001D800C = d;
    D_001D8000 = a;
    D_001D8004 = b;
    D_001D8010 = 0;
    func_0038CFA8(a, b);
    func_0038CFA8(D_001D8008, D_001D800C);
}
/* localdecomp:end func_003A8B90 */

/* localdecomp:start func_003A8BE8 */
extern u32 D_001D8010_003A8BE8;
extern u32 D_001D8004_003A8BE8;
extern s32 D_001D8000;
extern s32 D_001D8008;
u32 func_003A8BE8(s32 arg0, u32 arg1) {
    s32 temp_4;
    u32 temp_2;
    u32 temp_2_2;
    u32 temp_6;
    u32 var_2;
    u32 var_3;
    temp_2 = D_001D8010_003A8BE8;
    temp_6 = D_001D8004_003A8BE8;
    temp_4 = (arg0 + 0x3F) & 0xFFFFFFC0;
    if (temp_2 < temp_6) {
        if (temp_6 < (u32) (temp_2 + temp_4)) {
            D_001D8010_003A8BE8 = temp_6;
        }
        temp_2_2 = D_001D8010_003A8BE8;
        if (temp_2_2 < temp_6) {
            goto A;
        }
    }
    var_2 = (D_001D8010_003A8BE8 - D_001D8004_003A8BE8) + D_001D8008;
    goto done;
A:
    var_2 = temp_2_2 + D_001D8000;
done:
    var_3 = var_2 % arg1;
    if (var_3 != 0) {
        var_3 = arg1 - var_3;
        var_2 += var_3;
    }
    D_001D8010_003A8BE8 = (u32) (D_001D8010_003A8BE8 + (temp_4 + var_3));
    return var_2;
}
/* localdecomp:end func_003A8BE8 */

/* localdecomp:start func_003A8C70 */
extern s32 func_003A8B28(s32);
extern s32 D_001DA034;
extern u8 D_00142BA0[];
extern s32 D_00227400[];
extern u8 D_00143A07[];
extern u8 D_00160C40_003A8C70[];
extern void func_00392F98(s32 *);
extern void func_003A8D38(s32, s32, s32, s32, s32);
void func_003A8C70(s32 arg) {
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
    idx = func_003A8B28(arg);
    p = (u32 *)(D_00142BA0 + (((u32)arg >> 2) << 2));
    *p |= 1 << (arg & 0x1F);
    func_00392F98(D_00227400);
    q = D_00160C40_003A8C70;
    arr = (s32)q + 8;
    x = (idx * 4 + 2) << 2;
    v = *(s32 *)(x + arr);
    d = D_00143A07[0];
    if (D_00227400[0]) d = 0;
    f = idx == 0x1F;
    func_003A8D38(v + *(s32 *)(q + 4), *(s32 *)(D_00160C40_003A8C70 + x + 0xC), (idx << 4) + arr, d, f);
}
/* localdecomp:end func_003A8C70 */

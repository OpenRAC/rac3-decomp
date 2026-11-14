#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


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
/* localdecomp:start func_003A6CC8 */
extern void func_003C25D8(O_3A1870 *, s32);
void func_003A6CC8(void) {
    s32 i;
    u8 *data;
    s32 *offs;
    u8 *e;
    u8 *q;
    s32 kind;
    O_3A1870 *o;
    s32 n;
    s32 j;
    func_11F0A0(0);
    func_003A0760((u8 *)D_00225700_003A6CC8.f6C, (u32)D_00225700_003A6CC8.f68);
    func_11F0A0(0);
    data = D_00225700_003A6CC8.f68;
    D_00225700_003A6CC8.f38 = 0;
    offs = (s32 *)(data + 0x14);
    D_00225700_003A6CC8.f40 = *(u16 *)(data + 0);
    D_00225700_003A6CC8.f48 = *(u16 *)(data + 8);
    D_00225700_003A6CC8.f44 = *(u16 *)(data + 0xC);
    D_00225700_003A6CC8.f64 = data + *(s32 *)(data + 0x10);
    for (i = 0; i < D_00225700_003A6CC8.f44; i++) {
        e = data + *offs++;
        kind = *(s32 *)e;
        e += 0xC;
        o = D_00225700_003A6CC8.f1A0[i];
        q = data + *(s32 *)e;
        e += 4;
        if (kind == 0x215) kind = 0xD54;
        if (o == 0) {
            if (kind == 0) {
                o = D_001D9BCC;
                func_003C25D8(o, 0);
            } else {
                o = func_003C24B0_003A6CC8(kind, 0x80);
            }
            o->f32 = 0x1FF;
            o->f34 |= 6;
            o->f62 = 0xFF;
            o->f38 = 0x20202000000000UL;
            o->f98 = 0;
            if (o->f24->f6 != 0) {
                if (o->fAA == 0xD54) o->f63 = 0;
                else o->f63 = 8;
            }
            n = o->f24->fC;
            o->f24->fC = n + 1;
            o->f42 = n;
            o->f43 = n;
            D_00225700_003A6CC8.f1A0[i] = o;
            if (o->fAA == 0xD54) D_00225700_003A6CC8.f54 = o;
        }
        o->f68 = q;
        o->f24->f48[o->f42] = e;
        for (j = 0; j < ((E_3A1870 *)e)->n; j++) {
            ((E_3A1870 *)e)->a[j] = (s32)(e + ((E_3A1870 *)e)->a[j]);
        }
    }
}
/* localdecomp:end func_003A6CC8 */

/* localdecomp:start func_003A6EF8 */
__asm__(".extern D_001D6EF8, 8");
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
/* localdecomp:start func_003A7480 */
/* PAL candidate for func_003A7480 (boot_elf): the US draft
   (rac3-uya-decomp func_003A7708) with the missing declaration of
   func_003A6F28_003A7480 added, so it builds with the flags of
   src/boot_elf/text/3A6C90.c. */

typedef struct { u8 pad[0x44]; s16 h44; u8 pad2[0x15A]; s32 tbl[1]; } S_225780_3A2028_003A7480;
typedef struct { u8 pad[0x28]; s32 f28; } E_3A2028_003A7480;
extern S_225780_3A2028_003A7480 D_00225700_3A7708;
extern E_3A2028_003A7480 *D_001DA49C_3A7708;
extern s32 D_001D5B94_003A7480;
extern s32 D_001D5B90_003A7480;
extern s32 D_001D9BC4_003A7480;
extern s32 D_001D9BC8_003A7480;
extern s32 D_001D9D1C_003A7480;
extern void func_003A91D0_003A7480();
extern void func_003A9150_003A7480();
extern void func_003923D0_003A7480();
extern void func_00392748_003A7480();
extern void func_003922B8_003A7480();
extern void func_0039C410_003A7480();
extern void func_003861F0_003A7480();
extern void func_003C2DC0_003A7480();
extern void func_00387F68_003A7480();
extern void func_003A3B70_003A7480();
extern s32 func_003A6890_003A7480();
extern void func_00392350_003A7480();
extern void func_00388AF8_003A7480();
extern void func_003A92F0_003A7480();
extern void func_003A72A0_003A7480();
extern s32 func_003A6F28_003A7480();
s32 func_003A7480(void) {
    E_3A2028_003A7480 *t;
    E_3A2028_003A7480 *e;
    s32 i;
    s32 r;
    s32 s;
    if (func_003A6F28_003A7480() == 0) return 1;
    t = D_001DA49C_3A7708;
    for (i = 0; i < D_00225700_3A7708.h44; i++) {
        do { e = (E_3A2028_003A7480 *)D_00225700_3A7708.tbl[i]; } while (0);
        if (e != 0 && t != e) {
            do { e->f28 = (s32)t; t = e; } while (0);
        }
    }
    D_001D5B94_003A7480 = 2;
    do {
        func_003A91D0_003A7480();
        func_003A9150_003A7480();
        func_003923D0_003A7480();
        func_00392748_003A7480(1);
        func_003922B8_003A7480();
        func_0039C410_003A7480();
        func_003861F0_003A7480();
        func_003C2DC0_003A7480();
        func_00387F68_003A7480();
        D_001D9D1C_003A7480 = -1;
        func_003A3B70_003A7480();
        r = func_003A6890_003A7480();
        func_00392350_003A7480(0);
        D_001D9BC4_003A7480 = 0x131;
        func_00388AF8_003A7480(0);
        s = D_001D5B90_003A7480;
        if (s != -2) {
            D_001D5B94_003A7480 = s;
            D_001D5B90_003A7480 = -2;
        }
        func_003A92F0_003A7480(1);
        func_12C908(0);
        D_001D9BC8_003A7480 = D_001D9BC8_003A7480 + 1;
    } while (D_001D5B94_003A7480 == 2);
    D_001D5B94_003A7480 = 0;
    func_003A72A0_003A7480();
    return r;
}
/* localdecomp:end func_003A7480 */

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
/* localdecomp:start func_003A7618 */
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[0x14]; s32 f4C; } S_225780_3A21C0_003A7618;
extern S_225780_3A21C0_003A7618 D_00225700_003A7618_003A7618;
extern u8 D_00160C40_003A8C70[];
extern u8 D_00142BA0_003A7618[];
extern u8 D_001A30B0_003A7618[];
extern u8 D_00143A07_003A7618[];
extern u8 D_001D52E0_003A7618;
extern u8 D_13D208_003A7618[];
extern s32 D_002275EC_003A7618[];
extern s32 D_001D4BB0_003A7618;
extern s32 D_001D4BB4_003A7618;
extern s32 D_001D5B94_003A7618;
extern s32 D_001D9BC8_003A7618;
extern void func_003A1C28_003A7618(void);
extern s32 func_003A8770_003A7618(s32);
extern void func_13CF80_003A7618(s32, s32, s32, s32, s32);
extern void func_0038A238_003A7618(s32);
extern void func_003A92F0_003A7618(s32);
extern s32 func_12C908_003A7618(s32);
extern void func_00387F68_003A7618();
extern void func_003912E8_003A7618(void);
extern void func_003A91D0_003A7618();
extern void func_003A9150_003A7618();
extern void func_11F0A0_003A7618(s32);
extern void func_003A5430_003A7618(void);
extern long func_13CDF0_003A7A18(s32);
extern s32 func_13CD28_003A7618(s32, s32, s32, void *);
extern void func_003A87D8_003A7618(s32, s32, s32, s32);
extern u32 func_003A8830_003A7618(s32, u32);
extern s32 func_003AF890_003A7618(s32, s32, s32 (*)(s32, s32), s32, s32);
extern s32 func_12A9F0_003A7618(s32, s32);
extern void func_12D4D8_003A7618(u8 *);
extern void func_003A9108_003A7618(void);
s32 func_003A7618(s32 arg) {
    s32 idx;
    u8 *q;
    s32 arr;
    s32 x;
    s32 a;
    s32 b;
    s32 *e;
    s32 base;
    s32 hi;
    s32 lo;
    u8 buf[4];
    s32 one;
    D_001D4BB0_003A7618 = D_001D4BB4_003A7618;
    one = 1;
    func_003A1C28_003A7618();
    D_001D5B94_003A7618 = one;
    if (arg >= 0) {
        u32 *p = (u32 *)(D_00142BA0_003A7618 + (((u32)arg >> 2) << 2));
        *p |= one << (arg & 0x1F);
    }
    idx = func_003A8770_003A7618(arg);
    q = D_00160C40_003A8C70;
    arr = (s32)q + 8;
    x = (idx * 4 + 2) << 2;
    D_001A30B0_003A7618[0x43] |= 8;
    a = *(s32 *)(x + arr) + *(s32 *)(q + 4);
    b = *(s32 *)(D_00160C40_003A8C70 + x + 0xC);
    D_00225700_003A7618_003A7618.f4C = 0;
    D_00225700_003A7618_003A7618.f34 = 0;
    func_13CF80_003A7618(2, 0, 0, 0, 0);
    func_0038A238_003A7618(4);
    func_003A92F0_003A7618(1);
    func_12C908_003A7618(0);
    D_001D9BC8_003A7618 = D_001D9BC8_003A7618 + 1;
    func_00387F68_003A7618();
    func_003912E8_003A7618();
    func_003A91D0_003A7618();
    func_003A9150_003A7618();
    func_11F0A0_003A7618(0);
    func_003A5430_003A7618();
    func_003A1C28_003A7618();
    func_11F0A0_003A7618(0);
    func_003A5430_003A7618();
    func_003A1C28_003A7618();
    func_13CDF0_003A7A18(0);
    e = (s32 *)((idx << 4) + arr);
    base = D_002275EC_003A7618[0] - 0x2C0000;
    hi = base - 0x1E0000;
    lo = hi - 0x8000;
    if (*e != 0) {
        buf[0] = 100;
        buf[1] = D_001D52E0_003A7618;
        buf[2] = 0;
        func_13CDF0_003A7A18(0);
        func_13CD28_003A7618(*e + *(s32 *)(q + 4), 0x10, lo, buf);
        func_13CDF0_003A7A18(0);
        D_00225700_003A7618_003A7618.f4C = lo;
    } else {
        D_00225700_003A7618_003A7618.f4C = 0;
    }
    D_00225700_003A7618_003A7618.f34 = 0;
    func_003A87D8_003A7618(base, 0x2C0000, hi, 0x1E0000);
    one = func_003AF890_003A7618(a, b, (s32 (*)(s32, s32))func_003A8830_003A7618, D_00143A07_003A7618[0], 0) != 0;
    func_12C908_003A7618(0);
    func_12A9F0_003A7618(0, 0);
    func_12D4D8_003A7618(D_13D208_003A7618);
    func_003A9108_003A7618();
    func_0038A238_003A7618(4);
    D_001D5B94_003A7618 = 6;
    D_001A30B0_003A7618[0x43] |= 0x10;
    return one;
}
/* localdecomp:end func_003A7618 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A78B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7AF8);

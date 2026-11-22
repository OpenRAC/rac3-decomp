#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A78B8(void);
typedef int u128_t __attribute__((mode(TI)));
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
/* localdecomp:start func_003A6890 */
#include "vu0.h"
extern f32 D_001D9BD0_003A6F28[1];
extern void func_003A8040(void);
extern s32 func_003E56E0(void);
extern void func_003A7AF8(void *);
extern s32 func_003A6808(s32);
extern void func_003A4288();
s32 func_003A6890(void) {
    s32 r;
    s32 over;
    f32 f;
    if (D_00225700_003A6890.f60 != 0) return 0;
    if (!(D_00225700_003A6890.f34 + 1 < D_00225700_003A6890.f40)) {
        D_001D5B90_003A6890 = 0;
        D_00225700_003A6890.f60 = 1;
        return 0;
    }
    func_003E5520();
    func_003A8040();
    f = D_001D9BD0_003A6F28[0] - 0.34f;
    D_00225700_003A6890.f38++;
    D_00225700_003A6890.f34++;
    D_001D9BD0_003A6F28[0] = f;
    if (f < 0.0f) D_001D9BD0_003A6F28[0] = 0.0f;
    if (!(D_00225700_003A6890.f34 < D_00225700_003A6890.f48)) func_003A1798();
    r = 0;
    over = !(D_00225700_003A6890.f34 < D_00225700_003A6890.f40);
    if (D_00225700_003A6890.f34 >= 0xF && D_001D9BD0_003A6F28[0] == 0.0f) {
        if (((D_00142690_003A6890[0] & 0xFFFF0000) != 0 || D_001D4D40_003A6890 != 0 || D_001D545C_003A6890 <= 0)
            && (((s32 *)&D_001D52FC_003A6890->f1A0)[1] & 0x800)) {
            r = 1;
        } else {
            r = 1;
            if ((D_001D52FC_003A6890->f1A0 & 0x8000000000FUL) ^ 0x8000000000FUL) r = 0;
        }
    }
    if (r != 0 || over) {
        D_00225700_003A6890.f60 = 1;
        D_001D5B90_003A6890 = 0;
    } else {
        s32 i;
        s32 v;
        s32 lim = D_00143950_003A6890[0] ? 0x50 : 0x60;
        if (D_00225700_003A6890.f38 >= lim) {
            D_00225700_003A6890.f3C++;
            if (D_001CCFD4_003A6890[0] != 0) func_003A2750(1);
            func_003A6CC8();
            func_003A6808(D_00225700_003A6890.f3C + 1);
        }
        v = func_003E56E0();
        for (i = 0; i < D_00225700_003A6890.f44; i++) {
            O_3A1438 *o = D_00225700_003A6890.f1A0[i];
            s32 h = D_00225700_003A6890.f38 >> 1;
            u8 *p;
            V4_3A1438 a, b;
            o->f41 = h + 1;
            o->f40 = h;
            func_003C29B0_003A6890(o);
            o->f44 = (f32)(D_00225700_003A6890.f38 & 1) * 0.5f;
            if (v != 0 && (D_00225700_003A6890.f38 & 1)) o->f44 = 1.0f;
            p = o->f68;
            func_0038CE20_003A6890(&a, p + o->f40 * 16, 1.0f - o->f44);
            func_0038CE20_003A6890(&b, p + o->f41 * 16, o->f44);
            {
                vu0_q x, y;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(o->f10) : "j"(x));
            }
            {
                s32 aa = o->fAA;
                if (aa == 0xD54) {
                    o->f63 = 8;
                    func_003A58C0(o, 0);
                    if (D_001DA008 == 0 || D_001DA008->fAA == aa) func_00389F18_003A6890(func_003A7AF8, o);
                }
            }
            o->f61 = 0xFF;
            func_003C7C38_003A6890(o);
            if (o->fAA == 0) {
                D_001A4BE0_003A6890.f25C0 = o;
                func_00381D68(o, 1);
            }
            if (o->fAA == 10) func_00381C90(o);
        }
        if (D_001D4B60_003A6890 == 4 || func_00381CB0_003A6890() > 0) {
            E_3A1438 *e;
            for (e = D_001DA49C_003A6890; e < D_001DA4A4_003A6890; e++) {
                if (e->f20 < 0xFE && e->fAA == 0x50A) e->f34 |= 1;
            }
        }
    }
    func_003A4288();
    func_003D0B20();
    func_003E55B8();
    return r;
}
/* localdecomp:end func_003A6890 */

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
/* localdecomp:start func_003A6F28 */
extern s32 func_003A6808(s32);
extern void func_003A7FE8(void);
extern void func_003A4288(void);
extern s32 func_003A2598(s32, s32, s32);
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
    func_0038CB78(D_001D9960, 0, 0x40);
    func_0038CB78(D_001D98A0, 0, 0x40);
    func_0038CB78(D_001E2240, 0, 0x40);
    func_0038CB78(D_001E2240 + 0x40, 0, 0x40);
    func_0038CB78(D_001D98E0, 0, 0x40);
    func_0038CB78(D_001D9920, 0, 0x40);
    b = D_002275EC[0];
    D_00225700_003A6F28.f30 = slot;
    D_00225700_003A6F28.f68 = b - 0x82000;
    D_00225700_003A6F28.f6C = b - 0x102000;
    D_001D5BC8 = 1.0f;
    D_001D5BCC = 0;
    D_00225700_003A6F28.f34 = 0;
    D_00225700_003A6F28.f3C = 0;
    D_00225700_003A6F28.f58 = b - 0x90000;
    { s32 j; for (j = 0; j < 1; j++) { D_001D9BD0_003A6F28[j] = 1.0f; D_001D9BD8_003A6F28[j] = 0; } }
    D_001D5B94 = 2;
    D_001D9BDC_003A6F28 = 1;
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
/* localdecomp:start func_003A72A0 */
extern s32 func_13B620(void);
extern S_3A1E48e *D_001D9DD4_003A72A0[2];
void func_003A72A0(void) {
    s32 i;
    if ((u16)(D_001CCFD0_003A72A0.f76 - 6) >= 2) D_001CCFD0_003A72A0.f76 = 5;
    if ((u16)(D_001CCFD0_003A72A0.f9E - 6) >= 2) D_001CCFD0_003A72A0.f9E = 5;
    func_0038A238(0xC);
    while (D_001CCFD0_003A72A0.f6C != 0 || D_001CCFD0_003A72A0.f24 != -1 || D_001CCFD0_003A72A0.f94 != 0) {
        func_003A4288();
        func_12C908(0);
    }
    while (func_13B620() != 0) {
    }
    {
        s32 j;
        D_001D9BDC = 0;
        D_001D9BE0 = 0;
        for (j = 0; j >= 0; j--) D_001D9BD0[j] = 0;
    }
    {
        u8 *q = D_00225900_003A72A0;
        *(f32 *)(q + 0xB0) = 0.63f;
    }
    func_003873C0();
    for (i = 0; i < D_00225700_003A72A0.n44; i++) {
        S_3A1E48d *p = D_00225700_003A72A0.e[i];
        if (p) {
            p->f24->bC--;
            p->f24->f48[p->f24->bC] = 0;
            func_003C2880((s32)p);
            D_00225700_003A72A0.e[i] = 0;
        }
    }
    {
        u8 *q = D_001A4BE0_003A72A0;
        if (*(s32 *)(q + 0x12A0)) {
            func_003C2880(*(s32 *)(q + 0x12A0));
            *(s32 *)(q + 0x12A0) = 0;
        }
    }
    if (D_001D9DD4_003A72A0[1]) D_001D9DD4_003A72A0[1]->h34 &= ~1;
}
/* localdecomp:end func_003A72A0 */

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

/* localdecomp:start func_003A78B8 */
typedef struct { u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C; u8 p240[0x10]; s32 f250; s32 f254; s32 f258; } S_225900_003A78B8;
extern u8 D_001CCFD0_003A78B8[];
typedef struct { u8 pad[0x90]; s32 f90[6]; } Q_003A78B8;
extern Q_003A78B8 D_001A30B0_003A78B8;
extern S_225900_003A78B8 D_00225900_003A78B8;
extern s32 D_001D9D04_003A78B8;
extern s32 D_001D545C_003A78B8;
extern s32 D_001D545C_003A78B8_l;
__asm__(".extern D_001D545C_003A78B8_l, 16");
extern s32 D_001D4B48_003A78B8;
__asm__(".extern D_001D4B48_003A78B8, 16");
extern s32 D_001D9D2C_003A78B8;
extern u8 D_001D9C44_003A78B8, D_001D9C45_003A78B8, D_001D9C46_003A78B8;
extern f32 D_001D9C48_003A78B8, D_001D9C4C_003A78B8, D_001D9C50_003A78B8, D_001D9C54_003A78B8;
extern u8 D_002D2100_003A78B8[];
__asm__(".extern D_001D9D04_003A78B8, 16");
__asm__(".extern D_001D9D2C_003A78B8, 16");
__asm__(".extern D_001D9C44_003A78B8, 16");
__asm__(".extern D_001D9C45_003A78B8, 16");
__asm__(".extern D_001D9C46_003A78B8, 16");
__asm__(".extern D_001D9C48_003A78B8, 16");
__asm__(".extern D_001D9C4C_003A78B8, 16");
__asm__(".extern D_001D9C50_003A78B8, 16");
__asm__(".extern D_001D9C54_003A78B8, 16");

extern s32 func_003BD4B8_003A78B8(void);
extern void func_0038A238_003A78B8(s32);
extern void func_11F0A0_003A78B8(s32);
extern void func_13CF80_003A78B8(s32, s32, s32, s32, s32);
extern void func_13CA28_003A78B8(void);
extern s32 func_13B620_003A78B8(void);
extern void func_003A5430_003A78B8(void);
extern void func_003A1C28_003A78B8(void);
extern void func_13BF00_003A78B8(s32);
extern void func_13BED0_003A78B8(void);
extern void func_00392260_003A78B8(s32, long, long);
extern void func_13D310_003A78B8(s32, u8 *);
extern s32 func_12C908_003A78B8(s32);
extern void func_0039C410_003A78B8(void);
extern void func_0039ADE0_003A78B8(void);
extern s32 func_0039A1E0_003A78B8(void);
extern void func_13CF40_003A78B8(s32);
extern long func_13CDF0_003A78B8(s32);
extern void func_003A9AD0_003A78B8(void);
void func_003A78B8(void) {
    s32 i;
    S_225900_003A78B8 *q;
    if (func_003BD4B8_003A78B8() != 0) return;
    func_0038A238_003A78B8(5);
    D_001D545C_003A78B8 = D_001D9D04_003A78B8;
    D_001D4B48_003A78B8 = 0;
    func_11F0A0_003A78B8(0);
    func_13CF80_003A78B8(2, 0, 0, 0, 0);
    func_13CA28_003A78B8();
    func_13B620_003A78B8();
    func_003A5430_003A78B8();
    func_003A1C28_003A78B8();
    D_001CCFD0_003A78B8[7] = 1;
    for (i = 0; i < 6; i++) {
        if (D_001A30B0_003A78B8.f90[i] != 0) {
            func_13BF00_003A78B8(D_001A30B0_003A78B8.f90[i]);
            func_13BED0_003A78B8();
            D_001D9D2C_003A78B8 = 0;
            D_001A30B0_003A78B8.f90[i] = 0;
        }
    }
    q = &D_00225900_003A78B8;
    q->f258 = 0x10;
    q->f250 = 0;
    q->f254 = 0;
    q->f228 = 0;
    q->f22C = 524288.0f;
    q->f238 = 255.0f;
    q->f23C = 128.0f;
    D_001D9C44_003A78B8 = q->f250;
    D_001D9C45_003A78B8 = q->f254;
    D_001D9C46_003A78B8 = q->f258;
    D_001D9C48_003A78B8 = q->f228;
    D_001D9C4C_003A78B8 = q->f22C;
    D_001D9C50_003A78B8 = q->f238;
    D_001D9C54_003A78B8 = q->f23C;
    func_00392260_003A78B8(0, 0, 0);
    func_13D310_003A78B8(D_001D545C_003A78B8_l, D_002D2100_003A78B8);
    D_001CCFD0_003A78B8[7] = 1;
    do {
        func_11F0A0_003A78B8(0);
        func_12C908_003A78B8(0);
        func_0039C410_003A78B8();
        func_0039ADE0_003A78B8();
    } while (func_0039A1E0_003A78B8() == 0);
    func_11F0A0_003A78B8(0);
    func_12C908_003A78B8(0);
    func_0039C410_003A78B8();
    func_0039ADE0_003A78B8();
    while (func_13B620_003A78B8() != 0);
    func_13BED0_003A78B8();
    func_13CF40_003A78B8(0);
    func_13CDF0_003A78B8(0);
    func_13CDF0_003A78B8(0);
    D_001CCFD0_003A78B8[7] = 0;
    func_003A9AD0_003A78B8();
}
/* localdecomp:end func_003A78B8 */

/* localdecomp:start func_003A7AF8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003A7AF8;
typedef union { u128_t q; V_003A7AF8 v; } Q_003A7AF8;
typedef struct { f32 u, v; } UV_003A7AF8;
typedef struct { Q_003A7AF8 v[4]; s32 col[4]; f32 uv[4][2]; long f70, f78, f80, f88; } P_003A7AF8;
typedef struct { s16 i; s16 pad; } I_003A7AF8;
typedef struct { u8 pad[0x140]; f32 x, y; } C_003A7AF8;
typedef struct { u8 pad[0x10]; f32 x, y; } O_003A7AF8;
__asm__(".extern D_001D5B94_003A7AF8, 16");
extern s32 D_001D5B94_003A7AF8;
__asm__(".extern D_001D6EE0, 4");
extern s32 D_001D6EE0;
__asm__(".extern D_001D6EE4, 4");
extern s32 D_001D6EE4;
__asm__(".extern D_001D6EE8, 4");
extern s32 D_001D6EE8;
extern s16 D_0016C5A0[];
extern C_003A7AF8 D_002222C0_003A7AF8;
extern V_003A7AF8 D_00222400_003A7AF8;
extern Q_003A7AF8 D_0022D9C0[];
extern UV_003A7AF8 D_0022DC70[];
extern UV_003A7AF8 D_0022DDC8[];
extern V_003A7AF8 D_003343D0[];
extern V_003A7AF8 D_003348E0[];
extern I_003A7AF8 D_00334680[][4];
extern long func_00389598(s32);
extern void func_003C2EC0(u8 *, s32, u8 *);
extern s32 func_0038CAD0(void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_003D2DA0(void *, s32, s32);
void func_003A7AF8(void *arg) {
    P_003A7AF8 q;
    V_003A7AF8 mtx[4];
    V_003A7AF8 nrm_w;
    V_003A7AF8 ref;
    V_003A7AF8 eye;
    V_003A7AF8 *verts;
    V_003A7AF8 *norms;
    I_003A7AF8 (*quads)[4];
    s32 nverts;
    s32 nquads;
    s32 col;
    s32 show;
    s32 i;
    s32 j;
    f32 blend;
    f32 m;
    f32 u;
    long tex;

    nverts = 43;
    nquads = 38;
    verts = D_003343D0;
    norms = D_003348E0;
    quads = D_00334680;
    tex = func_00389598(0x15);
    col = 0x3CA5A281;
    if (D_001D5B94_003A7AF8 == 2) col = 0x28A5A281;
    q.f80 = 0xFF9000000260UL;
    q.f78 = tex;
    q.f88 = 0x8000000044UL;
    q.f70 = 0;
    q.col[3] = col;
    q.col[2] = col;
    q.col[1] = col;
    q.col[0] = col;
    func_003C2EC0(arg, 0, (u8 *)mtx);
    show = 0;
    if (D_001D5B94_003A7AF8 == 0 || D_001D5B94_003A7AF8 == 2) {
        if (fabs_asm(D_002222C0_003A7AF8.x - ((O_003A7AF8 *)arg)->x) < 16.0f
            && fabs_asm(D_002222C0_003A7AF8.y - ((O_003A7AF8 *)arg)->y) < 16.0f) show = 1;
    } else {
        show = 1;
    }
    if (D_001D5B94 == 6 && D_0016C5A0[0] == 2) show = 0;
    if (show || D_001D6EE0 == 1) {
        D_001D6EE4 = 1;
        func_0038CAD0(&D_001D6EE8);
        blend = (f32)D_001D6EE8 / 50.0f;
        for (i = 0; i < nverts; i++) {
            func_0038D028(&D_0022D9C0[i], &verts[i], mtx);
            vec_sub_ab(&eye, &D_0022D9C0[i], &D_00222400_003A7AF8);
            func_0038CF68(&eye, &eye, 1.0f);
            func_0038D028(&nrm_w, &norms[i], mtx);
            func_0038CF68(&nrm_w, &nrm_w, 0.1f);
            func_0038CE20_003A6890(&ref, &nrm_w, func_0038CE68(&nrm_w, &eye) * 2.0f);
            vec_sub_ab(&ref, &eye, &ref);
            func_0038CF68(&ref, &ref, 1.0f);
            ref.z += 1.0f;
            m = sqrt_asm(ref.z + ref.z) * 2.0f;
            if (D_001D6EE0 == 1 || D_001D6EE8 == 0) {
                D_0022DC70[i].u = ref.x / m + 0.5f;
                D_0022DC70[i].v = ref.y / m + 0.5f;
            } else {
                u = ref.x / m + 0.5f;
                D_0022DC70[i].u = u + (D_0022DDC8[i].u - u) * blend;
                u = ref.y / m + 0.5f;
                D_0022DC70[i].v = u + (D_0022DDC8[i].v - u) * blend;
            }
        }
        if (D_001D6EE0 == 1) D_001D6EE0 = 2;
    } else {
        if (D_001D6EE4 == 1) {
            D_001D6EE4 = 0;
            for (i = 0; i < nverts; i++) {
                D_0022DDC8[i].u = D_0022DC70[i].u;
                D_0022DDC8[i].v = D_0022DC70[i].v;
                func_0038D028(&D_0022D9C0[i], &verts[i], mtx);
            }
        } else {
            for (i = 0; i < nverts; i++) {
                func_0038D028(&D_0022D9C0[i], &verts[i], mtx);
            }
        }
        D_001D6EE8 = 50;
    }
    for (i = 0; i < nquads; i++) {
        for (j = 0; j < 4; j++) {
            s32 k = quads[i][j].i;
            q.v[j].q = D_0022D9C0[k].q;
            q.uv[j][0] = D_0022DC70[k].u;
            q.uv[j][1] = D_0022DC70[k].v;
        }
        func_003D2DA0(&q, 0, 0);
    }
}
/* localdecomp:end func_003A7AF8 */

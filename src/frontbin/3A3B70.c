#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A3B70(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003A3BB8(s32, s32);
extern void func_003A4260(void);
/* --- end of declarations from other files --- */

/* declarations of 39DB38.c's earlier functions (tools/port_from_us.py) */
typedef struct {
    u8 pad0[0x100];
    f32 cur[16];
    f32 prev[16];
    u8 pad180[0xE];
    s16 head;
    s32 cnt;
    u8 pad194[0xC];
    s32 x1A0;
    s32 x1A4;
    s32 x1A8;
    s32 x1AC;
    s32 x1B0;
    s32 x1B4;
    s32 x1B8;
    s32 x1BC;
    s32 x1C0;
    s32 x1C4;
    s32 x1C8;
    s32 x1CC;
    s32 x1D0;
    s32 x1D4;
    s32 x1D8;
    u8 pad1DC[4];
    s32 hist[30];
    f32 ang[30];
    f32 mag[30];
    s32 x348;
    s32 idx;
    s32 count;
    s32 btn[7];
    s32 btn2[7];
    f32 an[7][16];
    u8 pad54C;
    u8 x54D;
    u8 x54E;
    u8 x54F;
    u8 pad550[0x18];
    s32 delay;
} Pad_39DB38;
extern s32 D_001D5B94;
extern u8 D_001D5477[];
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
#define SWAP_LR(x) \
    if ((x) & 0x8000) { (x) = ((x) & ~0x8000) | 0x2000; } \
    else if ((x) & 0x2000) { (x) = ((x) & ~0x2000) | 0x8000; }
typedef struct P_39E4B0 {
    u8 pad[0x188]; u8 f188; u8 f189; u8 pad18A[0x198 - 0x18A];
    s32 f198; s32 f19C; s32 f1A0; u8 pad1A4[8]; s32 f1AC; s32 f1B0; u8 pad1B4[8]; s32 f1BC;
    u8 pad1C0[0x1DC - 0x1C0]; s32 f1DC; u8 pad1E0[0x348 - 0x1E0]; s32 f348;
    u8 pad34C[0x54C - 0x34C]; u8 f54C; u8 pad54D[3]; u8 f550; u8 f551[6]; u8 f557; u8 f558; u8 pad559[3];
    s32 f55C; s32 f560; s32 f564; u8 pad568[4];
    void (*f56C)(struct P_39E4B0 *, u8 *, s32, s32); s32 f570; u8 f574; u8 f575;
} P_39E4B0;
extern P_39E4B0 *D_001D52FC_003A3740;
extern u8 D_001D4CF4;
extern u8 D_001D6DF0[8];
extern void func_003A2DC8(Pad_39DB38 *, u8 *, s32);
extern s32 func_12F470(s32, s32);
extern s32 func_12F728(s32, s32, s32, s32);
extern s32 func_12F860(s32, s32, s32, s32);
extern s32 func_12F5A8(s32, s32);
extern s32 func_12F608(s32, s32, s32, s32);
extern s32 func_12F9E0(s32, s32, u8 *);
extern s32 func_12FC18(s32, s32);
extern s32 func_12FC78(s32, s32);
extern s32 func_12EBB8(s32);
extern s32 func_12F3F8(s32, s32, u8 *);
extern s32 func_12F918(s32, s32, u8 *);

/* localdecomp:start func_003A3B70 */
typedef struct { u8 pad[0x5C0]; } S_39E8E0;
extern S_39E8E0 D_001CD0C0[];
void func_003A3740(S_39E8E0 *);
void func_003A3B70(void) {
    s32 i;
    for (i = 0; i < 8; i++) func_003A3740(&D_001CD0C0[i]);
}
/* localdecomp:end func_003A3B70 */

/* localdecomp:start func_003A3BB8 */
typedef struct { u8 pad[0xA4]; u8 arr[1]; } S_143950;
extern S_143950 D_143950;
extern u8 D_001A71C4[];
s32 func_003A3BB8(s32 a, s32 i) {
    if (D_143950.arr[i] != 0 && D_001A71C4[0] == 0) {
        switch (a) {
        case 0x40: return 0x44;
        case 4: return 1;
        case 8: return 2;
        }
    }
    return a;
}
/* localdecomp:end func_003A3BB8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A3C30);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39E9A0;
extern V4_39E9A0 D_00222400_0039E9A0[];
extern V4_39E9A0 D_00227660[];
extern s32 D_001A30F4[];
extern void func_00382580(s32, f32, f32);
extern s32 func_003D3CB0();
extern void func_0038CE20_0039E9A0(void *, void *, f32);

LINKER_REMNANT("asm/remnants", func_003A3CE8);

/* localdecomp:start func_003A3CF0 */
typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad2[9]; u8 f19; } S_39EA60;
s32 func_003A3CF0(f32 *op, void *c, f32 x, f32 lo, f32 hi) {
    S_39EA60 *o = (S_39EA60 *)op;
    s32 a = o->f8;
    f32 t;
    if ((o->f19 & 1) || c != 0) {
        if (x <= lo) return o->fC;
        if (hi <= x) return a;
        t = hi - x;
        return a + (s32)((t * t * (f32)(o->fC - a)) / ((hi - lo) * (hi - lo)));
    }
    if (x <= lo) return o->fC;
    if (!(hi <= x)) return a + (s32)(((hi - x) * (f32)(o->fC - a)) / (hi - lo));
    return a;
}
/* localdecomp:end func_003A3CF0 */

/* localdecomp:start func_003A3DC8 */
extern s32 D_00222400[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_003A3CF0(f32 *, void *, f32, f32, f32);
typedef struct { s32 pad; f32 *q; } S_39EB38;
void func_003A3DC8(S_39EB38 *p, void *a, void *b, void *c) {
    f32 f;
    if (b == 0) b = D_00222400;
    f = func_0038CF00(a, b);
    func_003A3CF0(p->q, c, f, p->q[0], p->q[1]);
}
/* localdecomp:end func_003A3DC8 */

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39EB98;
typedef struct { u8 pad[0x50]; f32 f50; } O_39EB98;
extern u8 D_00222800[];
extern void func_0038D5B0(void *, void *);
extern void func_0038D028_003A3E28(V4_39EB98 *, V4_39EB98 *, V4_39EB98 *);
extern f32 func_0038DAB8_003A3E28(f32, f32);
extern f32 func_0038DB00(f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003A3E28);

/* localdecomp:start func_003A3FE0 */
typedef struct { u8 p[0xC]; s32 fC; s32 f10; } T;
extern T D_00143950_b;
extern s32 D_1A30D0[];
extern void func_0038CD28(void *, void *, s32);
void func_003A3FE0(void) {
    s32 *s = D_1A30D0;
    s32 *d = s - 8;
    s32 *a, *b, *q;
    s32 i, x, y, t;
    func_0038CD28(s, d, 0x20);
    x = D_00143950_b.f10;
    d[1] = D_00143950_b.fC;
    d[2] = x;
    d[5] = x * 25 / 32;
    s[-8] = x * 7 / 10;
    y = x * 6 / 10;
    d[3] = y;
    d[4] = y;
    a = s;
    b = d;
    q = b;
    for (i = 0; i < 6; i++) {
        t = (*a != *b);
        q[0x6C8] |= t << i;
        a++;
        b++;
    }
}
/* localdecomp:end func_003A3FE0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A40D0);

/* localdecomp:start func_003A4260 */
extern s32 D_001685EC[];
extern void func_0013CFC0(s32, s32);
void func_003A4260(void) {
    func_0013CFC0(2, D_001685EC[0]);
}
/* localdecomp:end func_003A4260 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A4288);

LINKER_REMNANT("asm/remnants", func_003A4F18);

/* localdecomp:start func_003A4F28 */
extern u8 D_1A30B0[];
void func_003A4F28(u32 i) {
    if (i < 52) {
        u8 *e = D_1A30B0 + i * 128;
        u8 s = e[0xD0];
        if (s == 7) {
            *(s32 *)(e + 0xDC) = 0;
            *(s32 *)(e + 0x100) = 0;
            e[0xD0] = 0;
            return;
        }
        if (s != 0 && s != 6) e[0xD0] = 4;
    }
}
/* localdecomp:end func_003A4F28 */

/* localdecomp:start func_003A4F80 */
typedef struct { u8 pad[0x1200]; s32 x1200; u8 pad2[0x25C0 - 0x1204]; s32 x25C0; } S_39FB60;
typedef struct { u8 pad[0x50]; u8 b50; u8 pad2[0x2F]; } S2_39FB60;
extern S_39FB60 D_001A4BE0[];
extern S2_39FB60 D_001A30B0[];
s32 func_003A4F80(s32 id) {
    s32 n = 0x34;
    s32 i;
    if (id == 0 || (D_001A4BE0[0].x25C0 != id && D_001A4BE0[0].x1200 != id)) n = 0x2A;
    for (i = 0; i < n; i++) {
        if (D_001A30B0[i + 1].b50 == 0) break;
    }
    if (i == n) return -1;
    return i;
}
/* localdecomp:end func_003A4F80 */

typedef int u128_39FBD8 __attribute__((mode(TI)));
typedef struct 
{
  u8 p0[0xC4];
  u8 *c4;
  u8 pC8[0x18];
  u128_39FBD8 qE0;
  u128_39FBD8 qF0;
} E_39FBD8;
typedef struct { u8 b[0x80]; } R_39FBD8;
extern s32 D_001D5B98_003A4FF8;
extern u8 D_001D6E14;
extern u8 D_00222480[];
extern s32 func_00382468(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003A4FF8);

/* localdecomp:start func_003A52A0 */
typedef struct { u8 pad[0xD]; u8 bD; u8 pad2[0x1A]; s32 f28; } O_39FE80;
typedef struct { u8 pad[0x24]; O_39FE80 *o; } P_39FE80;
extern u8 D_1A30B0[];
extern s32 func_003A4FF8();
s32 func_003A52A0(s32 a, s32 b, P_39FE80 *p) {
    O_39FE80 *o;
    s32 r;
    u8 *e;
    if (p == 0) return -1;
    o = p->o;
    if (o == 0) return -1;
    if (o->f28 == 0) return -1;
    if (a >= o->bD) return -1;
    r = func_003A4FF8(o->f28 + a * 32, b, p, 0, 0x400);
    if (r >= 0) {
        e = D_1A30B0 + r * 128;
        *(s32 *)(e + 0xDC) = (s32)p;
        *(s16 *)(e + 0xCA) = a;
        *(s32 *)(e + 0x108) = -1;
    }
    return r;
}
/* localdecomp:end func_003A52A0 */

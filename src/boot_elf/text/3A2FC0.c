#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A3F70(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003A3FB8(s32, s32);
extern s32 func_003A5748(s32, s32, s32);
extern void func_003A2FC0(void);
extern void func_003A44D0(void);
extern void func_003A4660(void);
/* --- end of declarations from other files --- */

typedef struct {
    u8 p0[0x198]; s32 f198; u8 p19C[0x54C - 0x19C]; u8 b54C; u8 p54D[3]; u8 b550; u8 p551[6]; u8 b557;
    u8 p558[0x14]; s32 f56C; s32 f570; u8 p574[0x5C0 - 0x574];
} Pad_3A2E80;
extern Pad_3A2E80 D_001CD0C0_003A2FC0[];
extern void *D_001D52FC;
extern void *D_001D5300;
extern void *D_001D5304;
extern void func_0012EA38(void);
extern s32 func_0012EC90(s32);
extern s32 func_0012EB40(s32);
extern s32 func_0012EBB8(s32);
extern s32 func_0012F0B8(s32, s32, void *);
extern void func_003A30D8_003A2FC0(Pad_3A2E80 *);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A2FC0);

/* localdecomp:start func_003A30D8 */
typedef struct {
    u8 pad0[0x100];
    f32 cur[16];
    f32 prev[16];
    u8 pad180[0x20];
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
    u8 pad1DC[0x34C - 0x1DC];
    s32 idx;
    s32 count;
    s32 btn[7];
    s32 btn2[7];
    f32 an[7][16];
} Pad_3A2F98;

void func_003A30D8(Pad_3A2F98 *o) {
    s32 i, j, k, n;

    for (i = 0; i < o->count; i++) {
        k = (o->idx - i + 7) % 7;
        o->btn[k] = 0;
        o->btn2[k] = 0;
        for (j = 15; j >= 0; j--) o->an[k][j] = 0.0f;
    }
    o->x1B0 = 0;
    o->x1A0 = 0;
    o->x1A4 = 0;
    o->x1A8 = 0;
    o->x1D0 = 1;
    o->x1D4 = 1;
    o->x1B4 = 0;
    o->x1B8 = 0;
    o->x1C0 = 0;
    o->x1C4 = 0;
    o->x1C8 = 0;
    o->x1D8 = 0;
    for (n = 0; n < 16; n++) {
        o->cur[n] = 0.0f;
        o->prev[n] = 0.0f;
    }
}
/* localdecomp:end func_003A30D8 */

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
} Pad_3A3088;
extern s32 D_001D5B94;
extern u8 D_001D5477[];
extern f32 func_0038D2B8(f32 *);
extern f32 func_0038D540(f32, f32);
extern f32 func_0038DF80(f32, f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A31C8);

LINKER_REMNANT("asm/boot_elf/remnants", func_003A3B38);

typedef struct P_3A3A00 {
    u8 pad[0x188]; u8 f188; u8 f189; u8 pad18A[0x198 - 0x18A];
    s32 f198; s32 f19C; s32 f1A0; u8 pad1A4[8]; s32 f1AC; s32 f1B0; u8 pad1B4[8]; s32 f1BC;
    u8 pad1C0[0x1DC - 0x1C0]; s32 f1DC; u8 pad1E0[0x348 - 0x1E0]; s32 f348;
    u8 pad34C[0x54C - 0x34C]; u8 f54C; u8 pad54D[3]; u8 f550; u8 f551[6]; u8 f557; u8 f558; u8 pad559[3];
    s32 f55C; s32 f560; s32 f564; u8 pad568[4];
    void (*f56C)(struct P_3A3A00 *, u8 *, s32, s32); s32 f570; u8 f574; u8 f575;
} P_3A3A00;
extern P_3A3A00 *D_001D52FC_003A3B40;
extern u8 D_001D4CF4;
extern u8 D_001D6DF0[8];
extern void func_003A31C8(Pad_3A3088 *, u8 *, s32);
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
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A3B40);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C500);

/* localdecomp:start func_003A3F70 */
typedef struct { u8 pad[0x5C0]; } S_39E8E0;
extern S_39E8E0 D_001CD0C0[];
void func_003A3B40(S_39E8E0 *);
void func_003A3F70(void) {
    s32 i;
    for (i = 0; i < 8; i++) func_003A3B40(&D_001CD0C0[i]);
}
/* localdecomp:end func_003A3F70 */

/* localdecomp:start func_003A3FB8 */
typedef struct { u8 pad[0xA4]; u8 arr[1]; } S_143950;
extern S_143950 D_143950;
extern u8 D_001A71C4[];
s32 func_003A3FB8(s32 a, s32 i) {
    if (D_143950.arr[i] != 0 && D_001A71C4[0] == 0) {
        switch (a) {
        case 0x40: return 0x44;
        case 4: return 1;
        case 8: return 2;
        }
    }
    return a;
}
/* localdecomp:end func_003A3FB8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A4030);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39E9A0;
extern V4_39E9A0 D_00222400_003A3EF0[];
extern V4_39E9A0 D_00227660[];
extern s32 D_001A30F4[];
extern void func_00382960(s32, f32, f32);
extern s32 func_003D4068();
extern void func_0038D200_003A3EF0(void *, void *, f32);

LINKER_REMNANT("asm/boot_elf/remnants", func_003A40E8);

/* localdecomp:start func_003A40F0 */
typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad2[9]; u8 f19; } S_39EA60;
s32 func_003A40F0(f32 *op, void *c, f32 x, f32 lo, f32 hi) {
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
/* localdecomp:end func_003A40F0 */

/* localdecomp:start func_003A41C8 */
extern s32 D_00222400[];
extern f32 func_0038D2E0(void *, void *);
extern s32 func_003A40F0(f32 *, void *, f32, f32, f32);
typedef struct { s32 pad; f32 *q; } S_39EB38;
void func_003A41C8(S_39EB38 *p, void *a, void *b, void *c) {
    f32 f;
    if (b == 0) b = D_00222400;
    f = func_0038D2E0(a, b);
    func_003A40F0(p->q, c, f, p->q[0], p->q[1]);
}
/* localdecomp:end func_003A41C8 */

extern f32 func_0038D2B8(f32 *);
extern f32 func_0038D540(f32, f32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A40E8;
typedef struct { u8 pad[0x50]; f32 f50; } O_3A40E8;
extern u8 D_222800[];
extern void func_0038D990(void *, void *);
extern void func_0038D408_003A4228(V4_3A40E8 *, V4_3A40E8 *, V4_3A40E8 *);
extern f32 func_0038DE98_003A4228(f32, f32);
extern f32 func_0038DEE0(f32, f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A4228);

/* localdecomp:start func_003A43E0 */
typedef struct { u8 p[0xC]; s32 fC; s32 f10; } T_3A42A0;
extern T_3A42A0 D_00143950_b;
extern s32 D_1A30D0[];
extern void func_0038D108(void *, void *, s32);
void func_003A43E0(void) {
    s32 *s = D_1A30D0;
    s32 *d = s - 8;
    s32 *a, *b, *q;
    s32 i, x, y, t;
    func_0038D108(s, d, 0x20);
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
/* localdecomp:end func_003A43E0 */

/* localdecomp:start func_003A44D0 */
typedef struct { s32 a, b, c, d, e; } V_3A4390;
typedef struct { u8 p0[8]; s32 f8; } S_143950_3A4390;
extern S_143950_3A4390 D_00143950_003A44D0;
extern u8 D_1A3100[];
extern u8 D_1A30B0[];
extern void func_0013B3F8(s32);
extern void func_0013BFE0(s32);
extern s32 func_0013C068(s32);
extern s32 func_0013C028(s32, s32, s32);
extern s32 func_0013BF30(s32, s32);
extern void func_0013BF68(s32, V_3A4390 *);
extern void func_003A43E0(void);
extern void func_003A5A20(void);
typedef int Q_3A4390 __attribute__((mode(TI)));
void func_003A44D0(void) {
    s32 i;
    u8 *p, *e;
    s32 *q;
    V_3A4390 v;
    for (i = 0; i < 4; i++) {
        __asm__("sq $0,%0" : "=m"(*(Q_3A4390 *)(D_1A3100 + i * 0x10)));
    }
    p = D_1A30B0;
    *(s32 *)(p + 0x48) = 0;
    *(s32 *)(p + 0x4C) = 0;
    e = p;
    for (i = 0x33; i >= 0; i--) {
        *(s32 *)(e + 0xC0) = 0;
        *(u8 *)(e + 0xD0) = 0;
        e += 0x80;
    }
    func_0013B3F8(2);
    func_0013BFE0(D_00143950_003A44D0.f8 == 0);
    func_0013C068(1);
    func_0013C028(1, 0x18, 0x2F);
    func_0013C028(2, 0x18, 0x2F);
    func_0013C028(4, 0x18, 0x2F);
    func_0013C028(5, 0x18, 0x2F);
    func_0013C028(6, 0x18, 0x2F);
    func_003A43E0();
    q = (s32 *)D_1A30B0;
    func_0013BF30(0, q[0]);
    func_0013BF30(1, q[1]);
    func_0013BF30(2, q[2]);
    func_0013BF30(3, q[3]);
    func_0013BF30(4, q[4]);
    func_0013BF30(5, q[5]);
    func_0013BF30(6, q[2]);
    v.a = 6;
    v.b = 0x3B;
    v.c = 0x6666;
    v.d = 0x8000;
    v.e = 0x8000;
    func_0013BF68(0, &v);
    func_003A5A20();
}
/* localdecomp:end func_003A44D0 */

/* localdecomp:start func_003A4660 */
extern s32 D_001685EC[];
extern void func_0013CFC0(s32, s32);
void func_003A4660(void) {
    func_0013CFC0(2, D_001685EC[0]);
}
/* localdecomp:end func_003A4660 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A4688);

LINKER_REMNANT("asm/boot_elf/remnants", func_003A5318);

/* localdecomp:start func_003A5328 */
extern u8 D_1A30B0[];
void func_003A5328(u32 i) {
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
/* localdecomp:end func_003A5328 */

/* localdecomp:start func_003A5380 */
typedef struct { u8 pad[0x1200]; s32 x1200; u8 pad2[0x25C0 - 0x1204]; s32 x25C0; } S_39FB60;
typedef struct { u8 pad[0x50]; u8 b50; u8 pad2[0x2F]; } S2_39FB60;
extern S_39FB60 D_001A4BE0[];
extern S2_39FB60 D_001A30B0[];
s32 func_003A5380(s32 id) {
    s32 n = 0x34;
    s32 i;
    if (id == 0 || (D_001A4BE0[0].x25C0 != id && D_001A4BE0[0].x1200 != id)) n = 0x2A;
    for (i = 0; i < n; i++) {
        if (D_001A30B0[i + 1].b50 == 0) break;
    }
    if (i == n) return -1;
    return i;
}
/* localdecomp:end func_003A5380 */

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
extern s32 D_001D5B98_003A53F8;
extern u8 D_001D6E14;
extern u8 D_00222480[];
extern s32 func_00382848(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A53F8);

/* localdecomp:start func_003A56A0 */
typedef struct { u8 pad[0xD]; u8 bD; u8 pad2[0x1A]; s32 f28; } O_39FE80;
typedef struct { u8 pad[0x24]; O_39FE80 *o; } P_39FE80;
extern u8 D_1A30B0[];
extern s32 func_003A53F8();
s32 func_003A56A0(s32 a, s32 b, P_39FE80 *p) {
    O_39FE80 *o;
    s32 r;
    u8 *e;
    if (p == 0) return -1;
    o = p->o;
    if (o == 0) return -1;
    if (o->f28 == 0) return -1;
    if (a >= o->bD) return -1;
    r = func_003A53F8(o->f28 + a * 32, b, p, 0, 0x400);
    if (r >= 0) {
        e = D_1A30B0 + r * 128;
        *(s32 *)(e + 0xDC) = (s32)p;
        *(s16 *)(e + 0xCA) = a;
        *(s32 *)(e + 0x108) = -1;
    }
    return r;
}
/* localdecomp:end func_003A56A0 */

/* localdecomp:start func_003A5748 */
/* PAL candidate for func_003A5748 (boot_elf/text/3A2FC0.c).

   Retail reads D_001D9D2C and D_001D5B9C with lui/%lo, not through $gp
   (lui $v1,%hi(D_1D9D2C); lw $v1,%lo(D_1D9D2C)($v1)).  The .extern size hints
   say the two globals are bigger than 8 bytes, so they are not small data and
   the assembler reaches them absolutely (docs/us/compiler_matrix_findings.md,
   "Declaration rule for -G8"; the same idiom the other matched files use). */

__asm__(".extern D_001D9D2C, 16");
__asm__(".extern D_001D5B9C, 16");
extern s32 D_001D9D2C;
extern s32 D_001D5B9C;
extern u8 D_1A30B0[];
extern s32 func_003A53F8();
s32 func_003A5748(s32 a, s32 b, s32 c) {
    s32 r;
    u8 *e;
    if (D_001D9D2C == 0) return -1;
    if (a >= D_001D5B9C) return -1;
    r = func_003A53F8(D_001D9D2C + a * 32, b, c, 0, 0x400);
    if (r >= 0) {
        e = D_1A30B0 + r * 128;
        *(s32 *)(e + 0xDC) = c;
        *(s16 *)(e + 0xCA) = a;
    }
    return r;
}
/* localdecomp:end func_003A5748 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A57D8);

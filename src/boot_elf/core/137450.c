#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 133BB8.c's earlier functions (tools/port_from_us.py) */
extern s32 func_00124920(void);
extern void func_00124970_00133BB8(void);
typedef struct {
    u8 pad0[0x12C];
    int f12C;
    u8 pad130[0x13C - 0x130];
    int f13C;
    u8 pad140[0x1C0 - 0x140];
    int f1C0;
    int f1C4;
    u8 pad1C8[0x878 - 0x1C8];
    int f878;
} S_133C58;
void func_00134D68(void *s);
void func_00134D60(void *s);
int func_00132970(void *s, int n);
int func_00132888_00133C58(void *s, int n);
void func_00134C00_00133C58(void *s, int n);
int func_00132428(void *s);
void func_0013A150(void *s, char *fmt, int x);
extern s32 func_0013A0F8();
extern char D_00151DF8[];
extern char D_00151E20[];
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0x68 - 0x14];
} Fb_133DF8;
typedef struct {
    u8 pad0[0x10C];
    u32 f10C;
    u32 f110;
    u32 f114;
    s32 f118[3];
    s32 f124;
    u8 pad128[0x134 - 0x128];
    s32 f134;
    s32 f138;
    s32 f13C;
    s32 f140;
    u8 pad144[0x14C - 0x144];
    s32 f14C;
    s32 f150;
    s32 f154;
    u8 pad158[0x184 - 0x158];
    s32 f184;
    s32 f188;
    s32 f18C;
    u8 pad190[0x198 - 0x190];
    s32 f198;
    u8 pad19C[0x1F8 - 0x19C];
    Fb_133DF8 fb[9];
    u8 pad5A0[0x858 - 0x5A0];
    s32 f858;
    u8 pad85C[0x87C - 0x85C];
    s32 f87C;
} S_133DF8;
typedef struct {
    s32 w;
    s32 h;
    u8 pad8[0x40 - 8];
    S_133DF8 *q;
} H_133DF8;
extern void func_00136000();
extern u32 func_00136010();
typedef struct {
    u8 pad0[0x160];
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
    s32 f170;
    u8 pad174[0x1BC - 0x174];
    s32 f1BC;
    u8 pad1C0[0x85C - 0x1C0];
    s32 f85C;
    s32 f860;
    s32 f864;
} S_134460;
extern u32 func_00132888();
extern void func_00134C00();
extern void func_001349F8();
typedef struct {
    u8 pad0[0x134];
    u32 f134;
    u32 f138;
    u8 pad13C[0x144 - 0x13C];
    int f144;
    int f148;
    int f14C;
    int f150;
    u8 pad154[0x858 - 0x154];
    int f858;
} S_1345A8;
extern char D_00151E60[];
extern char D_00151E88[];
int func_00132888_001345A8(void *s, int n);
extern s32 func_0013A0F8();
typedef struct {
    u8 pad0[0x828];
    s32 x828;           
    u32 x82C;           
    u8 pad830[0x850 - 0x830];
    u32 x850;           
    u32 x854;           
} S_1346E8;
extern u32 func_00132888();
extern void func_00134BC8(S_1346E8 *);
extern s32 func_0013A0F8();
extern char D_00151EA8[];
extern char D_00151ED0[];
typedef struct { u8 pad[0x878]; s32 x878; } S_1349F8;
typedef struct { void (*f[11])(S_1349F8 *); } T_1349F8;
extern void func_00134D68_001349F8(S_1349F8 *);
extern void func_00134D60_001349F8(S_1349F8 *);
extern void func_00134C00_001349F8(S_1349F8 *, s32);
extern s32 func_00132970_001349F8(S_1349F8 *, s32);
extern u32 func_00132888_001349F8(S_1349F8 *, s32);
extern u8 D_00151FB8[];
typedef struct {
    u8 pad0[0x160];
    s32 f160;
    u8 pad164[0x838 - 0x164];
    long f838;
    long f840;
    u8 pad848[0x868 - 0x848];
    s32 f868;
    u8 pad86C[0x878 - 0x86C];
    s32 f878;
} S_134C08;
typedef struct {
    s32 type;
    s32 pad4;
    long f8;
    long f10;
} Cb_134C08;
extern void func_00134D68_00134C08();
extern void func_00134C00();
extern s32 func_00132970_00134C08();
extern u32 func_00132888();
extern void func_00134110();
extern void func_001343C0();
extern void func_00134460();
extern s32 func_00135D50(s32, s32 *);
extern u32 func_00132888();
typedef struct {
    u8 pad[0x154];
    s32 f154;
    s32 f158;
    s32 f15C;
} S_134DB8;
typedef struct {
    u8 pad0[0x14C];
    s32 f14C;
    u8 pad150[0x184 - 0x150];
    s32 f184;
    s32 f188;
    u8 pad18C[0x194 - 0x18C];
    s32 f194;
    u8 pad198[0x19C - 0x198];
    s32 hoff[3];
    s32 voff[3];
} S_134EE0;
extern u32 func_00132888();
typedef struct {
    u8 pad0[0x68];
} Fb_1350A8;
typedef struct {
    Fb_1350A8 *a;
    Fb_1350A8 *b;
    s32 pad;
    Fb_1350A8 *c;
} G_1350A8;
typedef struct {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[0x18 - 0x10];
    s32 f18;
    u8 pad1C[0x24 - 0x1C];
    s32 (*f24)();
    u8 pad28[0x30 - 0x28];
    s32 (*f30)();
    u8 pad34[0x3C - 0x34];
    s32 f3C;
    u8 pad40[0x48 - 0x40];
    s32 f48;
    u8 pad4C[0x54 - 0x4C];
    s32 f54;
    u8 pad58[0x60 - 0x58];
    s32 f60;
    s32 f64;
    u8 pad68[0x8C - 0x68];
    s32 f8C;
    long f90;
    s32 f98;
    s32 f9C;
    long fA0;
    s32 fA8;
    s32 fAC;
    s32 fB0;
    u8 padB4[0xC0 - 0xB4];
    s32 fC0;
    s32 fC4;
    s32 fC8[14];
    long f100;
    s32 f108;
    s32 f10C;
    s32 f110;
    s32 f114;
    s32 f118[4];
    u8 pad128[0x1C8 - 0x128];
    G_1350A8 g[3];
    Fb_1350A8 fb[9];
    u8 pad5A0[0x85C - 0x5A0];
    s32 f85C;
    s32 f860;
    s32 f864;
    void *f868;
} D_1350A8;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 padC[0x10 - 0xC];
    long f10;
    long f18;
    long f20;
    long f28;
    long f30;
    long f38;
    D_1350A8 *f40;
} M_1350A8;
extern char D_00152058[];
extern char D_00152008[];
extern char D_00152030[];
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_0013A0F8();
extern s32 func_0013A150_001350A8(void *, char *, ...);
extern void func_00135FD8();
extern u32 func_00136010();
extern void func_00134FD8();
extern s32 func_00135C60();
extern s32 func_00135E88();
extern s32 func_00135FF0();
extern s32 func_00136080();
extern s32 func_001360A8();
typedef struct { u8 pad[0xC4]; s32 xC4; u8 pad2[0x24]; s32 xEC; s32 xF0; s32 xF4; s32 xF8; } T_135C10;
typedef struct { u8 pad[0x40]; T_135C10 *x40; } S_135C10;
extern void func_001353A8(S_135C10 *);
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    u8 pC[0x98 - 0xC];
    s32 x98;
    u8 p9C[0xC0 - 0x9C];
    s32 xC0;
    u8 pC4[0x128 - 0xC4];
    s32 x128;
    u8 p12C[0x858 - 0x12C];
    s32 x858;
    u8 p85C[0x878 - 0x85C];
    s32 x878;
} S_135C60;
typedef struct {
    u8 p0[8];
    s32 x8;
    u8 pC[0x40 - 0xC];
    S_135C60 *x40;
} A_135C60;
extern void func_001352E0(S_135C60 *);
typedef struct { u8 pad[0x184]; s32 x184; } T_135E40;
typedef struct { u8 pad[0x40]; T_135E40 *x40; } S_135E40;
extern void func_00135818(S_135E40 *, s32, s32);
extern void func_00135988(S_135E40 *, s32, s32);
typedef struct { u8 pad[0x28]; s32 x28; } C_135E88;
typedef struct { u8 pad[0x1C8]; C_135E88 *a0; C_135E88 *b0; u8 p1[8]; C_135E88 *a1; C_135E88 *b1; u8 p2[8]; C_135E88 *a2; C_135E88 *b2; } T_135E88;
typedef struct { u8 pad[0x40]; T_135E88 *x40; } S_135E88;
typedef struct {
    u8 pad[0x28];
    s32 x28;
} Pic_135F08;
typedef struct {
    u8 pad[0x130];
    s32 x130;
    u8 pad134[0x50];
    s32 x184;
    u8 pad188[0x48];
    Pic_135F08 *x1D0;
    u8 pad1D4[0xC];
    Pic_135F08 *x1E0;
    u8 pad1E4[0xC];
    Pic_135F08 *x1F0;
} Dec_135F08;
extern char D_00152138[];
extern char D_00152158[];
extern s32 func_0013A0F8();
extern s32 func_00131398(Dec_135F08 *);
typedef struct { u32 x0; u32 x4; u32 x8; } S_136010;
extern s32 func_0013A0F8();
extern char D_00152178[];
typedef struct { u8 pad[0x40]; u8 *x40; } S_136080;
extern void func_0013A280(u8 *);
typedef struct { u8 pad[0x40]; u8 *x40; } S_1360A8;
extern void func_0013A368(u8 *);
typedef struct {
    u8 pad0[0xEC];
    u32 fEC;
    u8 padF0[4];
    int fF4;
    int fF8;
    u8 padFC[0x184 - 0xFC];
    int f184;
} S_1360D0;
typedef struct {
    u32 f0;
    u8 pad4[0xC - 4];
    int fC;
    int f10;
} In_1360D0;
int func_00124920(void);
int func_00124970(void);
typedef struct {
    u8 pad0[4];
    int f4;
    int f8;
    int fC;
    int f10;
    u8 pad14[4];
    long f18;
    long f20;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    int f50;
    int f54;
    int f58;
    int f5C;
    int f60;
} In_136620;
typedef struct {
    long a;
    long b;
    long c;
} TS_136620;
typedef struct {
    u8 pad0[0x10];
    TS_136620 ts[2];
} Out_136620;
typedef struct {
    u8 pad0[8];
    int f8;
    u8 padC[0x8C - 0xC];
    int f8C;
    long f90;
    int f98;
    int f9C;
    long fA0;
    u8 padA8[0xC0 - 0xA8];
    int fC0;
    int fC4;
    int fC8;
    int fCC;
    int fD0;
    int fD4;
    int fD8;
    u8 padDC[0xE0 - 0xDC];
    int fE0;
    int fE4;
    u8 padE8[0xF0 - 0xE8];
    int fF0;
    int fF4;
    int fF8;
    u8 padFC[0x100 - 0xFC];
    long f100;
    int f108;
    u8 pad10C[0x128 - 0x10C];
    int f128;
    u8 pad12C[0x184 - 0x12C];
    int f184;
    u8 pad188[0x834 - 0x188];
    int f834;
    u8 pad838[0x868 - 0x838];
    Out_136620 *f868;
} S_136620;
extern char D_00152198[];
int func_00121718(char *buf, int n, const char *fmt, ...);
void func_00136D50();
void func_001360D0();
typedef struct {
    u8 pad0[4];
    int f4;
    int f8;
    u8 padC[0xC0 - 0xC];
    int fC0;
    u8 padC4[0x128 - 0xC4];
    int f128;
    u8 pad12C[0x130 - 0x12C];
    int f130;
    u8 pad134[0x184 - 0x134];
    int f184;
    u8 pad188[0x1CC - 0x188];
    int f1CC;
    u8 pad1D0[0x1DC - 0x1D0];
    In_136620 *f1DC;
    u8 pad1E0[0x1EC - 0x1E0];
    In_136620 *f1EC;
} S_136A40;
typedef struct {
    u8 pad0[8];
    int f8;
    u8 padC[0x40 - 0xC];
    S_136A40 *f40;
} O_136A40;
extern char D_001521C8[];
extern void func_00136360(S_136A40 *s, int a, int b);
void func_00136620(S_136620 *s, In_136620 *a1, In_136620 *a2, int n);
typedef struct {
    u8 pad0[0x108];
    s32 f108;
    u8 pad10C[0x160 - 0x10C];
    s32 f160;
    u8 pad164[0x184 - 0x164];
    s32 f184;
    u8 pad188[0x1C8 - 0x188];
    s32 f1C8;
    u8 pad1CC[0x1D4 - 0x1CC];
    s32 f1D4;
    u8 pad1D8[0x1D8 - 0x1D8];
    s32 f1D8;
    u8 pad1DC[0x1E4 - 0x1DC];
    s32 f1E4;
    u8 pad1E8[0x1E8 - 0x1E8];
    s32 f1E8;
    u8 pad1EC[0x1F4 - 0x1EC];
    s32 f1F4;
} S_136B00;

/* localdecomp:start func_00137450 */
/* libmpeg: skip a PS system header (then its stream entries); 2.9-ee-991111 */
typedef struct {
    u64 buf;
    u64 pos;
    u32 x10;
    u8 *ptr;
    s32 bits;
    u8 *start;
    u8 *end;
} BS_137450;

static __inline__ void skip_137450(BS_137450 *bs, s32 n) {
    bs->buf <<= n;
    bs->bits -= n;
    while (bs->bits <= 56) {
        bs->buf |= (u64)*bs->ptr++ << (56 - bs->bits);
        if (bs->ptr >= bs->end) bs->ptr = bs->start;
        bs->bits += 8;
    }
    bs->pos += n;
}

static __inline__ u32 show_137450(BS_137450 *bs, s32 n) {
    return bs->buf >> (64 - n);
}

s32 func_00137450(BS_137450 *bs) {
    skip_137450(bs, 56);
    skip_137450(bs, 40);
    while (show_137450(bs, 1) == 1) {
        skip_137450(bs, 24);
    }
    return 1;
}
/* localdecomp:end func_00137450 */

/* localdecomp:start func_00137620 */
typedef struct {
    u64 buf;
    u64 pos;
    u32 x10;
    u8 *ptr;
    s32 bits;
    u8 *start;
    u8 *end;
} BS_137620;

typedef struct {
    u32 ext;
    u32 scr;
    u32 scr_hi;
    u32 sys;
} PH_137620;

extern void func_00137450_00137620(BS_137620 *, PH_137620 *);

static __inline__ void skip_137620(BS_137620 *bs, s32 n) {
    bs->buf <<= n;
    bs->bits -= n;
    while (bs->bits <= 56) {
        bs->buf |= (u64)*bs->ptr++ << (56 - bs->bits);
        if (bs->ptr >= bs->end) bs->ptr = bs->start;
        bs->bits += 8;
    }
    bs->pos += n;
}

static __inline__ u32 getbits_137620(BS_137620 *bs, s32 n) {
    u32 v = bs->buf >> (64 - n);
    skip_137620(bs, n);
    return v;
}

s32 func_00137620(BS_137620 *bs, PH_137620 *ph) {
    u32 a, b, c, n, i;

    skip_137620(bs, 34);
    a = getbits_137620(bs, 3);
    skip_137620(bs, 1);
    b = getbits_137620(bs, 15);
    skip_137620(bs, 1);
    c = getbits_137620(bs, 15);
    skip_137620(bs, 1);
    ph->ext = getbits_137620(bs, 9);
    skip_137620(bs, 30);
    n = getbits_137620(bs, 3);
    ph->scr = (a << 30) | (b << 15) | c;
    ph->scr_hi = a >> 2;
    for (i = 0; i < n; i++) {
        skip_137620(bs, 8);
    }
    if ((s32)(bs->buf >> 32) == 0x1BB) {
        ph->sys = 1;
        func_00137450_00137620(bs, ph);
    } else {
        ph->sys = 0;
    }
    return 1;
}
/* localdecomp:end func_00137620 */

/* localdecomp:start func_00137CC8 */
/* MPEG-2 program stream: parse one PES packet header from the bit reader bs into out
   (Sony libmpeg, built with ee-gcc 2.9-ee-991111). */
typedef struct {
    unsigned long buf;   /* 0x00 */
    unsigned long pos;   /* 0x08: bit position */
    u8 *base;            /* 0x10 */
    u8 *ptr;             /* 0x14 */
    s32 cnt;             /* 0x18 */
    u8 *top;             /* 0x1C */
    u8 *end;             /* 0x20 */
    s32 size;            /* 0x24 */
} BS_137CC8;

typedef struct {
    unsigned long id;    /* 0x00 */
    u32 len;             /* 0x08 */
    u32 scr;             /* 0x0C */
    unsigned long pts;   /* 0x10 */
    unsigned long dts;   /* 0x18 */
    u32 datapos;         /* 0x20 */
    s32 datalen;         /* 0x24 */
    u32 pktpos;          /* 0x28 */
} PES_137CC8;

typedef struct { u8 b[16]; } T16_137CC8;
extern const T16_137CC8 D_00152200;
extern char D_00152210[];

/* Refill the 64-bit bit buffer a byte at a time from the ring buffer. */
static __inline__ void fill_137CC8(BS_137CC8 *bs) {
    while (bs->cnt < 57) {
        bs->buf |= (unsigned long)*bs->ptr++ << (56 - bs->cnt);
        if (bs->ptr >= bs->end) bs->ptr = bs->top;
        bs->cnt += 8;
    }
}

static __inline__ u32 getbits_137CC8(BS_137CC8 *bs, s32 n) {
    u32 v;
    v = bs->buf >> (64 - n);
    bs->buf <<= n;
    bs->cnt -= n;
    fill_137CC8(bs);
    bs->pos += n;
    return v;
}

static __inline__ void skipbits_137CC8(BS_137CC8 *bs, s32 n) {
    bs->buf <<= n;
    bs->cnt -= n;
    fill_137CC8(bs);
    bs->pos += n;
}

static __inline__ void seek_137CC8(BS_137CC8 *bs, s32 n) {
    bs->buf = 0;
    bs->cnt = 0;
    bs->pos += n * 8;
    bs->ptr = bs->base + (s32)(bs->pos >> 3);
    if (bs->ptr >= bs->end) bs->ptr -= bs->size;
    skipbits_137CC8(bs, 0);
}

s32 func_00137CC8(void *ctx, BS_137CC8 *bs, PES_137CC8 *out) {
    T16_137CC8 tbl = D_00152200;
    u32 v;
    u32 ptsdts, escr, flags, ext, hlen;
    s32 start;
    s32 len;

    out->pktpos = bs->pos;
    skipbits_137CC8(bs, 24);
    out->id = (unsigned long)getbits_137CC8(bs, 8) << 32;
    v = getbits_137CC8(bs, 16);
    out->len = v;
    out->dts = -1;
    out->pts = -1;
    if (out->id != 0xBC00000000 && out->id != 0xBE00000000 && out->id != 0xBF00000000
        && out->id != 0xF000000000 && out->id != 0xF100000000 && out->id != 0xFF00000000
        && out->id != 0xF200000000 && out->id != 0xF800000000) {
        skipbits_137CC8(bs, 2);
        v = getbits_137CC8(bs, 2);
        out->scr = v;
        skipbits_137CC8(bs, 4);
        ptsdts = getbits_137CC8(bs, 2);
        escr = getbits_137CC8(bs, 1);
        flags = getbits_137CC8(bs, 4);
        ext = getbits_137CC8(bs, 1);
        hlen = getbits_137CC8(bs, 8);
        start = bs->pos;
        if (ptsdts & 2) {
            u32 a, b, c, lo;
            skipbits_137CC8(bs, 4);
            a = getbits_137CC8(bs, 3);
            skipbits_137CC8(bs, 1);
            b = getbits_137CC8(bs, 15);
            skipbits_137CC8(bs, 1);
            c = getbits_137CC8(bs, 15);
            skipbits_137CC8(bs, 1);
            lo = (a << 30) | (b << 15) | c;
            out->pts = (((unsigned long)(a >> 2)) << 32) | lo;
        }
        if (ptsdts == 3) {
            u32 a, b, c, lo;
            skipbits_137CC8(bs, 4);
            a = getbits_137CC8(bs, 3);
            skipbits_137CC8(bs, 1);
            b = getbits_137CC8(bs, 15);
            skipbits_137CC8(bs, 1);
            c = getbits_137CC8(bs, 15);
            skipbits_137CC8(bs, 1);
            lo = (a << 30) | (b << 15) | c;
            out->dts = (((unsigned long)(a >> 2)) << 32) | lo;
        }
        if (escr == 1) {
            skipbits_137CC8(bs, 48);
        }
        if (flags) {
            s32 n = tbl.b[flags];
            skipbits_137CC8(bs, n);
        }
        if (ext == 1) {
            u32 priv, pack, seq, pstd, ext2;
            priv = getbits_137CC8(bs, 1);
            pack = getbits_137CC8(bs, 1);
            seq = getbits_137CC8(bs, 1);
            pstd = getbits_137CC8(bs, 1);
            skipbits_137CC8(bs, 3);
            ext2 = getbits_137CC8(bs, 1);
            if (priv == 1) {
                skipbits_137CC8(bs, 48);
                skipbits_137CC8(bs, 48);
                skipbits_137CC8(bs, 32);
            }
            if (pack == 1) {
                func_0013A0F8(ctx, D_00152210);
                return 0;
            }
            if (seq == 1) {
                skipbits_137CC8(bs, 16);
            }
            if (pstd == 1) {
                skipbits_137CC8(bs, 16);
            }
            if (ext2 == 1) {
                u32 n, i;
                skipbits_137CC8(bs, 1);
                n = getbits_137CC8(bs, 7);
                for (i = 0; i < n; i++) {
                    skipbits_137CC8(bs, 8);
                }
            }
        }
        {
            s32 k = hlen - (s32)((bs->pos - start) >> 3);
            if (k) {
                seek_137CC8(bs, k);
            }
        }
        len = out->len - hlen - 3;
        out->datalen = len;
        out->datapos = bs->pos;
        if (out->id == 0xBD00000000) {
            out->id |= getbits_137CC8(bs, 32);
            len -= 4;
        }
        if (len) {
            seek_137CC8(bs, len);
        }
    } else if (out->id == 0xBC00000000 || out->id == 0xBF00000000 || out->id == 0xF000000000
               || out->id == 0xF100000000 || out->id == 0xFF00000000 || out->id == 0xF200000000
               || out->id == 0xF800000000) {
        s32 n = out->len;
        if (out->id == 0xBF00000000) {
            out->id |= getbits_137CC8(bs, 32);
            n -= 4;
        }
        if (n) {
            seek_137CC8(bs, n);
        }
    } else if (out->id == 0xBE00000000) {
        s32 n = out->len;
        if (n) {
            seek_137CC8(bs, n);
        }
    }
    return 1;
}
/* localdecomp:end func_00137CC8 */

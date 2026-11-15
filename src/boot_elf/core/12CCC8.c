#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 12A948.c's earlier functions (tools/port_from_us.py) */
extern s32 func_0012B098(s32);
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern s32 D_15A140;
extern void *D_15A144;
extern volatile int D_0013F914;
extern volatile int D_0013F920;
extern volatile int D_0013F928;
extern volatile int D_0013F934;
extern volatile int D_0013F960;
extern volatile int D_0013F964;
extern int D_15A140;
extern void func_0011EE50(s32);
typedef struct {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    u32 attr;
    u32 option;
} SemaParam_12AC40;
extern volatile int D_0013F920;
extern volatile int D_0013F928;
extern volatile int D_0013F92C;
extern volatile int D_0013F930;
extern volatile int D_0013F934;
extern char D_00151300[];
extern char D_00151310[];
extern char D_00151320[];
extern char D_00151330[];
extern int func_0011EE20();
extern s32 D_0013F924_0012AE20[];
extern s32 D_0013F948_0012AE20[];
extern void func_0012ADC8(void);
extern void func_00121B70();
extern s32 func_00124920(void);
extern s32 func_00124970(void);
typedef struct { u8 pad[0x24]; s32 x24; } S_12AEA8;
extern void func_0012AC40_0012AEA8(void);
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_00121760_0012AEA8();
extern s32 func_0012B098(s32);
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern volatile s32 D_0013F928;
extern s32 D_0013F910;
extern s32 D_0013F91C;
extern s32 D_0013F93C;
extern S_12AEA8 D_00140AD0;
extern char D_001513B8[];
extern char D_001513E0[];
extern u8 D_0013F980[];
extern s32 D_0013F910_0012B138[];
extern u8 D_00141480_0012B138[];
extern char D_00151408_0012B138[];
extern s32 func_00122A10(void *);
extern s32 func_0011FC78(s32);
extern void func_00121760_0012B1A8(const char *, ...);
typedef struct {
    u8 pad[0x24];
    s32 serve;
} Cd_12B1A8;
extern volatile s32 D_0013F92C;
extern s32 D_0013F910;
extern s32 D_0013F918;
extern s32 D_0013F954;
extern Cd_12B1A8 D_00141480_0012B1A8;
extern char D_00151418[];
extern char D_00151440[];
extern void func_0012AC40_0012B1A8(void);
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_00121760_0012B1A8(const char *, ...);
extern s32 func_0012B138(s32);
extern void func_00121FE8(s32);
extern s32 func_00122630_0012B1A8(Cd_12B1A8 *, u32, s32);
typedef struct { u8 pad[0x24]; s32 x24; } S_12B5E8;
extern s32 func_0012B138(s32);
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern void func_00121760_0012B5E8();
extern void func_00121F38();
extern s32 func_00122810();
extern s32 func_00124920(void);
extern void func_00124970_0012B5E8(void);
extern void func_0012AC40_0012B5E8(void);
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern s32 D_0013F910;
extern volatile s32 D_0013F92C;
extern s32 D_0013F940;
extern s32 D_0013F950;
extern S_12B5E8 D_15A390;
extern s32 D_15A3D0;
extern s32 D_00140B00_0012B5E8[];
extern char D_00151488[];
extern char D_001514A0[];
extern char D_001514C0[];
typedef struct {
    u8 pad0[0x24];
    int serve;
    u8 pad28[0x40 - 0x28];
} Cd_12B800;
extern int D_0013F910;
extern volatile int D_0013F930;
extern int D_0013F940;
extern int D_0013F950;
extern char D_001514A0[];
extern char D_001514C0[];
extern char D_001514D8[];
extern Cd_12B800 D_15A390_0012B800;
extern int D_15A3D0;
extern int D_00141380[];
extern int func_00121760();
extern int func_0011EE40();
extern int func_0011EE70();
extern int func_00121FE8_0012B800();
extern void func_00121F38();
extern int func_0012AC40();
extern int func_0012B5E8();
extern int func_00124920();
extern int func_00124970_0012B800();
extern s32 func_00122630(void *, s32, s32);
extern s32 func_00122810();
extern s32 D_00140B00_0012BC00[];
extern u8 D_00141480_0012BC00[];
extern s32 D_0013F92C_0012BC00[];
extern volatile int D_0013F960;
extern u8 D_00141480[];
extern int D_00140B00_0012BC98[];
extern int func_0012B1A8(int n);
extern s32 D_00140F40;
extern s32 D_001414A8;
extern s32 D_001414AC;
extern s32 D_001414B0;
extern u8 D_00140B00[];
extern u8 D_00141480[];
extern s32 D_0013F92C_0012BD50;
extern s32 func_0012B1A8(s32);
extern void func_00121F38(void *, s32);
extern s32 func_00122810();
extern s32 func_0011EE40(s32);
typedef struct {
    u8 b[8];
} Clock_12BE28;
extern u8 D_00140B00[];
extern s32 D_0013F92C_0012BE28;
extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);
typedef struct {
    s16 inter;
    s16 omode;
    s16 ffmode;
    u16 version;
    int vsc;
    int vscid;
} GParam_12BEE8;
GParam_12BEE8 *func_0012C078_0012BEE8(void);
u64 func_0011F160(u64 imr);
void func_0011F870(int n);
void func_0011EB20(int n, int id);
void func_0011EA20(int inter, int omode, int ffmode);
extern u8 D_001414D0[];
extern s32 func_00123430(void *, s32);
extern s32 func_00123840(s32, void *, s32);
extern void func_001236C0(s32);
extern s32 func_00117070(void *);
extern u8 D_00151540[];
typedef struct {
    u64 pmode;
    u64 smode2;
    u64 dispfb;
    u64 display;
    u64 bgcolor;
} Disp_12C4B0;
typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
} Gs_12C4B0;
extern void *func_0012C078(void);
extern void *func_0012C078(void);
typedef struct {
    u64 ATE : 1;
    u64 pad : 63;
} Bit_12C638;
typedef struct {
    u64 frame1;
    u64 frame1addr;
    u64 zbuf1;
    u64 zbuf1addr;
    u64 xyoffset1;
    u64 xyoffset1addr;
    u64 scissor1;
    u64 scissor1addr;
    Bit_12C638 prmodecont;
    u64 prmodecontaddr;
    Bit_12C638 colclamp;
    u64 colclampaddr;
    Bit_12C638 dthe;
    u64 dtheaddr;
    u64 test1;
    u64 test1addr;
} DrawEnv_12C638;
short func_0012C570(short psm, short w, short h);
extern char D_00151588[];
extern s32 func_00121760_0012C820(char *, ...);
extern long func_0011F340();
extern void func_0011F2B0();

/* localdecomp:start func_0012CCC8 */
extern int func_00121760();
extern char D_001516E0[];

int func_0012CCC8(u64 *p1, u64 *p2)
{
    u32 i;

    i = 0;
    while (*(volatile u32 *)0x1000A000 & 0x100) {
        if (i++ > 0x1000000) {
            goto timeout;
        }
    }
    *(volatile u32 *)0x1000A020 = 6;
    if (((u32)p1 & 0x70000000) == 0x70000000) {
        *(volatile u32 *)0x1000A010 = ((u32)p1 & 0x0FFFFFFF) | 0x80000000;
    } else {
        *(volatile u32 *)0x1000A010 = (u32)p1 & 0x0FFFFFFF;
    }
    *(volatile u32 *)0x1000A000 = 0x101;
    while (*(volatile u32 *)0x1000A000 & 0x100) {
        if (i++ > 0x1000000) {
            goto timeout;
        }
    }
    *(volatile u32 *)0x1000A020 = p1[10] & 0x7FFF;
    if (((u32)p2 & 0x70000000) != 0x70000000) {
        goto other;
    }
    *(volatile u32 *)0x1000A010 = ((u32)p2 & 0x0FFFFFFF) | 0x80000000;
    goto kick;
timeout:
    func_00121760(D_001516E0);
    return -1;
other:
    *(volatile u32 *)0x1000A010 = (u32)p2 & 0x0FFFFFFF;
kick:
    *(volatile u32 *)0x1000A000 = 0x101;
    return 0;
}
/* localdecomp:end func_0012CCC8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0012CE44);

/* localdecomp:start func_0012CE48 */
/* libgraph sceGsExecStoreImage (graph018.o), as rac1-decomp has it (src/core/gs/store_image.c) */
typedef int Q_12CE48 __attribute__((mode(TI)));
typedef struct {
    unsigned long SBP : 14;
    unsigned long p14 : 2;
    unsigned long SBW : 6;
    unsigned long p22 : 2;
    unsigned long SPSM : 6;
    unsigned long p30 : 2;
    unsigned long DBP : 14;
    unsigned long p46 : 2;
    unsigned long DBW : 6;
    unsigned long p54 : 2;
    unsigned long DPSM : 6;
    unsigned long p62 : 2;
} Bitbltbuf_12CE48;
typedef struct {
    unsigned long RRW : 12;
    unsigned long p12 : 20;
    unsigned long RRH : 12;
    unsigned long p44 : 20;
} Trxreg_12CE48;
typedef struct {
    unsigned int vifcode[4];
    unsigned long giftag[2];
    Bitbltbuf_12CE48 bitbltbuf;
    long bitbltbufaddr;
    unsigned long trxpos;
    long trxposaddr;
    Trxreg_12CE48 trxreg;
    long trxregaddr;
    unsigned long finish;
    long finishaddr;
    unsigned long trxdir;
    long trxdiraddr;
} StoreImage_12CE48 __attribute__((aligned(16)));

extern char D_00151720[];
extern char D_00151758[];
extern char D_00151788[];
extern char D_001517C8[];
extern Q_12CE48 D_001414E0;

int func_0012CE48(StoreImage_12CE48 *sp, Q_12CE48 *dstaddr) {
    extern int func_0011F140();
    extern void func_00121760_0012CE48();
    extern u64 func_0011F160_0012CE48();
    unsigned int cnt = 0;
    int nfull = 0, nrem = 0, nbyte = 0, nrest = 0;
    int w, h, psm, bytes, i, n;
    u64 old;
    int h2;
    union {
        Q_12CE48 q;
        unsigned char c[16];
    } buf;

    w = sp->trxreg.RRW;
    h = sp->trxreg.RRH;
    psm = sp->bitbltbuf.SPSM;
    h2 = 0;
    switch (psm) {
        case 0x00:
        case 0x30:
            bytes = w * h * 4;
            nbyte = bytes & 0xF;
            nfull = (bytes >> 4) & ~7u;
            nrem = (bytes >> 4) & 7;
            if (!nbyte) {
                h2 = h;
                nrest = 0;
            } else {
                h2 = (h + 3) & ~3;
                n = w * h2;
                nrest = (n >> 2) - nfull - nrem - 1;
            }
            break;
        case 0x01:
        case 0x31:
            bytes = w * h * 3;
            nbyte = bytes & 0xF;
            nfull = (bytes >> 4) & ~7u;
            nrem = (bytes >> 4) & 7;
            if (!nbyte) {
                h2 = h;
                nrest = 0;
            } else {
                h2 = (h + 15) & ~15;
                n = w * h2;
                n = ((n * 3) >> 4) - nfull;
                nrest = n - nrem - 1;
            }
            break;
        case 0x02:
        case 0x0A:
        case 0x32:
        case 0x3A:
            bytes = w * h * 2;
            nbyte = bytes & 0xF;
            nrem = (bytes >> 4) & 7;
            nfull = (bytes >> 4) & ~7u;
            if (!nbyte) {
                h2 = h;
                nrest = 0;
            } else {
                h2 = (h + 7) & ~7u;
                n = w * h2;
                nrest = (n >> 3) - nfull - nrem - 1;
            }
            break;
        case 0x13:
        case 0x1B:
            bytes = w * h;
            nbyte = bytes & 0xF;
            nrem = (bytes >> 4) & 7;
            nfull = (bytes >> 4) & ~7u;
            if (!nbyte) {
                h2 = h;
                nrest = 0;
            } else {
                h2 = (h + 7) & ~7u;
                n = w * h2;
                nrest = (n >> 4) - nfull - nrem - 1;
            }
            break;
        case 0x14:
        case 0x24:
        case 0x2C:
            bytes = (w * h) >> 1;
            nbyte = bytes & 0xF;
            nrem = (bytes >> 4) & 7;
            nfull = (bytes >> 4) & ~7u;
            if (!nbyte) {
                h2 = h;
                nrest = 0;
            } else {
                h2 = (h + 7) & ~7u;
                n = w * h2;
                nrest = (n >> 5) - nfull - nrem - 1;
            }
            break;
    }

    if (nbyte) {
        *(long *)((unsigned int)&sp->trxreg | 0x20000000) = (long)(int)sp->trxreg.RRW | ((long)h2 << 32);
    }

    while (*(volatile int *)0x10009000 & 0x100) {
        if (cnt++ > 0x1000000) {
            func_00121760_0012CE48(D_00151720);
            return -1;
        }
    }

    old = func_0011F160_0012CE48(func_0011F140() | 0x200);
    *(volatile long *)0x12001000 = 2;
    *(volatile int *)0x10009020 = 7;
    if (((unsigned int)sp & 0x70000000) == 0x70000000) {
        *(volatile int *)0x10009010 = ((unsigned int)sp & 0x0FFFFFFF) | 0x80000000;
    } else {
        *(volatile int *)0x10009010 = (unsigned int)sp & 0x0FFFFFFF;
    }
    *(volatile int *)0x10009000 = 0x101;
    while (*(volatile int *)0x10009000 & 0x100) {
        if (cnt++ > 0x1000000) {
            func_00121760_0012CE48(D_00151720);
            return -1;
        }
    }

    while (!(*(volatile long *)0x12001000 & 2)) {
        if (cnt++ > 0x1000000) {
            func_00121760_0012CE48(D_00151758);
            *(volatile Q_12CE48 *)0x10005000 = D_001414E0;
            return -1;
        }
    }

    *(volatile int *)0x10003C00 = 0x800000;
    *(volatile long *)0x12001040 = 1;

    if (nfull) {
        *(volatile int *)0x10009020 = nfull;
        if (((unsigned int)dstaddr & 0x70000000) == 0x70000000) {
            *(volatile int *)0x10009010 = ((unsigned int)dstaddr & 0x0FFFFFFF) | 0x80000000;
        } else {
            *(volatile int *)0x10009010 = (unsigned int)dstaddr & 0x0FFFFFFF;
        }
        *(volatile int *)0x10009000 = 0x100;
        while (*(volatile int *)0x10009000 & 0x100) {
            if (cnt++ > 0x1000000) {
                func_00121760_0012CE48(D_00151788);
                *(volatile long *)0x12001000 = 0x100;
                *(volatile long *)0x12001040 = 0;
                *(volatile int *)0x10003000 = 1;
                *(volatile int *)0x10003C10 = 1;
                return -1;
            }
        }
    }

    for (i = 0; i < nrem; i++) {
        while (!(*(volatile int *)0x10003C00 & 0x1F000000)) {
            if (cnt++ > 0x1000000) {
                func_00121760_0012CE48(D_001517C8);
                *(volatile long *)0x12001000 = 0x100;
                *(volatile long *)0x12001040 = 0;
                *(volatile int *)0x10003000 = 1;
                *(volatile int *)0x10003C10 = 1;
                return -1;
            }
        }
        dstaddr[nfull + i] = *(volatile Q_12CE48 *)0x10005000;
    }

    if (nbyte) {
        while (!(*(volatile int *)0x10003C00 & 0x1F000000)) {
            if (cnt++ > 0x1000000) {
                func_00121760_0012CE48(D_001517C8);
                *(volatile long *)0x12001000 = 0x100;
                *(volatile long *)0x12001040 = 0;
                *(volatile int *)0x10003000 = 1;
                *(volatile int *)0x10003C10 = 1;
                return -1;
            }
        }
        buf.q = *(volatile Q_12CE48 *)0x10005000;
        for (i = 0; i < nbyte; i++) {
            ((unsigned char *)&dstaddr[nfull + nrem])[i] = buf.c[i];
        }
        for (i = 0; i < nrest; i++) {
            while (!(*(volatile int *)0x10003C00 & 0x1F000000)) {
                if (cnt++ > 0x1000000) {
                    func_00121760_0012CE48(D_001517C8);
                    *(volatile long *)0x12001000 = 0x100;
                    *(volatile long *)0x12001040 = 0;
                    *(volatile int *)0x10003000 = 1;
                    *(volatile int *)0x10003C10 = 1;
                    return -1;
                }
            }
            buf.q = *(volatile Q_12CE48 *)0x10005000;
        }
    }

    *(volatile int *)0x10003C00 = 0;
    *(volatile long *)0x12001040 = 0;
    func_0011F160_0012CE48(old);
    {
        Q_12CE48 t = D_001414E0;
        *(volatile long *)0x12001000 = 2;
        *(volatile Q_12CE48 *)0x10005000 = t;
    }
    return 0;
}
/* localdecomp:end func_0012CE48 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D4D4);

/* localdecomp:start func_0012D4D8 */
extern void *func_0012C078(void);
extern void func_0011F870(int n);
extern void func_0011EB20(int n, int id);
extern s32 func_0011EB00();
extern void func_0011F8D8();
s32 func_0012D4D8(s32 a0) {
    u8 *p;
    s32 old;
    p = func_0012C078();
    old = *(s32 *)(p + 8);
    if (a0 == 0) {
        func_0011F870(2);
        func_0011EB20(2, *(s32 *)(p + 0xC));
        *(s32 *)(p + 0xC) = 0;
        *(s32 *)(p + 8) = 0;
    } else {
        if (old != 0) {
            func_0011F870(2);
            func_0011EB20(2, *(s32 *)(p + 0xC));
        }
        *(s32 *)(p + 8) = a0;
        *(s32 *)(p + 0xC) = func_0011EB00(2, a0, -1);
        func_0011F8D8(2);
    }
    return old;
}
/* localdecomp:end func_0012D4D8 */

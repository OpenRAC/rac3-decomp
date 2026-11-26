/* PAL near miss (k6 a6, 2026-11-26): func_L01_00428098 (11540 B, 34 places), the level loader, ported from
 * func_L39_005A12B8 (the multiplayer copy) by aligning the two retail .s files for the symbol map and adding the
 * story-level code by hand: the hero clear (func_0038CB78 of 0x28E0 bytes), func_0013D3D0(0x4D2), the
 * moby-spawn filter on the save bits (D_001BBC40 / D_001BBE90 / D_L01_00237800 / D_L01_001DFE80 with
 * bolts2 / xp2), the end moby (state 0xFD) and per-moby func_L01_004312D8, the ship spawn (class 0xD54)
 * and the story tail calls; the splitscreen tie copies are dropped. Needs -mvu0-use-vf0-vf2 on
 * L01_00427E58.c's line (its other three functions still match with it, checked at all places).
 * Measured with --flags "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as": 2373 raw
 * words differ but only about 170 instructions when aligned (2871 vs 2886 instructions). What is left is
 * mostly scheduling and register choice: stack spills of reload/start (0(sp), 4(sp)) where retail keeps
 * them on the stack, some %hi/gp addressing of the same globals (D_001D545C, D_L01_001E0DC8) that
 * retail reaches absolutely in places, the tie/shrub loops' first-statement order, and the store order
 * of the 0xE0 constants at the end. The renaming kit is in ~/RACSwarm/k6/w/big (align.py, build.py). */
#include "common.h"
/* localdecomp:start func_L01_00428098 */
typedef int TI128__5A12B8 __attribute__((mode(TI)));
typedef union { TI128__5A12B8 q; float f[4]; int i[4]; } Vec_5A12B8;


typedef struct {
    char pad00[0xC];
    char *data;                   /* 0x0C: the level data image */
    int i10;
    int i14;
    int i18;
    char pad1C[0x2C];
    char *heap;                   /* 0x48 */
    char *mark4C;
    char *mark50;
    char *mark54;
    char *mark58;
    char *mark5C;
    char *mark60;
    char *mark64;
} LoadCtx_5A12B8;

typedef struct { char pad00[0x64C]; int f64C; char pad650[0x18]; int f668; int f66C; char pad670[0x79A4 - 0x670]; int i79A4; char pad79A8[0x18]; int i79C0; int i79C4; } Boot_5A12B8;
typedef struct { char pad00[0x25C]; int i23C; int i240; int i244; } Cfg_5A12B8;
typedef struct { void *hero; char pad04[0x3C]; int i40; int i44; int i48; } Sel_5A12B8;
typedef struct { char pad00[8]; int i8; char pad0C[0x84]; } Sound_5A12B8;  /* 0x90 */
typedef struct { char pad00[0xB8]; int count; Sound_5A12B8 *table; } Slots_5A12B8;
typedef struct { char pad00[0xC]; int count; int i10; unsigned short *bits; int i18; int i1C; float pos[2][4]; float dir[2][4]; } Tutorial_5A12B8;
typedef struct { char pad00[4]; char *p4; char *p8; int iC; int i10; int i14; } Coll_5A12B8;

typedef struct {
    Vec_5A12B8 bounds;              /* 0x00 */
    unsigned short h10;
    short h12;
    unsigned short h14;
    short h16;
    short h18;
    unsigned short h1A;
    unsigned char b1C;
    unsigned char b1D;            /* class index */
    unsigned char b1E;
    unsigned char b1F;
} Tie_5A12B8;                       /* 0x20 */

typedef struct { Vec_5A12B8 row[4]; } Matrix_5A12B8;   /* 0x40 */

typedef struct {
    char pad00[0x20];
    int first;                    /* 0x20: the class's first tie index */
    char pad24[0xC];
    char *table;                  /* 0x30 */
    char pad34[4];
    short h38;
    char pad3A[4];
    unsigned short h3E;
    float f40;
    char pad44[0xC];
    Vec_5A12B8 sphere;              /* 0x50: centreXYZ and radius */
} TieClass_5A12B8;

typedef struct {
    Vec_5A12B8 bounds;              /* 0x00 */
    float f10;
    char pad14[3];
    unsigned char b17;
    short h18;
    unsigned char b1A;            /* class index */
    unsigned char b1B;
    unsigned short h1C;
    unsigned short h1E;
} Shrub_5A12B8;                     /* 0x20 */

typedef struct {
    char pad00[0xC];
    float fC;
    char pad10[6];
    unsigned short h16;
    Shrub_5A12B8 *first;            /* 0x18 */
    float *p1C;
    float f20;
} ShrubClass_5A12B8;

typedef struct {
    char pad00[0x10];
    Vec_5A12B8 pos;                 /* 0x10 */
    unsigned char state;          /* 0x20 */
    unsigned char b21;
    char pad22[2];
    char *pClass;                 /* 0x24 */
    char pad28[4];
    float f2C;
    unsigned char b30;
    char pad31;
    unsigned short h32;
    unsigned short h34;
    unsigned short h36;
    int i38;
    char pad3C[0x27];
    unsigned char b63;
    int i64;
    int i68;
    char pad6C[0x12];
    unsigned char b7E;
    char pad7F[0x2B];
    short oClass;                 /* 0xAA */
    char padAC[4];
    unsigned char bB0;
    unsigned char bB1;
    short hB2;
    short hB4;
    short hB6;
    char padB8[0x38];
    float rot[4];                 /* 0xF0 */
} Moby_5A12B8;                      /* 0x100 */

typedef struct { char pad00[0x24]; float f24; char pad28[0x1C]; unsigned short h44; } MobyClass_5A12B8;

typedef struct {
    short h0, h2, h4, h6, h8;
    char pad0A[2];
    int iC, i10, i14, i18, i1C;
    char pad20[0x10];
} GroupEntry_5A12B8;                /* 0x30 */

typedef struct Groups_5A12B8 {
    int count;                    /* 0x00 */
    char *p4;
    char *p8;
    char *pC;
    char *p10;
    char *p14;
    char pad18[0x18];
    GroupEntry_5A12B8 entries[0];   /* 0x30 */
} Groups_5A12B8;

typedef struct { int offset; int size; } Blob_5A12B8;
extern int *D_L01_001D6764;
extern int D_L01_001D6768;
extern int *D_L01_001D676C;
extern int D_L01_001D6770;
extern int D_L01_001DFC48;
extern struct Groups_5A12B8 *D_L01_001DFC4C;
extern char *D_L01_001E011C;   /* clip volumes, 0x90 bytes each */
extern int D_L01_001E0120;
extern char *D_L01_001E0100;   /* cuboids */
extern int D_L01_001E0104;
extern char *D_L01_001E0124;   /* spheres */
extern int D_L01_001E0128;
extern char *D_L01_001E0100;   /* cylinders */
extern int D_L01_001E0104;
extern int D_L01_001E0134;     /* path count */
extern char *D_L01_001E0138;   /* path data */
typedef struct { int i0; int i4; } Path_5A12B8;
typedef struct { Vec_5A12B8 head; char *data; int i14; char pad18[8]; } Rail_5A12B8;   /* 0x20 */
extern Rail_5A12B8 *D_L01_001DFC90;
extern int D_L01_001DFC94;
extern char *D_L01_001E0278;
extern int D_L01_001E027C;
extern int D_L01_001E0280;
extern int D_L01_001E0284;

extern LoadCtx_5A12B8 D_L01_001EA940;
extern Boot_5A12B8 D_00160C40;
extern char *D_001D4B54;
extern char D_L01_001E2880[];
extern char D_L01_001F4740[];
typedef struct { int i0; char pad04[0xB3]; unsigned char lang; } Opt_005A12B8;
extern Opt_005A12B8 D_00143950;
extern float D_001D5308;
extern Coll_5A12B8 D_L01_001EAA00_00428098;
extern char D_L01_001EAA80[];
extern char D_L01_001DFBC0[];
extern char D_L01_00201D60[];
extern char D_L01_0021DD60[];
extern Cfg_5A12B8 D_L01_001E7580;
extern unsigned char D_L01_001DF9E4;
extern unsigned char D_L01_001DF9E5;
extern unsigned char D_L01_001DF9E6;
extern float D_L01_001DF9E8;
extern float D_L01_001DF9EC;
extern float D_L01_001DF9F0;
extern float D_L01_001DF9F4;
extern int D_L01_001D673C;
extern float D_L01_001DFC30;
extern float D_L01_001DFC50;
extern float D_L01_001DFC54;
extern float D_L01_001DFC58;
extern float D_L01_001DFC5C;
extern Sel_5A12B8 D_0016C580;
extern Tutorial_5A12B8 D_L01_001F3F40;
extern int D_L01_001D60EC;
extern int D_L01_001E0F14;
extern float D_L01_001E0EC0;
extern float D_L01_001E0DD8;
extern int D_L01_001E0050;
extern int D_L01_001E0288;
extern char D_00100AE0[];
extern char D_L01_001F1B40[];
extern char D_L01_001F1C40[];
extern char D_L01_001F1740[];
extern int D_L01_001DFE78;
extern char D_L01_001F0540[];
extern char D_L01_001F0740[];
extern int D_L01_001E0E94;
typedef struct { char pad00[0x36]; unsigned short h36; char pad38[2]; unsigned short h3A; char pad3C; unsigned char b3D; char pad3E[2]; } Tfrag_5A12B8;   /* 0x40 */
extern char *D_L01_001E0E90;
typedef struct { char pad00[0x2C]; int count; } TextHdr_5A12B8;
extern TextHdr_5A12B8 D_L01_002E5F30;
extern unsigned char D_001A7BB2[]; /* option bytes; [2] is the language */
typedef struct { int offset; int pad4[3]; } Text_5A12B8;
extern Text_5A12B8 *D_L01_001DFCC0;
extern int D_L01_001E0EE0;
extern Tie_5A12B8 *D_L01_001E0ED4;
extern Tie_5A12B8 *D_L01_001E0ED8;
extern Matrix_5A12B8 *D_L01_001E0EDC;
extern int D_L01_001E0F0C;
extern const int D_L39_00242CC0;
extern char *D_L39_0024CA58[];
extern Tie_5A12B8 *D_L39_0024CA38[];
extern Tie_5A12B8 *D_L39_0024CA48[];
extern char *D_L39_0024CA98[];
extern int D_L39_0024CA68[];
extern int D_L39_0024CA78[];
extern int D_L39_0024CA88[];
extern char *D_L01_001E0F08;
extern char D_L01_0023E800[];
extern int D_L01_001E0EFC;
extern int D_L01_001E0F00;
extern int D_L01_001E0F04;
extern TieClass_5A12B8 *D_L01_0023C500[];
extern unsigned char D_L01_0023C800[];
extern Shrub_5A12B8 *D_L01_001E0DC8;
extern int D_L01_001E0DC4;
extern Matrix_5A12B8 *D_L01_001E0DD0;
extern unsigned char *D_L01_001E0DD4;
extern Shrub_5A12B8 *D_L01_001E0DCC;
extern int D_L01_001DA510[];
extern ShrubClass_5A12B8 *D_L01_00238470[];
extern unsigned char D_L01_002385F0[];
typedef struct { float f0, f4, f8; int iC; float f10, f14, f18; int i1C; } Cam_5A12B8;
extern Cam_5A12B8 *D_L01_001DF804;
extern int D_L01_001DF808;
extern Slots_5A12B8 D_001A30B0;
extern int D_L01_001EFC80[][3];
extern int D_L01_001EFD40[][3];
extern Moby_5A12B8 *D_L01_001E001C;
extern Moby_5A12B8 *D_L01_001E0020;
extern Moby_5A12B8 *D_L01_001E0030;
extern Moby_5A12B8 *D_L01_001E0024;
extern int D_L01_001E0034;
extern int func_003C2948(int, char *);
extern short D_L01_001F4B40[];
extern int D_001D545C;
extern int D_L01_0021DE20[];
extern int D_L01_001E0058;
extern int D_L01_001E005C;
extern char *D_L01_0021F6C0[];
extern char *D_L01_001DF840;
extern char *D_L01_001DFE74;
extern int D_L01_001DFE70;
extern char *D_L01_001E00C0;
extern int D_L01_001E00B4;
extern char D_L01_00220840[];
extern int D_L01_001DFB80;
extern unsigned short *D_L01_001E0EE4;
extern int D_L01_001DFB94;
extern short D_L01_001E0140;
extern short D_L01_001E238C[];
extern short D_L39_0024C080;
extern short D_L39_0024C0C0;
typedef struct { short h0; char pad02[0x7E]; } Bank_5A12B8;
extern Bank_5A12B8 D_L01_0021FAB8[];
extern int D_L39_0024112C;
extern int D_L39_0024BC34;
extern int D_L01_001D7B88;
extern int D_L01_001D7B8C;
extern int D_L01_001D7B90;
extern int D_L01_001DFB40;
extern int D_L01_001D7B80;
extern char D_L01_001D6128[] __attribute__((section(".sdata")));
extern char D_L01_001D60F8[] __attribute__((section(".sdata")));
extern char *D_L01_001DF940;
extern char *D_L01_001D6158;

extern int func_003A26F0(void *, int, int);
extern void func_0011F0A0(int);
extern void func_003A0760(void *, void *);
extern void func_0038CB78(void *, int, int);
extern u8 D_001A4BE0_00428098[];
extern void func_0013D3D0(int);
extern int D_L01_001D669C;
extern u8 D_001BBC40[];
extern u8 D_001BBE90[];
extern u8 D_L01_001DFE80[];
typedef struct { u8 pad[0x464]; u8 x464[1]; } T_00428098;
extern T_00428098 D_L01_00237800;
extern int func_L01_00400430(int);
extern int D_L01_0023AC70[];
extern void func_L01_004AC1C0(void *);
extern void func_L01_004312D8(void *, int);
extern void func_L01_004DF428(void);
extern void func_L01_00457558(void);
extern void func_L01_003158D0(void);
extern int D_L01_001E2360[];
extern short D_L01_0021FEB8;
extern int D_L01_001D7B94;
extern short D_L01_001E0180;
extern short D_L01_001E01C0;
extern int D_L01_001DFC34;
extern Moby_5A12B8 *D_L01_001DF94C;
extern void func_003C2D88(void);
extern void func_L01_0044DF00(int);
extern void func_0038CBA0(void *, int);
extern void func_003864C0(int);
extern void func_00392260(int, int, int);
extern void func_003A8F90(void *);
extern void func_0038CC88(void *, void *, int);
extern void func_003D0180(void *);
extern void func_0038D000(void *, void *, void *);
extern float func_0038CEA8(void *);
extern void func_0038CE50(void *, void *, float);
#include "vu0.h"
extern void func_0038CD28(void *, void *, int);
extern void func_003E0B10(void *);
extern void func_L01_004AB070(void *);
extern void func_003C25D8(void *, int);
extern float func_003C3D30(void *, int, int, float);
extern void func_003C7C38(void *);
extern void func_003C6F90(void *, int, int, int, int);
extern void func_00387EF0(void);
extern void func_L01_003F5BE0(void);
extern void func_00384D88(void);
extern void func_L01_004606A8(int);
extern void func_L01_004C88C8(void);
extern void func_L01_004574E0(void);
extern void func_L01_00457528(void);
extern void func_L01_003F5498(int, float);

char *func_L01_00428098(int reload)
{
    char *hdr = D_L01_001EA940.data;
    char *heap = D_L01_001EA940.heap;
    short *idx; /* moby index by file order */
    int tmp; /* scratch int: section 0x44's data base, a group's offset and end flag in the group loop */
    char *p;
    float *start;

    if (!reload) {
        func_003A26F0(heap, D_00160C40.i79C0 + D_00160C40.i79A4, D_00160C40.i79C4);
        D_001D4B54 = heap;
    }
    func_0011F0A0(0);
    func_003A0760(D_001D4B54, hdr);
    func_0011F0A0(0);
    func_0038CB78(D_001A4BE0_00428098, 0, 0x28E0);
    func_0038CB78(D_L01_001E2880, 0, 0x190);
    func_0038CB78(D_L01_001F4740, 0, 0x400);
    func_003C2D88();
    func_0013D3D0(0x4D2);
    if (D_00143950.i0) {
        if (D_001D5308 == 1.0f)
            func_L01_0044DF00(1);
    } else {
        if (D_001D5308 != 1.0f)
            func_L01_0044DF00(0);
    }
    D_L01_001EAA00_00428098.p4 = D_L01_001EAA80;
    D_L01_001EAA00_00428098.p8 = D_L01_001DFBC0;
    D_L01_001EAA00_00428098.iC = 0;
    D_L01_001EAA00_00428098.i10 = 0;
    D_L01_001EAA00_00428098.i14 = 0;
    func_0038CBA0(D_L01_00201D60, 0x1C000);
    func_0038CBA0(D_L01_0021DD60, 0xC0);

    /* section 0: the level header */
    p = (hdr + ((int *)hdr)[(0) / 4]);
    D_L01_001E7580.i23C = *(int *)p;
    p += 4;
    D_L01_001E7580.i240 = *(int *)p;
    p += 4;
    D_L01_001E7580.i244 = *(int *)p;
    p += 4;
    D_L01_001DF9E4 = *(unsigned char *)p;
    p += 4;
    D_L01_001DF9E5 = *(unsigned char *)p;
    p += 4;
    D_L01_001DF9E6 = *(unsigned char *)p;
    p += 4;
    D_L01_001DF9E8 = *(float *)p;
    D_L01_001DF9EC = *(float *)(p + 4);
    D_L01_001DF9F0 = *(float *)(p + 8);
    D_L01_001DF9F4 = *(float *)(p + 0xC);
    D_L01_001DFC30 = *(float *)(p + 0x10);
    D_L01_001D673C = 0;
    p += 0x14;
    if (*(int *)p) {
        D_L01_001D673C = 1;
        D_L01_001DFC50 = *(float *)(p + 4);
        D_L01_001DFC54 = *(float *)(p + 8);
        D_L01_001DFC58 = *(float *)(p + 0xC);
        D_L01_001DFC5C = 1.0f;
    }
    start = (float *)(p + 0x10);
    p += 0x20;
    D_0016C580.i40 = *(int *)p;
    D_0016C580.i44 = *(int *)(p + 4);
    D_0016C580.i48 = *(int *)(p + 8);
    D_L01_001F3F40.count = 0;
    p += 0x10;
    if (*(int *)(p + 0xC)) {
        int i;

        D_L01_001F3F40.count = *(int *)(p + 0xC);
        for (i = 0; i < D_L01_001F3F40.count; i++) {
            float *e = (float *)((char *)&D_L01_001F3F40 + (i << 4));

            e[8] = *(float *)p;
            e[9] = *(float *)(p + 4);
            e[10] = *(float *)(p + 8);
            e[16] = *(float *)(p + 0x10);
            e[17] = *(float *)(p + 0x14);
            e[18] = *(float *)(p + 0x18);
            p += 0x20;
        }
    } else {
        p += 0x20;
    }
    D_L01_001D669C = *(int *)p;
    D_L01_001D60EC = *(int *)(p + 4);
    func_003864C0(0);
    D_L01_001E0EC0 = 983040.0f;
    D_L01_001E0DD8 = 500.0f;
    D_L01_001E0F14 = 0x3C0;
    D_L01_001E0050 = 0x3C0;
    D_L01_001E0288 = 0x7D0000;
    func_00392260(D_L01_001E7580.i23C, D_L01_001E7580.i240, D_L01_001E7580.i244);
    func_003A8F90(D_00100AE0);
    func_0038CBA0(D_L01_001F1B40, 0x100);
    func_0038CBA0(D_L01_001F1C40, 0x180);
    func_0038CBA0(D_L01_001F1740, 0x400);

    /* section 4: up to twelve 64-byte records */
    {
        char *s = (hdr + ((int *)hdr)[(4) / 4]);
        int n = *(int *)s;

        s += 0x10;
        if (n >= 12)
            n = 12;
        if (n)
            func_0038CC88(D_L01_001F1740, s, n << 6);
    }

    /* section 0x84 */
    if (((int *)hdr)[0x84 / 4]) {
        char *s = (hdr + ((int *)hdr)[(0x84) / 4]);
        int n = *(int *)s;

        s += 0x10;
        D_L01_001DFE78 = n;
        if (n) {
            char *entries;
            int i;

            func_0038CC88(D_L01_001F0540, s, n << 4);
            entries = D_L01_001F0740;
            func_0038CC88(entries, s + (D_L01_001DFE78 << 4), D_L01_001DFE78 << 7);
            for (i = 0; i < D_L01_001DFE78; i++) {
                char *e = entries + (i << 7);

                if (*(int *)(e + 0x48) < 0)
                    *(int *)(e + 0x48) = 11;
                if (*(int *)(e + 0x4C) < 0)
                    *(int *)(e + 0x4C) = 11;
            }
        }
    } else {
        D_L01_001DFE78 = 0;
    }
    {
        int i;

        for (i = 0; i < D_L01_001E0E94; i++)
            ((Tfrag_5A12B8 *)D_L01_001E0E90)[i].h36 = 0xFFFF;
    }
    {
        int i = 0;

        while (i < D_L01_001E0E94) {
            unsigned short *q = (unsigned short *)0x70003000;
            int k = 0;

            while (k < 0x3FF && i < D_L01_001E0E94) {
                *q++ = i;
                k++;
                i++;
            }
            *q = 0xFFFF;
            func_003D0180((void *)0x70003000);
        }
    }
    D_L01_001EA940.mark4C = heap;

    /* section 0x10: the help text of the current language (D_001A7BB2[2]) */
    if (((int *)hdr)[0x10 / 4]) {
        int lang = D_00143950.lang * 4;
        char *s = hdr + *(int *)(hdr + lang + 0x10);
        int size;
        int i;

        D_L01_002E5F30.count = *(int *)s;
        s += 4;
        size = *(int *)s;
        s += 4;
        D_L01_001DFCC0 = (Text_5A12B8 *)heap;
        size += 3;
        size &= ~3;
        func_0038CC88(heap, s, size);
        for (i = 0; i < D_L01_002E5F30.count; i++) {
            int delta = (int)D_L01_001DFCC0;

            D_L01_001DFCC0[i].offset += delta;
        }
        heap = (char *)(((int)(heap + size) + 0x3F) & 0xFFFFFFC0u);
    }
    D_L01_001EA940.mark50 = heap;

    /* section 0x34: the ties */
    {
        char *s = (hdr + ((int *)hdr)[(0x34) / 4]);
        int n = *(int *)s;
        char *mark;
        int last;
        int i;

        s += 0x10;
        D_L01_001E0EE0 = n;
        if (n >= 0x1000)
            D_L01_001E0EE0 = 0xFFF;
        D_L01_001E0ED4 = (Tie_5A12B8 *)heap;
        D_L01_001E0EE4 = (unsigned short *)D_L01_001EA940.i14;
        heap += D_L01_001E0EE0 << 5;
        D_L01_001E0F0C = 0x10000;
        D_L01_001E0F08 = D_L01_0023E800;
        D_L01_001E0EFC = 0;
        D_L01_001E0F00 = 0;
        D_L01_001E0F04 = 0;
        if (D_L01_001E0EE0)
            func_0038CB78(D_L01_001E0ED4, 0, D_L01_001E0EE0 << 5);
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        D_L01_001E0EDC = (Matrix_5A12B8 *)heap;
        heap += D_L01_001E0EE0 << 6;
        if (D_L01_001E0EE0)
            func_0038CB78(D_L01_001E0EDC, 0, D_L01_001E0EE0 << 6);
        mark = heap;
        last = -1;
        D_L01_001E0ED8 = D_L01_001E0ED4 + D_L01_001E0EE0;
        for (i = 0; i < D_L01_001E0EE0; i++) {
            Tie_5A12B8 *tie = D_L01_001E0ED4 + i;
            Matrix_5A12B8 *m = D_L01_001E0EDC + i;
            int draw;
            int occl;
            float scale;
            float t;
            Vec_5A12B8 *r1;
            Vec_5A12B8 *r2;

            tie->b1D = D_L01_0023C800[*(int *)s];
            if (tie->b1D != last) {
                D_L01_0023C500[tie->b1D]->first = i;
                D_L01_0023C500[tie->b1D]->h3E = 0;
                D_L01_0023C500[tie->b1D]->table = mark;
                last = tie->b1D;
            }
            r1 = &m->row[1];
            r2 = &m->row[2];
            D_L01_0023C500[tie->b1D]->h3E++;
            draw = *(int *)(s + 4) >> 4;
            if (draw >= 0x100)
                draw = 0xFF;
            mark += ((D_L01_0023C500[tie->b1D]->h38 + 3) >> 1) << 2;
            tie->b1C = draw;
            tie->h18 = 0;
            tie->h1A = 0xFFFF;
            tie->h16 = 0;
            tie->h14 = 0xFFFF;
            tie->b1F = 0xFF;
            occl = *(int *)(s + 0xC);
            m->row[0].q = *(TI128__5A12B8 *)(s + 0x10);
            m->row[1].q = *(TI128__5A12B8 *)(s + 0x20);
            m->row[2].q = *(TI128__5A12B8 *)(s + 0x30);
            m->row[3].q = *(TI128__5A12B8 *)(s + 0x40);
            s += 0x50;
            if (m->row[0].f[0] * (m->row[1].f[1] * m->row[2].f[2] - m->row[1].f[2] * m->row[2].f[1])
                + m->row[1].f[0] * (m->row[0].f[2] * m->row[2].f[1] - m->row[0].f[1] * m->row[2].f[2])
                + m->row[2].f[0] * (m->row[0].f[1] * m->row[1].f[2] - m->row[0].f[2] * m->row[1].f[1]) < 0.0f)
                tie->b1E |= 8;
            tie->h10 = occl;
            tie->h12 = i;
            m->row[3].f[3] = D_L01_0023C500[tie->b1D]->f40;
            func_0038D000(tie, &D_L01_0023C500[tie->b1D]->sphere, m);
            scale = func_0038CEA8(&m->row[0]);
            scale = fmax_asm(scale, func_0038CEA8(r1));
            scale = fmax_asm(scale, func_0038CEA8(r2));
            tie->bounds.f[3] = D_L01_0023C500[tie->b1D]->sphere.f[3] * scale;
            func_0038CE50(tie, tie, m->row[3].f[3]);
            vec_add_ba(tie, tie, &m->row[3]);
            (D_L01_001E0EDC + i)->row[0].f[3] = 1.0f / func_0038CEA8(&(D_L01_001E0EDC + i)->row[0]);
            (D_L01_001E0EDC + i)->row[1].f[3] = 1.0f / func_0038CEA8(&(D_L01_001E0EDC + i)->row[1]);
            (D_L01_001E0EDC + i)->row[2].f[3] = 1.0f / func_0038CEA8(&(D_L01_001E0EDC + i)->row[2]);
            tie->h18 = *(unsigned short *)s;
            s += 0x10;
        }
        func_0038CB78(heap, 0, mark - heap);
        heap = (char *)(((int)(mark) + 0x3F) & 0xFFFFFFC0u);
    }

    /* section 0x94: tie groups */
    if (((int *)hdr)[0x94 / 4]) {
        short *s = (short *)(hdr + ((int *)hdr)[(0x94) / 4]);
        int idx = *s++;

        while (idx != -1) {
            if (idx < D_L01_001E0EE0) {
                Tie_5A12B8 *tie = D_L01_001E0ED4 + idx;
                TieClass_5A12B8 *cls = D_L01_0023C500[tie->b1D];
                int n = *s;
                int w = cls->h38 + 3;
                char *dst = cls->table + (((w >> 1) * (idx - cls->first)) << 2);

                if (n == (w & 0xFFFE) || ((w & 0xFFFE) == 0x202 && n == 0x200))
                    func_0038CC88(dst, s + 1, n << 1);
            }
            s += *s + 1;
            idx = *s++;
        }
    }

    /* section 0x38: a relocated pointer table */
    {
        int *s = (int *)(hdr + ((int *)hdr)[(0x38) / 4]);
        int n = *s++;
        int size = *s++;
        int *offs;
        char *base;

        s += 2;
        offs = s;
        D_L01_001D6764 = (int *)heap;
        heap += n << 2;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        s += (n + 3) & ~3;
        base = heap;
        heap += size;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (n) {
            int i;

            for (i = 0; i < n; i++) {
                if (offs[i] != -1) {
                    D_L01_001D6768 = i + 1;
                    D_L01_001D6764[i] = (int)(base + offs[i]);
                } else {
                    D_L01_001D6764[i] = 0;
                }
            }
        }
        if (size)
            func_0038CD28(base, (char *)(((int)s + 0xF) & ~0xF), size);
    }
    D_L01_001EA940.mark54 = heap;

    /* section 0x40: the shrubs */
    {
        char *s = (hdr + ((int *)hdr)[(0x40) / 4]);
        int n = *(int *)s;
        int last;
        int i;
        int j;
        int c;

        D_L01_001E0DC8 = (Shrub_5A12B8 *)heap;
        s += 0x10;
        D_L01_001E0DC4 = n;
        heap += n << 5;
        if (n)
            func_0038CB78(D_L01_001E0DC8, 0, n << 5);
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        D_L01_001E0DD0 = (Matrix_5A12B8 *)heap;
        heap += D_L01_001E0DC4 << 6;
        if (D_L01_001E0DC4)
            func_0038CB78(D_L01_001E0DD0, 0, D_L01_001E0DC4 << 6);
        D_L01_001E0DD4 = (unsigned char *)heap;
        heap += D_L01_001E0DC4 * 0x60;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (D_L01_001E0DC4)
            func_0038CB78(D_L01_001E0DD4, 0, D_L01_001E0DC4 * 0x60);
        last = -1;
        D_L01_001DA510[1] = (int)D_L01_001E0DD4;
        D_L01_001E0DCC = D_L01_001E0DC8 + D_L01_001E0DC4;
        for (i = 0; i < D_L01_001E0DC4; i++) {
            int cls = D_L01_002385F0[*(int *)s];
            Shrub_5A12B8 *shrub = D_L01_001E0DC8 + i;
            Matrix_5A12B8 *m = D_L01_001E0DD0 + i;
            Vec_5A12B8 *r1;
            Vec_5A12B8 *r2;
            float a, b, scale, t;
            int w, h, r, g, bl;

            shrub->b1A = cls;
            if (cls != last) {
                last = cls;
                D_L01_00238470[cls]->first = shrub;
                D_L01_00238470[cls]->h16 = 0;
            }
            D_L01_00238470[cls]->h16++;
            shrub->h18 = i;
            shrub->f10 = *(float *)(s + 4);
            if (shrub->f10 < 16.0f)
                shrub->f10 = 16.0f;
            shrub->b1B = 0;
            shrub->h1E = 0xFFFF;
            if (D_L01_00238470[cls]->p1C) {
                shrub->b17 = *D_L01_00238470[cls]->p1C;
                t = shrub->b17 + 24.0f;
                if (shrub->f10 < t)
                    shrub->f10 = t;
            }
            r1 = &m->row[1];
            r2 = &m->row[2];
            m->row[0].q = *(TI128__5A12B8 *)(s + 0x10);
            m->row[1].q = *(TI128__5A12B8 *)(s + 0x20);
            m->row[2].q = *(TI128__5A12B8 *)(s + 0x30);
            m->row[3].q = *(TI128__5A12B8 *)(s + 0x40);
            m->row[3].f[3] = D_L01_00238470[cls]->f20;
            m->row[2].i[3] = 0;
            s += 0x50;
            if (D_L01_00238470[cls]->p1C && !((int *)D_L01_00238470[cls]->p1C)[7]) {
                a = (func_0038CEA8(&m->row[0]) + func_0038CEA8(r1)) * 0.5f;
                b = func_0038CEA8(r2);
                h = b * 4096.0f;
                w = a * 4096.0f;
                if (h > 0x10000)
                    h = 0x10000;
                if (w > 0x10000)
                    w = 0x10000;
                m->row[2].i[3] = w | (h << 16);
            }
            r = *(int *)s;
            s += 4;
            g = *(int *)s;
            s += 4;
            bl = *(int *)s;
            s += 8;
            g = (g << 8) | 0x80000000;
            m->row[0].i[3] = (bl << 16) | g | r;
            shrub->h1C = *(unsigned short *)s;
            s += 0x10;
            func_0038D000(shrub, D_L01_00238470[cls], m);
            scale = func_0038CEA8(&m->row[0]);
            scale = fmax_asm(scale, func_0038CEA8(r1));
            scale = fmax_asm(scale, func_0038CEA8(r2));
            shrub->bounds.f[3] = D_L01_00238470[cls]->fC * scale;
            func_0038CE50(shrub, shrub, m->row[3].f[3]);
            vec_add_ba(shrub, shrub, &m->row[3]);
        }
        j = 0;
        while (j < D_L01_001E0DC4) {
            unsigned short *q = (unsigned short *)0x70000000;
            int k = 0;

            while (j < D_L01_001E0DC4 && k < 0xFA0) {
                *q++ = j;
                k++;
                j++;
            }
            *q = 0xFFFF;
            func_003E0B10((void *)0x70000000);
        }

        for (c = 0; c < D_L01_001E0DC4; c++) {
            unsigned char *q = D_L01_001E0DD4 + c * 0x60;
            int r = 0;
            int g = 0;
            int b = 0;
            int texels = 24;
            int k;

            for (k = 0; k < texels; k++) {
                r += q[0];
                g += q[1];
                b += q[2];
                q += 4;
            }
            g /= texels;
            b /= texels;
            r /= texels;
            *(int *)((char *)D_L01_001E0DD0 + c * 0x40 + 0x1C) = (b << 16) | (g << 8) | r;
        }
    }

    /* section 0x44: another relocated pointer table */
    {
        int *s = (int *)(hdr + ((int *)hdr)[(0x44) / 4]);
        int n = *s++;
        int size = *s++;
        int *offs;

        s += 2;
        offs = s;
        D_L01_001D676C = (int *)heap;
        heap += n << 2;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        s += n;
        tmp = (int)heap;
        heap += size;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (n) {
            int i;

            for (i = 0; i < n; i++) {
                if (offs[i] != -1) {
                    D_L01_001D6770 = i + 1;
                    D_L01_001D676C[i] = tmp + offs[i];
                } else {
                    D_L01_001D676C[i] = 0;
                }
            }
        }
        if (size)
            func_0038CD28((char *)tmp, (char *)(((int)s + 0xF) & ~0xF), size);
    }

    /* section 8: 32-byte records */
    if (((int *)hdr)[8 / 4]) {
        char *s = (hdr + ((int *)hdr)[(8) / 4]);
        int n = *(int *)s;

        D_L01_001DF804 = (Cam_5A12B8 *)heap;
        s += 0x10;
        D_L01_001DF808 = n;
        heap += n << 5;
        if (n)
            func_0038CB78(D_L01_001DF804, 0, n << 5);
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        {
            int i;

            for (i = 0; i < D_L01_001DF808; i++) {
                Cam_5A12B8 *e = &D_L01_001DF804[i];

                e->iC = *(int *)s;
                s += 4;
                e->f0 = ((float *)s)[0];
                e->f4 = ((float *)s)[1];
                e->f8 = ((float *)s)[2];
                s += 0xC;
                e->f10 = ((float *)s)[0];
                e->f14 = ((float *)s)[1];
                e->f18 = ((float *)s)[2];
                s += 0xC;
                e->i1C = *(int *)s;
                s += 4;
            }
        }
    }

    /* section 0xC: 0x90-byte records */
    if (((int *)hdr)[0xC / 4]) {
        char *s = (hdr + ((int *)hdr)[(0xC) / 4]);
        int n = *(int *)s;

        s += 0x10;
        D_001A30B0.count = n;
        if (n) {
            int size = n * 0x90;
            int i;

            D_001A30B0.table = (Sound_5A12B8 *)heap;
            heap += size;
            heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
            func_0038CB78(D_001A30B0.table, 0, size);
            for (i = 0; i < D_001A30B0.count; i++) {
                Sound_5A12B8 *e = D_001A30B0.table + i;

                func_0038CC88(e, s, 0x90);
                s += 0x90;
                func_L01_004AB070(e);
            }
        } else {
            D_001A30B0.table = 0;
        }
    }

    /* section 0x4C: the mobys */
    D_L01_001EA940.mark58 = heap;
    idx = D_L01_001F4B40;
    {
        char *p = (hdr + ((int *)hdr)[(0x4C) / 4]);
        int n2;
        int count = 0;
        int n;
        char *next;
        int i;

        n = *(int *)p;
        p += 4;
        n2 = *(int *)p;
        p += 0xC;
        D_L01_001E001C = (Moby_5A12B8 *)heap;
        func_0038CB78(heap, 0, (n + n2) << 8);
        func_0038CB78(D_L01_001EFC80, 0, 0xC0);
        func_0038CB78(D_L01_001EFD40, 0, 0xC0);
        for (i = 0; i < n; i++) {
            int cls;
            int w2;
            int flags;
            int uid;
            int bolts;
            int xp;
            int bolts2;
            int xp2;
            int w9;
            char skip = 0;

            next = p + ((*(int *)p >> 2) << 2);
            p += 4;
            cls = *(int *)p;
            p += 4;
            w2 = *(int *)p;
            p += 4;
            flags = *(int *)p;
            p += 4;
            uid = *(int *)p;
            p += 4;
            bolts = *(int *)p;
            p += 4;
            bolts2 = *(int *)p;
            p += 4;
            xp = *(int *)p;
            p += 4;
            xp2 = *(int *)p;
            p += 4;
            w9 = *(int *)p;
            p += 4;
            if (cls >= 0 && w9 > 0) {
                int lvl = (D_001BBC40[cls + D_001D545C * 16] >> (w2 * 2)) & 3;

                if (lvl == 0)
                    lvl = func_L01_00400430(cls);
                if (*(int *)p == 0x1F5 || *(int *)p == 0x200) {
                    skip = w9 < lvl;
                } else if (lvl < w9) {
                    skip = 1;
                    D_L01_001EFC80[cls][w2] += xp;
                    D_L01_001EFD40[cls][w2] += bolts;
                }
            }
            if (!skip && flags) {
                if (D_L01_00237800.x464[uid]) {
                    skip = 1;
                } else if (flags & 3) {
                    if (D_L01_001DFE80[cls] & 0x80) {
                        if (!(flags & 2))
                            goto drop;
                        {
                            int b = D_001BBE90[(uid >> 1) + (D_001D545C << 10)];

                            if (uid & 1)
                                b >>= 4;
                            if (!(b & 8)) {
                                u8 *q = &D_001BBE90[(uid >> 1) + (D_001D545C << 10)];
                                u8 v = (uid & 1) ? (*q | 0x80) : (*q | 0x8);

                                *q = (uid & 1) ? (v & 0x8F) : (v & 0xF8);
                            }
                            bolts = bolts2;
                            xp = xp2;
                        }
                    } else {
                        int t = (flags & 1) == 0;

                        if (t)
                            skip = 1;
                        else
                            skip = 0;
                    }
                } else if (flags & 8) {
                    u8 *q = &D_001BBE90[(uid >> 1) + (D_001D545C << 10)];

                    if (reload) {
                        *q = (uid & 1) ? (*q & 0x8F) : (*q & 0xF8);
                    } else if (uid & 1) {
                        if ((*q >> 4) & 7)
                            goto drop;
                    } else {
                        if (*q & 7)
                            goto drop;
                    }
                } else if ((flags & 0xC) == 4) {
                    u8 *q = &D_001BBE90[(uid >> 1) + (D_001D545C << 10)];

                    if (uid & 1) {
                        if ((*q >> 4) & 7)
                            goto drop;
                    } else {
                        if (*q & 7) {
                        drop:
                            skip = 1;
                        }
                    }
                }
            }
            if (*(int *)p == 0x7D0)
                skip = 1;
            if (skip) {
                idx[i] = -1;
            } else {
                Moby_5A12B8 *m;
                int snap;
                float lift;
                int pv;
                int r;
                int g;
                int b;
                int upd;

                idx[i] = count;
                m = D_L01_001E001C + count;
                func_003C25D8(m, *(int *)p);
                p += 4;
                m->hB2 = uid;
                m->bB0 = cls;
                m->bB1 = w2 & 0xF;
                if (flags == 0)
                    m->bB1 |= 0x80;
                m->hB4 = bolts;
                m->hB6 = xp;
                if (m->pClass)
                    m->f2C = ((MobyClass_5A12B8 *)m->pClass)->f24 * *(float *)p;
                p += 4;
                m->h32 = *(unsigned short *)p;
                p += 4;
                m->b30 = *(unsigned char *)p;
                p += 0xC;
                m->pos.f[0] = ((float *)p)[0];
                m->pos.f[1] = ((float *)p)[1];
                m->pos.f[2] = ((float *)p)[2];
                p += 0xC;
                m->rot[0] = ((float *)p)[0];
                m->rot[1] = ((float *)p)[1];
                m->rot[2] = ((float *)p)[2];
                p += 0xC;
                m->b21 = *(unsigned char *)p;
                p += 4;
                snap = *(int *)p;
                p += 4;
                lift = *(float *)p;
                p += 4;
                if (snap) {
                    float h = func_003C3D30(&m->pos, 0, 0, 0.5f);

                    if (0.0f < h)
                        m->pos.f[2] = h + lift;
                }
                p += 4;
                pv = *(int *)p;
                m->h36 = 0x7F80;
                p += 4;
                m->i68 = pv;
                if (*(int *)p == 0)
                    m->h36 = 0;
                p += 4;
                if (m->pClass)
                    ((MobyClass_5A12B8 *)m->pClass)->h44 |= *(unsigned short *)p;
                m->h34 |= *(unsigned short *)p;
                p += 4;
                if (m->pClass)
                    func_003C7C38(m);
                r = *(int *)p;
                p += 4;
                g = *(int *)p;
                p += 4;
                b = *(int *)p;
                p += 4;
                upd = *(int *)p;
                count++;
                func_003C6F90(m, (b << 16) + (g << 8) + r, 0, 0, 0);
                m->i38 = upd;
                m->b7E &= 0xFE;
                if (D_001D545C >= 0 && *(int *)p != -1)
                    func_L01_004312D8(m, *(int *)p);
            }
            p = next;
        }
        {
            int total = (count + n2) << 8;

            D_L01_001DF94C = D_L01_001E001C + count;
            func_003C25D8(D_L01_001DF94C, 0);
            heap += total;
            D_L01_001DF94C->state = 0xFD;
            D_L01_001E0020 = D_L01_001DF94C + 1;
            D_L01_001E0020->state = 0xFF;
            D_L01_001E0030 = (Moby_5A12B8 *)heap;
            heap += n2 << 8;
            D_L01_001E0034 = n2 << 2;
            D_L01_001E0024 = (Moby_5A12B8 *)((char *)D_L01_001E001C + total - 0x100);
            heap = (char *)func_003C2948(n2, (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u));
            D_L01_001EA940.mark5C = heap;
        }
    }

    /* sections 0x60 / 0x5C: pointed-to blobs copied into the heap */
    if (((int *)hdr)[0x60 / 4]) {
        char *pv = (hdr + ((int *)hdr)[(0x60) / 4]);
        Blob_5A12B8 *tbl = (Blob_5A12B8 *)(hdr + ((int *)hdr)[(0x5C) / 4]);
        int i;
        Moby_5A12B8 *m;

        for (i = 0; i < D_L01_001DF808; i++) {
            int k = D_L01_001DF804[i].i1C;

            if (k < 0) {
                D_L01_001DF804[i].i1C = 0;
            } else {
                int size = tbl[k].size;
                char *src = pv + tbl[k].offset;

                D_L01_001DF804[i].i1C = (int)heap;
                func_0038CD28(heap, src, size);
                tbl[k].offset = (int)heap;
                heap += size;
            }
        }
        for (i = 0; i < D_001A30B0.count; i++) {
            int k = D_001A30B0.table[i].i8;

            if (k < 0) {
                D_001A30B0.table[i].i8 = 0;
            } else {
                int size = tbl[k].size;
                char *src = pv + tbl[k].offset;

                D_001A30B0.table[i].i8 = (int)heap;
                func_0038CD28(heap, src, size);
                tbl[k].offset = (int)heap;
                heap += size;
            }
        }
        for (m = D_L01_001E001C; m != D_L01_001E0020; m++) {
            if (m->oClass == 0) {
                m->i68 = 0;
            } else {
                int k = m->i68;

                if (k < 0) {
                    m->i68 = 0;
                } else {
                    int size = tbl[k].size;
                    char *src = pv + tbl[k].offset;

                    m->i68 = (int)heap;
                    func_0038CD28(heap, src, size);
                    tbl[k].offset = (int)heap;
                    heap += size;
                }
            }
        }
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
    }
    D_L01_001EA940.mark60 = heap;

    /* section 0x58: moby references through the blob directory */
    if (((int *)hdr)[0x58 / 4]) {
        int *q = (int *)(hdr + ((int *)hdr)[(0x58) / 4]);
        Blob_5A12B8 *tbl = (Blob_5A12B8 *)(hdr + ((int *)hdr)[(0x5C) / 4]);

        while (q[0] >= 0) {
            int x = tbl[q[0]].offset;
            int off = q[1];

            if (x >= D_L01_001EA940.i18) {
                int *r = (int *)(x + off);

                if (*r >= 0)
                    *r = idx[*r];
            }
            q += 2;
        }
    }

    /* section 0x64: pointer relocations through the blob directory */
    if (((int *)hdr)[0x64 / 4]) {
        int *q = (int *)(hdr + ((int *)hdr)[(0x64) / 4]);
        Blob_5A12B8 *tbl = (Blob_5A12B8 *)(hdr + ((int *)hdr)[(0x5C) / 4]);

        while (q[0] >= 0) {
            int x = tbl[q[0]].offset;
            int off = q[1];

            if (x >= D_L01_001EA940.i18) {
                int *r = (int *)(x + off);

                *r += x;
            }
            q += 2;
        }
    }

    /* section 0x50: moby groups */
    func_0038CB78(D_L01_0021DE20, 0, 0x440);
    {
    int off = ((int *)hdr)[0x50 / 4];

    D_L01_001E0058 = 0;
    if (off) {
        char *q = hdr + off;
        char *base = heap;
        int *offs;
        int n;
        int size;
        int i;

        n = *(int *)q;
        q += 4;
        size = *(int *)q;
        offs = (int *)(q + 0xC);
        heap += size;
        q = (char *)offs + (n << 2);
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (size)
            func_0038CD28(base, q, size);
        for (i = 0; i < n; i++, offs++) {
            tmp = *offs;
            if (tmp >= 0) {
                int g = (int)(base + tmp);
                unsigned short *src;
                short *dst;

                D_L01_0021DE20[i] = g;
                src = (unsigned short *)g;
                dst = (short *)src;
                D_L01_001E0058 = i + 1;
                do {
                    int id = *src;
                    short t;

                    tmp = *(short *)src;
                    g = (id & 0x7FFF) << 1; /* the entry's slot in the moby index, in two steps */
                    g += (int)idx;
                    tmp &= 0x8000;
                    t = *(short *)g;
                    if (t >= 0)
                        *dst++ = t;
                    if (tmp) {
                        if (D_L01_0021DE20[i] < (int)dst)
                            dst[-1] |= 0x8000;
                        else
                            D_L01_0021DE20[i] = 0;
                        break;
                    }
                    src++;
                } while (!tmp);
            }
        }
    }

    }

    /* section 0x54: blob pointers into a copied pool */
    {
    int off = ((int *)hdr)[0x54 / 4];

    D_L01_001E005C = D_L01_001E0058;
    D_L01_001E0058 += 0x20;
    if (off) {
        char *q = hdr + off;
        char *base = heap;
        Blob_5A12B8 *tbl;
        int size;
        int n;
        int i;

        size = *(int *)q;
        q += 4;
        n = *(int *)q;
        q += 0xC;
        heap += size;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (size)
            func_0038CD28(base, q, size);
        q += size;
        tbl = (Blob_5A12B8 *)(hdr + ((int *)hdr)[(0x5C) / 4]);
        for (i = 0; i < n; i++) {
            int w = *(int *)q;
            int hi = w >> 16;
            int x = tbl[w & 0xFFFF].offset;

            if (x >= D_L01_001EA940.i18)
                *(int *)(x + hi) = (int)(base + *(int *)(q + 4));
            q += 8;
        }
    }

    }

    /* section 0x78: paths */
    if (((int *)hdr)[0x78 / 4]) {
        char *q = (hdr + ((int *)hdr)[(0x78) / 4]);
        char *src;
        int size;
        int i;

        D_L01_001E0134 = *(int *)q;
        src = q + *(int *)(q + 4);
        size = *(int *)(q + 8);
        D_L01_001E0138 = heap;
        heap += size;
        q += 0x10;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (size)
            func_0038CD28(D_L01_001E0138, src, size);
        for (i = 0; i < D_L01_001E0134; i++) {
            Path_5A12B8 *e = (Path_5A12B8 *)(D_L01_001E0138 + *(int *)q);

            D_L01_0021F6C0[i] = (char *)e;
            e->i4 = 0;
            q += 4;
        }
    }

    /* section 0x7C: rails */
    if (((int *)hdr)[0x7C / 4]) {
        char *q = (hdr + ((int *)hdr)[(0x7C) / 4]);
        char *src;
        char *copy;
        int n;
        int size;
        int i;

        n = *(int *)q;
        D_L01_001DFC94 = n;
        src = q + *(int *)(q + 4);
        size = *(int *)(q + 8);
        D_L01_001DFC90 = (Rail_5A12B8 *)heap;
        heap += n << 5;
        q += 0x10;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        for (i = 0; i < D_L01_001DFC94; i++) {
            *(TI128__5A12B8 *)&D_L01_001DFC90[i] = *(TI128__5A12B8 *)q;
            q += 0x10;
            D_L01_001DFC90[i].i14 = *(int *)q;
            q += 0x10;
        }
        copy = heap;
        heap += size;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (size)
            func_0038CD28(copy, src, size);
        for (i = 0; i < D_L01_001DFC94; i++) {
            D_L01_001DFC90[i].data = copy + *(int *)q;
            q += 4;
        }
    }

    /* section 0x74: clip volumes, 0x90-byte records from 0x80-byte sources */
    if (((int *)hdr)[0x74 / 4]) {
        char *q = (hdr + ((int *)hdr)[(0x74) / 4]);
        int n = *(int *)q;
        int i;

        D_L01_001E011C = heap;
        D_L01_001E0120 = n;
        q += 0x10;
        heap += n * 0x90;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (n)
            func_0038CB78(D_L01_001E011C, 0, n * 0x90);
        for (i = 0; i < D_L01_001E0120; i++) {
            func_0038CC88(D_L01_001E011C + i * 0x90, q, 0x90);
            q += 0x80;
        }
    }

    /* sections 0x68, 0x6C, 0x70: cuboids, spheres and cylinders */
    if (((int *)hdr)[0x68 / 4]) {
        char *q = (hdr + ((int *)hdr)[(0x68) / 4]);
        int n = *(int *)q;
        int i;

        D_L01_001E0100 = heap;
        q += 0x10;
        D_L01_001E0104 = n;
        heap += n << 7;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (n)
            func_0038CB78(D_L01_001E0100, 0, n << 7);
        for (i = 0; i < D_L01_001E0104; i++) {
            func_0038CC88(D_L01_001E0100 + (i << 7), q, 0x80);
            q += 0x80;
        }
    }
    if (((int *)hdr)[0x6C / 4]) {
        char *q = (hdr + ((int *)hdr)[(0x6C) / 4]);
        int n = *(int *)q;
        int i;

        D_L01_001E0124 = heap;
        q += 0x10;
        D_L01_001E0128 = n;
        heap += n << 7;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (n)
            func_0038CB78(D_L01_001E0124, 0, n << 7);
        for (i = 0; i < D_L01_001E0128; i++) {
            func_0038CC88(D_L01_001E0124 + (i << 7), q, 0x80);
            q += 0x80;
        }
    }
    if (((int *)hdr)[0x70 / 4]) {
        char *q = (hdr + ((int *)hdr)[(0x70) / 4]);
        int n = *(int *)q;
        int i;

        D_L01_001E0100 = heap;
        q += 0x10;
        D_L01_001E0104 = n;
        heap += n << 7;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (n)
            func_0038CB78(D_L01_001E0100, 0, n << 7);
        for (i = 0; i < D_L01_001E0104; i++) {
            func_0038CC88(D_L01_001E0100 + (i << 7), q, 0x80);
            q += 0x80;
        }
    }

    /* section 0x88 */
    if (((int *)hdr)[0x88 / 4]) {
        char *s = (hdr + ((int *)hdr)[(0x88) / 4]);
        int size = *(int *)s;

        D_L01_001DF840 = heap;
        s += 0x10;
        size += 0x4000;
        heap += size;
        func_0038CC88(D_L01_001DF840, s, size);
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
    }

    /* section 0x80 */
    if (((int *)hdr)[0x80 / 4]) {
        char *s = (hdr + ((int *)hdr)[(0x80) / 4]);
        int n = *(int *)s;

        D_L01_001DFE74 = heap;
        s += 0x10;
        D_L01_001DFE70 = n;
        heap = (char *)(((int)heap + (n << 4) + 0x83F) & 0xFFFFFFC0u);
        if (n)
            func_0038CC88(D_L01_001DFE74, s, (n << 4) + 0x800);
        else
            func_0038CC88(D_L01_001DFE74, s, 0x800);
    }

    /* section 0x8C */
    if (((int *)hdr)[0x8C / 4]) {
        char *s = (hdr + ((int *)hdr)[(0x8C) / 4]);
        int n = *(int *)s;

        D_L01_001E00C0 = heap;
        s += 0x10;
        D_L01_001E00B4 = n;
        heap += n << 5;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (n)
            func_0038CC88(D_L01_001E00C0, s, n << 5);
    }
    D_L01_001E0278 = heap;
    D_L01_001EA940.mark64 = heap;
    heap += 0x20000;
    D_L01_001E0280 = -1;
    D_L01_001E027C = 0;
    D_L01_001E0284 = 0;
    func_0038CBA0(D_L01_00220840, 0x200);
    if (D_001D545C >= 0) {
        D_0016C580.hero = 0;
        if (0.0f < start[0]) {
            int i;
            Moby_5A12B8 *m;

            for (i = 19; i >= 0; i--)
                D_L01_0023AC70[i] = 0;
            m = func_003C24B0(0xD54, 0x80);
            m->pos.f[0] = start[0];
            m->pos.f[1] = start[1];
            m->pos.f[2] = start[2];
            m->rot[2] = start[3];
            m->h32 = 0xFF;
            m->b30 = 0x10;
            m->i64 = (int)func_L01_004AC1C0;
            m->h34 &= ~2;
            if (m->b63)
                m->b63 = 8;
            func_003C7C38(m);
            D_0016C580.hero = m;
            func_L01_004312D8(m, 0);
            ((Moby_5A12B8 *)D_0016C580.hero)->pClass[0xC] = 1;
            if (D_001D545C != 11)
                func_L01_004AC1C0(D_0016C580.hero);
        }
    }

    heap = (char *)(((int)heap + 0xF) & ~0xF);

    /* section 0x98: the group record and its five tables */
    {
        char *s;
        int size;
        int i;

        s = (hdr + ((int *)hdr)[(0x98) / 4]);
        D_L01_001DFC4C = (Groups_5A12B8 *)heap;
        size = *(int *)s;
        heap += size;
        func_0038CC88(D_L01_001DFC4C, s + 4, size);
        if (D_L01_001DFC4C->p4)
            D_L01_001DFC4C->p4 += (int)D_L01_001DFC4C;
        else
            D_L01_001DFC4C->p4 = 0;
        if (D_L01_001DFC4C->p8)
            D_L01_001DFC4C->p8 += (int)D_L01_001DFC4C;
        else
            D_L01_001DFC4C->p8 = 0;
        if (D_L01_001DFC4C->pC)
            D_L01_001DFC4C->pC += (int)D_L01_001DFC4C;
        else
            D_L01_001DFC4C->pC = 0;
        if (D_L01_001DFC4C->p10)
            D_L01_001DFC4C->p10 += (int)D_L01_001DFC4C;
        else
            D_L01_001DFC4C->p10 = 0;
        if (D_L01_001DFC4C->p14)
            D_L01_001DFC4C->p14 += (int)D_L01_001DFC4C;
        else
            D_L01_001DFC4C->p14 = 0;
        for (i = 0; i < D_L01_001DFC4C->count; i++) {
            GroupEntry_5A12B8 *e;

            e = (GroupEntry_5A12B8 *)D_L01_001DFC4C + i;
            if (e[1].h0)
                e[1].iC += (int)D_L01_001DFC4C->p4;
            else
                e[1].iC = 0;
            e = (GroupEntry_5A12B8 *)D_L01_001DFC4C + i;
            if (e[1].h2)
                e[1].i10 += (int)D_L01_001DFC4C->p8;
            else
                e[1].i10 = 0;
            e = (GroupEntry_5A12B8 *)D_L01_001DFC4C + i;
            if (e[1].h4)
                e[1].i14 += (int)D_L01_001DFC4C->pC;
            else
                e[1].i14 = 0;
            e = (GroupEntry_5A12B8 *)D_L01_001DFC4C + i;
            if (e[1].h6)
                e[1].i18 += (int)D_L01_001DFC4C->p10;
            else
                e[1].i18 = 0;
            e = (GroupEntry_5A12B8 *)D_L01_001DFC4C + i;
            if (e[1].h8)
                e[1].i1C += (int)D_L01_001DFC4C->p14;
            else
                e[1].i1C = 0;
        }
        {
            int bytes;

            D_L01_001DFC48 = (int)heap;
            bytes = D_L01_001DFC4C->count * 0xE0;
            heap += bytes;
            func_0038CB78((void *)D_L01_001DFC48, 0, bytes);
        }
    }

    if (D_L01_001DFB80 && ((int *)hdr)[0x90 / 4]) {
        int *q = (int *)(hdr + ((int *)hdr)[(0x90) / 4]);
        int *q0;
        int n1;
        int n2;
        int n3;
        int bad1 = 1;
        int bad2;

        q0 = q;
        n1 = q[0];
        n2 = q[1];
        n3 = q[2];
        q += 4;
        if (D_L01_001F3F40.count) {
            q += n1 * 2;
            if (D_L01_001F3F40.i18 == n1)
                bad1 = 0;
            D_L01_001F3F40.i1C = bad1 == 0;
        } else if (D_L01_001E0E94 == n1) {
            int i;

            bad1 = 0;
            for (i = 0; i < n1; i++) {
                if (((Tfrag_5A12B8 *)D_L01_001E0E90)[i].b3D != q[1])
                    bad1 = 1;
                q += 2;
            }
        } else {
            q += n1 * 2;
        }
        bad2 = 1;
        if (D_L01_001E0ED8 - D_L01_001E0ED4 == n2) {
            int i;

            bad2 = 0;
            for (i = 0; i < n2; i++) {
                int id = (unsigned short)q[1];

                if (D_L01_001E0ED4[i].h10 != id)
                    bad2 = 1;
                q += 2;
            }
        } else {
            q += n2 * 2;
        }
        {
            Moby_5A12B8 *m;
            unsigned short *table;
            int i;

            table = D_L01_001E0EE4 + 0x78000;
            func_0038CB78(table, -1, 0x10000);
            for (i = 0; i < n3; i++) {
                if ((unsigned)(q[i * 2 + 1] + 0x4000) < 0x8000)
                    table[q[i * 2 + 1] + 0x4000] = q[i * 2];
            }
            for (m = D_L01_001E001C; m->state != 0xFF; m++) {
                if (m->h36 != 0x7F80) {
                    if ((unsigned)(m->hB2 + 0x4000) < 0x8000) {
                        short v = table[m->hB2 + 0x4000];

                        if (v < 0)
                            m->h36 = 0x7F80;
                        else
                            m->h36 = ((v >> 3) << 8) | (1 << (v & 7));
                    } else {
                        m->h36 = 0x7F80;
                    }
                }
            }
        }
        if (bad1) {
            if (D_L01_001E0E94 > 0) {
                unsigned short *e = (unsigned short *)(D_L01_001E0E90 + 0x3A);
                int left = D_L01_001E0E94;

                do {
                    *e = 0x7F80;
                    e = (unsigned short *)((char *)e + 0x40);
                } while (--left);
            }
        } else if (D_L01_001F3F40.count) {
            int i;

            q = q0 + 4;
            for (i = 0; i < n1; i++) {
                int w = q[0];

                D_L01_001F3F40.bits[i] = ((w >> 3) << 8) | (1 << (w & 7));
                q += 2;
            }
        } else {
            int i;

            q = q0 + 4;
            for (i = 0; i < n1; i++) {
                int w = q[0];

                ((Tfrag_5A12B8 *)D_L01_001E0E90)[i].h3A = ((w >> 3) << 8) | (1 << (w & 7));
                q += 2;
            }
        }
        if (bad2) {
            Tie_5A12B8 *t;
            unsigned short *table;
            int i;

            table = D_L01_001E0EE4 + 0x78000;
            q = &q0[n1 * 2 + 4];
            func_0038CB78(table, 0xFFFEFFFE, 0x8000);
            for (i = 0; i < n2; i++) {
                if ((unsigned)q[i * 2 + 1] < 0x4000)
                    table[q[i * 2 + 1]] = q[i * 2];
            }
            for (t = D_L01_001E0ED4; t != D_L01_001E0ED8; t++) {
                int id = t->h10;

                if ((unsigned)id < 0x4000) {
                    short v = table[id];

                    if (v < 0)
                        t->h10 = 0x7F80;
                    else
                        t->h10 = ((v >> 3) << 8) | (1 << (v & 7));
                } else {
                    t->h10 = 0x7F80;
                }
            }
        } else {
            int i;

            q = &q0[n1 * 2 + 4];
            for (i = 0; i < n2; i++) {
                int w = q[0];

                D_L01_001E0ED4[i].h10 = ((w >> 3) << 8) | (1 << (w & 7));
                q += 2;
            }
        }
        D_L01_001DFB94 = 2;
    } else {
        Moby_5A12B8 *moby;
        Tie_5A12B8 *tie;

        for (moby = D_L01_001E001C; moby != D_L01_001E0024; moby++)
            moby->h36 = 0x7F80;
        for (tie = D_L01_001E0ED4; tie != D_L01_001E0ED8; tie++)
            tie->h10 = 0x7F80;
        if (D_L01_001E0E94 > 0) {
            unsigned short *e = (unsigned short *)(D_L01_001E0E90 + 0x3A);
            int left = D_L01_001E0E94;

            do {
                *e = 0x7F80;
                e = (unsigned short *)((char *)e + 0x40);
            } while (--left);
        }
        D_L01_001DFB94 = 0;
        D_L01_001F3F40.i1C = 0;
    }
    func_00387EF0();
    func_L01_004DF428();
    func_L01_004DF840();
    func_L01_003F5BE0();
    func_00384D88();
    func_L01_004606A8(0);
    func_L01_004C88C8();
    func_L01_004574E0();
    func_L01_00457528();
    func_L01_00457558();
    func_L01_003158D0();
    func_L01_004126C8();
    D_L01_001E0140 = 0;
    {
        int i;

        for (i = 7; i >= 0; i--)
            D_L01_0021FAB8[i].h0 = 0;
        for (i = 11; i >= 0; i--)
            D_L01_001E2360[i] = 0;
    }
    {
        Moby_5A12B8 *h = D_0016C580.hero;

        D_L01_0021FEB8 = 0;
        D_L01_001D7B94 = 0xE0;
        D_L01_001E0180 = 0;
        D_L01_001E01C0 = 0;
        D_L01_001D7B80 = 0xE0;
        D_L01_001D7B88 = 0xE0;
        D_L01_001D7B8C = 0xE0;
        D_L01_001D7B90 = 0xE0;
        D_L01_001DFB40 = 0;
        D_L01_001DFC34 = 0;
        if (h)
            *(long *)((char *)h + 0x38) = *(long *)(*(char **)(D_001A4BE0_00428098 + 0x25C0) + 0x38);
    }
    func_L01_003F5498(0, 7.0f);
    switch (D_001D545C) {
    case 2:
    case 5:
    case 6:
    case 7:
    case 8:
    case 10:
        D_L01_001DF940 = D_L01_001D6128;
        break;
    default:
        D_L01_001DF940 = D_L01_001D60F8;
        break;
    }
    D_L01_001D6158 = D_L01_001DF940;
    return heap;
}
/* localdecomp:end func_L01_00428098 */

/* func_L39_005A12B8: the level gameplay loader (rac2 func_L00_00300618), levels 39-53. Near miss,
   not linked. Rebuilt section by section from retail (Opus family D, 2026-11-08), starting from the
   Sonnet port of the rac2 C.
   State: 2743 of 2743 instructions, the same opcode at every row; 2729 rows (99.5%) equal with
   registers, 10 hunks left (check.py at level 39).
   Needs, when it lands: `-mvu0-use-vf0-vf2` on the file's flag line (vec_add_ba for the tie and
   shrub bounds), and include/vu0.h's fmax_asm (retail's max.s is never in a delay slot; SN cc1 emits
   max.s only under -ffast-math and then puts it in delay slots). Until then check it with
     tools/check.py THIS.c func_L39_005A12B8 --flags "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as"
   What made the difference (beyond writing rac3's code from retail):
   - the level-load struct D_L39_001F0A00 (also func_L39_005A3D98's, one type for the file when it lands);
   - strict aliasing (gcc 2.95 -O2): stores through struct fields do not reload scalar int globals
     (paths: Path_5A12B8.i4; rails: the TI copy through a cast reloads, the .i14 field store does not);
   - D_L39_00242CC0 (the player count) is declared const: retail hoists the loop bound into a spilled
     pseudo across func_0038CC88, which loop.c only does for an unchanging load;
   - D_L39_002424A8/D8 in .sdata (gcc's one-insn `la`, which reorg cannot put in the switch's slots);
   - the moby skip test as `t = (flags & 1) == 0; if (t) ... else ...` (retail's xori/andi/movz,
     one more insn than the folded forms, which is what gives hdr $s6 over the moby xp pseudo);
   - two block-local `table` pointers in section 0x90 (one variable conflicts with n1).
   Left (10 hunks):
   1. +0x2BC/+0x334/+0x3B0: $s1/$s2 swapped for %hi(D_00100AE0) and %hi(D_L39_002667C0). GCSE (PRE)
      creates their pseudos in hash order, and SN cc1 hashes the symbol name (renaming either one
      flips them), so the address names cannot give retail's order; equal allocation priority.
   2. +0x1140..+0x1194 (shrub colour average): $t4/$t5 swapped for i+1 and the D_L39_0024C900 load.
   3. +0x143C: `count = 0`'s spill store is scheduled before `lw 0x4C(hdr)` instead of after it.
   4. +0x2A0C: the D_L39_00243208 = 0xE0 store comes first instead of fifth (no source position tried
      moves it).
   The 0.911 member func_L01_00428098 is another contributor's claim (issue #3); not used.
*/
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
extern int *D_L39_002429E4;
extern int D_L39_002429E8;
extern int *D_L39_002429EC;
extern int D_L39_002429F0;
extern int D_L39_0024BC48;
extern struct Groups_5A12B8 *D_L39_0024BC4C;
extern char *D_L39_0024C01C;   /* clip volumes, 0x90 bytes each */
extern int D_L39_0024C020;
extern char *D_L39_0024C000;   /* cuboids */
extern int D_L39_0024C004;
extern char *D_L39_0024C024;   /* spheres */
extern int D_L39_0024C028;
extern char *D_L39_0024C02C;   /* cylinders */
extern int D_L39_0024C030;
extern int D_L39_0024C034;     /* path count */
extern char *D_L39_0024C038;   /* path data */
typedef struct { int i0; int i4; } Path_5A12B8;
typedef struct { Vec_5A12B8 head; char *data; int i14; char pad18[8]; } Rail_5A12B8;   /* 0x20 */
extern Rail_5A12B8 *D_L39_0024BC90;
extern int D_L39_0024BC94;
extern char *D_L39_0024C188;
extern int D_L39_0024C18C;
extern int D_L39_0024C190;
extern int D_L39_0024C194;

extern LoadCtx_5A12B8 D_L39_0025F680;
extern Boot_5A12B8 D_L39_001F0A00;
extern char *D_L39_00240294;
extern char D_L39_0024DCC0[];
extern char D_L39_00268F00[];
typedef struct { int i0; char pad04[0xB3]; unsigned char lang; } Opt_005A12B8;
extern Opt_005A12B8 D_001A5810;
extern float D_L39_00241180;
extern Coll_5A12B8 D_L39_0025F740;
extern char D_L39_0025F7C0[];
extern char D_L39_0024BBC0[];
extern char D_L39_00276720[];
extern char D_L39_00292720[];
extern Cfg_5A12B8 D_L39_0025D6C0;
extern unsigned char D_L39_0024BA64;
extern unsigned char D_L39_0024BA65;
extern unsigned char D_L39_0024BA66;
extern float D_L39_0024BA68;
extern float D_L39_0024BA6C;
extern float D_L39_0024BA70;
extern float D_L39_0024BA74;
extern int D_L39_002429BC;
extern float D_L39_0024BC30;
extern float D_L39_0024BC50;
extern float D_L39_0024BC54;
extern float D_L39_0024BC58;
extern float D_L39_0024BC5C;
extern Sel_5A12B8 D_L39_001FC340;
extern Tutorial_5A12B8 D_L39_00268BC0;
extern int D_L39_00242918;
extern int D_L39_0024CA34;
extern float D_L39_0024C9D0;
extern float D_L39_0024C908;
extern int D_L39_0024BF90;
extern int D_L39_0024C198;
extern char D_00100AE0[];
extern char D_L39_002667C0[];
extern char D_L39_002668C0[];
extern char D_L39_002663C0[];
extern int D_L39_0024BDD8;
extern char D_L39_002651C0[];
extern char D_L39_002653C0[];
extern int D_L39_0024C9A4;
typedef struct { char pad00[0x36]; unsigned short h36; char pad38[2]; unsigned short h3A; char pad3C; unsigned char b3D; char pad3E[2]; } Tfrag_5A12B8;   /* 0x40 */
extern char *D_L39_0024C9A0;
typedef struct { char pad00[0x2C]; int count; } TextHdr_5A12B8;
extern TextHdr_5A12B8 D_L39_004989E0;
extern unsigned char D_001A7BB2[]; /* option bytes; [2] is the language */
typedef struct { int offset; int pad4[3]; } Text_5A12B8;
extern Text_5A12B8 *D_L39_0024BCC0;
extern int D_L39_0024C9F0;
extern Tie_5A12B8 *D_L39_0024C9E4;
extern Tie_5A12B8 *D_L39_0024C9E8;
extern Matrix_5A12B8 *D_L39_0024C9EC;
extern int D_L39_0024CA20;
extern const int D_L39_00242CC0;
extern char *D_L39_0024CA58[];
extern Tie_5A12B8 *D_L39_0024CA38[];
extern Tie_5A12B8 *D_L39_0024CA48[];
extern char *D_L39_0024CA98[];
extern int D_L39_0024CA68[];
extern int D_L39_0024CA78[];
extern int D_L39_0024CA88[];
extern char *D_L39_0024CA1C;
extern char D_L39_002BC740[];
extern int D_L39_0024CA10;
extern int D_L39_0024CA14;
extern int D_L39_0024CA18;
extern TieClass_5A12B8 *D_L39_002BA440[];
extern unsigned char D_L39_002BA740[];
extern Shrub_5A12B8 *D_L39_0024C8F8;
extern int D_L39_0024C8F4;
extern Matrix_5A12B8 *D_L39_0024C900;
extern unsigned char *D_L39_0024C904;
extern Shrub_5A12B8 *D_L39_0024C8FC;
extern int D_L39_00244810[];
extern ShrubClass_5A12B8 *D_L39_002B6A20[];
extern unsigned char D_L39_002B6BA0[];
typedef struct { float f0, f4, f8; int iC; float f10, f14, f18; int i1C; } Cam_5A12B8;
extern Cam_5A12B8 *D_L39_0024B850;
extern int D_L39_0024B854;
extern Slots_5A12B8 D_L39_001FE020;
extern int D_L39_002649C0[][3];
extern int D_L39_00264A80[][3];
extern Moby_5A12B8 *D_L39_0024BF5C;
extern Moby_5A12B8 *D_L39_0024BF60;
extern Moby_5A12B8 *D_L39_0024BF70;
extern Moby_5A12B8 *D_L39_0024BF64;
extern int D_L39_0024BF74;
extern int func_003C2948(int, char *);
extern short D_L39_00269500[];
extern int D_L39_002412DC;
extern int D_L39_002927E0[];
extern int D_L39_0024BF98;
extern int D_L39_0024BF9C;
extern char *D_L39_00293B40[];
extern char *D_L39_0024B8C0;
extern char *D_L39_0024BDD4;
extern int D_L39_0024BDD0;
extern char *D_L39_0024BFC0;
extern int D_L39_0024BFAC;
extern char D_L39_00295FC0[];
extern int D_L39_0024BB80;
extern unsigned short *D_L39_0024C9F4;
extern int D_L39_0024BB94;
extern short D_L39_0024C040;
extern short D_L39_00294338[];
extern short D_L39_0024C080;
extern short D_L39_0024C0C0;
typedef struct { short h0; char pad02[0x7E]; } Bank_5A12B8;
extern Bank_5A12B8 D_L39_00293F38[];
extern int D_L39_0024112C;
extern int D_L39_0024BC34;
extern int D_L39_002431F8;
extern int D_L39_00243200;
extern int D_L39_00243204;
extern int D_L39_00243208;
extern int D_L39_0024320C;
extern char D_L39_002424D8[] __attribute__((section(".sdata")));
extern char D_L39_002424A8[] __attribute__((section(".sdata")));
extern char *D_L39_0024B9C0;
extern char *D_L39_00242508;

extern int func_003A26F0(void *, int, int);
extern void func_001264E0(int);
extern void func_003A0760(void *, void *);
extern void func_0038CB78(void *, int, int);
extern void func_003C2D88(void);
extern void func_L39_005BA0F8(int);
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
extern void func_L39_0057B610(void);
extern void func_L39_0057B1C0(void);
extern void func_L01_004606A8(int);
extern void func_L39_005FF5E8(void);
extern void func_L01_004574E0(void);
extern void func_L01_004126C8(void);
extern void func_L01_003F5498(int, float);

char *func_L39_005A12B8(int reload)
{
    char *hdr = D_L39_0025F680.data;
    char *heap = D_L39_0025F680.heap;
    short *idx = D_L39_00269500; /* moby index by file order, rebuilt at each use */
    int tmp; /* scratch int: section 0x44's data base, a group's offset and end flag in the group loop */
    char *p;

    if (!reload) {
        func_003A26F0(heap, D_L39_001F0A00.i79C0 + D_L39_001F0A00.i79A4, D_L39_001F0A00.i79C4);
        D_L39_00240294 = heap;
    }
    func_001264E0(0);
    func_003A0760(D_L39_00240294, hdr);
    func_001264E0(0);
    func_0038CB78(D_L39_0024DCC0, 0, 0x190);
    func_0038CB78(D_L39_00268F00, 0, 0x600);
    func_003C2D88();
    if (D_001A5810.i0) {
        if (D_L39_00241180 == 1.0f)
            func_L39_005BA0F8(1);
    } else {
        if (D_L39_00241180 != 1.0f)
            func_L39_005BA0F8(0);
    }
    D_L39_0025F740.p4 = D_L39_0025F7C0;
    D_L39_0025F740.p8 = D_L39_0024BBC0;
    D_L39_0025F740.iC = 0;
    D_L39_0025F740.i10 = 0;
    D_L39_0025F740.i14 = 0;
    func_0038CBA0(D_L39_00276720, 0x1C000);
    func_0038CBA0(D_L39_00292720, 0xC0);

    /* section 0: the level header */
    p = (hdr + ((int *)hdr)[(0) / 4]);
    D_L39_0025D6C0.i23C = *(int *)p;
    p += 4;
    D_L39_0025D6C0.i240 = *(int *)p;
    p += 4;
    D_L39_0025D6C0.i244 = *(int *)p;
    p += 4;
    D_L39_0024BA64 = *(unsigned char *)p;
    p += 4;
    D_L39_0024BA65 = *(unsigned char *)p;
    p += 4;
    D_L39_0024BA66 = *(unsigned char *)p;
    p += 4;
    D_L39_0024BA68 = *(float *)p;
    D_L39_0024BA6C = *(float *)(p + 4);
    D_L39_0024BA70 = *(float *)(p + 8);
    D_L39_0024BA74 = *(float *)(p + 0xC);
    D_L39_0024BC30 = *(float *)(p + 0x10);
    D_L39_002429BC = 0;
    p += 0x14;
    if (*(int *)p) {
        D_L39_002429BC = 1;
        D_L39_0024BC50 = *(float *)(p + 4);
        D_L39_0024BC54 = *(float *)(p + 8);
        D_L39_0024BC58 = *(float *)(p + 0xC);
        D_L39_0024BC5C = 1.0f;
    }
    p += 0x20;
    D_L39_001FC340.i40 = *(int *)p;
    D_L39_001FC340.i44 = *(int *)(p + 4);
    D_L39_001FC340.i48 = *(int *)(p + 8);
    D_L39_00268BC0.count = 0;
    p += 0x10;
    if (*(int *)(p + 0xC)) {
        int i;

        D_L39_00268BC0.count = *(int *)(p + 0xC);
        for (i = 0; i < D_L39_00268BC0.count; i++) {
            float *e = (float *)((char *)&D_L39_00268BC0 + (i << 4));

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
    D_L39_00242918 = *(int *)p;
    func_003864C0(0);
    D_L39_0024C9D0 = 983040.0f;
    D_L39_0024C908 = 500.0f;
    D_L39_0024CA34 = 0x3C0;
    D_L39_0024BF90 = 0x3C0;
    D_L39_0024C198 = 0x7D0000;
    func_00392260(D_L39_0025D6C0.i23C, D_L39_0025D6C0.i240, D_L39_0025D6C0.i244);
    func_003A8F90(D_00100AE0);
    func_0038CBA0(D_L39_002667C0, 0x100);
    func_0038CBA0(D_L39_002668C0, 0x180);
    func_0038CBA0(D_L39_002663C0, 0x400);

    /* section 4: up to twelve 64-byte records */
    {
        char *s = (hdr + ((int *)hdr)[(4) / 4]);
        int n = *(int *)s;

        s += 0x10;
        if (n >= 12)
            n = 12;
        if (n)
            func_0038CC88(D_L39_002663C0, s, n << 6);
    }

    /* section 0x84 */
    if (((int *)hdr)[0x84 / 4]) {
        char *s = (hdr + ((int *)hdr)[(0x84) / 4]);
        int n = *(int *)s;

        s += 0x10;
        D_L39_0024BDD8 = n;
        if (n) {
            char *entries;

            func_0038CC88(D_L39_002651C0, s, n << 4);
            entries = D_L39_002653C0;
            func_0038CC88(entries, s + (D_L39_0024BDD8 << 4), D_L39_0024BDD8 << 7);
            if (D_L39_0024BDD8 > 0) {
                char *e = entries;
                int left = D_L39_0024BDD8;

                do {
                    if (*(int *)(e + 0x48) < 0)
                        *(int *)(e + 0x48) = 11;
                    if (*(int *)(e + 0x4C) < 0)
                        *(int *)(e + 0x4C) = 11;
                    e += 0x80;
                } while (--left);
            }
        }
    } else {
        D_L39_0024BDD8 = 0;
    }
    if (D_L39_0024C9A4 > 0) {
        char *e = D_L39_0024C9A0 + 0x36;
        int left = D_L39_0024C9A4;

        do {
            *(unsigned short *)e = 0xFFFF;
            e += 0x40;
        } while (--left);
    }
    {
        int i = 0;

        while (i < D_L39_0024C9A4) {
            unsigned short *q = (unsigned short *)0x70003000;
            int k = 0;

            while (k < 0x3FF && i < D_L39_0024C9A4) {
                *q++ = i;
                k++;
                i++;
            }
            *q = 0xFFFF;
            func_003D0180((void *)0x70003000);
        }
    }
    D_L39_0025F680.mark4C = heap;

    /* section 0x10: the help text of the current language (D_001A7BB2[2]) */
    if (((int *)hdr)[0x10 / 4]) {
        int lang = D_001A5810.lang * 4;
        char *s = hdr + *(int *)(hdr + lang + 0x10);
        int size;
        int i;

        D_L39_004989E0.count = *(int *)s;
        s += 4;
        size = *(int *)s;
        s += 4;
        D_L39_0024BCC0 = (Text_5A12B8 *)heap;
        size += 3;
        size &= ~3;
        func_0038CC88(heap, s, size);
        for (i = 0; i < D_L39_004989E0.count; i++) {
            int delta = (int)D_L39_0024BCC0;

            D_L39_0024BCC0[i].offset += delta;
        }
        heap = (char *)(((int)(heap + size) + 0x3F) & 0xFFFFFFC0u);
    }
    D_L39_0025F680.mark50 = heap;

    /* section 0x34: the ties */
    {
        char *s = (hdr + ((int *)hdr)[(0x34) / 4]);
        int n = *(int *)s;
        char *mark;
        int last;
        int i;

        s += 0x10;
        D_L39_0024C9F0 = n;
        if (n >= 0x1000)
            D_L39_0024C9F0 = 0xFFF;
        D_L39_0024C9E4 = (Tie_5A12B8 *)heap;
        D_L39_0024C9F4 = (unsigned short *)D_L39_0025F680.i14;
        heap += D_L39_0024C9F0 << 5;
        D_L39_0024CA20 = 0x10000;
        D_L39_0024CA1C = D_L39_002BC740;
        D_L39_0024CA10 = 0;
        D_L39_0024CA14 = 0;
        D_L39_0024CA18 = 0;
        if (D_L39_0024C9F0)
            func_0038CB78(D_L39_0024C9E4, 0, D_L39_0024C9F0 << 5);
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        D_L39_0024C9EC = (Matrix_5A12B8 *)heap;
        heap += D_L39_0024C9F0 << 6;
        if (D_L39_0024C9F0)
            func_0038CB78(D_L39_0024C9EC, 0, D_L39_0024C9F0 << 6);
        mark = heap;
        last = -1;
        D_L39_0024C9E8 = D_L39_0024C9E4 + D_L39_0024C9F0;
        for (i = 0; i < D_L39_0024C9F0; i++) {
            Tie_5A12B8 *tie = D_L39_0024C9E4 + i;
            Matrix_5A12B8 *m = D_L39_0024C9EC + i;
            int draw;
            int occl;
            float scale;
            float t;
            Vec_5A12B8 *r1;
            Vec_5A12B8 *r2;

            tie->b1D = D_L39_002BA740[*(int *)s];
            if (tie->b1D != last) {
                D_L39_002BA440[tie->b1D]->first = i;
                D_L39_002BA440[tie->b1D]->h3E = 0;
                D_L39_002BA440[tie->b1D]->table = mark;
                last = tie->b1D;
            }
            r1 = &m->row[1];
            r2 = &m->row[2];
            D_L39_002BA440[tie->b1D]->h3E++;
            draw = *(int *)(s + 4) >> 4;
            if (draw >= 0x100)
                draw = 0xFF;
            mark += ((D_L39_002BA440[tie->b1D]->h38 + 3) >> 1) << 2;
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
            m->row[3].f[3] = D_L39_002BA440[tie->b1D]->f40;
            func_0038D000(tie, &D_L39_002BA440[tie->b1D]->sphere, m);
            scale = func_0038CEA8(&m->row[0]);
            scale = fmax_asm(scale, func_0038CEA8(r1));
            scale = fmax_asm(scale, func_0038CEA8(r2));
            tie->bounds.f[3] = D_L39_002BA440[tie->b1D]->sphere.f[3] * scale;
            func_0038CE50(tie, tie, m->row[3].f[3]);
            vec_add_ba(tie, tie, &m->row[3]);
            (D_L39_0024C9EC + i)->row[0].f[3] = 1.0f / func_0038CEA8(&(D_L39_0024C9EC + i)->row[0]);
            (D_L39_0024C9EC + i)->row[1].f[3] = 1.0f / func_0038CEA8(&(D_L39_0024C9EC + i)->row[1]);
            (D_L39_0024C9EC + i)->row[2].f[3] = 1.0f / func_0038CEA8(&(D_L39_0024C9EC + i)->row[2]);
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
            if (idx < D_L39_0024C9F0) {
                Tie_5A12B8 *tie = D_L39_0024C9E4 + idx;
                TieClass_5A12B8 *cls = D_L39_002BA440[tie->b1D];
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
        D_L39_002429E4 = (int *)heap;
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
                    D_L39_002429E8 = i + 1;
                    D_L39_002429E4[i] = (int)(base + offs[i]);
                } else {
                    D_L39_002429E4[i] = 0;
                }
            }
        }
        if (size)
            func_0038CD28(base, (char *)(((int)s + 0xF) & ~0xF), size);
    }
    if (D_L39_00242CC0 >= 2) {
        int i;

        D_L39_0024CA58[2] = heap;
        heap += 0x80000;
        D_L39_0024CA58[3] = heap;
        heap += 0x80000;
        for (i = 0; i < D_L39_00242CC0; i++) {
            if (i == 0) {
                D_L39_0024CA38[0] = D_L39_0024C9E4;
                D_L39_0024CA48[0] = D_L39_0024C9E8;
                D_L39_0024CA98[0] = D_L39_0024CA1C;
            } else {
                D_L39_0024CA38[i] = (Tie_5A12B8 *)heap;
                heap += D_L39_0024C9F0 << 5;
                heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
                if (D_L39_0024C9F0)
                    func_0038CC88(D_L39_0024CA38[i], D_L39_0024C9E4, D_L39_0024C9F0 << 5);
                D_L39_0024CA48[i] = D_L39_0024CA38[i] + D_L39_0024C9F0;
                D_L39_0024CA98[i] = heap;
                heap += 0x2000;
            }
            D_L39_0024CA68[i] = D_L39_0024CA10;
            D_L39_0024CA78[i] = D_L39_0024CA14;
            D_L39_0024CA88[i] = D_L39_0024CA18;
        }
    }
    D_L39_0025F680.mark54 = heap;

    /* section 0x40: the shrubs */
    {
        char *s = (hdr + ((int *)hdr)[(0x40) / 4]);
        int n = *(int *)s;
        int last;
        int i;

        D_L39_0024C8F8 = (Shrub_5A12B8 *)heap;
        s += 0x10;
        D_L39_0024C8F4 = n;
        heap += n << 5;
        if (n)
            func_0038CB78(D_L39_0024C8F8, 0, n << 5);
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        D_L39_0024C900 = (Matrix_5A12B8 *)heap;
        heap += D_L39_0024C8F4 << 6;
        if (D_L39_0024C8F4)
            func_0038CB78(D_L39_0024C900, 0, D_L39_0024C8F4 << 6);
        D_L39_0024C904 = (unsigned char *)heap;
        heap += D_L39_0024C8F4 * 0x60;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (D_L39_0024C8F4)
            func_0038CB78(D_L39_0024C904, 0, D_L39_0024C8F4 * 0x60);
        last = -1;
        D_L39_00244810[1] = (int)D_L39_0024C904;
        D_L39_0024C8FC = D_L39_0024C8F8 + D_L39_0024C8F4;
        for (i = 0; i < D_L39_0024C8F4; i++) {
            int cls = D_L39_002B6BA0[*(int *)s];
            Shrub_5A12B8 *shrub = D_L39_0024C8F8 + i;
            Matrix_5A12B8 *m = D_L39_0024C900 + i;
            Vec_5A12B8 *r1;
            Vec_5A12B8 *r2;
            float a, b, scale, t;
            int w, h, r, g, bl;

            shrub->b1A = cls;
            if (cls != last) {
                last = cls;
                D_L39_002B6A20[cls]->first = shrub;
                D_L39_002B6A20[cls]->h16 = 0;
            }
            D_L39_002B6A20[cls]->h16++;
            shrub->h18 = i;
            shrub->f10 = *(float *)(s + 4);
            if (shrub->f10 < 16.0f)
                shrub->f10 = 16.0f;
            shrub->b1B = 0;
            shrub->h1E = 0xFFFF;
            if (D_L39_002B6A20[cls]->p1C) {
                shrub->b17 = *D_L39_002B6A20[cls]->p1C;
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
            m->row[3].f[3] = D_L39_002B6A20[cls]->f20;
            m->row[2].i[3] = 0;
            s += 0x50;
            if (D_L39_002B6A20[cls]->p1C && !((int *)D_L39_002B6A20[cls]->p1C)[7]) {
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
            func_0038D000(shrub, D_L39_002B6A20[cls], m);
            scale = func_0038CEA8(&m->row[0]);
            scale = fmax_asm(scale, func_0038CEA8(r1));
            scale = fmax_asm(scale, func_0038CEA8(r2));
            shrub->bounds.f[3] = D_L39_002B6A20[cls]->fC * scale;
            func_0038CE50(shrub, shrub, m->row[3].f[3]);
            vec_add_ba(shrub, shrub, &m->row[3]);
        }
    }
    {
        int i = 0;

        while (i < D_L39_0024C8F4) {
            unsigned short *q = (unsigned short *)0x70000000;
            int k = 0;

            while (i < D_L39_0024C8F4 && k < 0xFA0) {
                *q++ = i;
                k++;
                i++;
            }
            *q = 0xFFFF;
            func_003E0B10((void *)0x70000000);
        }
    }
    {
        int i;

        for (i = 0; i < D_L39_0024C8F4; i++) {
            unsigned char *q = D_L39_0024C904 + i * 0x60;
            int r = 0;
            int g = 0;
            int b = 0;
            int n = 24;
            int j;

            for (j = 0; j < n; j++) {
                r += q[0];
                g += q[1];
                b += q[2];
                q += 4;
            }
            g /= n;
            b /= n;
            r /= n;
            *(int *)((char *)D_L39_0024C900 + i * 0x40 + 0x1C) = (b << 16) | (g << 8) | r;
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
        D_L39_002429EC = (int *)heap;
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
                    D_L39_002429F0 = i + 1;
                    D_L39_002429EC[i] = tmp + offs[i];
                } else {
                    D_L39_002429EC[i] = 0;
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

        D_L39_0024B850 = (Cam_5A12B8 *)heap;
        s += 0x10;
        D_L39_0024B854 = n;
        heap += n << 5;
        if (n)
            func_0038CB78(D_L39_0024B850, 0, n << 5);
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        {
            int i;

            for (i = 0; i < D_L39_0024B854; i++) {
                Cam_5A12B8 *e = &D_L39_0024B850[i];

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
        D_L39_001FE020.count = n;
        if (n) {
            int size = n * 0x90;
            int i;

            D_L39_001FE020.table = (Sound_5A12B8 *)heap;
            heap += size;
            heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
            func_0038CB78(D_L39_001FE020.table, 0, size);
            for (i = 0; i < D_L39_001FE020.count; i++) {
                Sound_5A12B8 *e = D_L39_001FE020.table + i;

                func_0038CC88(e, s, 0x90);
                s += 0x90;
                func_L01_004AB070(e);
            }
        } else {
            D_L39_001FE020.table = 0;
        }
    }

    /* section 0x4C: the mobys */
    D_L39_0025F680.mark58 = heap;
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
        D_L39_0024BF5C = (Moby_5A12B8 *)heap;
        func_0038CB78(heap, 0, (n + n2) << 8);
        func_0038CB78(D_L39_002649C0, 0, 0xC0);
        func_0038CB78(D_L39_00264A80, 0, 0xC0);
        for (i = 0; i < n; i++) {
            int cls;
            int w2;
            int flags;
            int uid;
            int bolts;
            int xp;
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
            p += 8;
            xp = *(int *)p;
            p += 8;
            w9 = *(int *)p;
            p += 4;
            if (cls >= 0 && w9 > 0 && *(int *)p != 0x1F5 && *(int *)p != 0x200) {
                D_L39_002649C0[cls][w2] += xp;
                D_L39_00264A80[cls][w2] += bolts;
                skip = 1;
            }
            if (!skip && flags && (flags & 3)) {
                int t = (flags & 1) == 0;

                if (t)
                    skip = 1;
                else
                    skip = 0;
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
                m = D_L39_0024BF5C + count;
                func_003C25D8(m, *(int *)p);
                p += 4;
                if (m->oClass == 0) {
                    m->h32 = 0;
                    m->b30 = 0;
                    m->h34 |= 0x41;
                }
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
            }
            p = next;
        }
        {
            int total = (count + n2) << 8;

            D_L39_0024BF60 = D_L39_0024BF5C + count;
            D_L39_0024BF60->state = 0xFF;
            heap += total;
            D_L39_0024BF70 = (Moby_5A12B8 *)heap;
            heap += n2 << 8;
            D_L39_0024BF64 = (Moby_5A12B8 *)((char *)D_L39_0024BF5C + total - 0x100);
            D_L39_0024BF74 = n2 << 2;
            heap = (char *)func_003C2948(n2, (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u));
            D_L39_0025F680.mark5C = heap;
        }
    }

    /* sections 0x60 / 0x5C: pointed-to blobs copied into the heap */
    if (((int *)hdr)[0x60 / 4]) {
        char *pv = (hdr + ((int *)hdr)[(0x60) / 4]);
        Blob_5A12B8 *tbl = (Blob_5A12B8 *)(hdr + ((int *)hdr)[(0x5C) / 4]);
        int i;
        Moby_5A12B8 *m;

        for (i = 0; i < D_L39_0024B854; i++) {
            int k = D_L39_0024B850[i].i1C;

            if (k < 0) {
                D_L39_0024B850[i].i1C = 0;
            } else {
                int size = tbl[k].size;
                char *src = pv + tbl[k].offset;

                D_L39_0024B850[i].i1C = (int)heap;
                func_0038CD28(heap, src, size);
                tbl[k].offset = (int)heap;
                heap += size;
            }
        }
        for (i = 0; i < D_L39_001FE020.count; i++) {
            int k = D_L39_001FE020.table[i].i8;

            if (k < 0) {
                D_L39_001FE020.table[i].i8 = 0;
            } else {
                int size = tbl[k].size;
                char *src = pv + tbl[k].offset;

                D_L39_001FE020.table[i].i8 = (int)heap;
                func_0038CD28(heap, src, size);
                tbl[k].offset = (int)heap;
                heap += size;
            }
        }
        for (m = D_L39_0024BF5C; m != D_L39_0024BF60; m++) {
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
    D_L39_0025F680.mark60 = heap;

    /* section 0x58: moby references through the blob directory */
    if (((int *)hdr)[0x58 / 4]) {
        int *q = (int *)(hdr + ((int *)hdr)[(0x58) / 4]);
        Blob_5A12B8 *tbl = (Blob_5A12B8 *)(hdr + ((int *)hdr)[(0x5C) / 4]);

        while (q[0] >= 0) {
            int x = tbl[q[0]].offset;
            int off = q[1];

            if (x >= D_L39_0025F680.i18) {
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

            if (x >= D_L39_0025F680.i18) {
                int *r = (int *)(x + off);

                *r += x;
            }
            q += 2;
        }
    }

    /* section 0x50: moby groups */
    func_0038CB78(D_L39_002927E0, 0, 0x440);
    {
    int off = ((int *)hdr)[0x50 / 4];

    D_L39_0024BF98 = 0;
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

                D_L39_002927E0[i] = g;
                src = (unsigned short *)g;
                dst = (short *)src;
                D_L39_0024BF98 = i + 1;
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
                        if (D_L39_002927E0[i] < (int)dst)
                            dst[-1] |= 0x8000;
                        else
                            D_L39_002927E0[i] = 0;
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

    D_L39_0024BF9C = D_L39_0024BF98;
    D_L39_0024BF98 += 0x20;
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

            if (x >= D_L39_0025F680.i18)
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

        D_L39_0024C034 = *(int *)q;
        src = q + *(int *)(q + 4);
        size = *(int *)(q + 8);
        D_L39_0024C038 = heap;
        heap += size;
        q += 0x10;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (size)
            func_0038CD28(D_L39_0024C038, src, size);
        for (i = 0; i < D_L39_0024C034; i++) {
            Path_5A12B8 *e = (Path_5A12B8 *)(D_L39_0024C038 + *(int *)q);

            D_L39_00293B40[i] = (char *)e;
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
        D_L39_0024BC94 = n;
        src = q + *(int *)(q + 4);
        size = *(int *)(q + 8);
        D_L39_0024BC90 = (Rail_5A12B8 *)heap;
        heap += n << 5;
        q += 0x10;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        for (i = 0; i < D_L39_0024BC94; i++) {
            *(TI128__5A12B8 *)&D_L39_0024BC90[i] = *(TI128__5A12B8 *)q;
            q += 0x10;
            D_L39_0024BC90[i].i14 = *(int *)q;
            q += 0x10;
        }
        copy = heap;
        heap += size;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (size)
            func_0038CD28(copy, src, size);
        for (i = 0; i < D_L39_0024BC94; i++) {
            D_L39_0024BC90[i].data = copy + *(int *)q;
            q += 4;
        }
    }

    /* section 0x74: clip volumes, 0x90-byte records from 0x80-byte sources */
    if (((int *)hdr)[0x74 / 4]) {
        char *q = (hdr + ((int *)hdr)[(0x74) / 4]);
        int n = *(int *)q;
        int i;

        D_L39_0024C01C = heap;
        D_L39_0024C020 = n;
        q += 0x10;
        heap += n * 0x90;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (n)
            func_0038CB78(D_L39_0024C01C, 0, n * 0x90);
        for (i = 0; i < D_L39_0024C020; i++) {
            func_0038CC88(D_L39_0024C01C + i * 0x90, q, 0x90);
            q += 0x80;
        }
    }

    /* sections 0x68, 0x6C, 0x70: cuboids, spheres and cylinders */
    if (((int *)hdr)[0x68 / 4]) {
        char *q = (hdr + ((int *)hdr)[(0x68) / 4]);
        int n = *(int *)q;
        int i;

        D_L39_0024C000 = heap;
        q += 0x10;
        D_L39_0024C004 = n;
        heap += n << 7;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (n)
            func_0038CB78(D_L39_0024C000, 0, n << 7);
        for (i = 0; i < D_L39_0024C004; i++) {
            func_0038CC88(D_L39_0024C000 + (i << 7), q, 0x80);
            q += 0x80;
        }
    }
    if (((int *)hdr)[0x6C / 4]) {
        char *q = (hdr + ((int *)hdr)[(0x6C) / 4]);
        int n = *(int *)q;
        int i;

        D_L39_0024C024 = heap;
        q += 0x10;
        D_L39_0024C028 = n;
        heap += n << 7;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (n)
            func_0038CB78(D_L39_0024C024, 0, n << 7);
        for (i = 0; i < D_L39_0024C028; i++) {
            func_0038CC88(D_L39_0024C024 + (i << 7), q, 0x80);
            q += 0x80;
        }
    }
    if (((int *)hdr)[0x70 / 4]) {
        char *q = (hdr + ((int *)hdr)[(0x70) / 4]);
        int n = *(int *)q;
        int i;

        D_L39_0024C02C = heap;
        q += 0x10;
        D_L39_0024C030 = n;
        heap += n << 7;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (n)
            func_0038CB78(D_L39_0024C02C, 0, n << 7);
        for (i = 0; i < D_L39_0024C030; i++) {
            func_0038CC88(D_L39_0024C02C + (i << 7), q, 0x80);
            q += 0x80;
        }
    }

    /* section 0x88 */
    if (((int *)hdr)[0x88 / 4]) {
        char *s = (hdr + ((int *)hdr)[(0x88) / 4]);
        int size = *(int *)s;

        D_L39_0024B8C0 = heap;
        s += 0x10;
        size += 0x4000;
        heap += size;
        func_0038CC88(D_L39_0024B8C0, s, size);
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
    }

    /* section 0x80 */
    if (((int *)hdr)[0x80 / 4]) {
        char *s = (hdr + ((int *)hdr)[(0x80) / 4]);
        int n = *(int *)s;

        D_L39_0024BDD4 = heap;
        s += 0x10;
        D_L39_0024BDD0 = n;
        heap = (char *)(((int)heap + (n << 4) + 0x83F) & 0xFFFFFFC0u);
        if (n)
            func_0038CC88(D_L39_0024BDD4, s, (n << 4) + 0x800);
        else
            func_0038CC88(D_L39_0024BDD4, s, 0x800);
    }

    /* section 0x8C */
    if (((int *)hdr)[0x8C / 4]) {
        char *s = (hdr + ((int *)hdr)[(0x8C) / 4]);
        int n = *(int *)s;

        D_L39_0024BFC0 = heap;
        s += 0x10;
        D_L39_0024BFAC = n;
        heap += n << 5;
        heap = (char *)(((int)(heap) + 0x3F) & 0xFFFFFFC0u);
        if (n)
            func_0038CC88(D_L39_0024BFC0, s, n << 5);
    }
    D_L39_0024C188 = heap;
    D_L39_0025F680.mark64 = heap;
    heap += 0x20000;
    D_L39_0024C190 = -1;
    D_L39_0024C18C = 0;
    D_L39_0024C194 = 0;
    func_0038CBA0(D_L39_00295FC0, 0x200);
    if (D_L39_002412DC >= 0)
        D_L39_001FC340.hero = 0;

    heap = (char *)(((int)heap + 0xF) & ~0xF);

    /* section 0x98: the group record and its five tables */
    {
        char *s;
        int size;
        int i;

        s = (hdr + ((int *)hdr)[(0x98) / 4]);
        D_L39_0024BC4C = (Groups_5A12B8 *)heap;
        size = *(int *)s;
        heap += size;
        func_0038CC88(D_L39_0024BC4C, s + 4, size);
        if (D_L39_0024BC4C->p4)
            D_L39_0024BC4C->p4 += (int)D_L39_0024BC4C;
        else
            D_L39_0024BC4C->p4 = 0;
        if (D_L39_0024BC4C->p8)
            D_L39_0024BC4C->p8 += (int)D_L39_0024BC4C;
        else
            D_L39_0024BC4C->p8 = 0;
        if (D_L39_0024BC4C->pC)
            D_L39_0024BC4C->pC += (int)D_L39_0024BC4C;
        else
            D_L39_0024BC4C->pC = 0;
        if (D_L39_0024BC4C->p10)
            D_L39_0024BC4C->p10 += (int)D_L39_0024BC4C;
        else
            D_L39_0024BC4C->p10 = 0;
        if (D_L39_0024BC4C->p14)
            D_L39_0024BC4C->p14 += (int)D_L39_0024BC4C;
        else
            D_L39_0024BC4C->p14 = 0;
        for (i = 0; i < D_L39_0024BC4C->count; i++) {
            GroupEntry_5A12B8 *e;

            e = (GroupEntry_5A12B8 *)D_L39_0024BC4C + i;
            if (e[1].h0)
                e[1].iC += (int)D_L39_0024BC4C->p4;
            else
                e[1].iC = 0;
            e = (GroupEntry_5A12B8 *)D_L39_0024BC4C + i;
            if (e[1].h2)
                e[1].i10 += (int)D_L39_0024BC4C->p8;
            else
                e[1].i10 = 0;
            e = (GroupEntry_5A12B8 *)D_L39_0024BC4C + i;
            if (e[1].h4)
                e[1].i14 += (int)D_L39_0024BC4C->pC;
            else
                e[1].i14 = 0;
            e = (GroupEntry_5A12B8 *)D_L39_0024BC4C + i;
            if (e[1].h6)
                e[1].i18 += (int)D_L39_0024BC4C->p10;
            else
                e[1].i18 = 0;
            e = (GroupEntry_5A12B8 *)D_L39_0024BC4C + i;
            if (e[1].h8)
                e[1].i1C += (int)D_L39_0024BC4C->p14;
            else
                e[1].i1C = 0;
        }
        {
            int bytes;

            D_L39_0024BC48 = (int)heap;
            bytes = D_L39_0024BC4C->count * 0xE0;
            heap += bytes;
            func_0038CB78((void *)D_L39_0024BC48, 0, bytes);
        }
    }

    if (D_L39_0024BB80 && ((int *)hdr)[0x90 / 4]) {
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
        if (D_L39_00268BC0.count) {
            q += n1 * 2;
            if (D_L39_00268BC0.i18 == n1)
                bad1 = 0;
            D_L39_00268BC0.i1C = bad1 == 0;
        } else if (D_L39_0024C9A4 == n1) {
            int i;

            bad1 = 0;
            for (i = 0; i < n1; i++) {
                if (((Tfrag_5A12B8 *)D_L39_0024C9A0)[i].b3D != q[1])
                    bad1 = 1;
                q += 2;
            }
        } else {
            q += n1 * 2;
        }
        bad2 = 1;
        if (D_L39_0024C9E8 - D_L39_0024C9E4 == n2) {
            int i;

            bad2 = 0;
            for (i = 0; i < n2; i++) {
                int id = (unsigned short)q[1];

                if (D_L39_0024C9E4[i].h10 != id)
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

            table = D_L39_0024C9F4 + 0x78000;
            func_0038CB78(table, -1, 0x10000);
            for (i = 0; i < n3; i++) {
                if ((unsigned)(q[i * 2 + 1] + 0x4000) < 0x8000)
                    table[q[i * 2 + 1] + 0x4000] = q[i * 2];
            }
            for (m = D_L39_0024BF5C; m->state != 0xFF; m++) {
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
            if (D_L39_0024C9A4 > 0) {
                unsigned short *e = (unsigned short *)(D_L39_0024C9A0 + 0x3A);
                int left = D_L39_0024C9A4;

                do {
                    *e = 0x7F80;
                    e = (unsigned short *)((char *)e + 0x40);
                } while (--left);
            }
        } else if (D_L39_00268BC0.count) {
            int i;

            q = q0 + 4;
            for (i = 0; i < n1; i++) {
                int w = q[0];

                D_L39_00268BC0.bits[i] = ((w >> 3) << 8) | (1 << (w & 7));
                q += 2;
            }
        } else {
            int i;

            q = q0 + 4;
            for (i = 0; i < n1; i++) {
                int w = q[0];

                ((Tfrag_5A12B8 *)D_L39_0024C9A0)[i].h3A = ((w >> 3) << 8) | (1 << (w & 7));
                q += 2;
            }
        }
        if (bad2) {
            Tie_5A12B8 *t;
            unsigned short *table;
            int i;

            table = D_L39_0024C9F4 + 0x78000;
            q = &q0[n1 * 2 + 4];
            func_0038CB78(table, 0xFFFEFFFE, 0x8000);
            for (i = 0; i < n2; i++) {
                if ((unsigned)q[i * 2 + 1] < 0x4000)
                    table[q[i * 2 + 1]] = q[i * 2];
            }
            for (t = D_L39_0024C9E4; t != D_L39_0024C9E8; t++) {
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

                D_L39_0024C9E4[i].h10 = ((w >> 3) << 8) | (1 << (w & 7));
                q += 2;
            }
        }
        D_L39_0024BB94 = 2;
    } else {
        Moby_5A12B8 *moby;
        Tie_5A12B8 *tie;

        for (moby = D_L39_0024BF5C; moby != D_L39_0024BF64; moby++)
            moby->h36 = 0x7F80;
        for (tie = D_L39_0024C9E4; tie != D_L39_0024C9E8; tie++)
            tie->h10 = 0x7F80;
        if (D_L39_0024C9A4 > 0) {
            unsigned short *e = (unsigned short *)(D_L39_0024C9A0 + 0x3A);
            int left = D_L39_0024C9A4;

            do {
                *e = 0x7F80;
                e = (unsigned short *)((char *)e + 0x40);
            } while (--left);
        }
        D_L39_0024BB94 = 0;
        D_L39_00268BC0.i1C = 0;
    }
    if (D_L39_00242CC0 >= 2) {
        int i;

        for (i = 1; i < D_L39_00242CC0; i++) {
            int j;

            for (j = 0; j < D_L39_0024C9F0; j++)
                D_L39_0024CA38[i][j].h10 = D_L39_0024CA38[0][j].h10;
        }
    }
    func_00387EF0();
    func_L39_0057B610();
    func_L39_0057B1C0();
    func_L01_004606A8(0);
    func_L39_005FF5E8();
    func_L01_004574E0();
    func_L01_004126C8();
    D_L39_0024C040 = 0;
    {
        int i;

        for (i = 7; i >= 0; i--)
            D_L39_00293F38[i].h0 = 0;
    }
    D_L39_0024320C = 0xE0;
    D_L39_002431F8 = 0xE0;
    D_L39_00243200 = 0xE0;
    D_L39_00243204 = 0xE0;
    D_L39_00243208 = 0xE0;
    D_L39_00294338[0] = 0;
    D_L39_0024C080 = 0;
    D_L39_0024C0C0 = 0;
    D_L39_0024112C = 0;
    D_L39_0024BC34 = 0;
    func_L01_003F5498(0, 7.0f);
    switch (D_L39_002412DC) {
    case 2:
    case 5:
    case 6:
    case 7:
    case 8:
    case 10:
        D_L39_0024B9C0 = D_L39_002424D8;
        break;
    default:
        D_L39_0024B9C0 = D_L39_002424A8;
        break;
    }
    D_L39_00242508 = D_L39_0024B9C0;
    return heap;
}

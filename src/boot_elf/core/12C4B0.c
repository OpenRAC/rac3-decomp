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

/* localdecomp:start func_0012C4B0 */
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

void func_0012C4B0(Disp_12C4B0 *disp)
{
    Gs_12C4B0 *gs = func_0012C078();

    if (gs->f6 == 1) {
        *(volatile u64 *)0x12000000 = disp->pmode;
        *(volatile u64 *)0x12000070 = disp->dispfb;
        *(volatile u64 *)0x12000080 = disp->display;
        *(volatile u64 *)0x120000C0 = disp->bgcolor;
    } else {
        *(volatile u64 *)0x12000000 = disp->pmode;
        *(volatile u64 *)0x12000020 = disp->smode2;
        *(volatile u64 *)0x12000090 = disp->dispfb;
        *(volatile u64 *)0x120000A0 = disp->display;
        *(volatile u64 *)0x120000E0 = disp->bgcolor;
    }
}
/* localdecomp:end func_0012C4B0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C56C);

/* localdecomp:start func_0012C570 */
extern void *func_0012C078(void);

s16 func_0012C570(s16 psm, s16 w, s16 h)
{
    u64 *gs;
    s32 bw;
    s32 bh;

    gs = func_0012C078();
    bw = (w + 63) / 64;
    if (psm & 2) {
        bh = (h + 63) / 64;
    } else {
        bh = (h + 31) / 32;
    }
    if ((*gs & 0x0000FFFF0000FFFFULL) == 1) {
        return bw * bh;
    }
    return bw * bh * 2;
}
/* localdecomp:end func_0012C570 */

/* localdecomp:start func_0012C638 */
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

int func_0012C638(DrawEnv_12C638 *draw, short psm, short w, short h, short ztest, short zpsm)
{
    draw->frame1addr = 0x4C;
    draw->frame1 = ((u64)(((w + 63) >> 6) & 0x3F) << 16) | ((u64)(psm & 0xF) << 24);
    draw->zbuf1addr = 0x4E;
    if (ztest == 0) {
        draw->zbuf1 = (u64)func_0012C570(psm, w, h) | ((u64)(zpsm & 0xF) << 24) | ((u64)1 << 32);
    } else {
        draw->zbuf1 = (u64)func_0012C570(psm, w, h) | ((u64)(zpsm & 0xF) << 24);
    }
    draw->xyoffset1addr = 0x18;
    draw->xyoffset1 = ((0x800L - (short)(w >> 1)) << 4) | ((0x800L - (short)(h >> 1)) << 36);
    draw->scissor1addr = 0x40;
    draw->scissor1 = ((u64)(w - 1) << 16) | ((u64)(h - 1) << 48);
    draw->prmodecontaddr = 0x1A;
    draw->prmodecont.ATE = 1;
    draw->colclampaddr = 0x46;
    draw->colclamp.ATE = 1;
    draw->dtheaddr = 0x45;
    if (psm & 2) {
        draw->dthe.ATE = 1;
    } else {
        draw->dthe.ATE = 0;
    }
    draw->test1addr = 0x47;
    if (ztest) {
        draw->test1 = ((u64)(ztest & 3) << 17) | 0x10000;
    } else {
        draw->test1 = 0x30000;
    }
    __asm__ __volatile__("sync");
    return 8;
}
/* localdecomp:end func_0012C638 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C81C);

/* localdecomp:start func_0012C820 */
extern char D_00151588[];
extern s32 func_00121760_0012C820(char *, ...);

s32 func_0012C820(u64 *tag)
{
    u32 i = 0;

    while (*(volatile u32 *)0x1000A000 & 0x100) {
        if (i++ > 0x1000000) {
            func_00121760_0012C820(D_00151588);
            return -1;
        }
    }
    *(volatile u32 *)0x1000A020 = (s32)(*tag & 0x7FFF) + 1;
    if (((u32)tag & 0x70000000) == 0x70000000) {
        *(volatile u32 *)0x1000A010 = ((u32)tag & 0x0FFFFFFF) | 0x80000000;
    } else {
        *(volatile u32 *)0x1000A010 = (u32)tag & 0x0FFFFFFF;
    }
    *(volatile u32 *)0x1000A000 = 0x101;
    return 0;
}
/* localdecomp:end func_0012C820 */

/* localdecomp:start func_0012C908 */
/* libgraph: 2.9-ee-991111, @ee29 -O2 -G0 */
extern long func_0011F340();
extern void func_0011F2B0();

s32 func_0012C908(void)
{
    u8 *p;
    p = func_0012C078();
    if (*(s32 *)(p + 8) == 0)
    {
        func_0011F2B0();
        if (*(s16 *)p != 1)
        {
            return 1;
        }
        return (s32)((*(volatile unsigned long *)0x12001000 >> 13) & 1);
    }
    else
    {
        long v = func_0011F340();
        long b = (v >> 13) & 1;
        if (*(s16 *)p != 1)
        {
            return 1;
        }
        return (s32)b;
    }
}
/* localdecomp:end func_0012C908 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C99C);

#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_00392440(s32, s32, s32, s32);
extern void func_00392868(s32, s32);
extern void func_003926E8(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { unsigned long v : 9; unsigned long r : 55; } FB_38CE40;
typedef struct {
    unsigned long dx : 12;
    unsigned long dy : 11;
    unsigned long magh : 4;
    unsigned long magv : 2;
    unsigned long p0 : 3;
    unsigned long dw : 12;
    unsigned long dh : 11;
    unsigned long p1 : 9;
} DI_38CE40;
typedef struct {
    unsigned long nloop : 15;
    unsigned long eop : 1;
    unsigned long p0 : 16;
    unsigned long id : 14;
    unsigned long pre : 1;
    unsigned long prim : 11;
    unsigned long flg : 2;
    unsigned long nreg : 4;
    unsigned long regs0 : 4;
    unsigned long regs : 60;
} GT_38CE40;
typedef struct {
    u8 p0[0x10];
    FB_38CE40 q10;
    DI_38CE40 q18;
    u8 p20[0x10];
    GT_38CE40 t30;
    FB_38CE40 q40;
    unsigned long q48;
    unsigned long q50;
    u8 p58[0x68];
    GT_38CE40 tC0;
    FB_38CE40 qD0;
    unsigned long qD8;
    unsigned long qE0;
    u8 pE8[0x68];
    s16 h150, h152, h154, h156, h158, h15A, h15C, h15E;
    s16 h160, h162, h164, h166, h168, h16A, h16C, h16E;
    s32 w170;
} E_38CE40;


extern u32 *D_001DA050;
extern s32 D_001D4CF8_003922B8;
extern void func_12C820(s32);
/* localdecomp:start func_003922B8 */
extern E_38CE40 D_001CFEC0_00391A58[];
extern E_38CE40 *D_001D4CF8_00391A58;
extern s32 D_001A1ED0_00391A58[];
extern s32 D_001D5520_003922B8;
extern u8 D_001D551D_003922B8;
extern s32 D_001D4D08_00391A58;
extern s32 D_001D4D0C_00391A58;
extern s32 D_001D4D10_00391A58;
extern s32 D_001D4D14_00391A58;
extern s32 D_001D4D18_00391A58;
extern s32 D_001D4D1C_00391A58;
extern s32 D_001D4D20_00391A58;
extern s32 D_001D4D24_00391A58;
extern s32 D_001D4D28_00391A58;
extern s32 D_001D4D2C_00391A58;
extern s32 D_001D4D30_00391A58;
extern s32 D_001D4D34_00391A58;
extern unsigned long D_001D02D0_00391A58[];
extern unsigned long D_001D0070_00391A58[];
extern unsigned long D_001D07B0_00391A58[];
extern unsigned long D_001D0900_00391A58[];
extern unsigned long D_00141850_00391A58[];
extern unsigned long D_00141990_00391A58[];
extern unsigned long D_00141AD0_00391A58[];
extern unsigned long D_00141DC0_00391A58[];
extern unsigned long D_001420B0_00391A58[];
extern void func_0012C138_003922B8(void *, s32, s16, s16, s16, s16);
extern void func_0012C638_003922B8(s32, s32, s32, s32, s32, s32);
extern void func_00391778(void);
extern void func_00391880(s32, s32);
extern void func_0038D068();
extern void func_11F0A0_003922B8(s32);
extern unsigned long D_001D07E8_003922B8[];
extern void func_12C4B0_003922B8(s32);
extern s32 D_001D4CF8_003922B8b[];

extern u32 *D_001DA050_003922B8;
extern s32 D_001D4CF8_003922B8_003922B8; 
extern void func_12C820_003922B8(s32);

void func_003922B8(void) {
    if (D_001DA050_003922B8 != 0) {
        D_001DA050_003922B8[0] = 0x30000009;
        D_001DA050_003922B8[1] = (D_001D4CF8_003922B8_003922B8 + 0x30) & 0xFFFFFFF;
        D_001DA050_003922B8[2] = 0;
        D_001DA050_003922B8[3] = 0x50000009;
        D_001DA050_003922B8 += 4;
    } else {
        func_12C820_003922B8(D_001D4CF8_003922B8_003922B8 + 0x30);
    }
}
/* localdecomp:end func_003922B8 */

extern u32 *D_001DA050;
extern u8 D_1D07B0[], D_1D0900[];
/* localdecomp:start func_00392350 */
extern char D_001D07B0[];
extern char D_001D0900[];

void func_00392350(int a0)
{
    int *p = (int *)D_001DA050;
    if (p == 0)
        return;
    p[0] = 0x30000015;
    if (a0 == 0)
        D_001DA050[1] = (int)D_001D07B0;
    else
        D_001DA050[1] = (int)D_001D0900;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000015;
    D_001DA050 = D_001DA050 + 4;
}
/* localdecomp:end func_00392350 */

extern u32 *D_001DA050;
extern s32 D_001D4CF8_003923D0;
/* localdecomp:start func_003923D0 */
extern u32 *D_001DA050_003923D0;
extern s32 D_001D4CF8_003923D0_003923D0;
void func_003923D0(void) {
    D_001DA050_003923D0[0] = 0x30000009;
    D_001DA050_003923D0[1] = (D_001D4CF8_003923D0_003923D0 + 0xC0) & 0xFFFFFFF;
    D_001DA050_003923D0[2] = 0;
    D_001DA050_003923D0[3] = 0x50000009;
    D_001DA050_003923D0 += 4;
}
/* localdecomp:end func_003923D0 */

typedef struct { unsigned long lo : 9; unsigned long hi : 55; } BF_38DC08;
typedef struct { u8 p0[0x160]; s16 h160; s16 h162; s16 h164; s16 h166; u8 p168[4]; u16 h16C; s16 h16E; } S_38DC08;
extern S_38DC08 D_001CFEC0_00392440[];
extern s32 D_001DA050_00392440;
extern long D_001D4C30;
extern void func_0038CBA0();
extern void func_0012C638(s32, s32, s32, s32, s32, s32);
/* localdecomp:start func_00392440 */
/* from level 39's func_L39_00597FF8 (the same code, already matched) */
typedef struct {
    unsigned long FBP : 9;
    unsigned long pad09 : 7;
    unsigned long FBW : 6;
    unsigned long pad22 : 2;
    unsigned long PSM : 6;
    unsigned long pad30 : 2;
    unsigned long FBMSK : 32;
} GsFrame_00392440;

__asm__(".extern D_001DA050_00392440_a, 16");
extern u32 *D_001DA050_00392440_a;
extern u32 *D_001DA050_00392440_b;
__asm__(".extern D_001DA050_00392440_b, 4");
extern void func_0038CBA0();

void func_00392440(s32 a, s32 b, s32 c, s32 flag) {
    s32 x;
    unsigned long *d;
    unsigned long *r;

    x = a - 6;
    if (x <= 0) {
        x = 1;
    }
    D_001CFEC0_00392440[0].h166 = c >> 13;
    D_001CFEC0_00392440[0].h160 = 1 << a;
    D_001CFEC0_00392440[0].h162 = 1 << b;
    D_001D4C30 = (unsigned long)(c >> 8) | ((unsigned long)(1 << x) << 14) | ((unsigned long)a << 26) | ((unsigned long)b << 30) | ((unsigned long)1 << 34);
    func_0038CBA0(D_001DA050_00392440_a, 0xF0);
    D_001DA050_00392440_a[0] = 0x1000000E;
    D_001DA050_00392440_a[1] = 0;
    D_001DA050_00392440_a[2] = 0;
    D_001DA050_00392440_a[3] = 0x5000000E;
    D_001DA050_00392440_a += 4;
    r = (unsigned long *)D_001DA050_00392440_a;
    r[0] = 0x1000000000000008L;
    r[1] = 0xE;
    D_001DA050_00392440_b = D_001DA050_00392440_a + 4;
    d = (unsigned long *)D_001DA050_00392440_b;
    func_0012C638((s32)d, D_001CFEC0_00392440[0].h164, D_001CFEC0_00392440[0].h160, D_001CFEC0_00392440[0].h162, 3, 0);
    ((GsFrame_00392440 *)d)->FBP = D_001CFEC0_00392440[0].h166;
    if (flag == 0) {
        d[2] = (unsigned long)D_001CFEC0_00392440[0].h16E | ((unsigned long)(D_001CFEC0_00392440[0].h16C & 0xF) << 24);
    } else {
        s32 t = a + b;
        if (t > 16) {
            t = 16;
        }
        d[2] = (unsigned long)((c - (4 << t)) >> 13) | ((unsigned long)(D_001CFEC0_00392440[0].h16C & 0xF) << 24);
    }
    D_001DA050_00392440_a += 0x20;
    r = (unsigned long *)D_001DA050_00392440_a;
    r[0] = 0x1000000000000001L;
    r[1] = 0xE;
    r[2] = 0x30003;
    r[3] = 0x47;
    r[4] = 0x4400000000008001L;
    r[5] = 0x4410;
    r[6] = 0x106;
    r[7] = 0;
    r[8] = (unsigned long)(0x8000 - D_001CFEC0_00392440[0].h160 * 8) | ((unsigned long)(0x8000 - D_001CFEC0_00392440[0].h162 * 8) << 16);
    r[9] = (unsigned long)(D_001CFEC0_00392440[0].h160 * 8 + 0x8000) | ((unsigned long)(D_001CFEC0_00392440[0].h162 * 8 + 0x7FF0) << 16);
    D_001DA050_00392440_a += 0x14;
}
/* localdecomp:end func_00392440 */

extern u32 *D_001DA050;
extern u8 D_001D0070[];
/* localdecomp:start func_003926E8 */
void func_003926E8(void)
{
    *(int *)(*(char * *)&D_001DA050 + 0) = 0x30000026;
    *(char **)(*(char * *)&D_001DA050 + 4) = D_001D0070;
    *(int *)(*(char * *)&D_001DA050 + 8) = 0;
    *(int *)(*(char * *)&D_001DA050 + 12) = 0x50000026;
    D_001DA050 = *(char * *)&D_001DA050 + 16;
}
/* localdecomp:end func_003926E8 */

extern u32 *D_001DA050;
extern u8 D_001D7370[];
extern u8 D_001D7390[];
extern u8 D_001D02D0[];
extern u8 D_001D7300[];
/* localdecomp:start func_00392748 */
extern u32 *D_001DA050;
extern u8 D_001D7370[], D_001D7390[], D_001D02D0[], D_001D7300[];
/* from rac4-decomp's func_004597B8 */
void func_00392748(s32 alternate)
{
    D_001DA050[0] = 0x30000002;
    if (alternate)
        D_001DA050[1] = (u32)D_001D7370;
    else
        D_001DA050[1] = (u32)D_001D7390;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000002;
    D_001DA050 += 4;
    D_001DA050[0] = 0x30000029;
    D_001DA050[1] = (u32)D_001D02D0;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000029;
    D_001DA050 += 4;
    D_001DA050[0] = 0x30000003;
    D_001DA050[1] = (u32)D_001D7300;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000003;
    D_001DA050 += 4;
}
/* localdecomp:end func_00392748 */

extern u32 *D_001DA050_00392868;
extern void func_003A9440(s32, unsigned long);
/* localdecomp:start func_00392868 */
void func_00392868(int w, int h) {
    int *tag;
    long *q;
    long *c;
    int n;
    int i;
    int zero;
    int step;
    int x;
    int y;
    long lo;
    long hi;
    n = w / 32;
    func_003A9440(0x42, 0x800000004AL);
    *(int *)((char *)D_001DA050 + 0) = (n + 5) | 0x10000000;
    *(int *)((char *)D_001DA050 + 4) = 0;
    *(int *)((char *)D_001DA050 + 8) = 0;
    *(int *)((char *)D_001DA050 + 12) = (n + 5) | 0x50000000;
    tag = D_001DA050;
    q = (long *)(tag + 4);
    D_001DA050 = tag + 4;
    zero = 0;
    q[zero] = 0x1000000000000001L;
    q[1] = 0xE;
    q[2] = 0x32003;
    q[3] = 0x47;
    q[4] = 0x2400000000000001L;
    q[5] = 0x10;
    q[6] = 0x146;
    q[7] = 0x80008080L;
    q[8] = (long)(n | 0x8000) | 0x2400000000000000L;
    q[9] = 0x44;
    i = zero;
    if (n > zero) {
        lo = (long)(0x8000 - h * 8) << 16;
        x = 0x8000 + -(w * 8);
        c = (long *)((char *)tag + 0x60);
        y = 0x8200 + -(w * 8);
        hi = (long)(h * 8 + 0x7FF0) << 16;
        do {
            step = 0x200;
            *c++ = x | lo;
            *c++ = y | hi;
            y += step;
            x += step;
            i++;
        } while (i < n);
    }
    D_001DA050 = D_001DA050 + (n * 4 + 20);
}
/* localdecomp:end func_00392868 */

/* US draft of func_00391A58 (rac3-uya-decomp func_00391998, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-fno-rerun-loop-opt` `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_00391A58 */
typedef int Q_38CE40 __attribute__((mode(TI)));
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

extern E_38CE40 D_001CFEC0_00391A58[];
extern E_38CE40 *D_001D4CF8_00391A58;
extern s32 D_001A1ED0_00391A58[];
extern s32 D_001D5520;
extern u8 D_001D551D;
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
extern void func_0012C138(void *, s32, s16, s16, s16, s16);
extern void func_0012C638(s32, s32, s32, s32, s32, s32);
extern void func_00391778(void);
extern void func_00391880(s32, s32);
extern void func_0038D068();
extern void func_11F0A0(s32);
void func_00391A58(s32 w, s32 h, s32 a2, s32 a3, s32 a4, s32 a5) {
    unsigned long *b;
    s32 r0 = D_001A1ED0_00391A58[0] >> 13;
    D_001CFEC0_00391A58->h150 = w;
    D_001CFEC0_00391A58->h152 = h;
    D_001CFEC0_00391A58->h15C = 1;
    D_001CFEC0_00391A58->h16C = 0x31;
    D_001CFEC0_00391A58->h15E = r0;
    D_001CFEC0_00391A58->h156 = D_001A1ED0_00391A58[1] >> 13;
    D_001CFEC0_00391A58->h16E = D_001A1ED0_00391A58[2] >> 13;
    D_001D4CF8_00391A58 = D_001CFEC0_00391A58;
    D_001CFEC0_00391A58->w170 = 0;
    D_001CFEC0_00391A58->h158 = a2;
    D_001CFEC0_00391A58->h15A = a3;
    D_001CFEC0_00391A58->h168 = a4;
    D_001CFEC0_00391A58->h16A = a5;
    D_001CFEC0_00391A58->h154 = 0;
    D_001CFEC0_00391A58->h164 = 0;
    func_0012C138(D_001CFEC0_00391A58, 1, a2, a3, a4, a5);
    D_001D4CF8_00391A58->q10.v = D_001CFEC0_00391A58->h15E;
    if (D_001D5520 != 0) {
        *(unsigned long *)&D_001D4CF8_00391A58->q18 = 0x1BF4FF00834140UL;
    }
    if (D_001D551D == 0) {
        D_001D4D08_00391A58 = *(unsigned long *)((u8 *)D_001D4CF8_00391A58 + 0x18) & 0xFFF;
        D_001D4D0C_00391A58 = (*(unsigned long *)((u8 *)D_001D4CF8_00391A58 + 0x18) >> 12) & 0x7FF;
    }
    D_001D4D10_00391A58 = (*(unsigned long *)((u8 *)D_001D4CF8_00391A58 + 0x18) >> 23) & 0xF;
    D_001D4D14_00391A58 = (*(unsigned long *)((u8 *)D_001D4CF8_00391A58 + 0x18) >> 27) & 0x3;
    D_001D4D18_00391A58 = (*(unsigned long *)((u8 *)D_001D4CF8_00391A58 + 0x18) >> 32) & 0xFFF;
    D_001D4D1C_00391A58 = (*(unsigned long *)((u8 *)D_001D4CF8_00391A58 + 0x18) >> 44) & 0x7FF;
    D_001D4D20_00391A58 = D_001D4D08_00391A58;
    D_001D4D24_00391A58 = D_001D4D0C_00391A58;
    D_001D4D28_00391A58 = D_001D4D10_00391A58;
    D_001D4D2C_00391A58 = D_001D4D14_00391A58;
    D_001D4D30_00391A58 = D_001D4D18_00391A58;
    D_001D4D34_00391A58 = D_001D4D1C_00391A58;
    if (D_001D551D != 0) {
        func_00391778();
    }
    func_0012C638((s32)&D_001D4CF8_00391A58->q40, D_001CFEC0_00391A58->h154, D_001CFEC0_00391A58->h150, D_001CFEC0_00391A58->h152, 3, D_001CFEC0_00391A58->h16C);
    D_001D4CF8_00391A58->q40.v = D_001CFEC0_00391A58->h156;
    *(unsigned long *)((u8 *)D_001D4CF8_00391A58 + 0x50) = D_001CFEC0_00391A58->h16E | ((long)(D_001CFEC0_00391A58->h16C & 0xF) << 24);
    *(Q_38CE40 *)((u8 *)D_001D4CF8_00391A58 + 0x30) = 0;
    {
        E_38CE40 *p = D_001D4CF8_00391A58;
        p->t30.nloop = 8;
        p->t30.eop = 1;
        p->t30.nreg = 1;
        p->t30.regs0 = 0xE;
        func_0012C638((s32)&p->qD0, D_001CFEC0_00391A58->h15C, D_001CFEC0_00391A58->h158, D_001CFEC0_00391A58->h15A, 0, 0);
    }
    {
        E_38CE40 *p = D_001D4CF8_00391A58;
        p->qD0.v = D_001CFEC0_00391A58->h15E;
        *(unsigned long *)((u8 *)p + 0xE0) = 0x8000UL << 17;
    }
    *(Q_38CE40 *)((u8 *)D_001D4CF8_00391A58 + 0xC0) = 0;
    {
        E_38CE40 *p = D_001D4CF8_00391A58;
        p->tC0.nloop = 8;
        p->tC0.eop = 1;
        p->tC0.nreg = 1;
        p->tC0.regs0 = 0xE;
    }
    b = D_001D02D0_00391A58;
    b[0] = (((0x8156UL << 16) | 0x8000) << 31) | 1;
    b[1] = 0xEEEE;
    b[2] = 0x30000;
    b[3] = 0x47;
    b[4] = 5;
    b[5] = 8;
    b[6] = (0x8000UL << 17) | 0x261;
    b[7] = 0x14;
    b[8] = ((long)D_001D4CF8_00391A58->h156 << 5) | ((long)(((u16)D_001D4CF8_00391A58->h150 >> 6) & 0x3F) << 14) | ((long)D_001D4CF8_00391A58->h154 << 20) | (0xEA80UL << 20);
    b[9] = 6;
    b[10] = (0x8800UL << 47) | 0x8010;
    b[11] = 0x5353;
    if (D_001D5520 != 0) {
        s32 n = 12;
        s32 i;
        for (i = 0; i < 16; i++) {
            s32 xa = i * 0x280 + 0x7FF8;
            s32 xb = (i + 1) * 0x280 + 0x7FF8;
            b[n++] = i * D_001D4CF8_00391A58->h150;
            b[n++] = (xa - (D_001D4CF8_00391A58->h158 << 3)) | ((long)(0x7FF8 - (D_001D4CF8_00391A58->h15A << 3)) << 16);
            b[n++] = ((i + 1) * D_001D4CF8_00391A58->h150) | ((long)D_001D4CF8_00391A58->h152 << 20);
            b[n++] = (xb - (D_001D4CF8_00391A58->h158 << 3)) | ((long)((D_001D4CF8_00391A58->h15A << 3) + 0x7FF8) << 16);
        }
    } else {
        s32 n = 12;
        s32 i;
        for (i = 0; i < 16; i++) {
            b[n++] = i * D_001D4CF8_00391A58->h150;
            {
                s32 w = D_001D4CF8_00391A58->h158;
                s32 t = i * w + 0x7FF8;
                b[n++] = (t - (w << 3)) | ((long)(0x7FF8 - (D_001D4CF8_00391A58->h15A << 3)) << 16);
            }
            b[n++] = ((i + 1) * D_001D4CF8_00391A58->h150) | ((long)D_001D4CF8_00391A58->h152 << 20);
            {
                s32 w = D_001D4CF8_00391A58->h158;
                s32 t = (i + 1) * w + 0x7FF8;
                b[n++] = (t - (w << 3)) | ((long)((D_001D4CF8_00391A58->h15A << 3) + 0x7FF8) << 16);
            }
        }
    }
    b[0x4C] = (0x8800UL << 47) | 0x8001;
    b[0x4D] = 0x4410;
    b[0x4E] = 0x181;
    b[0x4F] = 0x8000UL << 16;
    b[0x50] = (0x7FF8 - (D_001D4CF8_00391A58->h158 << 3)) | ((long)(0x7FF8 - (D_001D4CF8_00391A58->h15A << 3)) << 16);
    b[0x51] = (0x7FF8 - (D_001D4CF8_00391A58->h158 << 3)) | ((long)((D_001D4CF8_00391A58->h15A << 3) + 0x7FF8) << 16);
    func_00391880(0, 0);
    b = D_001D0070_00391A58;
    b[0] = (((0x8116UL << 16) | 0x8000) << 31) | 1;
    b[1] = 0xEEEE;
    b[2] = 0x31001;
    b[3] = 0x47;
    b[4] = 5;
    b[5] = 8;
    b[6] = (0x8000UL << 17) | 0x261;
    b[7] = 0x14;
    b[8] = ((long)D_001D4CF8_00391A58->h156 << 5) | ((long)(((u16)D_001D4CF8_00391A58->h150 >> 6) & 0x3F) << 14) | ((long)D_001D4CF8_00391A58->h154 << 20) | (0xEA80UL << 20);
    b[9] = 6;
    b[10] = (0x8800UL << 47) | 0x8010;
    b[11] = 0x5353;
    {
        s32 n = 12;
        s32 i;
        for (i = 0; i < 16; i++) {
            b[n++] = i << 9;
            b[n++] = (0x6FFC + i * 0x200) | ((long)(0x7FFC - (D_001D4CF8_00391A58->h152 << 3)) << 16);
            b[n++] = (0x200 + i * 0x200) | ((long)D_001D4CF8_00391A58->h152 << 20);
            b[n++] = (0x71FC + i * 0x200) | ((long)((D_001D4CF8_00391A58->h152 << 3) + 0x7FFC) << 16);
        }
    }
    b = D_001D07B0_00391A58;
    b[0] = (0x8000UL << 45) | 1;
    b[1] = 0xE;
    b[2] = 0x30000;
    b[3] = 0x47;
    b[4] = (0x9000UL << 46) | 0x8001;
    b[5] = 0x10;
    b[6] = 0x106;
    b[7] = 0x8000UL << 16;
    b[8] = (0x9000UL << 46) | 0x8010;
    b[9] = 0x44;
    {
        s32 n = 10;
        s32 i;
        for (i = 0; i < 16; i++) {
            b[n++] = (0x6FF8 + i * 0x200) | ((long)(0x7FF8 - (D_001D4CF8_00391A58->h152 << 3)) << 16);
            b[n++] = (0x71F8 + i * 0x200) | ((long)((D_001D4CF8_00391A58->h152 << 3) + 0x7FF8) << 16);
        }
    }
    func_0038D068(D_001D0900_00391A58, D_001D07B0_00391A58, 0x150);
    b = D_00141850_00391A58;
    {
        s32 n = 8;
        s32 i;
        for (i = 0; i < 16; i++) {
            b[n++] = (0x6FF8 + i * 0x200) | ((long)(0x7FF8 - (D_001D4CF8_00391A58->h152 << 3)) << 16);
            b[n++] = (0x71F8 + i * 0x200) | ((long)((D_001D4CF8_00391A58->h152 << 3) + 0x7FF8) << 16);
        }
    }
    b = D_00141990_00391A58;
    {
        s32 n = 8;
        s32 i;
        for (i = 0; i < 16; i++) {
            if (D_001D5520 != 0) {
                b[n++] = (i * 0x280 + 0x6BF8) | ((long)(0x7FF8 - (D_001D4CF8_00391A58->h15A << 3)) << 16);
                b[n++] = ((i + 1) * 0x280 + 0x6BF8) | ((long)((D_001D4CF8_00391A58->h15A << 3) + 0x7FF8) << 16);
            } else {
                b[n++] = ((i << 9) + 0x6FF8) | ((long)(0x7FF8 - (D_001D4CF8_00391A58->h15A << 3)) << 16);
                b[n++] = (((i + 1) << 9) + 0x6FF8) | ((long)((D_001D4CF8_00391A58->h15A << 3) + 0x7FF8) << 16);
            }
        }
    }
    b = D_00141AD0_00391A58;
    {
        s32 n = 0x18;
        s32 i;
        u32 u, v;
        v = 0;
        u = 0;
        for (i = 0; i < 16; i++) {
            b[n++] = u;
            b[n++] = v;
            u += 0x200;
            b[n++] = u | ((long)D_001D4CF8_00391A58->h152 << 20);
            v += 0x100;
            b[n++] = v | 0x10000000;
        }
    }
    b = D_00141DC0_00391A58;
    {
        s32 n = 0x18;
        s32 i;
        u32 u, v;
        v = 0;
        u = 0;
        for (i = 0; i < 16; i++) {
            b[n++] = u;
            b[n++] = v;
            u += 0x200;
            b[n++] = u | ((long)D_001D4CF8_00391A58->h152 << 20);
            v += 0x40;
            b[n++] = v | 0x4000000;
        }
    }
    {
        s32 x = D_001A1ED0_00391A58[1];
        D_001420B0_00391A58[2] = ((long)x >> 13) | (((((0xFFFFUL << 16) | 0xFF00) << 20) | 0x8000) << 4);
        D_001420B0_00391A58[10] = (long)((x >> 8) | 0x24020000) | (0xC800UL << 19);
    }
    func_11F0A0(0);
}
/* localdecomp:end func_00391A58 */

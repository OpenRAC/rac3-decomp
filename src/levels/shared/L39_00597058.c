#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00597058);

/* localdecomp:start func_L39_00597230 */
typedef int Q_00597230 __attribute__((mode(TI)));
typedef struct { unsigned long v : 9; unsigned long r : 55; } FB_00597230;
typedef struct {
    unsigned long dx : 12;
    unsigned long dy : 11;
    unsigned long magh : 4;
    unsigned long magv : 2;
    unsigned long p0 : 3;
    unsigned long dw : 12;
    unsigned long dh : 11;
    unsigned long p1 : 9;
} DI_00597230;
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
} GT_00597230;
typedef struct {
    u8 p0[0x10];
    FB_00597230 q10;
    DI_00597230 q18;
    u8 p20[0x10];
    GT_00597230 t30;
    FB_00597230 q40;
    unsigned long q48;
    unsigned long q50;
    u8 p58[0x68];
    GT_00597230 tC0;
    FB_00597230 qD0;
    unsigned long qD8;
    unsigned long qE0;
    u8 pE8[0x68];
    s16 h150, h152, h154, h156, h158, h15A, h15C, h15E;
    s16 h160, h162, h164, h166, h168, h16A, h16C, h16E;
    s32 w170;
} E_00597230;

extern E_00597230 D_L39_00228580[];
extern E_00597230 *D_L39_00240408;
extern s32 D_001FC450[];
extern s32 D_L39_002413A0;
extern u8 D_L39_0024139D;
extern s32 D_L39_00240430;
extern s32 D_L39_00240434;
extern s32 D_L39_00240438;
extern s32 D_L39_0024043C;
extern s32 D_L39_00240440;
extern s32 D_L39_00240444;
extern s32 D_L39_00240448;
extern s32 D_L39_0024044C;
extern s32 D_L39_00240450;
extern s32 D_L39_00240454;
extern s32 D_L39_00240458;
extern s32 D_L39_0024045C;
extern unsigned long D_L39_00228C90[];
extern unsigned long D_L39_00228A30[];
extern unsigned long D_L39_00229170[];
extern unsigned long D_L39_002292C0[];
extern unsigned long D_001A3800[];
extern unsigned long D_001A3940[];
extern unsigned long D_001A3A80[];
extern unsigned long D_001A3D70[];
extern unsigned long D_001A4060[];
extern void func_00139638(void *, s32, s16, s16, s16, s16);
extern void func_00139B38(s32, s32, s32, s32, s32, s32);
extern void func_00391398(void);
extern void func_L39_00597058(s32, s32);
extern void func_0038CC88(void *, void *, s32);
extern void func_001264E0(s32);
/* from the US draft of func_00391A58 (nonmatching/boot_elf/func_00391A58.c; rac3-uya-decomp func_00391998) */
void func_L39_00597230(s32 w, s32 h, s32 a2, s32 a3, s32 a4, s32 a5) {
    unsigned long *b;
    s32 r0 = D_001FC450[0] >> 13;
    D_L39_00228580->h150 = w;
    D_L39_00228580->h152 = h;
    D_L39_00228580->h15C = 1;
    D_L39_00228580->h16C = 0x31;
    D_L39_00228580->h15E = r0;
    D_L39_00228580->h156 = D_001FC450[1] >> 13;
    D_L39_00228580->h16E = D_001FC450[2] >> 13;
    D_L39_00240408 = D_L39_00228580;
    D_L39_00228580->w170 = 0;
    D_L39_00228580->h158 = a2;
    D_L39_00228580->h15A = a3;
    D_L39_00228580->h168 = a4;
    D_L39_00228580->h16A = a5;
    D_L39_00228580->h154 = 0;
    D_L39_00228580->h164 = 0;
    func_00139638(D_L39_00228580, 1, a2, a3, a4, a5);
    D_L39_00240408->q10.v = D_L39_00228580->h15E;
    if (D_L39_002413A0 != 0) {
        *(unsigned long *)&D_L39_00240408->q18 = 0x1BF4FF00834140UL;
    }
    if (D_L39_0024139D == 0) {
        D_L39_00240430 = *(unsigned long *)((u8 *)D_L39_00240408 + 0x18) & 0xFFF;
        D_L39_00240434 = (*(unsigned long *)((u8 *)D_L39_00240408 + 0x18) >> 12) & 0x7FF;
    }
    D_L39_00240438 = (*(unsigned long *)((u8 *)D_L39_00240408 + 0x18) >> 23) & 0xF;
    D_L39_0024043C = (*(unsigned long *)((u8 *)D_L39_00240408 + 0x18) >> 27) & 0x3;
    D_L39_00240440 = (*(unsigned long *)((u8 *)D_L39_00240408 + 0x18) >> 32) & 0xFFF;
    D_L39_00240444 = (*(unsigned long *)((u8 *)D_L39_00240408 + 0x18) >> 44) & 0x7FF;
    D_L39_00240448 = D_L39_00240430;
    D_L39_0024044C = D_L39_00240434;
    D_L39_00240450 = D_L39_00240438;
    D_L39_00240454 = D_L39_0024043C;
    D_L39_00240458 = D_L39_00240440;
    D_L39_0024045C = D_L39_00240444;
    if (D_L39_0024139D != 0) {
        func_00391398();
    }
    func_00139B38((s32)&D_L39_00240408->q40, D_L39_00228580->h154, D_L39_00228580->h150, D_L39_00228580->h152, 3, D_L39_00228580->h16C);
    D_L39_00240408->q40.v = D_L39_00228580->h156;
    *(unsigned long *)((u8 *)D_L39_00240408 + 0x50) = D_L39_00228580->h16E | ((long)(D_L39_00228580->h16C & 0xF) << 24);
    *(Q_00597230 *)((u8 *)D_L39_00240408 + 0x30) = 0;
    {
        E_00597230 *p = D_L39_00240408;
        p->t30.nloop = 8;
        p->t30.eop = 1;
        p->t30.nreg = 1;
        p->t30.regs0 = 0xE;
        func_00139B38((s32)&p->qD0, D_L39_00228580->h15C, D_L39_00228580->h158, D_L39_00228580->h15A, 0, 0);
    }
    {
        E_00597230 *p = D_L39_00240408;
        p->qD0.v = D_L39_00228580->h15E;
        *(unsigned long *)((u8 *)p + 0xE0) = 0x8000UL << 17;
    }
    *(Q_00597230 *)((u8 *)D_L39_00240408 + 0xC0) = 0;
    {
        E_00597230 *p = D_L39_00240408;
        p->tC0.nloop = 8;
        p->tC0.eop = 1;
        p->tC0.nreg = 1;
        p->tC0.regs0 = 0xE;
    }
    b = D_L39_00228C90;
    b[0] = (((0x8156UL << 16) | 0x8000) << 31) | 1;
    b[1] = 0xEEEE;
    b[2] = 0x30000;
    b[3] = 0x47;
    b[4] = 5;
    b[5] = 8;
    b[6] = (0x8000UL << 17) | 0x261;
    b[7] = 0x14;
    b[8] = ((long)D_L39_00240408->h156 << 5) | ((long)(((u16)D_L39_00240408->h150 >> 6) & 0x3F) << 14) | ((long)D_L39_00240408->h154 << 20) | (0xEA80UL << 20);
    b[9] = 6;
    b[10] = (0x8800UL << 47) | 0x8010;
    b[11] = 0x5353;
    if (D_L39_002413A0 != 0) {
        s32 n = 12;
        s32 i;
        for (i = 0; i < 16; i++) {
            s32 xa = i * 0x280 + 0x7FF8;
            s32 xb = (i + 1) * 0x280 + 0x7FF8;
            b[n++] = i * D_L39_00240408->h150;
            b[n++] = (xa - (D_L39_00240408->h158 << 3)) | ((long)(0x7FF8 - (D_L39_00240408->h15A << 3)) << 16);
            b[n++] = ((i + 1) * D_L39_00240408->h150) | ((long)D_L39_00240408->h152 << 20);
            b[n++] = (xb - (D_L39_00240408->h158 << 3)) | ((long)((D_L39_00240408->h15A << 3) + 0x7FF8) << 16);
        }
    } else {
        s32 n = 12;
        s32 i;
        for (i = 0; i < 16; i++) {
            b[n++] = i * D_L39_00240408->h150;
            {
                s32 w = D_L39_00240408->h158;
                s32 t = i * w + 0x7FF8;
                b[n++] = (t - (w << 3)) | ((long)(0x7FF8 - (D_L39_00240408->h15A << 3)) << 16);
            }
            b[n++] = ((i + 1) * D_L39_00240408->h150) | ((long)D_L39_00240408->h152 << 20);
            {
                s32 w = D_L39_00240408->h158;
                s32 t = (i + 1) * w + 0x7FF8;
                b[n++] = (t - (w << 3)) | ((long)((D_L39_00240408->h15A << 3) + 0x7FF8) << 16);
            }
        }
    }
    b[0x4C] = (0x8800UL << 47) | 0x8001;
    b[0x4D] = 0x4410;
    b[0x4E] = 0x181;
    b[0x4F] = 0x8000UL << 16;
    b[0x50] = (0x7FF8 - (D_L39_00240408->h158 << 3)) | ((long)(0x7FF8 - (D_L39_00240408->h15A << 3)) << 16);
    b[0x51] = (0x7FF8 - (D_L39_00240408->h158 << 3)) | ((long)((D_L39_00240408->h15A << 3) + 0x7FF8) << 16);
    func_L39_00597058(0, 0);
    b = D_L39_00228A30;
    b[0] = (((0x8116UL << 16) | 0x8000) << 31) | 1;
    b[1] = 0xEEEE;
    b[2] = 0x31001;
    b[3] = 0x47;
    b[4] = 5;
    b[5] = 8;
    b[6] = (0x8000UL << 17) | 0x261;
    b[7] = 0x14;
    b[8] = ((long)D_L39_00240408->h156 << 5) | ((long)(((u16)D_L39_00240408->h150 >> 6) & 0x3F) << 14) | ((long)D_L39_00240408->h154 << 20) | (0xEA80UL << 20);
    b[9] = 6;
    b[10] = (0x8800UL << 47) | 0x8010;
    b[11] = 0x5353;
    {
        s32 n = 12;
        s32 i;
        for (i = 0; i < 16; i++) {
            b[n++] = i << 9;
            b[n++] = (0x6FFC + i * 0x200) | ((long)(0x7FFC - (D_L39_00240408->h152 << 3)) << 16);
            b[n++] = (0x200 + i * 0x200) | ((long)D_L39_00240408->h152 << 20);
            b[n++] = (0x71FC + i * 0x200) | ((long)((D_L39_00240408->h152 << 3) + 0x7FFC) << 16);
        }
    }
    b = D_L39_00229170;
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
            b[n++] = (0x6FF8 + i * 0x200) | ((long)(0x7FF8 - (D_L39_00240408->h152 << 3)) << 16);
            b[n++] = (0x6FF8 + (i + 1) * 0x200) | ((long)((D_L39_00240408->h152 << 3) + 0x7FF8) << 16);
        }
    }
    func_0038CC88(D_L39_002292C0, D_L39_00229170, 0x150);
    b = D_001A3800;
    {
        s32 n = 8;
        s32 i;
        for (i = 0; i < 16; i++) {
            b[n++] = (0x6FF8 + i * 0x200) | ((long)(0x7FF8 - (D_L39_00240408->h152 << 3)) << 16);
            b[n++] = (0x6FF8 + (i + 1) * 0x200) | ((long)((D_L39_00240408->h152 << 3) + 0x7FF8) << 16);
        }
    }
    b = D_001A3940;
    {
        s32 n = 8;
        s32 i;
        for (i = 0; i < 16; i++) {
            if (D_L39_002413A0 != 0) {
                b[n++] = (i * 0x280 + 0x6BF8) | ((long)(0x7FF8 - (D_L39_00240408->h15A << 3)) << 16);
                b[n++] = ((i + 1) * 0x280 + 0x6BF8) | ((long)((D_L39_00240408->h15A << 3) + 0x7FF8) << 16);
            } else {
                b[n++] = ((i << 9) + 0x6FF8) | ((long)(0x7FF8 - (D_L39_00240408->h15A << 3)) << 16);
                b[n++] = (((i + 1) << 9) + 0x6FF8) | ((long)((D_L39_00240408->h15A << 3) + 0x7FF8) << 16);
            }
        }
    }
    b = D_001A3A80;
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
            b[n++] = u | ((long)D_L39_00240408->h152 << 20);
            v += 0x100;
            b[n++] = v | 0x10000000;
        }
    }
    b = D_001A3D70;
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
            b[n++] = u | ((long)D_L39_00240408->h152 << 20);
            v += 0x40;
            b[n++] = v | 0x4000000;
        }
    }
    {
        s32 x = D_001FC450[1];
        D_001A4060[2] = ((long)x >> 13) | (((((0xFFFFUL << 16) | 0xFF00) << 20) | 0x8000) << 4);
        D_001A4060[10] = (long)((x >> 8) | 0x24020000) | (0xC800UL << 19);
    }
    func_001264E0(0);
}
/* localdecomp:end func_L39_00597230 */

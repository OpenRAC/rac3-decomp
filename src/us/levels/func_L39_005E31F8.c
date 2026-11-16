#include "common.h"

/* NTSC-U counterpart of func_L39_005E5768 (src/levels/shared/L39_005E5678.c) */
typedef struct { s32 f0; void (*f4)(s32); s32 f8; } T_005E5678;
extern T_005E5678 D_001D8390_sda_005E31F8[] __attribute__((section(".sdata")));
extern s32 func_L01_00513698(void);

/* localdecomp:start func_L39_005E31F8 */
typedef struct S_005E5768 {
    u8 pad0[4];
    u8 f4;
    u8 f5;
    u8 f6;
    u8 pad7;
    s32 f8;
    u8 padC[0xAD - 0xC];
    u8 fAD;
} S_005E5768;


extern s32 D_001A5990[];
extern s32 D_L39_00241520;
extern s32 D_001D835C_sda;
__asm__(".extern D_001D835C_sda, 4");
__asm__(".extern D_001D8390_sda_005E31F8, 8");
extern char D_L39_00243C78[];
extern char D_L39_00243C80[];
extern char D_L39_00243C88[];
extern char D_L39_00243C90[];
extern s32 func_L01_00513698(void);
extern void *func_003B46F0(s32);
extern char *func_L39_005E5A88(void *, s32, s32);
extern char *func_0037DF98(s32);
extern int func_00120048(char *, char *, ...);

void func_L39_005E31F8(void) {
    s32 sel = 0;
    s32 i = 0;
    char *c;
    char *p;
    char *p2;

    s32 m;
    m = func_L01_00513698();
    switch (m) {
    case 0:
        sel = 0;
        break;
    case 1:
        sel = 1;
        break;
    case 2:
        sel = 2;
        break;
    case 3:
        sel = 3;
        break;
    }
    for (i = 0; i < D_001D835C_sda; i++) {
        switch (D_001D8390_sda_005E31F8[i].f0) {
        case 0x146: {
            char *a;
            char *b;
            a = func_L39_005E5A88(func_003B46F0(sel), 0, i);
            func_00120048(a, D_L39_00243C78, func_0037DF98(0x146));
            p = D_L39_00243C80;
            b = func_L39_005E5A88(func_003B46F0(sel), 1, i);
            if (((S_005E5768 *)D_001A5990)->f8 != 0) {
                c = func_0037DF98(0x237);
            } else {
                c = func_0037DF98(0x236);
            }
            func_00120048(b, p, c);
            break;
        }
        case 0x148: {
            char *a;
            char *b;
            a = func_L39_005E5A88(func_003B46F0(sel), 0, i);
            func_00120048(a, D_L39_00243C78, func_0037DF98(0x148));
            p = D_L39_00243C80;
            b = func_L39_005E5A88(func_003B46F0(sel), 1, i);
            if (((S_005E5768 *)D_001A5990)->f6 != 0) {
                c = func_0037DF98(0x175);
            } else {
                c = func_0037DF98(0x176);
            }
            func_00120048(b, p, c);
            break;
        }
        case 0x234: {
            char *a;
            a = func_L39_005E5A88(func_003B46F0(sel), 0, i);
            func_00120048(a, D_L39_00243C78, func_0037DF98(0x234));
            func_00120048(func_L39_005E5A88(func_003B46F0(sel), 1, i), D_L39_00243C88);
            break;
        }
        case 0x233: {
            char *a;
            a = func_L39_005E5A88(func_003B46F0(sel), 0, i);
            func_00120048(a, D_L39_00243C78, func_0037DF98(0x233));
            func_00120048(func_L39_005E5A88(func_003B46F0(sel), 1, i), D_L39_00243C88);
            break;
        }
        case 0x508: {
            char *a;
            char *b;
            a = func_L39_005E5A88(func_003B46F0(sel), 0, i);
            func_00120048(a, D_L39_00243C78, func_0037DF98(0x508));
            p = D_L39_00243C80;
            b = func_L39_005E5A88(func_003B46F0(sel), 1, i);
            if (((S_005E5768 *)D_001A5990)->fAD != 0) {
                c = func_0037DF98(0x175);
            } else {
                c = func_0037DF98(0x176);
            }
            func_00120048(b, p, c);
            break;
        }
        case 0x509: {
            char *a;
            char *b;
            a = func_L39_005E5A88(func_003B46F0(sel), 0, i);
            func_00120048(a, D_L39_00243C78, func_0037DF98(0x509));
            p = D_L39_00243C80;
            b = func_L39_005E5A88(func_003B46F0(sel), 1, i);
            if (D_L39_00241520 != 0) {
                c = func_0037DF98(0x175);
            } else {
                c = func_0037DF98(0x176);
            }
            func_00120048(b, p, c);
            break;
        }
        case 0x18E: {
            char *a;
            char *b;
            a = func_L39_005E5A88(func_003B46F0(sel), 0, i);
            func_00120048(a, D_L39_00243C90, func_0037DF98(0x142), func_0037DF98(0x18E));
            p2 = D_L39_00243C80;
            b = func_L39_005E5A88(func_003B46F0(sel), 1, i);
            if (((S_005E5768 *)D_001A5990)->f5 != 0) {
                c = func_0037DF98(0x175);
            } else {
                c = func_0037DF98(0x176);
            }
            func_00120048(b, p2, c);
            break;
        }
        case 0x18D: {
            char *a;
            char *b;
            a = func_L39_005E5A88(func_003B46F0(sel), 0, i);
            func_00120048(a, D_L39_00243C90, func_0037DF98(0x142), func_0037DF98(0x18D));
            p2 = D_L39_00243C80;
            b = func_L39_005E5A88(func_003B46F0(sel), 1, i);
            if (((S_005E5768 *)D_001A5990)->f4 != 0) {
                c = func_0037DF98(0x175);
            } else {
                c = func_0037DF98(0x176);
            }
            func_00120048(b, p2, c);
            break;
        }
        }
    }
}
/* localdecomp:end func_L39_005E31F8 */

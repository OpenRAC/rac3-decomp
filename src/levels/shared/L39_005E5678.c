#include "common.h"

/* localdecomp:start func_L39_005E5678 */
typedef struct { s32 f0; void (*f4)(s32); s32 f8; } T_005E5678;
extern s32 D_001D8378_sda;
__asm__(".extern D_001D8378_sda, 4");
extern T_005E5678 D_001D83A8_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D83A8_sda, 4");
extern T_005E5678 D_L39_00243ABC[] __attribute__((section(".sdata")));
extern s32 func_L01_00517688(void);
extern void func_L39_0061C0E0(s32, s32);
extern void func_L39_005D6468(s32, s32);
extern void func_L39_005F3548(s32, s32, s32);
extern void func_L01_00353C80(void *);
extern s32 func_L01_0049F168(s32);
extern void func_L01_00517748(s32);

void func_L39_005E5678(void *arg0, u32 arg1) {
    if (arg1 & 0xA040) {
        s32 i = D_001D8378_sda;
        if ((D_L39_00243ABC + i)->f0 != 0) {
            (D_001D83A8_sda + i)->f4(arg1);
        }
    } else if (arg1 & 0x900) {
        func_L39_0061C0E0(func_L01_00517688(), 0);
        func_L39_005D6468(func_L01_00517688(), 0);
        func_L39_005F3548(4, 0, 0);
        func_L01_00353C80(arg0);
    } else if (arg1 & 0x10) {
        func_L39_005F3548(4, 0, 0);
        func_L01_00517748(func_L01_0049F168(func_L01_00517688()));
        func_L01_00353C80(arg0);
    }
}
/* localdecomp:end func_L39_005E5678 */

/* localdecomp:start func_L39_005E5768 */
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


extern s32 D_001A5810[];
extern s32 D_002413A0;
extern s32 D_001D8374_sda;
__asm__(".extern D_001D8374_sda, 4");
__asm__(".extern D_001D83A8_sda, 8");
extern char D_L39_00243B10[];
extern char D_L39_00243B18[];
extern char D_L39_00243B20[];
extern char D_L39_00243B28[];
extern s32 func_L01_00517688(void);
extern void *func_003B9BD0(s32);
extern char *func_L39_005E7FF8(void *, s32, s32);
extern char *func_00381FF0(s32);
extern int func_00120048(char *, char *, ...);

void func_L39_005E5768(void) {
    s32 sel = 0;
    s32 i = 0;
    char *c;
    char *p;
    char *p2;

    s32 m;
    m = func_L01_00517688();
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
    for (i = 0; i < D_001D8374_sda; i++) {
        switch (D_001D83A8_sda[i].f0) {
        case 0x146: {
            char *a;
            char *b;
            a = func_L39_005E7FF8(func_003B9BD0(sel), 0, i);
            func_00120048(a, D_L39_00243B10, func_00381FF0(0x146));
            p = D_L39_00243B18;
            b = func_L39_005E7FF8(func_003B9BD0(sel), 1, i);
            if (((S_005E5768 *)D_001A5810)->f8 != 0) {
                c = func_00381FF0(0x237);
            } else {
                c = func_00381FF0(0x236);
            }
            func_00120048(b, p, c);
            break;
        }
        case 0x148: {
            char *a;
            char *b;
            a = func_L39_005E7FF8(func_003B9BD0(sel), 0, i);
            func_00120048(a, D_L39_00243B10, func_00381FF0(0x148));
            p = D_L39_00243B18;
            b = func_L39_005E7FF8(func_003B9BD0(sel), 1, i);
            if (((S_005E5768 *)D_001A5810)->f6 != 0) {
                c = func_00381FF0(0x175);
            } else {
                c = func_00381FF0(0x176);
            }
            func_00120048(b, p, c);
            break;
        }
        case 0x234: {
            char *a;
            a = func_L39_005E7FF8(func_003B9BD0(sel), 0, i);
            func_00120048(a, D_L39_00243B10, func_00381FF0(0x234));
            func_00120048(func_L39_005E7FF8(func_003B9BD0(sel), 1, i), D_L39_00243B20);
            break;
        }
        case 0x233: {
            char *a;
            a = func_L39_005E7FF8(func_003B9BD0(sel), 0, i);
            func_00120048(a, D_L39_00243B10, func_00381FF0(0x233));
            func_00120048(func_L39_005E7FF8(func_003B9BD0(sel), 1, i), D_L39_00243B20);
            break;
        }
        case 0x508: {
            char *a;
            char *b;
            a = func_L39_005E7FF8(func_003B9BD0(sel), 0, i);
            func_00120048(a, D_L39_00243B10, func_00381FF0(0x508));
            p = D_L39_00243B18;
            b = func_L39_005E7FF8(func_003B9BD0(sel), 1, i);
            if (((S_005E5768 *)D_001A5810)->fAD != 0) {
                c = func_00381FF0(0x175);
            } else {
                c = func_00381FF0(0x176);
            }
            func_00120048(b, p, c);
            break;
        }
        case 0x509: {
            char *a;
            char *b;
            a = func_L39_005E7FF8(func_003B9BD0(sel), 0, i);
            func_00120048(a, D_L39_00243B10, func_00381FF0(0x509));
            p = D_L39_00243B18;
            b = func_L39_005E7FF8(func_003B9BD0(sel), 1, i);
            if (D_002413A0 != 0) {
                c = func_00381FF0(0x175);
            } else {
                c = func_00381FF0(0x176);
            }
            func_00120048(b, p, c);
            break;
        }
        case 0x18E: {
            char *a;
            char *b;
            a = func_L39_005E7FF8(func_003B9BD0(sel), 0, i);
            func_00120048(a, D_L39_00243B28, func_00381FF0(0x142), func_00381FF0(0x18E));
            p2 = D_L39_00243B18;
            b = func_L39_005E7FF8(func_003B9BD0(sel), 1, i);
            if (((S_005E5768 *)D_001A5810)->f5 != 0) {
                c = func_00381FF0(0x175);
            } else {
                c = func_00381FF0(0x176);
            }
            func_00120048(b, p2, c);
            break;
        }
        case 0x18D: {
            char *a;
            char *b;
            a = func_L39_005E7FF8(func_003B9BD0(sel), 0, i);
            func_00120048(a, D_L39_00243B28, func_00381FF0(0x142), func_00381FF0(0x18D));
            p2 = D_L39_00243B18;
            b = func_L39_005E7FF8(func_003B9BD0(sel), 1, i);
            if (((S_005E5768 *)D_001A5810)->f4 != 0) {
                c = func_00381FF0(0x175);
            } else {
                c = func_00381FF0(0x176);
            }
            func_00120048(b, p2, c);
            break;
        }
        }
    }
}
/* localdecomp:end func_L39_005E5768 */

/* localdecomp:start func_L39_005E5CD8 */
extern s32 D_001A5810[];
extern f32 D_001D8394_sda;
extern f32 D_001D8398_sda;
extern f32 D_001D839C_sda;
__asm__(".extern D_001D8394_sda, 4");
__asm__(".extern D_001D8398_sda, 4");
__asm__(".extern D_001D839C_sda, 4");
extern void func_L01_00516558(s32, f32 *, f32 *);
extern void func_L01_00516470(s32, f32, f32);

void func_L39_005E5CD8(void) {
    f32 y1, x1, y0, x0;
    f32 a, b, base, d;
    f32 e = 0.008f;
    f32 z = 0.0f;

    b = (f32)D_001A5810[3] * (1.0f / 1024.0f);
    a = (f32)D_001A5810[4] * (1.0f / 1024.0f);
    x0 = z;
    y0 = z;
    x1 = z;
    y1 = z;
    func_L01_00516558(0x1E0009, &x0, &y0);
    func_L01_00516558(0x1E000C, &x1, &y1);
    base = D_001D8394_sda + D_001D839C_sda;
    d = D_001D8398_sda - base - e;
    base = base + e;
    x0 = base + d * b;
    x1 = base + d * a;
    func_L01_00516470(0x1E0009, x0, y0);
    func_L01_00516470(0x1E000C, x1, y1);
}
/* localdecomp:end func_L39_005E5CD8 */

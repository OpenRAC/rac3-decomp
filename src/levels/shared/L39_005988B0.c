#include "common.h"

/* declared by functions of L39_00598780.c, which this file was cut from */
typedef struct S_00598780 {
     char pad0[0x40];
     s32 f40;
     char pad44[0x10];
     s32 f54;
     s32 f58;
     s32 a5C[4];
     s32 a6C[4];
     s16 f7C;
     s16 f7E;
     s32 f80;
     char pad84[4];
     s32 f88;
} S_00598780;
extern S_00598780 D_L39_0025F440;

/* localdecomp:start func_L39_005988B0 */
typedef struct S_005988B0 {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ s32 f40;
    /* 0x44 */ s32 f44;
    /* 0x48 */ char pad48[0x14];
    /* 0x5C */ s32 a5C[4];
    /* 0x6C */ s32 a6C[4];
    /* 0x7C */ s16 f7C;
    /* 0x7E */ s16 f7E;
} S_005988B0;
typedef struct Box_005988B0 {
    u16 h[14];
} Box_005988B0;
extern char D_L39_002428C0[];
extern char D_L39_002428C8[];
extern u8 D_L39_002429AC;
__asm__(".extern D_L39_002429AC, 16");
extern u8 D_L39_002429AD;
__asm__(".extern D_L39_002429AD, 16");
extern u8 D_L39_002439FC;
__asm__(".extern D_L39_002439FC, 16");
extern u8 D_L39_0024BE70;
__asm__(".extern D_L39_0024BE70, 16");
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403F8, 16");
extern s32 D_L39_00240304;
__asm__(".extern D_L39_00240304, 16");
extern s32 D_L39_0024CBD0;
__asm__(".extern D_L39_0024CBD0, 16");
extern f32 D_L39_0024CBD4;
__asm__(".extern D_L39_0024CBD4, 16");
extern s32 D_001D7200_sda;
__asm__(".extern D_001D7200_sda, 4");
extern char *D_001D717C_sda;
__asm__(".extern D_001D717C_sda, 4");
extern char *D_001D7180_sda;
__asm__(".extern D_001D7180_sda, 4");
extern char *D_001D7184_sda;
__asm__(".extern D_001D7184_sda, 4");
extern u8 D_001D7188_sda;
__asm__(".extern D_001D7188_sda, 1");
extern u8 D_L39_0024BE70_005988B0 __attribute__((section(".sdata")));
extern u8 D_001D729D_sda;
__asm__(".extern D_001D729D_sda, 1");
extern void func_L39_0058B1B8(s32, s32, s32, s32);
extern void func_L39_00589538(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_L01_003B84E8_005988B0(void);
extern char *func_00381FF0(s32);
extern char *func_L01_0047F3D8(s32);
extern void func_003910C0(u16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_0038E150(s32);
extern void func_003AF408(void *, s32, char *, s32, s32, s32, s32, char *, char *, s32);
extern void func_00389370(void);
extern void *func_0011D534(void *, s32, s32);
extern s32 func_00120048(char *, char *, ...);

void func_L39_005988B0(void) {
    char buf[0x200];
    Box_005988B0 box;
    char *text;
    char *a;
    char *b;
    s32 id1;
    s32 id2;
    s32 flag;
    u8 v;
    f32 z0, z1;

    if (!D_L39_0025F440.f7E) {
        func_L39_0058B1B8(0, 0, 0, 0x30);
    }
    if (D_L39_0025F440.f7C) {
        return;
    }
    func_L39_00589538(0);
    func_003A9440(0x42, 0x8000000044UL);
    func_003A9440(0x47, 0x5360B);
    switch (D_L39_0025F440.f40) {
    case 1:
        if (D_001D7200_sda == -2) {
            flag = 1;
            if (D_L39_0025F440.a5C[0] <= 0) {
                break;
            }
            id1 = 0;
            text = D_L39_002428C0;
            id2 = 0;
            func_L01_003B84E8_005988B0();
            switch (D_L39_002403F8) {
            case 8:
                id1 = 0x8E3;
                id2 = 0x8DF;
                text = func_L01_0047F3D8(0x1A3);
                break;
            case 14:
                if (D_L39_0024BE70) {
                    break;
                }
            case 15:
                id1 = 0x8E3;
                id2 = 0x8DF;
                text = func_L01_0047F3D8(0x1A0);
                break;
            case 33:
                id1 = 0x8E3;
                id2 = 0x8DF;
                text = func_L01_0047F3D8(0x11E9);
                break;
            case 12:
            case 13:
            case 31:
            case 32:
                text = func_L01_0047F3D8(0x1AF);
                break;
            case 9:
            case 10:
                text = func_L01_0047F3D8(0x1AD);
                break;
            case 16:
            case 17:
                text = func_L01_0047F3D8(0x1AE);
                break;
            case 25:
            case 29:
                if (D_L39_002439FC) {
                    text = func_00381FF0(0x1EBB);
                } else {
                    text = func_L01_0047F3D8(0x1AB);
                }
                break;
            case 23:
            case 30:
                text = func_L01_0047F3D8(0x1AC);
                break;
            case 19:
                id1 = 0x8DE;
                text = func_L01_0047F3D8(0x1B0);
                break;
            case 20:
                id1 = 0x8DE;
                text = func_L01_0047F3D8(0x1B2);
                break;
            case 3:
                id1 = 0x8DE;
                text = func_L01_0047F3D8(0x194);
                if (((S_005988B0 *)&D_L39_0025F440)->f44) {
                    id1 = 0;
                }
                break;
            case 21:
                if (D_L39_0024BE70) {
                    id1 = 0x11E8;
                    text = func_L01_0047F3D8(0x196);
                } else if (D_L39_002429AC) {
                    char *fmt = D_L39_002428C8;
                    id1 = 0x8E2;
                    id2 = 0x8DF;
                    b = func_L01_0047F3D8(0x199);
                    func_00120048(buf, fmt, b, 1, 1, func_L01_0047F3D8(0x19A));
                    text = buf;
                } else {
                    id1 = 0x11E8;
                    text = func_L01_0047F3D8(0x199);
                }
                break;
            case 24:
                id1 = 0x8DE;
                text = func_L01_0047F3D8(0x1B2);
                break;
            case 22:
                id1 = 0x8DE;
                text = func_L01_0047F3D8(0x1B1);
                break;
            case 27: {
                char *fmt = D_L39_002428C8;
                id1 = 0x8E2;
                id2 = 0x8DF;
                b = func_L01_0047F3D8(0x1A2);
                func_00120048(buf, fmt, b, 1, 1, func_L01_0047F3D8(0x11E8));
                text = buf;
                break;
            }
            case 26:
                id1 = 0x8E2;
                id2 = 0x8DF;
                text = func_L01_0047F3D8(0x1A5);
                break;
            case 4:
            case 5:
            case 6:
                if (D_L39_002429AC && !D_L39_0024BE70_005988B0) {
                    id1 = 0x8E2;
                    id2 = 0x8DF;
                    text = func_L01_0047F3D8(0x19C);
                } else {
                    v = D_L39_002429AC ? D_001D729D_sda : D_L39_002429AD;
                    if (v) {
                        id1 = 0x8E2;
                        text = func_L01_0047F3D8(0x19C);
                    } else if (D_L39_0024BE70) {
                        id1 = 0x11E8;
                        text = func_L01_0047F3D8(0x196);
                    } else {
                        id1 = 0x254;
                        id2 = 0x194A;
                        text = func_L01_0047F3D8(0x19E);
                    }
                }
                break;
            case 7:
                id1 = 0x11E8;
                text = func_L01_0047F3D8(0x196);
                break;
            default:
                flag = 0;
                break;
            }
            if (flag) {
                Box_005988B0 t;
                func_0011D534(&t, 0, sizeof(t));
                t.h[1] = D_L39_00240304;
                t.h[2] = 0x4C;
                t.h[3] = 0x1B4;
                t.h[4] = 0x100;
                t.h[5] = 0x68;
                t.h[8] = 0x10;
                t.h[9] = 1;
                box = t;
                a = id1 ? func_L01_0047F3D8(id1) : 0;
                b = id2 ? func_L01_0047F3D8(id2) : 0;
                func_0038E150(1);
                func_003AF408(&box, 0x8066CCFF, text, 1, 1, -1, 0, a, b, 0);
            }
        }
        break;
    case 9: {
        u16 *bp;
        s32 alpha;
        char *a;
        char *b;

        z0 = 0.0f;
        z1 = 0.0f;
        alpha = D_L39_0024CBD4 * 100.0f + 0.5f + (D_L39_0024CBD0 == 1 ? z0 : z1);
        bp = box.h;
        func_003910C0(bp, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, alpha, 0x10, 3);
        a = D_001D717C_sda;
        if (!a) {
            a = func_L01_0047F3D8(0x8E2);
        }
        b = D_001D7180_sda;
        if (!b) {
            b = func_L01_0047F3D8(0x8DF);
        }
        text = D_001D7184_sda;
        if (!text) {
            text = func_L01_0047F3D8(0x17C);
        }
        func_0038E150(1);
        func_003AF408(bp, 0x80F0F0F0, text, 1, 1, -1, 0, a, b, D_001D7188_sda);
        break;
    }
    case 10: {
        u16 *bp;
        s32 alpha;
        char *a;

        z0 = 0.0f;
        z1 = 0.0f;
        alpha = D_L39_0024CBD4 * 100.0f + 0.5f + (D_L39_0024CBD0 == 1 ? z0 : z1);
        bp = box.h;
        func_003910C0(bp, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, alpha, 0x10, 3);
        a = D_001D717C_sda;
        if (!a) {
            a = func_L01_0047F3D8(0x8E2);
        }
        text = D_001D7184_sda;
        if (!text) {
            text = func_L01_0047F3D8(0x17C);
        }
        func_0038E150(1);
        func_003AF408(bp, 0x80F0F0F0, text, 1, 1, -1, 0, a, 0, D_001D7188_sda);
        break;
    }
    }
    func_00389370();
}
/* localdecomp:end func_L39_005988B0 */

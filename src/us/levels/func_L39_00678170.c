#include "common.h"

/* NTSC-U counterpart of func_L39_0067ABC8 (src/levels/39_multiplayer_menu/L39_0067ABC8.c) */
extern s32 D_L39_0024D1C0;
extern s32 D_L39_0024D1F4;
extern int func_00126150(void);
extern int func_001260F0(int arg0, int arg1);
extern void func_L39_004B3918(void);

/* localdecomp:start func_L39_00678170 */
typedef struct { s32 type; s32 code; s32 c; s32 d; } S16_0067ABC8;
typedef struct { u8 pad[0x1C4]; s32 pad_held; } SPad_0067ABC8;
typedef struct { s32 a; void *b; s32 c; void *d; s32 e; } SA_0067ABC8;
typedef struct { s32 a; s32 b; } SB_0067ABC8;
typedef struct { s32 status; void (*func)(void); void *stack; s32 size; void *gp; s32 prio; } ST_0067ABC8;

extern s32 D_L39_00242A90;
extern u8 D_L39_00247B94;
extern f32 D_L39_00247B90;
extern s32 D_L39_00247B98;
extern s32 D_L39_0024D1C4;
extern S16_0067ABC8 D_L39_0024D1C8 __attribute__((section(".sdata")));
extern S16_0067ABC8 D_L39_0024D1D8 __attribute__((section(".sdata")));
extern s32 D_L39_0024D1E8;
extern void *D_L39_0024D1EC;
extern s32 D_L39_0024D1F8;
typedef struct { s32 magic; void *a; void *b; } SM_0067ABC8;
extern SM_0067ABC8 D_L39_00240680 __attribute__((section(".sdata")));
extern u8 D_L39_00240690[0x20] __attribute__((section(".sdata")));
extern s32 D_L39_002406B0[8] __attribute__((section(".sdata")));
extern SPad_0067ABC8 *D_L39_002412E4;
extern s32 D_L39_002415C0;
extern u8 D_L39_0036DC90[];
extern u8 D_L39_0036DE30[];
extern u8 D_L39_002468D8[];
extern u8 D_L39_0049D950[];
extern u8 D_L39_00248140[] __attribute__((section(".sdata")));
extern u8 D_001A5FD2 __attribute__((section(".data")));
extern u16 D_L39_0024D1F0;
__asm__(".extern D_L39_0024D140, 0");
extern u8 D_L39_0024D140[] __attribute__((section(".sdata"), aligned(8)));
__asm__(".extern D_L39_0024D180, 0");
extern u8 D_L39_0024D180[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_002468C8, 4");
__asm__(".extern D_L39_002468D4, 4");
extern s32 D_L39_002468C8;
extern u8 D_L39_002468D0;
extern s32 D_L39_002468D4;

extern void func_003BEBF8(f32 *, f32, f32);
extern s32 func_003894A0(s32, s32, f32);
s32 func_L01_005130C8(s32, s32);
extern void func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern s32 func_001985B8(void);
extern void *func_0011D534(void *, s32, s32);
extern s32 func_L39_004B3710(void *, s32, s32, s32, void *);
extern s32 func_L39_004B3D88(s32, void *, u16);
extern s32 func_L39_004B3E20(s32 *, void *, s32, u16 *);
extern s32 func_L39_004B3750(void *);
extern s32 func_L39_004B3D28(void *);
extern s32 func_0011D2EC(void *, void *, s32);
extern void func_L39_006791F0(void *, void *);
extern s32 func_L39_005F0E48(s32, s32, void *);
extern s32 func_L39_004B3C10(void);
extern s32 func_0037DF98(s32);
extern void func_001375B0(void *, void *, s32);
extern void *memcpy(void *, const void *, unsigned int);
extern int func_L39_0067C0B0(void);
extern s32 func_00126060(void *);
extern s32 func_001271D0(s32, s32);
extern void func_L39_00518630(s32);
extern void func_00127108(s32);
extern s32 func_L01_00512AB0(s32, s32, s32);
extern s32 func_003E29B8(s32, s32);
extern s32 func_L01_00514680(s32, s32, s32);
extern s32 func_L01_00512480(s32, f32, f32);
extern s32 func_L01_00513548(s32, f32, f32);
extern s32 func_L01_00512FE8(s32, s32);
s32 func_L01_00512C88(s32, s32, s32);
extern s32 func_00120048(u8 *, u8 *, ...);
void func_L01_00475040(void);
extern void func_L39_005A43D8(void);
void func_L39_00677D90(void);
extern s32 func_L39_0067C078(void);
extern void *func_001206F4(void *, void *);
void func_L39_0067A788_00678170(u8 *);

void func_L39_00678170(void) {
    s32 col;
    s32 c;
    s32 i;

    if (D_L39_00242A90 == -2) {
        if (D_L39_00247B94) {
            func_003BEBF8(&D_L39_00247B90, 0.0f, 0.0666666701f);
        } else {
            func_003BEBF8(&D_L39_00247B90, 1.0f, 0.0666666701f);
        }
        c = D_L39_00247B98;
        col = func_003894A0(c & 0xFFFFFF, c, D_L39_00247B90);
        func_L01_005130C8(0x460001, col);
        func_L01_005130C8(0x460002, col);
        if (D_L39_00247B94) {
            if (D_L39_00247B90 == 0.0f) {
                if (D_L39_0024D1C0 == 11 || D_L39_0024D1C0 == 12) {
                    D_L39_002415C0 = 0;
                    D_L39_00242A90 = -2;
                    func_L39_005BD7D8(12, 2, 0, 0, 0);
                } else if (D_L39_0024D1C0 == 13) {
                    func_001985B8();
                    D_L39_00242A90 = -2;
                    D_L39_002415C0 = 1;
                    func_L39_005BD7D8(12, 2, 0, 0, 0);
                }
            }
            return;
        }
    }

    switch (D_L39_0024D1C0) {
    case 0: {
        SA_0067ABC8 a;
        SB_0067ABC8 b;
        s32 r;
        {
        func_0011D534(&D_L39_0024D1C8, 0, 0x10);
        func_0011D534(&D_L39_0024D1D8, 0, 0x10);
        func_0011D534(&a, 0, 0x14);
        a.a = 1;
        a.e = 0x10000;
        a.c = 8;
        a.d = D_L39_0049D950;
        a.b = &D_L39_002468C8;
        func_0011D534(&b, 0, 8);
        b.a = 0x3C;
        b.b = 0x20;
        r = func_L39_004B3710(&a, 0x30, 0, 0, &b);
        if (r < 0) {
            D_L39_0024D1C0 = 8;
            D_L39_0024D1E8 = r;
            D_L39_0024D1C4 = 0;
            func_L39_004B3918();
        } else if (D_L39_002468D0) {
            D_L39_0024D1C0 = 1;
        } else {
            D_L39_0024D1C0 = 2;
        }
        }
        break;
    }
    case 1: {
        u8 buf[0x100];
        u16 len;
        s32 mode;
        s32 r;

        r = func_L39_004B3D88(1, D_L39_0024D1EC, D_L39_0024D1F0);
        if (r < 0) {
            D_L39_0024D1C0 = 8;
            D_L39_0024D1C4 = 1;
            D_L39_0024D1E8 = r;
        } else {
            func_L39_004B3E20(&mode, buf, 0x100, &len);
            D_L39_0024D1C0 = 2;
        }
        break;
    }
    case 2: {
        s32 r;

        D_L39_00240680.magic = 0x3C3360AB;
        D_L39_00240680.a = D_L39_00240690;
        D_L39_00240680.b = D_L39_002406B0;
        D_L39_002406B0[0] = 0;
        r = func_L39_004B3750(&D_L39_00240680);
        if (r < 0) {
            D_L39_0024D1C0 = 8;
            D_L39_0024D1C4 = 2;
            D_L39_0024D1E8 = r;
        } else {
            D_L39_0024D1C0 = 3;
        }
        break;
    }
    case 3: {
        s32 r;
        s32 t;

        r = func_L39_004B3D28(&D_L39_0024D1C8);
        if (r < 0) {
            D_L39_0024D1C0 = 8;
            D_L39_0024D1C4 = 2;
            D_L39_0024D1E8 = r;
            break;
        }
        if (func_0011D2EC(&D_L39_0024D1D8, &D_L39_0024D1C8, 0x10)) {
            t = D_L39_0024D1C8.type;
            if (t == 5) {
                D_L39_0024D1C0 = 9;
                func_L39_004B3918();
            } else if (t == 6 || t == 7) {
                D_L39_0024D1C0 = 4;
                D_L39_0024D1C4 = 2;
                func_L39_006791F0(&D_L39_0024D1C8, D_L39_0036DC90);
            }
        }
        D_L39_0024D1D8 = D_L39_0024D1C8;
        if (D_L39_0024D1C0 == 3 && (D_L39_002412E4->pad_held & 0x10)) {
            func_L39_005F0E48(0x17, 0, 0);
            r = func_L39_004B3C10();
            if (r < 0) {
                D_L39_0024D1C0 = 8;
                D_L39_0024D1C4 = 2;
                D_L39_0024D1E8 = r;
            }
            D_L39_0024D1C0 = 5;
        }
        break;
    }
    case 5: {
        s32 r;
        s32 t;

        r = func_L39_004B3D28(&D_L39_0024D1C8);
        if (r < 0) {
            D_L39_0024D1C0 = 8;
            D_L39_0024D1C4 = 2;
            D_L39_0024D1E8 = r;
            break;
        }
        if (func_0011D2EC(&D_L39_0024D1D8, &D_L39_0024D1C8, 0x10)) {
            t = D_L39_0024D1C8.type;
            if (t == 5) {
                D_L39_0024D1C0 = 9;
                func_L39_004B3918();
            } else if (t == 6 || t == 7) {
                D_L39_0024D1C0 = 4;
                D_L39_0024D1C4 = 2;
                func_L39_006791F0(&D_L39_0024D1C8, D_L39_0036DC90);
            } else if (t == 2) {
                D_L39_0024D1C0 = 6;
                D_L39_0024D1C4 = 11;
                func_L39_004B3918();
            }
        }
        break;
    }
    case 8: {
        s32 r;

        r = D_L39_0024D1E8;
        if (r >= -0x194 && r < -0x190) {
            D_L39_0024D1C0 = 4;
            D_L39_0024D1C4 = 2;
            D_L39_0024D1C8.type = 6;
            D_L39_0024D1C8.code = r;
            func_L39_006791F0(&D_L39_0024D1C8, D_L39_0036DC90);
        } else {
            D_L39_0024D1C0 = 4;
            D_L39_0024D1C4 = 4;
            func_001206F4(D_L39_0036DC90, func_0037DF98(0x11B1));
            func_001206F4(D_L39_0036DC90 + 0x50, func_0037DF98(0x11B1));
            func_001206F4(D_L39_0036DC90 + 0xF0, func_0037DF98(0x11B1));
        }
        break;
    }
    case 4: {
        s32 pad;

        pad = D_L39_002412E4->pad_held;
        if (pad & 0x40) {
            func_L39_005F0E48(4, 0, 0);
            D_L39_0024D1C0 = D_L39_0024D1C4;
        } else if (pad & 0x10) {
            func_L39_005F0E48(0x17, 0, 0);
            D_L39_0024D1C0 = 6;
            D_L39_0024D1C4 = 12;
            func_L39_004B3918();
        }
        break;
    }
    case 6:
        func_L39_0067C078();
        D_L39_0024D1C0 = 7;
        break;
    case 7: {
        s32 info[16];
        {
        func_001375B0(info, D_L39_0024D140, 0x40);
        if (info[12] == 5) {
            D_L39_0024D1C0 = D_L39_0024D1C4;
        } else if (func_L39_0067C0B0() > 30000) {
            D_L39_0024D1C0 = D_L39_0024D1C4;
        }
        }
        break;
    }
    case 9: {
        ST_0067ABC8 t;

        func_001260F0(func_00126150(), D_L39_0024D1F4);
        t.func = func_L39_00677D90;
        t.stack = (void *)((s32)D_L39_0036DE30 & ~0xF);
        D_L39_0024D1F8 = 3600;
        D_001A5FD2 = 0;
        t.size = 0x1FF0;
        t.gp = D_L39_00248140;
        t.prio = 0x28;
        D_L39_002468D4 = func_00126060(&t);
        func_001271D0(D_L39_002468D4, 0);
        D_L39_0024D1C0 = 10;
        break;
    }
    case 10:
        D_L39_0024D1F8 = D_L39_0024D1F8 - 1;
        if (D_L39_0024D1F8 <= 0 || D_001A5FD2) {
            D_L39_0024D1C0 = 13;
        }
        if (D_L39_002412E4->pad_held & 0x10) {
            func_L39_005F0E48(0x17, 0, 0);
            D_L39_0024D1C0 = 6;
            D_L39_0024D1C4 = 12;
            func_L39_00518630(D_L39_002468D4);
        } else {
            func_00127108(1000);
        }
        break;
    case 11:
    case 12:
    case 13:
        break;
    }

    for (i = 0x460004; i <= 0x460007; i++) {
        func_L01_00512AB0(i, 1, 0);
        func_003E29B8(i, 2);
        func_L01_005130C8(i, 0x8066CCFF);
    }
    func_L01_00512AB0(0x46000F, 1, 0);
    func_L01_00512AB0(0x460008, 1, 0);

    switch (D_L39_0024D1C0) {
    case 0:
    case 1:
    case 2:
    case 3:
        func_L01_00512AB0(0x460008, 1, 1);
        func_L01_005130C8(0x460008, 0xAFAFAFAF);
        func_L01_00512AB0(0x460004, 1, 1);
        func_L01_00514680(0x460004, 1, 0);
        func_L01_00512480(0x460004, 0.5f, 0.275f);
        func_L01_00513548(0x460004, 0.8f, 0.2f);
        func_L01_00512FE8(0x460004, func_0037DF98(0x11AD));
        func_L01_00512AB0(0x460007, 1, 1);
        func_003E29B8(0x460007, 1);
        func_L01_00512480(0x460007, 0.5f, 0.55f);
        func_L01_00513548(0x460007, 0.8f, 0.2f);
        func_L01_00512FE8(0x460007, func_0037DF98(0x1259));
        func_L01_005130C8(0x460007, func_003894A0(0x8066CCFF, 0, 0.5f));
        func_L01_00514680(0x460007, 1, 0);
        func_L01_00512C88(0x460007, 3, 1);
        break;
    case 10:
        func_L01_00512AB0(0x460004, 1, 1);
        func_L01_00512480(0x460004, 0.5f, 0.275f);
        func_L01_00513548(0x460004, 0.8f, 0.2f);
        func_00120048(D_L39_0024D180, D_L39_002468D8, func_0037DF98(0x1356));
        func_L01_00512FE8(0x460004, (s32)D_L39_0024D180);
        break;
    case 4:
        func_L01_00512AB0(0x460008, 1, 1);
        func_L01_005130C8(0x460008, 0x803040AF);
        func_L01_00512AB0(0x460004, 1, 1);
        func_L01_00514680(0x460004, 1, 0);
        func_L01_00512480(0x460004, 0.5f, 0.275f);
        func_L01_00513548(0x460004, 0.8f, 0.2f);
        func_L01_00512FE8(0x460004, (s32)D_L39_0036DC90);
        func_L01_00512AB0(0x460005, 1, 1);
        func_L01_00514680(0x460005, 0, 0);
        func_003E29B8(0x460005, 1);
        func_L01_00512480(0x460005, 0.5f, 0.4f);
        func_L01_00513548(0x460005, 0.8f, 0.3f);
        func_L01_00512FE8(0x460005, (s32)(D_L39_0036DC90 + 0x50));
        func_L01_00512AB0(0x460006, 1, 1);
        func_L01_00514680(0x460006, 1, 0);
        func_L01_00512480(0x460006, 0.5f, 0.8f);
        func_L01_00513548(0x460006, 0.8f, 0.2f);
        func_L01_00512FE8(0x460006, (s32)(D_L39_0036DC90 + 0xF0));
        func_L01_00512AB0(0x460007, 1, 1);
        func_003E29B8(0x460007, 1);
        func_L01_00512480(0x460007, 0.5f, 0.55f);
        func_L01_00513548(0x460007, 0.8f, 0.2f);
        func_L01_00512FE8(0x460007, func_0037DF98(0x1259));
        func_L01_005130C8(0x460007, func_003894A0(0x8066CCFF, 0, 0.5f));
        func_L01_00514680(0x460007, 1, 0);
        func_L01_00512C88(0x460007, 3, 1);
        func_L01_00512AB0(0x46000F, 1, 1);
        break;
    case 5:
        func_L01_00512AB0(0x460004, 1, 1);
        func_L01_00514680(0x460004, 1, 0);
        func_L01_00512480(0x460004, 0.5f, 0.25f);
        func_L01_00513548(0x460004, 0.8f, 0.2f);
        func_L01_00512FE8(0x460004, func_0037DF98(0x11AF));
        func_L01_00514680(0x460006, 0, 0);
        func_L01_00512AB0(0x460010, 1, 0);
        break;
    case 6:
        func_L01_00514680(0x460004, 1, 0);
        func_L01_00512AB0(0x460004, 1, 1);
        func_L01_00512480(0x460004, 0.5f, 0.25f);
        func_L01_00513548(0x460004, 0.8f, 0.2f);
        func_L01_00512FE8(0x460004, func_0037DF98(0x11B0));
        func_L01_00512AB0(0x460010, 1, 0);
        break;
    case 7:
        func_L01_00512AB0(0x460004, 1, 1);
        func_L01_00512480(0x460004, 0.15f, 0.2f);
        func_L01_00513548(0x460004, 0.8f, 0.2f);
        func_L01_00512C88(0x460004, 1, 3);
        func_L01_00514680(0x460004, 0, 1);
        func_L01_00512FE8(0x460004, func_0037DF98(0x11B0));
        func_L01_00512AB0(0x460005, 1, 1);
        func_L01_00514680(0x460005, 1, 1);
        func_L01_00512480(0x460005, 0.5f, 0.3f);
        func_L01_00513548(0x460005, 0.8f, 0.2f);
        func_003E29B8(0x460005, 1);
        func_L01_00512FE8(0x460005, (s32)D_L39_0024D140);
        func_L01_005130C8(0x460005, func_003894A0(0x80000000, 0x8066CCFF, 0.75f));
        func_L01_00512AB0(0x460010, 1, 0);
        break;
    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
        break;
    }
    func_L01_00475040();
    func_L39_005A43D8();
    if (D_L39_0024D1C0 == 11 || D_L39_0024D1C0 == 12) {
        D_L39_00247B94 = 1;
    } else if (D_L39_0024D1C0 == 13) {
        D_L39_00247B94 = 1;
    }
}
/* localdecomp:end func_L39_00678170 */

#include "common.h"

typedef struct { int a, b, c; } T;

/* declared by functions of L39_0067A788.c, which this file was cut from */
void func_L01_004126A8(s32);

/* declared by functions of L39_0067AB38.c, which this file was cut from */
extern s32 D_L39_0024D0C0;
extern s32 D_L39_0024D0F4;
extern int func_00126150(void);
extern int func_001260F0(int arg0, int arg1);
extern void func_L39_004B3B18(void);

/* localdecomp:start func_L39_0067ABC8 */
typedef struct { s32 type; s32 code; s32 c; s32 d; } S16_0067ABC8;
typedef struct { u8 pad[0x1C4]; s32 pad_held; } SPad_0067ABC8;
typedef struct { s32 a; void *b; s32 c; void *d; s32 e; } SA_0067ABC8;
typedef struct { s32 a; s32 b; } SB_0067ABC8;
typedef struct { s32 status; void (*func)(void); void *stack; s32 size; void *gp; s32 prio; } ST_0067ABC8;

extern s32 D_L39_00242910;
extern u8 D_L39_00247A34;
extern f32 D_L39_00247A30;
extern s32 D_L39_00247A38;
extern s32 D_L39_0024D0C4;
extern S16_0067ABC8 D_L39_0024D0C8 __attribute__((section(".sdata")));
extern S16_0067ABC8 D_L39_0024D0D8 __attribute__((section(".sdata")));
extern s32 D_L39_0024D0E8;
extern void *D_L39_0024D0EC;
extern s32 D_L39_0024D0F8;
typedef struct { s32 magic; void *a; void *b; } SM_0067ABC8;
extern SM_0067ABC8 D_L39_00240500 __attribute__((section(".sdata")));
extern u8 D_L39_00240510[0x20] __attribute__((section(".sdata")));
extern s32 D_L39_00240530[8] __attribute__((section(".sdata")));
extern SPad_0067ABC8 *D_L39_00241164;
extern s32 D_L39_00241440;
extern u8 D_L39_0036DBA0[];
extern u8 D_L39_0036DD40[];
extern u8 D_L39_00246758[] __attribute__((aligned(8)));
extern u8 D_L39_00246778[];
extern u8 D_L39_0049D890[];
extern u8 D_L39_00247FC0[] __attribute__((section(".sdata")));
extern u8 D_001A58C7 __attribute__((section(".data")));
extern u8 D_001A5E52 __attribute__((section(".data")));
extern u16 D_L39_0024D0F0;
__asm__(".extern D_L39_0024D040, 0");
extern u8 D_L39_0024D040[] __attribute__((section(".sdata"), aligned(8)));
__asm__(".extern D_L39_0024D080, 0");
extern u8 D_L39_0024D080[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_00246748, 4");
__asm__(".extern D_L39_00246754, 4");
extern s32 D_L39_00246748;
extern u8 D_L39_00246750;
extern s32 D_L39_00246754;

extern void func_003C4138(f32 *, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
s32 func_L01_005170B8(s32, s32);
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern s32 func_00198478(void);
extern void *func_0011D534(void *, s32, s32);
extern s32 func_L39_004B3910(void *, s32, s32, s32, void *);
extern s32 func_L39_004B3F88(s32, void *, u16);
extern s32 func_L39_004B4020(s32 *, void *, s32, u16 *);
extern s32 func_L39_004B3950(void *);
extern s32 func_L39_004B3F28(void *);
extern s32 func_0011D2EC(void *, void *, s32);
extern void func_L39_0067BCA8(void *, void *);
extern s32 func_L39_005F3548(s32, s32, void *);
extern s32 func_L39_004B3E10(void);
extern s32 func_00381FF0(s32);
extern void func_001375B0(void *, void *, s32);
extern void *memcpy(void *, const void *, unsigned int);
extern int func_L39_0067EBD0(void);
extern s32 func_00126060(void *);
extern s32 func_001271D0(s32, s32);
extern void func_L39_00518830(s32);
extern void func_00127108(s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_L01_00518670(s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00516FD8(s32, s32);
s32 func_L01_00516C78(s32, s32, s32);
extern s32 func_00120048(u8 *, u8 *, ...);
void func_L01_00478898(void);
extern void func_L39_005A61D8(void);
void func_L39_0067A7E0(void);
extern s32 func_L39_0067EB98(void);
extern void *func_001206F4(void *, void *);
void func_L39_0067A788(u8 *);

void func_L39_0067ABC8(void) {
    s32 col;
    s32 c;
    s32 i;

    if (D_L39_00242910 == -2) {
        if (D_L39_00247A34) {
            func_003C4138(&D_L39_00247A30, 0.0f, 0.07792208f);
        } else {
            func_003C4138(&D_L39_00247A30, 1.0f, 0.07792208f);
        }
        c = D_L39_00247A38;
        col = func_0038DBD8(c & 0xFFFFFF, c, D_L39_00247A30);
        func_L01_005170B8(0x460001, col);
        func_L01_005170B8(0x460002, col);
        if (D_L39_00247A34) {
            if (D_L39_00247A30 == 0.0f) {
                if (D_L39_0024D0C0 == 11 || D_L39_0024D0C0 == 12) {
                    D_L39_00241440 = 0;
                    D_L39_00242910 = -2;
                    func_L39_005BF798(12, 2, 0, 0, 0);
                } else if (D_L39_0024D0C0 == 13) {
                    func_00198478();
                    D_L39_00242910 = -2;
                    D_L39_00241440 = 1;
                    func_L39_005BF798(12, 2, 0, 0, 0);
                }
            }
            return;
        }
    }

    switch (D_L39_0024D0C0) {
    case 0: {
        SA_0067ABC8 a;
        SB_0067ABC8 b;
        s32 r;
        {
        func_0011D534(&D_L39_0024D0C8, 0, 0x10);
        func_0011D534(&D_L39_0024D0D8, 0, 0x10);
        func_0011D534(&a, 0, 0x14);
        a.a = 1;
        a.e = 0x10000;
        a.c = 8;
        a.d = D_L39_0049D890;
        a.b = &D_L39_00246748;
        func_0011D534(&b, 0, 8);
        b.a = 0x3C;
        b.b = 0x20;
        r = func_L39_004B3910(&a, 0x30, 0, 0, &b);
        if (r < 0) {
            D_L39_0024D0C0 = 8;
            D_L39_0024D0E8 = r;
            D_L39_0024D0C4 = 0;
            func_L39_004B3B18();
        } else if (D_L39_00246750) {
            D_L39_0024D0C0 = 1;
        } else {
            D_L39_0024D0C0 = 2;
        }
        }
        break;
    }
    case 1: {
        u8 buf[0x100];
        u16 len;
        s32 mode;
        s32 r;

        r = func_L39_004B3F88(1, D_L39_0024D0EC, D_L39_0024D0F0);
        if (r < 0) {
            D_L39_0024D0C0 = 8;
            D_L39_0024D0C4 = 1;
            D_L39_0024D0E8 = r;
        } else {
            func_L39_004B4020(&mode, buf, 0x100, &len);
            D_L39_0024D0C0 = 2;
        }
        break;
    }
    case 2: {
        s32 r;

        D_L39_00240500.magic = 0x3C3360AB;
        D_L39_00240500.a = D_L39_00240510;
        D_L39_00240500.b = D_L39_00240530;
        D_L39_00240530[0] = 0;
        r = func_L39_004B3950(&D_L39_00240500);
        if (r < 0) {
            D_L39_0024D0C0 = 8;
            D_L39_0024D0C4 = 2;
            D_L39_0024D0E8 = r;
        } else {
            D_L39_0024D0C0 = 3;
        }
        break;
    }
    case 3: {
        s32 r;
        s32 t;

        r = func_L39_004B3F28(&D_L39_0024D0C8);
        if (r < 0) {
            D_L39_0024D0C0 = 8;
            D_L39_0024D0C4 = 2;
            D_L39_0024D0E8 = r;
            break;
        }
        if (func_0011D2EC(&D_L39_0024D0D8, &D_L39_0024D0C8, 0x10)) {
            t = D_L39_0024D0C8.type;
            if (t == 5) {
                D_L39_0024D0C0 = 9;
                func_L39_004B3B18();
            } else if (t == 6 || t == 7) {
                D_L39_0024D0C0 = 4;
                D_L39_0024D0C4 = 2;
                func_L39_0067BCA8(&D_L39_0024D0C8, D_L39_0036DBA0);
            }
        }
        D_L39_0024D0D8 = D_L39_0024D0C8;
        if (D_L39_0024D0C0 == 3 && (D_L39_00241164->pad_held & 0x10)) {
            func_L39_005F3548(0x17, 0, 0);
            r = func_L39_004B3E10();
            if (r < 0) {
                D_L39_0024D0C0 = 8;
                D_L39_0024D0C4 = 2;
                D_L39_0024D0E8 = r;
            }
            D_L39_0024D0C0 = 5;
        }
        break;
    }
    case 5: {
        s32 r;
        s32 t;

        r = func_L39_004B3F28(&D_L39_0024D0C8);
        if (r < 0) {
            D_L39_0024D0C0 = 8;
            D_L39_0024D0C4 = 2;
            D_L39_0024D0E8 = r;
            break;
        }
        if (func_0011D2EC(&D_L39_0024D0D8, &D_L39_0024D0C8, 0x10)) {
            t = D_L39_0024D0C8.type;
            if (t == 5) {
                D_L39_0024D0C0 = 9;
                func_L39_004B3B18();
            } else if (t == 6 || t == 7) {
                D_L39_0024D0C0 = 4;
                D_L39_0024D0C4 = 2;
                func_L39_0067BCA8(&D_L39_0024D0C8, D_L39_0036DBA0);
            } else if (t == 2) {
                D_L39_0024D0C0 = 6;
                D_L39_0024D0C4 = 11;
                func_L39_004B3B18();
            }
        }
        break;
    }
    case 8: {
        s32 r;

        r = D_L39_0024D0E8;
        if (r >= -0x194 && r < -0x190) {
            D_L39_0024D0C0 = 4;
            D_L39_0024D0C4 = 2;
            D_L39_0024D0C8.type = 6;
            D_L39_0024D0C8.code = r;
            func_L39_0067BCA8(&D_L39_0024D0C8, D_L39_0036DBA0);
        } else {
            D_L39_0024D0C0 = 4;
            D_L39_0024D0C4 = 4;
            func_001206F4(D_L39_0036DBA0, func_00381FF0(0x11B1));
            func_001206F4(D_L39_0036DBA0 + 0x50, func_00381FF0(0x11B1));
            func_001206F4(D_L39_0036DBA0 + 0xF0, func_00381FF0(0x11B1));
        }
        break;
    }
    case 4: {
        s32 pad;

        pad = D_L39_00241164->pad_held;
        if (pad & 0x40) {
            func_L39_005F3548(4, 0, 0);
            D_L39_0024D0C0 = D_L39_0024D0C4;
        } else if (pad & 0x10) {
            func_L39_005F3548(0x17, 0, 0);
            D_L39_0024D0C0 = 6;
            D_L39_0024D0C4 = 12;
            func_L39_004B3B18();
        }
        break;
    }
    case 6:
        func_L39_0067EB98();
        D_L39_0024D0C0 = 7;
        break;
    case 7: {
        s32 info[16];
        {
        func_001375B0(info, D_L39_0024D040, 0x40);
        func_L39_0067A788(D_L39_0024D040);
        if (D_001A58C7 == 5 && info[12] == 4) {
            memcpy(D_L39_0024D040, D_L39_00246758, 29);
        }
        if (info[12] == 5) {
            D_L39_0024D0C0 = D_L39_0024D0C4;
        } else if (func_L39_0067EBD0() > 30000) {
            D_L39_0024D0C0 = D_L39_0024D0C4;
        }
        }
        break;
    }
    case 9: {
        ST_0067ABC8 t;

        func_001260F0(func_00126150(), D_L39_0024D0F4);
        t.func = func_L39_0067A7E0;
        t.stack = (void *)((s32)D_L39_0036DD40 & ~0xF);
        D_L39_0024D0F8 = 3600;
        D_001A5E52 = 0;
        t.size = 0x1FF0;
        t.gp = D_L39_00247FC0;
        t.prio = 0x28;
        D_L39_00246754 = func_00126060(&t);
        func_001271D0(D_L39_00246754, 0);
        D_L39_0024D0C0 = 10;
        break;
    }
    case 10:
        D_L39_0024D0F8 = D_L39_0024D0F8 - 1;
        if (D_L39_0024D0F8 <= 0 || D_001A5E52) {
            D_L39_0024D0C0 = 13;
        }
        if (D_L39_00241164->pad_held & 0x10) {
            func_L39_005F3548(0x17, 0, 0);
            D_L39_0024D0C0 = 6;
            D_L39_0024D0C4 = 12;
            func_L39_00518830(D_L39_00246754);
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
        func_L01_00516AA0(i, 1, 0);
        func_003E7F20(i, 2);
        func_L01_005170B8(i, 0x8066CCFF);
    }
    func_L01_00516AA0(0x46000F, 1, 0);
    func_L01_00516AA0(0x460008, 1, 0);

    switch (D_L39_0024D0C0) {
    case 0:
    case 1:
    case 2:
    case 3:
        func_L01_00516AA0(0x460008, 1, 1);
        func_L01_005170B8(0x460008, 0xAFAFAFAF);
        func_L01_00516AA0(0x460004, 1, 1);
        func_L01_00518670(0x460004, 1, 0);
        func_L01_00516470(0x460004, 0.5f, 0.275f);
        func_L01_00517538(0x460004, 0.8f, 0.2f);
        func_L01_00516FD8(0x460004, func_00381FF0(0x11AD));
        func_L01_00516AA0(0x460007, 1, 1);
        func_003E7F20(0x460007, 1);
        func_L01_00516470(0x460007, 0.5f, 0.55f);
        func_L01_00517538(0x460007, 0.8f, 0.2f);
        func_L01_00516FD8(0x460007, func_00381FF0(0x1259));
        func_L01_005170B8(0x460007, func_0038DBD8(0x8066CCFF, 0, 0.5f));
        func_L01_00518670(0x460007, 1, 0);
        func_L01_00516C78(0x460007, 3, 1);
        break;
    case 10:
        func_L01_00516AA0(0x460004, 1, 1);
        func_L01_00516470(0x460004, 0.5f, 0.275f);
        func_L01_00517538(0x460004, 0.8f, 0.2f);
        func_00120048(D_L39_0024D080, D_L39_00246778, func_00381FF0(0x1356));
        func_L01_00516FD8(0x460004, (s32)D_L39_0024D080);
        break;
    case 4:
        func_L01_00516AA0(0x460008, 1, 1);
        func_L01_005170B8(0x460008, 0x803040AF);
        func_L01_00516AA0(0x460004, 1, 1);
        func_L01_00518670(0x460004, 1, 0);
        func_L01_00516470(0x460004, 0.5f, 0.275f);
        func_L01_00517538(0x460004, 0.8f, 0.2f);
        func_L01_00516FD8(0x460004, (s32)D_L39_0036DBA0);
        func_L01_00516AA0(0x460005, 1, 1);
        func_L01_00518670(0x460005, 0, 0);
        func_003E7F20(0x460005, 1);
        func_L01_00516470(0x460005, 0.5f, 0.4f);
        func_L01_00517538(0x460005, 0.8f, 0.3f);
        func_L01_00516FD8(0x460005, (s32)(D_L39_0036DBA0 + 0x50));
        func_L01_00516AA0(0x460006, 1, 1);
        func_L01_00518670(0x460006, 1, 0);
        func_L01_00516470(0x460006, 0.5f, 0.8f);
        func_L01_00517538(0x460006, 0.8f, 0.2f);
        func_L01_00516FD8(0x460006, (s32)(D_L39_0036DBA0 + 0xF0));
        func_L01_00516AA0(0x460007, 1, 1);
        func_003E7F20(0x460007, 1);
        func_L01_00516470(0x460007, 0.5f, 0.55f);
        func_L01_00517538(0x460007, 0.8f, 0.2f);
        func_L01_00516FD8(0x460007, func_00381FF0(0x1259));
        func_L01_005170B8(0x460007, func_0038DBD8(0x8066CCFF, 0, 0.5f));
        func_L01_00518670(0x460007, 1, 0);
        func_L01_00516C78(0x460007, 3, 1);
        func_L01_00516AA0(0x46000F, 1, 1);
        break;
    case 5:
        func_L01_00516AA0(0x460004, 1, 1);
        func_L01_00518670(0x460004, 1, 0);
        func_L01_00516470(0x460004, 0.5f, 0.25f);
        func_L01_00517538(0x460004, 0.8f, 0.2f);
        func_L01_00516FD8(0x460004, func_00381FF0(0x11AF));
        func_L01_00518670(0x460006, 0, 0);
        func_L01_00516AA0(0x460010, 1, 0);
        break;
    case 6:
        func_L01_00518670(0x460004, 1, 0);
        func_L01_00516AA0(0x460004, 1, 1);
        func_L01_00516470(0x460004, 0.5f, 0.25f);
        func_L01_00517538(0x460004, 0.8f, 0.2f);
        func_L01_00516FD8(0x460004, func_00381FF0(0x11B0));
        func_L01_00516AA0(0x460010, 1, 0);
        break;
    case 7:
        func_L01_00516AA0(0x460004, 1, 1);
        func_L01_00516470(0x460004, 0.15f, 0.2f);
        func_L01_00517538(0x460004, 0.8f, 0.2f);
        func_L01_00516C78(0x460004, 1, 3);
        func_L01_00518670(0x460004, 0, 1);
        func_L01_00516FD8(0x460004, func_00381FF0(0x11B0));
        func_L01_00516AA0(0x460005, 1, 1);
        func_L01_00518670(0x460005, 1, 1);
        func_L01_00516470(0x460005, 0.5f, 0.3f);
        func_L01_00517538(0x460005, 0.8f, 0.2f);
        func_003E7F20(0x460005, 1);
        func_L01_00516FD8(0x460005, (s32)D_L39_0024D040);
        func_L01_005170B8(0x460005, func_0038DBD8(0x80000000, 0x8066CCFF, 0.75f));
        func_L01_00516AA0(0x460010, 1, 0);
        break;
    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
        break;
    }
    func_L01_00478898();
    func_L39_005A61D8();
    if (D_L39_0024D0C0 == 11 || D_L39_0024D0C0 == 12) {
        D_L39_00247A34 = 1;
    } else if (D_L39_0024D0C0 == 13) {
        D_L39_00247A34 = 1;
    }
}
/* localdecomp:end func_L39_0067ABC8 */

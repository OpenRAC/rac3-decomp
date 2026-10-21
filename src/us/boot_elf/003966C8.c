#include "common.h"

/* NTSC-U version of func_003967B0 (boot_elf): 25 -> 30; 8 -> 10 */

extern s32 func_U_003966C8();

typedef struct { s16 x; s16 y; } P_3896E8;
typedef struct {
    u8 n0; u8 n1; u8 p2[0x2E];
    u8 k30[0x10];
    u8 k40[0x10];
    P_3896E8 pt[0x10];
    s32 o90[0x10];
    s32 oD0[0x10];
} T_3896E8;
typedef struct { u32 w0; u32 w4; } E_3899B8;
typedef struct { u32 w0; u32 w4; } E_389B98;
typedef struct { u32 w0; u32 w4; } E_389D18;
typedef struct { s16 ch; s8 adj; u8 end; } K_389D18;
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 h12; s16 h14, h16; } B_38BB50;
typedef struct { u32 w0, w1; } G_38BB50;
extern void func_12A950(void);
extern void func_12BEE8(s32, s32, s32, s32);
typedef struct {
    u8 p0[0x150];
    s16 h150, h152, h154, h156, h158, h15A;
} E_38CC68;
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
extern void func_11F0A0(s32);
extern void func_12C4B0(s32);
extern void func_12C820(s32);
extern u8 D_1D07B0[], D_1D0900[];
typedef struct { unsigned long lo : 9; unsigned long hi : 55; } BF_38DC08;
typedef struct { u8 p0[0x160]; s16 h160; s16 h162; s16 h164; s16 h166; u8 p168[4]; u16 h16C; s16 h16E; } S_38DC08;
typedef struct { s32 a, b; } E_38E;
typedef struct { u8 pad[8]; E_38E e[10]; s32 f58, f5C, f60, f64, f68; u8 f6C; } S_38E;
typedef struct { u8 p0[8]; struct { s32 id; s32 x; } e[10]; s32 head; s32 tail; } S_E380;
typedef struct {
    u8 pad0[0x60];
    s32 active;
    u8 flag64;
    u8 pad65[3];
    s32 mode68;
    u8 flag6C;
} Object_0038E440;
typedef struct { u8 pad[0x18]; s16 h18; u8 pad2[0x17C - 0x1A]; s32 x17C; } S_38E5B8;
typedef struct LookupEntry_38E730 {
    u16 key;
    u8 reserved[6];
} LookupEntry_38E730;
typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_0038E798;
typedef struct { u32 w; u32 x; } E_0038E798;
typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_38E930;
typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } E_38E930;
typedef struct { s32 f0; s32 f4; u8 p8[0x18]; s32 f20; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; u8 p3C[0x28]; s32 f64; s32 f68; u8 p6C[4]; s32 f70; u8 p74[8]; s32 f7C; u8 p80[0x10]; } S_EB;
typedef struct S_38EC18 {
    s32 pad0;
    s32 v4, v8, vC;
    void (*f10)(struct S_38EC18 *);
    s32 v14, v18, pad1C;
    s32 a20, a24, a28, a2C;
    void (*a30)(struct S_38EC18 *);
    s32 a34, a38;
    s32 pad3C[11];
    s32 x68;
} S_38EC18;
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
typedef struct { s32 x0; u8 pad[0x3C]; s16 x40; u8 x42; u8 x43; s32 x44; } S_38ED00;
s32 func_U_00393288(s32);
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
typedef struct { u8 p0[0x58]; s32 f58; s32 f5C; u32 f60; u8 p64[0x18]; s32 f7C; } S_38EE58;
typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p1[0x48]; s32 f58; s32 f5C; s32 f60; u8 p2[0x10]; s32 f74; s32 f78; } S;
typedef struct { u8 pad[0x38]; u16 h38; u8 pad2[0xF0 - 0x3A]; } S_38F310;
typedef struct { s32 w0; u8 pad[0x14]; s32 w18; } D_393F38;
extern s32 D_1D4C60[2];
extern s32 D_1D4C80[2];
typedef struct { u8 pad[0x48]; s16 h48; s16 h4A; u8 p2[0x58-0x4C]; s32 w58; s32 w5C; u8 p3[0x70-0x60]; s32 w70; s32 w74; s32 w78; } S_38F3A0;
typedef struct { u8 p0[0x64]; s32 f64; u8 p68[4]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_390730;
typedef struct { u8 p0[0x148]; f32 f148; f32 f14C; u8 p150[0x70]; s32 f1C0; s32 f1C4; s32 f1C8; s32 f1CC; } P_390730;
typedef struct { u8 p0[8]; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; } T_390730;
typedef struct { u8 p0[0x286C]; s32 f286C; } G_390730;
typedef struct { u8 p0[8]; s32 w8; u8 pC[0x44]; s32 w50; s32 w54; s32 w58; s32 w5C; u8 p60[0xC]; s32 w6C; u8 p70[4]; s32 w74; } O_91A18;
/* localdecomp:start func_U_003966C8 */
typedef struct { s16 f0; u8 b2; u8 p3[9]; s32 fC; } O_391B70;
typedef struct { u16 h0; u16 h2; u16 h4; u8 b6; u8 b7; } E_391B70;
extern u8 *D_U_001D9F24_003967B0;
extern s32 D_U_001D9D80_003967B0;
extern s32 func_U_00382868(s32, s32);
s32 func_U_003966C8(O_391B70 *o) {
    E_391B70 *e = (E_391B70 *)(D_U_001D9F24_003967B0 + o->f0 * 8);
    s32 r = 0;
    if (e->h0 != 0xFFFF) {
        switch (o->b2) {
        case 0:
            r = e->h4;
            break;
        case 1:
            r = e->h4 + ((D_U_001D9D80_003967B0 - o->fC) / e->b7) % e->h2;
            break;
        case 2: {
            s32 n = e->h2 * 2;
            r = ((D_U_001D9D80_003967B0 - o->fC) / e->b7) % (n - 2);
            if (r >= e->h2) {
                s32 u = r + 2;
                r = n - u;
            }
            goto add;
        }
        case 3: {
            s32 t = o->fC;
            do {
                if (t < D_U_001D9D80_003967B0) {
                    s32 n;
                    r = (D_U_001D9D80_003967B0 - t) / e->b7;
                    n = e->h2 * 2;
                    if (r < n - 2) {
                        if (r >= e->h2) {
                            s32 u = r + 2;
                            r = n - u;
                        }
                    add:
                        r += e->h4;
                    } else {
                        s32 k;
                        r = e->h4;
                        k = func_U_00382868(0x1E, t) + 10;
                        o->fC = e->h2 * 2 + k;
                    }
                } else {
                    r = *(s32 *)((u8 *)o + 4);
                }
            } while (0);
        }
        }
    }
    *(s32 *)((u8 *)o + 4) = r;
    return r;
}
/* localdecomp:end func_U_003966C8 */

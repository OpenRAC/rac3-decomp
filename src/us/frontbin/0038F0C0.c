#include "common.h"

/* NTSC-U version of func_003938F8 (frontbin): 180 -> 210 */

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
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 fl; s16 h14, h16, h18, h1A; } O_0038B1E8;
typedef struct { s16 key; s8 val; u8 end; } K_0038B1E8;
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
s32 func_U_0038E730(s32);
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
typedef struct { u8 p0[0x58]; s32 f58; s32 f5C; u32 f60; u8 p64[0x18]; s32 f7C; } S_38EE58;
typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p1[0x48]; s32 f58; s32 f5C; s32 f60; u8 p2[0x10]; s32 f74; s32 f78; } S;
/* localdecomp:start func_U_0038F0C0 */
extern void func_U_0038EFD0(void *);
 
void func_U_0038F0C0(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0xD2;
    *(s16 *)((u8 *)p + 0x48) = 0;
    *(s16 *)((u8 *)p + 0x4A) = 0;
    func_U_0038EFD0(p);
}
/* localdecomp:end func_U_0038F0C0 */

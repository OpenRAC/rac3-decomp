#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void func_003C1078(void);
/* --- end of declarations from other files --- */

/* declarations of 3BE710.c's earlier functions (tools/port_from_us.py) */
extern s32 D_001DA2D0_003BE800;
extern u8 D_001DA2D4_003BE800;
extern s32 D_001DA2D8_003BE800;
extern s32 D_001DA2DC_003BE800;
extern s32 D_001D8D28_003BE800;
extern s32 D_001D8D40_003BE800;
extern u8 D_001D8D2C_003BE800[8];
extern u8 D_001D8D44_003BE800[8];
extern s32 D_002FCDC4[];
extern void func_003BBDC0(s32, s32);
extern void func_003BC7C0();
extern void func_003BE068(s32, s32 *, s32);
extern s32 func_003BE0F0();
extern void func_003BE1D8();
extern void func_003BE6C0();
extern void func_003BE8E0();
extern void func_003BE948();
extern s32 func_003BE940();
extern void func_003BF130();
typedef int Q_3B9098 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9098;
typedef struct { f32 f0, f4, f8, fC, f10; u8 b14, b15; } Sub_3B9098;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    u8 hA[2];
    f32 fC;
    V4_3B9098 v10;
    Sub_3B9098 s20;
} S_3B9098;
extern s32 func_0038CEE0(void *);
extern void func_003CD608(s32);
typedef int u128_3B9160 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, fC, f10;
    u8 b14, b15;
    u8 pad16[6];
    void *f1C;
} Q_3B9160;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_3B9160 v10;
    Q_3B9160 q;
} P_3B9160;
extern void *func_003CD4C0(s32);
extern s32 func_00382848(s32);
extern u8 *D_002FCF20[];
extern void func_003BE948();
typedef struct { f32 f0, f4, f8, fC, f10; u8 b14, b15; u8 pad16[6]; void *f1C; } Sub_3B9160;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u16 hA;
    f32 fC;
    Q_3B9160 q10;
    Sub_3B9160 s20;
} S_3B9160;
typedef int Q_3B92B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B92B8;
extern void func_0038D348(s32, s32, f32);
extern void func_0038D270(void *, void *, void *);
extern f32 func_0038D288(void *);
extern void func_0038D218(void *, void *, f32);
extern f32 func_0038D478(f32);
extern s32 func_00382848();
extern f32 func_003828C0(f32, f32);
extern S_3B9160 *func_003BEA10(Q_3B9160 *, f32 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_003BF168();
extern void func_0038A2F8();
extern void func_003BEFE0(void *);
typedef struct { u8 b[8]; } V8_3B98B8;
typedef struct { u128_t q[4]; } M4_3B98B8;
extern V8_3B98B8 D_001D8D80[];
extern M4_3B98B8 D_001D8D90[];
extern u8 D_001D8DD0;
extern s32 D_001D9348;
extern void func_003C33A0();
extern void func_003D9808();
extern void func_003D3158();
extern u8 D_001DA2D4[];
extern u8 D_001DA300[];
extern s32 D_001D9364[];
u8 func_003BDFB0(void);
extern u8 D_001DA2D4_003BF2B8;
extern volatile u8 D_001DA300_003BF2B8;
extern s32 D_001DA2D0;
extern s32 D_001D8D28;
extern s32 D_001D8D40;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
extern S_3B9A08 D_00225700_003BF2B8;
extern void func_003BCB20();
extern s32 func_003BE2C8();
extern s32 func_003BE2D0();
extern void func_003BE520();
extern void func_003BBD20();
extern s32 func_003BE0F0();
extern void func_003BE218();
extern void func_003BE6C0();
extern void func_003BE2F8();
extern void func_003882D0();
extern void func_003BE8E0();
extern void func_003BE318();
extern void func_003BE2F8();
extern void func_003BCB20();
extern u8 D_001DA310;
extern u8 D_001DA311;
extern s32 D_001D8DF0;
extern s32 D_001D8DF4;
extern void *D_002FCC40[];
extern void func_003BBDC0(s32, s32);
extern void func_003BC7C0();
extern void func_003BE068(s32, s32 *, s32);
extern s32 func_003BE0F0(void);
extern void func_003BE1D8(s32);
extern void func_003BF658();
extern void func_003BF498();
extern void func_003BE6C0(void *);
extern void func_003BE5B0(s32);
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x74]; s16 hAA; } S_3B9BE8;
extern s32 D_001D4B60[];
extern u8 func_00381BC0(void);
typedef int Q_3B9C50 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9C50;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u8 padA[2];
    s32 wC;
    Q_3B9C50 q10;
    V4_3B9C50 v20;
    Q_3B9C50 q30;
} S_3B9C50;
typedef struct { u8 pad[4]; u8 b4; } T_3B9C50;
extern f32 D_001D8E00;
extern f32 D_001D8E04;
extern s32 D_001D8E08;
extern s32 D_001D8E0C;
extern s32 D_001D8E10;
extern s32 D_001D8E14;
extern s32 D_001D8E18;
extern s32 D_001D8E1C;
extern f32 D_001D8E20;
extern u8 D_001D8E24;
extern u8 D_001D8E28;
extern T_3B9C50 *D_002FD004[];
extern void *func_003CD4C0(s32);
extern f32 func_003828C0(f32, f32);
extern s32 func_00382878(s32, s32);
extern void func_0038D348(s32, s32, f32);
typedef int Q_3B9DA8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9DA8;
typedef struct {
    u8 pad0[0x10];
    V4_3B9DA8 v10;
    V4_3B9DA8 v20;
    V4_3B9DA8 v30;
} S_3B9DA8;
extern void func_003CD608(s32);
typedef int Q_3B9E98 __attribute__((mode(TI)));
typedef struct { V4_3B9C50 a; V4_3B9C50 b; } E_3B9E98;
extern s32 func_003C2F40_003BF748(void *, s32);
extern S_3B9C50 *func_003BF500(V4_3B9C50 *, V4_3B9C50 *);
extern void func_00382960(V4_3B9C50 *, f32, f32);
extern f32 func_003828C0(f32, f32);
extern void func_0038D1D8(void *, void *, void *, f32);
extern s32 func_003BE2A8(void);
extern void func_003BF748(void *a);
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x15E]; s32 w1A0; } S_3BA108;
extern S_3BA108 D_00225700_003BF9B8[];
extern u32 D_001DA49C;
extern u32 D_001DA4A0;
extern u8 D_001DA310;
extern s32 D_001D8DF0;
extern void func_003C8190();
extern void func_003BCB20();
extern s32 func_003BE2C8();
extern s32 func_003BE2D0();
extern void func_003BBD20();
extern void func_003BE520();
extern s32 func_003BE0F0();
extern void func_003BE218();
extern void func_003BE6C0();
extern void func_003BE2F8();
extern void func_003882D0();
extern void func_003BF498();
extern void func_003BE318();
extern void func_003BF968();
extern void func_003BE2F8();
extern void func_003BCB20();
extern f32 D_001DA340;
extern s32 D_001DA338;
extern u8 D_001DA33C;
extern u8 D_001DA344[2];
extern s32 D_001D8E30;
extern u8 D_001D8E34[];
extern void *D_002FCDA4[];
extern void func_003BBDC0(s32, s32);
extern void func_003BC7C0();
extern s32 func_003BE0F0(void);
extern void func_003BE1D8(s32);
extern void func_003BE6C0(void *);
extern void func_003BFC78(void);
extern void func_003BFC18();
extern void func_003C0010();
extern s32 D_0016C5E4[];
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x2E]; void *x64; u8 pad3[0x42]; s16 hAA; } S_3BA368;
extern void func_003C0118(S_3BA368 *p);
extern void func_003A8620(void *);
extern u8 D_0031D130[];
extern u8 *D_001D6EEC[];
typedef int Q_3BA5B8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x10]; Q_3BA5B8 q10; u8 pad20[0x12]; s16 h32; } B_3BA5B8;
typedef struct {
    B_3BA5B8 *b;
    s32 w4;
    f32 f8;
    u8 bC, bD, bE, bF;
    union { Q_3BA5B8 q; f32 f[4]; } q10;
} Sub_3BA5B8;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u16 hA;
    f32 fC;
    Q_3BA5B8 q10;
    Sub_3BA5B8 s20;
} S_3BA5B8;
extern void *func_003CD4C0(s32);
extern s32 func_00382848();
extern u8 *D_002FCFFC[];
extern void func_0038D3E0(void *, void *, void *);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BA748;
typedef int Q_3BA748 __attribute__((mode(TI)));
typedef struct { s8 p0[0x20]; s8 b20; } O_3BA748;
typedef struct { O_3BA748 *obj; s32 f4; u8 p8[5]; u8 b0D; u8 pE[2]; V_3BA748 v10; } B_3BA748;
typedef struct { u8 p0[4]; s32 f4; u8 b8; u8 p9; s16 h0A; f32 fC; V_3BA748 v10; B_3BA748 b; } P_3BA748;
extern s32 func_0038CEE0();
extern void func_003CD608(s32);
extern void func_0038D3E0(void *, void *, void *);
extern u8 *D_001DA31C_003C0118[2];
extern u8 D_00380060[];
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850;
extern u8 D_001DA318[8];
extern f32 D_001D8E64;
extern s32 D_001D8E68;
extern f32 D_001D8E6C;
extern f32 D_001D8E70;
extern u8 *func_003BFE80(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 D_001DA31C[];
extern void func_003CD608(s32);
typedef int Q_3BA9A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BA9A0;
typedef struct { f32 x, y; } V2_3BA9A0;
typedef struct { f32 v[3]; } V3_3BA9A0;
typedef struct { u8 pad[8]; u8 b8; } O_3BA9A0;
extern s32 D_001D8ED8;
extern s32 D_001D8EDC;
extern s32 D_001D8EF0;
extern s32 D_001D8EC0;
extern s32 D_001D8EC4;
extern s32 D_001D8F10;
extern f32 D_001D8EE0;
extern s32 D_001D8F50;
extern f32 D_001D8ED0;
extern f32 D_001D8ED4;
extern s32 D_001D8EC8;
extern s32 D_001D8ECC;
extern s32 D_001D8F70;
extern s32 D_001D8F00_003C0268;
extern V4_3BA9A0 D_003800C0[];
extern O_3BA9A0 *D_001DA318_003C0268;
extern V2_3BA9A0 D_001DA390_003C0268;
extern s32 D_001DA348_003C0268;
extern s32 D_001DA378_003C0268;
extern V4_3BA9A0 D_00222420[];
extern V4_3BA9A0 D_00222400[];
extern s32 D_001D9D00;
extern f32 D_001DA340;
extern void func_003A97F8(s32, unsigned long);
extern void func_0038CB30(void);
extern s32 func_00382848();
extern void func_0038D408();
extern void func_0038D3E0(void *, void *, void *);
extern void func_0038D200(f32 *, void *, f32);
extern s32 func_0038DFB8(s32, s32, f32);
extern void func_0038D068();
extern long func_00389978(s32);
extern void func_003D3DDC();
extern f32 func_0038D2E0(void *, void *);
typedef int Q_3BAE98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BAE98;
extern f32 D_001D8E60;
extern f32 D_001D8FC8;
extern s32 D_001D8F94;
extern s32 D_001D8E80;
extern s32 D_001D8F9C;
extern s32 D_001D8F98;
extern f32 D_001D8FA0;
extern f32 D_001D8FA4;
extern f32 D_001D8FA8;
extern f32 D_001D8FAC;
extern f32 D_001D8FB8;
extern f32 D_001D8FBC;
extern f32 D_001D8FC0;
extern f32 D_001D8FC4;
extern s32 D_001D8FB0;
extern s32 D_001D8FB4;
extern s32 D_001D8F90;
extern f32 D_001DA334;
extern s32 D_001D9D00;
extern void func_003A97F8(s32, unsigned long);
extern void func_0038CB30(void);
extern void func_0038D408();
extern s32 func_0038DFB8(s32, s32, f32);
extern void func_0038D200(f32 *, void *, f32);
extern void func_003D9AF8(void *, s32, s32, s32, s32, f32);
extern s32 D_001DA338_003C0C60;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 f40; } T_3BB398;
extern T_3BB398 D_00225700[];
extern void func_003BCB20();
extern void func_003BE520();
extern void func_003BBD20();
extern void func_003BE218();
extern void func_003BE2F8();
extern void func_003C0210();
extern s32 func_003BE2C8();
extern s32 func_003BE2D0();
u8 func_003BDFB0(void);
extern void func_003A8850();
extern s32 func_003BFC00(void);
extern void func_003C0268(void *);
extern void func_003C0760(void *);
extern void func_003BE2F8();
extern void func_003BCB20();
extern void func_003C0210();
typedef struct { u8 pad[0x40]; s32 w40; s32 w44; } S_3BB558;
extern S_3BB558 D_002D1FC0[];
extern void func_003BBDC0(s32, s32);
extern s32 func_003823D0(s32);
extern s32 func_11BB58(void *, s32, s32);
extern void func_003BE3C0(f32);
extern s32 func_0038CEB0();
extern s32 func_003BE2D0();
extern void func_003BBD20();
extern s32 D_001D4BC0;
extern u8 D_002D1FC0_003C0FF8[];
extern void func_00389620();
extern void func_00391330(s32, s32, unsigned long, u8 *, s32, f32);
extern void func_00389750();

/* localdecomp:start func_003C1058 */
extern void func_003A8620(void *);
extern u8 D_0031D130[];
 
void func_003C1058(void) {
    func_003A8620(D_0031D130);
}
/* localdecomp:end func_003C1058 */

/* localdecomp:start func_003C1078 */
extern u8 D_001D8D20;
void func_003C1078(void) {
    D_001D8D20 = 0;
}
/* localdecomp:end func_003C1078 */

/* localdecomp:start func_003C1080 */
extern s32 D_002D2018[];
extern s32 func_11BB58(void *, s32, s32);
extern u8 D_001D8D20;
void func_003C1080(s32 a0) {
    D_001D8D20 = 1;
    func_11BB58(D_002D2018, a0, 0x40);
}
/* localdecomp:end func_003C1080 */

/* localdecomp:start func_003C10B0 */
typedef struct { s32 f0; u8 p4[0x4C]; u8 f50; u8 f51; } S_BB7E8;
typedef struct { s32 a; s32 b; } P_BB7E8;
typedef struct { u8 p[0x68]; s32 f68; } T_BB7E8;
extern S_BB7E8 D_002D2008_003C10B0[];
extern T_BB7E8 D_00227580[];
extern P_BB7E8 D_0037FA58[];
extern s32 D_0037FA60[];
extern s32 D_0037FA64[];
extern s32 D_001D9030;
extern u8 D_001D9034[];
extern s32 D_0022D8B0[];
extern s32 D_00225700_003C10B0[];
extern s32 func_003BBB70();
extern void func_003BC940();
extern void func_003A5AF8();
extern void func_003C12B8();
s32 func_003C10B0(void) {
    s32 r, a, s, tmp;
    s32 *p;
    u8 *d;
    s32 t;
    S_BB7E8 *g;
    g = D_002D2008_003C10B0;
    g->f50 = 0;
    g->f51 = 0;
    r = func_003BBB70();
    if (D_001D8D20) {
        D_001D8D20 = 0;
    } else {
        d = (u8 *)g + 0x10;
        if ((u32)(r - 1) < 2 || r == 4 || r == 8 || r == 0x1B || r == 0x1C || r == 9 || r == 0x1D
            || r == 5 || r == 0xD || r == 0x17 || r == 0xA || r == 0x12 || r == 0xE) {
            if (r > 0) a = D_0037FA58[r % 60].b;
            else a = D_0037FA64[0];
        } else {
            if (r > 0) a = D_0037FA58[r % 60].a;
            else a = D_0037FA60[0];
        }
        func_11BB58(d, func_003823D0(a), 0x40);
    }
    func_003BBDC0(1, 0);
    func_003BC7C0(5, &D_001D9030);
    func_003BE068(4, (s32 *)D_001D9034, D_001D9030);
    s = D_00227580[0].f68;
    func_003BC940(r, &tmp, s);
    D_002D2008_003C10B0[0].f0 = s;
    s = s + tmp;
    D_00227580[0].f68 = s;
    func_003BE1D8(func_003BE0F0());
    func_003BE6C0(func_003C12B8);
    { s32 i = 0; while (D_0022D8B0[i]) { D_0022D8B0[i] = 0; i++; } }
    func_003A5AF8(D_00225700_003C10B0[0x15]);
    func_003C1058();
    return 1;
}
/* localdecomp:end func_003C10B0 */

/* localdecomp:start func_003C12B8 */
extern void func_003C1638();
void func_003C12B8(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x1E03:
        *(u16 *)(p + 0x34) |= 1;
        *(void **)(p + 0x64) = func_003C1638;
        ok = 1;
        break;
    case 0xD54:
        *(void **)(p + 0x64) = 0;
        ok = 1;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_003C12B8 */

typedef struct { u8 p0[0x24]; struct { u8 p[0x24]; f32 f24; } *w24; u8 p28[4]; f32 f2C; u8 p30[0x32]; u8 b62; u8 p63[0x32]; u8 b95; u8 p96[0x14]; s16 hAA; } Q_3BBA50;
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x12]; Q_3BBA50 *w54; } G_3BBA50;
extern G_3BBA50 D_00225700_003C1318[];
extern u8 D_002D2008_003C1318[];
extern u32 D_001DA49C;
extern u32 D_001DA4A0;
extern f32 D_001D6EF0;
extern Q_3BBA50 *D_001DA008;
extern Q_3BBA50 *D_0022D8B0_003C1318[];
extern void func_003C8190();
extern void func_003A5CC0();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C1318);

/* US draft of func_003C1510 (rac3-uya-decomp func_003C1408, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003C1510 */
extern s32 D_001D9030_003C1510;
extern u8 D_002D2008_003C1510[];
extern u8 D_00225700_003C1510[];
extern void func_003BCB20();
extern s32 func_003BE2C8();
extern s32 func_003BE2D0();
extern void func_003BBD20();
extern void func_003BE520();
extern s32 func_003BE0F0();
extern void func_003BE218();
extern void func_003BE6C0();
extern void func_003BE2F8();
extern void func_003C1058();
extern void func_003BE318();
extern void func_003C12B8();
__asm__(".extern D_001D9030_003C1510, 4");
void func_003C1510(s32 a0) {
    s32 v4;
    s32 v5;
    u8 *g;
    if (D_002D2008_003C1510[0x50] != 0) {
        func_003BCB20();
        if (func_003BE2C8() == 1) {
            func_003BE520();
        }
        if (func_003BE2C8() > 0 && func_003BE2D0() != 0) {
            func_003BBD20();
        }
        if (D_002D2008_003C1510[0x51] == 0) {
            if (func_003BE2C8() > 0 && a0 != 0) {
                v4 = D_001D9030_003C1510;
                D_002D2008_003C1510[0x51] = 1;
            } else {
                v4 = func_003BE0F0();
            }
            func_003BE218(v4);
            func_003BE6C0(func_003C12B8);
            func_003BE2F8();
            func_003C1058();
        }
    }
    g = D_00225700_003C1510;
    v5 = *(s16 *)(g + 0x40);
    if (D_002D2008_003C1510[0x51] != 0) {
        if (*(s32 *)(g + 0x34) >= 0x1F) v5 += 0x1E;
    }
    func_003BE318(*(s32 *)(g + 0x34), v5, 6, 6);
}
/* localdecomp:end func_003C1510 */

extern void func_0038A140(void (*)(), s32);
/* localdecomp:start func_003C1638 */
void func_003C1660();

/* from rac2-decomp's func_0034F780, renamed */
void func_003C1638(int value) {
    func_0038A140(func_003C1660, value);
}
/* localdecomp:end func_003C1638 */

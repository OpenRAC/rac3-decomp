#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
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
extern void func_003C3278(u8 *, s32, u8 *);
extern void func_0038D3E0(void *, void *, void *);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C0010);

/* US draft of func_003C0118 (rac3-uya-decomp func_003C0010, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003C0118 */
__asm__(".extern D_001D8E64, 4");
__asm__(".extern D_001D8E68, 4");
__asm__(".extern D_001D8E6C, 4");
__asm__(".extern D_001D8E70, 4");
extern u8 *D_001DA31C_003C0118[2];
extern u8 D_00380060[];
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850;
extern u8 D_001DA318[8];
extern f32 D_001D8E64;
extern s32 D_001D8E68;
extern f32 D_001D8E6C;
extern f32 D_001D8E70;
extern u8 *func_003BFE80(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_003C0118(S_3BA368 *a) {
    s32 i;
    u8 **p = D_001DA31C_003C0118;
    u8 *e = D_00380060;
    u8 *r;
    for (i = 5; i >= 0; i--) {
        if (*p == 0) {
            r = func_003BFE80(e, (s32)a, D_001D8E68, 0, 0, -1, 0, -1, 0, 0, D_001D8E6C * 210000.0f, D_001D8E70, 1.0f);
            *p = r;
            if (r != 0) r[3] = 0x44;
        }
        e += 0x10;
        p++;
    }
    { S_3BA850 *q = (S_3BA850 *)D_001DA318; q->f1C = D_001D8E64 * 0.020000002f; }
}
/* localdecomp:end func_003C0118 */

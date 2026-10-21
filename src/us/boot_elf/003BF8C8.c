#include "common.h"

/* NTSC-U version of func_003BF9B8 (boot_elf): 12 -> 15; 12 -> 15 */

typedef int u128_t __attribute__((mode(TI)));

extern s32 func_U_003BE000();
extern void func_U_003BE5D0();
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
typedef struct { u8 b[8]; } V8_3B98B8;
typedef struct { u128_t q[4]; } M4_3B98B8;
u8 func_U_003BDEC0(void);
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
extern void func_U_003BCA48();
extern s32 func_U_003BE1D8();
extern s32 func_U_003BE1E0();
extern void func_U_003BE430();
extern void func_U_003BBC48();
extern s32 func_U_003BE000();
extern void func_U_003BE128();
extern void func_U_003BE5D0();
extern void func_U_003BE208();
extern void func_U_003882A8();
extern void func_U_003BE228();
extern void func_U_003BE208();
extern void func_U_003BCA48();
extern u8 D_U_001DA390;
extern s32 D_U_001D8E20;
extern s32 func_U_003BE000(void);
extern void func_U_003BF3A8();
extern void func_U_003BE5D0(void *);
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x74]; s16 hAA; } S_3B9BE8;
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
typedef int Q_3B9DA8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9DA8;
typedef struct {
    u8 pad0[0x10];
    V4_3B9DA8 v10;
    V4_3B9DA8 v20;
    V4_3B9DA8 v30;
} S_3B9DA8;
typedef int Q_3B9E98 __attribute__((mode(TI)));
typedef struct { V4_3B9C50 a; V4_3B9C50 b; } E_3B9E98;
/* localdecomp:start func_U_003BF8C8 */
/* The flag pair at 0x1DA310: retail reaches the second byte with `lui` (the assembler's
   expansion), so the pair is declared sized (gcc leaves the accesses to the assembler as
   macros) with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md). The first byte goes through $gp, as the plain D_U_001DA390. */
extern u8 D_U_001DA390_003BF9B8[2];
__asm__(".extern D_U_001DA390_003BF9B8, 16");
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x15E]; s32 w1A0; } S_3BA108;
extern S_3BA108 D_U_00225780_003BF9B8[];
extern u32 D_U_001DA51C;
extern u32 D_U_001DA520;
extern u8 D_U_001DA390;
extern s32 D_U_001D8E20;
extern void func_U_003C8028();
extern void func_U_003BCA48();
extern s32 func_U_003BE1D8();
extern s32 func_U_003BE1E0();
extern void func_U_003BBC48();
extern void func_U_003BE430();
extern s32 func_U_003BE000();
extern void func_U_003BE128();
extern void func_U_003BE5D0();
extern void func_U_003BE208();
extern void func_U_003882A8();
extern void func_U_003BF3A8();
extern void func_U_003BE228();
extern void func_U_003BF878();
__asm__(".extern D_U_001DA51C, 16");
__asm__(".extern D_U_001DA520, 16");
s32 func_U_003BF8C8(s32 a) {
    u32 p;
    s32 r;
    u8 t;
    S_3BA108 *g;
    r = 0;
    for (p = D_U_001DA51C; p < D_U_001DA520; p += 0x100) {
        func_U_003C8028(p);
    }
    D_U_001DA390 = func_U_003BDEC0();
    if (D_U_001DA390 != 0) {
        func_U_003BCA48();
        if (func_U_003BE1D8() == 1) {
            func_U_003BE430();
        }
        if (func_U_003BE1D8() > 0 && func_U_003BE1E0() != 0) {
            func_U_003BBC48();
        }
        t = D_U_001DA390_003BF9B8[1];
        if (a != 0) { if (t != 0) r = 1; }
        if (t == 0) {
            s32 v4;
            if (func_U_003BE1D8() > 0 && a != 0) {
                v4 = D_U_001D8E20;
                D_U_001DA390_003BF9B8[1] = 1;
            } else {
                v4 = func_U_003BE000();
            }
            func_U_003BE128(v4);
            func_U_003BE5D0(func_U_003BF3A8);
            func_U_003BE208();
            func_U_003882A8();
        }
    }
    g = D_U_00225780_003BF9B8;
    if (g->w1A0 != 0) func_U_003BF878(g->w1A0);
    func_U_003BE228(g->w34, g->h40, 15, 15);
    return r;
}
/* localdecomp:end func_U_003BF8C8 */

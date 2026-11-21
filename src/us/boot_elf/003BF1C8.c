#include "common.h"

/* NTSC-U version of func_003BF2B8 (boot_elf): 12 -> 15; 12 -> 15 */
#include "common.h"


typedef int u128_t __attribute__((mode(TI)));



extern s32 func_U_003BE000();
extern void func_U_003BE5D0();
extern void func_U_003BE7F0();
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
extern u8 D_U_001DA354_003BF2B8;
extern s32 D_U_001DA350;
extern s32 D_U_001D8D58;
extern s32 D_U_001D8D70;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
extern S_3B9A08 D_U_00225780_003BF2B8;
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
extern void func_U_003BE7F0();
extern void func_U_003BE228();
/* localdecomp:start func_U_003BF1C8 */
__asm__(".extern D_U_001DA354_003BF2B8, 16");
typedef struct { u8 pad[4]; u8 b4; } S_003BF2B8;
__asm__(".extern D_U_001DA37C_003BF2B8, 16");
extern S_003BF2B8 D_U_001DA37C_003BF2B8;
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
extern void func_U_003BE7F0();
extern void func_U_003BE228();
void func_U_003BF1C8(s32 a0) {
    s32 v;
    if (D_U_001DA354_003BF2B8 != 0) {
        func_U_003BCA48();
        if (func_U_003BE1D8() == 1) {
            func_U_003BE430();
        }
        if (func_U_003BE1D8() > 0 && func_U_003BE1E0() != 0) {
            func_U_003BBC48();
        }
        if (D_U_001DA37C_003BF2B8.b4 == 0) {
            v = 0;
            if (func_U_003BE1D8() > 0 && a0 != 0) {
                switch (D_U_001DA350) {
                case 0:
                    v = D_U_001D8D58;
                    break;
                case 1:
                    v = D_U_001D8D70;
                    break;
                }
                D_U_001DA37C_003BF2B8.b4 = 1;
            } else {
                v = func_U_003BE000();
            }
            func_U_003BE128(v);
            func_U_003BE5D0(func_U_003BE7F0);
            func_U_003BE208();
            func_U_003882A8();
        }
    }
    {
        S_3B9A08 *g = &D_U_00225780_003BF2B8;
        func_U_003BE228(g->f34, g->h40, 0xF, 0xF);
    }
}
/* localdecomp:end func_U_003BF1C8 */
